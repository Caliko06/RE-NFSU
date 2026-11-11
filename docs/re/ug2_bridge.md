# UG2 <-> NFSU1 bridge: where one road joins the two cities (2026-11-10)

Read-only study over decoded collision rows. No game, no Chrome, no build. Scripts: scratchpad `bridge/` (occ.py, pair2.py, fin.py).
Transform UG2 -> NFSU1 space: rotate with `R`, then add t. `R90: (x,y)->(-y,x)`, `R180: (-x,-y)`, `R270: (x,y)->(y,-x)`; z' = z + tz. NFSU1 stays where it is.

## Method
- FACT: ground rows (flags & 0x0a == 0) of the NFSU1 union (54,735 rows, 44,146 ground) and of build/ug2/coll_rows.bin (87,753 ground). Surface 1 is the main road in both.
- FACT: x,y are s16/8, so every UG2 vertex must stay in -4096..4095.875 (census/ug2/coll_load.md). Bounding boxes cannot sit side by side (5000 + 3145 wide).
  So I tested real occupancy: both worlds drawn on an 8-unit grid, NFSU1 grown by 32 units, UG2 shifted by FFT correlation for every yaw, zero overlap required,
  UG2 full extent (x -3100.5..1900.25, y -2080.6..3151.9, walls included) inside +-4096.
- FACT: R0 has 0 free placements; R90 1,053; R180 1,200; R270 4,336 (8-unit steps). So a placement fits without cropping UG2.
- Road ends: skeleton of the surface-1 raster (dead ends) plus straight road runs whose side faces open space for 2,500 units (a T-junction candidate); NFSU1 also checked with road nodes (tools/openworld/tour.py read_net).
- UG2 road graph: UNKNOWN, not decoded. No web search done (no web tool in this run); NFSU1 node layout only.

## Ranked pairs (all: ends face each other, heading error <= 3 degrees, widths N/U measured on the surface-1 strip)
| rank | NFSU1 end (x,y,z, out heading, width) | UG2 end (x,y,z, out heading, width) | R | t = (tx, ty, tz) | gap | UG2 box after t |
|---|---|---|---|---|---|---|
| 1 | (120,499,43), north (0,1), ~20, DEAD END | (211,1405,49), east (1,0), 36, road side (T) | 270 | (-1287.4, 812.2, -6.2) | 103 | x -3368..1864, y -1088..3913 |
| 2 | (348,667,47), west (-0.98,0.21), 22, DEAD END | (118,1561,44), north (0.26,0.97), 33, road side (T) | 270 | (-1311.4, 804.2, +3.1) | 100 | x -3392..1840, y -1096..3905 |
| 3 | (-690,-789,45), west (-1,0.05), 22, DEAD END at x -690 | (-1193,-152,24), west (-1,0.09), 57, road side (T) | 180 | (-1979.8, -936.1, +21.2) | 97 | x -3880..1121, y -4088..1144 |
- Rank 1 -> UG2 end lands at (117,601,z43). Real distance between the two cities elsewhere (outside 600 units of the bridge): about 320 units. Best z match (tz -6).
- Rank 2 is the same UG2 lobe, 150 units further along; z match tz +3, but the cities come within about 96 units of each other elsewhere (tight).
- Rank 3 is a different side (UG2 to the west, turned upside down): the NFSU1 end has road nodes (sections 1106 s41, 1108 s23 run to x -691), so it is the best end on the NFSU1 side.
  Costs: tz +21, UG2 y reaches -4088 (8 units from the limit), min gap elsewhere about 136, UG2 end is a wide road (57) next to a 22 one. Variant (-538,-433) <-> (-1184,-431): gap 242, box y -4016.
- Picture of rank 1: scratchpad `bridge/compB.png` (UG2 north-west of NFSU1, its loop lobe touches the NFSU1 north). Rank 3: `bridge/compC.png`.

## Evidence
- FACT rank 1 NFSU1: 60 surface-1 rows run up the axis x 111..125 from y 394 to 508, z 43.0..43.2, then stop; only 3 wall rows within 60 units: an open end.
  INFERENCE: it is a stub; no road node lies within 60 units (nearest: section 1005 s21 nodes x 122..256, y 401..516), so the AI graph has nothing there.
- FACT rank 1 UG2: a straight N-S run x ~211, y 1360..1459, z 48.9..49.5, outer side open for 2,500 units.
- FACT rank 2 NFSU1: 30 surface-1 rows end at the point (z 46.8), 23 wall rows within 80 units.
- The first idea (UG2 turned 180 degrees south of NFSU1 at y -1905 / -1982, z 9-14, tz ~0) fails the +-4096 limit: UG2 y reaches -7166.

## Not verified
- UNKNOWN: surface 1 = asphalt (only "the biggest road-like surface").
- UNKNOWN: if a UG2 side road has a guard wall that must be cut for the T; wall rows (flags & 2) were not used in the overlap test (ground only), only in the extent.
- UNKNOWN: z beyond ground rows. UG2 z runs about -27..407 after tz for ranks 1-3 (north mountain road z 374 + tz); walls span +-508 and a tz shift moves them out of -508..508.
- UNKNOWN: overlap by height (overpasses); the grid test is 2D.
- Ends are on an 8-unit grid; a real connector road still needs a heading and z blend written by hand. No run in the game.

## Decision (OWNER 2026-11-10)
Rank 1 chosen: R270 `(x,y)->(y,-x)`, then t = (-1287.4, 812.2, -6.2). One constant for render (web/ug2/ug2world.js) and collision.
