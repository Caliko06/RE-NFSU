# How many traffic cars WORLD can hold: every cap on the way to 48 (2026-11-03, becario lalo)

Question: WORLD is limited by the total pool of 21 traffic cars, but entrants stop at 30. Which limits does 48 traffic
cars hit, at what address, and what breaks if each is raised. Read-only on `pc/Speed.exe`; nothing was built or run.
Marks: **F** read in code/log/docs, **I** inference, **NV** not verified. Tools: `objdump -d pc/Speed.exe` (llvm) for
every instruction quoted, the pool-ctor scan (all 43 `0x566dc0` call sites, size and count read in the disassembly, name
read at the pushed string), `docs/openworld/re_racer_cap.md`, `re_coll_pool.md`, `docs/re/traffic.md`,
`host/free.c`, `host/rivals.c`.

Target: 1 player + 8 rivals + 48 traffic = **57 entrants** (cap 64). AI cars = 8 + 48 = 56 (pools 64).

## The one that bites first: the entrant table is exactly 30 and ends at RaceStatus (F)

- Table: 30 x 0x750, `0x77c790 .. 0x78a2f0`. RaceStatus starts at `0x78a2f0`: the last entrant byte is the byte before it.
- Cap: `cmp [ebp+0x12c], 0x1e` at `0x4322e0`, immediate at **`0x4322e6`** (`1e`); `jge` skips the build. F
- The ctor memsets it: `mov ecx,0x36d8` (`0x36d8` dwords = 0xdb60 = 30 x 0x750) at `0x431e9d`, `mov edi,0x77c790` at
  `0x431ea2`, and stores the pointer `0x77c790` into RaceStatus+0x128 at `0x431ec4`. F
- A startup loop initializes each entry: `mov esi,0x77cec4` (base + 0x734), `mov edi,0x1e` at `0x689d22`, call
  `0x417600(base+0x10)`, byte `[base+0x734]=0`, step 0x750. F
- **Raising the cap alone is not possible**: entrant 31 writes 18 x 0x750 = 54,912 B past `0x78a2f0`, over RaceStatus
  (track id at +0, traffic level at +0x10, direction, the racer counts and everything the race reads). Crash or silent
  corruption, not a graceful drop. F
- Every reader uses the pointer at `0x78a418` (`0x422aac`, `0x422b20`, `0x448fe0`, `0x4490a0`, `0x4a0dae`, `0x4a46f5`,
  `0x4b3b4a`, `0x4b3c6e`, `0x4b4066`, `0x4b439a`, `0x4b43d4`, `0x4b43f6`, `0x4b455a`, `0x4b463b`, `0x4b472d`,
  `0x4b6309`, `0x51e034`, `0x51e3ff`) so the array can be relocated without touching those sites. F
- Only two places hardcode the old base: the ctor (`0x431ea2`, `0x431ec4`) and the startup init loop (`0x689d22`).
  Both are safe to leave pointing at the old 30 entries **if** the new block is zeroed and the entry build `0x432360`
  initializes the fields it needs: the init loop only sets `+0x10` (via `0x417600`) and `+0x734 = 0`. **NV** whether an
  entry that skipped `0x417600` behaves (it is the only real risk of the cheap path).
- Cheap path (recommended first): host allocates 64 x 0x750 zeroed in guest memory and writes the pointer to
  `[0x78a418]` before the race build (`0x422a70`), plus the cap patch below. F for the addresses, NV for the skipped
  subobject ctor.
- Expensive path (fixed address): extend `.data` (VirtualSize and SizeOfImage in the PE header, +0x1D400), then patch
  `0x431ea3` and `0x431eca` to the new base, `0x431e9e` to 0x7500 dwords, `0x689d23` to new base + 0x734 and
  `0x689d28` to 0x40. I, more moving parts, no host memory.

## The rest, in order of risk

