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
