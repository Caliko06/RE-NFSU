# Why the car passes walls or falls after a reset: hypotheses ranked

Scope: the original code (pc/Speed.exe, hopper decomp in census/hopper/decomp.c, build/build/hopper/frame.txt,
build/build/hopper/collreset.txt) and the port (host/free.c free_tmove). No game run (the worktree was read-only,
do not build or run). Markers: V read in the disassembly/decompile, I inference, U unknown.

Note: the pedido named `docs/re/ai/reset_*.md`; that path does not exist in this worktree. The reset RE lives in
`docs/re/coll_reset.md` (cache/pool) and `build/build/hopper/resetcar.txt`/`collreset.txt`.

## The reset, as the binary does it

- Entry used by the port: `0x427f70` (host/free.c free_tmove, and the same tail as the game's own respawn). It ends in
  `0x427c50` (V: coll_reset.md §1; the body at 0x427c50 reads arg0 = pointer to a 3-float position, arg1 = speed,
  arg2 = heading word).
- `0x427c50` writes, in this order (V, objdump of 0x427c50..0x427d84):
  - `car+0x3b4 = arg2` (heading word) and `car+0x3b6 = 0` (0x427c97/0x427c9e): **orientation is set**, not kept.
  - `car+0x60/64/68 = *arg0` (0x427cb1..0x427cb7) and `car+0x3d0 = arg1` (speed).
  - `call 0x440740(car+0x540)` (0x427cc0/0x427cc6): clears the car's collision cache: box = +inf/+inf/-inf/-inf and every
    body count 0 (coll_reset.md §1, V).
  - `call 0x4278d0` (0x427ccd), `car+0x460 = 0` (0x427d15).
  - `0x5673e0` output = unit heading * arg1 -> `car+0x70/74/78` (0x427d0a..0x427d13): **velocity is set** from the
    reset's own heading and speed, and its magnitude lands at `car+0x3d4` (0x427d2e..0x427d30).
- So a reset leaves a complete state: position, heading, velocity, speed, empty cache. Nothing is "left over".

## The sim step clamp (main loop)

- `GameFlow::MainLoop 0x447600` (V, frame.txt): at 0x4477d8 the QPC delta is clamped at 0 (`if < 0`), converted with
  `2^shift * delta * [0x7301d0] * 0.001` (0x4477f0..0x4477fa) and passed to `0x585b40`.
  `[0x7301d0] = 1000 / QPCfreq` (V: set at 0x564880 in `0x564860`), so the argument is `2^shift * seconds`.
- `0x585b40` turns that integer into `dt [0x73ad38] = int(arg) * 1/3600` (V: 0x585d5d, constant 0x6cc7e4 = 1/3600f),
  i.e. dt in seconds when the scaling gives 60 counts per second.
- `0x585d70` runs the fixed-step scheduler once per frame: `n = trunc(60 * (dt + rem [0x73456c]))` (V: 0x585d71..0x585da2;
  constant 0x6cc8b0 = 60.0f), keeps the remainder, and stores `n` at `[0x6f088c]`. At least 1 step (`if n == 0: n = 1`).
- At the end of the frame body the main loop clamps the frame counter to 3: `mov eax,3; cmp eax,ecx; jle; mov ecx,3`
  (V: 0x447a2f..0x447a3c, decomp "if (arg_18 > 0x3) arg_18 = 0x3"). 3 is exactly 3 sim steps of 1/60 s = **50 ms**,
  the same cap the NFSU2 port documents (I: the clamp and the tick quantity are the same frame value in the decomp,
  the binding of the two stack slots is not fully resolved by the aliasing decompiler; the number 3 and its position
  next to the dt computation are V).
- So Speed.exe already caps a frame at 3 steps. A frame cannot integrate more than 3 * v/60 metres: at 50 m/s, 2.5 m.
  The ground query inflates its box by `|vel|*0.05 + 3.0` m (coll_reset.md, V), which covers exactly that. A 50 ms frame
  alone does not tunnel a wall, and it cannot make a car fall (falling = no ground body, not a big step).
- Turbo: `RN_TURBO=k` multiplies every guest clock by k (host/win32.c), so dt grows k times and the 3-step clamp binds
  harder (the game slows down, it does not step further). The web 60 fps path does not touch the clamp: dt still comes
  from the guest's own QPC/limiter. Neither changes the clamp value itself (V code, I effect on feel).

## Ranked hypotheses

1. **H1 - a big dt on the frame after the reset: PARTLY TRUE, not the cause of the fall.**
   V: the clamp exists and is 3 steps = 50 ms (0x447a33, 0x585d70). V: the reset itself runs outside the sim step (the
   host calls 0x427f70 from Present, free.c), so the following step uses the frame dt, which can be the 50 ms cap.
   I: with the swept ground box (+3 m and |v|*0.05) that step cannot pass a wall; it also cannot remove the ground.
   Ranks first only because it is the only one of the four the code does not refute.
2. **H2 - the cache car+0x540 is not refilled after 0x440740: FALSE.**
   V: 0x427c50 calls 0x440740 with car+0x540, which writes an empty (infinite) box and zeroes every body count;
   0x4407b0 then must take the rebuild branch (coll_reset.md §1). No code path moves the car and leaves +0x540 stale.
3. **H3 - the 8192 collision pool is full: FALSE as stated, PLAUSIBLE under another name.**
   V: the body pool is 1,024 slots (raised to 8,192 by patch 0x4412bd in this line of work); when it is full,
   0x441b90 calls 0x441b20, and when nothing has count 0 it executes `int3` 0x441b82 -> TRAP -> the game stops. It does
   not fall or pass a wall. I: the silent "no bodies" path is pool B `[0x72cbf4]` (wall polygon/witness bodies): 0x469810
   tests `used == cap` and returns with nothing built, no int3 (re_coll_pool.md, V code / I consequence). That car then
   has no wall and no ground bodies: **both** symptoms, and exactly the pair reported. Pool B's cap is patched 0xa0 -> 0x800
   at 0x4669fe; a full raised pool A only makes the halt later.
4. **H4 - velocity/orientation not cleared by 0x427c50: FALSE.**
   V: heading word +0x3b4 written from the reset's argument, +0x3b6 zeroed, velocity +0x70/74/78 written from
   unit(heading) * arg1, speed +0x3d0 written, +0x460 zeroed (0x427c97..0x427d15).

## What is left (the candidate the probe must decide)

- The placement itself: 0x427f70 computes x/y from a track node and z from the node's height. In the merged/open world
  the node comes from the shipped track while the collision stream is the merged one; if the ground at that x/y is not
  in the car's rebuilt box (or the node's z is under the road), the car has no ground and drives through walls because
  the walls of that stream chunk were never acquired either. I: same symptom pair as pool B, different mechanism; the
  probe separates them by the position right after the reset: a car under the road with a full cache is placement; a car
  at road height with `cache 0 / ground 0` next to a full pool B is pool B.

