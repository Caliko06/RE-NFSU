// BRIDGE: rivals with a soul in Quick Race (OWNER 2026-10-27), not in the original. The game builds each opponent in 0x4b4040:
// in the career ([0x78a33c] != 0) it takes the event's fixed preset (0x4b26f0, list 0x748844, FrontB.lzc chunk 0x30220: 184
// presets of 0x408 bytes) or, past the event's records, a stock car with a random paint (0x4b3c60); quick race always the
// latter. Then it matches the opponent's rating to the player's (0x57f700 / 0x57f970) and registers it with 0x5809c0.
// PATCH 0x4b4321 sends that call here first (cave 0x6736b1: jmp [SCREEN_ADDR+0x60]).
//
// The Underground career keeps the game's own rivals, always (OWNER 2026-10-27: the canon is the real cars). In Quick Race
// every opponent becomes one of POOL procedural personas (name, car, archetype, seed) with a build of its tier made of the
// game's own parts (GLOBALB 0x80034602, read live from the list at 0x73ad40): kit, widebody, hood, roof scoop, wing,
// lights, exhaust, brakes, rims, paint, vinyl layers and their colours, sponsor decals, tint, neon. The build goes into a
// preset record of our own, and the game's preset code 0x4b26f0 applies it. 0x57f700 then matches the new car to the
// rating the game chose, and the archetype moves one tuning category per group by +-1 (its driving). RN_RIVALS=0: the
// original in Quick Race too.
#include "host.h"
#include <string.h>
#include <math.h>

#define POOL 300
#define NSYN 8                  // synthetic preset records: one per opponent slot of a race
#define RIDE_SIZE 0x720         // RideInfo: 0x57d160 clears up to +0x71c
enum { CLEAN, SHOW, DRIFT, SLEEPER, STREET, BOSO, VIP, TRACK, NARCH };

static const char *CARS[20] = {"GOLF", "FOCUS", "MIATA", "NEON", "CIVIC", "PEUGOT", "CELICA", "ECLIPSE", "RX7", "SUPRA",
    "S2000", "RSX", "IMPREZA", "LANCER", "INTEGRA", "TIBURON", "350Z", "SENTRA", "240SX", "SKYLINE"};

typedef struct {
    const char *name;
    uint8_t kit, wide, hood, scoop, wing, lights, exhaust;   // % at tier 3 (tier t: x t/3)
    uint8_t vinyl, layers, decals, neon, tint;               // % vinyl, max layers, decals per door, % neon, tint 0..2
    int8_t power, grip, accel;                               // driving: +-1 on one category of each group
    uint32_t paint[8];                                        // body colours (0xRRGGBB), 0 ends
    const char *wings, *rims, *vinyls, *brands;               // '|' lists of name prefixes; "" = any
    uint32_t rimcol[3];                                       // rim paint
    uint8_t cars[12];                                         // car ids it likes, 0xff ends
} Arch;

static const Arch ARCH[NARCH] = {
    [CLEAN] = {"jdm-clean", 55, 0, 25, 0, 45, 30, 50, 25, 1, 1, 0, 0, -1, 1, 0,
               {0xf2f2ee, 0xc0c4c8, 0x18181c, 0x5a5f66, 0xb0121b, 0x1a3f9a, 0xe8c400},
               "FLYTE|TOURING|AEROMAX|CARBON X|TRIVO", "ENKEI|BBS|RACING", "STRIPE|BODY",
               "HKS|GREDDY|APEX|ENKEI|BBS|SKUNK2|JSP|5ZIGEN", {0x8c6a3a, 0xf0f0f0, 0xc8a040},
               {4, 11, 14, 10, 9, 19, 8, 12, 2, 0xff}},
    [SHOW] = {"show", 100, 45, 60, 40, 80, 90, 80, 100, 3, 3, 90, 1, -1, 0, 1,
              {0x6a1fb0, 0x2bd12b, 0x0e7fe0, 0xff6a00, 0xe0e0f0, 0xc0107a, 0x00b5b0},
              "SUPERNOVA|INFERNO|MAKO|BACKDRAFT|KATANA|DUOTEK|BOOMERANG", "MOMO|KONIG|NINJA|SIX|CYCLONE|FIVE",
              "TRIBAL|SPLASH|WILD|MODERN|LIGHTNING|TEAR", "KENWOOD|ALPINE|AUDIOBAHN|PLASMAGLOW|STREET GLOW|NOS|NITROUS",
              {0xc0c0c0, 0xc8a040, 0x141414}, {7, 6, 4, 3, 15, 11, 14, 16, 1, 0xff}},
    [DRIFT] = {"drift", 85, 25, 70, 10, 85, 40, 70, 75, 2, 2, 20, 1, 1, -1, 0,
               {0xff5a00, 0xf2f2ee, 0x101012, 0x7fd000, 0xe0b000, 0x2050c0, 0xc81e1e},
               "ALUMINUM GT|DUAL GT|KATANA|WARHAWK|DOWNFORCE", "KONIG|ENKEI|RACING", "TEAR|STRIPE|SPLASH|WILD",
               "GREDDY|HKS|TOYO|YOKOHAMA|KUMHO|APEX|BILSTEIN|SPARCO", {0x8c6a3a, 0x141414, 0xf0f0f0},
               {18, 8, 19, 16, 10, 9, 2, 6, 0xff}},
    [SLEEPER] = {"sleeper", 10, 0, 10, 0, 5, 10, 40, 0, 0, 0, 0, 2, 1, 0, 0,
                 {0x18181c, 0x2e3238, 0x1c2a44, 0x5a1418, 0x6e7276, 0xb8b8b0},
                 "FLYTE", "ENKEI|O.Z.", "", "", {0x141414, 0x404448, 0x404448}, {17, 13, 12, 1, 0, 4, 14, 5, 0xff}},
    [STREET] = {"street", 90, 20, 50, 45, 80, 60, 70, 85, 2, 3, 55, 1, 0, -1, 1,
                {0x1060e0, 0xc81e1e, 0xf0f0f0, 0x101012, 0xffc000, 0x20a040, 0x8a2be2, 0x00a0d0},
                "", "", "TRIBAL|FLAME|STRIPE|LIGHTNING|MODERN|BODY", "NOS|NITROUS|AEM|INJEN|HKS|GREDDY|SPARCO|MOMO|NEUSPEED",
                {0xc0c0c0, 0x141414, 0xc8a040}, {0xff}},
    [BOSO] = {"bosozoku", 95, 40, 60, 80, 100, 70, 90, 95, 3, 2, 70, 1, 1, -1, 0,
              {0xc000c0, 0xffd000, 0xe01010, 0x10a040, 0xff8000, 0xf0f0f0, 0x2040ff},
              "HAMMERHEAD|BOOMERANG|SUPERNOVA|WARHAWK|INFERNO|DUOTEK", "SIX|NINJA|CYCLONE|KONIG",
              "FLAME|LIGHTNING|WILD|TRIBAL|FLAG", "", {0xc8a040, 0xf0f0f0, 0x141414}, {9, 19, 4, 18, 6, 8, 14, 0xff}},
    [VIP] = {"vip", 50, 0, 0, 0, 25, 40, 50, 0, 0, 0, 10, 2, 0, 1, -1,
             {0x0e0e10, 0xd8ccb0, 0x4a1018, 0x2a2e36, 0xe8e8e4, 0x1a2238},
             "FLYTE|GRIFTER", "BBS|LIVIA|SPLIT|FIVE", "", "BBS", {0xc0c0c0, 0xc8a040, 0x141414},
             {13, 17, 12, 9, 19, 16, 0xff}},
    [TRACK] = {"time-attack", 75, 15, 80, 0, 95, 30, 60, 60, 1, 4, 0, 1, 0, 1, 0,
               {0xf2f2ee, 0xc0c4c8, 0xd01818, 0x1a3f9a, 0xf0c000, 0x101012},
               "DOWNFORCE|ALUMINUM GT|DUAL GT|CARBON X|TRIVO", "ENKEI|O.Z.|BBS", "STRIPE|FLAG",
               "SPARCO|BREMBO|TOYO|YOKOHAMA|KUMHO|AEM|MOMO|HKS|EIBACH|KONI|WILWOOD|ACT", {0xf0f0f0, 0x8c6a3a, 0xc8a040},
               {10, 8, 12, 13, 2, 14, 11, 4, 19, 0xff}},
};
static const uint8_t ARCH_W[NARCH] = {15, 15, 13, 9, 20, 9, 9, 10};

