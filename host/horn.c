// Traffic horn: probe (RN_HORNLOG=1, off by default) and its draft fix (RN_HORNFIX=1, off by default).
// PATCH 0x52536a (cave 0x5256e8: jmp [SCREEN_ADDR+0xa4]) is the only call of EAXTrafficCar::StartHorn 0x524f30 in the image, at the
// end of the honk branch of EAXTrafficCar::Update 0x5251e0. edi = the sound object (the same one as car+0x878), [esp+4] = sample
// index, the callee pops it (0x525075: ret 4). The sound path tests no parked byte, no draw flag and no distance to the world (only
// a 30 m sphere plus a probabilistic front cone, docs/re/traffic_honks.md), so a car the world does not draw still honks.
// Fields (docs/re/horn_traffic.md, all read from the binary): sound +0x234 owner car, +0x240 clock, +0x300 voice, +0x2f8 the player's
// car as 0x5328b0 resolved it this frame; car +0x50/0x54 body x/y used by the placement, +0x60/0x64 the position the range test
// reads, +0x4d0 the draw flag (DrawRaceCarList 0x571050 skips the car when it is 0, 0x570eb9), +0x2c the vehicle that carries the
// parked byte +0x4d1 (as host/aitel.c AIT reads it). 0x73ad34 is the 4 kHz ticker (CLK_S in host/rivals.c).
// RN_HORNLOG: one HORNL line per honk (frame, car index in the race list, car, sample, parked, draw flag, the two view masks the
// draw test reads, distance to the player, seconds since the car was recycled, and what RN_HORNFIX would have done).
// RN_HORNFIX: skip StartHorn when the owner car is parked, when its draw flag is 0, or when it was recycled less than 3 s ago.
#include <math.h>
#include <string.h>
#include "host.h"

#define HORN_MAX 64
static struct { uint32_t car; float x, y, rec; unsigned char parked; } hc[HORN_MAX];
static int hlog = -1, hfix;

static float hclock(Ctx *c) { return (float)ld(c, 0x73ad34, 4) / 4000.0f; }
static int inmem(Ctx *c, uint32_t p, uint32_t need) { (void)c; return p > 0x10000 && p < GUEST_MEM - need; }
static int parked_of(Ctx *c, uint32_t car) {          // +0x4d1 lives on the vehicle, not on the car
    uint32_t v = inmem(c, car, 0x4e0) ? ld(c, car + 0x2c, 4) : 0;
    return inmem(c, v, 0x4e0) && c->mem[v + 0x4d1];
}

// Once per Present (host/d3d9.c, next to free_tick): the two ways a traffic car gets a new spot, so the horn hook can tell a car
// that just appeared next to the player from one that drove there.
void horn_tick(Ctx *c) {
    if (hlog < 0) hlog = getenv("RN_HORNLOG") != NULL, hfix = getenv("RN_HORNFIX") != NULL;
    if (!hlog && !hfix) return;
    uint32_t h = ld(c, 0x7361f8, 4);
    if (ld(c, 0x77a920, 4) != 6 || !h || h >= GUEST_MEM - 0x1000) { memset(hc, 0, sizeof hc); return; }
    float now = hclock(c);
    for (uint32_t r = ld(c, h, 4), k = 0; r && r != h && k < 200; r = ld(c, r, 4), k++) {
        uint32_t e = inmem(c, r, 0x900) ? ld(c, r + 0x14, 4) : 0;
        if (!e || e >= GUEST_MEM - 8 || ld(c, e + 4, 4) != 3) continue;
        int i = 0;
        while (i < HORN_MAX && hc[i].car && hc[i].car != r) i++;
        if (i == HORN_MAX) continue;
        float x = ldf(c, r + 0x50), y = ldf(c, r + 0x54);
        int parked = parked_of(c, r);
        if (!hc[i].car) memset(&hc[i], 0, sizeof hc[i]), hc[i].car = r, hc[i].rec = -1e9f;
        else if (hypotf(x - hc[i].x, y - hc[i].y) > 50.0f) hc[i].rec = now;   // 50 m in one frame is a teleport, not driving
        else if (hc[i].parked && !parked) hc[i].rec = now;                    // parked and moved again: a recycle too
        hc[i].x = x, hc[i].y = y, hc[i].parked = (unsigned char)parked;
    }
}

// PATCH 0x52536a: the honk branch's StartHorn call. edi = the sound object, the original callee pops its one argument.
uint32_t horn_start(Ctx *c) {
    if (hlog < 0) hlog = getenv("RN_HORNLOG") != NULL, hfix = getenv("RN_HORNFIX") != NULL;
    uint32_t a = ARG(0), s = c->r[EDI];
    if (!hlog && !hfix) return call_guest(c, 0x524f30, 1, &a);
    uint32_t car = inmem(c, s, 0x330) ? ld(c, s + 0x234, 4) : 0, player = inmem(c, s, 0x330) ? ld(c, s + 0x2f8, 4) : 0;
    int idx = -1, parked = 0, draw = 0, skip = 0;
    float d = -1.0f, rec = 1e9f;
    uint32_t me = 0;                                     // the player: kind 1 in the race list (0x5328b0's answer is a lookup by position,
    for (uint32_t h = ld(c, 0x7361f8, 4), r = h ? ld(c, h, 4) : 0, k = 0; r && r != h && k < 200 && !me; r = ld(c, r, 4), k++) {
        uint32_t e = inmem(c, r, 0x900) ? ld(c, r + 0x14, 4) : 0;
        if (e && e < GUEST_MEM - 8 && ld(c, e + 4, 4) == 1) me = r;
    }
    if (inmem(c, me, 0x900)) player = me;                // so the list wins; the sound object's +0x2f8 only when there is no list
    if (inmem(c, car, 0x900)) {
        parked = parked_of(c, car);
        draw = c->mem[car + 0x4d0];
        uint32_t h = ld(c, 0x7361f8, 4);
        for (uint32_t r = h ? ld(c, h, 4) : 0, k = 0; r && r != h && k < 200; r = ld(c, r, 4), k++)
            if (r == car) { idx = (int)k; break; }
        if (inmem(c, player, 0x900))
            d = hypotf(ldf(c, car + 0x60) - ldf(c, player + 0x60), ldf(c, car + 0x64) - ldf(c, player + 0x64));
        for (int i = 0; i < HORN_MAX && rec > 1e8f; i++)
            if (hc[i].car == car) rec = hclock(c) - hc[i].rec;
        skip = hfix && (parked || !draw || rec < 3.0f);
    }
    if (hlog)
        rn_log("HORNL f%u car %08x idx %d snd %u parked %d draw %d view %08x,%08x d %.1f rec %.1f skip %d", rn_telem.presents, car, idx, a,
               parked, draw, inmem(c, car, 0x900) ? ld(c, car + 0x530, 4) : 0, inmem(c, car, 0x900) ? ld(c, car + 0x534, 4) : 0, d, rec, skip);
    if (skip) return 0;
    return call_guest(c, 0x524f30, 1, &a);
}

const Api horn_apis[] = {{"rn", "horn_start", 0, horn_start}};
const int horn_api_count = 1;
