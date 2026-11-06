# Car-to-car contact: who bounces, with which physics (Speed.exe PC)

V = read in code/bytes/log, I = inference, U = open. No run. Question: when the player touches a rival or traffic,
who gets the push, and is the player's car special? **One solver for every car; the split is mass only. The player is
not special; a rival is, but in how it MOVES, not in how it collides.**

## 1. Answer first

- Shared path, no driver-kind test: `World::ProcessContacts 0x420380` -> pair loop `0x46b790`/`0x46b5e0` ->
  `Contact::ResolveImpulse 0x46bae0` -> `ApplyImpulse` slot 19 `0x46a260`. V.
- j = -(1+e)·v_rel_n / (denomA+denomB); e = **0.1** (`0x466900` -> `0x6cc7b8`), halved to 0.05 on a glancing hit
  (`0x46c620` side-swipe test, `0x6b7254` = 0.5). denom = `DenominatorTerm 0x46ba50` per body (r×n through the
  inverse-inertia matrix, crossed with r, dotted with n). V.
- Equal and opposite |j|; each body's speed change = j/mass. Lighter car moves more. V formula, I feel.
- Mass from the car record (`CarPhysicsInfo+0x110` -> `1/m` at body+0x148, `0x584b10`), never from the driver. Data:
  tuners 1.04..1.55 t, every traffic car 1.80 t, BUS 6.5 t. `1/m` floored at `1/1.85` (`0x46a080`, `0x6b727c`), so only
  the BUS is clamped. V (exe + GLOBALB.BUN, tools/re/carinfo.py).
- Walls: `GetMassInverse` returns 0 -> never pushed, the car takes 100 %. V.
- Cap: |j| <= `0.3 / max(1/m)` (`0x70009c` = 0.3): one contact changes the lighter car's normal speed by at most
  0.3 m/s. V. Same "impulse" scale as camera 30/35 and props 0.3: I.
- AI cars differ only by MOVER (`Car_SetMode 0x426110`: 1 = PhysicsMover `0x476840`, 3 = MellowMover `0x4740d0`,
  4 = BeltMover `0x463260`). Modes 1/3 get a rigid body in the collision body (`SetupPhysicsPointers 0x469f30`);
  mode 4 does not -> `1/m` = 0 -> a BeltMover rival absorbs nothing and the player takes the whole hit. V/I.
- Baselines: rivals are mode 3 (20/20 AIJUMP, `mode 3`, wheels 4), never mode 4 (0 AIBELT). V.

## 2. Pieces

| what | where |
|---|---|
| contact phase | `0x420380`: broadphase + witness list, then `0x46b790`/`0x46b5e0` per pair -> `0x46bae0` |
| response | `0x46bae0`: normal `0x46b8c0`, restitution, denom, clamp, `0x465830` (sound/cam), AddContactImpulse |
| effective mass | `0x46ba50` (inertia from body+0x30); 1/m slot 22: Car `0x46a080` = max(body+0x148, 1/1.85), Static `0x466770` = 0 |
| apply | slot 19 `0x46a260` -> `0x584f60`, then `0x46a370` (hook car+0x868, x0.013 `0x7000cc`) |
| penetration push-out | asked of `IsMoveable` slot 24: Car `0x466850`, Static `0x575940` (=0) |

## 3. Player vs AI

- Factory `0x422410` (arg = driver kind): kind 1 player -> mode 1; kind 2 rival -> mode 0; kind 3 traffic ->
  `0x425150`, which returns 3 unless the car is the human player or a drag event is on (`[0x78a344]`/`[0x7361a8`]). V.
- `Racer::Update 0x44b1b0` promotes a rival to mode 1 while it is (or was, up to 4000 ms: timer racer+0x428, `0x6cc9fc`
  = 4000, refreshed while drawn) visible; else it drops back to `0x425150` = 3 (asm `0x44b378`..`0x44b3e3`). V.
- Mode 4 forced at `0x44ba32` when `[0x700740] != 0` and `0x44b060` allows (frees the mover, builds a BeltMover);
  `[0x700740]` is 0 in WORLD now (host/rivals.c): 0 AIBELT. V.
- Collision body, mass, inertia, restitution: identical for player, rival, traffic. The mover is not: player always 1;
  rival 1 near/seen, 3 far; traffic 3.
- Same physics step? **No.** One virtual step per car, by mover: `0x4774a0` (engine, drivetrain, 4 wheels, 4
  suspensions, `0x46aa40` substeps) in mode 1 only; `0x474a90` (one Euler step + drag/power `0x474d40`, RigidBody +
  Mellovator) in mode 3/4, no wheel-suspension loop. Same mass in the hit, different way of putting power down. V/I.

## 4. AIHIT: one-frame speed drop by pair (>= 4 m/s, `nearest ... car` = car < 6 m)

Median m/s (n), `runs/w_ai_s1`/`s2`/`s3`:

| hit | by | s1 | s2 | s3 |
|---|---|---|---|---|
| player | rival | 7.4 (4) | 6.1 (5) | 8.7 (8) |
| player | traffic | 14.0 (9) | 10.0 (24) | 6.5 (5) |
| rival | player | 11.1 (1) | 7.1 (5) | 7.0 (8) |
| rival | rival | 7.0 (14) | 6.6 (18) | 7.0 (29) |
| rival | traffic | 13.4 (31) | 9.9 (57) | 13.2 (19) |
| traffic | player | - | 6.4 (3) | 8.3 (3) |
| traffic | traffic | 5.4 (8) | 6.7 (10) | 6.7 (2) |

Reads: player vs traffic costs the player more than the traffic (1.80 vs ~1.2 t: predicted 1.5, seen 1.4..1.6); player
vs rival is near symmetric (same mass class); rival vs traffic is the worst pair for the rival. V numbers, I cause.
AIHIT mixes wall hits, so it is a trend, not a measurement of j.

## 5. Damage

No deformation. (a) crash state `car+0x38 = 1` at |impulse| >= **30** (`0x6b72bc`, `0x465d00`), camera shake at 35
(`0x6b72b8`) — docs/re/camera_crash.md; (b) per-hit hook `car+0x868`, x0.013 (`0x46a370`, meaning U); (c) drag/grip
scale `body+0x1e4 = phys+0x290*(1-damage)` (docs/re/physics.md), phys+0x290 = 0 on all 35 cars -> stock no-op.
`0x46a0c0` reads the crash state to pick the tangential factor (1.0 crashed, else 0.4). V read, I effect.

## 6. Probe and open ends

Opt-in, no behaviour change: at `0x46be82` (after the clamp) log `j`, `1/mA`, `1/mB`, `typeA`, `typeB`, `|vrel|` under
`RN_AILOG`. Settles the unit of j and the real split per pair instead of the AIHIT proxy. Not built, not run: UNTESTED.
Knob if rivals should feel heavier: car mass `CarPhysicsInfo+0x110` (data) or e at `0x6cc7b8` (exe, every pair).
Open: `0x46c620` gates a glancing hit (radius +0x78 vs 0.3, head-on dot -0.97 at `0x6b72b4`), I; car+0x868, U; mode-3 wheel loads, U.
