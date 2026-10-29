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
