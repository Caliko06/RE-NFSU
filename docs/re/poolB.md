# Pool B (TrackPolygonCollisionBodySlotPool, [0x72cbf4]): can it fill and silently kill a car's walls? (H3)

Lane 1, H3. Read only: no game run, no build, no ghosts. Markers: **F** read in code/log, **I** inferred, **NV** not verified.
Sources: `census/hopper/decomp.c` (0x466970, 0x469580, 0x469810, 0x469a00, 0x46a440, 0x46a580, 0x46a5b0, 0x466e20,
0x566dc0), `docs/re/ai/reset_00469810.md`, `reset_0046a440.md`, `reset_0046a580.md`, `reset_0046a6e0.md`,
`docs/re/coll_reset.md` §3, `docs/openworld/re_coll_pool.md`, `host/rivals.c:616-636`, `host/d3d9.c:1180-1193`,
`tools/recomp/patches.py:562-579`, `runs/w_L1/log.txt` (119 COLLOG lines, frames 3000..38400), bytes of `pc/Speed.exe`.

## Answer

**No, not from a reset, and not in the only run that has this data.** The reset path never touches pool B: no allocation, no
free, no destroy of the car. Pool B only fills if live wall bodies stay pinned, and the measured high-water in `w_L1` is
**101 of 2048** (88 in use at the last sample), with **zero WALLCAP lines** and 0 orphans over 35,400 frames and 30 cars
(8 rivals + 21 traffic + player). The silent branch is real (**F**, `used == cap` returns having built nothing), but H3 is not
supported by the evidence: the car that falls through is not a car that ran out of pool B in that run.

## Who allocates (F, decomp + asm)

- Pool created at `0x466970` (called from `0x449870`), five times `0x566dc0(n = arg, slot = 0x270)`. Header at +0x0: free-list
  head `+0x4`, `used` u32 `+0x6` (= +0x18 B), `high` `+0x7` (+0x1c), `slot size` `+0x9` (+0x24), `n` `+0xa` (+0x28),
  `cap` `+0xb` (+0x2c); slots start at +0x30 (0x566dc0). Third allocation is `[0x72cbf4]` (0x466970 body).
- Cap immediate at `0x4669fe`: binary bytes are `bf a0 00 00 00` = `mov edi,0xa0` = **160 stock** (F, file offset 0x669fe).
  `tools/recomp/patches.py` rewrites it to 0x800 per **runtime** patch, so 2048 exists only in a patched host build, never in
  `pc/Speed.exe` (F).
