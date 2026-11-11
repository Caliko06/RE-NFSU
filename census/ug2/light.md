# UG2 world shading: how SPEED2.EXE v1.2 combines colour, fog and material (facts for the browser pass)

Exe = pc/ug2/SPEED2.EXE (md5 59b7d600...), VA = file offset + 0x400000 in .text. Shaders are NOT compiled blobs hidden in code: they are 23 D3DX9 effect files (`0xFEFF0901`, compiler "D3DX9 5.04.00.2904", vs_1_1 / ps_1_1) stored as RCDATA resources named `IDI_*_FX` in .rsrc (file 0x41d000). Extracted with a throw-away PE resource walker and disassembled with a small vs/ps 1.x disassembler (not committed; every listing below is quoted). "Res file off" = byte offset inside SPEED2.EXE; resource VA = file + 0x49f000. Marks: FACT = read from exe bytes or code, INFERENCE = consistent reading, UNKNOWN = not found.

## 1. Which effect draws a scenery group
| fact | value | proof |
|---|---|---|
| Effect table (23 entries, stride 0x8c, entry = {?, path, name, ...}) | idx 0 WORLD, 1 WORLDHEADLIGHT, 2 WORLDREFLECT, 3 WORLDHEADLIGHTREFLECT, 4 WORLDBONE, 5 CAR, 6 WORLDMIN, 7 WORLDNOFOG, 8 FE, 9..12 DEPTH_WORLD*, 13 WORLDNODEPTH, 14 WORLDHEADLIGHTNODEPTH, 15 FILTER, 16 OVERBRIGHT, 17 SCREENFILTER, 18 DEPTH_OF_FIELD, 19 RAIN_DROP, 20 SKYMORPH, 21 HORIZON_FOG, 22 RUNWAYLIGHT | table at 0x7ff84c; names read at 0x7ff854, 0x7ff8e0, 0x7ff96c ... 0x80045c (FACT). Loop of 23 objects stored to `0x86eb28[4*i]`: `mov [4*ebp+0x86eb28],eax` at 0x5d243a, `cmp ebp,0x16` at 0x5d2442 (FACT). That index i = table index is INFERENCE, confirmed by the layouts below |
| Mask -> object | mesh mask &0x1 -> 4 (WORLDBONE), &0x40 -> 2 (WORLDREFLECT), &0x80 -> 5 (CAR), else 0 (WORLD) | table 0x800464 = {0x1,4},{0x40,2},{0x80,5}, default 0 (read at file; code 0x5c58cf..0x5c5919, result stored `mov [ecx+0x3c],edx` 0x5c591b) |
| Layout check of the mapping | WORLD vs declares position, colour0, texcoord0 (24 B); WORLDREFLECT same; CAR declares position, normal, texcoord (no colour used); WORLDBONE adds blendweight/blendindices | vs `dcl_*` lines: WORLD res 0x423320, REFLECT 0x432870, CAR 0x43b264. Matches measured strides: mask 0 and 0x40 = 24 B, mask 0x4180 = 36 B (has a normal) |
| Per group substitution | texture record +0x56 == 2 (additive, SRCALPHA/ONE) and base effect kind [obj+4] is 0 or 1 -> effect `[0x86eb44]` = idx 7 WORLDNOFOG (no fog). Texture hashes 0x06d57415 and 0xbd3d01a8 -> `[0x86eb80]` = idx 22 RUNWAYLIGHT. Other kinds -> idx 9..13 (depth / no-depth variants, `[0x86eb4c..0x86eb60]`) in the headlight/depth passes | 0x5c5acc..0x5c5ade (`cmp dl,2 ... mov ecx,[0x86eb44]`), 0x5c5b79..0x5c5b89; call of the queue 0x5ceb30 at 0x5c5ba7 (FACT; meaning of the other modes UNKNOWN) |
| Scenery in the RA city | masks: 0 (8,982 solid chunks), 0x40 (1,605), 0x1000 (2), 0x4180 (115). So almost everything is WORLD; roads/glossy 0x40 = WORLDREFLECT; 62 solids = CAR | census/ug2/tex.md mask table + probe below |

