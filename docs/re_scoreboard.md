# RE scoreboard: from "it runs" to "we know it" (OWNER 2026-10-29)

Scope: recompile, extract, reconstruct, patch, bridge, and reverse engineer the original game until every system is
accounted for: canon (career, events, movies, text), free tracks, traffic, rivals, tuning, sound, assets, blur, cameras,
props. Publishing is out of this scope (branch `publish` is parked, see HANDOFF.md).

Marks: V = I re-ran it or read the code this session, D = a doc or the ledger says it (not re-checked), U = unknown.

## 1. What is true today (V unless marked)

| Fact | Number | Source |
|---|---|---|
| Function starts in the Hopper export | 14,333 | `census/hopper/funcs.tsv` |
| Lifted to C | 13,739, failed 0, trap sites 7,655 (dead SIMD paths) | `census/lift_report.json` |
| Compared against Unicorn | 5,813 of 13,800; 5,809 match; gate FAIL | `census/difftest.json` |
| Unexplained difftest mismatch | 1 (`0x67a337`); 3 others are documented QEMU deviations | D `docs/coverage.md` §2 |
| Functions with a real name | 52 of 14,333 in funcs.tsv (582 in census/names_*.tsv, 493 V, 2026-10-29) (0.4 %; 31 rows have an empty name) | `awk` over `funcs.tsv`, names neither empty nor starting `sub_` (corrected by the names-seed agent) |
| Active patches | 122 | `census/lift_report.json` |
| Career rows | 167/167, a regression guard only | `census/rows.json` |
| Hopper query scripts | 131 `tools/hopper/q_*.py`, 85 frozen PS2/NFSU1 RE notes in `ref/docs/re` | `ls` |

Reading: the port is a faithful machine translation (lifted + partly diff-tested). What we have *understood* is written in
prose docs and patch comments, not in one registry. There is no file that says "address X is function Y of system Z,
learned with tool T". That registry is the missing instrument, and it is what makes "100 %" measurable.

## 2. What the last OpenCode session got wrong (audit, 2026-10-29)

- **Scope drift.** Asked "how do we publish", it built publishing (branch `publish`, 1 commit, `host/files.c` block
  reader, `tools/serve.py` gzip blocks, `docs/publish*.md`). The OWNER then said "Pausa, no estamos en el paso de
  publicar" and "revierte lo que no te autorice"; the session was interrupted before reverting anything.
- **The coverage counter undercounts.** `host/dispatch.c` sets its bit only inside `rn_call`. The lifter emits direct
  calls as plain C (`f_674898(c);`, `tools/recomp/lift.py:294`); only indirect calls and jumps reach `rn_call`.
  So "1,627 of 13,739 = 11.8 %" and "88 % of the exe has not run" are floors, not measurements. Do not quote them.
- **Number drift between the chat and the doc.** Chat: 95.9 % of 14,333; doc: 95.7 % of 14,354 seeds (adds 24 caves).
  The doc is right. A subagent also said "90 patches / 16 caves"; the table has 122 and the build lists 24 caves.
- **"Coverage" was read as "RE".** Lifted 95.7 % and diff-tested 42 % say nothing about understanding. The honest
  triple is: translated, verified, understood. Only the first is near done.
- **The privacy rule changed on 2026-10-28** (a session removed "nothing is published" from AGENTS.md at the OWNER's
  request). AGENTS.md now says publishing is the OWNER's call. This scope does not publish.

Audited: sessions `ses_e7983eca` (publish), `ses_e79683ee` x2 (the two explore subagents), `ses_e79cd546` (rule and
asset-limit change); `git log/diff` of `main..publish` and the dirty tree; `docs/coverage.md`, `docs/publish_prompt.md`,
`host/dispatch.c`, `web/telemetry.js`, `web/gpu.js`, `tools/recomp/build.py`, `tools/webcheck.mjs` diffs; the census
numbers above re-computed from the JSON. Not audited line by line: `docs/publish.md`, `host/files.c`, `tools/serve.py`
(publish-only), and the OWNER's own play log `build/web.log`.

## 3. The systems, what exists, what is open

Evidence marks are about the docs named; none of these was re-run here.

