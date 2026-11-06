# resetscan: qué mide y qué salió en dos ghosts WORLD (medido, no supuesto)

Read-only sobre `Speed.exe`: la herramienta solo lee `runs/w_*/log.txt`. No arranca el juego,
ni Chrome, ni ghosts, ni compila.

```
python3 tools/openworld/resetscan.py runs/w_L1/log.txt
python3 tools/openworld/resetscan.py runs/w_j/log.txt
```

Marcadores: **F** = leído/medido en el log, **I** = lo infiere el script, **NV** = este log no lo
puede afirmar.

## Nombres de columna reales (head del log, 2026-11-03)

- `carpos <t> <idx> k<kind> <x> <y> [P] [N]` — **solo x,y**: ni z ni velocidad. Una fila por coche
  cada ~2.03 s. `kind` 1 = jugador, 2 = rival, 3 = tráfico.
- `COLLOG <frame> walls N peak N witness N peak N nextid N bodies N orphans N flat N first id N nz .. d .. | me awake .. off .. wit .. mode .. cache N pos x,y,z sp S reset R`
  — el único z + velocidad por muestra, solo del jugador, cada 300 frames (~5 s).
- `AIP f<frame> sp S pos x,y,z wheels W crash C` — jugador, cada 60 frames (~1.1 s a 53 fps).
- `AIJUMP` / `AIHIT` — z y `sp A -> B` por evento, con `pos`/`at x,y,z`.
- `FREE frame <f> traffic N: NAME <m> m (+<delta>) ... | ... | tmove N fail N (...)`.
- `TRAFLOG <frame> ... polys P polymax P polycap C`.

## Reglas y por qué

| señal | regla | techo honesto |
|---|---|---|
| embedded | \|dpos\| < 0.5 m por más de 6 s **y** alguna velocidad > 5 m/s | `carpos` no trae velocidad; la velocidad se pide prestada a un `AIJUMP`/`AIHIT` del mismo `kind` a ≤ 8 m y ≤ 10 s (I: el evento da una dirección de coche, no el `idx`). Sin testigo se imprime UNCONFIRMED (NV). |
| fall | caída de z > 5 m en ≤ 2 s | z solo existe en `AIP` (jugador, dt real vía interpolación de `carpos`) y `COLLOG` (5 s, marcado *coarse*). |
| teleport | > 30 m entre muestras consecutivas | con 2 s de hueco, 30 m = 15 m/s: eso lo hace un coche normal. El subconjunto útil es velocidad implícita > 60 m/s; el conteo crudo se imprime al lado. |
| 30 s después | muestras y camino recorrido en `[t, t+30]` | solo `carpos`: no hay z ni estado en esa ventana. |

## Hallazgos que salen de los dos logs

- **F**: en estos dos ghosts `carpos` solo trae `k3` (21 coches de tráfico). No hay filas de
  jugador (`k1`) ni de rival (`k2`), así que el jugador solo se ve por `AIP`/`COLLOG`.
- **F**: `runs/w_L1` acaba con `polys 8192` de `polycap 8192`; `runs/w_j` con 8173 de 8192
  (99.1 %). El pool de muros vive pegado al tope en los dos.
- **F**: el contador `reset` de COLLOG se mueve en `w_L1` (6162 → 0 → 190179 → 194179 →
  2360646) y **no** se mueve en `w_j` (se queda en 6141).
- **F/I**: los saltos por `idx` son constantes (cientos por log, hasta 1163 m/s implícitos) y
  coinciden en el tiempo con los deltas gigantes de `FREE tmove` (−306.0 m, +306.1 m, ±420 m):
  el `idx` de `carpos` es un **slot reutilizado**, no un coche continuo. Leer esos saltos como
  «un coche se teletransporta» es falso; son resets de slot. NV: el log no separa reset real de
  reciclaje de slot, se ven idénticos.
- **F**: la caída de z más limpia es en `w_L1`, `AIP f4440→4500`: 60 frames, 1.75 s, z 64 → 58
  (6 m) a [2314,-349] con sp 42.6 → 48.4 m/s. Es un salto de bordillo, no un fall-through.
- **F**: no hay ningún fall-through sostenido: ninguna serie de z se va a −0 ni el jugador se
  queda sin suelo en ninguno de los dos logs.

## Salida real: runs/w_L1/log.txt

