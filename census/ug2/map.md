# UG2 map picture and its world bounds (2026-11-11)

Goal: the WORLD Free Run minimap (track 1010) shows the UG2 city from UG2's own shipped map. Read-only study, no game run.
Exe = `pc/ug2/SPEED2.EXE` v1.2 (VA = file offset + 0x400000, checked with `rea address-to-file-offset`). Data = `/Users/angeldamian/RE-NFSU-UG2/Need For Speed Underground 2/`.
Proof sources: REA CLI 6.7.0 (`function`, `xrefs`, `search`, `read-bytes`, `address-to-file-offset`) + capstone/objdump on the same exe as second source + byte reads of the data files.
Marks: FACT = bytes or code read (address / file offset given), INFERENCE = fits all data, no code proof, UNKNOWN = not proven (nothing is built on it).

## 1. Texture (the picture)
| item | value | proof |
|---|---|---|
| file | `TRACKS/TRACKMAP4000.BIN` (4,195,072 B), one TPK (`0xb3300000`); 129 such files, ids 4000..4716 | `ls`; exe string `TRACKS\TRACKMAP%d.bin` 0x791864 (file 0x391864), `TRACKMAP%d` 0x791858 |
| name, hash | `TRACKMAP4000`, hash `0xf7600936` | record name @0xf0, hash @0x108 of the file; exe hash fn **0x43db50** (`or eax,-1; imul eax,eax,0x21; add eax,c`) = h = -1, h*33 + c, called by 0x50b990 (sprintf + hash) from 0x4b54ac; python of the same fn gives f7600936 for "TRACKMAP4000", f7600937 for 4001 = the next file's record |
| record | 0x7c B at file 0xe4 (chunk `0x33310004`): pixel offset +0x30 (@0x114) = 0; mip0 size +0x40 (@0x124) = 0x400000; **w +0x44 (@0x128) = 2048, h +0x46 (@0x12a) = 2048**; mips +0x4e (@0x132) = 1 | bytes of the file, layout from census/ug2/tex.md |
| format | **D3DFMT DXT5** (`0x35545844`) at gpu entry +0x14 (@0x17c, chunk `0x33310005` @0x160) | bytes; DXT5 = 16 B per 4x4 = 1 B/pixel = 0x400000 B = mip0 size |
| pixels | file 0x300..0x400300: chunk `0x33320002` header @0x280 (size 0x400078), payload @0x288, first 128-byte boundary = 0x300 (exe 0x494f49 rule in tex.md) | bytes |
| decode | `tools/ug2_tex.py` `packs()` + `decode()` -> 2048 x 2048, alpha 255 everywhere, RGB = dark terrain, water, grey and white roads; no route line, no markers | decoded and looked at: `web/plan/shots/ug2_worldmap.png` is built from it |
| loaded by | `0x4b53c0` (REA decompile): `esi[0x15] = *(s16*)([0x863448] + 0x18)` (the track id), `row = 0x5d3e40(id)`, `sprintf("TRACKS\TRACKMAP%d.bin", id)` (call 0x4b549e), `esi[0x16] = hash("TRACKMAP%d")` (0x4b54ac), file opened with 0x57d900 into the pool "TrackMapMemory" 0x791848 (0x4b54c5..0x4b54d0), loaded by 0x57cef0 | exe 0x4b53c0..0x4b5500; second source capstone, same bytes |
| why 4000 | Free Roam start sets `[0x89e7a0]` (current track id) = 0xfa0 = 4000 and `[0x89e7b0]` = 0 (the Free Roam flag of roads.md) | exe 0x540571 and 0x5407d6 (`mov [0x89e7a0], 0xfa0` next to `mov [0x89e7b0], ebx(0)`); the id read by 0x4b53c0 comes from `[0x863448]+0x18`, not from `[0x89e7a0]`: that it is 4000 in Free Roam is **INFERENCE** (row 4000 is "(40XX-41XX) Circuit/Sprint", L4RA) |
| other pictures | 4001..4177 (L4RA races) = the same base terrain + the race route in white; 4500..4504 (512 x 512 DXT3, alpha 0) = city-centre highlight; 4200..4222 / 4300 / 46xx / 47xx = other arenas (STREAML4RB..RH) | decoded contact sheet of all 129 files; only 4000 shows the whole L4RA city without a route (looked at) |

Not used: string `WORLD_MAP` (0x7a2cf8) is a table entry of joystick event names (`JOY_EVENT_REQUEST_WORLD_MAP`), no xref, not a texture. `Track2000_map` (0x798b18, FNG element lookup 0x4f741e) is a UI element name, not a picture.

