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

## M5 Menus
- Create a profile (type a name, the file lands in save/), reach the main menu, move through the menus, hear music.
- Gate: one Chrome capture of the main menu after the profile; the profile file is in save/.

## M6 A race
- Quick Race: the circuit loads, the car drives, the race ends and returns to the menu.
- Gate: one full race in Chrome without a stop.

## M7 Career and saves
- Underground career, garage, customization, options persist in save/.
- Gate: save, reload the page, continue the career.

## M8 Widescreen
- 16:9, wider horizontal view, HUD placed for it. Every change is a `PATCH:` line. Gate: a race in 16:9.

## M9 Play
- The OWNER plays the career at http://127.0.0.1:5180/.

## Only when a run hits it
- Known layer gaps: GetMessageA that would wait (0x411030, window inactive), SuspendThread of a running thread
  (0x448d00, 0x5a4a50), D3D9 device lost / Reset (0x4016e0 -> 0x40a4e0). Fix one when a run stops on it.
- Speed: only when the OWNER feels lag. Then measure hitches over 33 ms first; candidates are -O2 for build/gen,
  fewer CHK, x87 state in locals, GIL hand-offs (audio thread 0x654a90 wakes every 10 ms).
- New lifter bug -> fix it in tools/recomp with the difftest (RN_ONLY trace).
