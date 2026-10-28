// BRIDGE: free mode (OWNER 2026-10-27: "on the track with real rivals driving, like a free online"), not in the original.
// Quick Race Free Run (mode 3, setup 0x4b5090) is the game's own endless drive: laps [0x78a31c] = 0, so nobody finishes.
// It registers only the player (0x5809c0 kind 1, grid [0x78a334] = 2) and the traffic (0x4b3ac0), and never calls the
// opponent builder 0x4b4040 that Circuit (0x4b49e0) calls with ([0x78a324] opponents, 0). Everything after that is mode
// blind (REA ev_289db272, ev_6d7d9c51): the race start 0x422a70 walks grid slots 1..4 of the entrant table [0x78a418]
// (0x750 each: +3 grid, +4 kind 1 player / 2 opponent / 3 traffic, +0x10 RideInfo) and builds each car with 0x422410,
// which gives an opponent driver type 3, the racer AI (0x425150, skill [0x6b7c20 + 4 * [0x78a40c]], 0x4a9900).
// PATCH 0x4b528d sends Free Run's traffic call here (cave 0x6736b7: jmp [SCREEN_ADDR+0x68]). With RN_FREE on, it sets
// [0x78a324] = 3 and calls 0x4b4040(3, 0) as Circuit does, the player first on the grid and the rivals behind; each
// opponent then reaches host/rivals.c rival_ride, which hands it to free_rival: one of the career's own rivals (name and
// preset of their last event, census/career_oracle.json), dressed by the game's preset code 0x4b26f0 (eax = preset hash,
// the career path at 0x4b4155). 0x4b4380, which 0x4b4040 runs in Quick Race, then matches every opponent's rating to the
// player's (0x57f700). RN_FREE=0: Free Run as shipped.
#include "host.h"
#include <math.h>
#include <string.h>

#define NRIV 3

// The career's rivals (census/career_oracle.json: every event's opponents, each name with the preset of its last event).
static const struct { const char *name; uint32_t preset; } CANON[] = {
    {"BRIAN", 0xa76ad63d}, {"BRETT", 0x8d2d3d32}, {"LOLA", 0x32d6d2f5}, {"WART", 0x3e438ee6}, {"NESTO", 0x493349a9},
    {"JOSE", 0x496e17a8}, {"ROSIE", 0xf713b959}, {"JACKIE", 0x6b75fb86}, {"BRYCE", 0x71845b7d}, {"CARL", 0xbff2ba3c},
    {"CARLA", 0xf5ea3c46}, {"DIRT", 0x6f1ac102}, {"DARYL", 0xb83c0594}, {"KLUTCH", 0x6408b98a}, {"PRISS", 0x7335abb4},
    {"STEFAN", 0x4e07a75c}, {"PROBES", 0x283031c5}, {"STEWART", 0x3328d41a}, {"AL", 0x98b598cb}, {"SCOTT", 0x869bd62b},
    {"HUNTER", 0xf71014d2}, {"TERRY", 0xf9ed7e06}, {"FISH", 0x4fa5993d}, {"LEBRON", 0x3bd031d5}, {"MACCA", 0x49f9c026},
    {"HECTOR", 0x6ff2a4c1}, {"JET", 0x43fe5c0b}, {"SPIN", 0x939ccbd4}, {"DESHAWN", 0xb708963b}, {"WILL", 0xdb2d97c0},
    {"MUTT", 0xa0f830fe}, {"RICCO", 0x3ea53eed}, {"HOFFMAN", 0x46ae2a9a}, {"CHAD", 0x9f2a8223}, {"JARED", 0xb62f8a53},
    {"TODD", 0xf9a6c94e}, {"BRAD", 0x6c79e5d4}, {"PAUL", 0x7bf9866c}, {"BOPPER", 0x5aa66cf5}, {"LAZIO", 0xf0f1052f},
    {"MACK-D", 0x4c9b52c8}, {"KURT", 0x174fa745}, {"B-DOG", 0xe8a7e7be}, {"BRITTON", 0x3bcf59bc},
    {"TANAKA", 0xe604f578}, {"VINCE", 0x541a96c6}, {"TAKASHI", 0x465bbc40}, {"NUTZ", 0xe8171d01}, {"STAN", 0x4438edd1},
    {"TICKETS", 0xf5cd094d}, {"GEARS", 0x5c075321}, {"VIONCE", 0x541a96c5}, {"SKID", 0x41234aa7},
    {"ISHII", 0xa7feadd8}, {"WU", 0x0fca18ce}, {"FORGE", 0xfc79d032}, {"MATT", 0xec5c29db}, {"SLIK", 0x8837ee78},
    {"JARRUS", 0x3f9cd43c}, {"KIRBY", 0xe7a47752}, {"SAMANTHA", 0xa4045c39}, {"KAZ", 0x4b23fd55},
    {"SPARKS", 0xba053fb6}, {"AMY", 0x45f16bb8}, {"TJ", 0x33f2f54a}, {"EDDIE", 0x7a282c98}, {"MELISSA", 0xf35d35de},
};
#define NCANON (int)(sizeof CANON / sizeof *CANON)

