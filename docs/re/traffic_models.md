# Traffic models: which of the 15 usage-2 rows appear, why not, and what it costs

Read only. F = read in code (objdump on `pc/Speed.exe`, base 0x400000) or in a run log, I = inference, NV = not verified.
Earlier notes (`docs/re/traffic.md`, `traffic_limits.md`, `traffic_cap.md`) were leads; every claim below was re-read.

## Answers first

1. **Today, stock: 6 of 15.** Only rows with weight 1.0 in district column 0 can be drawn, and every shipped track id is
   >= 1000, which always selects column 0 (`0x57d00d` `cmpl $0x3e8`; `0x57d060` `flds 0xc60(%eax,%esi,4)`, esi = district).
   The nine zero-weight rows are never drawn: TAXI, AMBULANCE, COUPE, FIRETRUCK, 4DR_SEDAN, BUS, MINIVAN, HATCHBACK,
   HATCHBACK02. Nothing else stops them: the row filter `0x57cfa0` only tests usage == 2 (`0x57cfcd` `cmpl %esi,%ecx`),
   `+0x40 != 0` (all 35) and `+0xd9 > 0` (all 15 have 1..8 paints). F
2. **With the cave that is already on (0x57d060 -> 0x63b270) plus `RN_TRAFMODELS=1` (already in `tools/openworld/ghost.sh`),
   all 15 appear.** Measured, not inferred: `runs/w_st_s2/log.txt` (track 1010, 21 cars) prints
   `models 18` with all 15 traffic names plus GOLF NEON INTEGRA, e.g. `... BUS FIRETRUCK ... AMBULANCE ...`. F
3. **Exact change for fair odds over the 15 rows: none needed for weight**, the cave gives 1.0 to every usage-2 row that
   has any nonzero district weight, and `RN_TRAFMODELS` writes the 3 missing rows (22 AMBULANCE, 26 FIRETRUCK, 30 BUS) to
   1.0. The only unfairness left is the cave's 8 racer rows at 0.375: 8 x 0.375 = 3 of 18 total, so a traffic row gets
   1/18 = 5.6 % instead of 1/15 = 6.7 % and 16.7 % of draws are racer cars. Set the cave's `stock` mask (0x63b270) to 0 to
   make it exactly 15-way. If the cave is ever off, two 7-byte patches give the same result without data:
   `0x57d060` and `0x57d0c1` `d984b0600c0000` / `d984b1600c0000` -> `d9e8 9090909090` (fld1: every row the iterator
   returns weighs 1.0; with the stock iterator that is exactly the 15 usage-2 rows). Draft: `tools/recomp/patch_drafts/tomas_traffic_models.py`. F/I
4. **A model costs, per unique model, one geometry and one texture file**: GEOMETRY.BIN 60,240..89,504 B, TEXTURES.BIN
   4,616 B except AMBULANCE 11,280 B (measured with `stat` on `game/Cars/*`). Loaded once per model, not per car: in
   `w_st_s2` the `flow open CARS\BUS\GEOMETRY.BIN` line appears exactly 1 time with 21 cars on the road. Resident
   memory is larger than the file and was not measured (NV). F for the files, NV for RAM.
5. **Where the unique-model limit is**: the pools that hold loaded rides are 40 slots each, `LoadedCarSlotPool` `0x58b213`
   (`movl $0x28,%edi`, size 0x1f4), `LoadedRideInfoSlotPool` `0x58b250`, `LoadedWheelSlotPool` `0x58b1d3` (docs/re/traffic_cap.md,
   F). 15 traffic + 8 racer + player = 24, so they do not bind at 15 models. Whether `0x58c3b0` caches per type or per
   entrant is NV (it walks a list at ride+0x4c and evicts, 1000 tries at `0x58c3c4`). F/NV
6. **What really caps a bigger model set is the car count, not the models**: the race list holds 32 cars
   (measured `STOP 0042119a` with 45 entrants, traffic_cap.md) and the entrant table is 30 (`0x4322e6` `1e`). So 21 to 23
   traffic cars is the ceiling today; 15 models is below every model-side pool. F

## Per row (usage 2 only; weights +0xc60..+0xc70 = districts 0..4)

| row | name | weight d0 | d1 | d2 | d3 | d4 | stock | cave | cave+RN_TRAFMODELS | blocker |
|---|---|---|---|---|---|---|---|---|---|---|
| 20 | TAXI | 0 | 0 | 1 | 0 | 1 | no | yes | yes | weight 0 in d0; d2/d4 dead (ids >= 1000) |
| 21 | 4DR_SEDAN02 | 1 | 1 | 0 | 1 | 0 | yes | yes | yes | - |
| 22 | AMBULANCE | 0 | 0 | 0 | 0 | 0 | no | no | yes | all five weights 0; cave returns 0 (no district set) |
| 23 | TAXI02 | 1 | 0 | 0 | 0 | 1 | yes | yes | yes | - |
| 24 | PANELVAN | 1 | 1 | 0 | 0 | 0 | yes | yes | yes | - |
| 25 | COUPE | 0 | 0 | 0 | 1 | 1 | no | yes | yes | weight 0 in d0 |
| 26 | FIRETRUCK | 0 | 0 | 0 | 0 | 0 | no | no | yes | all five weights 0 |
| 27 | PARCELVAN | 1 | 1 | 0 | 0 | 1 | yes | yes | yes | - |
| 28 | PICKUP | 1 | 1 | 0 | 1 | 0 | yes | yes | yes | - |
| 29 | 4DR_SEDAN | 0 | 0 | 1 | 0 | 0 | no | yes | yes | weight 0 in d0 |
| 30 | BUS | 0 | 0 | 0 | 0 | 0 | no | no | yes | all five weights 0 |
| 31 | SUV | 1 | 1 | 0 | 1 | 0 | yes | yes | yes | - |
| 32 | MINIVAN | 0 | 1 | 0 | 1 | 0 | no | yes | yes | weight 0 in d0 |
| 33 | HATCHBACK | 0 | 0 | 1 | 0 | 1 | no | yes | yes | weight 0 in d0 |
| 34 | HATCHBACK02 | 0 | 0 | 1 | 0 | 1 | no | yes | yes | weight 0 in d0 |

Rows 0..19 are usage 0 (tuner cars). The cave also lets 8 of them in at 0.375 (ids 0 1 3 4 5 6 14 17: GOLF FOCUS NEON
CIVIC PEUGOT CELICA INTEGRA SENTRA); LANCER (13) never, it has 0 paints (`0x57cfe2` `movsbl 0xd9`, `jg`).

## Fair odds math, 21 cars, 15 models

Each draw is weighted and then retried up to 100 times against a type already in the entrant list (`0x4b3ac0`), so the
first 15 cars tend to be 15 different models and the last 6 repeat. Expected appearances per model with the cave and
RN_TRAFMODELS: 21 x 1/18 = 1.17 for a traffic model, 21 x 0.375/18 = 0.44 for a racer model. With `stock` = 0: 21 x 1/15
= 1.4 each. F (weights) / I (the retry outcome; the run shows 18 models in 21 cars, F).

## Open

- Resident bytes per model (solids + textures after load) not measured. NV.
- Whether `0x58c3b0` is keyed by type or by entrant, so 21 cars of 15 types ask for 15 or 21 slots. NV.
- AMBULANCE is the only usage-2 car with its own TEXTURES.BIN size (11,280 vs 4,616); why was not chased. NV.
