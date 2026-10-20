# W1: orchestrator (Opus), repo ~/RE-NFSU, branch main, port 5180
Read AGENTS.md, HANDOFF.md, docs/PLAN.md. You own main, the recompiler (tools/recomp), the gate and the plan.

## Every session
0. Before any lane starts a new scope: data check (strict rule 2). Ask the OWNER once, yourself.
1. Reconcile: for each lane branch with new commits (w-d3d9, w-win32, w-census): read its diff and its HANDOFF
   lines, merge with `--no-commit`, resolve overlaps (two lanes may add the same API: keep one, documented version),
   delete every STANDIN(<lane>) the owner lane replaced, build native + web, run the gate if tools/recomp or host/rt.h changed, one native --shot and one Chrome run.
   Commit only if the run matches what the lane reported. Then the lane merges main back (say so in its brief).
2. Work your own blocks back to back (PLAN.md): lifter bugs found by lanes, performance for M6, the PATCH table,
   widescreen M8. Update PLAN.md (done / next) and HANDOFF.md (replace, max 30 lines).
3. When a lane finishes its brief, rewrite its brief with the next scope from PLAN.md and give the OWNER the
   one-line prompt to paste (below). Mechanical batches -> rewrite docs/briefs/c1-codex.md.

## Prompts the OWNER pastes (one per session; briefs live on main, so each lane merges main first)
- W2: `En ~/RE-NFSU-wt/d3d9 haz git merge main. Luego lee AGENTS.md, HANDOFF.md, docs/PLAN.md y docs/briefs/w2-d3d9.md. Haz el brief completo.`
- W3: `En ~/RE-NFSU-wt/win32 haz git merge main. Luego lee AGENTS.md, HANDOFF.md, docs/PLAN.md y docs/briefs/w3-win32.md. Haz el brief completo.`
- C1 (Codex): `Work in ~/RE-NFSU-wt/census. First run git merge main. Then read AGENTS.md and docs/briefs/c1-codex.md. Do the brief, commit on w-census.`

## Rules that matter here
- No subagents. You do the work; parallel work is the lanes.
- A lane result that does not reproduce in your one run is not merged; write why in its brief.
- Keep main green: native build, web build, gate pass, the game reaches at least the stop HANDOFF.md names.
