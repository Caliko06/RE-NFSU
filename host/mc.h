// Minecraft lane, front F-Speed (docs/re/mc_speed_exit.md): the player leaves the car in Free Run and walks.
// Remaster only: RN_MC=0 in original mode (web/mode.js RN_ORIGINAL_ENV) turns all of it off.
// One world frame: Speed.exe world units = metres (gravity 9.8 at 0x7000ac), z up (0x440a40 returns z).
#pragma once
#include <stdint.h>

typedef struct {
    int32_t on_foot;     // 1 while the player walks, 0 while he drives
    float pos[3];        // feet, world metres (z up), z = the game's ground query 0x440a40 when on_ground
    float heading;       // radians, facing direction = (cos, sin) in the world xy plane
    float vel[3];        // m/s, world
    int32_t on_ground;   // 1 when 0x440a40 found a surface under pos this frame
    uint32_t car;        // guest address of the parked player car (0 while driving)
    float pitch;         // camera pitch from the mouse, radians, + = look up
    int32_t walked;      // 1 once the pedestrian moved since leaving the car (log only)
    float view[16];      // scene view of this frame (D3D row vectors: v_cam = v_world * view), copied at the render hook
    float proj[16];      // scene projection of this frame (row vectors, D3D left-handed z 0..1)
    int32_t track;       // after proj (offsets above stay): the race's track id [0x78a2f0] on race frames, 0 outside a race; 1010 = WORLD (web/ug2/ug2world.js draws the UG2 city only then)
} McPed;

extern McPed rn_mc;      // wasm address: rn_mc_state() (host/mc.c)

typedef struct Ctx Ctx;
int mc_enabled(void);                  // RN_MC switch (remaster on, original off)
int mc_key(uint8_t dik, int down);     // host/input.c key_event: 1 = the key is ours, the game must not see it
int mc_mouse(int32_t dx, int32_t dy);  // host/input.c input_poll: 1 = the motion is ours
void mc_frame(Ctx *c);
void input_release_game(void);         // host/input.c: every key the game holds goes up
void dinput8_mouse_mode(void);         // host/dinput8.c: the pointer mode back to what the game's mouse asks for                 // once per game frame (host/d3d9.c Present): walk, ground, enter/exit
// Render hook (host/d3d9.c, the first HUD quad of a race frame: the 3D pass is done, the scene depth is bound).
// It fills rn_mc.view/proj and draws the actor at rn_mc.pos/heading. F-Max replaces mc_draw_actor's body.
void mc_draw_actor(Ctx *c, const McPed *p);
// host/d3d9.c: draw ntri world-space triangles (xyz, 9 floats each) in one colour (0xAARRGGBB) with rn_mc.view * rn_mc.proj,
// depth test and depth write on, no cull, no blend, into the scene's colour and depth. Only valid inside mc_draw_actor.
void d3d9_draw_tris(Ctx *c, const float *xyz, uint32_t ntri, uint32_t argb);