int rn_free_now;                 // 1 while 0x4b4040 builds free mode's rivals (host/rivals.c rival_ride asks free_rival), 2 in its traffic
static int on, live, picked[NRIV], npicked;
static uint32_t names;           // NRIV guest strings of 16 bytes: 0x5809c0 copies the entrant name from its 4th argument

static uint32_t rnd(uint32_t *s) { uint32_t x = *s; x ^= x << 13; x ^= x >> 17; x ^= x << 5; return *s = x ? x : 0x9e3779b9u; }
static uint32_t ghash(Ctx *c, uint32_t p) { uint32_t h = 0xffffffffu; for (uint8_t b; (b = c->mem[p]); p++) h = h * 33 + b; return h; }
static uint32_t preset_named(Ctx *c, uint32_t h) {   // the game's preset list 0x748844 (0x4b2640 finds them the same way)
    for (uint32_t p = ld(c, 0x748844, 4); p && p != 0x748844; p = ld(c, p, 4))
        if (ghash(c, p + 0x28) == h) return p;
    return 0;
}

// 0x5809c0(id, 2, ride, name, skill, ?, index) of one free mode rival: a career rival not yet in this race.
uint32_t free_rival(Ctx *c, uint32_t *a) {
    uint32_t s = ld(c, 0x6f227c, 4) ^ (a[6] * 0x85ebca6bu) ^ rn_telem.presents * 0x9e3779b9u;
    int k = rnd(&s) % NCANON;
    for (int tries = 0; tries < NCANON; tries++, k = (k + 1) % NCANON) {
        int dup = 0;
        for (int j = 0; j < npicked; j++) dup |= picked[j] == k;
        if (!dup) break;
    }
    uint32_t ride = a[2], rec = preset_named(c, CANON[k].preset);
    if (rec) {
        uint32_t one = ride;
        c->r[EAX] = CANON[k].preset;
        call_guest_cdecl(c, 0x4b26f0, 1, &one);
        uint32_t nm = names + 16 * (npicked % NRIV);
        snprintf(G(nm), 16, "%s", CANON[k].name);
        a[3] = nm;
    }
    if (npicked < NRIV) picked[npicked++] = k;
    if (getenv("RN_FREELOG"))
        rn_log("FREE rival %u: %s preset %08x %s (%s)", a[6], CANON[k].name, CANON[k].preset, rec ? "applied" : "MISSING",
               rec ? G(rec + 0x28) : "-");
    return call_guest(c, 0x5809c0, 7, a);
}

