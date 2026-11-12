# Bayview gaps: what UG2 holds vs what the port draws and drives (2026-11-11, plan row 12, first deliverable)

Map: `web/plan/shots/ug2_bayview_gaps.png`. Tool: `.venv/bin/python -I tools/probe/ug2_gaps_map.py` (prints every number here). Names: `census/ug2/names.tsv` (stream rows).
Marks: FACT = bytes or code read; INFERENCE = fits the data; UNKNOWN = nothing is built on it. Nothing was run in the game; city.bin, collision and build untouched.

## 1. Answer
- The loaded city is already the whole drivable Bayview: 255 of 255 STREAML4RA collision sections, and 0 of 38,007 ground-collision cells (8 m) lack city.bin geometry within 40 m. FACT (tool).
- The gaps are not holes in the ground. They are what rides on it: traffic (G1), a few dropped objects (G2, G3), hidden race props (G4), the data edge at the airport (G5), one unplaced district (G6), the other bundles (G7), RD extras (G8).

## 2. Gap table (one column per gap, ids match the badges on the map)
| | G1 traffic | G2 sky sheets | G3 beyond reach | G4 hidden props | G5 airport edge | G6 EL_NORTE | G7 other bundles | G8 RD extras |
|---|---|---|---|---|---|---|---|---|
| size | 680 of 855 road sections, 140 of 184 km | 42 instances | 84 instances | 5,999 instances, 12,049 barrier collision rows | 11 % of AIRPORT polygon past x 1898 | 1 of 13 districts | 6 bundles: RB RC RF RG RH RR | 426 instances (57 visible) |
| where | south (Coal Harbour, Airport), north-west (Jackson Heights), outer ring; 0 km in 8 of 12 districts | scattered | SW coast, north-west | whole city | east end | none found | own frames | x -32..129, y -771..0 |
| cause | NFSU1 net id is 1 byte (0x44a2ae): 254 ids - 78 NFSU1 - 1 connector = 175 UG2 ids; select() grows from the bridge mouth, so A1x and A4x get 0 | SKYDOME, PAN_, XO_VISTA skipped (ug2_world.py SKIP) | only scenery within 160 m of a collision row is kept (REACH) | flag 0x10 = off until a group is enabled (0x5db2e0, 0x5710a0); barrier rows byte 0 != 0 dropped (ug2_coll.py) | RA ground collision ends at x 1898, polygon to 2146 (0x3414a) | name at 0x800c38 but no 0x11 record in PathsFreeRoam.bin | each bundle has its own collision and objects; merging made the dark wedge (row 1) | ug2_world.py reads RA only |
| proof | tool: 175 of 855, 44.1 of 184.3 km; roads.md 0.7 | tool: 42 `sky/panorama` | tool: 84 `beyond reach` | tool: 5,999 `hidden`; coll.md | tool district table | tool: 12 of 13 found | tool: 1 equal object per bundle, rare solids never line up | tool: only in RD 426 |
| next | more ids (patch or merge sections) | skip is right (vistas) | DONE 2026-11-11 (row 12): REACH 160 -> 600 in ug2_world.py, +84 instances, +9,419 verts, +7,662 tris (city.bin 4,237,736 -> 4,247,155 verts, 2,945,141 -> 2,952,803 tris); shot ug2_g3_far.png | race rows 11 | RE DONE 2026-11-11: nothing to add, see section 7 | RE: hash under another name? | UNKNOWN placement, OWNER decides | optional |

## 3. District table (polygons from PathsFreeRoam.bin chunk 0x3414a, type 0x11, name hash at +0x30)
| district | JACKSON_HEIGHTS | PIGEON_PARK | BEACON_HILL_W | BEACON_HILL_E | HOTELS | FINANCE | STADIUM | SOUTH_MARKET | FORT_UNION | AIRPORT | COAL_HARBOUR_E | COAL_HARBOUR_W |
|---|---|---|---|---|---|---|---|---|---|---|---|---|
| polygon km2 | 5.96 | 1.21 | 0.47 | 0.48 | 0.45 | 0.51 | 0.44 | 0.46 | 0.25 | 0.82 | 0.86 | 1.36 |
| % within 40 m of city.bin | 60 | 65 | 97 | 100 | 100 | 99 | 99 | 100 | 99 | 65 | 97 | 82 |
| road km | 22.0 | 6.6 | 11.8 | 14.6 | 18.2 | 12.5 | 8.6 | 11.6 | 4.3 | 6.1 | 18.7 | 15.3 |
| km in traffic net | 0 | 6.6 | 8.7 | 11.0 | 7.7 | 5.3 | 0.3 | 0 | 0.3 | 0 | 0 | 0 |
Low coverage in JACKSON_HEIGHTS, PIGEON_PARK, AIRPORT is mostly sea and mountain inside the polygon (INFERENCE: seen on the map, not measured against water).

