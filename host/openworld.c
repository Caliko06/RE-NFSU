// Open world, phase D1 (docs/OPENWORLD.md). Native only; everything is off unless RN_WORLD=1.
//
// 1. File redirect: with RN_WORLD=1 the game's TRACKS\TRACKB<id>.LZC of the 16 L1RA street tracks is served from the merged
//    copy tools/openworld/build.py wrote (build/openworld/TRACKB<id>.lzc, or RN_WORLD_DIR): one collision world for the whole
//    city, no fences, no streaming chunks 0x34153/0x34154. gf_open (host/files.c) asks rn_world_open before its lookup.
// 2. Test only, RN_WORLD_AT="log" (only logs) or "x,y,z,yaw16": once the car has driven RN_WORLD_MOVE metres from the grid (default 120; and RN_WORLD_WAIT presents have passed, default 0) the player car is
//    put there with the game's own Car::ResetToPosition 0x427e60 (ecx = car, edx = vec3*, eax = yaw as the s16 at car+0x3b4,
//    2 stack args as the start in 0x422eb0 pushes: 0, 0). 0x427e60 -> 0x427c50 -> PutFlatOnTrack 0x4278d0 queries the ground.
//    Then the car's position and the ground query 0x440a40(obj = car+0x540, pos, 0, 0, &flag) (flag byte 1 = a polygon found, 0 = no ground and the
//    height is the z it was given; the height comes back on the FPU) are logged each RN_WORLD_LOG presents (default 60). No hook in d3d9.c is allowed in
//    this phase, so a host thread takes the GIL every 20 ms (it runs when the main thread passes the GIL, as the winmm timer
//    threads do) and calls the guest on its own context (own stack and TEB).
#ifndef __EMSCRIPTEN__
#include <ctype.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include "host.h"

static int enabled(void) {
    static int on = -1;
    if (on < 0) { const char *e = getenv("RN_WORLD"); on = e && *e && *e != '0'; }
    return on;
}

static int ci_eq(const char *a, const char *b, size_t n) {
    for (size_t k = 0; k < n; k++) if (tolower((unsigned char)a[k]) != tolower((unsigned char)b[k])) return 0;
    return 1;
}

static void *tp_thread(void *arg);
static void tp_start(void) {
    static int started;
    if (started || !getenv("RN_WORLD_AT")) return;
    started = 1;
    pthread_t t;
    pthread_create(&t, NULL, tp_thread, NULL);
    pthread_detach(t);
}

// gpath ends in TRACKB<id>.LZC (any case, any folder): the merged file when it exists. 1 = served (real and size are set).
int rn_world_open(const char *gpath, char *real, size_t n, uint64_t *size) {
    tp_start();   // RN_WORLD_AT also runs on the original TRACKB (the A/B run: RN_WORLD_AT=log only logs)
    if (!enabled()) return 0;
    const char *b = gpath;
    for (const char *p = gpath; *p; p++) if (*p == '/' || *p == '\\') b = p + 1;
    if (!ci_eq(b, "TRACKB", 6) || !isdigit((unsigned char)b[6])) return 0;
    const char *e = b + 6;
    unsigned id = 0;
    while (isdigit((unsigned char)*e)) id = id * 10 + (unsigned)(*e++ - '0');
    if (!ci_eq(e, ".LZC", 5)) return 0;
    const char *dir = getenv("RN_WORLD_DIR");
    snprintf(real, n, "%s/TRACKB%u.lzc", dir && *dir ? dir : "build/openworld", id);
    struct stat sb;
    if (stat(real, &sb) || !S_ISREG(sb.st_mode)) { rn_log("OPENWORLD: no merged file %s, the original TRACKB%u is used", real, id); return 0; }
    *size = (uint64_t)sb.st_size;
    rn_log("OPENWORLD: %s -> %s (%llu bytes)", gpath, real, (unsigned long long)sb.st_size);
    return 1;
}

// ---- the test teleport ------------------------------------------------------------------------------------------------
static Ctx tc;                  // the thread's guest context
static uint32_t scratch;        // vec3 at +0, flag byte at +32

static int ctx_make(void) {
    Ctx *m = g_ctx;
    if (!m) return 0;
    tc = *m;
    memset(tc.r, 0, sizeof tc.r);
    tc.halt = 0;
    tc.cf = tc.zf = tc.sf = tc.of = tc.pf = tc.df = tc.af = 0;
    tc.fcw = 0x27f; tc.fsw = 0; tc.ftop = 0; tc.ftag = 0;
    uint32_t teb = guest_alloc(0x1000), lo = guest_alloc(0x80000), hi = lo + 0x80000;
    if (!teb || !lo) return 0;
    memcpy(tc.mem + teb, tc.mem + m->fs, 0x1000);
    tc.fs = teb;
    st(&tc, teb + 0x00, 0xffffffffu, 4);
    st(&tc, teb + 0x04, hi, 4);
    st(&tc, teb + 0x08, lo, 4);
    st(&tc, teb + 0x18, teb, 4);
    st(&tc, teb + 0x24, 0x7f0, 4);
    st(&tc, teb + 0x2c, teb + 0xe10, 4);
    tc.r[ESP] = hi - 64;
    scratch = guest_alloc(64);
    return scratch != 0;
}

