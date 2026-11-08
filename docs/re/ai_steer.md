# How the rivals steer (JustDrive type 7 -> steer input), and where they hit walls

Question (wave 2): look-ahead of the aim point JustDrive hands to `0x45db30` (vtable `0x6c8c18` slot +0x40), the steer
table `0x7060c0`, and what the rival aims at in the top wall cluster. Wave 3: `AIHIT ... wall` is not a wall counter
(docs/re/ai_drops.md), so the clusters are recomputed without the false families and the steering verdict is rewritten.
V = read in code/data/log, I = inference, U = open. Nothing run: `census/hopper/decomp.c`, `pc/Speed.exe` (PE, read-only),
`~/RE-NFSU/runs/w_*/log.txt`, `game/Tracks/TRACKB*.LZC`.

## Answer
1. **The aim point comes in through one setter only.** Driver vtable `0x6c8c18` slot `+0x40` = `0x45db30`: one argument,
   a pointer to two floats, **x -> driver+0x1f4, y -> driver+0x1f8**, and it is the sole writer of those fields in the
   whole `.text` (byte scan: `0x45db3f`, plus `0x4735b6/0x4736b9/0x47370a` on the predictor struct). V
2. **The look-ahead distance is NOT in the driver; it is in whoever calls `vt+0x40`.** No `call 0x45db30` exists; the 52
   `call [reg+0x40]` sites are the only door (`0x44f161` Avoid/Pass, `0x458beb` path, `0x46066c/0x46071b` RealDriver,
   `0x583426/0x58363d` and `0x59a9b5..0x59c223` traffic). Which one serves rival JustDrive: **U**. Traffic is settled
   (docs/re/traffic_react.md). V for the sites.
3. **`0x7060c0` is a blend weight, not an angle limit** (correction to wave 1, which had compared an RVA with a VA):
   `{ptr 0x7060b0, count 2}`, pairs **(10 m/s -> 0.0), (20 m/s -> 1.0)**; `0x45e370` returns
   `(1-t) x headingErrorToPoint + t x headingErrorToVelocity`, `t = table(speed)`. Below 10 m/s it steers at the point,
   above 20 m/s along its own velocity vector; no clamp anywhere in the path (`0x4592f0` softens only, I). V data/formula.
4. **Consequence for "oscillation".** There is no limiter to rail: above 20 m/s the blend follows the velocity heading,
   so a bad aim point shows up as a wrong line, not as zig-zag. I
5. **CORRECTED (wave 3): the "wall hits" are not wall contacts, and filtering the false families does not move the
   clusters off the driving line.** `AIHIT ... wall` fires on any one-frame drop >= 4 m/s with no other car within 6 m
   (host/aitel.c:127) and bumps `tr[i].wall`; nothing tests geometry. Same 14 runs, kind 2/3 only: **6430 wall-tagged,
   minus 1242 with `after` 6.1/8.1 (traffic target / route reset), minus 341 within +-3 frames of a `FREE respawn` line
   of that run, minus 663 with `before` > 70 m/s (garbage field, docs/re/ai_drops.md §5) = 4184 survive (65 %), 3562
   kind 2 + 622 kind 3.** V numbers.
6. **They are NOT at the road edges.** Distance from each surviving hit to the nearest road section edge (chunk `0x34121`,
   0x88-byte nodes, half width `(wl+wr)/2` at +36/+40, all 16 street tracks; reader as tools/openworld/worldmap.py):
   p25 -8.0 m, **p50 -4.1 m**, p75 -1.9 m; **8 % within 1 m of an edge**, 4 % more than 2 m past it. Calibration, the
   player's own clean line (AIP above 3 m/s, same geometry): p50 -6.8/-6.3/-4.8 m, **4-5 % within 1 m**. A surviving hit is
   ~2.7 m closer to the kerb than a normal line but still mid-pavement: if there is an obstacle it is a mid-road object
   (pillar, gantry, prop), never the kerb. V numbers, I cause.
