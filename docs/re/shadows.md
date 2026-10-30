# Car shadows: what the game does, and the plan for real ones (2026-10-30)

Tools: G = Ghidra export `census/ghidra/decomp_0x54c000_0x5f1800.c` (read this session), C = capstone `tools/recomp/asm.py dis`, D = bytes of the
unpatched exe read with python struct, H = our host/web code read. Names that come from earlier notes: `census/names_render_w2.tsv`.
Not run: the game does not run in the pod yet, so every runtime statement below is open (U) until the Mac checks it.

## 1. What the game draws today (V, G+D)

The shadow is part of the big car draw `0x56dc30` (called from `0x570947`, `0x571017`, `0x57119a`). It is **one projected ground patch per car, not a
shadow map**:

1. Gate (G, around the call of `0x56d700`): not a reflection draw (`param_9 == 0`), LOD below 3, option `[0x700e7c] > 1` (the SHADOW setting,
   default **2** in the exe image, D), `[0x6f1ac8] != 0` (1 in the image), the car has a render-info `+0x3c` and `+0x12e` flag, and `0x56d8b0` says OK.
2. `0x56d700` (`CarShadow_SunVector`) makes the direction. Sun object `[0x735518]` is one record of the array `[0x735510]` (stride 0x110, count
   `[0x735514]`, found by id in `+4` by `0x546310`); its position is at `+0x2c, +0x30, +0x34`. With no record the sun is (-16384, 0, 7000) (`[0x6ccbe8]`).
   Vector = car position minus sun position. The elevation is clamped: if the angle is below `0x1a90` (37.4 degrees, 65536 = 360) it is replaced by that
   angle (`0x564bd0` gives the sine and cosine). Result in `0x73c670/0x73c674` = ground offset per metre of height (x, y); `[0x7306b4]` = 1/z.
   So the default light is the same everywhere, from -x (the shadow falls toward +x), at 37.4 degrees at least. (U: whether any track has a sun record
   with another position; the loader of that array was not read.)
3. Outline: for each point of the car's shadow shape (`vtable+0xc` of the shape at `render-info+0x3c`, count in `+0x14`, via `0x540ae0/0x540990`)
   the ground height is read (`0x440a40`) and the point is moved along the sun vector by its height above the ground. Points go to `0x73c260`
   (16 bytes each). `0x56cf10` (`CarShadow_BuildOutline`) takes the convex hull (`0x56ce10`), puts the ground height + `[0x6b5dd0]` = 0.06 m on every point
   (`0x73c680`) and makes a fan of soft edge quads (blur width `[0x6b5e08]` = 0.333 of the offset).
4. Draw: vertices go through `0x410940/0x410910/0x4108d0` (position, UV, colour) with colour `0x808080 | alpha << 24`, alpha 0..254. The patch scale lerps
   between `[0x6b5d78]` = 1.4 and `[0x6b5d74]` = 1.1 by the car's height above the ground (smoothstep 0 to 3 m, `[0x6b5d80]`, `[0x6b5d84]`), so a jumping car
   gets a smaller, fainter shadow. The texture is the car's SHADOWIG (in game, `%s_SHADOWIG`, string `0x6bbd14`, built in `0x56a130`) or SHADOWFE in the
   front end. Draw call in the D3D layer: a normal textured, alpha-blended triangle list on the ground (U: exact render states).
5. Other shadows: none found (props and buildings have no shadow; the road gets only this patch).

Consequences: the shadow is a flat decal the shape of the car's hull, always the same direction, no shadow on the car itself, none on walls or other cars,
none from props.

## 2. Design of real shadows (not built yet)

Goal: cars (and near objects) cast onto the road and onto each other and themselves, with `?shadows=0` giving the game's decal exactly as now.

Fits the existing path: `host/d3d9.c` turns every draw into a command, `web/gpu.js` replays them with WebGPU; shaders are WGSL made by `host/sm1.c`.

1. **Light.** One directional light. Direction from the game: take the same vector as `0x56d700` (read `[0x735518]` +0x2c..0x34 from `host/d3d9.c`
   each frame, same default and same 37.4 degree clamp) so the real shadow agrees with the decal direction and with the car lighting. (I: check against
   the car.efx light direction already used by the car look pack.)
2. **Caster list.** In `host/d3d9.c` mark the draws of cars (the car shaders are already recognised for the car look pack, `host/sm1.c`) and keep, per frame,
   their draw commands with the world matrix (vertex shader constants). Only cars within ~60 m of the camera.
3. **Depth pass.** In `web/gpu.js` before the main world draws are submitted: render the marked car draws again into a depth-only `depth32float`
   texture (map size per quality: 1024 / 2048 / 4096), with a light view-projection fitted to the player car and the nearest cars (orthographic box,
   texel-snapped to avoid shimmer). Depth-only pipeline, same vertex layouts, a small vertex shader that applies the stored world matrix and the light matrix.
4. **Apply as a screen pass, not in every material.** After the world and cars are drawn, a full-screen pass reads the scene depth buffer, rebuilds the
   world position (inverse view-projection from the projection block `+0x40` the code already reads for the speed blur, `host/d3d9.c`), looks the position
   up in the shadow map (3x3 PCF with `textureSampleCompare`), and darkens the colour by `1 - k * shadow` with `k` about 0.45 (a road stays dry, not mirrored:
   AGENTS rule). Same place as the existing post passes (`bloom`, `psblur`, `fxaa`). This avoids rewriting the WGSL of every world material.
