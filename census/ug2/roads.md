# UG2 road graph -> NFSU1 traffic net: facts, mapping, recommendation (2026-11-11)

Read-only study. Tool: `tools/ug2_roads.py` (decode, counts, self-checks, z check, `census/ug2/roads.png`). Probes: `tools/probe/ug2_xref.py` (imm32 xref), `d.sh` (objdump window), `ug2_nfsu1_net.py` (counts of the live NFSU1 net).
Marks: FACT = bytes or code read (address or path+offset given), INFERENCE = fits all data, no code proof, UNKNOWN = not decoded.
Addresses: UG2 = `pc/ug2/SPEED2.EXE` (VA = file offset + 0x400000, also in .rdata/.data); NFSU1 = `pc/Speed.exe`. Placement UG2 -> NFSU1: R270 `(x,y)->(y,-x)` then `+ (-1287.375, 812.25, -6.203125)` (`docs/re/ug2_bridge.md`).
`census/ug2/prior_roads.md` was used as a lead; its corrections are in section 6.

## 0. Answer in 8 lines
1. The UG2 free-roam city keeps its AI/traffic graph in `TRACKS/ROUTESL4RA/RoutesFreeRoam.bin` (829,232 B), not inside L4RA.BUN: chunks `0x34121` sections, `0x34122` links, `0x34123` intersections. Same four chunk ids as NFSU1 (`0x34121..0x34124`). FACT (loader 0x5deb80, section 1).
2. Counts (L4RA): 855 sections, 10,603 nodes, 3,289 link entries, 38 intersection records, 184,306 m of road, 20 road classes. FACT (`ug2_roads.py`).
3. UG2 sections and nodes are a slimmed repack of NFSU1's: section header 0x8c (NFSU1 0x27c), node 0x38 bytes (NFSU1 0x88), link slots u16 (NFSU1 u8), section ids 11 bits (NFSU1 8 bits). Same ideas: sections = polylines, entries = (src section,node)->(dst section,node), node flag bits 25/26 = traffic may spawn, 11/18/27/28 = drivable. FACT.
4. The decode is right: 10,181 of 10,603 nodes lie within 12 m of a surface-1 ground vertex, node z (s16/8) differs from the collision z by median 0.02 m (99.9 % within 2 m); every link slot hits an entry whose source is that node (3,289/3,289). `census/ug2/roads.png`.
5. NFSU1 Free Run traffic reads only the live `TRACKB1010.lzc` net: 78 sections, 3,523 nodes, 196 entries (the tour net, `tools/openworld/tour.py`). UG2 streets have NO node in it today, so no traffic car can drive there.
6. Mapping: x, y, z, tangent, section ids, links, drive flags map directly; lane/width/offset bytes and about 20 NFSU1 node floats/words have no proven UG2 source (template them); UG2 direction and type nibbles are not decoded (derive them from geometry, as `tour.py` does).
7. Limits in the running game (with the `widen` patches already in `tools/recomp/patches_road.py`): section id <= 254, entries <= 2,047, entries per source section <= 254; retail path (no EBASE) needs <= 255 entries and <= 128 sections in total. The whole UG2 graph (855 / 3,289) does not fit; a main-road subset does.
8. Recommended: transcode UG2 sections near the bridge 1:1 into new NFSU1 sections appended to the live net (stage 1: about 600 m disc = 15 sections, 226 nodes, 40 entries, fits the retail path), plus one authored connector over the bridge; stage 2 = more roads through the widened path. Details and risks: section 5.

## 1. UG2 side: where the data is