static const char *NAMES[] = {"Kaze", "Ryu", "Nova", "Vex", "Jinx", "Slick", "Torque", "Apex", "Blitz", "Rook", "Haze", "Zero",
    "Kenji", "Mika", "Dante", "Rico", "Luz", "Nico", "Yuki", "Taz", "Juno", "Rex", "Ivy", "Kai", "Sable", "Ghost", "Rhino",
    "Viper", "Echo", "Neko", "Dash", "Ozzy", "Kilo", "Remy", "Sasha", "Bix", "Cruz", "Drex", "Flint", "Gio", "Hex", "Inez",
    "Jett", "Koda", "Lux", "Moxie", "Nash", "Omar", "Pike", "Quinn", "Raze", "Sly", "Tank", "Ume", "Vega", "Wolf", "Xan",
    "Yoshi", "Zed", "Akira", "Benji", "Coco", "Deuce", "Ezra", "Fang", "Gunz", "Hiro", "Iggy", "Jade", "Knox", "Lobo", "Mars",
    "Nyx", "Onyx", "Pixie", "Ruby", "Stix", "Toshi", "Vince", "Wren", "Xeno", "Yara", "Zoey", "Ace", "Bolt", "Cyra", "Diaz",
    "Ember", "Fizz", "Gator", "Holly", "Ink", "Jolt", "Kobe", "Lefty", "Mako", "Nitro", "Odie", "Pablo", "Rascal", "Shin",
    "Tito", "Uri", "Vida", "Wiz", "Yuri", "Zuri", "Maya", "Tre", "Lalo", "Kat", "Spike", "Rocco", "Chula", "Mondo"};
#define NNAMES (int)(sizeof NAMES / sizeof *NAMES)

typedef struct { char name[8]; uint8_t car, arch; uint32_t seed; } Persona;
typedef struct { uint32_t rec, car, key, name; uint8_t slot, lvl, rgb[3], kind; } Part;   // kind: paint family
enum { K_NONE, K_GLOSS, K_METAL, K_PEARL, K_CUSTOM, K_VINYL, K_RIMS, K_CALIPERS, K_MUFFLERS };

static Persona pool[POOL];
static Part *parts;
static int nparts, ready, on;
static uint32_t syn[NSYN], used[NSYN], nused;
static uint32_t carhash[20];

static uint32_t hash(const char *s) { uint32_t h = 0xffffffffu; while (*s) h = h * 33 + (uint8_t)*s++; return h; }
static uint32_t ghash(Ctx *c, uint32_t p) { uint32_t h = 0xffffffffu; for (uint8_t b; (b = c->mem[p]); p++) h = h * 33 + b; return h; }
static uint32_t rnd(uint32_t *s) { uint32_t x = *s; x ^= x << 13; x ^= x >> 17; x ^= x << 5; return *s = x ? x : 0x9e3779b9u; }
static int roll(uint32_t *s, int pct) { return (int)(rnd(s) % 100) < pct; }
static int prefixed(const char *name, const char *list) {         // name starts with one of "A|B|C"; "" = any
    if (!*list) return 1;
    for (const char *p = list; *p;) {
        const char *e = strchr(p, '|'); size_t n = e ? (size_t)(e - p) : strlen(p);
        if (!strncmp(name, p, n)) return 1;
        p += n + (e != NULL);
    }
    return 0;
}