## 2. Final colour (WORLD, idx 0; the one the browser must copy)
Vertex shader, res file 0x423320 (VA 0x8c2320 = `IDI_WORLD_FX` offset 0x25b0), constants from its CTAB (0x423328): WorldViewProj c0..c3, WorldView c4..c6, TextureOffset c7, FogValue c8:
```
def c9,1,0,0,0
dcl_position0 v0 ; dcl_color0 v1 ; dcl_texcoord0 v2
dp4 oPos.x,v0,c0 ; dp4 oPos.y,v0,c1 ; dp4 oPos.z,v0,c2 ; dp4 oPos.w,v0,c3
dp4 r0.w,v0,c6                       ; view-space depth (3rd row of WorldView)
add r0.w,-r0.w,c8.x ; mul r0.w,r0.w,c8.y ; max r0.w,r0.w,c8.z ; min oFog,r0.w,c9.x
add oT0,v2,c7                        ; uv + TextureOffset (texture scroll)
mov oD0,v1                           ; vertex colour passed through, NOT lit
```
Pixel shader (ps_1_1), res file 0x422f9c:
```
tex t0
mul r0, t0, v0            ; texture * vertex colour, all 4 channels
add r0.xyz, r0, r0        ; rgb x2   (the "modulate 2x")
mov r0.w, r0.wwww         ; alpha = tex.a * vertex.a
```
| fact | value | proof |
|---|---|---|
| Colour | out.rgb = clamp(2 * tex.rgb * vtx.rgb); out.a = tex.a * vtx.a. Vertex byte 128 = neutral. No lighting term, no normal, no ambient, no sun, no time-of-day constant in this effect | listing above; the effect has 14 parameters only: BlendState, Base{Min,Mag}TextureFilter, WorldViewProj, WorldView, TextureOffset, TextureOffsetMatrix, diffusemap, BaseTextureFilterParam, FocalRange, FogOn, FogColor, FogValue, samp (parameter table of the effect, read with the D3DX effect layout) (FACT) |
| Same result in the fixed-function fallback technique `world_fixed` | COLOROP = MODULATE2X (value 5), COLORARG1 = TEXTURE, COLORARG2 = DIFFUSE, ALPHAOP = MODULATE, ALPHAARG1 = TEXTURE, ALPHAARG2 = DIFFUSE; stage 1 disabled | state records: COLOROP value 5 at res file 0x421ab4, `103..110` in the D3DX state numbering (INFERENCE for the numbering: 103,104,105,106,107,108,109,110 = ColorOp, ColorArg0..2, AlphaOp, AlphaArg0..2; values 5,-,2,0,4,-,2,0 fit it exactly) |
| uv offset | TextureOffset (c7) is added to uv per draw; value source (scroll via texture record +0x52 == 3, s16 +0x5e/+0x60, exe 0x5bcdf2) not decoded | listing; UNKNOWN for the values |
| Sampler | ADDRESSU = ADDRESSV = WRAP (1), mip filter LINEAR (2); min/mag filter come from the params BaseMin/BaseMagTextureFilter (value set by the game, UNKNOWN) | sampler block of `samp`: values at res file 0x421220 (=1), 0x421240 (=1), 0x421260 (=2). State ids 165/166/171 = ADDRESSU/ADDRESSV/MIPFILTER is INFERENCE (D3DSAMP order after Texture = 164). Answers the "wrap vs clamp UNKNOWN" of tex.md: WRAP. Same in WORLDREFLECT (0x4300bc..), WORLDNOFOG (0x424730..), CAR (0x43837c..) |
| Second pass of technique `world` | a position-only vs writing view depth into colour (res file 0x422da0: `dp4 r0.w,v0,c6; mul c7.x; max c8.x; min oD0.x,..`) and ps `dp3 r0,c0,v0` (0x422cf0), with COLORWRITEENABLE = 8 (alpha only) in the second pass: writes depth into destination alpha for the depth-of-field filter (FocalRange, DEPTH_OF_FIELD.efx). It must not change RGB | INFERENCE (state 73 = COLORWRITEENABLE value 8 at res file 0x4216dc; numbering not proven). Browser: ignore |
| Alpha test / blend | from the TEXTURE record, not the effect: ALPHATESTENABLE/ALPHAREF 0x5f when +0x55 == 1, blend table from +0x56 (0x5bcca7, 0x5bccbc..0x5bcd14; see tex.md). Because the ps outputs tex.a * vtx.a, VERTEX alpha takes part in the alpha test (ref 0x5f = 95/255) and in SRCALPHA blending | FACT from the ps and 0x5bcb70; blend/test only when the flags say so |
| WORLDREFLECT ps (mask 0x40, road) | `tex t0; tex t1; mul r0,t0,v0; add r1.xyz,r0,r0; mad r0.xyz,t1,r0.wwww,r1; mov r0.w,c0.wwww (c0.w = 1)` => rgb = 2*t0*v0 + t1.rgb * (t0.a * v0.a); alpha forced 1.0. t1 = ReflectedTex (render-to-texture of the scene; vs maps it with ReflectedProj) | res file 0x432738 (ps), 0x432870 (vs) (FACT). Road texture alpha is 1..9/255 (tex.md), so the reflection weight is about 0.02 x 0.5: a browser draw can skip t1 and use 2*tex*vtx |
| WORLDNOFOG (idx 7, additive textures) | same ps (res 0x425fcc) and vs (0x426350) minus the fog instructions | FACT |
| CAR (mask 0x4180, 62 solids / 3,624 vertices) | lit by normal: vs computes a spherical-harmonic diffuse from HarmonicCoeff (c0..c9), AmbientCoeff, DiffuseMin/Range, SpecularMin/Range, EnvmapMin/Range, SpecularPower, EnvmapPower, LocalEyePos (c17); ps modulates tex x2 and adds specular + env map. vertex colour is NOT read (no dcl_color) | res file 0x43b264 (vs), 0x43b0a8 (ps), CAR parameter table. Constant values come from the material record (section 4), runtime values UNKNOWN. Browser: treat as 2*tex*(grey) |
| Headlight variants | idx 1, 3, 10..14 add HeadlightTex/HeadlightColor/HeadlightClipTex and a depth/clip projection on top of the same 2x modulate (ps res 0x1390 of IDI_WORLDHEADLIGHT_FX: `mul_sat_x2 r0.xyz,t0,r0` where r0 = headlight term + v0). Only when a car headlight lights the surface; not needed for the static city | FACT for the listing, trigger UNKNOWN |

