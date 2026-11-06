# Traffic: how it drives (RE + logs 2026-11-04, becario tomas)

Base: docs/re/traffic_react.md (kept; its chain holds). V = read in code/log, I = inference, U = open.

## Answer in five lines
1. **Lane keeping**: a traffic car is on rails. The default action (type 8) follows its route node lane; there is no controller that
   steers back to a lane centre. 7 to 33 "hit a wall, no car within 6 m" events per minute per run (765 total) is what that costs. V log, I cause.
2. **Speed**: it crawls. Median 5.8 m/s (21 km/h), p90 16.1 m/s; per car the mean speed median is 6.8 m/s and **no car averages above 12.9**.
   A free car in type 8 does 12.1 m/s median, 17.7 p90. V (13011 AIT samples, 21 cars per run, 7 runs).
3. **It is in the Avoid action (type 3) 69.5% of the time** and type 8 30.5%; nothing else ever appears (no GetUnstuck for kind 3). V.
4. **A stopped leader freezes the queue**: 30.6% of all samples are speed < 0.5 m/s while the parked flag is set 0.3% of the time. Longest
   observed standstill inside the 80 m window: 34 s (w_x_base), 27 s (w_L3), 16 s (w_ai_s1). Of the standstills, 30% have a stopped
   traffic car 1..31 m ahead in the same lane; 67% have no leader in view, so they are standstills that did not expire. V/I.
5. **The player is only half seen**: goal-4 cars brake/honk/swerve for him, goal-5 cars skip him above 20 m/s, and no car ever looks
   behind. So the player rear-ends traffic (0.0 to 2.6 hits/min) far more than traffic hits him, and traffic-vs-traffic hits run
   0.5 to 12 per minute. V.

## Decision chain, verified 2026-11-04 (V unless marked)
| addr | what it proves | how |
|---|---|---|
| 0x583350 | one car per step: `kind==3`, `[0x6f08a4] % 2N`, odd only, index = /2; then 0x44ca70, 0x458cc0, route 0x44cf30 | decomp 811327 |
| 0x44e020 | selector: priority 600 = intersections (0x4543d0), 300 = `0x453920` then honk 0x44c2e0 then Avoid ctor 0x453860; else type 8 | decomp 131193 |
| 0x453920 | finder, range 99999.0; **goal-5 exemption at 0x4539db**: `mov edx,[ecx+0x1c]; test; setne; je` then speed vs `[0x6ccb4c]` = 20.0 | asm.py 0x4539c8 |
| 0x44f470 | slot walk starts at own-1 and goes DOWN to 0 (`esi = edx-1`, loc_44f4d1): cars behind are never read | decomp 134068 |
| 0x453c60 | Avoid update: lane tries in a loop of 4 (`var_20 < 4`) via 0x453ba0, else the brake branch | decomp 140502 |
| 0x45e180 | SetDesiredSpeed writes +0x200 speed, +0x204, +0x208, +0x20c flag; `ret 0x10` | asm.py 0x45e180 |

Constants read from the image: 0x6b76e0 = 30.0 (act+0x208 range), 0x6b76e4 = 15.0 (full stop), 0x6b76e8 = 40.0 (rel speed gate),
0x6b7604 = 0.5 (lane tolerance), 0x6b76d8 = 5.0 (dead test), 0x6ccb4c = 20.0 (goal-5 player exemption), 0x6b5db0 = 0.05 (brake light). V.
The patch bytes quoted in traffic_react.md for 0x4539db match the image byte for byte (`8b 51 1c 85 d2 0f 95 c0 84 c0 74 18`). V.

