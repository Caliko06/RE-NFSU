# Prior art: how NFSU2Recomp loads and draws the world

Source: https://github.com/TalhaMudo/NFSU2Recomp (commit `9d0fe21`). Read: README, file tree, `runtime/com.c`, `runtime/metal.m`, `runtime/overrides.c`, `runtime/fileio.c`, `run.sh`. Not quoted here = UNKNOWN.

**Answer:** it has no world loader and no track decoder of its own. It lifts the original `SPEED2.EXE` (23,278 x86 functions to C) and lets the game's own code open the game files and issue Direct3D 9 draws; the runtime replaces only Win32 (files, memory) and D3D9 (Metal).

| Layer | What does it | Evidence |
|---|---|---|
| Lift x86 to C | `tools/reloc2.py` (91,106 absolute addresses), `tools/genall.py` + `tools/lift.py` | README "How it works" |
| Generated code | `gen/all/shard_*.c` (128 files) + `fntab.c` (guest addr to native fn) | README "How it works" |
| Find files on disk | `runtime/fileio.c` maps Win32 paths into game-folder paths (`resolve_in`, `fileio_resolve_read`) | `runtime/fileio.c:78,224` |
| Read files | lifted game code calls the Win32 wrappers (`fileio_call`, `fileio_call_impl`) | `runtime/fileio.c:353,367` |
| Guest memory | 32-bit space reserved with `mmap`, `runtime/mem.c` | README "How it works" |
| D3D9 device | `runtime/com.c` hooks the device vtable, dispatches by method id (`MID_DrawIndexedPrimitive`, `MID_DrawPrimitiveUP`, `MID_SetStreamSource`, `MID_SetIndices`) | `runtime/com.c:680-714, 811-845, 2719, 2767, 3146` |
| 3D geometry | `DrawIndexedPrimitive` + SetStreamSource/SetIndices; static VB/IB mirrored in a persistent pool, else index-expansion fallback | `runtime/com.c:494-495, 2046-2050` |
| UI | `DrawPrimitiveUP` with raw, non-transformed positions | `runtime/com.c:461-465` |
| Vertex shaders | run on the CPU, `runtime/vsemu.c`; vs/ps 1.x-2.x to MSL | `runtime/com.c:461-465`, README |
| Textures | `CreateTexture`/`LockRect`/`UnlockRect` to `metal_upload_texture` | `runtime/com.c:56, 688-689, 714` |
| Render state | `D3DRS_CULLMODE` applied by `metal_set_cull` | `runtime/com.c:979-985` |
| Encode to Metal | `runtime/metal.m` (one 558 KB file) builds the draw list, encodes Metal passes | `runtime/metal.m:1022, 2638` |
| Camera matrices | captured, not changed: `sub_005c7ed0`, `eView+0x40` Camera (`+0xbc` NearZ, `+0xc0` FarZ, `+0xc4` FOV) | `runtime/overrides.c:648-668` |
| D3DX effects | `runtime/d3dx_hle.c` short-circuits the framework (~47 % of guest time) | README, `D3DX_HLE.md` |

**What it patches.** FIXMAT (`run.sh:64-68, 85-87`): the front-end world-view-projection matrix arrives broken (only rows 2 and 3 written, 0-1 zero), every vertex collapses to (1,1), `FIXMAT_MODE=3` injects an identity matrix because "the raw positions are already in clip space"; root cause unknown, still shipped. Also region switch (`GA(0x7fa73cu)`, `runtime/overrides.c:308-320`), frame rate, car shadow height, logo/sponsor screens, rain/sky forcing (`runtime/overrides.c:308-645`).

| Missing / open | Source |
|---|---|
| SEH not implemented (`RtlUnwind`/`RaiseException` are stubs) | README "Known limitations" |
| x87 as 64-bit doubles, not 80-bit; ~310 rare opcodes still traps | idem |
| Crowds / skinned meshes unverified against Windows | idem |
| Track/world file formats: no decoder in the files read | INFERENCE (fileio.c is path/handle only) |
| Full open world streaming while driving | UNKNOWN |

**For NFSU1+UG2.** Useful part: the split is confirmed, file layer (`fileio.c`) plus D3D9-to-Metal layer (`com.c` + `metal.m`); the world comes from the game's own loaders, so no BUN/LZC parser is needed to render. Their transform handling is not a reference (identity-matrix workaround on a broken WVP front end). Code is not reusable: repo is not open source (`LICENSE`).