## 3. Fog
| fact | value | proof |
|---|---|---|
| Mechanism | per-vertex linear fog. oFog = clamp((FogValue.x - viewZ) * FogValue.y, FogValue.z, 1); D3D fog factor 1 = unfogged, so fogged colour = f * pixel + (1 - f) * FogColor. FOGENABLE and FOGCOLOR are effect states fed by params FogOn and FogColor; the effect sets no FOGTABLEMODE/START/END (D3D device init sets FOGENABLE=0 only, 0x5c24b2..0x5c24be) | vs listing section 2; effect state numbering 14/16 = FOGENABLE/FOGCOLOR is INFERENCE (D3DRS order: ZENABLE 0 ... FOGENABLE 14, FOGCOLOR 16 in the D3DX table; their values are expressions bound to FogOn / FogColor, expression blocks named FogOn / FogColor in the effect, res file 0x42138c) |
| Where FogValue comes from | `FogValue = (250.0, 1/(250.0 - S), min(1 - D, 0.6), ?)` with S = float [0x89e85c], D = float [0x89e860]; sent with SetVector (effect vtable +0x88, handle `[param_obj+0x4ac]`) | exe 0x5cb032 `fld [0x7a27a0]` (= 250.0, read bytes 0x437a0000), `fsub [0x89e85c]`, 0x5cb03e..0x5cb04e (x = 250.0, y = 1.0/(250-S) with `fdivr [0x784250]` = 1.0), 0x5cb052..0x5cb06f (z = 1.0 - [0x89e860], clamped to <= 0.6 = `[0x784564]` 0x3f19999a), call at 0x5cb092 |
| Meaning | fog starts at view depth S, is full (factor floor z) at 250 world units; fog weight is at most max(D, 0.4) | derived from the two lines above |
| FogColor | D3DCOLOR 0xFF RR GG BB with each channel = trunc(0.75 * byte) of the dword at [0x89e864] (bits 16..23 -> R, 8..15 -> G, 0..7 -> B; the 0.75 is `[0x785510]`), sent with SetInt (vtable +0x68, handle `[param_obj+0x45c]`) | 0x5cb0b8..0x5cb189 (`and edi,0xffffff`, three `fmul [0x785510]` + `call 0x75bed4`, call at 0x5cb189). That 0x75bed4 truncates (CRT ftol) is INFERENCE |
| FogOn | int = global `[0x870cd8]` (the same address registered under the name `g_FogEnable`, 0x5bebd3..0x5bebe8); default value UNKNOWN (runtime) | SetInt at 0x5cb0b5 |
| Filling [0x89e850..] | function 0x614300(this = 0x89e850, view) is the ONLY writer of S, D, colour (resolved in section 8). Only caller: 0x5cb028..0x5cb02d; no vtable/pointer to 0x614300 or 0x89e850 exists (byte search of the whole exe: 0x89e850 only at 0x5cb029, 0x89e85c/60/64 only at 0x5cb03a/5a/c3) | section 8 |
| Horizon fog | separate post effect `horizon_fog.efx` (params diffusemap, ScreenOffset), flag `g_HorizonFogEnable` | resource IDI_HORIZON_FOG_FX 0x4460f0 (1,348 B), string 0x7a36f4. Not decoded further. Browser: skip |