| # | Limit | Address | Now | For 48 traffic | What breaks if raised alone / not raised | Mark |
|---|---|---|---|---|---|---|
| 1 | Entrant table + cap | `0x4322e6` imm; array `0x77c790` | 30 | 64 + relocation | not raised: cars past 30 dropped; raised alone: RaceStatus overwritten | F |
| 2 | AIGoalSlotPool | `0x45553c` (`movl $0x1a,%edi`) | 26 | 64 | car 27+ gets no goal slot (`0x566dc0` returns 0); behaviour on exhaustion **NV** | F/I |
| 3 | AIActionSlotPool | `0x45557c` | 27 | 64 | same for actions; a car with no action does not steer/brake | F/I |
| 4 | FuturePointsSlotPool | `0x4555bc` | 27 | 64 | route/future path for cars 28+ | F/I |
| 5 | FuturePointSlotPool | `0x4555f9` (`0x280`) | 640 (=24/car) | 1536 (`0x600`) | cars run short of future points, path quality only | F/I |
| 6 | Cave traffic-count cap | `tools/recomp/caves/traffic.s`, in patches.py cave | `27 -> 26` clamp | 64 | WORLD count 32 x1.5 = 48 clamped to 26: 22 cars silently missing | F |
| 7 | CarCollisionBodySlotPool | `0x4669bf` (`movl $0x1e,%edi`, size 0x190) | 30 | 64 | car 31+ has no collision body: passes walls / no contacts, NV crash | F/I |
| 8 | TrackPolygonSlotPool | PATCH `0x4412be` (exe `0x400`, build 0x2000) | 8192 | 16384 (`0x4000`) | WORLD already used 8145/8192 with 21 cars (runs/w_L1 TRAFLOG polymax); 48 x 160 = 7,680 + player + camera reaches the int3 `0x441b82` stop | F |
| 9 | LoadedCarSlotPool | `0x58b213` (`movl $0x28,%edi`, size 0x1f4) | 40 | 64 | 41st ride may fail to load; per ride or per type is **NV** | F/NV |
| 10 | LoadedRideInfoSlotPool | `0x58b250` (size 0x1c) | 40 | 64 | ride info missing for late cars | F/NV |
| 11 | LoadedWheelSlotPool | `0x58b1d3` (size 0x68) | 40 | 64 | wheel info missing | F/NV |
| 12 | Physics pools | `0x4764f0` (`lea edi,[esi+0x20]`), rest `n = count` | scales with `[0x78a41c]` | automatic | nothing to change; **NV** that they are built after every entrant exists | F/NV |
| 13 | `hitcar[32]` in the host | `host/rivals.c:584`, `s < 31` | 31 tracked hits | 56 need more | it stops counting new hit cars, no overflow | F |
| 14 | Host loops `k < 200` | `host/rivals.c:697`, `713` etc. | 200 | fine | none | F |

Not found, checked: no per-car sound or voice pool exists among the 43 `0x566dc0` pools (names read; the closest are
`SkidSetSlotPool` and the emitter pools, all sized by polygons or 100+). Car audio hangs off `car+0x30`, so 48 cars add
voices but no fixed pool. **F for "no pool named sound/voice", NV for the mixer's own limit.**
One open object: `0x4632be` `movb $0x1e, 0x5(%esi)` plus `rep stosl` 30 dwords on an object with vtable `0x6b9694`
(the traffic-driver vtable family), i.e. a 30-entry neighbour/contact array. **NV** what it is; if it is the AI
neighbour list, 48 cars need it at 56 too.

## Host constants for 48 (not applied)

| File:line | Now | For 48 | Note |
|---|---|---|---|
| `host/free.c:168` | WORLD base 14 (x1.5 = 21) | 32 | 32 x1.5 = 48; needs the cave cap raised (row 6) |
| `host/rivals.c:663` `REFILL_POOL` | 18 (tried 21) | 48 | the gate measured as binding in `docs/re/traffic_density.md` |
| `host/rivals.c:662` `REFILL_NEAR` | 14 | 48 | non-WORLD only today |
| `host/rivals.c:584` `hitcar[32]` | 32 | 64 | counter for the hit telemetry |
| `host/rivals.c` traffic_refill band | 150..650 m, 18 m spacing | keep | 48 cars already fill the ring; the band change is `docs/re/traffic_density.md` P1 |

## Order to try

1. Entrant relocation (host pointer + zeroed 64 x 0x750) with cap 64, at 48 traffic. One run.
2. AI pools 64/64/64/1536 and CarCollisionBody 64. One run.
3. Cave cap 64 + `FREE_TRAFFIC 32`. Watch `REFILLWHY`, `TRAFLOG polymax` and the COLLOG wall/orphan counters.
4. TrackPolygon 0x4000 and Loaded* 64 only if the logs show the pool filling or rides failing to load.

## Patch bytes

`tools/recomp/cand/lalo.py`, `when=lambda: False`, `old` verified against `pc/Speed.exe` by running the file (read-only).
Cave cap and TrackPolygon live in `patches.py` (already owns those bytes), so they are named here and not duplicated as
candidates.

## Main's test, 2026-11-04 (ghost c_a / c_b, RN_FREETRAFFIC=24, F)
Everything in "Patch bytes" was applied except the AI slot pools (patches.py already has them at 48/49/49/1280 since 2026-11-01) and
the entrant table moved to 0x7c0000 (0x7a0000 is SECT_ADDR's table, 0x796000..0x798000 ROAD/CODE_AREA). The build applied them; the
game stopped at frame ~2120 right after the 45 entrants were built:
`STOP 0042119a: memory fault`, in sub_421170 (a checksum over the race list object [0x7361f8]): it walks `count = [L+0x18]` pointers at
`L+0x28` but that array holds **32** entries (`L+0x28 .. L+0xa8`), then writes 0x10-byte records from `L+0xa8` (-> `L+0x2a8` for 32).
`L` is `esi` at 0x41f7d4 inside a bigger object (`esi+0x15d0` is another member), so the list cannot grow in place.
=> The hard limit is **32 cars in the race list**: 1 player + 8 rivals + at most 23 traffic (now 21). Lifting the entrant table,
AI pools and collision pools past 30 buys 2 cars at most. The ring/pool gate was already tried (d_a/d_b: near100 10 -> 11).
