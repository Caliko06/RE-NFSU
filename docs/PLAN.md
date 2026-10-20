# Plan: NFSU PC 1:1 in Chrome (W1 keeps this current)
Done = the OWNER plays the career in Chrome and it behaves like the PC game. Each milestone has one gate: the run
that proves it. Lanes: W1 orchestrator, W2 D3D9, W3 Win32/input/audio, C1 Codex census (docs/briefs/).

## Done
- M0 census. M1 lifter: whole exe lifted, gate pass (census/difftest.json).
- M2 boot: CRT, threads (one GIL + 20 ms quantum), timers, no-network Winsock, files on demand (host/files.c).
- M3 first frames: window, D3D9 device, 2 Presents (frame 2 = Clear). Stop: USER32!BeginPaint (0x41116f).
- M4 part: loading screen renders (SM1 -> WGSL, textures, native = Chrome). Input and dsound -> Web Audio exist.
  Title screen renders (PATCH 0x4f5891 while MOVIES\ is missing; OWNER adds it).
  Stop: Enter -> the sound engine runs x86 code from game/Sound/*.abk (not in Speed.exe). W1: recompiler.

## M4 Front end on screen (W2 leads, W3 helps)
- W2: BeginPaint/EndPaint/ValidateRect; vs_1_1 + ps_1_x bytecode -> WGSL; vertex declarations and FVF; DXT1/3/5 and
  the other formats the game creates; render/texture/sampler states -> WebGPU pipelines; locks of VB/IB/textures.
- W3: registry values of a real install; any Win32 stop on the way; file writes for the config file.
- Gate: native --shot and one Chrome capture show the EA logo / title / main menu as on a real PC
  (compare with a real-hardware capture or video: same layout, text, colors).

## M5 Interactive menus (W3 leads)
- dinput8: keyboard + mouse from browser events (shared memory, read in GetDeviceState/GetDeviceData).
- user32: key/mouse/focus messages the game reads; cursor.
- dsound -> Web Audio: secondary buffers, Lock/Unlock, play cursors, volume/pan/frequency; one AudioWorklet
  draining a ring buffer in the shared heap. Music and menu sounds play.
- Movies run as the game's own code (no host work expected); fix what stops.
- Gate: in Chrome the OWNER moves through the menus with the keyboard and hears menu music.

## M6 A race (W1 leads performance; W2/W3 fix their stops)
- Quick Race -> circuit loads, the car drives, the race ends and returns to the menu.
- Speed: build/gen at -O2, drop CHK where the address is provably in range, x87 state in locals,
  hot host paths. Measure hitches over 33 ms (lag rule), not percents.
- Gate: one full race in Chrome without a stop; hitches over 33 ms counted and reported.

## M7 Career and saves (W3)
- Save/load through the server (write endpoint, saves outside game/), profile, Underground career, garage,
  customization, options persist. Gate: save, reload the page, continue the career.

## M8 Widescreen (W1, PATCH table)
- 16:9 resolution, wider horizontal view, HUD placed for it. Every change is a `PATCH:` line. Gate: race in 16:9.

## Always
- New lifter bug -> W1 fixes it in tools/recomp with the difftest (RN_ONLY trace) and merges.
- Layer facts that are guesses today (D3D caps/modes, window message order) -> check against Wine when available.
