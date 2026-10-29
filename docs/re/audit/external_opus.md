# Auditoría externa del RE nocturno de NFSU (Speed.exe), 2026-10-29

Revisor independiente; solo lectura. Herramienta principal: capstone 5.0.7 (.venv) sobre pc/Speed.exe con un
lector PE propio (`scratchpad/xd.py`: desensamblado, bytes, floats, búsqueda de rel32/imm32 en .text y punteros en
.data). Datos del juego leídos con `tools/census/jdlz.py` (solo el descompresor) y un recorrido de chunks propio.
No usé REA ni Hopper (no hizo falta) ni corrí el juego (ver §4).

## Resultado en una línea
De 24 afirmaciones muestreadas: **21 CONFIRMADAS, 2 REFUTADAS, 1 NO CONCLUYENTE**. Las direcciones y constantes de los
docs son sólidas; lo débil es la capa de conteo: `systems.tsv` contradice a `names.tsv` en el 47 % de las funciones
nombradas, la columna "tagged" de §5 es tautológica y "diff-tested" no existe por sistema.

## 1. Muestra (24 afirmaciones, sesgada a las específicas)

| # | Doc | Afirmación | Dirección | Resultado | Evidencia (capstone salvo que se diga) |
|---|---|---|---|---|---|
| 1 | assets | 47 loaders en la tabla, unloaders en paralelo; round-robin, int3 si nadie toma tras n+1 intentos | 0x7007e0 / 0x7008a0 / 0x447ac0 | CONFIRMADA | 47 punteros no nulos + terminador 0 (unloaders terminan en 0xffffffff); 0x447ac0: `inc ebx; cmp ebx,n; xor ebx,ebx` y `cmp edi,eax; jle; int3` |
| 2 | assets | Slot ResourceFile de 0xb4 bytes; COMP ver 1 / JDLZ ver 2 | 0x447f40, 0x58d3c0 | CONFIRMADA | `push 0xb4` antes de crear el pool; `cmp eax,0x504d4f43 ('COMP')`, `cmp dl,1`; `cmp eax,0x5a4c444a ('JDLZ')` |
| 3 | assets | Loader 22 acepta 0x34030 y lo enlaza en 0x737b48; loader 9 acepta 0x80035000/10 como no-op | 0x58d4c0, 0x402820 | CONFIRMADA | índice 22 de la tabla = 0x58d4c0, `cmp [eax],0x34030`, `mov [eax],0x737b48`; índice 9 = 0x402820 devuelve 1 para ambos ids |
| 4 | blur | Scene RT 800x600 por defecto, blur A/B a W/2 x H/2 (320x240), formato 21 | 0x701034/38, 0x40cb80, 0x702a28 | CONFIRMADA | datos 0x320,0x258; `sar ebx,1`/`sar eax,1` → 0x702a2c/30 (iniciales 0x140,0xf0); 0x702a28 = 0x15 |
| 5 | blur | Constantes de fuerza (25, 125, 0.65, 0.00625, 0.2/0.1, 1.1 double, 1/255 double, 1.2, 1.5) y rampa de n hacia el flag | 0x702a38.., 0x6ccd00, 0x40cd40 | CONFIRMADA | floats leídos; 0x6ccd00 = double 0x3f70101010101010 = 1/255; rampa `fcom; test ah,5; jp` suma 0.2 si n<flag, resta 0.1 si n>flag |
| 6 | camera | Por defecto en carrera: tipo `[0x700aa4]!=0 ? 0x11 : 1`; 0x700aa4 = 1 y sin escritor | 0x42c670, 0x700aa4 | CONFIRMADA | `neg; sbb; and 0x10; inc` → 0x11/1; valor 1; 7 refs imm32 en .text, todas `a1` (load), ningún puntero en .data |
| 7 | camera | Fábrica: 23 tipos (0..0x16), jump table + byte index; tipos 4..12 = OrbitCarCameraMover (0xd0) | 0x42c6d0, 0x42d2f4, 0x42d330 | CONFIRMADA | `cmp eax,0x16; ja`; índices 4..12 = 0x0e → 0x42d296 = mismo destino que `ja`, que hace `push 0xd0` |
| 8 | camera | FOV global s16 por POV: 0,1,4 = 0x32dc (71.5°), 2,3 = 0x4000 (90°); lo leen 0x489690, 0x48b8c0, 0x480750 | 0x6fbdf4 | CONFIRMADA | bytes `dc32 dc32 0040 0040 dc32`; 3 refs imm32 caen en esas 3 funciones (límites de census/hopper/funcs.tsv) |
| 9 | canon | EventDesc 0x14c bytes indexados en `[0x733ff8+4*id]` (256 slots); 0x34a01 = filas de 0x20 en 0x733f78; 116 y 25 registros | 0x5a00a0, 0x5a0060 | CONFIRMADA | `mul 0x3159721f; shr 6` (= /0x14c), `rep stosd 0x100`, `add eax,0x14c`; rama 0x34a01 `shr 5`. Datos: FrontB.lzc 0x34a02 = 38512 B = 116 reg, ids 0..122; 0x34a01 = 25 reg |
| 10 | canon | Ganar el evento 0x71 pone el flag 0x7677ac; cash en +0x1374 y vitalicio en +0x1378 | 0x5a0dc0 | CONFIRMADA | `cmp [esp+0xc],0x71` → `mov [0x7677ac],1`; suma en +0x1374 y +0x1378 |
| 11 | canon | 42 nombres de película (nombre→id por 0x4f7840); 23 .mad en disco | 0x6f90d8 | CONFIRMADA | tabla de stride 8, 42 entradas ("01_day".."nfsgb"), `cmp esi,0x2a`; `ls game/Movies` = 23 .mad |
| 12 | canon | 0x5a1100 "abre todo evento no ganado cuyos prerrequisitos están hechos" | 0x5a1100 | NO CONCLUYENTE | Hay dos pasadas: la 1.ª **cierra** (1→0) todos los abiertos, la 2.ª llama 0x5a0fc0 y pone 1. Además consulta una segunda fuente `[mgr+0x88b0]+0x58a0` que el doc no menciona. La condición "no ganado" no la verifiqué en 3 intentos |
| 13 | garage | Registro de pantallas nombre→fábrica, stride 0x14 | 0x6f94d8 | CONFIRMADA | filas {ptr "Options.fng", 0x494910, flag, …}, stride 0x14 |
| 14 | garage | Cancel copia ride B (+0x730) sobre A (+0x10) | 0x504890 | CONFIRMADA | `copy(A=eax+0x10, B=eax+0x730)` vía 0x4323f0 (dst=arg1). Omite que además copia B a 0x748850 y escribe `[0x72cc80]=2` |
| 15 | garage | "path 0..8 → tipos 0x10..0x18"; "16..24 son los 9 perf paths" | 0x5a0350 | REFUTADA (incompleta) | la función tiene **11** casos (`cmp eax,0xa`): 9→tipo 8 y 10→tipo 5 (tipos visuales). Coincide con `level[11]` de tuning.md, no con "9 paths" |
| 16 | garage | Precio visual = record[tipo].cost[nivel-1]; nivel 0 y 4 cuestan 0 | 0x5a08f0 | CONFIRMADA | nivel byte en part+0x11; tabla de salto: 0→0, 1..3→+4/+8/+0xc, >3→0 |
| 17 | props | Tabla de superficies de 29 filas; 17 nombres de smack type | 0x6ef2d0, 0x6ef240 | CONFIRMADA | stride 0x94 (`imul ebx,0x94` en 0x441d88), cota `cmp esi,0x6f0394` = 29 filas; 17 punteros a cadenas (NONE..TRASHCAN) |
| 18 | props | Pool Smokeable 32 x 0x4d0; Virgin 0x68 por slot | 0x595bf0 | CONFIRMADA | `push 0x9a30` (=32·0x4d0+0x30), `mov [esi+0x28],0x4d0`; `imul edx,0x68` |
| 19 | props | "loader 3 `0x5952a0`" | 0x7007e0[3] | REFUTADA | en la tabla, índice 3 = 0x442040; 0x5952a0 es el índice **29**. assets.md/traffic.md usan el índice real (loader 4 = 0x5455c0, 23 = 0x442dd0) |
| 20 | rivals | Tabla IA de 523 floats copiada a 0x779c78 | 0x462070 | CONFIRMADA | `cmp [eax],0x34b00; mov ecx,0x20b; mov edi,0x779c78; rep movsd` (0x20b = 523) |
| 21 | rivals | Rubber band una vez por periodo de tabla; ticks a 0.00025 s; neutro los primeros segundos por skill | 0x44bd10, 0x6cca38 | CONFIRMADA | `(now-[edi+0x420])*[0x6cca38]` vs `[0x77a49c]` (último float de la tabla); `fild [ +0x14]*0.00025` vs `[skill*0x54+0x77a044]` |
| 22 | rivals | Quick race: 48 nombres, 20 coches; DriverInfo id 100+k, kind 2, grid k+1, +0x735/+0x736 | 0x4b3a20, 0x4b3c60, 0x5809c0 | CONFIRMADA | `div 0x30`; `mov esi,0x14; div` sobre 0x6fafc8..0x6fb018; llamada en 0x4b4321 empuja `ebx+0x62`, `2`, …, `ebx-1` (k = ebx-2, inferido del bucle) |
| 23 | sound | 26 canciones (19 IG + 7 FE); tabla de directorios de 23; picker usa 0x758934 en menús y 0x758930 en carrera, bit 1<<(orden+1) | 0x6f4d08, 0x6f7eb0, 0x53c3a0 | CONFIRMADA | recorrido de registros de 16 B termina en 0x6f4ea8 con 19/7; 23 punteros a dir ("Car_0\\Eng_UG_0\\".."TURBO\\"); `inc ecx; shl ebp,cl; test [0x758934],ebp`, `cmp …,0x1a` |
| 24 | traffic | Tope 30 entrantes; espaciado 99999 salvo zona tipo 4; spawn ruta→registro→nodo aleatorio, 100 intentos; teleporter 1.0/0.3 s, 250/500 m; kind 3 con vtable 0x6b96b0 | 0x4322a0, 0x59b3e0, 0x598bf0, 0x6b5a30, 0x4b3c22 | CONFIRMADA | `cmp [ebp+0x12c],0x1e`; `mov [ebp-4],0x47c34f80` (99999.0), `mov edx,4`; llamadas 0x5991a0/0x598c80/0x598fb0 con `cmp …,0x64`; floats 1.0,0.3,250,500; `push 3` al ctor DriverInfo; ctor 0x582f90 escribe vtable 0x6b96b0 (slot 3 = 0x583350) |
| (extra) | tuning | 0x583ea0 = lookup genérico {n,xmin,xmax,1/step,data*} con clamp; tablas de dirección 45°→2.9°/7° a "160"; 35 CarTypeInfo de 0xc90, física 0x2b0 en +0x110; 0x57f2b0→0x575960 | 0x583ea0, 0x705f48, 0x57c8b0 | CONFIRMADA | cabeceras `a 0 160.0 0.05625 ptr`; datos 45,23,11…2.9 y 45,15,11…7; `imul 0xc90`, `cmp esi,0x23`, `rep movsd 0xac`; única llamada a 0x575960 en 0x57f30f |
| (extra) | proposals | 0x5a1520 devuelve 1e9 con `[0x735ec1]` | 0x5a1520 | CONFIRMADA (con omisión) | devuelve 0x3b9aca00 si **cualquiera** de `[0x73494c]`, `[0x735ec1]`, `[0x73440c]`; el tercer flag no aparece en proposals.md |

