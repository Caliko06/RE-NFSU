// GPS in WORLD: the block the page reads (host/gps.h) and the pose of the player car, each Present. Lead F1 fills gps_frame.
#include "host.h"
#include "gps.h"
RnGps rn_gps;
uint32_t rn_gps_addr(void) { return (uint32_t)(uintptr_t)&rn_gps; }
// RaceStatus track id [0x78a2f0]: same gate as host/d3d9.c mc_hook.
// Player list and pose: tableros/gps-recon.md section 1 (REA + objdump).
void gps_frame(Ctx *c) {
    rn_gps.valid = 0;
    rn_gps.frame = rn_telem.presents;
    if (!rn_racing() || ld(c, 0x78a2f0, 4) != 1010) return;
    uint32_t h = ld(c, 0x7361f8, 4);
    if (!h || h >= GUEST_MEM - 0x1000) return;
    for (uint32_t car = ld(c, h, 4), k = 0;
         car && car != h && car < GUEST_MEM - 0x1000 && k < 200;
         car = ld(c, car, 4), k++) {
        uint32_t entrant = ld(c, car + 0x14, 4);
        if (!entrant || entrant >= GUEST_MEM - 16 || ld(c, entrant + 4, 4) != 1) continue;
        for (int i = 0; i < 3; i++) rn_gps.pos[i] = ldf(c, car + 0x60 + 4 * i);
        rn_gps.yaw16 = ld(c, car + 0x3b4, 2);
        rn_gps.valid = 1;
        return;
    }
}
