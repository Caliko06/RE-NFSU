// BRIDGE: night lights, OWNER 2026-10-27 (Block 7 part 1; RE in docs/night_re.md). RN_LIGHTS=0 (web/mode.js original) = as shipped.
// 1. Live brake lights: 0x56d8d0 lights a tail flare at [0x6b5da0] = 0.7 and adds 16 * brake ([car+0x1e4]) on top, clamped
//    to 1.0, so a brake only went 0.7 -> 1.0. The tail now rests at 0.35 and the brake still reaches 1.0 (flare size and
//    colour follow the intensity in 0x5443f0). Car type 3 keeps 0x6b5da4; 0x6b5da0 has no other reader.
// 2. Headlight: HeadlightColor (0.8, 0.8, 0.9) at 0x7010ac (read only by 0x4100a0) becomes a warm halogen white, and the
//    clip ramp (PATCH 0x40e6b5) keeps full light to ~73 m instead of ~48 m, fading out by ~98 m (the end of the texture:
//    u = depth * 0.005 + 0.5, texel i covers depth ((i + 0.5) / 64 - 0.5) * 200 m).
#include "host.h"

static int lights_on(void) {
    static int on = -1;
    if (on < 0) { const char *e = getenv("RN_LIGHTS"); on = !(e && e[0] == '0'); }
    return on;
}

void lights_init(Ctx *c) {
    st(c, SCREEN_ADDR + 0x64, host_addr_of("rn", "headlight_clip"), 4);
    if (!lights_on()) return;
    stf(c, 0x6b5da0, 0.35f);
    stf(c, 0x7010ac, 1.0f); stf(c, 0x7010b0, 0.94f); stf(c, 0x7010b4, 0.82f);
}

// 0x40e560's texels: 0..32 = 0 (behind and the first ~3 m), 33..47 = 255, 48..63 = 255 - 16 * (i - 48).
static uint32_t headlight_clip(Ctx *c) {
    uint32_t bits = ARG(0);
    if (lights_on() && bits)
        for (int i = 48; i < 64; i++) {
            uint32_t v = i < 56 ? 255 : 255 - 32 * (i - 55);
            st(c, bits + 4 * i, v > 255 ? 0 : v * 0x01010101u, 4);
        }
    return ld(c, 0x71abb4, 4);
}

const Api lights_apis[] = {{"rn", "headlight_clip", 1, headlight_clip}};
const int lights_api_count = 1;
