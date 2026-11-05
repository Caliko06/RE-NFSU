# Refute A -> B, then merge (Auditor A). No runs, no repo edits. Tags: FACT / INF / UNK.

## 0. B's NOT VERIFIED item, checked
- FACT spend-guard.py:71 counts an OWNER prompt only if `origin.kind == "human"` in the MAIN transcript. Transcripts show a SendMessage
  from another session arrives as `"origin":{"kind":"peer","from":"uds:/tmp/cc-socks/..."}` (713 peer rows; 3705 human). So a peer message
  never resets the idle clock: a worker that only gets SendMessage is "unattended" from minute 0 (B right), until the global bypass.json
  (written only from a human prompt, spend-guard.py:60-64, applies to every session) is live. `bypass 24h` is clamped by BYPASS_MAX_H=12 (line 18):
  B's edit is needed, or the OWNER types "bypass 12h" twice.
  Still UNK: whether a peer message fires the UserPromptSubmit event (so runcap reset). If not, the counter file /tmp/runcap-<sid> is a
  hard 30 per worker window for the whole day (not "unlimited", my reading of B's row 6 is "30 total", same conclusion): raise to 100.
- FACT spend-guard.py:171 `SendMessage` is also gated when unattended (must cite `#N`): the DONE/BLOCKED replies of workers die without bypass.
- FACT block-dangerous-cmds.sh is in no settings.json (global or repo): B is right that it protects nothing today.

## 1. Where I disagree with B
1. Row 10 (register block-dangerous-cmds.sh globally). Register it in the repo `.claude/settings.json` only (worktrees inherit the tracked
   file), not in ~/.claude/settings.json: the script also blocks `git branch -D`, `git reset --hard`, `pkill`, `checkout .` for MW/MP/MC repos
   and Dashboards, where nobody asked for it. The worktree cleanup this day needs (12 stale wt + `branch -D`) would also trip it:
   orchestrator uses `git worktree remove` + `branch -d`. Conf 65%.
2. Operating model, "own build dir" (section 3). Correct in direction, incomplete in fact:
   - FACT today's Becario worktrees symlink `build/` to main (nacho/build -> RE-NFSU/build). With 3 windows serving, that is fatal: serve.py POSTs
     `build/web.log` and `build/telemetry.ndjson`, bench.py writes `build/bench/`, webcheck `build/webcheck.log`: three windows overwrite each other's logs.
   - FACT a plain `git worktree add` lacks everything .gitignore hides: game/ (1.3 GB), ref/, pc/Speed.exe (`pc/*.exe`), web/remaster (811 MB), .venv,
     census/hopper/decomp.c, save/, runs/. Each w<k> needs: symlinks for game, ref, web/remaster, .venv, census/hopper/decomp.c; a copy of pc/Speed.exe
     and save/; a REAL build/ seeded with `cp -c` clones of main's build/gen (128 MB), build/wobj (81 MB), web/out (108 MB) so the first build is a 31 s
     no-op, not 336 s. Disk is fine (36 GB free, 3 x ~320 MB). One orchestrator script, ~15 min to write and check. B did not list it.
   - FACT ports: serve.py takes a port arg; webcheck has RN_CDP_PORT and a URL arg; bench.py has BENCH_URL. B's 5181-5183/9382-9384 works with no code change.
3. "4 builds at once" (B accepts 70% risk). FACT build.py:31 honours RN_JOBS; FACT macgate.sh:9 says builds are not gated since 10-27 on purpose.
   INF worse than B says: the lift seal hashes the recomp sources (a7a80ee), patches.py is one, so ANY patch edit = full relift+compile 336 s CPU-bound
   on 10 cores. W3 (patches) iterating plus 3 merges onto main = builds queue. Mitigations: RN_JOBS=4 for windows, RN_JOBS=10 only for main's merge build,
   and split patches.py into modules so most edits are host/*.c (incremental). Adopt B's idea, add these.
4. B row 8 / block 4 "macbench only for the final gate". Disagree: p99 and ">33 ms" are LOAD-SENSITIVE (bench spk5 vs spk3: same code, p99 33.4 vs 19.6,
   max 149 vs 43 ms, with other sessions loading the Mac, commit cc5c291). The perf work (my Block 3) cannot iterate with 3 windows running ghosts/builds.
   Fix without macbench ceremony: perf block has 2 explicit exclusive slots per hour (other windows read/RE/write code only, no runs, no builds), measured with
   the vsync rows. Final macbench gate still at the end.
5. B's lane map puts Safari graphics in B2. Disagree: Safari is the single largest unknown (never run; waitAsync, WebKit WGSL), everything in W2/W3
   that is "browser" depends on it. Smoke-run Safari in block 1 (~1 h); if it needs a big fix, the day plan changes at hour 2, not hour 6.
6. Test rule, row 18 / section 3 "test only if boot/menus, shared physics, build, deletes". Add one case B missed: a change to the render/present path
   or to a shader (gpu.js/sm1.c) can break boot on Safari or Chrome and is "boot" by effect; and a perf change is only done with the number. Both already
   fit "test below the bar is not done", I only ask to name them.
7. Safari automation (B: NV, "OWNER is the test"). Not needed: telemetry.js POSTs frame/vsync rows to /telemetry from any browser; `open -a Safari URL`
   plus reading build/telemetry.ndjson is a full test with no safaridriver. New risk B did not see: a headed Safari run is audible and visible on the
   OWNER's screen (silent-test-runs memory; chrome-guard only covers Chrome). Fix: `?mute=1` (skip AudioContext.resume) and bench windows only in slots.
8. B's lane W3 (game) carries WORLD AI + remaster defaults + RN_UNLOCK + feel + reset/walls + patches.py: too much for one window and one file.
   Keep W3 on domain "game" but split patches.py into patches_<topic>.py (my restructuring item 6) and give reset/walls its own module; Becarios take the
   mechanical items (defaults, RN_UNLOCK, deletions) so W3 does RE only.
9. Row 12 agrees with me; row 1-3,6 numbers: accept. Row 2 "AGENTS=8": harmless, windows/Becarios are not Claude subagents (FACT spend-guard counts only Agent/Task tool_use).

## 2. What B found that changes my blocks (adopt)
- Lane ownership by DOMAIN for the whole day (W1 graphics+perf, W2 input/entry/LAN, W3 game) instead of my per-block re-assignment: removes file sharing
  and re-briefing. I map my files: W1 = web/gpu.js, host/d3d9.c, host/files.c, host/sm1.c; W2 = web/input.js, touch.js, pad.js, audio.js, index.html(+boot.js),
  mode.js, tools/serve.py, setup.html; W3 = host/rivals.c, free.c, openworld.c, win32.c flags, tools/recomp/patches*.py. Orchestrator = deletions, docs, merges, main build.
- B1 "base" first (deletions, docs/re/ai commit, RN_UNLOCK, TRAFPAINT/LEAN on, ONE `webcheck --route`): adopt, the HANDOFF already says the build is unrun.
  Run it BEFORE lanes branch so every worktree starts from a known-good main.
- Rule edits (calls 3000, idle 240, bypass 24, runcap 100, context-guard relay cut, 15-line HANDOFF, memory rewrites) and the single test rule: adopt as written,
  except row 10 above.
- Becario gate reduced to path check + build; ghost only if dangerous/number: adopt (my blocks lean on Becarios for extraction and bisect).
- "Orchestrator writes no feature code > 20 lines": adopt. It also protects the 20% integrate slot.

## 3. Merged plan (one day, ~3 h per block; each block ends with merge + build + commit + HANDOFF <= 15 lines)
| Block | Goal | W1 (gpu/perf) | W2 (input/entry/LAN) | W3 (game) | Becarios (<=5, disjoint) | Done-number | Test? | Risk | Conf |
|---|---|---|---|---|---|---|---|---|---|
| 0 (orch, 1 h, before launch) | Clean base, rules cut, worktrees w1..w3 ready | - | - | - | deletions list, docs/re/ai commit prep | `webcheck --route` PASS once on main; 3 worktrees each build no-op <= 60 s on own ports | YES: boot + build + deletions | worktree symlink gaps; rule edits typed wrong | 80 |
| 1 Reach | Safari Mac boots and plays; LAN Mac/iPad open one URL; gamepad on Mac | waitAsync fallback (helper Worker), Safari headed smoke, fix WGSL/limits until a race renders | serve.py HTTP/1.1 + /setup + launchd + mobileconfig; pad.js (Gamepad -> DIK); audio unlock; `?mute=1` | RN_UNLOCK (orig), TRAFPAINT/LEAN on, WORLD ghost 1800 s baseline on final build (no perf runs while W1 measures) | WGSL/iOS checklist (read-only), stream-read stats from build/bench logs | Safari headed race 1103 for 180 s: 0 WebGPU/JS errors, vsync rows logged; other Mac and iPad reach the main menu over https; pad drives menu+car | YES for W1 (render/boot path: webcheck --route + Safari run); NO for server/pad (OWNER plays) | first Safari run is UNK | 60 |
| 2 Touch + harness | iPad playable by touch; one command gives a headed 3-min race table | gpu.js uniform packing study only (numbers), calloc arena in d3d9.c (shared-nothing with W2) | touch.js overlay (DIK pushes, menu d-pad, auto fps=30, coarse pointer), boot.js split | reset/walls RE and patch in patches_reset.py (module split first) | tools/bench.py headed mode + cause table (`spike:` lines), param table for boot.js | iPad finishes a race by touch (OWNER plays); bench prints count >20/>33 ms per minute for Chrome and Safari | YES for reset patch (shared physics, ghost forced resets, same seed); NO for touch | digital steering feels late | 65 |
| 3 Perf to the number | p99 <= 20 ms, >33 ms count <= 1/min, then 0 | exclusive bench slots: stream-read prefetch (files.c), per-frame arena, uniform packing, pack uploads off the frame | no runs; touch/menu polish, /setup toggles | spike (1846,-727) + WORLD spawn spikes in host/ (no runs in slots; ghosts outside slots) | bisect, log digestion | 3 headed minutes, Chrome AND Safari: p99 <= 20 ms and max <= 33 ms in 2 of 3 runs (literal "0 in every run" is a stretch) | YES: perf number is the definition; original-mode perf fixes need feel-neutral proof (A/B screenshot hash) | load-sensitive numbers; GC/thermal | 75 for p99, 40 for literal 0 |
| 4 Feel + WORLD + close | Feel defaults on, WORLD ghosts green, one PLAN, final gate | final macbench p99 Chrome + Safari | /setup polish, QR, instructions | WORLD ghosts 1800 s x3 same seed, remaster defaults (accel/hornfix/chasecam if approved), reset/walls follow-up | doc cleanup, delete SCOPE/AI_SCOPE after moving s5 method | ghost 0 pass-through after forced resets, same seed; final macbench numbers recorded; OWNER plays on :5180 | YES once (route + final bench); defaults NO | OWNER taste (10 reverts so far) | 65 |

## 4. Residual risks not in B or in my first file
- Worktree windows never tested with the 3-window cap script (spend-guard.py:176 counts claude processes with cwd matching `-wt/`): `~/RE-NFSU-wt/w1..w3` match; the 12 old Becario worktrees are not claude windows, so they do not count. FACT.
- Two serving ports per window means three Chrome profiles + wasm 2 GB virtual each; macgate (free mem >= 20%, 10 s settle) serialises launches on 16 GB: fine, but a headed Safari plus Chrome plus 3 builds pushes memory pressure; run Safari only in slots.
