# Reverse engineering notes: how Need for Speed Underground works inside

Short maps of what `Speed.exe` (2003, PC) does, found by reading the binary: physics, camera, rival AI, traffic, tracks, rendering, sound. Every claim is marked **V** (read in code or bytes), **I** (inferred) or **U** (open), with the address that proves it. Names live in [`census/`](../../census). **Play the game: [nfsu.cc](https://nfsu.cc)** · How the notes are made: [English](https://nfsu.cc/blog/en/reverse-engineering-tools-ghidra-hopper-rea.html) · [Español](https://nfsu.cc/blog/es/herramientas-ingenieria-inversa-ghidra-hopper-rea.html)

| Topic | Notes |
|---|---|
| Driving | [`physics`](physics.md) [`accel`](accel.md) [`tuning`](tuning.md) [`feel_patch_plan`](feel_patch_plan.md)  |
| Camera | [`camera`](camera.md) [`camera_chase`](camera_chase.md) [`camera_crash`](camera_crash.md) [`camera_jump`](camera_jump.md) [`camera_speed`](camera_speed.md)  |
| Rival AI | [`race_ai`](race_ai.md) [`rivals`](rivals.md) [`rival_profiles`](rival_profiles.md) [`ai_steer`](ai_steer.md) [`ai_rubber`](ai_rubber.md) [`ai_speed`](ai_speed.md) [`ai_corner`](ai_corner.md)  and the other `ai_*.md` |
| Traffic | [`traffic`](traffic.md) [`traffic_models`](traffic_models.md) [`traffic_density`](traffic_density.md) [`traffic_react`](traffic_react.md) [`traffic_limits`](traffic_limits.md)  and the other `traffic_*.md` |
| Tracks, resets | [`track`](track.md) [`roadid`](roadid.md) [`coll_reset`](coll_reset.md) [`reset_causes`](reset_causes.md) [`reset_walls`](reset_walls.md)  |
| Render, sound | [`render`](render.md) [`render_pc`](render_pc.md) [`blur`](blur.md) [`sound`](sound.md) [`texture_lab`](texture_lab.md)  |
| Game flow, menus | [`gameflow`](gameflow.md) [`frontend_menu`](frontend_menu.md) [`garage`](garage.md) [`mode_menu`](mode_menu.md) [`race_setup`](race_setup.md) [`hud_input`](hud_input.md) [`unlock`](unlock.md)  |
| Data, hosting | [`assets`](assets.md) [`car_assets`](car_assets.md) [`public_pack`](public_pack.md) [`hosting`](hosting.md) [`runtime`](runtime.md)  |
| Method | [`systems_method`](systems_method.md) [`coverage_method`](coverage_method.md) [`RESULTS`](RESULTS.md)  |

Back to the [repo](../../README.md).
