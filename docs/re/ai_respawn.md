# Rival respawn cadence (wave 3)

Question (OWNER 2026-11-04): `free_respawn` (`host/free.c:299`) placed 519 rivals in three 1200 s runs, ~1 every 7 s, at the player's
speed and 100-700 m away. Trigger rules, state before each respawn (stuck seconds, d behind), share that lands within 150 m ahead
(visible pop-in), and whether this is the rival "teletransportándose" the OWNER sees. Marks V = code/log, I = inference, U = open.

## Answer

- **519 lines** in `w_ai_s1..s3` (219/156/144): **24** from the opening pass (frame 3540 and its failed rival's retry at 3600) and
  **495** from the 1/s respawn, i.e. one every **7.3 s** (11.0 / 7.8 / 7.2 per minute per run). V
- **Triggers: 94 % distance, 6 % stuck.** Before a distance respawn the rival was a median **480 m** away (min 400) and **57 % behind**
  the player. Before a stuck respawn it was a median **77 m** away (p10 13 m) at **0.4 m/s**; only 8/28 had AIR `stuck >= 5`. V
- **Landing: 5 % (25/495) within 150 m ahead**, 8 % within 200, 19 % within 250, **30 % within 300**; 64 % land behind. So at 300 m the
  player gets a rival appearing in his windscreen **~2.5 times a minute**, at 150 m ~0.4/min. V
- **Yes, this is the rival teleport** (I on visibility). The other teleporter is the traffic refill (`host/rivals.c`, `REFILL_MIN` 150 m)
  and it moves kind 3 only. The vanish side is rarer: 3 % (13/495) sat <= 150 m ahead, all stuck-triggered. V counts, I sight.

## Trigger rules (V, `host/free.c`)

- **Clock:** `free_tick`, once a second (`presents % 60 == 0`, line 556), only after `start + 600` (10 s, line 576).
- **One rival per second:** the first success returns (line 380). The first candidate **in race-list order** wins, not the farthest.
- **Distance:** kind 2 entrant, straight-line `hypot >= RN_RIVALFAR` (default **400 m**, line 302). Any direction: there is **no
  "behind for N s" rule** for rivals (unlike traffic, `host/rivals.c` 4 s and 130 m).
- **Stuck:** net displacement **< 2.0 m over 1 s, 5 s in a row** (`st5[].slow >= 5`, lines 319-321), whatever the distance. It counts
  displacement, not speed, which is why it fires more often than AIR's speed-based `stuck`: 20/28 have AIR `stuck < 5` (V/I).
- **Cooldown:** 480 frames = **8 s per rival** (line 328); the log's smallest same-rival gap is exactly 8 s, 28 cases. V
- **Spot:** the player's node (0x428150/0x428160) walked **220..379 m of road** (`m0 = 220 + rnd % 160`, line 338) with 0x4563d0 along or
  against the node direction (coin, line 337), one try, accepted if 0x456c90 validates it and it is > 31 m from every car (line 356).
  There is **no straight-line minimum**, so a hairpin lands the car close: s3 TJ 49 -> 32 m ahead, s3 KAZ 3 -> 201 m.
- **On arrival:** the game's own AI reset `0x427f70(car, section, node, player speed, 1, dir, 0, 0, 0)` (line 372); speed = the
  player's (min 8 m/s, 0x700d58, line 366): median 12 m/s, 75 cases >= 40 (the AIJUMP family, docs/re/ai_jump.md).
- **Opening pass** (separate, lines 572-574): once, 90..340 m, alternating ahead/behind; `RN_RIVALOPEN=0` off. Not touched by the patch.

## Per-respawn state from AIR (495 regular; AIR line at the frame before and after)

- before: 57 % behind, 43 % ahead; 77 % were already past 400 m one second earlier, 94 % at the trigger (`was`, median 480 m); 6 % stuck
  (median 77 m, p10 13 m).
- after: |d| 0-99 m 8 %, 100-199 6 %, **200-299 49 %**, 300-399 35 %; ahead 36 %, behind 64 %.
- landed ahead <= 150 m: 5 % (25), of them 4 stuck-triggered, 21 distance-triggered; every one is a car the player did not see before.
- exact addresses for one case: s3 f45720 TJ, stuck at 49 m ahead (was 49), reappears 32 m ahead, 8 m/s (log line of that frame).

## Proposed patch: `RN_FREE_SOFT=1` (opt-in, stock mode untouched)

Rule: the 1/s respawn never moves a rival the player can see in front of him, and always puts it **behind**, at least **150 m** back
along his forward vector (his motion, else his heading car+0x90/+0x94, as `host/aitel.c` AIP reads it). 4 walk tries, each 60 m farther,
never the other way; 150 m is the traffic refill's own out-of-view distance (`REFILL_MIN`, `host/rivals.c:664`). Drafted in
`host/free.c` (lines 279-294 helper, and 324, 337, 343, 346, 358 in `free_respawn`):

```c
if (!open && soft && rx * fwx + ry * fwy > 0 && rd < far) continue;      // in front and in sight: not this one
int ahead = open ? !(nr & 1) : soft ? 0 : rnd(&seed) & 1;                // soft: always behind
for (int t = 0; t < (open || soft ? 4 : 1) && !clear; t++) {             // soft: 4 tries, same way
    ... a[3] = (along == (ahead ^ (soft && !open ? 0 : t & 1)));
    if (clear && soft && !open && (nx - px) * fwx + (ny - py) * fwy > -SOFT_MIN) clear = 0;
```

It logs `FREE soft respawn: behind the player, >= 150 m, ...` once and adds ` (soft)` to each respawn line. `RN_FREE_SOFT=0` (default):
byte-for-byte the old path. **Not compiled or run** (the brief forbids building); `cc -fsyntax-only host/free.c` passes -> syntax V,
behaviour U.

## Open (U)

- The car draw distance is not measured: "300 m ahead is visible" is an inference, not a number.
- With soft on, a rival > 400 m ahead is still moved (lands behind); if the draw distance is over 400 m that one would still pop out.
- Soft leaves the opening pass as is on purpose (it answers a different OWNER complaint).
