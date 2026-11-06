# resetscan en los ghosts del probe de reset: w_r_a y w_r_b (medido)

`git merge main` hecho en `bec/chela`; de ahí vienen `host/aitel.c` (probe `RN_RESETLOG`) y
`docs/re/reset_causes.md`. Read-only: esta herramienta solo lee el log. No corrí el juego, ni
Chrome, ni ghosts, ni compilé nada.

```
python3 tools/openworld/resetscan.py runs/w_r_a/log.txt
python3 tools/openworld/resetscan.py runs/w_r_b/log.txt
```

## Qué escriben las líneas nuevas (F: host/aitel.c)

- `RST f<frame> call <addr> car <hex> idx <n> pos x,y,z sp S head H dt D cache a/b/c/d` — se
  dispara al entrar a `0x427c50`/`0x427f70`: posición, z y velocidad **del momento del reset**.
- `RSTA f<frame> car ... pos ... dz +- moved .. sp .. cache ..` — primer frame después del call:
  `dz` = z de ahora − z del reset (m) y `moved` = distancia horizontal desde el punto del call.
- `RSTW f<frame> +<k> car ... pos ... dz +- moved .. sp .. cache .. [MOVED-WHILE-SLOW]` — cada
  10 frames hasta +120; `dz` es acumulado contra el reset y `moved` es el paso desde la muestra
  anterior. `MOVED-WHILE-SLOW` = se movió >3 m con sp<1 en las dos muestras (lo pone el probe).

## Cómo lo reporta `resetscan.py`

- une cada `RST` con su `RSTA` y su serie `RSTW` **por coche** (no por frame: en `w_r_a` hay 4
  resets en el mismo f3240 y unir por frame perdía tres).
- `dz@last` = `dz` de la última muestra (los 120 frames que pide el pedido), `dz min` = el peor.
- `frames stopped` = muestras `RSTW` con `sp < 1` × 10 frames.
- `longest` = la racha más larga seguida de muestras con `sp < 1` y paso < 1 m.
- banderas: **DZ-DRIFT** si `dz min < -2 m`; **STOPPED>60f AFTER X m** si el coche se alejó
  >30 m del punto del reset y después estuvo >60 frames parado en el mismo sitio;
  **MOVED-WHILE-SLOW** si el propio probe la marcó.

## Lo que salió

- **F**: `w_r_a` 25 resets, 9 con bandera; `w_r_b` 26 resets, 6 con bandera.
- **F**: `f3240` en `w_r_a` es una oleada de 4 resets en un solo frame con `sp 0.0` y la cache
  llena (52/52, 40/40, 40/38, 20/19). Los cuatro coches reaparecen 95 a 436 m más allá: es el
  reset de reubicación, no un tirón del jugador.
- **F**: deriva de z al reset es común y grande: `w_r_a` −15.46 m (idx 7, f3240) y −13.77 m
  (idx 16, f6780); `w_r_b` −16.30 m (idx 0, f4440) y −11.47 m (idx 25, f11460). El z que escribe
  el reset no es el z del suelo al que llega el coche.
- **F**: solo `w_r_a` tiene coches que quedan parados después del reset: idx 14 en f3240 se va a
  436 m y pasa 120 frames con `sp 0.0` y paso 0.00 (cache 27/26/1/0). En `w_r_b` no hay ningún
  caso de `STOPPED>60f`.
- **I**: `moved` del `RSTA` de 300 a 1200 m no es deriva: es el salto del propio reset (el call
  apunta al coche antes de reubicarlo). No lo cuento como drift, solo como distancia del reset.
- **NV**: este log no dice si la deriva de z es un fall-through o solo un desnivel de la calle;
  haría falta la z del suelo en el punto de destino, que el probe no escribe.

## Salida real: runs/w_r_a/log.txt

