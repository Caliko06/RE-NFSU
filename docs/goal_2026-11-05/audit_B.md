# Audit B: process lens (2026-11-05). Facts are from files/commands I ran; NV = not verified.

## 0. Verdict in 6 lines
- The expensive part was never the hooks. It was (a) 10-29..10-31 naming/census/pod/visual-lane waves and (b) the 11-05 audit loop.
- Visible product yield by day (git log since 10-29, 266 commits): 10-30 = 96 commits, 10-31 = 41, then 13, 3, 46, 23, 17.
  10 commits are reverts after "OWNER: ugly / worse / looks bad" (halo, AO, tonemap, render quality, light streaks, chase cam;
  823e7d4 reverted ALL game code to f12a150). Visual lanes built blind, not played, then thrown away.
- Real wins came when a measured loop met a play check: 11-03/04 WORLD (BeltMover off: 93 jumps -> 0; traffic stopped 63% -> 38%).
- 11-05: 17 commits, 22 commits since 10-29 say "audit"; none visible to the OWNER and "built not run" (game runs were paused).
  The audit found 27 confirmed / 14 partial / 0 refuted: it was not wrong, but it produced hardening (handle table, md5 boot
  check, seal) before the product goals (Safari, touch, 60 fps/0 hitches) had a single line of code.
- Rules that block work: budget 400 (25 of 124 sessions needed a manual "budget +N"), 60-min unattended rule vs worker windows,
  runcap 30 per OWNER message (workers get no OWNER message), Becario 5-step gate, stale memory that contradicts AGENTS.md.
- Rules that earned their keep: macgate (Jetsam kills 10-25), chrome-guard (Dock Chrome hijack 10-26), bounded waits/outputs
  (14 GB trace, 8 h build), md5/read-only game/ref, no-kill-others.

## 1. Rule / hook table
Cost = calls, wall, blocked work, context. Evidence = what it prevented.

