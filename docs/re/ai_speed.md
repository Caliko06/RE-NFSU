# Rival speed: are WORLD rivals (kind 2) slow, and what sets their speed (2026-11-04)

Marks: V = read in code or measured in the logs (address / number given), I = inference, U = open.
Logs: /Users/angeldamian/RE-NFSU/runs/w_*/log.txt, lines `AIR` (per rival, 1/s, host/aitel.c:99) and `AIP` (player, 1/s).
Fields used: `sp` = car+0x3d4 m/s, `s4b8` = ctx+0x4b8, `s404` = car+0x404, `rec14` = record+0x14, `own` = action+0x1e4,
`route` = byte action+0x1f0, `prio` = action+0x1f4. All 7 runs carry the same PATCH set (log `PATCH` lines).

## Answer

**No, they are not slow.** While a rival is moving (sp > 5 m/s) its speed is 0.80 to 1.24 x the player's at the same
second, p90 32-44 m/s (115-158 km/h). What reads as "slow" is standing time: 3-18 % of its samples are below 2 m/s
(stuck, crashed, waiting), not a low cruise. V (tables below)

## Measured (V)

`mov%` = share of samples sp > 5; `stuck%` = sp < 2; `med`/`p90` m/s over all samples; `ratio` = median rival/player sp
where BOTH > 5 m/s; `4b8` = median ctx+0x4b8.

| run | player med | rival | mov% | stuck% | med | p90 | ratio | 4b8 |
|---|---|---|---|---|---|---|---|---|
| w_L3 (career) | 17.7 | BRITTON / CARL / DIRT / JARED | 83-92 | 3-9 | 18.4-23.8 | 36.4-41.1 | 0.89-0.98 | 0.50 |
| w_L3 | | PRISS / PROBES / TERRY / TJ | 87-88 | 5-6 | 21.2-24.0 | 38.0-40.2 | 0.90-1.01 | 0.50 |
| w_b | 22.1 | FISH / HECTOR / ISHII / JOSE | 87-93 | 3-7 | 22.5-24.7 | 32.2-35.3 | 0.86-0.90 | 0.50 |
| w_b | | SAMANTHA / STAN / STEWART / TODD | 75-96 | 3-17 | 17.5-25.5 | 33.2-39.5 | 0.88-0.91 | 0.50 |
| w_ai_s1 (seed 1) | 25.3 | all 8 | 79-92 | 5-18 | 19.2-25.9 | 35.4-42.5 | 0.80-0.97 | 0.50 |
| w_ai_s2 (seed 2) | 21.9 | all 8 | 80-91 | 6-16 | 17.4-26.0 | 33.8-41.0 | 0.84-1.09 | 0.50 |
| w_x_base | 5.3 | all 8 | 73-87 | 7-15 | 13.1-21.1 | 27.6-36.5 | 0.98-1.24 | 0.50 |
| w_ai_s3 (seed 3) | 5.6 | 6 of 8 | 55-93 | 6-25 | 7.7-25.3 | 26.5-44.0 | 1.45-2.00 | 0.50 |

The last two rows have a player median of 5 m/s (crashed or off track), so the ratio is inflated by the denominator: use
their `med`/`p90` only. w_ai_s3 NESTO spent 41 % of the run below 2 m/s (V).

## What fixes a rival's speed (code chain, all from docs/re/rivals.md and docs/re/race_ai.md)

1. **Desired speed, every frame**: `0x44c550` = `routeSpeedByte x rec+0x14 x ctx+0x4b8`, then capped by the car's own
   limit (vtable `[obj+0xff]+0x10`). `routeSpeedByte` = route node `+0x6a` (node stride 0x88, base +0x27c) at
   `node + jitter`, jitter `[-(b+1), b]` with `b` = record `+0x50`, re-rolled every 5.0 s (`0x77a498`); a 0 byte falls
   back to 30.0 (`0x6ccac0`). V (rivals.md §4)
2. **rec+0x14** = 0.95 at skill 0 to 1.0 at skill 9, interpolated. V (rivals.md §2). It is the only *skill* term that
   scales the target, and its whole range is 5 % — skill cannot make a rival much slower, only the rubber band can.