```
# resetscan runs/w_r_a/log.txt

## 1. In the log (F)
- 10680 lines, 2079 carpos rows, cars by kind: {'traffic': 21}
- carpos t window 40.50..239.14 s, sample gap median 2.03 s (carpos carries x,y only: no z, no speed)
- frames per second: 60.9 measured on AIP pairs, 59.5 by span ratio (I: no single line pairs a frame with a carpos t)
- polys max 8192 of polycap 8192 (1.0 of cap at the last TRAFLOG)

## 2. Still / embedded, per car (|dpos| < 0.5 m for > 6 s)
- traffic #9: 4 still episodes (0 with speed witness > 5 m/s)
    t 89.10..97.23 s, 5 samples, at [2343.8, -75.4], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
    t 123.58..131.69 s, 5 samples, at [2004.0, 222.9], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
    t 135.75..160.09 s, 13 samples, at [1998.2, 228.5], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
    t 170.23..180.37 s, 6 samples, at [1684.8, 498.7], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
- traffic #10: 2 still episodes (0 with speed witness > 5 m/s)
    t 125.61..158.05 s, 17 samples, at [2060.2, 185.9], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
    t 174.30..186.43 s, 7 samples, at [1688.2, 488.9], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
- traffic #11: 4 still episodes (2 with speed witness > 5 m/s)
    t 101.29..109.40 s, 5 samples, at [2321.1, 133.9], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
    t 115.47..123.58 s, 5 samples, at [2313.1, 149.7], witness speed 7.8 -> EMBEDDED (F for the position, I for the speed: the log has no per-row speed) [hit-wall f7540 115.4s]
    t 145.89..156.03 s, 6 samples, at [2128.5, 191.2], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
    t 164.15..172.26 s, 5 samples, at [1908.1, 370.3], witness speed 18.0 -> EMBEDDED (F for the position, I for the speed: the log has no per-row speed) [hit-car f10254 161.4s]
- traffic #12: 1 still episodes (0 with speed witness > 5 m/s)
    t 131.69..156.03 s, 13 samples, at [2090.7, 189.1], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
- traffic #13: 2 still episodes (0 with speed witness > 5 m/s)
    t 111.42..125.61 s, 8 samples, at [2121.6, 188.3], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
    t 131.69..156.03 s, 13 samples, at [2108.1, 189.4], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
- traffic #14: 1 still episodes (0 with speed witness > 5 m/s)
    t 147.93..160.09 s, 7 samples, at [2020.9, 208.2], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
- traffic #15: 3 still episodes (0 with speed witness > 5 m/s)
    t 93.17..103.32 s, 6 samples, at [2329.4, -3.2], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
    t 166.18..180.37 s, 8 samples, at [1687.4, 516.6], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
    t 182.39..188.46 s, 4 samples, at [1688.2, 523.7], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
- traffic #16: 2 still episodes (0 with speed witness > 5 m/s)
    t 115.47..123.58 s, 5 samples, at [2096.3, 186.5], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
    t 166.18..188.46 s, 12 samples, at [1688.0, 504.9], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
- traffic #17: 1 still episodes (0 with speed witness > 5 m/s)
    t 151.97..160.09 s, 5 samples, at [2037.3, 202.3], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
- traffic #18: 4 still episodes (0 with speed witness > 5 m/s)
    t 93.17..103.32 s, 6 samples, at [2326.8, 11.1], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
    t 117.50..123.58 s, 4 samples, at [2080.0, 184.7], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
    t 133.72..158.05 s, 13 samples, at [2074.0, 186.9], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
    t 210.76..218.86 s, 5 samples, at [1478.0, 647.0], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
- traffic #19: 4 still episodes (1 with speed witness > 5 m/s)
    t 50.63..56.72 s, 4 samples, at [2032.9, -562.8], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
    t 87.08..95.20 s, 5 samples, at [2340.3, -91.1], witness speed 16.3 -> EMBEDDED (F for the position, I for the speed: the log has no per-row speed) [hit-wall f5796 86.2s]
    t 129.66..135.75 s, 4 samples, at [1975.9, 269.0], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
    t 145.89..164.15 s, 10 samples, at [1978.4, 285.3], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
- traffic #20: 2 still episodes (0 with speed witness > 5 m/s)
    t 125.61..131.69 s, 4 samples, at [2111.3, 191.2], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
    t 133.72..156.03 s, 12 samples, at [2111.6, 193.3], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
- traffic #21: 3 still episodes (0 with speed witness > 5 m/s)
    t 99.26..109.40 s, 6 samples, at [2319.3, 136.2], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
    t 125.61..133.72 s, 5 samples, at [1988.2, 240.8], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
    t 139.82..162.12 s, 12 samples, at [1991.2, 241.5], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
- traffic #22: 2 still episodes (1 with speed witness > 5 m/s)
    t 101.29..109.40 s, 5 samples, at [2317.0, 144.9], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
    t 147.93..156.03 s, 5 samples, at [1980.5, 265.7], witness speed 16.5 -> EMBEDDED (F for the position, I for the speed: the log has no per-row speed) [hit-car f10035 157.7s]
- traffic #23: 1 still episodes (0 with speed witness > 5 m/s)
    t 137.79..160.09 s, 12 samples, at [2011.7, 218.5], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
- traffic #24: 2 still episodes (0 with speed witness > 5 m/s)
    t 123.58..129.66 s, 4 samples, at [2012.1, 216.4], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
    t 133.72..160.09 s, 14 samples, at [2009.0, 221.4], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
- traffic #25: 2 still episodes (0 with speed witness > 5 m/s)
    t 111.42..123.58 s, 7 samples, at [2110.4, 187.7], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
    t 125.61..156.03 s, 16 samples, at [2106.6, 191.2], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
- traffic #26: 4 still episodes (0 with speed witness > 5 m/s)
    t 91.14..97.23 s, 4 samples, at [2336.9, -118.3], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
    t 123.58..131.69 s, 5 samples, at [1991.9, 230.2], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
    t 135.75..162.12 s, 14 samples, at [1992.5, 234.1], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
    t 176.32..186.43 s, 6 samples, at [1688.2, 472.6], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
- traffic #27: 1 still episodes (0 with speed witness > 5 m/s)
    t 151.97..160.09 s, 5 samples, at [2052.6, 198.6], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
- traffic #28: 1 still episodes (1 with speed witness > 5 m/s)
    t 143.87..154.00 s, 6 samples, at [1978.3, 251.5], witness speed 16.5 -> EMBEDDED (F for the position, I for the speed: the log has no per-row speed) [hit-car f10035 157.7s]
- traffic #29: 2 still episodes (0 with speed witness > 5 m/s)
    t 131.69..162.12 s, 16 samples, at [1995.0, 233.5], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
    t 180.37..186.43 s, 4 samples, at [1674.4, 526.7], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)

## 3. Teleports (> 30 m between samples, implied speed > 60 m/s)
- traffic #9: 6 teleports (raw >30 m count 16)
    t 42.53 s  [526.2, -998.8] -> [1911.5, -497.5]  1473.2 m in 2.03 s = 725.7 m/s   | next 30 s: 14 samples, path 338.3 m, ends [2224.4, -595.4]
    t 87.08 s  [2277.5, -504.8] -> [2344.5, -70.4]  439.5 m in 2.02 s = 217.6 m/s   | next 30 s: 14 samples, path 674.3 m, ends [1981.4, 287.2]
    t 107.37 s  [2344.8, -67.9] -> [1945.9, 342.8]  572.5 m in 2.02 s = 283.4 m/s   | next 30 s: 14 samples, path 148.2 m, ends [1998.2, 228.5]
    t 162.12 s  [1998.2, 228.5] -> [1698.3, 461.1]  379.5 m in 2.03 s = 187.0 m/s   | next 30 s: 14 samples, path 150.3 m, ends [1686.3, 603.0]
    t 192.51 s  [1686.3, 603.0] -> [1154.9, 352.8]  587.4 m in 2.02 s = 290.8 m/s   | next 30 s: 14 samples, path 574.8 m, ends [1178.7, 352.8]
    t 206.71 s  [1123.3, 352.7] -> [1294.8, 445.5]  195.0 m in 2.03 s = 96.1 m/s   | next 30 s: 14 samples, path 262.8 m, ends [1067.8, 358.0]
- traffic #10: 8 teleports (raw >30 m count 22)
    t 42.53 s  [855.7, -131.3] -> [1930.1, -496.2]  1134.7 m in 2.03 s = 559.0 m/s   | next 30 s: 14 samples, path 978.7 m, ends [2337.8, -184.8]
    t 56.72 s  [1761.8, -434.6] -> [2328.1, -410.3]  566.8 m in 2.02 s = 280.6 m/s   | next 30 s: 14 samples, path 1058.0 m, ends [2345.4, -201.8]
    t 74.94 s  [2329.5, -153.5] -> [2303.7, -486.2]  333.7 m in 2.03 s = 164.4 m/s   | next 30 s: 14 samples, path 545.1 m, ends [2332.2, -124.4]
    t 85.06 s  [2242.1, -554.9] -> [2345.4, -201.8]  367.9 m in 2.03 s = 181.2 m/s   | next 30 s: 14 samples, path 557.7 m, ends [2032.7, 197.4]
    t 105.35 s  [2332.2, -124.4] -> [2017.3, 206.2]  456.6 m in 2.03 s = 224.9 m/s   | next 30 s: 14 samples, path 55.6 m, ends [2060.2, 185.9]
    t 160.09 s  [2059.9, 186.1] -> [1731.8, 464.7]  430.4 m in 2.04 s = 211.0 m/s   | next 30 s: 14 samples, path 367.2 m, ends [1387.7, 521.8]
    t 188.46 s  [1688.2, 488.9] -> [1387.7, 521.8]  302.3 m in 2.03 s = 148.9 m/s   | next 30 s: 14 samples, path 177.2 m, ends [1492.0, 659.9]
    t 220.89 s  [1484.9, 653.7] -> [948.9, 352.9]  614.6 m in 2.03 s = 302.8 m/s flags N   | next 30 s: 9 samples, path 175.3 m, ends [775.4, 341.4]
- traffic #11: 6 teleports (raw >30 m count 15)
    t 48.61 s  [1285.3, -605.0] -> [1878.0, -469.1]  608.1 m in 2.03 s = 299.5 m/s   | next 30 s: 14 samples, path 318.3 m, ends [2165.6, -595.9]
    t 83.03 s  [2180.4, -601.1] -> [2323.5, 34.2]  651.2 m in 2.02 s = 322.4 m/s   | next 30 s: 14 samples, path 166.1 m, ends [2318.3, 152.7]
    t 158.05 s  [2128.5, 191.2] -> [1872.2, 408.8]  336.2 m in 2.02 s = 166.4 m/s   | next 30 s: 14 samples, path 849.6 m, ends [1553.7, 704.1]
    t 174.30 s  [1908.1, 370.3] -> [1467.6, 662.5]  528.6 m in 2.04 s = 259.1 m/s   | next 30 s: 14 samples, path 352.0 m, ends [1473.0, 677.5]
    t 180.37 s  [1456.1, 641.4] -> [1606.5, 738.0]  178.8 m in 2.02 s = 88.5 m/s   | next 30 s: 14 samples, path 179.1 m, ends [1455.8, 653.1]
    t 222.93 s  [1425.4, 594.3] -> [980.6, 353.0]  506.0 m in 2.04 s = 248.1 m/s   | next 30 s: 8 samples, path 112.2 m, ends [868.7, 356.2]
- traffic #12: 6 teleports (raw >30 m count 23)
    t 44.55 s  [1670.9, -1790.4] -> [2040.8, -567.0]  1278.1 m in 2.02 s = 632.7 m/s   | next 30 s: 14 samples, path 219.7 m, ends [2243.4, -579.3]
    t 89.10 s  [2324.9, -455.4] -> [2317.8, 132.8]  588.2 m in 2.02 s = 291.2 m/s   | next 30 s: 14 samples, path 551.2 m, ends [2065.1, 188.2]
    t 105.35 s  [2323.3, 40.9] -> [1997.2, 229.6]  376.8 m in 2.03 s = 185.6 m/s   | next 30 s: 14 samples, path 107.6 m, ends [2090.7, 189.1]
    t 158.05 s  [2090.7, 189.1] -> [1733.3, 454.3]  445.0 m in 2.02 s = 220.3 m/s   | next 30 s: 14 samples, path 748.5 m, ends [1531.3, 679.2]
    t 176.32 s  [1883.8, 397.9] -> [1456.0, 627.0]  485.3 m in 2.02 s = 240.2 m/s flags N   | next 30 s: 14 samples, path 757.5 m, ends [1247.4, 398.7]
    t 198.60 s  [1659.5, 717.8] -> [1319.2, 471.2]  420.3 m in 2.03 s = 207.0 m/s   | next 30 s: 14 samples, path 436.8 m, ends [929.0, 359.0]
- traffic #13: 6 teleports (raw >30 m count 19)
    t 44.55 s  [1674.6, -1787.4] -> [2078.5, -568.8]  1283.8 m in 2.02 s = 635.5 m/s   | next 30 s: 14 samples, path 711.1 m, ends [2158.3, -583.6]
    t 60.77 s  [1863.8, -448.8] -> [2227.2, -582.6]  387.2 m in 2.03 s = 190.8 m/s   | next 30 s: 14 samples, path 542.0 m, ends [2336.3, -191.4]
    t 81.01 s  [2140.0, -575.6] -> [2336.4, -258.9]  372.7 m in 2.02 s = 184.5 m/s   | next 30 s: 14 samples, path 578.9 m, ends [2131.2, 193.2]
    t 103.32 s  [2325.7, -133.7] -> [2188.6, 221.9]  381.1 m in 2.03 s = 187.7 m/s   | next 30 s: 14 samples, path 90.8 m, ends [2108.0, 189.3]
    t 158.05 s  [2108.1, 189.4] -> [1782.1, 457.5]  422.1 m in 2.02 s = 209.0 m/s   | next 30 s: 14 samples, path 722.4 m, ends [1448.8, 635.5]
    t 174.30 s  [1897.6, 382.0] -> [1502.3, 687.2]  499.4 m in 2.04 s = 244.8 m/s   | next 30 s: 14 samples, path 297.3 m, ends [1313.3, 468.3]
- traffic #14: 3 teleports (raw >30 m count 28)
    t 42.53 s  [267.1, -1870.6] -> [1884.9, -461.0]  2145.8 m in 2.03 s = 1057.0 m/s   | next 30 s: 14 samples, path 982.8 m, ends [2339.6, -233.4]
    t 54.70 s  [1732.4, -437.7] -> [2325.0, -461.2]  593.1 m in 2.04 s = 290.7 m/s   | next 30 s: 14 samples, path 416.3 m, ends [2342.4, -49.6]
    t 162.12 s  [2020.9, 208.2] -> [1696.9, 696.4]  585.9 m in 2.03 s = 288.6 m/s   | next 30 s: 14 samples, path 289.9 m, ends [1456.2, 648.4]
- traffic #15: 7 teleports (raw >30 m count 26)
    t 42.53 s  [340.8, -1046.9] -> [2141.3, -576.2]  1861.0 m in 2.03 s = 916.8 m/s   | next 30 s: 14 samples, path 893.8 m, ends [2219.7, -585.8]
    t 60.77 s  [1872.3, -458.0] -> [2312.1, -467.0]  439.9 m in 2.03 s = 216.7 m/s   | next 30 s: 14 samples, path 785.3 m, ends [2331.8, -17.8]
    t 83.03 s  [2192.5, -594.3] -> [2335.6, -109.0]  506.0 m in 2.02 s = 250.5 m/s   | next 30 s: 14 samples, path 460.2 m, ends [2256.2, 222.1]
    t 105.35 s  [2329.4, -3.2] -> [2168.1, 194.1]  254.8 m in 2.03 s = 125.5 m/s   | next 30 s: 14 samples, path 250.9 m, ends [2322.9, 97.2]
    t 158.05 s  [2343.7, -56.7] -> [1677.6, 507.4]  872.9 m in 2.02 s = 432.1 m/s   | next 30 s: 14 samples, path 40.7 m, ends [1688.2, 523.7]
    t 192.51 s  [1688.4, 526.2] -> [1227.3, 383.5]  482.7 m in 2.02 s = 238.9 m/s   | next 30 s: 14 samples, path 534.5 m, ends [1243.7, 399.5]
    t 212.78 s  [1107.3, 355.9] -> [1299.2, 454.3]  215.7 m in 2.02 s = 106.8 m/s   | next 30 s: 13 samples, path 252.9 m, ends [1087.1, 353.2]
- traffic #16: 5 teleports (raw >30 m count 27)
    t 42.53 s  [464.4, -1907.7] -> [2039.8, -562.8]  2071.4 m in 2.03 s = 1020.4 m/s   | next 30 s: 14 samples, path 414.8 m, ends [2328.2, -414.8]
    t 105.35 s  [2335.9, -107.8] -> [2073.3, 187.9]  395.5 m in 2.03 s = 194.8 m/s   | next 30 s: 14 samples, path 74.5 m, ends [2146.6, 185.5]
    t 158.05 s  [2323.0, 91.9] -> [1688.4, 462.0]  734.6 m in 2.02 s = 363.7 m/s   | next 30 s: 14 samples, path 43.4 m, ends [1688.0, 504.9]
    t 190.49 s  [1688.0, 504.9] -> [1435.2, 597.4]  269.2 m in 2.03 s = 132.6 m/s   | next 30 s: 14 samples, path 743.4 m, ends [1105.9, 359.4]
    t 214.81 s  [1559.0, 695.0] -> [1178.2, 359.2]  507.7 m in 2.03 s = 250.1 m/s   | next 30 s: 12 samples, path 272.7 m, ends [905.5, 359.1]
- traffic #17: 3 teleports (raw >30 m count 10)
    t 87.08 s  [2311.8, -487.3] -> [2330.9, 120.9]  608.5 m in 2.02 s = 301.2 m/s   | next 30 s: 14 samples, path 152.1 m, ends [2243.5, 230.2]
    t 162.12 s  [2037.3, 202.3] -> [1690.5, 634.5]  554.1 m in 2.03 s = 273.0 m/s   | next 30 s: 14 samples, path 300.6 m, ends [1482.2, 683.8]
    t 224.94 s  [1389.2, 538.2] -> [850.2, 353.0]  569.9 m in 2.01 s = 283.5 m/s   | next 30 s: 7 samples, path 141.2 m, ends [730.6, 293.3]
- traffic #18: 6 teleports (raw >30 m count 16)
    t 44.55 s  [1172.9, -609.5] -> [1905.0, -492.7]  741.4 m in 2.02 s = 367.0 m/s   | next 30 s: 14 samples, path 301.0 m, ends [2179.9, -600.1]
    t 85.06 s  [2233.7, -583.6] -> [2323.0, 46.1]  636.0 m in 2.03 s = 313.3 m/s   | next 30 s: 14 samples, path 405.6 m, ends [2066.2, 185.7]
    t 105.35 s  [2326.8, 11.1] -> [2041.7, 189.1]  336.1 m in 2.03 s = 165.6 m/s   | next 30 s: 14 samples, path 72.6 m, ends [2074.0, 186.9]
    t 164.15 s  [2099.6, 185.2] -> [1678.1, 580.3]  577.7 m in 2.03 s = 284.6 m/s   | next 30 s: 14 samples, path 554.8 m, ends [1340.4, 475.1]
    t 192.51 s  [1720.1, 459.8] -> [1340.4, 475.1]  380.0 m in 2.02 s = 188.1 m/s   | next 30 s: 14 samples, path 678.8 m, ends [1124.5, 359.1]
    t 220.89 s  [1478.0, 647.0] -> [1124.5, 359.1]  455.9 m in 2.03 s = 224.6 m/s   | next 30 s: 9 samples, path 164.4 m, ends [960.2, 358.4]
- traffic #19: 5 teleports (raw >30 m count 18)
    t 44.55 s  [1684.8, 569.0] -> [1969.0, -524.3]  1129.6 m in 2.02 s = 559.2 m/s   | next 30 s: 14 samples, path 222.8 m, ends [2173.0, -604.2]
    t 87.08 s  [2259.3, -527.0] -> [2340.4, -90.8]  443.7 m in 2.02 s = 219.6 m/s   | next 30 s: 14 samples, path 648.4 m, ends [1984.5, 248.7]
    t 105.35 s  [2338.6, -98.7] -> [1969.4, 324.7]  561.8 m in 2.03 s = 276.7 m/s   | next 30 s: 14 samples, path 113.6 m, ends [1975.9, 269.0]
    t 168.21 s  [1978.2, 289.2] -> [1613.1, 725.7]  569.1 m in 2.03 s = 280.3 m/s   | next 30 s: 14 samples, path 659.1 m, ends [1270.4, 421.4]
    t 190.49 s  [1674.7, 559.5] -> [1334.2, 483.2]  348.9 m in 2.03 s = 171.9 m/s   | next 30 s: 14 samples, path 346.3 m, ends [1038.6, 353.2]
- traffic #20: 4 teleports (raw >30 m count 16)
    t 42.53 s  [328.5, -1429.6] -> [1837.3, -451.7]  1798.0 m in 2.03 s = 885.7 m/s   | next 30 s: 14 samples, path 289.3 m, ends [2092.5, -585.3]
    t 87.08 s  [2253.3, -553.0] -> [2328.5, 99.3]  656.6 m in 2.02 s = 325.1 m/s   | next 30 s: 14 samples, path 275.6 m, ends [2160.8, 196.5]
    t 158.05 s  [2111.6, 193.3] -> [1684.9, 500.6]  525.8 m in 2.02 s = 260.3 m/s   | next 30 s: 14 samples, path 325.8 m, ends [1586.5, 730.4]
    t 222.93 s  [1445.0, 627.3] -> [891.6, 355.7]  616.5 m in 2.04 s = 302.2 m/s   | next 30 s: 8 samples, path 154.0 m, ends [751.7, 316.1]
- traffic #21: 5 teleports (raw >30 m count 16)
    t 48.61 s  [2138.3, -582.1] -> [2018.3, -552.0]  123.7 m in 2.03 s = 60.9 m/s   | next 30 s: 14 samples, path 237.2 m, ends [2235.7, -578.9]
    t 87.08 s  [2283.7, -509.9] -> [2328.5, 76.0]  587.6 m in 2.02 s = 290.9 m/s   | next 30 s: 14 samples, path 508.2 m, ends [1970.0, 321.9]
    t 111.42 s  [2319.3, 136.2] -> [1950.9, 338.9]  420.5 m in 2.02 s = 208.2 m/s   | next 30 s: 14 samples, path 124.1 m, ends [1991.2, 241.5]
    t 164.15 s  [1991.2, 241.5] -> [1695.1, 639.9]  496.4 m in 2.03 s = 244.5 m/s   | next 30 s: 14 samples, path 287.7 m, ends [1497.8, 683.4]
    t 222.93 s  [1445.8, 620.0] -> [1046.5, 353.2]  480.2 m in 2.04 s = 235.4 m/s   | next 30 s: 8 samples, path 204.4 m, ends [842.3, 359.3]
- traffic #22: 5 teleports (raw >30 m count 6)
    t 48.61 s  [1330.7, -604.2] -> [2099.9, -587.5]  769.4 m in 2.03 s = 379.0 m/s   | next 30 s: 14 samples, path 275.9 m, ends [2316.0, -485.9]
    t 91.14 s  [2327.4, -356.7] -> [2269.3, 217.7]  577.3 m in 2.04 s = 283.0 m/s   | next 30 s: 14 samples, path 632.3 m, ends [1967.3, 323.1]
    t 111.42 s  [2317.0, 144.9] -> [1911.5, 374.1]  465.8 m in 2.02 s = 230.6 m/s   | next 30 s: 14 samples, path 149.5 m, ends [1980.8, 262.6]
    t 168.21 s  [1981.6, 277.6] -> [1574.4, 719.2]  600.7 m in 2.03 s = 295.9 m/s   | next 30 s: 14 samples, path 140.7 m, ends [1460.2, 649.0]
    t 226.96 s  [1331.7, 481.0] -> [770.8, 335.6]  579.4 m in 2.02 s = 286.9 m/s   | next 30 s: 6 samples, path 85.0 m, ends [723.2, 267.7]
- traffic #23: 8 teleports (raw >30 m count 13)
    t 60.77 s  [1857.5, -890.4] -> [2237.9, -558.4]  504.9 m in 2.03 s = 248.7 m/s   | next 30 s: 14 samples, path 581.4 m, ends [2340.3, -101.4]
    t 85.06 s  [2210.4, -584.1] -> [2333.3, -117.8]  482.2 m in 2.03 s = 237.5 m/s   | next 30 s: 14 samples, path 625.2 m, ends [2015.2, 212.2]
    t 105.35 s  [2338.6, -20.5] -> [1981.9, 266.5]  457.8 m in 2.03 s = 225.5 m/s   | next 30 s: 14 samples, path 144.3 m, ends [2018.5, 210.3]
    t 162.12 s  [2011.7, 218.5] -> [1674.1, 573.7]  490.0 m in 2.03 s = 241.4 m/s   | next 30 s: 14 samples, path 1490.5 m, ends [1334.2, 473.7]
    t 164.15 s  [1674.1, 573.7] -> [2014.6, 208.5]  499.3 m in 2.03 s = 246.0 m/s   | next 30 s: 14 samples, path 1018.7 m, ends [1353.9, 492.9]
    t 166.18 s  [2014.6, 208.5] -> [1679.2, 607.0]  520.9 m in 2.03 s = 256.6 m/s   | next 30 s: 14 samples, path 515.4 m, ends [1366.2, 505.3]
    t 190.49 s  [1674.7, 489.2] -> [1334.2, 473.7]  340.9 m in 2.03 s = 167.9 m/s   | next 30 s: 14 samples, path 209.2 m, ends [1443.2, 609.7]
    t 224.94 s  [1443.6, 611.7] -> [1080.8, 353.0]  445.6 m in 2.01 s = 221.7 m/s   | next 30 s: 7 samples, path 147.4 m, ends [933.4, 353.4]
- traffic #24: 7 teleports (raw >30 m count 24)
    t 42.53 s  [896.5, -191.6] -> [1862.3, -467.9]  1004.5 m in 2.03 s = 494.8 m/s   | next 30 s: 14 samples, path 422.6 m, ends [2241.6, -567.2]
    t 89.10 s  [2331.5, -421.3] -> [2289.3, 217.5]  640.2 m in 2.02 s = 316.9 m/s   | next 30 s: 14 samples, path 267.5 m, ends [2035.3, 203.0]
    t 162.12 s  [2009.0, 221.4] -> [1763.1, 457.6]  341.0 m in 2.03 s = 168.0 m/s flags N   | next 30 s: 14 samples, path 1223.0 m, ends [1422.9, 567.3]
    t 176.32 s  [1868.5, 409.6] -> [1413.5, 551.1]  476.5 m in 2.02 s = 235.9 m/s   | next 30 s: 14 samples, path 732.2 m, ends [1485.2, 651.9]
    t 180.37 s  [1425.0, 571.4] -> [1679.5, 630.3]  261.2 m in 2.02 s = 129.3 m/s   | next 30 s: 14 samples, path 456.3 m, ends [1491.9, 657.4]
    t 190.49 s  [1674.4, 542.9] -> [1422.9, 567.3]  252.7 m in 2.03 s = 124.5 m/s   | next 30 s: 14 samples, path 615.3 m, ends [1141.3, 355.9]
    t 218.86 s  [1506.2, 669.1] -> [1141.3, 355.9]  480.9 m in 2.02 s = 238.1 m/s   | next 30 s: 10 samples, path 245.6 m, ends [895.8, 353.0]
- traffic #25: 6 teleports (raw >30 m count 23)
    t 44.55 s  [1854.5, 423.3] -> [1828.7, -437.3]  861.0 m in 2.02 s = 426.2 m/s   | next 30 s: 14 samples, path 906.1 m, ends [2324.2, -335.3]
    t 54.70 s  [1722.6, -442.9] -> [2242.3, -565.8]  534.0 m in 2.04 s = 261.8 m/s   | next 30 s: 14 samples, path 432.9 m, ends [2329.6, -169.2]
    t 105.35 s  [2324.8, 9.1] -> [2097.1, 187.4]  289.2 m in 2.03 s = 142.5 m/s flags N   | next 30 s: 14 samples, path 26.6 m, ends [2106.6, 191.2]
    t 158.05 s  [2106.6, 191.2] -> [1823.5, 444.5]  379.9 m in 2.02 s = 188.1 m/s   | next 30 s: 14 samples, path 655.6 m, ends [1677.5, 550.1]
    t 172.26 s  [1928.6, 359.0] -> [1689.9, 673.6]  394.9 m in 2.03 s = 194.5 m/s   | next 30 s: 14 samples, path 542.5 m, ends [1332.7, 482.0]
    t 190.49 s  [1677.5, 546.4] -> [1437.6, 608.9]  247.9 m in 2.03 s = 122.1 m/s   | next 30 s: 14 samples, path 379.6 m, ends [1166.8, 356.0]
- traffic #26: 8 teleports (raw >30 m count 31)
    t 52.66 s  [1663.0, -372.9] -> [2201.1, -596.5]  582.7 m in 2.03 s = 287.0 m/s   | next 30 s: 14 samples, path 1365.7 m, ends [2341.6, -239.7]
    t 68.87 s  [1951.3, -505.5] -> [2337.0, -104.2]  556.6 m in 2.03 s = 274.2 m/s   | next 30 s: 14 samples, path 661.8 m, ends [2336.9, -118.3]
    t 70.89 s  [2337.0, -104.2] -> [2332.3, -440.7]  336.5 m in 2.02 s = 166.6 m/s   | next 30 s: 14 samples, path 335.2 m, ends [2339.0, -108.5]
    t 105.35 s  [2342.2, -88.0] -> [1980.0, 306.7]  535.7 m in 2.03 s = 263.9 m/s   | next 30 s: 14 samples, path 89.1 m, ends [1993.7, 231.2]
    t 164.15 s  [1992.5, 234.1] -> [1733.1, 464.5]  346.9 m in 2.03 s = 170.9 m/s   | next 30 s: 14 samples, path 381.9 m, ends [1465.5, 643.4]
    t 188.46 s  [1688.2, 472.6] -> [1438.7, 603.7]  281.8 m in 2.03 s = 138.8 m/s   | next 30 s: 14 samples, path 715.0 m, ends [1416.5, 556.6]
    t 210.76 s  [1613.7, 725.4] -> [1335.4, 470.1]  377.7 m in 2.02 s = 187.0 m/s   | next 30 s: 14 samples, path 910.1 m, ends [745.5, 314.0]
    t 222.93 s  [1436.0, 591.8] -> [862.8, 356.1]  619.8 m in 2.04 s = 303.8 m/s   | next 30 s: 8 samples, path 131.2 m, ends [745.5, 314.0]
- traffic #27: 7 teleports (raw >30 m count 22)
    t 42.53 s  [974.3, -258.7] -> [1989.5, -531.6]  1051.2 m in 2.03 s = 517.9 m/s   | next 30 s: 14 samples, path 953.2 m, ends [2187.3, -597.2]
    t 56.72 s  [1787.9, -428.4] -> [2318.0, -471.7]  531.9 m in 2.02 s = 263.3 m/s   | next 30 s: 14 samples, path 849.8 m, ends [2345.7, -48.2]
    t 78.99 s  [2115.1, -577.7] -> [2332.1, -146.4]  482.8 m in 2.03 s = 237.8 m/s   | next 30 s: 14 samples, path 277.7 m, ends [2326.1, 127.7]
    t 162.12 s  [2052.6, 198.6] -> [1679.6, 632.5]  572.2 m in 2.03 s = 281.9 m/s   | next 30 s: 14 samples, path 187.9 m, ends [1692.0, 457.1]
    t 192.51 s  [1692.0, 457.1] -> [1265.0, 420.6]  428.6 m in 2.02 s = 212.2 m/s   | next 30 s: 14 samples, path 1345.8 m, ends [1216.1, 367.9]
    t 208.74 s  [1146.7, 352.8] -> [1665.9, 714.1]  632.5 m in 2.03 s = 311.6 m/s   | next 30 s: 14 samples, path 717.4 m, ends [1071.6, 353.2]
    t 210.76 s  [1665.9, 714.1] -> [1287.7, 438.3]  468.1 m in 2.02 s = 231.7 m/s   | next 30 s: 14 samples, path 285.3 m, ends [1035.6, 353.2]
- traffic #28: 7 teleports (raw >30 m count 38)
    t 42.53 s  [344.6, -1382.6] -> [2035.3, -548.5]  1885.3 m in 2.03 s = 928.7 m/s   | next 30 s: 14 samples, path 968.7 m, ends [2344.8, -224.6]
    t 58.74 s  [1813.4, -433.1] -> [2328.4, -424.8]  515.1 m in 2.02 s = 255.0 m/s   | next 30 s: 14 samples, path 748.0 m, ends [2340.1, -236.5]
    t 76.96 s  [2333.4, -153.9] -> [2328.7, -431.6]  277.7 m in 2.02 s = 137.5 m/s   | next 30 s: 14 samples, path 704.2 m, ends [2139.3, 196.3]
    t 103.32 s  [2329.5, -141.8] -> [2167.4, 203.4]  381.4 m in 2.03 s = 187.9 m/s   | next 30 s: 14 samples, path 162.2 m, ends [2011.2, 215.4]
    t 168.21 s  [1976.7, 269.7] -> [1685.2, 696.4]  516.8 m in 2.03 s = 254.6 m/s   | next 30 s: 14 samples, path 595.7 m, ends [1437.1, 600.9]
    t 190.49 s  [1677.7, 508.3] -> [1376.6, 515.7]  301.2 m in 2.03 s = 148.4 m/s   | next 30 s: 14 samples, path 898.2 m, ends [1008.5, 359.1]
    t 218.86 s  [1554.3, 691.9] -> [1008.5, 359.1]  639.3 m in 2.02 s = 316.5 m/s   | next 30 s: 10 samples, path 295.8 m, ends [734.0, 302.5]
- traffic #29: 5 teleports (raw >30 m count 35)
    t 58.74 s  [1864.0, -457.3] -> [2201.7, -593.4]  364.1 m in 2.02 s = 180.2 m/s   | next 30 s: 14 samples, path 823.3 m, ends [2332.0, -177.7]
    t 72.91 s  [1996.1, -531.6] -> [2325.5, -439.4]  342.1 m in 2.02 s = 169.3 m/s   | next 30 s: 14 samples, path 415.6 m, ends [2335.1, -28.3]
    t 105.35 s  [2333.8, -19.8] -> [1982.4, 245.0]  440.0 m in 2.03 s = 216.7 m/s   | next 30 s: 14 samples, path 87.3 m, ends [1995.0, 233.5]
    t 164.15 s  [1995.0, 233.5] -> [1689.5, 673.1]  535.3 m in 2.03 s = 263.7 m/s   | next 30 s: 14 samples, path 518.1 m, ends [1320.6, 475.1]
    t 190.49 s  [1674.4, 521.1] -> [1346.2, 500.4]  328.9 m in 2.03 s = 162.0 m/s   | next 30 s: 14 samples, path 363.6 m, ends [1039.3, 355.9]
- %d jumps in total. I: per-idx carpos rows are NOT one continuous car (a slot gets
  re-used/respawned far away, the same thing the FREE tmove deltas show), so read
  these as slot resets, not as one car teleporting. NV: the log cannot tell a real
  reset from slot re-use, they look identical here.

## 4. Falls (z drop > 5 m inside one sample gap)
- COLLOG f5700->6000 (300 frames, 5.71 s): z 66.0 -> 53.0 (drop 13.0 m) at [2332.0, -425.0], sp 39.2 -> 32.8  [coarse: COLLOG rows are 300 frames apart, so this bounds the drop, NV on the 2 s window]
- COLLOG f6900->7200 (300 frames, 5.46 s): z 61.0 -> 51.0 (drop 10.0 m) at [2304.0, 190.0], sp 33.2 -> 32.4  [coarse: COLLOG rows are 300 frames apart, so this bounds the drop, NV on the 2 s window]

## 5. Reset counter and wall pressure (COLLOG)
- f3300 reset 6274 -> 0 at pos [1685.0, -456.0, 64.0] sp 0.0
- walls at peak: 1 rows, first f3000 walls 15 at peak 15 (F; a sustained cap is the wall pool, not a fall)

## 6. Reset events: RST -> RSTA -> RSTW (probe, F)
- 25 reset calls, watch 120 frames after each (RSTW every 10 frames)
- dz = z(now) - z(at the reset call); frames stopped = RSTW samples with sp<1 x10

  frame  idx car       sp0  dz@last  dz min  moved max  stopped  longest  flags
   3240    7 016d1a30   0.0   -15.46  -15.46      95.5      100       10  DZ-DRIFT -15.46
   3240   10 016d66a0   0.0    +1.41   +1.39     163.5       90       90  STOPPED>60f AFTER 163 m
   3240   11 016d2dd0   0.0    +1.93   +1.67     245.4      100       90  STOPPED>60f AFTER 245 m
   3240   14 0286aec0   0.0    -8.71   -8.71     435.8      120      120  DZ-DRIFT -8.71, STOPPED>60f AFTER 436 m
   4140    0 027ec1c0  33.8    -2.31   -2.31     663.9        0        0  DZ-DRIFT -2.31
   4440    0 027dff00  28.0    +0.87   +0.68     639.2        0        0  
   5160   29 027dff00  28.4   +16.75  +16.69     609.9        0        0  
   5340    0 0286aec0  21.9    +7.24   +7.24     198.0        0        0  
   5400    0 0276ff10  21.4    +1.71   +1.71     562.0        0        0  
   5640    0 027dff00  28.5    +9.87   +7.08     246.9        0        0  
   6780   16 027dff00  30.7   -13.73  -13.77     207.4        0        0  DZ-DRIFT -13.77
   9600    1 016d1a30  28.0   +10.33  +10.30     740.7        0        0  
   9720    0 0276e790  50.0    -4.15   -4.15     725.5        0        0  DZ-DRIFT -4.15
  10140   29 016d1a30  32.4    +0.62   +0.54     342.7        0        0  
  10920   29 016d2dd0   1.9    +0.24   +0.19     139.9       30       30  
  10980   29 016d1a30  19.3    -0.18   -0.23     192.5        0        0  
  11220   29 0276e790  21.4    +0.48   +0.45     167.3       20       20  
  12060    0 027ec1c0  17.1    +3.57   +3.57     567.8        0        0  
  12120    1 0286aec0  19.4    +4.61   +4.61     502.2        0        0  
  12540   22 0276ff10  27.6    -8.12   -8.90     510.9        0        0  DZ-DRIFT -8.90
  12720   27 016d2dd0  26.8    +0.91   +0.59     262.4        0        0  
  12840   28 027dff00  15.4    -0.58   -0.74     436.8        0        0  
  13080   29 016d1a30  31.8    +0.50   -0.34     385.5        0        0  
  13440   27 0276e790  30.6    -8.64   -8.91     501.1        0        0  DZ-DRIFT -8.91
  14100   28 027dff00  23.0    -1.23   -1.24      38.6        0        0  

- 9 of 25 events flagged
  f3240 idx 7 016d1a30: DZ-DRIFT -15.46 | sp0 0.0, dz@+120 -15.46, RSTA moved 95.5 sp 24.1, cache (52, 52, 0, 0)
  f3240 idx 10 016d66a0: STOPPED>60f AFTER 163 m | sp0 0.0, dz@+120 +1.41, RSTA moved 163.5 sp 24.1, cache (40, 40, 0, 0)
  f3240 idx 11 016d2dd0: STOPPED>60f AFTER 245 m | sp0 0.0, dz@+120 +1.93, RSTA moved 245.4 sp 24.1, cache (40, 38, 2, 0)
  f3240 idx 14 0286aec0: DZ-DRIFT -8.71, STOPPED>60f AFTER 436 m | sp0 0.0, dz@+120 -8.71, RSTA moved 435.8 sp 24.1, cache (20, 19, 1, 0)
  f4140 idx 0 027ec1c0: DZ-DRIFT -2.31 | sp0 33.8, dz@+120 -2.31, RSTA moved 663.9 sp 33.0, cache (23, 21, 2, 0)
  f6780 idx 16 027dff00: DZ-DRIFT -13.77 | sp0 30.7, dz@+120 -13.73, RSTA moved 207.4 sp 19.2, cache (30, 30, 0, 0)
  f9720 idx 0 0276e790: DZ-DRIFT -4.15 | sp0 50.0, dz@+120 -4.15, RSTA moved 725.5 sp 8.1, cache (25, 19, 6, 0)
  f12540 idx 22 0276ff10: DZ-DRIFT -8.90 | sp0 27.6, dz@+120 -8.12, RSTA moved 510.9 sp 19.1, cache (17, 13, 4, 0)
  f13440 idx 27 0276e790: DZ-DRIFT -8.91 | sp0 30.6, dz@+120 -8.64, RSTA moved 501.1 sp 8.1, cache (21, 15, 6, 0)

## 7. FREE tmove: per-name delta > 120 m over one row (reset/recycle, F)
- f2880 {'TODD': -195.7, 'CARL': -137.3, 'VINCE': -193.1}
- f3000 {'TODD': -306.0, 'SKID': -304.6, 'CARL': -304.5, 'EDDIE': -304.4, 'VINCE': -304.3}
- f3120 {'TODD': -306.0, 'SKID': -304.6, 'CARL': -304.5, 'EDDIE': -304.4, 'VINCE': -304.3}
- f3240 {'SKID': -166.3, 'TODD': 133.5, 'CARL': 132.5}
- f3360 {'CARL': 132.6, 'TODD': 133.6, 'SKID': -166.3}
- f3480 {'CARL': 132.6, 'TODD': 133.6, 'SKID': -166.3}
- f3600 {'CARL': 132.6, 'TODD': 133.6, 'SKID': -166.3}
- f3720 {'CARL': 132.4, 'TODD': 133.5, 'SKID': -166.4}
- f3840 {'CARL': 132.4, 'TODD': 133.2, 'SKID': -166.8}
- f3960 {'CARL': 132.3, 'TODD': 133.0, 'SKID': -167.1}
- ... 80 more
```

