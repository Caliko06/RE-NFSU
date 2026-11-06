# The (1846,-727) speed spikes and the no-pool menu traffic path (2026-11-04, becario yoli)

Question (HANDOFF "Open", AI_SCOPE §3): what is at (1846,-727) that makes rivals spike one frame, and does the menu
path without `?pool=1` spawn traffic at all. Read-only: no game run, no Chrome, no build. Marks: **F** = read in a log
or in data, **I** = inference, **NV** = not verified.

## 1. Short answer

- (1846,-727) is **ordinary flat street**, 11 m wide, three tracks deep (1001, 1103, 1104 all lay the same ground tiles at
  z = 52.9). No RESET / RESET_TO_POINT zone, no smackable prop, nearest wall 6 m west. **F**
- The rivals' "wall" hits there are **not a wall**: AIHIT takes the position of the car itself and labels "wall" only
  because no other car is within 6 m (`host/aitel.c:10-11, 90-93`). At the impact the car's z reads 53, i.e. on the road.
  **F**
- The real anomaly is the **number**, not the car: in `runs/w_a` car `017cfbb0` loses 6-7 m/s per frame for 6 frames
  (43.7 -> 8.2) while its position still advances ~0.8-1 m per frame, then gains **+19.8 m/s in one frame** (8.2 -> 28.0)
  with the same position and the same distance to the player (1456 m). **F**
- Cause **unknown**. Next probe = log `(vx,vy)` and |Δpos|/Δt next to `sp` (car+0x3d4) for that one car; whichever of the
  three disagrees is the field to RE. **NV**

## 2. Evidence, the spike (F)

Three runs hit the same rounded point, one car each, so it is the geometry, not one bad rival:

    runs/w_d/log.txt:2555  AIHIT f5237  kind 2 car 0171d130 sp 20.6 -> 15.9 act 7 wall (nearest kind 2 at 91.8 m) d 558  at 1846,-727,53
    runs/w_a/log.txt:17230 AIHIT f12390 kind 2 car 017cfbb0 sp 28.0 -> 15.4 act 7 wall (nearest kind 2 at 403.2 m) d 1456 at 1846,-727,53
    runs/w_b/log.txt:20286 AIHIT f14299 kind 2 car 017149f0 sp 18.3 -> 13.5 act 7 wall (nearest kind 3 at 258.5 m) d 616  at 1846,-727,53

The frame-by-frame cluster is `runs/w_a/log.txt:12383-12390` (HECTOR, car `017cfbb0`):

    f12383 sp 43.7 -> 39.3 at 1842,-727,53
    f12384 sp 39.3 -> 34.0 at 1844,-726,53
    f12385 sp 34.0 -> 28.1 at 1845,-726,53
    f12386 sp 28.1 -> 21.7 at 1846,-726,53
    f12387 sp 21.7 -> 15.1 at 1847,-726,53
    f12388 sp 15.1 ->  8.2 at 1847,-726,53
    f12390 sp 28.0 -> 15.4 at 1846,-727,53     <- +19.8 m/s in one frame, no movement

`d` (distance to the player) is 1454, 1455, 1455, 1456 over the same frames and the position never leaves a 5 x 1 m box.
A car cannot lose 36 m/s in 6 frames and cannot regain 20 m/s in one frame without moving; one of the logged fields is
not the car's real motion. `sp` is `car+0x3d4` (`host/aitel.c:55`); the AIHIT trigger is `sp_before - sp >= 4 && sp_before > 5`
(`:89`), so the whole cluster is one slow car whose speed field collapses and snaps back. **F**

## 3. What is physically there (F, data decoded with `tools/openworld/polys.py` against the 16 TRACKB)

- Ground: three quads of tracks **1001, 1103, 1104** cover the point, identical bytes, `surf 1`, `flags 0x10/0x11`
  (horizontal, 4 vertices), all at **z = 52.9**. Tiles are ~3.5 x 3.8 m, so it is a normal road surface, tiled.
