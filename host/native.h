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

// 0x5c97cb D3DX effect: apply one state record to the device (thiscall ecx = effect, (rec, index), ret 8). Called per
// state by Pass 0x5d01ec and by the parameter-change walk 0x5cf304. 11.4 % of the race game thread, of which ~0.5 % is
// the device work: the rest is the lifted body and the call bridge (build/bench/spk2.2715D8F0 profile, 2026-11-02).
// Native here: the cases that make one device call (render, texture stage and sampler states, light enable, texture,
// transform, shader constants, vertex shader constant state). The others (vertex/pixel shader objects, lights,
// materials, the record-list recursion, NPatchMode, the caps check when [this+0x84] == 2) run the lifted body.
// The device call itself goes through rn_call with the same stack, registers and return address as the lifted code.
#define NAT_NS(a, n) (NAT_OK(a, n) && ((uint32_t)(a) + (n) <= fr || (uint32_t)(a) >= sp + 12))   // in range, off the frame
static inline int nat_call(Ctx *c, uint32_t esp, uint32_t target, uint32_t ra) {
    esp -= 4; st(c, esp, ra, 4); c->r[4] = esp;
    rn_call(c, target);
    if (c->halt) return 0;
    if (c->ret != ra) { c->halt = 1; c->halt_at = ra - 6; c->why = "return address changed"; return 0; }
    return 1;
}
static inline int nat_5c97cb(Ctx *c) {
    uint32_t sp = c->r[4], th = c->r[1], fr = sp - 0x460;     // frame: ebp = sp-4, locals to ebp-0x438, 3 saves, 5 pushes
    if (!NAT_OK(fr, 0x46c) || !NAT_NS(th, 0x90)) return 0;
    uint32_t ebp = sp - 4, rec = ld(c, sp + 4, 4), idx = ld(c, sp + 8, 4);
    if (!NAT_NS(rec, 0x6c)) return 0;
    uint32_t edi = idx == 0xffffffffu ? ld(c, rec + 4, 4) : idx, arg2 = edi, r = rec;   // arg2: [ebp+0xc] after 0x5c9806
    if (ld(c, rec, 4) == 0xffffffffu) { r = ld(c, rec + 0x64, 4); if (!NAT_NS(r, 0xac)) return 0; }
    else if (!NAT_NS(r, 0xac)) return 0;
    uint32_t ta = ld(c, r, 4) * 0x1c + 0x6dc274;
    if (!NAT_NS(ta, 4)) return 0;
    uint32_t s = ld(c, ta, 4), ty = s >> 24, x84 = ld(c, th + 0x84, 4);
    uint32_t dev = ld(c, th + 8, 4);
    if (!NAT_NS(dev, 4)) return 0;
    uint32_t vt = ld(c, dev, 4);
    // the call: registers at it, the arguments (first = lowest address), the vtable slot, the return address, epilogue
    uint32_t a[5], na, off, ra, eax = dev, ecx = vt, edx = 0, ebx = r, esi = th, epi_b = 0;
    a[0] = dev;
    switch (ty) {
    case 1: case 2: case 8:     // SetRenderState / SetTextureStageState / SetSamplerState
        ecx = s & 0xffffff; edx = vt;
        if (ty == 1) { a[1] = ecx; a[2] = ld(c, r + 0x68, 4); na = 3; off = 0xe4; ra = 0x5c984a; }
        else { a[1] = edi; a[2] = ecx; a[3] = ld(c, r + 0x68, 4); na = 4;
               off = ty == 2 ? 0x10c : 0x114; ra = ty == 2 ? 0x5c9866 : 0x5ca078; }
        break;
    case 3:                     // LightEnable only
        if (s != 0x300000d) return 0;
        a[1] = edi; a[2] = ld(c, r + 0x68, 4); na = 3; off = 0xd4; ra = 0x5c99d0;
        break;
    case 5: {                   // SetTexture (0x5c9ac9)
        if (x84 == 2) return 0;
        uint32_t pt = ld(c, th + 0x8c, 4) + ld(c, r + 0xc, 4) * 4;
        if (!NAT_NS(pt, 4)) return 0;
        uint32_t P = ld(c, pt, 4);
        if (!NAT_NS(P, 0x3c)) return 0;
        uint32_t p38 = ld(c, P + 0x38, 4), q = ld(c, P + 0x28, 4) + ld(c, r + 0x14, 4), v;
        if (!p38) {
            uint32_t b = ld(c, th + 0x2c, 4);
            if (!NAT_NS(q + b, 4)) return 0;
            v = ld(c, q + b, 4);
        } else {
            uint32_t e = ld(c, th + 0xc, 4);
            if (!NAT_NS(e + 8, 4) || !NAT_NS(p38 + 8, 4)) return 0;
            uint32_t b = ld(c, e + 8, 4);
            if (!NAT_NS(q + b, 4)) return 0;
            uint32_t k = ld(c, q + b, 4), tb = ld(c, p38 + 8, 4);
            if (!NAT_NS(tb + k * 4, 4)) return 0;
            v = ld(c, tb + k * 4, 4);
        }
        ebx = ld(c, th + 0x24, 4); eax = v * 0x1c;
        if (!NAT_NS(eax + ebx + 4, 4)) return 0;
        a[1] = edi; a[2] = ld(c, eax + ebx + 4, 4); na = 3;
        ecx = dev; edx = vt; off = 0x104; ra = 0x5c9b10;
        break;
    }
    case 6:                     // vertex shader constant state 0x6000008, shader constants
        if (s == 0x6000008) {
            ebx = x84 == 1 ? 2 : ld(c, r + 0x68, 4);
            a[1] = ebx; na = 2; off = 0x164; ra = 0x5c9b39;
            break;
        }
        if (x84 == 1) return 0;
        edx = 0x6000102; ecx = s;
        if (s > 0x6000102) {
            switch (s) {
            case 0x6000105: off = 0x1b4; break;
            case 0x6000202: off = 0x178; ecx = 0xfd; break;
            case 0x6000205: case 0x6000305: case 0x6000405: off = 0x1b4; ecx = 0xfd; edx = 3; break;
            case 0x6000302: case 0x6000402: off = 0x178; ecx = 0xfd; edx = 3; break;
            default: return 0;
            }
        } else if (s == 0x6000102) off = 0x178;
        else {
            static const uint16_t offs[8] = {0, 0, 0x178, 0x180, 0x188, 0x1b4, 0x1bc, 0x1c4};
            ecx = s - 0x6000000;
            if (ecx > 7 || !offs[ecx]) return 0;
            off = offs[ecx];
        }
        switch (off) {
        case 0x178: ra = 0x5ca00c; break;  case 0x180: ra = 0x5c9f61; break;  case 0x188: ra = 0x5c9f7c; break;
        case 0x1b4: ra = 0x5c9ff4; break;  case 0x1bc: ra = 0x5c9f97; break;  default: ra = 0x5c9faf; break;
        }
        a[1] = edi; a[2] = ld(c, r + 0x4c, 4); a[3] = ld(c, r + 0xa8, 4); na = 4;
        eax = vt; esi = dev; epi_b = 1;
        break;
    case 7: {                   // SetTransform (0x5ca01b)
        uint32_t k = s - 0x7000000;
        if (k > 3) return 0;
        if (k == 2) edi += 0x100; else if (k == 3) edi += 0x10;
        ebx = r + 0x68;
        a[1] = k == 0 ? 3 : k == 1 ? 2 : edi; a[2] = ebx; na = 3; off = 0xb0; ra = 0x5ca05f;
        break;
    }
    default: return 0;
    }
    if (!NAT_NS(vt + off, 4)) return 0;
    uint32_t target = ld(c, vt + off, 4);
    // prologue (0x5c97cb): push ebp; sub esp, 0x438; push ebx; [ebp-7..-5] = 0; push esi; push edi; locals
    st(c, sp - 4, c->r[5], 4);
    st(c, ebp - 0x43c, c->r[3], 4); st(c, ebp - 0x440, c->r[6], 4); st(c, ebp - 0x444, c->r[7], 4);
    st(c, ebp - 4, th, 4); st(c, ebp - 0x1c, 0, 4); st(c, ebp - 0xc, 0xff, 4); st(c, ebp - 8, 0x11, 4);
    if (idx == 0xffffffffu) st(c, ebp + 0xc, arg2, 4);
    uint32_t esp = ebp - 0x444 - 4 * na;
    for (uint32_t k = 0; k < na; k++) st(c, esp + 4 * k, a[k], 4);
    c->r[0] = eax; c->r[1] = ecx; c->r[2] = edx; c->r[3] = ebx; c->r[5] = ebp; c->r[6] = esi; c->r[7] = edi;
    if (!nat_call(c, esp, target, ra)) return 1;
    uint32_t v = c->r[0], e;
    if (epi_b) e = (int32_t)v < 0 ? v : 0;                          // 0x5ca00c
    else e = (int32_t)v >= 0 || ld(c, c->r[6] + 0x84, 4) == 1 ? 0 : v;   // 0x5ca0d2
    uint32_t sp2 = c->r[4], bp = c->r[5];                            // 0x5ca0e3: [ebp-0x1c] is still 0, no Release
    c->r[7] = ld(c, sp2, 4); c->r[6] = ld(c, sp2 + 4, 4); c->r[3] = ld(c, sp2 + 8, 4);
    c->r[5] = ld(c, bp, 4);
    c->ret = ld(c, bp + 4, 4);
    c->r[4] = bp + 16;                                              // leave; ret 8
    c->r[0] = e;
    c->cf = 0; c->zf = 1; c->sf = 0; c->of = 0; c->pf = 1; c->af = 0;   // test eax, eax with [ebp-0x1c] = 0
    return 1;
}

