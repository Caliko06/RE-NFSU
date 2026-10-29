02:46 night-opus-a: tuning+sound docs and readers (b7f006d) verified by orchestrator: carinfo 1435/1435 tables + 4537/4537 parts byte-equal, ast/abkbank 100% byte coverage. Refutes: 0x583ea0 is a generic table lookup, 0x705f48.. is steering-vs-speed (0x460a80), not tuning. Next A: names_*.tsv, corrections list, proposals, garage UI + engine sound model.

## HANDOFF night-opus-a (context 250k, 02:47)
Done (commits b7f006d, 6a2f672): docs/re/tuning.md (data chunk 0x34600, upgrade builders, NOS, part DB, unlock rule,
corrections table), docs/re/sound.md (files, name resolver 0x521c80, music picker 0x53c3a0), docs/re/proposals.md,
readers tools/re/{carinfo,ast,abkbank}.py (each has a 'check' that passes).
In flight: two sonnet-exec agents verifying name candidates; outputs land in
/private/tmp/claude-501/-Users-angeldamian-RE-NFSU/692cb4a3-bc35-4d3e-9294-0f15ec19b3de/scratchpad/names_tuning_agent.tsv and /private/tmp/claude-501/-Users-angeldamian-RE-NFSU/692cb4a3-bc35-4d3e-9294-0f15ec19b3de/scratchpad/names_sound_agent.tsv (inputs tune_c2.tsv, snd_c2.tsv in the same dir).
Next, in order: (1) census/names_tuning.tsv + census/names_sound.tsv from those files: re-derive 10 sampled names per
system with the other tool (Ghidra gpar vs census/hopper/decomp.c) and mark V only where both agree; (2) garage UI flow
(GarageMainScreen / ChooseGaragePerfPath / GaragePerfTuner -> RideInfo spec writes); (3) engine-sound model: which field
picks Car_n (request +0x3c) and Eng_UG_n (+0x40) for classes 0xc/0xd in resolver 0x521c80, then RPM -> pitch/volume in the
ABK engine module (tools/recomp/abk.py). Open U items are listed at the end of each doc.
02:48 heartbeat: A busy; cov/systems/cam agents running (coverage_method.md and systems.tsv drafts exist); B waiting for acct 3 reset (03:19). Acct 5 at 68% session / 79% week: no new subagents until B is up; A told to cap at 2 subagents and hand off at 88%.
Agent TSVs: /private/tmp/claude-501/-Users-angeldamian-RE-NFSU/692cb4a3-bc35-4d3e-9294-0f15ec19b3de/scratchpad/names_sound_agent.tsv (212 rows, done) and /private/tmp/claude-501/-Users-angeldamian-RE-NFSU/692cb4a3-bc35-4d3e-9294-0f15ec19b3de/scratchpad/names_tuning_agent.tsv (pending); V marks need a 10-sample second-tool check.
02:51 M1 done: RN_COV union 6,038/13,739 (43.9%); flag-off gen md5 07b9d06a unchanged; commit 40caf0b. Floor only (prologue, no later events).

