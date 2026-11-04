// Feel probe (RN_FEELLOG, off by default), docs/re/feel_patch_plan.md: the numbers behind the OWNER's four complaints, so a
// patch is flipped against a measurement and not a hunch. Log lines only, nothing is written to the game.
//   FEEL, every 30 frames: the player's speed (m/s and mph), the POV code the camera mover is using, the chase row that POV
//        resolves to in the car's CarTypeInfo (distance, height) and the FOV word of that POV in 0x6fbdf4, in degrees.
//   FEEL A, once per standing start (speed under 0.3 m/s, then a race car): the time to 60 and to 100 mph, counted on the
//        Present clock (60 per second, the limiter is 1:1: docs/re/feel_2026-10-31.md 5). A run that never reaches 100 mph in
//        20 s logs what it got and ends; the line says "no 100".
// Offsets: race list [0x7361f8] and the player entrant kind 1 (host/aitel.c), speed car+0x3d4 (m/s). CarTypeInfo car+0xc,
// rows at info+0xb50 (+0x10 normal, +0x60 the [0x7364a0] == 3 set), row = {s16 id, s16 aux, f32 distance, f32 height,
// f32 lateral}, distance negative = behind the car (docs/re/camera.md 4). FOV index: [[0x7361bc]+0x27c] mover, +0x1c its
// view, s16 +0xc4 the POV code (as host/d3d9.c jumpcam_log reads it); the word at 0x6fbdf4 + 2*pov is 1/65536 of a turn
// per unit (0x32dc = 71.5 deg). Nitrous on: [0x73654c] (host/d3d9.c psblur_vel).
#include <math.h>
#include <string.h>
#include "host.h"

#define FEEL_MPS_PER_MPH 0.44704f
#define FEEL_60  (60.0f * FEEL_MPS_PER_MPH)    // 26.82 m/s
#define FEEL_100 (100.0f * FEEL_MPS_PER_MPH)   // 44.70 m/s

// The row this POV resolves to, as 0x47d680 does: first 16-byte row whose s16 id equals the POV code.
static uint32_t feel_row(Ctx *c, uint32_t info, int set, int pov) {
    if (!info || info >= GUEST_MEM - 0xc00) return 0;
    for (int i = 0; i < 5; i++) {
        uint32_t a = info + 0xb50 + (set ? 0x60 : 0x10) + 16 * i;
        if ((int16_t)ld(c, a, 2) == pov) return a;
    }
    return 0;
}

void feel_tel(Ctx *c) {
    static int on = -1, run, g60, g100;
    static uint32_t start, last;
    static float a60, a100;
    if (on < 0) on = getenv("RN_FEELLOG") != NULL;
    if (!on) return;
    uint32_t now = rn_telem.presents;
    uint32_t ctrl = ld(c, 0x77a920, 4) == 6 ? ld(c, 0x7361bc, 4) : 0;
    uint32_t car = ctrl && ctrl < GUEST_MEM - 0x1000 ? ld(c, ctrl + 4, 4) : 0;
    if (!car || car >= GUEST_MEM - 0x1000) { run = 0; return; }
    float sp = ldf(c, car + 0x3d4);
    if (!(sp >= 0) || sp > 200.0f) { run = 0; return; }        // a bad read (not a race car yet) is not a start
    if (sp < 0.3f) run = 0, g60 = g100 = 0, a60 = a100 = 0;    // standing: the next sample starts a run
    else if (!run) run = 1, start = now, g60 = g100 = 0, a60 = a100 = 0;
    else if (!g100) {
        float t = (float)(now - start) / 60.0f;
        if (!g60 && sp >= FEEL_60) g60 = 1, a60 = t;
        if (sp >= FEEL_100) g100 = 1, a100 = t;
        if (g100 || (g60 && t >= 20.0f)) {
            run = 0;
            if (g100) rn_log("FEEL A f%u 0-60 %.2f s 0-100 %.2f s (standing start f%u)", now, a60, a100, start);
            else rn_log("FEEL A f%u 0-60 %.2f s 0-100 no (still under 100 mph after 20 s, start f%u)", now, a60, start);
        }
    }
    if (now - last < 30) return;
    last = now;
    uint32_t mover = ld(c, ctrl + 0x27c, 4), view = mover && mover < GUEST_MEM - 0x40 ? ld(c, mover + 0x1c, 4) : 0;
    int pov = view && view < GUEST_MEM - 0x200 ? (int16_t)ld(c, view + 0xc4, 2) : -1;
    int set = ld(c, 0x7364a0, 4) == 3;
    uint32_t row = pov >= 0 ? feel_row(c, ld(c, car + 0xc, 4), set, pov) : 0;
    int word = pov >= 0 && pov < 16 ? (int16_t)ld(c, 0x6fbdf4 + 2 * pov, 2) : 0;
    rn_log("FEEL f%u sp %.2f m/s (%.0f mph) cam %u pov %d row %08x dist %.2f h %.2f fov %d (%.1f deg) nit %d set %d", now, sp,
           sp / FEEL_MPS_PER_MPH, ld(c, ctrl + 0x60, 4), pov, row, row ? ldf(c, row + 4) : 0.0f, row ? ldf(c, row + 8) : 0.0f,
           word, word * 360.0f / 65536.0f, ld(c, 0x73654c, 4) != 0, set);
}
