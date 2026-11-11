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
| Filling [0x89e850..] (S at +0xc, D at +0x10, colour dword at +0x14) | function 0x614300(this = 0x89e850, view). Two modes. (a) `[0x8a1d70] != 0` (flag, meaning UNKNOWN): constants from .data: floats 0.62, 0.31, 1.3 at +0..+8, **S = 212.0** (0x800e28 = 0x43540000), **D = 0.74** (0x800e24 = 0x3f3d70a4), colour bytes 0x6e, 0x69, 0x4b (0x800e34, 0x800e30, 0x800e2c) -> FogColor (82, 78, 56) after the 0.75 factor. (b) otherwise: a blend of two sets of named tunable curves, `Normal Fog` (objects 0x8a1e90, 0x8a1ec0) and `Night Normal Fog` (0x8a31f0, 0x8a3220), plus `Night Raining Fog` (0x8a1e30, 0x8a1e60) and `Fog Blend Distance` (0x8a3250, 0x8a326c), evaluated per view with weight [0x8a1c88] and flag [0x8a1c90] | 0x614300..0x61447c (FACT for structure; names from the string table at 0x7a9418..0x7a944c registered by the static constructors at 0x77f780, 0x77f7b0, 0x77f7e0, 0x77f810). The VALUES of mode (b) (the day/night fog colour and distances) are UNKNOWN: the curve data is not in the exe (constructors take only the name, 0x60b7e0) and the install has no plain-text copy |
| Clear colour | UNKNOWN (not searched) | |
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
| Sky | SKYMORPH.efx (res 0x44eef8): ps `mul_x2 r0, (t0*dp3(c1,c0) + t1*(...)), v0`: a two-texture cross-fade (SkyMorphAlpha, SkyMorphAlpha2, SkyMorphTexture) times vertex colour x2, with the same oFog; the SKYDOME solid (skipped by ug2_world.py) is the likely user. Sky colour source UNKNOWN | listing |

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
2. Fog per vertex, linear in view depth: f = clamp((250 - z) / (250 - S), zmin, 1); out = f * c + (1 - f) * FogColor; additive (+0x56 == 2) groups unfogged. S, zmin, FogColor: see NOT VERIFIED.
3. Roads (mask 0x40): same formula, skip the reflection term; keep vertex alpha out of the output alpha (the ps forces alpha 1).
4. No ambient / sun / time-of-day multiplier on scenery; no material for ROAD.

## NOT VERIFIED
- Runtime FogValue S / D and the FogColor of the real game: only the override constants (S 212.0, D 0.74, colour 0x6e69 4b * 0.75) and the formula are proven; the day/night curve data (`Normal Fog`, `Night Normal Fog`, rain, blend distance) was not located in any file. Which mode (flag [0x8a1d70]) is active in free roam is UNKNOWN.
- That `0x86eb28[i]` is the effect of table entry i (inferred from the dcl layouts and the additive -> idx 7 substitution, not from the creation code, which only builds wrapper classes at 0x5d2290..0x5d2442).
- D3DX state-id numbering used for FOGENABLE/FOGCOLOR (14/16), TSS (103..110), sampler (164..174), COLORWRITEENABLE (73): inferred from D3DX state-table order, consistent with every value seen, not checked against a D3DX table.
- Which float of the 27-float material record feeds which CAR parameter and the upload code; whether the shared effect parameters (FogValue, FogColor) are set on every effect or shared through an effect pool (the set code at 0x5cb077.. targets `[0x86eb28]` = WORLD only).
- Texture-scroll TextureOffset values, min/mag filter values, device clear colour, gamma/sRGB state (not searched), SCREENFILTER / OVERBRIGHT runtime constants, how the SKYDOME is drawn.
- No game or Chrome run; no rendered comparison.
