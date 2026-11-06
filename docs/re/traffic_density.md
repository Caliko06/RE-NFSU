# Traffic density in WORLD: the knobs and where the cars actually are (2026-11-03, becario lalo)

Question: why is traffic sparse in WORLD, and which values move it. Read-only on `pc/Speed.exe`; nothing was built or run.
Marks: **F** = read in code or log, **I** = inference, **NV** = not verified. Sources: `docs/re/traffic.md`,
`docs/openworld/re_traffic_racers.md`, `docs/openworld/re_spawn.md`, `docs/openworld/re_traffic_teleport.md`,
`host/rivals.c` (traffic_refill), `host/free.c` (free_setup, free_traffic, free_tmove), `tools/recomp/patches.py`
(PATCH 0x4b3b01 block), `tools/recomp/caves/traffic.s` (count), and the TRAFLOG/REFILLWHY lines of `runs/w_L1..3`,
`runs/w_x_base`.

## Answer in one paragraph

The pool is fixed and small: WORLD asks 14 cars, the cave makes it x1.5 = 21, hard cap 26 (**F**). Nothing spawns or
despawns; cars are moved (**F**). Two inserters put them back, and both have a **floor on distance**: the game's teleporter
walks 250 m ahead (`0x6b5a38`) and the host refill tries 150..650 m (**F**). So a reused car almost never lands inside
100 m: it lands in the 150..250 m ring. The measured logs show exactly that: near250 sits at the refill pool gate
(median 17..18, capped at 18) while near100 is median 7..8 of 21 cars (**F**). On top of that the refill rejects
most of its attempts on the spacing test (74..88 % of REFILLWHY failures), because it lands on one road chain where
cars are already 18 m apart (**F**). Sparse = few cars total, all of them parked in a 100 m ring just outside what you
see, and the refill stops as soon as 18 are within 250 m (**F** host gate `REFILL_POOL 18`).

## Knobs

| # | Address / const | Now | What it does | Effect on near100 | Mark |
|---|---|---|---|---|---|
| K1 | `host/free.c:168` `FREE_TRAFFIC` (WORLD 14) | 14 | WORLD's base count before the x1.5 cave | pool +3 per +2 base | F |
| K2 | cave `0x63b280` count (patches.py `0x4b3b01`) | `n*3/2`, cap 26 | multiplies the track row count, cap 26 (rides cap 30 at `0x4322a0`, 4 racers) | +1 car = +1 possible near | F |
| K3 | track row `+0xd4` (GLOBALB, 1010) | 31 m | spacing the placer demands between cars (`0x59aa60` / `0x59b1e0`) | none directly | F (docs/openworld/re_traffic_rivals.md) |
| K4 | `0x6b5a38` f32 (1 ref in free run, 5 total) | 250.0 | walk distance of `0x59a2c0` **and** reject radius of `0x59ad90` | lowering it moves the ring toward the player | F (bytes `00007a43`) |
| K5 | `0x6b5a3c` f32 | 500.0 | give-up distance of the walk (route distance) | none | F (bytes `0000fa43`) |
| K6 | `0x6b5a30` f32 | 1.0 s | Free Run teleporter tick (`0x59ae60`) | rate only | F (bytes `0000803f`, 1 ref) |
| K7 | `0x598725` `83 c0 01` | 1 car/tick free, 22 route | cars the teleporter checks per tick (`(route?0x15:0)+1`) | rate only | F (bytes `83e01583c001` at `0x598722`) |
| K8 | `host/rivals.c:662` `REFILL_NEAR` / `REFILL_POOL` | 14 / 18 | refill runs while fewer than 18 are within 250 m; a parked/frozen car always goes | **the binding gate**: raising it lets more cars stay near | F |
| K9 | `host/rivals.c:718` band | `150+80*(t%6)+rnd%100` m, 8 tries | where the refill inserts | **raising the floor is why near100 is low** | F |
| K10 | `host/rivals.c:728` | `>= 150` m from player | minimum distance for a refill spot | same as K9 | F |
| K11 | `host/rivals.c:731` | `>= 18` m from every driving car | spacing for a refill spot; 74..88 % of REFILLWHY failures | blocking most attempts | F |
| K12 | `host/rivals.c:668` `STUCK_PRESENTS 600` | ~10 s, >= 200 m | parked/frozen recycling timer | low | F |
| K13 | `0x59b3e0` + free_spacing | 99999 -> 31 m | density gate on the game's own move (`docs/openworld/re_traffic_teleport.md`) | 0 on the host path (refill bypasses it) | F / I |
| K14 | TRAFFIC_DENSITY zone `+0x7c` (0x3414a) | per zone, 35..190 m | spacing when the player is in a zone and no stopped car within 250 m | only the game's teleporter | F |

