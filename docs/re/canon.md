# Canon: career, events, rewards, text, movies, saves (Speed.exe PC) — RE notes

Marks: V = read in code or bytes this session, I = inferred, U = open. Tools: G = Ghidra 12.1.4 export
`census/ghidra/decomp_*.c`, H = Hopper export `census/hopper/decomp.c`, C = capstone `tools/recomp/asm.py`,
D = data read with the readers below. Earlier work: `tools/census/career.py` (career oracle, field addresses),
`ref/docs/re/event-desc.md` (PS2 build: hints only). Names: `census/names_canon.tsv`.

Readers (each has a `check` that passes on the real files):
`tools/re/events.py` (EventDesc, 116/116 records re-pack), `tools/re/lang.py` (22 string tables re-pack, Korean decodes),
`tools/re/save.py` (profile saves: 9 files re-pack, Adler-32 recomputes).

## Answer

- **The whole career is one data table.** `FrontEnd/FrontB.lzc` holds container `0x80034a00` (loader `0x5a00a0`):
  `0x34a02` = 116 `EventDesc` records of 0x14c bytes, ids 0..122, indexed into `[0x733ff8 + 4*id]` (256 slots);
  `0x34a01` = 25 rows of 0x20 bytes into `[0x733f78 + 4*id]`. V (H, G, D)
- **An event** = kind, race mode, entry fee, cash per difficulty, up to 8 stages (track, laps, direction), up to 6
  prerequisite ids with an all/any rule, 3 movie slots, 3 named rivals with a car preset hash, up to 5 rewards. V (D),
  field readers in `tools/census/career.py`, sampled with G below.
- **Progress is one byte per event.** `career + 0x34c + id` (career object `0x75eef8`): 0 locked, 1 open, 2 won,
  3 racing, 5 quit. `0x5a1100` opens every event that is not won and whose prerequisites are done (`0x5a0fc0`:
  skip status 2 / 4 and kind 8; rule `+0xa8` 0 = all, 1 = any over `+0x9c[+0xaa]`). V (H, G)
- **Winning** (`0x5a0dc0`): cash `career+0x1374` and lifetime cash `+0x1378` grow by the cash for the difficulty,
  status = 2, each type-1 reward hands out a magazine cover (27 unlock slots of 0x454 bytes at `career+0x13a8`, byte 1 = unlocked,
  hash -> index table `0x744ab0`; `0x51ad30` announces it, I); winning event `0x71` (113) sets the career-beaten flag
  `0x7677ac`. V (G)
- **Reward types** (triples `type, value, arg` at `+0x38`, count `+0x74`). The values decode against Speed.exe's own
  names with bStringHash: 31/31 hashes match. V (D) for the meaning of the values, I for who applies types 0/2/3/4:
  | type | value | arg | count | meaning |
  |---|---|---|---|---|
  | 0 | part category 0..0x18 | level (1..4) | 67 | performance/visual upgrade unlock; `0x5a3f00` folds them into a bit set for the reward screen (V G) |
  | 1 | hash of `MAGAZINE_RACE_n` | 0 | 11 | magazine cover (given in `0x5a0dc0`, V G) |
  | 2 | hash of a car name (`MIATA`, `SKYLINE`...) | 0 | 20 | car unlock |
  | 3 | track id (1001..1308) | 0/1 | 47 | track unlock for Quick Race; arg = reverse direction (I) |
  | 4 | 0 | 0 | 2 | U |
- **Text** is 3,846 strings per language keyed by bStringHash of a label; `Languages/Labels.bin` holds the labels
  themselves (3,843/3,846 re-hash). V (D, H for the loader `0x59fce0`)
- **Movies**: 23 `.mad` files ship; the game knows 42 movie names (`0x6f90d8`, name -> id by `0x4f7840`). V (C, H)

## EventDesc (0x14c bytes)

