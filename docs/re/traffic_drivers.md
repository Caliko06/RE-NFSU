# Traffic drivers: target speed, lane changes, gaps, hook points (RE 2026-11-04, becario memo)

F = read in code (`census/hopper/decomp.c` line, plus `objdump -d pc/Speed.exe`, base 0x400000). I = inference. NV = not verified.
Track 1010. Nothing was run: no patch was assembled, applied or measured. Existing docs (`traffic_react.md`, `traffic.md`,
`ai_traffic_stop.md`) were used as leads and are corrected where this read disagrees.

## Answers first

1. **Target speed is computed once per traffic think in `0x583910`** (called only from `0x583850`, and `0x583850` is called only
   from the traffic driver `0x583350` / `0x583700`). The value comes out in `*edi`; `0x583850` pushes it and calls the driver
   vtable `+0x38` at `0x5838e8`, which is `RealDriver::SetDesiredSpeed 0x45e180`, a single store `[driver+0x200]` (F).
   The start speed is separate: spawn record `+0xb0` mph (F in `traffic.md`, offset not re-read here).
2. **Lane-change code exists, in one place only: the Avoid action `0x453c60`.** The trigger is the lane finder `0x453920`
   reporting a car ahead in the same lane; there is no timer, no "driver wants to overtake" and no player-behind scan (F).
   It writes `ctx+0x394` = target lane and `ctx+0x398` = 1 at `0x453e30` / `0x453c82` (F, bytes below).
3. **Gap checks**: finder `0x44f470` (lane/lateral/range, no distance limit), `act+0x204` lane-change clearance, `act+0x208`
   brake range (floor 30 m), 15 m full stop, 40 m/s closing gate, 50 m honk, spawn spacing `0x59b1e0` (all F).
4. **Hooks**: per-car speed factor → 5-byte call at `0x5838af` into a cave (traffic-only path). Triggered lane change →
   no byte-only hook; the trigger *is* the finder result. Min gap to the player → scale the target speed by the slot distance
   in the same cave; the game's own gates are global constants.

## 1. `0x583910`: how the cruise number is built (F, asm)

`esi` = traffic AI, `esi+4` = car, `esi+0x3e0` = neighbour ctx (`ctx+0x388` = own index, row = 0x38 B), `esi+0x3f8` = current action.

| step | address | what |
|---|---|---|
| lookahead | 0x58393d..0x583964 | `min(car+0x3d4 * 1.3, 20.0)` (`0x6b5ba0`, `0x6b5ba4`) |
| route scalar | 0x583995 | `0x5a6bc0(roadpos, lookahead, 99999.0, &node)` walks the path calling node vt `+0x18` = `0x5a7690` |
| route blend | 0x5839a7..0x5839d7 | if scalar >= -0.1 (`0x6b5ba8`): `10 + (scalar-10) * t`, t from table `0x7044a0` via `0x454f30` |
| lane scalar | 0x583a37, 0x583a5b | `0x5a6b00(roadpos, lane)` twice; lane = own slot `+0x18` (`ctx + own*0x38 + 0x18`) |
| cruise | 0x583a65..0x583a8b | `min(route, lane)` then `min(that, max(car speed * 1.3, 8.0))` (`0x6b5b98`, `0x6b5b9c`) |
| parked | 0x583a8f..0x583a9b | if `AI+0x4d1 != 0`: speed = `0.0` (`0x6cc7a4`) |
| action override | 0x583aa1..0x583aec | if `act+0x1f0 != 0`: keep cruise, gain 0, steer 0. Else `speed = act+0x1e4`, `steer = act+0x1e8`, `gain = act+0x1ec` |
| final clamp | 0x583aef..0x583b12 | target = `min(action target, cruise)`; both exits store `[edi]` (0x583b05 or 0x583b0d) |

**Where the lane speed comes from (F)**: node byte `[node + lane + 0x6a]` read at `0x5a76d2` inside `0x5a7690`
(`movzx eax, byte ptr [eax + esi + 0x6a]`), then `<<16` and `* 1/65536` (`0x6cc83c`) = the raw byte as a float. `lane` is the
index the node vtable `+0x10` returns for the interpolation point. So the traffic cruise is a min over a per-node, per-lane byte.
U: the unit of that byte (byte 8..20 would fit the observed 5..16 m/s medians, not proven).

Consequences: cruise is capped at `1.3 x current speed` (floor 8 m/s), so a car cannot jump in speed; and the action can only
lower the number, never raise it. That is why a stopped car with `act+0x1f0 = 0` and `act+0x1e4 = 0` stays stopped (`ai_traffic_stop.md`).

## 2. Lane change: `0x453c60` (F)

- Selector `0x44e020` builds Avoid `0x453860` (vtable `0x6c939c`, update `0x453c60`) **only** when `0x453920` returns a car in
  the same lane; otherwise `vt[6]` = lane drive `0x44e2b0`. No other writer of `ctx+0x394` exists outside this action (F, scan).
- Lane scan at `0x453c60`: `esi[0xe5]` = current lane; order from `+1,-1,+2,-2` (or mirrored, `var_2A`), each candidate tested by
  `0x453ba0` = `0x5a7700(candidate lane)` empty **or** the found car is farther than `act+0x204` (F).