7. **What is left is a speed step at 10 fixed mid-road spots, not a cornering fault.** Same clusters as before the filter
   (the old 2045,169 is the one now centred at 2066,179; 1998,234 is its own spot), 11-14 runs each, dominated by act 7
   (JustDrive, no Avoid/Block in the frame). At 2066,179: 461 surviving hits, `before` p50 **37.8 m/s**, drop p50
   6.0 m/s, only 4 % lose >= 20. A 6 m/s loss at 137 km/h is not a crash into a wall, and the p10 of the kept set (4.3)
   sits on the detector's own 4 m/s cut. V numbers, I reading.
8. **Steering verdict.** Nothing in these logs shows rivals steering clumsily. The counter that made them look clumsy
   counted speed-field rewrites; the survivors sit on the racing line, not the kerb; the two code findings that would
   explain a bad line (short aim point, velocity blend above 20 m/s) are still unmeasured. The claim "rivals hit walls
   1-2 times a minute each" is **retracted**: it was 1-2 speed drops a minute each, in the unpatched runs. V retraction,
   U what the 4184 survivors physically are.

## Wall-tagged hits per rival per minute (14 runs)

| run | sec | wall | -6.1/8.1 | -respawn | -garbage | kept | wall/min/rival | kept/min/rival |
|---|---|---|---|---|---|---|---|---|
| w_ai_s1 / s2 / s3 | 1174/1174/1184 | 502/399/635 | 214/158/241 | 27/26/37 | 0/0/0 | 261/215/357 | 3.2/2.5/4.0 | 1.7/1.4/2.3 |
| w_x_base / w_L3 | 237/664 | 68/270 | 29/113 | 7/17 | 0/1 | 32/139 | 2.2/3.1 | 1.0/1.6 |
| w_h / w_i / w_j | 248/240/244 | 143/87/57 | 67/37/14 | 9/5/4 | 0/0/0 | 67/45/39 | 4.3/2.7/1.8 | 2.0/1.4/1.2 |
| w_d / w_e / w_f | 235/210/251 | 272/279/313 | 26/30/30 | 15/8/20 | 40/41/32 | 191/200/231 | 8.7/10.0/9.4 | 6.1/7.1/6.9 |
| w_a / w_b / w_c | 389/360/307 | 1509/960/936 | 130/113/40 | 65/60/41 | 223/189/137 | 1091/598/718 | 29.1/20.0/22.9 | 21.0/12.4/17.5 |

w_a/b/c are the 17:04 build (unpatched, the only runs with the >70 m/s field: 549 of its 663 events); the s1-s3
baselines keep 1.4-2.3 per rival per minute. The 10x gap is a build difference, and the old table mixed both, which is
what made the rivals look uniformly clumsy. V numbers, I cause.

## Clusters, surviving hits only (30 m greedy re-centring, kind 2/3)
```
479 hits 12 runs 51 cars 2066,179     195 hits 11 runs 40 cars 1841,-732
340 hits 11 runs 35 cars 2133,177     169 hits 11 runs 31 cars 1999,233
291 hits 14 runs 63 cars 2186,-585    149 hits  8 runs 37 cars  737,114
200 hits 14 runs 93 cars 1701,-444    120 hits 11 runs 36 cars 1175,352
198 hits 12 runs 48 cars 1838,440     117 hits 13 runs 52 cars 2228,-556
```
Same ten places, same order as the unfiltered list: the filter removes 35 % of the events, not the places. V.

## Patch: none, two measurements left

No gain or limit is shown to be off; `0x7060c0` is not a clamp and the shipped 10/20 m/s ramp is sane.
1. Find the writer of the surviving step: log `car+0x3d4` with the `car+0x87c` / `0x4264d0` reset state at the drop frame
   for the 10 cluster coordinates (RN_AIDS + RST probe), and see whether it is the move path (`0x4789d0`) or a contact.
2. Look-ahead: log `driver+0x1f4/+0x1f8` and the car position per frame for the worst car of `w_a` and measure
   `|point - car|` against speed; ~15-30 m at 38 m/s means a late, wide entry. Testable with `RN_STEERLOG`, no patch. I

Open: caller of `vt+0x40` for rivals (U); whether `0x4592f0` also clamps (I); the mid-road obstacle/step at the 10
coordinates and why every rival meets it (U). Reproduce with
`python3 -I tools/re/ai_walls.py ~/RE-NFSU/runs ~/RE-NFSU/game/Tracks`.
