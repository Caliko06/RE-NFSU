# Plan: NFSU PC 1:1 in Chrome
For the OWNER alone: Chrome on this Mac, tools/serve.py on 127.0.0.1:5180, saves in save/. No deploy.
One session on main. Each milestone has one gate: the run that proves it.

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

## OWNER decisions
- HUD/menus in 16:9 (M8.4, build/evidence/1_hud.md), OWNER 2026-10-25: race HUD side groups at the window edges (the
  default; B = a 16:9 box only differs on wider windows, and on the OWNER's 2.2:1 window they want the edges); menus stay a
  4:3 panel, no stretch. A/B shots in build/hud169; ?env=RN_HUD=169|43 and RN_FE=stretch stay as opt-in switches.

## Only when a run hits it
- Known layer gaps: GetMessageA that would wait (0x411030, window inactive), SuspendThread of a running thread
  (0x448d00, 0x5a4a50). Fix one when a run stops on it.
- New lifter bug -> fix it in tools/recomp with the difftest (RN_ONLY trace).
