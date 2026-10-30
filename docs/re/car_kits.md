# Car kits and parts: contrast, colour, volume in the Remaster (Skyline, Tiburon)

Goal (docs/SCOPE_CARS.md, content item 2): kits and parts with visible contrast/colour/volume, no new reflections, paint not darker.
Tool tags: G = Ghidra export (census/ghidra/decomp_0x*.c), H = Hopper export (census/hopper/decomp.c, grep only),
P = Python readers I wrote over game/ files (build/carpack/mats.py, solidmats.py, paintparts.py; read-only),
S = host/sm1.c as it is today. REA MCP and live Hopper were NOT used in this pass.
Offsets are for Speed.exe base 0x400000.

## Hallazgos

### 1. What reaches the pixel shader per part

- The car pixel shader sees only: the SH constants c0..c9 (one set per car), c14..c16 (cube rotation), c17 (eye), **c18 DiffuseMin(+a), c19 DiffuseRange,
  c20/c21 SpecularMin/Range, c22/c23 powers, pc0/pc1 EnvmapMin/Range**, and ONE 2D texture (t1) whose alpha is the reflectivity mask (S car_ps_body, car.efx.txt).
  Vertex COLOR0 is ignored (0xff000000). No tangents. No part hash, no slot id, no paint tint constant.
- The constants are written per draw group by 0x40fae0 (G census/ghidra/decomp_0x401000_0x4a6800.c line 11391), with ECX = material record (160 B, GLOBALB chunk 0x135200)
  and EAX = mesh flags:
  DiffuseMin = rgb(+0x34) * +0x30, a = +0x50; DiffuseRange = rgb(+0x44) * +0x40 - Min; Spec* from +0x5c/+0x6c, Env* from +0x80/+0x90 (times 0.5 = [0x6cc7dc]).
  Env terms are zeroed when flag 0x100 is clear or cube quality [0x700e74] = 0; diffuse and spec are zeroed only when the env path is on AND flag 0x80 is clear
  (G: `else if (-1 < (char)in_EAX)`). Car meshes carry 0x4180/0xc180 (0x80 and 0x100 set), so they keep diffuse.
- So the only per-part signal is the **material signature (c18, c19, pc0, pc1)** of the group. The shader can read it with no exe change, and car_ps_vol already does
  (vrg = max(c19.rgb), vmx = max(c18+c19)). This is data per MATERIAL, not per part: two parts with the same material look identical to the shader.
- Which materials the kits use (P, solids whose LOD A has at least one group of that material; counts are solids, NOT triangles, so the weight by area is NOT VERIFIED):

  | material (hash) | Skyline (99 solids) | Tiburon (100) | signature (P, build/carpack/materials_rgb.txt) |
  |---|---|---|---|
  | CARSKIN 0xd6d6080a, patched to the paint material at Render | 76 | 77 | paint: see below |
  | PLAINNOTHING | 59 | 53 | min 0, max 0: black, no env |
  | BOTTOM | 32 | 34 | min 0.83, range +0.01, env 0 |
  | CARBONFIBER | 15 | 16 | min 0.58, max 1.04, range +0.46 (already contrasty) |
  | MOLDINGS | 14 | 11 | min 1.00, range 0, env 0.27 |
  | ALUMINUM | 11 | 11 | min 0.70, range 0, env 0.01..0.11 |
  | DULLPLASTIC | 7 | 12 | min 1.00, range 0, env 0.13 |
  | GRILL | 6 | 10 | min 1.10, range -0.06, env 0.10 |
  | CHROME, HEADLIGHTGLASS, HEADLIGHTREFLECTOR | 5, 3, 0 | 3, 5, 5 | diffuse 0 or glass: not touched |

  All kit-plastic materials have rgb = (1,1,1): their colour comes only from the texture (CARBOTTOM, GRILL_02, INTERCOOLER, BADGING).
- Paint materials (REGPAINT*, METPAINT*, PEARL*, CUSTOMPAINT_n) have rgb about (1,1,1) too (REGPAINTRED min (1.04,1.03,0.89), P). **The paint colour is not in the material.**
  Many presets share one material hash with different colours (P: GLOSS_L2_COLOR01 RGB 130,130,155, _06 80,80,80 and _11 129,130,120 all use material hash 2189453964), so the colour lives in the part.

### 2. How the game picks and applies paint and part colour

- Paint = a CarPart of slot 30 (type byte 0x1e). Attributes (P, tools/re/carinfo.py parts()): RED, GREEN, BLUE (0..255), GLOSS (128), and 0x6ba02c05 = material hash.
  Presets are the "ANY" car parts GLOSS_L1/L2/L3_*, METAL_L2_*, ... (P, build/carpack/paintparts.py). Colour-preset names come from chunk 0x34601 (docs/re/tuning.md, reader 0x4322a0).