Tuning cuenta con 2 afirmaciones en las filas extra y en #16 (precio por nivel, compartida con garage).

## 2. Contradicciones

1. **Numeración de loaders**: props.md:21 "loader 3 `0x5952a0`" vs la tabla 0x7007e0 (índice 29); assets.md y traffic.md usan
   el índice real. (V capstone)
2. **9 vs 11 perf paths**: garage.md:11,13,41 dice 9 paths (0..8); tuning.md:16 y garage.md:121 dicen `level[11]`;
   0x5a0350 mapea 11 entradas (9→8, 10→5). El chooser muestra 9, pero el modelo de datos tiene 11. (V capstone)
3. **Referencias obsoletas**: garage.md:10 y canon.md:193 siguen diciendo que tuning.md afirma "No prices"; tuning.md:23 ya
   está corregido. (lectura de docs)
4. **systems.tsv vs names.tsv**: de las 886 funciones con nombre que son inicio de función levantada, **419 (47 %)** tienen en
   systems.tsv un sistema distinto del de names.tsv (tras normalizar sound→audio, tuning/garage→car, blur→render, subsistemas
   `x.y`→`x`). Ejemplos: `OrbitCarCameraMover::ctor 0x4840c0` → track (low); `TrafficCar_HonkAtPlayer 0x44c2e0` → rivals
   (high); `GarageMainScreen::SetRideInfo 0x4b0e50` → canon (high); `Mesh_Load 0x40c690` → track. (script propio)
