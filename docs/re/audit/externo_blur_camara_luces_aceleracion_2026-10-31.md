# Auditoría externa: blur, luces, cámara y aceleración

Consultor independiente, sin acceso de escritura. Fecha: 2026-10-31.
Alcance: los cuatro síntomas que reporta el OWNER jugando :5180 en Remaster, medidos contra la
evidencia que dejó su propia sesión. No se abrió el juego, no se ejecutó ningún build y no se
leyó Speed.exe en esta auditoría: todo lo que sigue sale de artefactos de la sesión y del repo.

## 0. Fuentes

| Qué | Dónde |
|---|---|
| Capturas | `~/Desktop/Screenshot 2026-10-31 at 8.56.39 a.m..png`, `...8.56.50 a.m..png` (garaje, SELECT CAR) |
| Video | `~/Desktop/Screen Recording 2026-10-31 at 8.59.09 a.m..mov` (30.28 s, 3828x1864, 60 fps) |
| Telemetría | `~/Downloads/nfsu-session-2026-10-31T14-56-05-130Z.json` (14.234 muestras, 104 eventos, 787 líneas de log) |
| Código y datos | `web/tune.js`, `web/gpu.js`, `web/mode.js`, `host/d3d9.c`, `host/rivals.c`, `tools/recomp/patches.py` |
| Docs | `docs/re/blur.md`, `docs/re/camera_chase.md`, `docs/re/physics.md`, `docs/re/flare_re.md`, `docs/re_scoreboard.md`, `docs/driving_patches.md` |

## 1. Convenciones y límites de la evidencia

Tres marcas, respetadas en todo el texto:

- **HECHO**: está escrito literalmente en el log, en los bytes o en el código citado. Reproducible.
- **LECTURA**: consecuencia de un cálculo sobre datos documentados. Depende de que la fórmula
  documentada sea correcta.
- **HIPÓTESIS**: explica los datos, pero no se puede separar de otras explicaciones con la
  evidencia disponible.

Límites que condicionan lo sostenible:

1. El video es una captura de pantalla de 3828 px de un back buffer de 2560x1116 (el log imprime
   `present 2560x1116`). Todo lo que se vea suave o con halo está contaminado por ese escalado de
   1.5x. **No es una fuente válida para juzgar nitidez ni tamaño de halo.**
2. El muestreo fue a 1 fps. La correlación entre un frame del video y una línea del log tiene un
   margen de ±2 s. La lectura del velocímetro en un frame temprano (74 mph) no cuadró con el log
   (~31 mph equivalente); ese desajuste quedó sin resolver y no se usa como prueba.
3. No hay captura del modo Original en el mismo punto. Sin ese par, "se ve agresivo" no tiene
   contra qué medirse salvo los números.
4. No se verificó byte a byte que ningún patch toque física. Se verificó la tabla declarada y sus
   comentarios, que es lo que el repo afirma de sí mismo.

## 2. Cómo se generó la evidencia

- Las capturas muestran el garaje, no la conducción. Sirven para luces en reposo, no para cámara
  ni blur.
- El video cubre los últimos 30 s de la sesión: un arranque desde parado, una subida a fondo y una
  salida de ruta.
- El JSON contiene la línea del banco de blur, las filas de cámara al cargar y una línea `JC` por
  segundo con velocidad, posición y el valor de la tabla de FOV. Esa parte no es interpretación:
  es lo que el build imprimió.

## 3. Blur

**HECHO.** La primera aplicación del banco imprime:

```
d3d9 blur bank: ramp 0.10-25.00 m/s, cap 0.260, streak 0.00625, trails 1fbc9e71
```

Ese conjunto coincide con la entrada `#3 "PS2"` de `web/tune.js:12` (ramp `[0.1, 25]`, `cap 0.26`,
`trails 1.5`). No coincide con `BLUR_DEFAULT = 6` ("PS2 depth", `web/tune.js:20`), que escribiría
`cap 0` y activaría el paso propio del port (`RN_PS`).

**HIPÓTESIS sobre el origen.** La elección de F6/F7 se persiste en `localStorage`
(`web/tune.js:41-42, 70`) y gana sobre el default. Es plausible que el preset observado venga de
una sesión anterior y no de una decisión de hoy. No se puede probar sin saber si alguien pulsó
F6/F7 a propósito. Si fue deliberado, esta parte de la auditoría cae y queda solo la discusión de
valores.

**LECTURA (aritmética sobre `docs/re/blur.md`).** Con `t = clamp((v-ramp0)/(ramp1-ramp0))`, tope
`cap`, y peso `w = min(1.5·t, 1)`:

| Velocidad | Preset activo (0.1→25, cap 0.26) | Original PC (`?blur=5`: 25→125, cap 0.65) |
|---|---|---|
| 9 mph | t 0.157, w **0.235** | t 0, w 0 |
| 60 mph | t 1.00, w **0.39** | t 0.018, w 0.027 |
| 100 mph | w 0.39 | w 0.295 |
| 148 mph | w 0.39 | w 0.62 |

