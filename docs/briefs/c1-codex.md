# C1: census lane (Codex). Mechanical work only, no decisions about game or layer behavior.
Worktree ~/RE-NFSU-wt/census, branch w-census. Python: ~/RE-NFSU/.venv/bin/python (capstone, pefile).
Write only new files under census/ and tools/census/. Never edit host/, tools/recomp/, web/, game/, pc/, ref/.
Every output says where each fact comes from (file + offset, or doc URL/section). Never guess a value: write "unknown".

## Tasks (do them in order, one commit each)
1. census/imports_sites.tsv: every call site of every import in pc/Speed.exe (site address, containing function from
   census/speed_exe_functions.tsv, dll!name). Script: tools/census/imports_sites.py.
2. census/registry.txt: every registry key and value name string in pc/Speed.exe (address + text) and every registry
   write in the installer files in game/ (setup.exe strings, .inf/.ini/.iss data): key, value name, type, value.
3. census/game_files.json: game/ inventory: path, size, first 16 bytes (hex), extension; plus which file names or
   extensions Speed.exe references as strings (address). Script: tools/census/game_files.py.
4. census/d3d9_sm1.json: from the DirectX 9 SDK documentation (cite each section): vs_1_1 and ps_1_0..ps_1_4
   instructions: opcode token value, operand count, destination write masks, source modifiers, version limits.
5. census/d3d9_states.json: from the D3D9 docs: every D3DRENDERSTATETYPE, D3DSAMPLERSTATETYPE,
   D3DTEXTURESTAGESTATETYPE value with its name, numeric id and documented default.

## Done
Each file exists, a short header line says how it was made, and the commit message lists the files with counts.