## 4. The eight bundles (tool output; owners from GLOBALB 0x34201 region field +0x40)
| bundle | RA | RD | RB | RC | RF | RG | RH | RR |
|---|---|---|---|---|---|---|---|---|
| MB | 118 | 121 | 28 | 15 | 17 | 19 | 2 | 4 |
| table entries (0x34110) | 393 | 410 | 23 | 29 | 25 | 48 | 9 | 9 |
| collision sections | 255 | 255 | 15 | 24 | 16 | 26 | 4 | 4 |
| ground extent (m) | 5.0 x 5.2 km, the city | same as RA | 3.2 x 3.5 | 2.6 x 1.8 | 1.4 x 2.0 | 4.7 x 3.6 | 1.2 x 0.5 | 1.0 x 1.0 |
| tracks that load it | 4000, 40xx-41xx circuits, sprints (71) | 44xx organic drags (5) | 42xx drag (8) | 43xx drift (12) | 46xx Street X (9) | 47xx speedway (16) | 48xx tuning (2) | 49xx replay cams (2) |
RD is RA again (same 255 collision sections and extent, 42,225 equal instances) plus 17 table entries; it is not another part of the map. FACT (tool).

## 5. How UG2 picks what to load (names in names.tsv)
- Track row (GLOBALB 0x34201, found by id: 0x5d3e40, kept at [0x883dac]) names the region: `TRACKS\L4RA.BUN` (small tables) and `TRACKS\STREAML4RA.BUN` (0x57dd46, 0x57a5b5); region L4RG gets its own buffer sizes (0x57a5ff). FACT.
- The big bundle is not read whole: 0x5e4e70 gives the TrackStreamer (0x88eb00) a buffer of 60,000 KiB (36,000..60,000 by mode, table 0x79dc54). FACT.
- Section table = L4R?.BUN chunk 0x34110, 80 B per entry: name `A21`, section id (letter = id/100 + 0x40, A21 = 121), offset in STREAML4R?.BUN (+0x14), size (+0x1c), centre x y z (+0x24). RA: 393 entries = 255 with collision and scenery, 112 scenery only, and 2400 X0 (shared solids, 7.9 MB at offset 0), 2500 Y0, 2600 Z0 which are always resident. FACT (0x5da7a0, bytes).
- Every frame 0x5e5110 asks for: 2500, 2400, 2600; the event sections of the current track id (chunk 0x34154: 22 records in RA, e.g. track 4001 -> 2601); and for each of 2 viewers the neighbour list of the viewer's section (chunk 0x34153: 255 records in RA, e.g. section 101 -> 101..104, 121..124, 199, 2401, 2501), or a 0x34155 group (107 records) when the viewer's section is in one. FACT (0x5e5110, 0x5e9c10, bytes of L4RA.BUN).
- So visibility is a stored per-section list, not a distance rule. UNKNOWN: who sets the viewer section at +0xc6 and the unload order.
- Districts: 13 names in the exe (0x7a50cc..0x7a5170) with hashes; 12 polygons in PathsFreeRoam.bin; the HUD finds the polygon (type 0x11) and prints its name (0x5eb0b1, 0x525704). FACT.

## 6. UNKNOWN
- Where RB, RC, RF, RG, RH, RR sit inside Bayview (or whether they do): no shared object lines up; tool and ug2_world.py comment agree.
- Whether the game shows anything east of x 1898 at the airport; EL_NORTE polygon; chunk 0x34155 meaning (group override inferred from 0x5e5220..0x5e52ec); the buffer behind table 0x7fa9d4.
- Highway ring = classes A30/A31 is INFERENCE (widest lane bytes, thick white loops on TRACKMAP4000), nothing in the exe names a highway class.

## 7. G5 airport east edge: what UG2 holds east of x 1898 (row 12, 2026-11-11)
- FACT (bytes): the AIRPORT polygon (6 points, x 1069..2146, y -1300..-206) has 11.8 % of its 8 m cells east of x 1898, but only 17-19 % of its cells have ground collision even west of 1898 (sea, hills). RA ground collision ends x 1900.25; RoutesFreeRoam road nodes end x 1891.1 (0 of 10,603 beyond 1898; RD 1647.7); the stream table (chunk 0x34110, 393 entries) has its easternmost centre at Q36 x 1830 (collision bbox to 1900); RA scenery instances with bbox centre x > 1898: 32 (24 visible, all drawn already, max x 2041; 8 hidden flag 0x10). So RA and RD hold nothing for x 1900..2146. The same holds for RD (same 255 sections).
- FACT (bytes): data further east exists only in other bundles: RB (drag, ground x to 2468) and RG (speedway, x to 2619, 26 sections S21..S32, R25..R33 east of 2000). They are separate arenas, not the city: RG road cells share 67 of 7,101 12 m cells with RA roads and 0 of them agree in z (median dz 16.3 m); RB 128 shared cells, 6 within 2 m, median dz -21 m. Frames differ, same finding as the dark wedge (row 1).
- FACT (code): one bundle per track. 0x57a580 builds one name 'TRACKS\STREAM%s.BUN' from the track row +0x40 (0x57a5a8..0x57a5bb) and opens it on the single TrackStreamer 0x88eb00 (0x57a5de); the district polygon only feeds a HUD string (0x5eb040, names in census/ug2/names_cityfill.tsv).
- INFERENCE: the polygon is a loose HUD zone that runs out over the coast; the game's world ends at x ~1900 and there is no hidden airport tail. UNKNOWN: whether the 0x34153 neighbour lists reference section ids missing from the table (a first parse gave ids absent from the 393 entries, but the record layout was not confirmed, nothing is built on it).
- Result: no data to add; no shot. The only east data is RG/RB, which the OWNER ruled out (G7).