```
# resetscan runs/w_L1/log.txt

## 1. In the log (F)
- 37033 lines, 8925 carpos rows, cars by kind: {'traffic': 21}
- carpos t window 38.53..899.06 s, sample gap median 2.03 s (carpos carries x,y only: no z, no speed)
- frames per second: 53.3 measured on AIP pairs, 41.6 by span ratio (I: no single line pairs a frame with a carpos t)
- polys max 8192 of polycap 8192 (0.998 of cap at the last TRAFLOG)

## 2. Still / embedded, per car (|dpos| < 0.5 m for > 6 s)
- traffic #9: 8 still episodes (2 with speed witness > 5 m/s)
    t 125.96..132.02 s, 4 samples, at [2003.0, 223.9], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
    t 194.89..200.97 s, 4 samples, at [859.1, 355.8], witness speed 21.8 -> EMBEDDED (F for the position, I for the speed: the log has no per-row speed) [hit-car f9200 192.4s]
    t 271.99..288.24 s, 9 samples, at [1675.6, -417.5], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
    t 367.34..375.44 s, 5 samples, at [1998.4, 228.2], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
    t 393.69..399.77 s, 4 samples, at [1980.5, 263.5], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
    t 604.59..734.30 s, 65 samples, at [2109.3, 198.9], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
- traffic #10: 9 still episodes (3 with speed witness > 5 m/s)
    t 324.71..338.91 s, 8 samples, at [2325.1, 39.5], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
    t 495.08..511.33 s, 9 samples, at [956.9, -236.4], witness speed 20.3 -> EMBEDDED (F for the position, I for the speed: the log has no per-row speed) [hit-wall f22176 493.8s]
    t 574.19..586.34 s, 7 samples, at [2327.5, 7.9], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
    t 608.65..626.88 s, 10 samples, at [1994.9, 232.5], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
    t 628.90..653.23 s, 13 samples, at [1992.0, 234.0], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
    t 673.50..683.63 s, 6 samples, at [1991.6, 231.1], witness speed 13.2 -> EMBEDDED (F for the position, I for the speed: the log has no per-row speed) [hit-car f33177 684.0s]
- traffic #11: 15 still episodes (5 with speed witness > 5 m/s)
    t 188.80..196.92 s, 5 samples, at [734.2, 304.2], witness speed 6.7 -> EMBEDDED (F for the position, I for the speed: the log has no per-row speed) [hit-car f9298 197.2s]
    t 363.28..379.50 s, 9 samples, at [1980.0, 251.8], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
    t 499.14..509.29 s, 6 samples, at [923.5, -212.8], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
    t 559.98..566.07 s, 4 samples, at [2328.8, -136.8], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
    t 576.21..584.31 s, 5 samples, at [2328.2, -128.4], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
    t 594.47..612.70 s, 10 samples, at [2014.1, 213.9], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
- traffic #12: 4 still episodes (0 with speed witness > 5 m/s)
    t 119.86..125.96 s, 4 samples, at [1977.3, 275.3], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
    t 349.06..359.21 s, 6 samples, at [2148.2, 197.4], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
    t 472.76..480.89 s, 5 samples, at [740.4, 313.7], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
    t 622.82..732.27 s, 55 samples, at [2126.2, 199.1], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
- traffic #13: 10 still episodes (1 with speed witness > 5 m/s)
    t 103.62..115.80 s, 7 samples, at [2298.6, 202.3], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
    t 200.97..217.20 s, 9 samples, at [894.7, 353.1], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
    t 310.54..318.64 s, 5 samples, at [2239.4, -570.4], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
    t 330.80..338.91 s, 5 samples, at [2333.3, -20.1], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
    t 474.80..484.94 s, 6 samples, at [743.9, 311.8], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
    t 634.99..657.29 s, 12 samples, at [2034.0, 200.7], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
- traffic #14: 8 still episodes (2 with speed witness > 5 m/s)
    t 77.07..97.54 s, 11 samples, at [2342.3, -200.1], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
    t 125.96..132.02 s, 4 samples, at [2014.8, 212.4], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
    t 198.94..205.03 s, 4 samples, at [793.0, 352.1], witness speed 16.8 -> EMBEDDED (F for the position, I for the speed: the log has no per-row speed) [hit-car f9316 198.5s, hit-wall f9540 210.4s]
    t 612.70..622.82 s, 6 samples, at [2303.6, 189.9], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
    t 651.20..683.63 s, 17 samples, at [1989.6, 231.1], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
    t 697.83..703.91 s, 4 samples, at [1978.6, 258.4], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
- traffic #15: 9 still episodes (3 with speed witness > 5 m/s)
    t 316.62..324.71 s, 5 samples, at [2322.5, -329.8], witness speed 16.4 -> EMBEDDED (F for the position, I for the speed: the log has no per-row speed) [hit-wall f12804 313.9s]
    t 373.41..381.52 s, 5 samples, at [2129.2, 185.1], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
    t 517.41..525.54 s, 5 samples, at [1285.3, -340.3], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
    t 562.02..586.34 s, 13 samples, at [2334.5, -21.1], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
    t 673.50..681.61 s, 5 samples, at [1978.2, 259.3], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
    t 730.26..742.43 s, 7 samples, at [1984.3, 246.4], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
- traffic #16: 14 still episodes (2 with speed witness > 5 m/s)
    t 70.99..97.54 s, 14 samples, at [2342.4, -209.7], witness speed 19.5 -> EMBEDDED (F for the position, I for the speed: the log has no per-row speed) [hit-car f4474 75.5s]
    t 188.80..194.89 s, 4 samples, at [857.2, 358.2], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
    t 353.11..363.28 s, 6 samples, at [2175.1, 215.3], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
    t 474.80..480.89 s, 4 samples, at [750.6, 323.8], witness speed 20.6 -> EMBEDDED (F for the position, I for the speed: the log has no per-row speed) [hit-wall f21708 485.9s]
    t 578.24..584.31 s, 4 samples, at [2331.5, -156.3], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
    t 612.70..622.82 s, 6 samples, at [2295.7, 200.9], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
- traffic #17: 7 still episodes (2 with speed witness > 5 m/s)
    t 115.80..132.02 s, 9 samples, at [1995.2, 239.5], witness speed 11.9 -> EMBEDDED (F for the position, I for the speed: the log has no per-row speed) [hit-wall f6108 114.8s]
    t 265.92..280.11 s, 8 samples, at [1680.9, -424.5], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
    t 282.14..288.24 s, 4 samples, at [1684.0, -433.5], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
    t 367.34..387.60 s, 11 samples, at [1981.3, 294.4], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
    t 507.26..515.39 s, 5 samples, at [1029.1, -294.6], witness speed 6.1 -> EMBEDDED (F for the position, I for the speed: the log has no per-row speed) [hit-car f22847 505.5s]
    t 598.53..738.37 s, 70 samples, at [2077.1, 197.7], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
- traffic #18: 9 still episodes (2 with speed witness > 5 m/s)
    t 95.51..101.60 s, 4 samples, at [2336.1, -180.9], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
    t 235.47..245.61 s, 6 samples, at [857.2, -120.2], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
    t 330.80..338.91 s, 5 samples, at [2331.0, -7.2], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
    t 515.39..523.50 s, 5 samples, at [1299.7, -338.0], witness speed 11.9 -> EMBEDDED (F for the position, I for the speed: the log has no per-row speed) [hit-car f23296 513.4s, hit-car f23296 513.4s]
    t 531.62..537.70 s, 4 samples, at [1679.8, -430.8], witness speed 8.1 -> EMBEDDED (F for the position, I for the speed: the log has no per-row speed) [hit-car f24296 531.0s]
    t 600.55..736.34 s, 68 samples, at [2091.8, 198.2], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
- traffic #19: 8 still episodes (4 with speed witness > 5 m/s)
    t 109.71..121.89 s, 7 samples, at [1978.8, 261.5], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
    t 194.89..205.03 s, 6 samples, at [863.8, 356.0], witness speed 21.8 -> EMBEDDED (F for the position, I for the speed: the log has no per-row speed) [hit-car f9200 192.4s]
    t 227.34..233.43 s, 4 samples, at [1405.1, -272.9], witness speed 17.1 -> EMBEDDED (F for the position, I for the speed: the log has no per-row speed) [hit-wall f9738 224.3s, hit-wall f9738 224.4s, hit-car f9842 235.2s]
    t 237.50..271.99 s, 18 samples, at [1403.8, -274.2], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
    t 322.69..328.77 s, 4 samples, at [2343.0, -78.2], witness speed 8.2 -> EMBEDDED (F for the position, I for the speed: the log has no per-row speed) [hit-car f13119 321.9s]
    t 515.39..521.48 s, 4 samples, at [1295.1, -339.3], witness speed 11.9 -> EMBEDDED (F for the position, I for the speed: the log has no per-row speed) [hit-car f23296 513.4s, hit-car f23296 513.4s]
- traffic #20: 13 still episodes (3 with speed witness > 5 m/s)
    t 68.96..75.05 s, 4 samples, at [2341.4, -200.3], witness speed 19.5 -> EMBEDDED (F for the position, I for the speed: the log has no per-row speed) [hit-car f4474 75.5s]
    t 77.07..97.54 s, 11 samples, at [2339.5, -196.1], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
    t 271.99..288.24 s, 9 samples, at [1673.7, -413.2], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
    t 326.74..336.88 s, 6 samples, at [2340.8, -93.1], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
    t 470.73..478.86 s, 5 samples, at [736.4, 303.6], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
    t 562.02..586.34 s, 13 samples, at [2330.7, -6.4], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
- traffic #21: 9 still episodes (2 with speed witness > 5 m/s)
    t 81.12..93.49 s, 7 samples, at [2332.6, -118.4], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
    t 371.39..377.47 s, 4 samples, at [2009.6, 218.3], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
    t 507.26..515.39 s, 5 samples, at [1033.0, -297.7], witness speed 6.1 -> EMBEDDED (F for the position, I for the speed: the log has no per-row speed) [hit-car f22847 505.5s]
    t 616.75..622.82 s, 4 samples, at [2293.7, 199.1], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
    t 661.35..667.42 s, 4 samples, at [1978.3, 264.5], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
    t 669.45..677.55 s, 5 samples, at [1976.9, 267.8], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
- traffic #22: 8 still episodes (1 with speed witness > 5 m/s)
    t 73.02..91.48 s, 10 samples, at [2328.6, -278.7], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
    t 103.62..115.80 s, 7 samples, at [2286.0, 211.5], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
    t 324.71..338.91 s, 8 samples, at [2323.1, 54.9], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
    t 383.55..389.63 s, 4 samples, at [1979.4, 281.6], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
    t 391.66..397.74 s, 4 samples, at [1979.9, 283.8], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
    t 624.85..665.40 s, 21 samples, at [2013.2, 206.8], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
- traffic #23: 6 still episodes (2 with speed witness > 5 m/s)
    t 87.20..99.57 s, 7 samples, at [2321.2, -128.5], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
    t 227.34..233.43 s, 4 samples, at [1399.7, -276.9], witness speed 16.7 -> EMBEDDED (F for the position, I for the speed: the log has no per-row speed) [hit-wall f9720 222.6s, hit-wall f9738 224.3s]
    t 237.50..269.97 s, 17 samples, at [1398.4, -278.0], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
    t 367.34..381.52 s, 8 samples, at [2138.3, 187.1], witness speed 14.1 -> EMBEDDED (F for the position, I for the speed: the log has no per-row speed) [hit-car f15665 369.3s]
    t 598.53..738.37 s, 70 samples, at [2070.0, 200.4], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
    t 866.47..878.71 s, 7 samples, at [763.3, 333.1], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
- traffic #24: 10 still episodes (1 with speed witness > 5 m/s)
    t 196.92..207.05 s, 6 samples, at [881.0, 354.9], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
    t 237.50..271.99 s, 18 samples, at [1407.0, -271.3], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
    t 367.34..375.44 s, 5 samples, at [1982.3, 253.1], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
    t 391.66..397.74 s, 4 samples, at [1977.1, 277.2], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
    t 428.16..434.24 s, 4 samples, at [1694.7, 442.0], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
    t 497.11..511.33 s, 8 samples, at [934.6, -222.8], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
- traffic #25: 9 still episodes (1 with speed witness > 5 m/s)
    t 75.05..93.49 s, 10 samples, at [2331.7, -263.5], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
    t 322.69..334.85 s, 7 samples, at [2343.6, -73.3], witness speed 8.2 -> EMBEDDED (F for the position, I for the speed: the log has no per-row speed) [hit-car f13119 321.9s]
    t 363.28..395.71 s, 17 samples, at [1977.4, 292.0], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
    t 598.53..606.62 s, 5 samples, at [2028.0, 203.9], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
    t 614.72..622.82 s, 5 samples, at [2018.3, 211.7], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
    t 626.88..655.26 s, 15 samples, at [2009.3, 214.9], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
- traffic #26: 3 still episodes (0 with speed witness > 5 m/s)
    t 188.80..196.92 s, 5 samples, at [733.3, 299.7], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
    t 229.37..243.57 s, 8 samples, at [941.0, -224.1], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
    t 357.17..365.31 s, 5 samples, at [2169.9, 204.4], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
- traffic #27: 8 still episodes (0 with speed witness > 5 m/s)
    t 192.86..205.03 s, 7 samples, at [745.2, 309.7], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
    t 365.31..397.74 s, 17 samples, at [1976.0, 305.9], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
    t 562.02..568.11 s, 4 samples, at [2337.9, -183.9], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
    t 657.29..665.40 s, 5 samples, at [1981.9, 263.0], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
    t 677.55..697.83 s, 11 samples, at [1981.6, 273.0], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
    t 707.96..742.43 s, 18 samples, at [1989.7, 247.2], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
- traffic #28: 5 still episodes (0 with speed witness > 5 m/s)
    t 381.52..395.71 s, 8 samples, at [1975.1, 266.7], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
    t 616.75..622.82 s, 4 samples, at [2029.8, 203.0], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
    t 624.85..659.32 s, 18 samples, at [2019.3, 206.8], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
    t 665.40..707.96 s, 22 samples, at [2013.3, 213.3], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
    t 722.15..736.34 s, 8 samples, at [2023.4, 205.6], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
- traffic #29: 6 still episodes (1 with speed witness > 5 m/s)
    t 198.94..211.12 s, 7 samples, at [884.7, 353.1], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
    t 310.54..316.62 s, 4 samples, at [2238.3, -574.6], witness speed 16.2 -> EMBEDDED (F for the position, I for the speed: the log has no per-row speed) [hit-car f12464 306.6s]
    t 326.74..336.88 s, 6 samples, at [2344.1, -61.5], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
    t 495.08..511.33 s, 9 samples, at [949.3, -229.6], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
    t 630.93..734.30 s, 52 samples, at [2104.7, 195.7], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
    t 868.52..874.64 s, 4 samples, at [736.0, 305.9], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)

## 3. Teleports (> 30 m between samples, implied speed > 60 m/s)
- traffic #9: 21 teleports (raw >30 m count 73)
    t 42.58 s  [370.3, -1301.5] -> [2129.4, -576.3]  1902.7 m in 2.03 s = 937.3 m/s   | next 30 s: 14 samples, path 883.1 m, ends [2246.2, -522.2]
    t 64.89 s  [1833.1, -439.0] -> [2306.7, -474.9]  475.0 m in 2.02 s = 235.1 m/s   | next 30 s: 14 samples, path 944.1 m, ends [2227.1, 235.9]
    t 75.05 s  [2238.2, -543.4] -> [2325.0, 83.7]  633.1 m in 2.03 s = 311.9 m/s   | next 30 s: 14 samples, path 329.4 m, ends [2117.9, 199.1]
    t 134.05 s  [2003.0, 223.9] -> [1689.0, 598.1]  488.5 m in 2.03 s = 240.6 m/s   | next 30 s: 14 samples, path 305.8 m, ends [1519.7, 690.2]
    t 168.53 s  [1519.6, 690.2] -> [1067.0, 355.9]  562.7 m in 2.03 s = 277.2 m/s   | next 30 s: 14 samples, path 208.2 m, ends [859.1, 355.8]
    t 217.20 s  [818.6, 355.7] -> [1382.8, -282.8]  852.1 m in 2.03 s = 419.7 m/s   | next 30 s: 14 samples, path 82.3 m, ends [1304.5, -299.8]
    t 263.89 s  [1244.4, -301.7] -> [1670.2, -404.2]  438.0 m in 2.03 s = 215.7 m/s   | next 30 s: 14 samples, path 621.7 m, ends [2216.9, -583.1]
    t 290.27 s  [1675.8, -418.0] -> [2234.3, -557.2]  575.6 m in 2.03 s = 283.5 m/s   | next 30 s: 14 samples, path 838.8 m, ends [2335.0, -175.4]
- traffic #10: 27 teleports (raw >30 m count 71)
    t 40.55 s  [216.3, 323.5] -> [1884.8, -473.2]  1849.0 m in 2.02 s = 915.3 m/s   | next 30 s: 14 samples, path 383.1 m, ends [2232.9, -592.5]
    t 75.05 s  [2250.5, -562.3] -> [2337.2, -29.0]  540.3 m in 2.03 s = 266.2 m/s   | next 30 s: 14 samples, path 480.5 m, ends [2078.0, 184.6]
    t 103.62 s  [2333.9, -114.1] -> [2078.0, 184.6]  393.3 m in 2.02 s = 194.7 m/s   | next 30 s: 14 samples, path 319.5 m, ends [2321.8, 119.0]
    t 134.05 s  [2321.8, 119.0] -> [1741.5, 461.5]  673.8 m in 2.03 s = 331.9 m/s   | next 30 s: 14 samples, path 380.9 m, ends [1438.4, 614.2]
    t 156.35 s  [1684.6, 519.8] -> [1442.7, 624.3]  263.5 m in 2.03 s = 129.8 m/s   | next 30 s: 14 samples, path 842.8 m, ends [725.1, 269.6]
    t 176.62 s  [1319.3, 469.9] -> [736.1, 304.1]  606.3 m in 2.02 s = 300.2 m/s   | next 30 s: 14 samples, path 136.0 m, ends [724.8, 170.2]
    t 215.17 s  [727.3, 128.7] -> [955.6, -235.2]  429.6 m in 2.03 s = 211.6 m/s   | next 30 s: 14 samples, path 117.2 m, ends [868.6, -157.5]
    t 249.70 s  [862.6, -149.8] -> [1617.6, -303.0]  770.4 m in 2.02 s = 381.4 m/s   | next 30 s: 14 samples, path 926.0 m, ends [1961.9, -515.7]
- traffic #11: 22 teleports (raw >30 m count 77)
    t 40.55 s  [-451.5, -230.3] -> [1864.7, -627.5]  2350.0 m in 2.02 s = 1163.4 m/s   | next 30 s: 14 samples, path 838.3 m, ends [2236.8, -560.6]
    t 60.84 s  [1831.5, -438.7] -> [2313.9, -472.9]  483.6 m in 2.03 s = 238.2 m/s   | next 30 s: 14 samples, path 825.6 m, ends [2342.3, -49.2]
    t 73.02 s  [2222.4, -583.3] -> [2325.6, 16.9]  609.0 m in 2.03 s = 300.0 m/s   | next 30 s: 14 samples, path 128.2 m, ends [2339.5, -94.8]
    t 103.62 s  [2339.5, -94.8] -> [1966.4, 327.5]  563.5 m in 2.02 s = 279.0 m/s   | next 30 s: 14 samples, path 123.6 m, ends [1980.6, 282.7]
    t 136.08 s  [1981.3, 284.5] -> [1683.6, 634.8]  459.7 m in 2.03 s = 226.5 m/s   | next 30 s: 14 samples, path 607.9 m, ends [1466.4, 640.1]
    t 156.35 s  [1687.7, 485.4] -> [1398.6, 532.8]  293.0 m in 2.03 s = 144.3 m/s   | next 30 s: 14 samples, path 1061.2 m, ends [753.6, 323.8]
    t 170.55 s  [1484.5, 651.7] -> [798.0, 352.7]  748.8 m in 2.02 s = 370.7 m/s   | next 30 s: 14 samples, path 194.3 m, ends [732.8, 302.0]
    t 227.34 s  [1110.2, 336.4] -> [1583.4, -265.4]  765.6 m in 2.03 s = 377.1 m/s   | next 30 s: 14 samples, path 247.3 m, ends [1565.8, -267.0]
- traffic #12: 26 teleports (raw >30 m count 50)
    t 42.58 s  [849.1, -610.3] -> [1993.0, -541.5]  1146.0 m in 2.03 s = 564.5 m/s   | next 30 s: 14 samples, path 326.2 m, ends [2258.0, -528.9]
    t 77.07 s  [2283.7, -505.7] -> [2321.7, 120.7]  627.6 m in 2.02 s = 310.7 m/s   | next 30 s: 14 samples, path 532.3 m, ends [1967.9, 321.1]
    t 105.65 s  [2323.3, 41.0] -> [1967.9, 321.1]  452.5 m in 2.03 s = 222.9 m/s   | next 30 s: 14 samples, path 102.2 m, ends [1975.6, 285.7]
    t 136.08 s  [1975.6, 285.7] -> [1687.9, 523.0]  372.9 m in 2.03 s = 183.7 m/s flags N   | next 30 s: 14 samples, path 270.9 m, ends [1617.7, 740.3]
    t 176.62 s  [1523.0, 690.9] -> [751.4, 316.1]  857.8 m in 2.02 s = 424.7 m/s   | next 30 s: 14 samples, path 90.9 m, ends [724.6, 233.9]
    t 211.11 s  [724.7, 219.7] -> [852.6, -87.4]  332.7 m in 2.02 s = 164.7 m/s   | next 30 s: 14 samples, path 323.3 m, ends [856.3, -91.1]
    t 215.17 s  [851.8, -59.4] -> [925.0, -199.4]  158.0 m in 2.03 s = 77.8 m/s   | next 30 s: 14 samples, path 145.4 m, ends [856.1, -83.0]
    t 245.61 s  [856.1, -83.0] -> [1462.0, -265.3]  632.7 m in 2.04 s = 310.2 m/s   | next 30 s: 14 samples, path 182.9 m, ends [1621.6, -322.1]
- traffic #13: 27 teleports (raw >30 m count 92)
    t 44.61 s  [959.1, -606.8] -> [1995.2, -543.2]  1038.1 m in 2.03 s = 511.4 m/s   | next 30 s: 14 samples, path 293.4 m, ends [2251.1, -549.2]
    t 75.05 s  [2251.1, -549.2] -> [2314.5, 160.8]  712.8 m in 2.03 s = 351.1 m/s   | next 30 s: 14 samples, path 229.0 m, ends [2298.6, 202.3]
    t 117.83 s  [2298.6, 202.3] -> [1958.1, 331.5]  364.2 m in 2.03 s = 179.4 m/s flags N   | next 30 s: 14 samples, path 741.7 m, ends [1674.5, 578.9]
    t 136.08 s  [1980.9, 297.1] -> [1656.0, 719.6]  533.0 m in 2.03 s = 262.6 m/s   | next 30 s: 14 samples, path 586.1 m, ends [1351.8, 500.8]
    t 154.32 s  [1676.0, 535.6] -> [1433.3, 608.1]  253.3 m in 2.02 s = 125.4 m/s   | next 30 s: 14 samples, path 378.9 m, ends [1167.1, 352.8]
    t 225.31 s  [872.5, 353.1] -> [1447.8, -262.4]  842.5 m in 2.02 s = 417.1 m/s   | next 30 s: 14 samples, path 501.7 m, ends [1322.3, -333.7]
    t 237.50 s  [1618.3, -313.9] -> [1341.4, -326.2]  277.2 m in 2.03 s = 136.5 m/s   | next 30 s: 14 samples, path 82.3 m, ends [1359.6, -322.7]
    t 269.97 s  [1348.8, -322.1] -> [1828.0, -444.4]  494.6 m in 2.03 s = 243.6 m/s   | next 30 s: 14 samples, path 1958.3 m, ends [2289.8, -494.3]
- traffic #14: 24 teleports (raw >30 m count 115)
    t 42.58 s  [352.7, -1244.6] -> [1890.1, -480.4]  1716.9 m in 2.03 s = 845.7 m/s   | next 30 s: 14 samples, path 623.7 m, ends [2332.5, -277.2]
    t 66.93 s  [2059.0, -579.8] -> [2331.0, -346.1]  358.6 m in 2.04 s = 175.8 m/s   | next 30 s: 14 samples, path 147.8 m, ends [2342.3, -200.1]
    t 99.57 s  [2342.3, -200.1] -> [2213.1, 229.3]  448.4 m in 2.03 s = 220.9 m/s   | next 30 s: 14 samples, path 210.5 m, ends [2014.8, 212.4]
    t 134.05 s  [2014.8, 212.4] -> [1688.1, 543.1]  464.9 m in 2.03 s = 229.0 m/s   | next 30 s: 14 samples, path 365.4 m, ends [1509.0, 684.8]
    t 168.53 s  [1495.5, 683.1] -> [992.8, 356.0]  599.8 m in 2.03 s = 295.4 m/s   | next 30 s: 14 samples, path 181.4 m, ends [811.7, 358.0]
    t 213.14 s  [779.3, 345.5] -> [918.1, -211.8]  574.3 m in 2.03 s = 282.9 m/s   | next 30 s: 14 samples, path 175.9 m, ends [1053.1, -322.6]
    t 253.75 s  [1112.0, -339.1] -> [1745.6, -451.8]  643.5 m in 2.02 s = 318.6 m/s   | next 30 s: 14 samples, path 790.5 m, ends [1817.0, -435.1]
    t 261.86 s  [1779.5, -446.0] -> [1658.0, -363.4]  146.9 m in 2.03 s = 72.4 m/s   | next 30 s: 14 samples, path 699.0 m, ends [1728.0, -439.0]
- traffic #15: 27 teleports (raw >30 m count 74)
    t 44.61 s  [2313.4, -463.9] -> [2173.0, -588.3]  187.6 m in 2.03 s = 92.4 m/s   | next 30 s: 14 samples, path 456.9 m, ends [2325.3, -433.8]
    t 99.57 s  [2328.9, -286.2] -> [2285.6, 207.0]  495.1 m in 2.03 s = 243.9 m/s   | next 30 s: 14 samples, path 828.6 m, ends [1915.4, 371.0]
    t 119.86 s  [2323.2, 70.9] -> [1846.5, 426.2]  594.5 m in 2.03 s = 292.9 m/s   | next 30 s: 14 samples, path 662.7 m, ends [1475.1, 648.9]
    t 142.17 s  [1877.5, 396.9] -> [1446.4, 617.6]  484.3 m in 2.03 s = 238.6 m/s flags N   | next 30 s: 14 samples, path 259.8 m, ends [1668.1, 713.4]
    t 172.57 s  [1668.1, 713.4] -> [954.2, 355.9]  798.4 m in 2.02 s = 395.3 m/s   | next 30 s: 14 samples, path 238.5 m, ends [735.6, 305.7]
    t 217.20 s  [792.3, 352.5] -> [995.0, -266.3]  651.2 m in 2.03 s = 320.8 m/s   | next 30 s: 14 samples, path 57.0 m, ends [1038.9, -302.6]
    t 251.73 s  [1043.0, -306.0] -> [1645.0, -336.8]  602.8 m in 2.03 s = 296.9 m/s   | next 30 s: 14 samples, path 1221.3 m, ends [1808.7, -432.9]
    t 276.05 s  [1570.7, -264.6] -> [2184.9, -594.3]  697.1 m in 2.02 s = 345.1 m/s   | next 30 s: 14 samples, path 1180.7 m, ends [2138.0, -582.3]
- traffic #16: 29 teleports (raw >30 m count 91)
    t 42.58 s  [926.9, 338.4] -> [2198.8, -607.5]  1585.1 m in 2.03 s = 780.8 m/s   | next 30 s: 14 samples, path 1503.3 m, ends [2342.4, -209.7]
    t 44.61 s  [2198.8, -607.5] -> [1866.5, -458.1]  364.3 m in 2.03 s = 179.5 m/s   | next 30 s: 14 samples, path 1138.9 m, ends [2342.4, -209.7]
    t 60.84 s  [1745.0, -441.3] -> [2201.3, -596.5]  482.0 m in 2.03 s = 237.4 m/s   | next 30 s: 14 samples, path 530.7 m, ends [2342.4, -209.7]
    t 68.96 s  [2109.8, -577.3] -> [2341.9, -220.6]  425.6 m in 2.03 s = 209.6 m/s   | next 30 s: 14 samples, path 10.9 m, ends [2342.4, -209.7]
    t 99.57 s  [2342.4, -209.7] -> [2047.5, 190.7]  497.3 m in 2.03 s = 245.0 m/s   | next 30 s: 14 samples, path 576.6 m, ends [1923.9, 363.3]
    t 117.83 s  [2219.8, 224.3] -> [1906.0, 379.0]  349.9 m in 2.03 s = 172.3 m/s   | next 30 s: 14 samples, path 441.4 m, ends [1699.5, 669.5]
    t 142.17 s  [1883.4, 399.0] -> [1692.1, 622.3]  294.0 m in 2.03 s = 144.8 m/s   | next 30 s: 14 samples, path 898.1 m, ends [1004.6, 359.3]
    t 168.53 s  [1519.0, 686.5] -> [1036.1, 359.2]  583.4 m in 2.03 s = 287.4 m/s   | next 30 s: 14 samples, path 188.0 m, ends [848.4, 357.0]
- traffic #17: 24 teleports (raw >30 m count 47)
    t 42.58 s  [856.7, -136.0] -> [2029.6, -549.7]  1243.7 m in 2.03 s = 612.7 m/s   | next 30 s: 14 samples, path 796.8 m, ends [2332.5, -166.0]
    t 64.89 s  [1845.0, -439.8] -> [2329.2, -149.3]  564.7 m in 2.02 s = 279.5 m/s   | next 30 s: 14 samples, path 65.2 m, ends [2336.5, -125.2]
    t 103.62 s  [2331.6, -149.5] -> [1993.2, 229.4]  508.0 m in 2.02 s = 251.5 m/s   | next 30 s: 14 samples, path 42.7 m, ends [1995.2, 239.5]
    t 134.05 s  [1995.2, 239.5] -> [1677.3, 461.8]  387.9 m in 2.03 s = 191.1 m/s   | next 30 s: 14 samples, path 622.8 m, ends [1254.2, 410.1]
    t 156.35 s  [1759.9, 456.1] -> [1322.3, 476.8]  438.1 m in 2.03 s = 215.8 m/s   | next 30 s: 14 samples, path 339.9 m, ends [1029.6, 355.9]
    t 213.14 s  [799.3, 356.7] -> [652.2, 26.0]  361.9 m in 2.02 s = 179.2 m/s flags N   | next 30 s: 14 samples, path 543.0 m, ends [1066.2, -325.4]
    t 215.17 s  [652.2, 26.0] -> [1021.2, -288.1]  484.6 m in 2.03 s = 238.7 m/s   | next 30 s: 14 samples, path 59.9 m, ends [1067.3, -326.3]
    t 253.75 s  [1075.5, -332.1] -> [1707.2, -449.2]  642.5 m in 2.02 s = 318.1 m/s   | next 30 s: 14 samples, path 49.3 m, ends [1684.0, -433.5]
- traffic #18: 28 teleports (raw >30 m count 99)
    t 44.61 s  [1987.3, 300.7] -> [1577.6, -265.2]  698.6 m in 2.03 s = 344.2 m/s   | next 30 s: 14 samples, path 1636.4 m, ends [2329.5, -130.9]
    t 48.67 s  [1554.4, -259.5] -> [2153.9, -589.3]  684.2 m in 2.03 s = 337.1 m/s   | next 30 s: 14 samples, path 934.6 m, ends [2328.8, -136.6]
    t 66.93 s  [1873.2, -462.3] -> [2337.6, -102.9]  587.2 m in 2.04 s = 287.9 m/s   | next 30 s: 14 samples, path 96.9 m, ends [2336.2, -180.8]
    t 103.62 s  [2336.1, -181.0] -> [1979.0, 258.5]  566.3 m in 2.02 s = 280.3 m/s   | next 30 s: 14 samples, path 71.9 m, ends [1992.6, 234.9]
    t 134.05 s  [1992.6, 234.9] -> [1713.1, 461.2]  359.6 m in 2.03 s = 177.2 m/s   | next 30 s: 14 samples, path 313.8 m, ends [1652.9, 732.2]
    t 168.53 s  [1585.7, 725.8] -> [1097.5, 352.8]  614.4 m in 2.03 s = 302.7 m/s   | next 30 s: 14 samples, path 299.0 m, ends [798.6, 353.3]
    t 211.12 s  [734.9, 304.7] -> [938.9, -216.4]  559.6 m in 2.03 s = 275.7 m/s   | next 30 s: 14 samples, path 132.4 m, ends [857.2, -120.2]
    t 247.68 s  [857.2, -120.2] -> [1578.7, -265.5]  736.0 m in 2.07 s = 355.5 m/s   | next 30 s: 14 samples, path 828.4 m, ends [1999.1, -528.8]
- traffic #19: 27 teleports (raw >30 m count 74)
    t 44.61 s  [1147.3, -609.9] -> [2117.8, -573.9]  971.2 m in 2.03 s = 478.4 m/s   | next 30 s: 14 samples, path 729.4 m, ends [2320.3, -464.6]
    t 66.93 s  [1912.9, -482.4] -> [2320.5, -381.5]  419.9 m in 2.04 s = 205.8 m/s   | next 30 s: 14 samples, path 681.5 m, ends [2343.1, -52.7]
    t 77.07 s  [2306.3, -484.2] -> [2325.5, 17.4]  502.0 m in 2.02 s = 248.5 m/s   | next 30 s: 14 samples, path 621.9 m, ends [1979.0, 273.6]
    t 103.62 s  [2343.9, -72.3] -> [1977.9, 289.1]  514.4 m in 2.02 s = 254.6 m/s   | next 30 s: 14 samples, path 50.4 m, ends [1976.8, 259.2]
    t 136.08 s  [1978.0, 259.2] -> [1687.9, 705.7]  532.5 m in 2.03 s = 262.3 m/s   | next 30 s: 14 samples, path 232.3 m, ends [1478.5, 681.8]
    t 168.53 s  [1470.0, 673.4] -> [921.3, 355.9]  633.9 m in 2.03 s = 312.3 m/s   | next 30 s: 14 samples, path 477.8 m, ends [863.8, 356.0]
    t 170.55 s  [921.3, 355.9] -> [1131.4, 352.7]  210.1 m in 2.02 s = 104.0 m/s   | next 30 s: 14 samples, path 267.7 m, ends [863.8, 356.0]
    t 219.23 s  [805.7, 350.9] -> [1432.5, -257.6]  873.6 m in 2.03 s = 430.3 m/s   | next 30 s: 14 samples, path 33.4 m, ends [1403.8, -274.1]
- traffic #20: 22 teleports (raw >30 m count 84)
    t 40.55 s  [-163.3, -1154.5] -> [1790.5, -729.5]  1999.5 m in 2.02 s = 989.8 m/s   | next 30 s: 14 samples, path 999.9 m, ends [2341.4, -200.3]
    t 46.64 s  [1782.7, -709.5] -> [1913.6, -486.7]  258.4 m in 2.03 s = 127.3 m/s   | next 30 s: 14 samples, path 719.1 m, ends [2341.4, -200.3]
    t 62.87 s  [1820.4, -438.4] -> [2332.6, -167.2]  579.6 m in 2.03 s = 285.5 m/s   | next 30 s: 14 samples, path 39.0 m, ends [2339.5, -196.1]
    t 99.57 s  [2339.5, -196.1] -> [2008.1, 218.8]  531.0 m in 2.03 s = 261.6 m/s   | next 30 s: 14 samples, path 139.9 m, ends [2073.6, 187.8]
    t 138.11 s  [2163.3, 195.4] -> [1617.6, 726.2]  761.3 m in 2.03 s = 375.0 m/s   | next 30 s: 14 samples, path 599.0 m, ends [1493.9, 652.2]
    t 154.32 s  [1677.6, 558.1] -> [1423.5, 568.2]  254.3 m in 2.02 s = 125.9 m/s   | next 30 s: 14 samples, path 1024.1 m, ends [724.6, 240.6]
    t 178.65 s  [1467.4, 658.6] -> [724.6, 260.2]  842.9 m in 2.03 s = 415.2 m/s   | next 30 s: 14 samples, path 154.9 m, ends [735.5, 107.0]
    t 217.20 s  [781.9, 71.4] -> [977.1, -256.9]  381.9 m in 2.03 s = 188.2 m/s   | next 30 s: 14 samples, path 168.3 m, ends [1114.2, -345.9]
- traffic #21: 31 teleports (raw >30 m count 76)
    t 42.58 s  [276.0, -1877.2] -> [1929.1, -508.0]  2146.5 m in 2.03 s = 1057.4 m/s   | next 30 s: 14 samples, path 861.8 m, ends [2342.5, -80.9]
    t 68.96 s  [2114.1, -587.6] -> [2336.7, -27.0]  603.2 m in 2.03 s = 297.1 m/s   | next 30 s: 14 samples, path 100.3 m, ends [2330.7, -125.4]
    t 103.62 s  [2330.7, -125.4] -> [2147.7, 192.7]  367.0 m in 2.02 s = 181.7 m/s   | next 30 s: 14 samples, path 124.0 m, ends [2026.0, 203.2]
    t 136.08 s  [2026.0, 203.2] -> [1677.6, 532.9]  479.7 m in 2.03 s = 236.3 m/s   | next 30 s: 14 samples, path 654.2 m, ends [1438.7, 596.3]
    t 156.35 s  [1730.0, 457.4] -> [1345.5, 479.8]  385.2 m in 2.03 s = 189.7 m/s   | next 30 s: 14 samples, path 1209.4 m, ends [724.8, 168.5]
    t 178.65 s  [1478.4, 647.1] -> [727.4, 126.7]  913.7 m in 2.03 s = 450.1 m/s   | next 30 s: 14 samples, path 190.7 m, ends [774.2, 79.1]
    t 251.73 s  [948.5, -139.1] -> [1613.2, -299.2]  683.7 m in 2.03 s = 336.8 m/s   | next 30 s: 14 samples, path 1120.1 m, ends [1892.0, -481.7]
    t 276.05 s  [1475.1, -250.4] -> [2086.5, -583.5]  696.3 m in 2.02 s = 344.7 m/s   | next 30 s: 14 samples, path 2159.0 m, ends [2089.6, -570.2]
- traffic #22: 27 teleports (raw >30 m count 41)
    t 42.58 s  [327.3, -1056.6] -> [1948.0, -507.6]  1711.2 m in 2.03 s = 842.9 m/s   | next 30 s: 14 samples, path 806.0 m, ends [2328.2, -291.0]
    t 60.84 s  [1803.8, -432.1] -> [2327.9, -407.9]  524.7 m in 2.03 s = 258.5 m/s   | next 30 s: 14 samples, path 129.2 m, ends [2328.6, -278.7]
    t 93.49 s  [2328.6, -278.7] -> [2192.4, 220.0]  517.0 m in 2.01 s = 257.2 m/s   | next 30 s: 14 samples, path 458.9 m, ends [1950.4, 341.0]
    t 117.83 s  [2285.9, 211.6] -> [1951.5, 339.4]  358.0 m in 2.03 s = 176.3 m/s   | next 30 s: 14 samples, path 652.7 m, ends [1541.3, 696.2]
    t 138.11 s  [1965.3, 328.2] -> [1611.3, 736.1]  540.1 m in 2.03 s = 266.1 m/s   | next 30 s: 14 samples, path 179.6 m, ends [1461.1, 650.8]
    t 172.57 s  [1450.1, 630.9] -> [889.3, 356.1]  624.5 m in 2.02 s = 309.2 m/s   | next 30 s: 14 samples, path 140.6 m, ends [757.9, 323.3]
    t 219.23 s  [800.1, 334.5] -> [757.6, 74.4]  263.5 m in 2.03 s = 129.8 m/s   | next 30 s: 14 samples, path 704.2 m, ends [1316.5, -341.5]
    t 233.43 s  [790.6, 43.8] -> [1283.7, -342.4]  626.3 m in 2.04 s = 307.0 m/s   | next 30 s: 14 samples, path 132.6 m, ends [1397.2, -284.6]
- traffic #23: 22 teleports (raw >30 m count 57)
    t 42.58 s  [440.6, -1913.0] -> [2071.5, -566.4]  2115.0 m in 2.03 s = 1041.9 m/s   | next 30 s: 14 samples, path 834.8 m, ends [2329.0, -146.6]
    t 64.89 s  [1894.0, -466.4] -> [2336.4, -94.5]  578.0 m in 2.02 s = 286.1 m/s   | next 30 s: 14 samples, path 87.9 m, ends [2321.2, -128.5]
    t 101.60 s  [2321.2, -128.5] -> [2224.1, 230.7]  372.1 m in 2.03 s = 183.3 m/s   | next 30 s: 14 samples, path 137.1 m, ends [2098.4, 190.9]
    t 138.11 s  [2073.5, 190.9] -> [1520.4, 690.2]  745.1 m in 2.03 s = 367.1 m/s   | next 30 s: 14 samples, path 335.7 m, ends [1298.8, 454.2]
    t 223.29 s  [845.9, 356.0] -> [1399.4, -277.5]  841.2 m in 2.03 s = 414.4 m/s   | next 30 s: 14 samples, path 3.8 m, ends [1398.4, -278.0]
    t 274.03 s  [1398.8, -278.6] -> [1975.5, -535.4]  631.3 m in 2.04 s = 309.5 m/s   | next 30 s: 14 samples, path 605.6 m, ends [2074.0, -584.6]
    t 284.17 s  [2107.0, -587.6] -> [1887.8, -476.1]  245.9 m in 2.03 s = 121.1 m/s   | next 30 s: 14 samples, path 314.0 m, ends [2170.2, -600.6]
    t 318.64 s  [2205.3, -599.6] -> [2328.1, 11.9]  623.7 m in 2.02 s = 308.8 m/s   | next 30 s: 14 samples, path 337.6 m, ends [2179.2, 214.9]
- traffic #24: 25 teleports (raw >30 m count 78)
    t 40.55 s  [-115.2, -1058.3] -> [1956.8, -504.2]  2144.8 m in 2.02 s = 1061.8 m/s   | next 30 s: 14 samples, path 1013.2 m, ends [2327.5, -343.2]
    t 60.84 s  [1694.8, -443.9] -> [2325.6, -442.7]  630.8 m in 2.03 s = 310.7 m/s   | next 30 s: 14 samples, path 236.2 m, ends [2345.8, -208.3]
    t 101.60 s  [2330.1, -137.0] -> [2113.7, 184.8]  387.8 m in 2.03 s = 191.0 m/s   | next 30 s: 14 samples, path 872.0 m, ends [1901.7, 382.0]
    t 117.83 s  [2294.9, 197.7] -> [1807.0, 456.0]  552.1 m in 2.03 s = 271.9 m/s   | next 30 s: 14 samples, path 533.6 m, ends [1674.4, 521.2]
    t 140.14 s  [1902.2, 380.7] -> [1675.5, 603.2]  317.6 m in 2.03 s = 156.5 m/s   | next 30 s: 14 samples, path 1023.7 m, ends [1136.2, 359.2]
    t 154.32 s  [1672.6, 489.0] -> [1479.0, 666.9]  262.9 m in 2.02 s = 130.2 m/s   | next 30 s: 14 samples, path 840.6 m, ends [941.7, 355.9]
    t 168.53 s  [1567.1, 700.7] -> [1136.2, 359.2]  549.8 m in 2.03 s = 270.8 m/s   | next 30 s: 14 samples, path 255.3 m, ends [881.0, 354.9]
    t 221.26 s  [823.0, 359.2] -> [1500.2, -262.4]  919.2 m in 2.03 s = 452.8 m/s   | next 30 s: 14 samples, path 185.0 m, ends [1407.0, -271.2]
- traffic #25: 18 teleports (raw >30 m count 70)
    t 44.61 s  [1171.3, -609.6] -> [1991.6, -536.8]  823.5 m in 2.03 s = 405.7 m/s   | next 30 s: 14 samples, path 604.5 m, ends [2333.3, -257.9]
    t 70.99 s  [2184.7, -606.5] -> [2335.7, -249.4]  387.7 m in 2.03 s = 191.0 m/s   | next 30 s: 14 samples, path 525.7 m, ends [2302.3, 188.1]
    t 97.54 s  [2330.8, -266.9] -> [2282.6, 209.3]  478.6 m in 2.03 s = 235.8 m/s   | next 30 s: 14 samples, path 261.4 m, ends [2340.1, -39.3]
    t 134.05 s  [2342.1, -82.6] -> [1674.4, 505.7]  889.9 m in 2.03 s = 438.4 m/s   | next 30 s: 14 samples, path 569.8 m, ends [1414.2, 574.4]
    t 156.35 s  [1784.6, 457.7] -> [1432.7, 607.0]  382.3 m in 2.03 s = 188.3 m/s   | next 30 s: 14 samples, path 331.1 m, ends [1210.5, 363.4]
    t 186.77 s  [1210.5, 363.4] -> [732.9, 111.9]  539.8 m in 2.02 s = 267.2 m/s   | next 30 s: 14 samples, path 316.9 m, ends [934.9, -123.6]
    t 251.73 s  [1027.7, -298.2] -> [1584.1, -281.4]  556.7 m in 2.03 s = 274.2 m/s   | next 30 s: 14 samples, path 241.8 m, ends [1728.1, -452.3]
    t 316.62 s  [2157.2, -597.9] -> [2333.7, -2.5]  621.0 m in 2.02 s = 307.4 m/s   | next 30 s: 14 samples, path 542.4 m, ends [2127.2, 188.3]
- traffic #26: 26 teleports (raw >30 m count 113)
    t 44.61 s  [1684.7, 563.4] -> [1905.5, -485.9]  1072.3 m in 2.03 s = 528.2 m/s   | next 30 s: 14 samples, path 599.7 m, ends [2325.2, -294.9]
    t 68.96 s  [2102.3, -580.7] -> [2326.7, -286.7]  369.9 m in 2.03 s = 182.2 m/s   | next 30 s: 14 samples, path 786.7 m, ends [2151.3, 191.0]
    t 97.54 s  [2321.6, -429.6] -> [2151.3, 191.0]  643.5 m in 2.03 s = 317.0 m/s   | next 30 s: 14 samples, path 710.6 m, ends [1919.2, 361.8]
    t 119.86 s  [2319.1, 128.4] -> [1918.2, 363.8]  464.9 m in 2.03 s = 229.0 m/s   | next 30 s: 14 samples, path 649.6 m, ends [1551.1, 706.4]
    t 136.08 s  [1941.8, 344.0] -> [1699.2, 687.5]  420.5 m in 2.03 s = 207.2 m/s   | next 30 s: 14 samples, path 321.7 m, ends [1446.5, 627.1]
    t 172.57 s  [1419.2, 577.7] -> [802.3, 354.2]  656.1 m in 2.02 s = 324.8 m/s   | next 30 s: 14 samples, path 98.5 m, ends [729.7, 290.5]
    t 209.09 s  [724.7, 259.3] -> [843.0, -108.7]  386.5 m in 2.04 s = 189.5 m/s   | next 30 s: 14 samples, path 158.8 m, ends [941.0, -224.1]
    t 249.70 s  [942.7, -225.3] -> [1636.9, -343.4]  704.2 m in 2.02 s = 348.6 m/s   | next 30 s: 14 samples, path 267.4 m, ends [1833.1, -450.0]
- traffic #27: 23 teleports (raw >30 m count 64)
    t 42.58 s  [327.3, -1439.8] -> [2047.1, -573.8]  1925.5 m in 2.03 s = 948.5 m/s   | next 30 s: 14 samples, path 365.1 m, ends [2331.6, -460.9]
    t 103.62 s  [2331.8, -159.8] -> [2009.7, 212.9]  492.6 m in 2.02 s = 243.9 m/s   | next 30 s: 14 samples, path 138.4 m, ends [2072.5, 184.9]
    t 138.11 s  [2128.1, 185.2] -> [1480.9, 672.2]  810.0 m in 2.03 s = 399.0 m/s   | next 30 s: 14 samples, path 351.5 m, ends [1677.7, 574.9]
    t 174.60 s  [1677.6, 512.6] -> [731.5, 297.5]  970.2 m in 2.03 s = 478.0 m/s   | next 30 s: 14 samples, path 208.0 m, ends [745.2, 309.7]
    t 209.09 s  [727.8, 286.5] -> [849.9, -149.1]  452.4 m in 2.04 s = 221.8 m/s   | next 30 s: 14 samples, path 143.4 m, ends [957.7, -241.1]
    t 251.73 s  [962.1, -254.7] -> [1458.5, -262.3]  496.5 m in 2.03 s = 244.6 m/s   | next 30 s: 14 samples, path 942.8 m, ends [1992.5, -545.1]
    t 276.05 s  [1565.6, -263.9] -> [2106.4, -584.3]  628.6 m in 2.02 s = 311.2 m/s   | next 30 s: 14 samples, path 1568.1 m, ends [2140.4, -594.4]
    t 278.09 s  [2106.4, -584.3] -> [1959.3, -525.9]  158.3 m in 2.04 s = 77.6 m/s   | next 30 s: 14 samples, path 1437.7 m, ends [2166.5, -604.1]
- traffic #28: 24 teleports (raw >30 m count 86)
    t 46.64 s  [2100.7, -580.7] -> [2223.9, -595.6]  124.1 m in 2.03 s = 61.1 m/s   | next 30 s: 14 samples, path 973.3 m, ends [2260.1, -514.4]
    t 48.67 s  [2223.9, -595.6] -> [2075.8, -571.6]  150.0 m in 2.03 s = 73.9 m/s   | next 30 s: 14 samples, path 1293.5 m, ends [2346.6, -52.2]
    t 64.89 s  [1859.1, -454.6] -> [2321.4, -430.7]  462.9 m in 2.02 s = 229.2 m/s   | next 30 s: 14 samples, path 777.0 m, ends [2327.7, 139.2]
    t 77.07 s  [2260.1, -514.4] -> [2346.6, -52.2]  470.2 m in 2.02 s = 232.8 m/s   | next 30 s: 14 samples, path 394.1 m, ends [2183.8, 222.1]
    t 136.08 s  [2023.6, 208.4] -> [1694.7, 656.8]  556.1 m in 2.03 s = 273.9 m/s   | next 30 s: 14 samples, path 252.8 m, ends [1506.4, 687.7]
    t 168.53 s  [1496.5, 686.5] -> [963.5, 353.0]  628.7 m in 2.03 s = 309.7 m/s   | next 30 s: 14 samples, path 190.7 m, ends [774.5, 340.4]
    t 211.12 s  [747.6, 317.9] -> [878.8, -163.4]  498.9 m in 2.03 s = 245.7 m/s   | next 30 s: 14 samples, path 1184.8 m, ends [1307.4, -331.9]
    t 225.31 s  [854.4, -41.3] -> [1552.1, -262.7]  732.0 m in 2.02 s = 362.4 m/s   | next 30 s: 14 samples, path 401.3 m, ends [1230.8, -332.6]
- traffic #29: 25 teleports (raw >30 m count 89)
    t 48.67 s  [1350.0, -597.5] -> [1906.8, -480.3]  569.0 m in 2.03 s = 280.3 m/s   | next 30 s: 14 samples, path 1620.9 m, ends [2340.5, -62.6]
    t 60.84 s  [1853.4, -443.9] -> [2334.2, -113.2]  583.6 m in 2.03 s = 287.5 m/s   | next 30 s: 14 samples, path 1104.1 m, ends [2327.7, 67.4]
    t 62.87 s  [2334.2, -113.2] -> [2315.8, -469.0]  356.3 m in 2.03 s = 175.5 m/s   | next 30 s: 14 samples, path 760.5 m, ends [2328.2, 80.1]
    t 75.05 s  [2242.6, -553.3] -> [2335.4, -98.5]  464.2 m in 2.03 s = 228.7 m/s   | next 30 s: 14 samples, path 353.2 m, ends [2268.3, 229.4]
    t 136.08 s  [2038.8, 201.9] -> [1674.5, 551.0]  504.6 m in 2.03 s = 248.6 m/s   | next 30 s: 14 samples, path 600.0 m, ends [1260.8, 411.9]
    t 156.35 s  [1697.1, 456.8] -> [1378.7, 527.0]  326.0 m in 2.03 s = 160.6 m/s   | next 30 s: 14 samples, path 347.0 m, ends [1100.5, 356.0]
    t 219.23 s  [841.8, 352.9] -> [1388.5, -286.8]  841.5 m in 2.03 s = 414.5 m/s   | next 30 s: 14 samples, path 54.9 m, ends [1338.4, -301.9]
    t 263.89 s  [1288.3, -301.6] -> [1786.6, -428.2]  514.1 m in 2.03 s = 253.3 m/s   | next 30 s: 14 samples, path 668.2 m, ends [2075.6, -577.4]
- %d jumps in total. I: per-idx carpos rows are NOT one continuous car (a slot gets
  re-used/respawned far away, the same thing the FREE tmove deltas show), so read
  these as slot resets, not as one car teleporting. NV: the log cannot tell a real
  reset from slot re-use, they look identical here.

## 4. Falls (z drop > 5 m inside one sample gap)
- AIP f4440->4500 (60 frames, 1.75 s): z 64.0 -> 58.0 (drop 6.0 m) at [2314.0, -349.0], sp 42.6 -> 48.4
- COLLOG f4200->4500 (300 frames, 10.64 s): z 69.0 -> 58.0 (drop 11.0 m) at [2257.0, -550.0], sp 15.1 -> 48.4  [coarse: COLLOG rows are 300 frames apart, so this bounds the drop, NV on the 2 s window]
- COLLOG f12900->13200 (300 frames, 7.89 s): z 68.0 -> 56.0 (drop 12.0 m) at [2287.0, -495.0], sp 29.4 -> 45.3  [coarse: COLLOG rows are 300 frames apart, so this bounds the drop, NV on the 2 s window]
- COLLOG f13800->14100 (300 frames, 4.84 s): z 63.0 -> 52.0 (drop 11.0 m) at [2321.0, 146.0], sp 41.0 -> 25.4  [coarse: COLLOG rows are 300 frames apart, so this bounds the drop, NV on the 2 s window]
- COLLOG f23100->23400 (300 frames, 5.17 s): z 59.0 -> 53.0 (drop 6.0 m) at [1046.0, -308.0], sp 32.5 -> 25.7  [coarse: COLLOG rows are 300 frames apart, so this bounds the drop, NV on the 2 s window]
- COLLOG f26100->26400 (300 frames, 5.34 s): z 64.0 -> 57.0 (drop 7.0 m) at [2327.0, -358.0], sp 30.6 -> 34.0  [coarse: COLLOG rows are 300 frames apart, so this bounds the drop, NV on the 2 s window]
- COLLOG f26400->26700 (300 frames, 4.76 s): z 57.0 -> 51.0 (drop 6.0 m) at [2332.0, -247.0], sp 34.0 -> 29.9  [coarse: COLLOG rows are 300 frames apart, so this bounds the drop, NV on the 2 s window]
- COLLOG f27600->27900 (300 frames, 5.35 s): z 62.0 -> 51.0 (drop 11.0 m) at [2315.0, 161.0], sp 43.8 -> 44.7  [coarse: COLLOG rows are 300 frames apart, so this bounds the drop, NV on the 2 s window]

## 5. Reset counter and wall pressure (COLLOG)
- f3300 reset 6162 -> 0 at pos [1685.0, -456.0, 64.0] sp 0.0
- f5100 reset 0 -> 190179 at pos [2331.0, -123.0, 51.0] sp 10.0
- f5400 reset 190179 -> 194179 at pos [2332.0, 32.0, 58.0] sp 33.6
- f33600 reset 194179 -> 2360646 at pos [2093.0, 179.0, 51.0] sp 1.7

## 6. FREE tmove: per-name delta > 120 m over one row (reset/recycle, F)
- f2880 {'SAMANTHA': -306.0, 'AL': -304.6, 'SCOTT': -304.5, 'TODD': -304.4, 'KAZ': -304.3}
- f3000 {'SAMANTHA': -306.0, 'AL': -304.6, 'SCOTT': -304.5, 'TODD': -304.4, 'KAZ': -304.3}
- f3120 {'SCOTT': -420.2, 'TODD': -418.6, 'KAZ': -418.5}
- f3240 {'HUNTER': 306.1, 'CHAD': 306.1, 'WILL': 306.1}
- f3360 {'WILL': 306.1, 'CHAD': 306.1, 'HUNTER': 306.1}
- f3480 {'SAMANTHA': 300.4, 'CHAD': 299.9, 'HUNTER': 197.4, 'TODD': 198.3}
- f3600 {'TODD': 197.0, 'HUNTER': 196.2, 'CHAD': 299.8, 'SAMANTHA': 300.2}
- f3720 {'TODD': 195.3, 'HUNTER': 195.1, 'CHAD': 299.7, 'SAMANTHA': 299.9}
- f3840 {'TODD': 194.2, 'HUNTER': 194.3, 'CHAD': 299.5, 'SAMANTHA': 299.7}
- f3960 {'TODD': 192.9, 'HUNTER': 193.1, 'CHAD': 298.8, 'SAMANTHA': 298.9}
- ... 75 more
```

