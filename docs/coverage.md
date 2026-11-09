# Coverage: how much of the real game this port actually is

Three different questions wear the same word. They have three different answers, and mixing them is how a port lies to
itself about its own state.

| Question | Answer | Where it comes from |
|---|---|---|
| How much of Speed.exe is lifted to C? | 13,757 functions, 0 failed; 615 seeds dropped as data, not code (quote no %) | `census/lift_report.json`, `tools/recomp/build.py` |
| How much of it runs in a session? | not measured yet: the counter in §4 only sees indirect calls, so 1,006 / 1,627 are floors | `host/dispatch.c`, §4 |
| Do all event rows still load and return to the menu? (RN_JUMP + injected finish, not played) | 167 of 167 rows (116 career, 46 quick race, 5 game), 30 tracks, 282 runs | `census/completion.json`, `tools/census/rows.py` |

Everything below is measured on `pc/Speed.exe` md5 `b6b9232c55376b3c38c56aac1f8a121d` (base 0x400000), numbers last checked 2026-11-09 against `census/lift_report.json` and `census/difftest.json`.

## 1. Static: the code that exists

`tools/recomp/build.py` lifts every function the census names, in parallel, and fails the build if one function cannot be
lifted (`failed 0`). Last build, printed by the build itself:

```
lifted 13756 functions, dropped 615 false data seeds, failed 0, trap sites 7655   # 2026-10-29 print; lift_report.json now says 13,757
ABK code modules: {'abk_files': 106, 'abk_modules': 79, 'abk_distinct_code': 23, 'abk_functions': 28}
```

