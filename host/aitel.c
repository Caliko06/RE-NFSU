// AI telemetry for the OWNER's F10 (RN_AILOG, on by default in the page; OWNER 2026-10-31: "do not diagnose blind"). Log lines only,
// nothing is written to the game. Each line starts with a tag the session JSON can be grepped for:
//   AIP  once a second: the player (speed m/s, position, wheels on the ground, crash state car+0x38).
//   AIR  once a second, each rival (entrant kind 2): distance to the player (+ ahead / - behind along the player's heading), speed,
//        current action type/priority (AI obj +0x3f8: +0x1f8 / +0x1f4; 7 JustDrive, 0 Pass, 5 Block, 0xa GetUnstuck, 1 Avoid),
//        +0x1f0 (1 = speed from the route nodes, 0 = the action's own speed +0x1e4), speed scales racer+0x4b8 and car+0x404,
//        skill record +0x14 (record = car+0x1c), seconds stuck (< 2 m/s), GetUnstuck count, wall and car hits so far.
//   AIDS once a second, each rival, only with RN_AIDS (off by default): the target-speed chain that AIR cannot show.
//        route node index (record+0x8), jitter b (record+0x50), the live jitter (ctx+0x404), the effective node,
//        the route speed byte (node+0x6a), record+0x14, ctx+0x4b8, car+0x404, the product want = byte x rec14 x 4b8
//        recomputed here (0x44c550 stores no such value: it passes it to the vehicle update, argument 1), and the
//        action's own speed pair +0x1e4 / +0x1e8 with the +0x1f0 flag that decides whether they are used.
//   AIT  once a second, each traffic car (kind 3) within 80 m: distance (signed as above), lateral offset from the player's line,
//        speed, action type (3 = Avoid), parked (AI obj +0x4d1).
//   AIDR once a second, the game's own slipstream value car+0x47c (0x426450) of the player (kind 1) and each rival (kind 2).
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

// AIDS (RN_AIDS, off by default; RN_AILOG must be on too): the target-speed chain of one rival, 1/s, host/aitel.c header.
// The desired speed itself is not stored anywhere: 0x44c550 keeps it in a float and passes it to the vehicle update
// (*(*ctx[0x2]+0x38))(speed, ...), and it returns sub_458f10(0,0). So this line logs the four inputs of the product and
// the product recomputed here: want = rb x rec+0x14 x ctx+0x4b8 (I, recomputed, not read from the game).
static void aids_log(Ctx *c, uint32_t f, const char *nm, uint32_t r, uint32_t v, uint32_t rec, uint32_t a, float sp) {
    int node = -1, b = -1, jit = 0, eff = -1, rb = -1;
    float rec14 = 0, s4b8 = 0, s404 = 0, want = 0, a1 = 0, a2 = 0;
    int flag = -1;
    if (rec && rec < GUEST_MEM - 0x60) {
        node = (int8_t)c->mem[rec + 8];
        b = (int8_t)c->mem[rec + 0x50];
        rec14 = ldf(c, rec + 0x14);
    }
    if (a && a < GUEST_MEM - 0x200) flag = c->mem[a + 0x1f0], a1 = ldf(c, a + 0x1e4), a2 = ldf(c, a + 0x1e8);
    if (!v) return;
    s4b8 = ldf(c, v + 0x4b8), s404 = ldf(c, r + 0x404);
    jit = (int32_t)ld(c, v + 0x404, 4);   // jitter of the route node, re-rolled every 0x77a498 s from record+0x50 (0x44c550)
    // route speed byte: route node idx*0x88 + 0x6a, nodes via the AI driver's route clone (driver +0x3e4, nodes at +8, host/d3d9.c:1154)
    uint32_t drv = ld(c, r + 0x2c, 4), route = drv && drv < GUEST_MEM - 0x400 ? ld(c, drv + 0x3e4, 4) : 0;
    uint32_t n = route && route < GUEST_MEM - 0x100 ? ld(c, route + 4, 4) : 0;
    if (node >= 0 && n && n < 4096) {
        eff = node + jit;
        if (eff < 0) eff = 0;
        if ((uint32_t)eff >= n) eff = n - 1;
        uint32_t np = ld(c, route + 8 + 4 * (uint32_t)eff, 4);
        if (np && np < GUEST_MEM - 0x80) rb = c->mem[np + 0x6a];
    }
    if (rb > 0) want = (float)rb * rec14 * s4b8;
    rn_log("AIDS f%u %s sp %.1f node %d b %d jit %d eff %d rb %d rec14 %.2f s4b8 %.2f s404 %.2f want %.1f a1 %.1f a2 %.1f flag %d nodes %u",
           f, nm, sp, node, b, jit, eff, rb, rec14, s4b8, s404, want, a1, a2, flag, n);
}

