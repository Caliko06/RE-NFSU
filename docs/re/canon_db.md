# Canon database of Speed.exe

Answer first: every lifted function now has one place to read it named. `census/canon/c/<range>.c` is Ghidra pseudocode
with every known name applied (callees show as `TrafficTeleporter::PlaceCar`, not `FUN_00598bf0`), and
`census/canon/funcs.jsonl` has one row per function: size, callers, callees, globals read/written, strings. The work
queue `census/canon/queue.tsv` lists what is still unnamed, bottom-up, with a prior-art hint when one exists.

## Why
Before this, names lived only in census/names_*.tsv and every export (census/ghidra, census/hopper) still said
`FUN_`/`sub_`. Each session re-read raw code and guessed. Ghidra also lacked 3,935 of the 13,739 lifted starts.

## Pieces (tools/canon/)
| Step | Command | Output |
|---|---|---|
| Merge names + systems, create missing functions, rename, plate comments | `.venv/bin/python tools/canon/canon.py apply` | build/ghidra/canon (writable clone of build/ghidra/proj), build/canon/apply.txt |
| Export, 4 Ghidra clones in parallel (~80 s) | `canon.py export -j 4` | census/canon/c/*.c, funcs.jsonl, data.jsonl (globals with readers/writers, 216 vtable candidates) |
| Prior art: NFSMW PC 1.3 symbols, x86 to x86 | `tools/canon/prior.py mw` | census/canon/prior_mw.tsv (153 names, mostly CRT/libs: the engine drifted too much) |
| Prior art: NFSU GameCube prototype symbols, link-order alignment | `tools/canon/gcalign.py` (`--holdout K` to measure) | census/canon/prior_gc.tsv |
| Queue | `canon.py queue` | census/canon/queue.tsv + per-system total/done/ready/blocked |

Apply on 2026-10-29: 3,299 functions created, 826 lifter starts sit inside a Ghidra function with no call into them
(left as is, listed in apply.txt), 179 failed to create, 1,534 names applied. 890 lifted starts are not in the export.

## Prior art (fetched to build/prior/, gitignored; read-only reference)
- github.com/dbalatoni13/nfsug `config/GNDP8P/symbols.txt`, `splits.txt`: the GameCube prototype of Sep 10 2003, same
  source as our PC build two months earlier. 10,086 named functions (mangled C++ with argument types), 741 source files.
- github.com/dbalatoni13/nfsmw `config/SPEED_EXE_1_3/symbols.json`: 14,327 names for the MW PC 1.3 exe. Its layout
  matches ~/RE-NFSMW/pc/Speed.exe exactly (sections 0x401000/0x890000/0x8ea000), so it names that repo directly.

## GameCube alignment: what it is worth (measured, gcalign.py --holdout)
Anchors are our names whose demangled GC name is unique: 369, of which 321 lie on one increasing run (the PC link order
follows the GC one; outliers are mostly destructors and inline methods MSVC emits elsewhere). Between anchors,
Needleman-Wunsch on log sizes (PC/GC size ratio 0.95, sd 0.69), then strong pairs become anchors (4 rounds).
| Grade | Meaning | Hidden anchors recovered |
|---|---|---|
| A | interval with equal counts, every pair in the size band | 40/41, 24/24 |
| R | diagonal run of >= 4 and in band | 60-73 % |
| B | DP pair in band | 67-80 % |
| S / X | a string the function references names its GC class / names another class | not measured (82 rows) |
| P | GC translation unit is GameCube-only (platform, SDK, MSL): the PC has different code there | not a name |
| source file (TU) | any grade | 94-95 % (137/144 with half the anchors hidden) |

So: A and S are names (mark I, tool `nfsug-align`; V only after reading). R/B are hints to confirm by reading. The
source file is reliable enough to set the system of unknown functions.

## Naming waves (Sonnet sessions, docs/re/canon_wave.md)
Take ready rows (open_callees = 0) of one system from queue.tsv, read the named pseudocode, confirm or reject the
prior hint, write rows to census/names_<system>.tsv (V when read, with the GC name when it fits), then
`canon.py apply && canon.py export && canon.py queue`: callers now read with the new names, and more rows turn ready.

## Systems from source files (tools/canon/tu_systems.py, 2026-10-29)
143 of 910 unknown functions get a system from their GameCube source file (file vote >= 4 and >= 70 %, else directory
vote; GameCube-only files skipped: an earlier pass that kept dolphinsdk gave 111 weak "render" rows). Written to
census/canon/systems_tu.tsv, read by the scoreboard as med. 767 stay unknown (357 > 64 bytes): they need reading.

## Round 1 lessons (canon-sonnet, 180 rows)
- GC hints on small leaves were mostly wrong (2 A hints were 16-byte getters matched to constructors): the holdout was
  measured on named anchors, which are larger. Queue now hides GC hints under 48 bytes.
- Round 2 (>= 48 B): hints taken/rejected A 0/1, R 10/16, B 6/23; wrong B hints were often the neighbour. `canon.py show`
  now prints a GC window (aligned symbol +-3, mangled names with argument types) instead of trusting one name.
- 888 lifted starts are not Ghidra functions (882 inside another function): census/canon/fragments.tsv with the parent;
  out of the queue. They count as parts of their parent, not as work.
- Round 3 (>= 48 B, with GC window): R 17/27, B 6/15; car aligned well (R 15/19), audio and rivals badly; the right name
  was often outside the window. `canon.py show` now also lists "GC free in file": GC methods of the same source file not
  yet taken by any PC name, nearest size first. gcalign reads the merged names_*.tsv (wave names become anchors:
  321 -> 443) and demangles nested scopes (Q<n>), so Realmc::GCInterface names anchor too.
- Round 5 (file batches): R 24/33, B 21/38 taken. AIAction family 0x44e260-0x4512f0 was labelled AICarController.cpp by a
  bad alignment stretch; the round's own names re-anchored it to AIPlan.cpp (GC split 0x8004bb5c-0x80055ed8). Overloads
  (same Class::method twice in GC) anchor when the evidence cites the mangled name. Holdout 1/2 after: file 293/304, A 92/94.
- Rounds 7-9 (canon-sonnet-c1): 2,511 -> 3,051 named, anchors 1,147. Hints are good where PC and GC order agree
  (CollisionBody, saems, CameraMover) and fail where the PC reorders (FEPkg_PostRace R 28 %, Race 0 %, MU_Options):
  workers name those from vtable slot order and dispatch tables. "GC free in file" now lists 16 candidates (was 8).
- Vtables (2026-10-29, Opus slice): Canon.java finds them by constructor writes (`mov [reg+off], imm` of a data address
  whose first dword points into code; ESP/EBP stores skipped), sized up to the next vtable or referenced address:
  434 tables, 3,948 slots (old run scan: 216, merged neighbours). `canon.py apply` runs `vtscan`, which creates slot
  functions Ghidra lacks (only 1 was missing). tools/canon/vtables.py --check: 79/88 = 90 % (was 5/18) after
  normalizing notes "(...)", destructor forms (~X, scalar deleting) and keeping descriptive placeholders (NopArg1,
  ResetField1D4) out of the vote. Wired: queue.tsv prior "vt <name>" (40 rows: 19 new, 9 equal GC, 12 replace GC),
  shown for every size. The 9 disagreements (sibling classes naming one slot differently) are in census/canon/vt_check.txt.

## Trivial functions (tools/canon/trivial.py, 2026-10-29)
Unnamed lifted functions of <= 48 bytes with an exact MSVC shape, read in bytes with capstone, go to
census/names_trivial.tsv with evidence `V: trivial: ...` (or I when the system comes only from callers). Shapes: jmp
thunk, scalar deleting destructor, vtable-setting destructor, EH stub (`mov eax,FuncInfo; jmp ___CxxFrameHandler`),
EH unwind funclet, static initializer, getter/setter, bare ret. EH parents come from FuncInfo (magic 0x19930520)
unwind maps and the stub's pusher; all 309 stub parents were checked in bytes (`push -1; push stub` or
`mov eax,stub; call __EH_prolog`). The system comes from structure (target, parent, destructor, readers of the global);
no solid system means no row. Second pass adds: any function listed as an unwind action in a FuncInfo, import thunks
(`jmp [IAT]`, system by DLL), static constructors and `push dtor; call _atexit 0x67100d`, initializers of globals no code
reads (called only from the CRT table at 0x6d49xx; system runtime, I), every MSVC scalar-deleting-destructor form,
<= 3-instruction leaves (system by callers, I), int3 padding. 2026-10-29: 1,742 rows (1,255 V); 1,975 small functions
still have no shape and 745 have a shape but no solid system.

tu_systems.py also writes low graph tags that the source-file vote confirms (878 on 2026-10-29); the scoreboard reads
them as med. Holdout of the file vote on known functions: 2,513 of 2,851 agree (88 %).

## Code with no GameCube file (tools/canon/libs.py, 2026-10-29)
Four regions have no GC source file: PC d3d9 renderer 0x5a0000-0x640000, EA sound library 0x640000-0x662800,
DirtySock/ProtoSSL 0x662800-0x670800 (online), MSVC CRT 0x670800-0x684000. Region membership alone is not a system
(each region mixes runtime with its own system), so an untagged function takes the system of its call-graph neighbours
inside the same region (>= 70 % and >= 2, or all of them), repeated; DirtySock seeds are functions that reference its
strings or call WS2_32/TAPI32 imports. One-step leave-one-out on known functions: 394/415 (95 %). Output
census/canon/systems_lib.tsv (1,538 rows, read by the scoreboard as med) and census/names_lib.tsv (153 Ghidra FID
names in the CRT region, I). 749 region functions stay untagged (most have no code callers: vtable or callback entries).