- Material half: CarRenderInfo ctor 0x56a130 (G census/ghidra/decomp_0x54c000_0x5f1800.c ~line 21891) reads attribute 0x6ba02c05 of RideInfo+0x4c4 (= slot 30), scans the material
  list DAT_00743c18 and stores the record at CarRenderInfo+0x4d0 (param_1[0x134]); windshield tint (slot 115, RideInfo+0x618) goes to +0x4d4. Render 0x56dc30 then replaces every
  CARSKIN group's material with it (docs/re/car_assets.md section 3).
- Colour half: RED/GREEN/BLUE are scanned by key hash 0xd99a / 0x2ddc8f0 / 0x136707 in **0x4d77a0** (G census/ghidra/decomp_0x4a6800_0x54c000.c line 34144). Its only caller
  is **0x4d7980**, a garage UI swatch (FEng object; H census/hopper/decomp.c 477579, callers 491111..491159). The same three keys are also read, plus ALPHA, for slot 116 NEON
  (G decomp_0x54c000_0x5f1800.c ~21540..21700, RideInfo+0x61c).
- The paint reaches the car as pixels: **0x5a9ce0** (G decomp_0x54c000_0x5f1800.c line 73002, gets "%s_SKIN1" target at CarRenderInfo+0x444) loops 8 layers, reads for each vinyl layer the
  4 packed colours at RideInfo+0x4f4.. (slots 42..57, VINYL_COLOURn) and for slots 37..40 (PAINT_ENGINE/SPOILER/BRAKE/EXHAUST) RED/GREEN/BLUE/GLOSS through 0x57cc70, then calls
  **0x5a8a50** (32-bit surface) or **0x5a8e90** (8-bit, byte 0x4a == 8) which remap each source pixel with a 4-colour palette on the CPU (G line 71883, uses float 0.003921 = [0x6cc970]).
  So body paint, vinyl colours and decals are baked into SKIN1 on the CPU. The shader never receives a paint colour constant.
- Answer to "can a kit get an accent derived from the paint without touching game data": **yes, read-only, but not from the shader alone.**
  (a) Parts drawn with CARSKIN already ARE the paint (same SKIN1 texture, same material). (b) For non-paint kit materials the shader has no paint colour; the host must hand it
  one. The three bytes are in the slot-30 CarPart: RideInfo+0x4c4 -> CarPart+0x14 = attribute array (pairs key, value), +0x1c = count (short). A read in the host (or a patch-table
  hook at Render 0x56dc30 that copies them to a spare uniform) changes no game data.

### 3. Why the kits are flat today (S + P)

- For a range-0 material the game's own formula gives k1 = c18 + d*c19 = c18, one number, so the diffuse is SH(N) * Min * texture: the only shading is the SH ambient, which varies little.
- car_ps_vol (host/sm1.c) already adds a ramp vf = 1 + 0.35*vs*(d - 0.55) with d = N.V: from d = 1 to d = 0.3 the whole swing is 1.16 -> 0.91 (25 %), then dk0 (car_ps_detail_pack
  floor 0.8) and the crease/edge term. A 25 % swing on a mid-grey texture is what the A/B (build/carlook/carvol/ab_kit_0_vs_1.png) shows: barely visible.
- The artists' own precedent in the same file: materials made for contrasty parts have range/min = CARBONFIBER 0.79 (0.58 -> 1.04), DULLENGINE 1.0, RUBBER 1.4, RAD/MESH 2.3, METPAINT 1.0..2.2
  (P). The kit plastics are 0.00..0.01. The kit materials were left flat by the data, and the formula that fixes it is the game's own.

## Propuesta

**Main change: give the range-0 kit materials the CARBONFIBER range, with the pivot at today's d = 0.55 so nothing facing the camera gets darker than now.**
One constant K, one place (car_ps_vol), diffuse only (volk), no new reflection (t0, a, d1c are not touched).

Formula (d = max(N.V, 0.01) is already in car_ps_body):

    vk = (1 + K*d) / (1 + K*0.55)          K = 0.8 (CARBONFIBER 0.46/0.58); strong preset K = 1.4
    km = (1 - smoothstep(0.02, 0.12, vrg)) * smoothstep(0.1, 0.4, vmx)     strict kit mask
    vf_kit = mix(vf_old, vk, km)           vf_old = the current 1 + 0.35*vs*(d - 0.55)

