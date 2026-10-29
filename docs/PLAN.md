# Plan: NFSU PC 1:1 in Chrome
For the OWNER alone: Chrome on this Mac, tools/serve.py on 127.0.0.1:5180, saves in save/. Deploy is the OWNER's call.
One session on main. Each milestone has one gate: the run that proves it.

## Now (OWNER 2026-10-29): reverse engineer to 100 %, not publish
Every system accounted for: canon, free tracks, traffic, rivals, tuning, sound, assets, blur, cameras, props. Method and
checks: docs/re_scoreboard.md §4 (honest coverage, systems.tsv, names.tsv, scoreboard). The open world block below keeps
going as the free-tracks/traffic/rivals thread. Branch `publish` is parked.

## Open world with life (OWNER 2026-10-28)
The OWNER played WORLD (remaster): invisible walls, no traffic seen, no rivals, "flat, lifeless". Wanted: rivals with
personality (they bump you, pass close, you can chase them, they crash too), traffic around the player, no invisible
walls. Simplest bridges and patches over the game's own AI; RE first; one check per step.
1. Traffic recycling: DONE 2026-10-28 for gaps (free_recycle, PATCH 0x5987f6: cars > 500 m also move; WORLD 1010 nearest
   car < 150 m in 219/223 lines, docs/openworld/re_traffic_teleport.md). Open:
   a. Odd places: 122/301 free placements land on nodes without the designer bit (free_tnode) -> verify: placed on node
      bit only, nearest car < 150 m still in most lines on 1001 and 1010.
   b. Groups: every move lands ~230 m ahead, one per tick; read how 0x599c80 spreads spawn objects (+0x70/+0x90) and use
      that spread -> verify: tp straight distance spread p25..p75 > 100 m.
   c. Races (route mode 0x5999c0): same check of gaps and groups -> verify: one 1001-style race log.
   d. Phase A dense traffic with tuned street models: racer rows need baked skins (DUMMY_SKIN slots) before
      PATCH 0x57cfc7 can come back -> verify: no invisible car in a WORLD shot.
2. Rivals (OWNER 2026-10-28: "more rivals out of nowhere", Japan-style night driving with tuned JDM cars; by phases):
   a. Respawn: DONE 2026-10-28, free_respawn (host/free.c): a rival > RN_RIVALFAR (400 m) is put 220..380 m of road
      ahead or behind (a coin) with the game's reset 0x427f70. WORLD 300 s: 16 respawns, 94 % of rival samples < 400 m.
      Speed: [0x700d58] = 8.0 is the reset's MINIMUM (0x426617), so a rival lands at the player's speed. Racers follow
      the tour's road graph forward (docs/openworld_e_re.md B1), so a rival faces and races the tour direction; with the
      player stopped or driving against the tour they leave again in 8..20 s. Judge it in the OWNER's play.
   b. JDM racers cruising in traffic = 1d (skins), Sonnet session.
   c. Phase 2: DONE 2026-10-28 (858ba03): 6 real rivals by default (RN_FREERIV, max 9), Chrome WORLD 400 s: 6 named, mean 28.5 m/5 s.
3. Walls: log the player position when speed drops to 0 with no visible wall; fix stub/fence there -> verify: the
   OWNER's spots pass.
4. Whole-city road graph (exe limits 128 sections / 255 entries) if 1-2 need streets off the tour.
OWNER play 2026-10-28 evening (WORLD): SELECT LOCATION page black; WRONG WAY still shows; a green gap to another car
shows at the top; only 3 rivals and they vanish fast (wants more, each with a personality: clumsy, aggressive); no
traffic in many zones; handling feels odd ONLY in WORLD. Baseline (autopilot on the tour, Chrome 300 s): traffic
nearest < 150 m in 124/130 lines, rivals < 400 m in 374/390 samples, so the gaps are OFF the tour, where no road graph exists.
5. WORLD picture on SELECT LOCATION -> verify: FE shot of the WORLD page shows the city; 1001's page unchanged.
6. DONE: no WRONG WAY and no gap HUD in free mode (PATCH 0x430dbd, free_hud) -> verified: FREE hud mask 0x144589 cleared, WORLD shot.
7. Handling in WORLD = 1001 -> verify: RN_BODYLOG A/B (z jitter, heading) on both tracks within noise.
8. City road graph: DONE 2026-10-28 (v2 f9cad5c, default in build/openworld; the tour net kept as TRACKB1010.tour.lzc). Open: lane
   bytes of flipped sections and type 0 fork rates (re_answers_0b.md from re-nfsu-8b); traffic near < 150 m fell 181/182 -> 120/181
   (19 cars over the whole city: raise traffic within the 30 entrants?). Then rival personalities (docs/openworld/re_rivals_personality.md).