## Measured (TRAFLOG every 300 presents; mean / median / p25 / p75 / max)

| run | samples | presents | near250 | near100 | parked | refill/1k presents | near250 >= 18 |
|---|---|---|---|---|---|---|---|
| w_x_base | 38 | 14,100 | 16.9 / 18 / 16 / 19 / 20 | 9.2 / 9 / 7 / 12 / 14 | 0.0 % | 10.6 | 25/38 |
| w_L1 | 119 | 38,400 | 16.9 / 18 / 15 / 19 / **21** | 7.5 / 8 / 5 / 9 / 17 | 0.8 % | 21.8 | 69/119 |
| w_L2 | 121 | 39,000 | 16.0 / 17 / 14 / 18 / **21** | 7.4 / 7 / 6 / 10 / 16 | 0.8 % | 25.6 | 49/121 |
| w_L3 | 124 | 39,900 | 16.0 / 17 / 14 / 18 / **21** | 7.9 / 8 / 6 / 10 / 18 | 1.6 % | 24.3 | 58/124 |

near100 == 0 in 0..3 % of samples, so it is not "no traffic", it is "traffic parked in the 100..250 m ring".
Cumulative REFILLWHY at the end of each run (walk / spacing / lane): w_x_base 41/415/33, w_L1 44/1968/254,
w_L2 105/2259/471, w_L3 61/2472/278, `early 0` in all four (**F**). Failure mass is the spacing test, 74..88 %.

Reading of the numbers:
- near250 median 17..18 against `REFILL_POOL 18`: the pool gate is closed most of the time, so the refill only
  replaces parked/frozen cars and cannot build a denser ring (**F**, 49..69 of 119..124 samples at or above 18).
- The gap near250 - near100 = 9..10 cars is the insertion band 150..250 m doing its job (**F** K9/K10 + the run numbers).
- w_L1..3 refill at 2.2..2.6 refills per 100 presents vs 1.06 in w_x_base: the L runs already carry the refill tuning,
  x_base is the older/slower config (**F** numbers, **NV** which build each one is).

## Proposal: 3 values to try, with expected near100

Ordered by expected gain per risk. All change a host constant; only P2/P3 touch exe bytes.

| P | Change | Why | Expected near100 (median of 21 cars) | Mark |
|---|---|---|---|---|
| P1 | `REFILL_NEAR 18 -> 21`, `REFILL_POOL` unused at 21, band `150+80t -> 90+70t`, ok `>= 150 -> >= 90` | closes the gate exactly when the ring is full; the floor stops pushing cars out of sight | 8 -> **11..12** (near250 stays 21) | I |
| P2 | `0x598725: 83 c0 01 -> 83 c0 04` (4 cars/tick in free run, route 22 -> 25) and `0x6b5a30: 1.0 -> 0.35` | the game's own teleporter only checks 1 car/s; 4 cars every 0.35 s recycles parked and behind cars ~11x faster | 8 -> **9** (fills to near250 21 sooner) | I |
| P3 | `0x6b5a38: 250 -> 175` | the walk and the reject radius land cars at 175 m, inside the ring the refill feeds | 8 -> **9** (and near250 gate reached sooner) | I, risk: 5 refs, also route mode |
| P4 (if more is wanted) | `FREE_TRAFFIC 14 -> 17` (x1.5 = 25, cap 26) **with P1** | 4 more cars in the pool; alone it only feeds the 250 m gate | 8 -> **10** with P1, 8 -> 8 alone | I |

Why not the obvious ones: the track row spacing (K3) is data in GLOBALB, not an exe constant; `0x6b5a38` is shared
with route mode (the doc warns not to edit it casually); the cave count (K2) can only reach 26 and collides with the
entrant cap 30 minus 4 racers, so it buys +4 at most (**F**).

## Check for each proposal (not run here)

One native WORLD run per row, `RN_FREELOG=1`, 240 s, and compare the TRAFLOG medians of near100/near250 plus the
REFILLWHY spacing share. Pass = near100 median up by the expected amount with near250 <= 21 and no new `fail` mass.
P2's route-mode count (25 per 0.3 s tick) must be watched in one career race before it ships.

## Files

- Candidate byte patches: `tools/recomp/cand/lalo.py` (list, `when=lambda: False`, `old` bytes verified against
  `pc/Speed.exe` by running that file; it is not wired into `patches.py`).