## 4. Material record 0x135200 (GLOBALB.BUN, 160 B, 27 f32 at +0x34)
| fact | value | proof |
|---|---|---|
| Who uses it in the city | groups with a material slot, per vertex mask (all 56,982 groups of STREAML4RA, group +0x20 -> table 0x134013): mask 0x40: ROAD 0x001c3745 on 2,342 groups, none on 2,748; mask 0x4180: ALUMINUM_2 0x5f5fa298 on 129, ALUMINUM 0x2e65e067 on 12, none on 221; mask 0: ROAD on 12, none on 22,552; mask 0x1000: none | measured, STREAML4RA.BUN chunk 0x134b02 (+0x20 of each 0x3c-B group) and 0x134013 pairs |
| ROAD floats | (0.9, 0.57, 0.56, 1) twice, (1, 1.523, 1, 1), (1, 1, 1, 1), (1, 1, 2.0, 0.048), (1, 1, 1, 0.302), (1, 1, 1) | GLOBALB.BUN record at file 0x57f8 (name ROAD, version 3) |
| ALUMINUM_2 floats | (1, 1, 1.032, 1.075), (1, 1, 1.018, 1), (1, 0.88, 1.11, 1), (1, 1, 1.004, 1), then zeros | GLOBALB.BUN record at 0xb0; ALUMINUM at 0x8 has non-zero tail (1, 1, 0.826, 0.376), (1, 1, 1, 0.077), (1, 1, 1) |
| Role in the world pass | NONE for WORLD and WORLDREFLECT: neither effect declares a material-like parameter (list in section 2). The only effect with DiffuseMin/Range, SpecularMin/Range, EnvmapMin/Range, SpecularPower, EnvmapPower, AmbientCoeff (= 6 x float4 + 3 = 27 floats) is CAR, i.e. the 0x4180 groups. So the 27 floats are the CAR/lighting-material block (the `eLightMaterialPlatInfoSlotPool` of exe string 0x7a3638) | float count 27 = 6*4 + 3 matches the CAR parameter table. The ORDER of the 27 floats vs the parameters and the code that uploads them: UNKNOWN. In the draw 0x5c5aaa..0x5c5abb the material pointer is only fetched and queued (`push eax` 0x5c5b98 -> 0x5ceb30) |
| Consequence | Ignore the material for ROAD and all mask 0 / 0x40 geometry: road colour = 2 * tex * vertex colour. Only the 62 mask-0x4180 solids need a lit (normal-based) look, 3,624 vertices |  |

## 5. Ambient, time of day, sky
| fact | value | proof |
|---|---|---|
| Ambient / sun / TOD multiplier on world colour | none in WORLD, WORLDREFLECT, WORLDNOFOG, WORLDMIN (WORLDMIN has only WorldViewProj). World colour is baked in the vertex colours | the four effect parameter tables / listings |
| Time of day that is applied | only through FogColor / FogValue (day/night fog curves, section 3) and the full-screen post effects below | 0x614300 uses `Night Normal Fog` and `Night Raining Fog` |
| Post effects (full screen, after the scene) | SCREENFILTER.efx: params TintColor, SaturationScale, FilterBlend, gainmap, rampmap; ps (res 0x1bf0 of IDI_SCREENFILTER_FX) does `dp3 r1,t0,{0.3,0.59,0.11}` (luma) and lerps colour/grey by FilterBlend -> a global tint + saturation grade. OVERBRIGHT.efx: params OverBrightOffset, OverBrightGreyScale: `mad_sat_x4 r0.xyz, (t0 - offset)` bright-pass, squared = bloom-like glow, flag `g_OverBrightEnable`. DEPTH_OF_FIELD.efx: DofFalloff, DofOffset1/2. FILTER.efx: 2..4 texture weighted sum (blur) | listings from the resources 0x441138 (SCREENFILTER), 0x43faf8 (OVERBRIGHT), 0x445030 (DOF), 0x43c2d0 (FILTER). The runtime values (TintColor etc.) UNKNOWN |
| Sky | SKYDOME solid, drawn with the WORLD effect; TOD textures swapped by hash; SKYMORPH only during a cross-fade | section 8 (resolved) |

