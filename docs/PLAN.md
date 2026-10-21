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
- Quick Race: the circuit loads and runs (done 2026-10-20); next: the car drives, the race ends, back to the menu.
- Gate: one full race in Chrome without a stop.

## M7 Career and saves
- Underground career, garage, customization, options persist in save/.
- Gate: save, reload the page, continue the career.

## M8 Screen and widescreen (each step has one gate, a capture in Chrome at http://127.0.0.1:5180/)
- M8.1 Big screen: the canvas fills the window, aspect kept, log on F2 (done 2026-10-20; build/fill.png).
- M8.2 (done 2026-10-20: PATCH 0x40877e, the race Reset is 1280x956 = the window; build/route.png) Bigger picture: the game runs at 1280x720 or more (the layer already offers modes up to 1920x1080).
  Found (REA): 0x408760 maps the game's resolution option [0x700e70] to width (eax) and height (esi) and calls 0x4086b0,
  which fills D3DPRESENT_PARAMETERS at 0x71a96c/0x71a970. Table: 640x480, 800x600, 1024x768, 1280x960, 1280x1024.
  Default 800x600 (0x408782). Enabled only if [0x71b7b0+i*4] != 0 (the layer's mode list). No patch needed for 1280x960.
  Gate: CreateDevice log shows the new size, the title and a race fill the window sharp.
- M8.3 3D aspect: already right. 0x42f020 builds the projection with H/W from 0x701038/0x701034 (REA). Horizontal FOV
  is fixed, so 16:9 shows less sky and road.
- M8.3b 2D (done 2026-10-20): the 2D layer was a 4:3 layout stretched over the back buffer. The 2D shaders are
  `mov oPos, v0` (vertices already in clip space); the sprite quad code 0x40beef makes them as x/320-1, 1-y/240.
  PATCH 0x40bf09.. (8 operands) scales x by S = (4/3)/(W/H): HUD and menus keep their shape, centred in 4:3.
  PATCH 0x408a24: the first CreateDevice uses the screen size too (it was 800x600), so the front end is 16:9.
  Captures: build/hud169.png, build/menu169.png. Route PASS.
- M8.4 HUD and menus placed for 16:9: corners anchored to the screen edges, full-screen art (title, loading) covering
  16:9 instead of 4:3 bars. Needs where the game places each element (quad positions). Gate: capture of menu, HUD, garage.
- M8.5 Route grows to 16:9: `node tools/webcheck.mjs --route` PASS at 1920x1080.

## M9 Play, ends at 5180
- The OWNER plays the career in Chrome at http://127.0.0.1:5180/, full window, 16:9.

## Only when a run hits it
- Known layer gaps: GetMessageA that would wait (0x411030, window inactive), SuspendThread of a running thread
  (0x448d00, 0x5a4a50). Fix one when a run stops on it.
- Speed: only when the OWNER feels lag. Then measure hitches over 33 ms first; candidates are -O2 for build/gen,
  fewer CHK, x87 state in locals, GIL hand-offs (audio thread 0x654a90 wakes every 10 ms).
- New lifter bug -> fix it in tools/recomp with the difftest (RN_ONLY trace).
