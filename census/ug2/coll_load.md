# How Free Run gets ground collision, and how to add the UG2 rows (2026-11-10)

Read-only study. Sources: pc/Speed.exe (base 0x400000) via objdump, census/ghidra decomp, docs/openworld/re_coll*.md, repo greps.
Nothing was run (no game, no Chrome, no build). Python used only for row counts over build/ug2/coll_rows.bin and the TRACKB files.

## 1. What Free Run loads today
- FACT: the WORLD row of the Free Run list is track id 1010, always on (host/openworld.c:68 WORLD_ID, :204 `id == WORLD_ID && worldrow_on()`).
  The game opens TRACKS\TRACKB1010.LZC; `rn_world_open` (host/openworld.c:171, called by gf_open host/files.c:192) serves
  build/openworld/TRACKB1010.lzc (:206), else TRACKB1001.lzc (WORLD_BASE, :209). Web: tools/serve.py:336 serves build/openworld at /world/.
  The 16 real tracks get merged files only with RN_WORLD=1 (?world=1, web/boot.js:108).
- FACT: the merged file IS in use, but it holds 53,603 rows, not 54,735: tools/openworld/build.py:55-66 `union_rows` drops 1,132 fence walls
  (census/openworld_build.json: union_polygons 54735, polygons 53603). Decoded build/openworld/TRACKB1010.lzc and TRACKB1001.lzc: wsrc 1,715,296 B = 53,603 rows,
  wcell 2,205 rows, widx 76,114 u16, wmap 10,120 B. Both files carry the same collision. Headroom to the u16 limit: 65,534 - 53,603 = 11,931 rows.
- Builders: build.py (`build_file` -> tools/hopper/q_owcoll2_write.py; asserts build.py:222 `<= 0xfffe`, q_owcoll2_write.py:55), tour.py:412 (OUT_ID 1010, tour variant
  is build/openworld/TRACKB1010.tour.lzc, Oct 28), citygraph.py:661 (`--write`, build/openworld_city). INFERENCE: the live TRACKB1010.lzc (Nov 1 10:07) is citygraph's output
  copied in; its collision equals build.py's. UNKNOWN: which command last copied it.

## 2. Every u16 / 65,535 limit (all from `objdump -d`, all addresses in Speed.exe)
Only 0x441660 reads widx entries; 0x441c10 and 0x4407b0 hold row POINTERS (dwords, no 16-bit load), 0x441530 reads wmap children.
| place | width | what a widening needs |
|---|---|---|
| widx entries, 0x441660 CollectPolys, 5 loads | u16 | `0f b7 4b fc` @0x4416c8 -> `8b 4b f8 90`; `0f b7 4b fe` @0x44179d -> `8b 4b fc 90`; `0f b7 0b` @0x441868 -> `8b 0b 90`; `0f b7 4b 02` @0x441932 -> `8b 4b 04 90`; `0f b7 0c 73` @0x441a30 -> `8b 0c b3 90` |
| same function, pointer math | step 2 B/entry | `8d 5c 73 04` @0x4416c4 -> `8d 5c b3 08` (lea ebx,[ebx+4*esi+8]); `83 c3 08` @0x441a09 -> `83 c3 10`. All 7 edits keep instruction length. Rows still `shl 5` (27 bits, ok) |
| widx count, loader 0x441380 (0x34133 branch @0x441423..) | `shr ecx,1` = size/2 into mgr+0x1c | INFERENCE: nobody reads mgr+0x1c (no xref to 0x77b14c; 0x441660 reads only +0x10 and +0x18), leave it |
| wcell `off`,`count` | u32 (0x441660 `[ecx+8]`,`[ecx+0xc]`) | none |
| wmap child / wcell row index | u16 (0x4415bd `movzx eax,word [ebx+2*edx]`) | none needed: UG2 uses 5,016 cells, union 2,204, sum ~7.2k << 65,535; wmap nodes also tiny |
| wsrc row count | u32 (0x441380 `size>>5`) | none |
| row +6 s16 | body POOL SLOT, not a row index (0x4400c1 writes it; 0x441b98 `movsx`, -1 = none; loader 0x441380 sets 0xffff on every row) | none while pool <= 0x7fff. Pool is already 0x4000: tools/recomp/patches_collision.py:11 (0x4412bd). re_coll_pool.md still says 0x2000 |
| body -> row | pointer at [body+0xc] (0x4400d0 clears +6) | none |
| save/restore 0x46a6e0 (called by World::DoSnapshot 0x41fc00) | writes row index as 2 B (`(row-0x77b140)>>5`, stream size arg 2) and ends with 0xffff; 0x46a440 names "TrackPolygon%d" | INFERENCE: snapshot = replay/rewind; no host reference to 0x41fc00. Rows >= 65,535 would be truncated there. Fix if needed: the three `push 2` size args -> 4 and the `0xffff` marker `c7 45 e4 ff ff 00 00` @0x46a89d -> `ff ff ff ff`. NOT VERIFIED that replay is unused in Free Run |
| 0x4407b0 cache / 0x441c10 | 160 pointers (push 0xa0 @0x440967, stack array ebp-0x28c; cache obj+0x20..+0x2a0) | not a row limit, see risk below |
| 0x441c10 world range | +-32767 | UG2 extent x -3100..1900, y -2080..3152 fits. Cell grid +-16384 (wmap, 1024x1024 cells) fits |
- Hot spot of the whole task: the exe's original TRACKB files keep u16 widx. A static reader patch (patches are build-time, `when` in tools/recomp/patches.py:46) breaks Original mode
  and the 16 plain tracks. So the loader must widen the original u16 chunk to u32 (small host cave on the 0x34133 branch of 0x441380) and the merged file ships u32 plus a flag.

