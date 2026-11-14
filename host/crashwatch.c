// RN_CRASHWATCH=1 (off by default): names the writer family of the "memory fault" at 0x5838c3 (traffic, 0x583850) and 0x44c56e (racer,
// 0x44c550), docs/re/roadid.md. Both do `call [[v+8]+0x3c]`: v = the AIVehicle (car+0x2c, vtable 0x6b96b0 for traffic), v+8 = its steering
// object (new 0x250 in the AIVehicle constructor 0x582f90, set at 0x582fed). The game thread reads it at every step, so the fault
// is the first read of a [v+8] that is no longer a heap pointer to an object with a vtable.
// RN_CWFILL=1 (with RN_CRASHWATCH): every Present sets the 8 decider-cache slots of each traffic car in use (a stress test of the full-cache path).
// 1. Once per Present (host/d3d9.c, next to world_spawn): for every car of the race list [0x7361f8] keep (v, [v+8], [[v+8]], heap
//    headers of both). The first frame a car's pair stops being valid, log the car and its last 12 frames (the writer sits
//    between the last good frame and that one), the first 0x60 bytes of v, and the heap headers around v.
// 2. In rn_stop (host/main.c): the registers that hold v / [v+8] at the stop, with the same dump.
// 3. RN_STW=1 build (rt.h): every Present arms the first 16 bytes of each car's v; a store into [v, v+12) that is not a valid
//    pointer write logs the writer's guest address (halt_at = the last memory instruction, or the host API entry), address, value
//    and the stack; a free of a watched v (win32.c heap_free) logs its stack. At most 60 lines.
// Heap block header (host/win32.c): [-16] size|used, [-12] size of the previous block, [-8]/[-4] free-list links.
#include <string.h>
#include "host.h"

#define NH 12
#define NC 40
static struct { uint32_t frame, n, v[NC], d[NC], vt[NC], r[NC]; } hist[NH];
static int hn, on = -1, said, fill = -1;
static uint32_t kind0[4];
static uint32_t wv[NC], nw;
static uint32_t full[4], seen[4], fullmax;   // per kind: car-frames seen, car-frames whose 8 decider-cache slots (v+0xc..v+0x28) all had bit 0 set
#ifdef RN_STW
uint8_t rn_stw_bm[1u << 20];
#endif

static int heapp(uint32_t p) { return p >= HEAP_LO + 16 && p < GUEST_MEM - 0x100; }
static int vtp(uint32_t p) { return p >= 0x697000 && p < 0x6d5000; }
static uint32_t W(Ctx *c, uint32_t a) { return a >= LOW && a < GUEST_MEM - 4 ? ld(c, a, 4) : 0xdeadbeefu; }

static void hdr(Ctx *c, const char *what, uint32_t p) {
    if (!heapp(p)) { rn_log("CW   %s %08x: not in the heap", what, p); return; }
    uint32_t b = p & ~15u;   // payloads are 16-aligned; an odd p lies inside its block, so look at the block below
    rn_log("CW   %s %08x: block hdr at %08x size|used %08x prev %08x (a pointer at +%x of its payload start)", what, p, b - 16, W(c, b - 16), W(c, b - 12), p - b);
}
static void dump(Ctx *c, const char *what, uint32_t p, int n) {
    if (!heapp(p)) return;
    char line[200];
    for (int o = 0; o < n; o += 16) {
        snprintf(line, sizeof line, "%08x %08x %08x %08x", W(c, p + o), W(c, p + o + 4), W(c, p + o + 8), W(c, p + o + 12));
        rn_log("CW   %s+%02x: %s", what, o, line);
    }
}
static int okpair(Ctx *c, uint32_t v, uint32_t *d, uint32_t *vt) {
    *d = ld(c, v + 8, 4); *vt = (*d & 15) == 0 && heapp(*d) ? ld(c, *d, 4) : 0;
    return (*d & 15) == 0 && heapp(*d) && vtp(*vt);
}
static void history(Ctx *c, uint32_t car) {
    for (int k = 1; k <= NH; k++) {
        int i = (hn + k - 1) % NH;
        for (uint32_t j = 0; j < hist[i].n; j++) if (hist[i].r[j] == car)
            rn_log("CW   frame %u: v %08x [v+8] %08x [[v+8]] %08x", hist[i].frame, hist[i].v[j], hist[i].d[j], hist[i].vt[j]);
    }
}

