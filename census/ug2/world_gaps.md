# UG2 world decoder: chunk ids read, ids ignored, mesh fields dropped

Decoder: `tools/ug2_world.py` (228 lines). Census: `census/ug2/l4ra_chunks.tsv`.
Real files: `.../Need For Speed Underground 2/TRACKS/L4RA.BUN` (422,528 B) and `STREAML4RA.BUN` (118,489,088 B).
The TSV is **top-level only** (`tools/probe/ug2_chunk_census.py:16-26`) and covers **L4RA.BUN**. A read-only walk with the
decoder's own `tree()` logic finds **0 of the 8 ids it reads inside L4RA.BUN**, and all 8 inside `STREAML4RA.BUN` (nested).
So `l4ra_chunks.tsv` alone cannot describe what the decoder reads: it lists 21 ids, none of them used.

## Ids the decoder reads today

| id | what it does with it | source |
|---|---|---|
| bit31 set | any such id = container, children walked | ug2_world.py:34-35 |
| 0x80134010 | solid container | ug2_world.py:57 |
| 0x134011 | u32 hash @0x10, name @0xa4 only | ug2_world.py:62-65 |
| 0x134900 | 16 u32 header; only h[9]=ntri, h[13]=nv | ug2_world.py:66-69 |
| 0x134b01 | vertices, hardcoded 24 B stride | ug2_world.py:70-71, 119 |
| 0x134b03 | u16 triangle list | ug2_world.py:72-73, 122 |
| 0x80034100 | section container | ug2_world.py:77 |
| 0x34102 | defs 68 B; only u32 @32 (LOD0 hash), @36 (LOD1) | ug2_world.py:82-84, 138 |
| 0x34103 | instances 64 B | ug2_world.py:85-87 |

Occurrences in STREAML4RA.BUN (my read-only walk, same tree() rule): 0x80134010 10,735 (first 0x148), 0x80034100 606
(first 0x854008). `L4RA.BUN` top-level holds 237 chunks, 21 distinct ids, none of the 8 (matches tsv counts: 1+1+1+36+1+1+1+1+1+1+45+59+1+23+14+45+1+1+1+1+1 = 237).

## Chunk ids it ignores

Inside 0x80134010, never read: 0x134012 x10,735 (u32 texture hash + pointer pairs, the only texture link),
0x134013 x850, 0x13401a x65. Inside 0x80134100: 0x134b02 x10,735 (groups: texture slots and material flags), plus
section children 0x34101 x606 (section id), 0x34104 x606 (BVH), 0x34105 x197, 0x34106 x606.
Top level of STREAML4RA.BUN, never read: 0x80134000 x1,145, 0x80034130 x255, 0x80036000 x251, 0x80135100 x250,
0x80135000 x249, 0xb3300000 x206 (texture packs), 0xb0300100 x3.
Every id in `census/ug2/l4ra_chunks.tsv` is ignored, 21 of 21: 80034150, 80034020, 00034107, 00e34010, 8003b600,
00034110, 00034108, 00034026, 00035021, 8003b200, 00037090, 00037080, 0003412f, 00037110, 00000000, 00037150,
00034250, 00034112, 00034111, 00034113, 8003b000 (l4ra_chunks.tsv:2-22). Their meaning for UG2 is UNKNOWN here.

## Mesh fields it discards

| field | where it lives | discarded at | effect |
|---|---|---|---|
| UV | vertex bytes 16..24 (u,v) | ug2_world.py:119-121 | no UV and no texture in output (write() 217-223: pos + rgba + u32 idx) |
| texture hash / material | 0x134012, 0x134b02 texture slots | never read | whole city is untextured, one flat colour per vertex |
| normals | none in the vertex record; only computed for flat meshes | ug2_world.py:182-192 | shading done from winding, not shipped normals |
| vertex colour of all-black meshes | vertex bytes 12..16 | ug2_world.py:182-192 | RGB overwritten with grey by normal; original colour lost |
| unused vertices | 0x134b01 | ug2_world.py:160-166 | only vertices an index touches are kept |
| degenerate triangles | 0x134b03 | ug2_world.py:123-124 | dropped |
| vertex-format mask / stride | 0x134900 header h[0..8],[10..12],[14..15] | ug2_world.py:68-69 | stride hardcoded 24 B; a 60 B format would be misread (UNKNOWN if UG2 has one) |
| solid bbox, 4x4 matrix | 0x134011 @0x20/@0x30/@0x40 | ug2_world.py:62-65 | not used (NFSU1 doc says the matrix must not be applied) |
| def 6 hashes, LOD distances | 0x34102 offsets 0..31, 40..67 | ug2_world.py:84 | only LOD0 hash, LOD1 as fallback (line 138) |
| instance bbox | 0x34103 bytes 0..24 | ug2_world.py:157-159 | read only for a >2 m mismatch count, not exported |
| instance flags | 0x34103 u16 @26 | never read | hide/view flags ignored; bytes 62..64 also unread |
| duplicate placements | 0x34103 | ug2_world.py:142-145 | same (hash, pos, matrix) emitted once |
| named meshes | 0x134011 name @0xa4 | ug2_world.py:18, 139 | SKYDOME, PAN_, XO_VISTA meshes dropped whole |
| far instances | all | ug2_world.py:197-214 | city_lod.bin keeps 800k tris near the centre only |

Colour channels are swapped BGRA->RGBA at ug2_world.py:121, so colour is kept, not dropped.
UV and vertex-format facts come from the same engine in `docs/openworld/re_mesh.md:101-106` (NFSU1); the UG2 equivalence is UNKNOWN.
Also UNKNOWN: what 0x134013, 0x13401a, 0x34105, 0x34106 and 0x00034107/0x00034110 carry.