// The parts list the game loaded (0x57c927): node +0xc records, +0x10 count; record 0x30: +0 name, +4 car (or the shared
// group of the slot), +8 key, +0x10 slot, +0x11 unlock level, +0x14 attributes (key, value) x [+0x1c].
static void catalog(Ctx *c) {
    uint32_t hR = hash("RED"), hG = hash("GREEN"), hB = hash("BLUE");
    int cap = 0;
    for (uint32_t n = ld(c, 0x73ad40, 4); n && n != 0x73ad40; n = ld(c, n, 4)) cap += ld(c, n + 0x10, 4);
    parts = calloc(cap, sizeof *parts);
    for (uint32_t n = ld(c, 0x73ad40, 4); n && n != 0x73ad40; n = ld(c, n, 4))
        for (uint32_t r = ld(c, n + 0xc, 4), e = r + 0x30 * ld(c, n + 0x10, 4); r < e && nparts < cap; r += 0x30) {
            Part *p = &parts[nparts++];
            p->rec = r; p->name = ld(c, r, 4); p->car = ld(c, r + 4, 4); p->key = ld(c, r + 8, 4);
            p->slot = c->mem[r + 0x10]; p->lvl = c->mem[r + 0x11];
            for (uint32_t a = ld(c, r + 0x14, 4), k = 0, na = ld(c, r + 0x1c, 2); a && k < na; k++) {
                uint32_t key = ld(c, a + 8 * k, 4), v = ld(c, a + 8 * k + 4, 4);
                if (key == hR) p->rgb[0] = v; else if (key == hG) p->rgb[1] = v; else if (key == hB) p->rgb[2] = v;
            }
            const char *s = G(p->name);
            p->kind = !strncmp(s, "GLOSS", 5) ? K_GLOSS : !strncmp(s, "METAL", 5) ? K_METAL : !strncmp(s, "PEARL", 5) ? K_PEARL
                    : !strncmp(s, "CUSTOMPAINT", 11) ? K_CUSTOM : !strncmp(s, "VINYL_", 6) ? K_VINYL : !strncmp(s, "RIMS_", 5) ? K_RIMS
                    : !strncmp(s, "CALIPERS_", 9) ? K_CALIPERS : !strncmp(s, "MUFFLERS_", 9) ? K_MUFFLERS : K_NONE;
        }
    for (int k = 0; k < 20; k++) carhash[k] = hash(CARS[k]);
    // The pool: the same personas for every save (a fixed seed), so a rival keeps its name, car and style.
    uint32_t s = 0x0dd0c0deu;
    for (int i = 0; i < POOL; i++) {
        Persona *p = &pool[i];
        int w = rnd(&s) % 100, a = 0;
        while (a < NARCH - 1 && w >= ARCH_W[a]) w -= ARCH_W[a++];
        const uint8_t *cl = ARCH[a].cars;
        int n = 0;
        while (n < 12 && cl[n] != 0xff) n++;
        p->arch = a; p->car = n ? cl[rnd(&s) % n] : rnd(&s) % 20; p->seed = rnd(&s);
        if (i < NNAMES) snprintf(p->name, sizeof p->name, "%s", NAMES[i]);
        else {                                                    // a street handle of two syllables, not taken yet
            static const char *SY[] = {"Ka", "Ze", "Ri", "No", "To", "Mi", "Ra", "Vo", "Xi", "Lu", "Ba", "De", "Jo", "Ky", "Sa",
                                       "Re", "Zu", "Ta", "Ni", "Go", "Ma", "Ko", "Su", "Ve", "Da", "Ro", "Ji", "Fe"};
            static const char *EN[] = {"", "x", "n", "k", "z", "r", "o", "a"};
            for (int dup = 1; dup;) {
                char lo[3]; const char *s2 = SY[rnd(&s) % 28];
                lo[0] = (char)(s2[0] | 0x20); lo[1] = s2[1]; lo[2] = 0;
                snprintf(p->name, sizeof p->name, "%s%s%s", SY[rnd(&s) % 28], lo, EN[rnd(&s) % 8]);
                dup = 0;
                for (int j = 0; j < i; j++) dup |= !strcmp(pool[j].name, p->name);
            }
        }
    }
    for (int k = 0; k < NSYN; k++) syn[k] = guest_alloc(0x408);
    ready = 1;
}

static uint32_t find_preset(Ctx *c, uint32_t h) {
    for (uint32_t p = ld(c, 0x748844, 4); p && p != 0x748844; p = ld(c, p, 4))
        if (ghash(c, p + 0x28) == h) return p;
    return 0;
}
// Our preset record k, linked at the front of the game's preset list (0x4b2640 finds presets by name) if it is not there.
static void link(Ctx *c, uint32_t r, const char *name) {
    snprintf(G(r + 0x28), 32, "%s", name);
    if (find_preset(c, hash(name)) == r) return;
    uint32_t head = 0x748844, first = ld(c, head, 4);
    st(c, r, first, 4); st(c, r + 4, head, 4); st(c, first + 4, r, 4); st(c, head, r, 4);
}
// A persona not yet in this race, from index i on.
static Persona *fresh(int i) {
    for (int tries = 0; tries < POOL; tries++, i = (i + 1) % POOL) {
        int dup = 0;
        for (uint32_t u = 0; u < nused && u < NSYN; u++) dup |= used[u] == (uint32_t)i;
        if (!dup) break;
    }
    used[nused++ % NSYN] = i;
    return &pool[i];
}

// A random part of a slot for this car (or shared), unlock level <= lvl, name in the list; 0 = none fits.
static const Part *pick(uint32_t *s, int car, int slot, int lvl, const char *list, int stock) {
    Ctx *c = g_ctx;
    const Part *cand[256]; int n = 0;
    for (int k = 0; k < nparts && n < 256; k++) {
        const Part *p = &parts[k];
        if (p->slot != slot || p->lvl > lvl || (!stock && p->lvl == 0)) continue;
        if (slot != 0x1f && slot != 0x11 && slot != 0x3a && slot != 0x73 && slot != 0x74 && p->car != carhash[car]) continue;
        if (!prefixed(G(p->name), list)) continue;
        cand[n++] = p;
    }
    return n ? cand[rnd(s) % n] : NULL;
}
static const Part *named(int car, int slot, const char *name) {
    Ctx *c = g_ctx;
    for (int k = 0; k < nparts; k++)
        if (parts[k].slot == slot && parts[k].car == carhash[car] && !strcmp(G(parts[k].name), name)) return &parts[k];
    return NULL;
}
// The paint of a family nearest a colour; a little spread between the three nearest so two rivals rarely match.
static const Part *paint(uint32_t *s, uint32_t rgb, uint32_t kinds) {
    const Part *best[3] = {0}; int d[3] = {1 << 30, 1 << 30, 1 << 30};
    int r = rgb >> 16 & 255, g = rgb >> 8 & 255, b = rgb & 255;
    for (int k = 0; k < nparts; k++) {
        const Part *p = &parts[k];
        if (p->slot != 0x1e || !(kinds >> p->kind & 1)) continue;
        int dr = p->rgb[0] - r, dg = p->rgb[1] - g, db = p->rgb[2] - b, e = 2 * dr * dr + 4 * dg * dg + 3 * db * db;
        for (int j = 0; j < 3; j++)
            if (e < d[j]) { for (int m = 2; m > j; m--) { d[m] = d[m - 1]; best[m] = best[m - 1]; } d[j] = e; best[j] = p; break; }
    }
    int j = rnd(s) % 3;
    return best[j] ? best[j] : best[0];
}

static void set(Ctx *c, uint32_t rec, int slot, const Part *p) { if (p) { st(c, rec + 0x48 + 8 * slot, slot, 4); st(c, rec + 0x4c + 8 * slot, p->key, 4); } }