5. **Mismo address, nombres distintos** en names_*.tsv (6 casos; la fusión eligió casi siempre el de assets):
   0x472c60 `CollisionShapes::FindByKey` (props) vs `CarShape_Find` (assets, ganó; engañoso, 77 de 88 formas son props);
   0x5a0060 canon vs assets; 0x59fb80; 0x5a3570; 0x47af20; 0x40a880 `NullUpdate_ret` (camera, ganó) vs nullsub compartido
   de 510 refs (sound; más exacto: también es el slot 1 de la vtable de TrafficAI).
6. **Atribución de sistema**: 0x5952a0 (loader de smackables, núcleo de props.md) está en names.tsv como `assets`.

## 3. Inferencias presentadas como hecho

- **Unidades**: blur.md "25 m/s = 90 km/h" y tuning.md "a 160" (eje de las tablas de dirección) asumen m/s y km/h; el
  binario solo da números. Falta: identificar la unidad de la velocidad que se pasa a 0x583ea0 desde 0x460a80.
- **"Todos los tiempos de la IA son 4000 ticks/s"** (rivals.md:32): 0x6cca38 tiene 260 referencias en todo el binario; es
  un reloj global, no algo de la IA. La afirmación es cierta pero mal acotada.
- **Skill en +0x735 y agresión en +0x736**: el ctor solo copia arg5/arg6; cuál es cuál depende de los valores del llamador.
  Marcado V en el doc; para respaldarlo hace falta leer qué lee cada campo (el rubber band usa skill).
