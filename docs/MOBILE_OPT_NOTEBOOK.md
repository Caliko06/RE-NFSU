# Mobile & Fast-Load Optimization Notebook (Phases 1 + 2)

## Governing Principle (`AGENTS.md` — Agencia Default)
> **Default (OWNER 2026-11-13):** work directly in the session, delegate to `cdx` or `bec` only when it saves time, no board or auditor. The full team below runs only when the OWNER asks for it.

**Application:** The OWNER explicitly authorized full Agencia delegation (Becarios in parallel, Swarm, Codex Angel, Claude subagents) for Phases 1 + 2 on 2026-11-20. We apply the org chart cleanly:
- **Orchestrator (this session):** owns the plan, verifies all slices, merges into `main`, updates `plan.json` / `HANDOFF.md`, never pushes/deploys without explicit OWNER go.
- **Becarios (parallel read-only):** `becario-mem` (memory/stack/thread safety proof), `becario-net` (raw Range 206, `CARS_TEXTURES.BIN` x16, and `Movies/` audit).
- **Leads (disjoint `share` workspaces):**
  - **Slice 1 (Claude — `lead-mem`):** WASM memory, stacks, pthread pool, rebuild `speed.wasm`.
  - **Slice 2 (Claude — `lead-net`):** Parallel boot (`Speed.exe` + `speed.wasm`), worker manifest dedup, `CARS_TEXTURES.BIN` x16 fix, mobile `cars_hook` / `NPRE` throttling.
  - **Slice 3 (Codex Angel / Swarm — `lead-dist`):** `data-chunks` coverage for uncompressed cars, gzip `Speed.exe`, CDN `immutable` headers in `tools/upload_r2.sh`, `manifest.json` upload exclusion.

---

## Baseline Evidence (Measured)
Source: `logs/lanes_live.json` (cold visit to `https://nfsu.cc/` -> Free Run HUD), `tools/recomp/build.py`, `host/host.h`, `host/threads.c`, `host/files.c`, `tools/upload_r2.sh`.

| Metric | Current Baseline | Root Cause (`file:line`) | Target |
|---|---|---|---|
| WASM linear memory | `2048 MB` fixed SAB | `tools/recomp/build.py:183` (`-sINITIAL_MEMORY=2048MB`) | `640 MB` |
| Guest address space | `1024 MB` (`sbrk` at boot) | `host/host.h:11` (`GUEST_MEM=0x40000000`), `host/main.c:187` | `384 MB` (measured use: ~45 MB) |
| Thread stacks | `16 MB` x `12` = `192 MB` | `build.py:183`, `host/threads.c:285` | `4 MB` x `8` = `32 MB` |
| Boot worker pool | `12` workers (`speed.js` x14) | `build.py:184` (`-sPTHREAD_POOL_SIZE=12`) | `8` workers (`RN_NPRE=2` on phone) |
| Cold wire transfer | `130.13 MB` / `273` reqs | `logs/lanes_live.json` (`Cars/` raw 23.8 MB, `Speed.exe` raw 3.18 MB) | `< 90 MB`, 0 raw race car `GEOMETRY.BIN` |
| Duplicate requests | `CARS_TEXTURES.BIN` x16, `data-chunks.json` x5, `game-files.json` x3 | `host/files.c:80-126`, `host/trackfiles.c` | x1 each |
| Boot waterfall | `Speed.exe` -> then `speed.wasm` (serial) | `web/boot.js:111-124` | Parallel fetch + gzip `Speed.exe` |
| CDN Cache-Control | `max-age=86400` on immutable SHA chunks & `game/*`; `no-cache` on `?v=` wasm | `tools/upload_r2.sh:11-29` | `max-age=31536000, immutable` on chunks & `game/*` |

---

## Verification Results (2026-11-20)
1. **Build:** `RN_JOBS=4 .venv/bin/python tools/recomp/build.py web` -> exit 0 (`patches active: 375`, `13,764` lifted functions, `0` failed, `INITIAL_MEMORY=1073741824`, `PTHREAD_POOL_SIZE=9`, `4 MB` stacks, `_rn_mc_state` removed).
2. **Public Pack:** `python3 tools/build_public.py` -> exit 0 (`data-chunks: 455 read pieces`, `505.2 MB` source -> `273.4 MB` gzip; `dist/ ready: 5677 files, 2.10 GB, 419 game files indexed`; `missed /Cars/ 206s in lanes_live.json: 0`).
3. **End-to-End Route Check:** `RN_URL='http://127.0.0.1:5184/?play=1&mute=1' node tools/webcheck.mjs --route` (via `macgate.sh`) -> **PASS (exit 0)** in `72.2 s`, `0 STOP`, `0` memory faults. `mem: wasm break` dropped from **1,360–1,548 MB** to **585 MB** (`guest heap 45 MB`, `guest virtual 7 MB`).
4. **Still Open (Next):**
   - WebKit/Safari race footprint test (`tools/webkit/wk.mjs` + `vmmap`) to verify `<= 1.5 GB` flat.
   - Phase 3 (GPU mobile: lazy shaders in `web/gpu.js`, `960x540` WebGL2 cap, DXT/mip cap).
   - R2 deploy + git push ONLY after explicit OWNER go.
