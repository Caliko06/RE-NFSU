# Cornering and braking of the AI rivals (Becario memo, 2026-11-04)

Question: how does a rival pick its target speed in a corner and when does it brake? Answer first, then the evidence.
Marks: V = read in code/decomp/log with an address or a number; I = inference; U = open. Original x86 only, nothing was run.

## Answer

1. **The target speed is a road-node byte, not a curve model.** `RacerAI::UpdateDesiredSpeed 0x44c550` reads
   `byte [node + 0x6a + lane]` (0..255) and builds `speed = byte x record+0x14 x ctx+0x4b8`. V (G+H). `record+0x14`
   = 0.95/0.96/0.97/0.98/0.99/1.0/1.0/1.0/1.0/1.0 for skill 0..9, so **skill changes corner speed by 5 % at most** (D).
   `ctx+0x4b8` is the rubber band. A byte of 0 becomes 30.0 m/s (`0x6ccac0`), i.e. "no cap" means 108 km/h, never "stop". V
   This branch runs only when `action+0x1f0 != 0` (JustDrive and the normal actions set it); otherwise the speed is the
   action's own `+0x1e4`. That is the "0x1f0 = speed from route" flag. V (0x44c550, `0x450210` sets 1, Draft/GetUnstuck/hit set 0).
2. **The node is picked with a two-sided random jitter, held 5 s.** Index = current node + `jitter`, where
   `jitter = Rng::NextMod(2*(b+1)) - (b+1)` → range `[-(b+1), +b]`, `b = record+0x50` = 8, 7, 6, 6, 5, 4, 4, 4, 4, 4
   (skill 0..9). Re-drawn every 5.0 s (`[0x77a498]` = 5.0, `0x6cca38` = 0.00025 s/tick). V (G+C+D). So **half the draws
   point behind the car**: the reference can be the speed of a corner the rival has already passed, for up to 5 s
   (~110 m at 22 m/s). This is the only "look-ahead" the AI has. There is no brake distance anywhere.
3. **It brakes only once it is already too fast.** `PsychoDriver::Update 0x45e970` (the only place that turns the target
   into pedals) compares `|desired+0x200| + 2.0` (`0x6b74a8` = 2.0 m/s deadband) with the car speed `+0x3d4`; only when the
   car is 2 m/s over target does it take the brake tables (`0x70057c/0x700598/0x7005b4`, clamp `-1.0`..0 `0x7003f8`).
   It is a proportional speed-error loop: no distance, no closing-rate, no corner radius. V (G, constants read from the exe;
   the `0x3f666666` 0.9 brake at 0x45f8e3 is the gearbox branch, not corner braking).
4. **Verdict: too fast into the corner, then a late and violent brake.** In 3 seeds (w_ai_s1..s3, ~118 s each) over 3,365
   rival-seconds: 472 speed drops >30 % inside 1 s (14 % of rival-seconds). 188 of them with **no impact at all** in the
   window (pure speed-reference drops; act 7 in 102, Avoid in 73): median **-44 %, 26.2 → 14.0 m/s in one second**.
   The other 284 end within a second in a ≥4 m/s impact and run 22.6 → 9.9 m/s. `AIHIT` kind 2: 213 events, 110 walls,
   103 car hits, in ~350 rival-seconds of racing — an impact every ~1.7 rival-seconds. V (logs).

## Numbers (AIR, 3 seeds, f > 3000, sp > 0.05)

| sample | n | mean | median | p90 |
|---|---|---|---|---|
| `route 1` (speed from the node byte) | 3,239 (98.0 %) | 22.3 m/s (50 mph) | 22.7 | 37.7 (84 mph) |
| `route 0` (action `+0x1e4`) | 64 | 12.3 m/s | 8.7 | 26.0 |
| JustDrive + route 1 | 2,259 | 24.4 m/s (55 mph) | 25.9 | 39.0 (87 mph) |

16 % of the JustDrive+route1 seconds are under 10 m/s (crashed or recovering), so the mean hides a stop-and-go pattern.

The `route 0` sample is small and slow because `+0x1f0 = 0` is set exactly by the slow-down actions: Draft (lead speed -
(20-gap), 0x450480), GetUnstuck (-15/-6), IJustGotHit, Accident. V.

## Why it is not merely "timid"

- The brake input only exists after the overshoot, so the car enters the corner at the *previous* node's cap (usually a
  straight's cap) and then loses ~44 % of its speed inside 20 m. That is the 0x1e4/x1e8 pair: `+0x1e8` (accel/gain) is
  0 while the route branch drives (fStack_20 = 0 at 0x44c7xx), so nothing ramps it. V.
- Skill does not help: the only per-skill knob on corner speed is `record+0x14` (0.95..1.0). What skill really changes is
  the *noise*: `b` = 8 for skill 0 vs 4 for skill 9 (a ±9 vs ±5 node window), so a slow rival keeps a stale or backwards
  reference far longer. V (D) for `b`, I for the effect.

## Patch

**No constant is clearly off**, so the patch is code, not data. `0x6b74a8` (2.0 m/s), `0x77a498` (5.0 s) and
`record+0x50` (8..4) are all defensible on their own; the fault is the signed jitter plus a proportional-only pedal loop.

Opt-in entry in `tools/recomp/patches.py`, gated by `RN_AI_LOOK=1` at build time. Site: `0x44c667` is the load of
`record+0x50`; the bias is `sub eax, esi` at **0x44c678**, right after `call 0x4216b0` (Rng::NextMod) and before
`mov [ebx+0x404], eax`:

| addr | old | new | meaning |
|---|---|---|---|
| 0x44c678 | `2bc6` (`sub eax, esi`) | `9090` (2 nops) | jitter `[-(b+1), b]` -> `[0, 2b+1]` nodes ahead |

Same length, no cave. Registers survive: eax keeps the NextMod result (stored at 0x44c67a), esi keeps b+1 but is dead
(reloaded at 0x44c691 from [ebx+0x3d8]), edx was only the pushed argument, and no conditional reads the sub's flags before
`test eax,eax` at 0x44c6b0. The node index is still clamped to `[0, nodes-1]` at 0x44c6b0. Max look-ahead: 17 nodes at
skill 0, 9 at skill 9. Not built or run here (rules: no build); `patches.apply()` was exercised over the real image with
the env on: 358 entries, all `old` bytes matched, `0x44c678` reads `90908983` after.

U: the byte is used as **m/s** (the 16.16 form `(byte<<16) * 1/65536` at `0x6cc83c` = 1.52587890625e-05 gives the byte
itself, and the observed 22 m/s / 50 mph means it cannot be mph). Who writes the lane index `[ctx+0x3d8]` and whether the
lane byte exists for every node (+0x6a..+0x7f is 22 bytes for 12 lanes) is U.