| # | Rule / hook | Cost | Prevented (evidence) | Verdict | Conf |
|---|---|---|---|---|---|
| 1 | spend-guard budget 400 calls/session, subagents included | 124 sessions seen; 4 reached 400; 25 needed an OWNER "budget +N" (one reached 943, ext 800). SCOPE_2026-11-04 had to open with "budget +400". Each stop = OWNER typing | 2026-11-02 night (46% of tokens on unasked work) - but that is rule 3's job, not this one | CHANGE-TO CALLS=3000 (one orchestrator day ~1500-2000 incl. subagents) | 75 |
| 2 | spend-guard 3 Claude subagents/session | 3329 sonnet + 198 opus + 119 haiku subagent calls in the window: the cap is already routed around (Becarios, windows). Blocks fan-out in the one session that integrates | cost control on Claude subagents (31% of all calls were subagents) | CHANGE-TO AGENTS=8 (windows and Becarios are not counted anyway) | 65 |
| 3 | spend-guard unattended: 60 min without OWNER prompt -> only WORKLIST `#N`; bypass max 12 h | A worker window opened with no prompt is unattended at minute 0 (memory agency-windows); a one-day run needs 2 bypass grants; every delegation must cite `#N` | the night of waste; real and still valuable | CHANGE-TO IDLE_MIN=240, BYPASS_MAX_H=24. Keep WORKLIST rule | 70 |
| 4 | spend-guard 3 worker windows (cwd in `*-wt/`) | `ps`+`lsof` per launch only; none | OWNER-set cap, matches the new model | KEEP 3 | 90 |
| 5 | spend-guard writes bypass.json only from human prompt | none | model self-granting | KEEP | 95 |
| 6 | runcap.py: 30 game/Chrome runs per OWNER message (was 1 -> 5 -> 30) | counter resets only on UserPromptSubmit: windows that only receive SendMessage get 30 for the whole day (NV: whether SendMessage fires the hook). Each raise (1->5->30) shows the cap tracks nothing | 7 of 21 runs in session 28d14248 were failed headless trips - that is retry loops, a behaviour rule ("one failed repro = stop") not a count | CHANGE-TO 100, and keep the reset. Real brake stays macgate + RN_SECS | 60 |
| 7 | macgate.sh (free mem >= 20%, 10 s settle) | ~10 s per launch, serial; `macgate.sh && cmd` footgun (memory macgate-no-exec) | JetsamEvent 2026-10-25 06:12 killed runs; 2 kernel panics 10-23 | KEEP | 90 |
| 8 | macbench.sh machine-wide bench turn | holds EVERY launch of every window up to 10+30+10 min | invalid benches (load ~11) | KEEP but only for the final p99 gate in block 4; never in lanes | 80 |
| 9 | chrome-guard.py (no real Chrome automation) | negligible | Dock Chrome windowless (10-26) | KEEP. Add nothing for Safari | 90 |
| 10 | block-dangerous-cmds.sh (push, reset --hard, clean -f, pkill, killall) | **not registered**: grep of ~/.claude/settings.json and the repo settings.json finds no entry, so it protects nothing | AGENTS "kill only your own" / no push rely on prose only | CHANGE-TO register as PreToolUse Bash (see 4) | 75 |
| 11 | mac-guard.py (RN_JOBS caps) | file exists, unregistered since 10-27 (its own header says removed) | 2 panics 10-23 (now covered by macgate) | CUT (delete file) | 90 |
| 12 | context-guard.py: relay at 250k ("open a new slice window") | PostToolUse on EVERY tool call re-reads a 4 MB transcript tail until the flag exists; the nudge contradicts memory same-session (OWNER 11-05: "todo se ejecuta en esta sesion") | nothing: OWNER overrides it | CUT the relay half and the PostToolUse entry; keep the 600-char scope.md anchor on UserPromptSubmit | 85 |
| 13 | nfsu1-context.sh injects HANDOFF.md at start | ~13 lines | cold start in 1 read | KEEP | 90 |
| 14 | dash-pin.sh, mp-context.sh, vc-context.sh | ms; other projects | n/a here | KEEP (out of scope, harmless) | 80 |
| 15 | kgrun.sh (Kaggle pull) | unregistered, unused; pods parked/dead (38 commits mention pod, 30 are merges from pod lanes) | 10-24 pod loss | CUT (move to ~/.claude/hooks/old/) | 85 |
| 16 | spend-guard.py.bak | clutter | none | CUT | 95 |
| 17 | Becario 5-step approval gate (SCOPE 11-04 s5): full diff read + REA check of every address + nacho review + cherry-pick + ghost vs baseline | every Becario diff = 3-4 more calls plus a 1-30 min ghost; ~12 Becario worktrees exist (beto..yoli) | forbidden-path writes; wrong addresses (14 of 41 audit findings were only "partial") | CHANGE-TO: script check of paths (`git diff --stat`), build, ghost only if the diff carries a number or is "dangerous"; nacho review only for dangerous | 70 |
| 18 | "Dangerous = shared physics/collision, deletes, build scripts, no number" | none | OWNER's own test-threshold list (matches) | KEEP, it becomes THE test rule | 85 |
| 19 | "Nothing a Becario returns is a fact until REA/Hopper confirms" | one REA call per claim | wrong naming claims | KEEP for address claims that become patches; drop for docs/prior art | 75 |
| 20 | Stop rule: 4 attempts per cause | none | the 4 h "feel" session that worsened handling (work-style) | KEEP | 85 |
| 21 | AGENTS: "No effect/feel change on by default until OWNER approves" + 11-04 exception | exception already makes remaster defaults replace; two rules for one fact | 10 reverts show OWNER taste is the only judge | CHANGE-TO one line: remaster/WORLD defaults change, one commit each; original = reference, perf fixes + RN_UNLOCK only | 85 |
| 22 | AGENTS: "Several problems: slices each with own number, patch, ghost" and "HANDOFF next names the patch, never a test" | ghost per slice = ceremony | focus | KEEP second; first becomes "ghost only if a number exists" | 70 |
| 23 | HANDOFF limit: global CLAUDE.md says 30 lines, AGENTS.md says 15 | confusion | none | CHANGE-TO 15 everywhere | 90 |
| 24 | Global CLAUDE.md: "400 model calls, 3 subagents" sentence | stale after row 1-2 | none | CHANGE-TO new numbers | 95 |
| 25 | Memory work-style: "No subagents, pods, parallel sessions, docs, audits"; "max one build and one check per request" | contradicts AGENTS (slices, Becarios, 30 runs) and the OWNER's new model; a worker reading it self-limits | the 10-31 spiral | CHANGE-TO rewrite (see 4) | 90 |
| 26 | Memory mobile-scope (Moto APK, Firefox/Edge, 30 fps OK, remaster off OK) | contradicted by OWNER answers 11-05 (Chrome+Safari, iPad/iPhone touch, 60 fps/p99 20 ms) | none now | CUT / replace by 3 lines | 90 |
| 27 | Memory pod-quota, owner-oracle-session, relay-account, agency-windows (file/launch recipe) | pods dead since 10-27; relay conflicts with same-session | n/a | CUT first three; agency-windows CHANGE to the new launch recipe | 80 |
| 28 | Memory prior-art-first | 2-4 searches per fix | NFSU community widescreen knowledge | CHANGE-TO only for new surfaces (Safari/WebGPU fallback, iOS touch, gamepad) | 70 |
| 29 | rn-trace-unbounded, bound-every-wait, silent-test-runs, macgate-no-exec, becarios-visible, same-session | cheap, one screen | 14 GB, 8 h build, music during tests, burned run | KEEP | 90 |
| 30 | Global: "log hitos with bitacora.py", "report starts from spend.py" | 1-2 calls per milestone | none visible | CHANGE-TO only at block end | 60 |
| 31 | AGENTS "Thirty runs... long ghosts RN_SECS up to 1800, at most 3 at once" | ok | CPU saturation | KEEP the 3-at-once; count per row 6 | 70 |

