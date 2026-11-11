# UG2 world textures: chunk ids, formats, links (tools/ug2_tex.py)

Exe = pc/ug2/SPEED2.EXE v1.2 (VA = file offset + 0x400000 in .text). Data = `.../Need For Speed Underground 2/TRACKS/STREAML4R?.BUN`
(the mesh and texture chunks live in STREAML4R*, not L4RA.BUN). The city = STREAML4RA.BUN only (ug2_world.py since df12a22); the other streams are only a texture-hash source. Prior art (OpenUG2, MWEncyclopedia TPK, NFSU1 docs/re/assets.md) was only a lead: every row cites the exe or measured bytes.

## Facts
| fact | value | proof |
|---|---|---|
| Pack = `0xb3300000` > header `0xb3310000` + data `0xb3320000` | stand-alone data pairs by key | exe 0x494ea0: cmp 0xb3300000 / 0xb3310000 / 0xb3320000; header key = hdr+0x60 looked up at 0x494f2e |
| Header children | 0x33310001 (key @+0x60), 0x33310002 hash index (size>>3), 0x33310003 (not in UG2 track packs), 0x33310004 records, 0x33310005 gpu entries | exe 0x494380 cmp chain; counts: 0x33310004 = size/0x7c (mul 0x8421085), 0x33310005 = size>>5 |
| Record 0x7c B: hash @+0x24, link hash @+0x2c, pixel off @+0x30, palette off @+0x34, sizes +0x38/+0x3c, mip0 size +0x40, s16 w +0x44, h +0x46, mips +0x4e, name @+0xc | exe 0x48fd30 reads +0x24 (index search 0x488bc0, 8 B entries) and +0x2c; rest measured: STREAML4RA.BUN 0x85711c record 0 ARC_WHOUSE_DOOR_01 = 128x128, mips 5, npix 0x2aa0 = DXT1 mip sum |
| Pixel blob | 0x33320002 payload, first 128-byte boundary, record offsets count from it | exe 0x494f49: (x+0x87)&-0x80; image output proves alignment |
| GPU entry D3DFORMAT @+0x14 | 'DXT1' 0x31545844, 'DXT3', 'DXT5', 0x29 = P8 | measured over 5,087 records (RA,RB,RC,RD,RF,RG,RH,RR): see counts below; decoded images are correct (tex_contact.png) |
| P8 palette | 256 x u32 at record +0x34 (npal 1024), file bytes B,G,R,A | exe 0x494a50 sets record+0x70 = pixels, +0x74 = palette (blob + offset, size-checked) then calls 0x5ce170; 0x5ce170 (`cmp [fmt],0x29`) copies `palette[index]` as a whole dword (0x5ce230..0x5ce23b) into a D3DFMT_A8R8G8B8 (0x15) texture, no swizzle, so bytes are B,G,R,A. FIXED in tool (it used R,G,B,A before) |
| Solid = 0x80134010 > 0x134011, 0x134012, 0x134013, 0x80134100 | | exe 0x493bb0 (solid loader) |
| Texture table 0x134012 | payload (chunk+8, NOT aligned) = pairs (u32 texture hash, u32 runtime ptr); count = size/8 | exe 0x493c02: solid+0x2c = esi+8; pair stride 8 and ptr at +4 read in draw 0x5c5a97 (`[ecx+8*edx+4]`) |
| Material table 0x134013 | payload pairs (hash, ptr) | exe 0x493c14: solid+0x3c = esi+8; draw 0x5c5ab5..5abb reads `[tbl+8*slot+4]` |
| Mesh header 0x134900 | +0x10 group count, +0x14 groups ptr (0x134b02 payload aligned 16), +0x18 indices (0x134b03), +0xc vertex mask | exe 0x5cc280 (0x5cc2b3, 0x5cc2dd, 0x5cc2f4) and 0x5c58a0 (+0x10 count) |
| Draw group 0x3c B | +0x00 bbox min f32x3, +0x0c u32 index count, +0x10 bbox max, **+0x1c u8 texture slot** (index into 0x134012), **+0x20 u8 material slot** (0xff = default material), **+0x34 u32 start index** | exe 0x5c58b2..0x5c58c7 (+0x34, stride 0x3c); 0x5c5a8c `movzx edx,[esi+0x1c]` -> texture table; 0x5c5aaa `[esi+0x20]`, 0xff -> 0x48ac50 default. +0x0c count: measured only (all 23,564 solids: sum counts = 3*h[9], groups contiguous from 0) |
| Vertex stride and uv offset depend on the mesh mask (0x134900 +0xc) | mask 0x0 / 0x40 / 0x1000: 24 B, xyz@0, BGRA@12, uv@16. **mask 0x4180: 36 B**, xyz@0, normal@12, BGRA@24, uv@28 | exe: mesh+0x3c = shader object chosen from the mask by the table at 0x800464 (0x5c58cf..0x5c591b: mask&0x1 -> 4, &0x40 -> 2, &0x80 -> 5, else 0, indexing 0x86eb28[]); SetStreamSource stride = `[0x870910]+8` of the active object (0x5cf5f0..0x5cf607). The per-object stride value itself was not found in the exe: UNKNOWN. Measured (STREAML4RA.BUN, 8,613 solids): vertex-buffer bytes / nv = 24.0 for masks 0x0 (8,982), 0x40 (1,605), 0x1000 (2) and 36.0 for 0x4180 (115 chunks, 62 distinct solids); values at stride 36 show normal (0,0,1), colour 0xffxxxxxx, uv in 0..1 |
| Group index count +0x0c | | exe 0x5cf7a1..0x5cf7ba: DrawIndexedPrimitive(TRIANGLELIST, ..., startIndex = (group+0x34 - indexbase)/2, primCount = [group+0xc] / 3 via mul 0xaaaaaaab). Proven |
| Link | mesh triangle -> group (start/3 .. (start+count)/3) -> slot -> `0x134012[slot].hash` -> pack record `+0x24` | exe 0x5c5a8c..0x5c5a9b (record hash read at +0x24, pairs with 0x48fd30) |

