# Prior art: how NFSU/UG2/MW projects describe rival and traffic AI

Question (OWNER 2026-11-04): what do the community and decompilation projects say about rival/traffic AI
(rubber band, aggression, drafting, difficulty files, known jank), and which ideas can we adopt with an address?
Marks: V = read in our code/docs with address, I = inference, U = doubt. Web claims are theirs, not verified by us.
No game, Chrome, port or binary was run. Our code facts are cited from docs/re/race_ai.md, rivals.md, traffic*.md.

## Answer first

- **Community coverage exists for UG2 and MW, not for NFSU1.** Nobody publishes a Speed.exe (NFSU1) AI decomp.
  UG2 knowledge is data-level (per-racer `CatchUp`, difficulty, edited with Binary/VltEd); MW has a public
  function-level doc (nfsmw-2005-re, docs/AI_SYSTEMS.md) with hooks and attribute hashes. Addresses from those
  games do **not** transfer to ours (U). What transfers is the shape of the system, which matches ours closely.
- **All three games: catch-up is a per-racer scale, not physics.** UG2 mods zero a per-racer `CatchUp` value;
  MW calls `ComputeRacerRubberBandTargetSpeed @ 0x5ff990` with 3 difficulty multipliers and 4 ramp tables.
  Ours is `0x44bd10`: `S = [0x78a404]` (EventDesc `+0x12c`), neutral window = skill record `+0x4c` (3..19 s),
  pair table `0x779fb0/0x779fd0`. V
- **Drafting: prior art is wrong for us.** MW's doc debunks "slipstream" as only the rubber band (no proximity
  check). Our Speed.exe does have one: `car+0x47c`, pair term `0x426300`, cosine >= 0.95 (`0x6b7b50`), 60 m
  (`0x70629c`), cap 0.9 (`0x6b7b54`), applied as `(1 - 0x47c)` at `0x479160`. V. It is just never read by the
  racer's speed prediction `0x456830`. So the fix is AI-side use, not new physics.
- **Traffic: they model the same blind spot.** MW ships attributes `CHECK_PLAYER_BEHIND_TRAFFIC`
  (`0xE8A7CCE2`) and `TRAFFIC_LANE_CHANGES` (`0x4463A62D`); our traffic finder `0x44f470` scans slots own-1..0
  only (asm `0x44f4aa`), so a player closing from behind is invisible. V ours, theirs is their doc.
- **Difficulty is data, never code.** Ours: EventDesc `+0x10` column, `[0x78a3fc]`, quick-race table `0x77a400`;
  "it does not change the AI code" (rivals.md §4, V). UG2/MW behave the same (skill/difficulty rows). So raising
  difficulty alone can never fix clumsiness; the constants below are the levers.

## 8 adoptable ideas (address or constant each)

| # | Idea from prior art | Touches in Speed.exe | Cost/Risk | Mark |
|---|---|---|---|---|
| 1 | Catch-up as one runtime knob, plus the window: UG2 mods set `CatchUp=0` per racer ("no rubberband", NFSMods 1694/3222) and MW exposes the gain function | `[0x78a404]` (S), skill rec `+0x4c` neutral 3..19 s at `0x44bd9d`, store `0x44bff5` | S / B | V code, I effect |
| 2 | "Rivals never slow": our band clamps `veh+0x404 = max(scale,1.0)` (`0x44bff5`) and the raw scale in `ctx+0x4b8` is read only when `action+0x1f0 != 0` (`0x44c731`); Draft/Accident/Hit/Unstuck zero it, so the slow-down half is lost. Community reports exactly this asymmetry ("AI never loses pace when ahead") | `0x44bff5`, `0x44bffe`, `0x44c731` | M / A | V code, I effect |
| 3 | Make the AI use the draft it already has: prediction `0x456830` divides by `car+0x404` and ignores `+0x47c`; read `0x47c` there like physics does at `0x479160`. Also the Draft action `0x450480` brakes (`lead - (20-gap)`, consts `0x6b7620`/`0x6b7628`), which reads as "rival backs off" | `0x456830`, `0x450480`, `0x6b7620`, `0x6b7628` | M / M | V code, I feel |
| 4 | `CHECK_PLAYER_BEHIND_TRAFFIC` / `TRAFFIC_LANE_CHANGES` as switches: mirror MW. Ours already exists in host (`traffic_tick`, host/rivals.c:595) as `?trafyield`; ship it on by default plus the visible flash `0x5693b7` `75`->`eb` | `0x44f470`, `0x4539db` (12-byte patch already drafted in traffic_react.md), `0x5693b7` | S / M | V patch bytes, effect U |
| 5 | Traffic reaction rate: our `TrafficAI::Update 0x583350` thinks for ONE car per sim step, index `[0x6f08a4] mod 2N` (`0x585e00`), so 0.66-0.73 s latency at N=22. MW/UG2 tick each traffic vehicle every frame (AIVehicleTraffic `vt[10]`) | counter/mod at `0x585e00`, `2N` factor | S / M | V code, I effect |
| 6 | Traffic density as data, not a magic number: gate `0x59b3e0` returns 99999 m unless the player stands in a `TRAFFIC_DENSITY` zone, so roads outside zones are empty. MW/UG2 ship `trafficpattern`/density attributes; ours are in chunk `0x3414a` `+0x7c` (min,max per level) | `0x59b3e0`, `0x3414a +0x7c`, per-level 35..190 m | S / B | V code+files |
| 7 | One spawn-time skill/aggression override instead of editing events: community edits `CatchUp`/difficulty per racer; a single hook after `0x4322a0` that clamps entrant `+0x735` (skill) and `+0x736` (aggr) makes "extra hard" and "no catch-up" runtime flags | `0x4b4040`, `0x4322a0`, entrant `+0x735/+0x736`, `0x77a400` | S / B | V code |
| 8 | Widen the defensive windows so the strong actions fire: Block needs closing time <= 2.0 s (`0x6b7638`) and a human follower within 35 m (`0x6b763c`); Pass needs race clock > 5.0 s (`0x6cc954`) and priority <= 200; Block ceiling `0x77a340` = 200/200/400. Community "AI aggression" tweaks do the same at data level | `0x6b7638` 2.0->4.0, `0x6b763c` 35->50, `0x77a340+8a` ceiling | S / M | V code, effect U |