## 6. Vertex colour statistics, RA city (tools/probe/ug2_vcol.py)
Colour bytes read from the vertex at +12 (BGRA in the file; shown as R,G,B,A), 4,449,461 drawn vertices from web/ug2/city.bin and the raw solids of STREAML4RA.BUN per mask (stride 24, colour at +12; mask 0x4180 stride 36, colour at +24).
| set | n | R mean / p5 / p50 / p95 | G mean | B mean | luma mean / median | rgb max >= 128 (x2 saturates) | alpha |
|---|---|---|---|---|---|---|---|
| city.bin, drawn (instance weighted) | 4,449,461 | 69.3 / 12 / 55 / 192 | 68.6 (p50 56) | 66.9 (p50 56) | 68.6 / 56 | 14.9 % | 94.3 % = 255, 5.4 % in 1..254, 0.2 % = 0 |
| raw mask 0x0 | 1,113,675 | 70.4 / 7 / 49 / 211 | 68.4 (p50 49) | 65.1 (p50 48) | 68.6 / 49 | 18.7 % | 92.7 % = 255, 6.8 % partial |
| raw mask 0x40 (road, REFLECT) | 187,248 | 87.6 / 25 / 69 / 216 | 83.0 (p50 67) | 73.2 (p50 62) | 83.2 / 67 | 22.7 % | **97.7 % partial: 130 (0x82) at p5..p75, 170 (0xaa) at p95, mean 129**; 2.2 % = 0 |
| raw mask 0x1000 | 16 | 186.5 | 181.0 | 179.0 | 182.4 | 50 % | all 255 |
| raw mask 0x4180 (CAR) | 3,624 | 74.1 / 27 / 68 / 135 | 74.6 | 73.8 | 74.3 / 68 | 7.6 % | all 255 (colour unused by CAR vs) |
Reading (FACT = measured; the brightness conclusion is INFERENCE):
- The data is dark by design: median 55/255 (0.22), mean 69/255 (0.27). Under the exe's rule out = 2 * tex * vtx the median surface is 0.43 x its texture and the mean 0.54 x, and 15 % of vertices are >= 128 so they over-brighten (clamped at 1.0 after x2). Without the x2, or with textures missing, the city is about half as bright as it should be and looks black.
- Vertex alpha is real data: partial alpha on 5.4 % of the drawn vertices (all of mask 0x40 sits at 130 / 170). It matters for alpha test and SRCALPHA blend (ps multiplies it in) and, on the road effect, only as reflection weight; it is not a blend factor when the texture flags say no blend (tex.md combos).
- Triangle-level alpha use (tex.md): 571,272 alpha-tested, 32,624 alpha-blended, 198,589 additive.

## 7. What the browser pass should do (derived, not extra facts)
1. rgb = min(1, 2 * tex.rgb * vtx.rgb); a = tex.a * vtx.a; alpha test only when record +0x55 == 1 with ref 0x5f/255; blend only per +0x56; WRAP uv.
2. Fog per vertex, linear in view depth: f = clamp((250 - z) / (250 - S), zmin, 1); out = f * c + (1 - f) * FogColor; additive (+0x56 == 2) groups unfogged. S, zmin, FogColor: row of the camera position in section 8 (night = `Night Normal Fog`).
3. Roads (mask 0x40): same formula, skip the reflection term; keep vertex alpha out of the output alpha (the ps forces alpha 1).
4. No ambient / sun / time-of-day multiplier on scenery; no material for ROAD.