// The build of persona p at tier t (1..3) into preset record rec.
static void build(Ctx *c, uint32_t rec, const Persona *pe, int t) {
    const Arch *a = &ARCH[pe->arch];
    int car = pe->car, lv = t == 1 ? 1 : t == 2 ? 2 : 4;
    uint32_t s = pe->seed ^ (uint32_t)t * 0x9e3779b9u;           // the same build each time it meets you at this tier
    const char *cn = CARS[car];
    char base[32]; snprintf(base, sizeof base, "%s_BASE", car == 5 ? "206" : cn);
    uint32_t b = find_preset(c, hash(base));
    memset(G(rec + 8), 0, 0x20);
    memset(G(rec + 0x48), 0, 0x408 - 0x48);
    snprintf(G(rec + 8), 32, "%s", cn);
    if (b) memcpy(G(rec + 0x48), G(b + 0x48), 0x408 - 0x48);
    #define P(x) ((x) * t / 3)
    int wide = t == 3 && roll(&s, a->wide);
    if (wide) set(c, rec, 6, pick(&s, car, 6, 4, "", 0));
    else if (roll(&s, P(a->kit) + (t > 1 ? 15 : 0))) {           // one kit: front, rear and skirts of the same name
        const Part *k = pick(&s, car, 1, lv, "", 0);
        if (k) { set(c, rec, 1, k); set(c, rec, 2, named(car, 2, G(k->name))); set(c, rec, 0xa, named(car, 0xa, G(k->name))); }
    }
    if (roll(&s, P(a->hood))) set(c, rec, 7, pick(&s, car, 7, lv, "", 0));
    if (roll(&s, P(a->scoop))) set(c, rec, 8, pick(&s, car, 8, lv, "", 0));
    if (roll(&s, P(a->wing) + 10)) { const Part *w = pick(&s, car, 0xb, lv, a->wings, 0); set(c, rec, 0xb, w ? w : pick(&s, car, 0xb, lv, "", 0)); }
    if (roll(&s, P(a->lights))) { set(c, rec, 0xd, pick(&s, car, 0xd, 4, "", 0)); set(c, rec, 0xe, pick(&s, car, 0xe, 4, "", 0)); }
    int exh = roll(&s, P(a->exhaust) + 10);
    if (exh) set(c, rec, 0xf, pick(&s, car, 0xf, lv, "", 0));
    int brk = t > 1 || pe->arch == TRACK;
    if (brk) set(c, rec, 0x10, pick(&s, car, 0x10, t, "", 0));
    // Rims: the archetype's brands; bigger with the tier.
    const Part *rim = pick(&s, car, 0x11, lv, a->rims, 0);
    if (!rim) rim = pick(&s, car, 0x11, lv, "", 0);
    if (pe->arch == SLEEPER && t == 1) rim = NULL;
    set(c, rec, 0x11, rim);
    // Paint: body from the archetype's colours; spoiler in body colour; rims, calipers, tips in the archetype's.
    int np = 0; while (np < 8 && a->paint[np]) np++;
    uint32_t body = a->paint[rnd(&s) % np], accent = a->paint[rnd(&s) % np];
    if (accent == body) accent = a->paint[(rnd(&s) + 1) % np];
    int lum = (int)(body >> 16 & 255) * 3 + (int)(body >> 8 & 255) * 6 + (int)(body & 255);
    uint32_t neutral = lum > 1500 ? 0x141414 : 0xf0f0f0;
    uint32_t fam = pe->arch == SHOW || pe->arch == VIP ? 1u << K_PEARL | 1u << K_METAL | 1u << K_CUSTOM
                 : pe->arch == SLEEPER ? 1u << K_METAL | 1u << K_GLOSS : 1u << K_GLOSS | 1u << K_METAL | (t == 3 ? 1u << K_PEARL : 0);
    const Part *bp = paint(&s, body, fam);
    set(c, rec, 0x1e, bp); set(c, rec, 0x26, bp);
    if (brk) set(c, rec, 0x27, paint(&s, roll(&s, 60) ? 0xc01010 : roll(&s, 50) ? 0xf0c000 : accent, 1u << K_CALIPERS));
    if (exh) set(c, rec, 0x28, paint(&s, 0x808080, 1u << K_MUFFLERS));
    if (rim) set(c, rec, 0x29, paint(&s, a->rimcol[rnd(&s) % 3], 1u << K_RIMS));
    // Vinyls: up to the archetype's layers (1 at tier 1); colours from the accent and a neutral against the body.
    int layers = 0;
    if (a->vinyl && roll(&s, P(a->vinyl) + 10)) layers = 1 + (int)(rnd(&s) % (a->layers < t ? a->layers : t));
    for (int l = 0; l < layers; l++) {
        const Part *v = pick(&s, car, 0x1f, l ? 3 : lv, a->vinyls, 0);
        if (!v) continue;
        set(c, rec, 0x1f + l, v);
        for (int j = 0; j < 4; j++) set(c, rec, 0x2a + 4 * l + j, paint(&s, (j + l) & 1 ? neutral : accent, 1u << K_VINYL));
    }
    // Sponsor decals: the same brands on both doors, one on each window; layouts from the car (wide ones with a widebody).
    int nd = P(a->decals) + (a->decals && t == 1);
    if (nd) {
        const char *rect[7] = {"HOOD RECT MEDIUM", "FRONT WINDOW RECT MEDIUM", "REAR WINDOW RECT MEDIUM", "L DOOR RECT MEDIUM",
                               "R DOOR RECT MEDIUM", "L PANEL RECT MEDIUM", "R PANEL RECT MEDIUM"};
        for (int k = 1; k < 7; k++) set(c, rec, 0x13 + k, named(car, 0x13 + k, rect[k]));
        if (wide) {
            const char *w[4] = {"WIDE2_DECAL_LEFT_DOOR_RECT_MEDIUM", "WIDE2_DECAL_RIGHT_DOOR_RECT_MEDIUM",
                                "WIDE2_DECAL_LEFT_QUARTER_RECT_MEDIUM", "WIDE2_DECAL_RIGHT_QUARTER_RECT_MEDIUM"};
            for (int k = 0; k < 4; k++) set(c, rec, 0x1a + k, named(car, 0x1a + k, w[k]));
        }
        set(c, rec, 0x43, pick(&s, car, 0x3a, 4, a->brands, 1));
        set(c, rec, 0x4b, pick(&s, car, 0x3a, 4, a->brands, 1));
        for (int k = 0; k < nd && k < 4; k++) {
            const Part *d = pick(&s, car, 0x3a, 4, a->brands, 1);
            set(c, rec, 0x53 + k, d); set(c, rec, 0x5b + k, d);
        }
    }
    // Glass and underglow.
    const char *tints[3] = {"LIGHT TINT BLACK", "MEDIUM TINT BLACK", "DARK TINT BLACK"};
    if (pe->arch != STREET || roll(&s, 70)) set(c, rec, 0x73, pick(&s, car, 0x73, 4, tints[a->tint < t ? a->tint : t - 1], 0));
    if (t > 1 && roll(&s, a->neon)) {
        const Part *best = NULL; int bd = 1 << 30;
        int ar = accent >> 16 & 255, ag = accent >> 8 & 255, ab = accent & 255;
        for (int k = 0; k < nparts; k++) {
            const Part *p = &parts[k];
            if (p->slot != 0x74 || !p->lvl) continue;
            const char *nm = G(p->name);
            if ((pe->arch != SHOW && pe->arch != BOSO) && strlen(nm) > 4 && strcmp(nm + strlen(nm) - 4, "Neon")) continue;
            int e = 0, m = 1 + (p->rgb[0] > p->rgb[1] ? p->rgb[0] : p->rgb[1]); m = m > p->rgb[2] ? m : p->rgb[2] + 1;
            e += (p->rgb[0] * 255 / m - ar) * (p->rgb[0] * 255 / m - ar) + (p->rgb[1] * 255 / m - ag) * (p->rgb[1] * 255 / m - ag)
               + (p->rgb[2] * 255 / m - ab) * (p->rgb[2] * 255 / m - ab) + (int)(rnd(&s) % 4000);
            if (e < bd) { bd = e; best = p; }
        }
        set(c, rec, 0x74, best);
    }
    #undef P
}

