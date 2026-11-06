# Rubber band 0x44bd10 in WORLD (free roam): does it run, and which way does it push?

Question (OWNER 2026-11-04): does the rubber band run in WORLD (no race clock), and which way does it push? What gates it?
Marks: V = read in code/bytes/log, I = inference, U = open. Logs: `/Users/angeldamian/RE-NFSU/runs/w_*/log.txt` (AIR,
`f %u %s d %+.0f sp %.1f s4b8 %.2f s404 %.2f`), scripts `becarios/rosa/work/{air,bins,fac,final}.py`.

## Answer

- **It runs, but it cannot push by distance in WORLD.** All early returns of `0x44bd10` pass, and the target (the player's car) is
  selected; the distance/rank gap comes from `0x44c010`, whose first instruction is `switch (0x78a400)` and whose outputs stay 0,0
  while `[0x78a400]` is 0. Free Run ships `[0x78a400] = 0` (the race options' Catch Up byte `+0x1f`), so `scale = 1.0 + 0 + 0`. V
- **What is left is a flat handicap, always down.** The factor block `scale *= max((f-1)*v+1, floor)` is gated by the target, not by
  `0x78a400`. Measured in WORLD: `racer+0x4b8` = 0.935..0.975 per rival (mean 0.95), constant for a whole run and with no correlation
  with the signed distance to the player. 22 WORLD runs, 55 000 AIR lines: **`s4b8` is never > 1.00**. V
- **Which way:** in WORLD only down, 2.5..6.5 %, same ahead or behind. The "rivals behind speed up / far ahead slow down" reading is
  a race behaviour (`[0x78a400] = 1`), and even there the measured shape is "far either way = slowed", with rare boosts > 1. V/I
- **Gates:** drag off (`[0x78a344] = 0`), `[0x7361a8] = 0`, one player, `[0x7360ac] = 0`, `[[0x7361f0]] != 9`, `[0x78a320] > 0`,
  action flag `[[ctx+0x3f8]+0x1f2]`, and the race clock past the skill window (record `+0x4c`, 3..19 s). All pass in WORLD. V

## Evidence

1. Early returns (`0x44bd10`, code + bytes): `car = [ctx+4]; if (!car) ret; if (car+0x18) ret; if ([0x78a344]) ret; if ([0x7361a8]) ret;`
   then `bVar2 = action && [action+0x1f2]`, then `0.3 s` since `ctx+0x108` vs `[0x77a49c] = 0.30`. V (Ghidra `RacerAI__UpdateRubberBand`,
   Hopper `sub_44bd10`, and the bytes `83 ec 30 56 57 8b f8 8b 47 04 8b 70 1c 85 f6`).
2. **Clock offset is `+0x14`, not `+4`** (the brief and `docs/re/race_ai.md` use `+4` for the Pass finder, a different field).
   Bytes at `0x44bd7d`: `8b 15 9c 61 73 00` = `mov edx,[0x73619c]`, `db 42 14` = `fild dword [edx+0x14]`, then `fimul [0x6cca38]`
   (0.00025 = 1/4000 s), `fcomp [eax+0x77a044]` (record `+0x4c`). The clock **does advance in WORLD**: `s4b8` is exactly 1.000 in the
   first 10 s bins of `w_a` (frames 2400-2999) and 0.948..0.955 from frame 3600 on, i.e. the neutral window ends and is honoured. V
3. WORLD gate values, 658 samples of the host probe (`host/free.c:723`, tag `FREE catchup`): `78a344 0`, `7361a8 0`, `78a320 1`,
   `7360ac 0`, `7361f0 1 or 4`, `7361c4 1` (one player), `78a404 1.00` (S = 1.0, not 0), `78a2f0 0x3f2` (1010 = WORLD). The same line shows
   **`78a400 0` in 658/658 samples** and `78a400 1` in none. V
4. AIR, WORLD, `?pool=0` run `w_a` (8 rivals, 345 samples each, no `s4b8 0.50` = no gang cruise, 0 `DUEL` lines): per rival
   mean `s4b8` 0.935 (TODD, STEWART), 0.943 HECTOR, 0.946 ISHII, 0.955 TICKETS, 0.963 RICCO, 0.964 JACKIE, 0.975 STEFAN;
   `corr(s4b8, d)` = -0.08..+0.08 for all eight. Per-rival spread is explained by skill only if `v` in `(f-1)*v+1` is the pair table,
   i.e. `f ~ 0.95`, `v = 0.5 (skill 9, rank 1) -> 0.975`, `v = 1.21..1.27 (rank 4) -> 0.936`. I
5. 100 m bins, `w_a` (V): speed is set by the route, not by d.

   | d (m) | -1000 | -700 | -500 | -300 | -100 | 0 | +100 | +300 | +500 | +700 | +900 |
   |---|---|---|---|---|---|---|---|---|---|---|---|
   | sp m/s | 23.2 | 20.2 | 28.0 | 33.7 | 22.5 | 21.1 | 26.8 | 35.0 | 34.8 | 26.5 | 29.2 |
   | s4b8 | 0.960 | 0.962 | 0.954 | 0.950 | 0.953 | 0.951 | 0.946 | 0.950 | 0.947 | 0.947 | 0.955 |

6. Same bins on a race (career `cjump_92`, `[0x78a400] = 1`, `w`-style AIR): `s4b8` 0.564 at -1000 m, 0.910 at -200, 0.962 at 0,
   0.845 at +100, 0.601 at +400, 0.612 at +900. So far behind is **slowed**, not boosted; boosts > 1 are rare (`cjump_92` 1.01..1.12,
   `cjump_102` 1.02..1.05) and the documented curve sample (+0.13 at -900 m, skill 0) does not survive the factor/clamp chain. V measured,
   I explained. The `?pool=1` gang cruise writes `s4b8 = 0.5` for a rival that is not duelling (`host/rivals.c gang_step`), which is why
   pooled WORLD runs show 0.50 at every distance: that is host code, not the band. V

## Why it matters

WORLD speed = `routeSpeed x record+0x14 x [racer+0x4b8]` when the action reads the route (`+0x1f0 = 1`). With the band alive but
distance-blind, every rival carries a 2.5..6.5 % handicap that grows with (1 - f) and rank, and no rival is ever pulled toward the
player. The gate is not "wrong" (the band fires); the **size and direction are**: it is a brake with no catch-up. Turning it off is
one flag away; turning on a real catch-up is already `RN_FREECU=1` (`host/free.c:507` sets `[0x78a400] = 1` and rescales the curve x
by `RN_FREECUX`, default 0.35).

## Proposed patch (opt-in, off by default)

`host/rivals.c`, in `persona_step` (the cave the game's call `0x44c573` already jumps to), `RN_RBWORLD=1` only, WORLD only, and only
while `[0x78a400] == 0`: put `racer+0x4b8` and `car+0x404` back to 1.0 when the game wrote a value < 1, and log
`RBWORLD <obj> raw <x> -> 1.00` once per rival per 10 s. Effect: WORLD speed is exactly `route x record+0x14`, no hidden handicap;
race mode and `RN_FREECU` untouched. Draft added, **not compiled or run** (the brief forbids building): test with
`RN_RBWORLD=1` + F10 and check `s4b8 1.00` on every AIR line. U until run.

## Open (U)

- `f = [[player car +0xa8]+0xc]`: still not identified. It behaves like a per-race constant ~0.95 (not the throttle: `s4b8` does not
  move with the player's speed, corr -0.05 over 20-57 m/s). Reading `+0xa8`'s constructor is the next step.
- Whether the `+0x14` clock pauses between races (it did not in `w_a`: the window closed and stayed closed).
