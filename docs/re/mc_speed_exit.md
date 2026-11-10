# Leaving the car in Free Run (front F-Speed)

Remaster only: `RN_MC=0` in original mode (`web/mode.js` RN_ORIGINAL_ENV). Marks: FACT = read in code with a second tool,
INFERENCE, UNKNOWN. Tools: H = `census/hopper/decomp.c`, C = capstone `tools/recomp/asm.py dis`, D = bytes of `pc/Speed.exe`.

## Interface (for F-Max)

### Pedestrian state
- Host C struct `McPed rn_mc` (`host/mc.h`), in wasm memory; its address is `rn_mc_state()` (EMSCRIPTEN_KEEPALIVE, `host/mc.c`).
- Fields: `on_foot` (i32), `pos[3]` (feet, world metres), `heading` (radians, facing = (cos, sin) in world xy), `vel[3]` (m/s),
  `on_ground` (i32), `car` (guest address of the parked car), `pitch` (camera, radians), `view[16]`, `proj[16]` (this frame's scene matrices).

### Units and axes
- Metres and seconds. FACT: gravity 9.8 at `0x7000ac` (D), used at `0x4638f5`, `0x456943`, `0x44e96f`, `0x429d44` (C);
  `0x6cc9f0` = 2.237 (mph per m/s) multiplies car speed `car+0x3d4` at `0x4286d0` (C).
- Z is up. FACT: `0x440a40` returns the plane height in z (`(d - nx*x - ny*y) / nz`, plane at body+0x70..0x7c), the car's z
  `car+0x68` is compared to it (`docs/re/ai_drops.md`), and gravity acts on index 2.
- Handedness: world right-handed z up (INFERENCE, `docs/re/physics.md:31`); the projection is D3D style, z_ndc = _33 + _43 / z_view (FACT, `host/d3d9.c` psblur_vel).
- Matrices: view block `blk = [0x7404c0]` (player view = `0x740460 + 0x60`, +0): floats 0..15 = view (D3D row vectors,
  v_cam = v_world * view), 16..31 = projection (FACT, `host/d3d9.c` psblur_vel).

### Render hook
- Where: `host/d3d9.c`, at the first HUD quad of a race frame (the line that sends `GPU_FXAA`): the 3D pass is over and the
  scene depth is still the bound depth. It copies view and projection into `rn_mc.view/proj`, then calls `mc_draw_actor`.
- Signature F-Max implements: `void mc_draw_actor(Ctx *c, const McPed *p)` (`host/mc.c`; today it draws a debug marker).
- Helper available there: `void d3d9_draw_tris(Ctx *c, const float *xyz, uint32_t ntri, uint32_t argb)`: world-space triangles
  with view * proj, depth test and write on, no cull. A skinned mesh needs its own shader and vertex format through the same
  `draw_cmd` record path (`host/d3d9.c`), or a GPU_* command replayed in `web/gpu.js`.

### Ground query
- `float 0x440a40(cache, const float xyz[3], int *surface_out, float normal_out[3], uint8_t *hit_out)`, stdcall, `ret 0x14`,
  result in ST0 (FACT, C+H). Pass 1: the highest surface at or below z + 1.0 (`0x6cc7bc`); pass 2: the top of the column.
  On a miss: hit = 0, result = the input z, normal (0, 0, -1), surface 1. Any out pointer may be 0.
- Cache: 0x2b4 bytes (box +0..0xf, loaded box +0x10, 160 body pointers +0x20, counts +0x2a0, last hit +0x2b0). FACT: 0x440a40 refills
  it itself when xy leaves the box (`0x440b02..0x440b0c`: `0x4407b0(xy, 8.0, 0)`, edi = cache). The pedestrian owns a private
  cache (`guest_alloc` + clear `0x440740`, eax = cache), never the car's `car+0x540`.
- `0x440ce0` (eax = xy, stack = cache, `ret 4`): z = 99999.1, returns only the hit flag in al.
- Cost: one box query of up to 160 polygons per refill (about once per 8 m walked), then up to 160 point-in-triangle tests (INFERENCE, not timed).
- Host call: `mc_ground` in `host/mc.c` (saves and restores the x87 state, as `host/aitel.c` rst_ground).

### Camera
- `Camera::SetCameraMatrix 0x47d070(camera, const float m[16], float dt)`, stdcall `ret 0xc` (FACT, C+H). It copies m to camera+0..0x3f
  (the D3D view, world to camera, row vectors; right, up, forward in columns 0..2), derives the eye +0x40, forward +0x50 and the eye
  velocity +0x1e0 = (eye - previous eye) / dt; cut byte +0x270 = 1 makes that velocity 0.
- Every mover of every view runs from `0x48e8b0` (no args), called by the main loop at `0x4479be`, before `RenderFrame 0x40a580` at
  `0x447a10` (FACT, C). `RenderFrame` copies camera+0..0x3f into the view block (`0x40dd00`), and the world queue reads the eye +0x40.
- PATCH 0x4479be (`tools/recomp/patches_mc.py`, cave 0x797600 -> `[SCREEN_ADDR+0xc8]`) = `host/mc.c` mc_views: the original call, then while on foot
  `0x47d070` again on the player camera `[0x740500]` (= 0x78d270) with the third-person matrix (4 m behind, eye 0.6 m above the head).
- FACT (run 3 log): the game's camera up column has world z = -1.0 (det +1), so the matrix copies the game's roll and handedness.

### Car input and Free Run
- Player input object P = `[[car+0x2c]+8]` (human driver ctor 0x59bfc0 -> 0x460e70; AI cars have none). Inputs: steer +0x28c (0x461840),
  gas +0x294 (0x4618b0), brake +0x29c (0x461da0), ebrake +0x2ac (0x461e10); `0x461a60` turns them into the physics outputs (FACT, C).
  On foot, host writes 0, 0, 0 and ebrake 1.0 each frame; all keys except F and Esc go to the pedestrian, not to the game.
- Free Run: `[0x777cc8] == 3` (StartRaceByMode 0x4b5c00 jump table 0x4b5d04, case 3 calls 0x4b5090) and `byte [0x78a347] == 0` (not career).
- Player car: the entry of `[0x7361f8]` whose `[[r+0x14]+4] == 1`; position +0x60..0x68, velocity +0x70..0x78, forward +0x90..0x98,
  heading word +0x3b4 (65536 = 360 deg, 0 = +x toward +y) (FACT, C).

## Controls (Remaster, Free Run)
F leaves the car (the pedestrian appears 1.6 m left of the car) and gets back in within 3.5 m. W/S forward and back, A/D sideways,
Shift runs (7 m/s, else 4 m/s), mouse turns and pitches (pointer lock on the first click).

## Evidence (slice/mc-speed)
- Run 1, `webcheck --route` on :5183: ROUTE PASS (exit 0), `web/plan/shots/mc_speed_route.png`.
- Run 3, Free Run 1001 in Remaster: out at frame 4029, walked 12.1 m along the car heading and back to 1.6 m, ground hit 1, F back in;
  `web/plan/shots/mc_speed_out.png`, `mc_speed_walk.png` (12 m down the road), `mc_speed_in.png` (back in, chase camera).
- Run 2 (before the roll fix) showed the view upside down: the reason for the up-column test.
- Not verified: mouse look, steps and falls (the road was flat), Esc/pause on foot, Original mode in Free Run, sloped ground.