Dos consecuencias a discutir:

- A velocidad de crucero urbano el peso es del orden de diez veces el del original.
- A fondo es **menor** que el del original. La rampa del PC crece con la velocidad; la que está
  corriendo se agota a 56 mph.

Si la lectura es correcta, el problema no es "blur demasiado agresivo" en abstracto sino un blur
**desplazado hacia abajo en velocidad**. Eso explicaría por qué en el garaje no molesta y en calle
sí.

**Falta para cerrarlo.** Un A/B del mismo frame con `?blur=0`, `?blur=5` y `?blur=6` capturado a
2560x1116, no desde el video. Es la única forma de separar "el peso calculado es alto" de "el peso
calculado se ve mal".

## 4. Luces

**HECHO.** Hay dos capas nuestras sobre el flare del juego, ninguna del original:

- `PATCH 0x409bdb` con `s = 1.5`: una luz quieta suma 1.5 veces su propio flare, cada frame
  (`tools/recomp/patches.py:129-143`). El log confirma el color aplicado: `trails 1fbc9e71`.
- Bloom de puente: bright pass a luma 0.72, gauss de ±16 px a resolución completa, sumado con peso
  0.2 (`web/gpu.js:357-427`).

**HECHO.** El documento que describe ese bloom dice literalmente `NOT VERIFIED on screen`
(`docs/flare_re.md:40-41`), y el comentario del código lo declara puente, no original.

**HIPÓTESIS principal.** Flare grande del juego (hasta 1.44 m de medio lado, `docs/flare_re.md`),
más 1.5x de brillo, más halo de 16 px, más el smear radial del blur a velocidad, producen la
lectura de "luz con estela / astigmatismo". Explicaciones rivales que no se pueden descartar: el
flare del propio juego ya es grande por diseño, y el escalado del video ablanda todo.

**Cómo se discrimina.** `?bloom=0` en el mismo punto con la misma luz en cuadro, a 1:1. Si el
halo persiste, es el flare y el 1.5x. Si desaparece, es el bloom y ahí hay una decisión de look.

**Dato que apunta lejos del blur.** En la captura del 350Z el remate trasero aparece como una
mancha roja alargada con el auto parado. A velocidad cero no hay motion blur, así que ese caso
concreto apunta a flare más bloom.

## 5. Cámara

**HECHO.** El build trae tres perillas encendidas por default (`web/tune.js:28-32`):
`SPEEDFOV = 10`, `CHASECAM = 1`, `NITROCAM = 1`. El modo Original las apaga (`web/mode.js:14-16`).

**HECHO.** El log muestra la tabla de FOV del juego moviéndose con la velocidad:

- `fov 13020` = 71.50° a baja velocidad.
- `fov 14651` = **80.48°** a 66.4 m/s.

Son unos 9° ganados entre 90 y 270 km/h, escritos en la tabla del propio motor (`0x6fbdf4`), que
`0x48bbed` lee cada frame.

**HECHO.** Al cargar la carrera el hook imprime las filas de cámara del auto:
`dist -5.80 -4.70 -5.80 height 1.70 1.70 3.45`.

**LECTURA, con supuesto declarado.** Si el hook aplica lo que dice su comentario
(`host/d3d9.c:875-886`: distancia ×(1+0.12·t), altura ×(1−0.10·t)), a fondo la cámara queda a
−6.50 m y 1.53 m. Tomando 0.9 m como altura del techo, el ángulo de mirada pasa de unos 7.9° a
unos 5.5°, y el auto encoge del orden de un 25% en pantalla. El 0.9 m es supuesto propio; el resto
sale de las constantes del código.

**No verificado.** No se vieron en el log las filas ya multiplicadas: se ven las originales al
cargar y se leen las constantes. La forma limpia de convertirlo en HECHO es que la línea `CHASE` se
repita cada segundo durante un arranque.

**¿RE o gusto?** La mecánica tiene RE real y documentado (`docs/re/camera_chase.md`: mover 0x11,
`0x48b8c0` SetDesired, filas en `CarTypeInfo+0xb50`, promedio móvil `0x48ec00`, tabla FOV
`0x6fbdf4`). Los tres coeficientes son elección, y el doc no los presenta como otra cosa.

**Lectura del síntoma.** "El auto pierde protagonismo, el ángulo baja" es el efecto esperado de
las tres perillas juntas, no un defecto de implementación. Si el equipo ya hizo un A/B y decidió
mantenerlas, la conversación es de composición y no de bug.

## 6. Aceleración

**HECHO.** De la línea `JC` por segundo, con el campo de velocidad y las posiciones:

- Un arranque desde parado llega a 27.4 unidades a los 3.2 s (otro arranque: 2.5 s).
- Las posiciones confirman la unidad: entre dos muestras el auto recorre del orden de 47 a 68
  unidades por segundo, y el HUD marca 143 mph cuando el campo dice 65.3. Eso hace consistente que
  el campo esté en m/s y el HUD use 2.237, como documenta `host/d3d9.c:972`.
