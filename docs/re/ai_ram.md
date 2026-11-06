# Does any AI action deliberately hit the player? (ramming / "te torean")

**Answer: no AI action aims at the player's car; the one that comes close is Block (5), and it is a lane block, not a ram.**
Block is a *closing-the-door* action: its finder only accepts a car **behind you in the same lane** and its steering then puts your
own line on that car's lateral position, 10..50 m ahead of it. In 34 min of logs no player contact happened while a rival was in
Block (0 of 94 player-side impact events). The impacts the player feels are the player hitting traffic (P>T, 3.6..11/min) and
rivals crashing into walls/traffic on their own.

## 1. Code (V = read at that address in `pc/Speed.exe`)

### Pass (0), finder `0x450730`, steer `0x450bb0`
- V `0x450730`: gate on `0x73619c+4` (last pass attempt) and elapsed ticks x `0.00025` > `0.3` s; scans the neighbour list
  (`ctx+0x3c`, stride `0x38`, count `ctx+4`), per entry `E+0x10` = along-gap, `E+0x14` = lateral, `E+0x4` = car handle;
  needs `gap - self` in a band and `sub_4569b0`/`sub_45bae0`/`sub_450b40` to agree; writes the target and returns **200**.
- V `0x450bb0` (vt slot 2): `0x45bae0` picks the side, `0x45ae10(...,2,...)` builds the pass point, then
  `fabs(E+0x4) < 5.0` (`0x6cc954`) -> `0x44f6c0` (give up). Pass wants **5 m of lateral clearance**, it does not aim at a car.

### Block (5), finder `0x450ec0`, ctor `0x450e20`, steer `0x451230`, re-target `0x451190`
- V `0x450ec0`: loop starts at **own index + 1** (`0x450f20`), i.e. the list entries behind the AI, and every candidate must pass:
  `sub_647b70()==6`, target alive (`[car+0x1d4]+0x90+0x1c != 0`), `sub_44d5f0() > 10.0` (`0x6b7648`); then with
  `E+0x10` = along-gap and `E+0x14` = lateral, `lat' = fabs(E+0x14) - halfwidth` (half width from `[ctx+0x3a8][E+0x30]`, `+0x3c`
  when `E+0x14 >= 0`, else `+0x20`) and `gap' = (E+0x10 - self+0x10) - lat'`; it needs `0 < gap' <= 50 m` (`0x6b7644` = 50.0,
  `0x6b7640` = -5.0 flips the sign) and a ratio test `gap'/E+4` against `30.0` for a human target and `2.0` otherwise
  (`0x6b7634`, `0x6b7638`, `0x6cc798` = 99999). Picks the nearest candidate and returns `0x77a340[8*aggr]` = **200 / 200 / 400**.
  So Block only fires on a car close behind, inside the AI's own lane corridor. Exact meaning of `E+4` in the ratio: U.
- V `0x451230` (vt slot 2): goal point = `sub_45c370(goal, self, 1, scale, E+0x14, gap)`. `E+0x14` is the **pursuer's lateral
  offset**, so the AI moves its own car onto the line of the car behind, at that car's distance. `E+0x14` is first clamped to the
  target's half width (`E+0xc`, or `E+eax*4-0x14` for the 5..10 / 11..16 part classes). `scale` = `1.0` (`0x6b7650`) when the
  Block-table flag `0x77a344[8*aggr]` is set (it is `1` for all three classes in shipped data). Then it sets the action flag
  `ctx+0x1f2 = 1` (rubber band on, per `docs/re/race_ai.md`) and keeps the route speed (`ctx+0x1f0 = 1`).
  -> Block steers **into the pursuer's lane**, it does not steer into the pursuer's body: the goal is always `gap` metres ahead.
- V `0x451190` (vt slot 7): re-runs the finder and swaps the target; no cooldown, so Block can hop between cars.

### Avoid (1), ctor `0x44f750` (vt `0x6c9324`), finder `0x44f8a0`, steer `0x44fb30`
- V `0x44f8a0`: calls `0x457590(0x77a4ac, ctx+0x38c, ...)` (the generic obstacle scan) and `0x458f10` twice; the ctor stores the
  resulting lateral in `+0x214` = `2.0` (`0x6b760c`) + arg, and `0x44fb30` rebuilds a goal point from `ctx+0x200`, the very same
  `0x45c370` lateral mechanism. It moves to a *free* lateral offset, not to a car. (Meaning of `0x77a4ac` and of `+0x214`: U.)

