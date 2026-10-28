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

## Questions, in order (each one is answered from the exe before any run)
1. Collision: is wsrc only the side walls, or the ground too? How does a car find the road height off the track
   (sub_441380 -> its users)? This decides everything: per-track walls mean that off a track's corridor there is
   either nothing to hit (fall through or float) or an invisible wall.
2. Fences: what is a fence, physically? Candidates: wall segments in wsrc that close side streets, props
   (0x34027: cones, barriers, signs) and/or scenery the section/zone chunks switch on. Find a fence in a frame,
   then its source.
3. Streaming: which of the 423 sections does a race load, and by what (route position, 0x34154, zones)? Can the
   streamer follow the car anywhere in the city, or does it only know the track's route?
4. Connection: overlay the 16 routes (rnode) and wall cells on one top-down map of L1RA. Which streets join
   which tracks, which city streets belong to no track (no walls, no roads, no ground?).
5. Traffic and AI: roads 0x34121/links are per track. Can the traffic follow a merged road graph?

## Expected design (inference; the answers above may change it)
- A merged world: at load, read all 16 TRACKB walls (and roads) and build the union collision once (a bridge in
  host/, cached), minus the fence segments. Our own walls only where the city really ends (map edge, holes).
- Streaming driven by the car position over all L1RA sections.
- Props fences dropped by a filter in the props loader.
- Launch: Free Run on any L1RA track + RN_OPEN; no lap end (already true in Free Run).

## Phases and who (triage)
| phase | class | who | done when |
|---|---|---|---|
| A. Questions 1-3: the mechanism | diagnosis | Opus, main session | each answer with function addresses, written here |
| B. Census + top-down map (q4) | mechanical | haiku-mechanic, parallel | tools/openworld/map.py writes build/openworld/map.png + census/openworld.json |
| C. Decompile the loaders and users found in A | RE | sonnet-exec | functions named, struct layouts written here |
| D. Merged collision + no fences + streaming | design Opus, build sonnet-exec | | a native run drives from the 1001 grid into a street of 1107 |
| E. Traffic on the merged roads | RE then build | sonnet-exec | traffic spawns and drives off the original route |
| F. Chrome | check | Opus | webcheck --route PASS and the OWNER drives it in Chrome |

## Rules for this block
- RE before runs. A run confirms a prediction. Runs are bounded (RN_SECS, head -c), muted, off-screen.
- Every patch is one line in the patch table with why; the switch off gives the shipped game.
- Write what is learned here (addresses, layouts) and in commits.
