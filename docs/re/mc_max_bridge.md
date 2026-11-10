# Max Payne character in the NFSU frame: bridge (F-Max, 2026-11-09)

Choice: run the stock Max Payne guest (`~/maxpayne-re` b28fb1a, its wasm loaded at runtime, not rebuilt) beside Speed in the same page, with its own module and memory, in a level with no AI; it keeps animating the player (skin, walk/run resolver 0x53e770, root motion) from the same input.
Why: no reader for .kfs/.skd/.kf2 exists outside the Max guest (grep of maxpayne-re tools/web/host), so "load the data and play it" means writing a new animation runtime; the guest already does it, and mc_seam.md S3 shows its packets can be read on another GPUDevice.
Draw: an imported, namespaced copy of Max's packet reader (`web/maxpayne/`) runs on NFSU's GPUDevice, creates Max's textures and shaders, drops every Max draw except the player's (object near the player, small bounds), and encodes those into NFSU's scene color and depth before the HUD; Max's own screen is never shown, its packets are acknowledged.
Frame: per player draw, body-local = W_max * B_max^-1 (B = player matrix from Max gamestate, words 6-17), then * C (Max to Speed units and axes, below) * Place (pedestrian position on 0x440a40 and heading, from F-Speed) * V_nfsu * P_nfsu; Max's own collision and camera are ignored, the pedestrian state owns position and ground.
Not chosen: rebuilding Max's wasm with host hooks (needs Max's recompile and its 16 GB build in parallel with F-Speed), two canvases (no shared depth), writing a kf2/skin player (rewrites the runtime).

## Units (Max level units -> Speed units)

| quantity | Max | Speed | conversion | evidence | status |
|---|---|---|---|---|---|
| length unit | metre: capsule top 1.95, run 4.2 | metre: g = 9.8, speed in m/s | s = 1.0 | Max: rea/map/look_move.md:64,74; player.md:12 walk 3.97 units in 0.9 s (4.4 u/s vs 4.2 data, +5 %, root-motion start-up). Speed: `[0x7000ac]` bytes = 9.8f, read at 0x4638a0 as `-(9.8 * z of the normalized path direction)` and at 0x44e950 as `9.8 * mass(+0x110)` in the drag-gravity term; `[0x6cc9f0]` = 2.237f (m/s to mph) times car speed `+0x3d4`/`+0x390` (census/ghidra decomp_0x401000_0x4a6800.c:31083, 37210); street 11 m wide (docs/re/spike_1846.md:9); 0-60 mph logged at 3.1-3.3 s (docs/re/accel.md:71) | Speed FACT (bytes + code). Max INFERENCE (capsule and speed data, one measured walk). s = 1 within ~5 %. No km/h (3.6) factor found: HUD factor is mph only |
| up axis | +Y (row 1 = up) | +Z (height) | Y -> z | Max: player.md:12-14. Speed: 0x440a40 computes ground z = `-((n.y*p.y + n.x*p.x - d) / n.z)` from the plane at body `+0x70/+0x74/+0x78/+0x7c` (decomp.c:101836, first branch); 0x4638a0 uses the z component as slope; BODY log prints z at `+0x58` (host/free.c:703) | FACT both |
| handedness | left-handed: D3D8 row vectors, right = +X, up = +Y, forward = +Z | right-handed: x to y is counter-clockwise seen from +z | mirror, det(C) = -1 | Max: player.md:12-13 forward = row 2 (dot 1.000); mouse right (+200 counts) raised yaw = atan2(row2.x,row2.z) by +1.2548 (player.md:14), so +X is right when forward is +Z. Speed: lateral offset L is applied as `L*(hy,-hx)` at 0x4422b0 (decomp.c:104102) and the doc calls it the right of the heading (docs/openworld/re_answers_0b.md:362); Atan2ToAngle16 0x564db0 = atan2(y,x) (below) | Max INFERENCE (mouse sign assumed standard). Speed INFERENCE, one source (the "right" label needs right-hand traffic). UNKNOWN: no cross product building a car or camera basis was found. A proof is the sign of `det[right; up; forward]` of the Speed chase camera matrix, or whether +steer/+yaw rate (body `+0xc8`) turns the car left on screen |
| heading zero and sense | yaw 0 = forward +Z; yaw = atan2(row2.x, row2.z); positive turns toward +X, i.e. to the right | heading 0 = +X, forward = (cos h, sin h); positive turns toward +Y, i.e. counter-clockwise, to the left | h = -yaw | Max: player.md:12-13. Speed: 0x464ed0 slip = (`+0x374` heading - Atan2ToAngle16(vel.x `+0x30`, vel.y `+0x34`)) x `[0x6cc980]` (ghidra decomp_0x401000_0x4a6800.c:71700-71722, docs/re/physics.md:29); 0x564db0 returns 0 for +x, 0x4000 for +y, -0x8000 for -x (ghidra decomp_0x54c000_0x5f1800.c:16429 with 0x564cd0 asin-like returning 0x4000 at ratio 1) | Speed FACT (heading = velocity direction at zero slip). Max sense INFERENCE (same one-sample basis as player.md:13) |
| angle16 to radians | float radians (Max uses 0.017453292 x degrees at 0x7cfb04) | 65536 = one turn; quarter = 0x4000 | rad = angle16 x 2pi/65536 = angle16 x 9.5873799e-5 | bytes: `[0x6cc980]` = 9.58738e-5, `[0x6cca4c]` = 10430.378 (65536/2pi), `[0x6cc978]` = 6.28318, `[0x6cc97c]` = 3.14159; 0x464ed0 wraps the product above pi by subtracting 2pi | Speed FACT. Max 0x7cfb04 value from look_move.md:36 only (one source) |