## Salida real: runs/w_j/log.txt

```
# resetscan runs/w_j/log.txt

## 1. In the log (F)
- 9946 lines, 2100 carpos rows, cars by kind: {'traffic': 21}
- carpos t window 38.51..239.13 s, sample gap median 2.03 s (carpos carries x,y only: no z, no speed)
- frames per second: 58.3 measured on AIP pairs, 59.2 by span ratio (I: no single line pairs a frame with a carpos t)
- polys max 8173 of polycap 8192 (0.991 of cap at the last TRAFLOG)

## 2. Still / embedded, per car (|dpos| < 0.5 m for > 6 s)
- traffic #9: 1 still episodes (0 with speed witness > 5 m/s)
    t 81.03..105.35 s, 13 samples, at [2325.8, 16.4], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
- traffic #10: 2 still episodes (0 with speed witness > 5 m/s)
    t 97.25..107.37 s, 6 samples, at [2323.1, 112.0], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
    t 139.81..156.03 s, 9 samples, at [1977.1, 274.9], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
- traffic #11: 1 still episodes (0 with speed witness > 5 m/s)
    t 95.22..105.35 s, 6 samples, at [2322.9, 95.7], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
- traffic #12: 1 still episodes (0 with speed witness > 5 m/s)
    t 83.06..105.35 s, 12 samples, at [2323.1, 48.8], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
- traffic #13: 2 still episodes (1 with speed witness > 5 m/s)
    t 81.03..97.25 s, 9 samples, at [2328.3, 3.9], witness speed 13.1 -> EMBEDDED (F for the position, I for the speed: the log has no per-row speed) [hit-car f6522 97.3s]
    t 151.97..178.33 s, 14 samples, at [1838.7, 429.4], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
- traffic #14: 1 still episodes (0 with speed witness > 5 m/s)
    t 145.88..154.00 s, 5 samples, at [1976.8, 270.2], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
- traffic #15: 2 still episodes (1 with speed witness > 5 m/s)
    t 145.88..151.97 s, 4 samples, at [1942.0, 341.3], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
    t 184.40..192.50 s, 5 samples, at [1695.0, 481.7], witness speed 7.4 -> EMBEDDED (F for the position, I for the speed: the log has no per-row speed) [hit-wall f11553 184.4s]
- traffic #16: 1 still episodes (0 with speed witness > 5 m/s)
    t 79.01..101.30 s, 12 samples, at [2331.8, -10.3], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
- traffic #17: 2 still episodes (0 with speed witness > 5 m/s)
    t 81.03..89.13 s, 5 samples, at [2339.3, -35.8], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
    t 141.84..156.03 s, 8 samples, at [1978.4, 311.0], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
- traffic #18: 1 still episodes (0 with speed witness > 5 m/s)
    t 81.03..101.30 s, 11 samples, at [2323.8, 31.7], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
- traffic #20: 2 still episodes (0 with speed witness > 5 m/s)
    t 72.94..81.03 s, 5 samples, at [2328.5, -135.2], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
    t 154.00..162.11 s, 5 samples, at [1815.3, 449.8], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
- traffic #21: 2 still episodes (0 with speed witness > 5 m/s)
    t 107.38..115.50 s, 5 samples, at [2167.3, 196.8], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
    t 151.97..158.06 s, 4 samples, at [1973.3, 317.5], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
- traffic #22: 1 still episodes (0 with speed witness > 5 m/s)
    t 95.22..103.32 s, 5 samples, at [2334.5, -135.0], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
- traffic #23: 1 still episodes (0 with speed witness > 5 m/s)
    t 145.88..160.09 s, 8 samples, at [1966.6, 327.3], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
- traffic #24: 1 still episodes (1 with speed witness > 5 m/s)
    t 72.94..81.03 s, 5 samples, at [2329.8, -142.4], witness speed 22.9 -> EMBEDDED (F for the position, I for the speed: the log has no per-row speed) [hit-car f5641 83.0s]
- traffic #25: 1 still episodes (0 with speed witness > 5 m/s)
    t 91.16..105.35 s, 8 samples, at [2323.2, 64.1], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
- traffic #26: 3 still episodes (2 with speed witness > 5 m/s)
    t 91.16..105.35 s, 8 samples, at [2323.2, 78.7], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
    t 164.14..174.27 s, 6 samples, at [1823.5, 441.4], witness speed 5.9 -> EMBEDDED (F for the position, I for the speed: the log has no per-row speed) [hit-wall f11186 178.3s]
    t 178.33..184.40 s, 4 samples, at [1821.9, 441.0], witness speed 5.9 -> EMBEDDED (F for the position, I for the speed: the log has no per-row speed) [hit-wall f11186 178.3s]
- traffic #27: 1 still episodes (0 with speed witness > 5 m/s)
    t 107.38..117.52 s, 6 samples, at [2152.1, 190.1], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
- traffic #28: 1 still episodes (0 with speed witness > 5 m/s)
    t 79.01..95.22 s, 9 samples, at [2336.5, -22.5], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
- traffic #29: 1 still episodes (0 with speed witness > 5 m/s)
    t 105.35..115.50 s, 6 samples, at [2175.2, 207.6], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)

## 3. Teleports (> 30 m between samples, implied speed > 60 m/s)
- traffic #9: 5 teleports (raw >30 m count 24)
    t 40.53 s  [399.5, -1901.9] -> [1891.8, -481.6]  2060.1 m in 2.02 s = 1019.9 m/s   | next 30 s: 14 samples, path 388.6 m, ends [2241.6, -582.3]
    t 74.96 s  [2252.4, -553.9] -> [2323.1, 42.8]  600.9 m in 2.02 s = 297.5 m/s   | next 30 s: 14 samples, path 26.6 m, ends [2325.8, 16.4]
    t 107.37 s  [2325.8, 16.4] -> [2071.0, 184.8]  305.4 m in 2.02 s = 151.2 m/s   | next 30 s: 14 samples, path 318.4 m, ends [2318.6, 127.6]
    t 149.94 s  [2323.1, 80.6] -> [1684.8, 495.2]  761.1 m in 2.03 s = 374.9 m/s   | next 30 s: 14 samples, path 382.6 m, ends [1539.4, 695.0]
    t 222.92 s  [1218.1, 369.9] -> [725.2, 273.9]  502.2 m in 2.04 s = 246.2 m/s   | next 30 s: 8 samples, path 97.5 m, ends [725.0, 176.4]
- traffic #10: 7 teleports (raw >30 m count 21)
    t 40.53 s  [-116.1, -1065.1] -> [1961.6, -523.4]  2147.2 m in 2.02 s = 1062.9 m/s   | next 30 s: 14 samples, path 313.8 m, ends [2244.8, -566.2]
    t 74.96 s  [2259.0, -542.0] -> [2310.7, 180.8]  724.6 m in 2.02 s = 358.7 m/s   | next 30 s: 14 samples, path 1203.0 m, ends [2323.1, 112.0]
    t 83.06 s  [2322.7, 113.1] -> [2322.5, -357.5]  470.6 m in 2.03 s = 231.8 m/s   | next 30 s: 14 samples, path 1146.8 m, ends [1932.7, 354.5]
    t 85.08 s  [2322.5, -357.5] -> [2288.7, 204.0]  562.5 m in 2.02 s = 278.5 m/s   | next 30 s: 14 samples, path 596.4 m, ends [1942.6, 347.5]
    t 109.40 s  [2323.1, 112.0] -> [1922.8, 361.1]  471.5 m in 2.03 s = 232.3 m/s   | next 30 s: 14 samples, path 110.2 m, ends [1977.9, 274.5]
    t 162.11 s  [1977.2, 271.1] -> [1688.2, 568.5]  414.7 m in 2.02 s = 205.3 m/s   | next 30 s: 14 samples, path 338.7 m, ends [1511.3, 685.4]
    t 210.75 s  [1463.0, 653.9] -> [1005.2, 353.7]  547.4 m in 2.03 s = 269.7 m/s   | next 30 s: 14 samples, path 246.7 m, ends [764.8, 333.1]
- traffic #11: 10 teleports (raw >30 m count 31)
    t 42.56 s  [1177.1, -609.6] -> [2140.6, -590.9]  963.7 m in 2.03 s = 474.7 m/s   | next 30 s: 14 samples, path 872.8 m, ends [2258.9, -510.5]
    t 44.58 s  [2140.6, -590.9] -> [2017.1, -545.9]  131.4 m in 2.02 s = 65.1 m/s   | next 30 s: 14 samples, path 763.3 m, ends [2246.9, -528.8]
    t 62.81 s  [1860.2, -451.4] -> [2318.5, -439.9]  458.4 m in 2.02 s = 227.0 m/s   | next 30 s: 14 samples, path 2455.9 m, ends [2322.7, 111.2]
    t 74.96 s  [2246.9, -528.8] -> [2327.6, 126.6]  660.3 m in 2.02 s = 326.9 m/s   | next 30 s: 14 samples, path 1689.4 m, ends [2322.9, 95.7]
    t 83.06 s  [2283.6, 221.5] -> [2232.8, -576.6]  799.7 m in 2.03 s = 393.9 m/s   | next 30 s: 14 samples, path 1360.8 m, ends [1910.0, 372.9]
    t 85.08 s  [2232.8, -576.6] -> [2316.5, 147.0]  728.4 m in 2.02 s = 360.6 m/s   | next 30 s: 14 samples, path 644.4 m, ends [1919.1, 365.0]
    t 107.37 s  [2322.9, 95.7] -> [1877.7, 399.1]  538.8 m in 2.02 s = 266.7 m/s   | next 30 s: 14 samples, path 185.1 m, ends [1978.8, 257.6]
    t 162.11 s  [2045.6, 187.7] -> [1684.5, 690.4]  619.0 m in 2.02 s = 306.4 m/s   | next 30 s: 14 samples, path 209.9 m, ends [1674.1, 481.5]
- traffic #12: 6 teleports (raw >30 m count 30)
    t 42.56 s  [1684.8, 578.3] -> [1886.9, -482.5]  1079.9 m in 2.02 s = 534.6 m/s   | next 30 s: 14 samples, path 393.5 m, ends [2239.9, -571.4]
    t 74.96 s  [2248.6, -543.9] -> [2322.9, 91.6]  639.8 m in 2.02 s = 316.7 m/s   | next 30 s: 14 samples, path 42.8 m, ends [2323.1, 48.8]
    t 107.37 s  [2323.1, 48.8] -> [2051.1, 190.0]  306.5 m in 2.02 s = 151.7 m/s   | next 30 s: 14 samples, path 153.7 m, ends [2154.2, 195.7]
    t 149.94 s  [2281.8, 209.1] -> [1689.3, 626.9]  725.0 m in 2.03 s = 357.1 m/s   | next 30 s: 14 samples, path 364.5 m, ends [1452.3, 634.6]
    t 192.50 s  [1331.0, 485.2] -> [1436.1, 599.2]  155.1 m in 2.03 s = 76.4 m/s   | next 30 s: 14 samples, path 675.3 m, ends [1094.6, 358.6]
    t 208.72 s  [1521.7, 675.7] -> [1215.6, 368.0]  434.0 m in 2.02 s = 214.9 m/s   | next 30 s: 14 samples, path 261.7 m, ends [955.4, 353.0]
- traffic #13: 7 teleports (raw >30 m count 39)
    t 40.54 s  [330.5, -1481.3] -> [1933.2, -489.9]  1884.5 m in 2.03 s = 928.3 m/s   | next 30 s: 14 samples, path 1454.7 m, ends [2335.6, -190.7]
    t 54.72 s  [1722.5, -441.3] -> [2098.5, -573.7]  398.6 m in 2.03 s = 196.4 m/s   | next 30 s: 14 samples, path 1027.4 m, ends [2328.3, 3.9]
    t 68.89 s  [1850.2, -446.1] -> [2335.6, -190.7]  548.5 m in 2.02 s = 271.5 m/s   | next 30 s: 14 samples, path 198.2 m, ends [2328.3, 3.9]
    t 107.37 s  [2328.8, 6.4] -> [1974.2, 318.6]  472.5 m in 2.02 s = 233.9 m/s   | next 30 s: 14 samples, path 164.0 m, ends [2028.3, 197.3]
    t 149.94 s  [2109.8, 187.5] -> [1839.5, 428.8]  362.3 m in 2.03 s = 178.5 m/s flags N   | next 30 s: 14 samples, path 1.3 m, ends [1838.6, 429.5]
    t 180.35 s  [1838.6, 429.5] -> [1525.7, 681.3]  401.6 m in 2.02 s = 198.8 m/s   | next 30 s: 14 samples, path 1024.2 m, ends [975.2, 359.2]
    t 198.59 s  [1677.3, 616.3] -> [1175.9, 359.4]  563.4 m in 2.03 s = 277.5 m/s   | next 30 s: 14 samples, path 460.7 m, ends [735.0, 304.6]
- traffic #14: 6 teleports (raw >30 m count 12)
    t 46.61 s  [2111.9, -581.1] -> [1900.4, -470.5]  238.7 m in 2.03 s = 117.6 m/s   | next 30 s: 14 samples, path 1369.8 m, ends [2335.3, -9.5]
    t 56.73 s  [1803.5, -428.6] -> [2319.0, -447.7]  515.9 m in 2.01 s = 256.6 m/s   | next 30 s: 14 samples, path 880.0 m, ends [2328.1, 122.4]
    t 74.96 s  [2227.6, -578.8] -> [2335.3, -9.5]  579.4 m in 2.02 s = 286.8 m/s   | next 30 s: 14 samples, path 194.7 m, ends [2312.1, 181.9]
    t 111.43 s  [2268.9, 229.4] -> [1969.8, 319.1]  312.3 m in 2.03 s = 153.8 m/s   | next 30 s: 14 samples, path 96.2 m, ends [1976.9, 269.7]
    t 162.11 s  [2001.5, 220.8] -> [1677.6, 620.6]  514.5 m in 2.02 s = 254.7 m/s   | next 30 s: 14 samples, path 182.7 m, ends [1700.6, 457.0]
    t 194.53 s  [1708.2, 456.3] -> [1292.9, 443.6]  415.5 m in 2.03 s = 204.7 m/s   | next 30 s: 14 samples, path 330.2 m, ends [997.7, 353.2]
- traffic #15: 6 teleports (raw >30 m count 26)
    t 48.64 s  [1392.9, -581.2] -> [2106.4, -573.9]  713.5 m in 2.03 s = 351.5 m/s   | next 30 s: 14 samples, path 864.4 m, ends [2333.3, -269.8]
    t 62.81 s  [1894.5, -467.0] -> [2328.6, -459.7]  434.2 m in 2.02 s = 214.9 m/s   | next 30 s: 14 samples, path 299.0 m, ends [2335.3, -163.7]
    t 109.40 s  [2343.4, -89.7] -> [1815.8, 449.1]  754.1 m in 2.02 s = 373.3 m/s   | next 30 s: 14 samples, path 135.0 m, ends [1919.1, 363.2]
    t 164.14 s  [1967.3, 321.4] -> [1677.9, 536.1]  360.3 m in 2.03 s = 177.5 m/s   | next 30 s: 14 samples, path 137.0 m, ends [1695.0, 481.6]
    t 194.53 s  [1695.0, 481.6] -> [1425.6, 580.0]  286.8 m in 2.03 s = 141.3 m/s   | next 30 s: 14 samples, path 804.4 m, ends [890.1, 353.0]
    t 208.72 s  [1490.5, 658.8] -> [1068.0, 353.2]  521.4 m in 2.02 s = 258.1 m/s   | next 30 s: 14 samples, path 322.9 m, ends [754.2, 321.6]
- traffic #16: 7 teleports (raw >30 m count 22)
    t 58.76 s  [1845.6, -778.0] -> [2196.4, -604.1]  391.5 m in 2.03 s = 192.9 m/s   | next 30 s: 14 samples, path 680.5 m, ends [2331.8, -10.3]
    t 74.96 s  [2296.3, -498.5] -> [2327.7, 7.0]  506.5 m in 2.02 s = 250.7 m/s   | next 30 s: 14 samples, path 18.9 m, ends [2331.2, -9.4]
    t 107.38 s  [2330.8, -9.1] -> [2037.7, 190.9]  354.8 m in 2.03 s = 174.8 m/s   | next 30 s: 14 samples, path 359.6 m, ends [2321.2, 125.3]
    t 149.94 s  [2323.9, 30.4] -> [1708.1, 454.0]  747.4 m in 2.03 s = 368.2 m/s   | next 30 s: 14 samples, path 386.1 m, ends [1680.5, 637.3]
    t 178.33 s  [1835.3, 439.7] -> [1680.5, 637.3]  251.0 m in 2.03 s = 123.7 m/s   | next 30 s: 14 samples, path 682.9 m, ends [1446.1, 609.6]
    t 194.53 s  [1677.8, 476.5] -> [1334.1, 473.8]  343.7 m in 2.03 s = 169.3 m/s   | next 30 s: 14 samples, path 1020.9 m, ends [733.8, 301.4]
    t 210.75 s  [1460.7, 634.3] -> [907.1, 355.9]  619.7 m in 2.03 s = 305.3 m/s   | next 30 s: 14 samples, path 244.8 m, ends [724.7, 252.6]
- traffic #17: 7 teleports (raw >30 m count 22)
    t 42.56 s  [907.7, -199.9] -> [2016.7, -546.4]  1161.9 m in 2.02 s = 575.2 m/s   | next 30 s: 14 samples, path 1379.9 m, ends [2228.3, -570.5]
    t 60.79 s  [1834.5, -436.6] -> [2344.8, -67.4]  629.9 m in 2.03 s = 310.3 m/s   | next 30 s: 14 samples, path 1086.4 m, ends [2339.3, -35.8]
    t 62.81 s  [2344.8, -67.4] -> [2303.5, -477.7]  412.4 m in 2.02 s = 204.1 m/s   | next 30 s: 14 samples, path 685.6 m, ends [2342.0, -24.5]
    t 72.94 s  [2228.3, -570.5] -> [2344.7, -88.6]  495.8 m in 2.02 s = 245.4 m/s   | next 30 s: 14 samples, path 89.7 m, ends [2337.1, -1.7]
    t 109.40 s  [2331.8, 55.5] -> [1854.9, 423.7]  602.5 m in 2.02 s = 298.3 m/s   | next 30 s: 14 samples, path 145.9 m, ends [1965.1, 328.7]
    t 162.11 s  [1981.1, 299.2] -> [1690.2, 610.5]  426.1 m in 2.02 s = 210.9 m/s   | next 30 s: 14 samples, path 362.6 m, ends [1462.6, 660.0]
    t 220.88 s  [1268.9, 423.6] -> [724.6, 246.3]  572.4 m in 2.02 s = 283.4 m/s   | next 30 s: 9 samples, path 115.5 m, ends [726.6, 130.9]
- traffic #18: 7 teleports (raw >30 m count 10)
    t 42.56 s  [1833.4, 436.7] -> [2047.6, -570.6]  1029.8 m in 2.02 s = 509.8 m/s   | next 30 s: 14 samples, path 315.9 m, ends [2300.8, -492.1]
    t 76.99 s  [2325.0, -469.7] -> [2323.1, 52.2]  521.9 m in 2.03 s = 257.1 m/s   | next 30 s: 14 samples, path 31.0 m, ends [2325.8, 38.6]
    t 107.38 s  [2325.8, 38.6] -> [1990.8, 236.9]  389.3 m in 2.03 s = 191.8 m/s   | next 30 s: 14 samples, path 145.6 m, ends [2082.9, 187.0]
    t 149.94 s  [2178.3, 207.8] -> [1674.7, 470.7]  568.1 m in 2.03 s = 279.8 m/s   | next 30 s: 14 samples, path 142.0 m, ends [1810.0, 451.5]
    t 186.43 s  [1853.2, 423.2] -> [1351.1, 500.0]  507.9 m in 2.03 s = 250.2 m/s   | next 30 s: 14 samples, path 1039.6 m, ends [798.2, 348.9]
    t 188.45 s  [1351.1, 500.0] -> [1495.8, 683.1]  233.4 m in 2.02 s = 115.5 m/s   | next 30 s: 14 samples, path 836.9 m, ends [770.8, 335.2]
    t 214.80 s  [1384.5, 533.4] -> [798.2, 348.9]  614.6 m in 2.02 s = 304.3 m/s   | next 30 s: 12 samples, path 155.7 m, ends [724.6, 227.0]
- traffic #19: 7 teleports (raw >30 m count 21)
    t 52.69 s  [1666.1, -379.4] -> [2186.2, -597.4]  563.9 m in 2.02 s = 279.2 m/s   | next 30 s: 14 samples, path 711.2 m, ends [2331.2, -160.7]
    t 68.89 s  [2009.8, -538.8] -> [2335.5, -237.9]  443.4 m in 2.02 s = 219.5 m/s   | next 30 s: 14 samples, path 250.8 m, ends [2327.8, -7.8]
    t 107.38 s  [2327.0, 1.4] -> [2012.3, 214.8]  380.2 m in 2.03 s = 187.3 m/s   | next 30 s: 14 samples, path 144.2 m, ends [2143.2, 190.1]
    t 149.94 s  [2218.9, 224.6] -> [1677.5, 582.9]  649.2 m in 2.03 s = 319.8 m/s   | next 30 s: 14 samples, path 240.2 m, ends [1801.3, 456.8]
    t 186.43 s  [1828.1, 443.5] -> [1661.1, 717.2]  320.6 m in 2.03 s = 157.9 m/s   | next 30 s: 14 samples, path 1351.0 m, ends [943.6, 355.5]
    t 196.56 s  [1679.2, 606.0] -> [1287.5, 424.1]  431.9 m in 2.03 s = 212.7 m/s   | next 30 s: 14 samples, path 928.3 m, ends [814.0, 355.5]
    t 212.78 s  [1442.7, 603.6] -> [965.8, 355.8]  537.4 m in 2.03 s = 264.7 m/s   | next 30 s: 13 samples, path 240.4 m, ends [739.7, 312.2]
- traffic #20: 6 teleports (raw >30 m count 24)
    t 42.56 s  [979.0, -247.8] -> [1860.3, -451.2]  904.5 m in 2.02 s = 447.8 m/s   | next 30 s: 14 samples, path 1355.8 m, ends [2328.8, -137.8]
    t 54.72 s  [1703.9, -446.3] -> [2196.5, -594.0]  514.3 m in 2.03 s = 253.3 m/s   | next 30 s: 14 samples, path 683.9 m, ends [2328.5, -134.7]
    t 68.89 s  [2047.5, -554.5] -> [2330.4, -125.9]  513.5 m in 2.02 s = 254.2 m/s   | next 30 s: 14 samples, path 49.4 m, ends [2336.0, -104.8]
    t 107.38 s  [2332.9, -106.9] -> [1942.4, 343.4]  596.0 m in 2.03 s = 293.6 m/s   | next 30 s: 14 samples, path 162.1 m, ends [1978.9, 252.4]
    t 154.00 s  [2012.8, 210.1] -> [1815.0, 449.9]  310.9 m in 2.03 s = 153.1 m/s   | next 30 s: 14 samples, path 61.1 m, ends [1782.1, 452.7]
    t 196.56 s  [1859.0, 415.2] -> [1233.1, 384.3]  626.7 m in 2.03 s = 308.7 m/s   | next 30 s: 14 samples, path 481.2 m, ends [766.8, 330.9]
- traffic #21: 6 teleports (raw >30 m count 26)
    t 40.54 s  [355.5, -1367.7] -> [1997.9, -532.6]  1842.5 m in 2.03 s = 907.6 m/s   | next 30 s: 14 samples, path 922.9 m, ends [2325.3, -453.6]
    t 56.73 s  [1761.2, -436.6] -> [2231.4, -584.2]  492.8 m in 2.01 s = 245.2 m/s   | next 30 s: 14 samples, path 380.3 m, ends [2337.5, -242.3]
    t 105.35 s  [2325.5, -135.0] -> [2165.8, 196.1]  367.6 m in 2.03 s = 181.1 m/s   | next 30 s: 14 samples, path 569.5 m, ends [1927.2, 356.3]
    t 117.52 s  [2167.3, 196.8] -> [1822.6, 449.7]  427.5 m in 2.02 s = 211.6 m/s   | next 30 s: 14 samples, path 212.7 m, ends [1976.6, 304.8]
    t 162.11 s  [1973.6, 310.9] -> [1687.7, 530.8]  360.7 m in 2.02 s = 178.6 m/s   | next 30 s: 14 samples, path 376.6 m, ends [1516.7, 689.3]
    t 212.78 s  [1426.0, 595.2] -> [1096.7, 359.2]  405.1 m in 2.03 s = 199.6 m/s   | next 30 s: 13 samples, path 258.0 m, ends [838.9, 352.8]
- traffic #22: 6 teleports (raw >30 m count 27)
    t 58.76 s  [1834.5, -442.7] -> [2258.2, -537.4]  434.2 m in 2.03 s = 213.9 m/s   | next 30 s: 14 samples, path 390.7 m, ends [2336.3, -181.5]
    t 105.35 s  [2334.5, -135.0] -> [2088.8, 184.7]  403.2 m in 2.03 s = 198.6 m/s   | next 30 s: 14 samples, path 361.6 m, ends [2323.0, 66.0]
    t 145.88 s  [2334.5, -19.9] -> [1889.7, 388.4]  603.8 m in 2.02 s = 298.9 m/s   | next 30 s: 14 samples, path 529.3 m, ends [1677.8, 584.5]
    t 172.24 s  [1929.8, 357.6] -> [1682.2, 628.0]  366.6 m in 2.02 s = 181.5 m/s   | next 30 s: 14 samples, path 550.1 m, ends [1324.2, 478.7]
    t 192.50 s  [1672.4, 495.9] -> [1414.2, 574.4]  269.9 m in 2.03 s = 132.9 m/s   | next 30 s: 14 samples, path 321.3 m, ends [1182.5, 356.2]
    t 224.94 s  [1174.6, 356.0] -> [724.9, 150.5]  494.4 m in 2.02 s = 244.8 m/s   | next 30 s: 7 samples, path 129.2 m, ends [799.9, 53.4]
- traffic #23: 7 teleports (raw >30 m count 7)
    t 42.56 s  [1523.6, 4.5] -> [2149.5, -587.4]  861.5 m in 2.02 s = 426.5 m/s   | next 30 s: 14 samples, path 997.2 m, ends [2331.1, -258.5]
    t 44.58 s  [2149.5, -587.4] -> [1964.6, -513.9]  199.0 m in 2.02 s = 98.5 m/s   | next 30 s: 14 samples, path 816.9 m, ends [2338.0, -241.1]
    t 58.76 s  [1826.5, -439.6] -> [2327.6, -396.3]  503.0 m in 2.03 s = 247.8 m/s   | next 30 s: 14 samples, path 243.0 m, ends [2331.4, -157.7]
    t 109.40 s  [2346.8, -51.3] -> [1830.7, 439.3]  712.1 m in 2.02 s = 352.5 m/s   | next 30 s: 14 samples, path 140.0 m, ends [1939.1, 350.9]
    t 164.14 s  [1973.9, 319.3] -> [1564.3, 698.3]  558.0 m in 2.03 s = 274.9 m/s   | next 30 s: 14 samples, path 301.9 m, ends [1674.6, 531.8]
    t 194.53 s  [1674.6, 531.8] -> [1458.8, 653.1]  247.6 m in 2.03 s = 121.9 m/s   | next 30 s: 14 samples, path 566.1 m, ends [1000.9, 358.7]
    t 214.80 s  [1377.3, 531.1] -> [1043.4, 359.2]  375.6 m in 2.02 s = 185.9 m/s   | next 30 s: 12 samples, path 195.2 m, ends [848.3, 359.3]
- traffic #24: 7 teleports (raw >30 m count 26)
    t 40.54 s  [913.6, -190.7] -> [2162.8, -603.4]  1315.6 m in 2.03 s = 648.1 m/s   | next 30 s: 14 samples, path 1690.1 m, ends [2338.3, -173.2]
    t 46.61 s  [2216.0, -603.6] -> [1864.0, -449.2]  384.4 m in 2.03 s = 189.3 m/s   | next 30 s: 14 samples, path 1283.8 m, ends [2329.8, -142.4]
    t 54.72 s  [1757.7, -431.4] -> [2075.8, -568.0]  346.2 m in 2.03 s = 170.5 m/s   | next 30 s: 14 samples, path 828.1 m, ends [2330.0, -141.7]
    t 68.89 s  [1861.9, -447.8] -> [2338.3, -173.2]  549.9 m in 2.02 s = 272.2 m/s   | next 30 s: 14 samples, path 133.9 m, ends [2343.4, -43.2]
    t 109.40 s  [2333.6, -15.5] -> [1873.7, 403.6]  622.2 m in 2.02 s = 308.0 m/s   | next 30 s: 14 samples, path 150.5 m, ends [1981.2, 300.8]
    t 162.11 s  [1984.0, 283.6] -> [1689.7, 673.5]  488.5 m in 2.02 s = 241.8 m/s   | next 30 s: 14 samples, path 217.5 m, ends [1677.6, 459.7]
    t 194.53 s  [1680.0, 456.8] -> [1378.7, 527.4]  309.5 m in 2.03 s = 152.4 m/s   | next 30 s: 14 samples, path 312.4 m, ends [1134.4, 356.2]
- traffic #25: 8 teleports (raw >30 m count 24)
    t 40.54 s  [114.6, 227.8] -> [1820.3, -441.7]  1832.4 m in 2.03 s = 902.7 m/s   | next 30 s: 14 samples, path 688.7 m, ends [2322.7, -325.6]
    t 68.89 s  [2144.9, -596.1] -> [2322.7, -325.6]  323.7 m in 2.02 s = 160.2 m/s   | next 30 s: 14 samples, path 2121.2 m, ends [2323.2, 64.1]
    t 76.99 s  [2322.4, -363.0] -> [2265.7, 219.2]  585.0 m in 2.03 s = 288.2 m/s   | next 30 s: 14 samples, path 1498.8 m, ends [2323.2, 64.1]
    t 83.06 s  [2308.4, 176.6] -> [2240.1, -570.8]  750.5 m in 2.03 s = 369.7 m/s   | next 30 s: 14 samples, path 1105.8 m, ends [1980.5, 257.0]
    t 85.08 s  [2240.1, -570.8] -> [2323.0, 87.6]  663.6 m in 2.02 s = 328.5 m/s   | next 30 s: 14 samples, path 454.1 m, ends [1983.0, 245.3]
    t 107.38 s  [2323.2, 64.1] -> [1981.3, 274.3]  401.3 m in 2.03 s = 197.7 m/s   | next 30 s: 14 samples, path 125.0 m, ends [2044.0, 194.7]
    t 147.91 s  [2094.4, 188.6] -> [1744.1, 464.7]  446.0 m in 2.03 s = 219.7 m/s   | next 30 s: 14 samples, path 247.9 m, ends [1697.6, 661.5]
    t 208.72 s  [1479.3, 682.3] -> [1097.5, 356.0]  502.2 m in 2.02 s = 248.6 m/s   | next 30 s: 14 samples, path 348.1 m, ends [757.6, 330.9]
- traffic #26: 8 teleports (raw >30 m count 27)
    t 42.56 s  [1171.7, 355.9] -> [1953.2, -522.1]  1175.4 m in 2.02 s = 581.9 m/s   | next 30 s: 14 samples, path 463.1 m, ends [2326.8, -466.7]
    t 76.99 s  [2324.8, -420.7] -> [2309.5, 174.7]  595.6 m in 2.03 s = 293.4 m/s   | next 30 s: 14 samples, path 1528.8 m, ends [2323.2, 78.7]
    t 83.06 s  [2322.0, 121.3] -> [2219.8, -594.3]  722.9 m in 2.03 s = 356.1 m/s   | next 30 s: 14 samples, path 1149.5 m, ends [1989.0, 240.1]
    t 85.08 s  [2219.8, -594.3] -> [2320.8, 114.1]  715.6 m in 2.02 s = 354.2 m/s   | next 30 s: 14 samples, path 456.4 m, ends [2003.8, 223.2]
    t 107.38 s  [2323.2, 78.7] -> [1982.6, 253.9]  383.0 m in 2.03 s = 188.7 m/s   | next 30 s: 14 samples, path 160.0 m, ends [2114.2, 184.9]
    t 149.94 s  [2178.4, 203.2] -> [1796.3, 453.8]  456.9 m in 2.03 s = 225.1 m/s   | next 30 s: 14 samples, path 46.6 m, ends [1821.9, 440.9]
    t 186.43 s  [1821.9, 441.0] -> [1671.3, 726.6]  322.9 m in 2.03 s = 159.1 m/s   | next 30 s: 14 samples, path 779.0 m, ends [1029.2, 359.3]
    t 208.72 s  [1499.0, 683.5] -> [1117.7, 359.1]  500.6 m in 2.02 s = 247.8 m/s   | next 30 s: 14 samples, path 330.0 m, ends [788.7, 349.5]
- traffic #27: 11 teleports (raw >30 m count 30)
    t 42.56 s  [1967.5, 335.1] -> [2239.9, -551.3]  927.3 m in 2.02 s = 459.1 m/s   | next 30 s: 14 samples, path 950.2 m, ends [2334.1, -268.2]
    t 48.64 s  [2188.5, -597.7] -> [1952.8, -521.9]  247.6 m in 2.03 s = 122.0 m/s   | next 30 s: 14 samples, path 716.8 m, ends [2337.3, -183.3]
    t 70.92 s  [2200.5, -607.0] -> [2334.1, -268.2]  364.2 m in 2.03 s = 179.4 m/s   | next 30 s: 14 samples, path 151.0 m, ends [2330.3, -122.9]
    t 105.35 s  [2331.6, -119.2] -> [2140.7, 189.4]  362.9 m in 2.03 s = 178.8 m/s   | next 30 s: 14 samples, path 1184.1 m, ends [2223.1, 230.5]
    t 119.55 s  [2152.1, 190.1] -> [1723.4, 461.2]  507.2 m in 2.03 s = 249.9 m/s   | next 30 s: 14 samples, path 791.4 m, ends [2105.5, 195.7]
    t 129.68 s  [1686.7, 475.4] -> [1820.5, 451.3]  136.0 m in 2.03 s = 67.0 m/s   | next 30 s: 14 samples, path 1057.2 m, ends [1861.7, 418.2]
    t 131.70 s  [1820.5, 451.3] -> [2236.5, 230.9]  470.8 m in 2.02 s = 233.1 m/s   | next 30 s: 14 samples, path 593.8 m, ends [1856.0, 422.8]
    t 149.94 s  [2105.5, 195.7] -> [1814.8, 453.2]  388.3 m in 2.03 s = 191.3 m/s   | next 30 s: 14 samples, path 639.3 m, ends [1463.9, 638.1]
- traffic #28: 6 teleports (raw >30 m count 22)
    t 44.58 s  [2165.7, 207.5] -> [1871.2, -460.8]  730.3 m in 2.02 s = 361.5 m/s   | next 30 s: 14 samples, path 1339.1 m, ends [2347.9, -62.9]
    t 56.73 s  [1805.2, -435.8] -> [2311.2, -469.3]  507.1 m in 2.01 s = 252.3 m/s   | next 30 s: 14 samples, path 803.1 m, ends [2336.5, -22.5]
    t 72.94 s  [2170.7, -591.0] -> [2347.9, -62.9]  557.0 m in 2.02 s = 275.8 m/s   | next 30 s: 14 samples, path 52.6 m, ends [2333.9, -12.8]
    t 109.40 s  [2333.3, -11.1] -> [1944.1, 342.4]  525.8 m in 2.02 s = 260.3 m/s   | next 30 s: 14 samples, path 113.2 m, ends [1981.0, 276.9]
    t 162.11 s  [1977.8, 288.1] -> [1683.5, 651.7]  467.8 m in 2.02 s = 231.6 m/s   | next 30 s: 14 samples, path 278.8 m, ends [1771.8, 457.7]
    t 196.56 s  [1820.0, 447.0] -> [1290.2, 441.0]  529.8 m in 2.03 s = 261.0 m/s   | next 30 s: 14 samples, path 286.9 m, ends [1034.7, 358.5]
- traffic #29: 5 teleports (raw >30 m count 25)
    t 42.56 s  [1333.3, 482.5] -> [2066.7, -579.1]  1290.3 m in 2.02 s = 638.8 m/s   | next 30 s: 14 samples, path 864.3 m, ends [2327.7, -308.8]
    t 62.81 s  [1889.2, -471.6] -> [2325.4, -437.3]  437.5 m in 2.02 s = 216.6 m/s   | next 30 s: 14 samples, path 290.8 m, ends [2326.6, -149.2]
    t 105.35 s  [2328.8, -119.8] -> [2175.4, 207.7]  361.6 m in 2.03 s = 178.2 m/s   | next 30 s: 14 samples, path 469.7 m, ends [1882.5, 394.7]
    t 117.52 s  [2175.2, 207.6] -> [1838.4, 437.6]  407.8 m in 2.02 s = 201.9 m/s   | next 30 s: 14 samples, path 132.0 m, ends [1938.1, 351.7]
    t 170.22 s  [1945.0, 349.1] -> [1563.1, 714.8]  528.8 m in 2.02 s = 261.8 m/s   | next 30 s: 14 samples, path 362.5 m, ends [1314.8, 469.5]
- %d jumps in total. I: per-idx carpos rows are NOT one continuous car (a slot gets
  re-used/respawned far away, the same thing the FREE tmove deltas show), so read
  these as slot resets, not as one car teleporting. NV: the log cannot tell a real
  reset from slot re-use, they look identical here.

## 4. Falls (z drop > 5 m inside one sample gap)
- COLLOG f4800->5100 (300 frames, 4.8 s): z 68.0 -> 60.0 (drop 8.0 m) at [2307.0, -491.0], sp 31.1 -> 49.3  [coarse: COLLOG rows are 300 frames apart, so this bounds the drop, NV on the 2 s window]
- COLLOG f5100->5400 (300 frames, 5.19 s): z 60.0 -> 52.0 (drop 8.0 m) at [2329.0, -290.0], sp 49.3 -> 6.0  [coarse: COLLOG rows are 300 frames apart, so this bounds the drop, NV on the 2 s window]
- COLLOG f6900->7200 (300 frames, 5.24 s): z 63.0 -> 51.0 (drop 12.0 m) at [2324.0, 139.0], sp 38.3 -> 43.1  [coarse: COLLOG rows are 300 frames apart, so this bounds the drop, NV on the 2 s window]

## 5. Reset counter and wall pressure (COLLOG)
- f3300 reset 6141 -> 0 at pos [1685.0, -456.0, 64.0] sp 0.0

## 6. FREE tmove: per-name delta > 120 m over one row (reset/recycle, F)
- f2880 {'WART': -306.0, 'EDDIE': -304.6, 'STAN': -304.5, 'WU': -304.4, 'SAMANTHA': -304.3}
- f3000 {'WART': -306.0, 'EDDIE': -304.6, 'STAN': -304.5, 'WU': -304.4, 'SAMANTHA': -304.3}
- f3120 {'EDDIE': -420.2, 'WU': -418.6, 'SAMANTHA': -418.4}
- f3240 {'VINCE': 306.1, 'CARLA': 306.1, 'DIRT': 306.1}
- f3360 {'VINCE': 306.1, 'DIRT': 306.1, 'CARLA': 306.1}
- f3480 {'CARLA': 306.1, 'VINCE': 306.1, 'DIRT': 306.1}
- f3600 {'CARLA': 197.4, 'WU': 297.0}
- f3720 {'WU': 296.8, 'CARLA': 196.4}
- f3840 {'WU': 296.7, 'CARLA': 195.4}
- f3960 {'WU': 296.8, 'CARLA': 194.7}
- ... 10 more
```

## Siguiente medición que este log no puede dar (NV)

Para separar «reset real» de «slot reciclado» hace falta el id de coche junto a la posición:
`carpos` no lo escribe. Un `carpos <t> <idx> k<kind> <hex addr> x y` (o el `car id` de `AIT`)
resolvería §3 sin tocar Speed.exe.