// Its driving: +-1 on one category of each group (power: engine 2, ECU 5, turbo 3; grip: suspension 1, tires 7,
// brakes 8; launch: transmission 6, nitrous 4, weight 0; index order from the tuner screens, 0x50a070).
static void personality(Ctx *c, uint32_t ride, const Persona *pe) {
    static const uint8_t grp[3][3] = {{2, 5, 3}, {1, 7, 8}, {6, 4, 0}};
    const Arch *a = &ARCH[pe->arch];
    int d[3] = {a->power, a->grip, a->accel};
    for (int g = 0; g < 3; g++) {
        if (!d[g]) continue;
        uint32_t f = ride + 8 + 4 * grp[g][(pe->seed >> (4 * g)) % 3];
        int v = (int)ld(c, f, 4) + d[g];
        st(c, f, v < 0 ? 0 : v > 3 ? 3 : v, 4);
    }
    c->mem[ride + 0x424] = 0xff;                                  // the rating is computed again (0x57f2b0)
}

// Builds persona pe into preset record rec, lets the game apply it to the ride (0x4b26f0 keeps DUMMY_SKIN/WHEEL) and
// matches the rating of tmp (the ride the game made, *r0 once 0x57f700 computed it) within 5.0; returns how far it stayed.
static float apply(Ctx *c, uint32_t ride, uint32_t tmp, uint32_t rec, const char *nm, const Persona *pe, int tier, float *r0) {
    build(c, rec, pe, tier);
    link(c, rec, nm);
    uint32_t one = ride, m[6] = {ride, tmp, 0, 0xffffffffu, 0, 0x40a00000u};
    c->r[EAX] = hash(nm);
    call_guest_cdecl(c, 0x4b26f0, 1, &one);
    call_guest(c, 0x57f700, 6, m);
    float r1; memcpy(r0, G(tmp + 0x428), 4); memcpy(&r1, G(ride + 0x428), 4);
    return r1 > *r0 ? r1 - *r0 : *r0 - r1;
}

// Personalities (RN_RIVALAI=0: as shipped; docs/openworld/re_rival_personality.md). The game picks each opponent's skill level by
// difficulty (0x4b4590: easy 0..2, medium 3..5, hard 6..8), so each band gets a clumsy and an aggressive level and its strength stays.
// Level 0 stays as shipped: an AI without a level reads record 0. The career keeps every shipped value.
// Clumsy: accepts 35 % of Pass/Avoid targets (+0x0c, 0x4627ac), reads the route speed 6 % lower (+0x14, 0x44c72b) and twice as far off
// its spot (+0x50, 0x44c667). Aggressive: route speed 4 % higher, and Block ceiling 400 (style 2, 0x44dbd0): it beats Avoid and Pass.
enum { NORMAL, CLUMSY, AGGRESSIVE };
static const uint8_t PERSONA[10] = {NORMAL, AGGRESSIVE, CLUMSY, AGGRESSIVE, NORMAL, CLUMSY, AGGRESSIVE, NORMAL, CLUMSY, AGGRESSIVE};
static int rivalai(void) { const char *e = getenv("RN_RIVALAI"); return !(e && e[0] == '0'); }
static int rival_style(uint32_t skill, uint32_t style) { return rivalai() && skill <= 9 && PERSONA[skill] == AGGRESSIVE ? 2 : (int)style; }

// Records 0x779ff8 + 0x54 * level (0x462070 copies them from GLOBALB): shipped, then the personas of this race.
static void rival_tables(Ctx *c, int personas) {
    static uint8_t shipped[10 * 0x54];
    static int saved;
    if (!saved++) memcpy(shipped, G(0x779ff8), sizeof shipped);
    memcpy(G(0x779ff8), shipped, sizeof shipped);
    if (!personas) return;
    char b[256];
    int n = 0;
    for (int lv = 1; lv <= 9; lv++) {
        uint32_t r = 0x779ff8 + 0x54 * lv;
        float accept = ldf(c, r + 0x0c), speed = ldf(c, r + 0x14);
        if (PERSONA[lv] == CLUMSY) accept = 0.35f, speed *= 0.94f, c->mem[r + 0x50] *= 2;
        if (PERSONA[lv] == AGGRESSIVE) speed *= 1.04f;
        memcpy(G(r + 0x0c), &accept, 4), memcpy(G(r + 0x14), &speed, 4);
        n += snprintf(b + n, sizeof b - n, " L%d %.2f %.3f %u", lv, ldf(c, r + 0x0c), ldf(c, r + 0x14), c->mem[r + 0x50]);
    }
    if (getenv("RN_RIVALLOG") || getenv("RN_FREELOG")) rn_log("rivalai accept speed look:%s", b);
}

