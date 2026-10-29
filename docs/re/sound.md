# Sound (Speed.exe PC) — RE notes

Marks: V = read in code or bytes this session, I = inferred, U = open. Tools: G = Ghidra 12.1.4 (REA MCP / headless
`tools/ghidra/gpar.sh`), H = Hopper export `census/hopper/decomp.c`, C = capstone `tools/recomp/asm.py`,
D = data read with `tools/re/ast.py` / `tools/re/abkbank.py`. Earlier work: `docs/re_audio_default.md` (the 9 volume
sliders, `0x4aa200`, category volume `0x51cb70`), `tools/recomp/abk.py` (ABK code modules lifted ahead of time).

## Answer

- **Two kinds of files.**
  - **ABK** (`game/Sound/**`, 106 files): a small x86 code module (the "patch" that plays a sound) plus a `BNKl`
    bank of short samples. There are 94 banks with 469 samples, 6.7 min in all. V (D)
  - **AST** (`game/SNDSTREAMS`, `game/SpeechStreams`): banks of long EA `SCxl` streams packed back to back.
    Music has 27 streams (97 min), stereo ambience 320, mono point ambience 102, special 33, English speech 277.
    V (D)
- **One name table drives every load.** `0x521c80` turns a request {class `+0x38`, index A `+0x3c`, index B `+0x40`} into a
  file name (table `0x6f7f10..0x6f80e8`) and a directory (table `0x6f7eb0`, 23 entries). Classes: 0 FE, 1 stream
  (name + second name per language/variant), 3 environment, 6 impact/scrape, 7 skids (A×5+B), 8 nitrous,
  10 shifting, 12 engine `C<A>U<B>_M0_ENG_MB`, 13 exhaust `C<A>U<B>_M0_EXH_MB`, 14 turbo (A×5+B). V (G)
- **Engine sound = family × upgrade level.** There are 4 engine families (`Car_0..3`) × 4 engine levels
  (`Eng_UG_0..3`). Each pair has an ENG bank and an EXH bank (3 mono loops of ~1.5 s at 22,050 Hz each), a shift
  bank (SML/MED/LRG by level) and a spark-chatter bank. So buying engine upgrades swaps the engine *recording*, not
  only the pitch. V for the file layout and the resolver (G, D). Which car field picks the family: U (asked of the
  sound agent; see below).
- **Music is a playlist, not random.** V (G):
  - The song table `0x6f4d08` (26 × {title, artist, album, "IG"|"FE"}) holds 19 in-game and 7 menu songs.
  - The picker `0x53c3a0` walks the order array at `0x758b58` (stride 8) from the position at `player+0xf8`
    (wraps at 26).
  - It skips songs whose bit is off in `0x758930` (in race: `[0x77a920]==3` or player mode 8) or in `0x758934`
    (menus). These are the EA Trax jukebox toggles in the options block `0x7588c4`.
  - It plays stream `song+1` of `STRM_Music_UG0_MB.ast`. Stream 0 (30 s) is outside the playlist.
  - Mode 99 at `player+0xf0` plays one chosen song (the jukebox preview).
  - `0x51c7b0` points the sound manager's `+0xa8` at the now-playing record (title/artist on screen).

## 1. Files