## Numbers (AIT/AIHIT, snapshot w_ai_s1 f18420 / s2 f19020 / s3 f17940; AIT logs kind-3 cars only within 80 m of the player)
```
run        dur_s cars samples  med  p10  p90  %parked %sp0  %act3 %act8 wall/min tt/min tp/min tr/min
w_ai_s1      264   21   1498   6.0  0.0 15.7     0.0   21.8  69.0  31.0   17.73   2.05   0.00   1.36
w_ai_s2      274   21   1586   6.0  0.0 16.0     0.0   23.3  62.5  37.5   16.64   2.19   0.66   2.41
w_ai_s3      256   21   1314  12.4  0.7 17.0     0.0    9.4  68.0  32.0   23.44   0.47   0.70   1.41
w_x_base     191   21   1458   0.0  0.0 13.8     0.0   54.0  85.9  14.1    7.23   0.94   0.94   0.94
w_a          345   21   1685   5.8  0.0 16.7     0.8   28.2  60.9  39.1   32.87  10.26   2.61   6.26
w_b          315   21   1488   6.0  0.0 16.7     1.3   27.7  60.6  39.4   32.19  12.00   2.10   8.19
w_L3         619   21   3982   5.1  0.0 15.9     0.0   37.4  74.0  26.0   12.60   1.45   0.78   0.68
ALL                   13011   5.8  0.0 16.1     0.3   30.6  69.5  30.5
```
tt = traffic hit with nearest car kind 3 under 6 m; tp = nearest kind 1 (player); tr = kind 2 (rival); wall = no car under 6 m. Counted
from AIHIT kind 3 only (a >= 4 m/s drop in one frame, host/aitel.c:88). tt/min is 0.5 down to 12 depending on run: the spread is bigger
than I can explain from the logs alone (U). 21 distinct kind-3 cars appear in every run, so N is at least 21.

## What actually stops a car, in order
- **Leader 1..15 m in lane** (act+0x208 = 30 m range, 15.0 and 30.0 gates): target 0 m/s, gain 2.0. Leader 15..30 m: target 6 m/s.
  This is the whole brake logic; there is no other. V code, matches the standstill clusters at d 13..30 m in AIT. V log.
- **Its own leader is stopped** and the lane-change test (0x453ba0, current/+-1/+-2) finds no clear lane, so it stays. Since act 3 has
  no timeout and kind 3 never gets GetUnstuck, the queue is permanent until the leader moves. V code + 34 s streaks. I for "permanent".
- **A junction**: a traffic car inside a junction is not an obstacle for others (0x44efd0 inverted), so two cars can enter the same
  junction and grill. V code (traffic_react item 4), no log counter yet (U).
- **The player parked in a lane**: only 108 samples (2.9% of standstills) show it, and only goal-4 cars plus goal-5 at < 20 m/s see him.
  So a parked player is a real, permanent lane blocker for part of the fleet. V log + code.

## Lane changes (what exists vs what the logs show)
Only two sources: the Avoid action picks current, +-1 or +-2 lanes with a 4 try loop, and the route lane drive changes lane when the
route node says so. There is no "overtake the slow car in front" rule outside Avoid, and no look-behind, so a lane change can be made
into a car coming from behind (no log counter for it: U). `|dlat|` per second is useless as a lane-change metric because lat is taken
against the player's heading (median 5.8 m/s of drift, p90 24.5): U, not measured.

## Smallest proposed change (nothing run, effect NOT VERIFIED)
1. Goal-5 exemption covers rivals only, so a player ahead is a real obstacle for every traffic car: 12 bytes at 0x4539db,
   `8b 51 1c 85 d2 0f 95 c0 84 c0 74 18` -> `8b 49 14 83 79 04 02 75 1b 90 90 90` (driver kind == 2 keeps the pass-through).
2. Stop the permanent standstill: give act 3 an expiry. C, host side (host/rivals.c traffic_tick): if a kind-3 car has +0x3d4 < 0.5,
   act 3, and the same condition for 6 s, write act+0x1e4 = 6.0 and arm the lane change (+0x394/+0x398 = 1,0) once; log it. Cheaper and
   reversible, but it is a host rule on top of game state (E7 warning). Bytes-only alternative needs a cave: U.

## Limits of this doc
AIT sees only cars within 80 m of the player and only 1 Hz, so every "%" here is "of traffic in view", not of the fleet. `parked`
(+0x4d1) is set on 0.3% of samples, so it does not mean "stopped"; it means something else (U). Free-flow speed of a single car was
never measured on a long uninterrupted stretch (U).
