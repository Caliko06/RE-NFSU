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
//        other car and its distance; "wall" when no car is within 6 m; its position (where the walls are).
// Offsets: race list [0x7361f8] (next +0, entrant +0x14, kind entrant+4, AI obj +0x2c, position +0x50, velocity +0x70, heading +0x90,
// speed +0x3d4, wheels +0x3cc), docs/re/race_ai.md, docs/re/traffic_react.md, host/rivals.c TRAFLOG.
#include <math.h>
#include <string.h>
#include "host.h"

#define AIT_MAX 64
static struct { uint32_t r; float sp, x, y; int wall, car, unst, stuck, lastact, jump, seen; } tr[AIT_MAX];

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
        if (tr[i].seen && (sp - tr[i].sp > 40.0f || tr[i].jump)) {   // not on a slot's first sample (sp 0 there, a car entering at speed is no jump)        // a speed jump and the 3 frames after it: is the car moving that fast, and which way
            tr[i].jump = sp - tr[i].sp > 40.0f ? 4 : tr[i].jump - 1;
            rn_log("AIJUMP f%u kind %u car %08x sp %.1f -> %.1f v %.1f %.1f %.1f pos %.1f %.1f %.1f moved %.1f act %d scale %.2f wheels %u mode %u spin %.0f %.0f nos %u/%.0f crash %u", f, kind, r, tr[i].sp, sp, ldf(c, r + 0x70), ldf(c, r + 0x74), ldf(c, r + 0x78),
                   x, y, ldf(c, r + 0x58), hypotf(x - tr[i].x, y - tr[i].y), at, ldf(c, r + 0x404), ld(c, r + 0x3cc, 4), ld(c, r + 0x28, 4), ldf(c, r + 0x2f0), ldf(c, r + 0x2f8), ld(c, r + 0x3fc, 4), ldf(c, r + 0x3f8), ld(c, r + 0x38, 4));
            // Mode 4 = BeltMover (ctor 0x463260, update 0x463f20): position = spline(s) + lateral, velocity = position difference / dt. s = (a t / 2 + b) t + s0.
            uint32_t m = ld(c, r + 0x34, 4), cp = ld(c, r + 0x30, 4);
            if (ld(c, r + 0x28, 4) == 4 && m && cp && m < GUEST_MEM - 0x48 && cp < GUEST_MEM - 0x1c0) {
                uint32_t lat = ld(c, m + 0x18, 4), sp14 = ld(c, m + 0x14, 4);
                char b[256];
                int n = c->mem[cp + 0x10], o = 0;
                for (int k = 0; k < n && k < 6 && o < 200; k++) o += snprintf(b + o, sizeof b - o, " %.0f,%.0f,%.0f", ldf(c, cp + 0x20 + 16 * k), ldf(c, cp + 0x24 + 16 * k), ldf(c, cp + 0x28 + 16 * k));
                if (!o) b[0] = 0;
                rn_log("AIBELT f%u car %08x t %.3f rate %.4f s0 %.3f b %.3f a %.3f lat %.2f keys %u n %d L %.1f pts%s", f, r, ldf(c, m + 0xc), ldf(c, m + 0x10), ldf(c, m + 0x1c), ldf(c, m + 0x20), ldf(c, m + 0x24),
                       lat && lat < GUEST_MEM - 4 ? ldf(c, lat) : 0, sp14 && sp14 < GUEST_MEM - 0x20 ? ld(c, sp14 + 0x1e, 2) : 0, n, ldf(c, cp + 0x1bc), b);
            }
        }
        tr[i].x = x, tr[i].y = y;
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
            rn_log("AIHIT f%u kind %u car %08x sp %.1f -> %.1f act %d %s (nearest kind %u at %.1f m) d %.0f at %.0f,%.0f,%.0f", f, kind, r, tr[i].sp, sp, at,
                   car ? "car" : "wall", ne && ne < GUEST_MEM - 8 ? ld(c, ne + 4, 4) : 0, nd, d, x, y, ldf(c, r + 0x58));
        }
        tr[i].sp = sp, tr[i].seen = 1;
        if (!sec) continue;
        if (kind == 2) {
            uint32_t rec = ld(c, r + 0x1c, 4);
            rn_log("AIR f%u %s d %+.0f lat %+.0f sp %.1f act %d/%d route %d own %.1f s4b8 %.2f s404 %.2f rec14 %.2f stuck %.1f s unst %d hits wall %d car %d",
                   f, G(e + 0x73c), along >= 0 ? d : -d, lat, sp, at, a ? (int)ld(c, a + 0x1f4, 4) : -1, a ? c->mem[a + 0x1f0] : -1,
                   a ? ldf(c, a + 0x1e4) : 0.0f, v ? ldf(c, v + 0x4b8) : 0.0f, ldf(c, r + 0x404), rec && rec < GUEST_MEM - 0x20 ? ldf(c, rec + 0x14) : 0.0f,
                   tr[i].stuck / 60.0f, tr[i].unst, tr[i].wall, tr[i].car);
        } else if (kind == 3 && d < 80) {
            rn_log("AIT f%u car %08x d %+.0f lat %+.1f sp %.1f act %d parked %u hits wall %d car %d draw %u blink %u view %x", f, r, along >= 0 ? d : -d, lat, sp, at,   // probe (exit: delete when "horns with no cars" is decided): the tests of DrawRaceCarList 0x571050
                   v ? c->mem[v + 0x4d1] : 0, tr[i].wall, tr[i].car, c->mem[r + 0x4d0], c->mem[r + 0x8a8], ld(c, r + 0x534, 4));
        }
    }
}