## 8. Fog and sky, resolved for L4RA (2026-11-10; probes tools/probe/ug2_fog.py, ug2_sky.py)
Fog source chain: 0x614300 -> `Normal Fog` / `Night Normal Fog` tables in **TRACKS/L4RA.BUN** (the "no plain-text copy" of section 3 was wrong: the curves are chunks 0x0003b601 inside container 0x8003b600 at file 0x18400; the name is the key = hash32 of the string, h = h*33 + c from 0xffffffff, exe 0x43db50). Other tracks have their own copies (L4RB..RR: same 4 hashes).
| fact | value | proof |
|---|---|---|
| Writers of S, D, colour | one function, 0x614300. S = `[esi+0xc]` = column 1, D = `[esi+0x10]` = column 0, colour dword `[esi+0x14]` = ((col4 << 8 | col3) << 8) | col2 (each ftol'd, 0x614585..0x6145b2). Columns 5,6,7 go to `[esi+0..8]`; nothing reads them (no reference to 0x89e850/54/58 besides `mov ecx,0x89e850`), dead stores | 0x61456f..0x6145b2 |
| FogColor byte order | D3DCOLOR 0xFF RR GG BB with R = trunc(0.75 * col4), G = trunc(0.75 * col3), B = trunc(0.75 * col2); the three values are first ftol'd to int, then x0.75, then ftol'd again | 0x5cb0c9..0x5cb171 (first extracted byte is bits 16..23 = col4 and ends up in bits 16..23 of the output) |
| Flag [0x8a1d70] | **never written**: the only instruction that mentions the address is the read at 0x614301; no pointer constant in 0x8a1c00..0x8a1d70 reaches it as a struct member (array 0x8a1d1c holds 7 dwords, index < 7, 0x611fd8..0x611fe2); it lives in BSS (.data raw ends at 0x81d000) so it is 0. Therefore the "override" branch (S 212, D 0.74, colour 6e,69,4b) NEVER runs in this exe; the table branch always does | grep of all of .text + byte search of the image |
| Table lookup | position = camera `x = [[view+0x40]+0x40]`, `y = [[view+0x40]+0x44]` (0x5f0c50, same fields the sky uses at 0x60f93c). Quadtree over bounds (x0,y0,x1,y1) = (-7840, -6880, 2400, 3360) for Normal and Night Normal (these also cover the whole city, -3100..1900 x -2080..3152): node = 4 u16 children, a node whose first u16 is 0 is a leaf holding the row index in the second u16; split at the midpoints, `x < mid` picks the low half; outside the bounds the row is 0. Row = 8 f32 (stride in header +0x1c). Chunks: 0x3b602 header (hash, 4 f32 bounds, nodes, rows, stride, cols), 0x3b603/0x3b604 column tables (all 0 / 0,4,..,28), 0x3b605 rows, 0x3b607 byte-node tree (0x5f0930) or 0x3b608 u16-node tree (0x5f0a30, used here) | loader 0x5fa3b0 (jump table at 0x5fa4bc maps ids 0x3b602..0x3b608), 0x5fa4e0, 0x5f0930, 0x5f0a30; node/child layout read from the code, reproduced in tools/probe/ug2_fog.py |
| Smoothing | the row is blended from the previous lookup by t = min(1, distance moved / 50.0) (radius 0x42480000 pushed at 0x614407), so fog changes over about 50 world units of travel | 0x5fa660..0x5fa6ca (t = dist/radius), 0x5fa570 |
| Day / night weight | out[k] = a * Normal[k] + (1 - a) * NightNormal[k] for k = 0..7; a = (flag [0x8a1c90] == 0) ? 1 - w : w, w = float [0x8a1c88] | 0x6143a9..0x6143d7, 0x61443b..0x614561 |
| w and flag (TOD machine) | start: all zero (BSS; 0x60f849..0x60f86c re-zeroes) so a = 1: **day** fog first. Only runs when `[0x8654a4] == 6` (set at 0x5782f6) AND `[0x870d14] == 1` (0x5bf1b0; = min over graphics-setting values 0x87652c.., 0x5be81c..0x5be829). Every time `(int)[0x7fb718] % 300 == 60` while state [0x8a1c8c] = 0 the state becomes 2 (0x60fae0..0x60faea); state 2 advances the sky index [0x8a1c94] by 2 (mod 8) and goes to state 4 (0x60fc44..0x60fc73); state 4 raises w from 0.5 to 1.0 over 20 time units (0x60fc86..0x60fcc3, 20.0 = `[0x802954]`), then resets w = 0 and toggles the flag 0 <-> 1 (0x60fcd4..0x60fd21). State 1 is never entered (no writer of 1 for [0x8a1c8c]). So steady states: flag 0, w 0 = pure `Normal Fog` (day); **flag 1, w 0 = pure `Night Normal Fog`** | 0x60fa9f..0x60fd2b (jump table 0x60fd2c -> 0x60fbcb, 0x60fc44, 0x60fc7f, 0x60fc86). Meaning of [0x7fb718] (1.0 initial in .data, set to 1.0 at 0x576d0b, stored at 0x57a192): clock, source UNKNOWN |
| Sky index <-> fog | index 0 SKY_SUNRISE_A, 2 SKY_NIGHT_A, 4 SKY_SUNSET_A, 6 SKY_NIGHT_A (hash table 0x8a07a8.. filled at 0x60fb14..0x60fb8a); each cycle index +2 and flag toggles, so flag 1 (night fog) coincides with index 2 or 6 (night sky), flag 0 with sunrise / sunset | 0x60fc5c, 0x60fd16 |
**Values for L4RA, night, no rain** = `Night Normal Fog` (hash 0xaff712de, chunk at L4RA.BUN 0x1f91c, 460 nodes, 16 rows x 8 f32). FogValue = (250, 1/(250 - S), min(1 - D, 0.6), ?); FogColor from the last column. Rows (leaf share = share of a 20-unit grid over x -3100..1900, y -2080..3152):
| row | share | D | S | z min | FogColor R,G,B |
|---|---|---|---|---|---|
| 0 (also outside bounds) | 12.9 % | 0.5 | 200 | 0.5 | 96,96,96 |
| 1 | 8.0 % | 0.25 | 50 | 0.6 | 93,72,73 |
| 2 | 10.5 % | 0.15 | 175 | 0.6 | 80,90,79 |
| 3 | 12.6 % | 0.27 | 180 | 0.6 | 58,114,119 |
| 4 | 1.9 % | 0.4 | 220 | 0.6 | 69,90,82 |
| 5 | 18.5 % | 0.15 | 30 | 0.6 | 99,97,75 |
| 6 | 1.8 % | 0.3 | 100 | 0.6 | 78,60,55 |
| 7 | 1.4 % | 0.2 | 150 | 0.6 | 42,52,90 |
| 8 | 2.9 % | 0.2 | 175 | 0.6 | 4,57,108 |
| 9 | 0.9 % | 0.2 | 175 | 0.6 | 41,81,102 |
| 10 | 0.5 % | 0.2 | 25 | 0.6 | 109,110,84 |
| 11 | 0.9 % | 0.15 | 175 | 0.6 | 71,98,99 |
| 12 | 1.3 % | 0.333 | 180 | 0.6 | 48,55,99 |
| 13 | 9.0 % | 0.2 | 200 | 0.6 | 70,84,67 |
| 14 | 5.0 % | 0.28 | 35 | 0.6 | 58,114,119 |
| 15 | 11.8 % | 0.75 | 210 | 0.25 | 93,73,56 |
Row raw bytes: `python3 tools/probe/ug2_fog.py <L4RA.BUN> x y` prints every table and the leaf row for a camera (x, y). Day tables (`Normal Fog`, hash 0x1da6aca4, chunk 0x1e798, 17 rows) are printed by the same probe.
| fact | value | proof |
|---|---|---|
| Rain (not used at night/dry) | rain blend only when `[[view+0x64]+0x1f0] > 0` (0x6145b5..0x6145d1); table `Night Raining Fog` (hash 0xd105af5d, chunk 0x20a10, bounds (-3360,-2240,6880,8000), 2 rows: row 0 = default (0.5,200,128,128,128), row 1 = D 1.0, S 5, RGB 110,110,110, cols 5..7 = 0.3, 0.1, 0.27), `Fog Blend Distance` (hash 0x54f62e8b, chunk 0x20b24, 1 row, value 50.0; default `0x42480000` = 50.0 at 0x6145e6). Combination formula of the rain branch not decoded | 0x6145d7..0x61477f; probe output |
| Clear colour | `0xff000000` (opaque black); `0x00000000` when the clear-mode argument is 2; Z 1.0; flags 3 (target + Z) for view kinds 1, 3, 4..9, else 7 (+ stencil), or 1 when mode 2. Other Clear calls (0x5b9bf4, 0x5d2c39, 0x5bb956..) clear with colour 0 | 0x5ba3c0..0x5ba44f (`mov ecx,0xff000000; jne; xor ecx,ecx`, pushes at 0x5ba41d..0x5ba44a), 0x5b9be1..0x5b9bf4, 0x5d2bba..0x5d2c39 (register values 0 not traced: INFERENCE) |
| Sky mesh | solid **SKYDOME** (hash 0xbe43edbb = hash("SKYDOME"), compared at 0x5c59ec) in STREAML4RA.BUN (solid chunk 0x790648, second copy 0x2ab5e08): mask 0 -> WORLD effect (idx 0), 101 vertices, 144 triangles, 24 B stride, all vertex colour BGRA (80,80,80,255) so out = 2 * tex * 80/255 = 0.627 * tex; dome radius 9698.3 horizontal, z 0..8010.1; group 0: 288 indices, texture slot 1 (SKY_SUNRISE_A, hash 0x2414a01e); group 1: 144 indices (cap, z 4824..6334), texture slot 0 (SKY_SUNRISE_A_CAP, hash 0x5fb8bcd1). Texture table chunk 0x134012 = (0x5fb8bcd1, 0), (0x2414a01e, 0) at STREAML4RA 0x790728 | tools/probe/ug2_sky.py output; effect choice 0x5c58cf..0x5c591b |
| Sky draw | 0x60f880: builds a 4x4 with identity rotation and translation = camera position (x, y, z) (`[eax+0x30..0x38]`, 0x60f93f..0x60f9ac), scale 1.0 for view ids 1..3 (`[0x7a6768]`), 0.004525 (`[0x7a676c]`) for ids 16..21; draws the SKYDOME instance 0x8a1dfc through 0x5c5930 (call 0x60fa15); the placed instance in the section (pos -842, 285, 0) is not the one that is drawn at runtime | 0x60f9d8..0x60fa15 |
| Sky texture of the moment | the dome always carries SKY_SUNRISE_A / _CAP; a replacement list at 0x8a2cac..0x8a2cc4 maps them to sky[idx], sky[idx]_CAP (`[0x8a07a8+4*idx]`, idx = [0x8a1c94]), or forces SKY_NIGHT_A / _CAP when `[0x870d14] != 1`. The SUNSET and NIGHT textures are not in STREAML4RA: hashes found only in **TRACKS/LOC4DYNTEX.BIN** (SKY_SUNSET_A 0xfc, SKY_SUNSET_A_CAP 0x14c, SKY_NIGHT_A 0x24c, SKY_NIGHT_A_CAP 0x274 in the hash table 0x33310002; tex.md calls this file unused: wrong for these 4 sky textures) | 0x60f8a0..0x60f92a; byte search of the install. Pixel format / size of the NIGHT texture: record in chunk 0x33310003 not decoded, UNKNOWN |
| Sky cross-fade | while state [0x8a1c8c] == 4 and `[0x870d14] != 0`, the SKYDOME uses effect idx 20 SKYMORPH (`[0x86eb78]`, 0x5c59ec..0x5c5a0b): SkyMorphTexture = the previous sky texture (`[0x8a07a8 + 4*((idx-1 or idx-2) & 7)]`), blend factor = [0x8a1c9c] / 20.0 (0x60fde0), alpha byte = factor * `[0x784544]` << 24 | 0x5cf677..0x5cf720 (constant 0x784544 not read: assumed 255, INFERENCE) |
| Sky fog (INFERENCE) | the dome goes through WORLD, whose vs fog has no exemption; every visible vertex is > 250 deep, so the sky is blended with the floor fraction: sky_rgb = zmin * (0.627 * tex) + (1 - zmin) * FogColor (zmin 0.5..0.6, or 0.25 on row 15) | vs listing section 2; not confirmed by a render |

## NOT VERIFIED
- Retail value of the TOD clock `[0x7fb718]` and of the setting `[0x870d14]` (both runtime): they decide whether free roam sits in day fog + sunrise sky, or night. In the steady night state the proven pair is `Night Normal Fog` + SKY_NIGHT_A; without the setting, fog stays `Normal Fog` while the sky is forced to night.
- Second sky object, hash 0x72923c81 (instance 0x8a1f10, loaded at 0x60f71f, drawn at 0x60fa4d..0x60fa6a with scale 0.004525): name and data not found in any install file.
- SKY_NIGHT_A pixel format / size (LOC4DYNTEX.BIN record), `[0x784544]`, columns 5..7 (dead stores), rain-blend formula, the 20-unit time base of w ([0x865154] is BSS: its value is runtime).
- Effect parameter binding: FogValue/FogColor are set only on `[0x86eb28]` (WORLD) at 0x5cb077; whether other effects (WORLDREFLECT, SKYMORPH) get them through an effect pool is not proven.
- That `0x86eb28[i]` is the effect of table entry i (inferred from the dcl layouts and the additive -> idx 7 substitution; consistent with SKYMORPH = 20 at 0x86eb78 being used for the sky), the D3DX state numbering for FOGENABLE/FOGCOLOR (14/16), TSS (103..110), sampler (164..174), COLORWRITEENABLE (73).
- Which float of the 27-float material record feeds which CAR parameter and its upload code; texture-scroll TextureOffset values; min/mag filter values; gamma/sRGB state; SCREENFILTER / OVERBRIGHT runtime constants.
- No game or Chrome run; no rendered comparison.
