// Coverage of the lifted code: which guest functions ever ran (docs/re/coverage_method.md).
// Normal build: only the empty rn_cov_report below. RN_COV=1 build (tools/recomp/build.py, -DRN_COV): every lifted
// function stores rn_cov_map[k] = 1 at its entry (RN_COV(RNI_<addr>) in build/gen_cov), k = position in the sorted
// table rn_fn_addr. That counts direct calls and tail jumps too; rn_call alone sees only indirect ones.
// rn_cov_viacall[k] is the old measure (set inside rn_call, host/dispatch.c), kept to show how far it undercounts.
// RN_COV_OUT=<file> gets, at exit / halt / RN_SECS: "RNCV", u32 N, then two bitmaps of ceil(N/8) bytes, bit k%8 of
// byte k/8 (entered; seen by rn_call). Without RN_COV_OUT the count is only printed.
#include "host.h"

void rn_cov_report(void);

#ifdef RN_COV
extern const uint32_t rn_fn_count;
uint8_t rn_cov_map[16384], rn_cov_viacall[16384];

void rn_cov_report(void) {
    static int once;
    if (__atomic_exchange_n(&once, 1, __ATOMIC_SEQ_CST)) return;
    uint32_t n = rn_fn_count, bytes = (n + 7) / 8, hits = 0, via = 0;
    if (n > sizeof rn_cov_map) { rn_log("coverage: %u functions do not fit rn_cov_map", n); return; }
    uint8_t *img = calloc(1, 8 + 2 * (size_t)bytes);
    memcpy(img, "RNCV", 4);
    memcpy(img + 4, &n, 4);
    for (uint32_t k = 0; k < n; k++) {
        if (rn_cov_map[k]) { img[8 + k / 8] |= 1u << (k % 8); hits++; }
        if (rn_cov_viacall[k]) { img[8 + bytes + k / 8] |= 1u << (k % 8); via++; }
    }
    const char *out = getenv("RN_COV_OUT");
    if (out) {
        FILE *f = fopen(out, "wb");
        if (f) { fwrite(img, 1, 8 + 2 * (size_t)bytes, f); fclose(f); }
        else rn_log("coverage: cannot write %s", out);
    }
    rn_log("coverage: %u of %u (rn_call alone saw %u)", hits, n, via);
    free(img);
}
#else
void rn_cov_report(void) {}
#endif