- **"Tipo 0x11 es el default enviado"** (camera.md): estático y bien respaldado, pero solo excluye escrituras por dirección
  absoluta; una escritura por base+offset (p. ej. un bloque de opciones) no está descartada. Falta un trace RN_TRACE de
  escrituras a 0x700aa4 o un xref Ghidra de la estructura que lo contiene.
- **"V = una segunda herramienta coincide"** (re_scoreboard §5): ~42 de 848 filas V en names_*.tsv citan una sola
  herramienta (p. ej. 0x447ab0 "capstone V", 0x447f40 "hopper V", 0x449765 "hopper V"). Heurística de texto; la cifra es
  aproximada.
- **"Etiquetas erróneas ~8–12 %"** (systems_method.md): la muestra estricta acuerda 19/50 (38 %); el resto es "plausible",
  "inverificable" o "unknown". El 47 % de desacuerdo con names.tsv sugiere que el error real es mayor.
- **0x5a1100**: la redacción "abre…" oculta que primero cierra todos los abiertos y que hay una segunda fuente de eventos
  (`+0x88b0`→`+0x58a0`).

## 4. Scoreboard y entregables M1–M6

- `python3 tools/census/scoreboard.py --md` reproduce **exactamente** la tabla de re_scoreboard.md §5 (13,739 / 12,179 /
  6,038 / 886 / 728).
- **M1 (cobertura)**: la unión 6,038 se reproduce desde los bitmaps crudos `build/cov/*.bin` (OR de 12 bitmaps = 6,038 bits).
  Pero `census/cov/<s>.json` solo guardan conteos, no direcciones: la unión no es reproducible desde census/ si se limpia
  build/. No corrí el juego: `cov_run.py` escribe en census/cov y build/cov (fuera de mi alcance de escritura), y los bitmaps
  ya permitían verificar.
- **M2 (systems.tsv)**: 11,901 de 17,368 filas tienen confianza `low`; la meta de acuerdo 40/50 no se cumplió (el propio doc lo dice).
- **M5**: la columna `tagged` es igual a `lifted` en todos los sistemas por construcción (todo lo que no es unknown cuenta
  como etiquetado), así que no informa nada. `diff-tested` es U en todos: §5 tiene 3 de los 4 números del brief.
- **M3**: names.tsv tiene 1,039 filas, de las cuales 153 son etiquetas de datos o direcciones internas (tablas de salto,
  constantes del teleporter, casos de switch); solo 886 son funciones. Los "conteos V/I/U" de names.tsv mezclan ambas cosas.
- El esquema de names.tsv llama `confidence` a la marca V/I/U, mientras que el brief pide "evidencia V y confianza med/high".

## 5. Recomendaciones (por prioridad)

1. **Reconciliar systems.tsv con names.tsv** antes de citar números por sistema: un nombre V con doc debe sobreescribir la
   etiqueta del grafo. Después, recalcular §5 y mostrar `tagged` solo con confianza med/high (hoy es tautológica).
2. **Hacer real el 4.º número**: que difftest.json guarde el resultado por función (dirección → igual/distinto), para que
   `diff-tested` deje de ser U.
3. **Aplicar la regla V en la fusión**: names_merge.py debería rechazar o bajar a I las filas V con una sola herramienta, y
   separar en otro archivo las etiquetas de datos (153 filas) de los nombres de función.
4. **Un lint de docs contra el binario**: generar la tabla de loaders (índice→dirección) desde 0x7007e0 y validar cada
   "loader N 0xADDR" en docs/re; con el mismo script, marcar referencias cruzadas obsoletas (garage.md:10, canon.md:193) y
   el conflicto 9/11 paths.
5. **Marcar como I las unidades y generalizaciones** (m/s, km/h, eje "160", "4000 ticks en la IA", skill/agresión) y guardar
   los bitmaps por escenario en census/cov para que M1 sea reproducible sin build/.
