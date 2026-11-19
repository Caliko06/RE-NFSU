# Claims to audit (WebGL 2 path vs Safari), 2026-11-19 night. Evidence only; approve or reject each.
Scope gate (scratchpad scope): WebKit without WebGPU reaches HUD + 60 s race, footprint <= 1.5 GB flat at race+60 s.
C1 Cause: in WebKit the page process grows until killed; it is the JS heap (logs/mh.txt: malloc_history inverted tree, JSC MarkedBlocks ~5.4 GB).
C2 Before fixes (live, WebGL 2): footprint 3.1 G at 6 s -> 8.3 G at 30 s then killed in the menus (numbers in this file's table below), page reloaded (logs/wk_live.json HUNG/RELOADED).
C3 Polyfill fixes (commit 5a39e1d, web/webgpu_gl.js lines marked RN) cut its race garbage ~700 -> ~380 MB per 12 s (logs/ch_hp2.heap.json vs logs/ch_hp3.heap.json, Chrome sampling, same JS).
C4 After fixes WebKit menus stay 1.3-1.9 GB and the race HUD is reached (logs/wk_fix2.json host 'race HUD'; logs/wk_fix4.fp), but the race still climbs to ~9 GB: GATE NOT MET.
C5 The remaining garbage is mostly web/gpu.js (runList/pipeline/sampler ~80 % in logs/ch_hp3.heap.json), and WebKit WITH WebGPU also climbs in the race (logs/wk_gpu_long.fp: 1.5 G -> 6.0 G).
C6 Chrome WebGL 2 still draws the race the same (web/plan/shots/webgl_phone_lowgc.png vs web/plan/shots/webgl_phone.png).
Before fixes footprint (WebGL 2, WebKit, local): 3s 0.7G, 6s 3.1G, 9s 3.5G, 12s 3.8G, 18s 4.6G, 24s 5.8G, 30s 8.3G (vmmap).
