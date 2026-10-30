# SCOPE: Car Look Pack (OWNER 2026-10-30, frozen). A hook prints this file and HANDOFF.md on every prompt.
If your next action is not in this file, stop and report it in one line. Delete this file and .claude/settings.json at close.

## Goal
Open :5180?carpack=1 (Remaster) and see cars that are NOT dark: paint as bright as the original, lamps contained, kits and parts
with visible colour/contrast and 3D, HD part textures sharp. No new reflections. Today's look must not get worse. The OWNER judges
it in the garage (CarCustomize: Skyline, Tiburon, stock and kits) and in WORLD at night.

## Shape of the delivery
- One switch ?carpack=0|1|split (RN_CARPACK). Default stays 0 = today until the OWNER approves; then the default flips.
- Work on main behind that switch (no branch: a checkout would swap files under the other window). Commit with `git add <paths>`.
- Each look change: one line in the patch table with the address and why, one A/B shot in build/carpack/.

## Measured today (scene: build/carbright/run.sh, Skyline rear at race start; build/carbright/measure.py)
paint luminance: default 0.144, no carvol/cardetail 0.152, carlook=2003 0.164, original 0.165. Biggest darkener = carlook=3
(host/sm1.c car_ps_live: cs*cs mid-tone squaring, x(1+4*lum^3) on highlights), then cardetail grime and carvol, bloom widens the red lamps.

## Acceptance matrix (OWNER 2026-10-30 night: not one car, not one scene)
Every look change is judged on all of these, ?carpack=0 vs 1 (split where useful), by someone LOOKING at the shots (w2 or a Haiku given a
list of what to look at: paint not dark, lamps not blown, kit parts readable, no new shine, no seams/flicker):
- Cars: Skyline, Tiburon, one dark-paint and one light-paint car, one stock and one with a kit; traffic and rivals count as cars too.
- Scenes: garage (CarCustomize, front/side/rear), race start by day, a night track, WORLD at night with traffic.
- Tool: build/carpack/matrix.sh (one Chrome run at a time, <= 4 min each). The shots + a one-line verdict per cell go to build/carpack/matrix.md.
A step is done when no cell is worse than carpack=0 and the cells it targets are visibly better. A gate on one scene alone is not acceptance.

## Gates (all measured on the same scene, each with ?carpack=0 identical to today)
- paint luminance >= 0.160 and <= 1.10 x original (0.165); pixels > 0.9 and saturated-red pixels not above today's.
- reflection path unchanged: only the diffuse term and lamp handling change.
- At close only: gate60 in garage and race start (p50 <= 16.7 ms, no frame > 33 ms); `node tools/webcheck.mjs --route` PASS.

## Content (in this order)
1. Brightness and lamps. RE: car.efx constants 0x40fae0, CarRenderInfo::Render 0x56dc30, SH terms c0..c9 per car.
2. Kits and parts: contrast, edge, colour. RE: CarParts 0x80034602, materials with DiffuseRange 0 (DULLPLASTIC, MATTEPLASTIC, MOLDINGS,
   SHINYPLASTIC, GRILL), what the data lets us change per part. docs/re/car_assets.md has the hooks.
3. HD textures of parts: coverage (build/carao/texcover*.tsv, web/remaster cars2) and wiring.
Out of this scope: AO bake into COLOR0 (paused: it darkens), Open World work (nfsu-c4's other lane), publishing.

## Effort and roles
50 % reverse engineering (name the address before a change), 10 % orchestration, 40 % implementation.
nfsu-w2 (this window) orchestrates: max 3 subagents (1 Sonnet or Opus + 2 Haiku only when worth it), reconciles, checks the scope.
nfsu-c4 (Opus 5.5): implements in host/sm1.c, web/mode.js, web/index.html (+ web/gpu.js for step 3 only, behind ?carpack); may run 1 or 2 subagents. Only one Chrome run at a time,
<= 4 min, load < 6. No ceremonial tests: a test must be able to fail on a real break. If two attempts at a step fail: evidence to
HANDOFF.md and the next step, no third attempt. Overnight: decide the simple option and log it in HANDOFF.md; do not wait for the OWNER.