Values: d = 1.0 -> 1.25, 0.8 -> 1.14, 0.55 -> 1.00, 0.3 -> 0.86, 0.05 -> 0.72 (today at vs = 1: 1.16, 1.09, 1.00, 0.91, 0.82). Slope 0.35 -> 0.56 (K 0.8), 0.79 for K 1.4.
Final volk is still clamped to [0.3, 1.6] and multiplied into dk as today; the crease term `(1 - 0.25*vs*...)` stays, with 0.25 -> 0.40 for km pixels (same place) if the first look is too soft.

Where in host/sm1.c (S, current line numbers): `car_ps_vol` (line ~449). Replace the `vf` line by

    "  let km = (1.0 - smoothstep(0.02, 0.12, vrg)) * smoothstep(0.1, 0.4, vmx);\n"
    "  let vk = (1.0 + %.2f * d) / (1.0 + %.2f * 0.55);\n"
    "  let vf = mix(1.0 + 0.35 * vs * (d - 0.55), vk, km) * (1.0 - 0.25 * vs * smoothstep(2.0, 10.0, -hc)) * (1.0 + 0.08 * vs * smoothstep(4.0, 14.0, hc));\n"

and pass K twice from the emit() at line ~529 (0.8 for ?carvol=1 and the carpack path, 1.4 for ?carvol=2). Gate it behind the existing switch (RN_CARVOL=0 stays bit-identical).
The pack tail (`pb0*(1 + 0.12*(1-pb0)^2)`) runs after this and lifts dark pixels a little.

Who gets it (P): MOLDINGS, DULLPLASTIC, MATTEPLASTIC, SHINYPLASTIC, BOTTOM, ALUMINUM, GRILL (and MAGSILVER on the wheels, range -0.02); CARBONFIBER (range 0.46), MESH, RAD (range 0.7) keep the old path
(vrg >= 0.12 gives km = 0). Not touched: PLAINNOTHING, CHROME, mirrors, reflectors (vmx < 0.1 gives km = 0), and no floor is added to them (no evidence what their black is for).
Known collision: a paint with range ~0 looks like a kit plastic to the shader (P): REGPAINTGREEN (min 0.80, range +0.01), CUSTOMPAINT_13/14/2, PEARL3/8, RIMPEARL6/8. They take vk too.
Because vk is 1.0 at d = 0.55 the mean paint level is kept; it only widens the swing. This must pass the SCOPE gate (paint luminance >= 0.160 and <= 1.10 x 0.165) on the Skyline rear scene.

### Second step, only if the owner still wants colour (needs one host uniform)

Colour accent for unpainted kit materials: `acc = paint / max(paint)`, divided by its luminance (so it adds no brightness), then in the tail
`pb = pb + km_plain * 0.05 * acc * (1 - pb0)` with km_plain = km * (1 - smoothstep(0.05, 0.2, max(pc0.rgb)))  (not on SHINYPLASTIC/MOLDINGS-like env > 0.2).
Additive, because a multiplicative tint on the dark CARBOTTOM / GRILL_02 textures shows nothing. Start 0.05 (0.03..0.08). The uniform comes from the slot-30 part bytes at
RideInfo+0x4c4 (section 2), read once per car in the host or by a patch at Render 0x56dc30 (one line in tools/recomp/patches.py with the reason). Do this only after the main change is judged.

## Sin verificar

- The A/B result: I did not run the game or Chrome (scope). The numbers above are arithmetic on the shader and on the materials file, not measurements of a frame.
- The weight by screen area/triangles of each material on a Skyline/Tiburon kit (counts above are solids that contain the material). The group record is at 0x40c910 (+0x20 material
  index, +0xc index count) and could give it.
- The mapping of the constant registers c18/c19/c20.. to the 4 `SetVertexShaderConstant` calls in 0x40fae0 comes from host/sm1.c and docs/re/car_assets.md; the Ghidra stack variables of 0x40fae0
  are aliased and I did not re-derive the register numbers (capstone listing of 0x40fae0 not read to the end).
- Where exactly the slot-30 body colour is consumed inside the compositor (0x5a9ce0 -> 0x5a8a50/0x5a8e90): the RGB of slots 37..40 and the vinyl colours at RideInfo+0x4f4 are read there,
  the base layer path (0x5a9930, 0x5aa800) was not followed. Whether the body paint also lives in SKIN1 or enters through the paint material alone is not proven; the RED/GREEN/BLUE keys
  themselves are only read by 0x4d77a0 (UI swatch) and the NEON block in the ctor, which suggests the former.
- Whether the shader can tell a painted kit surface (CARSKIN patched) from a plastic one when their signatures collide (list above): it cannot; the mask is by signature only.
- `PLAINNOTHING` role (59 solids per car): black by data (min 0, max 0); what those groups are in the picture was not identified.
- Garage presets in chunk 0x34601 were not decoded.
- Not tried (out of the list by the brief): normal/roughness maps, carlook candidates, new reflections, AO in COLOR0.