// 0x5809c0(id, 2, ride, record, skill, style, index) with esi = the ride slot: stdcall, 7 arguments.
static uint32_t rival_ride(Ctx *c) {
    uint32_t a[7];
    for (int k = 0; k < 7; k++) a[k] = ARG(k);
    if (a[6] <= 1) rn_player_car(c), rival_tables(c, rivalai() && (rn_free_now || !c->mem[0x78a33c]));
    if (rn_free_now) {                                           // host/free.c: free mode's career rivals
        uint32_t e = free_rival(c, a);                           // 0x5809c0 returns the entrant; free_rival picks the level at +0x735
        c->mem[e + 0x736] = (uint8_t)rival_style(c->mem[e + 0x735], c->mem[e + 0x736]);
        if (getenv("RN_FREELOG")) rn_log("rivalai %s level %d style %d", G(e + 0x73c), (int8_t)c->mem[e + 0x735], (int8_t)c->mem[e + 0x736]);
        return e;
    }
    if (!on) { const char *e = getenv("RN_RIVALS"); on = e && e[0] == '0' ? -1 : 1; }
    if (on > 0 && !c->mem[0x78a33c]) {
        if (!ready) catalog(c);
        uint32_t ride = a[2], k = a[6] % NSYN, rec = syn[k];
        if (a[6] <= 1) nused = 0;                                  // the first opponent of a race
        uint32_t tmp = guest_alloc(RIDE_SIZE);
        memcpy(G(tmp), G(ride), RIDE_SIZE);
        // A persona from the game's random stream; its tier from the tuning the game gave this rival.
        int lv = 0; for (int i = 0; i < 9; i++) lv += ld(c, ride + 8 + 4 * i, 4);
        int tier = lv >= 18 ? 3 : lv >= 7 ? 2 : 1;
        uint32_t s = ld(c, 0x6f227c, 4) ^ (a[6] * 0x85ebca6bu);
        Persona *pick_p = fresh(rnd(&s) % POOL);
        // The persona's car must reach the rating the game chose (0x57f700 can only move levels 0..3): up to 12 personas,
        // the nearest kept.
        char nm[32]; snprintf(nm, sizeof nm, "RN_RIVAL_%u", k);
        float r0 = 0;
        Persona *best = pick_p; float bd = 1e9f;
        for (int tries = 0; tries < 12; tries++) {
            if (tries) { nused--; pick_p = fresh((int)(pick_p - pool + 1 + rnd(&s) % 37) % POOL); }   // one slot per rival
            float d = apply(c, ride, tmp, rec, nm, pick_p, tier, &r0);
            if (d < bd) { bd = d; best = pick_p; }
            if (d <= 12.f) break;
        }
        if (best != pick_p) { apply(c, ride, tmp, rec, nm, pick_p = best, tier, &r0); used[(nused - 1) % NSYN] = (uint32_t)(best - pool); }
        personality(c, ride, pick_p);
        if (getenv("RN_RIVALLOG")) {
            float r1; memcpy(&r1, G(ride + 0x428), 4);
            rn_log("rival %u: %s %s %s tier %d rating %.1f -> %.1f", a[6], pick_p->name, CARS[pick_p->car], ARCH[pick_p->arch].name,
                   tier, r0, r1);
            for (int sl = 0; sl < 0x78; sl++) {
                uint32_t key = ld(c, rec + 0x4c + 8 * sl, 4);
                for (int q = 0; key && q < nparts; q++)
                    if (parts[q].key == key && (parts[q].slot == sl || (sl >= 0x26 && sl <= 0x39 && parts[q].slot == 0x1e) ||
                        (sl >= 0x1f && sl <= 0x22 && parts[q].slot == 0x1f) || (sl >= 0x3b && sl <= 0x72 && parts[q].slot == 0x3a))) {
                        if (sl != 3 && sl != 4 && sl != 5 && sl != 0 && sl != 9 && sl != 0x12 && sl != 0x77) rn_log("  %02x %s", sl, G(parts[q].name));
                        break;
                    }
            }
        }
        guest_free(tmp);
        a[5] = rival_style(a[4], a[5]);
    }
    return call_guest(c, 0x5809c0, 7, a);
}

// RN_AILOG=1: test-only race log (tools/ailog.py sums it up). Every 60 frames, each racer: name, kind, route metres car+0x814, speed car+0x3d0,
// rank (record +0xa), mean |slip angle| in degrees; at once, each change of a racer's action type [[drv+0x3f8]+0x1f8] and each nitro start (CarState car+0x40, +0x3bc, 0x4654f0).
static void ai_log(Ctx *c) {
    static int on = -1;
    static struct { uint32_t car, act, nos, n; float slip; } st_[16];
    if (on < 0) on = getenv("RN_AILOG") != NULL;
    if (!on || ld(c, 0x77a920, 4) != 6) return;
    static uint32_t draft;                // racer-seconds in the game's slipstream: car+0x47c (0x426450) above 0.1
    uint32_t h = ld(c, 0x7361f8, 4), sec = rn_telem.presents % 60 == 0;
    char b[640];
    int n = 0, i = 0;
    for (uint32_t r = h ? ld(c, h, 4) : 0, k = 0; r && r != h && k < 200 && i < 16; r = ld(c, r, 4), k++) {
        uint32_t e = ld(c, r + 0x14, 4), kind = e ? ld(c, e + 4, 4) : 0, v = ld(c, r + 0x2c, 4), rec = ld(c, r + 0x1c, 4);
        if (kind != 1 && kind != 2) continue;
        uint32_t a = v ? ld(c, v + 0x3f8, 4) : 0, type = a ? ld(c, a + 0x1f8, 4) : 99, nos = ld(c, r + 0x3fc, 4);
        if (st_[i].car == r && st_[i].act != type) rn_log("AIEV %u %s act %u", rn_telem.presents, G(e + 0x73c), type);
        if (st_[i].car == r && st_[i].nos != nos && nos && nos != 0x7fffffff) rn_log("AIEV %u %s nos", rn_telem.presents, G(e + 0x73c));
        st_[i].car = r, st_[i].act = type, st_[i].nos = nos;
        draft += sec && ldf(c, r + 0x47c) > 0.1f;
        if (rn_telem.presents % 6 == 0 && ldf(c, r + 0x3d0) > 10) {   // slip angle: 0x464ed0 (esi = CarState, radians on the FPU), as 0x479350 reads it
            uint32_t esi = c->r[ESI], ft = c->ftop;
            c->r[ESI] = r + 0x40, call_guest(c, 0x464ed0, 0, NULL), c->r[ESI] = esi;
            double a2 = c->st[c->ftop];
            fpop(c), c->ftop = ft;
            st_[i].slip += (float)fabs(a2) * 57.296f, st_[i].n++;
        }
        if (sec && n < 560) {
            n += snprintf(b + n, sizeof b - n, " %s:%u:%.0f:%.1f:%d:%.1f", kind == 1 ? "ME" : G(e + 0x73c), kind, ldf(c, r + 0x814), ldf(c, r + 0x3d0), rec ? c->mem[rec + 0xa] : -1, st_[i].n ? st_[i].slip / st_[i].n : 0);
            st_[i].slip = 0, st_[i].n = 0;
        }
        i++;
    }
    if (n) rn_log("AILOG %u draft %u%s", rn_telem.presents, draft, b);
}