// In place of Free Run's call to AddTrafficCars 0x4b3ac0 (no arguments).
static uint32_t free_setup(Ctx *c) {
    if (!on) { const char *e = getenv("RN_FREE"); on = e && e[0] == '0' ? -1 : 1; }
    if (on > 0 && ld(c, 0x777cc8, 4) == 3 && !c->mem[0x78a347]) {
        if (!names) names = guest_alloc(16 * NRIV);
        uint32_t tab = ld(c, 0x78a418, 4), n = ld(c, 0x78a41c, 4);
        for (uint32_t i = 0; i < n; i++)                          // the player leads the grid (0x422a70 slot 1 = the front)
            if (ld(c, tab + 0x750 * i + 4, 4) == 1) c->mem[tab + 0x750 * i + 3] = 1;
        c->mem[0x78a334] = 1;
        st(c, 0x78a324, NRIV, 4);
        npicked = 0, rn_free_now = 1;
        uint32_t args[2] = {NRIV, 0};
        call_guest_cdecl(c, 0x4b4040, 2, args);
        rn_free_now = 0;
        tab = ld(c, 0x78a418, 4), n = ld(c, 0x78a41c, 4);
        for (uint32_t i = 0, g = 2; i < n; i++)                   // 0x4b4040 numbered them 1..3: behind the player, 2..4
            if (ld(c, tab + 0x750 * i + 4, 4) == 2) c->mem[tab + 0x750 * i + 3] = g++;
        if (getenv("RN_FREELOG")) rn_log("FREE setup: %u entrants, %u rivals at frame %u", n, NRIV, rn_telem.presents);
        live = 1, rn_free_now = 2;                                // AddTrafficCars: free_traffic dresses the racer rows
    }
    uint32_t r = call_guest(c, 0x4b3ac0, 0, NULL);
    rn_free_now = 0;
    return r;
}

// Tuned traffic. AddTrafficCars 0x4b3ac0 builds each traffic ride stock (0x57d160 type, 0x57d340, 0x57e9a0 the first
// paint) and registers it with 0x5809c0(0x32 + i, 3, ride, "", -1, 0, 0) at 0x4b3c2f; the traffic pool (PATCH 0x57d060)
// also picks racer rows, type usage 0 ([0x734588] + 0xc90 * type + 0xc54). PATCH 0x4b3c2f sends that call here (cave
// 0x43a7ea: jmp [SCREEN_ADDR+0x6c]). In free mode a racer row wears the preset of a career rival with the same car,
// applied by 0x4b26f0 (it resets the ride to the preset's car, 0x57cf70 -> 0x57d160, then sets its 0x78 part slots at
// ride +0x44c). A traffic ride has no skin of its own (0x57d160 zeroes the DUMMY_SKIN / DUMMY_WHEEL hashes at +0x444 /
// +0x448, which 0x4b4040 sets for the four racers only), so the vinyl, decal and rim paint slots are cleared again, the
// way 0x57e9a0 clears the vinyls of stock traffic, and 0x57ea80 (stdcall, the ride) recomputes the ride's derived state.
static int8_t ctype[NCANON];      // the car type of each career preset (-1 = not in the game's list), filled once
static uint32_t free_traffic(Ctx *c) {
    uint32_t a[7];
    for (int k = 0; k < 7; k++) a[k] = ARG(k);
    uint32_t ride = a[2], type = ld(c, ride, 4), tab = ld(c, 0x734588, 4);
    if (rn_free_now == 2 && tab && ld(c, tab + 0xc90 * type + 0xc54, 4) == 0) {
        static int typed;
        if (!typed++) {
            uint32_t tmp = guest_alloc(0x720);
            for (int k = 0; k < NCANON; k++) {
                ctype[k] = -1;
                if (!preset_named(c, CANON[k].preset)) continue;
                uint32_t one = tmp;
                c->r[EAX] = CANON[k].preset;
                call_guest_cdecl(c, 0x4b26f0, 1, &one);
                ctype[k] = (int8_t)ld(c, tmp, 4);
            }
            guest_free(tmp);
        }
        int cand[NCANON], n = 0;
        for (int k = 0; k < NCANON; k++) if (ctype[k] == (int)type) cand[n++] = k;
        if (n) {
            uint32_t s = ld(c, 0x6f227c, 4) ^ a[0] * 0x9e3779b9u, one = ride;
            int k = cand[rnd(&s) % n];
            c->r[EAX] = CANON[k].preset;
            call_guest_cdecl(c, 0x4b26f0, 1, &one);
            for (int sl = 0x13; sl <= 0x72; sl++)
                if (sl <= 0x1d || (sl >= 0x1f && sl <= 0x22) || sl == 0x29 || sl >= 0x2a) {
                    st(c, ride + 0x44c + 4 * sl, 0, 4);
                    c->mem[ride + 0x62c + sl]++;
                }
            call_guest(c, 0x57ea80, 1, &one);
            if (getenv("RN_FREELOG")) rn_log("FREE traffic %u: type %u wears %s's preset %08x", a[0], type, CANON[k].name, CANON[k].preset);
        }
    }
    return call_guest(c, 0x5809c0, 7, a);
}

