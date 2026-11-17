"""Devlog posts for tools/build_blog.py (OWNER 2026-11-17: posts on what was built and the tools, for people who search RE and decomp,
not only the game; GitHub repo linked; AI agents get their own post). Same rules as the guides: every number names its source above the post."""

REPO = "https://github.com/Caliko06/RE-NFSU"
DEV_DATE = "2026-11-17"

DEV = [
    # Sources: tools/recomp/lift.py docstring (Capstone, f_<addr>(Ctx*), registers and flags as C locals, rn_call, TRAP);
    # tools/recomp/build.py (clang -O2 native, emcc -O2 -pthread web, 160 chunks); census/lift_report.json at 66f2660 (13,760 functions,
    # 106 ABK files, 79 modules, 28 ABK functions); host/abk.c; tools/recomp/difftest.py docstring (Unicorn oracle, random inputs, registers,
    # x87 TOP and st(0), all memory); census/difftest.json (5,805 compared, 5,802 all match, 32,131 matching cases, 3 functions with mismatches);
    # first commit 2026-10-19 "first lifter slice checked against Unicorn (1403 functions match)"; patches tools/recomp/patches_*.py.
    dict(key="recomp", img="olympic-city-drive.webp", dev=True,
         slug=dict(en="static-recompilation-x86-to-webassembly", es="recompilacion-estatica-x86-a-webassembly"),
         title=dict(en="Static recompilation: turning a 2003 x86 .exe into WebAssembly", es="Recompilación estática: convertir un .exe x86 de 2003 en WebAssembly"),
         desc=dict(en="How the NFSU.cc lifter reads Speed.exe with Capstone, writes every one of its 13,760 functions as C, compiles them with Emscripten and checks them bit for bit against Unicorn.",
                   es="Cómo el traductor de NFSU.cc lee Speed.exe con Capstone, escribe cada una de sus 13,760 funciones en C, las compila con Emscripten y las compara bit a bit contra Unicorn."),
         alt=dict(en="Olympic City at night, drawn by the recompiled game", es="Olympic City de noche, dibujada por el juego recompilado"),
         cap=dict(en="Every frame here comes from functions lifted out of the 2003 executable.", es="Cada cuadro sale de funciones traducidas del ejecutable de 2003."),
         lead=dict(en="There is no source code for Need for Speed Underground. There is one Windows program, Speed.exe, and a tool that rewrites it, function by function, into code a browser can run.",
                   es="No existe el código fuente de Need for Speed Underground. Existe un programa de Windows, Speed.exe, y una herramienta que lo reescribe, función por función, en código que un navegador puede ejecutar."),
         body=dict(en="""
<h2>Emulate or translate?</h2>
<p>An emulator reads each x86 instruction while you play and imitates it. That costs time on every frame, forever. Static recompilation pays once: before the page exists, a tool reads the whole program and writes the same logic in another language. When you open the site, the translation is already done.</p>
<h2>The lifter</h2>
<p>The lifter is a Python program (<a href="REPO/blob/main/tools/recomp/lift.py">tools/recomp/lift.py</a>). It opens the executable with <b>pefile</b>, disassembles it with <b>Capstone</b> and writes every guest function as one C function:</p>
<ul>
<li>The eight x86 registers and the flags become C local variables, written back to a shared context only at calls and exits, so the C compiler can optimize them like normal code.</li>
<li>A direct call becomes a direct C call. An indirect call or jump, through a pointer the game computes, goes through one lookup table from guest address to function.</li>
<li>An instruction the lifter does not know becomes a <b>TRAP</b>: if it ever runs, the game stops and prints its address. Nothing is guessed.</li>
</ul>
<p>The list of functions comes from a census of the executable. Today the lifter writes 13,760 of them into 160 chunks of C, and <code>clang</code> (for a native test build) or <code>emcc</code> (Emscripten, for the browser) compiles them with <code>-O2</code>.</p>
<h2>Code that hides in the data</h2>
<p>Not all of the game's code lives in Speed.exe. Its sound engine loads small x86 modules out of the <code>.abk</code> sound banks at run time and relocates them in memory. A static translator never sees that code in the executable, so a second pass reads all 106 sound banks, finds 79 code modules (28 distinct functions) and lifts them ahead of time. At run time the host recognizes a live copy by its header and calls the lifted version.</p>
<h2>Proving it, bit for bit</h2>
<p>A translation is only useful if it is exact. <a href="REPO/blob/main/tools/recomp/difftest.py">difftest.py</a> runs each lifted function next to <b>Unicorn</b>, a reference x86 CPU, on random inputs. Both stop at the first Windows call or at the return, and every register, the x87 floating point stack and all of memory are compared. In the last full run, 5,802 of the 5,805 functions it could reach matched on every case (32,131 matching cases); the three that differ are listed by address. Unicorn is only a test oracle: it never ships in the game.</p>
<p>The first day of the project already ended with 1,403 functions matching Unicorn, and the same day the recompiled program started in Chrome and asked for Direct3D.</p>
<h2>Changing the game without editing the game</h2>
<p>Fixes and options are patches applied while lifting: small files such as <code>patches_render.py</code> or <code>patches_input.py</code>, one line per patch, each with the address it changes and the reason. The original bytes stay in the executable, and the Original 2003 version runs as shipped.</p>
<h2>Read the code</h2>
<p>The lifter, the tests and the patch files are on <a href="REPO">GitHub</a>. The next piece is what answers the game when it calls Windows: <a href="[[host]]">DirectX 9 and Windows rebuilt for the browser</a>.</p>
""", es="""
<h2>¿Emular o traducir?</h2>
<p>Un emulador lee cada instrucción x86 mientras juegas y la imita. Eso cuesta tiempo en cada cuadro, para siempre. La recompilación estática paga una sola vez: antes de que exista la página, una herramienta lee todo el programa y escribe la misma lógica en otro lenguaje. Cuando abres el sitio, la traducción ya está hecha.</p>
<h2>El traductor</h2>
<p>El traductor es un programa en Python (<a href="REPO/blob/main/tools/recomp/lift.py">tools/recomp/lift.py</a>). Abre el ejecutable con <b>pefile</b>, lo desensambla con <b>Capstone</b> y escribe cada función del juego como una función de C:</p>
<ul>
<li>Los ocho registros x86 y las banderas se vuelven variables locales de C, que se escriben de vuelta a un contexto compartido solo en llamadas y salidas; así el compilador las optimiza como código normal.</li>
<li>Una llamada directa se vuelve una llamada directa de C. Una llamada o salto indirecto, por un puntero que calcula el juego, pasa por una tabla que va de dirección del juego a función.</li>
<li>Una instrucción que el traductor no conoce se vuelve un <b>TRAP</b>: si alguna vez se ejecuta, el juego se detiene e imprime su dirección. Nada se adivina.</li>
</ul>
<p>La lista de funciones sale de un censo del ejecutable. Hoy el traductor escribe 13,760 en 160 bloques de C, y <code>clang</code> (para una versión nativa de pruebas) o <code>emcc</code> (Emscripten, para el navegador) los compila con <code>-O2</code>.</p>
<h2>Código escondido en los datos</h2>
<p>No todo el código del juego vive en Speed.exe. Su motor de sonido carga pequeños módulos x86 desde los bancos de sonido <code>.abk</code> mientras corre y los reubica en memoria. Un traductor estático nunca ve ese código en el ejecutable, así que una segunda pasada lee los 106 bancos, encuentra 79 módulos de código (28 funciones distintas) y los traduce por adelantado. Al correr, el host reconoce una copia viva por su encabezado y llama a la versión traducida.</p>
<h2>Probarlo, bit a bit</h2>
<p>Una traducción solo sirve si es exacta. <a href="REPO/blob/main/tools/recomp/difftest.py">difftest.py</a> corre cada función traducida junto a <b>Unicorn</b>, un CPU x86 de referencia, con entradas aleatorias. Los dos se detienen en la primera llamada a Windows o en el retorno, y se comparan todos los registros, la pila de punto flotante x87 y toda la memoria. En la última corrida completa, 5,802 de las 5,805 funciones que alcanzó coincidieron en todos los casos (32,131 casos iguales); las tres que difieren quedan anotadas por dirección. Unicorn es solo un oráculo de prueba: nunca va dentro del juego.</p>
<p>El primer día del proyecto ya terminó con 1,403 funciones iguales a Unicorn, y ese mismo día el programa recompilado arrancó en Chrome y pidió Direct3D.</p>
<h2>Cambiar el juego sin editar el juego</h2>
<p>Las correcciones y opciones son parches que se aplican al traducir: archivos pequeños como <code>patches_render.py</code> o <code>patches_input.py</code>, una línea por parche, cada una con la dirección que cambia y el porqué. Los bytes originales se quedan en el ejecutable, y la versión Original 2003 corre como salió de fábrica.</p>
<h2>Lee el código</h2>
<p>El traductor, las pruebas y los parches están en <a href="REPO">GitHub</a>. La siguiente pieza es lo que le responde al juego cuando llama a Windows: <a href="[[host]]">DirectX 9 y Windows reconstruidos para el navegador</a>.</p>
""")),

    # Sources: AGENTS.md (REA MCP + a second tool on every value; census V/I/U; Hopper census/hopper/decomp.c; Ghidra headless census/ghidra/ in 4 address
    # ranges; objdump); census/names_*.tsv = 55 files, 10,742 rows (wc at 2026-11-17); census/speed_exe_functions.tsv 14,330 rows;
    # RN_TRACE in host/d3d9.c header; menu action table 0x7032d8 action Back 0x17 docs/re/hud_input.md:47, census/names_input.tsv:16, HANDOFF 2026-11-15 (Esc + Backspace); tools/recomp/trapreach.py; docs/re/ (one note per system: ai_*, camera_*, gameflow, hosting...).
    dict(key="retools", img="olympic-city-world.webp", dev=True,
         slug=dict(en="reverse-engineering-tools-ghidra-hopper-rea", es="herramientas-ingenieria-inversa-ghidra-hopper-rea"),
         title=dict(en="The reverse engineering toolbox: Ghidra, Hopper, REA and a census of names", es="La caja de herramientas de ingeniería inversa: Ghidra, Hopper, REA y un censo de nombres"),
         desc=dict(en="Which disassemblers and decompilers were used to understand Need for Speed Underground, and the one rule that kept the work honest: no address is trusted until two tools agree.",
                   es="Qué desensambladores y descompiladores se usaron para entender Need for Speed Underground, y la regla que mantuvo honesto el trabajo: ninguna dirección vale hasta que dos herramientas coinciden."),
         alt=dict(en="A street in Olympic City from the recompiled game", es="Una calle de Olympic City en el juego recompilado"),
         cap=dict(en="Every option on this site touches an address someone had to read first.", es="Cada opción de este sitio toca una dirección que alguien tuvo que leer primero."),
         lead=dict(en="Recompiling a game makes it run. Changing it, fixing it or adding options means understanding it, and a 2003 executable comes with no names, no symbols and no comments.",
                   es="Recompilar un juego lo hace correr. Cambiarlo, corregirlo o agregarle opciones exige entenderlo, y un ejecutable de 2003 llega sin nombres, sin símbolos y sin comentarios."),
         body=dict(en="""
<h2>The tools</h2>
<ul>
<li><b>Ghidra</b>, run headless from scripts: the whole executable decompiled to C-like code in four address ranges, saved as text so any search tool can read it.</li>
<li><b>Hopper</b>, a disassembler for macOS: a second decompiler with its own opinion of each function, exported the same way.</li>
<li><b>REA</b>, a reverse engineering server that AI agents talk to over MCP (Model Context Protocol): open the binary, read a function's pseudocode, list who calls an address, read raw bytes.</li>
<li><b>objdump</b> and <b>Capstone</b> for the plain instruction listing, the last word when the decompilers disagree.</li>
<li><b>The running game</b>: a trace switch logs every Windows and DirectX call with its arguments, so a guess about a function can be checked against what it really does.</li>
</ul>
<h2>Two tools or it does not count</h2>
<p>Decompilers are wrong in small ways: a missed argument, a float read as an integer, a jump table cut short. So the project has one rule: every value, file format or patch names what proves it (an address in the executable, a chunk id in a data file, a line in the code), read with REA plus a second tool. What is not proven is written down as UNKNOWN, and nothing is built on it.</p>
<h2>A census instead of a wiki</h2>
<p>Names are stored as plain tables, one per system: cars, camera, collision, menus, audio, the rival AI. Each row is an address, a name and a mark: <b>V</b> when it was read in the code, <b>I</b> when it was inferred, <b>U</b> when unknown. Today there are 55 of those tables with 10,742 rows, next to a census of the 14,330 function entries in Speed.exe. A table can be grepped, diffed and checked by a script; a page of prose cannot.</p>
<h2>An example</h2>
<p>The phone controls needed a BACK button. Instead of faking a key press and hoping, the input code was read until the menu's action table showed up (address 0x7032d8): one of its actions is Back, and its keys are Escape and Backspace. The touch button sends exactly that key, and the game does the rest the way it did in 2003.</p>
<h2>Notes per system</h2>
<p>Each investigation leaves a short note in <code>docs/re/</code>: how the camera follows the car, how rivals choose a line, how the game loads a track. They are maps for the next person, not essays. All of it is on <a href="REPO">GitHub</a>. The work itself was done with AI agents under these rules: <a href="[[agents]]">how that worked</a>.</p>
""", es="""
<h2>Las herramientas</h2>
<ul>
<li><b>Ghidra</b>, sin ventana, desde scripts: todo el ejecutable descompilado a un código parecido a C en cuatro rangos de direcciones, guardado como texto para que cualquier buscador lo lea.</li>
<li><b>Hopper</b>, un desensamblador para macOS: un segundo descompilador con su propia opinión de cada función, exportado igual.</li>
<li><b>REA</b>, un servidor de ingeniería inversa con el que hablan los agentes de IA por MCP (Model Context Protocol): abrir el binario, leer el pseudocódigo de una función, ver quién llama a una dirección, leer bytes crudos.</li>
<li><b>objdump</b> y <b>Capstone</b> para la lista simple de instrucciones, la última palabra cuando los descompiladores no coinciden.</li>
<li><b>El juego corriendo</b>: un interruptor de traza registra cada llamada a Windows y DirectX con sus argumentos, para comparar una suposición sobre una función con lo que de verdad hace.</li>
</ul>
<h2>Dos herramientas o no cuenta</h2>
<p>Los descompiladores se equivocan en cosas pequeñas: un argumento perdido, un número decimal leído como entero, una tabla de saltos cortada. Por eso el proyecto tiene una regla: cada valor, formato de archivo o parche nombra lo que lo prueba (una dirección del ejecutable, un id de bloque en un archivo de datos, una línea del código), leído con REA más una segunda herramienta. Lo que no está probado se escribe como UNKNOWN, y nada se construye encima.</p>
<h2>Un censo en vez de una wiki</h2>
<p>Los nombres se guardan como tablas simples, una por sistema: coches, cámara, colisiones, menús, audio, la IA de los rivales. Cada fila es una dirección, un nombre y una marca: <b>V</b> si se leyó en el código, <b>I</b> si se dedujo, <b>U</b> si se desconoce. Hoy hay 55 tablas con 10,742 filas, junto a un censo de las 14,330 entradas de función de Speed.exe. Una tabla se puede buscar, comparar y revisar con un script; una página de prosa no.</p>
<h2>Un ejemplo</h2>
<p>Los controles de celular necesitaban un botón ATRÁS. En vez de simular una tecla y esperar que funcione, se leyó el código de entrada hasta encontrar la tabla de acciones del menú (dirección 0x7032d8): una de sus acciones es Back, y sus teclas son Escape y Retroceso. El botón táctil manda exactamente esa tecla, y el juego hace el resto como en 2003.</p>
<h2>Notas por sistema</h2>
<p>Cada investigación deja una nota corta en <code>docs/re/</code>: cómo la cámara sigue al coche, cómo eligen línea los rivales, cómo carga el juego una pista. Son mapas para el siguiente, no ensayos. Todo está en <a href="REPO">GitHub</a>. El trabajo lo hicieron agentes de IA bajo estas reglas: <a href="[[agents]]">así funcionó</a>.</p>
""")),

    # Sources: host/win32.c header (Windows XP SP2, one CPU, code page 1252, C:\\NFSU); host/d3d9.c header (ATI RADEON 9800 PRO 128 MB HAL, vtable
    # slots as host functions, missing method stops loudly); host/gpu.c + web/gpu.js headers (frame command list, mailbox in the shared heap,
    # WebGPU on the page's thread); host/sm1.c (shader model 1 -> WGSL); host/dsound.c + web/audio.js (software mixer 44.1 kHz, AudioWorklet);
    # host/threads.c (one global lock in ticket order); host/files.c (synchronous XHR byte ranges in a worker); host/dinput8.c; web/saves.js;
    # host/*.c = 14,258 lines (wc 2026-11-17).
    dict(key="host", img="phone-touch.webp", dev=True,
         slug=dict(en="directx-9-and-windows-on-webgpu", es="directx-9-y-windows-sobre-webgpu"),
         title=dict(en="DirectX 9 and Windows XP rebuilt on WebGPU, Web Audio and workers", es="DirectX 9 y Windows XP reconstruidos sobre WebGPU, Web Audio y workers"),
         desc=dict(en="The recompiled game still calls Windows and DirectX. This is the layer that answers: a Radeon 9800 that draws with WebGPU, a sound card made of an AudioWorklet, and a hard drive that lives on a server.",
                   es="El juego recompilado sigue llamando a Windows y DirectX. Esta es la capa que contesta: una Radeon 9800 que dibuja con WebGPU, una tarjeta de sonido hecha con un AudioWorklet y un disco duro que vive en un servidor."),
         alt=dict(en="The browser version on a phone with touch controls", es="La versión de navegador en un celular con controles táctiles"),
         cap=dict(en="The game asks for a keyboard; on a phone the touch layer answers with the key codes it expects.", es="El juego pide un teclado; en un celular la capa táctil contesta con los códigos de tecla que espera."),
         lead=dict(en="Translated code is not enough. The game opens windows, files and sound buffers, and asks for a DirectX 9 card. About 14,000 lines of C and a few JavaScript files answer every one of those calls.",
                   es="El código traducido no basta. El juego abre ventanas, archivos y búferes de sonido, y pide una tarjeta DirectX 9. Unas 14,000 líneas de C y unos cuantos archivos de JavaScript contestan cada una de esas llamadas."),
         body=dict(en="""
<h2>A fake PC from 2003</h2>
<p>The host presents one machine and sticks to it: Windows XP SP2, one CPU, code page 1252, the game installed at <code>C:\\NFSU</code>, and an ATI Radeon 9800 Pro with 128 MB on a 1920x1080 desktop. Each Windows function is written from Microsoft's documentation and knows nothing about the game. If the game calls a method that is not written yet, it stops with that method's name instead of carrying on with a wrong answer.</p>
<h2>Graphics: DirectX 9 to WebGPU</h2>
<p>The game draws through DirectX 9 objects. The host keeps those objects in the game's own memory and records each frame as a compact list of commands. When the game presents a frame, the list is handed through a mailbox in shared memory to the page, which runs it with <b>WebGPU</b>. The game's shaders are shader model 1 bytecode; a small translator decodes them and writes WGSL, the shader language of WebGPU.</p>
<h2>Sound: a software mixer and an AudioWorklet</h2>
<p>DirectSound gives the game sound buffers in its own memory. A mixer thread reads them the way a 2003 sound card read its buffers, at 44.1 kHz, and writes into a ring in shared memory. In the page, an <b>AudioWorklet</b> plays that ring and resyncs when the two clocks drift apart.</p>
<h2>Threads: real ones, one at a time</h2>
<p>The game starts several threads. Each one becomes a real thread (a Web Worker in the browser), but one global lock, handed out in ticket order, lets only one run game code at a time. A thread gives the lock up only where Windows would block it: sleeping, waiting, a busy critical section. The translated code needs no atomics, and the game still sees real threads. Shared memory between workers is why the site is served with cross-origin isolation headers.</p>
<h2>Files: a hard drive on the internet</h2>
<p>The game reads its files with ordinary Windows calls. In the browser, a reading thread turns each read into an HTTP byte range request, synchronous inside its worker, so the game waits exactly as it waited for a 2003 hard drive. How that became fast enough over the internet is its own story: <a href="[[load]]">loading and hosting</a>.</p>
<h2>Input and saves</h2>
<p>DirectInput is rebuilt with one keyboard and one mouse. Gamepads and phone buttons are translated into the keyboard codes the game expects, so its own controls menu still works. The save folder lives in memory and is copied to the browser's storage a moment after each change.</p>
<p>Every file named here is on <a href="REPO/tree/main/host">GitHub</a>.</p>
""", es="""
<h2>Una PC falsa de 2003</h2>
<p>El host presenta una sola máquina y no se sale de ella: Windows XP SP2, un CPU, página de códigos 1252, el juego instalado en <code>C:\\NFSU</code>, y una ATI Radeon 9800 Pro de 128 MB en un escritorio de 1920x1080. Cada función de Windows se escribe desde la documentación de Microsoft y no sabe nada del juego. Si el juego llama a un método que todavía no existe, se detiene con el nombre de ese método en vez de seguir con una respuesta equivocada.</p>
<h2>Gráficos: de DirectX 9 a WebGPU</h2>
<p>El juego dibuja con objetos de DirectX 9. El host guarda esos objetos en la memoria del propio juego y registra cada cuadro como una lista compacta de comandos. Cuando el juego presenta un cuadro, la lista pasa por un buzón en memoria compartida a la página, que la ejecuta con <b>WebGPU</b>. Los shaders del juego son bytecode de shader model 1; un traductor pequeño los decodifica y escribe WGSL, el lenguaje de shaders de WebGPU.</p>
<h2>Sonido: un mezclador por software y un AudioWorklet</h2>
<p>DirectSound le da al juego búferes de sonido en su propia memoria. Un hilo mezclador los lee como una tarjeta de sonido de 2003 leía los suyos, a 44.1 kHz, y escribe en un anillo de memoria compartida. En la página, un <b>AudioWorklet</b> reproduce ese anillo y se resincroniza cuando los dos relojes se separan.</p>
<h2>Hilos: reales, uno a la vez</h2>
<p>El juego arranca varios hilos. Cada uno se vuelve un hilo real (un Web Worker en el navegador), pero un candado global, repartido por turnos, deja que solo uno ejecute código del juego a la vez. Un hilo suelta el candado solo donde Windows lo bloquearía: dormir, esperar, una sección crítica ocupada. El código traducido no necesita operaciones atómicas, y el juego sigue viendo hilos reales. La memoria compartida entre workers es la razón de que el sitio se sirva con aislamiento de origen cruzado.</p>
<h2>Archivos: un disco duro en internet</h2>
<p>El juego lee sus archivos con llamadas normales de Windows. En el navegador, un hilo lector convierte cada lectura en una petición HTTP por rango de bytes, síncrona dentro de su worker, así el juego espera igual que esperaba a un disco duro de 2003. Cómo se volvió lo bastante rápido por internet es otra historia: <a href="[[load]]">carga y hosting</a>.</p>
<h2>Controles y partidas</h2>
<p>DirectInput se reconstruye con un teclado y un ratón. Los mandos y los botones del celular se traducen a los códigos de teclado que el juego espera, así su propio menú de controles sigue funcionando. La carpeta de partidas vive en memoria y se copia al almacenamiento del navegador un momento después de cada cambio.</p>
<p>Cada archivo nombrado aquí está en <a href="REPO/tree/main/host">GitHub</a>.</p>
""")),

    # Sources: host/files.c header (516 requests in a row at 75 ms = most of the 65 s, live 2026-11-16; whole files up to 8 MB);
    # HANDOFF.md 2026-11-16 night (65.7 s -> 28.2 s live cold, 21.4 s second visit, 4 prefetch threads, web/entry_hint.tsv from census/entry_reads.tsv,
    # 66.3 -> 22.7 s on dist at 80 ms RTT with tools/loadcap.mjs); docs/re/hosting.md (R2, egress free, COOP/COEP/CORP, cache rule, 1.95 GB);
    # tools/upload_r2.sh (speed.wasm 70 MB -> ~16 MB gzip); HANDOFF row 3 (songs + movies kept), row Host (pages + scripts no-cache, data 1 day, ?v=<build>);
    # plan.json step 2 row 4 (42.5 MB to the menu).
    dict(key="load", img="olympic-city-drive.webp", dev=True,
         slug=dict(en="hosting-a-2-gb-game-on-cloudflare-r2-load-time", es="alojar-un-juego-de-2-gb-en-cloudflare-r2-tiempo-de-carga"),
         title=dict(en="From 65.7 to 28.2 seconds: hosting a 2 GB PC game on Cloudflare R2", es="De 65.7 a 28.2 segundos: alojar un juego de PC de 2 GB en Cloudflare R2"),
         desc=dict(en="Why a game built for a hard drive was slow over the internet, how one measurement found the cause (516 requests in a row), and the setup that serves 1.95 GB with the music included.",
                   es="Por qué un juego hecho para disco duro era lento por internet, cómo una medición encontró la causa (516 peticiones seguidas) y el montaje que sirve 1.95 GB con la música incluida."),
         alt=dict(en="Driving through Olympic City after the game finished loading", es="Manejando por Olympic City después de que el juego terminó de cargar"),
         cap=dict(en="The first visit downloads only what the game reads; the rest waits until you drive there.", es="La primera visita baja solo lo que el juego lee; lo demás espera hasta que manejas ahí."),
         lead=dict(en="A hard drive in 2003 answered a read in a few milliseconds. A server on the other side of the world answers in tens. The game does not know the difference, and it reads a lot.",
                   es="Un disco duro de 2003 contestaba una lectura en unos milisegundos. Un servidor del otro lado del mundo contesta en decenas. El juego no sabe la diferencia, y lee mucho."),
         body=dict(en="""
<h2>The whole game, music included</h2>
<p>The public pack is 1.95 GB: the recompiled program, the game's data, every licensed song and the movies. Nothing is cut. The program itself, speed.wasm, is about 70 MB and travels gzipped in about 16 MB. The first visit fetches about 42.5 MB to reach the main menu; tracks and cars arrive when the game asks for them.</p>
<h2>Where it is hosted</h2>
<ul>
<li><b>Cloudflare R2</b> holds the files. Downloads from R2 cost nothing, which matters for a 2 GB game.</li>
<li>Three response headers (<code>Cross-Origin-Opener-Policy</code>, <code>Cross-Origin-Embedder-Policy</code>, <code>Cross-Origin-Resource-Policy</code>) turn on cross-origin isolation, which the browser requires before it shares memory between the game's threads.</li>
<li>Pages and scripts are never cached at the edge; game data is cached for a day. Scripts carry the build number in their address, so a new build is never mixed with an old one.</li>
</ul>
<h2>The measurement that found it</h2>
<p>On our heaviest test route, from the link to driving, the live site took 65.7 seconds. The download size was not the problem. A capture of every request showed 516 byte range requests in a row, each waiting about 75 ms for the previous one: the game reads a file, then the next, exactly as it did on a hard drive, and each read now costs a round trip.</p>
<h2>The fix</h2>
<ul>
<li>A file up to 8 MB is fetched whole on its first read and kept, so its later reads cost nothing.</li>
<li>A list of what the game always read on that route, recorded from real visits, let four prefetch threads fetch those files before the game asked.</li>
</ul>
<p>On a test server with an 80 ms delay added to every request, the same route went from 66.3 to 22.7 seconds. On the live site, a first visit went from 65.7 to 28.2 seconds, and a second visit, with the browser's cache warm, to 21.4.</p>
<p>The loader is <a href="REPO/blob/main/host/files.c">host/files.c</a> and the measuring tool is <a href="REPO/blob/main/tools/loadcap.mjs">tools/loadcap.mjs</a>. To see the result, <a href="/">open the game</a>.</p>
""", es="""
<h2>El juego completo, con música</h2>
<p>El paquete público pesa 1.95 GB: el programa recompilado, los datos del juego, cada canción con licencia y los videos. No se recorta nada. El programa, speed.wasm, pesa unos 70 MB y viaja comprimido en unos 16 MB. La primera visita baja unos 42.5 MB para llegar al menú principal; pistas y coches llegan cuando el juego los pide.</p>
<h2>Dónde vive</h2>
<ul>
<li><b>Cloudflare R2</b> guarda los archivos. Descargar desde R2 no cuesta nada, y eso importa para un juego de 2 GB.</li>
<li>Tres encabezados de respuesta (<code>Cross-Origin-Opener-Policy</code>, <code>Cross-Origin-Embedder-Policy</code>, <code>Cross-Origin-Resource-Policy</code>) activan el aislamiento de origen cruzado, que el navegador exige antes de compartir memoria entre los hilos del juego.</li>
<li>Las páginas y los scripts nunca se guardan en la caché del borde; los datos del juego se guardan un día. Los scripts llevan el número de build en su dirección, así una build nueva nunca se mezcla con una vieja.</li>
</ul>
<h2>La medición que lo encontró</h2>
<p>En nuestra ruta de prueba más pesada, del link a manejar, el sitio en vivo tardaba 65.7 segundos. El tamaño de la descarga no era el problema. Una captura de cada petición mostró 516 peticiones por rango seguidas, cada una esperando unos 75 ms a la anterior: el juego lee un archivo, luego el siguiente, igual que en un disco duro, y ahora cada lectura cuesta un viaje de ida y vuelta.</p>
<h2>La solución</h2>
<ul>
<li>Un archivo de hasta 8 MB se baja completo en su primera lectura y se guarda, así sus lecturas siguientes no cuestan nada.</li>
<li>Una lista de lo que el juego siempre leía en esa ruta, grabada de visitas reales, dejó que cuatro hilos de precarga bajaran esos archivos antes de que el juego los pidiera.</li>
</ul>
<p>En un servidor de prueba con 80 ms de retraso agregados a cada petición, la misma ruta pasó de 66.3 a 22.7 segundos. En el sitio en vivo, una primera visita pasó de 65.7 a 28.2 segundos, y una segunda visita, con la caché del navegador caliente, a 21.4.</p>
<p>El cargador es <a href="REPO/blob/main/host/files.c">host/files.c</a> y la herramienta de medición es <a href="REPO/blob/main/tools/loadcap.mjs">tools/loadcap.mjs</a>. Para ver el resultado, <a href="/">abre el juego</a>.</p>
""")),

    # Sources: git log (first commit 2026-10-19, 1,022 commits at 2026-11-17); AGENTS.md (agents choose the method, evidence rule REA + second tool,
    # UNKNOWN, plan.json rows with state + evidence, OWNER verdict, commit after every step, headless muted Chrome checks, tools/webcheck.mjs);
    # ~/.codex/AGENTS.md (Claude, Codex `cdx`, OpenCode + DeepSeek `bec`); difftest as the guard (tools/recomp/difftest.py); REA MCP.
    dict(key="agents", img="olympic-city-world.webp", dev=True,
         slug=dict(en="reverse-engineering-a-game-with-ai-agents", es="ingenieria-inversa-de-un-juego-con-agentes-de-ia"),
         title=dict(en="Reverse engineering a game with AI agents: what worked", es="Ingeniería inversa de un juego con agentes de IA: qué funcionó"),
         desc=dict(en="NFSU.cc went from the first commit to a public site in four weeks, with Claude, Codex and OpenCode agents doing the reading, patching and testing. The rules that kept them from guessing.",
                   es="NFSU.cc pasó del primer commit a un sitio público en cuatro semanas, con agentes de Claude, Codex y OpenCode leyendo, parchando y probando. Las reglas que les impidieron adivinar."),
         alt=dict(en="Olympic City in the browser version of the game", es="Olympic City en la versión de navegador del juego"),
         cap=dict(en="One person decided what to build and judged every result by playing it.", es="Una persona decidió qué construir y juzgó cada resultado jugándolo."),
         lead=dict(en="The first commit is from October 19, 2026. Four weeks and 1,022 commits later, the game was public. One person directed the work; AI coding agents did most of the reading, writing and testing.",
                   es="El primer commit es del 19 de octubre de 2026. Cuatro semanas y 1,022 commits después, el juego era público. Una persona dirigió el trabajo; agentes de IA para programar hicieron la mayor parte de la lectura, la escritura y las pruebas."),
         body=dict(en="""
<h2>Who did what</h2>
<ul>
<li><b>The owner</b> chose the direction, played every build and said yes or no. A rejected idea was written down and not reopened without them.</li>
<li><b>Claude</b> (Anthropic's Claude Code) planned, read the binary and wrote most of the lifter and the host.</li>
<li><b>Codex</b> (OpenAI) took whole slices in parallel: a subsystem, a tool, a test.</li>
<li><b>OpenCode with DeepSeek</b> handled cheap, wide jobs: search the decompiled code, fill a census table, run a batch.</li>
</ul>
<h2>The risk: a confident guess</h2>
<p>A language model can write a plausible offset or a plausible file format that is simply wrong, and a game built on wrong values fails far away from the mistake. Most of the rules of this project exist to stop that.</p>
<ul>
<li><b>Proof or UNKNOWN.</b> Every value, format or patch names what proves it: an address read with REA (a reverse engineering server agents use over MCP) plus a second tool such as Ghidra or Hopper. Unproven means UNKNOWN, and nothing is built on it. More on that in <a href="[[retools]]">the toolbox</a>.</li>
<li><b>A machine judge.</b> The lifter's output is compared bit for bit with a reference x86 CPU. An agent cannot argue with a mismatch. See <a href="[[recomp]]">static recompilation</a>.</li>
<li><b>Loud failures.</b> A missing instruction or a missing DirectX method stops the game with its name, so a gap is found the first time it runs instead of hiding.</li>
<li><b>Real runs.</b> Changes are checked in a headless, muted Chrome that boots the real game and takes screenshots, and the owner judges from those screenshots and from playing.</li>
<li><b>One state file.</b> A plan file lists every step with its state (fixed, verified, fails) and the evidence. A new session starts from it, not from memory.</li>
</ul>
<h2>What did not work</h2>
<p>Long reports, percent-done scores and big multi-agent ceremonies cost time without making the game better, and were dropped. Heavy testing was cut to one check that matches how the owner plays. What stayed is small: a goal, the evidence rule, a commit after every finished step, and a person who plays the result.</p>
<p>The whole history, rules included, is public on <a href="REPO">GitHub</a>. The agents' instructions are in <a href="REPO/blob/main/AGENTS.md">AGENTS.md</a>.</p>
""", es="""
<h2>Quién hizo qué</h2>
<ul>
<li><b>El dueño</b> eligió la dirección, jugó cada build y dijo sí o no. Una idea rechazada se anotaba y no se reabría sin él.</li>
<li><b>Claude</b> (Claude Code de Anthropic) planeó, leyó el binario y escribió la mayor parte del traductor y del host.</li>
<li><b>Codex</b> (OpenAI) tomó tramos completos en paralelo: un subsistema, una herramienta, una prueba.</li>
<li><b>OpenCode con DeepSeek</b> se encargó de trabajos baratos y anchos: buscar en el código descompilado, llenar una tabla del censo, correr un lote.</li>
</ul>
<h2>El riesgo: una suposición segura de sí misma</h2>
<p>Un modelo de lenguaje puede escribir un offset creíble o un formato de archivo creíble que simplemente está mal, y un juego construido sobre valores equivocados falla lejos del error. La mayoría de las reglas de este proyecto existen para frenar eso.</p>
<ul>
<li><b>Prueba o UNKNOWN.</b> Cada valor, formato o parche nombra lo que lo prueba: una dirección leída con REA (un servidor de ingeniería inversa que los agentes usan por MCP) más una segunda herramienta como Ghidra o Hopper. Sin prueba es UNKNOWN, y nada se construye encima. Más en <a href="[[retools]]">la caja de herramientas</a>.</li>
<li><b>Un juez de máquina.</b> La salida del traductor se compara bit a bit con un CPU x86 de referencia. Un agente no puede discutir con una diferencia. Ver <a href="[[recomp]]">recompilación estática</a>.</li>
<li><b>Fallas ruidosas.</b> Una instrucción o un método de DirectX que falta detiene el juego con su nombre, así un hueco aparece la primera vez que corre en vez de esconderse.</li>
<li><b>Corridas reales.</b> Los cambios se revisan en un Chrome sin ventana y en silencio que arranca el juego real y toma capturas, y el dueño juzga con esas capturas y jugando.</li>
<li><b>Un solo archivo de estado.</b> Un archivo de plan lista cada paso con su estado (arreglado, verificado, falla) y su evidencia. Una sesión nueva empieza desde ahí, no desde la memoria.</li>
</ul>
<h2>Lo que no funcionó</h2>
<p>Los reportes largos, los porcentajes de avance y las grandes ceremonias de muchos agentes costaron tiempo sin mejorar el juego, y se quitaron. Las pruebas pesadas se redujeron a una revisión que se parece a cómo juega el dueño. Lo que quedó es poco: una meta, la regla de evidencia, un commit después de cada paso terminado y una persona que juega el resultado.</p>
<p>Toda la historia, reglas incluidas, es pública en <a href="REPO">GitHub</a>. Las instrucciones de los agentes están en <a href="REPO/blob/main/AGENTS.md">AGENTS.md</a>.</p>
""")),
]

for a in DEV:
    for lang in a["body"]:
        a["body"][lang] = a["body"][lang].replace('href="REPO', 'href="' + REPO)