## Leads from night-opus-a for night-opus-a2 (tuning names, 244 rows: 206 V / 37 I / 1 U; 14 disagree with the map)
Raw agent TSVs are kept in census/names_raw/ (names_tuning_agent.tsv, names_sound_agent.tsv); not yet merged, V marks need the 10-sample second-tool check.
- 0x5044b0 GarageManager::InstallPart; 0x57f700/0x57f970 MatchPerformance overloads (swapped in the map); 0x473fc0 drift/drag row pick (not GetUpgradeLevel); 0x4af140 GarageCarLoader::Update.
- Price: GetCarPartCost 0x5a08f0 reads [0x733f78+type*4], cost at +4/+8/+0xc by part level.
- Cash career+0x1374 (career 0x75eef8); bought parts store 0x75f344; IsUpgradeUnlocked 0x5a1550 needs career+0x34c+stage==2; path->type 0x5a0350; junkman table 0x6fad60.
- FECarConfig spec at +0x2e0, written by InstallPhysicsUpgrade 0x5047d0.
03:2x night-opus-a2 (angeldamian-36 not reachable by SendMessage; logging here): started. Names: automatic Ghidra<->Hopper
address cross-check confirms 136/200 sound V and 137/206 tuning V rows; sonnet-exec checks 10 samples/system + the 133 rest.
Big finding: tuning.md "No prices" is wrong: cost table chunk 0x34a01 (FrontB.lzc) -> [0x733f78+type*4], cost[lvl1..3]
100..4000, points +0x10..+0x1c; readers 0x5a08f0 / 0x5a05f0; cash [0x76026c]. Garage flow with a sonnet-exec; A2 on sound U items.
03:29 night-opus-b: up (assets+canon); angeldamian-36 not reachable by SendMessage, logging here. V: chunk dispatcher 0x447ac0 + 47-loader table 0x7007e0 (unload 0x7008a0); tools/re/chunks.py check (235 files tile, 116 ids); LZC = JDLZ, byte-equal to BUN twins; tools/re/lang.py (22 files repack), tools/re/events.py (116/116 repack). 3 agents: loaders A/B, save format.
03:4x night-opus-a2: deliverable (1) done, 9fc13da: census/names_sound.tsv 199 V/13 I, names_tuning.tsv 205 V/38 I/1 U; V only with Hopper agreement (auto address check + sonnet semantic check of 133 rows + 10 samples/system: 0 disagree). sound.md §5 (engine patch node graph, FE speech table) written, not committed yet.

## HANDOFF night-opus-a2 (block done)
Done: 9fc13da names_sound.tsv (199 V/13 I) + names_tuning.tsv (205 V/38 I/1 U), V only with Hopper agreement
(tools/census/names_xcheck.py + semantic check, 0 disagree). 5103257 docs/re/garage.md (screens, part list, prices,
purchase, preview/cancel, save), sound.md §5 (engine Csis params 0x52bf70, ENG patch node graph, FE speech 0x6f8728),
tuning.md "no prices" corrected, 5 proposal rows. angeldamian-36 was not reachable by SendMessage; this log is the report.
Next, in order: (1) reader tools/re/csiscurves.py: dump the ENG patch curve records (RPM -> pitch/volume per loop);
(2) garage.md Open 3/4/7 need one bounded run each (engine-bay slot after reload, cash after career beaten, reload of a
bought part), test profile only; (3) speech: who plays the ~270 non-FE lines; (4) census/names.tsv merge (M3) of
names_sound/tuning with seed/blur/camera.
Not mine (dirty, untouched): census/lift_report.json, docs/openworld/re_answers_0b.md, untracked census/names_{blur,camera}.tsv,
census/systems.tsv, docs/re/blur.md, tools/census/sys*.py, tools/hopper/q_*.py, docs/re_*.md.
03:43 night-opus-b: save format done (tools/re/save.py, 9 files re-pack, Adler-32 0x41dd10; block 0xf660 from player 0x7588c4); canon.md + names_canon.tsv (46 names) + names_assets.tsv (26) committed de61702. Waiting on loader meanings A/B, EventDesc unknown fields.
07:01 orchestrator back after account-5 5h limit (03:0x-07:00): subagents a6d97/a2d5c died on 429 and were resumed at 07:01; B and a2 delivered de61702/5103257/9fc13da then hit account 3 limit; relay hook ignored (Ghostty forbidden, session now 0%).
07:04 M2 systems (146c21f), M3 names.tsv (8a50517), M4 camera+blur (bd5fa4f), M5 scoreboard (677289f) committed by the orchestrator; HANDOFF rewritten. B and a2 resume 08:20. Next: props/traffic/rivals only on account 3.
07:17 heartbeat: nothing running; webcheck --route PASS (needs tools/serve.py up); account 5 week 85% so no subagents; B and a2 resume 08:20. tools/re/tpk.py untracked (b/a2 work in progress).

