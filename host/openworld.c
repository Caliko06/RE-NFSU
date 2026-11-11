// Open world, phase D1 (docs/OPENWORLD.md). The merged TRACKB for the 16 real tracks is off unless RN_WORLD=1; the WORLD entry
// of the Free Run list (below, track id 1010) is always on.
//
// 1. File redirect: with RN_WORLD=1 the game's TRACKS\TRACKB<id>.LZC of the 16 L1RA street tracks is served from the merged
//    copy tools/openworld/build.py wrote (build/openworld/TRACKB<id>.lzc, or RN_WORLD_DIR): one collision world for the whole
//    city, no fences, no streaming chunks 0x34153/0x34154. gf_open (host/files.c) asks rn_world_open before its lookup.
// 2. Test only, RN_WORLD_AT="log" (only logs) or "x,y,z,yaw16": once the car has driven RN_WORLD_MOVE metres from the grid (default 120; and RN_WORLD_WAIT presents have passed, default 0) the player car is
//    put there with the game's own Car::ResetToPosition 0x427e60 (ecx = car, edx = vec3*, eax = yaw as the s16 at car+0x3b4,
//    2 stack args as the start in 0x422eb0 pushes: 0, 0). 0x427e60 -> 0x427c50 -> PutFlatOnTrack 0x4278d0 queries the ground.
//    Then the car's position and the ground query 0x440a40(obj = car+0x540, pos, 0, 0, &flag) (flag byte 1 = a polygon found, 0 = no ground and the
//    height is the z it was given; the height comes back on the FPU) are logged each RN_WORLD_LOG presents (default 60). No hook in d3d9.c is allowed in
//    this phase, so a host thread takes the GIL every 20 ms (it runs when the main thread passes the GIL, as the winmm timer
//    threads do) and calls the guest on its own context (own stack and TEB).
#include <ctype.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include "host.h"

static int enabled(void) {
    static int on = -1;
    if (on < 0) on = rn_env("RN_WORLD", 0) != 0;
    return on;
}

static int ci_eq(const char *a, const char *b, size_t n) {
    for (size_t k = 0; k < n; k++) if (tolower((unsigned char)a[k]) != tolower((unsigned char)b[k])) return 0;
    return 1;
}