| File (`TRACKS/ROUTESL4RA/`) | Bytes | Chunks | Used when | Proof |
|---|---|---|---|---|
| `RoutesFreeRoam.bin` | 829,232 | `0x34121` @0x0 size 713,468; `0x34122` @0xAE304 size 105,252; `0x34123` @0xC7E30 size 10,488 (chunk id u32, size u32 = payload only, no container bit) | Free Roam / non-race loads | string `Tracks\Routes%s\RoutesFreeRoam.bin` 0x7a0b70, pushed at 0x57f56c (branch 0x57f55e, taken when `[0x89e7b0]==0`, or when 0x457ba0 / 0x4ae8d0 say so, 0x57f4fd..0x57f51e) |
| `Routes<4001..>F/B.bin` (120 files) | per race | same chunks, more entries | a race (`Routes%d%s.bin` 0x7a0b94, suffix F / B 0x7a0bb4/b8) | 0x57f545 |
| `RoutesAll.bin` | 912,456 | same | NOT loaded: no string "RoutesAll" in the exe (strings scan) | UNKNOWN use, probably tool output |
| `PathsFreeRoam.bin` | 134,020 | container `0x80034147` with `0x3414a` (69,628 B) and `0x3414d` (64,368 B) | Free Roam | string 0x7a0bbc, pushed 0x57f4be; container loader 0x5d9a90 (called 0x5da49a) |
| `Paths<id>.bin` | per race | same container | a race (0x7a0be0, 0x57f46a) | |
| `TrackPosMarkers*.bin` | | not read for this study | | UNKNOWN |

- Chunk handler: 0x5deb80 (function-pointer table entry at 0x7fa8a8). It compares the id with 0x34121 -> `0x5de1c0` with manager 0x88a320; 0x34122 -> entries at chunk+0xc, count `(size-4)>>5` (stores 0x883db0 / 0x883db4); 0x34123 -> `[0x883dbc]`, count `size/276` (mul 0x76b981db, shr 7, 0x5debf7..0x5dec11); 0x34124 -> `[0x883dc4]`, count `size/0x108` (0x5dec17..). Unload 0x5e4820 (table entry 0x7fa938). FACT.
- L4RA.BUN has no 0x34121..0x34124 (`census/ug2/l4ra_chunks.tsv`; only `0x3412f` = collision barrier groups). FACT.
- `RoutesFreeRoam.bin` of L4RA has no 0x34124 (designer spawn points); the engine reads it if present (0x5dec17). FACT.
- Other sections: L4RB 142 sections / 1,070 nodes / 288 entries, L4RC 54 / 671 / 136, L4RD 26 / 471 / 52, L4RF 33 / 617 / 86, L4RG 44 / 1,263 / 100, L4RH and L4RR 8-byte empty files (`ug2_roads.py --sec B` etc.). They belong to the other STREAML4R* arenas, not the city. UNKNOWN whether they share the L4RA frame (not needed here).
- City bounds from nodes: x -3066..1891, y -2073..3121 (raw UG2 units), z -12..384. FACT.

### 1.1 Section (0x34121 record = header 0x8c + n x 0x38)
Walk proof: `0x5de1c0` steps `eax += 0x8c + s16[eax+0x34] * 0x38` (0x5de21a..0x5de221) and files an id: `[mgr + 4*u16[eax+0xa] + 0x14] = eax` (0x5de212..0x5de216). All 855 sections tile the chunk exactly (end = chunk end). FACT.

| Offset | Type | Meaning | Proof / data |
|---|---|---|---|
| +0x0, +0x4 | u32 x2 | 0x0b, 0x0b (list links, as NFSU1) | all 855 |
| +0x8 | u16 | 1 | all |
| +0xa | u16 | section id, 101..1219 (11 bits: mask 0x7ff at 0x5de294) | 0x5de212 |
| +0xc | u32 | 0 (NFSU1: list tag 0/1; UG2 has no list-1 stubs) | all 855 = 0 |
| +0x10 | char[16] | class name `TrackRoutesA<d><d>`: 20 classes A10-A14, A20-A24, A30-A34, A40-A44 | counts: A10 6, A11 6, A12 10, A13 6, A14 8, A20 40, A21 23, A22 56, A23 34, A24 32, A30 85, A31 37, A32 186, A33 86, A34 76, A40 34, A41 36, A42 39, A43 34, A44 21 sections. First digit follows the district band on the map (1 north mountain, 2 north centre, 3 city centre, 4 south, `roads.png` colours); second digit = street class. Names A15..A65 and `TrackRoutesTraffic*5` exist in an exe table (0x7a4d88..0x7a4fe8) but not in this file. Meaning of the class: INFERENCE (district / street class), nothing reads it that I found: UNKNOWN |
| +0x30 | f32 | 1.0 | all |
| +0x34, +0x36 | s16 x2 | node count n (3..101), repeated | 0x5de1f3 |
| +0x40 | f32 | route length in metres, sum 184,306 m | INFERENCE (matches node spacing, not code-read) |
| +0x44..+0x53 | 4 x u32 | 0xffffffff in 851 sections; 4 sections hold `0x....ffff` values | UNKNOWN |
| +0x54 | f32 | 0 in 721 sections, else 6.0, 22.0, 38.0 ... (27 values) | UNKNOWN (speed or width? not proven) |
| +0x60 | f32 x4 | bbox xmin, ymin, xmax, ymax | e.g. section 101: (-3033.1, 2177.1, -2396.6, 2521.8) matches its nodes; same slot order as NFSU1 +0x20 |
| +0x70 | u32 | flags 0x007fe141 (626), 0x007fe541 (210), 6 others; bit 7 and bit 1 are tested, bit 8 is set at runtime (0x5de212..0x5de4ae) | UNKNOWN meaning |
| +0x74, +0x78, +0x7c, +0x80 | u16 256, f32 999.0, u16 256, f32 999.0 | constants (NFSU1 has 10 blocks of {u32 1, f32 999.0, name}; 10 of 78 live NFSU1 sections have none) | all 855 |
| +0x84..+0x8b | 8 bytes 0/1 | lane flags, 4 per side | INFERENCE (NFSU1 header +0x270..+0x27b: 6 per side, tested by 0x442950: six bytes at +0x270 or +0x276) |