| System | What exists (D) | Open |
|---|---|---|
| Canon: career, events, text | `q_career*`, `q_eventtab`, `q_evtype`, `q_cevent`, `census/career_oracle.json`; PS2 ledger rows `Q-laps`; 167 rows | OWNER's playthrough depth (U, `build/web.log`); event tables not in a registry; movies: `na_boot.mad` missing, patched around (`0x4f5891`); 23 VP6 movies |
| Free tracks / city | `re_zones`, `re_stream`, `re_coll`, `re_mesh`, `re_citygraph`, `tour.md`; 16 street TRACKB, 101 streamer polygons | invisible walls (PLAN Now 3), orphan stubs, city net lane bytes |
| Traffic | `traffic_placement`, `openworld_e_re` (section B weak), `re_traffic_teleport`, `re_traffic_racers` | odd placements 122/301, group spread, JDM skins, race-mode placement |
| Rivals | `re_rivals_ai`, `re_racer_cap`, `re_rival_personality`; 6 rivals default | personalities not driven by the game's data; PS2 `Q-ai` is U |
| Tuning (parts, garage, physics) | tuning block `0x705f48..0x705f84`, speed caps `0x583ea0`, driver `0x5a6ef0` "run as shipped" (`driving_patches.md`); PS2 physics rows | weakest on PC: 2 patch mentions, no PC doc for parts/upgrade tables |
| Sound | `re_audio_default` (sliders, `0x4aa200`), ABK code lifted (`abk.py`, 106 files), dsound -> Web Audio | no PC doc for ABK/AST formats, mixer, speech streams, music selection |
| Assets | TRACKB/`.lzc` parsers (`tools/openworld`), `census/game_files.json` (every referenced file exists), `TEXTURES.BIN` | no single container spec (BUN, BIN, LZC chunks) for PC; ids of chunks live in scattered docs |
| Blur | `q_blur`, `q_fxblur`, PS2 ELF reference | `PS_FAR = 200` and W/512 offsets are guesses (PLAN Earlier 1) |
| Cameras | `re_jumpcam` (modes by strings, why Free Run misses JUMPVIEW) | other camera modes, chase/bumper/hood parameters, replay cameras |
| Props | `re_props`, `census/openworld_props.json` (77 classes, 1,122 instances) | behavior of non-smackables, reset/respawn of props |

## 4. Path to a number (each step has its own check)

1. **Make the counter honest.** Instrument function *entry* in the lifter behind `RN_COV=1` (like `RN_PROF`), so direct
   calls count; one store per call, off in normal builds. Check: a run where the count of a known direct-call chain
   (e.g. `0x674898` under its caller) is non-zero while `rn_call` never saw it.
2. **Union of what ran.** Run it over the 282 census runs and the OWNER's sessions; keep `census/cov.bin` (one bit per
   function). Check: title-screen run is a subset of the race run.
3. **Tag every function with a system.** Roots by string xrefs (REA `search_strings` -> `xrefs` ->
   `resolve_containing_procedure`), then call-graph closure, then the docs' addresses. Output `census/systems.tsv`
   (addr, system, how). Check: sample 50, 45 or more agree on a manual read.
4. **Names ledger.** `census/names.tsv`: addr, name, system, tool that produced it, doc. Seed it from the addresses
   already written in docs, patch comments and `q_*.py` (grep `0x[0-9a-f]{6}`), then from the PS2 ELF analogs.
5. **Work down by system**, in the order the OWNER feels it: cameras and blur, tuning, sound, assets, then the rest;
   each finding names its tool; a bridge or patch only after the code is read.
6. **Scoreboard script** `tools/census/scoreboard.py`: per system, functions, lifted, ran, named, diff-tested.
   "100 %" per system means every function is tagged, every function that ran is named or marked trivial, and every
   one that never ran is proven dead (SIMD path, online, installer) or has a scenario that reaches it.

## 5. Four numbers per system (tools/census/scoreboard.py, 2026-10-29 09:20, V)

Universe = the 13,739 lifted functions. tagged = systems.tsv (draft: ~12% of tags wrong in a manual read, see docs/re/systems_method.md); ran = RN_COV union, a floor (prologue only); named = census/names_*.tsv (V = second tool agrees); diff-tested = U per system, difftest.json keeps only the total (5,813 compared, 5,809 equal).

| system | lifted | tagged | ran | named | named V | diff-tested |
|---|---|---|---|---|---|---|
| render | 2243 | 2243 | 949 | 32 | 22 | U |
| canon | 2056 | 2056 | 682 | 123 | 107 | U |
| runtime | 1771 | 1771 | 716 | 33 | 28 | U |
| unknown | 1560 | 0 | 905 | 35 | 28 | U |
| audio | 1299 | 1299 | 789 | 178 | 167 | U |
| rivals | 1085 | 1085 | 604 | 79 | 58 | U |
| car | 964 | 964 | 335 | 140 | 119 | U |
| track | 792 | 792 | 449 | 130 | 106 | U |
| online | 691 | 691 | 28 | 2 | 2 | U |
| hud | 354 | 354 | 178 | 26 | 20 | U |
| camera | 261 | 261 | 79 | 24 | 14 | U |
| traffic | 197 | 197 | 140 | 48 | 29 | U |
| props | 183 | 183 | 103 | 28 | 20 | U |
| assets | 154 | 154 | 46 | 7 | 7 | U |
| input | 129 | 129 | 35 | 1 | 1 | U |
| TOTAL | 13739 | 12179 | 6038 | 886 | 728 | 5813 (no split) |

Reading: "unknown" is the untagged remainder. Named is still low in every system; audio, car, rivals, traffic, props, canon and camera moved during the night block. Ran is 44% overall.
