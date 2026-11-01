// AI telemetry for the OWNER's F10 (RN_AILOG, on by default in the page; OWNER 2026-10-31: "do not diagnose blind"). Log lines only,
// nothing is written to the game. Each line starts with a tag the session JSON can be grepped for:
//   AIP  once a second: the player (speed m/s, position, wheels on the ground, crash state car+0x38).
//   AIR  once a second, each rival (entrant kind 2): distance to the player (+ ahead / - behind along the player's heading), speed,
//        current action type/priority (AI obj +0x3f8: +0x1f8 / +0x1f4; 7 JustDrive, 0 Pass, 5 Block, 0xa GetUnstuck, 1 Avoid),
//        +0x1f0 (1 = speed from the route nodes, 0 = the action's own speed +0x1e4), speed scales racer+0x4b8 and car+0x404,
//        skill record +0x14 (record = car+0x1c), seconds stuck (< 2 m/s), GetUnstuck count, wall and car hits so far.
//   AIT  once a second, each traffic car (kind 3) within 80 m: distance (signed as above), lateral offset from the player's line,
//        speed, action type (3 = Avoid), parked (AI obj +0x4d1).
//   AIHIT at once, any car of the race list whose speed drops 4 m/s or more in one frame: who, speed before -> after, the nearest
//        other car and its distance; "wall" when no car is within 6 m.
// Offsets: race list [0x7361f8] (next +0, entrant +0x14, kind entrant+4, AI obj +0x2c, position +0x50, velocity +0x70, heading +0x90,
// speed +0x3d4, wheels +0x3cc), docs/re/race_ai.md, docs/re/traffic_react.md, host/rivals.c TRAFLOG.
#include <math.h>
#include <string.h>
#include "host.h"

#define AIT_MAX 64
static struct { uint32_t r; float sp; int wall, car, unst, stuck, lastact; } tr[AIT_MAX];

static int slot(uint32_t r) {
    int i = 0;
    while (i < AIT_MAX && tr[i].r && tr[i].r != r) i++;
    if (i == AIT_MAX) return -1;
    if (!tr[i].r) memset(&tr[i], 0, sizeof tr[i]), tr[i].r = r, tr[i].lastact = -1;
    return i;
}

void ai_tel(Ctx *c) {
    static int on = -1;
    static uint32_t race;
    if (on < 0) on = getenv("RN_AILOG") != NULL;
    if (!on) return;
    uint32_t h = ld(c, 0x7361f8, 4);
    if (ld(c, 0x77a920, 4) != 6 || !h || h >= GUEST_MEM - 0x1000) { race = 0; return; }
    if (h != race) memset(tr, 0, sizeof tr), race = h;
    uint32_t f = rn_telem.presents, me = 0;
    for (uint32_t r = ld(c, h, 4), k = 0; r && r != h && k < 200; r = ld(c, r, 4), k++) {
        uint32_t e = ld(c, r + 0x14, 4);
        if (e && e < GUEST_MEM - 0x800 && ld(c, e + 4, 4) == 1) { me = r; break; }
    }
    if (!me) return;
    float px = ldf(c, me + 0x50), py = ldf(c, me + 0x54), fx = ldf(c, me + 0x90), fy = ldf(c, me + 0x94);
    float fl = hypotf(fx, fy);
    if (fl > 0) fx /= fl, fy /= fl;
    int sec = f % 60 == 0;
    if (sec) rn_log("AIP f%u sp %.1f pos %.0f,%.0f,%.0f wheels %u crash %u", f, ldf(c, me + 0x3d4), px, py, ldf(c, me + 0x58),
                    ld(c, me + 0x3cc, 4), ld(c, me + 0x38, 4));
    for (uint32_t r = ld(c, h, 4), k = 0; r && r != h && k < 200; r = ld(c, r, 4), k++) {
        uint32_t e = ld(c, r + 0x14, 4);
        if (!e || e >= GUEST_MEM - 0x800) continue;
        uint32_t kind = ld(c, e + 4, 4), v = ld(c, r + 0x2c, 4);
        if (v >= GUEST_MEM - 0x800) v = 0;
        int i = slot(r);
        if (i < 0) continue;
        float sp = ldf(c, r + 0x3d4), x = ldf(c, r + 0x50), y = ldf(c, r + 0x54);
        float dx = x - px, dy = y - py, d = hypotf(dx, dy), along = dx * fx + dy * fy, lat = dx * fy - dy * fx;
        uint32_t a = v ? ld(c, v + 0x3f8, 4) : 0;
        if (a >= GUEST_MEM - 0x200) a = 0;
        int at = a ? (int)ld(c, a + 0x1f8, 4) : -1;
        if (at == 0xa && tr[i].lastact != 0xa) tr[i].unst++;
        tr[i].lastact = at;
        if (sp < 2.0f) tr[i].stuck++; else tr[i].stuck = 0;
        if (tr[i].sp - sp >= 4.0f && tr[i].sp > 5.0f) {   // an impact: who was nearest
            float nd = 1e9f;
            uint32_t nr = 0;
            for (uint32_t o = ld(c, h, 4), j = 0; o && o != h && j < 200; o = ld(c, o, 4), j++) {
                if (o == r) continue;
                float od = hypotf(ldf(c, o + 0x50) - x, ldf(c, o + 0x54) - y);
                if (od < nd) nd = od, nr = o;
            }
            uint32_t ne = nr ? ld(c, nr + 0x14, 4) : 0;
            int car = nd < 6.0f;
            if (car) tr[i].car++; else tr[i].wall++;
            rn_log("AIHIT f%u kind %u car %08x sp %.1f -> %.1f act %d %s (nearest kind %u at %.1f m) d %.0f", f, kind, r, tr[i].sp, sp, at,
                   car ? "car" : "wall", ne && ne < GUEST_MEM - 8 ? ld(c, ne + 4, 4) : 0, nd, d);
        }
        tr[i].sp = sp;
        if (!sec) continue;
        if (kind == 2) {
            uint32_t rec = ld(c, r + 0x1c, 4);
            rn_log("AIR f%u %s d %+.0f lat %+.0f sp %.1f act %d/%d route %d own %.1f s4b8 %.2f s404 %.2f rec14 %.2f stuck %.1f s unst %d hits wall %d car %d",
                   f, G(e + 0x73c), along >= 0 ? d : -d, lat, sp, at, a ? (int)ld(c, a + 0x1f4, 4) : -1, a ? c->mem[a + 0x1f0] : -1,
                   a ? ldf(c, a + 0x1e4) : 0.0f, v ? ldf(c, v + 0x4b8) : 0.0f, ldf(c, r + 0x404), rec && rec < GUEST_MEM - 0x20 ? ldf(c, rec + 0x14) : 0.0f,
                   tr[i].stuck / 60.0f, tr[i].unst, tr[i].wall, tr[i].car);
        } else if (kind == 3 && d < 80) {
            rn_log("AIT f%u car %08x d %+.0f lat %+.1f sp %.1f act %d parked %u hits wall %d car %d", f, r, along >= 0 ? d : -d, lat, sp, at,
                   v ? c->mem[v + 0x4d1] : 0, tr[i].wall, tr[i].car);
        }
    }
}