// RN_SPAWN="x:y:z:yaw16" (web: ?env=RN_SPAWN=117.6:601.3:44:32768): once per race, 2 s after GO (rn_flow 0x604: the start 0x422eb0 has reset
// the grid), the player's car is put at that NFSU1 point by the game's own reset-to-point 0x427e60 (ecx = car, edx = &pos, eax = yaw16,
// 2 stack args 0), then the streamer's viewer is seeded with 0x444840 (eax 0, edx 0x77a980, ecx = &car pos), as the native test teleport
// below does (tp_thread). Runs on the game's own context at Present (host/d3d9.c, next to free_tick), so it works in the web build.
void world_spawn(Ctx *c) {
    static float at[4];
    static int n = -1;
    static uint32_t race, go, buf, car, after;
    if (n < 0) { const char *e = getenv("RN_SPAWN"); n = e ? sscanf(e, "%f:%f:%f:%f", &at[0], &at[1], &at[2], &at[3]) : 0; if (e && n < 3) rn_log("SPAWN: cannot read RN_SPAWN \"%s\" (x:y:z[:yaw16])", e); }
    if (n < 3) return;
    if (rn_new_race(&race)) go = 0, after = 0;
    if (rn_flow != 0x604) return;
    if (after && rn_telem.presents == after) {   // one line 20 s later: where the car went and its speed (car+0x1e0/+0x1e4)
        rn_log("SPAWN +20 s: car at %.1f %.1f %.1f speed %.1f m/s", ldf(c, car + 0x60), ldf(c, car + 0x64), ldf(c, car + 0x68), hypotf(ldf(c, car + 0x1e0), ldf(c, car + 0x1e4)));
        after = 0;
    }
    if (!go) go = rn_telem.presents;
    if (go == ~0u || rn_telem.presents < go + 120) return;
    go = ~0u;
    car = 0;
    uint32_t h = ld(c, 0x7361f8, 4);   // the player's node of the race list = the car (player_node below)
    for (uint32_t r = h ? ld(c, h, 4) : 0, k = 0; r && r != h && k < 200 && !car; r = ld(c, r, 4), k++) {
        uint32_t e = ld(c, r + 0x14, 4);
        if (e && e < GUEST_MEM - 16 && ld(c, e + 4, 4) == 1) car = r;
    }
    if (!car) { rn_log("SPAWN: no player car in the race list"); return; }
    if (!buf) buf = guest_alloc(16);
    stf(c, buf, at[0]); stf(c, buf + 4, at[1]); stf(c, buf + 8, at[2]);
    uint32_t keep[7] = {c->r[EAX], c->r[EBX], c->r[ECX], c->r[EDX], c->r[ESI], c->r[EDI], c->r[EBP]}, ft = c->ftop, a[2] = {0, 0};
    float was[3] = {ldf(c, car + 0x60), ldf(c, car + 0x64), ldf(c, car + 0x68)};
    c->r[ECX] = car; c->r[EDX] = buf; c->r[EAX] = n > 3 ? (uint32_t)(int32_t)at[3] : ld(c, car + 0x3b4, 2);
    call_guest(c, 0x427e60, 2, a);
    c->r[EAX] = 0; c->r[EDX] = 0x77a980; c->r[ECX] = car + 0x60;
    call_guest(c, 0x444840, 0, NULL);
    c->r[EAX] = keep[0], c->r[EBX] = keep[1], c->r[ECX] = keep[2], c->r[EDX] = keep[3], c->r[ESI] = keep[4], c->r[EDI] = keep[5], c->r[EBP] = keep[6], c->ftop = ft;
    rn_log("SPAWN: car %08x %.1f %.1f %.1f -> %.1f %.1f %.1f (asked %.1f %.1f %.1f yaw %d) frame %u", car, was[0], was[1], was[2],
           ldf(c, car + 0x60), ldf(c, car + 0x64), ldf(c, car + 0x68), at[0], at[1], at[2], n > 3 ? (int)at[3] : -1, rn_telem.presents);
    after = rn_telem.presents + 1200;
}

#ifdef __EMSCRIPTEN__
static void tp_start(void) {}     // the test teleport is native only
#else
static void *tp_thread(void *arg);
static void tp_start(void) {
    static int started;
    if (started || !getenv("RN_WORLD_AT")) return;
    started = 1;
    pthread_t t;
    pthread_create(&t, NULL, tp_thread, NULL);
    pthread_detach(t);
}
#endif

#ifdef __EMSCRIPTEN__
#include <emscripten.h>
// The size of a file the server has at "/<path>", -1 when it has none.
EM_JS(double, world_head, (const char *path), {
    var x = new XMLHttpRequest();
    x.open('HEAD', '/' + UTF8ToString(path), false);
    x.send();
    return x.status === 200 ? Number(x.getResponseHeader('Content-Length')) : -1;
});
#endif

