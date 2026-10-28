# Open world: all of Olympic City, no fences

OWNER 2026-10-27: "connect the whole NFSU world, remove the fences, real Free Run, drive the whole map like GTA."
Apart from Free Run (host/free.c, RN_FREE), which stays as it is.

## Scope
- In: region L1RA, the 16 street tracks (circuits 1001-1008, sprints 1102-1109), one drivable city with the
  player, traffic, and optionally the free-mode rivals.
- Out (OWNER): drag and drift arenas (L1RB/RC/RE, 1201-1214, 1301-1308), test track 1099, new menus, police,
  online. Entry is a switch (RN_OPEN, ?mode=open) on top of a Free Run launch on an L1RA track.

## Measured (2026-10-27, game/Tracks, ref/tools/ug1-tracks streams.py + tracks.py pc)
- All 16 street tracks share ONE world stream: STREAML1RA.BUN (92 MB, 423 sections, ids 101..2617). The bulk of
  the city lies within x -607..2338, y -1931..706 (p2..p98 of section AABBs, s16, units probably m); 2-3
  sections are huge (sky/backdrop).
- Their per-event streams STREAML1RA_<id>.BUN are 0 bytes, so the visible city is the same for every L1RA race.
- L1RB/RC/RE reuse section ids but NOT the coordinates (1 matching AABB each): separate arenas, not connected to
  the city by geometry. Hence they are out.
- Everything that differs per track is in TRACKB<id>.lzc. Bytes per chunk (tracks.py pc):
  roads 0x34121 125-465 KB, links 0x34122, routes 0x34124, walls wmap/wcell/wsrc/widx 0x34130-33 (wsrc 245-773 KB),
  markers 0x34146, route rhead/rnode 0x34148/49, section 0x34154 (32 B), props 0x34027 (7-50 KB), zones 0x3414a.
  Sprints carry ~2x the walls and roads of circuits: those chunks cover the route corridor, not the whole city.

## PC anchors (census/hopper/decomp.c; confirm in Speed.exe before relying on them)
| what | load | unload |
|---|---|---|
| walls 0x34130-33 (wmap, wcell, wsrc, widx) | sub_441380 | sub_441480 |
| roads 0x34121 / routes 0x34124 | sub_442dd0 | sub_442e60 |
| stream sections 0x80034100 (0x34101 id, 0x34103 placements) | sub_4457c0 | sub_445b66 |
| section 0x34154 | inside sub_446db0 | |
| props 0x34027 | inside sub_5952a0 | |
PS2 ELF equivalents are in the ref tool docstrings (walls 0x159578, roads 0x15cca0, props 0x307908, TrackStreamer::Init 0x15f8e0).

## Answers (2026-10-27, from Speed.exe; REA ghidra ev_328ced7e = props loader 0x5952a0)
1. Collision (ANSWERED). wsrc 0x34132 = "TrackPolygon" rows of 32 B, ground AND walls; layout in
   tools/openworld/polys.py (loader 0x441380, manager 0x77b130; body build 0x43ff30/0x43fd20). The car's ground
   query 0x440a40 uses only these polygons (list from 0x4407b0, (flags & 0x0a) == 0) and returns "no ground" off
   them: there is no other ground source. Bodies: "TrackPolygon%d" 0x46a440, save/restore 0x46a6e0.
   Measured: the 16 tracks are cuts of ONE city mesh: 54,735 unique polygons, 97.5 % identical byte for byte across
   tracks. So the union of the 16 wsrc is a clean world collision. Flags 0x00/0x10/0x11 ground, 0x12 low walls,
   0x16 infinite walls (z -508..508). Surface byte (+2) does not mark fences.