// Handling (RN_HANDLING=0 / ?handling=0: as shipped; docs/re/physics.md). The OWNER's "rigid": outside drift events 0x4774a0 gives the rear wheels extra grip as the
// slip angle grows (0x4773f0: min(0.35, 2.5 * v/30 * slip), V from all 35 cars' physics +0x284), so at 30 m/s the cap holds from 4 degrees on and the tail will not step out.
// Cap 0x6ffdd4 (.data, its only reader 0x477473..) goes to HANDLING_REAR, for every car. Yaw damping 0x479350 runs in drift events only: not touched.
#define HANDLING_REAR 0.18f
static void handling_data(Ctx *c) {
    static int done;
    if (done++) return;
    const char *e = getenv("RN_HANDLING");
    if (e && e[0] == '0') return;
    float rear = HANDLING_REAR;
    memcpy(G(0x6ffdd4), &rear, 4);
}

// Traffic that reacts (RN_TRAFYIELD=0 / ?trafyield=0: as shipped; docs/openworld/re_traffic_rivals.md). Traffic only ever looks ahead: its
// finder 0x453920 takes the nearest car ahead in its lane, so a player closing from behind is never seen and hits the car square on.
// Now a traffic car with the player in its neighbour list (0x57a910), same lane, 0.6..2.5 s from impact, takes a free neighbour lane
// the way its own avoid update does (0x453c60: 0x453ba0 says if the lane is clear, then lane ctx+0x394, route state ctx+0x398 = 1) and
// sounds its horn (0x429100, thiscall on the car). Outside the career, as the personas; each car once in YIELD_WAIT frames.
#define YIELD_WAIT 240
void traffic_tick(Ctx *c) {
    static int off = -1, n_yield;
    static uint32_t act, seed = 0x51ed2701;
    static struct { uint32_t car, frame; } seen[32];
    ai_log(c);
    handling_data(c);
    if (off < 0) { const char *e = getenv("RN_TRAFYIELD"); off = e && e[0] == '0'; }
    if (off || rn_telem.presents % 6 || ld(c, 0x77a920, 4) != 6 || c->mem[0x78a33c]) return;
    uint32_t h = ld(c, 0x7361f8, 4), me = 0;
    for (uint32_t r = h ? ld(c, h, 4) : 0, k = 0; r && r != h && k < 200 && !me; r = ld(c, r, 4), k++) {
        uint32_t e = ld(c, r + 0x14, 4);
        if (e && ld(c, e + 4, 4) == 1) me = r;
    }
    if (!me) return;
    if (!act) {                                // the action 0x453ba0 reads: +0x204 the gap that counts as taken, +0x208 the scan range
        float taken = ldf(c, 0x6b76d8), range = ldf(c, 0x6b76e0);
        act = guest_alloc(0x210), memcpy(G(act + 0x204), &taken, 4), memcpy(G(act + 0x208), &range, 4);
    }
    for (uint32_t r = ld(c, h, 4), k = 0; r != h && k < 200; r = ld(c, r, 4), k++) {
        uint32_t e = ld(c, r + 0x14, 4), v = ld(c, r + 0x2c, 4);
        if (!e || ld(c, e + 4, 4) != 3 || !v || c->mem[v + 0x4d1]) continue;
        uint32_t ctx = v + 0x2c, a = ld(c, v + 0x3f8, 4), n = ld(c, ctx + 4, 4), lane = ld(c, ctx + 0x394, 4);
        int own = (int8_t)c->mem[ctx + 0x388];
        if (!a || ld(c, a + 0x1f8, 4) == 3 || ld(c, a + 0x1f8, 4) == 0x12) continue;   // already avoiding, or at a junction
        if (n > 16 || own < 0 || (uint32_t)own >= n || lane < 11 || lane > 16) continue;
        uint32_t o = ctx + 8 + 0x38 * own, p = 0;
        for (uint32_t i = 0; i < n && !p; i++) if (ld(c, ctx + 8 + 0x38 * i + 0x34, 4) == me) p = ctx + 8 + 0x38 * i;
        if (!p) continue;
        // Entry (0x44f470, 0x453c60): +4 speed relative to this car, +8/+0xc half width/length, +0x10 along the path, +0x18.. offset from each lane.
        float gap = ldf(c, o + 0x10) - ldf(c, p + 0x10) - ldf(c, o + 0xc) - ldf(c, p + 0xc), closing = ldf(c, p + 4);
        float side = ldf(c, p + 0x18 + 4 * (lane - 11)) - ldf(c, o + 0x18 + 4 * (lane - 11));
        if (gap <= 0 || closing < 5 || gap / closing < 0.6f || gap / closing > 2.5f) continue;
        if (fabsf(side) > 0.5f + ldf(c, o + 8) + ldf(c, p + 8)) continue;
        int s = 0;
        while (s < 31 && seen[s].car && seen[s].car != r) s++;
        if (seen[s].car == r && rn_telem.presents < seen[s].frame + YIELD_WAIT) continue;
        seen[s].car = r, seen[s].frame = rn_telem.presents;
        uint32_t esi = c->r[ESI], to = 0, dir = rnd(&seed) & 2;   // a coin for the first side
        for (int t = 0; t < 2 && !to; t++, dir ^= 2) {
            uint32_t want = lane + dir - 1, one = act;
            c->r[EAX] = lane, c->r[ECX] = want, c->r[ESI] = ctx;
            if (call_guest(c, 0x453ba0, 1, &one) & 0xff) to = want;
        }
        c->r[ESI] = esi;
        if (!to) continue;
        st(c, ctx + 0x394, to, 4), st(c, ctx + 0x398, 1, 4), st(c, ctx + 0x39c, 0, 4), st(c, ctx + 0x3a0, 0, 4), c->mem[ctx + 0x3a4] = 0;
        uint32_t honk[6] = {0x3e800000, 0x3e000000, 0x3e800000, 0, 1, 0};              // 0.25, 0.125, 0.25 s, horn +0x83f
        c->r[ECX] = r, call_guest(c, 0x429100, 6, honk);
        if (getenv("RN_FREELOG") || getenv("RN_RIVALLOG"))
            rn_log("trafyield #%d: lane %u -> %u, gap %.1f m, closing %.1f m/s, frame %u", ++n_yield, lane, to, gap, closing, rn_telem.presents);
    }
}