### 1.2 Node (0x38 B)
| Offset | Type | Meaning | Proof / data |
|---|---|---|---|
| +0x0, +0x4 | f32 x, y | position, raw UG2 units | 10,181/10,603 within 12 m of a surface-1 ground vertex (`--zcheck`) |
| +0x8 | f32 | 0.0 in all 10,603 (z is not here) | |
| +0xc | u32 | bits 0..10 = own section id (10,603/10,603 equal the section id; read `& 0x7ff` at 0x5de294); bits 20..24 = intersection group (31 = none; 19 groups x 4 nodes = 76 nodes); bit 11 forward-drivable, bit 18 backward-drivable, bit 27 / 28 forward / backward drivable, bit 25 / 26 forward / backward traffic-spawn | bit test code: 0x5dd550..0x5dd58e (kind 0 -> `shr 0xb`, 1 -> `shr 0x19`, 2 -> `shr 0x1b`), 0x5dd770 (`shr 0x1b/0x1c`, `0x19/0x1a`); the setter 0x5de540..0x5de58f ORs 0x800/0x40000, 0x2000000/0x4000000, 0x8000000/0x10000000. Counts: bit 11 = bit 18 = bit 27 = bit 28 = 9,034 nodes; bit 25 6,085, bit 26 6,056; 1,539 nodes have none of them (the road margins) |
| +0x12 | s16 | z * 8 (z = value / 8 metres) | code: 0x5d4410 builds z as `s16 << 13 * [0x784278]` (= 1/65536); data: dz vs collision median 0.02, p5 -0.18, p95 0.20 |
| +0x10, +0x14..+0x17 | u16 / u32 | per-section-constant pairs (e.g. 0x09bd, 0x0844) | UNKNOWN |
| +0x18, +0x1a | s16 x2 | unit tangent x, y * 32768 (direction of rising node index) | 8,133 of 8,893 interior nodes agree with the polyline direction (cos > 0.97; the rest are sharp corners) |
| +0x1c, +0x1e | u16 x2 | link slots: index into 0x34122, 0xffff = none | 0x5d43c0 (`word [node+0x1c]`, `shl 5`, `+ [0x883db0]`) and 0x5de360. Slot 0 used 2,861x, slot 1 428x; 3,289 slots hit an entry, 232 slots hold an index >= 3,289 (race-only entries, absent from FreeRoam) |
| +0x20..+0x2b | 12 bytes | lane data (0xff = none) | UNKNOWN meaning (NFSU1 has 24 lane bytes at +0x68..+0x7f) |
| +0x2c, +0x2d | u8 x2 | 100, 100 | all |
| +0x2e..+0x35 | 8 bytes | width codes: 6 (default) or 20, 16, 15, 14 ...; class A30 mean of the 3 variable bytes 10.0 / 14.5 / 16.8, A33 6.0 / 6.5 / 10.9 | NFSU1 has 12 such bytes (+0x75..+0x80), 6 per side, three of them constant 6. INFERENCE that they are the same thing |
| +0x36, +0x37 | | 0 | |