- Walls: nearest is the vertical `flags 0x12` quad **x = 1840.2** (y -721 .. -724 and -724 .. -739), i.e. **6 m west**,
  then x = 1864.5 (18 m east), x = 1841.9 at y = -741.9 (15 m south). Nothing within 6 m, so nothing at the car.
- Zones (chunk 0x3414a) containing the point: only **TRAFFIC_DENSITY** (one per track, huge 1000 m boxes). **No RESET or
  RESET_TO_POINT row covers it**, so the zone teleport 0x427ed0 / 0x4314a0 (`docs/openworld/re_zones.md`) is not the cause.
- Props: no smackable instance within 20 m (`census/openworld_props.json`); nearest are a no-parking sign 20.7 m away and
  `XO_WARNTROLLY_1B_00` 23.4 m away.
- Traffic drives through it: `carpos ... k3 1845.7 -726.3` (`runs/w_i/log.txt:821`), `k3 1849.5 -742.8` (`w_h:1016`),
  `k3 1849.4 -729.1` (`w_e:1474`). The street is on the tour.

**I**: a rival that decelerates that hard on flat, open road is reacting to something the logger cannot see (its own
action speed write, a ground/contact flag, or a neighbour that is not in the race list), or `car+0x3d4` is being written
by a path that is not the physics. The three candidate writers are the AI action speed (`+0x1e4` / `+0x1f0`),
0x427ed0's reset (ruled out here: no zone) and 0x4314a0's route respawn (would move the car, it does not).

## 4. Next probe (bounded, one cause)

1. Reuse the AIHIT call site: when kind 2 and the drop is >= 4, also log `vx,vy,vz` (car+0x70/74/78),
   `hypot(x - prev_x, y - prev_y)` and `car+0x404` (speed scale). 30 lines, no game change.
   Reading: |v| matches `sp` and the direction flips -> contact response; |v| matches the *position* delta -> `+0x3d4` is
   stale/garbage; both agree and the position is what lags -> the mover (mode 4 / free_tmove) is involved.
2. One native run with `RN_SHOT_FRAMES=12383-12390` on the same seed (RN_SEED=1) to see the car (`docs/openworld/AI_SCOPE.md` §6).
3. Only then RE the writer the probe names (ghostreport counts it as one AIHIT cluster, not as "wall hits").

## 5. The no-pool menu traffic path (F, and what is still open)

Traffic in WORLD does not depend on `?pool=1`: the pool flag is only gangs and livery
(`host/rivals.c:465` `rn_pool() && track == 1010`, `:359-360` pool lines). The chain that puts traffic on the road from
the Free Run menu is:

- `host/free.c:43-52` `world_ai()`: track id `[0x78a2f0] == 1010` -> AI on (8 rivals + 21 traffic; `?ai=0` off).
- `host/free.c:164-170`: `AddTrafficCars` count read from the track table (`[0x441fe0()+dir+mode*2+0xc0]` = 12 on 1001 and
  1010) raised to 14, then x1.5 by 0x57d060 -> **21 cars**, and put back after the race.
- `host/rivals.c:687` `traffic_refill()` in WORLD: on by default, `RN_TRAFREFILL=0` off; `:843` writes `[0x700740] = !world`
  (BeltMover off in WORLD); `:417-419` `traffic_spacing()`.
- Measured only through `TRAFLOG` (`host/rivals.c:638`): cars, parked, near250/near100, refill/fail, yields, dodges.

So "the no-pool menu path never ran" is an **acceptance gap, not a code gap**: one menu Free Run into WORLD without
`?pool=1`, `TRAFLOG` present with `cars ~21`, `near100 > 0`, closes it. **NV** (never run per HANDOFF).

## 6. Patch

None proposed: the cause is not established, so `tools/recomp/cand/yoli.py` holds an empty list and the bytes that the
probe above would have to justify. Nothing was added to `tools/recomp/patches.py`.