### Aggression / personality
- V: the skill record (stride `0x54` at `0x779ff8`) has **no aggression field**; its 22 fields are speed, fork odds, timers and
  distances (`docs/re/rivals.md` s2). Aggression is the separate byte rival row `+0x18` -> entrant `+0x736` (0,1,2; class 2 on 19 rows).
- V: its only readers are the selector ceiling `0x77a340[8*a]` (200/200/400) and the Block flag `0x77a344[8*a]`, plus the
  `1.0` lateral scale. Class 2 therefore only buys the right to start Block/Avoid over a running Avoid (300) or IJustGotHit (400);
  it does not add speed, contact force or a "target the player" rule.
- V: no other action touches the player's car body. `0x44ed70` IJustGotHit is *reactive* (it fires after a hit);
  `0x450730`/`0x450ec0` are the only two actions that name another car and both steer to a **free lateral / a lane**, never to a hit point.
- U: what `0x77a358..0x77a3ff` (12 + 30 floats) feeds, and `[ctx+0x3a8]` (the car-dimension table with `+0x20`, `+0x3c`).

## 2. Logs (`AIHIT` = any race car losing >=4 m/s in one frame; `car`/`wall` = nearest other car inside 6 m)
Segments/min (each line = one car losing speed, so a real touch can appear twice). Drop = m/s in that frame.

| run | len | P>V | V>P | V>V | V>T | T>V | P>T | T>P | P/T wall | V wall | T wall |
|---|---|---|---|---|---|---|---|---|---|---|---|
| w_ai_s1 | 3.2 min | 0.31 | 0.31 | 1.86 | 5.26 | 0.93 | 1.86 | 0 | 0.31/0 | 6.19 | 9.90 |
| w_ai_s2 | 3.4 min | 0.88 | 0.59 | 2.93 | 9.07 | 1.76 | 4.68 | 0 | 1.17/0 | 11.41 | 9.95 |
| w_ai_s3 | 3.1 min | 0.64 | 0.96 | 5.79 | 4.82 | 1.61 | 1.29 | 0.64 | 2.25/0 | 15.11 | 12.21 |
| w_x_base | 4.0 min | 0.76 | 1.52 | 4.30 | 11.14 | 0.76 | 4.30 | 0.76 | 0.51/0 | 11.39 | 5.82 |
| w_L3 | 11.1 min | 1.08 | 0.54 | 3.89 | 11.75 | 0.63 | 3.62 | 0.72 | 1.45/0 | 12.65 | 11.75 |
| w_a | 6.5 min | 0.77 | 2.47 | 14.02 | 34.52 | 5.55 | 10.94 | 2.31 | 3.70/0 | 203.43* | 29.13 |
| w_b | 6.0 min | 1.33 | 1.50 | 11.48 | 27.80 | 7.32 | 10.99 | 1.83 | 3.66/0 | 131.66* | 28.13 |

- Player-vs-rival (P>V + V>P, deduped events): **0.6..2.5/min** of race time; mean player drop 8..15 m/s.
- Rival-vs-rival: 2..14/min. Rival-vs-traffic: 5..35/min. **V wall: 6..203/min** — the biggest AI failure by far is rivals hitting
  walls on their own, roughly 10x the rate at which they touch the player. `w_a`/`w_b` (*) hold speed drops of 1e3..3e4 m/s, i.e.
  resets/teleports; ignore their wall means (U).
- Action mix of rival samples (`AIR act`): JustDrive 52..67 %, Avoid 21..29 %, GetUnstuck 4..8 %, Pass 3..5 %, **Block 1..2 %**,
  IJustGotHit 0..2 %, AccidentRecovery 0..1 %.
- Block with the player inside 80 m: 4..23 samples per run, and in **20 of 23** of them the blocker is `d = +10..+16 m` **ahead** of the
  player with `|lat| = 6..8.5 m`. That is the "cuts in front of you" event. Contacts while a rival was in Block: **0**.
- Typical player incident: P>T, 4.3..11/min (the player runs into traffic), drop 9..15 m/s.

## 3. Verdict and cheap opt-in probe
- V: no hit-seeking AI. I: what the OWNER feels as "me torean" is (a) a rival in Block moving into his lane from 10..16 m ahead, and
  (b) rivals and traffic piling up in the same corridor, where the player rear-ends them.
- Opt-in experiment (not shipped, one line in `tools/recomp/patches.py`, gated by `RN_NOBLOCK=1`): poke `esi[0xea]`-path is too
  invasive; instead patch the Block priority byte `0x450ef1` path by returning -1 at `0x450ec0` entry (`0x450ecd` `or eax,-1; ret`)
  behind the env var, and compare `AIHIT` P>V per minute against `RN_NOBLOCK` unset in the same seed. Keep original mode untouched.
