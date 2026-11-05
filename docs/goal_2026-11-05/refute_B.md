# Refute B -> A, then merge (2026-11-05). Checked with grep/git show only; nothing run, no repo edits.

## 1. Where I disagree with A
1. "Safari never run, boot is the biggest unknown, 60% first-run" is too pessimistic. HANDOFF at 3fba755 (11-03) line 9:
   "139428b LAN HTTPS + sbrk guest (iPhone plays WORLD)" and line 12 "Stutter left (W census, iPhone + Mac)": an iPhone ran this exact page
   with the same waitAsync pump, and the OWNER sent an iPhone F10. A cites 139428b as proof, but the commit message itself only
   shows headless-Chrome memory numbers (peak 725-750 MB) and says the tab-kill was fixed. So the proof is a worker's HANDOFF sentence:
   real, current in the file (HANDOFF e61dd63 still lists "open OWNER asks: Safari Mac F10"), but NV as a measurement. Both are WebKit.
   Consequence: do not budget W1 for 3 h of Safari boot. Budget a 5-minute OWNER check first; build the Worker fallback only if it fails.
2. waitAsync as the only frame driver: A is right on the fact. web/gpu.js:1362-1371 `pump()` is the only loop (called once at :1395); host/gpu.c:49
   wakes it with emscripten_futex_wake. rAF is used only for presenting (gpu.js:82,101). I disagree only on the risk (point 1): not an unknown.
3. Cost of Block 1 (Safari + server + gamepad in one 3 h block, three lanes, conf 65%): honest on the server part (serve.py has no
   `protocol_version`, grep empty: HTTP/1.0 confirmed), but it hides that the real Block-1 risk is audio. web/audio.js/index.html have no
   mute switch (grep "mute" = empty), Safari cannot be muted from a command line, so a headed Safari bench plays the game's music on the
   OWNER's speakers (memory silent-test-runs: "the OWNER must never hear test runs"). A never mentions it. Needs `?mute=1` (S) before any headed run.
4. Block 3 W3 "runs benches in a loop, writes no files" wastes a full Claude window, and macbench.sh holds every launch of every window
   for up to 10+30+10 min: a bench loop in W3 stalls W1 and W2. Benches are one job for the orchestrator, one at a time, not a lane.
