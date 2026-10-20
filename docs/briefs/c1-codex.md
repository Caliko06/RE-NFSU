# C1: census lane (Codex). Mechanical work only, no decisions about game or layer behavior.
Worktree ~/RE-NFSU-wt/census, branch w-census. First: `git merge main` (it has your tasks 1-5, merged).
Python: ~/RE-NFSU/.venv/bin/python (capstone, pefile).
Write only new files under census/ and tools/census/. Never edit host/, tools/recomp/, web/, game/, pc/, ref/.
Every output says where each fact comes from (file + offset, or doc URL/section). Never guess a value: write "unknown".
Same format as tasks 1-5 (merged): header with how it was made, counts, sources per entry. That format was right.

## Tasks (do them in order, one commit each)
6. census/d3d9_formats.json: every D3DFORMAT in d3d9types.h (name, numeric value or FOURCC with its four chars),
   bits per pixel or bytes per 4x4 block, channel bit masks or layout, and whether it is a depth/stencil, index,
   vertex-data or compressed format. Sources: d3d9types.h line, D3DFORMAT docs page section.
7. census/dinput_keys.json: every DIK_* code in dinput.h with its value, the matching Win32 VK_* code and scan code
   (Win32 docs), and the KeyboardEvent.code string (W3C "UI Events KeyboardEvent code Values", section). If a code has
   no documented match, write "unknown". Also the DIMOFS_* offsets and DIMOUSESTATE/DIMOUSESTATE2 layouts.
8. census/dsound_consts.json: from dsound.h and the DirectSound docs: DS_OK and every DSERR_* (HRESULT hex),
   DSSCL_*, DSBCAPS_*, DSBPLAY_*, DSBSTATUS_*, DSBLOCK_*, DSBVOLUME/DSBPAN/DSBFREQUENCY limits, and the field
   layout (offset, size) of DSBUFFERDESC, DSCAPS, DSBCAPS, WAVEFORMATEX.

## Done
Each file exists, a short header line says how it was made, and the commit message lists the files with counts.