// Reset probe (RN_RESETLOG=1, off by default; OWNER: why a car passes walls or falls after a reset, docs/re/reset_causes.md).
// The reset 0x427c50 (and its entry 0x427f70, host/free.c free_tmove) writes position +0x60, heading +0x3b4, velocity
// +0x70/74/78 and speed +0x3d0, and clears the collision cache car+0x540 with 0x440740. This probe reads that state
// only. reset_call runs from rn_call before the body (host/dispatch.c), reset_tel once per Present (host/d3d9.c).
// Recipe (docs/re/reset_causes.md): RN_RESETLOG=1 RN_FREELOG=1 RN_FREETMOVE=1 with traffic on (?traffic=15&trafrefill=1),
// or a ghost: tools/openworld/ghost.sh <tag> 240 RN_RESETLOG=1 RN_FREETMOVE=1 RN_TRAFREFILL=1.
int rn_resetlog = -1;
#define RST_MAX 4
#define RST_WATCH 120
static struct { uint32_t car, f0; int idx, k, armed, after, prev; float x, y, z, sp, lx, ly, lz, lsp; } rq[RST_MAX];
static int rq_n;

static int rst_index(Ctx *c, uint32_t car) {
    uint32_t h = ld(c, 0x7361f8, 4);
    if (!h || h >= GUEST_MEM - 0x1000) return -1;
    int k = 0;
    for (uint32_t r = ld(c, h, 4); r && r != h && k < 200; r = ld(c, r, 4), k++)
        if (r == car) return k;
    return -1;
}

// target 0x427f70: arg0 = car. target 0x427c50: car = EDI (the entry's this), arg0 = position pointer.
void reset_call(Ctx *c, uint32_t target) {
    if (rn_resetlog < 0) rn_resetlog = getenv("RN_RESETLOG") != NULL;
    if (!rn_resetlog) return;
    uint32_t car = target == 0x427c50 ? c->r[EDI] : ld(c, c->r[ESP] + 4, 4);
    if (!car || car >= GUEST_MEM - 0x900) return;
    uint32_t f = rn_telem.presents;
    int i = 0;
    while (i < RST_MAX && rq[i].car && rq[i].car != car) i++;
    if (i == RST_MAX) return;
    if (!rq[i].car) rq[i].car = car, rq[i].armed = 0;
    if (rq[i].armed && rq[i].f0 == f) return;   // 0x427f70 then 0x427c50 in the same frame: one reset
    rq[i].idx = rst_index(c, car);
    rq[i].x = ldf(c, car + 0x60), rq[i].y = ldf(c, car + 0x64), rq[i].z = ldf(c, car + 0x68);
    rq[i].sp = ldf(c, car + 0x3d0);
    rq[i].f0 = f, rq[i].k = 0, rq[i].armed = 1, rq[i].after = 0, rq[i].prev = 0;
    if (i + 1 > rq_n) rq_n = i + 1;
    rn_log("RST f%u call %08x car %08x idx %d pos %.2f,%.2f,%.2f sp %.1f head %d dt %.4f cache %u/%u/%u/%u",
           f, target, car, rq[i].idx, rq[i].x, rq[i].y, rq[i].z, rq[i].sp, (int16_t)ld(c, car + 0x3b4, 2), ldf(c, 0x73ad38),
           ld(c, car + 0x7e0, 4), ld(c, car + 0x7e4, 4), ld(c, car + 0x7e8, 4), ld(c, car + 0x7ec, 4));
}

void reset_tel(Ctx *c) {
    if (rn_resetlog <= 0) return;
    uint32_t f = rn_telem.presents;
    for (int i = 0; i < rq_n; i++) {
        if (!rq[i].car || !rq[i].armed) continue;
        uint32_t car = rq[i].car;
        float x = ldf(c, car + 0x60), y = ldf(c, car + 0x64), z = ldf(c, car + 0x68), sp = ldf(c, car + 0x3d4);
        if (!rq[i].after) {   // first frame after the call: the state the reset left
            rq[i].after = 1, rq[i].lx = x, rq[i].ly = y, rq[i].lz = z, rq[i].lsp = sp, rq[i].prev = 1;
            rn_log("RSTA f%u car %08x idx %d pos %.2f,%.2f,%.2f dz %+.2f moved %.2f sp %.1f cache %u/%u/%u/%u",
                   f, car, rq[i].idx, x, y, z, z - rq[i].z, hypotf(x - rq[i].x, y - rq[i].y), sp,
                   ld(c, car + 0x7e0, 4), ld(c, car + 0x7e4, 4), ld(c, car + 0x7e8, 4), ld(c, car + 0x7ec, 4));
            rq[i].k = 0;
            continue;
        }
        uint32_t d = f - rq[i].f0;
        if (d > RST_WATCH) { rq[i].armed = 0, rq[i].car = 0; continue; }   // slot free after 2 s
        if (d % 10) continue;
        float mv = hypotf(x - rq[i].lx, y - rq[i].ly);
        int moved = mv > 3.0f && sp < 1.0f && rq[i].lsp < 1.0f;   // embedded or fallen: it slid while stopped
        rn_log("RSTW f%u +%u car %08x idx %d pos %.2f,%.2f,%.2f dz %+.2f moved %.2f sp %.1f cache %u/%u/%u/%u%s",
               f, d, car, rq[i].idx, x, y, z, z - rq[i].z, mv, sp,
               ld(c, car + 0x7e0, 4), ld(c, car + 0x7e4, 4), ld(c, car + 0x7e8, 4), ld(c, car + 0x7ec, 4),
               moved ? " MOVED-WHILE-SLOW" : "");
        rq[i].lx = x, rq[i].ly = y, rq[i].lz = z, rq[i].lsp = sp;
    }
}
