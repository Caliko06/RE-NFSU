# Prior art: traffic count, traffic cars, driver personality, headlight glow

Lane PRIOR ART (lupe, 2026-11-04). Question: how did others solve (1) widened traffic models/count, (2) tuned/varied traffic
cars, (3) per-driver personality, (4) clean headlight glow. Rule: only facts with a source URL. Marks: **F** = read in our
`pc/Speed.exe` (address + bytes) or read in the cited source; **I** = inference; **NV** = could not verify. Nothing was run:
no game, no build, no Chrome, no Ghidra/Hopper window. No address below is invented; where the source is another game's
binary it is labelled as such and is *not* transferable.

## Answers first

1. **Traffic count: nobody publishes a NFSU1 traffic-count patch.** The only NFSU1 code that touches car pools is
   NFSU1 Unlimiter, and it widens the **car-type table**, not the entrant/traffic ring. NFSU2 Unlimiter *does* widen the
   traffic manager, and its numbers (stride, count) are the useful shape. **F** for their code, **I** for our port.
2. **Varied traffic cars: done by content swap in UG2, and by a usage flag in NFSU1.** The flag is `CarTypeInfo+0xC54`
   (0 = racer, 2 = traffic in our data), stride `0xC90`, table pointer `[0x734588]`. That is the exact hook for "tuned cars
   as traffic". **F**.
3. **Per-driver personality: no NFS title ships it as data.** MW/UG2 expose global traffic switches
   (`TRAFFIC_LANE_CHANGES`, `CHECK_PLAYER_BEHIND_TRAFFIC`). Real per-driver personality with fairness exists in traffic
   microsimulation (SUMO/Krauss `sigma`, MOBIL politeness), which maps 1:1 onto our per-entrant bytes `+0x735/+0x736`.
   **F** source, **I** port.
4. **Headlight glow: remasters fix the *resolution-dependent halo*, not the light.** NFS HD Reflections scales reflection
   resolution; ReShade presets add bloom on top. No source found that reworks the glow geometry itself. **F** source, **NV**
   for our renderer.

## 1. Widening traffic models and traffic count

| Source | What it actually does | Applies to our binary |
|---|---|---|
| NFSU1 Unlimiter, `UnlimiterStuff.h` https://github.com/nlgxzef/NFSUUnlimiter | Reads the car-type table `[0x734588]`, `CarArraySize -= 8`, `CarCount = CarArraySize/0xC90`, hard cap **127**; writes the new size to 27 sites (`0x4397C4`, `0x43B048`, `0x4BC1CD`, `0x57D4BE`…). Also `AllNewCarsCanBeDrivenByAI`. **F** (their source) | **Exact binary family.** Our exe: `mov ecx,[0x734588]` at `0x424c50`, `imul eax,eax,0xC90` at `0x424c56` (`69 c0 90 0c 00 00`). Same pointer, same stride. **F**. It does **not** touch the traffic ring or the 30-entrant table. That gap is ours to close. |
| NFSU2 Unlimiter, `StreamingTrafficCarManager.h` https://github.com/nlgxzef/NFSU2Unlimiter | Replaces the manager with `0x1230 + 0x920 * 64` bytes and walks the traffic list head at `+576` dwords, re-rolling skins per traffic car. **F** (their source) | Sister game, addresses useless for us. Adoptable: (a) the pool is one flat block sized by *count*, (b) per-car skin is re-rolled at stream time, not at spawn, which is why UG2 traffic looks varied. **I** for us. |
| NFSU Extra Options, `ExtraOptionsStuff.h` https://github.com/ExOptsTeam/NFSUExOpts | `RacerControllers Min/Max` 1..4, laps 0..127, injected as immediates. **F** (their source) | Shows the accepted pattern (INI -> immediate write). Our equivalent knobs already exist: `0x4322e6` (30 entrants), cave clamp 26. **F** ours, from `docs/re/traffic_cap.md`. |

**No source found** for a NFSU1 `Speed.exe` traffic-count address, a traffic ring size, or a `TRAFFIC_DENSITY` patch by
anyone. Our own `docs/re/traffic_cap.md` (race list is 32, `0x42119a` fault) stays the only evidence on that wall. **F** ours,
**NV** for the community.

## 2. Traffic with tuned or varied cars

