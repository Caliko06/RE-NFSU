// Address -> code: lifted guest functions and host API functions.
#include <stdarg.h>
#include <strings.h>
#include <time.h>
#include "host.h"

extern const uint32_t rn_fn_count;
extern const uint32_t rn_fn_addr[];
extern void (*const rn_fn_ptr[])(Ctx *);

typedef struct { char dll[32], name[64]; int nargs; HostFn fn; uint32_t calls; } HostEntry;
static HostEntry hosts[1024];
const Api *find_api(const char *dll, const char *name);
static int nhosts;

uint32_t host_addr_of(const char *dll, const char *name) {
    for (int k = 0; k < nhosts; k++)
        if (!strcasecmp(hosts[k].dll, dll) && !strcmp(hosts[k].name, name)) return HOST_BASE + 16u * k;
    if (nhosts == 1024) { fprintf(stderr, "host table full\n"); exit(1); }
    HostEntry *h = &hosts[nhosts];
    snprintf(h->dll, sizeof h->dll, "%s", dll);
    snprintf(h->name, sizeof h->name, "%s", name);
    const Api *a = find_api(dll, name);
    if (a) { h->fn = a->fn; h->nargs = a->nargs; }
    return HOST_BASE + 16u * nhosts++;
}

const Api *find_api(const char *dll, const char *name) {
    static const Api *tables[] = {win32_apis, user32_apis, thread_apis, net_apis};
    const int *counts[] = {&win32_api_count, &user32_api_count, &thread_api_count, &net_api_count};
    for (int t = 0; t < 4; t++)
        for (int k = 0; k < *counts[t]; k++)
            if (!strcasecmp(tables[t][k].dll, dll) && !strcmp(tables[t][k].name, name)) return &tables[t][k];
    return NULL;
}

// Host -> guest call (window procedures, callbacks): stdcall, the callee pops the arguments.
uint32_t call_guest(Ctx *c, uint32_t fn, int n, const uint32_t *args) {
    uint32_t saved[8];
    memcpy(saved, c->r, sizeof saved);
    for (int k = n - 1; k >= 0; k--) { c->r[ESP] -= 4; st(c, c->r[ESP], args[k], 4); }
    uint32_t back = host_addr_of("rn", "callback_return");
    c->r[ESP] -= 4;
    st(c, c->r[ESP], back, 4);
    rn_call(c, fn);
    uint32_t v = c->r[EAX];
    if (!c->halt && c->ret != back) { c->halt_at = fn; rn_halt(c, "callback %08x returned to %08x", fn, c->ret); }
    if (!c->halt && c->r[ESP] != saved[ESP]) { c->halt_at = fn; rn_halt(c, "callback %08x is not stdcall/%d", fn, n); }
    if (!c->halt) memcpy(c->r, saved, sizeof saved);
    return v;
}

// Last host calls, for the stop report.
#define RING 48
static int ring[RING];
static uint32_t ring_ret[RING];
static unsigned ring_n;

static void call_host(Ctx *c, uint32_t target) {
    uint32_t k = (target - HOST_BASE) / 16;
    if (k >= (uint32_t)nhosts || (target & 15)) { rn_halt(c, "jump into host space %08x", target); return; }
    HostEntry *h = &hosts[k];
    uint32_t ra = ld(c, c->r[ESP], 4);
    ring[ring_n % RING] = (int)k; ring_ret[ring_n % RING] = ra; ring_n++;
    h->calls++;
    if (!h->fn) { c->halt_at = ra; rn_halt(c, "missing API %s!%s", h->dll, h->name); return; }
    if (rn_trace()) rn_log("api %s (ret %08x)", h->name, ra);
    uint32_t v = h->fn(c);
    if (c->halt) { if (!c->halt_at) c->halt_at = ra; return; }
    c->ret = ra;
    c->r[ESP] += 4 + (h->nargs > 0 ? 4u * h->nargs : 0);
    c->r[EAX] = v;
}

void rn_call(Ctx *c, uint32_t target) {
    if (target >= HOST_BASE) { call_host(c, target); return; }
    uint32_t lo = 0, hi = rn_fn_count;
    while (lo < hi) {
        uint32_t mid = (lo + hi) / 2;
        if (rn_fn_addr[mid] < target) lo = mid + 1; else hi = mid;
    }
    if (lo < rn_fn_count && rn_fn_addr[lo] == target) { rn_fn_ptr[lo](c); return; }
    c->halt_at = target;
    rn_halt(c, "no lifted function at %08x", target);
}

void dispatch_report(void) {
    unsigned n = ring_n < RING ? ring_n : RING;
    rn_log("last %u API calls (oldest first):", n);
    for (unsigned k = ring_n - n; k < ring_n; k++)
        rn_log("  %s!%s  <- %08x", hosts[ring[k % RING]].dll, hosts[ring[k % RING]].name, ring_ret[k % RING]);
    int used = 0;
    for (int k = 0; k < nhosts; k++) used += hosts[k].calls != 0;
    rn_log("distinct APIs called: %d of %d imported", used, nhosts);
}

// The CPU we present: a plain P6-class x86 with an FPU and a TSC, no MMX/SSE/3DNow.
// The game's CPU checks then take its x87 code paths.
void rn_cpuid(Ctx *c, uint32_t *a, uint32_t *b, uint32_t *cc, uint32_t *d) {
    (void)c;
    if (*a == 0) { *a = 1; *b = 0x756e6547; *d = 0x49656e69; *cc = 0x6c65746e; return; }   // "GenuineIntel"
    if (*a == 1) { *a = 0x0611; *b = 0; *cc = 0; *d = 0x00000111; return; }               // FPU, TSC, CX8
    *a = *b = *cc = *d = 0;
}

uint64_t rn_rdtsc(Ctx *c) {
    (void)c;
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return (uint64_t)ts.tv_sec * 1000000000ull + (uint64_t)ts.tv_nsec;   // 1 GHz clock
}

static char halt_msg[256];
void rn_halt(Ctx *c, const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    vsnprintf(halt_msg, sizeof halt_msg, fmt, ap);
    va_end(ap);
    c->halt = 1;
    c->why = halt_msg;
}

void rn_log(const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    vfprintf(stdout, fmt, ap);
    va_end(ap);
    fputc('\n', stdout);
    fflush(stdout);
}

int rn_trace(void) {
    static int t = -1;
    if (t < 0) t = getenv("RN_TRACE") != NULL;
    return t;
}