// ---- the "WORLD" entry of the Free Run list (track id 1010), docs/openworld/world_entry.md -------------------------------------
// Always on (native and web), RN_WORLDROW=0 = the list as shipped. The game's track-info table (GLOBALB chunk 0x34201, 31 rows
// x 0xfc, loader 0x442040: [0x736168] = rows, [0x73616c] = count) gets a 32nd row cloned from row 0 (CT1, region L1RA): id 1010,
// mask 0x90 (0x10 = Free Run only; 0x80 = no reverse entry, PATCH 0x4ba207 skips it in the list's second pass). The chunk handler
// pointer 0x7007ec points at a cave (PATCH, slot SCREEN_ADDR+0x74) that lands in world_rows, which runs 0x442040 and adds the row.
// The name comes the same way: 0x700850 (language loader 0x59fce0) -> world_lang adds the pair (hash of "TRACK_NAME_1010", "WORLD")
// to the sorted language table [0x734434] (count [0x73442c]). The minimap of the row reads its bounds at +0x8c/+0x90/+0x94
// (0x590ad0: u = (x - X0) / S, v = (Y0 - y) / S): the picture of tools/openworld/worldmap.py, same three numbers. They are one square
// holding both cities: NFSU1 road nodes x -691..2393, y -1920..734 and the UG2 map picture (TRACKMAP4000, census/ug2/map.md) placed by
// R270 + t, x -3633..2000, y -1395..4238. The worldmap.py assert checks that these three defines match its own.
#define WORLD_ID   1010
#define WORLD_BASE 1001            // its TRACKB is the merged city of base track 1001
#define WORLD_X0   (-3650.f)
#define WORLD_Y0   4260.f
#define WORLD_S    6240.f
#define WORLD_NAME_HASH 0x5461a075u   // "TRACK_NAME_1010" with the game's hash (0x4f42f0: h = -1, h = h * 33 + c)

int rn_tex_overlay;   // 1 once Cars/TEXTURES.BIN was served from the overlay with the DUMMY_SKIN5..12 targets (host/free.c checks it)

static int worldrow_on(void) {
    static int on = -1;
    if (on < 0) { const char *e = getenv("RN_WORLDROW"); on = !(e && e[0] == '0'); }
    return on;
}

static uint32_t rows_prev, lang_prev;   // the copies of the last load (the unloaders only zero the pointers): freed at the next one

// Handler of chunk 0x34201: the original loader, then one more row.
uint32_t world_rows(Ctx *c) {
    uint32_t chunk = ARG(0), r = call_guest_cdecl(c, 0x442040, 1, &chunk);
    if (!r || ld(c, chunk, 4) != 0x34201 || !worldrow_on()) return r;
    uint32_t rows = ld(c, 0x736168, 4), n = ld(c, 0x73616c, 4);
    if (!rows || n != 31 || (int16_t)ld(c, rows + 0x6c, 2) != 1001) { rn_log("OPENWORLD: track table is not the expected one (%u rows), no WORLD row", n); return r; }
    uint32_t nr = guest_alloc((n + 1) * 0xfc);
    if (!nr) return r;
    memcpy(G(nr), G(rows), n * 0xfc);
    uint32_t w = nr + n * 0xfc;
    memcpy(G(w), G(rows), 0xfc);                                  // CT1: L1RA, the circuit values (laps, traffic counts)
    memset(G(w), 0, 0x40);
    snprintf(G(w), 32, "WORLD");                                  // +0x00 name, copied at +0xdc
    memset(G(w + 0xdc), 0, 32);
    snprintf(G(w + 0xdc), 32, "WORLD");
    snprintf(G(w + 0x20), 32, "Location1\\Track_%d", WORLD_ID);
    st(c, w + 0x6c, WORLD_ID, 2); st(c, w + 0x6e, WORLD_ID, 2);   // s16 id twice
    st(c, w + 0x74, 0x90, 4);                                     // mask: Free Run (0x10) only, no reverse (0x80)
    stf(c, w + 0x8c, WORLD_X0); stf(c, w + 0x90, WORLD_Y0); stf(c, w + 0x94, WORLD_S); st(c, w + 0x98, 0, 2);   // minimap bounds, no rotation
    if (rows_prev) guest_free(rows_prev);
    rows_prev = nr;
    st(c, 0x736168, nr, 4); st(c, 0x73616c, n + 1, 4);
    rn_log("OPENWORLD: track row %u = WORLD (id %d, mask 0x90) at %08x", n, WORLD_ID, w);
    return r;
}

