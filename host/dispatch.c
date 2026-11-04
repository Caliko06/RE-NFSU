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
    static const Api *tables[] = {win32_apis, user32_apis, thread_apis, net_apis, d3d9_apis, dinput8_apis, dsound_apis, rivals_apis, free_apis, horn_apis};
    const int *counts[] = {&win32_api_count, &user32_api_count, &thread_api_count, &net_api_count, &d3d9_api_count, &dinput8_api_count, &dsound_api_count, &rivals_api_count, &free_api_count, &horn_api_count};
    for (int t = 0; t < (int)(sizeof tables / sizeof *tables); t++)
        for (int k = 0; k < *counts[t]; k++)
            if (!strcasecmp(tables[t][k].dll, dll) && !strcmp(tables[t][k].name, name)) return &tables[t][k];
    return NULL;
}

// Host -> guest call (window procedures, callbacks): stdcall, the callee pops the arguments.
static uint32_t call_guest_pop(Ctx *c, uint32_t fn, int n, const uint32_t *args, int cdecl, uint32_t *edx) {
    uint32_t saved[8];
    memcpy(saved, c->r, sizeof saved);
    for (int k = n - 1; k >= 0; k--) { c->r[ESP] -= 4; st(c, c->r[ESP], args[k], 4); }
    uint32_t back = host_addr_of("rn", "callback_return");
    c->r[ESP] -= 4;
    st(c, c->r[ESP], back, 4);
    rn_call(c, fn);
    uint32_t v = c->r[EAX];
    if (edx) *edx = c->r[EDX];
    if (!c->halt && c->ret != back) { c->halt_at = fn; rn_halt(c, "callback %08x returned to %08x", fn, c->ret); }
    if (!c->halt && c->r[ESP] != saved[ESP] - (cdecl ? 4u * n : 0)) { c->halt_at = fn; rn_halt(c, "callback %08x is not %s/%d", fn, cdecl ? "cdecl" : "stdcall", n); }
    if (!c->halt) memcpy(c->r, saved, sizeof saved);
    return v;
}
uint32_t call_guest(Ctx *c, uint32_t fn, int n, const uint32_t *args) { return call_guest_pop(c, fn, n, args, 0, NULL); }
uint32_t call_guest_cdecl(Ctx *c, uint32_t fn, int n, const uint32_t *args) { return call_guest_pop(c, fn, n, args, 1, NULL); }
uint64_t call_guest64(Ctx *c, uint32_t fn, int n, const uint32_t *args) {
    uint32_t hi, lo = call_guest_pop(c, fn, n, args, 0, &hi);
    return (uint64_t)hi << 32 | lo;
}

// Last host calls, for the stop report.
#define RING 48
static int ring[RING];
static uint32_t ring_ret[RING];
static unsigned ring_n;

// RN_API=Draw,Present: the trace shows only API names that contain one of these words.
static int traced(const char *name) {
    static const char *f;
    if (!f) f = getenv("RN_API") ? getenv("RN_API") : "";
    if (!*f) return 1;
    for (const char *p = f; *p;) {
        size_t n = strcspn(p, ",");
        for (const char *q = name; *q; q++) if (!strncmp(q, p, n)) return 1;
        p += n + (p[n] == ',');
    }
    return 0;
}
// What each guest thread is doing (telemetry): inside an API, or running guest code after it. No clock here: this runs
// at every API call (thousands per frame in a race).
static struct { uint32_t tid, api, ra, in; } busy[64];
static int nbusy;
static __thread int slot = -1;
void dispatch_threads_report(void) {
    for (int k = 0; k < nbusy && k < 64; k++) {
        int newer = 0;      // a thread id that came back (short-lived threads): only its newest slot
        for (int j = k + 1; j < nbusy && j < 64; j++) newer |= busy[j].tid == busy[k].tid;
        if (!newer) rn_log("  thread %x: %s %s!%s (ret %08x)", busy[k].tid, busy[k].in ? "in" : "guest code after",
               hosts[busy[k].api].dll, hosts[busy[k].api].name, busy[k].ra);
    }
}
static void call_host(Ctx *c, uint32_t target) {
    uint32_t k = (target - HOST_BASE) / 16;
    if (k >= (uint32_t)nhosts || (target & 15)) { rn_halt(c, "jump into host space %08x", target); return; }
    HostEntry *h = &hosts[k];
    uint32_t ra = ld(c, c->r[ESP], 4);
    ring[ring_n % RING] = (int)k; ring_ret[ring_n % RING] = ra; ring_n++;
    h->calls++;
    if (!h->fn) { c->halt_at = ra; rn_halt(c, "missing API %s!%s", h->dll, h->name); return; }
    if (rn_trace() && traced(h->name)) rn_log("api %s (ret %08x)", h->name, ra);
    gil_slice();
    if (slot < 0) slot = __atomic_fetch_add(&nbusy, 1, __ATOMIC_RELAXED);
    if (slot < 64) { busy[slot].tid = ld(c, c->fs + 0x24, 4); busy[slot].api = k; busy[slot].ra = ra; busy[slot].in = 1; }
    uint32_t v = h->fn(c);
    if (slot < 64) busy[slot].in = 0;
    if (c->halt) { if (!c->halt_at) c->halt_at = ra; return; }
    c->ret = ra;
    c->r[ESP] += 4 + (h->nargs > 0 ? 4u * h->nargs : 0);
    c->r[EAX] = v;
}

