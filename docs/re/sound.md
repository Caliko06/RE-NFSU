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

## Open (U)
- Engine family per car: which CarTypeInfo/RideInfo field feeds request A for classes 12/13, and B (engine level =
  spec level[2]?). Turbo variant (A×5+B) vs turbo level.
- The engine-sound model inside the ABK code (RPM → loop crossfade/pitch). The code is lifted in `abk.py`; its
  semantics are not read yet.
- Speech: which event picks which of the 277 lines (STRMBANK descriptors?).
- Mixer path to dsound: the categories and sliders are in `docs/re_audio_default.md`. The voice/3D mixer names
  are in `census/names_sound.tsv` (EAXS_3DMixer, EAXMixMgr, EAXSND8Wrapper).
