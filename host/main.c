// Loads pc/Speed.exe into guest memory the way the Windows loader does, then runs its entry point.
// Usage: speed <Speed.exe> <game dir> [--shot frame.png]
#include "host.h"
#include "gpu.h"

Ctx *g_ctx;
void dispatch_report(void);
void win32_set_root(const char *game_dir);

static uint8_t *read_file(const char *path, long *size) {
    FILE *f = fopen(path, "rb");
    if (!f) return NULL;
    fseek(f, 0, SEEK_END);
    *size = ftell(f);
    fseek(f, 0, SEEK_SET);
    uint8_t *p = malloc(*size);
    if (fread(p, 1, *size, f) != (size_t)*size) { fclose(f); free(p); return NULL; }
    fclose(f);
    return p;
}

// Return addresses on the guest stack: values in .text that follow a call instruction.
static void backtrace(Ctx *c) {
    char line[256] = "";
    int n = 0;
    uint32_t hi = ld(c, c->fs + 4, 4);
    for (uint32_t a = c->r[ESP]; a + 4 <= hi && n < 12; a += 4) {
        uint32_t v = ld(c, a, 4);
        if (v < 0x401006 || v >= 0x697000) continue;
        const uint8_t *p = c->mem + v;
        if (p[-5] == 0xe8 || (p[-2] == 0xff && (p[-1] & 0x38) == 0x10) || (p[-6] == 0xff && (p[-5] & 0x38) == 0x10) ||
            (p[-3] == 0xff && (p[-2] & 0x38) == 0x10) || (p[-7] == 0xff && (p[-6] & 0x38) == 0x10)) {
            snprintf(line + strlen(line), sizeof line - strlen(line), " %08x", v);
            n++;
        }
    }
    rn_log("stack:%s", line);
}

static uint32_t rd32(const uint8_t *p) { uint32_t v; memcpy(&v, p, 4); return v; }
static uint16_t rd16(const uint8_t *p) { uint16_t v; memcpy(&v, p, 2); return v; }

int main(int argc, char **argv) {
    if (argc < 3) { fprintf(stderr, "usage: speed <Speed.exe> <game dir>\n"); return 2; }
    long fsize;
    uint8_t *pe = read_file(argv[1], &fsize);
    if (!pe) { fprintf(stderr, "cannot read %s\n", argv[1]); return 2; }
    win32_set_root(argv[2]);
    if (argc > 4 && !strcmp(argv[3], "--shot")) gpu_set_shot(argv[4]);

    static Ctx ctx;
    Ctx *c = g_ctx = &ctx;
    c->memsz = GUEST_MEM;
    c->mem = calloc(1, GUEST_MEM);
    if (!c->mem) { fprintf(stderr, "cannot allocate guest memory\n"); return 2; }

    const uint8_t *nt = pe + rd32(pe + 0x3c);
    const uint8_t *opt = nt + 24;
    uint32_t nsec = rd16(nt + 6), optsz = rd16(nt + 20);
    uint32_t base = rd32(opt + 28), image_size = rd32(opt + 56), hdr_size = rd32(opt + 60);
    uint32_t entry = base + rd32(opt + 16);
    if (base != IMAGE_BASE) { fprintf(stderr, "unexpected image base %08x\n", base); return 2; }
    memcpy(c->mem + base, pe, hdr_size);
    const uint8_t *sec = opt + optsz;
    for (uint32_t k = 0; k < nsec; k++, sec += 40) {
        uint32_t va = rd32(sec + 12), raw = rd32(sec + 16), off = rd32(sec + 20);
        memcpy(c->mem + base + va, pe + off, raw);
    }

    // Imports: every IAT slot gets the fake address of its host function.
    uint32_t imp = rd32(opt + 104);
    for (uint8_t *d = c->mem + base + imp; rd32(d + 12); d += 20) {
        const char *dll = (const char *)c->mem + base + rd32(d + 12);
        uint32_t names = rd32(d) ? rd32(d) : rd32(d + 16), iat = rd32(d + 16);
        for (uint32_t k = 0;; k++) {
            uint32_t t = rd32(c->mem + base + names + 4 * k);
            if (!t) break;
            char ord[16];
            const char *name = ord;
            if (t & 0x80000000u) snprintf(ord, sizeof ord, "#%u", t & 0xffff);
            else name = (const char *)c->mem + base + t + 2;
            st(c, base + iat + 4 * k, host_addr_of(dll, name), 4);
        }
    }

    win32_init(c, image_size);
    threads_init(c);
    finit(c);
    c->fcw = 0x27f;              // Windows starts threads with 53-bit precision, all exceptions masked
    c->r[ESP] = STACK_HI - 16;
    c->r[ESP] -= 4;
    st(c, c->r[ESP], host_addr_of("rn", "entry_returned"), 4);
    rn_log("Speed.exe loaded: entry %08x, %u sections, guest memory %u MB", entry, nsec, GUEST_MEM >> 20);
    rn_call(c, entry);
    rn_stop(c);
    return 0;
}

// Called with the GIL held by the thread that stopped: report and end every thread.
void rn_stop(Ctx *c) {
    dispatch_report();
    rn_log("STOP in thread %x at %08x: %s", ld(c, c->fs + 0x24, 4), c->halt_at, c->why ? c->why : "(no reason)");
    rn_log("eax=%08x ecx=%08x edx=%08x ebx=%08x esp=%08x ebp=%08x esi=%08x edi=%08x",
           c->r[0], c->r[1], c->r[2], c->r[3], c->r[4], c->r[5], c->r[6], c->r[7]);
    backtrace(c);
    exit(0);
}