Cheapest first: #4 + #6 (one flag, one constant, both reversible).

## Known jank, mapped to our code (what the community reports vs what we can see)

- **"Rivals get stuck / stop at walls":** nothing turns a racer around (`0x45d640` just returns `[0x78a2fc]`, V);
  recovery is `GetUnstuck 0x451b00` behind a 6.0 s cooldown (`0x462aa0`, V). Traffic has a reversal
  (`0x59c210` retypes the path), racers do not. I: this is the stuck case, not a data problem.
- **"They ram you":** only cops ram in MW (`CreateAIActionRam @ 0x43b9b0`); racers avoid. Ours matches: the hit
  reaction `IJustGotHit 0x4522a0` is a back-off (target = culprit speed - 6) with no revenge path (V). What feels
  like ramming is `Avoid`/`Block` lane changes plus `0x77a340` allowing Block at priority 400 (V).
- **"They fly / corner at impossible speed":** UG2 no-rubberband mod author warns the AI "might literally fly in
  the air", engine-side. Ours: the band writes a speed scale (`0x404`) without touching grip or the line, so a
  large scale is a cornering-speed boost with no handling (I, and rivals.md §3 risks list the same).
- **"Traffic is dead / does not dodge":** three independent gates, all V: goal-5 cars exempt the player above
  20 m/s (`0x4539cf`), reaction only within 30 m (`0x6b76e0`), and one car thinks per 2N steps (`0x585e00`).

## What prior art does NOT give us

- No NFSU1 symbol names, no verified UG2/MW-address equivalence; any address from those docs is U for Speed.exe.
- MW's "no drafting" is a claim about MW only, and it contradicts our binary. Treat community folklore as a list
  of symptoms, never as a spec. Their traffic knobs are attribute hashes in `attributes.bin`, ours are raw
  fields in `.lzc` chunks: same idea, different plumbing.

## Sources

- NFSMods, "Underground 2 no rubberband mod (+ extra hard AI)": https://nfsmods.xyz/mod/1694 (per-racer
  `CatchUp` = 0, difficulty 9; author's "AI might fly" caveat).
- NFSMods, "No Catch Up Mode NFSU2 Career Mode": https://nfsmods.xyz/mod/3222 (same switch, career tracks).
- Arqade, "Are the URL races in NFSU2 rigged?": https://gaming.stackexchange.com/questions/410838 (catch-up
  works both ways, AI speed without handling).
- nfsmw-2005-re, `docs/AI_SYSTEMS.md`: https://github.com/s-b-repo/nfsmw-2005-re (goal/action stack,
  `ComputeRacerRubberBandTargetSpeed 0x5ff990`, `AIActionRam 0x43b9b0`, traffic attribute hashes
  `CHECK_PLAYER_BEHIND_TRAFFIC 0xE8A7CCE2`, `TRAFFIC_LANE_CHANGES 0x4463A62D`, `TRAFFIC_SPEED 0x811C6606`).
- NFSMWBartender: https://github.com/rng-guy/NFSMWBartender (per-spawn traffic independence, `CarSpawns.ini`).
- GameAIPro ch. 42 (https://www.gameaipro.com/GameAIPro/GameAIPro_Chapter42_A_Rubber-Banding_System_for_Gameplay_and_Race_Management.pdf):
  disable the band at race start and at low speed, slow the leader instead of boosting the chaser. Ours disables
  it for 3..19 s (V) but never slows the leader in `0x404` (idea #2).
- NFS ProStreet "AI Tweak" (https://nfsmods.xyz/mod/2665): what players call "drafting and aggression" is
  authored in AI data, which is consistent with ours being `0x779ff8 + 0x54*skill`.
