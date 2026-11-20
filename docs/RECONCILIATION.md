# RE-NFSU Reconciliation Notebook

Forensic audit and reconciliation ledger for **RE-NFSU** (`https://nfsu.cc`, static x86-to-WebAssembly recompilation of *Need for Speed: Underground* 2003).  
Date: **2026-11-20** · Baseline commit: `03d16cf` (`main`)

---

## 1. Executive Snapshot (Verified Numbers)

| Layer | Location | Verified State (2026-11-20) | Health |
|---|---|---|---|
| **Static Recompiler (x86 → WASM)** | `tools/recomp/` (23 active files) | **13,765** lifted functions, **0** failed, **375** active patches (after retiring Minecraft's 2 patches), **0** unintended overlaps | Healthy |
| **Reference Parity (Unicorn x86)** | `census/difftest.json` | **5,802 / 5,805** exact match (3 documented QEMU deviations, `gate: pass`) | Healthy |
| **Win32 / DirectX 9 Host (C)** | `host/` (28 compiled C files, ~14.8k LOC) | `emcc -O2 -pthread -fsyntax-only` passes 28/28 with 0 errors | Healthy |
| **WebGPU / WebGL 2 Renderer (JS)** | `web/gpu.js`, `web/webgpu_gl.js` | Per-draw GC allocations eliminated; 4 WebGL 2 state/cache risks closed (`glcheck.mjs` 13/13) | Fixed locally (needs Safari re-measurement) |
| **Public Static Package (`dist/`)** | `dist/manifest.json` (`v=57b56505a3`) | **5,589** files, **2.067 GB** (`1.925 GiB`); `speed.wasm` 67 MB raw / 16 MB gzip (`0a4e664a...`) | In sync with `web/` (needs rebuild after these edits) |

---

## 2. Reconciliation Ledger (Before → After)

| # | Area | Forensic Finding (Before) | Root Cause / Why It Matters (ELI5) | Action Taken (After) | Verification |
|---|---|---|---|---|---|
| **R1** | **Safari / iPhone XR OOM** (`web/gpu.js`) | JS heap grew to 6–9 GB in racing until WebKit killed the tab. `logs/ch_hp3.heap.json` showed **2,113 MB** allocated in 12 s, with `web/gpu.js` causing **69.7%** (1,472 MB: `runList` 968.9 MB, `pipeline` 280.9 MB, `sampler` 222.4 MB). | Every draw call (hundreds per frame at 60 fps) allocated throwaway closures, arrays, `.subarray()` views, and template strings. Chrome's V8 swept them fast enough to hide the leak; Safari's WebKit/JSC (`bmalloc`) fell behind and got killed by the OS. | Eliminated per-draw allocations: 28-bit packed integer key in `samplerFrom(w, to)`; zero-alloc nested `Map` trie + integer `tag` fast-reject in `pipeline()`; hoisted `UOFF_ARR`/`BF_ARR`, integer `passRt`/`passDs`, scalar viewport/scissor comparisons, direct `for` loops for uniform floats, and nested `Map` trie for `texBinds` (allocates `entries` only on cache miss). | Syntax verified; mock `runList` cache-hit test passed; **next**: re-run WebKit footprint gate (`<= 1.5 GB` flat at race+60 s). |
| **R2** | **WebGL 2 Polyfill Risks** (`web/webgpu_gl.js`) | Audit of the WebGL 2 state-caching layer flagged 4 real edge-case bugs. | Cached GL state could go stale after GPU context loss or shader relinking, or collide on large binding indices / multiple devices. | (a) Added `gl._resetSameState()` hooked to `webglcontextlost` and `webglcontextrestored`; (b) scoped `colorSamplerFor` via `WeakMap` on `device._colorSamplerBySamp` with 6-field descriptor verification; (c) replaced `index * 4096 + binding` with nested `Map` in `texBinding`; (d) wrapped `gl.linkProgram` to invalidate `uloc` caches via `_linkVer`. | `glcheck.mjs` 13/13 pipelines compile; Node mock tests pass for all 4 cases. |
| **R3** | **Plan State Drift** (`web/plan/plan.json`) | Row 11 ("Search engines") had `"done": "False"` (string, truthy in JS/Python); Row 3 still reported old `dist/` size (`1.95 GB`, `5219 files`, with retired `ug2/`). | Stale manual edits left type/number drift in the single source of truth. | Fixed Row 11 to boolean `false`; updated Row 3 `ev` with actual `dist/manifest.json` numbers (`5,589 files, 2.067 GB / 1.925 GiB`, `data-chunks/` 240.1 MB, `ug2/` retired). | `python3 -m json.tool web/plan/plan.json` OK. |
| **R4** | **Git History Rewrite Drift** (`HANDOFF.md`) | Cited 4 commit hashes (`5a39e1d`, `a9dc277`, `3b198e6`, `9ca97e1`) that no longer exist on `main` (orphaned on `backup/pre-rewrite` after `3b149fb`), and referenced `step 2 row 4` instead of `row 5` for Safari. | Rewriting history to exclude internal notes changed commit SHAs without updating the handoff map. | Replaced with actual `main` hashes (`b03b27d`, `d1cef60`, `64ea385`, `90fd853`) and corrected row reference to `step 2 row 5` (kept at 14 lines). | All 4 hashes verified on `main` via `git branch --contains`. |
| **R5** | **Rejected Minecraft Lane Still Built** (`tools/recomp/patches_mc.py`, `host/mc.c`) | Even though `RN_MC` was rejected and defaulted to `0`, `patches_mc.py` still patched `0x4479be` + cave `0x797600`, and `build.py` still compiled `host/mc.c` (246 LOC) into `speed.wasm`. | Dead code ran a hook on every main-loop frame and widened the binary patch surface unnecessarily. | Moved `host/mc.c`, `host/mc.h`, `tools/recomp/patches_mc.py` to `attic/mc/` with `attic/mc/README.md`; removed hooks from `patches.py`, `build.py`, `host/{host.h,dispatch.c,win32.c,input.c,d3d9.c}` and `web/mode.js`. | `patches.active()` = **375** (0 errors); 0 dangling refs; `emcc -fsyntax-only` passes 28/28 `host/*.c`. |

---

## 3. Open Items & Known Technical Debt

1. **WebKit Footprint Re-Measurement (Gate)**: Rebuild `speed.wasm` without `host/mc.c` and run `tools/webkit/wk.mjs` + `vmmap` to verify Safari racing stays flat (`<= 1.5 GB`) after R1.
2. **Pre-existing Native Build Warning in `host/files.c:402-404`**: `clang -fsyntax-only` (non-Emscripten) flags `__EMSCRIPTEN__`-gated symbols (`pre_head`, `pre_tail`, `preq`, `NQ`, `rn_load`, `queued_id`). Web/Emscripten build (`emcc`) is unaffected.
3. **Opt-in Max Payne (`?max=1`)**: `web/maxpayne/` reads `_rn_mc_state()` from `host/mc.c`; it is paused while the retired pedestrian lane stays in `attic/mc/`.
