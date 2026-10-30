# Car part textures: HD coverage and the simplest wiring (Skyline, Tiburon first)

Written 2026-10-30 (read-only analysis, no game or Chrome run). Tool tags:
P = python on game/ files (tools/re/tpk.py, tools/remaster/index.py functions, own scripts in build/carpack/),
T = the previous session's tables (build/carao/texcover*.tsv, kit_textures.tsv), checked here, not trusted,
G = Ghidra export (census/ghidra/decomp_0x54c000_0x5f1800.c), S = source read (web/gpu.js, host/d3d9.c, web/mode.js).
Scripts: build/carpack/cov.py (coverage), alpha.py (alpha check), tt.py (solid texture tables), vsize.py (vinyl size sample).

## Findings (numbers first)

1. **Every texture in the car packs that is not a runtime composite has an HD version, except 160 tiny lamp textures.**
   Packed textures: 2155 (20 kit cars + AMBULANCE + WHEELS in their TEXTURES.BIN, plus Cars/TEXTURES.BIN 345). With HD: 1995. Missing: 160 (P: cov.py;
   same 1995 as T texcover.tsv and as the 1995 rows of web/remaster/index_v2.tsv; they are 1073 unique webp files in
   web/remaster/cars2, 25.3 MB, because identical textures share one file).
2. **The 160 missing are all HEADLIGHT/BRAKELIGHT pieces, 16x16 (148) or 32x16 (12)** (P). Skyline: 0 missing. Tiburon: 0 missing.
   Other cars: GOLF 32, RX7 27, PEUGOT 26, SENTRA 26, MIATA 24, INTEGRA 10, FOCUS 4, NEON 4, 350Z/CIVIC/SUPRA 2, 240SX 1.
3. **Kit parts have no texture of their own.** Bumper, skirt, hood, roof, spoiler, trunk solids reference `<CAR>_SKIN1` plus a few
   shared detail textures (P: tt.py over GEOMETRY.BIN table 0x134012; agrees with T kit_textures.tsv). On Skyline and Tiburon the
   detail set is CARBOTTOM bd1f0e0a (bumpers, skirts), CARBONFIBRE 721aff7c (hoods, spoilers), GRILL_01 69c032b9, GRILL_02 69c032ba,
   INTERCOOLER 427b4565, `<CAR>_BADGING`. All of them have HD (CARBOTTOM 256x64 -> 1024x256, CARBONFIBRE 128 -> 512,
   GRILLs 128x64 -> 512x256, BADGING 128 -> 512).
4. **Correction to T kit_textures.tsv:** it has no FRONT_BUMPER rows for ECLIPSE, IMPREZA, INTEGRA, SKYLINE, TIBURON. Solid names in
   GEOMETRY.BIN are cut at 27 characters, so `SKYLINE_KIT09_FRONT_BUMPER_A` loses its `_A`, and the LOD-A filter dropped them (P: tt.py).
   Read directly: those 5 cars have 48 front-bumper solids each (16 kits x 3 LODs). Their textures are SKIN1, CARBOTTOM, GRILL_01/02,
   INTERCOOLER, CARBONFIBRE and BADGING (Eclipse/Integra/Tiburon), all with HD. The conclusion of T does not change.
5. **The body/kit skin is the only low-resolution surface.** `<CAR>_SKIN1` (Skyline 3eda2ca3, Tiburon 0ecb3d67, RX7 efd842c5 = bStringHash
   of the name, P) is in no pack. 82 table references in the Skyline LOD-A solids (99 solids) and 82 in Tiburon (100) are to it (T kit_textures.tsv; 9 and 8 more
   references are to 7 hashes found in no pack, e.g. dda11455, 7b220ddf: probably the runtime DUMMY_DECAL textures, NOT VERIFIED). The game draws a runtime 512x512 composite, DUMMY_SKIN1..4 (530b82b0..b3, A8R8G8B8, in Cars/TEXTURES.BIN, P).
