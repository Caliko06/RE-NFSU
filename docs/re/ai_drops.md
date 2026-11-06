# AIHIT drops, wave 3: who writes the 8.1 m/s reset, and what it costs a rival

V = read in code/bytes/log, I = inference, U = open. No build, no run. Question: the 230 drops that land on 8.1 m/s (6
baselines, 46 cars) are a speed rewrite; **who** writes it (game or our host), under which thresholds, and what it costs.
Data: `runs/w_ai_s1..s3` (1200 s), `w_x_base`, `w_b`, `w_L3`; probes `w_p_a/b`, `w_r_a/b`.

## 1. Answer

1. **The game writes it, not the host.** Every one is `Car::ServiceResetRequest 0x4264d0` (once per sim step, from the car
   update `0x46a030`). For a rival (kind 2) it calls `0x427f70` with
   `speed = min(8.0, |car+0x3d0| * max(0, dot(car+0x818/0x81c, car+0x90/0x94)))`, the part of the current speed that
   survives turning onto the route, **capped at 8.0** (0x700d58 = `00000041` in pc/Speed.exe, read at 0x426617 and
   0x4312xx): a car entering at 26 m/s leaves at 8.0 and the next mover step logs 8.1.
2. **The host cannot make these drops.** `free_respawn` (host/free.c) writes `v = max(sp, 8.0)`, a floor, and only takes
   rivals under 2 m/s for 5 s or 400 m+ away, so a car at 26 m/s keeps 26; `still_r` (host/rivals.c) only recycles frozen
   or parked **traffic** 200 m+ from the player. Neither lowers a fast car. V code, I arithmetic.
3. **GetUnstuck is not it**: `0x452070` writes act+0x1e4 = -15.0 / -6.0 m/s (a reverse) and never raises the flag or
   moves the car; the 20.0 m off-route test (0x6b7690) only selects that action (docs/re/ai_stuck.md). **Trigger** is the
   flag `car+0x87c`, and for rivals the best fit is the game's "car is under the road" recovery `0x42a4d0` (§3, I).
4. **Cost**: each reset deletes ~19 m/s (median 26.8 -> 8.1) and the rival needs a median 3.0 s to be back at 95 % of its
   entry speed: the 230 resets are **3.0 % of rival time** (1.4 % of it below 15 m/s). V logs, §4.

## 2. The chain and its thresholds (V, code)

- `0x4264d0` tests `car+0x87c` once per step and dispatches by driver kind: kind 1 + ctrl+0x734 == 0 -> `0x4314a0` (human,
  same 8.0 cap at 0x4312xx); kind 3 -> `0x59a960` (traffic respawn); the rest (rivals) -> `0x427f70(car, section, node,
  speed, 1, dir ±1, 0, 0, lateral)`, which ends in `0x427c50` (writes position, heading, velocity).
- Writers of `car+0x87c` (all through `0x428080`, `car+0x87c = 1` unless `[0x78a368] != 0 and kind == 2`):
  | trigger | threshold | gate |
  |---|---|---|
  | `0x42a4d0`, same update, before the test | all wheels down (`car+0x3cc == 4`), `0x440a40` finds a surface, and `car+0x68 + 0.25` (**0x6cc90c = 0.25**) is **below** it: the car sank into the road | none, no contact, no speed test |
  | `0x47ac00` (collision response `0x474ca0` / `0x477300`) | crash stamp older than **1.0 s** (`(now-stamp)*0.00025 > 1.0`) and `car+0x58 < 0.1` | only after a collision |
  | `0x479e20` (nitrous/catch-up, from `0x4774a0`) | speed > **1.15 x** `RideInfo::GetTheoreticalTopSpeed` | stock cars never reach it |
  | `0x427ed0` (RESET / RESET_TO_POINT zone, from `0x44b1b0` AI, `0x430e00` human) | inside the polygon (height gate zone+0x14) | RESET_TO_POINT teleports to the zone point at exactly **8.0**; RESET skips kind 2 when `[0x78a368] != 0` |
  | `0x426930` JumpCamTrigger (no ground 32 frames, > 5000 m from route, 0x6b7bac) | | called **only** from `0x420b40` in MainLoop = the player's camera, not rivals |
  `[0x78a368]` inside a WORLD race is U (0 in Free Run, docs/openworld/re_zones.md).

