# Patches that touch physics, AI, traffic or input (PLAN 6.3, 2026-10-27)

Source: tools/recomp/patches.py (each PATCH comment has the RE), host/win32.c (switches at SCREEN_ADDR).
No patch changes car physics or the rivals' AI: the speed caps 0x583ea0, tuning 0x705f48..0x705f84 and the racer
driver 0x5a6ef0 run as shipped.

| Patch | Area | Effect (before -> after) | Default | Keep / drop |
|---|---|---|---|---|
| 0x57d060, 0x57d0c1, 0x57cfc7 (cave 0x63b270) | traffic types | 6 of 12 types weighted in Quick Race district 0 -> 12 types at 1.0, + 8 compact racer rows at 0.375; run on 1001: 6 -> 18 distinct types | on (RN_TRAFFIC=0 = original) | keep: OWNER 2026-10-25 "traffic alive" |
| 0x4b3b01 | traffic count | trackinfo count x1.5: 12 -> 18 cars, cap 26 (rides cap 30 at 0x4322a0) | on | keep: same |
| 0x583a37, 0x583a5b | traffic AI pace | lane speed from 0x5a6b00 x1.0 -> x0.85..1.15 per car (hash of its AI object, stable) | on | keep: cars no longer move in lockstep; RN_TRAFFIC=0 restores x1.0 |
| 0x4609e3, 0x460a80, 0x460b4f, 0x460c02 | steering input | keyboard model (angle cap grows over 0.55 s held, rate limit 0x460de0) -> gamepad model (angle = speed cap at once) | off (?steer=pad) | keep as opt-in: OWNER choice 2026-10-26, default stays the game's keyboard path |
| 0x585b94 | frame pacing | 1/60 s limiter in load states too -> skipped while loading (states 1,2,4,5,7,8, race state 1); menu->race ~400 frames / 7.4 s -> load-bound | on | keep: race and front end keep the 1:1 60 Hz limit, so physics steps are unchanged |
| 0x4470f0 (cave 0x408814) | RNG seed | QPC seed -> fixed K | off (RN_SEED) | keep test-only: A/B and repeatable runs |
| 0x42d4b0, 0x42d4a9 (cave 0x6436e3) | player input | player mode 2/3 -> 4 AUTO_PILOT (game AI drives) | off (RN_AUTOPILOT) | keep test-only: lap and A/B runs |
| 0x56e0d2 | draw only | LOD by screen size -> always the caller's minimum LOD | on | keep: look only, no gameplay read |
| host/input.c keyboard | input | keys -> the game's own action map (joy events), [0x736514] = 0 keyboard model | on | keep: same path as the PC keyboard |
| host/input.c RN_KEYS / RN_JUMP / RN_CAREER / RN_FINISH | input | scripted keys, race jumps, career walk, forced win | off | keep test-only (never set by the page unless ?keys/?jump) |

Handling or AI changes in this block: none made. The only gameplay changes that ship by default are the three
traffic patches above (numbers in the table) and the load-only limiter skip.
