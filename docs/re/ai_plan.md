# AI patch plan, ranked by feel gain / cost (wave 2, 2026-11-04)

Inputs: my ranking in docs/re/ai_prior.md plus wave-1 findings in
`~/RE-NFSU-wt/{paco,rosa,yoli,chela,beto,memo,tomas,pepa}/docs/re/ai_*.md` and docs/re/ai_stuck.md.
Marks: V = address/bytes/number read; I = inference; U = open. Nothing was built or run.
Ranking rule: (what the OWNER feels in a 4 min WORLD ghost) / (hours to patch + verify). One patch set at a time,
same seed, one run (AGENTS V1). Baseline tags: `AIR` (rivals), `AIT` (traffic), `AIHIT` (>=4 m/s drop), `AIP`.

## Answer first

The three things that read as "clumsy AI" are not speed, aggression or drafting. They are, in order:
**false-positive unstuck reversals** (7-25 per minute, 27-38 % of them at >=5 m/s), **traffic that never sees the
player ahead** (player rear-ends traffic 4.3-11/min, the top player incident), and **the backwards route-node
reference** that makes rivals brake after they are already too fast (14 % of rival-seconds lose >30 % speed in 1 s).
Drafting is worth ~0 (stock aero coefficient is 0.0) and ramming does not exist (0 contacts while a rival was in
Block in 34 min of logs). Both are out of the plan.

## Plan (6 items, most valuable first)

### 1. Unstuck: stop reversing for 1.3 s when the car is merely slowed (S, high gain)
- What: require 1.5 s of slowness instead of 0.4 s, and 3.0 m/s instead of 5.0 m/s as "stopped".
- Address/bytes: `0x6b7680` `cdcccc3e` -> `0000c03f` (0.4 -> 1.5 s), `0x6b7684` `0000a040` -> `00004040`
  (5.0 -> 3.0 m/s). Readers: `0x451c2e`, `0x451c48/54`, `0x451eaf/ec5`, `0x451ffb/45202b`. V bytes (ai_stuck.md).
- Evidence: trigger is 0.4 s within a contact-list entry AND speed < 5.0, or >20 m off route, priority **500**
  (0x451c9b); recovery reverses at **-15 / -6 m/s** for 1.3 s with 6 s cooldown (`0x6b7674/78`, `0x462aa0`). V.
  Measured: 7.4-25.1 entries/min over 8 rivals, 27-38 % at >=5 m/s, time in 0xa up to 10.3 % of samples, single
  stops 13.7-17.9 s (ai_stuck.md). Rivals are NOT slow otherwise: 0.80-1.24x player speed, p90 32-44 m/s (paco).
- Risk: a genuinely stuck rival waits 1.1 s longer; the 20 m off-route branch still fires, so stuck% should not
  rise much. Both floats are read only by the stuck finders (V), so nothing else changes.
- Measure (same seed): AIR `% <2 m/s`, **entries/min**, `% time in 0xa`, max stop; AIHIT P>V. Pass: entries/min
  drops >=40 % and stuck% does not rise more than +1 point.

### 2. Traffic: the player counts as an obstacle (S, high gain, bytes already verified)
- What: goal-5 cars stop exempting the player above 20 m/s; rivals keep the pass-through.
- Address/bytes: 12 bytes at `0x4539db`, `8b 51 1c 85 d2 0f 95 c0 84 c0 74 18` ->
  `8b 49 14 83 79 04 02 75 1b 90 90 90`. V byte-for-byte (tomas, checked against the image).
- Evidence: `0x4539db` drops the obstacle when kind==6 and speed > 20 m/s (`0x6ccb4c`), so a goal-5 car never
  brakes for a fast player; the finder `0x44f470` also never reads slots behind (`0x44f4aa`). V. Player hits
  traffic 4.3-11/min vs traffic hits him 0-0.66/min (chela, tomas). Approach speed at 30 m gate `0x6b76e0` V.
- Risk: more braking/swerving ahead of the player = more sudden obstacles; that is the intended trade. Traffic
  queue behaviour worsens if item 3 is not applied (a braking leader in lane is exactly the permanent stop).
- Measure: AIT `%act3`/`%sp0`, `tp/min` (traffic hit by player), wall/min, and AIP distance/speed; pass on a
  visible drop of `tp/min` with wall/min and standstill length not worse.

### 3. Traffic: a standstill that never expires (M, high gain, host rule)
- What: give Avoid (type 3) an expiry: kind-3 car at `+0x3d4 < 0.5` and `act 3` for 6 s -> write `act+0x1e4 = 6.0`,
  arm one lane change (`ctx+0x394/0x398 = 1,0`), log it. C, `host/rivals.c traffic_tick`.
- Evidence: 30.6 % of traffic samples are < 0.5 m/s, `parked +0x4d1` is set on 0.3 % only, streaks up to 34 s;
  act 3 has no timeout and kind 3 never gets GetUnstuck; the only brake logic is leader 1..15 m -> 0 m/s, 15..30 m
  -> 6 m/s (tomas, V code + logs).
- Risk: host rule over game state (E7). Keep it opt-in (`RN_TRAFFIC_UNJAM=1`), one write per car per 6 s, and make
  it log `old/new` so a wrong write is visible in the same run.