// Each Present (host/d3d9.c): with RN_FREELOG, every 2 s of a free mode race, each rival's distance to the player. A car of
// the race list [0x7361f8] (next at +0, position +0x50, host/lights.c) points at its entrant at +0x14 (0x425150 reads it).
void free_tick(Ctx *c) {
    static int raced;
    if (!live) return;
    // The setup runs in the front end (state 3, runs/jump_3_1001): the race is over once state 6 went back to 3.
    if (ld(c, 0x77a920, 4) != 6) { if (raced && ld(c, 0x77a920, 4) == 3) live = raced = 0; return; }
    raced = 1;
    static int log = -1;
    if (log < 0) log = getenv("RN_FREELOG") != NULL;
    if (!log || rn_telem.presents % 120) return;
    uint32_t h = ld(c, 0x7361f8, 4), player = 0;
    int ntraffic = 0;
    for (uint32_t r = h ? ld(c, h, 4) : 0, k = 0; r && r != h && k < 200; r = ld(c, r, 4), k++) {
        uint32_t e = ld(c, r + 0x14, 4), kind = e ? ld(c, e + 4, 4) : 0;
        if (kind == 1) player = r;
        ntraffic += kind == 3;
    }
    if (!player) return;
    char line[256]; int o = snprintf(line, sizeof line, "FREE frame %u traffic %d:", rn_telem.presents, ntraffic);
    for (uint32_t r = ld(c, h, 4), k = 0; r != h && k < 200; r = ld(c, r, 4), k++) {
        uint32_t e = ld(c, r + 0x14, 4);
        if (!e || ld(c, e + 4, 4) != 2) continue;
        double dx = ldf(c, r + 0x50) - ldf(c, player + 0x50), dy = ldf(c, r + 0x54) - ldf(c, player + 0x54);
        double dz = ldf(c, r + 0x58) - ldf(c, player + 0x58);
        o += snprintf(line + o, sizeof line - o, " %s %.0f m", G(e + 0x73c), sqrt(dx * dx + dy * dy + dz * dz));
        if (o > 200) break;
    }
    // The three nearest traffic cars (kind 3): whether the game keeps traffic near the player at all.
    double near[3] = {1e9, 1e9, 1e9};
    for (uint32_t r = ld(c, h, 4), k = 0; r != h && k < 200; r = ld(c, r, 4), k++) {
        uint32_t e = ld(c, r + 0x14, 4);
        if (!e || ld(c, e + 4, 4) != 3) continue;
        double dx = ldf(c, r + 0x50) - ldf(c, player + 0x50), dy = ldf(c, r + 0x54) - ldf(c, player + 0x54);
        double d = sqrt(dx * dx + dy * dy);
        for (int j = 0; j < 3; j++) if (d < near[j]) { double t = near[j]; near[j] = d; d = t; }
    }
    o += snprintf(line + o, sizeof line - o, " | traffic near %.0f %.0f %.0f m", near[0], near[1], near[2]);
    rn_log("%s", line);
}

uint32_t world_rows(Ctx *c), world_lang(Ctx *c);   // host/openworld.c: the WORLD entry of the Free Run list (PATCH 0x7007ec, 0x700850)
const Api free_apis[] = {{"rn", "free_setup", 0, free_setup}, {"rn", "free_traffic", 7, free_traffic},
                         {"rn", "world_rows", -1, world_rows}, {"rn", "world_lang", -1, world_lang}};
const int free_api_count = 4;