- On success: `esi[0xe5] = lane` (`0x453e30`), `ctx+0x398 = 1` (`0x453c82`, swerve flag), plus `act+0x1e8 = 0`, `act+0x1ec = 2.0`.
- Brake branch: `act+0x208` = `min(measured gap, 30.0)` (`0x453ee2..0x453ebb`); gap 15..30 m → 6 m/s, <= 15 m → 0 m/s
  (`0x6b76e4` = 15, `0x6b76e0` = 30). `act+0x204` is reset to a constant at `0x453ec5`.
- Closing gate: `0x6b76e8` = 40 m/s of relative speed drops the obstacle (fast close-in gets a brake, not a lane change).

## 3. Gap checks that exist (F)

| check | address / field | value |
|---|---|---|
| finder walk, ahead only | `0x44f470`, slots `own-1` down to 0 | range arg 99999 in `0x453920`; accepts first lane match `|lane diff| <= 0.5` (`0x6b7604`) + half widths |
| slot distance | `ctx + idx*0x38 + 0x14` (signed, own row `+0x14`) | signed gap; `-1.0` key (`0x6cc8a8`) when behind |
| lane-change clearance | `act+0x204` | written at `0x453ec5`, compared in `0x453ba0` |
| brake range | `act+0x208` | `0x453ebb` store of 30.0, then `min` with measured gap |
| full stop / slow | `0x6b76e4` / `0x6b76e0` | 15 m / 30 m |
| honk | `0x44c2e0` | 50 m, only after the finder fires |
| neighbour list reach | `0x57a910` | `R = max(50, car+0x50 * speed)` (`0x700680`), route delta <= 3R |
| spawn spacing | `0x59b1e0`, track row `+0xd4` | metres between cars at placement |

No check reads a car **behind** the traffic car, so the player closing from behind is invisible (confirms `traffic_react.md`).

## 4. Hook points

**A. Per-car speed factor (clear path).** `0x5838af` is a 5-byte call `E8 5C 00 00 00` to `0x583910`, on the traffic-only path,
with the three arguments already pushed; `edi` (pushed last) is `&speed`. Redirect it to executable zero padding at the end of
`.text` (`.text` = 0x401000..0x696ea7; 0x696ea7..0x697000 is 0x159 zero bytes, section flags 0x60000020 = code, not writable).

```
0x5838af: E8 F3 35 11 00        call 0x696ea7          ; was E8 5C 00 00 00
0x696ea7: E8 64 EA EE FF        call 0x583910          ; original, args still on stack
0x696eac: 8B 4C 24 08           mov  ecx,[esp+8]       ; &speed (ret + pushed first arg)
0x696eb0: 8B 86 E0 03 00 00     mov  eax,[esi+0x3e0]
0x696eb6: 0F BE 80 88 03 00 00  movsx eax,byte [eax+0x388]
0x696ebd: D9 04 85 E0 6E 69 00  fld  dword [eax*4+0x696ee0]   ; factor[car index]
0x696ec4: D9 01                 fld  dword [ecx]
0x696ec6: DE C9                 fmulp st(1),st
0x696ec8: D9 19                 fstp dword [ecx]
0x696eca: C3                    ret
```

Table: 32 floats at `0x696ee0`, e.g. index i → `0.85 + 0.02*(i%16)` (all <= 1.15). Cave 36 B + table 128 B = 164 B of the 345
available (`0x696ea7..0x697000`, zero, executable, read-only for the loader; the table is only read). `esi` survives the cave; `eax`
is reloaded at 0x5838b4. Effects: every traffic car keeps the game's own cruise, clamps and
brakes, scaled per car. NV: not assembled; the `[esp+8]` slot and the factor table address need one test run with a log.

**B. Per-lane speed (no cave).** The lane byte `node+0x6a+lane` is plain track data: editing it changes the lane's speed for all
cars in that lane, for free, and is the natural way to make one lane "slow" and another "fast". Cost: per track file, not per car.

**C. Triggered lane change.** No byte can create a lane change without a leader: the trigger is the finder result feeding
`0x44e020`. Two usable levers: (1) lower `0x6b76e8` (40 m/s) so a fast-closing car changes lane instead of braking — global;
(2) host rule: write `ctx+0x394` = free lane and `ctx+0x398` = 1 for a kind-3 car (the same two stores as `0x453c60`), as
`host/rivals.c` `traffic_tick` already does; it only takes effect while act 3 (I, NV).

**D. Minimum gap to the player.** Nothing bounds it: the car targets route speed when the lane is clear, and the only player-facing
gates are the global 30/15 m constants. Cheapest bound in the same cave (A): read the nearest slot distance
`[ctx + (own-1)*0x38 + 0x14]` and clamp `target = min(target, max(0, (gap - 8.0) * 0.5))`. Constants to expose: 8 m standoff,
0.5 1/s gain. Global alternative: `0x6b76e4` 15 -> 22 and `0x6b76e0` 30 -> 40 widens every brake, no per-car control.

## Open (U)

- Unit and range of `node+0x6a+lane`; whether `0x5a6bc0` returns min or last value along the lookahead.
- `act+0x1f0` has other writers than `0x453c60` and `0x44e2b0` (lane drive); not enumerated.
- Whether writing `ctx+0x394` from outside act 3 has any effect (no reader found outside the Avoid action).
- Nothing measured: no run, no A/B of factor or gap clamps.