2. Fences (ANSWERED from the data, 2026-10-27 late). A wall W of track A is a fence when another track B has ground
   on both sides of W and B's wsrc does not hold W: the game, loading B, drives through it. tools/openworld/fences.py
   -> census/openworld_fences.json, build/openworld/fences.png: 1,149 of 10,510 union walls (0x12: 735, 0x16: 414),
   all at junctions where a route turns away. Walls with ground on one side only (the T-shaped stubs) are where the
   collision mesh ends: removing them drops the car off the ground; they need new ground first (phase G).
   The closure barricades you SEE (XO_TRACKBARRIERA, TRACKTURNBARRIER*, TRACKBARRIERNEOND) are static placements in
   the per-track section 2601..2617 (the 0x34154 one), no instance row: dropping 0x34154 drops them. Smackables
   (docs/openworld/re_props.md): an instance row 0x34027 (0x70 B, class key @+0, (section, index) of a base-stream
   placement @+4/+6) makes that placement breakable; 32 smacked at once (SmokeableSlotPool), count < 0x8000.
   Union of the 16 tracks: 77 classes, 1,122 unique instances (census/openworld_props.json).
3. Streaming (ANSWERED, docs/openworld/re_stream.md). The streamer already follows the car city-wide: 0x445050
   per frame, 0x48e8b0 car pos/vel, 0x444870 samples 3 points ahead, 0x446fd0/0x5679b0 find the boundary polygon,
   0x444b50 builds the wanted set from its 0x34152 visible list + fixed 2500/2400/2600/2499 + the track's 0x34154
   section (2601..2617, one per track, hugs the route at 12-22 m: lead, probably the track's barrier geometry).
   0x34151 polygons, 0x34152 lists and the 11 prediction zones are identical in all 16 tracks and cover the whole
   city. Per track only: preload flag 0x34107 +0xa (the corridor), lookahead filter 0x34153, 0x34154. Pool = preload
   + 2 MB (0x449996..0x4499a0), async, 3 reads in flight, LRU (0x444780), cap 256 sections per round in 0x444b50.
   Merged set: base track, drop 0x34153 and 0x34154, keep its preload flags (the union, 341, passes the 256 cap);
   optional margin 2 -> ~6 MB at 0x4499a0. Unmeasured: load speed at top speed.
4. Map (DONE, phase B): tools/openworld/map.py -> build/openworld/map.png + census/openworld.json. The 16 routes
   form one connected street network.
5. Collision writer (DONE, docs/openworld/re_coll.md). wmap = 10-level quadtree over [-16384,16384)^2, 32-unit
   leaves -> wcell -> widx u16 -> wsrc; walk 0x441530/0x441660/0x441c10. Re-derived for all 16 tracks: 100 % byte
   match. Caps: 65,534 polygons (union 54,735), 160 per query (0x4407b0), 1024 bodies (0x4412b0, int3 when full),
   unknown top-level chunk id = int3 (0x447ac0). .lzc = JDLZ v2 (decoder 0x58d190); 0x58d3c0 also takes raw.
   Writer: tools/hopper/q_owcoll2_write.py, q_owcoll2_lzc.py.
6. Visual city vs collision (DONE, docs/openworld/re_mesh.md, visual_vs_coll.png). The visible streets end where
   the collision ends: of 77 stub ends, 67 have no street past them; 4 continue 44-87 m ((-184,-1346),
   (-119,-1402), (933,-1549), (1423,-435)). 25 % of visual road has no ground under it, nearly all < 2 m from
   ground (shoulders, plazas). So the drivable city IS the union of the 16 corridors.

## Phases and who (2026-10-27 late, after answers 1-6)
| phase | who | done when |
|---|---|---|
| D1. Merged TRACKB per base track: union wsrc minus fences, union props 0x34026/27, 0x34153 and 0x34154 dropped; RN_WORLD overlay in host/openworld.c | sonnet-exec | native run: car on a 1001 launch driven/teleported into a 1107-only street, on ground, no wall at the fence |
| D2. Breakable barricades at the closures: a new 26xx-like section with the barrier placements at fences, each with an instance row | RE sonnet-exec, then build | native shot: barricade at a fence, a hit knocks it |
| E. Traffic and AI on the merged roads 0x34121/22/24 | RE then build | traffic drives off the base route |
| F. Chrome: serve the overlay (tools/serve.py is shared with the peer session) | Opus | webcheck PASS, the OWNER drives it |
| G. The 4 stubs that continue visually: ground from the render mesh | later | |

## Rules for this block
- RE before runs. A run confirms a prediction. Runs are bounded (RN_SECS, head -c), muted, off-screen.
- Every patch is one line in the patch table with why; the switch off gives the shipped game.
- Write what is learned here (addresses, layouts) and in commits.