| Off | Type | Field | Mark | Where read |
|---|---|---|---|---|
| +0x00 | u32 | id (< 0x100) | V | loader 0x5a00a0 indexes by it |
| +0x04 | u32 | kind: 0 race, 1 tournament (stages), 2 / 3 Junkman / Samantha events, 6 (40 events), 8 never opens; 4, 5 single | V for 1/2/3/8 (career.py, 0x5a0fc0 G), U for 0/4/5/6 meaning | 0x5a0fc0, 0x4ab670 |
| +0x08 | u32 | race mode 0..5 | V field, I names | 0x4b5df0 |
| +0x10 | f32 | entry fee | V | 0x5a0d43 |
| +0x18 | u32 | 0..4 on 10 events | U | |
| +0x1c..+0x24 | 3 f32 | values 95..172 on 7 events (score / time targets?) | U | |
| +0x28 | 3 f32 | cash for a win, by difficulty (career+0x348) | V | 0x5a0e3b |
| +0x34 | u32 | `0xa000n` on 40 events | U | |
| +0x38 | 5 x 12 | rewards (type, value, arg) | V | 0x5a0dc0, 0x5a3f00 |
| +0x74 | u32 | reward count | V | 0x5a3f00 (G: `param_1 + 0x1d`) |
| +0x78 | 8 x 4 | stages: u16 track, u8 laps, u8 direction | V | 0x4b5df0 |
| +0x98 | u32 | stage count (1, 3 or 4) | V | |
| +0x9c | 6 x i16 | prerequisite ids | V | 0x5a0fc0 |
| +0xa8 | i16 | prerequisite rule 0 all / 1 any | V | 0x5a0fc0 (G) |
| +0xaa | i16 | prerequisite count | V | 0x5a0fc0 (G) |
| +0xac / +0xb8 / +0xc4 | 12 s | movie before / after a loss / after a win | V | 0x4c5df0, 0x4e86d0 (career.py) |
| +0xd0 | u32 | set on one event only | U | |
| +0xd4 | 3 x 0x1c | rivals: name[8], u32, u32 car preset hash (= FEHashUpper of a 0x30220 preset label), 12 bytes | V name+hash | PS2 note: 212/212 keys match |
| +0x128..+0x148 | 9 x 4 | 0..3, a float 0.8..1.2, a hash, 0..3, 1/2, floats 0.25..1, 1.0, 1.0, 0/2 | U (AI skill / traffic density?) | |

`tools/re/events.py fields` prints the value spread of every unnamed range.

## Text (chunk 0x39000)

Layout in `tools/re/lang.py` (docstring). Loader `0x59fce0` stores charset `[0x734438]`, count `[0x73442c]`, table
`[0x734434]`, strings `[0x734430]` and rebases each offset; lookup `0x59fb80` binary-searches the sorted hash table. V (H, D)
- Files: the game opens `LANGUAGES\<NAME>.BIN` (10 names in Speed.exe). `LANGUAGE_*.bin` (3,845 strings, one fewer) are
  not named in Speed.exe: an older copy left on disc. I
- The charset (`u32 n`, `u16[n]`) maps a byte (or a 2-byte code) to Unicode. Western: identity over 256. Korean: 807
  entries; a lead byte 0x80..0x85 with trail t is `charset[t + (0x86 - lead) * 0x80]`; every Korean string decodes. V (D)
  No code reads `[0x734438]` except the loader (H grep): the charset is likely only for the font tools. I
- `Chinese.bin` has empty strings (no Chinese text on PC). V (D)
- Each language file also carries its FEng fonts (chunks 0x30201). V (D, `tools/re/chunks.py tree`)

## Movies

- Files (23): 01_DAY, 02_FAN_e/_s, 04_GUM_e/_s, 05_ENG .. 19_FIN (story), THX_logo, logo_eng, e3_title, drift,
  eng_drag. V (ls)
- Movie enum `0x6f90d8`: 42 `{name, id}` pairs, `0x4f7840` turns a name into the id by strcmp. Names with no file in
  this build: preopen, psa, fre/ger/spa/dut/ita/swe_drag, ssx, intssx, nfl, intnfl, nascar, logo_fre..logo_swe, nfsgb.
  V (C, H)
- Localised variants `0x6ee844`: records of 0x60 bytes, `{name, lang, name}` pairs (FR/GR/IT/SP prefixes). V (C)
- Movie theatre (`MU_UG_MovieTheaterViewer`) table `0x6fae30`: 16 rows `{hash, ICON_FMV_nn, movie}`; 12_BUD is not in
  the theatre. Read by 0x4c9240 and 0x513c90. V (C), readers I
- Boot movie `0x4deaa0`: language `[0x734998]` 0 or 5 -> `na_boot` (not shipped; the port patches around it at
  `0x4f5891`), else the localised logo from `0x59fd70` (`logo_eng`). V (H)
- Path `0x4f57a0`: `sprintf("%sMOVIES\%s%s", root, name, ".mad")`. V (H)

## Saves