3. **ctx+0x4b8** = rubber-band scale, written every 0.3 s by `0x44bd10`; `car+0x404 = max(scale, 1.0)` at the same
   time (`0x44bfe9`, `0x44bffe`), so the engine scale never drops below 1.0 while the AI target keeps the raw scale. V
4. **action+0x1e4** is the action's own desired speed in m/s, used only when action+0x1f0 = 0. `0x44c550` reads the pair
   `+0x1e4` / `+0x1e8` (dwords 0x79 / 0x7a) and, when the flag is 1, takes the route byte instead. V Writers found in
   `census/ghidra/decomp_0x401000_0x4a6800.c`: `0x44e850` = |culprit velocity| - k (IJustGotHit back-off), `0x44e950` =
   coast (drag terms), `0x452070` GetUnstuck = `DAT_0x6b7674` -15.0 or `0x6b7678` -6.0, `0x4515c0` Avoid = 15.0 - 1.0 =
   14.0 (`0x6b7658`, `0x6cc7bc`, both read from pc/Speed.exe), 0, or a fraction of the current speed; base ctor writes 1.0. V
   The 17.0 measured at fl=1 (234 samples act 1/300) is **stale**: Avoid writes 14.0, and 17.0 matches a previous
   IJustGotHit (23 - 6; 58 samples at act 12/400 fl=0). The field is not cleared on action change, so `AIR` shows the last
   action's number even when the frame ignores it. I (stale), V (writers). U: the 1000.0 seen on some Pass samples.
5. **Desired speed is not stored anywhere** (answered): `0x44c550` keeps it in a float and passes it to the vehicle update
   `(*(*ctx[0x2]+0x38))(speed, action+0x1f1, ...)`; its `return` value is `sub_458f10(0,0)`, and there is no store to
   `ctx+0x200` in that function. V (hopper `census/hopper/decomp.c` 0044c550). So the value can only be recomputed, which
   is what `AIDS` does.

## The one scale that is measurably low: ctx+0x4b8 = 0.50

`ctx+0x4b8` is 0.50 in 94 % of the moving samples of w_L3, w_b and w_ai_s1/s2/s3 (`s404` stays 1.00 in all of them). V
Splitting by that field: 4b8 = 0.50 rivals run at median **24.0 m/s** (n = 3910, w_L3), 4b8 >= 0.93 at **29.4 m/s**
(n = 410). Same run, cars and player. V. So the raw rubber-band floor costs ~5 m/s, 18 %. The exact repetition of 0.50
(never 0.49) looks like a clamp; no table in rivals.md §3 holds 0.5 (record floor `+0x18` is 0.76..0.92). I: it is the
`max((f-1) x v + 1, floor)` term landing at ~0.49 and clamped elsewhere. U until that address is found.

## AIDS: the chain is now measurable (host/aitel.c, off unless RN_AIDS is set)

One line per rival per second: `node` = record+0x8, `b` = record+0x50, `jit` = ctx+0x404 (live jitter, re-rolled every
0x77a498 s), `eff` = clamped node+jit, `rb` = route byte at node+0x6a (via the AI route clone, driver+0x3e4, nodes at +8),
`rec14`, `s4b8`, `s404`, `want` = rb x rec14 x s4b8 recomputed at log time (I, not a store), and the action pair `a1`/`a2`
+ `flag`. Same run as `AIR`, so `want` vs `sp` says whether the target limits the rival at all. U: `rb` is read through the
node pointer array (d3d9.c:1154), rivals.md quotes base+0x27c+i*0x88; only a run with RN_AIDS confirms rb is 20..40, not 0.

## Draft patch (OPT-IN, not applied)

Make the AI target ignore the sub-1.0 rubber band: store `max(scale, 1.0)` in `ctx+0x4b8` as well as in `car+0x404`.
Value from the numbers: +5 m/s (+18 %) for rivals the band is holding now, i.e. "rival ahead of the player is throttled".

- Site `0x44bffe` (store of the raw scale into `[ctx+0x4b8]`, rivals.md §3 step 5): reuse the `max(scale, 1.0)` already
  computed for `0x44bfe9`, behind `RN_AI_NO_4B8_FLOOR=1`, so original mode stays untouched.
- Bytes not written here: `tools/recomp/asm.py dis` needs capstone, absent in this worktree (V: `ModuleNotFoundError`),
  and patches.py checks `old` first, so a wrong entry stops the build. Produce them where capstone exists.
