# Plan: NFSU PC in Chrome
For the OWNER alone: Chrome on this Mac, :5180, saves in save/. Older plans live in git history (before 2026-10-31).

## Now
0. WORLD AI quality (rivals, traffic, NPCs), OWNER 2026-11-04: scope, rules, agents and RE ladder in docs/openworld/AI_SCOPE.md. Items 1-3 below are older (2026-10-31).
1. Car falls through / passes walls after a reset; handling feels worse (OWNER 2026-10-31).
2. Feel: blur, light halos, camera angle at speed, acceleration (docs/re/feel_2026-10-31.md has the addresses found).
3. Traffic almost absent in WORLD; horns heard with no cars; hitches.

## Parked (do not resume unless the OWNER asks)
Naming waves, canon, scoreboard, census growth, open-world research docs, the pod, branch `publish`.

## Ghost player on the Mac (OWNER 2026-10-31: approved for another day; no pod)
Measured: `RN_AILOG=1 tools/completion.py queue 1 cjump_7` = 71 s wall for one sprint event (74 s race), 1 core, 0.5 GB.
Whole canon (277 races; career_trace 2026-10-27 walked it with RN_FINISH in 22 min) ~ 9 core-h, ~1.5-2 h at 6 in parallel.
Steps: (1) ai_log walks the traffic list [0x7361f8]; racers are L+0x28[0..L[6]-1] (REPORT_career.md), fix it so rivals show.
(2) `completion.py queue 6 cjump_<n> ...` per event (census/rows.json), `collect`, then one table: crash, stall, rivals that
do not finish, AIHIT walls, collision pool. (3) cjump_7 lead: TRAFLOG polys climbs 21 -> 8192 (cap) by frame 6300, never
drops; check docs/openworld/re_coll_pool.md (walls lost when full?) and whether the original fills it too. WORLD: not reachable.

## Known decisions
- HUD side groups at the window edges; menus stay a 4:3 panel.
- Perf: race p50 is at vsync; gate60 fails on spikes. Next perf work = profile the spike frames.
