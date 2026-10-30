# Jump camera: trigger, camera, return, and why it was missing (2026-10-30)

Tools: G = Ghidra export `census/ghidra/decomp_0x401000_0x4a6800.c`, D = bytes of the unpatched exe (python struct, `tools/recomp/asm.py`),
H = our host code read. Earlier work: `docs/openworld/re_jumpcam.md` (same chain, runtime logs of 2026-10-28). Not run in the pod this time
(the game does not run there yet): the new facts below are from code and bytes, the Mac must confirm with a jump.

## The chain (V, G+D)

1. `0x426930` (per car, every frame; the jump test runs when `frame % 8 == 3`). Input: `car+0x3cc` = wheels on the ground (0..4),
   `car+0x3d4` = speed (m/s), level x = option byte `[0x78a3fa]` (0x80 in a normal game).
2. Fires only if no special camera is running (`ctrl+0x60` not 6 or 7), `[0x7361e8] == 0`, all wheels in the air (`car+0x3cc == 0`),
   `ctrl+0x4ac == 0` and speed > curve `0x7062fc`. Curves are piecewise linear (x, y) pairs read by `0x583f20` (D):
   - speed `0x7062fc`: 50 m/s at x=0 to 5 m/s at x=255. At x=128: **27.4 m/s (99 km/h)**.
   - `0x706314`: 4.0 to 0.5 (look-ahead seconds fed to the flight predictor `0x429cf0`).
   - min height `0x7062cc`: 2.5 to 0.5. At x=128: **1.5 m**. Min distance `0x7062e4`: 2.5 to 0.5, at x=128: **1.5 m**.
3. The predictor `0x429cf0` returns max height and distance of the flight. If both are above the curves, `0x42c4b0()` must return non-zero
   (it builds the camera spline from the driver's route; fails if the route has fewer than 5 nodes over 75 m, see re_jumpcam.md), then
   **`0x426930` calls `0x42da40(mode 6, 0, 1, 1)`** (call at `0x426dd7` region; the call to `0x42c4b0` at `0x426dd7` is the one our cave replaces).
4. `0x42da40` mode 6: slow motion `0x420050(0.4, 8.0 s)` (`[0x6b7ab0]`, `[0x6b7a74]`), camera mover **type 0xf** (TrackCar, update `0x485c00`) through
   `0x42c6d0(ctrl, 0xf, 1)`, `ctrl+0x60 = 6`, `[0x73654c] = 1`. Cooldown: 5 s per mode (`[0x6b7a88]`). Refusals: see re_jumpcam.md.
5. The shot (`0x485c00`, G): the eye is a point of the route spline (`mover+0x410..0x428`, segment chosen by the car's progress), the target is the
   car (`mover+0x438` car, position `+0x60`); FOV `mover[0x1c]+0xc4` is set here from the distance (`0x564db0`), `+0xbc = [0x6b6cd0]`. No wall sweep is
   run on this eye (the push-out `0x4838e0` has two call sites in the export, neither inside `0x485c00`, which calls `0x483860` and `0x485b90` instead).
6. Back to the chase: while `ctrl+0x60` is 6 or 7, `0x426930` calls `0x42ddc0(ctrl, 1)` when the car touches down: if `car+0x38 == 1`, with all 4 wheels down and
   0.5 s (`[0x6b7ba4]`) after `car+0x4c8`; otherwise as soon as one wheel touches (`car+0x3cc > 0`). `0x42ddc0` clears `[0x73654c]`, `ctrl+0x60 = 0`, restores time, and
   `0x42c450` calls the default camera `0x42c670` (type 0x11, the chase). The mode-7 shot (landing view, mover 0x10) follows through the same gates.

## Why it did not show in our build (V, H)

- **Cause: our own patch.** `PATCH 0x426dd7` and `0x4662e0` (cave `0x5567e3`) send the `0x42c4b0` question to `host/free.c free_jumpcam`, which returned 0
  in free mode (Free Run and WORLD, `live`). With 0 the jump shot is refused every time, so the chase stayed. That was added on 2026-10-28
  because the spline eye sits inside buildings in the city. Circuits and Quick Race always ran the original call.
- Not the cause (checked in code): `?chasecam` and `?nitrocam` only rewrite CarTypeInfo rows `[[car+0xc]+0xb50]`, read by mover 0x11; mover 0xf
  does not read them. `PATCH 0x42d87e` only changes the autopilot's camera type (0x12 to 0x11). `fov_frame` writes the FOV table, which mover 0xf does not read
  (it sets its own FOV at `+0xc4`).
- The same cave also feeds the crash camera (`0x465d00`, call `0x4662e0`): it came back too.

## The fix and its exit

`free_jumpcam` now runs the original call in free mode too. `?jumpcam=0` (env `RN_JUMPCAM=0`) restores the 2026-10-28 answer. Exit: if the OWNER
likes the jump shots, delete the switch; if the shots go through buildings in WORLD, the next step is a wall sweep on the eye of `0x485c00`
(the push-out `0x4838e0` takes a car collision cache, so it only works near the car) or a route check in `free_jumpcam`.
Known risk (from 2026-10-28, not re-measured): in the city the eye can sit in a building or behind a pillar for about 2 s.