## Earlier (OWNER 2026-10-27 late): regressions before the open world
The OWNER plays and sees: speed blur too strong, traffic glitches (flicker as a car loads, some still invisible, too
few cars), "lagazos" (the game feels slow), and the road looks wet everywhere. Four RE threads, each to the cause in
Speed.exe (the PS2 ELF for the blur), each fix behind a switch, look choices as one A/B strip for the OWNER:
1. Blur (e359add psblur): PS2 Z -> alpha and scale from the ELF; PS_FAR = 200 and the W/512 offsets are guesses.
2. Lag: OWNER telemetry 2026-10-27 shows Present steady (95 % 15-18 ms, 1 frame > 33): measure sim steps per Present.
3. Traffic: cars in the game's list vs drawn per frame (native vs Chrome); spawn, despawn, density from the exe.
4. Road: fx\worldreflect.efx (ReflectedTexMin, ROAD_WET, PUDDLE): full reflection only where the game marks it.
In parallel (OWNER 2026-10-27): another session works the open world in its own files (docs/OPENWORLD.md).

## Open world (parallel session, OWNER 2026-10-27 night)
All of Olympic City (L1RA, the 16 street tracks) drivable with no fences, GTA style, apart from Free Run. Out: drag
and drift arenas, test track, new menus, police, online. Phases and answers: docs/OPENWORLD.md.

## Done
- M0 census. M1 lifter: whole exe lifted, gate pass (census/difftest.json).
- M2 boot: CRT, threads (one GIL + 20 ms quantum), timers, no-network Winsock, files on demand (host/files.c).
- M3 first frames: window, D3D9 device, Presents.
- M4 front end on screen: SM1 -> WGSL, textures, loading screen, title (PATCH 0x4f5891 while MOVIES\ is missing).
  Input (dinput8) and dsound -> Web Audio exist. ABK code modules lifted ahead of time (tools/recomp/abk.py).
- Title -> USER PROFILE over the 3D garage. Save folder (CSIDL_COMMON_APPDATA\NFS Underground = save/) with writes.

## Roadmap contract (OWNER 2026-10-25): 25/167 -> 167/167, 60 fps, RTX effects
Blocks in order. Each one closes with progress before -> after, `webcheck --route` PASS, one commit, HANDOFF.md.
1. Quick Race (46 rows): DONE 2026-10-25 (46/46, f414af4). RN_JUMP per track + one RN_KEYS route per mode.
2. Underground career (116 rows): career.1+ = ChooseCareerCar -> MapScreen -> EventBriefing -> race -> results.
   `career1` like `career0`; RN_JUMP to the game's own event start (RE); the OWNER's save (asas) as a mid-career start.
   DONE 2026-10-25 (116/116): RN_JUMP e<N> + RN_FINISH + RN_NEXT (tournament stages by PostRaceMenu 0x64bf64d2).
3. Whole game (5 game rows + scope): garage and customization with everything unlocked (PATCH with RE citation),
   options persist, save -> reload page -> continue, sound, music, movies. Gate: one Chrome run that saves, reloads, continues.
   Rows DONE 2026-10-25 (5/5, native). Chrome gate DONE 2026-10-25: tools/savegate.py PASS (event 3 saves, a new page
   loads that career status, event 4 runs and saves, a third page loads it).
4. 60 fps, 0 hitches > 33 ms: gate60/bench in Chrome; measure first, fix in the recompiler or the layer.
   2026-10-25: the game caps itself at 60 (0x585b40); the misses are CPU-bound frames of ~4450 draws. Telemetry at
   0.01 ms, direct web clock. x87 runs are opt-in (RN_X87RUN=1, small gain). Next: inline fx2, then D3DX per-draw Pass.
5. RTX as layer bridges, each with a switch: textures 4x + normal/AO, shadows + SSAO, HDR bloom/tonemap, body reflections,
   AA, speed motion blur + light trails (RE PC/PS2 first, never overdone, road never wet). A/B shot per effect; gate60 with all on.
Rules: RE before every fix (address + Hopper/Ghidra line). Short targeted runs. Two attempts without progress -> stop in HANDOFF, move on.

## Block 6, night of 2026-10-27 (OWNER): the Underground career 1:1, then driving, then the look
Order matters. Each part closes with a number before -> after and a commit. Leads are notes; Speed.exe is the authority.

### 6.1 Career 1:1 against the original (first; most of the night if it needs it)
Question: is the career we run the one Speed.exe defines? Events and their order, tracks, laps, direction, opponents,
rewards and unlocks, story movies (game/Movies 01_DAY..19_FIN.mad), magazine covers, the end of the career.
Measured today (2026-10-27): 167/167 rows pass, but by RN_JUMP + injected finish, with the unlock patches always on
(debug byte 0x735ec1; the 22 reads of the career-beaten flag 0x7677ac turned into 1). So order, locks and movies were
never measured: census/completion.json names no movie.
- Oracle, read from the exe and its data: career table (lead 0x733ff8, FrontB.lzc), career status (lead
  0x75eef8+0x34c), the movie message (0x4f5860 type 7, name from 0x4f57a0) and who posts each story movie, the reward
  and unlock code, the game's own completion % if it keeps one (MW did this: RN_COMPLETION). -> census/career_oracle.json.
