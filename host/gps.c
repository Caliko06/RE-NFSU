// GPS in WORLD: the block the page reads (host/gps.h) and the pose of the player car, each Present. Lead F1 fills gps_frame.
#include "host.h"
#include "gps.h"
RnGps rn_gps;
uint32_t rn_gps_addr(void) { return (uint32_t)(uintptr_t)&rn_gps; }
void gps_frame(Ctx *c) { (void)c; }
