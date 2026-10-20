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
    int32_t cf, zf, sf, of, pf, df, af;
    uint32_t eflx;              // eflags bits we only store (AC, ID)
    uint32_t fcw, fsw, ftop, ftag;  // fsw keeps C0..C3 only; ftag bit i = physical st i in use
    double st[8];
    uint32_t mb;                // base of the live ABK code module the called lifted function belongs to
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
// ABK code modules lifted ahead of time (tools/recomp/abk.py -> build/gen/abk.c). Defined in host/abk.c.
typedef struct { uint32_t id, size, nfn; const uint32_t *off; void (*const *fn)(Ctx *); } RnMod;
void (*rn_mod_find(Ctx *c, uint32_t target, uint32_t *mb))(Ctx *);
uint64_t rn_rdtsc(Ctx *c);
void rn_cpuid(Ctx *c, uint32_t *a, uint32_t *b, uint32_t *cc, uint32_t *d);

// ---- x87 ----------------------------------------------------------------
// Registers are doubles: precision control 24 bits rounds to float, 53 and 64 bits keep double.
#define FC0 0x100u
#define FC2 0x400u
#define FC3 0x4000u
static inline double *fr(Ctx *c, int i) { return &c->st[(c->ftop + i) & 7]; }
static inline double fround(Ctx *c, double v) { return ((c->fcw >> 8) & 3) == 0 ? (double)(float)v : v; }
// NaN results follow the x87 rules (Intel SDM table 4-7), not the host's: an invalid operation on
// non-NaN operands gives the "real indefinite" (-NaN); NaN operands propagate quieted, the larger
// significand wins and a tie takes the positive one.
static inline uint64_t dbits(double v) { uint64_t b; memcpy(&b, &v, 8); return b; }
static inline double bitsd(uint64_t b) { double v; memcpy(&v, &b, 8); return v; }
static inline double fnan2(double a, double b) {
    if (a == a) return bitsd(dbits(b) | 0x8000000000000ull);
    if (b == b) return bitsd(dbits(a) | 0x8000000000000ull);
    uint64_t x = dbits(a) | 0x8000000000000ull, y = dbits(b) | 0x8000000000000ull;
    uint64_t mx = x & 0xfffffffffffffull, my = y & 0xfffffffffffffull;
    if (mx != my) return bitsd(mx > my ? x : y);
    return bitsd(x < y ? x : y);     // same significand: the one without the sign bit
}
#ifdef RN_REF_QEMU5
#define FIE 0x00u     // difftest only: QEMU 5 (Unicorn) never raises IE; the SDM does
#else
#define FIE 0x01u     // invalid operation
#endif
#define FZE 0x04u     // zero divide
#define FSF 0x40u     // stack fault
// Results of x87 arithmetic: NaN rules above; an invalid operation on non-NaN operands also sets IE.
static inline double fx2(Ctx *c, double a, double b, double r) {
    if (r == r) return r;
    if (a != a || b != b) return fnan2(a, b);
    c->fsw |= FIE;
    return bitsd(0xfff8000000000000ull);
}
static inline double fx1(Ctx *c, double a, double r) {
    if (r == r) return r;
    if (a != a) return bitsd(dbits(a) | 0x8000000000000ull);
    c->fsw |= FIE;
    return bitsd(0xfff8000000000000ull);
}
static inline double fdiv_(Ctx *c, double a, double b) {
#ifdef RN_REF_QEMU5
    if (b == 0) c->fsw |= FZE;      // difftest only: the reference CPU flags every x/0, and never IE
#else
    if (b == 0 && a == a && a != 0 && !isinf(a)) c->fsw |= FZE;     // finite non-zero / 0
#endif
    return fx2(c, a, b, a / b);
}
#define FADD(a, b) fx2(c, (a), (b), (a) + (b))
#define FSUB(a, b) fx2(c, (a), (b), (a) - (b))
#define FMUL(a, b) fx2(c, (a), (b), (a) * (b))
#define FDIV(a, b) fdiv_(c, (a), (b))

