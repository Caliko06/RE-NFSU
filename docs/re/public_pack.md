# Public pack map (plan.json step 2 rows 3-4), 2026-11-13
Run 1: `:5180/?play=1&pool=1&mode=remaster&mute=1`, cold headless Chrome, CDP Network log of page + workers (every sync XHR Range). Marks: exe loaded 0.5 s, first Present 1.6 s, front end ready 2.15 s, city ready 19.6 s, race HUD 23.6 s. Data: census/public_pack.tsv (1966 rows), census/names_files.tsv. Run 2 (menu route) died at 2.6 s: `STOP ... __syscall_mkdirat`, web/out was being rebuilt by another worker; not repeated (2-run limit). "Menu" below = front end ready before the WORLD jump (INFERENCE).
## Bytes on the wire (MB, uncompressed except speed.wasm = gzip 16.4 of 70.4)
| Phase | web/out+pc | game/ | web/remaster | web/ug2 | build/openworld | page js | Total | Reqs |
|---|---|---|---|---|---|---|---|---|
| link -> menu (0-2.15 s) | 18.8 | 15.3 | 7.7 | 0.0 | 0.5 | 0.3 | 42.5 | 415 |
| menu -> driving (2.15-23.6 s) | 0.0 | 135.1 | 27.0 | 199.7 | 17.4 | 0.1 | 379.3 | 2518 |
Link -> driving = 421.8 MB; the next 20 s of driving add 1.8 MB (SNDSTREAMS). Fetched bytes include host/files.c read-ahead (256 KB, doubling to 4 MB), so they are >= what the game reads.
## Top 10 per phase (MB)
| # | link -> menu | MB | menu -> driving | MB |
|---|---|---|---|---|
| 1 | out/speed.wasm (gz) | 15.7 | ug2/city.bin | 98.6 |
| 2 | remaster/bc/* (many) | 7.4 | ug2/tex/*.png (1489) | 57.0 |
| 3 | game/FrontEnd/Road_Segment.bin | 6.1 | game/Tracks/STREAML1RA.BUN (66 ranges) | 54.8 |
| 4 | game/FrontEnd/FrontB.lzc | 4.0 | ug2/city_tex.bin | 43.7 |
| 5 | pc/Speed.exe | 3.0 | remaster/bc/* (829 files) | 27.0 |
| 6 | game/Sound/FE/FE_MB.abk | 1.8 | world/CARS_TEXTURES.BIN | 10.6 |
| 7 | game/Languages/LanguageTextures.bin | 1.1 | game/Cars/SKYLINE/GEOMETRY.BIN | 6.8 |
| 8 | game/Global/GlobalB.lzc | 0.9 | world/TRACKB1010.lzc | 5.4 |
| 9 | world/DYNTEX.BIN | 0.25 | game/Cars/GOLF/GEOMETRY.BIN | 3.8 |
| 10 | game/Cars/WHEELS/GEOMETRY.BIN | 0.25 | game/Cars/LANCER/GEOMETRY.BIN | 3.7 |
## Never opened (no Speed.exe literal in census/game_files.json, no request in run 1): 56.1 MB
| Group | Files | MB | Note |
|---|---|---|---|
| game root: setup.exe, AutoRun*, SECDRV.SYS, RunGame.exe, NFSU20MEG.bin (20.2), 0000000*, *.TMP, readme, filelists, .DS_Store | 17 | 22.9 | installer leftovers |
| game/Support/ (25), 3DSetup/ (3), AutoRun/ (2) | 30 | 5.7 | EReg, uninstall, dicts |
| web/ug2/city_lod.bin | 1 | 27.5 | web/ug2/ug2world.js:91 fallback only when city.bin is absent |
Opened in run 1: game 118 files, ug2 1491, openworld 4. UNKNOWN (opener exists, WORLD never asked; needs the menu/Original run): Cars 47 files 177.7 MB, Tracks 98 files 200.0 MB, Movies 23 files 164.8 MB, SpeechStreams 1 (17.5), SNDSTREAMS 2 (14.4), Sound 91 (21.1), FrontEnd 3 (18.9), Languages 29 (3.4), Global 6 (8.3). No exe literal, UNKNOWN: FrontEnd/TSELECT.BIN 12.3, Global/Street.bin, CHARACTERSA.BIN, Languages/LANGUAGE_*.bin, Labels.bin, Largest.bin.
Opener chain (V = literal + xref, I = inferred): bOpenFile 0x594c60 / queue AsyncRead 0x58aba0 (I) -> EAFile_QueueOpen 0x63a5d0 -> device op 0x6391e0 (call 0x639246) -> EAFile::DeviceOpen 0x63d1c0 -> CreateFileA 0x63d333 / 0x63d37f (V); reads ReadFile 0x63d5b6 (V). Movies: _fopen 0x671541 -> CRT 0x680aa6 -> CreateFileA 0x680c83 (V).
| Family | Opening code (string ref) | When in run 1 | Whole or ranges |
|---|---|---|---|
| fx/*.efx | Effects_CreateAll 0x40e180, bOpenFile call 0x40e2ca | boot 0.5-0.9 s | whole (2-8 KB) |
| Global, Languages, FrontEnd | LoadGlobalA 0x448600, LoadGlobalB 0x448650 (.lzc 0x44865f; .BUN only names the slot 0x44867c), InGame 0x44933c, HUDTEX/DYNTEX table 0x7007b0; Language_LoadTextureBin 0x59f7c0 + table 0x6ee658 (English only); LoadingFrontEndPart1 0x448b10, Road_Segment 0x448adb | boot 1.0-1.9 s; InGameB 11.9 s | mostly whole, 256 KB steps |
| Cars | CarLoader::AllocateSkin 0x58bb50 (TEXTURES 0x58bbdf, VINYLS 0x58bc27); GEOMETRY path string is data in GLOBALB.BUN (offset 1678928); parts table 0x7007a0 | player SKYLINE 2.2-3.2 s; pool + traffic cars 12.0-14.0 s | ranges: GEOMETRY ~3.5 of 5.5 MB, VINYLS 0.3-2 of 16 MB, WHEELS shared pack by offset |
| Tracks | LoadingTrackSpecific 0x4491a0 (TRACKB 0x4497be, STREAM%s 0x44970d/0x44972c, TEX%dTRACK 0x44953e) | STREAML1RA.BUN 15.0-16.2 s (WORLD maps to base track; TRACKB1010 comes from /world/) | ranges: 48.1 of 88.1 MB |
| Sound/*.abk, EVT_SYS/*.csi | EAXAemsManager::Initialize 0x5212e0, SetCurrentBankPath 0x521c80, LoadAemsBank 0x522020 | FE banks 2.0 s; engine/skid/env banks 14.2-14.5 s | whole or near-whole |
| SNDSTREAMS/*.ast | SetCurrentBankPath 0x521c80 (SNDStreams\ 0x521e74, .ast 0x521e4c), probe 0x521b90 | Music_UG0 2.2, 10.4, 17.0, 25 s; AMB_Stereo 16.5, 24.5, 26-37 s | ranges of 256-512 KB: 3.0 of 241 MB |
| SpeechStreams, Movies | 0x521e8b SPEECHSTREAMS\ ; MoviePlayer::BuildPath 0x4f57a0 (ref 0x4f57af) | not requested | UNKNOWN |
| web/ug2 | web/ug2/ug2world.js:68 city.bin, :78 city_tex.bin, :91 bridge, :94 tex.json, :155 tex/*.png | city ready 19.6 s (loads only in WORLD) | whole files |
Not VERIFIED: the real menu path (title, profile, Quick Race), Original mode tracks, other languages, any non-localhost timing or compression ratio of the data files. REA MCP was not available in this session: second tool = Ghidra decomp + objdump (census/ghidra/, pc/Speed.exe).
