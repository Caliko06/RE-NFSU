# Voxels in Free Run (Remaster only, front F-Voxel, OWNER 2026-11-09 "own voxels")
Original design for a night street-racing city. Not a copy of any other block game: own blocks, rules, art, creatures.

- Where: simulation in host C (`host/voxel.c`, game thread, next to the guest): pedestrian physics and the ground query 0x440a40
  run on that thread, so collision and generation call them with no cross-thread copy. Meshing, drawing and UI in JS (`web/voxel/`).
- On/off: `RN_VOXEL` (default on; `RN_VOXEL: '0'` in `RN_ORIGINAL_ENV`, web/mode.js). Active only in Free Run (`[0x777cc8] == 3`).
- World frame: cell (i,j,k) = game world box [i,i+1) x [j,j+1) x [k,k+1) in game units (x, y, z; z up, right-handed,
  docs/re/physics.md:31). 1 cell = 1 unit = 1 m until F-Speed measures otherwise (one constant, `VOX_SCALE`).
- Storage: chunks of 16x16x16 cells in a fixed pool of 1024 slots in the wasm heap (8 MB). Per cell 1 byte block id and
  1 byte light (high nibble sky, low nibble block). Slot table: chunk coords, state, version. Flat arrays, no palette: the
  pool is small and the page reads the same bytes with no copy (`host/voxel.h` is the shared layout).
- Meshing: JS, culled faces per chunk (only faces next to a see-through cell), flat light per face from the cell in front
  (technique: M. Lysenko, "Meshing in a Minecraft game", 0fps.net 2012). A chunk remeshes when its version changes (4 per frame).
- Drawing: the host sends `GPU_VOXEL` (View, Projection, target cell, time) just before `GPU_FXAA`, the scene-to-HUD point.
  web/gpu.js hands it the scene colour and depth targets; web/voxel/render.js draws there with load/store and the depth test,
  so the city hides voxels and voxels hide the city, then FXAA/bloom/blur run over both. The HUD stays on top.
- Light: two 0..15 channels, flood fill with a queue for add and a queue for remove, so a break leaves no light behind
  (technique: B. Arnold, "Fast Flood Fill Lighting in a Blocky Voxel Game", Seed of Andromeda blog 2015).
  Sky = night ambient from above, blocked only by voxels. Shader: albedo x (night blue ambient x sky + sodium orange x block),
  emitters glow at full. Voxel light does not relight the street (the game's lighting is in its shaders): stated, not faked.
- Tick, once per rendered Free Run frame at the scene-to-HUD point, game thread: 1 page input (slot, break, place) ->
  2 camera ray, DDA (Amanatides and Woo 1987) -> 3 break/place -> 4 load/generate near chunks, drop far ones (budget) ->
  5 fixed 20 Hz steps: scheduled ticks (fall, flow), 3 random ticks per chunk, creatures -> 6 light queues -> 7 GPU_VOXEL.
- Collision: `vox_sweep(box, delta)` moves an axis-aligned box per axis against solid cells (standard AABB sweep). The
  pedestrian's step calls it after the game's ground query: voxels answer "solid box at this cell", the street stays the game's.
  Cars do not collide with voxels: car physics is guest code with its own world collision; no hook is made, so cars pass through.
- Blocks (id name: look, rule): 0 air; 1 asphalt: black, fine grit; 2 concrete: pale grey slab; 3 brick: soot red;
  4 tread plate: diamond steel; 5 scrap: rust mix; 6 tyre stack: black rings; 7 crate: pallet wood; 8 barrier: orange and
  white stripes; 9 sodium lamp: emits 14, warm orange; 10 neon: emits 11, magenta glow; 11 glass: see-through, passes light;
  12 grit: falls when nothing is under it; 13 oil: falls, then runs off any edge beside it (no levels), see-through, dark sheen.
  Random tick: scrap under the open sky slowly weathers into grit.
- Creatures (box models, drawn in the voxel pass): gutter rat: walks on solid cells, wanders, runs from the player within 4 m
  and from light above 9; lamp moth: flies, circles the brightest emitter within 12 cells, rests on it when none moves.
- Inventory and controls: counts per block type; hotbar of 9 slots. Left mouse breaks (+1 to its count), right mouse
  places (-1), keys 1-9 or the wheel pick a slot, I opens the block grid to assign slots. Start kit: 30 of each building block.
  UI in web/voxel/ with the Remaster HUD's visual language.
- Generation (slice 4): base height = the game's ground (0x440a40) where it has ground, own noise terrain where it has none.
  Never fills cells at or under the road surface or above the road within 4 m: the street stays drivable; props sit beside it.
- Saved: changed chunks (run-length bytes) and the inventory, per track, in the page's storage; generation redoes the rest.
- Until F-Speed's pedestrian is merged, the voxel "player" is the game camera: ray from the screen centre, reach 12 m.