6. **Wheels are fine.** All 1476 rim solids of Cars/WHEELS/GEOMETRY.BIN reference only 41 static `*_WHEEL` textures, all of them in the
   WHEELS pack and all HD (84/84 with the `_INNER` ones; 128x128 -> 512). No rim solid references DUMMY_WHEEL (P: tt.py).
   Per-car TIRE (128 -> 512) and KIT00_WHEEL_BLUR are HD too.
7. **Logos are fine.** Cars/TEXTURES.BIN 345/345 HD (251 sponsor decals INJEN, AEM, RACINGHART..., 256x64 -> 1024x256), plus `<CAR>_BADGING` HD.
8. **The HD files keep the alpha.** For every indexed car texture whose original alpha varies (107 A8R8G8B8, 171 DXT1 with
   punch-through, 264 DXT3) the webp has an alpha channel; the ones with constant alpha are RGB (P: alpha.py, 0 lost). The reflection
   mask (PS: `out.rgb += 2*tex.a*(spec+2*env)`, docs/re/car_assets.md) is therefore the same class of data as before.
9. **The composite ignores the HD layer textures.** `?skinhd` (default ON in Remaster, only `0` turns it off, web/mode.js:7 and
   web/gpu.js:677,747) rebuilds DUMMY_SKIN at up to 2048 on the GPU, but binds the layers' original 512 view: `{ binding: 1, resource: l.own }, { binding: 2, resource: m.own }`
   (web/gpu.js:767). Layers in the composite include `<CAR>_DOORLINE`, `_DOORLINE_KIT`, `_DOORLINE_WIDEBODY` and their `_MASK` (names built in
   0x5a96b0.. 0x5a9c10, G), `_HOOD`, `_SPOILER`, `_HOOD_SPOILER` (+`_MASK`) and the vinyl layers. The 6 DOORLINE textures of each car are
   512x512 A8R8G8B8 and all have a 1024x1024 HD webp (Skyline: 3 RGBA ~74 KB, 3 RGB ~10 KB; Tiburon: 3 RGBA ~37 KB, 3 RGB ~13 KB) that is downloaded and
   uploaded to the GPU today and then never sampled by the skin.
10. **Vinyls have no HD:** 17522 P8 512x512 textures (874-878 per car), not indexed (index.py skips P8). A 1024 webp sample of 12 Skyline
    vinyls (Lanczos, q88) averages 16.9 KB, so about 15 MB per car, ~300 MB for 20 cars (P: vsize.py; palette order not checked, size only).

## Coverage by car and part (P unless marked)

Counts are textures in the car's TEXTURES.BIN that the game can reference; "HD" = has an entry in index_v2.tsv by content hash.

| Car | packed | HD | missing | missing is |
|---|---|---|---|---|
| SKYLINE | 120 | 120 | 0 | |
| TIBURON | 83 | 83 | 0 | |
| 240SX / 350Z / CIVIC / SUPRA | 119 / 76 / 74 / 51 | 118 / 74 / 72 / 49 | 1 / 2 / 2 / 2 | lamp 16x16 |
| FOCUS / NEON / INTEGRA | 53 / 82 / 55 | 49 / 78 / 45 | 4 / 4 / 10 | lamp 16x16, 32x16 |
| MIATA / SENTRA / PEUGOT / RX7 / GOLF | 119 / 120 / 111 / 112 / 117 | 95 / 94 / 85 / 85 / 85 | 24 / 26 / 26 / 27 / 32 | lamp 16x16, 32x16 |
| the other 7 (CELICA ECLIPSE IMPREZA LANCER RSX S2000 AMBULANCE) | | all | 0 | |
| WHEELS | 84 | 84 | 0 | |
| Cars/TEXTURES.BIN | 345 + 8 DUMMY | 345 | 0 | DUMMY_SKIN1-4, DUMMY_WHEEL1-4 are runtime composites on purpose |

(CIVIC, CELICA, GOLF also have 6, 2, 2 P8 textures the index skips: CIVIC DOORLINE x6 512x512, CELICA/GOLF STYLE01/02_ENGINE 256x256. Not counted above.)

