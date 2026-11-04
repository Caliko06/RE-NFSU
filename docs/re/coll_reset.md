# Fall-through / pass-wall after a reset: cache, pool or ids? (read from code only)

Markers: V = read in code, I = inferred, U = unknown. No game run. Sources: build/hopper/collreset.txt,
build/hopper/collpool.txt, census/hopper/decomp.c, objdump of pc/Speed.exe, build/gen/f014.c, host/free.c, host/rivals.c.

## 1. Is there a reset/teleport path that clears or refills the car cache, or moves the car without it? (V)
- Reset core 0x427c50 (from 0x427f70 and 0x427e60, and from host `free.c` free_tmove, which calls 0x427f70):
  writes car+0x60/+0x64/+0x68 = position (0x427cb1..0x427cb7), car+0x70/+0x74/+0x78 = velocity part
  (0x427d0a..0x427d13), then `lea eax,[edi+0x540]; call 0x440740` at 0x427cc0/0x427cc6. So the reset DOES clear the
  car cache (car+0x540): 0x440740 writes +inf/+inf/-inf/-inf over the cached box and decrements every body count to 0.
- Consequence: the next 0x4267a0 definitely refills. 0x4407b0 compares the new query box to the cached one
  (0x4407e8..0x440821) and jumps to the rebuild at 0x440827, because no finite box is inside an empty infinite one.
  So a stale cache cannot be the cause.
- The reset writes no +0x6c/+0x7c; 0x4407b0 never reads them (2D box from box+0,4,8 + radius + dir +0x70; radius =
  |vel|*0.05 + 3.0 at 0x426849..0x426855). Only other caches with their own clear are 0x592280/0x5966d0 (WorldObject,
  +0x144/+0x174), not the player. No path found that moves the car and leaves +0x540 stale: U outside 0x427xxx.

## 2. Full pool and AcquireBody failure: what does 0x4267a0 do with the missing surface? (V)
- 0x441b90: `used [+0x18] == cap [+0x2c]` (0x441baa) calls 0x441b20 first (0x441bb0). 0x441b20 frees count-0 bodies
  (count byte at body+8), clears their row slot with 0x4400d0 (`row+6 = 0xffff` at 0x4400d7), max 0x64 per call, and
  if it freed nothing -> `int3` 0x441b82.
- The recomp lifts that int3 to `TRAP(0x441b82,"not lifted: int3")` (build/gen/f014.c:7532) -> c->halt = game stops.
  That is the 85 s stop of docs/openworld/re_coll_pool.md, not a fall.
- There is no skip-frame, no use-last and no drop branch: 0x441c10 stores the returned pointer unchecked (0x441d5c),
  0x4407b0 buckets it reading [ptr+0xa], and 0x4267a0 only tests the surface to store +0x8a4/+0x228 (0x42688d).
  The only "use last" is 0x440a40's cache+0xac shortcut, and the reset zeroes +0xac. `eax = 0` (no free slot) can
  only follow "used == cap and nothing freed", i.e. the int3 first.

## 3. Pool, id table, or neither? (I)
- Pool A (0x736184) cannot produce a silent fall-through: it halts. The id table (0x466b01, ids 0xde -> 0x840)
  only feeds the wall witness ([[0x736070]+8] read at 0x469929) that keeps/drops DynamicCollisionBody walls; it never
  reaches the ground query of 0x440a40. So: neither.
- The one silent "no collision" path is pool B [0x72cbf4] (0x270 B slots, cap patched 0xa0 -> 0x800 at 0x4669fe):
  0x469810 tests `used == cap` (0x469915/0x469918) and returns with nothing built (`je 0x4699de`), no int3, and it
  destroys nothing (only 0x46a580 and 0x46a6e0 free a slot). That car then has no wall and no ground bodies -> both
  symptoms. I: pool B exhaustion, or a wrong placement z from 0x427f70/0x427c50, explains the report; U which.

## Patch
no patch. Probe: one WORLD free run with `RN_AILOG=1` (COLLOG host/rivals.c:541, WALLCAP host/d3d9.c:1191), press
reset, F10. Decide on that line: `cache 0 / ground 0` while `polys < polycap` -> refill or placement, not the pool
(compare pos z to the road); `walls` at the WALLCAP cap next to the fall -> pool B, whose fix is a release in 0x469810.