// Every indirect call and vtable call looks its target up: a binary search over the 14k functions was 6% of the game
// thread in a race (CPU profile 2026-10-25). Buckets of 64 code bytes index the sorted list: one or two compares.
#define BUCKET_SHIFT 6
static uint32_t *bucket, nbucket;      // bucket[b] = first function at or after rn_fn_addr[0] + (b << BUCKET_SHIFT)
static void bucket_init(void) {         // under the GIL, like every rn_call
    nbucket = ((rn_fn_addr[rn_fn_count - 1] - rn_fn_addr[0]) >> BUCKET_SHIFT) + 2;
    bucket = malloc(4u * nbucket);
    for (uint32_t b = 0, k = 0; b < nbucket; b++) {
        while (k < rn_fn_count && ((rn_fn_addr[k] - rn_fn_addr[0]) >> BUCKET_SHIFT) < b) k++;
        bucket[b] = k;
    }
}

void rn_call(Ctx *c, uint32_t target) {
    if (target >= HOST_BASE) { call_host(c, target); return; }
    if (rn_steerlog && target == 0x461840) steer_event(c);
    if (target == 0x427f70 || target == 0x427c50) reset_call(c, target);   // RN_RESETLOG, host/aitel.c
    if (!bucket) bucket_init();
    uint32_t b = (target - rn_fn_addr[0]) >> BUCKET_SHIFT;
    if (target >= rn_fn_addr[0] && b + 1 < nbucket)
        for (uint32_t k = bucket[b]; k < bucket[b + 1]; k++)
            if (rn_fn_addr[k] == target) {
#ifdef RN_COV
                extern uint8_t rn_cov_viacall[];
                rn_cov_viacall[k] = 1;
#endif
                rn_fn_ptr[k](c);
                return;
            }
    uint32_t mb;
    void (*mod)(Ctx *) = rn_mod_find(c, target, &mb);
    if (mod) { c->mb = mb; mod(c); return; }
    c->halt_at = target;
    // Evidence for the stop: what is at the target and who called it (the return address on the stack).
    char hex[2 * 32 + 1] = "";
    for (uint32_t k = 0; k < 32 && target + k < c->memsz; k++) snprintf(hex + 2 * k, 3, "%02x", c->mem[target + k]);
    rn_halt(c, "no lifted function at %08x (bytes %s, return address %08x)", target, hex, ld(c, c->r[ESP], 4));
}

// RN_APIRING=1: also the last API calls. The end is read once: the other threads keep calling (at RN_SECS the game still
// runs), and a loop bound on the live ring_n never ended (GBs of log per matrix run, Pod disk full, 2026-10-24).
void dispatch_report(void) {
    unsigned end = ring_n, n = end < RING ? end : RING;
    if (getenv("RN_APIRING")) rn_log("last %u API calls (oldest first):", n);
    for (unsigned k = end - n; k < end && getenv("RN_APIRING"); k++)
        rn_log("  %s!%s  <- %08x", hosts[ring[k % RING]].dll, hosts[ring[k % RING]].name, ring_ret[k % RING]);
    int used = 0;
    for (int k = 0; k < nhosts; k++) used += hosts[k].calls != 0;
    rn_log("distinct APIs called: %d of %d imported", used, nhosts);
    rn_cov_report();
}

uint64_t rn_rdtsc(Ctx *c) {
    (void)c;
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return ((uint64_t)ts.tv_sec * 1000000000ull + (uint64_t)ts.tv_nsec) * 16 / 5;   // 3.2 GHz (host/cpu.c)
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