- `0x469810` (caller `0x469580`, callback from the car's broadphase walk `0x420380`) is the per-car builder. It collects at most
  `0x30` = 48 candidate polygons (`if (eax < 0x30)`) from the car's polygon list (`edi[0x19]`, count `+0xa8`, stride 0x20), sorted
  so the nearest/last is built first, each passing `0x469a00` (facing/visibility dot products). Per candidate: pool-full test
  `[+0x18] == [+0x2c]` at 0x469912; else pop the free list (`+0x4` head), `used++`, `high = max(high, used)`, then
  `0x46a440` constructs the body (`0x441b90` gives the row's collision body, `TrackPolygon%d`, witness id from
  `[0x736070]+8`). 0x46a440 also needs a **pool A** slot (0x441b90) (F).
- `0x46a6e0` is the save/restore path only (caller 0x41fc00, "AllTrackPolygonCollisionBodies"): it allocates one body per saved
  row through the same free-list code. Not a per-frame path (F).
- Growth: if the free list is empty and flag bit0 of +0x14 is set it calls 0x566e60 (SlotPool::Grow); the pool was created with
  flags 0xb, and AcquireBody never grows — 0x469810's copy does call Grow (F in decomp; **I** whether bit0 survives, not read).

## Who frees (F)

- Only the reference count of a wall body releases a slot: `0x466e20` (witness destructor) unlinks the witness from its polygon
  pairs, clears the bitmap bit in `[0x72cbfc]`, decrements each polygon's `+0x1a`, and if the object kind is 3 (track polygon)
  and the count reaches 0 calls its virtual destructor (F). That destructor is `0x46a580` -> `0x46a5b0`: clears the map entry,
  decrements `dword_736014`, then pushes the slot on the free list (`*slot = [+0x4]`, `used--`) (F).
- 0x46a6e0's teardown frees the bodies it created for a save in the same way; it is not called by gameplay frames (F).
- Nothing frees by distance, time, route, reset or car speed. No bulk clear exists, and 0x46a580 has **no static caller** in the
  census: it is only reached through the polygon vtable (F listing, I that it is complete).

## Reset 0x427c50 and leaks

- Reset writes position/velocity and clears the **pool A** cache (`car+0x540`, 0x440740). It does not touch `[0x72cbf4]`, does
  not destroy the car, and does not walk the wall/witness lists (`docs/re/coll_reset.md` §1, re-read here) (F).
- Therefore a reset cannot *create* a leak: it allocates nothing and frees nothing. The car keeps its wall bodies and witnesses;
  they are released later by the normal witness path. If 0x469810 re-ran and rebuilt the same polygons without a prior release,
  the pool would climb 48 per car per frame and hit any cap in seconds; **that does not happen** in the log (F, below), so the
  rebuild is gated upstream (existing witness/body reuse through 0x469580/0x469670; **I**, exact reuse test not traced).
- Post-reset counts specifically: **NV**. `w_L1` has COLLOG samples but no reset event line, so I cannot show used-vs-peak
  across a reset. The peak is across the whole run (which includes the drive the OWNER calls "after reset passes always" only if
  the run has resets; the log does not record them).

## Measured, `runs/w_L1/log.txt` (F)

119 `COLLOG` lines, frames 3000..38400, `host/rivals.c:633`: `walls` = pool B used, `peak` = pool B high-water,
`witness` = `[0x72cc00]`, `bodies` = pool A.

| metric | max | where |
|---|---|---|
| pool B used (`walls`) | **88** | f13500 |
| pool B high-water (`peak`) | **101** | f29700 |
| witness used / peak | 124 / 140 | - |
| pool A used / cap | 8179 / 8192 | f38400 (patched, by design) |
| WALLCAP lines (near-cap probe) | **0** | whole log |
| orphans | 0 | whole log |
| cars | 30 (8 rivals + 21 traffic + player) | TRAFLOG f38400 |

101 is 63% of the **stock** cap (160) and 5% of the patched cap (2048): the run never reaches either. `host/d3d9.c:1180`
only prints WALLCAP when a pool is at its cap at 40 m/s or more; zero lines over 38,400 frames is a second, independent
"never full" (I: probe only fires at speed).

## Conclusion for H3

- The silent branch exists (F): on `used == cap` 0x469810 returns with no bodies, no int3, no marker. A car in that state has
  no walls and no ground bodies for that step, exactly the reported symptom (I).
- It cannot be reached by reset, because reset neither allocates nor frees (F). Filling would need ~160 simultaneous live wall
  bodies across all cars; the measured worst is 101 with 30 cars (F). One frame cannot overflow it either: at most 48 new
  bodies per car per step, and 30 cars x 48 = 1,440 < 2,048 (I, arithmetic on 0x469810's 0x30 cap).
- Remaining open: whether a single car ever reaches `used == cap` in a run the OWNER calls "after reset" — **NV**, no such
  trace in `w_L1`. To close it: one WORLD run with `RN_AILOG=1`, press reset twice, read `walls`/`peak` in COLLOG and the
  WALLCAP lines; if `walls` sits at 160/2048 next to the fall, H3 is live, otherwise the placement path (0x427f70/0x427c50 z)
  is the answer, as `docs/re/coll_reset.md` already says.

## Patch

**None.** No leak to patch: the reset does not allocate, and 35,400 frames of evidence stay at 5% of cap. A candidate in
`tools/recomp/cand/beto.py` would be unjustified. If a future run shows a leak, the fix is a release of the car's witnesses at
the reset (call 0x466e20 for each witness of that car's wall list, or 0x440740-equivalent for `[0x72cbf4]`), not a bigger cap:
the cap is already 2048 in the host build and still untouched.
