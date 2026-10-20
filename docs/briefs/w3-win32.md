# W3: Win32, registry, input, audio (Opus)
Worktree ~/RE-NFSU-wt/win32, branch w-win32, port 5182. First: `git merge main`.
Read AGENTS.md, HANDOFF.md, docs/PLAN.md (M4 helper, M5 lead, M7). W1 merges your branch.

## Scope (yours)
1. Registry (OWNER decision): HKLM\Software\EA Games\Need For Speed Underground and every key/value the game asks
   (RegOpenKey*, RegQueryValueExA, RN_TRACE shows them). Values = what the real installer writes: find the names in
   Speed.exe strings and the installer data in game/ (setup files, .inf/.ini), C1 census/registry.txt if present.
   Never invent a value; if one cannot be found, stop and ask the OWNER.
2. Win32 stops on the way (kernel32/user32/advapi32/winmm/shell32/shfolder), except painting (W2 owns BeginPaint etc).
3. File writes (config, saves) through tools/serve.py: a write endpoint into ~/RE-NFSU/save/ (gitignored, never
   game/). host/files.c gets write support; same code path native (writes to save/) and web.
4. Input (M5): browser keyboard/mouse -> shared memory -> dinput8 (GetDeviceState/GetDeviceData, buffered events),
   user32 key/mouse/focus messages, GetAsyncKeyState/GetKeyState.
5. Audio (M5): dsound -> Web Audio. DirectSoundCreate, primary/secondary buffers, Lock/Unlock, GetCurrentPosition,
   Play/Stop, volume/pan/frequency, notifications if used. One AudioWorklet reads a ring buffer in the shared heap.
   Native: write a WAV of what plays (off-screen, for checks).

## Rules
- Documented API behavior only. Order of window messages: documented; mark guesses for a Wine check.
- Outside your scope only what blocks you, minimal, listed for W1. Only tests that fail when it matters.

## Done
One commit per block on w-win32. Report = commit body (AGENTS.md strict rule 7): what works, numbers, next stop,
outside-scope changes.
Gate M5: in Chrome the menus react to the keyboard and menu music plays.