| Dir (table 0x6f7eb0) | Files | Content (D) |
|---|---|---|
| `Car_<0..3>\Eng_UG_<0..3>\` | 16 dirs × {C?U?_M0_ENG_MB, C?U?_M0_EXH_MB, shifting_*, SparkChatter_0?} | engine + exhaust loops, shifts |
| `TURBO\` | TURBO_00..02, 00A..02C (3 sizes × 4 variants) | turbo spool / blow-off |
| `NOS\` | nitrous_00/01 | nitrous |
| `Skids\` | SKID_PAV(2), SKIDS_DRIFT(2) | tyre squeal by surface / drift |
| `IG_GLOBAL\` | ENV_COMMON, ENV_CHINA01, WIND_00/01, IMPACT, SCRAPE, ROADNOISE_00 | in-game shared |
| `FE\`, `Global\` | FE_MB, FE_COMMON_MB | menus |
| `Evt_Sys\`, `STRMBANK\` | event system banks, stream-bank descriptors | U: role of STRMBANK |

`tools/re/abkbank.py check`: 106 files parse; every non-empty `BNKl` slot is a PT header whose data offset lies
inside the bank, and the header field `+0x14` equals the file size. V (D, 2026-10-29).
ABKC header: `+0x10` module id, `+0x14` file size, `+0x18` header size, `+0x20/+0x24` bank offset/size,
`+0x30/+0x34` relocation tables (`tools/recomp/abk.py`). BNKl: `u16 version=5, u16 slots, u32 size`; slots at `+0x10`
are self-relative offsets (0 = empty) to PT tag lists.

`tools/re/ast.py check` walks all 5 AST files byte by byte: every stream is `SCHl SCCl SCDl* SCEl`, and the gaps
are zero padding only. Coverage is 100 % of the bytes of all five files. V (D). PT tags used: 0x82 channels,
0x84 rate (absent = 22,050), 0x85 samples. Ambience and special streams are 24 kHz; music and speech carry no rate
tag (22,050 Hz default).

## 2. Load path

- `0x51d240` is the sound manager's per-frame service (manager at `[0x7356a8]`; G). It drains the pending-load
  queue (entries 0x1c bytes at `mgr+0x1ec`, `mgr+0x7c` → `mgr+0x78`). For each entry it calls `0x522020`, which
  resolves the name through `0x521c80` and starts the load. Then it updates the object lists `mgr+0xc4`, `+0xd0`
  and `+0xe4` (vtable `+0x30` = update) and the stream manager `mgr+0x104`. V (G); object names: see
  `census/names_sound.tsv`.
- `0x51c5f0` switches the stream set (arg 1..4, 9 → set 5..9) and blocks, servicing loads (`0x58a850`) until no
  slot in `0x72ce58..0x72cfd7` is busy. V (G); I that this runs between front end and race.

## 3. Music selection (detail)

Song table record (16 bytes, `0x6f4d08..0x6f4ea8`): `char* title, artist, album, where` with where = "IG"
(songs 0..18) or "FE" (19..25). V (D).
Picker `0x53c3a0` (V, G). It reads `p = player`, `order = 0x758b58[pos*2]`, where `pos = p+0xf8`.
- In race, it advances while `!(0x758930 & 1<<(order+1))`; otherwise it uses `0x758934`.
- It gives up after 26 tries and leaves the music off.
- It then sets `stream = order+1` into the stream request (+0x4c/+0x54/+0x58) and `p+0xfc = stream-1`, and
  advances `pos`.

## 4. Engine sound chain (sonnet-exec agent, Ghidra; names checked against Hopper, census/names_sound.tsv)

- **Bank choice.**
  - `0x51dec0` (LoadInGameSoundBanks) walks the race entrants: 0x750 bytes each at `[0x78a418]`, `+0x10` RideInfo.
    It keeps local human entrants only (`+4==1`, `+0x734==0`). When `[0x734658]!=0`, every level is forced to 3.
  - **Family A** (classes 12/13) = fixed table `0x6f8100` indexed by car index (`RideInfo+0`, mapped by the
    20-case switch `0x520320`; the switch bytes at 0x5203d4 are not read byte by byte, I). It is not a
    CarTypeInfo field. Car index→family: 0→2, 1→0, 2→0, 3→0, 4→0, 5→0, 6→2, 7→2, 8→1, 9→3, 10→2, 11→2, 12→3,
    13→2, 14→2, 15→3, 16→1, 17→0, 18→2, 19→1.
  - **Level B** = spec `level[2]`, the engine path. TunerCar::Initialize `0x526420` stores it at `this+0x1efc`
    (`mov eax,[edx+0x20]` at 0x526494) and the family at `+0x1ef4`.
  - Turbo: B = `level[3]`, A = `clamp(byte [entrant+0x435], 0..3)` (field U).
  - Nitrous: B = `level[4]`. Skids: B = `level[7]`.
  - The shifting class 0xa is never queued: its `0x521c80` branch is dead, and shift sounds come from the engine
    bank.
  - AI and traffic cars reuse one of two already loaded engine banks (`[mgr+0x68+k*4]`, alternating by
    `[0x78eae4]`, 0x526500..0x526516).
- **Per frame.**
  - `EAXTunerCar::Update 0x52c620` → `0x52c3f0` reads RPM `car+0x3e0` (/ `this+0x1f24`) into `this+0x1f20` and
    torque `car+0x3ec` into `this+0x1f90`.
  - `UpdateTorque 0x527080` / `UpdateRPM 0x527180` smooth them with curve `0x5326f0`.
  - `UpdateEngineVol 0x529cd0` (AI `0x5235a0`) crossfades two volume layers by load `this+0x2ac` (0..0x400) with
    table `0x6f7220`.
  - `0x52bf70` pushes L/R volume, four 0..0x400 values, load and pan to the engine's Csis instance
    (`this+0x1760`, created by `InitializeEngine 0x529b60` in class `0x7441c8`).
- **Down to dsound.**
  - EA's SND software mixer owns the buffers: `DirectSoundCreate` from `0x654340`/`0x654880`, primary `0x71406c`,
    500 ms streaming secondary `0x714070`.
  - The pump `0x654050` runs the 100 Hz server `0x64e330`, then the mixer `0x656d70`, then Lock/Unlock.
  - `EAXSND8Wrapper::Initialize 0x532a20` sets 32 voices and 22,050/44,100 Hz from `0x6f7e88`.
  - `EAXMixMgr 0x5364e0` holds 4 groups × 11 channels, with presets at `0x743ca8` (stride 0x6c).
- Names and the 20 corrections to the x86-ps2 map: agent TSV (night_log.md handoff), to be merged into
  `census/names_sound.tsv`.

## 5. Engine patch: from RPM to the three loops (night-opus-a2)

- **Parameters.** `0x52bf70` writes the engine Csis instance (`[this+0x1760]`) every frame. Then `0x64bc30`
  commits it. V (H, 2026-10-29). The Csis param slots are ints:
  | slot | value | scale |
  |---|---|---|
  | `+0x14`, `+0x18` | RPM `this+0x1f1c` | × 0.1024, clamped 0..0x400 (0x400 = 10,000 rpm) |
  | `+0x1c`, `+0x20` | torque/load `this+0x1f8c` | × 10.24, clamped 0..0x400 (0x400 = 100) |
  | `+0x24`, `+0x28` | volume L/R `this+0x238`/`+0x23c` | clamped 0..0x7fff |
  | `+0x44` | `this+0x2ac` (the load used by UpdateEngineVol) | clamped 0..0x400 |
  | `+0x48` | `this+0x6c` | clamped 0..0x10000 |
  | `+0x4c` | pan from the car's i16 `+0x52` | −0x3fff..0x3fff |

  The constants 0.1024 and 10.24 come from `0x3dd1b717` and `0x4123d70a`.
- **The patch is a node graph, not code with formulas.** The ENG module (for example `C0U0_M0_ENG_MB.abk`, module
  id 121576) has one patch function at `+0xa8`. It is 0x5a2 bytes of straight-line code: `push esi; call node; mov
  [esi+k],eax; add esi,size`. Each call evaluates one node whose state block lives in the instance, and each result
  is written into the input slots of later nodes. V (C, capstone on the relocated header, `tools/recomp/abk.py`
  relocate). The node functions live in Speed.exe:
  | node | what it does (H, C) |
  |---|---|
  | `0x64cdd0` (27 uses) | curve: clamps the input to [min,max] of a curve record, then reads an int8/int16 table at `+0x10`, with a float scale at `+0xc` |
  | `0x64d0b0` (23) | product: `a * b * scale` |
  | `0x64db50` (10) | pass-through/copy of three values |
  | `0x64cb90` (4) | gate with hysteresis: on inside window [a,b], off inside window [c,d] |
  | `0x64cf90` (4) | select: `list[index]` |
  | `0x64da70` (4) | ramp/slew toward a target over N steps |
  | `0x64d960` (3) | oscillator (phase wrap, sine through `0x713ca0`) |
  | `0x64d860` (3) | voice node: state 0 stop / 1 start / 2 update; picks the sample from a list by index `+0x14`, then calls the voice-type handlers `0x6e9a98` (start), `0x6e9aa8` (stop), `0x6e9ab8` (update) |
- **Shape (V, C).** First the inputs are fanned out to the nodes (`+0xc2..+0x143`). Then come four RPM/load curves
  and two pairs of hysteresis gates (on/off windows), three oscillators and the shared curves. Then there are three
  identical voice chains, `curve → sum → select → ramp → curve → product → voice 0x64d860`, one for each of the
  bank's three mono loops. So **pitch and volume of each loop are designer curves of RPM and load**, crossfaded by
  the gates. There is no formula in Speed.exe. The curve tables sit in the instance state built from the bank
  header, and their values are not dumped yet (U).
- **Speech (FE).** `PlaySpeechStream 0x51c830` with event `0x59` reads the table `0x6f8728[id*2 + variant]`. Only
  7 entries are set: id 2 → lines 0/1, 5 → 2, 6 → 3, 7 → 4, 11 → 5/6. The others are −1, which means stop. It then
  calls stream-manager vfunc `+0x98(0x59, line)`. The callers are FE screens (`0x4c3db0`, `0x4c5320`, `0x4c5fa0`,
  `0x4c6cb0`, `0x4c7790`, `0x4cd3e0`, `0x4cd490`, `0x50a5d0`). V (H, D). Which code plays the other ~270 lines of
  `SpeechStreams` (in race?) is U.

## Open (U)
- `entrant+0x435` (turbo variant); the 0x520320 switch read byte by byte.
- The values of the engine curve tables (RPM → pitch/volume per loop). The graph is read (§5), the numbers are not.
- Speech: the code path for the ~270 non-FE lines (in-race?) and the role of STRM_English_Speech_MB.abk (module 1497).
- Mixer path to dsound: the categories and sliders are in `docs/re_audio_default.md`. The voice/3D mixer names
  are in `census/names_sound.tsv` (EAXS_3DMixer, EAXMixMgr, EAXSND8Wrapper).
