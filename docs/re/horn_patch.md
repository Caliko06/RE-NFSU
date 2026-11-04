# Horn patch draft: probe at StartHorn, and the three tests it skips on

Base: `~/Dashboards/tokentok/becarios/tomas/work/horn_traffic.md` (V = read in the binary). Nothing here was built or run:
the worktree is `RE-NFSU-wt/tomas` (branch `bec/tomas`) and the order was to draft, not to build. Everything below is a byte
reading of `pc/Speed.exe` with objdump plus the host pattern of `host/rivals.c` / `host/free.c`.

## 0. Chosen test: car+0x4d0, not 0x5693b0

- **0x5693b0 is not a visibility test.** Whole function:
  `mov ecx,[eax+0x14]; cmp [ecx+4],3; jne L; mov al,1; ret; L: mov al,[eax+0x855]; ret`
  = 1 for any kind 3 (traffic), else the headlight-flash byte `car+0x855` that `UpdateHornFlash 0x429190` writes. It answers
  "is this car flashing", not "is it drawn". The §6 note in `horn_traffic.md` guessed wrong.
- **The draw list's own first gate is `car+0x4d0`**: `DrawRaceCarList 0x571050` reads `movb 0x4d0(%edi),%al / testb / je` at
  0x570eb9 and skips the car when it is 0. It also requires the car not to be the camera's own car, `0x570b90` to pass, and the
  view bit `1 << [view+4]` to be set in `car+0x534` (0x570ee2) and `car+0x530` (0x570bc3, with blink `car+0x8a8`).
- **0x570b90 is the per-car visible test** inside that list (view mask +0x530/+0x538, blink +0x8a8, `0x4280a0`). It needs the
  draw context as its stack argument, so the horn hook would have to guess the view index; the probe logs `+0x530/+0x534`
  instead and leaves 0x570b90 out of the decision.
- **Parked is `+0x4d1` of the vehicle `[car+0x2c]`, not of the car** (as `host/aitel.c` AIT already reads it).

So the fix tests: parked (`[car+0x2c]+0x4d1`), draw flag (`car+0x4d0` == 0 means the draw list skips it), and recycle age.

## 1. Probe (default OFF)

`host/horn.c`, PATCH 0x52536a (cave 0x5256e8, `jmp [SCREEN_ADDR+0xa4]`), the only `StartHorn` call site in the image, at the end of
the honk branch of `EAXTrafficCar::Update 0x5251e0`. Register state at the hook: `edi` = the sound object (`car+0x878`),
`[esp+4]` = sample index, callee `ret 4` (0x525075). The host function makes the original call with
`call_guest(c, 0x524f30, 1, &idx)`, which keeps `edi`, so the callee sees the same `this`.

`RN_HORNLOG=1` logs one line per honk:

```
HORNL f<frame> car <car> idx <index in [0x7361f8]> snd <sample 0..50> parked <0|1> draw <0|1> view <0x530>,<0x534> d <m> rec <s> skip <0|1>
```

`d` is the distance the range test uses (`car+0x60/0x64` vs the player's, same fields as `0x524bb0`), `rec` is seconds since
`horn_tick` saw the car teleport >50 m in one Present or leave the parked state, `skip` is what `RN_HORNFIX` would do. A ghost horn
names itself in one line: `draw 0` or `parked 1` or `rec < 3` with `d < 30`.

`horn_tick` (also in `host/horn.c`, called from `host/d3d9.c` next to `free_tick`) only does work when one of the two flags is set.
It reads the same 4 kHz ticker as `host/rivals.c` (`0x73ad34`, `CLK_S 4000`).

## 2. Patch draft (default OFF)

`RN_HORNFIX=1` skips `StartHorn` when the owner car is parked, when `car+0x4d0` is 0, or when `rec < 3 s`. The caller still sets
`+0x31d` and `+0x308` (the branch after the call is untouched) but `+0x300` stays 0, so `Update` never enters the "already honking"
tail and the voice is never created. Side effect: `0x73565c` (the 5 s global cooldown, written inside `0x524f30`) is not updated
by a skipped honk, so a nearby legitimate car can honk sooner. With both flags unset the hook is a plain call to `0x524f30`.

Not in this draft: occlusion. `0x5251e0` has no raycast, and adding one per honk candidate is a different decision.

## 3. NV items closed (from `horn_traffic.md` §2 and §7)

- **Writer of `EAXTrafficCar+0x31e`**: `0x5249d6`, inside the ctor `0x524970` (built by `0x51d8c0` for kind 3),
  `movb $1,0x31e(%esi)`. Single writer in the image, single reader (0x5252a0). It is set once and never cleared, so it gates
  nothing per frame: every traffic sound object may honk while it lives.
- **Writers of `+0x314` / `+0x320`** (the two 3 s timers): ctor zeroes both (`0x5249f5`, `0x5249dd`); `+0x314` is written again at
  `0x5250da` inside the drive-by helper `0x525080`; `+0x320` is written at `0x52530c`, in `Update`'s global-cooldown path, to the
  car's own clock. No other writers.
- The "visible test" of §6 was `0x5693b0`; it is the flash predicate (§0 above).

## 4. Files and wiring

| file | change |
|---|---|
| `host/horn.c` | new: `horn_start` (hook) + `horn_tick` (recycle stamps), `RN_HORNLOG` / `RN_HORNFIX`, both off |
| `tools/recomp/patches.py` | PATCH 0x52536a + cave 0x5256e8 (6 of the 8 CC bytes there, no reference to them) |
| `host/win32.c` | `SCREEN_ADDR+0xa4` = `horn_start` |
| `host/d3d9.c` | `horn_tick(c)` at each Present |
| `host/host.h`, `host/dispatch.c`, `tools/recomp/build.py` | declaration, `horn_apis` table, source list |

`cc -fsyntax-only -Ihost host/horn.c` passes. Nothing else was compiled or run.

## 5. SIGUIENTE

Build once and run a track with `RN_HORNLOG=1` for a minute, then read how many `HORNL` lines have `draw 0` or `rec < 3`. If that
share is small, the ghost horns are the missing occlusion test (§2) and this fix will not move the OWNER's complaint; if it is
large, turn `RN_HORNFIX=1` on and compare the same minute.
