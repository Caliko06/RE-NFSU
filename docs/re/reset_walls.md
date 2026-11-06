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

## Block 2 (nfsu-w3, static RE + 2 ghosts, 2026-11-05)
Evidence: Ghidra headless decomp (census/ghidra) + objdump of pc/Speed.exe; no REA session opened.
- Probe fix: `reset_every` armed RST after the call (host/aitel.c), so Block 1's "pos before" was the pos after. Now RST = before, RSTA = after.
- Player reset in WORLD (ghost r_fix, 117 forced resets, seed 1): the route-path branch (0x427f70) runs: car moves 1-3 m, dz +0.07, speed clamped 8.1.
  Placement cannot put it past a wall. 0 strict crossings (r_base 105 resets, r_fix 117, ~10k post-reset frames each); the 4 lenient crossings are the same two decks as Block 1.
- Found, not exercised: `0x4314a0` no-route branch (0x4317ac z = 0; node test at z = 100000 at 0x431724). `0x440a40` takes the highest surface below z+1, else the
  highest of the column, so z = 0 lands on the top layer of the column. patches_reset.py starts both queries at the car's z. Same result on a one-layer column.
- Still open: nothing in the code reached by the player's normal reset moves it into a wall. A pass-through needs the OWNER's F10 or a human-speed ghost.