- Measure: AIT `%sp0` (30.6 % -> target <10 %), longest standstill per run, `tt/min`; guardrail: `tp/min` and
  `wall/min` must not rise.

### 4. Rivals: one-sided route-node window (M, high gain, medium risk)
- What: drop the negative half of the speed-reference jitter, so the sampled node is 0..2b+1 ahead instead of
  -(b+1)..b.
- Address: load `[rec+0x50]` at `0x44c667` inside `0x44c550`; C equivalent `node = cur + Rng::NextMod(2*(b+1))`.
  A 2-3 byte cave; exact bytes U (no capstone in the worktrees: `ModuleNotFoundError`).
- Evidence: jitter range is `[-(b+1), +b]`, b = 8..4 by skill, held **5 s** (`[0x77a498] = 5.0`), so half the draws
  point at a node already passed (~110 m at 22 m/s). Braking exists only as `|target| + 2.0` vs speed in
  `0x45e970`: no brake distance, no radius (memo, V+D). 14 % of rival-seconds lose >30 % speed in 1 s, 188 of the
  472 with no impact at all, median 26.2 -> 14.0 m/s in one second (memo, V logs).
- Risk: earlier, smoother braking may read as "slower" and the node ahead may be a corner at lower cap sooner;
  wall hits could rise. This is the one item that can go either way, so it is measured, not assumed.
- Measure: median/p90 rival speed and **count of >30 % drops** in 1 s (memo's script), wall/min per rival, and
  `AILAP`-style lap time if present. Pass: drops fall >=30 % with median speed not down more than 3 %.

### 5. Rubber band: remove the blind WORLD handicap, optionally add real catch-up (S, medium gain)
- What: keep `racer+0x4b8` and `car+0x404` at 1.0 when the game writes < 1 in WORLD, or turn on real catch-up.
- Address: `0x44bffe` (store of the raw scale) / host `persona_step` cave; existing flags `RN_RBWORLD=1` (rosa) and
  `RN_FREECU=1` (`host/free.c:507` sets `[0x78a400] = 1`, curve x `RN_FREECUX`, default 0.35).
- Evidence: in WORLD `[0x78a400] = 0` (658/658 probes) so `0x44c010` returns 0,0; what is left is `(f-1)*v+1`
  with f ~0.95 -> `4b8` = 0.935..0.975, constant, **never > 1.00** in 22 runs. In race mode far behind is also
  SLOWED, not boosted (m=0.564 at -1000 m) (rosa, V).
- Correction to wave 1: the repeated `4b8 = 0.50` (paco) is the **host** `?pool=1` gang cruise (`gang_step`), not a
  game value; do not patch Speed.exe to "fix" it (rosa V, I for which runs are pooled).
- Risk: rivals ~3-6 % faster; with `RN_FREECU` the race becomes noticeably harder. Keep both opt-in and separate.
- Measure: every AIR line `s4b8 = 1.00` (or >1 with ECU) per rival; rival median/p90 speed; P>V events unchanged.

### 6. Wall hot spots: measure the clamp before touching the steering (S measure, fix unknown)
- What: no patch. Dump per frame `(car+0x1da - steerHeading)` and the `0x7060c0` output for the worst rival
  (ISHII in w_a) behind `RN_STEERLOG`, then decide.
- Evidence: 1.0-2.0 wall hits/min/rival in the s-baselines but 7.7-25.4/min in w_a/w_b/w_d-w_f, one rival holding
  ~20 % of hits (ISHII 272/1320, one every 1.3 s) with only 8-11 % low-speed time; hits cluster at 7 spots, and
  6 of 7 are not in the top curvature quartile, i.e. a wall next to the line, not a missed corner (beto, V).
  The clamp table `0x7060c0` values are past the raw `.data` -> U.
- Risk: patching a gain blind trades one wall cluster for another (beto's conclusion). Measure: that dump plus
  wall/min in the same seed. Gate: if item 4 raises wall/min, this is the next investigation, not a global gain.

## Rejected from my wave-1 list (evidence, do not re-propose)

- **Draft / slipstream**: `car+0x47c` exists but the aero drag coefficient `body+0x1e4 = phys+0x290` is **0.0 on all
  35 cars**, so the force path is skipped; the value is read only by `0x456830` (AI prediction) and the style item
  `0x43fa90`. Effect on speed: 0 m/s (yoli, V data + I). Making it real changes physics for every car.
- **Ramming**: no action aims at the player. Block steers into the pursuer's *lane*, 10..16 m ahead, and had 0
  contacts in 34 min; "te torean" is the player rear-ending traffic + Block cutting in (chela, V logs).
- **Widen Block** (my wave-1 #8) would make "cuts in front" worse, and Block is already 1-2 % of samples.
- **Traffic tick 2N** (`0x585e00`) is real (0.7 s at N=22) but items 2+3 cover the symptom for less risk.
- **Difficulty** changes only data (skill column `+0x10`, `[0x78a3fc]`, `0x77a400`), never AI code (rivals.md §4).

## Order and gates

1 -> 2 -> 3 -> 4 -> 5. After each: one same-seed ghost (s1 patch set + one change), commit the run id and result
here. Stop and re-read if a guardrail metric (stuck%, tp/min, wall/min) moves the wrong way. Items 1-3 are
reversible data/byte patches or host rules; item 4 needs capstone; item 5 uses a flag that already exists.