- El paso de física es fijo de 1/60 y cada 60 frames del log caen en 1.00 s de reloj de pared. No
  hay compresión de tiempo. **Descarta** que el simulador corra más rápido que el original.

**HECHO.** Ningún patch declarado toca torque, caja ni arrastre (`docs/driving_patches.md`; tabla
revisada). El único cambio de conducción es el agarre trasero `0x6ffdd4` 0.35 → 0.18
(`host/rivals.c:526-535`), que es lateral.

**HECHO.** `docs/re/physics.md` cierra la sección del motor con
`Gears and clutch 0x46d9f0/0x46e020; not re-read here`, y agrega "No run was made". El scoreboard
marca tuning como el sistema más débil: `no PC doc for parts/upgrade tables`.

**Conclusión honesta.** No hay evidencia de que la aceleración esté mal, ni de que esté bien:
**no existe una medición de referencia del original** para la misma nave. Lo sostenible es que el
número es reproducible y que el reloj no está acelerado.

**Sospechoso ni confirmado ni descartado.** `PATCH 0x735ec1` hace que el juego reporte todos los
upgrades de performance comprados y desbloqueados (`tools/recomp/patches.py:67-71`). Si el auto de
la carrera hereda esos valores, la nave estaría efectivamente al máximo y 0-60 en 3 s sería
coherente. "Comprado" no es necesariamente "instalado": es hipótesis, no hallazgo.

**Cómo se cierra con un número.** Mismo auto, mismo punto, mismo instante de gas: una pasada en
Remaster, una en Original (F4) y una con `RN_UNLOCK=0`.

## 7. Hallazgo lateral que conviene no confundir con el blur

En el video, a 9 mph aparece una nube blanca grande sobre la calle que desaparece a 29 mph. Si
fuera blur, a 29 mph estaría **más** fuerte, no menos. **HIPÓTESIS:** humo de partículas por
deslizamiento de rueda al arrancar, que este auto produce por lo rápido que sale. No se afirma:
se menciona porque, si alguien está apuntando al blur en ese frame, está apuntando a otro objeto.
Se discrimina con `?blur=0` en el mismo arranque.

Contexto adicional: la sesión transcurre en **WORLD (id 1010)**, no en una carrera. A los 201 s el
auto sale de la ruta (`nodes 1`, `last 0 m`) y sigue a 66 m/s por ciudad vacía hasta despegar.
Parte del "sin ambiente" puede ser eso y no la cámara.

## 8. Lo que no se puede sostener

- No se puede decir que el blur se vea mal. Sí que el peso calculado es alto con el preset activo,
  y que ese preset no es el default declarado.
- No se puede decir que el bloom sea la causa del "astigmatismo". Sí que es una capa que el
  original no tiene y que nunca se validó en pantalla.
- No se puede decir que las perillas de cámara estén mal elegidas. Sí que están encendidas, cuánto
  mueven la composición y que explican el síntoma sin otro culpable.
- No se puede decir que la aceleración sea incorrecta. Sí que no hay contra qué compararla.
- No se verificó el render a 1:1 ni el modo Original, que es donde se decidiría todo esto.

## 9. Propuesta de verificación, por costo

1. **Confirmar el preset.** Si el 3 fue elección o residuo. Si es residuo, el arreglo es de higiene
   (resetearlo o mostrar el preset activo), no de render.
2. **Tres capturas a 1:1 del mismo frame**: `?blur=0`, `?blur=5`, `?blur=6`. Con eso el blur pasa
   de discusión a decisión.
3. **Una captura con `?bloom=0`** sobre la misma luz. Separa bloom de flare.
4. **A/B de cámara** con las tres perillas en 0 y las tres en 1, misma curva, mismo frame.
5. **Un log `CHASE` por segundo durante un arranque**, para que las filas multiplicadas sean HECHO.
6. **0-60 en Original vs Remaster, y con `RN_UNLOCK=0`**, antes de abrir la caja en RE.

Si los pasos 2 a 4 muestran que el Remaster gusta más con las capas apagadas, la conversación
cambia de "arreglar un bug" a "elegir un look", y la decisión es del OWNER con la evidencia a la
vista.

## 10. Pregunta abierta para el equipo

¿Existe ya un par de capturas del mismo tramo en Original y Remaster con el auto a la misma
velocidad? Si ese par existe, la auditoría de cámara y luces es redundante y conviene verlo antes
de proponer nada más.

Cierre: el trabajo de RE detrás de blur y cámara es real y está documentado con direcciones; lo
que falta no es RE sino **una medición de referencia del original** para aceleración, y **una
validación en pantalla** para el bloom. Las otras dos quejas se explican con valores elegidos que
están encendidos, y eso se decide mirando un A/B, no leyendo más código.