## Probe (host/aitel.c, RN_RESETLOG=1, off by default)

- `reset_call(c, target)` from `rn_call` at 0x427f70 and 0x427c50 (before the body): logs `RST` with the frame, the car,
  its index in the race list [0x7361f8], position/speed/heading before, dt [0x73ad38], and the cache counts car+0x7e0..0x7ec.
- `reset_tel(c)` from Present: first sample after a call logs `RSTA` (position after, dz since before, distance); then
  every 10 frames for 120 frames logs `RSTW` with the position, speed, the distance since the previous sample and a
  `MOVED` flag when that distance is > 3 m while speed < 1 (embedded or fallen). No game state is written.
- To force many resets in a ghost: host/free.c free_tmove (0x427f70) respawns a traffic car once a second while fewer
  than TMOVE_NEAR (10) are within 250 m, and rivals.c traffic_refill does the same in WORLD. Recipe:
  `RN_RESETLOG=1 RN_FREELOG=1 RN_AILOG=1 RN_FREETMOVE=1` plus traffic (`?traffic=15`, `?trafrefill=1`; on :5186 the page
  passes them, in a native ghost `tools/openworld/ghost.sh <tag> 240 RN_FREETMOVE=1 RN_TRAFREFILL=1` with
  `?traffic=15`). Read `RST/RSTA/RSTW` lines next to `FREE respawn` and `WALLCAP`.
