# What the night of 2026-10-29 found in Speed.exe (and how to check it)

Check everything below with one command (4 s quick, 3.5 min full; read-only):

    .venv/bin/python tools/verify_re.py [--quick]

It does two things. Part 1 runs the 9 readers we wrote (`tools/re/*.py check`) on the files in `game/`: each one parses a
format and re-packs it byte for byte, so a pass means the format is understood exactly. Part 2 reads the unpatched
`pc/Speed.exe` (md5 b6b9232c...) with capstone and raw bytes and asserts 35 claims from the docs (addresses, constants,
table sizes). A FAIL means a doc is wrong. The 2026-10-29 run: ALL PASS. An independent Opus auditor (no access to our
conclusions) sampled 24 other claims: 21 confirmed, 2 refuted and fixed, 1 open (`docs/re/audit/external_opus.md`).

Marks: V = read in the binary and a second tool agrees; I = inferred; U = unknown. Detail and open items are in each doc.

## Data formats we can now read and write back (byte-exact)
| Format | Result | Reader | Check output |
|---|---|---|---|
| TPK texture packs | 347 packs, 27,458 textures, 0 bad; pixel size = sum of mips; JDLZ streams hold pixel..palette | `tools/re/tpk.py` | `bad 0` |
| Chunk containers (BUN/LZC) | 235 files tile exactly; 116 ids; every top-level id has a loader (47 loaders at 0x7007e0) | `tools/re/chunks.py` | `top-level without a loader: []` |
| Career events | 116 EventDesc records of 0x14c bytes re-pack equal; fields named (rating, target times, league, host, modes 0..5) | `tools/re/events.py` | `116/116` |
| Language strings | 3,843 of 3,846 keys are bStringHash(label) | `tools/re/lang.py` | |
| Save files (.ugd) | 0x13 + caption + time + 0xf660 block + Adler-32 (0x41dd10); 9 files re-pack equal | `tools/re/save.py` | `repack equal` |
| Cars and parts | 1,435 tables and 4,537 parts byte-equal | `tools/re/carinfo.py` | `4537 re-pack byte-equal` |
| Audio streams | speech AST: 277 streams, 25.3 min, 100% of bytes; 106 ABK files, 94 banks, 469 samples | `tools/re/ast.py`, `abkbank.py` | `all valid: True` |
| Engine sound curves | 32 ENG/EXH patches, 864 curves | `tools/re/csiscurves.py` | `bad: none` |