// 0x5c85c1 D3DX effect: copy one parameter's data into shader-constant registers (stdcall (pdesc, psrc, pdst, pleft),
// ret 0x10; the four are pointers to cursors that it advances). Reached from the parameter-change walk 0x5cf304 via
// 0x5cafde: 2.4 % of the race game thread (spk2). Native: the float type ([desc] == 3, class 0..3), a transposed copy
// through fld/fstp (a signaling NaN comes out quiet with IE set). Integer/bool types, structs (class 5, recursive) and
// the error path run the lifted body. The cursors and data are read and written in the original order, element by
// element, so overlapping buffers behave the same; a buffer inside this function's own frame is not modelled.
static inline int nat_5c85c1(Ctx *c) {
    uint32_t sp = c->r[4], fr = sp - 0x30;                      // frame: ebp = sp-4, locals to ebp-0x20, 3 saves
    if (c->df || !NAT_OK(fr, 0x44) || (c->ftag & (1u << ((c->ftop - 1) & 7)))) return 0;
    uint32_t p1 = ld(c, sp + 4, 4), p2 = ld(c, sp + 8, 4), p3 = ld(c, sp + 12, 4), p4 = ld(c, sp + 16, 4);
    if (!NAT_NS(p1, 4) || !NAT_NS(p2, 4) || !NAT_NS(p3, 4) || !NAT_NS(p4, 4)) return 0;
    uint32_t D = ld(c, p1, 4);
    if (!NAT_NS(D, 0x1c)) return 0;
    uint32_t cls = ld(c, D + 4, 4), ty = ld(c, D, 4);
    if (cls > 3 || ty != 3) return 0;
    uint32_t n = ld(c, D + 0x10, 4), cols = ld(c, D + 0x14, 4), rows = ld(c, D + 0x18, 4);
    uint32_t ebp = sp - 4, c4 = (cols >> 2) + ((cols & 3) != 0);
    st(c, sp - 4, c->r[5], 4);                                  // push ebp; sub esp, 0x20; push ebx, esi, edi
    st(c, ebp - 0x24, c->r[3], 4); st(c, ebp - 0x28, c->r[6], 4); st(c, ebp - 0x2c, c->r[7], 4);
    st(c, ebp - 0x10, 0, 4); st(c, ebp - 8, n ? n : 1, 4);
    st(c, ebp - 0x1c, cols, 4); st(c, ebp - 0x20, rows, 4); st(c, ebp - 4, cols, 4);
    st(c, ebp - 0x18, c4, 4); st(c, ebp - 0xc, c4, 4);
    uint32_t ecx = 0, edx = cols >> 2, nn = n ? n : 1, fl = 0, at = 0;
    st(c, ebp - 0x14, 0, 4);
    for (uint32_t i = 0; i < nn; i++) {                         // 0x5c86b9
        if (!ld(c, p4, 4)) break;
        st(c, ebp + 0x10, 0, 4);
        for (uint32_t j = 0; j < rows; j++) {                   // 0x5c86ca
            uint32_t left = ld(c, p4, 4);
            ecx = left;
            if (!left) break;
            if (ld(c, ebp - 0x18, 4) > left) { edx = left << 2; st(c, ebp - 4, edx, 4); st(c, ebp - 0xc, left, 4); }
            edx = 0;
            uint32_t cnt = ld(c, ebp - 4, 4);
            for (uint32_t k = 0, so = j << 2; k < cnt; k++, so += rows << 2) {   // 0x5c86ed
                uint32_t s = so + ld(c, p2, 4), d = ld(c, p3, 4) + k * 4;
                if (!NAT_OK(s, 4)) { at = 0x5c86ef; goto fault; }
                uint32_t b = ld(c, s, 4);
                if ((b & 0x7f800000u) == 0x7f800000u && (b & 0x7fffffu) && !(b & 0x400000u)) { b |= 0x400000u; c->fsw |= FIE; }
                if (!NAT_OK(d, 4)) { at = 0x5c86f4; goto fault; }
                st(c, d, b, 4);
                fl = 1; edx = k + 1;
            }
            ecx = ld(c, ebp - 0xc, 4); edx = ecx << 4;          // 0x5c870a
            st(c, p3, ld(c, p3, 4) + edx, 4);
            st(c, p4, ld(c, p4, 4) - ecx, 4);
            st(c, ebp + 0x10, j + 1, 4);
        }
        st(c, p2, ld(c, p2, 4) + ((rows * cols) << 2), 4);      // 0x5c871e
        st(c, ebp - 0x14, i + 1, 4);
        ecx = nn;
    }
    if (fl) c->st[(c->ftop - 1) & 7] = findef();               // the fld/fstp slot, popped
    {   uint32_t a = ld(c, p1, 4), res = a + 0x1c;              // 0x5c8864: add dword [eax], 0x1c
        st(c, p1, res, 4);
        c->cf = res < a; c->of = ((~(a ^ 0x1cu)) & (a ^ res) & 0x80000000u) != 0; c->af = ((a ^ 0x1cu ^ res) >> 4) & 1;
        c->zf = res == 0; c->sf = res >> 31; c->pf = par(res); }
    c->r[0] = 0; c->r[1] = ecx; c->r[2] = edx;                  // eax = [ebp-0x10] = 0
    c->r[3] = ld(c, ebp - 0x24, 4); c->r[6] = ld(c, ebp - 0x28, 4); c->r[7] = ld(c, ebp - 0x2c, 4);
    c->r[5] = ld(c, ebp, 4); c->ret = ld(c, sp, 4); c->r[4] = sp + 0x14;   // leave; ret 0x10
    return 1;
fault:
    c->halt = 1; c->halt_at = at; c->why = "memory fault";
    return 1;
}
