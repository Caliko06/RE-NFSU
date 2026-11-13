// WORLD teleport: verify resident collision, ResetToPoint, then seed the viewer.
// Binary reads and the reason not to wait on 0x445100: tableros/gps-tp-evidence.md.
#include "host.h"
#include "gps.h"

void gps_teleport(Ctx *c) {
    static uint32_t scratch;
    if (__atomic_load_n(&rn_gps.tp_req, __ATOMIC_ACQUIRE) != 1) return;
    int result = -1;
    // Track key 0x78a2f0 (0x441fe0), flow 6/4 = driving, including Original's WORLD.
    if (rn_flow != 0x604 || ld(c, 0x78a2f0, 4) != 1010) goto done;
    uint32_t car = 0, head = ld(c, 0x7361f8, 4);
    if (head && head < GUEST_MEM - 0x1000) {
        for (uint32_t p = ld(c, head, 4), k = 0; p && p != head && p < GUEST_MEM - 0x1000 && k < 200; p = ld(c, p, 4), k++) {
            uint32_t entrant = ld(c, p + 0x14, 4);
            if (entrant && entrant < GUEST_MEM - 16 && ld(c, entrant + 4, 4) == 1) { car = p; break; }
        }
    }
    if (!car || !isfinite(rn_gps.tp[0]) || !isfinite(rn_gps.tp[1]) || !isfinite(rn_gps.tp[2])) goto done;
    if (!scratch) scratch = guest_alloc(32);
    if (!scratch) goto done;
    for (int k = 0; k < 3; k++) stf(c, scratch + 4 * k, rn_gps.tp[k]);
    st(c, scratch + 16, 0, 4);
    Ctx saved = *c;  // Present must retain its CPU registers, flags and complete x87 stack.
    uint32_t ground_args[5] = {car + 0x540, scratch, 0, 0, scratch + 16};
    call_guest(c, 0x440a40, 5, ground_args);
    float ground = (float)*fr(c, 0);
    fpop(c);
    int found = ld(c, scratch + 16, 1) != 0;
    if (!c->halt && found) {
        float before[3] = {ldf(c, car + 0x60), ldf(c, car + 0x64), ldf(c, car + 0x68)};
        uint32_t args[2] = {0, 0};
        c->r[ECX] = car; c->r[EDX] = scratch; c->r[EAX] = (uint32_t)rn_gps.tp_yaw16 & 0xffff;
        call_guest(c, 0x427e60, 2, args);  // -> 0x427c50 -> 0x4278d0 ground snap
        if (!c->halt) {
            c->r[EAX] = 0; c->r[EDX] = 0x77a980; c->r[ECX] = car + 0x60;
            call_guest(c, 0x444840, 0, NULL);
        }
        if (!c->halt) result = 1;
        rn_log("GPS TP: car %08x %.2f %.2f %.2f -> %.2f %.2f %.2f ground=%d height=%.2f yaw=%d frame=%u result=%d",
               car, before[0], before[1], before[2], ldf(c, car + 0x60), ldf(c, car + 0x64), ldf(c, car + 0x68),
               found, ground, rn_gps.tp_yaw16, rn_telem.presents, result);
    } else if (!c->halt) {
        rn_log("GPS TP: rejected target %.2f %.2f %.2f: no resident ground", rn_gps.tp[0], rn_gps.tp[1], rn_gps.tp[2]);
    }
    if (!c->halt) *c = saved;
done:
    __atomic_store_n(&rn_gps.tp_res, result, __ATOMIC_RELEASE);
    __atomic_store_n(&rn_gps.tp_req, 0, __ATOMIC_RELEASE);
}
