// Feel probe (RN_FEELLOG, off by default), docs/re/feel_probe_fix.md: the numbers behind the OWNER's four complaints, so a
// patch is flipped against a measurement and not a hunch. Log lines only, nothing is written to the game.
//   FEEL, every 30 frames: the camera mover object and its mode, the POV code it is using, the chase row that POV resolves to
//        in the car's CarTypeInfo (distance, height), the FOV word the projection actually got and the table word of that POV,
//        both in degrees, plus the player's speed and nitrous.
//   FEEL A, once per real standing start: the time to 60 and to 100 mph, counted on the Present clock (60 per second, the
//        limiter is 1:1: docs/re/feel_2026-10-31.md 5). A start needs the car under 1 m/s for 30 frames and then moving; a
//        car change, a stop or a speed jump of 8 m/s in one frame throws the run away (runs/w_d_a logged 0.02 s starts when
//        the car pointer under it changed every frame).
//
// What each field reads (all verified in Speed.exe, see the doc for the addresses):
//   mover  [ctrl+0x27c], ctrl = [0x7361bc] while [0x77a920] == 6. The camera object 0x48bcb0 updates; mover+0x2c is the car
//          it drives (0x48bd19) and mover+0x1c is the view it writes.
//   pov    (s16)[mover+0x40]. 0x48bf43 feeds it to FindCameraRow 0x47d680, which walks the car's rows matching this s16.
//   row    FindCameraRow: base [[car+0xc]+0xb50], count at +4 and rows at +0x60 when [0x7364a0] == 3, else count at +0 and
//          rows at +0x10 (0x47d680). Row = {s16 id, s16 aux, f32 distance, f32 height, f32 lateral}; 0x48b8c0 reads distance at
//          +4 and height at +8 (0x48ba2a), distance negative = behind the car (docs/re/camera.md 4).
//   fov    the word 0x485ff1 writes into view+0xc4, i.e. the angle the projection was built with, 1/65536 of a turn per
//          unit (0x32dc = 71.5 deg). tab = the entry of the POV in 0x6fbdf4, the same table 0x480750 indexes with the row id.
//   speed  car+0x3d4 m/s (the HUD's own unit; 0x6cc9f0 x 2.237 = mph). Nitrous on: [0x73654c].
#include <math.h>
#include <string.h>
#include "host.h"

#define FEEL_MPS_PER_MPH 0.44704f
#define FEEL_60  (60.0f * FEEL_MPS_PER_MPH)    // 26.82 m/s
#define FEEL_100 (100.0f * FEEL_MPS_PER_MPH)   // 44.70 m/s

// FindCameraRow 0x47d680: the row whose s16 id is this POV, in the row set [0x7364a0] selects.
static uint32_t feel_row(Ctx *c, uint32_t info, int pov) {
    if (!info || info >= GUEST_MEM - 0xc00) return 0;
    uint32_t base = info + 0xb50;
    int set2 = ld(c, 0x7364a0, 4) == 3;
    int n = (int)ld(c, base + (set2 ? 4 : 0), 4);
    if (n <= 0 || n > 8) return 0;
    for (int i = 0; i < n; i++) {
        uint32_t a = base + (set2 ? 0x60 : 0x10) + 16 * i;
        if ((int16_t)ld(c, a, 2) == pov) return a;
    }
    return 0;
}

void feel_tel(Ctx *c) {
    static int on = -1, ready, run, g60, g100;
    static uint32_t still, start, prev_car, last;
    static float a60, a100, prev_sp;
    if (on < 0) on = getenv("RN_FEELLOG") != NULL;
    if (!on) return;
    uint32_t now = rn_telem.presents;
    uint32_t ctrl = ld(c, 0x77a920, 4) == 6 ? ld(c, 0x7361bc, 4) : 0;
    uint32_t mover = ctrl && ctrl < GUEST_MEM - 0x1000 ? ld(c, ctrl + 0x27c, 4) : 0;
    if (mover >= GUEST_MEM - 0x400) mover = 0;
    uint32_t car = mover ? ld(c, mover + 0x2c, 4) : 0;              // the car the camera drives (0x48bd19)
    if (!car || car >= GUEST_MEM - 0x1000) car = ctrl && ctrl < GUEST_MEM - 0x1000 ? ld(c, ctrl + 4, 4) : 0;
    if (!car || car >= GUEST_MEM - 0x1000) { still = ready = run = 0; return; }
    float sp = ldf(c, car + 0x3d4);

    // ---- standing start: 30 frames under 1 m/s arm a run, the first frame at or over 1 m/s starts the clock ----
    if (car != prev_car) { prev_car = car; still = ready = run = 0; }     // another car (reset, next race, a rival's pointer)
    if (!(sp >= 0) || sp > 200.0f) { still = ready = run = 0; return; }   // a bad read is not a start
    if (sp < 1.0f) {
        if (still < 31) still++;
        if (still >= 30) ready = 1;
        run = 0, g60 = g100 = 0, a60 = a100 = 0;
    } else if (ready && !run) {
        still = 0, run = 1, start = now, g60 = g100 = 0, a60 = a100 = 0, prev_sp = sp;
    } else if (run) {
        still = 0;
        float t = (float)(now - start) / 60.0f;
        if (sp - prev_sp > 8.0f) { run = 0, ready = 0, still = 0; }       // teleport, reset or the pool handed the slot on
        else {
            if (!g60 && sp >= FEEL_60) g60 = 1, a60 = t;
            if (sp >= FEEL_100) g100 = 1, a100 = t;
            if (g100 || (g60 && t >= 20.0f)) {
                run = 0, ready = 0;                                       // a moving car is not a standing start again
                if (g100) rn_log("FEEL A f%u 0-60 %.2f s 0-100 %.2f s (start f%u)", now, a60, a100, start);
                else rn_log("FEEL A f%u 0-60 %.2f s 0-100 no (still under 100 mph after 20 s, start f%u)", now, a60, start);
            }
        }
        prev_sp = sp;
    }
    if (now - last < 30) return;
    last = now;

    // ---- camera: the mover, its POV code and the row that POV resolves to ----
    uint32_t view = mover ? ld(c, mover + 0x1c, 4) : 0;
    if (view >= GUEST_MEM - 0x200) view = 0;
    int pov = mover ? (int16_t)ld(c, mover + 0x40, 2) : -1;
    if (pov < 0 || pov > 7) pov = -1;
    uint32_t row = pov >= 0 ? feel_row(c, ld(c, car + 0xc, 4), pov) : 0;   // 0x48bf4e: info+0xb50 then FindCameraRow
    int live = view ? (int16_t)ld(c, view + 0xc4, 2) : 0;                  // 0x485ff1: what the projection got
    int tab = pov >= 0 ? (int16_t)ld(c, 0x6fbdf4 + 2 * pov, 2) : 0;        // 0x480750: table[POV]
    rn_log("FEEL f%u sp %.2f m/s (%.0f mph) mode %u mover %08x pov %d row %08x dist %.2f h %.2f fov %d (%.1f deg) tab %d (%.1f deg) nit %d set %d",
           now, sp, sp / FEEL_MPS_PER_MPH, ld(c, ctrl + 0x60, 4), mover, pov, row, row ? ldf(c, row + 4) : 0.0f,
           row ? ldf(c, row + 8) : 0.0f, live, live * 360.0f / 65536.0f, tab, tab * 360.0f / 65536.0f,
           ld(c, 0x73654c, 4) != 0, ld(c, 0x7364a0, 4) == 3);
}