Skyline and Tiburon by part. "SKIN1" = runtime composite (item 5), not packed. Solid counts are LOD A (T), front bumpers from P (item 4).

| Part (slot) | Skyline textures | Tiburon textures | HD |
|---|---|---|---|
| FRONT_BUMPER (16 kits) | SKIN1, CARBOTTOM, GRILL_01/02, INTERCOOLER, CARBONFIBRE (kit 0x) | SKIN1, CARBOTTOM, GRILL_01/02, INTERCOOLER, CARBONFIBRE, BADGING | all details yes; SKIN1 no |
| REAR_BUMPER (16) | SKIN1 x16, CARBOTTOM x16, GRILL_01/02, INTERCOOLER | SKIN1 x16, CARBOTTOM x16, GRILL_01 x9 | details yes |
| SKIRT (16) | SKIN1 x16, CARBOTTOM x16 | same | CARBOTTOM yes |
| HOOD (21) | SKIN1 x11, CARBONFIBRE x10 | same | CARBONFIBRE yes |
| SPOILER (21) | SKIN1 x21, CARBONFIBRE x6 | SKIN1 x21, CARBONFIBRE x3 | CARBONFIBRE yes |
| ROOF (10), TRUNK | SKIN1 only | SKIN1 only | no (composite) |
| BODY / BASE | SKIN1, BADGING, DRIVER | SKIN1, BADGING, DRIVER | BADGING, DRIVER yes |
| HEADLIGHT / BRAKELIGHT | STYLE01-04 + KIT00, 64x64..256x128 | same | yes, none missing |
| ENGINE (3) | SKIN1, `*_ENGINE`, STYLE01/02_ENGINE 256x256 | same | yes (-> 1024) |
| WHEEL | `*_WHEEL` from WHEELS, SKYLINE_TIRE | TIRE, TIREBACK | yes |
| Logos | sponsor decals (Cars/TEXTURES.BIN) | same | yes |

Short list of what is missing and visible in the garage on those two cars: no static texture. What is soft is the SKIN1 composite: panel lines
(DOORLINE, DOORLINE_KIT, WIDEBODY) and vinyl/decal layers drawn from 512 sources (items 9 and 10).

## Current wiring (how a substitute is chosen)

1. The game binds textures through the solid's table 0x134012 (hash, ptr), resolved by 0x53f9b0 -> 0x5461c0 (G; hash lookup in the loaded
   TPKs). For the player's body it uses the DUMMY_SKINn hash that 0x4b4040 stores at ride +0x444 (docs/PLAN.md 6.2; 0x580b00 copies
   it to [0x106]). The exact instruction that swaps the table's `<CAR>_SKIN1` entry for DUMMY_SKINn: NOT VERIFIED.
2. The pack is keyed by **content, not by name**: host/d3d9.c:1302-1310, at UnlockRect of level 0, for DXT formats and non-dynamic
   A8R8G8B8/X8R8G8B8, computes FNV-1a 64 of the locked level-0 bytes and sends GPU_TEXKEY (container id, hash lo, hi).
   tools/remaster/index.py builds the same hash from the TPK (JDLZ unpacked) -> web/remaster/index*.tsv: `hash16<TAB>cars2/<hash>.webp`.
3. web/gpu.js:1013 (GPU_TEXKEY) -> `useHd(t,key)` (173) -> `pack.get(key)`; `loadHd` (117) decodes the webp (premultiplyAlpha none), caps level 0
   at 1024 (`HD_MAX`, line 106, `?hdmax=`), builds mips on the GPU, and sets `t.view`; the original stays in `t.own`. Index lists are read at
   gpu.js:98 (index.tsv, index_v2.tsv, index_fe_v2.tsv; v2 unless `?pack=1`; `?remaster=0` off).