## 2. Low-yield patterns (numbers)
- Docs/census/rescue churn: spend.txt 303 commits = 198 code + 105 docs-only (35%). Git log since 10-29 by file touched:
  132 touch host/web/recomp/pc, 56 docs only, 29 census, 27 empty/merge. 10-29 alone: 27 commits, 18 census, 0 host/web.
- Naming waves (RE wave 4B, "Names wave 2/3/4A/4B", GPU name pass, local-model rows): 10 commits + 8 census commits; the costliest
  10-29 subagents (18.2M, 15.5M, 14.8M, 14.2M cache-read) were read-only naming/RE dossiers. PLAN.md already parks them
  ("Naming waves, canon, scoreboard, census growth"): the rule exists, the habit left a 145 MB census/ behind. Zero effect on Chrome play.
- Audits of audits: 10-31 forensic audit -> "Cut the harness" -> 11-05 repo audit (12 Becario lanes + Sonnet contrast, one HTML)
  -> 10 implementation commits -> this two-auditor refute round. 22 commits say "audit". Findings C05/C07/C08/C09/C12/C13/C14/C16/C36
  are fine engineering but no OWNER goal depends on them; C05 (1 GB scan every 120 frames) is the only one with a perf link.
- HANDOFF-only commits: 37 of 266 (14%) plus 50 other doc commits. A HANDOFF per block is the OWNER's rule; HANDOFF per step is waste.
- Pod lanes: 30 merge commits and 38 "pod" mentions on 10-30/31; visual lanes (AO, halo, tonemap, vignette, shadows, grade, FXAA, CAS,
  facade) then 6+ reverts the same/next day. Cost: unbounded; yield: 0 kept effects (halo deleted, render quality reverted).
- Becario ceremony: 12 worktrees; every diff read, REA-checked, reviewed by nacho, ghosted. Good yield only where a number existed
  (chavo extract 463f20, nacho pointer-reuse bug, paco docs fix). Draft patches for feel were mostly "did not move their number" (b715c90 dropped 3).
- Contradictory prose: memory says no subagents/no parallel; AGENTS allows slices; SCOPE adds Becarios; context-guard says relay;
  same-session says never relay; HANDOFF 15 vs 30. Each window pays to read all of it and obeys a random subset.
- Rules raised stepwise (runs 1 -> 5 -> 30; calls 400 + xcalls) after each time they blocked: signal that the limit was a proxy.

## 3. Operating model for the one-day run (4 blocks)
Effort split 70 build / 20 integrate / 10 plan, enforced structurally, not by prose:
- Orchestrator (this window, Opus medium via /triage): plans, briefs, merges, builds main, talks to OWNER. Writes no feature code
  over 20 lines; reads each window's DONE message (3-5 lines). That is the 20% + 10%.
- W1 / W2 / W3: Sonnet 5.5 high (/triage RE/implementation class), each in its own worktree `~/RE-NFSU-wt/w1..w3` (counts for the
  cap-3 hook), own build dir (NOT the shared symlink) and own ports (5181-5183 / 9382-9384). They build, run, commit on their branch.
  Lanes never share a written file:
  - W1 graphics + perf: web/gpu.js, host/d3d9.c; Safari/WebGPU-or-WebGL path, frame-time p99, hitches >33 ms.
  - W2 input + entry: web/ input, gamepad, remappable keys, iOS touch layer, menu, one URL on LAN.
  - W3 game: host/rivals.c, free.c, openworld.c, patches.py; WORLD AI, remaster defaults, RN_UNLOCK.
  Orchestrator owns main, deletions (rockport/ao/canon/dash/carao), docs, AGENTS/PLAN/HANDOFF.