5. **The game decal** is turned off when real shadows are on (skip the decal draw by its SHADOWIG texture id), otherwise two shadows add up.
6. **Switch and quality:** `?shadows=0|1`, default on in Remaster, off in Original (`web/mode.js` RN_ORIGINAL), `?shadowres=1024|2048|4096`.
   Exit rule: when the A/B is decided, the losing path and the switch are deleted in the same commit.

## 3. Cost and what is open

- Extra GPU work: one more geometry pass of the cars (a few thousand triangles each, depth only) plus one full-screen pass. Budget on the Mac M-series:
  gate60 p50 <= 16.7 ms with every effect on. Not measured. Measure with the gpu.js timestamp queries (`ts` in the frame log) on the 4090 first, then ask
  the Mac; resolution is the quality knob.
- Open (U): (a) render states of the game decal; (b) whether any track defines its own sun record (loader of `[0x735510]`); (c) how to know the
  scene depth buffer is the one of the main view in `gpu.js` (the speed-blur pass already reads it: reuse that plumbing); (d) car draws that use skinned or
  instanced vertices; (e) interaction with the planar road reflection (`roadrefl`).
- Needs from the visual lane: the A/B bank in `tools/` (same scene, shadows 0 and 1), as the orchestrator asked.
- Next step when the game runs: log, from `host/d3d9.c`, the draw that carries SHADOWIG (render states, vertex count) and `[0x735518]` per track; then build step 2.

## 4. Runtime results and what was built (2026-10-30, pod 4090, `tools/abbench.py`, Quick Race 1003 grid, frame 300)

Measured with `RN_DRAWLOG=40` (new, test-only: every draw of each 40th frame) and `RN_POKE` of `[0x700e7c]` to 0, diff of the draw lists:

- **Decal draws (answers U (a)):** only with the option on: triangle strips (type 5), stride 24 (position, colour, UV), alpha blend SRCALPHA / INVSRCALPHA,
  depth test on, depth write off, cull on, one texture (SHADOWIG). Per car about 20 two-triangle strips plus 3 fans of 28 to 38 vertices; 6 cars on the grid.
- **Sun record exists per track (answers U (b)):** `[0x735518]` is set in Quick Race 1003: position (-3900, 650, 1300), not the (-16384, 0, 7000) default. From the
  grid car it is 18 degrees up, below the 37.35 degree floor, so the elevation is 37.35 and the light direction is D = (0.793, -0.054, -0.607). Other tracks
  were not logged (`RN_SHADOWLOG=1` logs it each 120 frames).
- 0x56d700 runs only inside the decal gate, so with the decal off `0x73c670..` stay 0: `host/d3d9.c shadow_data` repeats its maths (`atan2(-z, horizontal)`,
  floor `0x1a90`; `0x564db0(x, y)` is atan2 with y second, checked in the decompile).

Built (touches host/d3d9.c, tools/recomp/patches.py, web/gpu.js, web/tune.js, web/mode.js):

- `PATCH 0x56e493`: the SHADOW compare of `0x56dc30` reads `SCREEN_ADDR+0x98`; the host writes the option there, or 0 while `?shadows=1`. The other option readers
  (flares) keep `[0x700e7c]`.
- `host/d3d9.c shadow_data` sends View, Projection (camera block `[0x7404c0]`), D and the player's car in the GPU_FXAA words 8..47. The car vertex shader is marked
  (bit 1 of the shader kind).
- `web/gpu.js shadows()`: keeps the scene's car body draws, redraws them depth-only into a `depth32float` map (orthographic, 64 m wide, texel-snapped) with
  the clip matrix columns c10..c13 multiplied by (View Proj)^-1 * LightViewProj, then a full-screen pass rebuilds light-space positions from the scene depth, 3x3 PCF,
  alpha 0.5 black. `?shadows=0` = the game's decal (the old path, untouched), `?shadowres=1024|2048|4096`, `?shadowk=` strength, `?shadowbias=`.
- GPU cost on the 4090 (abbench p50 per pass, 1080p, 6 cars, change against ?shadows=0): shadow map 0.04 / 0.05 / 0.13 ms at 1024 / 2048 / 4096, apply 0.05 ms; the
  decal's own draws leave (draw 1080p -0.12 ms), so the net is about zero. The Mac M-series is not measured.
- Seen: shadows fall to the right of the grid cars on the road and on the next car's side; no shimmer test yet (grid frame only).

Open: moving shadows while driving (texel snapping untested), props and walls do not cast, headlight/night look (the light is the game's sun), cars far
from the player are outside the 64 m box, and the apply pass also darkens the casting car itself a little (bias 0.0012).

After the merge with the visual post (AO, grade, bloom, FXAA; 2026-10-30): the shadow pass runs first at GPU_FXAA (words 10..49 of the command, after the psblur and AO words), so AO, bloom and the grade work on the
shadowed colour. The PCF is 5x5 with 2 texels between taps at 2048 (an edge about 25 cm soft, not a hard filter); apply pass +0.11 ms, map +0.05 ms at 2048 on the 4090.
