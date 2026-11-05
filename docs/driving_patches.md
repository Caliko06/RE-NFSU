# Patches that touch physics, AI, traffic or input (PLAN 6.3, 2026-10-27)

Source: tools/recomp/patches.py (each PATCH comment has the RE), host/win32.c (switches at SCREEN_ADDR).
No patch changes car physics: the speed caps 0x583ea0 and the tuning 0x705f48..0x705f84 run as shipped. The AI is no
longer shipped code in WORLD: 0x44c573 and 0x45c8c2 call host/rivals.c (rival personalities), 0x45406c and 0x4540e9 call
host/free.c (the traffic's Avoid action follows the car ahead instead of 6 / 0 m/s), all off with RN_AI=0.

| Patch | Area | Effect (before -> after) | Default | Keep / drop |
|---|---|---|---|---|
| 0x57d060, 0x57d0c1 (cave 0x63b270) | traffic types | 6 of 12 types weighted in Quick Race district 0 -> 12 types at 1.0. The racer rows (0x57cfc7) are off since 2026-10-28: a racer body is DUMMY_SKIN<n>, set only for slots 1..4, so in traffic it drew no body | on (RN_TRAFFIC=0 = original) | keep: OWNER 2026-10-25 "traffic alive" |
| 0x4b3b01 | traffic count | trackinfo count x1.5: 12 -> 18 cars, cave clamp 55 (rides cap 64, PATCH 0x4322e0 in AddEntrant 0x4322a0) | on | keep: same |
| 0x583a37, 0x583a5b | traffic AI pace | lane speed from 0x5a6b00 x1.0 -> x0.85..1.15 per car (hash of its AI object, stable) | on | keep: cars no longer move in lockstep; RN_TRAFFIC=0 restores x1.0 |
| 0x45406c, 0x4540e9 ([SCREEN_ADDR+0xbc/0xc0]) | traffic AI avoid | Avoid action: car ahead at 15..30 m with no free lane -> 6 m/s whatever it does; within 15 m -> 0 m/s and gain 0, a dead stop. WORLD -> host/free.c avoid_follow / avoid_close: target is the speed it can still stop from behind the lead (4 m/s², 5 m gap) | on (RN_AI=0 = original) | keep: shipped queues crawled at 4 m/s |
| 0x44c573, 0x45c8c2 (caves 0x43b556, 0x43db2a) | rival AI personality | racer desired-speed step 0x44c550 -> host/rivals.c persona_step (per skill level: brake early/late, revenge, draft, nitro panic); side-line clearance 0x45cea0 -> persona_clear, +1.5 m for a clean rival | on in WORLD (RN_AI=0 = original) | keep: OWNER 2026-11-01 |
| 0x4609e3, 0x460a80, 0x460b4f, 0x460c02 | steering input | keyboard model (angle cap grows over 0.55 s held, rate limit 0x460de0) -> gamepad model (angle = speed cap at once) | off (?steer=pad) | keep as opt-in: OWNER choice 2026-10-26, default stays the game's keyboard path |
| 0x585b94 | frame pacing | 1/60 s limiter in load states too -> skipped while loading (states 1,2,4,5,7,8, race state 1); menu->race ~400 frames / 7.4 s -> load-bound | on | keep: race and front end keep the 1:1 60 Hz limit, so physics steps are unchanged |
| 0x4470f0 (cave 0x408814) | RNG seed | QPC seed -> fixed K | off (RN_SEED) | keep test-only: A/B and repeatable runs |
| 0x42d4b0, 0x42d4a9 (cave 0x6436e3) | player input | player mode 2/3 -> 4 AUTO_PILOT (game AI drives) | off (RN_AUTOPILOT) | keep test-only: lap and A/B runs |
| 0x56e0d2 | draw only | LOD by screen size -> always the caller's minimum LOD | on | keep: look only, no gameplay read |
| host/input.c keyboard | input | keys -> the game's own action map (joy events), [0x736514] = 0 keyboard model | on | keep: same path as the PC keyboard |
| host/input.c RN_KEYS / RN_JUMP / RN_CAREER / RN_FINISH | input | scripted keys, race jumps, career walk, forced win | off | keep test-only (never set by the page unless ?keys/?jump) |

Handling: no patch changes it. AI: the traffic-reaction and rival-personality rows above do, host-side, WORLD-gated
(SCREEN_ADDR hooks in host/free.c and host/rivals.c, RN_AI=0 restores the shipped calls). The only gameplay changes that
ship by default are the traffic patches above (numbers in the table) and the load-only limiter skip; the gamepad steering
and AUTO_PILOT stay opt-in.