4. DUMMY_SKIN is excluded on purpose (no hash). The skin is rebuilt by `skin_bridge` (host/d3d9.c:1347, only at the composite's UnlockRect
   return 0x5a8e7d) -> GPU_SKIN -> web/gpu.js:745 `skin()` at up to 2048, bilinear layers, mip chain, then `t.view = t.skin.createView()` (810).
   The composite has no HD layer input (item 9) and does not touch DUMMY_WHEEL (no bridge; but no rim solid uses it, item 6).
5. **`?skinhd=1` is the same as the default**: it covers the body/kit skin (paint, panel lines, vinyl), at 4x, with smoother mask edges,
   but not more detail than the 512 layers have. It does not cover the static kit textures; those go through the content-hash pack above, already HD.

## Minimal proposal

Goal: kits, wheels, logos sharp in the garage. Static kit textures, wheels and logos already are (items 3, 6, 7). What can still get sharper
is the SKIN1 composite. Smallest steps, in order of impact per MB:

| # | Action | Where | Cost |
|---|---|---|---|
| 1 | In `skin()`, bind the layer and mask HD view when the layer has one (`l.view !== l.own ? l.view : l.own`), and run the composite again when an HD layer finishes loading (keep the last GPU_SKIN args on the texture; call it from `loadHd().then`). Gives 1024 panel lines (DOORLINE, _KIT, _WIDEBODY and masks) in the 2048 skin on every car that has them (19 of 20; CIVIC = P8). | web/gpu.js:767 and 185 (about 10 lines) | **0 MB** of assets. VRAM: those 6 HD textures per car are already uploaded today and unused (6 x 1024^2 RGBA + mips, about 33 MB per car). |
| 2 | Use Catmull-Rom (or 4-tap bicubic) instead of bilinear for `layer` and `mask` in the skin shader; keeps the 128 threshold crisp on vinyl and decal edges. | web/gpu.js:~690 skin shader | 0 MB; one shader, 4x only for 2048 skin draws (per composite, not per frame) |
| 3 | Add the 10 P8 textures the index skips: CIVIC DOORLINE x6, CELICA and GOLF STYLE01/02_ENGINE. | tools/remaster/index.py + a SR pass | about 0.8 MB |
| 4 | Optional: 160 lamp textures 16x16/32x16 -> 64x64 (Lanczos is enough, they are lamp glass). None on Skyline or Tiburon. | cars2 + index_v2.tsv | under 0.3 MB |
| - | Not recommended: HD for all 17522 vinyls. | | about 15 MB per car (sample), ~300 MB for all; the 4x skin with action 2 already makes their edges follow the mask curve |

Do not change: alpha. Every substitute must keep it (finding 8); any file added in 3 or 4 has to be written RGBA when the original has
varying alpha (DXT3, DXT1 punch-through, A8R8G8B8), as alpha.py checks. A/B for action 1: same garage shot of Skyline with kit panel lines,
before/after, `?skinhd=check` is a 512 nearest oracle and does not apply to HD layers (it must keep using `own`).

## Not verified

- Where exactly the game replaces the `<CAR>_SKIN1` table hash with DUMMY_SKINn (only the ride +0x444 field and 0x580b00 were read).
- That the composite layers named above are the ones drawn in the garage for Skyline and Tiburon (names come from the Ghidra string builders;
  no RN_SKINLOG run was made; I did not launch the game).
- Whether the HD DOORLINE/MASK webp (made by the super-resolution pass) keeps the exact channel meaning the shader needs (mask uses blue;
  recolour layers use R,G,B as weights). The check is one A/B shot; recolour layers may need to keep `own`.
- Whether the pack's x2/x4 ratios in T are right (I checked the Skyline and Tiburon webp sizes: x4 for DXT, x2 for 512 DOORLINE because of the 1024 cap).
- Palette order of the P8 vinyls in vsize.py (only file size was used).
- Whether any rim paint colour goes through a DUMMY_WHEEL composite in the garage (no solid references it, 0x5a9af0 builds `_WHEEL_INNER_MASK`
  hashes for the layer list only).
- Visual result of any action: nothing was run in Chrome.