- Becarios (max 5, TokenTok): mechanical + research only, disjoint paths: delete lists, asset conversion, touch-UI drafts, prior art
  for Safari/iOS, doc cleanup. No gate beyond: path-check script, Main build, ghost only if "dangerous".
- Talk: /sesiones. Windows are named `w1..w3`; orchestrator `ListAgents` then PING/PONG once; afterwards only DONE/BLOCKED/REQ
  (3-5 lines + commit hash). Brief lives in a file `runs/day/w<k>_brief.md` in the /triage format (Objetivo/Contexto/Alcance/
  Hecho cuando/Límites). OWNER types "bypass 24h" once at the start (row 3); workers are then attended.
- Models: /triage at each brief. Diagnosis (cause unknown, cross-lane conflict) = Opus in the orchestrator only; implementation and
  RE with a plan = Sonnet windows; mechanical = Becarios/haiku. No `/model` switches mid-session (cache).
- Blocks (each ends with merge + build + commit + HANDOFF <= 15 lines; ~3 h each):
  B1 base: deletions + docs/re/ai commit + RN_UNLOCK (original) + TRAFPAINT/LEAN on + ONE `webcheck --route` (deletion + boot = test).
     Lanes start: W1 frame-time harness (p99 in Chrome), W2 input/touch design+code, W3 WORLD rest.
  B2: W1 Safari graphics layer; W2 gamepad/remap + touch controls; W3 WORLD AI + remaster defaults.
  B3: W1 hitches to 0 frames >33 ms; W2 menu + single URL + LAN on iPad/iPhone; W3 feel/reset/walls from OWNER F10.
  B4: integrate, macbench p99 in Chrome and Safari (the only bench), OWNER plays, final HANDOFF. Safari automation = NV
  (safaridriver availability unchecked); otherwise the OWNER is the Safari/iOS test.
- Test threshold (binding): run only when the change touches boot/menus, physics/collision shared with original mode, the build,
  or deletes code. Everything else: build, ship to :5180, OWNER plays. A "test" below that bar is not done and not counted.
  A failed repro once = stop and ask for F10 (existing rule, keep).
- Gates left: macgate, chrome-guard, bounded waits, md5 boot check, read-only game/ref, 3 ghosts at once, stop rule 4 attempts.