Reader: `tools/re/save.py` (`dump FILE`, `check`: 4 .ugd, 2 .opt, Profiles.usr, 2 .cfg recompute their Adler-32 and
re-pack byte for byte). Tool marks here: C = capstone, H, G, F = the real files in save/ (read only).
Everything lives in `<CSIDL_COMMON_APPDATA>\NFS Underground\` (the port maps it to save/): `Profiles.usr` plus per profile
`<name>.cfg`, `<name>.opt`, `<name>_autosave.ugd` and `<name><slot>.ugd`. All binary files are little endian, version
dword 0x13, and use one checksum: Adler-32 (a=1, b=0, mod 0xfff1, result b<<16|a) = `0x41dd10`, identical to zlib.

- `.ugd` (63123 = 0xf693 bytes): `u32 0x13 | 0x12 caption | 0x19 time stamp | 0xf660 block | u32 adler32(block)`.
  The checksum covers only the 0xf660 block (not the header) and is stored last. Verified on 4 real files (recomputed = stored).
- Block = a compacted copy of the player block P at 0x7588c4 (size 0xf944; stride to player 1 is 0xf944), made by
  `0x4ab120` (pack) and `0x4ab200` (unpack, only if version and checksum match). Pieces, in order: `u32 0` | P+0x210 (4) |
  P+0x364..P+0xeee8 (0xeb84) | P+0xeee8 (4) | P+0xeef4 (0xa50) | P+0x214 (0x80). The big run holds the customization
  records, the 20 car records and the career object (0x75eef8 = P+0x6634, 0x88b4 bytes).
- `.opt` (749 bytes): `u32 0x13 | 0x2e5 payload | u32 adler32(payload)`. Payload = `u32 0` + 15 pieces of P below 0x364 (name, flags,
  nine audio floats at file byte 0x3d, controls) + P+0xeec. Writer `0x41e200`, reader `0x41e330`, serializer `0x4aaad0`.
- `.usr` (Profiles.usr): `u32 count | count x 0x20-byte records` (name[8] then stack residue), most recently used first,
  no checksum. `.cfg`: text `KEY: value\r\n`, 22 integer keys from the table at 0x700ec0, two closing blank lines.
- Career: status bytes at career+0x34c+id (V), difficulty +0x348 (V), cash +0x1374 = earned +0x1378 - spent +0x137c (V, holds on
  asas: 28100 - 18776 = 9324), current car hash +0x08 (asas = SUPRA, new profile "a" = SKYLINE), bought parts +0x450.. (25 x 36 keys).
- Saved data holds one pointer (+0x88b0, live race object, 0 in menus) and one vtable (+0x44c = 0x6c6434): a loader must not relocate them.

### Header and file-level table

| file offset | size | meaning | mark | address |
|---|---|---|---|---|
| ugd +0x00 | 4 | version 0x13; reader rejects anything else | V | write 0x41d8e6; check 0x41da96, 0x41dbc8 |
| ugd +0x04 | 0x12 | caption, raw copy of a caller buffer. Autosave passes static 0x6b7c58 ("auto\0\0\0\0" + rodata residue "PERT..."); manual save passes UI field esi+0x20c ("Damian\0\0ITC_TT14i.") | V | 0x41d9a3; 0x417063; 0x41cf50 |
| ugd +0x16 | 0x19 | time stamp text "HH:mm dd/MM/yyyy" = GetTimeFormat (TIME_NOSECONDS, "HH':'mm" when [0x734998] is 2 or 4) + " " + GetDateFormat (short); bytes after the NUL are stack residue | V | 0x41d906..0x41d98d |
| ugd +0x2f | 0xf660 | block (below) | V | 0x4ab120 called at 0x41d9d0 |
| ugd +0xf68f | 4 | adler32 of the block only | V | 0x41dd10 called at 0x41d9f4; compare 0x41daf5 |
| opt +0x00 | 4 | version 0x13 | V | 0x41e2ae; 0x41e330 compares |
| opt +0x04 | 0x2e5 | payload from 0x4aaad0; first dword is 0 | V | 0x41e2d6 |
| opt +0x2e9 | 4 | adler32 of the payload | V | 0x41e2fa |
| usr +0x00 | 4 | count | V | write 0x41d59b; load 0x41d140 |
| usr +0x04 | 0x20 each | profile name[8], rest is stack residue; list is MRU: 0x41d2a0 moves or inserts the name (case-insensitive compare, &0x5f) at index 0 | V | 0x41d5ea (fwrite size 0x20) |
| cfg | text | key table {name*, &var, type 0 int / 1 float / 2 string} at 0x700ec0; order BPP RES PERFORMANCE ENVMAP WORLDENVMAP SHADOW HEADLIGHTS CARLIGHTING DAMAGE CROWD ROADREFLECTION FOG MOTIONBLUR LIGHTSTREAKS LIGHTGLOW ANIMATEDTEXTURE PARTICLESYSTEMS DEPTHOFFIELD WorldLOD CarLOD SOUNDPERF SOUNDENABLE (all type 0) | V | write 0x41c7a0 (loop 0x41c7f5..0x41c912); read 0x41c680 via 0x4051f0 |
| pro | - | `<name>0.pro`: u32 1 \| blob \| adler32(blob), writer 0x41d650, reader 0x41d770; no file exists in save/ | V code, no sample | 0x41d70a, 0x41d836 |

### Block pieces (.ugd block offset, P offset)

| block off | size | P offset / VA | meaning | mark | address |
|---|---|---|---|---|---|
| 0x0000 | 4 | - | zero dword (unpack skips it) | V | 0x4ab12b; skip 0x4ab205 |
| 0x0004 | 4 | P+0x210 / 0x758ad4 | one dword, values 0xc9e (a), 0xc08c (asas), 0x5971 (asas0); meaning not found | U | copy 0x4ab15d / 0x4ab213 |
| 0x0008 | 4+4 | P+0x364 / 0x758c28 | head of the customization database: +4 is 0xa356d66f in all files, +0 differs (a: 0xea0ba433) | U | init 0x4ac460 |
| 0x0010 | 10 x 0x338 | P+0x36c / 0x758c30 | customization records; rec+4 = hash of a formatted name (0xc4f9a0e2 + i); rec+0 non-zero means used; all 10 empty in our files | V (layout, id), U (inside) | index bound 0x4e7c47; init 0x4ac491..0x4ac4ab |
| 0x2040 | 20 x 0x348 | P+0x239c / 0x75ac60 | car records, one per tuner car (usage 0); +0 = 1, +8 = car-type hash (= bStringHash of the CarTypeInfo name, F: GOLF 0x163087 ... SKYLINE 0xbe48375e), +0xc = 0xff default (asas has 4 on TIBURON, 2 on SKYLINE), +0x10 = byte table 00 01 02 .. 19 | V (array, hash), I (+0 +0xc +0x10 meaning) | init 0x4ac4d3..0x4ac4f4; F |
| 0x61e0 | 4 | P+0x653c / 0x75ee00 | car record count (20) | V | 0x4ac4b6, 0x4bc176 |
| 0x61e4 | 13 x 16 | P+0x6540 / 0x75ee04 | list of 16-byte entries {hash, hash, flag, id}; first three (0x9eafc754..56) have flag 8 and id -1, the next ten flag 0xff and id 0x68..0x71 | I (purpose) | built 0x4ac220; F |
| 0x62d4 | 4 | P+0x6630 / 0x75eef4 | entry count of that list (0xd) | V | 0x4bc2f1, 0x4bc4d2; F |
| 0x62d8 | 0x88b4 | P+0x6634 / 0x75eef8 | career object | V | reset 0x5a0a00 |
| 0xeb8c | 4 | P+0xeee8 / 0x7677ac | career-beaten flag (event 0x71 won) | V (brief) | 0x5a0dc0 |
| 0xeb90 | 0xa50 | P+0xeef4 / 0x7677b8 | stats and records: 8-byte records up to 0x7681ba (key word, byte, byte, ...; 0x4baba0 scans them), then counters 0x7681b8..0x768208 shown by the stats screen; zeroed for a new profile | I | 0x4baba0; 0x4ea6b0..0x4ea810; clear 0x41cfc4 |
| 0xf5e0 | 0x80 | P+0x214 / 0x758ad8 | 32 dwords, zero for a new profile; meaning not found | U | clear 0x41cf92 |

### Career object (offsets from 0x75eef8)

| offset | size | meaning | mark | address |
|---|---|---|---|---|
| 0x000 | 0x338 | current car customization record (same shape as a car record: +0 = 1, +8 hash, +0xc, +0x10 byte table); 0x51ad30 copies 0xce dwords from here | I | 0x51ad92 |
| 0x008 | 4 | current car type hash (compared with CarTypeInfo+0xd0, 35 x 0xc90) | V | 0x4bc4ea..0x4bc50a; F |
| 0x2e0 | 11 x 4 | installed upgrade level 0..3 per upgrade path 0..10 (weights, suspension, engine, turbo, nitrous, ECU, transmission, tires, spoiler, ground effects, brakes in carinfo.py path ids); "all paths >= n except 9 and 10" unlocks MAGAZINE_TASK n | I | 0x51aed0..0x51b055 (skips 0x75f1fc/0x75f200) |
| 0x338 | 12 | two hashes (43599b4d, 307d9226), meaning not found | U | F |
| 0x348 | 4 | difficulty 0/1/2 (briefing writes it; win cash is indexed by it) | V | 0x5a0e35, 0x4c5df0 |
| 0x34c | 0x100 | event status byte per id: 0 locked, 1 open, 2 won, 3 racing, 5 quit (4 is tested, writer not found) | V | 0x5a0cf5..0x5a0d72, 0x5a0f95, 0x5a1100 |
| 0x44c | 4 | vtable pointer 0x6c6434 of the parts store (store object starts here, `this` = 0x75f344) | V (value F), I (meaning) | 0x5056fc, F |
| 0x450 | 25 x 0x90 | bought parts: row per path type (index < 0x19), 36 dword keys per row (0 = empty); membership test | V | 0x5a3630 (reads), 0x5a0b04 (clear 0xe10) |
| 0x1260 | 0x110 | cleared by reset; users index it by 4 | U | 0x5a0b0c, 0x50bc10 |
| 0x1370 | 2 | two flag bytes set to 1 together | I | 0x4d8420, 0x4d8270, 0x4d82f0 |
| 0x1374 | 4 | cash (signed); 1e9 shown when cheat flags [0x73494c] [0x735ec1] [0x73440c] | V | 0x5a1520, 0x5a0d4b, 0x5a0e44 |
| 0x1378 | 4 | total earned (grows with wins; cash = earned - spent in F) | V | 0x5a0e4a |
| 0x137c | 4 | total spent (purchases add) | V | 0x5a0d51, 0x4c37de |
| 0x1380 | 4 | cleared by reset, no other user found | U | 0x5a0a51 |
| 0x1384 | 2 | cars-owned flag (0 = no car yet, tested by the prologue) | V | 0x4e880a, 0x4bc4ea |
| 0x1386 | 2 | two bytes, [0x76027f] toggled on first garage visit | I | 0x4eb05e, 0x4eb069 |
| 0x1388 | 4 | id of the event whose rewards were just given (-1 none) | V | 0x5a3f00 (stores [eax]), 0x5a0e2a |
| 0x138c | 4 | bit set of reward kinds just given (bit per category) | V | 0x5a3f00 |
| 0x1390 | 0x14 | five dwords cleared after each win and by reset | U | 0x5a0d98..0x5a0daa |
| 0x13a4 | 4 | bit mask of seen/used items (asas 0x1fff9cc) | I | 0x4c3db0, 0x4cd490, 0x50a5d0 |
| 0x13a8 | 27 x 0x454 | unlock slots keyed by name hash through the runtime table 0x744ab0 {hash, index}; byte0 and byte1 are flags (byte1 = unlocked, set by reward type 1 and MAGAZINE_TASK rules); the body repeats a car record (+0xc = car hash, e.g. SUPRA in slots 19 and 20) | V (array, stride, flags), I (body) | 0x5a0a82..0x5a0a9b, 0x5a0b73, 0x5a0e91 |
| 0x4344 | - | slots 11..26 are scanned by the announcer | V | 0x5a0eec |
| 0x8884 | 27 | per-slot "announced" bytes | V | 0x5a0eff |
| 0x889f | 1 | byte cleared by reset | U | 0x5a0ab7 |
| 0x88a0 | 16 | flags for the four magazine tasks and others (bytes at 0x767798..a7) | I | 0x51ae90..0x51b3b0 |
| 0x88b0 | 4 | pointer to the live race/event object (its +0x58a0 holds an event id that overrides the table); 0 in menus | V | 0x5a0cf5, 0x5a0f98 |


## Open

- U: event kinds 0/4/5/6 by name; fields +0x18..+0x24, +0x34, +0xd0, +0x128..+0x148; reward type 4.
- U: who applies reward types 0, 2, 3 (unlock queries scanning won events).
- U: `0x34a01` rows (25 x 0x20, values like 300/600/900): `0x5a08f0` reads `[0x733f78 + type*4]` as a price table
  (night-opus-a lead) while the career cash is real; reconcile with docs/re/tuning.md "No prices".
