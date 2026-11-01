// Native bodies of hot guest functions (tools/recomp/lift.py NATIVE). Each does the lifted code's operations in the same
// order on the rt.h model (x87 values as doubles, fround after each result, the same NaN and IE rules), with the x87
// stack in locals instead of c->st[], and leaves the same registers, flags, x87 state and memory. It returns 0 when the
// input is outside its fast case (x87 registers in use, DF set, an address out of range); the lifted body then runs.
// Proof: RN_ONLY=<addr> tools/recomp/difftest.py (bit for bit against Unicorn).
#pragma once
#include "rt.h"

#define NAT_OK(a, n) ((uint32_t)((a) - LOW) <= c->memsz - LOW - (n))

// 0x5d6f5d D3DXMatrixMultiply, x87 version (D3DX's CPU dispatch 0x5ac69c calls it), stdcall (out, m1, m2), ret 0xc.
// 5.8 % self of the race game thread (build/bench/spk2 profile, 2026-11-01). out == m2: column by column in place;
// out == m1 == m2: m2 is first copied to the local at ebp-0x40 (and [ebp+0x10] points at it); else row by row.
static inline double nat_mm4(Ctx *c, double a0, double a1, double a2, double a3, uint32_t q) {
    double p0 = fround(c, FMUL(a0, ldfx(c, q)));
    double p1 = fround(c, FMUL(a1, ldfx(c, q + 4)));
    double p2 = fround(c, FMUL(a2, ldfx(c, q + 8)));
    double p3 = fround(c, FMUL(a3, ldfx(c, q + 12)));
    double s1 = fround(c, FADD(p2, p0)), s2 = fround(c, FADD(p1, p3));
    return fround(c, FADD(s1, s2));
}
static inline double nat_mm4s(Ctx *c, double b0, double b1, double b2, double b3, uint32_t q) {   // stride 16
    double p0 = fround(c, FMUL(b0, ldfx(c, q)));
    double p1 = fround(c, FMUL(b1, ldfx(c, q + 16)));
    double p2 = fround(c, FMUL(b2, ldfx(c, q + 32)));
    double p3 = fround(c, FMUL(b3, ldfx(c, q + 48)));
    double s1 = fround(c, FADD(p2, p0)), s2 = fround(c, FADD(p1, p3));
    return fround(c, FADD(s1, s2));
}
static inline int nat_5d6f5d(Ctx *c) {
    uint32_t sp = c->r[4];
    if (c->ftag || c->df || !NAT_OK(sp - 0x54, 0x64)) return 0;
    uint32_t out = ld(c, sp + 4, 4), m1 = ld(c, sp + 8, 4), m2 = ld(c, sp + 12, 4);
    if (!NAT_OK(out, 64) || !NAT_OK(m1, 64) || !NAT_OK(m2, 64)) return 0;
    st(c, sp - 4, c->r[5], 4);                                  // push ebp; sub esp, 0x40; push ebx, esi, edi
    st(c, sp - 0x48, c->r[3], 4); st(c, sp - 0x4c, c->r[6], 4); st(c, sp - 0x50, c->r[7], 4);
    int cf;
    if (m2 == out && m1 != out) {                               // 0x5d6f75: per column j of m2
        for (uint32_t j = 0; j < 4; j++) {
            double a0 = ldfx(c, m2 + 4 * j), a1 = ldfx(c, m2 + 4 * j + 16), a2 = ldfx(c, m2 + 4 * j + 32),
                   a3 = ldfx(c, m2 + 4 * j + 48);
            for (uint32_t i = 0; i < 4; i++) stf(c, out + 16 * i + 4 * j, (float)nat_mm4(c, a0, a1, a2, a3, m1 + 16 * i));
        }
        cf = 1;                                                 // add esi, 4 -> 0
        c->r[1] = m1; c->r[2] = m2;
    } else {
        if (m2 == out) {                                        // 0x5d6fd3: copy m2 to the local, [ebp+0x10] = it
            st(c, sp - 0x54, 0x10, 4);                          // push 0x10; pop ecx
            uint32_t loc = sp - 0x44;
            for (uint32_t k = 0; k < 64; k += 4) st(c, loc + k, ld(c, m2 + k, 4), 4);
            st(c, sp + 12, loc, 4);
            m2 = loc;
            cf = 0;                                             // cmp [ebp+0xc], eax: equal
        } else cf = m2 < out;                                   // cmp esi, eax
        for (uint32_t i = 0; i < 4; i++) {                      // 0x5d6fe1: per row i of m1
            uint32_t r = m1 + 16 * i;
            double b0 = ldfx(c, r), b1 = ldfx(c, r + 4), b2 = ldfx(c, r + 8), b3 = ldfx(c, r + 12);
            for (uint32_t j = 0; j < 4; j++) stf(c, out + 16 * i + 4 * j, (float)nat_mm4s(c, b0, b1, b2, b3, m2 + 4 * j));
        }
        c->r[1] = m1 + 0x40; c->r[2] = m2;
    }
    for (int k = 0; k < 8; k++) c->st[k] = findef();            // all 8 slots were pushed and then popped or freed
    c->r[0] = out;                                              // ebx, ebp, esi, edi: popped back unchanged
    c->ret = ld(c, sp, 4);
    c->r[4] = sp + 16;
    c->cf = cf; c->zf = 1; c->sf = 0; c->of = 0; c->pf = 1; c->af = 1;   // inc edi -> 0
    return 1;
}