### 1.3 Link entry (0x34122, 32 B, starts at chunk+0xc)
| Offset | Type | Meaning | Proof |
|---|---|---|---|
| +0 | u32 | 0 (runtime distance) | all |
| +4 | u16 | destination node index | 3,289/3,289 valid |
| +6 | u16 | source node index | 3,260 of 3,260 section-crossing entries; the node's link slot points back at the entry (3,289/3,289) |
| +8 | u16 | destination section id | valid for all |
| +0xa | u16 | source section id (NFSU1 has these as u8 at +9 / +0xa) | valid for all |
| +0xc, +0xd | byte, byte | two type nibble pairs, always equal bytes: low nibble in {2, 4, 5, 7} etc., high nibble in {2, 4, 5, 7, 10}; code tests low nibble == 7 / 3 / 2 / 8 (0x5de3a7..0x5de3f9) | UNKNOWN mapping to NFSU1 `+0xb` / `+0xc` |
| +0xe | byte | bit 2 (0x04) read as `>> 0x12 & 1`, XORed with the walk direction (0x5de427..0x5de42d); bit 7 (0x80) | only ~64 % of reverse twins differ in bit 2 (2,088 of 3,289), geometry agrees ~70 %: direction semantic UNKNOWN |
| +0xf | byte | 0 (2,487), 4, 12, 1, 8 ... | UNKNOWN |
| +0x10..+0x17 | | 0xffffffff, 0 | |
| +0x18..+0x1f | 4 x u16 | on 1,433 entries: (section, section, node, node) of the reverse twin, else 0xffff | partly decoded, UNKNOWN use |
Structure: every entry has a reverse twin (dst->src exists for 3,289/3,289), no duplicates; 29 entries stay inside one section; only 5 entries go from a section's last node to another section's first node. So UG2 sections are NOT chained end to start: they are joined by mid-section hops at junctions, as in NFSU1. Entry gap src node -> dst node: median 2.2 m, p90 7.2 m, max 35 m. Heading of dst vs src: 1,769 aligned (cos > 0.92), 856 opposite, 664 turns. Max 33 entries leave one section.

### 1.4 Intersections (0x34123, 276 = 0x114 B) and zones
- Record: +0 u32 1, +4 u16 section A, +6 u16 section B, +8 u16 0xffff, +0xa u16 node in A, +0xc u16 node in B, then 16 runtime items (s32 0 / -1, f32 -1.0 -1.0). 38 records = 19 groups of 2; record k's two nodes carry group k // 2 in node bits 20..24 (76/76). NFSU1 stride is 0x170 (22 items) and 49 records in the whole game. FACT (check in `ug2_roads.py`).
- Zones (`PathsFreeRoam.bin`, chunk 0x3414a, rows of variable size = s16 at row +0x42, walked by 0x5d9b60..0x5d9b7c; 671 rows tile the chunk): `+0 u32 type, +4/+8 f32 x, y, +0xc/+0x10 f32 direction, +0x24 f32 x4 bbox, +0x40 u16 nverts, +0x42 s16 size, +0x44 nverts x (f32 x, f32 y)`. Type table at 0x800d80 (21 entries): 0 NO_WRONG_WAY, 1 WRONG_WAY, 2 RESET, 3 RESET_TO_POINT, 4 GUIDED_RESET, 5 TUNNEL, 6 OVERPASS, 7 OVERPASS_SMALL, 8 DRIFT_GATE, 9 DRIFT_HOT_SPOT, 10 TUTORIAL, 11 SHORTCUT, 12 STREAMER_PREDICTION, 13 RACE_START_TRIGGER, 14 SHOP_TRIGGER, 15 SHOWCASE_TRIGGER, 16 TRAFFIC_TYPE, 17 NEIGHBOURHOOD, 18 SMS_TRIGGER, 19 BANK_TRIGGER, 20 GARAGE. L4RA has 4 TRAFFIC_TYPE rows (u32 values 3, 6, 2 at row +0x38..), no TRAFFIC_DENSITY type (NFSU1 type 4). Meaning of TRAFFIC_TYPE values: UNKNOWN. `0x3414d`: 894 records of 72 B (stride from 0x5d9ba4..0x5d9bb8): UNKNOWN.
- Speed, one-way, lane count: no field was proven. Forward and backward drive flags agree on every node (bits 11/18/27/28), so no one-way flag exists in the node flags. UNKNOWN whether lane bytes encode it.