// Handler of chunk 0x39000 (the language table): the original loader, then the name of the WORLD row in sorted place.
uint32_t world_lang(Ctx *c) {
    uint32_t chunk = ARG(0), r = call_guest_cdecl(c, 0x59fce0, 1, &chunk);
    if (!r || ld(c, chunk, 4) != 0x39000 || !worldrow_on()) return r;
    uint32_t n = ld(c, 0x73442c, 4), tab = ld(c, 0x734434, 4);
    if (!tab || !n) return r;
    uint32_t nt = guest_alloc((n + 1) * 8), str = guest_alloc(8), k = 0;
    if (!nt || !str) return r;
    snprintf(G(str), 8, "WORLD");
    while (k < n && ld(c, tab + 8 * k, 4) < WORLD_NAME_HASH) k++;
    // English.bin already has TRACK_NAME_1010 ("Grand Station (DT 6)", a cut track): then that pair is replaced, not duplicated
    int have = k < n && ld(c, tab + 8 * k, 4) == WORLD_NAME_HASH;
    memcpy(G(nt), G(tab), 8 * k);
    st(c, nt + 8 * k, WORLD_NAME_HASH, 4); st(c, nt + 8 * k + 4, str, 4);   // 0x59fce0 made the string pointers absolute
    memcpy(G(nt + 8 * k + 8), G(tab + 8 * (k + have)), 8 * (n - k - have));
    n -= have;
    if (lang_prev) guest_free(lang_prev);
    lang_prev = nt;
    st(c, 0x734434, nt, 4); st(c, 0x73442c, n + 1, 4);
    return r;
}

// Collision index of a TRACKB (PATCH 0x441423, cave 0x797620: push chunk, push mgr; call [SCREEN_ADDR+0xcc]), the 0x34133 branch of the
// loader 0x441380; CollectPolys 0x441660 now reads u32 entries. A chunk that starts with 0xffffffff is already u32 (the merged city,
// tools/ug2_collfile.py: more than 65,534 rows): used in place. Any other is u16 (the 16 shipped files): widened into a guest copy.
// Sets mgr+0x18 (entries) and +0x1c (count, read by nobody). The copy of the last load is freed at the next one.
uint32_t world_widx(Ctx *c) {
    static uint32_t prev;
    uint32_t mgr = ARG(0), ch = ARG(1), size = ld(c, ch + 4, 4), data = ch + 8, ptr = data, n;
    if (prev) { guest_free(prev); prev = 0; }
    if (size >= 4 && ld(c, data, 4) == 0xffffffffu) { ptr = data + 4; n = (size - 4) / 4; }
    else {
        n = size / 2;
        ptr = prev = guest_alloc(n * 4 + 4);
        if (!ptr) { rn_log("OPENWORLD: no memory for %u widx entries", n); n = 0; ptr = data; }
        for (uint32_t k = 0; k < n; k++) st(c, ptr + 4 * k, ld(c, data + 2 * k, 2), 4);
    }
    st(c, mgr + 0x18, ptr, 4); st(c, mgr + 0x1c, n, 4);
    return 0;
}

// The caves of PATCH 0x7007ec / 0x700850 jump through these slots; filled on the first file open (before GLOBALB is read), so
// host/win32.c is untouched.
static void world_install(void) {
    static int done;
    if (done || !g_ctx) return;
    done = 1;
    st(g_ctx, SCREEN_ADDR + 0x74, host_addr_of("rn", "world_rows"), 4);
    st(g_ctx, SCREEN_ADDR + 0x78, host_addr_of("rn", "world_lang"), 4);
    st(g_ctx, SCREEN_ADDR + 0xcc, host_addr_of("rn", "world_widx"), 4);
}
// (world_rows and world_lang are in the api table at the end of host/free.c, the last table dispatch.c searches.)

// A file of the WORLD id: the same name with the id of the base track (a shipped file), 1 = it is one of those.
int rn_world_alias(const char *gpath, char *out, size_t n) {
    const char *b = gpath;
    for (const char *p = gpath; *p; p++) if (*p == '/' || *p == '\\') b = p + 1;
    if (!worldrow_on() || !ci_eq(b, "STREAML1RA_1010.BUN", 20)) return 0;   // STREAML1RA_<id>.BUN: 0 bytes for every L1RA track, the base one too
    snprintf(out, n, "%.*s%s", (int)(b - gpath), gpath, "STREAML1RA_1001.BUN");
    return 1;
}

