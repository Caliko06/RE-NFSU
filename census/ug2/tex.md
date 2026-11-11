# UG2 world textures: chunk ids, formats, links (tools/ug2_tex.py)

Exe = pc/ug2/SPEED2.EXE v1.2 (VA = file offset + 0x400000 in .text). Data = `.../Need For Speed Underground 2/TRACKS/STREAML4R?.BUN`
(the mesh and texture chunks live in STREAML4R*, not L4RA.BUN). Prior art (OpenUG2, MWEncyclopedia TPK, NFSU1 docs/re/assets.md) was only a lead: every row cites the exe or measured bytes.

## Facts
| fact | value | proof |
|---|---|---|
| Pack = `0xb3300000` > header `0xb3310000` + data `0xb3320000` | stand-alone data pairs by key | exe 0x494ea0: cmp 0xb3300000 / 0xb3310000 / 0xb3320000; header key = hdr+0x60 looked up at 0x494f2e |
| Header children | 0x33310001 (key @+0x60), 0x33310002 hash index (size>>3), 0x33310003 (not in UG2 track packs), 0x33310004 records, 0x33310005 gpu entries | exe 0x494380 cmp chain; counts: 0x33310004 = size/0x7c (mul 0x8421085), 0x33310005 = size>>5 |
| Record 0x7c B: hash @+0x24, link hash @+0x2c, pixel off @+0x30, palette off @+0x34, sizes +0x38/+0x3c, mip0 size +0x40, s16 w +0x44, h +0x46, mips +0x4e, name @+0xc | exe 0x48fd30 reads +0x24 (index search 0x488bc0, 8 B entries) and +0x2c; rest measured: STREAML4RA.BUN 0x85711c record 0 ARC_WHOUSE_DOOR_01 = 128x128, mips 5, npix 0x2aa0 = DXT1 mip sum |
| Pixel blob | 0x33320002 payload, first 128-byte boundary, record offsets count from it | exe 0x494f49: (x+0x87)&-0x80; image output proves alignment |
| GPU entry D3DFORMAT @+0x14 | 'DXT1' 0x31545844, 'DXT3', 'DXT5', 0x29 = P8 | measured over 5,087 records (RA,RB,RC,RD,RF,RG,RH,RR): see counts below; decoded images are correct (tex_contact.png) |
| P8 palette | 256 x RGBA bytes at record +0x34 (npal 1024) | measured: RDP_GRAVEL_A_CK pal alpha 255, rgb grey-blue; ARC_SIDEWALK_E alpha ramps 1..133 (blend texture, genuine). Channel order inferred from plausible colours: INFERENCE |
| Solid = 0x80134010 > 0x134011, 0x134012, 0x134013, 0x80134100 | | exe 0x493bb0 (solid loader) |
| Texture table 0x134012 | payload (chunk+8, NOT aligned) = pairs (u32 texture hash, u32 runtime ptr); count = size/8 | exe 0x493c02: solid+0x2c = esi+8; pair stride 8 and ptr at +4 read in draw 0x5c5a97 (`[ecx+8*edx+4]`) |
| Material table 0x134013 | payload pairs (hash, ptr) | exe 0x493c14: solid+0x3c = esi+8; draw 0x5c5ab5..5abb reads `[tbl+8*slot+4]` |
| Mesh header 0x134900 | +0x10 group count, +0x14 groups ptr (0x134b02 payload aligned 16), +0x18 indices (0x134b03), +0xc vertex mask | exe 0x5cc280 (0x5cc2b3, 0x5cc2dd, 0x5cc2f4) and 0x5c58a0 (+0x10 count) |
| Draw group 0x3c B | +0x00 bbox min f32x3, +0x0c u32 index count, +0x10 bbox max, **+0x1c u8 texture slot** (index into 0x134012), **+0x20 u8 material slot** (0xff = default material), **+0x34 u32 start index** | exe 0x5c58b2..0x5c58c7 (+0x34, stride 0x3c); 0x5c5a8c `movzx edx,[esi+0x1c]` -> texture table; 0x5c5aaa `[esi+0x20]`, 0xff -> 0x48ac50 default. +0x0c count: measured only (all 23,564 solids: sum counts = 3*h[9], groups contiguous from 0) |
| Vertex 24 B: xyz f32, BGRA u32, **uv f32 @+16** | | stride/xyz/colour from tools/ug2_world.py; uv offset measured: textured result looks right only by the contact sheet of textures, uv per-mesh NOT eyeballed (UNKNOWN) |
| Link | mesh triangle -> group (start/3 .. (start+count)/3) -> slot -> `0x134012[slot].hash` -> pack record `+0x24` | exe 0x5c5a8c..0x5c5a9b (record hash read at +0x24, pairs with 0x48fd30) |

## Counts (this run, tools/ug2_tex.py)
| item | value |
|---|---|
| packs / texture records in STREAML4R* | 502 / 5,087 (1,838 distinct hashes) |
| record formats (RA+RD+RB sample) | DXT1 3723, DXT3 443, P8 60, DXT5 3 |
| city.bin vertices / triangles (side file order verified IDENTICAL to city.bin: all vertex positions equal) | 7,286,167 / 5,043,580 |
| distinct texture hashes referenced by the drawn city solids | 1,735 |
| decoded and written (web/ug2/tex/*.png) | 1,727 (DXT1 1,518, DXT3 174, P8 35) = 99.5 % |
| no pack record anywhere searched | 8 (16 absent from track packs; 8 more found in GLOBAL/*.bin, InGameCommon.lzc, FrontB.lzc) |
| triangles whose texture is decoded | 5,022,589 of 5,043,580 (99.58 %) |
| distinct material hashes from 0x134013 used | 2 (7,693 groups carry a non-0xff material slot; meaning of the material record NOT decoded) |

## Outputs (generated, ignored)
`web/ug2/tex/<hash8>.png` RGBA mip 0 | `web/ug2/tex.json` list index = texture index (`file` null = unresolved) | `web/ug2/city_tex.bin` 'UG2T': u32 nverts, ntri, ntex, nmat, then nverts x (f32 u, f32 v), ntri x u16 texture index, ntri x u16 material index (0xffff = none). Same vertex/triangle order as city.bin.

## NOT verified
- uv convention (V flip) and wrap/clamp mode: uv min/max reach +-94,000 (71 % of verts inside 0..1); no mesh rendered textured here. Wrap mode is in the material/sampler state, not decoded.
- P8 RGBA byte order (inferred); DXT3/DXT5 alpha nibble order is the standard D3D9 layout, checked by eye on the TACOS neon and flares.
- 0x134013 material records and their effect (alpha, additive, tiling): UNKNOWN. Textures with `alpha` true in tex.json need blending but the blend mode is not proven.
- Same hash in several streams (RA/RD repeat): first pack wins; pixel equality of duplicates not checked.
- LOC4DYNTEX.BIN (night/dynamic textures, 95 MB): header-only pack, no records found; not used.
- No game or Chrome run.