## 2. NFSU1 side: what the running game consumes

Live net, measured: `build/openworld/TRACKB1010.lzc` (`tools/probe/ug2_nfsu1_net.py`): chunk 0x34121 at 0x4f0ec size 528,736 = 78 x 0x27c + 3,523 x 0x88; ids 0..77, list tag 0 for all, max 360 nodes in a section; chunk 0x34122 at 0xd0254 size 6,272 = 196 entries; no 0x34123, no 0x34124; TrackPath 0x34148/49 present. This is the tour net (`tools/openworld/tour.py`, `docs/openworld/tour.md`); `tools/ug2_collfile.py` rewrites only the collision block of that file. FACT.

| Piece | Layout | Reader (Speed.exe) | Proof |
|---|---|---|---|
| Loader | chunk 0x34121 -> parse with manager 0x77af20; 0x34122 -> `[0x736150]`, count `[0x736154]` = size >> 5; 0x34123 -> `[0x736158]`, size / 0x170; 0x34124 -> `[0x736160]`, size / 0x108 | 0x442dd0 (cmp 0x34121..0x34124), parse 0x442b70 | objdump this run |
| Section | header 0x27c: +0xa s16 id, +0xc list tag 0/1, +0x10 s16 node count, +0x20 f32 x4 bbox; nodes 0x88; next = + 0x27c + n x 0x88 | 0x442b70 (0x442b80, 0x442b88, 0x442bb2..0x442bbc) | objdump; tour.py `read_net` |
| Node | +0..+8 f32 x, y, z; +0xc, +0x10 f32 unit tangent (forward), +0x14, +0x18 its negative (6,662 of 6,753 nodes); +0x1c..+0x28 4 f32 about 9-11 (look like widths, UNKNOWN); +0x2c..+0x34 3 f32 within +-0.19 (UNKNOWN); +0x38 f32 route distance; +0x60..+0x73 lane bytes; +0x75..+0x80 12 width codes (6 / 20 ...); +0x81, +0x82 u8 link slots (0xff none); +0x83 u8 own section id; +0x84 u32 flags | `+0xc/+0x10` heading: host/rivals.c:732 (`along = node[+0xc]*vx + node[+0x10]*vy`), data alignment test this run; slots: 0x4564bd `movzx ebp, byte [edi+edx+0x81]` (also 0x5a53f8, 0x5a56ce, 0x5a6da9); `+0x38`: 0x442570 -> 0x443d60; id +0x83: 0x424f50, 0x44d3e0 | `docs/re/traffic.md` (node table), re_widen.md |
| Node flags +0x84 | forward drivable = any of bits 6, 25, 27 (0x4424d0: `shr 6`, `shr 0x19`, `shr 0x1b`); backward = any of bits 19, 26, 28 (0x442520: `shr 0x13`, `0x1a`, `0x1c`); traffic may spawn = bit 25 / 26 (0x4420b0 `shr 0x19` / `0x1a`); bits 20..24 intersection index, 31 = none | objdump this run | |
| Entry | 32 B: +0 f32 distance (filled at load), +4 u16 dst node, +6 u16 src node, +8 u8 (0/1/2, 1,147 of 1,193 are 0), +9 u8 dst section, +0xa u8 src section, +0xb type (2,7,3,0,5,4,1), +0xc type2 (7,2,5), +0xd direction (0 forward entry, 1 reverse twin) | walker 0x4563d0 (direction test 0x4564e4..0x4564f6), step 0x5a53c0, racer decider 0x458bd0 | `docs/openworld/re_citygraph.md`, `docs/re/traffic.md`; data over the 16 base tracks (1,193 entries) |
| Intersections | 0x170 B, runtime states; reached from a node by bits 20..24 | 0x44d570 | not a placement input; node index 31 = none, as `tour.py` writes |
| Free Run traffic | placement random node 0x598fb0; teleporter 0x598600 -> move 0x59a2c0 walks the graph 250 m ahead (0x4563d0, give up past 500 m, wants exactly 1 result 0x59a4fa); lane 0x5995e0; density gate 0x59b3e0; node spawn flag 0x4420b0 | `docs/re/traffic.md` (V marks), `docs/openworld/re_citygraph.md` | |
| Gates already bypassed for the open world | density zone (99,999 m unless in a TRAFFIC_DENSITY zone) -> `host/free.c free_spacing` via the patch at 0x598774; spawn bit 25/26 -> `free_tnode` via 0x59a5cf / 0x59a669 | `tools/recomp/patches_race.py` lines 38-57 | So UG2 needs neither a density zone nor spawn bits for Free Run (INFERENCE: patches not run on UG2 nodes) |
| Host refill | `host/rivals.c traffic_refill` re-places parked, far (> 450 m) or behind cars 150..650 m ahead on the road from the player's node (0x428160); default state off ("?trafrefill=1") | host/rivals.c:668-730 | UNKNOWN whether on in the shipped page |

