# UG2 city collision (STREAML4RA.BUN), 2026-11-10

Tool: `python3 -I tools/ug2_coll.py` -> build/ug2/coll_rows.bin (unique 32 B rows, raw UG2 world units).

FACT (decoded and range-checked):
- 255 section chunks 0x80034130 in STREAML4RA.BUN, each: 0x34131 (48 B header: u16 section id, then f32 corner/bbox),
  0x34134 (polygon rows), 0x34136 and 0x34137 (per-section index tables, not needed).
- 0x34134 rows use the NFSU1 wsrc layout (tools/openworld/polys.py, Speed.exe 0x43ff30) with ABSOLUTE coordinates:
  x, y = s16/8, z = s16 base + s16/256 (x4 with flag 0x04). Same format, same units as NFSU1.
- 153,625 rows, 125,738 unique (sections share border rows). Ground (flags & 0x0a == 0): 87,753.
- Extent: x -3100.5 .. 1900.25, y -2080.6 .. 3151.9, z -508 .. 508 (z +-508 = infinite walls, as in NFSU1).
- Surfaces on ground rows: 1 (68,357), 16 (10,795), 8 (3,962), 11 (2,913), 15 (1,078); NFSU1 has the same top two.

NFSU1 Free Run for comparison (union of the 16 street tracks): x -699.3 .. 2446.1, y -1930.3 .. 822.5.
The two raw extents overlap, so the UG2 city needs a translation before it can sit next to NFSU1 (set by the bridge).

Limit: NFSU1 holds at most 65,534 rows per collision file (u16 widx, re_coll.md). NFSU1 union 54,735 + UG2 125,738
= 180,473 rows, about 2.8 x the limit. Open: widen the index or load UG2 rows another way (RE pending).

Placement (OWNER 2026-11-10, docs/re/ug2_bridge.md rank 1): R270 (x,y)->(y,-x), t (-1287.4, 812.2, -6.2); UG2 lands at x -3368..1864, y -1088..3913, inside +-4096.
Load path and limit fix: census/ug2/coll_load.md (u32 widx in 0x441660 + loader cave in 0x441380, original tracks stay u16).