## 2. World -> pixel bounds
| item | value | proof |
|---|---|---|
| table | chunk `0x34201` of `GLOBAL/GLOBALB.BUN`: header @0x735f00 (size 38,776 = 131 rows x 0x128); **GlobalB.lzc** @0x1027f50 holds the same chunk with 130 rows (the exe names both: `GLOBAL\GLOBALB.BUN`, `GLOBAL\GLOBALB.LZC`; which one is read: UNKNOWN, row 4000 is identical in both) | chunk walk (`chunks.py` of this study) |
| loader | `0x5d3eb0`: `cmp [chunk], 0x34201`; `[0x883da0] = chunk + 8`; `[0x883da4] = size / 0x128` (mul 0xbacf914d, shr 8). Unloader 0x5d3ef0. Registered by `push 0x5d3ef0 / push 0x5d3eb0 / push 0x34201` at 0x77e740 | exe, REA `function` + objdump |
| lookup by id | `0x5d3e40`: scan rows (stride 0x128) for `movsx [row + 0x8a] == id` | exe, REA + objdump |
| row 4000 | BUN file @0x7365f8 (row index 6): name "(40XX-41XX) Circuit/Sprint" @+0, "Location4\Track_4000" @+0x20, region "L4RA" @+0x40, **id s16 @+0x8a = 4000**, rotation u32 @+0x98 = 0 | bytes; same row in GlobalB.lzc @0x1028648 |
| **X0** | f32 @+0xac (file 0x7366a4) = **-3425.429931640625** | bytes; read by exe 0x4b0a33 (`mov edx,[ecx+0xac]`) |
| **Y0** | f32 @+0xb0 (file 0x7366a8) = **3287.260009765625** | bytes; exe 0x4b0a3d |
| **S** | f32 @+0xb4 (file 0x7366ac) = **5633.16015625** (square: the one value spans u and v) | bytes; exe 0x4b0a21 |
| same for all L4RA rows | 71 rows (region L4RA: id 4000, 4011.. and the other L4RA race ids) share X0, Y0, S | table scan of the 131 rows |
| use | the world-map object **0x4b09e0** (REA `function`): `row = 0x5d3e40([0x89e7a0])` (0x4b0a01), copies +0xac/+0xb0/+0xb4 (0x4b0a21..0x4b0a3d), maps the viewed window A = X0 + t*S, B = Y0 - t2*S to **u = (A - X0) * (1/S), v = (Y0 - B) * (1/S)** (0x4b0aad..0x4b0ae1; 1.0 = `[0x784250]`, 1/512 = `[0x78f8cc]`) | exe; no rotation and no flip in this code |
| rotation | row +0x98 (int) is read by 0x4b53c0 (`fild [ebx+0x98]`, times 0x791884 = 0.000625) and is 0 for row 4000 | exe 0x4b5432..0x4b544c, bytes |
| check with data | the 10,603 UG2 road nodes of `RoutesFreeRoam.bin` (tools/ug2_roads.py, raw UG2 x, y) put through u = (x - X0)/S, v = (Y0 - y)/S on the 2048 px picture: **75.9 %** land on bright road pixels (L > 110) against 16..19 % when the nodes are shifted by 60 px and 14 % / 7 % when x/y are swapped / v is flipped; overlay looked at | scratch overlay, this study |

## 3. Placement in the NFSU1 world (not new, reused as is)
| item | value | proof |
|---|---|---|
| transform | (x, y) -> (y + TX, -x + TY), TX -1287.375, TY 812.25 | `tools/ug2_roads.py` `to_nfsu1`, `docs/re/ug2_bridge.md` decision |
| picture square in WORLD units | x' -3633.3..1999.9, y' -1395.5..4237.7 (= UG2 x -3425.43..2207.73, y -2345.9..3287.26) | arithmetic of the two tables above |
| pixel mapping | the picture turns a quarter turn clockwise: world[py][px] = ug2[n-1-px][py] (u grows toward -y', v toward -x') | derived from the transform; checked: 10,603 UG2 nodes through `to_nfsu1` fall on the pasted roads (scratch overlay) |
| bridge road | x 114.8..128.8 (width 14), NFSU1 stub axis x 121.8 from y 394 (60 ground rows y 394..508, dead end 507.9) to the UG2 south ground edge y 588.8..589.6 | `docs/re/ug2_bridge.md` (FACT rank 1, "Bridge road built") |

## 4. New WORLD bounds (tools/openworld/worldmap.py, host/openworld.c)
One square holding both cities: NFSU1 road nodes x -691..2393, y -1920..734 + the UG2 square above. **X0 = -3650, Y0 = 4260, S = 6240** (x -3650..2590, y -1980..4260; 24.4 world units per pixel at 256 px; UG2 itself is 2.75 per pixel at 2048).

## 5. UNKNOWN / not verified
- Runtime: nothing was run. That the HUD minimap of the WORLD row shows the picture the way the 1024 preview does is NOT VERIFIED; world_entry.md already says the NFSU1 minimap follows the player and the zoom is relative to S, so with S 6240 the visible piece is about twice as wide as before.
- Size stays 256 x 256: the TPK record could hold more (w,h @+0x44) but the NFSU1 loader path for a bigger map texture was not traced here. The 1024 preview is `build/openworld/world_map_1024.png`.
- Whether the UG2 HUD minimap (`MinimapEntity` 0x790b18 / `MinimapWrapper`, FNG lookups at 0x4ac6d2, 0x776b32) reads the same row: not traced; only the world-map object 0x4b09e0 and the loader 0x4b53c0 are proven readers.
- That `[0x863448]+0x18` = 4000 in Free Roam (INFERENCE, section 1). Which of GLOBALB.BUN / GlobalB.lzc the exe reads.
- The picture's alpha is 255 and the roads are grey/white: the exe's blend of the map quad (0x4b0b19 -> 0x5179d0 calls) is not decoded.