void ai_tel(Ctx *c) {
    static int on = -1, aids = -1;
    static uint32_t race;   // rn_race of the state in tr[] and the draft counters
    if (on < 0) on = getenv("RN_AILOG") != NULL;
    if (aids < 0) aids = getenv("RN_AIDS") != NULL;
    if (!on) return;
    uint32_t h = ld(c, 0x7361f8, 4);
    if (!rn_racing() || !h || h >= GUEST_MEM - 0x1000) return;
    static uint32_t tow_n, sec_n;          // seconds with the player's draft (car+0x47c) > 0.2, out of seconds in this race
    if (rn_new_race(&race)) memset(tr, 0, sizeof tr), tow_n = sec_n = 0;
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
    float pd = ldf(c, me + 0x47c);
    if (sec) tow_n += pd > 0.2f, sec_n++;
    if (sec) rn_log("AIP f%u sp %.1f pos %.0f,%.0f,%.0f wheels %u crash %u draft %.3f tow>0.2 %u/%u %.1f%%", f, ldf(c, me + 0x3d4), px, py, ldf(c, me + 0x58),
                    ld(c, me + 0x3cc, 4), ld(c, me + 0x38, 4), pd, tow_n, sec_n, sec_n ? 100.0f * tow_n / sec_n : 0.0f);
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
        // AIDR: the game's own slipstream value car+0x47c (0x426450, sum of the 0x426300 pair terms, cap 0.9) once a second,
        // for the player (kind 1) and each rival (kind 2). Log only; docs/re/ai_draft.md. Read it with d = the gap to the car ahead.
        if (kind == 1 || kind == 2)
            rn_log("AIDR f%u kind %u car %08x draft %.3f sp %.1f d %+.0f lat %+.0f", f, kind, r, ldf(c, r + 0x47c), sp,
                   along >= 0 ? d : -d, lat);
        if (kind == 2) {
            uint32_t rec = ld(c, r + 0x1c, 4);
            if (aids) aids_log(c, f, G(e + 0x73c), r, v, rec, a, sp);
            rn_log("AIR f%u %s d %+.0f lat %+.0f sp %.1f act %d/%d route %d own %.1f s4b8 %.2f s404 %.2f rec14 %.2f stuck %.1f s unst %d hits wall %d car %d at %.0f,%.0f",
                   f, G(e + 0x73c), along >= 0 ? d : -d, lat, sp, at, a ? (int)ld(c, a + 0x1f4, 4) : -1, a ? c->mem[a + 0x1f0] : -1,
                   a ? ldf(c, a + 0x1e4) : 0.0f, v ? ldf(c, v + 0x4b8) : 0.0f, ldf(c, r + 0x404), rec && rec < GUEST_MEM - 0x20 ? ldf(c, rec + 0x14) : 0.0f,
                   tr[i].stuck / 60.0f, tr[i].unst, tr[i].wall, tr[i].car, x, y);
        } else if (kind == 3 && d < 80) {
            rn_log("AIT f%u car %08x d %+.0f lat %+.1f sp %.1f act %d parked %u hits wall %d car %d draw %u blink %u view %x", f, r, along >= 0 ? d : -d, lat, sp, at,   // probe (exit: delete when "horns with no cars" is decided): the tests of DrawRaceCarList 0x571050
                   v ? c->mem[v + 0x4d1] : 0, tr[i].wall, tr[i].car, c->mem[r + 0x4d0], c->mem[r + 0x8a8], ld(c, r + 0x534, 4));
        }
    }
}

