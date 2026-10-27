# Night lighting in Speed.exe (RE, Block 7 part 1, 2026-10-27)

Sources: Ghidra headless (tools/ghidra/gpar.sh on build/ghidra/proj), Hopper batches build/hopper/{hlproj,carlight,worldflare}.txt,
game/fx/*.efx (XOR 0xAA text HLSL). Checked at runtime with RN_WATCH/RN_POKE (native and Chrome).

## Graphics options (table 0x700ef0: name, flag, 12 bytes each)
| Option | Flag | Read by | Note |
|---|---|---|---|
| HEADLIGHTS | 0x700e80 | 0x408f00 (adds view 7), 0x40c910 (material remap), 0x409580 | projected headlight |
| CARLIGHTING | 0x700e84 | nobody | dead option |
| ROADREFLECTION | 0x700e90 | 0x40c910, 0x408f00 | picks the *reflect techniques |
| MOTIONBLUR | 0x700e98 | 0x409580, 0x40b3f0, 0x40cb80 | |
| LIGHTSTREAKS | 0x700e9c | 0x409580, 0x40b3f0, 0x40cb80 | flare buffer 0x71abb0 (PATCH 0x409bdb) |
| LIGHTGLOW | 0x700ea0 | 0x409580, 0x570c70 (racers), 0x570d00 (traffic) | car light flares |
| DEPTHOFFIELD | 0x700eac | nobody | dead option |
Presets: 0x410a00 scores the machine (0x41eff0, score 0x701088; < 0.3 / 0.6 / 0.9 = preset 0 / 1 / 2) and
0x410ce0 clamps each flag to the cap table 0x701040. Preset 1 sets HEADLIGHTS, MOTIONBLUR, LIGHTSTREAKS = 0.
At real clock our CPU scores 0.92 (preset 3, all on). RN_TURBO=4 lowers the score: turbo runs have no headlight.

## Projected headlight (one, the player's)
- 0x408410 turns view 7 (0x740760, flag 0x740768) on in a race with the player view. 0x408f00 adds it when HEADLIGHTS.
- 0x40c910: with flag 0x200 and HEADLIGHTS, world materials remap world -> worldheadlight (0x706818) or
  worldreflect -> worldheadlightreflect (0x706798).
- Effects 0x7014e0 + 0x80*i (world, worldheadlight, worldreflect, worldheadlightreflect, worldbone, car, filter);
  per-effect setup callbacks 0x702420 + 4*i (0x40e740 worldheadlight, 0x40e900 worldheadlightreflect).
- Parameter names 0x701860 + 0x40*k; the effect object keeps handle k at dword 7+k.
- Per draw 0x4100a0: HeadlightWVP (handle 0xe) from the view-7 matrix, HeadlightClipMat (0x2e), HeadlightColor
  (0x1c) = (0.8, 0.8, 0.9, 0) from 0x7010ac..0x7010b4 (constant, never written).
- HeadlightTex = texture "HEADLIGHTS" (cone shape). HeadlightClipTex 0x71abb4 = 64x1 built by 0x40e560: u = w*0.005+0.5,
  texels 0..32 = 0, 33..47 = 255, 48..63 = 239..0: light from ~3 m, full to ~50 m, gone at ~100 m.
- Shader: out = (headlight * clip * HeadlightColor + vertex colour) * diffuse * 2.
- Chrome draws it: A/B at 51.5 s on 1001 with RN_POKE=700e80=1/0 (same frame) shows the lit road.

## Car light flares (0x56d8d0, every racer and up to 99 traffic cars, gate LIGHTGLOW)
- Markers per model (list at car+0x500), by name hash (h = h*33 + c from -1): LEFT/RIGHT_HEADLIGHT 0x9db90133 /
  0xd09091c6, LEFT/RIGHT/CENTRE_BRAKELIGHT 0x31a66786 / 0xbf700a79 / 0xa2a2fc7c.
- Intensity: headlight 1.0 (0x6b5d9c); tail 0.7 (0x6b5da0), 0.85 (0x6b5da4) for car type 3; brake adds
  16 * [car+0x1e4] when > 0.05 (0x6b5dac, 0x6b5db0); everything clamps to 1.0, so a brake goes 0.7 -> 1.0 only.
  Debug forces: 0x7345e4 (head +1), 0x7345e8 (tail +1). Broken lights (damage state 0xd/0xe) skip a group.
- Each flare -> 0x5447c0: fade by distance, mode 0/2 from 32000 to 40000, mode 1 3900 -> 4000; type index +0xd picks
  textures from 0x6f4150 (2 per type); then 0x5443f0 draws the quad.

## Track lamps (0x544f30 from 0x409580 / 0x409b70)
Per visible track section (0x446fd0) a list of flare records, each to 0x544e90 / 0x5447c0 as above.

## Speed blur (0x40cd40, from 0x409580)
Speed = |v| of [0x740500]+0x1e0. t = clamp((speed - [0x702a38]) / ([0x702a3c] - [0x702a38])) + 1.1*[0x73641c],
capped by [0x702a40]; [0x73641c] ramps toward [0x73654c] (nitrous) by 0x702a48 / 0x702a4c per frame. The previous
frame (0x71ab9c, 0x71aba0) is drawn back zoomed toward the centre (offset x [0x702a44] streak) with that alpha:
a zoom feedback blur. web/tune.js presets write 0x702a38..0x702a44.
