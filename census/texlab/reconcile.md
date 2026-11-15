# Reconciliación plan.json ↔ git ↔ HANDOFF (solo lectura)

Repo `/Users/angeldamian/RE-NFSU`, rama `main`, HEAD `8826481`. Fecha 2026-11-14.

Método: cada hash de 7 hex citado en `ev` se probó con `git cat-file -e <h>^{commit}` y se confirmó ancestro de `main` con `git merge-base --is-ancestor`. Cada ruta con extensión citada en `ev` se probó con `test -e` en raíz del repo, `web/` y `web/plan/`.

## Paso 1 — UG2 city in NFSU1 (13 filas)

| | F1 geom | F2 puente | F3 texturas | F4 colisión | F5 streaming | F6 look | F7 tráfico | F8 menú WORLD | F9 desbloqueo | F10 UG2 Original | F11 carreras | F12 Bayview | F13 GPS |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| estado | VERIFIED | VERIFIED | VERIFIED | FIXED | VERIFIED | FIXED | FIXED | FIXED | FIXED | VERIFIED | FIXED | FIXED | FIXED |
| commits en ev | df12a22 | — (shot+log) | — (shot) | — (shot) | — (cifras) | — (shot) | 51a211e, 5a2793b | 6726ec8, 7a4db0f, f9d67a1, a3c0b35, e575ef2, 77890bb, dda7b0e | cc1cf4d, a72da66, 19c63d8, ed7fe32, 04a164a | d06119e, 517ebde, 892477b, 16d185b | 636e525, 222890b, 878ff04, 634b72c, a859cad, 4eb51ca, 62be692, d1f675b, 66377f0, a601a7a, eaca974 | b9a5515, b38d608, 45502cf, 75f7b64, 5a2793b, 478c829 | ad475a7, 6e4874b, 33a126c, f4b6d0e, 69265fe |
| commits ok en main | 1/1 | — | — | — | — | — | 2/2 | 7/7 | 5/5 | 4/4 | 11/11 | 6/6 | 5/5 |
| commits que faltan | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| rutas citadas / faltantes | 1 / 0 | 1 / 0 | 1 / 0 | 1 / 0 | 0 / 0 | 1 / 0 | 4 / 0 | 7 / 0 | 5 / 0 | 2 / 0 | 8 / 0 | 7 / 0 | 5 / 0 (+8 shots) |
| discrepancia | ninguna | ninguna | ninguna | 3 commits solo en `note` (0ac6012, 020db46, a940bc7), no en `ev`; los 3 existen en main | ev sin commit y sin archivo: solo cifras, no reproducible | ninguna | ninguna | `launcher/v6/world.webp` resuelve en `web/launcher/v6/world.webp` (existe) | ninguna | ninguna | ninguna | ninguna | 8 shots `gps_*` sin extensión en `ev`: los 8 existen en `web/plan/shots/` |

## Paso 2 — Public on the internet (9 filas)

| | F1 estático | F2 saves | F3 pack datos | F4 carga rápida | F5 otras máquinas | F6 hosting | F7 cara pública | F8 launch | F9 60 fps |
|---|---|---|---|---|---|---|---|---|---|
| estado | VERIFIED | FIXED | UNVERIFIED | UNVERIFIED | UNVERIFIED | UNVERIFIED | UNVERIFIED | UNVERIFIED | UNVERIFIED |
| commits en ev | 07d45e6 | e36d0b6 | 137c779 | 137c779, 1060940 | — | — | — | — | 11dce45, 4bab050, e4dffe7, d5773a3 |
| commits ok en main | 1/1 | 1/1 | 1/1 | 2/2 | — | — | — | — | 4/4 |
| commits que faltan | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| rutas citadas / faltantes | 6 / 0 | 4 / 0 | 3 / 0 | 6 / 0 | 0 / 0 | 0 / 0 | 0 / 0 | 0 / 0 | 9 / 0 |
| discrepancia | ninguna | ninguna | sin commit que pruebe el pack (declarado facts only) | estado UNVERIFIED con código mergeado (70437a5) y medición en `census/loadfast.json`: por la regla del plan sería FIXED | ev es prosa ("solo el Mac del OWNER"): sin evidencia que verificar | ev es prosa (precios de memoria): sin evidencia | ev es prosa (prior art): sin evidencia | ev es prosa: cita "step 1 has 7 rows FIXED" = 8 FIXED si se incluye la fila 4 (whose `who` no es el OWNER) | UNVERIFIED con código mergeado y mediciones; `ev` cita "this commit" sin hash: único punto no verificable |

## HANDOFF.md contra plan.json, filas 4 y 9 del paso 2

| Campo | HANDOFF | plan.json | ¿coincide? |
|---|---|---|---|
| F4 segundos (WORLD dibujado) | 86.0 → 64.6 s | 85.97 → 64.57 s | sí (redondeo) |
| F4 MB | 471.7 → 302.4 MB | 471.7 → 302.4 MB | sí |
| F4 requests | 3133 → 706 | 3133 → 706 | sí |
| F4 commit / autor | cdx angel, slice/loadfast 1060940 | 1060940 (cdx angel) | sí |
| F4 condición del remaster | "remaster OFF … (main default with remaster ON not measured)" y línea 8: "opt-in propuesto y NO mergeado (main keeps them on)" | "OWNER 2026-11-14 decidió opt-in: main ya lo tiene OFF por defecto (web/gpu.js ?remaster=1)" | **no**: HANDOFF quedó 2 commits atrás (9d232ed → 95e8976 → 8826481); `web/gpu.js:149` hoy solo activa el pack con `?remaster=1` |
| F9 frames > 23 ms | 60 base / 24 off → 8 on → 5 merged | 60 base; pace off 24; ?pace=vsync 8; mergeado 5 | sí |
| F9 p99 / worst | 34.4 worst, p99 20.8 | worst 34.4, p99 20.8 | sí |
| F9 commit | d5773a3 | d5773a3 (+ 11dce45, 4bab050, e4dffe7) | sí |

## Discrepancias globales

1. HANDOFF línea 8 es falsa hoy: dice que el opt-in del remaster no se mergeó y que main lo mantiene encendido; `8826481` lo puso opt-in (`web/gpu.js:149`). El plan ya está actualizado.
2. HANDOFF línea 6 conserva "main default with remaster ON not measured": con el opt-in, los números de la fila 4 ya son el default de main. Solo sobra el paréntesis.
3. `plan.json` `"updated": "2026-11-13"` mientras filas 4 y 9 citan trabajo del 2026-11-14: campo de fecha atrasado.
4. Filas 4 y 9 del paso 2 están en UNVERIFIED con commits mergeados y mediciones medidas: por la propia regla del plan deberían estar FIXED (falta jugarlo en el equipo del OWNER, no la evidencia).
5. HANDOFF línea 13 ("left dirty") coincide exacto con `git status --short`: `tools/build_public.py`, `census/play_index.tsv`, `census/lift_report.json`, `census/ug2/ground_gaps.png` (más untracked: `pc/ug2/SPEED2.EXE`, `census/shots/`, `logs/`, `web/plan/shots/chunk_v1.png`, etc.).
6. Nada citado en `ev` de ninguno de los 22 filas falta en `main`: 0 commits perdidos, 0 rutas inexistentes.

## Lo que no se pudo verificar

- Los `ev` en prosa (paso 2 filas 5, 6, 7, 8) no citan commit ni archivo: no hay nada que contrastar con git.
- El "this commit" del `ev` de la fila 9 del paso 2 no tiene hash; no se comprobó su existencia.
- Este trabajo fue solo de lectura: no se modificó ningún archivo del repo.
