# Draft (rebufo) frequency: how often the OWNER would feel it

Question: from existing logs, how often would the player's draft `car+0x47c` be > 0.2 (the gate of the opt-in
`RN_DRAFT_K` rule)? Answer from the geometry the game uses, with the real tables read from `pc/Speed.exe`.

## Answer first

**About 6 % of the player's seconds.** Pooled over the three new 1200 s baselines `w_ai_s1..s3` (3403 logged
seconds): **5.9 %** (201 s) with `draft > 0.2`, 6.9 % of the seconds where the player is actually moving
(sp > 1 m/s). The four older logs (`w_x_base`, `w_a`, `w_b`, `w_L3`, 1470 s) give **7.6 %**. V (numbers below).
With `k = 0.055` a second at `draft` 0.2 is worth **+1.1 % speed**, at 0.6 **+3.3 %**, at the 0.9 cap **+4.95 %**.
So the rebufo would be felt as a real shove only in the **2.7 %** of seconds with `draft > 0.6`, and mostly in
city traffic, not on the highway:

| player speed | seconds | draft>0.2 | draft>0.4 | draft>0.6 |
|---|---|---|---|---|
| 0-5 m/s  | 1448 | 48 (3.3 %) | 28 (1.9 %) | 8 (0.6 %) |
| 5-15     | 1111 | 132 (11.9 %) | 106 (9.5 %) | 62 (5.6 %) |
| 15-25    | 689 | 66 (9.6 %) | 54 (7.8 %) | 35 (5.1 %) |
| 25-35    | 754 | 35 (4.6 %) | 28 (3.7 %) | 19 (2.5 %) |
| 35-60    | 871 | 32 (3.7 %) | 20 (2.3 %) | 10 (1.1 %) |
| all      | 4873 | 313 (6.4 %) | 236 (4.8 %) | 134 (2.7 %) |

V for the table (7 logs, 4873 s), I for the "would be felt" reading: +1 % of 40 m/s is 0.4 m/s, the same order
as the throttle noise the OWNER already complains about.

Episodes are short: **44 / 57 / 35** tow runs in s1 / s2 / s3, median **1 s**, longest **8 s** (s1, mean 43 m/s),
then 5 s, 4 s, 4 s. V. So the tow is a flicker at 1 Hz sampling, not a sustained pull; the k rule will fire in
bursts of 1-3 seconds and its effect will read as the speed wobbling, not as a slingshot. I.

Sources split (s1..s3): seconds whose > 0.2 comes from a **rival** (kind 2) 80 s = 2.4 %, from **traffic**
(kind 3) 125 s = 3.7 % (they can overlap). V. In the older logs traffic dominates even more (84 s vs 28 s).

## The tables, as read (V, bytes at these VAs of pc/Speed.exe)

- `0x426300` (one pair, called from `0x426450`): `ecx` = the *other* car, `edx` = the car receiving the draft
  (0x426470 `mov ecx,[esi+edx]`, 0x426477 `mov edx,ebx`). All tests are on the **source** car. V.
- speed gate: `[ecx+0x3d4] >= [0x706288]` = **1.0**. V.
- gap: `ecx+0x60..68` minus `edx+0x60..68` (3D), `sqrt`, then `min(d, [0x70629c] = 60.0)`, and `d > 0` required. V.
- heading: `lea edx,[ecx+0x70]` -> `sub_567370` normalizes the **source car's velocity**; `cos = dot(vdir, gap)/d`. V.
  It is *not* the player's heading (ai_draft.md left this U; it is the other car's velocity vector).
- cosine ramp: `(cos - [0x6b7b50] = 0.95) / ([0x6cc7bc] = 1.0 - 0.95)`, and `<= 0` returns 0. V.
- reach `sub_583f20(0x7062b4, speed)`: struct `{pts = 0x706280, count = 4}` -> piecewise linear
  `(0,0) (1,0) (5,10) (150,60)`: 0 below 1 m/s, 10 m at 5 m/s, then **+0.3445 m per m/s**, flat **60 m** above 150 m/s. V.
  This corrects ai_draft.md ("{base 2.5, cap 255, slope 0.5}"): those three floats belong to the *next* struct at
  `0x7062bc` (`(0,2.5) (255,0.5)`), a different curve. Real reach: 18.6 m at 30 m/s, 28.9 m at 60 m/s. V.
- falloff `sub_583ea0(0x7062a0, t)` over the values at `0x700d3c` = **1, 0.9, 0.75, 0.55, 0.3, 0** (6 knots,
  linear between them), with `t = clamp(d / (reach * ramp), 0, 1)`. V. Note the ramp divides the reach: a
  marginal cosine shrinks the usable window, it does not only scale the result.
- sum capped at `[0x6b7b54]` = **0.9** (0x426490 `fcomp`, break). V.

## Method (script: `becarios/yoli/work/draftfreq.py`, run `python3 -I`)

Per logged second: `AIP` gives the player's speed; every `AIR`/`AIT` line of the same frame gives the car's signed
`d` (ahead+) and `lat` relative to the player's heading, plus its speed `sp`. Recompute `cos = d/hypot(d,lat)`,
reach, ramp, `t`, falloff, sum, cap 0.9. 201 of 3403 s above 0.2 in s1..s3 and 112 of 1470 s in the older four = 313 of 4873
(the per-band table pools all 7 logs). Logs used: `w_ai_s1..s3` (seeds 1-3, already on disk), `w_x_base`, `w_a`,
`w_b`, `w_L3`. Runs that are not races log no `AIP` and are skipped.

## Limits, and the check that settles it (U)

- No log in `runs/` has the branch's `AIP ... draft` field (`grep -c 'draft'` = 0 over all logs), so this is a
  **model of the game's arithmetic, not a measurement**. V.
- Distance is 2D here (`hypot(dx,dy)`), the game uses 3D; cosine uses the player's heading in the logs, the
  source's velocity in the game; `d`/`lat` are printed with 0 decimals; 1 Hz sampling misses sub-second tows and
  inflates the edge ones. Each of those can move the 6 % by a point or two, not by a factor. I.
- Settle it in the Wave 3 ghost: `RN_AILOG=1 RN_DRAFT_K=0.055`, then `grep AIDR` (the game's own `car+0x47c`)
  and `grep AIP` (its `draft` and `tow>0.2 N/M x%`). **Prediction to falsify: 4-9 % tow seconds, no episode
  longer than ~10 s, traffic-majority, and the AIDR value of each second equal to within ~0.1 of the geometry
  recompute.** If AIDR reads far higher, the pair term is being summed over cars that `AIR`/`AIT` do not log
  (rivals out of the 80 m AIT window are not logged, but they are outside reach too). I.
- Nothing to patch: `RN_DRAFT_K` is already the env var; no code change is implied by these numbers.