## 3. Which writer fires (I; 230 drops to 8.1 with entry > 8.2 m/s, 223 in 8.2..60, 0.24..0.59 per rival-minute)

- **act at the drop: 7 JustDrive 201 (87 %)**, 1 Avoid 23, 0 Pass 3, 10 GetUnstuck 2, 5 Block 1; no act 14 (Accident, the
  action a wall crash installs), so `0x47ac00` is not the dominant writer. V (AIR/AIHIT).
- **224 of 230 have no car within 6 m** ("wall"); nearest car median 50 m, p10 32 m. Not a car-to-car contact. V.
- **Positions: 44 cells of 100 m** (top (1500,-300) 29, (2000,-500) 23, (1900,-500) 17); per car the median gap is 20..52 s
  and the median move 300..600 m: the car is not re-trapped in one polygon but recurs along the route, so a RESET-zone loop
  is out and a per-car geometry failure fits. **Verdict**: `0x42a4d0`, the sunk-car recovery (I). Residual: the 6 events
  with a car at 4..6 m and the 23 at act 1 (Avoid) could be `0x47ac00` after a contact. U per event.

## 4. What it costs (V, 6 runs, 36,224 rival-seconds)

| metric | value |
|---|---|
| speed lost instantly | median 26.8 -> 8.1 m/s = 18.7 m/s, 70 % of it |
| back to 95 % of entry speed | median **3.0 s** (n = 197 of 223, p75 8 s) |
| rival time in recovery, capped 15 s/event (strictly < 15 m/s) | 1,078 s = **3.0 %** (513 s = 1.4 %); uncapped 5,199 s = 14 % |

~0.4 resets per rival-minute; it reads as "that car died in the corner", not as a crash: no action change, nobody near.

## 5. The other families (unchanged from waves 1-2, condensed)

- **Grid re-place**: every rival drops at the same frame from the same value to 0.0 (`w_x_base` f3181: five cars 26.5 ->
  0.0, act -1, player standing) = `PlaceAllRacers 0x422a70`. **Traffic 6.1**: 238 of 243 `6.1` drops are kind 3, act 8 =
  `0x453c60` "6 m/s at 15..30 m, 0 at <= 15 m": facing a car at 15 m, traffic stops in one frame instead of braking (V log,
  I writer). **Garbage**: older unpatched runs read 8,000..37,000 m/s, drop > 70 m/s (0 in s1-s3). **No mode change**:
  AIBELT 0, no AIJUMP within ±6 frames. U for the tail.

## 6. Draft: opt-in change (not built, not run). The 8.0 cap is the harsh number

`host/rivals.c`, `ai_resetspeed` next to `ai_tune` (same pattern as RN_AI_STUCK: data float, every present, default off):
`RN_AI_RESETSPEED=<m/s>` -> `stf(c, 0x700d58, <m/s>)`; 8.0 -> 20.0 restores half the speed on a corner reset.
As a static patch: `0x700d58  old=00000041  new=0000a041`. Side effect, V: the constant is shared, so the human's reset
(0x4312xx) and the RESET_TO_POINT zone teleport (arg of 0x427e60) also come out at 20 m/s. Rivals-only alternative:
`0x427f70` is already hooked for RN_RESETLOG (`rn_call`, host/aitel.c); after the call, rewrite `car+0x3d0` and
`car+0x70..0x78` to `min(entry speed, X)` when kind == 2. Acceptance: same seed + RN_RESETLOG=1, each RSTA `sp` reads the new
value, the 8.1 count goes to 0, nothing else in the log changes.

## 7. Probe that settles §3 (one run, nothing built here: UNTESTED)

`RN_RESETWHY=1`, in the same `rn_call` hook before `0x4264d0` runs: log `car+0x3cc`, `car+0x68` minus the `0x440a40` surface
at the car (the 0x42a4d0 test) and `car+0x58` (the 0x47ac00 crash timer). Whichever fires is in the line. U: writer per event
until then; `[0x78a368]` in a WORLD race; the rival kind on the reset path; the ~10 % of drops at act 1/0.