## Salida real: runs/w_r_b/log.txt

```
# resetscan runs/w_r_b/log.txt

## 1. In the log (F)
- 10537 lines, 2100 carpos rows, cars by kind: {'traffic': 21}
- carpos t window 38.49..239.16 s, sample gap median 2.03 s (carpos carries x,y only: no z, no speed)
- frames per second: 58.8 measured on AIP pairs, 59.2 by span ratio (I: no single line pairs a frame with a carpos t)
- polys max 8185 of polycap 8192 (0.999 of cap at the last TRAFLOG)

## 2. Still / embedded, per car (|dpos| < 0.5 m for > 6 s)
- traffic #9: 2 still episodes (0 with speed witness > 5 m/s)
    t 87.17..97.31 s, 6 samples, at [2325.1, 8.9], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
    t 188.51..194.60 s, 4 samples, at [742.8, 310.3], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
- traffic #10: 1 still episodes (0 with speed witness > 5 m/s)
    t 85.13..107.44 s, 12 samples, at [2323.8, 118.3], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
- traffic #12: 1 still episodes (0 with speed witness > 5 m/s)
    t 131.77..137.84 s, 4 samples, at [2040.5, 201.2], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
- traffic #13: 1 still episodes (0 with speed witness > 5 m/s)
    t 89.19..97.31 s, 5 samples, at [2340.6, -224.3], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
- traffic #14: 1 still episodes (0 with speed witness > 5 m/s)
    t 129.75..137.84 s, 5 samples, at [2027.1, 209.1], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
- traffic #15: 1 still episodes (0 with speed witness > 5 m/s)
    t 133.79..139.87 s, 4 samples, at [2059.5, 191.3], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
- traffic #16: 2 still episodes (0 with speed witness > 5 m/s)
    t 91.23..97.31 s, 4 samples, at [2340.5, -195.9], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
    t 121.64..127.73 s, 4 samples, at [2015.6, 211.9], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
- traffic #17: 2 still episodes (0 with speed witness > 5 m/s)
    t 87.17..111.51 s, 13 samples, at [2315.5, 156.2], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
    t 178.38..184.46 s, 4 samples, at [943.2, 352.9], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
- traffic #18: 2 still episodes (0 with speed witness > 5 m/s)
    t 119.62..137.84 s, 10 samples, at [2041.9, 192.5], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
    t 208.78..214.86 s, 4 samples, at [926.5, -214.9], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
- traffic #19: 1 still episodes (0 with speed witness > 5 m/s)
    t 127.73..135.81 s, 5 samples, at [2050.8, 190.5], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
- traffic #21: 1 still episodes (0 with speed witness > 5 m/s)
    t 89.19..97.31 s, 5 samples, at [2342.7, -213.3], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
- traffic #22: 1 still episodes (0 with speed witness > 5 m/s)
    t 85.13..109.47 s, 13 samples, at [2319.4, 137.6], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
- traffic #23: 1 still episodes (0 with speed witness > 5 m/s)
    t 129.75..135.81 s, 4 samples, at [2165.7, 204.5], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
- traffic #24: 1 still episodes (0 with speed witness > 5 m/s)
    t 87.17..97.31 s, 6 samples, at [2324.9, 21.3], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
- traffic #25: 1 still episodes (0 with speed witness > 5 m/s)
    t 131.77..137.84 s, 4 samples, at [2167.1, 208.8], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
- traffic #26: 1 still episodes (0 with speed witness > 5 m/s)
    t 85.13..105.42 s, 11 samples, at [2321.9, 122.5], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)
- traffic #28: 1 still episodes (0 with speed witness > 5 m/s)
    t 131.77..137.84 s, 4 samples, at [2021.3, 211.2], witness speed 0.0 -> UNCONFIRMED (NV: no speed for this car in the log)

## 3. Teleports (> 30 m between samples, implied speed > 60 m/s)
- traffic #9: 9 teleports (raw >30 m count 36)
    t 42.54 s  [1629.3, 740.2] -> [1880.5, -470.6]  1236.6 m in 2.03 s = 609.2 m/s   | next 30 s: 14 samples, path 316.8 m, ends [2165.2, -602.7]
    t 81.08 s  [2233.1, -587.4] -> [2340.1, -92.5]  506.3 m in 2.04 s = 248.2 m/s   | next 30 s: 14 samples, path 494.7 m, ends [2175.8, 200.8]
    t 99.34 s  [2325.1, 8.9] -> [2086.7, 187.8]  298.1 m in 2.03 s = 146.8 m/s   | next 30 s: 14 samples, path 296.6 m, ends [2318.2, 131.0]
    t 129.75 s  [2318.2, 131.0] -> [1865.0, 414.9]  534.8 m in 2.02 s = 264.7 m/s   | next 30 s: 14 samples, path 727.1 m, ends [1563.7, 711.4]
    t 143.92 s  [1956.7, 332.5] -> [1696.2, 664.9]  422.3 m in 2.02 s = 209.1 m/s   | next 30 s: 14 samples, path 959.5 m, ends [876.4, 354.0]
    t 170.26 s  [1501.7, 687.2] -> [892.6, 353.0]  694.8 m in 2.02 s = 343.9 m/s   | next 30 s: 14 samples, path 252.4 m, ends [795.6, 354.8]
    t 200.69 s  [795.6, 354.8] -> [980.7, -248.5]  631.1 m in 2.03 s = 310.9 m/s   | next 30 s: 14 samples, path 1283.3 m, ends [1226.8, -335.6]
    t 218.91 s  [863.6, -47.7] -> [1544.0, -265.7]  714.5 m in 2.02 s = 353.7 m/s   | next 30 s: 10 samples, path 447.7 m, ends [1124.6, -337.6]
- traffic #10: 9 teleports (raw >30 m count 36)
    t 40.51 s  [-87.7, 152.1] -> [1826.9, -451.0]  2007.3 m in 2.02 s = 993.7 m/s   | next 30 s: 14 samples, path 350.4 m, ends [2141.3, -591.6]
    t 81.08 s  [2246.9, -550.5] -> [2324.8, 89.9]  645.1 m in 2.02 s = 319.4 m/s   | next 30 s: 14 samples, path 29.1 m, ends [2323.7, 119.0]
    t 141.90 s  [2162.1, 201.7] -> [1696.9, 675.7]  664.1 m in 2.03 s = 327.2 m/s flags N   | next 30 s: 14 samples, path 892.0 m, ends [953.9, 355.9]
    t 168.24 s  [1486.6, 685.0] -> [994.2, 356.0]  592.2 m in 2.03 s = 291.7 m/s   | next 30 s: 14 samples, path 251.4 m, ends [754.1, 322.9]
    t 198.66 s  [754.1, 322.9] -> [855.7, -71.2]  407.0 m in 2.03 s = 200.5 m/s   | next 30 s: 14 samples, path 1570.6 m, ends [1405.2, -277.8]
    t 200.69 s  [855.7, -71.2] -> [1035.4, -291.1]  284.0 m in 2.03 s = 139.9 m/s   | next 30 s: 14 samples, path 1316.3 m, ends [1432.5, -266.2]
    t 220.94 s  [880.6, -66.7] -> [1578.8, -265.6]  726.0 m in 2.03 s = 357.6 m/s   | next 30 s: 9 samples, path 1003.0 m, ends [963.2, -181.4]
    t 222.96 s  [1578.8, -265.6] -> [1362.1, -310.0]  221.2 m in 2.02 s = 109.5 m/s   | next 30 s: 8 samples, path 781.8 m, ends [963.2, -181.4]
- traffic #11: 5 teleports (raw >30 m count 14)
    t 42.54 s  [1159.5, 347.3] -> [2079.7, -582.6]  1308.2 m in 2.03 s = 644.5 m/s   | next 30 s: 14 samples, path 340.8 m, ends [2247.0, -572.3]
    t 81.08 s  [2263.1, -525.5] -> [2330.2, 122.2]  651.2 m in 2.02 s = 322.4 m/s   | next 30 s: 14 samples, path 185.1 m, ends [2209.6, 231.2]
    t 139.87 s  [2045.1, 196.9] -> [1675.7, 463.5]  455.6 m in 2.03 s = 224.4 m/s flags N   | next 30 s: 14 samples, path 603.5 m, ends [1337.2, 486.5]
    t 158.10 s  [1779.5, 454.1] -> [1411.5, 569.5]  385.7 m in 2.02 s = 190.9 m/s   | next 30 s: 14 samples, path 860.8 m, ends [733.1, 111.3]
    t 178.38 s  [1249.6, 401.0] -> [724.9, 158.5]  578.0 m in 2.03 s = 284.7 m/s   | next 30 s: 14 samples, path 289.4 m, ends [881.2, -71.4]
- traffic #12: 9 teleports (raw >30 m count 34)
    t 42.54 s  [1688.1, 514.4] -> [2034.4, -551.9]  1121.1 m in 2.03 s = 552.3 m/s   | next 30 s: 14 samples, path 893.6 m, ends [2235.8, -551.7]
    t 60.80 s  [1811.5, -433.9] -> [2315.1, -448.2]  503.8 m in 2.03 s = 248.2 m/s   | next 30 s: 14 samples, path 889.6 m, ends [2331.9, 70.0]
    t 81.08 s  [2188.8, -591.2] -> [2347.8, -70.6]  544.3 m in 2.02 s = 269.5 m/s   | next 30 s: 14 samples, path 431.0 m, ends [2169.7, 210.4]
    t 139.87 s  [2040.5, 201.2] -> [1745.7, 454.4]  388.6 m in 2.03 s = 191.4 m/s   | next 30 s: 14 samples, path 1158.7 m, ends [1129.0, 352.5]
    t 152.03 s  [1847.1, 429.7] -> [1669.4, 715.5]  336.5 m in 2.02 s = 166.6 m/s   | next 30 s: 14 samples, path 855.0 m, ends [986.7, 354.4]
    t 160.14 s  [1681.1, 640.4] -> [1242.9, 394.4]  502.5 m in 2.04 s = 246.3 m/s   | next 30 s: 14 samples, path 329.5 m, ends [928.2, 359.1]
    t 200.69 s  [826.2, 352.5] -> [577.8, -23.6]  450.7 m in 2.03 s = 222.0 m/s   | next 30 s: 14 samples, path 653.5 m, ends [966.0, -206.0]
    t 202.70 s  [577.8, -23.6] -> [1032.9, -289.8]  527.2 m in 2.01 s = 262.3 m/s   | next 30 s: 14 samples, path 138.7 m, ends [965.8, -193.6]
- traffic #13: 10 teleports (raw >30 m count 28)
    t 44.57 s  [2271.6, 228.2] -> [2184.9, -594.3]  827.1 m in 2.03 s = 407.4 m/s   | next 30 s: 14 samples, path 1025.8 m, ends [2332.4, -444.5]
    t 46.59 s  [2184.9, -594.3] -> [1944.3, -497.7]  259.3 m in 2.02 s = 128.4 m/s   | next 30 s: 14 samples, path 792.1 m, ends [2331.5, -419.0]
    t 58.77 s  [1819.8, -448.6] -> [2236.2, -589.0]  439.4 m in 2.03 s = 216.5 m/s   | next 30 s: 14 samples, path 394.9 m, ends [2340.4, -232.5]
    t 99.34 s  [2340.6, -224.3] -> [2028.5, 196.3]  523.7 m in 2.03 s = 258.0 m/s   | next 30 s: 14 samples, path 181.3 m, ends [2183.7, 211.2]
    t 141.90 s  [2315.3, 152.5] -> [1676.6, 613.1]  787.5 m in 2.03 s = 387.9 m/s   | next 30 s: 14 samples, path 531.0 m, ends [1507.8, 672.2]
    t 158.10 s  [1679.3, 461.8] -> [1438.7, 603.7]  279.3 m in 2.02 s = 138.3 m/s   | next 30 s: 14 samples, path 1360.6 m, ends [873.3, 353.1]
    t 172.29 s  [1507.8, 672.2] -> [724.6, 265.0]  882.7 m in 2.03 s = 434.8 m/s   | next 30 s: 14 samples, path 1014.0 m, ends [858.4, -126.5]
    t 174.32 s  [724.6, 265.0] -> [979.8, 358.3]  271.7 m in 2.03 s = 133.9 m/s   | next 30 s: 14 samples, path 769.2 m, ends [856.6, -99.6]
- traffic #14: 8 teleports (raw >30 m count 49)
    t 42.54 s  [359.8, -1369.6] -> [2071.2, -573.0]  1887.7 m in 2.03 s = 929.9 m/s   | next 30 s: 14 samples, path 1082.7 m, ends [2341.6, -210.0]
    t 60.80 s  [1785.4, -438.8] -> [2328.7, -428.9]  543.4 m in 2.03 s = 267.7 m/s   | next 30 s: 14 samples, path 572.0 m, ends [2327.3, 139.0]
    t 139.87 s  [2027.1, 209.1] -> [1684.9, 497.3]  447.4 m in 2.03 s = 220.4 m/s   | next 30 s: 14 samples, path 756.0 m, ends [1409.7, 545.9]
    t 160.14 s  [1698.9, 668.0] -> [1310.0, 450.5]  445.6 m in 2.04 s = 218.4 m/s   | next 30 s: 14 samples, path 856.1 m, ends [741.2, 305.5]
    t 170.26 s  [1409.7, 545.9] -> [853.5, 356.0]  587.7 m in 2.02 s = 291.0 m/s   | next 30 s: 14 samples, path 323.4 m, ends [913.9, 334.3]
    t 198.66 s  [737.1, 309.9] -> [913.9, 334.3]  178.5 m in 2.03 s = 87.9 m/s   | next 30 s: 14 samples, path 1368.0 m, ends [1275.3, -345.7]
    t 206.76 s  [1062.2, 334.9] -> [690.8, 71.5]  455.3 m in 2.03 s = 224.3 m/s   | next 30 s: 14 samples, path 870.8 m, ends [1371.6, -310.0]
    t 208.78 s  [690.8, 71.5] -> [972.4, -249.2]  426.8 m in 2.02 s = 211.3 m/s   | next 30 s: 14 samples, path 449.9 m, ends [1376.1, -306.2]
- traffic #15: 6 teleports (raw >30 m count 18)
    t 44.57 s  [1877.0, 400.0] -> [2066.9, -575.6]  993.9 m in 2.03 s = 489.6 m/s   | next 30 s: 14 samples, path 356.4 m, ends [2325.4, -437.7]
    t 97.31 s  [2325.5, -135.0] -> [2174.4, 206.7]  373.6 m in 2.03 s = 184.0 m/s   | next 30 s: 14 samples, path 112.1 m, ends [2067.6, 187.5]
    t 141.90 s  [2059.5, 191.3] -> [1684.8, 697.2]  629.6 m in 2.03 s = 310.1 m/s   | next 30 s: 14 samples, path 634.8 m, ends [1274.7, 430.2]
    t 158.10 s  [1675.5, 513.7] -> [1392.0, 545.4]  285.3 m in 2.02 s = 141.2 m/s   | next 30 s: 14 samples, path 782.1 m, ends [724.7, 217.6]
    t 180.41 s  [1205.2, 363.4] -> [724.6, 243.2]  495.4 m in 2.03 s = 244.0 m/s   | next 30 s: 14 samples, path 189.0 m, ends [767.3, 65.3]
    t 218.91 s  [838.1, -5.8] -> [1358.7, -320.7]  608.4 m in 2.02 s = 301.2 m/s   | next 30 s: 10 samples, path 178.7 m, ends [1520.4, -265.9]
- traffic #16: 8 teleports (raw >30 m count 22)
    t 42.54 s  [852.9, -146.8] -> [2013.8, -537.0]  1224.7 m in 2.03 s = 603.3 m/s   | next 30 s: 14 samples, path 1287.8 m, ends [2140.7, -579.8]
    t 62.82 s  [1839.6, -452.7] -> [2329.9, -154.5]  573.9 m in 2.02 s = 284.1 m/s   | next 30 s: 14 samples, path 1148.4 m, ends [2340.5, -195.9]
    t 64.85 s  [2329.9, -154.5] -> [2201.9, -589.3]  453.2 m in 2.03 s = 223.3 m/s   | next 30 s: 14 samples, path 695.2 m, ends [2340.5, -195.9]
    t 77.01 s  [2086.5, -573.3] -> [2330.1, -127.5]  508.0 m in 2.03 s = 250.3 m/s   | next 30 s: 14 samples, path 906.8 m, ends [1941.4, 348.7]
    t 99.34 s  [2340.5, -195.9] -> [1879.5, 402.2]  755.1 m in 2.03 s = 372.0 m/s   | next 30 s: 14 samples, path 246.0 m, ends [2015.6, 211.9]
    t 139.87 s  [2006.7, 221.3] -> [1688.0, 566.8]  470.0 m in 2.03 s = 231.5 m/s   | next 30 s: 14 samples, path 344.2 m, ends [1515.2, 685.7]
    t 172.29 s  [1501.8, 683.9] -> [757.4, 326.2]  825.9 m in 2.03 s = 406.8 m/s   | next 30 s: 14 samples, path 617.4 m, ends [948.2, -229.7]
    t 200.69 s  [724.6, 238.3] -> [948.2, -229.7]  518.7 m in 2.03 s = 255.5 m/s   | next 30 s: 14 samples, path 362.7 m, ends [1270.1, -342.4]
- traffic #17: 6 teleports (raw >30 m count 8)
    t 40.51 s  [323.5, -1157.6] -> [1976.1, -532.0]  1767.0 m in 2.02 s = 874.8 m/s   | next 30 s: 14 samples, path 317.4 m, ends [2250.5, -551.8]
    t 83.10 s  [2327.5, -467.3] -> [2313.9, 163.7]  631.1 m in 2.02 s = 312.4 m/s   | next 30 s: 14 samples, path 7.7 m, ends [2315.5, 156.2]
    t 131.77 s  [2323.1, 82.7] -> [1965.1, 329.0]  434.5 m in 2.02 s = 215.1 m/s   | next 30 s: 14 samples, path 800.4 m, ends [1469.5, 667.1]
    t 141.90 s  [1981.5, 275.8] -> [1595.2, 731.2]  597.2 m in 2.03 s = 294.2 m/s   | next 30 s: 14 samples, path 688.3 m, ends [1033.2, 355.9]
    t 168.24 s  [1455.9, 641.5] -> [1058.2, 355.9]  489.6 m in 2.03 s = 241.2 m/s   | next 30 s: 14 samples, path 246.7 m, ends [811.6, 353.8]
    t 200.69 s  [795.6, 351.4] -> [926.6, -214.6]  581.0 m in 2.03 s = 286.2 m/s   | next 30 s: 14 samples, path 153.0 m, ends [1041.7, -312.4]
- traffic #18: 8 teleports (raw >30 m count 26)
    t 44.57 s  [1723.9, 457.5] -> [1569.1, -265.5]  739.4 m in 2.03 s = 364.2 m/s   | next 30 s: 14 samples, path 1381.4 m, ends [2242.6, -541.5]
    t 48.63 s  [1587.3, -281.2] -> [2077.6, -574.9]  571.5 m in 2.04 s = 280.2 m/s   | next 30 s: 14 samples, path 848.5 m, ends [2207.9, -590.9]
    t 64.85 s  [1866.5, -450.8] -> [2308.8, -473.3]  442.9 m in 2.03 s = 218.2 m/s   | next 30 s: 14 samples, path 869.1 m, ends [2342.5, -50.2]
    t 81.08 s  [2201.8, -595.2] -> [2324.9, 20.9]  628.3 m in 2.02 s = 311.0 m/s flags N   | next 30 s: 14 samples, path 766.5 m, ends [1981.8, 267.0]
    t 101.36 s  [2343.4, -75.0] -> [1943.7, 342.4]  577.9 m in 2.02 s = 286.1 m/s   | next 30 s: 14 samples, path 189.5 m, ends [2041.9, 192.5]
    t 139.87 s  [2041.9, 192.5] -> [1674.4, 506.0]  483.1 m in 2.03 s = 238.0 m/s   | next 30 s: 14 samples, path 688.5 m, ends [1212.0, 364.7]
    t 158.10 s  [1746.9, 457.8] -> [1310.5, 465.6]  436.5 m in 2.02 s = 216.1 m/s   | next 30 s: 14 samples, path 355.9 m, ends [999.7, 353.5]
    t 202.70 s  [858.7, 353.9] -> [911.0, -202.4]  558.8 m in 2.01 s = 278.0 m/s   | next 30 s: 14 samples, path 85.9 m, ends [974.0, -259.7]
- traffic #19: 7 teleports (raw >30 m count 13)
    t 46.59 s  [2323.5, 34.0] -> [1879.8, -473.7]  674.3 m in 2.02 s = 333.8 m/s   | next 30 s: 14 samples, path 310.3 m, ends [2159.1, -599.7]
    t 77.01 s  [2159.1, -599.7] -> [2335.8, -248.6]  393.1 m in 2.03 s = 193.6 m/s   | next 30 s: 14 samples, path 745.1 m, ends [1985.4, 246.9]
    t 99.34 s  [2339.9, -85.1] -> [1981.2, 298.3]  525.0 m in 2.03 s = 258.6 m/s   | next 30 s: 14 samples, path 162.7 m, ends [2051.1, 190.4]
    t 141.90 s  [2046.3, 191.8] -> [1684.9, 569.4]  522.7 m in 2.03 s = 257.5 m/s   | next 30 s: 14 samples, path 814.9 m, ends [1164.5, 355.8]
    t 162.16 s  [1650.6, 736.6] -> [1237.5, 393.5]  537.0 m in 2.02 s = 265.8 m/s   | next 30 s: 14 samples, path 319.2 m, ends [931.5, 354.9]
    t 202.70 s  [838.7, 353.0] -> [859.6, -135.1]  488.5 m in 2.01 s = 243.1 m/s   | next 30 s: 14 samples, path 523.4 m, ends [1174.3, -346.1]
    t 210.81 s  [855.5, -66.5] -> [975.1, -253.6]  222.1 m in 2.03 s = 109.4 m/s   | next 30 s: 14 samples, path 336.5 m, ends [1278.7, -345.7]
- traffic #20: 9 teleports (raw >30 m count 42)
    t 40.51 s  [-471.3, -212.7] -> [1851.6, -811.1]  2398.7 m in 2.02 s = 1187.5 m/s   | next 30 s: 14 samples, path 1193.8 m, ends [2324.2, -338.1]
    t 50.66 s  [1857.8, -883.6] -> [1968.8, -516.1]  383.9 m in 2.03 s = 189.1 m/s   | next 30 s: 14 samples, path 892.1 m, ends [2341.5, -185.8]
    t 62.82 s  [1834.5, -443.0] -> [2328.0, -428.1]  493.7 m in 2.02 s = 244.4 m/s   | next 30 s: 14 samples, path 414.6 m, ends [2338.5, -20.3]
    t 99.34 s  [2331.5, 49.4] -> [1950.2, 336.9]  477.5 m in 2.03 s = 235.2 m/s   | next 30 s: 14 samples, path 240.2 m, ends [2092.5, 181.2]
    t 141.90 s  [2175.8, 200.3] -> [1578.8, 713.4]  787.2 m in 2.03 s = 387.8 m/s   | next 30 s: 14 samples, path 1206.9 m, ends [1066.1, 356.5]
    t 158.10 s  [1678.3, 597.3] -> [1310.3, 451.1]  396.0 m in 2.02 s = 196.0 m/s   | next 30 s: 14 samples, path 735.7 m, ends [919.9, 358.9]
    t 170.26 s  [1423.6, 576.3] -> [1066.1, 356.5]  419.7 m in 2.02 s = 207.8 m/s   | next 30 s: 14 samples, path 256.9 m, ends [809.5, 358.8]
    t 200.69 s  [809.5, 358.8] -> [1011.8, -275.8]  666.1 m in 2.03 s = 328.1 m/s   | next 30 s: 14 samples, path 884.8 m, ends [1366.3, -293.8]
- traffic #21: 9 teleports (raw >30 m count 37)
    t 42.54 s  [971.2, -277.5] -> [2186.1, -590.3]  1254.5 m in 2.03 s = 618.0 m/s   | next 30 s: 14 samples, path 840.0 m, ends [2092.2, -570.0]
    t 62.82 s  [1866.5, -454.6] -> [2208.8, -591.3]  368.6 m in 2.02 s = 182.5 m/s   | next 30 s: 14 samples, path 707.2 m, ends [2342.7, -213.3]
    t 77.01 s  [2031.4, -546.5] -> [2334.5, -174.1]  480.2 m in 2.03 s = 236.5 m/s   | next 30 s: 14 samples, path 539.8 m, ends [2143.6, 189.7]
    t 99.34 s  [2342.7, -213.3] -> [2109.0, 188.0]  464.4 m in 2.03 s = 228.8 m/s   | next 30 s: 14 samples, path 260.7 m, ends [2318.9, 152.8]
    t 129.75 s  [2318.9, 152.8] -> [1958.9, 329.5]  401.0 m in 2.02 s = 198.5 m/s   | next 30 s: 14 samples, path 641.9 m, ends [1673.0, 721.5]
    t 141.90 s  [1977.8, 290.4] -> [1684.9, 550.2]  391.5 m in 2.03 s = 192.9 m/s   | next 30 s: 14 samples, path 1290.1 m, ends [799.0, 356.9]
    t 162.16 s  [1649.1, 733.4] -> [1324.2, 464.2]  421.9 m in 2.02 s = 208.9 m/s   | next 30 s: 14 samples, path 810.2 m, ends [724.6, 242.3]
    t 170.26 s  [1374.4, 508.6] -> [799.0, 356.9]  595.1 m in 2.02 s = 294.6 m/s   | next 30 s: 14 samples, path 192.3 m, ends [724.7, 198.0]
- traffic #22: 7 teleports (raw >30 m count 22)
    t 46.59 s  [1378.2, -595.4] -> [2183.4, -590.5]  805.2 m in 2.02 s = 398.6 m/s   | next 30 s: 14 samples, path 450.3 m, ends [2260.4, -528.8]
    t 48.63 s  [2183.4, -590.5] -> [2020.9, -560.0]  165.3 m in 2.04 s = 81.0 m/s   | next 30 s: 14 samples, path 303.9 m, ends [2274.3, -515.9]
    t 83.10 s  [2325.8, -477.2] -> [2319.8, 145.3]  622.5 m in 2.02 s = 308.2 m/s   | next 30 s: 14 samples, path 16.9 m, ends [2320.4, 129.1]
    t 139.87 s  [2336.1, -24.9] -> [1824.5, 443.8]  693.8 m in 2.03 s = 341.8 m/s   | next 30 s: 14 samples, path 759.7 m, ends [1263.8, 419.0]
    t 152.03 s  [1842.4, 430.6] -> [1431.5, 604.7]  446.3 m in 2.02 s = 220.9 m/s   | next 30 s: 14 samples, path 400.5 m, ends [1138.8, 352.9]
    t 182.43 s  [1138.8, 352.9] -> [724.7, 199.9]  441.5 m in 2.02 s = 218.5 m/s   | next 30 s: 14 samples, path 185.0 m, ends [806.4, 51.9]
    t 218.91 s  [816.4, 38.6] -> [1412.3, -268.2]  670.2 m in 2.02 s = 331.8 m/s   | next 30 s: 10 samples, path 265.2 m, ends [1301.2, -332.3]
- traffic #23: 8 teleports (raw >30 m count 20)
    t 42.54 s  [840.7, -1606.3] -> [1893.5, -486.2]  1537.2 m in 2.03 s = 757.2 m/s   | next 30 s: 14 samples, path 278.9 m, ends [2147.6, -590.0]
    t 77.01 s  [2166.0, -598.8] -> [2337.5, -197.5]  436.4 m in 2.03 s = 215.0 m/s   | next 30 s: 14 samples, path 564.9 m, ends [2090.9, 184.5]
    t 99.34 s  [2327.4, -7.0] -> [2055.2, 186.1]  333.7 m in 2.03 s = 164.4 m/s   | next 30 s: 14 samples, path 189.1 m, ends [2163.3, 203.3]
    t 139.87 s  [2163.9, 203.5] -> [1779.3, 454.1]  459.0 m in 2.03 s = 226.1 m/s   | next 30 s: 14 samples, path 581.9 m, ends [1543.7, 700.8]
    t 150.01 s  [1854.9, 418.9] -> [1695.1, 691.0]  315.6 m in 2.03 s = 155.4 m/s   | next 30 s: 14 samples, path 1107.0 m, ends [726.2, 278.8]
    t 172.29 s  [1529.5, 693.6] -> [741.3, 309.1]  877.0 m in 2.03 s = 432.0 m/s   | next 30 s: 14 samples, path 148.0 m, ends [724.9, 165.3]
    t 216.89 s  [772.6, 67.2] -> [1485.1, -265.6]  786.4 m in 2.03 s = 387.4 m/s   | next 30 s: 11 samples, path 450.5 m, ends [1054.0, -306.8]
    t 218.91 s  [1485.1, -265.6] -> [1324.6, -328.3]  172.3 m in 2.02 s = 85.3 m/s   | next 30 s: 10 samples, path 278.2 m, ends [1054.0, -306.8]
- traffic #24: 7 teleports (raw >30 m count 23)
    t 40.51 s  [264.6, -1874.0] -> [1885.5, -477.7]  2139.4 m in 2.02 s = 1059.1 m/s   | next 30 s: 14 samples, path 336.8 m, ends [2190.3, -607.4]
    t 81.08 s  [2250.5, -556.3] -> [2323.1, 53.0]  613.6 m in 2.02 s = 303.8 m/s   | next 30 s: 14 samples, path 475.2 m, ends [2066.8, 184.9]
    t 99.34 s  [2324.9, 21.3] -> [2007.8, 218.9]  373.6 m in 2.03 s = 184.1 m/s   | next 30 s: 14 samples, path 156.7 m, ends [2152.8, 191.2]
    t 141.90 s  [2295.9, 201.8] -> [1690.6, 702.0]  785.2 m in 2.03 s = 386.8 m/s   | next 30 s: 14 samples, path 810.6 m, ends [1004.8, 356.6]
    t 170.26 s  [1485.9, 681.4] -> [1004.8, 356.6]  580.5 m in 2.02 s = 287.4 m/s   | next 30 s: 14 samples, path 800.8 m, ends [919.5, -195.4]
    t 198.66 s  [765.1, 338.6] -> [919.5, -195.4]  555.9 m in 2.03 s = 273.8 m/s   | next 30 s: 14 samples, path 994.9 m, ends [1459.6, -266.1]
    t 212.83 s  [852.2, -75.7] -> [1425.2, -269.5]  604.9 m in 2.02 s = 299.4 m/s   | next 30 s: 13 samples, path 322.8 m, ends [1420.0, -262.1]
- traffic #25: 6 teleports (raw >30 m count 27)
    t 42.54 s  [1424.6, 1.8] -> [1972.0, -513.5]  751.8 m in 2.03 s = 370.3 m/s   | next 30 s: 14 samples, path 955.5 m, ends [2332.0, -255.4]
    t 56.74 s  [1773.9, -429.2] -> [2325.5, -438.6]  551.7 m in 2.04 s = 270.4 m/s   | next 30 s: 14 samples, path 379.8 m, ends [2348.2, -65.3]
    t 141.90 s  [2166.6, 208.4] -> [1683.2, 634.1]  644.1 m in 2.03 s = 317.3 m/s   | next 30 s: 14 samples, path 1018.0 m, ends [974.9, 353.0]
    t 158.10 s  [1678.2, 471.9] -> [1451.8, 640.8]  282.5 m in 2.02 s = 139.8 m/s   | next 30 s: 14 samples, path 724.6 m, ends [823.3, 356.0]
    t 170.26 s  [1393.8, 545.0] -> [974.9, 353.0]  460.8 m in 2.02 s = 228.1 m/s   | next 30 s: 14 samples, path 349.5 m, ends [769.5, 370.4]
    t 200.69 s  [769.5, 370.4] -> [900.0, -198.4]  583.6 m in 2.03 s = 287.5 m/s   | next 30 s: 14 samples, path 164.5 m, ends [1025.8, -301.5]
- traffic #26: 5 teleports (raw >30 m count 23)
    t 44.57 s  [1690.6, -1769.4] -> [1969.7, -528.2]  1272.2 m in 2.03 s = 626.7 m/s   | next 30 s: 14 samples, path 290.7 m, ends [2238.1, -581.4]
    t 83.10 s  [2297.2, -498.0] -> [2321.4, 125.8]  624.3 m in 2.02 s = 309.0 m/s   | next 30 s: 14 samples, path 33.2 m, ends [2316.3, 118.3]
    t 135.81 s  [2337.5, -29.9] -> [1892.9, 385.6]  608.5 m in 2.02 s = 301.3 m/s   | next 30 s: 14 samples, path 943.3 m, ends [1272.2, 423.1]
    t 145.96 s  [1944.6, 342.2] -> [1459.3, 653.8]  576.7 m in 2.04 s = 282.7 m/s   | next 30 s: 14 samples, path 419.7 m, ends [1175.4, 356.1]
    t 202.70 s  [861.6, 356.0] -> [987.5, -259.2]  628.0 m in 2.01 s = 312.4 m/s   | next 30 s: 14 samples, path 134.9 m, ends [1095.1, -338.2]
- traffic #27: 7 teleports (raw >30 m count 23)
    t 54.70 s  [1693.3, -454.6] -> [2176.8, -600.1]  504.9 m in 2.02 s = 250.0 m/s   | next 30 s: 14 samples, path 385.0 m, ends [2328.0, -301.0]
    t 97.31 s  [2337.0, -170.3] -> [2107.6, 184.8]  422.8 m in 2.03 s = 208.3 m/s   | next 30 s: 14 samples, path 287.5 m, ends [2320.8, 121.6]
    t 131.77 s  [2322.5, 107.0] -> [1935.1, 353.4]  459.1 m in 2.02 s = 227.3 m/s   | next 30 s: 14 samples, path 1001.7 m, ends [1419.3, 576.3]
    t 143.92 s  [1977.0, 309.8] -> [1677.0, 703.3]  494.8 m in 2.02 s = 245.0 m/s   | next 30 s: 14 samples, path 1083.1 m, ends [835.1, 352.9]
    t 158.10 s  [1674.4, 541.5] -> [1436.4, 606.6]  246.7 m in 2.02 s = 122.1 m/s   | next 30 s: 14 samples, path 795.0 m, ends [732.2, 299.2]
    t 170.26 s  [1371.2, 521.2] -> [872.6, 353.1]  526.2 m in 2.02 s = 260.5 m/s   | next 30 s: 14 samples, path 623.8 m, ends [851.0, -141.6]
    t 198.66 s  [726.0, 275.3] -> [851.0, -141.6]  435.2 m in 2.03 s = 214.4 m/s   | next 30 s: 14 samples, path 170.8 m, ends [971.6, -258.6]
- traffic #28: 9 teleports (raw >30 m count 36)
    t 40.51 s  [-104.4, -1057.3] -> [1854.2, -732.4]  1985.4 m in 2.02 s = 982.9 m/s   | next 30 s: 14 samples, path 724.6 m, ends [2031.5, -562.5]
    t 62.82 s  [1855.0, -915.5] -> [1926.0, -502.0]  419.6 m in 2.02 s = 207.7 m/s   | next 30 s: 14 samples, path 1068.6 m, ends [2297.3, 210.6]
    t 77.01 s  [2125.7, -587.9] -> [2340.6, -41.3]  587.3 m in 2.03 s = 289.3 m/s   | next 30 s: 14 samples, path 450.1 m, ends [2124.1, 198.9]
    t 139.87 s  [2021.3, 211.2] -> [1704.5, 464.6]  405.7 m in 2.03 s = 199.8 m/s   | next 30 s: 14 samples, path 1003.6 m, ends [1109.5, 352.8]
    t 162.16 s  [1694.1, 652.0] -> [1417.9, 565.3]  289.5 m in 2.02 s = 143.3 m/s   | next 30 s: 14 samples, path 769.3 m, ends [855.5, 356.0]
    t 168.24 s  [1453.5, 629.7] -> [1109.5, 352.8]  441.6 m in 2.03 s = 217.5 m/s   | next 30 s: 14 samples, path 337.1 m, ends [775.7, 339.0]
    t 200.69 s  [773.8, 337.7] -> [855.9, -79.4]  425.1 m in 2.03 s = 209.4 m/s   | next 30 s: 14 samples, path 875.4 m, ends [1091.8, -338.1]
    t 202.70 s  [855.9, -79.4] -> [586.9, -17.0]  276.1 m in 2.01 s = 137.4 m/s   | next 30 s: 14 samples, path 607.2 m, ends [1099.7, -339.1]
- traffic #29: 9 teleports (raw >30 m count 23)
    t 40.51 s  [-77.5, 154.9] -> [1938.8, -497.5]  2119.2 m in 2.02 s = 1049.1 m/s   | next 30 s: 14 samples, path 892.0 m, ends [2329.0, -441.1]
    t 54.70 s  [1749.4, -437.0] -> [2238.1, -581.6]  509.6 m in 2.02 s = 252.3 m/s   | next 30 s: 14 samples, path 391.1 m, ends [2343.6, -229.0]
    t 99.34 s  [2341.7, -32.2] -> [1980.8, 248.4]  457.1 m in 2.03 s = 225.2 m/s   | next 30 s: 14 samples, path 179.6 m, ends [2134.8, 187.2]
    t 141.90 s  [2210.6, 226.7] -> [1639.7, 739.4]  767.3 m in 2.03 s = 378.0 m/s   | next 30 s: 14 samples, path 832.3 m, ends [915.3, 355.9]
    t 168.24 s  [1466.7, 667.5] -> [953.6, 355.9]  600.3 m in 2.03 s = 295.7 m/s   | next 30 s: 14 samples, path 259.8 m, ends [784.4, 351.7]
    t 200.69 s  [778.4, 348.7] -> [853.1, -108.6]  463.4 m in 2.03 s = 228.3 m/s   | next 30 s: 14 samples, path 1273.6 m, ends [1314.2, -299.5]
    t 204.73 s  [852.0, -74.2] -> [578.3, -23.0]  278.4 m in 2.03 s = 137.2 m/s   | next 30 s: 14 samples, path 990.2 m, ends [1284.8, -300.5]
    t 206.76 s  [578.3, -23.0] -> [1036.4, -300.6]  535.6 m in 2.03 s = 263.9 m/s flags N   | next 30 s: 14 samples, path 464.0 m, ends [1275.4, -300.9]
- %d jumps in total. I: per-idx carpos rows are NOT one continuous car (a slot gets
  re-used/respawned far away, the same thing the FREE tmove deltas show), so read
  these as slot resets, not as one car teleporting. NV: the log cannot tell a real
  reset from slot re-use, they look identical here.

## 4. Falls (z drop > 5 m inside one sample gap)
- COLLOG f5400->5700 (300 frames, 3.91 s): z 65.0 -> 54.0 (drop 11.0 m) at [2319.0, -378.0], sp 25.1 -> 27.8  [coarse: COLLOG rows are 300 frames apart, so this bounds the drop, NV on the 2 s window]

## 5. Reset counter and wall pressure (COLLOG)
- f3300 reset 6141 -> 0 at pos [1685.0, -456.0, 64.0] sp 0.0

## 6. Reset events: RST -> RSTA -> RSTW (probe, F)
- 26 reset calls, watch 120 frames after each (RSTW every 10 frames)
- dz = z(now) - z(at the reset call); frames stopped = RSTW samples with sp<1 x10

  frame  idx car       sp0  dz@last  dz min  moved max  stopped  longest  flags
   3600    1 01793710   9.5    -0.03   -0.05     148.9        0        0  
   3600    2 017a2500  10.2    +2.19   +1.89     242.0        0        0  
   3600    3 01794a70  18.3    -3.46   -6.31     325.6        0        0  DZ-DRIFT -6.31
   3600    6 0177ac20  20.4    +5.35   +5.35     453.3        0        0  
   4440    0 0177ef60  42.6   -16.30  -16.30     563.5        0        0  DZ-DRIFT -16.30
   4740   29 01774460  32.8   +16.40  +15.04     514.8        0        0  
   5100    0 01794a70  25.0    +8.27   +6.39     150.3        0        0  
   5220    0 01764e90  26.7    +8.12   +7.47     216.9        0        0  
   6660   19 01764e90  44.4    -0.76   -2.70     258.8        0        0  DZ-DRIFT -2.70
   9420   28 01793710  15.8    +0.50   +0.39     136.4       20       20  
  10200   10 01764e90  15.9    -7.87   -7.87     523.9        0        0  DZ-DRIFT -7.87
  10320   25 01793710  15.2    +1.82   +1.75     325.4        0        0  
  10380   26 0177ac20  15.9    +2.28   +1.43     302.8        0        0  
  10980   22 01793710  22.4    -0.90   -0.96      51.0        0        0  
  11160   23 0177ac20  23.9    -1.12   -1.13      58.0        0        0  
  11400   24 01764e90  33.5    -3.38   -3.49     253.9        0        0  DZ-DRIFT -3.49
  11460   25 0176ea00  47.5   -11.38  -11.47     416.1        0        0  DZ-DRIFT -11.47
  11760   22 01793710  16.0    +5.00   +1.84     133.9        0        0  
  11940   23 0177ac20   9.8    +1.28   +0.58      72.0        0        0  
  12180   24 0176ea00  22.2    +5.17   +1.64      88.7        0        0  
  12420   25 01764e90  11.0    +4.23   +2.56     724.6        0        0  
  12600   26 01774460  18.7    -1.56   -1.86     794.0        0        0  
  12720   27 0177ef60  36.8    +4.94   +3.19     815.1        0        0  
  13980    0 0177ac20  29.4    +6.30   +3.87     336.6        0        0  
  14100   29 017a2500   9.5    +2.82   +2.72    1219.8        0        0  
  14280   26 0176ea00  15.3    +1.48   -0.79     567.9        0        0  

- 6 of 26 events flagged
  f3600 idx 3 01794a70: DZ-DRIFT -6.31 | sp0 18.3, dz@+120 -3.46, RSTA moved 325.6 sp 22.5, cache (12, 11, 1, 0)
  f4440 idx 0 0177ef60: DZ-DRIFT -16.30 | sp0 42.6, dz@+120 -16.30, RSTA moved 563.5 sp 8.1, cache (16, 14, 2, 0)
  f6660 idx 19 01764e90: DZ-DRIFT -2.70 | sp0 44.4, dz@+120 -0.76, RSTA moved 258.8 sp 54.1, cache (28, 27, 1, 0)
  f10200 idx 10 01764e90: DZ-DRIFT -7.87 | sp0 15.9, dz@+120 -7.87, RSTA moved 523.9 sp 45.7, cache (18, 15, 3, 0)
  f11400 idx 24 01764e90: DZ-DRIFT -3.49 | sp0 33.5, dz@+120 -3.38, RSTA moved 253.9 sp 38.3, cache (29, 29, 0, 0)
  f11460 idx 25 0176ea00: DZ-DRIFT -11.47 | sp0 47.5, dz@+120 -11.38, RSTA moved 416.1 sp 41.0, cache (20, 16, 4, 0)

## 7. FREE tmove: per-name delta > 120 m over one row (reset/recycle, F)
- f2880 {'WILL': -306.0, 'BRETT': -304.6, 'HECTOR': -304.5, 'CARLA': -304.4, 'KIRBY': -304.3}
- f3000 {'WILL': -306.0, 'BRETT': -304.6, 'HECTOR': -304.5, 'CARLA': -304.4, 'KIRBY': -304.3}
- f3120 {'BRETT': -420.1, 'CARLA': -418.5, 'KIRBY': -418.4}
- f3240 {'TICKETS': 306.1, 'BRYCE': 306.1, 'MUTT': 306.1}
- f3360 {'TICKETS': 306.1, 'BRYCE': 306.1, 'MUTT': 306.1}
- f3480 {'MUTT': 306.1, 'TICKETS': 306.1, 'BRYCE': 306.1}
- f3600 {'TICKETS': 197.4, 'CARLA': 297.0}
- f3720 {'CARLA': 296.8, 'TICKETS': 196.4}
- f3840 {'CARLA': 296.7, 'TICKETS': 195.4}
- f3960 {'CARLA': 296.7, 'TICKETS': 194.7}
- ... 19 more
```