5. Reset/walls RE (OWNER item 1 since 10-31, docs/PLAN.md "Now" #1) is put last (Block 4, 55%). RE is calendar time and the
   stop rule is 4 attempts per cause: it must start in Block 1 as a long lane, not be crammed into the last 3 h. Deletions
   (rockport/ao/canon/dash/carao) are also in Block 4 (W3): done last they conflict with every lane's merges and cost builds. Do them first.
6. Perf done-number. A's "halve first, <=1 per minute" is reasonable but silently lowers the OWNER's bar (0 frames >33 ms in 3 min,
   p99<=20). Measured baseline (45e767d message): race 1103, headless Chrome, ~3700 frames: spk3 p99 19.6 / max 43 / 3 frames >33 ms; spk4 p99 21.1 /
   max 55 / 5 frames, "not yet separated from run noise". So 3-5 per minute headless today; ~10-15 per 3 min. Headless has no real vsync,
   so these numbers do not transfer to headed. Define it, do not soften it silently:
   DONE = race 1103 (the only race ever benched), HEADED, 180 s after a 10 s warm-up, game running at the limiter, page `vsync` rows
   (telemetry.js) as the clock; PASS = p99 <= 20 ms AND count(>33 ms) = 0 in 2 of 3 consecutive runs, in Chrome-for-Testing and in Safari;
   report the count per run either way. If count is 1-2, the OWNER decides; I do not call it done. Conf of literal PASS in both: 35%.
7. "Two perf items C18/C19 not measured" is fair, but A then plans uniform packing (gpu.js U_STEP) in Block 3 before the headed
   harness gives per-cause counts. Order must be: harness (B1) -> baseline by cause (B2) -> fix top 2 (B3). A has this order; keep it, but
   do not pre-assign uniform packing to W1 before the table exists.
8. "One builder window per block, shared build/ (8.6 GB)" overstates it: most of build/ is junk (bench 765M, pod 692M, runs_freeriv 564M,
   openworld 1.9G); the lift (build/gen) is what matters, full 336 s, no-op 31 s (HANDOFF). Solve with per-worktree gen cloned via
   `cp -Rc` (APFS, free) = incremental 31 s builds in each window. NV: that build.py paths are repo-relative. Fallback = A's one builder.

## 2. What A found that I adopt
- patches.py (674 lines, 156 PATCHES.append) and web/tune.js split into patches_<lane>.py: ADOPT. Orchestrator does it in Block 0 before
  any worktree forks (mechanical, covered by the one route test). Same for index.html (190 lines) -> web/boot.js + param table in mode.js.
- Do NOT split gpu.js (1396 lines) or d3d9.c: ADOPT. Extract only pump() if the fallback is needed.
- New files per lane (web/pad.js, web/touch.js, web/setup.html, tools/bench headed): ADOPT; it gives real disjoint ownership.
- input.js `pushKey/pushMouse` export; touch and pad push DIK events: ADOPT, one window owns all of input (W2).
- serve.py HTTP/1.1 + LaunchAgent + /setup, audio unlock on touchend, `?fps=30` on coarse pointer: ADOPT.
- Zero touch/gamepad code (grep touch web/*.js = empty; only keyboard+mouse): confirmed. This is the largest product gap, not Safari.
- "Digital touch steering will feel like the keyboard model": ADOPT as a stated risk; analog steer is a post-day item.
- Failure list item 5 (single-file collisions) already matches my lane-ownership rule.

## 3. Merged plan (one day, 4 blocks after a 30-minute Block 0 run by the orchestrator, ~3 h each)
Block 0 (orchestrator + Becarios, no lanes): deletions (rockport, ao, canon, dash, build/carao), commit docs/re/ai, RN_UNLOCK original,
TRAFPAINT/LEAN on, patches/index split, `?mute=1`, 3 worktrees, ONE `webcheck --route` (boot + deletion + build = test yes). Ask the OWNER
for the 5-minute Safari/iPhone check now.

| Block | Goal | Lanes (written files, no overlap) | Done-number | Test? | Risk | Conf |
|---|---|---|---|---|---|---|
| 1 Reach | Safari Mac boots and plays; other Mac/iPad load by one URL; gamepad; headed harness; reset RE starts | W1: web/gpu.js (fallback only if Safari fails), new tools/bench_headed.py, web/telemetry.js. W2: web/input.js, new web/pad.js, tools/serve.py, new web/setup.html, web/audio.js. W3: docs/re + tools/recomp/patches_reset.py + host collision files (RE only). B: WebKit WGSL checklist, touch prior art, param table draft | Safari headed race 1103 180 s: 0 JS/WebGPU error lines, vsync rows present; 2nd Mac + iPad reach main menu; gamepad moves menu and car | yes for serve.py/HTTP1.1 (hitch risk) and bench harness smoke; no for pad | audio on headed Safari; CA trust on devices | 70 |
| 2 Touch + baseline | iPad playable by touch; baseline frames >33 ms by cause, Chrome + Safari | W2: new web/touch.js + css string. W1: host/files.c (read-ahead), host/d3d9.c calloc arena (~2182-2237). W3: reset patch draft + WORLD flags in web/mode.js. B: menu-to-DIK table, doc cleanup | iPad finishes a race by touch; table of >33 ms by cause (3 runs, headed) | yes for reset patch (shared physics, difftest) and files.c (boot path); touch no | digital steering feels late | 65 |
| 3 Perf to the number | top 2 causes fixed | W1: web/gpu.js uniform slots / pack uploads (per the table). W3: host/free.c, rivals.c, openworld.c spikes at (1846,-727). W2: /setup polish, device-class defaults, remap check, LaunchAgent. B: bisect/log digest | p99<=20 and max<=33 in 2 of 3 runs, Chrome and Safari (literal 0 reported) | yes for d3d9/gpu changes touching all draws; macbench NOT here | tail metric (GC, OS) | 40 literal / 75 p99 |
| 4 Integrate | feel/reset landed, defaults on, final gate | W3: reset/walls final. W1: perf leftovers. W2: touch polish. Orchestrator alone: macbench x3 headed, merge, HANDOFF, one PLAN | ghost 0 pass-through after forced resets (RN_RESETEVERY, same seed) + the perf gate of section 1 item 6 + OWNER plays | yes: route PASS once + difftest for reset | OWNER verdict on feel unknown | 55 |

## 4. Final rule list after A (changes vs audit_B marked *)
KEEP: macgate, chrome-guard, bounded waits/outputs, md5 check, read-only game/ref, 3-worker cap, 4-attempt stop, nfsu1-context, bypass-by-human-prompt, [nfsu] canary, silent-test-runs.
CHANGE: spend-guard CALLS 400->3000, AGENTS 3->8, IDLE_MIN 60->240, BYPASS_MAX_H 12->24; runcap 30->100; block-dangerous-cmds.sh register;
  context-guard cut relay + PostToolUse; HANDOFF 15 lines everywhere; work-style/mobile-scope/agency-windows rewritten; Becario gate -> path check + build + ghost only if dangerous.
CUT: mac-guard.py, kgrun.sh, spend-guard.py.bak, memories pod-quota/owner-oracle/relay-account, SCOPE_2026-11-04.md, AI_SCOPE.md.
* NEW: `?mute=1` page switch + rule "headed Safari/Chrome runs set ?mute=1"; without it headed benches break silent-test-runs.
* CHANGED: macbench only in Block 4, by the orchestrator, never in a lane (A's W3 bench loop dropped).
* CHANGED: do not cut mac-guard's idea blindly: three windows x RN_JOBS = Mac memory risk (2 kernel panics 10-23 at 10 workers). Put "RN_JOBS=3 per window,
  full rebuild (336 s) only after `macgate.sh --try`" in AGENTS.md instead of the file.
* CHANGED: orchestrator does no feature code and runs the benches; windows do not run macbench.
* NV: headed Chrome-for-Testing opens a window on the OWNER's screen (focus theft); OWNER to confirm headed is acceptable. Safari measurements rely on the page's telemetry POST (A's claim, not checked).