### 2.1 Limits (with the widen patches of `tools/recomp/patches_road.py`, `docs/openworld/re_widen.md`)
| Limit | Value | Where | UG2 L4RA needs |
|---|---|---|---|
| Section ids | <= 254 (id 255 = none); retail 128 | manager moved to 0x796000 with 256 slots; `movsx` -> `movzx` at 50 sites; id sanity 0x435e79 | 855 sections, ids 101..1219 -> must be re-numbered and cut |
| Entries (total) | retail <= 255; widened <= 2,047 (11-bit decider cache 0x458c29, 0x458c95, 0x458cf0, 0x458c9d) | PostLoad hook 0x443123, EBASE at 0x796410 | 3,289 -> cut |
| Entries leaving one source section | <= 254 (slot byte = rank inside the section when total > 255) | caves E1..E4 | max 33, fine |
| Node count per section | s16 (live max 360) | 0x442bb2 | max 101, fine |
| Section / node ids in link pairs | u8 section, u16 node | entry +4..+0xa | fine after re-number |
| Route distance +0x38 | wraps by the loop length L when `|d| > L/2` (0x443d60, flag byte `[[ecx+0xc]+1]`); the city writer kept it under 13.8 km of a 42 km loop | 0x443d60 | the UG2 part adds up to 137-184 km of centreline: distances must stay under L/2 (INFERENCE from the code, not run) |
| Chunk 0x34121 size | live 0.53 MB; 3,000 UG2 nodes add 0.4 MB | loader buffer: UNKNOWN | UNKNOWN (`re_widen.md` open item) |
| Traffic cars | 30 entrants; 23 traffic with 6 rivals; Free Run asks 14 x 1.5 = 21, cap 26 | 0x4322a0, cave 0x63b280 | independent of the net |
Open crash (not shown to be the widen patch): a 161-section / 441-entry net crashed twice at 0x44c56e when the player started at (211.0, 402.6, 43.0) (`re_widen.md`, Stage 4). That spot is about 100 m from the bridge stub.

