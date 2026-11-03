// Native vs lifted 0x5c85c1 on random descriptors and cursors (no calls besides itself).
#include "gen2.c"
#include <stdio.h>
#include <stdlib.h>
volatile int rn_preempt; void gil_preempt(void) {}
void rn_call(Ctx *c, uint32_t t) { c->halt = 1; c->why = "call"; }
#define MEMSZ 0x2000000u
#define H 0x1800000u
#define STK 0x1ff0000u
static uint64_t rs; static uint32_t rnd(void) { rs ^= rs << 13; rs ^= rs >> 7; rs ^= rs << 17; return (uint32_t)rs; }
int main(int argc, char **argv) {
    int N = atoi(argv[1]); uint8_t *mem = calloc(MEMSZ, 1), *m0 = malloc(MEMSZ - H), *m1 = malloc(MEMSZ - H);
    int nat = 0, fb = 0, bad = 0;
    for (int cs = 0; cs < N; cs++) {
        rs = 0xabcdefull + cs * 104729ull;
        for (uint32_t a = H; a < H + 0x20000; a += 4) { uint32_t v = rnd(); if ((rnd() & 15) == 0) v = 0x7f800001u | (rnd() & 0x3fffff); memcpy(mem + a, &v, 4); }
        memset(mem + STK - 0x1000, 0, 0x2000);
        #define W(a, v) do { uint32_t _v = (v); memcpy(mem + (a), &_v, 4); } while (0)
        uint32_t D = H + 0x100, cur = STK + 0x100;               // cursors live in the caller's frame, above ours
        W(D, (rnd() & 7) == 0 ? rnd() % 6 : 3); W(D + 4, (rnd() & 7) == 0 ? rnd() % 7 : rnd() & 3);
        W(D + 0x10, rnd() % 4); W(D + 0x14, rnd() % 6); W(D + 0x18, rnd() % 6);
        W(cur, D); W(cur + 4, H + 0x1000 + (rnd() & 0xff) * 4); W(cur + 8, H + 0x8000 + (rnd() & 0xff) * 4); W(cur + 12, rnd() % 40);
        uint32_t sp = STK; W(sp, 0x1fffff0); W(sp + 4, cur); W(sp + 8, cur + 4); W(sp + 12, cur + 8); W(sp + 16, cur + 12);
        Ctx c0; memset(&c0, 0, sizeof c0);
        for (int k = 0; k < 8; k++) c0.r[k] = rnd();
        c0.r[4] = sp; c0.mem = mem; c0.memsz = MEMSZ; c0.fcw = 0x27f; c0.ftop = rnd() & 7;
        for (int k = 0; k < 8; k++) c0.st[k] = findef();
        if (rnd() & 1) c0.ftag = 1u << (rnd() & 7);
        c0.cf = rnd() & 1; c0.zf = rnd() & 1; c0.af = rnd() & 1;
        memcpy(m0, mem + H, MEMSZ - H);
        Ctx ca = c0; int ok = nat_5c85c1(&ca);
        if (!ok) { fb++; if (memcmp(&ca, &c0, sizeof ca) || memcmp(m0, mem + H, MEMSZ - H)) { bad++; printf("fallback touched %d\n", cs); } continue; }
        nat++; memcpy(m1, mem + H, MEMSZ - H); memcpy(mem + H, m0, MEMSZ - H);
        Ctx cb = c0; f_5c85c1_lift(&cb);
        int d = memcmp(&ca, &cb, sizeof ca) != 0 || memcmp(m1, mem + H, MEMSZ - H) != 0;
        if (d && bad < 4) {
            printf("MISMATCH %d type %u cls %u n %u cols %u rows %u left %u\n", cs, ld(&c0, D, 4), ld(&c0, D + 4, 4), ld(&c0, D + 0x10, 4), ld(&c0, D + 0x14, 4), ld(&c0, D + 0x18, 4), ld(&c0, cur + 12, 4));
            for (int k = 0; k < 8; k++) if (ca.r[k] != cb.r[k]) printf("  r%d %08x vs %08x\n", k, ca.r[k], cb.r[k]);
            printf("  flags n %d%d%d%d%d%d l %d%d%d%d%d%d fsw %x/%x\n", ca.cf, ca.zf, ca.sf, ca.of, ca.pf, ca.af, cb.cf, cb.zf, cb.sf, cb.of, cb.pf, cb.af, ca.fsw, cb.fsw);
            for (uint32_t k = 0; k < MEMSZ - H; k++) if (m1[k] != mem[H + k]) { printf("  mem %08x\n", H + k); break; }
        }
        bad += d;
    }
    printf("cases %d: native %d, fallback %d, mismatches %d\n", N, nat, fb, bad);
    return bad != 0;
}
