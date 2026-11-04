# Night brief (OWNER 2026-10-29): RE of NFSU toward 100 %, frozen contract

Orchestrator: session `angeldamian-36` (Sonnet 5.5). Windows: `night-opus-a` (acct 5), `night-opus-b` (acct 3, starts when its 5 h resets).
Workers: `sonnet-exec` (RE, tools, implementation of a decided plan), `haiku-mechanic` (batches, counts, runs).
Opus does diagnosis and design forks; if a step fails twice it goes to an Opus window, not to a third try.

## Frozen (only the OWNER changes these; a worker that wants to must stop and say so)
1. Scope: reverse engineer Speed.exe system by system, read-only on game behavior. No patches in tools/recomp/patches.py, no
   behavior change in host/ or web/, no publishing, no online. Branch `publish` stays parked.
2. Systems: canon, track (free tracks, world), traffic, rivals, car (tuning, physics, garage), camera, render (blur,
   lights), hud, audio, assets, props, input, runtime, online (out of scope), unknown.
3. Denominator: the 13,739 lifted functions (+28 ABK functions listed apart). It does not change to make a number look better.
4. Four numbers per system, always together: tagged (census/systems.tsv), ran (union of census/cov, entry-level),
   named (census/names.tsv, evidence V, confidence med or high), diff-tested (census/difftest.json). "100 %" for a system
   means: all its functions tagged; every one that ran is named or marked trivial with a reason; every one that never ran is
   proven dead (SIMD path, online, installer) or has a scenario that reaches it.
5. Evidence marks: V read in code or bytes, I inferred, U open; each row names the tool. A name without V stays I.
6. Rules: AGENTS.md. game/ and ref/ read-only; every run bounded; disk nearly full; git add exact paths; no Ghostty or
   extra terminals; kill only your own processes.

## Morning deliverables (what the OWNER finds, in this order)
M1. Honest coverage: `RN_COV=1` build, union over about ten scenarios, `census/cov/*.json` + `docs/re/coverage_method.md`.
M2. `census/systems.tsv` (every lifted function tagged, with confidence and evidence) + method doc, 50-sample agreement.
M3. `census/names.tsv` merged from names_seed + names_<system>.tsv, with counts V/I/U.
M4. RE docs, answer first, V/I/U: `docs/re/{tuning,sound,assets,canon,camera,blur}.md`, plus read-only readers under tools/re/ where a format is decoded.
M5. `tools/census/scoreboard.py` and the table in docs/re_scoreboard.md with the four numbers per system.
M6. `docs/re/proposals.md`: patches or bridges the RE suggests (address, effect, risk, switch name). Proposed only, none applied;
    the OWNER approves in the morning. Plus HANDOFF.md (≤30 lines) and one commit per block on main.
Stretch if time and quota remain: props, traffic, rivals, free tracks deepened into the same four-number format.

## Communication
Workers report to the orchestrator in few words at: deliverable done, big finding, blocked/2 failed attempts, ~90 min status.
Windows use SendMessage to `angeldamian-36` (fallback: docs/re/night_log.md). The orchestrator reviews every deliverable
against its "done when", merges, commits, and keeps docs/re/night_log.md as the single timeline.

## Stop conditions (everything halts and waits for the OWNER)
Scope drift (publishing, patches, features, a different project); a change in game behavior; main stops passing
`node tools/webcheck.mjs --route`; a worker edits a frozen item. (Quota at 92 % is not a stop: AGENTS.md "Close" — commit, HANDOFF.md, `claude-acc relay check`, relay.)

## Tools (REA skill applied)
REA MCP on pc/Speed.exe (open_binary, procedure_pseudo_code, xrefs, search_strings, resolve_containing_procedure,
build_reconstruction_obligation_ledger / evaluate_reconstruction_coverage for the "100 %" ledger, export_evidence_bundle
to build/rea/ so findings keep Evidence IDs); REA CLI ~/RE-NFSMW/tools/rea/rea.sh for workers without MCP; Hopper in many
background windows via tools/hopper/hpar.sh (30-min demo cycled by the script); Ghidra headless tools/ghidra/gpar.sh;
capstone tools/recomp/asm.py; census/hopper/decomp.c; Unicorn difftest; native off-screen runs to confirm a value whose
address is already named. Same-game references in ref/docs/re (PS2 addresses differ) and the x86<->PS2 map found by
night-opus-a (324 tuning name candidates, to be verified, not trusted).