## 4. Exact edits
Global hooks (edit with the OWNER's ok already given in owner_answers.md):
1. ~/.claude/hooks/spend-guard.py: `CALLS, AGENTS, IDLE_MIN = 400, 3, 60` -> `CALLS, AGENTS, IDLE_MIN = 3000, 8, 240`;
   `BYPASS_MAX_H = 12` -> `BYPASS_MAX_H = 24`; header comment lines 2/3 "400 model calls"/"3" -> new numbers; deny text "budget +400" -> "budget +1000".
2. ~/.claude/settings.json: delete the whole `"PostToolUse"` block (context-guard); add under PreToolUse a third entry
   `{"matcher":"Bash","hooks":[{"type":"command","command":"/Users/angeldamian/.claude/hooks/block-dangerous-cmds.sh","timeout":5}]}`.
3. ~/.claude/hooks/context-guard.py: delete the `flag`/`last > LIMIT` section (everything after the scope block, and the LIMIT/TAIL
   constants); header "Two jobs" -> "One job: scope anchor". Keep the scope.md injection.
4. /Users/angeldamian/RE-NFSU/.claude/hooks/runcap.py: `if n >= 30:` -> `if n >= 100:`; stderr text "max 30" -> "max 100"; header line 1 "thirty" -> "one hundred (OWNER 2026-11-05)".
5. rm ~/.claude/hooks/mac-guard.py spend-guard.py.bak; mv kgrun.sh to ~/.claude/hooks/old/ (main session executes; I did not).
Global ~/.claude/CLAUDE.md:
6. "A session gets 400 model calls (its subagents' calls included) and 3 subagents." -> "A session gets 3000 model calls (subagents included) and 8 subagents."
   and "Over it: commit, HANDOFF, end. Only the OWNER extends it, by typing "budget +400" or "agents +2"." -> `... "budget +1000" or "agents +4".`
7. "HANDOFF.md (max 30 lines, replaced)" -> "HANDOFF.md (max 15 lines, replaced)".
8. "Registra hitos con `python3 ~/Dashboards/tokentok/tools/bitacora.py hito "texto"`." -> add "solo al cerrar un bloque".
AGENTS.md (project):
9. Replace the "Slices are allowed ..." bullet with: "- Day model (OWNER 2026-11-05): orchestrator + up to 3 Claude windows (worktrees ~/RE-NFSU-wt/w1..w3, own build dir and ports 5181-5183/9382-9384, disjoint written files) + up to 5 Becarios; 4 blocks, each ends in merge + build + commit + HANDOFF. Effort 70% build, 20% integrate, 10% plan. Windows talk through /sesiones, models through /triage."
10. Replace "- No effect or feel change on by default until the OWNER approves. Original mode stays untouched as the reference.\n  Exception (OWNER 2026-11-04, docs/SCOPE_2026-11-04.md): ..." with: "- Remaster/WORLD defaults may change, one commit each so it reverts. Original mode is the reference: only perf fixes that do not change feel, and RN_UNLOCK."
11. Replace "- The OWNER is the test for feel, look, lag and WORLD. Patch from RE plus their F10 JSON or recording, build, ship, ask.\n  Verify WORLD yourself with ghost drivers (OWNER 2026-11-03)." with: "- Test only when the change touches boot/menus, physics/collision shared with original mode, the build, or deletes code (`webcheck --route` or a ghost). Anything else: build, ship on :5180, the OWNER plays. No re-validation, no test below that bar."
12. "- Thirty game or Chrome runs per OWNER message on the Mac, at most (enforced: .claude/hooks/runcap.py);" -> "- 100 game or Chrome runs per OWNER message, at most (runcap.py);".
13. "- Several problems in one message: take them as slices, each with its own number, patch and ghost; report all at the end." -> "- Several problems in one message: one lane each, report all at the end."
14. "## Hard limits" ports line: "- Ports: ours 5180, 9381." -> "- Ports: 5180/9381 (orchestrator), 5181-5183/9382-9384 (windows w1..w3)."
15. "## Close": "Commit on main; HANDOFF.md ≤15 lines, replaced." -> "Windows commit on their branch; orchestrator merges to main; HANDOFF.md ≤15 lines, replaced, per block."
CLAUDE.md (project): no change (one line @AGENTS.md).
Docs: replace docs/PLAN.md with one "Day plan" (goal from owner_answers.md, 4 blocks above, 10 lines); delete docs/SCOPE_2026-11-04.md
and docs/openworld/AI_SCOPE.md after moving its s5 (method: ghost.sh + ghostreport.py, F/I/NV tags, 6 lines) into docs/PLAN.md.
SCOPE s5 approval gate -> replace by row 17.
Memory (~/.claude/projects/-Users-angeldamian-RE-NFSU/memory/):
16. work-style.md: replace body with: "OWNER-visible result per block; stay on the goal; RE only code behind the symptom; parallel windows and Becarios allowed under AGENTS.md day model; no audits or new docs unless asked; 'pausa' = stop all; one failed repro = ask for F10." Drop "Max one build and one check per request" and "No subagents, pods, parallel sessions".
17. Delete mobile-scope.md, pod-quota.md, owner-oracle-session.md, relay-account.md; add `day-model.md` (3 lines: owner_answers goal, targets Chrome+Safari+iPad/iPhone touch, perf bar 60 fps p99<=20 ms, 0 frames >33 ms); rewrite agency-windows.md launch recipe to "SendMessage brief path + PING; OWNER types bypass 24h once".
18. MEMORY.md: remove the four deleted lines and the mobile-scope line; add day-model line.
19. prior-art-first.md: append "Only for new surfaces: Safari/WebGPU fallback, iOS touch, gamepad."

## 5. Not verified / risks
- NV: whether SendMessage to a window fires UserPromptSubmit (runcap reset, spend-guard "human" origin). Row 3/6 assume it does not.
- NV: Safari automation on this Mac; the plan treats the OWNER as the Safari/iOS test.
- Per-window build dir: full build 336 s, no-op 31 s (HANDOFF); 4 builds at once may hit the 16 GB memory level that macgate guards (builds are not gated).
  Suggest RN_JOBS=3 per window; mac-guard (cut) used to cap this. Evidence: 2 kernel panics 10-23 with 10 workers. Risk accepted at 70%.
- Raising caps is cheap to reverse; the only irreversible risk is a runaway night, covered by rule 3 (kept) and bypass expiry.
