# recon_numbers: reclamado vs obtenido (2026-10-29)

Repo: /Users/angeldamian/RE-NFSU. Python: /Users/angeldamian/RE-NFSU/.venv/bin/python (python3.14). Todo de solo lectura: se usó `PYTHONDONTWRITEBYTECODE=1`; no se corrió `census/names_merge.py` (escribe census/names.tsv), no se usó `tpk.py dds` ni `csiscurves.py json` (escriben archivos), no se corrió el juego ni Chrome.

| # | cifra | reclamado | obtenido | comando exacto | estado |
|---|---|---|---|---|---|
| 1 | TPK pixel size = mip sum | True | True en A8R8G8B8 (468), DXT1 (7356), DXT3 (2062), P8 (17572) | `.venv/bin/python tools/re/tpk.py check` | OK |
| 2 | TPK texturas malas | 0 de 27,458 | `347 packs, 27458 textures, bad 0` | `.venv/bin/python tools/re/tpk.py check` | OK |
| 3 | csiscurves patches | 32 | `32 ENG/EXH patches, 864 curves; bad: none` | `.venv/bin/python tools/re/csiscurves.py check` | OK |
| 4 | csiscurves curvas | 864 | 864 (misma línea) | `.venv/bin/python tools/re/csiscurves.py check` | OK |
| 5 | ids de chunk | 137 | 137 filas distintas en docs/re/assets.md (94 V / 22 I / 21 U); el walker ve 116 ids (`ids: 116, top-level: 58`) y census/chunks.json tiene 116 claves | `.venv/bin/python tools/re/chunks.py check` + conteo de filas de docs/re/assets.md | DIFIERE |
| 6 | loaders en 0x7007e0 | 47 | 47 entradas no nulas (índices 0..46; índice 47 = 0) leídas de pc/Speed.exe; `len(LOADERS)` = 47 | scratch: `.venv/bin/python -I <scratch>/loader_table.py` (lee PE de pc/Speed.exe) | OK |
| 7 | eventos de voz | 95 | 95 dwords en 0x6f6bc8, todos no nulos | scratch: `.venv/bin/python -I <scratch>/speech_table.py` | OK |
| 8 | líneas de voz | 277 | suma de la tabla = 277; `ast.py check` da 277 streams en STRM_English_Speech_MB.ast | scratch `speech_table.py`; `.venv/bin/python tools/re/ast.py check` | OK |
| 9 | intersecciones chunk 0x34123 | 49 | 49 registros en 14 archivos (size/0x170) | scratch: `.venv/bin/python -I <scratch>/count_traffic.py` (usa tools/re/chunks.py walk) | OK |
| 10 | spawn points chunk 0x34124 | 94 | 94 registros en 20 archivos (size/0x108) | scratch: `.venv/bin/python -I <scratch>/count_traffic.py` | OK |
| 11 | AST: cobertura de bytes | 100% | 5 archivos, chunks+padding = total bytes en los 5 | `.venv/bin/python tools/re/ast.py check` | OK |
| 12 | ABK: sample banks | 106 archivos, 94 con banco, 469 muestras, 6.7 min | `106 ABK files, 94 with a BNKl bank, 469 samples, 6.7 min; all valid: True` | `.venv/bin/python tools/re/abkbank.py check` | OK |
| 13 | ABK/AST round-trip (re-empaquetado) | round-trip | Los checks son de cobertura y parseo, no de re-empaquetado; no hay modo round-trip en ast.py ni abkbank.py | — | SIN COMANDO |
| 14 | save adler32 | check | a_autosave.ugd: stored 0xa79ab393 = recomputed 0xa79ab393 OK; 9 archivos repack equal | `.venv/bin/python tools/re/save.py check` | OK |
| 15 | save bloque 0xf660 | check | el check no imprime el bloque 0xf660 por separado; sólo repack byte a byte del archivo completo | `.venv/bin/python tools/re/save.py check` | SIN COMANDO |
| 16 | census/names.tsv direcciones | 1,039 (819 V / 198 I / 22 U) | 1039 filas, 1039 direcciones distintas; V 819, I 198, U 22 | `.venv/bin/python -c` que lee census/names.tsv (sin correr names_merge.py) | OK |
| 17 | scoreboard lifted | 13739 | 13739 | `.venv/bin/python tools/census/scoreboard.py` | OK |
| 18 | scoreboard tagged | 12179 | 12179 | `.venv/bin/python tools/census/scoreboard.py` | OK |
| 19 | scoreboard ran | 6038 | 6038 | `.venv/bin/python tools/census/scoreboard.py` | OK |
| 20 | scoreboard named | 886 (728 V) | 886 (728 V) | `.venv/bin/python tools/census/scoreboard.py` | OK |
| 21 | census/cov/union.json direcciones | 6038 | `len(addrs)` = 6038 (total 13739, pct 43.9) | `.venv/bin/python -c` que lee census/cov/union.json | OK |
| 22 | md5 build/gen sin flag | 07b9d06a976fb6136bd302f1ed3619a6 | No calculado: el repo no define el método del md5 (grep md5 sólo halla docs/re/coverage_method.md líneas 3-4). No se reconstruyó. | — | SIN COMANDO |

## DIFIERE (salida relevante)

### 5. ids de chunk (137 vs 116)
```
ids: 116, top-level: 58
top-level without a loader: []
```
docs/re/assets.md tiene 137 filas con id único (94 V / 22 I / 21 U). census/chunks.json tiene 116 claves. De las 137 filas, 22 no aparecen en census/chunks.json (ej. 0x00034021, 0x00034030, 0x00034300) y census/chunks.json trae 1 clave extra (0x00000000, padding). 137 - 22 + 1 = 116. assets.md contradice a sí mismo: línea 8 dice 116 ids; la sección de tabla dice 137. No investigué de dónde salen los 22 ids extra.

## Notas
- Salidas completas de los checks en /private/tmp/claude-501/-Users-angeldamian/79ee5150-e4ff-4a52-9b55-0fd755190ce7/scratchpad/run_tpk.txt, run_csiscurves.txt, run_chunks.txt, run_ast.txt, run_abkbank.txt, run_save.txt, run_scoreboard.txt. Todos con exit 0 (rerun del 09:52).
- Los scripts de conteo son míos y están en el scratchpad, no en el repo: `count_traffic.py`, `speech_table.py`, `loader_table.py`.
- Sound.md §6 no cita ningún script para los 95 eventos y 277 líneas; la verificación de la fila 7 y 8 la hice leyendo la tabla 0x6f6bc8 del PE directamente.