## 3. Options, ranked
Measured with tools/hopper/q_owcoll2_gen.cells_of on build/ug2/coll_rows.bin (scripts in the scratchpad, not in the repo):
UG2 125,738 rows -> 5,016 cells, 186,519 widx entries, max 342 rows in one cell, max 990 in a 2x2 block (ground only: 87,753 rows, 4,995 cells, 133,305 entries, 169 / 488).
NFSU1 merged: 53,603 rows, ground 44,146 (walls &2: 9,378). Combined: 179,341 rows (180,473 without the fence cut), ~262k widx entries, 5.7 MB wsrc.
1. (a) Widen widx to u32 inside Speed.exe. Cost: 7 same-size byte edits in 0x441660 (table above) + one loader cave (u16 -> u32 for originals, static host buffer or flag for the merged
   file) + writer change (tools/hopper/q_owcoll2_gen.py:94-120 `build` packs `<%dH`, q_owcoll2_write.py:55 and build.py:222 asserts, q_owcoll2_sim.py reader). Everything else already
   fits (items above). File grows by ~1 MB (widx 4 B) + 4 MB wsrc before JDLZ. Needs a rebuild (not done here).
2. (b) Host replacement of 0x441660 (only that one; 0x441530 and 0x4407b0 need nothing). Same result as (a), but 1,196 B of logic to re-implement and keep byte-exact; its only gain is that
   it can also read a host table. Not better than (a).
3. (c) Cut rows: does NOT fit. Only 11,931 free rows = 13.6 % of the UG2 ground rows; even if every NFSU1 wall (9,457) were dropped, room is 21,388 = 24 %. Ground-only both: 131,899 rows.
4. (d) Two sets swapped by position: worst. The loader 0x441380/unload 0x441480 are file-load time functions with live bodies pointing into the old buffer (pool pins up to 160 rows per car,
   re_coll_pool.md); swapping needs every cache cleared and a reload mid-drive, and breaks "one universe, no cut".
- RECOMMEND (a): the reader has 5 loads and nothing else indexes rows, so widening is 7 same-length edits plus a loader cave, and it keeps the full 125,738 rows.

## 4. Risks that are not u16 (all checked by numbers, none by a run)
- FACT: the 160-polygon query cap stays. Cells with >160 rows in their 2x2 block: NFSU1 549 of 2,204 (355 of 2,195 ground), UG2 1,377 of 5,016 (744 of 4,995 ground). Same order of
  density as NFSU1, so no new class of risk, and the cap drops candidates silently in cell order (re_coll.md section 3).
- FACT: the body pool is already 16,384 (0x4000) slots, enough for 64 cars x 160.
- UNKNOWN: a ~9 MB decompressed TRACKB (wsrc 5.7 MB + widx 1 MB + rest 1.7 MB) against the request buffer/heap limit of the file system (0x447fcc alloc, flags 0x2000); the current one is 3.4 MB.
- FACT (format limit, not u16): a wsrc row stores x,y as s16/8 (0x43ff30), so every vertex must lie in -4096..+4095.875 m on both axes. NFSU1 spans x -699..2446 (3,145 m), y -1930..822 (2,753 m);
  UG2 spans x -3100..1900 (5,000 m), y -2080..3152 (5,232 m). Side by side they need 8,145 m in x (or 7,985 m in y) of the 8,192 m available: it fits only with almost no gap and a
  placement chosen for it. The UG2 -> NFSU1 translation must be fixed before rows are written; z is base s16 + s16/256, unaffected.