## 3. Field mapping UG2 -> NFSU1 (what the writer must do)
| NFSU1 field | UG2 source | Status |
|---|---|---|
| Node x, y (+0, +4) | node +0, +4, then R270 + t | direct (transform) |
| Node z (+8) | s16 @+0x12 / 8, then + tz | direct (z check) |
| Node tangent +0xc, +0x10; negative +0x14, +0x18 | s16 @+0x18, +0x1a / 32768, rotated by R270 (`(tx,ty)->(ty,-tx)`); negate for the second pair | direct (tangent check, both games) |
| Node +0x1c..+0x2b, +0x2c..+0x37 (7 floats) | no UG2 field | template / UNKNOWN (widths look like 9..11 on normal roads, 10.5 on 20-wide) |
| Node +0x38 route distance | none | derive (writer: continuous along a run, spanning tree across links, as `citygraph.py`) |
| Node +0x3c..+0x5f, +0x60..+0x73 lane bytes | UG2 +0x20..+0x2b has 12 lane bytes, meaning unknown | template (copy a measured NFSU1 node of a similar width class) |
| Node +0x75..+0x80 width codes (12) | UG2 +0x2e..+0x35 (8) | INFERENCE: 3 variable + const per side; copy or template |
| Node +0x81, +0x82 link slots (u8) | UG2 u16 slots +0x1c, +0x1e | direct after re-index (rank inside source section, or global index when total <= 255) |
| Node +0x83 own section id (u8) | node +0xc bits 0..10 | direct after re-number |
| Node +0x84 flags | UG2 +0xc: bit 11 -> 6, 25 -> 25, 27 -> 27, 18 -> 19, 26 -> 26, 28 -> 28; bits 20..24 := 31 | direct (bit-for-bit, both codes read) |
| Section header +0xa id, +0xc list tag, +0x10/+0x12 count, +0x20 bbox | UG2 +0xa, 0, +0x34/+0x36, +0x60 (transform, then recompute) | direct |
| Header +0x34..+0x23b (10 name blocks) | none | zero (10 of 78 live sections have none: INFERENCE that zero is accepted) |
| Header +0x270..+0x27b lane flags (6 + 6) | UG2 +0x84..+0x8b (4 + 4) | template (INFERENCE only) |
| Entry +4, +6 | UG2 +4, +6 | direct |
| Entry +9, +0xa (u8 sections) | UG2 +8, +0xa (u16) | direct after re-number |
| Entry +0xb type, +0xc type2, +0xd direction | UG2 nibbles at +0xc/+0xd and bit 2 of +0xe | NOT mappable (UNKNOWN). Write type 2 / 2 and d = 0 / 1 by geometry (leave src heading: dst ahead = 0, twin = 1), the way `tour.py` writes hops (forward d=0 on the source, reverse d=1 on the destination) |
| Entry +8 (u8 0/1/2), +0 f32 | none | 0 (filled at load by 0x442150) |
| Intersection records (UG2 38) | | drop: set node bits 20..24 = 31 as `tour.py` does; traffic then ignores lights |
| Spawn records 0x34124, zones | UG2 has none in the file / TRAFFIC_TYPE only | drop; the Free Run patches do not need them |
No counterpart in UG2: NFSU1 lane offset floats, the 10 name blocks, intersection state items. No counterpart in NFSU1: UG2 class names, 0x3414d records, TRAFFIC_TYPE zones, race-only entries.

## 4. Numbers for the choice of subset (L4RA, raw UG2 space)
- UG2 graph is redundant: a node has a same-direction neighbour section within 14 m for 4,868 of 10,603 nodes (opposite 2,293, cross 1,176, alone 2,266); a spatial dedupe at R = 3 m keeps 427 of 855 sections (74 % of the length), at R = 6 m 342. So the NFSU1 id budget is exceeded even after dedupe.
- Subsets of whole sections fall apart: sections >= 200 m long (243 sections, 65 % of the length) split into 47 components through UG2's own entries, the largest holding 51 sections. A usable subset has to be cut by area, or re-segmented (cluster and re-plan like `citygraph.py --write --radius 2.0`: 161 sections / 441 entries for NFSU1's 16 tracks).
- Area subsets keep UG2's own links and stay connected. Sections with any node inside a disc around the bridge mouth (UG2 211, 1405):

| Disc radius | 400 m | 600 m | 800 m | 1,000 m | 1,500 m |
|---|---|---|---|---|---|
| Sections | 7 | 15 | 21 | 45 | 214 |
| Nodes | 129 | 226 | 307 | 583 | 2,698 |
| Entries inside | 18 | 40 | 60 | 120 | 625 |
| Road length (whole sections) | 3.1 km | 5.3 km | 6.9 km | 13.4 km | 53.3 km |
| Components | 1 | 1 | 1 | 2 | 3 |
| Total entries with the live 196 | 214 | 236 | 256 | 316 | 821 |
| Needs widened entry path (> 255) | no | no | yes | yes | yes |

- The UG2 node nearest the bridge mouth: section 230, node 23, class A21, UG2 (211.x, 1405.x, 49.25) -> NFSU1 (124.1, 601.2, 43.0), 12.6 m from the bridge's UG2 end (121, 589). The NFSU1 end of the bridge (x 111..125, y 394..508, z 43) has NO node of the live net: nearest is section 12 node 97 at (229.2, 468.6, 43.8), 115 m away. A connector road of about 3 new nodes sections has to be authored along the stub and the bridge.

## 5. Recommendation (one approach)
Transcode, do not extend the NFSU1 data model: write the UG2 sections as NEW NFSU1 sections appended to the live net, with a template node and the direct fields of section 3, plus one connector across the bridge.