// One file of the merged city by its name, served from build/openworld (native) or /world/ (web, tools/serve.py). 1 = served.
static int world_file(const char *name, char *real, size_t n, uint64_t *size) {
#ifdef __EMSCRIPTEN__
    snprintf(real, n, "world/%s", name);
    double len = world_head(real);
    if (len < 0) { rn_log("OPENWORLD: no merged file /%s, the original is used", real); return 0; }
    *size = (uint64_t)len;
#else
    const char *dir = getenv("RN_WORLD_DIR");
    snprintf(real, n, "%s/%s", dir && *dir ? dir : "build/openworld", name);
    struct stat sb;
    if (stat(real, &sb) || !S_ISREG(sb.st_mode)) { rn_log("OPENWORLD: no merged file %s, the original is used", real); return 0; }
    *size = (uint64_t)sb.st_size;
#endif
    return 1;
}

// gpath ends in TRACKB<id>.LZC (any case, any folder): the merged file when it exists; for the WORLD id (always) also
// TEX1010TRACK.BIN, the minimap picture. 1 = served (real and size are set).
int rn_world_open(const char *gpath, char *real, size_t n, uint64_t *size) {
    tp_start();   // RN_WORLD_AT also runs on the original TRACKB (the A/B run: RN_WORLD_AT=log only logs)
    world_install();
    const char *b = gpath;
    for (const char *p = gpath; *p; p++) if (*p == '/' || *p == '\\') b = p + 1;
    if (worldrow_on() && ci_eq(b, "TEX1010TRACK.BIN", 17)) {
        if (!world_file("TEX1010TRACK.BIN", real, n, size)) return 0;
        rn_log("OPENWORLD: %s -> %s (%llu bytes)", gpath, real, (unsigned long long)*size);
        return 1;
    }
    // Overlays of two shipped TPK files (tools/remaster/world_overlays.py, tpkwrite.py): Cars/TEXTURES.BIN with the render targets
    // DUMMY_SKIN5..12 / DUMMY_WHEEL5..12 for the traffic racers (free mode, host/free.c), Global/DYNTEX.BIN with the SELECT LOCATION
    // pictures of the WORLD row. A missing overlay file leaves the original.
    {
        const char *par = b - 1;
        while (par > gpath && par[-1] != '/' && par[-1] != '\\') par--;
        const char *fe = getenv("RN_FREE");   // the overlay only feeds free mode; RN_FREE=0 (original mode) keeps the shipped file
        if (!(fe && fe[0] == '0') && b > gpath && ci_eq(b, "TEXTURES.BIN", 13) && ci_eq(par, "CARS", 4) && (par[4] == '/' || par[4] == '\\')) {
            if (world_file("CARS_TEXTURES.BIN", real, n, size)) { rn_tex_overlay = 1; rn_log("OPENWORLD: %s -> %s (%llu bytes)", gpath, real, (unsigned long long)*size); return 1; }
            return 0;
        }
        if (worldrow_on() && ci_eq(b, "DYNTEX.BIN", 11) && world_file("DYNTEX.BIN", real, n, size)) {
            rn_log("OPENWORLD: %s -> %s (%llu bytes)", gpath, real, (unsigned long long)*size);
            return 1;
        }
    }
    if (!ci_eq(b, "TRACKB", 6) || !isdigit((unsigned char)b[6])) return 0;
    const char *e = b + 6;
    unsigned id = 0;
    while (isdigit((unsigned char)*e)) id = id * 10 + (unsigned)(*e++ - '0');
    if (!ci_eq(e, ".LZC", 5)) return 0;
    char name[40];
    if (id == WORLD_ID && worldrow_on()) {
        // the WORLD row: its own file (tools/openworld/tour.py: the merged city with a closed road tour for the rivals, docs/openworld/tour.md);
        // without it the merged city of the base track
        if (world_file("TRACKB1010.lzc", real, n, size)) { rn_log("OPENWORLD: %s -> %s (%llu bytes)", gpath, real, (unsigned long long)*size); return 1; }
        id = WORLD_BASE;
    } else if (!enabled()) return 0;
    snprintf(name, sizeof name, "TRACKB%u.lzc", id);             // web: tools/serve.py serves build/openworld at /world/; host/files.c web_read fetches "<real>" by range
    if (!world_file(name, real, n, size)) { rn_log("OPENWORLD: the original TRACKB%u is used", id); return 0; }
    rn_log("OPENWORLD: %s -> %s (%llu bytes)", gpath, real, (unsigned long long)*size);
    return 1;
}


