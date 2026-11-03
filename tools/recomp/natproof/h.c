// Native vs lifted 0x5c97cb on random well-formed D3DX effect states. Device calls are stubs that log and return.
#include "gen.c"
#include <stdio.h>
#include <stdlib.h>
volatile int rn_preempt; void gil_preempt(void) {}
#define MEMSZ 0x2000000u
#define H 0x1800000u
#define STK 0x1ff0000u
#define RETA 0x1fffff0u
static uint64_t rs;
static uint32_t rnd(void) { rs ^= rs << 13; rs ^= rs >> 7; rs ^= rs << 17; return (uint32_t)rs; }
typedef struct { uint32_t t, esp, r[8], a[6]; } Log;
static Log lg[2][64]; static int nl[2], side; static uint64_t callseed;
static int nargs(uint32_t off) {
    switch (off) { case 0xe4: case 0xd4: case 0x104: case 0xb0: case 0x158: case 0xcc: return 3;
    case 0x10c: case 0x114: case 0x178: case 0x180: case 0x188: case 0x1b4: case 0x1bc: case 0x1c4: return 4;
    case 0x164: case 0x15c: case 0x170: case 0x1ac: case 0x13c: case 0x1c: case 0xc4: return 2; case 8: return 1; }
    return -1;
}
void rn_call(Ctx *c, uint32_t t) {
    int n = t >= 0xe0000000u ? nargs(t - 0xe0000000u) : -1;
    if (n < 0) { c->halt = 1; c->why = "stub"; c->halt_at = t; return; }
    Log *L = &lg[side][nl[side]++ & 63];
    L->t = t; L->esp = c->r[4]; memcpy(L->r, c->r, 32);
    for (int k = 0; k < 6; k++) L->a[k] = ld(c, c->r[4] + 4 * k, 4);
    uint64_t z = callseed + 0x9e3779b97f4a7c15ull * nl[side];
    z ^= z >> 31; z *= 0xbf58476d1ce4e5b9ull; z ^= z >> 27;
    c->r[0] = (z & 7) == 0 ? 0x8876086c : (z & 7) == 1 ? (uint32_t)(z >> 32) : 0;
    c->r[1] = (uint32_t)(z >> 8); c->r[2] = (uint32_t)(z >> 16);           // scratch registers clobbered
    c->ret = ld(c, c->r[4], 4); c->r[4] += 4 + 4 * n;
}
void f_5d71f8(Ctx *c) { c->halt = 1; c->why = "stub 5d71f8"; }
static uint8_t *m0, *m1;
int main(int argc, char **argv) {
    int N = argc > 1 ? atoi(argv[1]) : 20000;
    uint8_t *mem = calloc(MEMSZ, 1); m0 = malloc(MEMSZ); m1 = malloc(MEMSZ);
    FILE *f = fopen(argv[2], "rb"); fread(mem + 0x400000, 1, 0x397800, f); fclose(f);
    uint32_t ids[512]; int nid = 0;
    for (uint32_t i = 0; i < 512; i++) { uint32_t s = *(uint32_t *)(mem + 0x6dc274 + 0x1c * i), ty = s >> 24;
        if (ty >= 1 && ty <= 10) ids[nid++] = i; }
    printf("state ids with a type: %d\n", nid);
    int handled = 0, fell = 0, bad = 0, badfb = 0; int bytype[11] = {0};
    for (int cs = 0; cs < N; cs++) {
        rs = 0x1234567ull + cs * 7919ull; callseed = rnd() | (uint64_t)rnd() << 32;
        for (uint32_t a = H; a < H + 0x10000; a += 4) { uint32_t v = rnd(); memcpy(mem + a, &v, 4); }
        memset(mem + STK - 0x2000, 0, 0x3000);
        #define W(a, v) do { uint32_t _v = (v); memcpy(mem + (a), &_v, 4); } while (0)
        uint32_t th = H + 0x100, dev = H + 0x300, vt = H + 0x400;
        W(th + 8, dev); W(dev, vt);
        for (uint32_t k = 0; k < 0x80; k++) W(vt + 4 * k, 0xe0000000u + 4 * k);
        W(th + 0x84, rnd() & 3); W(th + 0x8c, H + 0x1000);
        for (uint32_t k = 0; k < 8; k++) {
            uint32_t P = H + 0x2000 + k * 0x40; W(H + 0x1000 + 4 * k, P);
            W(P + 0x38, rnd() & 1 ? 0 : H + 0x3000); W(P + 0x28, (rnd() & 7) * 4); W(P + 0x24, (rnd() & 7) * 4);
        }
        W(H + 0x3008, H + 0x3100);
        for (uint32_t k = 0; k < 64; k++) { W(H + 0x3100 + 4 * k, rnd() & 15); W(H + 0x4000 + 4 * k, rnd() & 15); W(H + 0x4800 + 4 * k, rnd() & 15); }
        W(th + 0x2c, H + 0x4000); W(th + 0xc, H + 0x5000); W(H + 0x5008, H + 0x4800); W(th + 0x24, H + 0x6000);
        uint32_t rec = H + 0x8000, r = rec, id = ids[rnd() % nid];
        if ((rnd() & 7) == 0) { W(rec, 0xffffffffu); r = H + 0x8100; W(rec + 0x64, r); }
        W(r, id); W(rec + 4, rnd() & 7); W(r + 0xc, rnd() & 7); W(r + 0x14, (rnd() & 7) * 4); W(r + 0x10, (rnd() & 7) * 4);
        uint32_t idx = (rnd() & 3) == 0 ? 0xffffffffu : rnd() & 7;
        uint32_t esp = STK; W(esp, RETA); W(esp + 4, rec); W(esp + 8, idx);
        Ctx c0; memset(&c0, 0, sizeof c0);
        for (int k = 0; k < 8; k++) c0.r[k] = rnd();
        c0.r[1] = th; c0.r[4] = esp; c0.mem = mem; c0.memsz = MEMSZ; c0.fcw = 0x27f;
        c0.cf = rnd() & 1; c0.zf = rnd() & 1; c0.sf = rnd() & 1; c0.of = rnd() & 1; c0.pf = rnd() & 1; c0.af = rnd() & 1;
        memcpy(m0, mem + H, MEMSZ - H);
        Ctx ca = c0; side = 0; nl[0] = 0;
        int ok = nat_5c97cb(&ca);
        if (!ok) {   // fallback must leave everything untouched
            fell++;
            if (memcmp(&ca, &c0, sizeof ca) || memcmp(m0, mem + H, MEMSZ - H) || nl[0]) { badfb++; if (badfb < 5) printf("fallback touched state, case %d id %u\n", cs, id); }
            continue;
        }
        handled++; bytype[*(uint32_t *)(mem + 0x6dc274 + 0x1c * id) >> 24]++;
        memcpy(m1, mem + H, MEMSZ - H); memcpy(mem + H, m0, MEMSZ - H);
        Ctx cb = c0; side = 1; nl[1] = 0;
        f_5c97cb_lift(&cb);
        int d = 0;
        for (int k = 0; k < 8; k++) if (ca.r[k] != cb.r[k]) { d = 1; if (bad < 5) printf("  r%d %08x vs lifted %08x\n", k, ca.r[k], cb.r[k]); }
        if (ca.cf != cb.cf || ca.zf != cb.zf || ca.sf != cb.sf || ca.of != cb.of || ca.pf != cb.pf || ca.af != cb.af || ca.df != cb.df) { d = 1; if (bad < 5) printf("  flags\n"); }
        if (ca.ret != cb.ret || ca.halt != cb.halt) { d = 1; if (bad < 5) printf("  ret %x/%x halt %d/%d\n", ca.ret, cb.ret, ca.halt, cb.halt); }
        if (memcmp(&ca, &cb, sizeof ca)) { d = 1; if (bad < 5) printf("  ctx bytes differ\n"); }
        if (nl[0] != nl[1] || memcmp(lg[0], lg[1], sizeof(Log) * (nl[0] & 63))) { d = 1; if (bad < 5) printf("  device calls differ (%d vs %d)\n", nl[0], nl[1]); }
        for (uint32_t k = 0; k < MEMSZ - H; k++) if (m1[k] != mem[H + k]) { d = 1; if (bad < 5) printf("  mem %08x %02x vs lifted %02x\n", H + k, m1[k], mem[H + k]); break; }
        if (d) { bad++; if (bad < 5) printf("MISMATCH case %d id %u state %08x idx %x x84 %u\n", cs, id, *(uint32_t *)(mem + 0x6dc274 + 0x1c * id), idx, ld(&c0, th + 0x84, 4)); }
    }
    printf("cases %d: native %d (by type:", N, handled);
    for (int t = 1; t <= 10; t++) printf(" %d:%d", t, bytype[t]);
    printf("), fallback %d, mismatches %d, fallback-touched %d\n", fell, bad, badfb);
    return bad || badfb;
}
