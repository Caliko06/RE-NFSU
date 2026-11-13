// GPS in WORLD (tableros/gps-recon.md): one block the page reads and writes through _rn_gps_addr() (HEAPU8 offsets below are fixed).
// Pose comes from the player car (race list [0x7361f8], car+0x60/+0x64/+0x68, yaw s16 car+0x3b4: Speed.exe 0x427c97, 0x427cb1).
#pragma once
#include <stdint.h>
#define GPS_ROUTE_MAX 2048
typedef struct {
    float pos[3];      // +0   car x, y, z (NFSU1 world frame, Z up)
    int32_t yaw16;     // +12  car+0x3b4, 0..65535 = one turn
    int32_t valid;     // +16  1 = WORLD track and the player car found this frame
    uint32_t frame;    // +20  Present count of the last update
    float tp[3];       // +24  teleport target (page writes)
    int32_t tp_yaw16;  // +36
    int32_t tp_req;    // +40  page sets 1; host does the teleport at the next Present and sets 0
    int32_t tp_res;    // +44  host: 1 done, -1 refused (not WORLD / no car)
    int32_t route_n;   // +48  points in route_xy (page writes; 0 = no route)
    float route_xy[2 * GPS_ROUTE_MAX];  // +52 route polyline x0, y0, x1, y1 ... (world frame) for the HUD minimap
} RnGps;
extern RnGps rn_gps;
uint32_t rn_gps_addr(void);