#ifndef __EMSCRIPTEN__
// ---- the test teleport ------------------------------------------------------------------------------------------------
static Ctx tc;                  // the thread's guest context
static uint32_t scratch;        // vec3 at +0, flag byte at +32

static int ctx_make(void) {
    Ctx *m = g_ctx;
    if (!m) return 0;
    tc = *m;
    memset(tc.r, 0, sizeof tc.r);
    tc.halt = 0;
    tc.cf = tc.zf = tc.sf = tc.of = tc.pf = tc.df = tc.af = 0;
    tc.fcw = 0x27f; tc.fsw = 0; tc.ftop = 0; tc.ftag = 0;
    uint32_t teb = guest_alloc(0x1000), lo = guest_alloc(0x80000), hi = lo + 0x80000;
    if (!teb || !lo) return 0;
    memcpy(tc.mem + teb, tc.mem + m->fs, 0x1000);
    tc.fs = teb;
    st(&tc, teb + 0x00, 0xffffffffu, 4);
    st(&tc, teb + 0x04, hi, 4);
    st(&tc, teb + 0x08, lo, 4);
    st(&tc, teb + 0x18, teb, 4);
    st(&tc, teb + 0x24, 0x7f0, 4);
    st(&tc, teb + 0x2c, teb + 0xe10, 4);
    tc.r[ESP] = hi - 64;
    scratch = guest_alloc(64);
    return scratch != 0;
}

// The player's node in the race list [0x7361f8] (host/free.c): its entrant (+0x14) has kind 1 at +4.
static uint32_t player_node(Ctx *c) {
    uint32_t h = ld(c, 0x7361f8, 4);
    if (!h || h >= GUEST_MEM - 0x1000) return 0;
    for (uint32_t r = ld(c, h, 4), k = 0; r && r != h && r < GUEST_MEM - 0x1000 && k < 200; r = ld(c, r, 4), k++) {
        uint32_t e = ld(c, r + 0x14, 4);
        if (e && e < GUEST_MEM - 16 && ld(c, e + 4, 4) == 1) return r;
    }
    return 0;
}

// The ground under p (3 floats in guest memory) by the game's own query on the car's cache object. Returns 1 with a height.
static int ground_at(uint32_t car, uint32_t p, float *h, int *flag) {
    st(&tc, scratch + 32, 0, 4);
    uint32_t a[5] = {car + 0x540, p, 0, 0, scratch + 32};
    uint32_t ft = tc.ftop;
    call_guest(&tc, 0x440a40, 5, a);
    *h = (float)*fr(&tc, 0);
    fpop(&tc);
    tc.ftop = ft;
    *flag = (int)ld(&tc, scratch + 32, 1);
    return *flag != 0;
}

// The game's own zone search 0x4436d0 (ecx = zone manager 0x7372b0, edx = type, eax = 0: from the first row, edi = the point
// xy = car+0x800 as 0x430e00 passes it, stack arg = the track direction [0x78a2fc]): the first zone row of that type that
// holds the car, 0 = none. docs/openworld/re_zones.md. Types 2 RESET and 3 RESET_TO_POINT are what 0x430e00 asks for.
static uint32_t zone_at(uint32_t car, uint32_t type) {
    uint32_t a[1] = {ld(&tc, 0x78a2fc, 4)};
    tc.r[ECX] = 0x7372b0; tc.r[EDX] = type; tc.r[EAX] = 0; tc.r[EDI] = car + 0x800;
    return call_guest(&tc, 0x4436d0, 1, a);
}