- 14,330 starts in `census/speed_exe_functions.tsv` (Hopper's function list, `census/hopper/funcs.tsv` has 14,333 rows),
  plus 41 PATCH cave entries that are entered by a call (22 `entry` patches and 19 entries of multi-entry caves): 14,371 seeds.
- 615 seeds are dropped because the address lands **inside** an instruction of real code: a data pointer that Hopper or a
  vtable read as a function. The build proves it (it knows every instruction byte of every lifted body) instead of
  trusting the list.
- 28 functions are not in the exe at all: they are x86 the sound engine runs out of `game/Sound/*.abk`, lifted ahead of
  time by `tools/recomp/abk.py` (106 files, 79 modules, 23 distinct code blocks).

### Trap sites: 7,655, and the game still runs

A trap site is one instruction the lifter does not translate: it becomes code that stops the game with its address and
mnemonic when it runs (`tools/recomp/lift.py`, "An instruction the lifter does not know becomes a TRAP"). 7,655 sites,
mostly SIMD:

| Reason | Sites | Reason | Sites |
|---|---|---|---|
| `pfmul` | 1,574 | `addps` | 355 |
| `movaps` | 1,022 | `movlps` | 206 |
| `pfadd` | 860 | `pfsub` | 182 |
| `mulps` | 538 | `movhps` | 173 |
| `shufps` | 407 | `femms` | 155 |
| `movss` | 393 | `pfacc` | 134 |

They never run because of a decision, not luck: `host/cpu.c` presents a Pentium 4 (Northwood, 3.2 GHz) with FPU, TSC and
MMX and **no SSE/3DNow**, so `cpuid` sends the game down its x87 and MMX paths. MMX is reported on purpose: the movie
library's YUV→RGB `0x647cb0` returns at once when the MMX flag `[0x70fdd8]` is 0, and the title movie stays grey.
The full reason list is `census/lift_report.json` → `trap_sites_by_reason` (133 reasons).

The honest reading: the 3DNow/SSE copies of these routines exist in the binary, are lifted as traps, and are dead code
under the CPU we advertise. If a later change advertises SSE, 7,655 stops appear at once.

## 2. Differential test: does the C do what the x86 did?

`tools/recomp/difftest.py` runs every function twice, in Unicorn (real x86) and in the lifted C, from the same seeds
(`data` = read the function's bytes, `call` = call it), and compares registers, flags and memory:

| | |
|---|---|
| functions in the census | 13,841 |
| functions compared | 5,805 |
| all cases match | 5,802 |
| cases matching | 32,131 (18 mismatching cases, all in the 3 functions below) |
| cases skipped | 78,579 (`skip_unmapped` 77,165, `skip_pinned_cpu_path` 775, `skip_timeout` 474, `skip_not_a_function` 133, `skip_call_into_data` 16, `skip_ret_imm16_sign` 16) |

The gate field in `census/difftest.json` says **pass** (regenerated 2026-11-07): 3 functions disagree, all documented reference deviations.

| Function | What happens | Status |
|---|---|---|
| `0x642774` | `F6 /1` is `TEST` on real CPUs (undocumented alias); QEMU 5 calls it invalid | documented reference deviation |
| `0x673824` | `FPREM` with invalid operands: the SDM gives −NaN, QEMU 5 gives +NaN | documented reference deviation |
| `0x67ca06` | `FPREM` on unsupported 80-bit encodings: the SDM gives −NaN, QEMU 5 gives +NaN | documented reference deviation |
| `0x67a337` | the reference retires into `0x6728cc`; there is no lifted function there | **fixed 2026-11-06** (lift.py body() reads `neg idx` tables downward; matches in the regenerated census/difftest.json). Was: real lifter gap. CRT memmove `0x672630` copies backward and jumps through a table that is indexed negatively (`neg ecx; jmp [ecx*4+0x6728c8]`, entries at `0x6728ac..0x6728c8`); `Lifter.table()` (lift.py:177) reads only forward, so those 7 labels are missing and the case falls to `rn_call`. Same pattern in the second CRT copy `0x678d30` (table `0x678fac`). Direct memmove probe: 224 of 312 overlapping backward copies of 4..34 bytes stop. Evidence: docs/re/audit/diag_67a337.md |

So the port's honest number is 5,802 of 5,805 matching, and the other 3 are reference deviations, not lifter gaps.

The comparison is only 5,805 of 13,841 functions because most functions cannot be called from a synthetic seed without a
real object graph: the skip reasons above are the exact list, not a shrug.

## 3. Imports: what the game asks Windows for

`census/imports_sites.tsv` (Capstone over the frontend-reached instructions + the PE import table):

- 254 imports in the PE, 225 with a resolved static call site, 4,780 indirect transfers the CFG cannot resolve.
- 198 of those 225 are implemented in `host/` (`win32.c`, `user32.c`, `threads.c`, `d3d9.c`, `dinput8.c`, `dsound.c`,
  `net.c`, `rivals.c`, `free.c`).
- The 27 missing are 25 `ws2_32` (socket/online/LAN, out of scope by decision), `kernel32!SetConsoleMode`, and
  `dsound.dll!#1` (an ordinal import the sound engine resolves by number).
- A missing import does not fail silently: `host/dispatch.c` stops the game with `missing API <dll>!<name>` and the
  return address.

## 4. Dynamic: how much of the game a session touches

**CORRECTION (2026-10-29 audit, docs/re_scoreboard.md §2): the counter below undercounts.** It sets its bit inside
`rn_call`, but the lifter emits direct calls as plain C (`f_674898(c);`, `tools/recomp/lift.py:294`); only indirect
calls and jumps reach `rn_call`. The numbers in this section are floors, and "88 % has not run" is not supported.
Fix: count at function entry behind `RN_COV=1`.

`host/dispatch.c` keeps one bit per entry of the dispatch table (`rn_fn_addr`, 13,756 entries) and
sets it the first time `rn_call` resolves an address to that function. The bitmap is 1.7 KB, the hit test is one load
and one test, and the store happens once per function, so the cost on the hot path is a predictable branch. The count
comes out three ways:

- `dispatch_report()` prints `coverage: N of 13756 guest functions ran (P%)` at every halt and on `RN_SECS`.
- `rn_cov_hits()` / `rn_cov_total()` are exported to the page.
- `web/telemetry.js` adds it to the session file (F10) as `summary.coverage`, and to the log on `pagehide`.

Measured (headless Chrome, `chrome-bot`, Apple metal-3, 1280x900, session file from F10 in `build/dl/`):

| Run | Guest functions | Share |
|---|---|---|
| 35 s at the title screen (menus, movie, frontend) | 1,006 | 7.3 % |
| 100 s: title → profile → Quick Race, Olympic Square, ~25 s of racing | 1,627 | 11.8 % |

The second row shows a race adds at least 621 indirectly-entered functions to the 1,006 the menus touched. It says
nothing about the share of the exe that ran (see the correction above).

## 5. Played: the career census

`tools/census/rows.py` drives the game through every career row with `RN_JUMP` (start an event through the game's own
function) and an injected finish, and records what it saw. `census/completion.json`, 282 runs:

| Stage reached | Runs | | |
|---|---|---|---|
| menu | 272 / 282 | racing | 255 / 282 |
| results | 215 / 282 | back to menu | 203 / 282 |
| unload | 202 / 282 | second race | 12 / 282 |

167 of 167 rows (116 career, 46 quick race, 5 game), 30 distinct tracks, 18,315 screenshots. 167/167 is a **regression guard**: it proves no row was
broken by a change, not that a human played it. The OWNER's own playthrough is the other half, and it lives in
`build/web.log`.

## 6. Patches: the game's own numbers, moved on purpose

361 active patches (`census/lift_report.json` → `patches`, table in `tools/recomp/patches.py`), each one line with why:
widescreen and 1920x1080 device creation (`0x408a24`), the 60 fps limiter (`0x585b94`), the car's reflection at 0.5
(`0x40fbb7` reads `0x707fc4`), the remaster switches. A patch is not a hole in the lift: it is a value the game reads,
changed with its address written down.

## 7. Measure it again

```sh
.venv/bin/python tools/recomp/build.py web        # prints lifted / dropped / failed / trap sites
.venv/bin/python tools/recomp/difftest.py         # full differential test -> census/difftest.json
RN_ONLY=0x401000 .venv/bin/python tools/recomp/difftest.py   # one function, seconds
node tools/webcheck.mjs --route                   # the route; the session file lands in build/dl after F10
.venv/bin/python tools/census/rows.py             # the 167-row career census
```

## 8. What this does not cover

- No number for "how much of the *game* runs" beyond one route and one career census; the counter now makes that
  measurable per session, and it needs sessions.
- 4,780 indirect transfers are resolved at run time, not statically: a coverage number counts what ran, never what could.
- The difftest cannot seed object-graph functions, so about 8,000 functions have no comparison.
- Online/LAN is not implemented (25 `ws2_32` imports) and is out of scope.
- No WebGL2 renderer: the port needs WebGPU (~86 % of browsers).