| Source | Fact | Applies |
|---|---|---|
| NFS World Traffic Pack, https://nfsmods.xyz/mod/6136 and https://www.nfsaddons.com/downloads/nfsug2/cars/other/9507/nfs-world-traffic-pack.html | UG2 traffic models replaced wholesale by NFS:World civilian cars (content swap, no code). **F** (page) | Idea only: our traffic **models** are rows with usage 2 and 60-90 KB of geometry (`docs/re/traffic_limits.md`). A tuned-looking traffic car needs a full model, not a swap of a small one. **I** |
| NFSU2 Custom Shaders, https://nfsmods.xyz/mod/6271 | "Carbon like headlights for traffic", new rain shaders, no car paint on vinyls. **F** (page) | Proves the community changes traffic *appearance* by shader, not by model. **I** |
| NFSU1 Unlimiter `IsRacer` https://github.com/nlgxzef/NFSUUnlimiter | `IsRacer(id) = *(BYTE*)(table + id*0xC90 + 0xC54) == 0`; traffic is the non-zero case. **F** (their source) | **This is our switch.** Give a racer model a traffic usage row (or copy the row with usage 2) and the spawner accepts it. Our row layout already carries usage at `+0xC54` and skins at `+0xd9`/`+0xc80` (`docs/re/traffic_limits.md`, **F** theirs). Untested in our build. **I** |

## 3. Per-driver personality (speed bands, lane changes, cut-in fairness)

| Source | Fact | Applies |
|---|---|---|
| nfsmw-2005-re, AI systems https://github.com/s-b-repo/nfsmw-2005-re/blob/main/docs/AI_SYSTEMS.md | Traffic is `AIVehicleTraffic` (vtable `0x00891CF8`), driven per frame from `vt[10] OnDriving(dt)`. Modding hooks are named attributes: `TRAFFIC_LANE_CHANGES` (`0x4463A62D`) and `CHECK_PLAYER_BEHIND_TRAFFIC` (`0xE8A7CCE2`). **F** (their doc) | Shape matches ours: one per-car update, lane-change as a switch. Ours updates **one car per sim step** (`0x585e00`, `2N`) and its finder `0x44f470` never reads slots behind. **F** ours. Their addresses are MW's, **NV** here. |
| SUMO, Krauss car-following https://sumo.dlr.de/docs/Car-Following_Models.html | Per-vehicle driver imperfection `sigma` (0 = perfect, ~0.5 = human) and reaction time `tau`; both are per-vehicle, not global. **F** (docs) | Directly adoptable as per-entrant bytes next to skill `+0x735` / aggression `+0x736`. Speed band = cruise factor, `sigma` = jitter around it. **I**, no address needed. |
| MOBIL lane-change model (Kesting, Treiber, Helbing) https://arxiv.org/abs/cond-mat/0305550 | Lane change requires (a) incentive, (b) safety: the new follower must not brake harder than `b_safe`; a `politeness` factor 0..1 trades own gain against others' loss. **F** (paper abstract/model) | This is the *cut-in fairness* rule worth copying: before `0x453920` commits a lane change, check the follower's required decel against a threshold. Our `TRAFFIC_LANE_CHANGES`-equivalent has no such check today. **I** |

## 4. Clean headlight glow in remasters and render mods

| Source | Fact | Applies |
|---|---|---|
| NFS HD Reflections, https://github.com/AeroWidescreen/NFSHDReflections | Scales *reflection* resolution (`Scale`, `ImproveReflectionLOD`, `ExtendRenderDistance`, `VehicleReflectionBrightness`), no headlight code. Author notes all addresses are hardcoded per exe build. **F** (README) | Idea: the community's "clean lights" wins come from resolution and LOD, i.e. the halo sprite is stretched by the framebuffer, not authored wrong. **I** for our renderer, **NV**. |
| ReShade preset "NFSU 2026 Resurrection DXHex", https://www.nexusmods.com/needforspeedunderground/mods/32 | Bloom/contrast/neon grading applied **after** the frame (post-process), described as stronger bloom. **F** (page) | Confirms glow is treated as post, not geometry. A post pass is not available in our recomp (no d3d8 shader chain verified). **I/NV** |
| NFSU2 Headlight Controller, https://nfsmods.xyz/mod/5039 | Toggles headlights in FE; credits "ARCHIE - memory addresses". **F** (page) | Only proves there is a headlight state flag worth finding. Their addresses are UG2's and are not published on the page. **NV** |

**Gap:** none of the four sources explains how the original halo is drawn (billboard quad vs. additive sprite). Renders
nothing about our `0x429100` light call family. Open question, not a result.

## What NOT to copy

- MW/UG2 numbers and addresses (`AIVehicleTraffic` vtable, `TRAFFIC_LANE_CHANGES` hash values) are per-binary; using them as
  our addresses would be invented. **F** that they are theirs, **I** that they differ from ours.
- Unlimiter's 127-car cap is a **car-type** cap, not traffic. Reading it as "127 traffic cars" is a trap.
- Content-pack traffic (NFS World Traffic Pack) does not raise count and does not survive our low-detail traffic rows.
