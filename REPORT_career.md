# REPORT_career: rivals in a career race and steering feel (nfsu-c1, 2026-10-29, measure only)

## A. Rivals in a normal career race (event 1: circuit 1003, 2 laps, rivals WART, NESTO, JOSE)
- Chrome (`?career=normal&jump=e1`, RN_AUTOPILOT drives the player, no RN_FINISH): the race runs to the end on
  its own. Race 6/4 at frame 3118, finish 6/1 at 12234 (~148 s of driving), results 6/8, RewardPopup, back to the hub.
- Positions: RN_CARPOS cannot show racers. It is native only, and it walks L[9]..L[6] of L = [0x7361f8], the traffic
  sub-list. The racers are L+0x28[0..L[6]-1] (0x41ffe0 reads it this way). Here L[6] = L[9] = 4.
  So a native run of the same input used RN_WATCH on the 4 cars: x,y at car+0x50/+0x54, speed at car+0x3d0,
  +0x404. The kind [[car+0x14]+4] is 1 for c0 (player) and 2 for c1..c3 (rivals). Run dir: runs/rivA/log4.txt, log5.txt.
- Result: **3 rivals spawn (the event's +0x128 = 3), all 3 run both laps and none vanishes or stops before the line.**
  They finish together at ~190 s (spread 8 m) and wait at the line. The autopilot player hit walls at 94, 131 and 173 s,
  and the rivals pulled 200-560 m (straight line) ahead.
- Spread between rivals: 117-175 m in lap 1, 34-69 m in lap 2. Rival speed fell from 55-68 to 37-52 (car+0x3d0 units)
  while the player was far behind. This looks like the rubber band slowing the leaders (0x44bd10) (I).
  +0x404 read 1.00 the whole race. That fits "max(scale, 1.0)" for leaders that are never boosted (I: object offset not proven).
- Which OWNER notes apply to a career race: **none.** PLAN.md:37 ("only 3 rivals, they vanish fast") and
  re_rival_turnback.md:3-4 (a rival leaves in 8-20 s) are WORLD/Free Run. There, racers follow the tour direction
  (0x45d640) and free_respawn moves them. In a career race the count is the event's own data, and rivals stay on the track.

## B. Steering feel (keyboard; RN_STEERLOG, host/input.c:549)
- Input: profile asas drives with W (throttle) and A/D (steer), not arrows. The arrows are not in the in-race action map:
  with them the car never moved, native or Chrome (runs/steerB/log.txt, log2.txt; RN_DILOG shows key events, no app action).
- Same RN_KEYS script both sides: Quick Race 1003, W held, A held 1000 ms. Native runs/steerB/log3.txt, Chrome scratch B2.
  | | key -> in (P+0x28c) | out P+0x1d0 at +3 / +6 / +30 frames | full | release -> 0 | frame |
  |---|---|---|---|---|---|
  | native | same frame | 2906 / 3235 / 4949 | 5348 at ~36 f | 9 f (150 ms) | 17 ms |
  | Chrome | same frame | 1730 / 3084 / 4388 | 5021 at ~42 f | 9 f (150 ms) | 16.7 ms |
  The differences follow speed: the cap S+0x74 grows with hold time S+0x14 (0 -> 1 over ~0.55 s), and it also depends on
  speed (native 22 vs Chrome 23.6). Page keydown -> game key state: the next frame (<= 17 ms; page present log).
- Addresses: event 0x461840 (STEER 0x87/0x88) -> P+0x28c; per frame 0x461650 -> 0x460930 -> 0x460a80 (angle cap by
  hold time and speed, digital flag [0x736514] = 0), 0x460de0 rate limit -> word P+0x1d0.
- Conclusion: the port equals native within 1 frame. "Rigid, late" is EA's keyboard model, as b28db5c found on 2026-10-26.
- Proposal: the A/B already exists as ?steer=pad (PATCH 0x4609e3/0x460a80/0x460b4f/0x460c02, the gamepad model:
  full angle at once, cap by speed only). A middle variant would be a faster hold-time ramp S+0x14 behind a switch.
  It would be one A/B strip on the same corner for the OWNER to pick. No code was changed.