// Reset probe (RN_RESETLOG=1, off by default; OWNER: why a car passes walls or falls after a reset, docs/re/reset_causes.md).
// Every path of the game's reset only raises car+0x87c: 0x428080 (request), 0x426930 (no ground every 32 frames via 0x440ce0,
// or > 5000 m from the route point), 0x427ed0 (RESET zone). Car::ServiceResetRequest 0x4264d0 (from the car update) consumes it:
// for driver kind 1 with driver+0x734 == 0 it does `eax = car+0x18; call 0x4314a0` (0x42653b). Player::ResetToRoute 0x4314a0
// then re-places the car with 0x427f70(car, section, node, speed, 1, dir, 0, 0, lat) when the car has a route path, or with
// 0x427c50(&pos, 0, heading) on the nearest route node that has ground (0x440a40) when it has none.
// reset_call runs from rn_call before the body (host/dispatch.c) for 0x427f70/0x427c50, reset_tel once per Present
// (host/d3d9.c). RN_RESETEVERY=<s> (default off) calls the player's own reset 0x4314a0 on the kind-1 car every N s.
// Recipe (docs/re/reset_causes.md): RN_RESETLOG=1 RN_RESETEVERY=3 in a Free Run ghost (tools/openworld/ghost.sh <tag> 240),
// or RN_RESETLOG=1 RN_FREELOG=1 RN_FREETMOVE=1 with traffic (?traffic=15&trafrefill=1) for traffic resets.
int rn_resetlog = -1;
static int rn_resetevery = -1;      // RN_RESETEVERY=<seconds>; <= 0 off
static uint32_t rq_next;            // next presents to fire it
#define RST_MAX 4
#define RST_WATCH 120
static struct { uint32_t car, f0; int idx, armed, after; float x, y, z, sp, lx, ly, lz, lsp; } rq[RST_MAX];
static int rq_n;
static uint32_t rq_race;
static uint32_t gq_pt, gq_flag;
static uint32_t wx_reset_car, wx_reset_f, wx_resets;   // last reset seen by rst_arm (RN_WALLX)

static void rst_clear(void) {
    memset(rq, 0, sizeof rq);
    rq_n = 0;
}

static int rst_index(Ctx *c, uint32_t car) {
    uint32_t h = ld(c, 0x7361f8, 4);
    if (!h || h >= GUEST_MEM - 0x1000) return -1;
    int k = 0;
    for (uint32_t r = ld(c, h, 4); r && r != h && k < 200; r = ld(c, r, 4), k++)
        if (r == car) return k;
    return -1;
}

// The game's own ground query 0x440a40 on the car's cache object (as host/openworld.c ground_at): return 1 with the height.
// It can rebuild that cache, so callers read the cache counters BEFORE this. The FPU stack is saved and put back.
static int rst_ground(Ctx *c, uint32_t car, float *h) {
    if (!gq_pt) gq_pt = guest_alloc(16), gq_flag = guest_alloc(16);
    if (!gq_pt || !gq_flag) return 0;
    float x = ldf(c, car + 0x60), y = ldf(c, car + 0x64);
    memcpy(c->mem + gq_pt, &x, 4), memcpy(c->mem + gq_pt + 4, &y, 4);
    st(c, gq_flag, 0, 4);
    uint32_t a[5] = {car + 0x540, gq_pt, 0, 0, gq_flag};
    uint32_t fcw = c->fcw, fsw = c->fsw, ftop = c->ftop, ftag = c->ftag;
    double st8[8];
    memcpy(st8, c->st, sizeof st8);
    call_guest(c, 0x440a40, 5, a);
    *h = (float)*fr(c, 0);
    fpop(c);
    memcpy(c->st, st8, sizeof st8);
    c->fcw = fcw, c->fsw = fsw, c->ftop = ftop, c->ftag = ftag;
    return ld(c, gq_flag, 1) != 0;
}

