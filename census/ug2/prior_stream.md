# UG2 world streaming: how the city is split and loaded (prior art, 2026-11-10)

Read-only. Sources: OpenUG2 `whoismept/OpenUG2` docs (FORMATS.md, DEVELOPER_GUIDE.md), the real
install at `~/RE-NFSU-UG2/.../TRACKS`, and our own `census/ug2/coll.md`, `coll_load.md`, `l4ra_chunks.tsv`.
Nothing run. UNKNOWN = not proven by any source below.

| Fact | How UG2 splits / loads it | Source |
|---|---|---|
| World is 8 region bundles, not one map | `STREAML4RA/RB/RC/RD/RF/RG/RH/RR.BUN`; RA alone is 118,489,088 B | `TRACKS/` listing; `census/ug2/tracks_files.tsv` |
| Bundle = chunk tree, walk by id | u32 id + u32 size; recurse only when `id>>28 == 8` | FORMATS.md:97-111 |
| STREAML4RA.BUN head | zero chunk @0x0 (0x34), root `0x80134000` @0x3c, size 274,740; first section `0x80134100` @0x240 | own walk of the file |
| Geometry family | `0x80134000` -> `0x80134010` (object + matrix + name) -> `0x80134100` (mesh) | FORMATS.md:167-176 |
| Section table lives in the SMALL companion | `L4RA.BUN` (422,528 B) carries gameplay tables for STREAML4RA: `0x34112` header @0x0 (96 B), `0x34110` @0x21480, `0x34111` @0x28f60, `0x34107` @0x28f80 (51,448 B), `0x3412f` @0x50100, `0x34250` @0x14d00, `0x80034150` @0x68 (84,044 B: `0x34151..0x34155`) | `census/ug2/l4ra_chunks.tsv` (real offsets) |
| `0x34107` = section/placement override table | 8-byte rows: u16 section id, u16 placement row, u16 flags copy, u16 ref count. 51,448/8 = 6,431 rows in RA | FORMATS.md:409-427; 6,430/6,431 join confirmed at :440-443 |
| 21,342 override rows exist across all 8 regions | all resolve to an existing section/placement | FORMATS.md:429-434 |
| Sections are spatial, and event art shares them | "event graphics and ordinary scenery share spatial sections"; districts may overlap | FORMATS.md:405-408, 663-668 |
| Placement data per section | `0x34101` (placements) and `0x34103` (rows); `0x34107` points into them | FORMATS.md:409-416, 943-946 |
| Collision split per section | 255 chunks `0x80034130` in STREAML4RA.BUN; leaves `0x34131` header / `0x34134` polys / `0x34136` refs / `0x34137` cells (32-unit XY cells) | `census/ug2/coll.md`; FORMATS.md:120-142 |
| Section id field | FORMATS says u32 at +0; our own decode saw u16 id then f32 bbox in the same 48 B header | FORMATS.md:132 vs coll.md (agree if u32 = id + pad) |
| Which sections are visible | NOT a file list. OpenUG2 picks a *resident* set at runtime; retail's own visible set is UNKNOWN | FORMATS.md:663-668; DEVELOPER_GUIDE.md:464 |
| Streaming policy in OpenUG2 | one resident, `resident=1400 m`, `draw=933 m`; 400 m cell snapping; background build, swap at a frame boundary, old resident freed after | DEVELOPER_GUIDE.md:464-466, 1386-1399 |
| Cost of loading too much | 700 m chunk 12,017 meshes; 1400 m 13,797 (2,149 placements); whole bundle 96,841 | DEVELOPER_GUIDE.md:142-145, 489-492 |
| Live streaming of unloaded sections | NOT implemented in OpenUG2; "district-specific copy selection and live streaming are separate, unimplemented work" | DEVELOPER_GUIDE.md:152-154 |
| LOD | no distance LOD decoded. Instance reader tries 3 stored keys (primary + alternatives) as availability fallback; vista sheets `PAN_*`, `*_WORLD_LOD` go to `World.vista` | FORMATS.md:602-612, 502-505 |
| Overall consequence | "STREAM bundles are overlapping route/event working sets, not adjacent map tiles" | DEVELOPER_GUIDE.md:465-466 |

## What this means for the port
- The split is per section (spatial id), the load unit is the whole bundle file: there is no shipped
  index of "visible sections", so any per-section streaming we build is our own policy (like OpenUG2's radius).
- `L4RA.BUN` is the only place that joins section id -> placement -> event group; STREAML4RA.BUN alone is geometry + collision.
- Our collision plan (`coll_load.md`) already treats each `0x80034130` as an independent block, which matches this split.

## UNKNOWN
- Retail (SPEED2.EXE) section activation and per-section unload order: no address, no decode.
- Whether a visible-section list exists in the exe near STREAM open; not searched.
- The `0x3410x` sub-chunk roles beyond `0x34101/03/07` (e.g. `0x34108`, `0x34113`, empty sizes in l4ra_chunks.tsv).
