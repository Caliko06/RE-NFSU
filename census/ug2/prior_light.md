# UG2 world lighting and sky: prior art (2026-11-10)

REFERENCE ONLY (OWNER 2026-11-10): UG2 sky, fog and look are rejected (plan.json `rejected`); the UG2 city is drawn under NFSU1's sky. The open items here are not tasks.

Sources: the real files in this repo, OpenUG2 (MIT, UG2 engine reimplementation), MWEncyclopedia (TsyVM, **Most Wanted 2005**, not UG2). Marks: [F] proven here, [O] OpenUG2 code, [M] MW chapter, [U] unverified.

| Topic | Fact | Source |
|---|---|---|
| Vertex colour | World vertices are 24 B: f32 x,y,z, u32 **BGRA** colour, f32 uv. Colour is kept, not dropped. [F] | `tools/ug2_world.py:6-7,121,133-139` (chunk 0x134b01, real STREAML4RA.BUN) |
| Vertex colour use | World batches are drawn with a per-vertex `a_Color` vec4 attribute. [O] | OpenUG2 `src/world_mesh.c:144` (github.com/whoismept/OpenUG2) |
| Prelight model | Mode `uVColor=1` = world **MODULATE2X**: `vColor*2`, so byte 128 is neutral. Mode 2 = car diffuse. [O] | OpenUG2 `src/shaders/ug2.frag:4,236-239` |
| Key light | One shared per-frame `uAmbient`/`uDiffuse` pair plus one `uLight` direction for the whole world; no per-object lights. [O] | OpenUG2 `src/shaders/ug2.frag:6,180-183` |
| Sky light | Sky must be **UNKNOWN**; only an analytic sky-colour fallback exists for geometry off screen. [O] | OpenUG2 `src/shaders/ug2.frag:166` |
| Fog | Exp^2 distance fog on depth, `uFogColor` + `uFogDensity`; the clear colour **is** the fog colour so horizon and haze agree. [O] | OpenUG2 `src/shaders/ug2.frag:7,93-94,107` |
| Sky geometry | The sky is a **named solid**: solid header 0x134011, name at offset 0xa4 = `SKYDOME` (also `PAN_`, `XO_VISTA`). [F] | `tools/ug2_world.py:18-19`, `census/ug2/world_gaps.md:53` |
| Sky textures | `SKY_NIGHT_A[_CAP]`, `SKY_SUNRISE_A[_CAP]`, `SKY_SUNSET_A`, `SKY_OVERCASTA[_CAP][_ENVMAP]`, `SKYMORPHTEXTURE`, `SKYMORPHALPHA`, `SKYMORPHALPHA2`. [F] | strings in `pc/ug2/SPEED2.EXE` (grep `SKY_`) |
| Sky morph | Named "morph" texture + 2 alphas: a sky cross-fade state, not a time-of-day clock. [F] | same strings, exe |
| Fog data | `FOGCOLOR`, `FOGDENSITY`, `FOGSTART/END`, `FogValue`, `Fog Blend Distance`. [F] | strings in `pc/ug2/SPEED2.EXE` |
| Light material | A `LightMaterial` type exists: `eLightMaterialPlatInfoSlotPool`. [F] | strings in `pc/ug2/SPEED2.EXE` |
| World chunks | 0x80134010 > 0x134011 (solid), 0x80134100 > 0x134900 mesh header, 0x134b01 verts, 0x134b03 idx, 0x80034100 > 0x34102 defs / 0x34103 instances. [F] | `tools/ug2_world.py:9-12`, `census/ug2/l4ra_chunks.tsv` |
| Chunk 0x34107/0x34108 | Companion tables of the section group (preload flags), **not** lighting. [O][F] | OpenUG2 `src/world_group_reader.h:28,79,82`; `tools/openworld/build.py:10` |
| MW analogues (not UG2) | MW names `skybox`/`SkyboxCurrentGen`/`SkyColor`/`skyrgba`/`SkyBlendFactor`/`skyshader` and `FogShader`/`FogValue`; world lighting = SunColor key + SkyColor ambient + fog, applied by `LightMaterial`, graded by `VisualTreatment`. [M] | github.com/TsyVM/MWEncyclopedia `C57-World-Systems/02-sky-fog.md`, `04-world-lighting.md` |
| MW trust | MWEncyclopedia is MW-only, no license, and is self-described by peers as "leads only, contains known errors". Use as leads. [M][U] | teamvanilla.dev/games/mostwanted.html |
| vs NFSU1 | Same 24 B xyz+BGRA+uv vertex and the same solid/section chunk family as NFSU1 [F]; the visible difference is that UG2 carries a named `SKYDOME` solid plus sky morph textures, while an NFSU1 street-track sky is **UNKNOWN** here. | `docs/openworld/re_mesh.md:101-106`, `tools/ug2_world.py:6-7` |

## UNKNOWN

- Which chunk (if any) holds sky colour, fog values and light-material rows **as data**, and their layout. The exe proves the names exist, not the file.
- Whether 0x134011 `SKYDOME` is a mesh at all (it is skipped by name today), its transform, and its texture binding path.
- Whether vertex colour is applied as MODULATE2X in UG2 itself, or only in OpenUG2's reading of it.
- Time-of-day: no `TimeOfDay`/`SunColor` string was found for UG2; MW has it, UG2 = UNKNOWN.
- NFSU1 sky and fog path (not searched in this pass).