// One watch slot per car; logs the state the reset had when it was called.
static int rst_arm(Ctx *c, uint32_t car, const char *why, uint32_t target) {
    if (rn_new_race(&rq_race)) rst_clear();
    uint32_t f = rn_telem.presents;
    int i = 0;
    while (i < RST_MAX && rq[i].car && rq[i].car != car) i++;
    if (i == RST_MAX) return -1;
    if (!rq[i].car) rq[i].car = car, rq[i].armed = 0;
    if (rq[i].armed && rq[i].f0 == f) return i;   // 0x427f70 then 0x427c50 in the same frame: one reset
    wx_reset_car = car, wx_reset_f = f, wx_resets++;   // RN_WALLX: the post-reset window starts here
    rq[i].idx = rst_index(c, car);
    rq[i].x = ldf(c, car + 0x60), rq[i].y = ldf(c, car + 0x64), rq[i].z = ldf(c, car + 0x68);
    rq[i].sp = ldf(c, car + 0x3d0);
    rq[i].f0 = f, rq[i].armed = 1, rq[i].after = 0;
    if (i + 1 > rq_n) rq_n = i + 1;
    rn_log("RST f%u %s call %08x car %08x idx %d pos %.2f,%.2f,%.2f sp %.1f head %d dt %.4f cache %u/%u/%u/%u",
           f, why, target, car, rq[i].idx, rq[i].x, rq[i].y, rq[i].z, rq[i].sp, (int16_t)ld(c, car + 0x3b4, 2), ldf(c, 0x73ad38),
           ld(c, car + 0x7e0, 4), ld(c, car + 0x7e4, 4), ld(c, car + 0x7e8, 4), ld(c, car + 0x7ec, 4));
    return i;
}

// target 0x427f70: arg0 = car. target 0x427c50: car = EDI (the entry's this), arg0 = position pointer.
void reset_call(Ctx *c, uint32_t target) {
    if (rn_resetlog < 0) rn_resetlog = getenv("RN_RESETLOG") != NULL || getenv("RN_WALLX") != NULL;   // RN_WALLX needs the reset frame
    if (!rn_resetlog || !rn_racing()) return;
    uint32_t car = target == 0x427c50 ? c->r[EDI] : ld(c, c->r[ESP] + 4, 4);
    if (!car || car >= GUEST_MEM - 0x900) return;
    rst_arm(c, car, "call", target);
}

// RN_RESETEVERY: the player's own reset, exactly the call 0x4264d0 makes (0x42653b: eax = car+0x18; call 0x4314a0).
static void reset_every(Ctx *c) {
    if (rn_resetevery < 0) {
        const char *e = getenv("RN_RESETEVERY");
        rn_resetevery = e ? atoi(e) : 0;
        if (rn_resetevery > 0) rn_resetlog = 1;   // forcing the reset implies logging it
    }
    if (rn_resetevery <= 0) return;
    uint32_t f = rn_telem.presents;
    if (f < rq_next || !rn_racing()) return;
    uint32_t h = ld(c, 0x7361f8, 4), car = 0;
    if (!h || h >= GUEST_MEM - 0x1000) return;
    for (uint32_t r = ld(c, h, 4), k = 0; r && r != h && k < 200; r = ld(c, r, 4), k++) {
        uint32_t e = ld(c, r + 0x14, 4);
        if (e && e < GUEST_MEM - 16 && ld(c, e + 4, 4) == 1) { car = r; break; }
    }
    if (!car) return;
    uint32_t ctrl = ld(c, car + 0x18, 4);
    if (!ctrl || ctrl >= GUEST_MEM - 0x900) return;
    rq_next = f + (uint32_t)rn_resetevery * 60;
    if (rn_resetlog > 0) rst_arm(c, car, "every", 0x4314a0);   // before the call: RST logs the pos before, RSTA the pos after (Block 1 armed it after)
    c->r[EAX] = ctrl;
    call_guest(c, 0x4314a0, 0, NULL);
    if (!c->halt) st(c, car + 0x87c, 0, 4);   // 0x4264d0 clears the request after the service
}

