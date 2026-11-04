# Traffic standstills: what keeps a car at 0 m/s, and the smallest unlock (RE 2026-11-04, becario tomas)

V = read in code/log (address or line), I = inference, U = open. Code = census/hopper/decomp.c (line numbers), patches.py not used:
the fix is a host rule (host/rivals.c, RN_AI_TRAFGO), so original mode is untouched.

## Answer first
A stopped traffic car is not waiting on a stale target: **its Avoid action re-acquires the same leader every think and writes 0 m/s into
act+0x1e4 with act+0x1f0 = 0**, and 0x583910 then hands that 0 to SetDesiredSpeed 0x45e180. Nothing in the action expires; the only way out is
the selector 0x44e020 building the default lane drive 0x44e2b0 (which sets act+0x1f0 = 1, route speed wins). That only happens when the finder
0x453920 reports **no car ahead in its lane at all**, and the finder has no distance limit (range 99999). So: leader within list reach ->
act 3 with target 0 or 6 m/s; leader stops -> the whole lane behind it stops and stays stopped. There is no timeout and no GetUnstuck for
kind 3 (AIT never shows act 10 in 30800 samples). V code + log, I for "stays stopped".

## The exit path, address by address (all V)
1. `0x453c60` Avoid update, brake branch: writes `ebx[0x79] = 0x40c00000` (6.0 m/s) when the obstacle is 15..30 m, `ebx[0x79] = 0` at <= 15 m,
   gain `ebx[0x7b] = 0x40000000` (2.0), and **`ebx[0x1f0] = 0`** (decomp 140644..140800: ebx[0x79] = act+0x1e4, 0x1ec = gain, 0x1f0 = speed owner).
   Gates confirmed in the image: 0x6b76e0 = 30.0, 0x6b76e4 = 15.0, 0x6b76e8 = 40.0 (rel speed), 0x6ccb4c = 20.0 (the goal-5 player exemption).
2. `0x583910` is the only consumer of act+0x1f0 (decomp 811858-811876): `eax = esi[0xfe]` (AI+0x3f8 = current action);
   `if (eax[0x1f0] != 0)` keep the computed route/lane speed, `else *edi = act+0x1e4` and gain = act+0x1ec. With +0x1f0 = 0 and +0x1e4 = 0
   the desired speed is 0 for as long as the action lives. Note also `if (esi[0x4d1] != 0) speed = 0`: the parked flag hard-zeroes speed.
3. `0x45e180` SetDesiredSpeed stores it: `mov [ecx+0x200], eax` (`ret 0x10`, asm.py 0x45e180). The PID 0x45e970 brakes to 0. No other writer
   exists for +0x200 in this path.
4. What ends act 3: `0x44e020` builds Avoid 0x453860 only when `0x453920` (finder) returns an obstacle; otherwise it calls `vt[6]`, the default
   lane drive ctor `0x44e2b0` (vtable 0x6c91bc), which sets **`esi[0x1f0] = 1`** (decomp 131457-131470). That is the whole unlock: +0x1f0 = 1.
5. The finder `0x453920` -> `0x44f470` (lane, lateral, range 99999.0) walks slots own-1 down to 0 and accepts the FIRST qualifier: lane
   |diff| <= 0.5 + half widths. Range 99999 removes any distance test, so a car 100 m ahead in lane still keeps the action alive. The
   neighbour list itself reaches `R = max(50, vt+0x50 * speed)` with route delta <= 3R, i.e. ~150 m at 0 m/s (I on the 3R bound, V on R).
6. Therefore: no stale slot is needed. A car whose leader has left the list, or whose leader is another permanently stopped car, never gets
   the lane drive back. U: whether the list can hold a car that no longer exists (a respawn teleport) - not seen in these logs.

## Numbers (AIT kind 3 within 80 m of the player, 7 runs; seeds w_ai_s1..s3 now full ~1130 s each)
```
run        dur_s samples  med  p90  %sp<0.5  %act3  tt/min  tp/min  tr/min
w_ai_s1     1128    8064   3.4 14.9     43.7   71.9    1.91    0.21    1.60
w_ai_s2     1138    7403   5.2 15.6     35.4   72.0    1.63    0.69    1.48
w_ai_s3     1137    6720   5.3 15.7     38.8   77.0    0.63    0.32    0.84
w_x_base     191    1458   0.0 13.8     54.0   85.9    0.94    0.94    0.94
w_a          345    1685   5.8 16.7     28.2   60.9   10.26    2.61    6.26
w_b          315    1488   6.0 16.7     27.7   60.6   12.00    2.10    8.19
w_L3         619    3982   5.1 15.9     37.4   74.0    1.45    0.78    0.68
ALL         30800   4.7 15.5     38.7   72.8
```
- Of 11137 samples stopped in act 3: **49% have no same-lane car at all inside the 80 m player window**; where one exists the gap is
  median 13 m (p25 6, p75 17, p90 33). 13 m is exactly under the 15 m full-stop gate, so they are parked on a leader they can see. V.
- Longest standstill seen inside the window: 34 s (w_x_base), 27 s (w_L3); act 3 is 72.8% of all samples. V.

## Proposed fix: host rule, opt-in (NOT VERIFIED by a run; this job may not build or run)
`host/rivals.c`, `trafgo()` (added above `traffic_tick`, called there before the existing guards): `RN_AI_TRAFGO=1` / `?trafgo=1`.
- Runs every 30 presents. For each kind-3 car with `ld(a+0x1f8) == 3` and speed `car+0x3d4 < 0.5` for 8 checks (4 s), it checks every car of
  the race list for one ahead within 12 m of the car's heading (+0x90/+0x94) and under 2.5 m aside. If none, it writes **act+0x1f0 = 1**
  (0x583910 then uses the route speed) and **act+0x200 = 0** (the obstacle id, so the next think re-acquires a real one), and logs `RNTGO`.
- Why this and not bytes: the same two stores are what the game's own lane drive ctor does (0x44e2b0), and the condition ("nothing within
  12 m ahead") is a host-side test that no single byte at 0x453c60 or 0x453920 expresses. A byte patch can only lower the 15 m gate
  (0x6b76e4) or shrink the finder range, which changes every car all the time instead of the deadlocked ones.
- AIT field that shows the effect: **`sp`** leaves 0.0 within ~1 s (it is `car+0x3d4`, the same value the rule tests) and **`act`** goes 3 -> 8
  once the finder stops firing; `RNTGO` lines in the log give the count per run, so tt/min and %sp<0.5 are the before/after numbers.
- Risk: a car genuinely stuck on a curb (its 7-33 wall hits/min, docs/re/ai_traffic.md) will be pushed forward anyway; the rule logs it, and
  RN_TRAFYIELD stays independent. Expected effect: %sp<0.5 down from ~39%, act 3 down from ~73%, queue tail length down. U until measured.

## Limits
AIT sees only cars within 80 m of the player, so "no leader" can only mean "no leader in view"; the list reach (150 m at 0 m/s) makes a real
leader invisible. The parked flag +0x4d1 is set on 0.3% of samples and even then a car can read 14 m/s, so this doc does not use it. The
`route` byte on the action (+0x1f0) is not logged for kind 3, which is why the AIT proof point is `sp` and `act`.