// Stack faults are masked on Windows: an empty register reads as the "real indefinite" (-NaN), and a push
// onto a full register loads it too. Keeping every empty slot at that value gives both for free.
static inline double findef(void) { uint64_t b = 0xfff8000000000000ull; double v; memcpy(&v, &b, 8); return v; }
static inline void fpush(Ctx *c, double v) {
    c->ftop = (c->ftop - 1) & 7;
    if (c->ftag & (1u << c->ftop)) { v = findef(); c->fsw |= FIE | FSF | 0x200u; }
    c->st[c->ftop] = v;
    c->ftag |= 1u << c->ftop;
}
static inline void fpop(Ctx *c) { c->st[c->ftop] = findef(); c->ftag &= ~(1u << c->ftop); c->ftop = (c->ftop + 1) & 7; }
static inline void ffree(Ctx *c, int i) { *fr(c, i) = findef(); c->ftag &= ~(1u << ((c->ftop + i) & 7)); }
static inline void finit(Ctx *c) {
    c->fcw = 0x37f; c->fsw = 0; c->ftop = 0; c->ftag = 0;
    for (int k = 0; k < 8; k++) c->st[k] = findef();
}
// x87 loads of float/double memory turn a signaling NaN into a quiet one (Intel SDM, FLD).
static inline double ldfx(Ctx *c, uint32_t a) {
    uint32_t b = ld(c, a, 4);
    float f;
    if ((b & 0x7f800000u) == 0x7f800000u && (b & 0x7fffffu) && !(b & 0x400000u)) { b |= 0x400000u; c->fsw |= FIE; }
    memcpy(&f, &b, 4);
    return f;
}
static inline double lddx(Ctx *c, uint32_t a) {
    uint64_t b = ld64(c, a);
    if ((b & 0x7ff0000000000000ull) == 0x7ff0000000000000ull && (b & 0xfffffffffffffull) && !(b & 0x8000000000000ull)) {
        b |= 0x8000000000000ull;
        c->fsw |= FIE;
    }
    return bitsd(b);
}
static inline void fset(Ctx *c, int i, double v) { *fr(c, i) = fround(c, v); }
static inline void fucom(Ctx *c, double a, double b) {
    c->fsw &= ~(FC0 | FC2 | FC3);
    if (a != a || b != b) c->fsw |= FC0 | FC2 | FC3;
    else if (a < b) c->fsw |= FC0;
    else if (a == b) c->fsw |= FC3;
}
static inline void fcom(Ctx *c, double a, double b) {
    c->fsw &= ~(FC0 | FC2 | FC3);
    if (a != a || b != b) c->fsw |= FC0 | FC2 | FC3 | FIE;
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
    if (!(r >= -lim && r < lim)) { c->fsw |= FIE; return (int64_t)((uint64_t)1 << (bits - 1)); }
    return (int64_t)r;
}
// FPREM/FPREM1 (Intel SDM): remainder of st0/st1 with the quotient truncated (FPREM) or rounded to
// nearest (FPREM1); C0, C3, C1 get quotient bits 2, 0, 1; C2 = 0 (the reduction is complete in one step:
// doubles never have the 64-bit exponent difference that makes the x87 stop early).
static inline void fprem(Ctx *c, int nearest) {
    double a = *fr(c, 0), b = *fr(c, 1), r;
    c->fsw &= ~(FC0 | 0x200u | FC2 | FC3);
    if (a != a || b != b || isinf(a) || b == 0) { *fr(c, 0) = fx2(c, a, b, NAN); return; }
    unsigned q;
    if (nearest) { int qi; r = remquo(a, b, &qi); q = (unsigned)(qi < 0 ? -qi : qi); }
    else {
        r = fmod(a, b);
        double r8 = fmod(a, 8 * fabs(b));
        q = (unsigned)nearbyint(fabs((r8 - r) / b));   // quotient mod 8
    }
    *fr(c, 0) = r;
    if (q & 4) c->fsw |= FC0;
    if (q & 1) c->fsw |= FC3;
    if (q & 2) c->fsw |= 0x200u;
}
static inline double ld80(Ctx *c, uint32_t a) {
    uint64_t m; uint16_t se;
    memcpy(&m, c->mem + a, 8); memcpy(&se, c->mem + a + 8, 2);
    int e = se & 0x7fff; double s = (se & 0x8000) ? -1.0 : 1.0;
    // Unsupported encodings (integer bit clear with a non-zero exponent: unnormal, pseudo-NaN/infinity)
    // make any x87 operation invalid (SDM 8.2.2): hold them as the real indefinite.
    if (e != 0 && !(m >> 63)) return findef();
    if (e == 0 && m == 0) return s * 0.0;
    if (e == 0x7fff) {
        if (!(m << 1)) return s * INFINITY;
        return bitsd((uint64_t)(se >> 15) << 63 | 0x7ff0000000000000ull | ((m >> 11) & 0xfffffffffffffull) | 0x8000000000000ull);
    }
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