// RN_WALLX=1 (off by default; GOAL 2026-11-05 Block 1, docs/re/reset_walls.md): count wall pass-throughs of the player.
// Truth = the walls the game itself holds: manager 0x77b130 wsrc rows (+0x10 ptr, +0x14 count, 32 B each, flags byte +3 & 2 =
// wall, layout in tools/openworld/polys.py). Every Present the player's xy step (prev -> now) is tested against the base
// segment of each wall row (its two farthest vertices) and its z span (+-2 m; 0x16 walls are infinite). A car that is stopped
// by a wall never has its centre cross the base segment, so each crossing is a pass-through. The step across a teleport
// (> 15 m in one Present, or the reset frame itself) is skipped. "post" = within 180 Presents (3 s) after the player's reset.
static struct { int on; uint32_t init, mm_all, mm_post, ns_all, ns_post, car, nall, npost, fall, fpost, jumps, last; float px, py, pz; int have; } wx;

static uint32_t player_car(Ctx *c) {
    uint32_t h = ld(c, 0x7361f8, 4);
    if (!h || h >= GUEST_MEM - 0x1000) return 0;
    for (uint32_t r = ld(c, h, 4), k = 0; r && r != h && k < 200; r = ld(c, r, 4), k++) {
        uint32_t e = ld(c, r + 0x14, 4);
        if (e && e < GUEST_MEM - 16 && ld(c, e + 4, 4) == 1) return r;
    }
    return 0;
}

static int seg_x(float ax, float ay, float bx, float by, float cx, float cy, float dx, float dy) {
    float d1 = (bx - ax) * (cy - ay) - (by - ay) * (cx - ax), d2 = (bx - ax) * (dy - ay) - (by - ay) * (dx - ax);
    float d3 = (dx - cx) * (ay - cy) - (dy - cy) * (ax - cx), d4 = (dx - cx) * (by - cy) - (dy - cy) * (bx - cx);
    return ((d1 > 0) != (d2 > 0) || d1 == 0 || d2 == 0) && ((d3 > 0) != (d4 > 0) || d3 == 0 || d4 == 0) && !(d1 == 0 && d2 == 0);
}

// Wall rows whose xy bbox overlaps the box pos +- r and whose z span holds z (+-3): what the car's wall cache (car+0x7e8) should hold.
static uint32_t walls_near(Ctx *c, uint32_t base, uint32_t n, float x, float y, float z, float r) {
    uint32_t k = 0;
    for (uint32_t i = 0; i < n; i++) {
        uint32_t row = base + i * 32, fl = ld(c, row + 3, 1);
        if (!(fl & 2)) continue;
        int nv = fl & 0x10 ? 4 : 3;
        float mnx = 1e9f, mxx = -1e9f, mny = 1e9f, mxy = -1e9f, mnz = 1e9f, mxz = -1e9f, bz = (int16_t)ld(c, row + 4, 2), kz = fl & 4 ? 4.0f : 1.0f;
        for (int j = 0; j < nv; j++) {
            float vx = (int16_t)ld(c, row + 8 + 2 * j, 2) / 8.0f, vy = (int16_t)ld(c, row + 16 + 2 * j, 2) / 8.0f;
            float vz = (bz + (int16_t)ld(c, row + 24 + 2 * j, 2) / 256.0f) * kz;
            mnx = fminf(mnx, vx), mxx = fmaxf(mxx, vx), mny = fminf(mny, vy), mxy = fmaxf(mxy, vy), mnz = fminf(mnz, vz), mxz = fmaxf(mxz, vz);
        }
        k += !(mxx < x - r || mnx > x + r || mxy < y - r || mny > y + r || z < mnz - 3.0f || z > mxz + 3.0f);
    }
    return k;
}