- Trace: a native run from a new profile with the unlock patches off (add a switch; the default stays on, OWNER
  2026-10-20) that moves only through what the game offers: the next event comes from the game's own open list, the
  win from RN_FINISH. Per event: id, track, laps, direction, opponents, movie, unlocks, rep, cover -> census/career_trace.json.
- Gate: trace vs oracle, 0 differences or each one explained by an address. Then Chrome: the first story movie, one in
  the middle and the final play, with sound, at their point.
- For the OWNER: what the unlock patches change in the career (order, what is open). They pick the default.

### 6.2 Traffic draws whole in Chrome (open parity bug)
Fixed 2026-10-28: the body-less cars were racer models our pool patch let into traffic. A racer body is the
DUMMY_SKIN<n> texture whose hash 0x4b4040 sets at ride +0x444 for slots 1..4; traffic rides get 0 (0x57d160), and
Cars/TEXTURES.BIN has baked <MODEL>_SKIN1..8 only for traffic models. PATCH 0x57cfc7 is off; tuned cars in traffic
need skin slots of their own first (same wall as the racer cap, docs/openworld/re_racer_cap.md).

### 6.3 Driving: handling, rival AI, traffic AI
The game's code runs, so physics and AI are the original unless a patch or the input layer changes them.
- First a table of what we change there and its effect, kept or dropped with a reason: traffic.s (count x1.5, pace
  x0.85..1.15, racer rows), ?steer=pad (0x4609e3..), frame limiter 0x585b94, the TEST-ONLY autopilot/seed patches.
- Handling (OWNER: rigid, late): the steering the game receives from our keyboard vs the game's own keyboard path
  (RN_STEERLOG); speed caps 0x583ea0 on 0x705f48..0x705f84 (lead); bought upgrades really change the tuning values.
- Rival and traffic AI: measure what the game does (gaps, catch-up, lane speed) from code and a trace; change only
  toward the original or what the OWNER named, with a number.

### 6.4 Look: cars, world textures, lights
OWNER words: more detail in the world textures, some things more 3D, the lights and how they look; cars get detail
(AO, grime, wear), not gloss.
- First read what was tried and dropped (git log: Sobel normal/roughness maps 5cf751d, carlook candidates, MSAA
  default, worldhd as WebP, wet road). Do not bring those back.
- Look, not only code: each change is an A/B shot on the same scene at the OWNER's size (2560x1116), opened and
  looked at (sips -Z 1000): original (native --shot) vs Chrome, before vs after. One switch per effect.
- Lights: RE how the game draws them (flares 0x409bdb, the light glow, headlights) before changing them.
- Material at hand: tools/ao (per-vertex AO baked for the 17 race rows), tools/remaster (BC7 world pack, sr.py),
  host/carsmooth.c, host/sm1.c car shading.

### Throughout the night
- 60 fps: gate60 PASS (macbench.sh turn) when a part that touches the frame closes; webcheck --route PASS per commit.
- Spend little: native runs before Chrome runs, Hopper/REA for questions, subagents only for mechanical batches.
- Two attempts without progress on one item: write the evidence in HANDOFF and move to the next part.
- Night done = 6.1 gate + 6.2 gate + 6.3 table and measured changes + 6.4 cars and one world change with A/B shots;
  HANDOFF with the numbers.

## OWNER decisions
- HUD/menus in 16:9 (M8.4, build/evidence/1_hud.md), OWNER 2026-10-25: race HUD side groups at the window edges (the
  default; B = a 16:9 box only differs on wider windows, and on the OWNER's 2.2:1 window they want the edges); menus stay a
  4:3 panel, no stretch. A/B shots in build/hud169; ?env=RN_HUD=169|43 and RN_FE=stretch stay as opt-in switches.

## Only when a run hits it
- Known layer gaps: GetMessageA that would wait (0x411030, window inactive), SuspendThread of a running thread
  (0x448d00, 0x5a4a50). Fix one when a run stops on it.
- New lifter bug -> fix it in tools/recomp with the difftest (RN_ONLY trace).
- Perf (port-nfsu2web, discarded 2026-10-28): race p50 already sits at vsync 16.7 ms, so CPU micro-ports (native
  matrix/frustum, inlining, _ftol2, limiter sleep) move nothing; gate60 fails on spikes (max 44-81 ms), and one run
  of the same build flips PASS/FAIL. Next perf work = profile the spike frames, and judge gate60 on several runs.