// car+0x87c is the "reset me" flag 0x427ed0 raises for a RESET zone (0x4264d0 consumes it); +0x1e0/+0x1e4 the velocity.
static void dump(Ctx *c, const char *what, uint32_t node, uint32_t car) {
    float h = 0; int flag = 0, ok = 0;
    if (car) ok = ground_at(car, car + 0x60, &h, &flag);
    rn_log("OPENWORLD %s: frame %u node %08x pos %.2f %.2f %.2f | car %08x (player view obj [0x740500] %08x) pos %.2f %.2f %.2f yaw16 %d | game ground query 0x440a40 at the car: %s height %.2f (flag byte %d) | car+0x87c %u speed %.1f m/s | zone RESET %08x RESET_TO_POINT %08x",
           what, rn_telem.presents, node, ldf(c, node + 0x50), ldf(c, node + 0x54), ldf(c, node + 0x58), car, ld(c, 0x740500, 4),
           ldf(c, car + 0x60), ldf(c, car + 0x64), ldf(c, car + 0x68), (int16_t)ld(c, car + 0x3b4, 2), ok ? "GROUND" : "NO GROUND", h, flag,
           ld(c, car + 0x87c, 4), hypotf(ldf(c, car + 0x1e0), ldf(c, car + 0x1e4)), zone_at(car, 2), zone_at(car, 3));
}

