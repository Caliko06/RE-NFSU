# Wave 2: other ways a rival reaches the player (cut-in, pass line, reverse)

**Answer: three mechanisms, none aimed at the player, all measured.** (1) A rival inside 15 m moves > 3 m sideways in 1 s into
the player's lane **1.5..14 times per minute** (103 in 19.6 min on seed 1, 278 on seed 3); that is the dominant "se me mete"
event, and 40 % of them end inside 2.5 m of the player's line. (2) The Pass side choice (`0x45c0d0`) only looks at widths and
relative speed, **never at where the human is**, so a pass line can cross the player's lane. (3) The GetUnstuck reverse
(-15/-6 m/s, 1.3 s, `docs/re/ai_stuck.md`) does drive into cars: **0..0.41 player hits per minute**, versus 16..64 wall hits per
run and up to 47 rival hits in the same run. V = code address or log number.

## (a) Rivals moving into the player's lane (AIR, 1 Hz)
Rule: consecutive `AIR` samples <= 70 frames apart, both within `|d| < 15 m` of the player, and `|lat|` drops by more than 3.0 m.
`lat` is the rival's lateral offset from the player's line, so a drop is a move toward the player's lane. V.

| run | span | cut-ins | per min | ended inside 2.5 m |
|---|---|---|---|---|
| w_ai_s1 | 19.6 min | 103 | 5.26 | 43 |
| w_ai_s2 | 19.8 min | 53 | 2.68 | 24 |
| w_ai_s3 | 19.7 min | 278 | 14.09 | 105 |
| w_x_base | 4.0 min | 6 | 1.51 | 4 |
| w_a | 6.5 min | 46 | 7.09 | 26 |
| w_b | 6.0 min | 35 | 5.83 | 15 |
| w_L3 | 11.1 min | 39 | 3.52 | 19 |

- V: seed 3 is 5x seed 1 on the same code, so this is track/seed dependent, not a fixed rate.
- I: most of these are the Block finder's target (`0x450ec0`: a car behind, inside the lane corridor, `0x451230` steers to
  `E+0x14`) plus ordinary Avoid of traffic; AIR cannot tell the two apart, because both are lateral ramps.
- U: with 1 Hz sampling a 3 m step can also be a measured swerve that finished inside the second; and the sign of `lat` flutters
  below ~1 m.

## (b) Pass line: can it cross the human's lane? Yes, the code never looks at the human.
- V `0x450730`: for a candidate it calls `sub_45bae0(point, &out, &side, entry, ctx, 0, *0x7006ec, 1)` and then `sub_450b40(point, side)`;
  `sub_450b40` only checks the *target*: if the target is traffic (`kind == 3`) it also needs `sub_44d5f0()` (relative speed)
  above `[0x700674]`, otherwise the pass is allowed, and if the target is not traffic it is allowed outright.
- V `0x45c0d0` (the side chooser inside `0x45bae0`) returns **1 / 2 / 3**. It compares the lateral room from
  `sub_5a6860(own part, -1.0)` with the target's half width (`[ctx+0x3a8][entry+0x30]`, `+0x3c` or `+0x20`) and the caller's
  distances; `1` and `2` both select lane index **2**, `3` selects lane **3**. The only player-aware term is absent: the human's
  `lat`, action and distance are never read.
- V `0x450bb0` (Pass steer): `0x45bae0` builds the point, `0x45ae10(..., 2, ...)` consumes it, and the action aborts only when
  `fabs(E+0x4) < 5.0` (`0x6cc954`), a clearance in metres, not a check of the human.
- So a pass whose target sits in the player's lane, taken on the side the player occupies, ramps the rival through the player's
  lane. I: that is the second source of "me torean", and the log cannot separate it from (a) because Pass is only 3..5 % of AI time.

## (c) Reversing into a following car (GetUnstuck, act 0xa, own speed -15 / -6)
Entries from `AIEV ... act 10`; "player behind" = the next `AIR` sample has `0 < d < 10 m` (the rival is just ahead of the player).
"Hits" = `AIHIT` by a rival (`kind 2`) whose own `act` was 10, split by the nearest car kind / wall.

| run | entries | per min | next sample <10 m | player behind | P | V | T | wall |
|---|---|---|---|---|---|---|---|---|
| w_ai_s1 | 206 | 10.5 | 1 | 0 | 0 | 6 | 3 | 20 |
| w_ai_s2 | 205 | 10.4 | 6 | 1 | 1 | 5 | 2 | 6 |
| w_ai_s3 | 677 | 34.3 | 79 | 45 | 8 | 47 | 15 | 16 |
| w_x_base | 56 | 14.1 | 3 | 2 | 0 | 1 | 0 | 2 |
| w_a | 187 | 28.8 | 3 | 1 | 0 | 0 | 3 | 64 |
| w_b | 113 | 18.8 | 3 | 1 | 0 | 2 | 1 | 43 |
| w_L3 | 154 | 13.9 | 16 | 6 | 0 | 3 | 2 | 11 |

- V: a reversing rival hits the player **0..0.41 times per minute** (8 in 19.7 min, seed 3; 1 in seed 2; 0 elsewhere).
- V: the same reversal hits **walls 11..64 times per run** and other rivals up to 47: the reverse mostly damages the AI itself.
- V: 45 of 677 entries in seed 3 start with the player inside 10 m right behind, i.e. one in 15 reversals is pointed at a
  following car, and the 1.3 s timer is what carries it into contact.

## Verdict
- V: no action seeks the player. The three contact sources are all *side effects* of a lane move: Block/Avoid lateral ramp (1.5..14
  cut-ins per minute), a Pass to a side chosen without the human's position, and a blind 1.3 s reverse.
- I: fix order by payoff: the reverse is the cheapest and most obviously wrong (it reverses with a car at 6 m), the pass side is the
  next (add the player's lateral to `0x45c0d0`'s room test), the Block corridor last (it is intentional in the design).
- U: exact traffic/lane index meaning of `1/2/3` in `0x45c0d0`, and whether `w_ai_s3`'s high reversal rate is a track or a
  `RN_*` variant (its `AIR` count per rival is the same, so it is the track).
