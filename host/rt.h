// Guest CPU state and helpers shared by the lifted code (build/gen) and the host layer.
#pragma once
#include <stdint.h>
#include <string.h>
#include <math.h>

enum { EAX, ECX, EDX, EBX, ESP, EBP, ESI, EDI };

typedef struct Ctx {
    uint32_t r[8];
    uint8_t *mem;               // guest address 0 = mem[0]; flat 32-bit space
    uint32_t memsz;
    uint32_t ret;               // return address popped by the last `ret`
    uint32_t halt, halt_at;     // halt != 0: stop everything, halt_at = guest address
    const char *why;
    uint32_t fs;                // TEB guest address
    int32_t cf, zf, sf, of, pf, df;
    uint32_t eflx;              // eflags bits we only store (AC, ID)
    uint32_t fcw, fsw, ftop, ftag;  // fsw keeps C0..C3 only; ftag bit i = physical st i in use
    double st[8];
} Ctx;

// Guest pages below 64 KB are never mapped: a null pointer read is a loud fault.
#define LOW 0x10000u
#define CHK(a, n, at) do { if ((uint32_t)((a) - LOW) > c->memsz - LOW - (n)) { c->halt_at = (at); c->why = "memory fault"; goto trap; } } while (0)
#define TRAP(at, msg) do { c->halt_at = (at); c->why = (msg); goto trap; } while (0)

static inline uint32_t ld(Ctx *c, uint32_t a, int n) { uint32_t v = 0; memcpy(&v, c->mem + a, n); return v; }
static inline void st(Ctx *c, uint32_t a, uint32_t v, int n) { memcpy(c->mem + a, &v, n); }
static inline float ldf(Ctx *c, uint32_t a) { float v; memcpy(&v, c->mem + a, 4); return v; }
static inline double ldd(Ctx *c, uint32_t a) { double v; memcpy(&v, c->mem + a, 8); return v; }
static inline void stf(Ctx *c, uint32_t a, float v) { memcpy(c->mem + a, &v, 4); }
static inline void std_(Ctx *c, uint32_t a, double v) { memcpy(c->mem + a, &v, 8); }
static inline uint64_t ld64(Ctx *c, uint32_t a) { uint64_t v; memcpy(&v, c->mem + a, 8); return v; }
static inline void st64(Ctx *c, uint32_t a, uint64_t v) { memcpy(c->mem + a, &v, 8); }
static inline int par(uint32_t v) { return !__builtin_parity(v & 0xffu); }

// Calls any guest or host address. Defined in host/dispatch.c.
void rn_call(Ctx *c, uint32_t target);
uint64_t rn_rdtsc(Ctx *c);
void rn_cpuid(Ctx *c, uint32_t *a, uint32_t *b, uint32_t *cc, uint32_t *d);

// ---- x87 ----------------------------------------------------------------
// Registers are doubles: precision control 24 bits rounds to float, 53 and 64 bits keep double.
#define FC0 0x100u
#define FC2 0x400u
#define FC3 0x4000u
static inline double *fr(Ctx *c, int i) { return &c->st[(c->ftop + i) & 7]; }
static inline double fround(Ctx *c, double v) { return ((c->fcw >> 8) & 3) == 0 ? (double)(float)v : v; }
static inline void fpush(Ctx *c, double v) { c->ftop = (c->ftop - 1) & 7; c->st[c->ftop] = v; c->ftag |= 1u << c->ftop; }
static inline void fpop(Ctx *c) { c->ftag &= ~(1u << c->ftop); c->ftop = (c->ftop + 1) & 7; }
// An invalid operation (inf-inf, 0*inf...) makes the x87 "real indefinite", a negative quiet NaN.
// The host makes +NaN (ARM, wasm on ARM): turn its default NaN into the x87 one.
static inline double fixnan(double v) {
    uint64_t b;
    memcpy(&b, &v, 8);
    if (b == 0x7ff8000000000000ull) { b = 0xfff8000000000000ull; memcpy(&v, &b, 8); }
    return v;
}
static inline void fset(Ctx *c, int i, double v) { *fr(c, i) = fround(c, v != v ? fixnan(v) : v); }
static inline void fcom(Ctx *c, double a, double b) {
    c->fsw &= ~(FC0 | FC2 | FC3);
    if (a != a || b != b) c->fsw |= FC0 | FC2 | FC3;
    else if (a < b) c->fsw |= FC0;
    else if (a == b) c->fsw |= FC3;
}
static inline uint16_t fstsw(Ctx *c) { return (uint16_t)((c->fsw & ~0x3800u) | (c->ftop << 11)); }
static inline double frnd(Ctx *c, double v) {
    switch ((c->fcw >> 10) & 3) {
    case 0: return nearbyint(v);
    case 1: return floor(v);
    case 2: return ceil(v);
    default: return trunc(v);
    }
}
// Integer store: out of range gives the "integer indefinite" value, like the FPU with IM masked.
static inline int64_t fist(Ctx *c, double v, int bits, int truncate) {
    double r = truncate ? trunc(v) : frnd(c, v);
    double lim = ldexp(1.0, bits - 1);
    if (!(r >= -lim && r < lim)) return (int64_t)((uint64_t)1 << (bits - 1));
    return (int64_t)r;
}
static inline double ld80(Ctx *c, uint32_t a) {
    uint64_t m; uint16_t se;
    memcpy(&m, c->mem + a, 8); memcpy(&se, c->mem + a + 8, 2);
    int e = se & 0x7fff; double s = (se & 0x8000) ? -1.0 : 1.0;
    if (e == 0 && m == 0) return s * 0.0;
    if (e == 0x7fff) return (m << 1) ? NAN : s * INFINITY;
    return s * ldexp((double)m, e - 16383 - 63);
}
static inline void st80(Ctx *c, uint32_t a, double v) {
    uint64_t m = 0; uint16_t se = signbit(v) ? 0x8000 : 0;
    if (isnan(v)) { se |= 0x7fff; m = 0xc000000000000000ull; }
    else if (isinf(v)) { se |= 0x7fff; m = 0x8000000000000000ull; }
    else if (v != 0) {
        int e; double f = frexp(fabs(v), &e);           // f in [0.5,1)
        m = (uint64_t)ldexp(f, 64); se |= (uint16_t)(e - 1 + 16383);
    }
    memcpy(c->mem + a, &m, 8); memcpy(c->mem + a + 8, &se, 2);
}
static inline void fxam(Ctx *c) {
    double v = *fr(c, 0);
    uint32_t s = signbit(v) ? 0x200u : 0;      // C1 = sign
    c->fsw &= ~(FC0 | 0x200u | FC2 | FC3);
    if (!(c->ftag & (1u << c->ftop))) c->fsw |= FC3 | FC0 | s;
    else if (isnan(v)) c->fsw |= FC0 | s;
    else if (isinf(v)) c->fsw |= FC2 | FC0 | s;
    else if (v == 0) c->fsw |= FC3 | s;
    else c->fsw |= FC2 | s;
}