static void *tp_thread(void *arg) {
    (void)arg;
    float at[4] = {0};
    int nat = strcmp(getenv("RN_WORLD_AT"), "log") ? sscanf(getenv("RN_WORLD_AT"), "%f,%f,%f,%f", &at[0], &at[1], &at[2], &at[3]) : -1;
    const char *w = getenv("RN_WORLD_WAIT"), *l = getenv("RN_WORLD_LOG");
    unsigned wait = w ? (unsigned)atoi(w) : 0, every = l && atoi(l) > 0 ? (unsigned)atoi(l) : 60;
    if (nat >= 0 && nat < 3) { rn_log("OPENWORLD: cannot read RN_WORLD_AT \"%s\" (x,y,z[,yaw16])", getenv("RN_WORLD_AT")); return NULL; }
    const char *mv = getenv("RN_WORLD_MOVE");
    float move = mv ? (float)atof(mv) : 120;     // the race has started (the start in 0x422eb0 resets cars at GO) once the car left the grid by this much
    const char *fl = getenv("RN_WORLD_FLOW");    // test only: count RN_WORLD_WAIT presents from when the race state (flow 6/N) reaches N (4 = GO), not from the first state 6
    int flow_n = fl ? atoi(fl) : 0;
    // test only, RN_WORLD_PUSH="speed,metres": after the teleport the car's velocity (car+0x70/+0x74, as RN_STEERLOG reads it) is set each poll
    // to speed m/s along the teleport yaw until the car is that many metres from the point: a straight drive (the keys do not throttle in the native run).
    float push_v = 0, push_d = 0;
    if (getenv("RN_WORLD_PUSH")) sscanf(getenv("RN_WORLD_PUSH"), "%f,%f", &push_v, &push_d);
    int pushing = 0;
    unsigned raced = 0, last = 0;
    float p0[2] = {0, 0}, pp[2] = {0, 0};
    uint32_t f87 = 0, z2 = 0, z3 = 0;
    int havep = 0;
    int done = 0, made = 0, have0 = 0;
    for (;;) {
        usleep(20000);
        gil_acquire();
        Ctx *c = g_ctx;
        if (c && !c->halt) {
            if (!rn_racing()) { raced = 0; }
            else {
                if (flow_n && (rn_flow >> 8) != 6) raced = 0;
                else if (flow_n && (rn_flow & 0xff) != (unsigned)flow_n) raced = 0;
                else if (!raced) raced = rn_telem.presents + 1;
                if (!made) made = ctx_make();
                uint32_t node = made ? player_node(c) : 0;
                uint32_t car = node;   // the list node is the car object itself (its +0x60 is the position 0x422eb0 reads from [[0x7361f8]+0x28])
                if (car && car < GUEST_MEM - 0x1000) {
                    unsigned age = rn_telem.presents + 1 - raced;
                    if (!have0) { p0[0] = ldf(c, car + 0x60); p0[1] = ldf(c, car + 0x64); have0 = 1; }
                    // Events between the periodic lines (the reset flag is consumed within a frame or two): a jump of the
                    // car > 15 m between two polls, car+0x87c changing, and entering or leaving a RESET / RESET_TO_POINT zone.
                    if (made) {
                        float cx = ldf(c, car + 0x60), cy = ldf(c, car + 0x64);
                        uint32_t v87 = ld(c, car + 0x87c, 4), n2 = zone_at(car, 2), n3 = zone_at(car, 3);
                        if (havep && hypotf(cx - pp[0], cy - pp[1]) > 15) { rn_log("OPENWORLD JUMP %.1f m from %.2f %.2f", hypotf(cx - pp[0], cy - pp[1]), pp[0], pp[1]); dump(c, "jump", node, car); }
                        else if (v87 != f87 || n2 != z2 || n3 != z3) dump(c, v87 != f87 ? "flag 0x87c changed" : "zone changed", node, car);
                        pp[0] = cx; pp[1] = cy; havep = 1; f87 = v87; z2 = n2; z3 = n3;
                    }
                    if (done && push_v > 0 && nat > 3) {
                        float dx = ldf(c, car + 0x60) - at[0], dy = ldf(c, car + 0x64) - at[1];
                        if (hypotf(dx, dy) < push_d) {
                            float a = at[3] * 6.2831853f / 65536.f;
                            stf(c, car + 0x70, push_v * cosf(a)); stf(c, car + 0x74, push_v * sinf(a));
                            if (!pushing) { rn_log("OPENWORLD: push %.1f m/s for %.1f m starts at frame %u", push_v, push_d, rn_telem.presents); pushing = 1; }
                        } else if (pushing) { rn_log("OPENWORLD: push ends at frame %u, %.1f m from the point", rn_telem.presents, hypotf(dx, dy)); pushing = 0; push_v = 0; }
                    }
                    int moved = hypotf(ldf(c, car + 0x60) - p0[0], ldf(c, car + 0x64) - p0[1]) >= move;
                    if (raced && age >= wait && moved && !done && nat >= 3) {
                        dump(c, "before", node, car);
                        stf(&tc, scratch, at[0]); stf(&tc, scratch + 4, at[1]); stf(&tc, scratch + 8, at[2]);
                        uint32_t a[2] = {0, 0};
                        tc.r[ECX] = car; tc.r[EDX] = scratch; tc.r[EAX] = nat > 3 ? (uint32_t)(int32_t)at[3] : ld(c, car + 0x3b4, 2);
                        call_guest(&tc, 0x427e60, 2, a);
                        // the streamer's viewer, as the start in 0x422eb0 seeds it: 0x444840(eax = 0, edx = 0x77a980, ecx = &car pos)
                        tc.r[EAX] = 0; tc.r[EDX] = 0x77a980; tc.r[ECX] = car + 0x60;
                        call_guest(&tc, 0x444840, 0, NULL);
                        done = 1; havep = 0;   // the teleport is not a jump to report
                        rn_log("OPENWORLD: teleport asked %.1f %.1f %.1f yaw %d, halt %u at %08x %s", at[0], at[1], at[2], nat > 3 ? (int)at[3] : -1, tc.halt, tc.halt_at, tc.why ? tc.why : "");
                        if (tc.halt) { tc.halt = 0; tc.why = NULL; tc.r[ESP] = ld(&tc, tc.fs + 4, 4) - 64; }
                        dump(c, "after", node, car);
                        last = rn_telem.presents;
                    } else if (rn_telem.presents - last >= every) {
                        dump(c, done ? "run" : "wait", node, car);
                        last = rn_telem.presents;
                    }
                }
            }
        }
        gil_release();
    }
    return NULL;
}
#endif
