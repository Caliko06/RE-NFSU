// The CPU we present: a plain P6-class x86 with an FPU and a TSC, no MMX/SSE/3DNow.
// The game's CPU checks then take its x87 code paths. difftest gives Unicorn the same answers.
#include "rt.h"

void rn_cpu_ident(uint32_t leaf, uint32_t out[4]) {   // eax, ebx, ecx, edx
    out[0] = out[1] = out[2] = out[3] = 0;
    if (leaf == 0) { out[0] = 1; out[1] = 0x756e6547; out[3] = 0x49656e69; out[2] = 0x6c65746e; }   // "GenuineIntel"
    if (leaf == 1) { out[0] = 0x0611; out[3] = 0x00000111; }                                         // FPU, TSC, CX8
}

void rn_cpuid(Ctx *c, uint32_t *a, uint32_t *b, uint32_t *cc, uint32_t *d) {
    uint32_t r[4];
    (void)c;
    rn_cpu_ident(*a, r);
    *a = r[0]; *b = r[1]; *cc = r[2]; *d = r[3];
}