// RN_CAR=<CAR>[:tier[:n]] (?car= on the web): the player's car in every race is the n-th (default 0) persona of that car model
// (CARS above) built at tier 1..3 (default 2; 3 = kits, wings, vinyls), by the same build/apply as a rival, on the player's ride
// (entrant table [0x78a418], 0x750 each, +4 kind 1, +0x10 RideInfo) before the race start builds the cars. The look matrix
// (build/carpack/matrix.sh) needs other cars than the profile's. Called by rival_ride for each race's first opponent (0x4b4321, inside
// 0x4b4040): the player is registered by then and the skin composite 0x5a8a50 of the cars has not run (a call at the race start, 0x422a86,
// was too late: the player's body drew black in 6 of 9 cells).
void rn_player_car(Ctx *c) {
    const char *e = getenv("RN_CAR");
    if (!e) return;
    char nm[16] = {0}; int tier = 2, n = 0;
    sscanf(e, "%15[^:]:%d:%d", nm, &tier, &n);
    int car = -1;
    for (int k = 0; k < 20; k++) if (!strcmp(nm, CARS[k])) car = k;
    if (car < 0 || tier < 1 || tier > 3) { rn_log("RN_CAR: \"%s\" is not CAR[:tier 1..3[:n]]", e); return; }
    uint32_t cnt = ld(c, 0x78a41c, 4), t = ld(c, 0x78a418, 4);
    for (uint32_t i = 0; i < cnt; i++) {
        if (ld(c, t + 0x750 * i + 4, 4) != 1) continue;
        if (!ready) catalog(c);
        if (getenv("RN_CARLIST")) {   // which persona n of a model is dark or light: the paint's own RGB of the first 6 personas of every model
            uint32_t ride = t + 0x750 * i + 0x10, scratch = guest_alloc(RIDE_SIZE), tmp = guest_alloc(RIDE_SIZE);
            for (int k = 0; k < 20; k++) for (int j = 0, q = 0; j < POOL && q < 6; j++) {
                if (pool[j].car != k) continue;
                memcpy(G(scratch), G(ride), RIDE_SIZE); memcpy(G(tmp), G(ride), RIDE_SIZE);
                float r0; apply(c, scratch, tmp, syn[0], "RN_PLAYER", &pool[j], 3, &r0);
                for (int sl = 0; sl < 0x78; sl++) {
                    uint32_t key = ld(c, syn[0] + 0x4c + 8 * sl, 4);
                    for (int u = 0; key && u < nparts; u++)
                        if (parts[u].key == key && parts[u].slot == sl && parts[u].kind >= K_GLOSS && parts[u].kind <= K_CUSTOM)
                            rn_log("RN_CARLIST %s n=%d %s %s rgb %u,%u,%u lum %.2f", CARS[k], q, ARCH[pool[j].arch].name, G(parts[u].name), parts[u].rgb[0], parts[u].rgb[1], parts[u].rgb[2],
                                   (0.2126 * parts[u].rgb[0] + 0.7152 * parts[u].rgb[1] + 0.0722 * parts[u].rgb[2]) / 255);
                }
                q++;
            }
            guest_free(scratch); guest_free(tmp);
        }
        const Persona *pe = NULL;
        for (int j = 0, q = 0; j < POOL && !pe; j++) if (pool[j].car == car && q++ == n) pe = &pool[j];
        if (!pe) { rn_log("RN_CAR: %s has no persona %d", nm, n); return; }
        uint32_t ride = t + 0x750 * i + 0x10, tmp = guest_alloc(RIDE_SIZE);
        memcpy(G(tmp), G(ride), RIDE_SIZE);
        float r0;
        apply(c, ride, tmp, syn[0], "RN_PLAYER", pe, tier, &r0);
        guest_free(tmp);
        rn_log("RN_CAR: player is %s tier %d, persona %s (%s)", nm, tier, pe->name, ARCH[pe->arch].name);
        return;
    }
}

// BRIDGE: every racer at the player's car detail (OWNER 2026-10-27: the rivals as well made as the Supra). 0x56dc30 draws
// a car with model BODY_A..D by its size on screen, s = 3 * [view+0xc] / (distance - 3) (0x545180): s >= 120 = A,
// >= 45 = B, >= 20 = C, else D (table 0x6b5dec, from the minimum LOD args 10 / 11 up), and ORs flag 0x800 into the draw
// when LOD >= 1 or the car type's usage ([0x734588] + 0xc90 * [[model+4]] + 0xc54) is 2, traffic (0x56e15d). The player's
// car is always near, so A; a rival 20-40 m ahead got B or C with the traffic flag. Two debug words of the game force the
// body and parts LOD, 0x6f1b30 / 0x6f1b34 (-1 = by size; one reader each, 0x56e12d / 0x56e13d, no writer: REA ev_cd471810,
// Hopper build/hopper/viewscale.txt). PATCH 0x57119a sends the race list's draw (0x571050, list [0x7361f8]) here (cave
// 0x43a7e4: jmp [SCREEN_ADDR+0x64]); a car that is not traffic is drawn with both at 0, then they go back to -1.
// Traffic keeps the game's LOD. RN_CARLOD=0: the original.
static uint32_t car_draw(Ctx *c) {
    static int lod = -1;
    if (lod < 0) { const char *e = getenv("RN_CARLOD"); lod = !(e && e[0] == '0'); }
    uint32_t a[12];
    for (int k = 0; k < 12; k++) a[k] = ARG(k);
    uint32_t m = a[0], t = m ? ld(c, m + 4, 4) : 0, tab = ld(c, 0x734588, 4);
    int racer = lod && t && tab && ld(c, tab + 0xc90 * ld(c, t, 4) + 0xc54, 4) != 2;
    if (getenv("RN_CARLODLOG")) {   // each model once
        static uint32_t seen[64]; static int n;
        int k = 0;
        while (k < n && seen[k] != m) k++;
        if (k == n && n < 64) seen[n++] = m, rn_log("CARLOD model %08x type %u usage %u racer %d", m, t ? ld(c, t, 4) : 0,
                                                    t && tab ? ld(c, tab + 0xc90 * ld(c, t, 4) + 0xc54, 4) : 0, racer);
    }
    if (racer) { st(c, 0x6f1b30, 0, 4); st(c, 0x6f1b34, 0, 4); }
    uint32_t r = call_guest(c, 0x56dc30, 12, a);
    if (racer) { st(c, 0x6f1b30, 0xffffffffu, 4); st(c, 0x6f1b34, 0xffffffffu, 4); }
    return r;
}

const Api rivals_apis[] = {{"rn", "rival_ride", 7, rival_ride}, {"rn", "car_draw", 12, car_draw}};
const int rivals_api_count = 2;