## Counts (this run, city = STREAML4RA, near-collision crop)
| item | value |
|---|---|
| packs / texture records in STREAML4R* | 502 / 5,087 (1,838 distinct hashes) |
| city.bin vertices / triangles (side file order verified IDENTICAL: every vertex position equal) | 4,449,461 / 3,051,862 |
| distinct texture hashes referenced by the drawn city solids | 1,483 |
| decoded and written (web/ug2/tex/*.png) | 1,478 (DXT1 1,299, DXT3 156, P8 23) = 99.66 % |
| no pack record anywhere searched (STREAML4R*, GLOBAL/*, FrontB.lzc) | 5 |
| triangles whose texture is decoded | 3,039,255 of 3,051,862 (99.59 %) |
| triangles with alpha test / alpha blend / additive | 571,272 / 32,624 / 198,589 |

## Draw state per texture record (step 2; exe addresses)
The state setter is 0x5bcc30 (esi = texture record), called from the flush loop 0x5cf420.
| record byte | exe | meaning | UG2 data (1,478 textures) |
|---|---|---|---|
| +0x55 | 0x5bcca7: `cmp [esi+0x55],1` -> 0x5bcb70(1, 0x5f) = SetRenderState ALPHATESTENABLE(15)=1, ALPHAREF(24)=0x5f; else (0,0) | ==1 alpha test, ref 0x5f. Value 2 is never tested by this code: UNKNOWN | 0: 1,152, 1: 148, 2: 178 |
| +0x56 | 0x5bccbc..0x5bcd14 -> 0x5bcbc0(en, src, dst) = ALPHABLENDENABLE(27), SRCBLEND(19), DESTBLEND(20); jump table 0x5bcf80 | 0 off; 1 SRCALPHA/INVSRCALPHA (5,6); 2 SRCALPHA/ONE (5,2) additive; 3,4 (5,6); 5 DESTALPHA/INVDESTALPHA (7,8); 6 DESTALPHA/ONE (7,2) | 0: 1,223, 1: 47, 2: 100 (only 0,1,2 occur) |
| +0x56 != 0 | 0x5bcd56..0x5bcd86: ZWRITEENABLE(14)=0 (blend 0: ZWRITE 1) | blended triangles do not write depth | |
| +0x51, +0x54 | 0x5ceb30: draw-queue bucket index = [+0x51]*0x17 + shader id, list chosen by [+0x54] | sort bucket, not decoded further | +0x51: 0 or 5 mostly |
| +0x52 | 0x5bcdf2: ==3 reads s16 +0x5e/+0x60 (uv scroll) | texture animation, not decoded | 0: 1,814 of 1,836 |
Combos seen (+0x55,+0x56): (0,0) 1,142; (1,0) 148 foliage/steel braces; (2,2) 90 neon; (2,1) 47 glass/fence; (2,0) 41 court decals; (0,2) 10 lights.
Consequence: alpha is only used when +0x55==1 or +0x56!=0. With both 0 the palette/DXT alpha is ignored (road P8 textures carry alpha ramps 1..9 that must NOT be drawn). tools/ug2_tex.py stores those PNGs opaque; `tex.json` keeps `flag55`, `flag56`, `blend` (none/alpha/add), `alpha_test`, `alpha` (= test or blend), `raw_alpha`.

## Magenta tiles of the first contact sheet (step 2, point 1)
Not an index bug. Cause 1: the sheet background was magenta and these textures have alpha ~0 in the colour area (decals, lights, road P8) which the draw never uses (above). Cause 2: P8 channel order was R,G,B,A; exe says B,G,R,A (table above); road textures now decode with correct colour (lane marks yellow/white, asphalt grey). Sheet: census/ug2/tex_contact.png (alpha textures over a checker, others opaque).

## Vertex mask (step 2, point 2): distribution in STREAML4RA.BUN (8,613 solids)
| mask | solids | verts | stride (size/nv) | uv min..max | uv inside 0..1 |
|---|---|---|---|---|---|
| 0x0 | 9,013 chunks | 1,113,675 | 24 | -94,204..93,939 | 61 % |
| 0x40 | 1,605 | 187,248 | 24 | -4,485..12,976 | 34 % |
| 0x1000 | 2 | 16 | 24 | 0..1 | 100 % |
| 0x4180 | 115 chunks (62 distinct solids) | 3,624 | **36** | -2.9..5.2 (at uv@28) | 62 % |
(counts are chunk occurrences, a solid hash can repeat.) Large uvs: only 50 of 8,613 solids have |uv| > 1,000, all TRN_* terrain / powerline pieces; for TRN_CS_POWERLINES_CHOP_Q11 uv is exactly linear in xyz (least squares residual 0.008): world-planar uv, so the renderer needs REPEAT and fractional uv; TRN_IP_TERRAINA_NR_CHOP_I6 is not linear (UNKNOWN). Not a layout error: stride matches for all of mask 0.
**tools/ug2_world.py hardcodes 24 B**: wrong for the 115 chunks of mask 0x4180 (62 distinct solids, 510 near instances). Under a 24-byte read 48 of the 62 solids still give finite positions, so they are drawn with scrambled vertices (only vertex 0 of each is right), and 14 are dropped. With the per-mask stride the city would gain 21,862 vertices / 11,436 triangles (side-file walk: 4,471,323 / 3,063,298). The side file uses the correct uv offset and, to stay aligned with the current city.bin, positions at 24 B; if ug2_world.py is fixed, rerun the tool: it detects which one matches (`positions_with_per_mask_stride` in tex.json).

## Material record 0x134013 -> 0x135200 (step 2, point 3)
- 0x134013 pairs (hash, ptr); the draw takes `[table + 8*slot + 4]` (group +0x20, 0xff = default 0x48ac50) and passes it to the draw queue (0x5ceb30 arg 8, entry +0x28). Used by 7,693 of 56,982 groups, and by only 2 hashes in the city: 0x001c3745 and 0x5f5fa298.
- The records themselves are `0x135200` chunks (160 B: hash @+0xc, version 3 @+0x10, name @+0x14, then 27 f32) in **GLOBAL/GLOBALB.BUN** (186 records; also GlobalB.lzc), not in the track streams. 0x001c3745 = "ROAD" (floats: two colours 0.9,0.57,0.56,1; 1.5230; 2.0; 0.048; 0.302), 0x5f5fa298 = "ALUMINUM_2" (colour-ish 1.0..1.1, zeros). These are lighting / specular shader parameters, not blend or wrap flags: blend and alpha test come from the TEXTURE record (table above). Which float the shader reads: UNKNOWN. tex.json lists the two hashes in "materials" (index = city_tex.bin material index).
- Wrap/clamp: no per-record address-mode setter found in the mesh draw path (the SetSamplerState/TextureStageState sites near 0x5c24e7 set filters; effect objects are called through their own vtable). Record bytes +0x4b, +0x4c are always 0; +0x48/+0x49 are log2 w/h. Wrap vs clamp is UNKNOWN; D3D default is WRAP.

## Outputs (generated, ignored)
`web/ug2/tex/<hash8>.png` RGBA mip 0 | `web/ug2/tex.json` (per texture: hash, file, w, h, fmt, name, pack, alpha_test, blend, alpha, raw_alpha, flag55, flag56; list index = texture index; `file` null = unresolved) | `web/ug2/city_tex.bin` 'UG2T': u32 nverts, ntri, ntex, nmat, then nverts x (f32 u, f32 v), ntri x u16 texture index, ntri x u16 material index (0xffff = none). Same vertex/triangle order as city.bin. The instance walk is a copy of ug2_world.main (its near() and loop are nested in main(), not importable); it is guarded by the IDENTICAL-positions check against city.bin.

## NOT verified
- uv wrap/clamp (UNKNOWN above) and the V convention; no mesh was rendered textured here.
- Record +0x55 == 2 (178 textures: court decals, glass, neon): the exe code only tests ==1; their draw path (probably effect shader) not decoded. Blend factors for 3..6 are exe-read but unused by data.
- The 0x4180 stride: 36 is measured from buffer size and values, the exe object stride value was not located.
- TRN_IP_TERRAINA_NR_CHOP_I6 uv (non-linear, +-94,000): not explained.
- Same hash in several streams (RA/RD repeat): first pack wins; pixel equality of duplicates not checked.
- LOC4DYNTEX.BIN: header-only pack, unused. DXT3 nibble order is the D3D9 standard (checked by eye on neon/flares).
- No game or Chrome run.
