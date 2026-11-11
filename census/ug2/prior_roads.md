# UG2 road graph and traffic (Paths / Routes) - what the bytes say

Section dirs: `TRACKS/ROUTESL4R{A,B,C,D,F,G,H,R}` (8 sections, 41 files each, e.g. `TRACKS/ROUTESL4RC/`).
Per section: `Paths<NNNN>.bin`, `PathsFreeRoam.bin` (geometry of lanes), `Routes<NNNN>{F,B}.bin`,
`RoutesFreeRoam.bin`, `RoutesAll.bin` (the AI graph). Source: `ls` of `/Users/angeldamian/RE-NFSU-UG2/Need For Speed Underground 2/TRACKS/ROUTESL4RC`.

Container (both kinds): 4-byte chunk id, then u32 size that includes the 8-byte header; bit 0x80000000 in the
id marks a container chunk. PathsFreeRoam: id `0x80034147` size `0x1220` (=4648 file size), child `0x0003414A`
size `0x02BC` (=700). Source: `TRACKS/ROUTESL4RC/PathsFreeRoam.bin` offset 0x00.
RoutesFreeRoam: id `0x00034121` (no container bit) size `0xB050` (=45136) at offset 0x00.

## Paths*.bin payload (inside child chunk `0x0003414A`)

| Offset | Type | Meaning | Evidence |
|---|---|---|---|
| 0x10 | u32 | path count (5 here) | PathsFreeRoam.bin +0x10 = 5; 5 records fit exactly |
| 0x14 | f32 x | node/lane point X | +0x14 = 839.97 |
| 0x18 | f32 y | node point Y (≈ -370..-545, so the ground plane) | +0x18 = -372.845 |
| 0x1C | f32 | 1.0 constant, all records | +0x1C, +0x80, +0xE4 = 1.0 |
| 0x20 | f32 | 0.0 | +0x20 |
| 0x24 | f32 | 27 to 37, varies per record (speed limit or width) | +0x24=37, +0x88=30, +0xEC=27, +0x150=26 |
| 0x28 | u32 | 1 | +0x28 |
| 0x2C | u32 | 0 | +0x2C |
| 0x30 | 4xf32 | (758.857, -454.127, 921.083, -291.563) = two points x/z, opposite corners | +0x30..+0x3C |
| 0x40 | 4xu32 | 0 | +0x40..+0x4C |
| 0x50 | u16,u16 | 4 and 100, same in every record | +0x50 = 0x00640004 |
| 0x54 | 8xf32 | 4 corner pairs x/z: (758.9,-454.1) (921.1,-454.1) (921.1,-291.6) (758.9,-291.6) = a road rectangle | +0x54..+0x70 |
| 0x74 | u32 | 5, same in every record (record terminator) | +0x74, +0xD8, +0x13C |

Record stride = 100 bytes (0x64): records start at 0x14, 0x78, 0xDC, 0x140, 0x1A4; 0x14 + 5*100 = 0x208.
`0x208..0x2C4` (188 bytes) follows the array inside the same chunk: UNKNOWN (not decoded).

## Routes*.bin payload (traffic graph)

| Offset | Type | Meaning | Evidence |
|---|---|---|---|
| 0x04 | u32 | total size incl header (0xB050) | RoutesFreeRoam.bin +0x04 |
| 0x08 | u32 | 11 | +0x08 |
| 0x0C | u32 | 11 | +0x0C |
| 0x10 | u16,u16 | 1 and 100 | +0x10 = 0x00640001 |
| 0x14 | u32 | 0 | +0x14 |
| 0x18 | char[16] | name, NUL padded: "TrackRoutesA10" | +0x18..+0x27 |
| 0x28 | f32 | 1.0 | +0x28 |
| 0x2C | u16 | 46 | +0x2C |
| 0x2E | u16 | 46 (46 u/s ≈ 165 km/h) | +0x2E |
| 0x30 | 2xf32 | 0.0 | +0x30, +0x34 |
| 0x38 | f32 | 1.0 | +0x38 |
| 0x3C | 4xu32 | 0 | +0x3C |
| 0x40 | f32 | 0.0 | +0x40 |
| 0x48 | f32 | 424.79 (region size or scale) | +0x48 = 0x43D46480 |
| 0x4C | 6xu32 | 0xFFFFFFFF (-1 sentinel) | +0x4C..+0x64 |
| 0x68 | 3xf32 | first node: (-194.9, 873.1, -113.1) | +0x68..+0x70 |
| 0x74 | f32 | 1056.5 | +0x74 |
| 0x78 | | first node record, variable length, starts right after | +0x78 |

Node records are variable length (0x78→0xA0 is 40 bytes, next stride differs); each begins with 5 bytes of
per-node bytes (`0x64 0x10 0xF8 0x01`, then 0x05) and repeats the `... 06 06 06 06 06 06 06 06` tail.
Field-level meaning of a node (links, lane ids) is UNKNOWN: not decoded.

`RoutesFreeRoam.bin` and `RoutesAll.bin` both 49508 bytes but not identical: they differ in flag bytes at
0x7C (0x01 vs 0x00). Source: byte compare of both files.

## Lanes vs graph

Confirmed: Paths files carry road rectangles and a per-record speed-ish value 26..37; Routes files carry a named
graph ("TrackRoutesA10") with per-node floats. Which Routes node field links to which Paths record index is UNKNOWN.

## OpenUG2 reader

UNKNOWN: no local copy, and the GitHub code search needs auth (401). Only seen named by the OWNER as open prior art.
Detection rule: files start with chunk id `0x00034121` (Routes) / `0x80034147` (Paths).