static void wallx_tel(Ctx *c) {
    if (!wx.on) wx.on = getenv("RN_WALLX") ? 1 : -1;
    if (wx.on < 0 || !rn_racing()) return;
    static uint32_t race;
    if (rn_new_race(&race)) wx.have = 0, wx.car = 0;   // the first frame of a race measures no jump from the last one
    uint32_t car = player_car(c), f = rn_telem.presents;
    if (!car) return;
    float x = ldf(c, car + 0x60), y = ldf(c, car + 0x64), z = ldf(c, car + 0x68);
    uint32_t base = ld(c, 0x77b140, 4), n = ld(c, 0x77b144, 4);
    if (!base || n > 1000000 || base >= GUEST_MEM - n * 32) return;
    float dx = x - wx.px, dy = y - wx.py;
    int skip = !wx.have || car != wx.car || hypotf(dx, dy) > 15.0f || (wx_reset_car == car && wx_reset_f == f);
    uint32_t since = wx_reset_car == car ? f - wx_reset_f : 0xffffffffu;
    int post = since <= 180;
    if (!wx.init) {
        wx.init = 1;
        uint32_t nw = 0;
        for (uint32_t i = 0; i < n; i++) nw += (ld(c, base + i * 32 + 3, 1) & 2) != 0;
        rn_log("WALLXINIT rows %u walls %u", n, nw);
    }
    if (!skip) {
        wx.fall++, wx.fpost += post;
        float lox = fminf(x, wx.px) - 1, hix = fmaxf(x, wx.px) + 1, loy = fminf(y, wx.py) - 1, hiy = fmaxf(y, wx.py) + 1;
        for (uint32_t i = 0; i < n; i++) {
            uint32_t r = base + i * 32;
            uint32_t fl = ld(c, r + 3, 1);
            if (!(fl & 2)) continue;
            int nv = fl & 0x10 ? 4 : 3;
            float vx[4], vy[4], vz[4], bz = (int16_t)ld(c, r + 4, 2), k = fl & 4 ? 4.0f : 1.0f;
            float mnx = 1e9f, mxx = -1e9f, mny = 1e9f, mxy = -1e9f, mnz = 1e9f, mxz = -1e9f;
            for (int j = 0; j < nv; j++) {
                vx[j] = (int16_t)ld(c, r + 8 + 2 * j, 2) / 8.0f, vy[j] = (int16_t)ld(c, r + 16 + 2 * j, 2) / 8.0f;
                vz[j] = (bz + (int16_t)ld(c, r + 24 + 2 * j, 2) / 256.0f) * k;
                mnx = fminf(mnx, vx[j]), mxx = fmaxf(mxx, vx[j]), mny = fminf(mny, vy[j]), mxy = fmaxf(mxy, vy[j]);
                mnz = fminf(mnz, vz[j]), mxz = fmaxf(mxz, vz[j]);
            }
            if (mxx < lox || mnx > hix || mxy < loy || mny > hiy || z < mnz - 2.0f || z > mxz + 2.0f) continue;
            int bi = 0, bj = 1;
            float bd = -1;
            for (int a = 0; a < nv; a++) for (int b = a + 1; b < nv; b++) {
                float d = hypotf(vx[a] - vx[b], vy[a] - vy[b]);
                if (d > bd) bd = d, bi = a, bj = b;
            }
            if (!seg_x(wx.px, wx.py, x, y, vx[bi], vy[bi], vx[bj], vy[bj])) continue;
            wx.nall++, wx.npost += post;
            rn_log("WALLX f%u row %u %s since %d pos %.2f,%.2f,%.2f step %.2f,%.2f wall %.1f,%.1f-%.1f,%.1f z %.1f..%.1f fl %02x sp %.1f",
                   f, i, post ? "POST" : "other", post ? (int)since : -1, x, y, z, dx, dy, vx[bi], vy[bi], vx[bj], vy[bj], mnz, mxz, fl,
                   ldf(c, car + 0x3d4));
        }
    } else if (wx.have && car == wx.car) wx.jumps++;
    if (!skip && (f % 15 == 0)) {   // WNEAR: does the cache hold the walls that really are within 8 m? (the cache box is bigger, so it should hold at least that many)
        uint32_t cw = ld(c, car + 0x7e8, 4), cn = ld(c, car + 0x7e0, 4), near = walls_near(c, base, n, x, y, z, 8.0f);
        wx.ns_all++, wx.ns_post += post;
        if (cw < near && cn < 0xa0) {
            wx.mm_all++, wx.mm_post += post;
            if (wx.mm_all <= 60) rn_log("WNEAR f%u %s since %d pos %.1f,%.1f,%.1f sp %.1f real8 %u cache %u/%u/%u/%u",
                                       f, post ? "POST" : "other", post ? (int)since : -1, x, y, z, ldf(c, car + 0x3d4), near, cn, ld(c, car + 0x7e4, 4), cw, ld(c, car + 0x7ec, 4));
        }
    }
    wx.car = car, wx.px = x, wx.py = y, wx.pz = z, wx.have = 1;
    if (f - wx.last >= 600) {
        wx.last = f ? f : 1;
        rn_log("WALLXSUM f%u cross %u post %u frames %u postframes %u resets %u skipped %u wnear_samples %u/%u wnear_short %u/%u (all/post)", f, wx.nall, wx.npost, wx.fall, wx.fpost, wx_resets, wx.jumps, wx.ns_all, wx.ns_post, wx.mm_all, wx.mm_post);
    }
}

