# Review: address claims in race_ai.md and rivals.md (nacho, 2026-11-04)

Question: which of the 12 load-bearing addresses the other Becarios will build on actually match the code?
Method: capstone over `pc/Speed.exe` (read-only symlink) + `census/hopper/decomp.c`. Nothing was run; `game/` is not
present in this worktree, so runtime tables (`.data`/BSS values) are unreadable here. V = read at the address, I =
inference, U = doubt. Addresses in the table are the ones the docs cite, not the ones I would cite.

**Verdict: 9 match, 3 partial, 1 wrong heading.** Nothing collapses. Two things need fixing before someone patches:
`race_ai.md` (c) heading says the game rewrites `car+0x404` at **1.12 every frame** — it does not (see #13), and the
Block finder's "kind 6" is not an entrant kind (#10).

| # | claim (doc) | address cited | match | correction / evidence |
|---|---|---|---|---|
| 1 | Draft is only requested by `Racer::RunAction`, type 4, priority 100, dur -1.0, ctor 0x450400 | 0x44bc11, 0x4625a3, 0x450400 | **Y** | 13 `call [reg+0x84]` in `.text`; only 0x44bc11 is preceded by `push 4`. 0x462595 `mov ecx,0x64`, `push [0x6b75b0]` (=-1.0), `call 0x450400` at 0x4625a3. V |
| 2 | Only Pass and GetUnstuck store 0 to `action+0x1e0` | 0x450c33, 0x452181 | **Y** | Both hits real. Total is 27 byte stores to `+0x1e0`, not 24; no other store of a literal 0 exists, and 0x452981 stores `al` hardcoded to 1 at 0x45296b. V |
| 3 | Draft update: lead = own-1, rival or human, lateral overlap, gap < 6, target `lead - (20-gap)`, only if strictly lower | 0x450480, 0x6b7620, 0x6b7628 | **Y** | 0x450537 `lea ebx,[edx+esi-0x30]` = slot own-1; 0x45056b kind==2, 0x45059f kind==1; 0x4505d8 lateral sum; 0x4505eb `fcomp [0x6b7628]`=6; 0x450600 `fld 20; fsub gap; fsubp`; 0x450617 skips the store unless strictly lower. V |
| 4 | JustDrive cannot replace Draft (new action needs strictly higher priority) | 0x44bc30 | **Y** | The compare is 0x44bc70-0x44bc76 (`cmp edx,[esi+0x1f4]` / `jg`), i.e. inside the function that starts at 0x44bc30. Cite 0x44bc76. V |
| 5 | `car+0x47c` = sum over cars of 0x426300, capped 0.9, written by World::Step each step | 0x426450, 0x426300, 0x6b7b54 | **Y** | 0x426470 loop, 0x426479 `call 0x426300`, 0x4264c1 returns `[0x6b7b54]`=0.9. Three `fstp [ebx+0x47c]` in sub_420b40 (decomp 53385/53398/53412). V |
| 6 | Pair term gates: other speed >= 1, dist <= 60, cos >= 0.95, reach from speed table, falloff 1/.9/.75/.55/.3/0 | 0x706288, 0x70629c, 0x6b7b50, 0x7062b4, 0x700d3c | **partial** | All five constants exist and are used. But 0x7062b4 is a curve **descriptor** `{pairs=0x706280, n=4}` = (0,0)(1,0)(5,10)(150,60), not floats; the falloff y-array 0x700d3c is reached through the descriptor at 0x7062a0. Don't patch 0x7062b4 as data. V |
| 7 | `(1 - car+0x47c)` enters physics at 0x479160 / 0x474d40 as `[ph+0x50]+0xc` | 0x479160, 0x474d40 | **Y** | 0x4791b4 `fld [ecx+0x47c]`, 0x4791bd `fsubr [0x6cc7bc]`=1.0, 0x4791c3 store to `[edx+0xc]`, edx=`[eax+0x50]`. At 0x474d40 the same product goes to `[ph+0x28]+0xc` (0x474d70), not +0x50. V |
| 8 | Pass finder: clock `[[0x73619c]+4]` >= 5 s, slots own-1..0 (farthest first), gap>0, \|lat\|<2\*gap, reach 0x4569b0, planner 0x45bae0, gate 0x450b40, returns 200 | 0x450730 + all of them | **Y** | 0x45076f `fmul 0.00025; fcomp [0x6cc954]`=5.0; loop 0x4507c0 walks slot 0 upward and exits on first hit (0x4508d4 `mov eax,0xc8`); 0x450806 `fadd st,st` = 2*gap; all three callees present. V |
| 9 | Pass reach test = `gap < 3*(1.5*S + rel)` (doc marks it I) | 0x4569b0 | **Y** | It is literally that: 0x456a4a `fmul [0x7006f0]`=3.0, 0x456a55 `fmul [0x6cc7dc]`=0.5, 0x456a5f `fmul 3.0`, 0x456a65 `fcomp gap`. Raise it from I to V. V |
| 10 | Block finder: first car behind must be "kind 6", flag +0x1c, speed >= 10 | 0x450ec0 | **partial** | The `== 6` at 0x450f41 is the return of `0x647b70([driver+0x1d4]+0x1c)` = `[[..]+0x24]`, a driver/scene code, **not** the entrant kind. The entrant kind test is separate and is `== 1` (human, 0x450fac). Wording will mislead a patch. V |
| 11 | Block finder limits: start window 12 s, gap in (-50,0), rel > -5, non-human closing <= 2.0 s, human <= 35 m | 0x435ca0, 0x6b7644, 0x6b7640, 0x6b7638, 0x6b763c | **Y** | 0x435ca0 = `now-start < [0x700a9c]`=12.0 (+0.5 s/slot, 0x700aa0). 0x6b7644=50 (negated), 0x6b7640=-5, 0x6b7638=2.0, 0x6b763c=35. Humans additionally get a 30 s closing cap ([0x6b7634]); doc omits it. V |
| 12 | Block ceiling 0x77a340[8*aggr] = 200/200/400, read in the selector; finder reads the flag | 0x77a340, 0x77a344 | **partial** | Code is right: 0x44dbd0 `cmp edi,[edx*8+0x77a340]`, 0x450ffc/0x451261 read `[eax*8+0x77a344]`. The values 200/200/400 live in the copied tuning chunk (0x77a340 is BSS); `game/` is absent in this worktree, so unverified here. U |
| 13 | `0x44bd10` writes `car+0x404=max(scale,1)` and `racer+0x4b8=scale` every 0.3 s | 0x44bff5, 0x44bffe, 0x77a49c | **Y** (body) / **N** (heading) | 0x44bfe9 `call 0x401c40` (fmax) → 0x44bff5 `fstp [eax+0x404]`; 0x44bffe `mov [edi+0x4b8],ecx`. Period gate 0x44bd60 `now-edi[0x108] >= [0x77a49c]`. But the (c) **heading** "rewritten at 1.12 every frame" is not in the binary: neutral is 1.0 (`0x3f800000` at 0x44bd8f-ish), 1.12 appears nowhere in the function. If a patch is the source of 1.12, say so in the heading. V |
| 14 | Only reader of `racer+0x4b8` is 0x44c550 at 0x44c731, gated by `action+0x1f0 != 0` | 0x44c731 | **Y** | 0x44c72b `fmul [eax+0x77a00c]` (record+0x14), 0x44c731 `fmul [ebx+0x4b8]`; 0x44c5b8 reads `[action+0x1f0]` and 0x44c5c0 jumps away when 0. V |

## Extras that matter for the next two jobs
- `0x456830` really is `arg / car+0x404` (0x456846 `fdivr [ebx+0x404]`) and then multiplies by `1-car+0x47c`
  (0x45687a). V. So a patch on 0x404 reaches the AI speed prediction, exactly as (c)(3) warns.
- `host/rivals.c:1026` already documents 0x44bfe9..0x44bffe correctly; trust it over the (c) heading.
- The claim in (a) that `host/rivals.c` says "the game has no slipstream" is **stale**: `grep -ri slipstream host/`
  returns one line (556) that calls car+0x47c "the game's slipstream". Nothing is wrong to fix there. V
- Selector order verified: 500 GetUnstuck, 600 PickRoute, 400 IJustGotHit, 400 AvoidCross, 300 Avoid, 500 Accident
  (0x44db7d), table+flag Block, 200 Pass (0x44dc27). No surprises. V
- Not verified (out of scope, no run): frequency of any of this, `[0x77a49c]`/`[0x77a344]` values, and whether
  `out2` sign in the rubber band behaves as race_ai.md guesses. U

## If you build on this
Do not "restore 1.12", cite 0x44bc76 for the priority compare, treat 0x7062b4 as a struct, and re-label the Block
finder filter as a driver-code check. Everything else in the 12 holds at the cited address.
