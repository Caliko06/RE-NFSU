# Jump cam in WORLD: why the player's route is not at the car (RE only, 2026-10-31)

V = read in code/data this session, I = inference, NV = not verified. Nothing was run. Tools: Ghidra export, capstone (asm.py dis),
OWNER log build/web.log (JCPICK / JC lines), TRACKB1010.lzc (build/openworld_city) parsed with ref/tools/ug1-tracks/lib.py.

## Cause (V code + V data, one mechanism)
The player's route starts at the driver's seed node drv+0x2c. The seed is chosen by progress, not by place:
- Player driver class vt 0x6b8968 (traffic class is vt 0x6b89c0; both share slot +0x2c = 0x59bd90). 0x59c210 (slot 3, every frame) -> 0x59c460 ->
  vt[+0x2c] 0x59bd90 (seed) -> 0x5a5730 (anchor the route on the seed, grow it with 0x5a58d0 until 10+ nodes and speed*[0x6b5a14] m, max 40).
- 0x59bd90: keep the seed only if 0x442690(sec, 24 m, flags 0x24, car+0x814) still finds a node and the car is < 5 m outside the road. Else 0x4561d0 twice:
  1st flags 0x8e4 (radius 48), 2nd flags 0x24 and NO radius (0x4561d0: radius 999999 unless flag 0x800). Flag 0x20 = rank by 0x4423b0 =
  max(|node+0x38 - car+0x814| - 24, xy distance). car+0x814 is the TrackPath cursor distance (cursor = car+0x800, filled by 0x443a10; +0x14 distance,
  +0x18/+0x1c tangent). In WORLD the TrackPath is the old 42 km tour polyline (854 pts) and node+0x38 is the new net's number, so the two do not agree.
  Every local node has a huge rank, call 1 fails, call 2 returns the node with the best progress match ANYWHERE.
- Check with the log (V): car 1502,664 (t=102): best rank = sec 16 node 0 at 386 m, node 1 at 399 m. JCPICK said "eye 1 ... dist 399 m". Car 2166,-566:
  best rank = sec 45 nodes 16..18 at 311..320 m (polyline pass D=495); Original eye was sec 45 node 25 (prog 237) at 330 m. Same for 200/259/363 m.
- The "f = n" refusals (k 0 f 11 n 11, speed 55) are the same seed: the route lies in sec 45 (west/south of the car, car heads east/north), every node
  has dot < 0 along car+0x70. It is not a lag of the cursor. 4ac = 0 in every JCPICK because 0x426930 requires it (no information).
- The cursor "every 60 frames at 0x426b63" is the TrackPath cursor car+0x800 (0x443a10), NOT the route. The route is rebuilt/extended every frame.
Second, separate defect (V data, I effect): route direction. vt[+0x40] of the player = 0x59c7b0: dot(car+0x818/0x81c TrackPath tangent, car+0x70/0x74 velocity
(car+0x90/0x94 below 10 mph)) > 0 -> [0x78a2fc] (forward) else its inverse; type 1 walks idx-1 (0x455390). Sec 63 (the jump spur, nodes 2235,-535 -> 2147,-575, dir
-0.9,-0.4, prog rising westward) runs against the polyline (east at 2166,-566): car drives east, tangent says "forward", the route walks west = behind the car.

## Q2 what case 0xf needs
Route node (0x6c+ B object made by path vt+0x2c 0x455230): +0x58 route dist, +0x5c section byte, +0x5e idx, +0x20/+0x3c left/right edge lateral (used by
the portal test 0x457300 with node+0x58). Position/edges come only from the graph record rec = [0x77af30 + sec*4] + 0x27c + idx*0x88 (WIDEN: table at 0x796010):
0x5a7270 -> vt+0x2c -> 0x442330: rec.xy + rec.dir*(d - node+0x58 = 0) + rec.normal*lat; vt+8/+0xc: rec+0x24/+0x28 half widths + lane shorts rec+0x3c+i*2.
Same 0x88 graph records the free-mode walk uses (0x4563d0 / 0x59a2c0 work on {section, rec} pairs); only the route wrappers differ. So any route that
is local and ahead gives a valid eye; nothing else about the nodes is wrong.

## Patch proposal (host only, mirrors the rival slot +0x40 = free_dir; no patches.py change)
In free_setup (live only, so Original stays the reference), write two slots of the PLAYER vtable (traffic class 0x6b89c0 stays untouched):
1. 0x6b8968+0x2c -> new free_hseed (ECX = driver, 1 stack arg, ret 4). Call the game's 0x59bd90 (call_guest, ecx = drv, arg = the flag). Then
   node = [drv+0x2c], car = [drv+4]; if node == 0 or hypot(node.xy - (car+0x60).xy) > 64: reseed with the game's 0x4561d0 (ecx = car+0x60, eax = 0,
   cdecl args &out(8 B: sec, node), flags, car+0x814): first flags 0x8c4 (radius 48, section flag, inside road, node bit; flag 0x20 dropped = rank by xy),
   then 0x004 (no radius, still xy). On success [drv+0x2c] = out[1]. Cost: ~8000 node distances per frame, fine.
2. 0x6b8968+0x40 -> new free_hdir (ECX = driver, no args): node = [drv+0x2c]; if 0 call 0x59c7b0. Else v = car+0x70/0x74 (car+0x90/0x94 when
   car+0x3d4 * [0x6cc9f0] <= [0x6cca94], as the game), dot = v . (node+0xc, node+0x10); return dot > 0 ? [0x78a2fc] : ([0x78a2fc] == 0).
3. free_jumpcam guard (cheap, keeps a bad route from making a far eye): after 0x42c4b0, if the node k of the clone is > 64 m from the car, free the clone
   with 0x42c640 and return 0 (log "route far").
Risks: (a) the cached seed no longer survives the 0x59bd90 keep-test, so the seed is re-searched every frame (harmless, same as now). (b) a seed on the
parallel road (sec 63 vs sec 0 are 47 m apart) is possible at junctions; flag 0x40 (car inside the road) in the first call limits it. (c) reverse routes end at a
section start without a dirf=1 link: then <5 nodes, 0x42c4b0 returns 0, no jump cam (correct, not bogus). (d) the player route also feeds the HUD/minimap
route and the decider cache: they now see a local route, which is what retail gives.
NV: that vtable 0x6b8968 is writable guest memory at that point (the rival slot 0x6c89f0+0x40 precedent says yes); the reseed on the 4 s grid; sec 63 reverse links.
Not needed: filling the clone ourselves from the road graph (0x5a51f0 copies whatever route the driver has; fix the route instead).