Final matrix (row vectors, `v_speed = s * v_max * C`, s = 1.0), Max (x right, y up, z forward) to Speed (x forward at h = 0, y left, z up):
`C = [[0,-1,0],[0,0,1],[1,0,0]]`, so Max (x,y,z) -> Speed (z, -x, y). det(C) = -1 (handedness differs: it is a mirror, so triangle winding flips when meshes pass through C).
Heading: `h_speed = h0 - yaw_max` in radians (`angle16 = round((h0 - yaw_max) * 10430.378)`), where h0 is the Speed heading the body faces when Max yaw is 0; with body-local = W * B^-1 the Max yaw is cancelled and h0 is the pedestrian heading from F-Speed.
Worked check: Max forward (0,0,1) at yaw 0 -> (1,0,0) = Speed heading 0 = angle16 0x0000; Max right (1,0,0) -> (0,-1,0) = the right of heading 0 (Speed right normal is (hy,-hx)); Max up (0,1,0) -> (0,0,1). Max forward at yaw +90 deg (1,0,0) -> (0,-1,0) = heading -90 deg = angle16 0xC000.

## Status after 3 runs (2026-11-09, slice/mc-import)

What is in git: web/maxpayne/boot.js, frame.js, gpu.js (Max's own web JS from maxpayne-re b28fb1a, adapted), /mp/ routes in
tools/serve.py, one F-Max call site each in web/boot.js and web/gpu.js, rn_mem_mb(3) = guest base in host/win32.c.
Loaded locally at runtime, never in git: ~/maxpayne-re/web/out/maxpayne.{js,wasm} (/mp/out/), ~/maxpayne-re/build/img
(/mp/img/), the Max game folder RN_MAX_GAME, default ~/Games/maxpayne (/mp/game/). Enable: remaster mode and ?max=1.

| run | result | shot |
|---|---|---|
| 1 | Free Run ran, no Max line in the page log (logs went to console.log) | web/plan/shots/mc_max_run1.png |
| 2 | Max booted in the NFSU page, RN_JUMP done at frame 140, mode 3; reader stopped: `curPipe is not defined` (copy lost Max's pass state) | none kept |
| 3 | no stop: Max loaded startup_level then part0_level1 by itself; 5,609 packets, 509,672 draws read on NFSU's device; Speed frame read (scene=drawing); **kept=0**, nothing drawn | web/plan/shots/mc_max_run3.png |

Open: why kept=0. The GM chain is right (Max host/gamestate.c:378-379) and the player flag is GSF_PLAYER = 2. Left: (a) the
software-skinned vertices are already in world space with W = identity (P_D3DSkinMesh, mc_max.md M4), so W's translation is
not the player position; (b) camera+0x8c is not the view used for those draws; (c) part0_level1 starts in a scripted part.
The status line now prints rejected noPlayer/notXyz/far/big and the nearest distance, so the next run names the cause.
Next patch: if `far` dominates, take the draws whose vertex bounds centre (through W) is within 1.5 m of the player, and use
body-local = W * B^-1 unchanged; also enter a level with a free-roaming start (RN_JUMP c_teleport) instead of startup_level.

## Contract with F-Speed (../mc-speed docs/re/mc_speed_exit.md "Interface", commit 319cdca), read 2026-11-09

F-Max reads `McPed` (on_foot +0, pos +4, heading +16, view +48, proj +112) in web/maxpayne/frame.js pedFrame: the body stands on
`pos` (feet, z from 0x440a40), faces `heading`, and is drawn with McPed view/proj; while driving nothing is drawn. Disagreements:
1. Draw site. F-Speed: host C `mc_draw_actor(Ctx*, const McPed*)` records into NFSU's list at the GPU_FXAA line ("F-Max replaces
   its body"). F-Max: Max's packets live in the page, so the draw is page-side, `MaxChar.scene` in web/gpu.js at the same
   GPU_FXAA command (same boundary, depth still bound). At the merge `mc_draw_actor` must stop drawing its debug box when ?max=1
   (or be emptied), otherwise box and character overlap.
2. Export. `rn_mc_state()` is plain C in ../mc-speed host/mc.c:14, with no EMSCRIPTEN_KEEPALIVE and not in build.py
   EXPORTED_FUNCTIONS, so the page cannot call it. The merge must add `_rn_mc_state` to that list; until then pedFrame sees no
   export and the body stands 3 m right of the car.
3. Keys. F-Speed sends all keys except F and Esc to the pedestrian (host side). F-Max forwards W/A/S/D/Shift/arrows from the page
   to Max's ring while on_foot, so both see the same keys: the pedestrian moves the body, Max plays the matching walk/run.
   Max's own root motion is not fed back into McPed (speeds may differ: Max run 4.2 m/s, F-Speed's walk speed is its own).

## Block 2 (runs 4-5)

- Skin space (FACT, Max code): 0x57d510:276-298 copies each bone's object-to-world (+0x5c), :300-345 multiplies by object 0's
  4x3 at +0x8c (world-to-object), setupPass 0x10415ef0:210-212 sets WORLD = the object's +0x5c. So skinned vertices are in the
  root object's space and W is its object-to-world; "world space with W = identity" was wrong.
- Run 4: every draw rejected as noPlayer: the view read from guest memory (GM+0x1074 camera, +0x8c) never gave a player frame.
  Replaced, not fixed: V = the WV most draws of a packet share (static level geometry). Run 5: viewN 45-128, W of the kept draws
  within 0.05-0.4 m of Max's gamestate position, kept 73,540 draws; the body draws in Free Run (web/plan/shots/mc_max_run5.png).
- Open: (1) pieces of Max's level near the player pass the filter (a tall panel and floor bits in run5.png). Next patch: keep
  only draws whose W equals the body's W (one skinned object) plus the weapon's. (2) Walking not shown: keys reach Max's ring
  (keys=4), but maxspeed stayed 0 and part0_level1 was in scripted parts (mode 2, control 1); Max's position changed once
  (z -13.25 -> -0.92), cause unknown. Next: enter a level in free control (RN_JUMP c_teleport, or a later chapter).
  (3) Placement still 3 m right of the car until `_rn_mc_state` is exported (contract item 2).
