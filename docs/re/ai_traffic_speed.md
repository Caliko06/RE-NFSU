# Traffic speed: who writes the "6.1 m/s" crawl, and is it data (2026-11-04, becario tomas)

V = read in code/data or measured in the logs (address or number given), I = inference, U = open. Code =
`census/hopper/decomp.c`, files = `game/Tracks/TRACKB*.lzc` via `tools/re/chunks.py` (script `becarios/tomas/work/lanes2.py`),
logs = `runs/w_ai_s1..s3/log.txt`.
## Answer first

1. **There is no 6.1 constant.** The lane-drive target (type 8) is the road network's lane speed byte,
   `node + 0x6a + lane id` (11..13 forward, 17..19 against), u8 in **m/s**. `0x5a7690` reads it, `0x5a6b00` /
   `0x5a6bc0` sample it along the route, `0x583910` min()s it with the curve limit and the action target, and
   `0x583850` hands it to SetDesiredSpeed `0x45e180`, which stores `vehicle + 0x200`. V
2. **6.1 = that byte at 6.** The byte is integer: 13.0 % of TRACKB1001's traffic lane-values are 6, 53.5 % are 20. The
   image holds `6.1f` twice, `0x6b5d8c` (render table, used at 0x56f129) and `0x6f0800` (menu, 0x70444c), neither
   reachable from the AI. V
3. **The AIHIT 6.1 drops are recycles, not cruise:** 437 of 911 kind-3 drops in the 3 seeds land on 6.1, 100 % act 8,
   100 % "wall", 151..564 m from the player, i.e. a car moved to a 6 m/s lane (`TRAFLOG refill` 1325..1991 moves per
   ~1130 s). 12..15 % of moves land on 6.1 against the 13.0 % share of byte 6 in the data. V / I (the match)
4. **Yes, the original career crawls too, on the same data:** one function serves every mode and reads no skill,
   difficulty or rubber-band term (unlike rivals `0x44c550`). The only per-car scale is the host pace cave
   (`0x583a37/0x583a5b`, x0.85..1.15) and it is **on** in these runs. V
5. **A data patch fixes the slow stretches, not the crawl you see:** 39.4 % of kind-3 samples are < 0.5 m/s (act 3
   stands), so raising the 6 m/s lanes moves the top of the distribution, not the median. I from the numbers.
## The chain (V, decomp line numbers)

`0x583350` TrafficAI::Update (one car per step) -> `0x583850` runs the action `vt+8`, then `0x583910`
CalcSpeedTarget, then RealDriver `vt+0x38` = SetDesiredSpeed(speed, 0, .., act+0x1f1).

`0x583910` (decomp 811791) reads car `esi[1]` (+0x3d4), route `esi[0xf9]`, action `esi[0xfe]`, parked `+0x4d1`; asks
`0x5a6bc0` (curve slowdown: walks route points, section `+0x5c`, node `+0x2f`, distance `+0x58`, each point's
`vt+0x18(node)`) and `0x5a6b00` (road limit: same walk, **linear interpolation** between two points); the point reader
`0x5a7690` does `movsx byte [node+0x6a+lane], <<16, * 1/65536` (0x37800000) -> float. Tail (decomp 811860..811900):
speed = min(route speeds, act+0x1e4 if act+0x1f0 == 0, arg_18, arg_10), **0 if parked**. `0x45e180`: `mov [ecx+0x200], eax`.
No skill, no rubber band: the body never touches record `+0x14` or `ctx+0x4b8`, the two speed scales of rivals
(docs/re/ai_speed.md). Traffic pace is the lane byte alone. V (absence in the only writer) I (no other walk).
## The exact data address

```
section = [0x77af30 + 4*id]           id 0..127, chunk 0x34121, loader 0x442dd0
node    = section + 0x27c + i*0x88
speed   = byte [node + 0x6a + k]      k = 11,12,13 forward / 17,18,19 against
                                      (lane present iff s16 [node + 0x3c + 2k] != -1)
```

Raising every traffic byte below 20 on 1001 touches 323 bytes of 2484 lane-values (V F). It is per-node track
data, not a tuning table: chunk 0x34121 lives inside `TRACKB*.lzc` (JDLZ), so a file patch must recompress; the
runtime pass below needs no file. Shares of the byte in shipped career tracks (V F):

| track | 6 m/s | 20 m/s | 15-16 | other | lane-values |
|---|---|---|---|---|---|
| 1001 | 13.0 % | 53.5 % | 5.7 % | 27.8 % | 2484 |
| 1003 | 8.7 % | 33.2 % | 19.8 % | 38.3 % | 2645 |
| 1006 | 13.4 % | 34.8 % | 10.8 % | 41.0 % | 2696 |
| 1210 | 13.9 % | 62.3 % | 2.3 % | 21.5 % | 2391 |
| 1202 | 0 % | 99.0 % | 0 % | 1.0 % | 3485 |

Not the cause: spawn-record start speed `+0xb0` is 15..30 mph = 6.7..13.4 m/s, no 13.6 mph (V F); track row `+0x6a` (traffic.md §Track row) has no reader here, `0x42adf0` is only the `int<<16 x 1/65536` converter (V decomp 65640).
## Numbers (logs)

- `AIT` kind 3, 3 seeds: 39.4 % < 0.5 m/s; median moving 7.2 m/s, p90 16.7 (subset n = 5624; full figures in
  docs/re/ai_traffic.md: median 5.8, p90 16.1 over 13011).
- `AIHIT` kind 3: 911 drops, 437 at 6.1 (s1 120/287, s2 121/270, s3 196/354), all act 8 + "wall", 151..564 m.
  Teleport chain: `0x5999c0`/`0x599c80` -> `0x42adf0` byte -> `0x59a7c0(<speed>)` -> `0x427f70` velocity =
  speed x node heading. V code + log.
- `TRAFLOG` last lines: refill 1325 (s1), 1346 (s2), 1991 (s3) for 21 cars; near100 8..15; fail 54..162. ~12..18 s
  per car between moves and each move can drop it to 6 m/s. V. Act-8 at 5.5..6.7 m/s is spread (6.1: 24, 6.5: 18,
  6.4: 17): after a move the pace cave (x0.85..1.15) decides, no single 6.1 target. V
## Proposed patch (data, opt-in, NOT RUN)

Host pass at race start, `RN_TRAFLANE=<m/s>` (host/rivals.c, with the other traffic knobs): for each section in
`[0x77af30]`, each node `sec+0x27c+i*0x88`, each k in 11..13 and 17..19, if `s16[b+0x3c+2k] != -1` and
`mem[b+0x6a+k]` is nonzero and `< N`, set it to N and count. ~15 lines of C, no new state.
Why not code bytes: the byte is data, nothing in the image to patch, and lanes 0..9 (racers) are other bytes, so
rivals keep their speeds. Log `TRAFLANE n bytes <x -> N`; read back `AIT sp` + `TRAFLOG refill`. Expected: the
6 m/s stretches gone (13 % of 1001's lanes), median barely moved while 39 % of samples are stopped. U until run.
## Limits (U)

- Why the after-speed prints 6.1 and never 6.0: the log is %.1f, sampled 1 s later, the write is 6.0; candidates
  are the 1 s PID settle (V it accelerates: `AIT` 0 -> 5.2 in 1 s) or a 0.1 residual in the teleport velocity.
- Unmeasured: whether a car stays on a 6 m/s stretch; the WORLD merge with the Rockport block can shift the share
  of 6 m/s lanes (the histogram is base 1001), not the mechanism.