1. Stage 1 (smallest that gives traffic on UG2 main roads near the join): the 600 m disc (15 sections, 226 nodes, 40 entries = 20 link pairs) plus a connector section along the NFSU1 stub and the bridge (new nodes on the generated bridge deck, 2 link pairs). Totals about 94 sections (ids 78..), about 240 entries: inside retail limits (< 128 sections, <= 255 entries), so the stock PostLoad sort/remap runs and no widened path is needed.
2. Stage 2 (the real city): re-segment (dedupe R about 3 m, cut at junctions, long runs) the main classes A2x / A3x / A4x to <= 170 sections and <= 1,800 entries, use the widened path (ids <= 254, EBASE), distances kept under L/2. Needs the open crash of `re_widen.md` Stage 4 understood first.
3. Why this and not "port the graph as it is": the section count (855) and entries (3,289) exceed the game's table sizes by 3.4x and 1.6x, and UG2 directions/types cannot be mapped (UNKNOWN), so links must be regenerated from geometry anyway, which `tour.py` / `citygraph.py` already do.
Proof points: (a) same chunk ids, same loader shape, same flag bits (0x4424d0 vs 0x5dd550/0x5dd770); (b) the decode matches the road collision (section 0); (c) z and tangent are direct; (d) the free-run gates (density, spawn bit) are already bypassed by patches; (e) the nearest UG2 node to the bridge mouth is on the road the bridge joins (A21, z 43.0).

Risks, in order:
1. Template node: the +0x1c..+0x37 floats, +0x3c..+0x73 words and lane bytes have no UG2 source. A wrong template makes `0x5995e0` return -1 (car parks, so traffic fails closed) or puts cars off their lane. Mitigation: template from an NFSU1 node of the same width code; one native run later (RN_FREELOG).
2. Directions and link types are regenerated by geometry, not read from UG2 (UNKNOWN). Turns (664 entries) and U-links (856) need a rule; a wrong d breaks backward walks (dead end = car parked, never a crash: `re_citygraph.md`).
3. Over 255 entries moves the game onto the widened path, which has one open reproducible crash near the bridge area (section 2.1). Stage 1 avoids it by staying <= 255.
4. Route distance +0x38 across two cities: must be continuous across the bridge link and stay inside L/2.
5. Chunk size / loader buffer for a bigger 0x34121 is UNKNOWN.
6. Strongly connected walks: dead ends only cost one failed placement; the UG2 disc has 1 component (600 m), but one-way semantics are UNKNOWN, so a car may be placed against traffic on a divided road.

## 6. Corrections to `census/ug2/prior_roads.md`
- The "Routes payload" table is the header of the FIRST SECTION (+0x0 0x0b, +0xa id 0x65, +0x10 name "TrackRoutesA10", bbox at +0x60), not a file header; nodes are fixed 0x38 B after a 0x8c header, not variable length. The "46 / 46 speed" is the section node count (0x2e = 46 in file C) at +0x34/+0x36.
- The "Paths" 100-byte records are zone rows (type u32 at row +0, e.g. 5 = TUNNEL), not lanes: `+0x10 = 5` is the type of row 0, `+0x50 u16 4, 100` is nverts and row size. The "road rectangle" is the zone polygon.
- RoutesAll.bin differs from RoutesFreeRoam.bin by 83,224 bytes in L4RA (more entries, race-only); the exe never names RoutesAll.

## 7. NOT VERIFIED
- No game run; nothing here was loaded into the game. The NFSU1 reader semantics of node floats +0x1c..+0x37, +0x3c..+0x67 and lane bytes are not read from code (only heading +0xc/+0x10 is, by host/rivals.c and data).
- UG2 entry type nibbles, bit 2 / 7 of +0xe, +0xf, header +0x44/+0x54/+0x70, lane bytes, class meaning, TRAFFIC_TYPE values, 0x3414d: UNKNOWN.
- `+0x40` route length = sum of node spacing: only checked as a sum (184,306 m), not per section.
- Walker semantics for UG2 itself (0x5de240) were read only where they test the bits above.
- Free Run gate patches on UG2 nodes, the host refill state in the shipped page, the loader buffer for a bigger net.
- Stage numbers (15 sections / 40 entries / ~94 sections / ~240 entries) are counts from the data; no net was written.