## What we learned, by system (addresses in Speed.exe)
- **Cameras.** The default race camera is `CubicCameraMover` (type 0x11): `0x42c670` picks 0x11 when `[0x700aa4]` is non-zero, it holds 1 and no code writes it by absolute address (writes by base+offset: not ruled out, I). The factory `0x42c6d0` has 23 types (0..0x16); FOV is a per-POV s16 table at `0x6fbdf4` (71.5 deg and 90 deg). Our old guesses `PS_FAR=200` and `W/512` do not exist on PC.
- **Blur.** Strength = ramp from camera-eye speed 25 to 125 (cap 0.65), 16 taps at half resolution (800x600 scene, 320x240 blur targets); constants at `0x702a38..44`, `0x6ccd00` = 1/255. Units of the speed (m/s) are I.
- **Canon (career).** Event table `0x5a00a0` (EventDesc 0x14c bytes, 256 slots at `0x733ff8`), price and rating table chunk 0x34a01, winning event 0x71 sets `0x7677ac`, cash at career +0x1374; 42 movie names (`0x6f90d8`), 23 `.mad` on disk. `0x5a1100` (re-open events) is I.
- **Tuning and garage.** 35 car types of 0xc90 bytes; the steering-vs-speed table at `0x705f48` is NOT tuning (10 points, x 0..160); part prices come from `0x5a08f0` reading `[0x733f78+type*4]` (the old "no prices" note was wrong); perf-path mapper `0x5a0350` has 11 cases. Reload restores the career block byte for byte (`0x41da40 -> 0x4ab200`).
- **Sound.** Engine chain: loader `0x51dec0`, family table `0x6f8100`, crossfade `0x529cd0` with table `0x6f7220`; 95 speech events and 277 lines (`0x6f6bc8`), all callers are front-end (I for "none in race", static scan only).
- **Assets.** Dispatcher `0x447ac0`, ResourceFile slot 0xb4 bytes (`0x447f40`), COMP and JDLZ containers; 137 chunk ids documented (115 seen in game files, 22 known only from code).
- **Props.** Smackables: pool of 32 x 0x4d0 (`0x595bf0`), Virgin `0x5962e0` -> Smokeable `0x596570`, respawn `0x5977f0` after 2.0 s at rest; surface rows are 0x94 bytes at `0x6ef2d0`.
- **Traffic.** No spawner: cars are moved by the teleporter `0x598600` (0.3 s on a route, 1.0 s in Free Run, 250 m ahead, 500 m cap; constants `0x6b5a30..3c`); 49 intersections (chunk 0x34123), 94 spawn points (0x34124); incoming cap 30 (`0x4322a0`).
- **Track.** Collision pool `0x4412b0` (TrackPolygonSlotPool, slot 0x80), the section streamer around `0x444480`, zone queries `0x4436d0`; of the 16 TRACKB files, 1001..1008 are closed routes and 1102..1109 open, 2.9..8.2 km. 62 names (48 V) in `docs/re/track.md`. The graph tag `track` is wrong for several functions (e.g. `0x4655f0` is body collision).
- **HUD and input.** One `HudManager` (`0x4a8e40`) per player owns 17 FEng widgets; a 64-bit visibility mask from `0x42e620` is applied by `0x4a9540`, widgets are updated by `0x4a9440`; the minimap is drawn in the same pass (`0x409cd0 -> 0x58e810`). Keyboard uses DirectInput8 action maps (40 game and 36 menu actions); wheels and force feedback go through an embedded "EZ Wheel Wrapper v4.26". 108 names (73 V) in `docs/re/hud_input.md`.
- **Runtime.** The C library is MSVC VS2003 static, `0x670c6c..0x6849d0` (about 540 functions); the engine base library (`bMalloc` pools, `SlotPool`, lists, hash) is `0x564000..0x568800`. Only 608 of the 3,765 functions tagged "runtime" are CRT; 1,228 are SEH unwind funclets and 235 the network stack. Ghidra's signature names are wrong for `0x67147f` (`_printf`) and `0x674839` (`_vfprintf`). 126 names (90 V) in `docs/re/runtime.md`.
- **Rivals.** Rating match `0x57f700/0x57f970` (303 of 313 rivals match the player), spawn `0x4b5df0 -> 0x4b4040 -> 0x4b26f0`, AI table of 523 floats copied to `0x779c78` (chunk 0x34b00), rubber band `0x44bd10` every 0.3 s with strength from EventDesc +0x12c. Skill vs aggression bytes (+0x735/+0x736) are I.

## Numbers (python3 tools/census/scoreboard.py; tables in docs/re_scoreboard.md §5)
13,739 functions lifted; 6,038 (43.9%) ran in 12 scenarios (a floor); 1,180 carry a name, 938 of them V; 5,502 are tagged by a med/high graph tag or a name.
Names: `census/names.tsv` (1,335 addresses, aliases and func/data kind). The graph's system tags are unreliable (38% strict agreement); a name's system overrides them.

## One finding that touches the game (OWNER's call, nothing applied)
Our patch `0x735ec1=1` ("everything available") also makes `0x5a1520` return 1e9 cash, so garage purchases drive the balance negative (asas0.ugd: -9,875). Proposal `?cash=real` in `docs/re/proposals.md`.

## What this does not claim
Names are checked against the binary where marked V, but no human has read every function. 56% of the functions never ran in our scenarios. Race-time behaviour (voices in race, AI by skill, camera writes by offset) rests on static scans marked I.