void reset_tel(Ctx *c) {
    reset_every(c);
    wallx_tel(c);
    if (rn_resetlog <= 0) return;
    if (!rn_racing()) {
        if (rq_n) rst_clear();
        return;
    }
    if (rn_new_race(&rq_race)) rst_clear();
    uint32_t f = rn_telem.presents;
    for (int i = 0; i < rq_n; i++) {
        if (!rq[i].car || !rq[i].armed) continue;
        uint32_t car = rq[i].car;
        float x = ldf(c, car + 0x60), y = ldf(c, car + 0x64), z = ldf(c, car + 0x68), sp = ldf(c, car + 0x3d4);
        uint32_t cb = ld(c, car + 0x7e0, 4), cg = ld(c, car + 0x7e4, 4), cw = ld(c, car + 0x7e8, 4), cr = ld(c, car + 0x7ec, 4);
        if (!rq[i].after) {   // first frame after the call: the state the reset left (counters read before the ground query)
            float zh = 0;
            int ok = rst_ground(c, car, &zh);
            char zr[32];
            snprintf(zr, sizeof zr, ok ? "%.2f" : "none", zh);
            rq[i].after = 1, rq[i].lx = x, rq[i].ly = y, rq[i].lz = z, rq[i].lsp = sp;
            rn_log("RSTA f%u car %08x idx %d pos %.2f,%.2f,%.2f dz %+.2f moved %.2f sp %.1f zroad %s dzroad %+.2f ground %d cache %u/%u/%u/%u",
                   f, car, rq[i].idx, x, y, z, z - rq[i].z, hypotf(x - rq[i].x, y - rq[i].y), sp,
                   zr, ok ? z - zh : 0.0f, ok, cb, cg, cw, cr);
            continue;
        }
        uint32_t d = f - rq[i].f0;
        if (d > RST_WATCH) { rq[i].armed = 0, rq[i].car = 0; continue; }   // slot free after 2 s
        if (d % 10) continue;
        float zh = 0;
        int ok = rst_ground(c, car, &zh);
        char zr[32];
        snprintf(zr, sizeof zr, ok ? "%.2f" : "none", zh);
        float mv = hypotf(x - rq[i].lx, y - rq[i].ly);
        int moved = mv > 3.0f && sp < 1.0f && rq[i].lsp < 1.0f;   // embedded or fallen: it slid while stopped
        rn_log("RSTW f%u +%u car %08x idx %d pos %.2f,%.2f,%.2f dz %+.2f moved %.2f sp %.1f zroad %s dzroad %+.2f ground %d cache %u/%u/%u/%u%s",
               f, d, car, rq[i].idx, x, y, z, z - rq[i].z, mv, sp, zr, ok ? z - zh : 0.0f, ok, cb, cg, cw, cr,
               moved ? " MOVED-WHILE-SLOW" : "");
        rq[i].lx = x, rq[i].ly = y, rq[i].lz = z, rq[i].lsp = sp;
    }
}
