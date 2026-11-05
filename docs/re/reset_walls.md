# Reset and walls in WORLD: pass-through count before any patch (nfsu-w3, Block 1, 2026-11-05)

Status: cause NOT reproduced. No patch address yet; the ghost counts below say which causes are out.

## Probe (host/aitel.c, off by default)
- `RN_WALLX=1`: every Present, the player's xy step is tested against the base segment of every wall row the game holds
  (manager 0x77b130 wsrc, +0x10 ptr, +0x14 rows, 32 B, byte +3 & 2; 53,603 rows, 9,378 walls). Skips teleports (> 15 m, reset frame).
  "POST" = within 180 Presents after the player's reset. Also `WNEAR`: walls within 8 m vs the car's wall cache (car+0x7e8).
- `RN_RESETEVERY=<s>` calls the player's own reset 0x4314a0 (as 0x4264d0 does). Run: `tools/openworld/ghost.sh <tag> 900 RN_WALLX=1 [RN_RESETEVERY=n]`, RN_SEED=1, autopilot, traffic on.

## Count before the patch (6 ghosts, seed 1, 600-900 s)
| run | frames (post-reset) | resets (all cars) | crossings | strict (car z <= wall top) |
|---|---|---|---|---|
| no reset (x2) | 6,598 / 7,198 (0) | 0 | 2 / 2 | 0 / 0 |
| every 3 s | 5,369 (4,071) | 48 | 0 | 0 |
| every 8 s | 7,783 (2,532) | 40 | 2 | 0 |
| every 15 s / 20 s | 5,393 (913) / 8,392 (944) | 23 / 33 | 2 / 2 | 0 / 0 |
- Every lenient crossing is one spot (rows 21120/21132/21134, x 957-983, y 357-368): car z 52.0, wall top 51.5-51.6, 36-42 m/s. It is a deck over the wall, and it also occurs with no reset. So **0 real pass-throughs after 65 forced player resets and about 8,200 post-reset frames.**
- WNEAR "cache has fewer walls than the 8 m box": 37% of samples with no reset, 42% / 27% after resets. No post-reset signal (my 8 m box is looser than the game's, so the base rate is noise).

## Out (V = ghost number)
- H2 stale cache (0x440740 clears it) and H4 velocity/heading: refuted by code and by the 0 above.
- Pool A int3 0x441b82: halts, does not pass walls. Pool B / witness exhaustion (0x469810): no WALLCAP line in any run.
- Player reset path 0x4314a0 with no route path: taken by the player (RSTE lines: speed 0 after reset), car lands on road (dzroad +0.34).

## Open (I, not tested)
The autopilot is not a human at 40+ m/s with 26 cars. Remaining candidates: pool B at the WALLCAP condition under traffic load, a step of 3 frames (50 ms) at 60 m/s. Next patch needs the OWNER's F10 log of a pass-through (WALLCAP / WALLX lines); with it the address follows.