void crashwatch_present(Ctx *c) {
    if (on < 0) on = rn_env("RN_CRASHWATCH", 0) != 0;
    if (!on) return;
    if (fill < 0) fill = rn_env("RN_CWFILL", 0) != 0;
    uint32_t L = ld(c, 0x7361f8, 4);
    if (!heapp(L)) return;
    uint32_t lo = ld(c, L + 0x24, 4), hi = ld(c, L + 0x18, 4), n = 0, f = rn_telem.presents;
#ifdef RN_STW
    memset(rn_stw_bm, 0, sizeof rn_stw_bm); nw = 0;
#endif
    int slot = hn % NH;
    hist[slot].frame = f;
    for (uint32_t i = lo; i < hi && i < lo + NC; i++) {
        uint32_t r = ld(c, L + 0x28 + 4 * i, 4);
        if (!heapp(r)) continue;
        uint32_t e = ld(c, r + 0x14, 4), kind = e >= LOW && e < GUEST_MEM - 8 ? ld(c, e + 4, 4) : 0, v = ld(c, r + 0x2c, 4), d = 0, vt = 0;
        if (!heapp(v)) continue;
        int ok = okpair(c, v, &d, &vt);
        if (kind < 4 && !kind0[kind]) {
            kind0[kind] = v;
            rn_log("CW first car of kind %u: car %08x v %08x vtable %08x [v+8] %08x [[v+8]] %08x ok %d", kind, r, v, ld(c, v, 4), d, vt, ok);
            hdr(c, "v", v);
        }
#ifdef RN_STW
        if (nw < NC && v < HEAP_LO + (64u << 20) - 16) {
            wv[nw++] = v;
            uint32_t o = v - HEAP_LO;
            rn_stw_bm[o >> 6] |= 1u << ((o >> 3) & 7);
            rn_stw_bm[(o + 8) >> 6] |= 1u << (((o + 8) >> 3) & 7);
        }
#endif
        if (kind == 2 || kind == 3) {   // the decider cache of 0x458bd0: 8 dwords at v+0xc, bit 0 = in use; all 8 in use = the path that wrote [v+8]
            int all = 1;
            for (int k = 0; k < 8; k++) all &= (int)(ld(c, v + 0xc + 4 * k, 4) & 1);
            seen[kind]++; full[kind] += all;
            if (kind == 3 && fill) for (int k = 0; k < 8; k++) st(c, v + 0xc + 4 * k, (uint32_t)k << 2 | 1, 4);   // RN_CWFILL=1: a stress test, every traffic cache full at each Present
        }
        hist[slot].r[n] = r; hist[slot].v[n] = v; hist[slot].d[n] = d; hist[slot].vt[n] = vt; n++;
        if (!ok && said < 3 && (kind == 2 || kind == 3)) {   // the player's driver is another class
            said++;
            rn_log("CW BAD frame %u car %08x kind %u v %08x vtable %08x [v+8] %08x [[v+8]] %08x", f, r, kind, v, ld(c, v, 4), d, vt);
            hdr(c, "v", v); hdr(c, "v+8", d);
            dump(c, "v", v, 0x60);
            history(c, r);
        }
    }
    hist[slot].n = n;
    hn++;
    if (f % 1200 == 0) rn_log("CW decider cache full (8 of 8 slots) in car-frames: racers %u of %u, traffic %u of %u; the fix path (cave 0x797280) ran %u times", full[2], seen[2], full[3], seen[3], ld(c, 0x7977f0, 4));
}

// Called by rn_stop: the registers at the stop. 0x5838c3 has v in esi and [v+8] in ecx; 0x44c56e has v in ebx and [v+8] in ecx.
void crashwatch_stop(Ctx *c) {
    if (on < 0) on = rn_env("RN_CRASHWATCH", 0) != 0;
    if (!on) return;
    const char *nm[8] = {"eax", "ecx", "edx", "ebx", "esp", "ebp", "esi", "edi"};
    for (int k = 0; k < 8; k++) {
        uint32_t p = c->r[k];
        if (k == 4 || !heapp(p)) continue;
        rn_log("CW STOP %s %08x vtable-slot %08x", nm[k], p, W(c, p));
        hdr(c, nm[k], p);
    }
    uint32_t v = c->halt_at == 0x5838c3 ? c->r[6] : c->r[3];
    rn_log("CW STOP v=%08x [v]=%08x [v+4]=%08x [v+8]=%08x [v+0x3f8]=%08x", v, W(c, v), W(c, v + 4), W(c, v + 8), W(c, v + 0x3f8));
    dump(c, "v", v, 0x60);
    dump(c, "v-0x20", v - 0x20, 0x20);
    uint32_t car = W(c, v + 4);
    if (heapp(car)) history(c, car);
}

static void stack(Ctx *c, const char *tag) {
    char line[256] = "";
    int n = 0;
    uint32_t hi = ld(c, c->fs + 4, 4);
    for (uint32_t a = c->r[ESP]; a + 4 <= hi && n < 10; a += 4) {
        uint32_t v = ld(c, a, 4);
        if (v < 0x401006 || v >= 0x697000) continue;
        const uint8_t *p = c->mem + v;
        if (p[-5] == 0xe8 || (p[-2] == 0xff && (p[-1] & 0x38) == 0x10) || (p[-6] == 0xff && (p[-5] & 0x38) == 0x10) ||
            (p[-3] == 0xff && (p[-2] & 0x38) == 0x10) || (p[-7] == 0xff && (p[-6] & 0x38) == 0x10)) {
            snprintf(line + strlen(line), sizeof line - strlen(line), " %08x", v);
            n++;
        }
    }
    rn_log("CW   %s stack(esp %08x, may be stale):%s", tag, c->r[ESP], line);
}

#ifdef RN_STW
static int stw_said;
void rn_stw_hit(Ctx *c, uint32_t a, uint32_t v, int n) {
    for (uint32_t k = 0; k < nw; k++) {
        uint32_t w = wv[k];
        if (a + n <= w || a >= w + 12) continue;
        if (n == 4 && a == w + 8 && (v & 15) == 0 && heapp(v)) return;   // a normal pointer write
        if (stw_said++ >= 60) return;
        rn_log("CW STW frame %u: store %d bytes %08x -> [%08x] (v %08x +%x, old %08x) by guest pc %08x%s", rn_telem.presents, n, v, a, w, a - w,
               ld(c, a, 4), c->halt_at, c->halt_at >= 0x401000 && c->halt_at < 0x697000 ? "" : " (a host API or the host)");
        stack(c, "store");
        return;
    }
}
#endif

// win32.c heap_free: a freed block that is a watched AIVehicle (v = payload start).
void crashwatch_free(Ctx *c, uint32_t p) {
#ifdef RN_STW
    for (uint32_t k = 0; k < nw; k++) if (wv[k] == p) {
        if (stw_said++ < 60) { rn_log("CW FREE of v %08x at frame %u by guest pc %08x", p, rn_telem.presents, c->halt_at); stack(c, "free"); }
        return;
    }
#else
    (void)c; (void)p;
#endif
}