// The player's node in the race list [0x7361f8] (host/free.c): its entrant (+0x14) has kind 1 at +4.
static uint32_t player_node(Ctx *c) {
    uint32_t h = ld(c, 0x7361f8, 4);
    if (!h || h >= GUEST_MEM - 0x1000) return 0;
    for (uint32_t r = ld(c, h, 4), k = 0; r && r != h && r < GUEST_MEM - 0x1000 && k < 200; r = ld(c, r, 4), k++) {
        uint32_t e = ld(c, r + 0x14, 4);
        if (e && e < GUEST_MEM - 16 && ld(c, e + 4, 4) == 1) return r;
    }
    return 0;
}

// The ground under p (3 floats in guest memory) by the game's own query on the car's cache object. Returns 1 with a height.
static int ground_at(uint32_t car, uint32_t p, float *h, int *flag) {
    st(&tc, scratch + 32, 0, 4);
    uint32_t a[5] = {car + 0x540, p, 0, 0, scratch + 32};
    uint32_t ft = tc.ftop;
    call_guest(&tc, 0x440a40, 5, a);
    *h = (float)*fr(&tc, 0);
    fpop(&tc);
    tc.ftop = ft;
    *flag = (int)ld(&tc, scratch + 32, 1);
    return *flag != 0;
}

static void dump(Ctx *c, const char *what, uint32_t node, uint32_t car) {
    float h = 0; int flag = 0, ok = 0;
    if (car) ok = ground_at(car, car + 0x60, &h, &flag);
    rn_log("OPENWORLD %s: frame %u node %08x pos %.2f %.2f %.2f | car %08x (player view obj [0x740500] %08x) pos %.2f %.2f %.2f yaw16 %d | game ground query 0x440a40 at the car: %s height %.2f (flag byte %d)",
           what, rn_telem.presents, node, ldf(c, node + 0x50), ldf(c, node + 0x54), ldf(c, node + 0x58), car, ld(c, 0x740500, 4),
           ldf(c, car + 0x60), ldf(c, car + 0x64), ldf(c, car + 0x68), (int16_t)ld(c, car + 0x3b4, 2), ok ? "GROUND" : "NO GROUND", h, flag);
}

static void *tp_thread(void *arg) {
    (void)arg;
    float at[4] = {0};
    int nat = strcmp(getenv("RN_WORLD_AT"), "log") ? sscanf(getenv("RN_WORLD_AT"), "%f,%f,%f,%f", &at[0], &at[1], &at[2], &at[3]) : -1;
    const char *w = getenv("RN_WORLD_WAIT"), *l = getenv("RN_WORLD_LOG");
    unsigned wait = w ? (unsigned)atoi(w) : 0, every = l && atoi(l) > 0 ? (unsigned)atoi(l) : 60;
    if (nat >= 0 && nat < 3) { rn_log("OPENWORLD: cannot read RN_WORLD_AT \"%s\" (x,y,z[,yaw16])", getenv("RN_WORLD_AT")); return NULL; }
    const char *mv = getenv("RN_WORLD_MOVE");
    float move = mv ? (float)atof(mv) : 120;     // the race has started (the start in 0x422eb0 resets cars at GO) once the car left the grid by this much
    unsigned raced = 0, last = 0;
    float p0[2] = {0, 0};
    int done = 0, made = 0, have0 = 0;
    for (;;) {
        usleep(20000);
        gil_acquire();
        Ctx *c = g_ctx;
        if (c && !c->halt) {
            if (ld(c, 0x77a920, 4) != 6) { raced = 0; }
            else {
                if (!raced) raced = rn_telem.presents + 1;
                if (!made) made = ctx_make();
                uint32_t node = made ? player_node(c) : 0;
                uint32_t car = node;   // the list node is the car object itself (its +0x60 is the position 0x422eb0 reads from [[0x7361f8]+0x28])
                if (car && car < GUEST_MEM - 0x1000) {
                    unsigned age = rn_telem.presents - raced;
                    if (!have0) { p0[0] = ldf(c, car + 0x60); p0[1] = ldf(c, car + 0x64); have0 = 1; }
                    int moved = hypotf(ldf(c, car + 0x60) - p0[0], ldf(c, car + 0x64) - p0[1]) >= move;
                    if (age >= wait && moved && !done && nat >= 3) {
                        dump(c, "before", node, car);
                        stf(&tc, scratch, at[0]); stf(&tc, scratch + 4, at[1]); stf(&tc, scratch + 8, at[2]);
                        uint32_t a[2] = {0, 0};
                        tc.r[ECX] = car; tc.r[EDX] = scratch; tc.r[EAX] = nat > 3 ? (uint32_t)(int32_t)at[3] : ld(c, car + 0x3b4, 2);
                        call_guest(&tc, 0x427e60, 2, a);
                        // the streamer's viewer, as the start in 0x422eb0 seeds it: 0x444840(eax = 0, edx = 0x77a980, ecx = &car pos)
                        tc.r[EAX] = 0; tc.r[EDX] = 0x77a980; tc.r[ECX] = car + 0x60;
                        call_guest(&tc, 0x444840, 0, NULL);
                        done = 1;
                        rn_log("OPENWORLD: teleport asked %.1f %.1f %.1f yaw %d, halt %u at %08x %s", at[0], at[1], at[2], nat > 3 ? (int)at[3] : -1, tc.halt, tc.halt_at, tc.why ? tc.why : "");
                        if (tc.halt) { tc.halt = 0; tc.why = NULL; tc.r[ESP] = ld(&tc, tc.fs + 4, 4) - 64; }
                        dump(c, "after", node, car);
                        last = rn_telem.presents;
                    } else if (rn_telem.presents - last >= every) {
                        dump(c, done ? "run" : "wait", node, car);
                        last = rn_telem.presents;
                    }
                }
            }
        }
        gil_release();
    }
    return NULL;
}
#endif