## HANDOFF night-opus-b (2026-10-29 ~08:45, after the quota reset)
assets done: docs/re/assets.md (pipeline, TPK layout, 137 chunk ids: 94 V / 22 I / 21 U), census/names_assets.tsv
(187 names: 171 high / 15 med / 1 low), readers tools/re/chunks.py (LOADERS fixed: loader 2 takes 0x34130..4 via
0x441380, loader 4 0xb3300000/0xb3320000/0xb0300100, loader 18 0x34492 + 0x80034405..25; every top-level id has a
loader) and tools/re/tpk.py (check: 347 packs, 27,458 textures, 0 bad; JDLZ streams hold pixel..palette range).
canon done: EventDesc unknowns resolved in docs/re/canon.md (+0x18 min ride rating, +0x1c target times, +0x34 URL
league/rank, +0x130 host, modes 0..5 named, kinds 0/1/2/3/6/8, reward queries 0x5a1550/0x5a1630/0x5a16f0, 0x34a01 =
prices + rating points per part category); census/names_canon.tsv 69 names. Second-tool check 10/10 in both docs.
Open (U): 0x33310003 consumer, event kinds 4/5, reward type 4, 0x34a07, 0x3a000, rival +0x18 byte; save block U rows.
angeldamian-36 not reachable (ListAgents shows only night-opus-a2).
08:49 night-opus-b: got the orchestrator's props/traffic/rivals block (typed in this window); traffic and rivals agents running, props by me.
08:50 night-opus-b: props done: docs/re/props.md, census/names_props.tsv 28 names (19 high V H+G, 9 med/low I), 10/10 second-tool agree. Corrections to re_props.md: 8 placed classes have a release limit > 0 (not 1), 44 classes unused (not 41). Respawn 0x5977f0: Virgin rebuilt after 2.0 s at rest.
08:51 night-opus-a2: (1) done d63dc41: tools/re/csiscurves.py (check: 32 ENG/EXH patches, 864 curves), sound.md §5 curves table; 4 voice chains (not 3); Csis param->patch input map U (SND dispatcher between 0x52bf70 and the patch).
09:01 night-opus-a2: (2) e5cb5ae answered by reading (no run): reload restores career block byte for byte (0x41da40->0x4ab200); engine-bay slot 12 missing in garage after reload (save bytes agree); FINDING for OWNER: our patch 0x735ec1=1 makes 0x5a1520 return cash 1e9, purchases drive cash negative (asas0.ugd -9875); proposal ?cash=real. Runs not done: they would write save/ (OWNER's), needs a scratch save root first.
09:02 night-opus-a2: (3) c176f74 speech: all 277 lines via 0x51c830 + FE callers, 95 events (0x6f6bc8), random line per event, 259 reachable, no race caller (scan of +0x90/+0x98 sites); STRM_English_Speech abk is only a stream directory.
## HANDOFF night-opus-a2 (second stretch done)
Done since cfb7c63: d63dc41 tools/re/csiscurves.py (curve dump, check passes); garage.md §7 (reload, slot 12, negative
cash); sound.md §6 (speech). (4) names_merge.py not rerun: no new names_*.tsv this stretch.
For the OWNER (morning): our patch 0x735ec1=1 (everything available) also disables the cash check via 0x5a1520, so
garage purchases drive cash negative (asas0.ugd -9875). Proposal row `?cash=real` in proposals.md; their call.
Next: (a) map the Csis params to patch inputs in0..in17 (read the SND dispatcher between 0x64bc30 and the patch, or
one bounded RN_WATCH run); (b) any garage run needs a scratch game dir whose ../save is not the repo save/
(host/files.c:30; a symlinked game/ dir resolves .. to the repo) — build a dir of per-entry symlinks + copied saves;
(c) listen/label the 95 speech events.
09:05 night-opus-b: rivals done: docs/re/rivals.md, census/names_rivals.tsv 28 names (20 V / 8 I). Spawn 0x4b5df0 -> 0x4b4040 -> 0x4b26f0 preset; 303/313 rivals match the player's rating (-1); rubber band 0x44bd10 every 0.3 s, strength EventDesc +0x12c; AI clock 4000 ticks/s; direction is one global 0x78a2fc.

## HANDOFF night-opus-b (2026-10-29, props/traffic/rivals block closed)
Done: docs/re/props.md + names_props.tsv (28), docs/re/rivals.md + names_rivals.tsv (28: 20 V / 8 I),
docs/re/traffic.md + names_traffic.tsv (120: 67 V / 49 I / 4 U). Each doc has a 10-name second-tool section.
names_merge: 1039 addresses (819 V / 198 I / 22 U). Scoreboard named V: rivals 58, traffic 29, props 20.
Key facts: smackable respawn 0x5977f0 (2.0 s at rest); rivals match the player's rating (303/313), rubber band
0x44bd10; traffic has no spawner, cars are moved by teleporter 0x598600 (0.3 s route / 1.0 s Free Run), 6 models.
Open: see each doc's Open list (traffic: writer of [ebx+0x59d4], Free Run x1.5, intersection states; rivals:
42 floats 0x77a358..0x77a3ff unread, quick race S=0; props: smack type +0xd8 consumer).
09:20 heartbeat: b delivered props/traffic/rivals (7340114, 9339318, db85f89), a2 csiscurves/garage §7/sound §6 (d63dc41, e5cb5ae, c176f74); csiscurves re-run OK (needs .venv/bin/python); scoreboard named 886 (728 V), names.tsv 1039. Account 3 session 69% at 09:17: both windows told to stop at 90%.
09:47 heartbeat: B and a2 idle (no commits since 4accc2e); OWNER asked for a full reconciliation: external Opus auditor + 2 haiku (names ledgers done: 12 V/V alias conflicts resolved by file order, 143 non-function rows, 7 camera field rows dropped by merge; numbers re-run pending). Account 5 session 17% / week 86%. No stop condition.
10:30 reconciliation done: external Opus audit (24 claims: 21 ok/2 refuted/1 open), recon names (12 V/V alias clashes, 7 field rows, 143 non-function rows), recon numbers (18 ok/1 differs/3 no command). Fixed: props loader index, garage 11 paths, stale no-prices refs, 0x5a1520 third flag, units marked I, 137 vs 116 chunk ids explained, scoreboard name-overrides-tag (tagged 12,179 -> 5,402), names.tsv aliases+kind, cov bitmaps kept, difftest writes compared_funcs. Reports in docs/re/audit/.
10:20 heartbeat: B and a2 idle; running full difftest (pid 38723, 55 min cap, old json saved in scratchpad difftest.before.json) so diff-tested gets a per-function list; sonnet-exec rechecking V names with one tool (v_recheck.tsv). Account 5 session 24% / week 87%. No stop condition; webcheck not needed (no lift.py/host change).
10:33 deliverable: tools/verify_re.py (9 reader checks + 31 exe claims, ALL PASS) and docs/re/RESULTS.md. Difftest rerun 8 cases: 5,798 compared, 5,794 equal, gate FAIL on 0x67a337 (unchanged, known) + 3 QEMU deviations; scoreboard diff-tested now real (5,781). V recheck: 328 one-tool V rows, 259 hold / 69 inconclusive / 0 contradicted.
10:43 0x67a337 diagnosed by an independent Opus: real lifter gap (negative-index jump table in CRT memmove 0x672630 and copy 0x678d30; Lifter.table() reads forward only). Not applied (changes lifter output); proposal row in proposals.md, docs/coverage.md row updated, evidence in docs/re/audit/diag_67a337.md + mm_probe.py.
10:48 heartbeat: account 5 week 90% (stop at 92%): stopped the V-name recheck agent (low value), kept the track agent; 0x67a337 closed as a lifter gap (7a02411). If the week hits 92% everything halts; resume in a Terminal.app window on account 3 (week 36%).
10:49 track done (sonnet-exec): docs/re/track.md + names_track.tsv 62 names (48 V), 10/10 second-tool; names.tsv 1,101 addresses; scoreboard named 948 (776 V). OWNER lifted the 92% quota stop (message at 10:5x): continue past it.
11:04 hud+input (108 names, 73 V; docs/re/hud_input.md) and runtime (126 names; docs/re/runtime.md) done and merged: names.tsv 1,335 addresses, scoreboard named 1,180 (938 V). V-recheck of 69 inconclusive rows still running. verify_re.py 35 claims ALL PASS.
11:07 V-name recheck of the 69 inconclusive rows read by hand: 66 hold, 2 corrected (0x700b44 -> SpecialCamModeTable I, 0x549130 -> EAXMod::NopArg1), 1 still open (0x537460 now I). Wave-2 coverage (10 scenarios) running.
11:14 wave-2 coverage done: 22 scenarios, union 6,067 (44.2%, +29). drag2 (track 1203) stops at d3d9 Present with rects/window.
11:19 heartbeat: nothing running; all workers finished and verified. Timestamps of lines from 10:33 to 11:14 corrected to the commit times (earlier I wrote them ahead of the clock). Account 5: session 87%, week 95% (OWNER lifted the 92% stop). Open: OWNER decisions in HANDOFF.md; lifter gap and drag2 host gap are proposals.
12:01 heartbeat: account 5 5h window reset (session 0%, week 97%); the three agents (render, gameflow, unknown bucket) died on 429 at ~11:25 with no output and were resumed. Relay hook ignored again (no Ghostty; session is at 0%). scoreboard.py now reads census/systems_override.tsv.
12:15 unknown bucket (601 hand-read, census/systems_override.tsv, names_misc 67) and render (84 names, docs/re/render.md) verified and merged: names.tsv 1,649; scoreboard named 1,464 (1,094 V), tagged 6,160; verify_re --quick ALL PASS. Gameflow worker still running.
12:25 gameflow done and merged (163 names, 123 V; state handlers 1..8 at [0x77a920] re-checked with capstone; docs/re/gameflow.md). Next: classify remaining unknown, close Open items.
13:12 canon wave round 1 (canon-sonnet): render/runtime/canon 60 rows each; named 1,464 -> 1,644; 106 apply failures (mid-function .part_ addresses in queue)
13:31 canon wave round 2 (canon-sonnet): render 60, runtime 59, canon 59; named 1,644 -> 1,822; queue excludes 888 fragments
13:50 canon wave round 3 (canon-sonnet): sound 58, car 60, rivals 60; Hopper second reading of 113 low rows (86 agreed->med, 1 renamed); 3 side fixes; named 1,822 -> 2,000
14:07 canon wave round 4 (canon-sonnet): hud 59, camera 57, track 58; named 2,000 -> 2,174; gcalign + queue rerun
14:20 canon wave round 5 by GC file (canon-sonnet): PartsBrowser 60, CameraMover 59, AIAction family 49; 5 corrections; named 2,174 -> 2,343; anchors 657
15:13 canon wave round 6 by GC file (canon-sonnet-c1): AIPlan 49, PartsBrowser 60, CameraMover 59; Hopper 65/77 low rows agreed; 2 corrections; named 2,343 -> 2,511; anchors 788
15:24 canon wave round 7 by GC file (canon-sonnet-c1): EAX3DS 60, FEngInterface 60, FEPkg_PostRace 60; named 2,511 -> 2,691; anchors 921
15:34 canon wave round 8 by GC file (canon-sonnet-c1): CollisionBody 60, RaceParameters(Race) 60, FEPkg_MU_Options 60; named 2,691 -> 2,871; anchors 1,032
15:45 canon wave round 9 by GC file (canon-sonnet-c1): InfoDialog 60, saems 60, FEPkg_Hud 60; see scoreboard
15:49 corrections after round 9: 8 rows (collision vtable slots, Race, cFEng/FEngine)
