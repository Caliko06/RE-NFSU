# GPS route on the game's HUD minimap

## Verified binary path (2026-11-12)

FACT: Speed.exe SHA256 c0fad450912952f53809a54690d235aa8b4e25b9f46650693c7cbee1b4c074b7, x86 PE.
Every row was read through REA/Ghidra 12.1.4 and independently disassembled from pc/Speed.exe with LLVM objdump.
Ghidra has no original debug types and mis-types some x87 locals; the instruction read settles the arithmetic.

| Address | REA evidence | Independent objdump observation |
|---|---|---|
| 0x409cd0 Hud::RenderPass | ev_74e2b3e257836b56d8e17802a403a214806dfa7d67b4f289044af41f5a1ff5a9 | 0x409ef0 calls 0x58e810 with render object 0x740460 |
| 0x58e540 TrackMap constructor | ev_e1762717579b80282012828c48fb89326af9a50665533b706fd033f1f883dc91 | 0x58e632 string pointer 0x6b91f8 TRACK%d_MAP; 0x58e651 texture lookup; 0x58e65b stores result at this+0x78 |
| 0x58e810 TrackMap::Draw | ev_7645f6e49f0571332c21caa9ec039d74de1ed27cd0fb50c24f903fd83f2f6eda | 0x58e8b6 calls 0x58f090 for the map quad |
| 0x58f090 map quad | ev_6eed5cc863833789028e763d49234138d5af58d46432e954fe226860881b9ff6 | calls 0x590ad0, 0x590dd0, then 0x58fb10 |
| 0x58f614 texture load, 0x58f631 clipped quad call | ev_5b93325cda7fa06b972021230fcd0166c20fedd6d6e79bf80e450a6b60097255 (containing procedure 0x58f090) | mov ecx,[ebx+0x78]; push ecx; call 0x58fb10 |
| 0x58fb10 Poly2D::ClipToRect | ev_998b3699955374e272217db482a51cb476a786ccf0ca59b2c2bd775561a88115 | 0x58fb1c..0x58fb60 builds rectangle from this+0x68/+0x6c center minus/plus this+0x70/+0x74 extent |
| 0x590ad0 WorldToMap | ev_9e2134f5a89235468a03db0db17a1d9772f5eeeeeef4b900ee5d37945b5e1ec8 | Negates input y; 0x590ade matrix this+0x20; 0x590afe transform; 0x590b07 row this+0xa4; subtract +0x8c, add +0x90, divide both by +0x94 |

Reproduce the second reads with `objdump -d --start-address=ADDR --stop-address=END pc/Speed.exe`.
Ranges: 409cd0..409f03, 58e540..58e670, 58e810..58e8bb, 58f090..58f63d, 58fb10..58fb94, 590ad0..590b48.

## Implementation and data identity

FACT: host/d3d9.c gps_map_texture rewrites the existing WORLD texture's GPU copy on a route content change.
There is no separate minimap projection, clipping path, world-space arrow or guest patch.
Consequently the same game's quad carries both the background and route through its follow/rotation/clip.
WORLD-only gate: gps_map_texture requires rn_racing(), track [0x78a2f0] == 1010 and the WORLD map's exact content key.
Original outside WORLD never passes that gate.

FACT: build/openworld/TEX1010TRACK.BIN contains TRACK1010_MAP at record 0x1bc. Record+0x30 plus 0x400 gives pixel offset 0xaad00.
The 0x40000 BGRA bytes at that offset have FNV1a64 0x59244a5381be2ddb, independently matching the host's existing tex_key calculation.
tools/openworld/worldmap.py main writes those 256x256 pixels and documents the TPK record layout.
The exact key intentionally rejects other map textures, including all shipped Original tracks.
World coordinates are already NFSU1 coordinates. WORLD row host/openworld.c uses X0=-3650, Y0=4260, S=6240.
Paint at u=(x+3650)/6240, v=(4260-y)/6240; the existing game's matrix is then applied by its normal render path.
Yellow line RGB(255,224,66), antialiased radius 1.35 texture pixels, is a presentation choice, not a recovered game constant.
Each change sends one GPU_TEXDATA command: 262160 payload bytes, zero texture uploads when the route hash is unchanged.
Clearing/arrival (route_n=0) decodes the unchanged guest pixels and restores the complete original background.

## Limits

Static path and data identity are FACT. Runtime visibility and rotation while driving are shown in web/plan/shots/gps_route_hud.png and gps_route_hud_turn.png. Runtime route publication and clear/arrival results are in tableros/gps-route-run.json.
The background's existing 256x256 resolution limits route detail to about 24.375 world units per texel.
A future regeneration of WORLD's map pixels requires updating GPS_MAP_KEY from the regenerated data.
