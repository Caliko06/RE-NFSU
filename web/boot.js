// Boot: the page log, the WebAssembly start and the frame loop (moved out of web/index.html, GOAL 2026-11-05).
const log = document.getElementById('log'), status = document.getElementById('status');
const t0 = performance.now();
// Everything shown here also goes to tools/serve.py (build/web.log), so a session can be read afterwards.
let pending = [], allLog = [];       // allLog: the whole session, for the F10 download (telemetry.js)
const duelBox = Object.assign(document.createElement('div'), { style: 'position:fixed;left:50%;top:14%;transform:translateX(-50%);padding:6px 16px;background:rgba(0,0,0,.72);color:#ffc24a;font:bold 20px system-ui;border-radius:6px;pointer-events:none;display:none;z-index:9' });
const duelSay = s => { const m = /DUEL (\S+) (start|won|lost)/.exec(s); if (!m) return; if (!duelBox.isConnected) document.body.appendChild(duelBox); duelBox.textContent = { start: `Duelo con ${m[1]}`, won: `${m[1]} te ganó`, lost: `Le ganaste a ${m[1]}` }[m[2]]; duelBox.style.display = ''; clearTimeout(duelSay.t); duelSay.t = setTimeout(() => duelBox.style.display = 'none', 3500); };
const keep = s => { pending.push(s); allLog.push(s); if (s.includes('DUEL ')) duelSay(s); };
let logUp = true;                    // tools/serve.py answers /log; a plain web host does not, and then nothing is sent
function flush() {
  if (!pending.length) return;
  if (!logUp) { pending = []; return; }
  const body = pending.join('\n') + '\n';
  pending = [];
  // keepalive (the batch still goes out if the page is closing) caps the body at 64 KB: a bigger batch was dropped whole,
  // silently (518 pack errors in one second took the race HUD line with them and the run looked hung, build/bench/g_cas).
  fetch('/log', { method: 'POST', body, keepalive: body.length < 60000 }).catch(() => {});
}
fetch('/log?new', { method: 'POST', body: `page ${location.href} ${new Date().toISOString()}\n` }).then(r => { logUp = r.ok; }, () => { logUp = false; });
setInterval(flush, 1000);
const secs = () => ((performance.now() - t0) / 1000).toFixed(2);
addEventListener('keydown', e => { if (!e.repeat) keep(`${secs()} key down ${e.code}`); }, true);
addEventListener('keyup', e => keep(`${secs()} key up ${e.code}`), true);
addEventListener('error', e => { line('JS error: ' + e.message + ' at ' + e.filename + ':' + e.lineno, 'stop'); flush(); });
addEventListener('unhandledrejection', e => { line('JS rejection: ' + (e.reason && e.reason.stack || e.reason), 'stop'); flush(); });
addEventListener('pagehide', flush);
addEventListener('keydown', e => { if (e.code === 'F2') { document.body.classList.toggle('dbg'); e.preventDefault(); e.stopPropagation(); } }, true);
function line(s, cls) {
  keep(`${secs()} ${s}`);
  if (/^STOP|^JS |abort|Aborted|RuntimeError/.test(s)) setTimeout(flush, 0);
  const d = document.createElement('div');
  if (cls) d.className = cls;
  else if (/^STOP/.test(s)) d.className = 'stop';
  else if (/^  \S+!/.test(s)) d.className = 'api';
  d.textContent = s;
  log.appendChild(d);
  // A 'stop' line (missing WebGPU, COOP/COEP, a lost GPU) ends the session: the gate says why (web/app.js), F2 opens this log.
  if (cls === 'stop' || /^STOP/.test(s)) { status.textContent = 'detenido a los ' + ((performance.now() - t0) / 1000).toFixed(2) + ' s'; status.className = 'stop'; RN_APP.set('stop', s); }
  // ?fast=1: the game is up when its main menu shows (the launcher's curtain lifts then); otherwise at the first present (below).
  else if (FAST && !up && /flow fe .*MU_Main_PC\.fng/.test(s)) { up = true; RN_APP.set('run'); }
}
const FAST = RN_Q.get('fast') === '1';
let up = false;
RN_APP.on((s, from) => keep(`${secs()} app: ${from} -> ${s}`));
// A download whose bytes are counted on the gate. Compressed transfers have no usable total, so it shows megabytes.
async function download(url, what) {
  const r = await fetch(url);
  if (!r.ok) throw new Error(`descarga de ${url}: HTTP ${r.status}`);
  let n = 0, mb = -1;
  const count = new TransformStream({ transform(c, ctl) {
    n += c.byteLength;
    if (n >> 20 !== mb) { mb = n >> 20; if (RN_APP.state === 'load') RN_APP.say(`${what} ${mb} MB`); }
    ctl.enqueue(c);
  } });
  return new Response(r.body.pipeThrough(count), { headers: { 'Content-Type': r.headers.get('Content-Type') || 'application/octet-stream' } });
}
(async () => {
  // check: what the game cannot run without, before any download (the wasm is 70 MB).
  if (!crossOriginIsolated || typeof SharedArrayBuffer === 'undefined') { line('Falta COOP/COEP: abre la página desde tools/serve.py', 'stop'); return; }
  if (!navigator.gpu) { line('gpu.js: WebGPU no disponible en este navegador', 'stop'); return; }
  if (!await navigator.gpu.requestAdapter().catch(() => null)) { line('gpu.js: WebGPU: sin adaptador', 'stop'); return; }
  RN_APP.set('load');
  if (window.RN_HOLD) await window.RN_HOLD;       // ?fast=1: scene B draws first (web/index.html)
  const exe = new Uint8Array(await (await download('pc/Speed.exe', 'Descargando')).arrayBuffer());
  // Game files are read on demand by the game thread (host/files.c), not loaded here.
  // F-Max: in Remaster the pedestrian is Max Payne when the local Max build answers on /mp/ (tools/serve.py); ?max=0 keeps
  // F-Speed's debug box. Original never loads it.
  const maxChar = RN_MODE === 'remaster' && RN_Q.get('max') !== '0' && (await fetch('/mp/out/maxpayne.js').catch(() => null))?.ok === true;
  status.textContent = 'corriendo'; status.className = 'run';
  const M = await Speed({
    arguments: ['/pc/Speed.exe', '/game'],
    print: s => line(s), printErr: s => line(s, 'dim'),
    onAbort: what => line('STOP wasm abort: ' + what),
    // The 70 MB module compiles while it downloads, as Emscripten's own loader does, with the bytes counted on the gate.
    instantiateWasm: (imports, done) => {
      download('out/speed.wasm', 'Descargando').then(r => WebAssembly.instantiateStreaming(r, imports))
        .then(w => { RN_APP.say('Arrancando…'); done(w.instance, w.module); }, e => line('STOP wasm: ' + e.message));
      return {};
    },
    preRun: [m => {
      m.FS.mkdir('/pc'); m.FS.writeFile('/pc/Speed.exe', exe);
      if (maxChar) m.ENV.RN_MAXCHAR = '1';   // host/mc.c mc_draw_actor: no debug box, Max is drawn by web/maxpayne/
      // The game draws at the pixels of this window (PATCH 0x408760), at most 2560x1440 to keep the GPU load sane.
      // A phone opened upright still gets a landscape back buffer (the game waits behind the upright gate, web/app.js): the
      // size is fixed here for the whole session.
      const turned = RN_APP.coarse && innerHeight > innerWidth, vw = turned ? innerHeight : innerWidth, vh = turned ? innerWidth : innerHeight;
      const dpr = window.devicePixelRatio || 1, BB = Number(RN_Q.get('bbmax') || (RN_APP.coarse ? 1280 : 2560)), k = Math.min(1, BB / (vw * dpr), BB * 9 / 16 / (vh * dpr));
      // Phones and tablets (coarse pointer): 1280 wide; an iPhone tab at 2560 was killed by iOS after 20-40 s (memory, likely).
      // Even sizes: the layer keeps width and height even (host/win32.c). At k = 1 the canvas gets exactly
      // back buffer / dpr CSS pixels, centred, so one back-buffer pixel is one device pixel; k < 1: Chrome scales it up.
      const bw = 2 * Math.floor(vw * dpr * k / 2), bh = 2 * Math.floor(vh * dpr * k / 2);
      m.ENV.RN_SCREEN = `${bw}x${bh}`;
      if (k === 1 && !turned) Object.assign(document.getElementById('screen').style, { width: `${bw / dpr}px`, height: `${bh / dpr}px`, margin: 'auto' });
      line(`screen: window ${innerWidth}x${innerHeight} css, dpr ${dpr}, k ${k.toFixed(3)}, back buffer ${m.ENV.RN_SCREEN}`);
      // web/mode.js: the original mode turns the native bridges off too (?env= still wins)
      if (RN_MODE === 'original') Object.assign(m.ENV, RN_ORIGINAL_ENV);
      else m.ENV.RN_WALLSOFTEN = '1'; // 0x46bae0: remove the remaster's grazing wall rebound
      line(`mode: ${RN_MODE} (F4 switches)`);
      // ?fps=30: the host frame pacer targets 30 fps (web/mode.js degradation switches; ?fx=0 is read there)
      if (RN_Q.get('fps') === '30') m.ENV.RN_FPS = '30';
      if (RN_Q.get('fx') === '0' || RN_Q.get('fps') === '30') line(`lite: fx ${RN_Q.get('fx') === '0' ? 'off' : 'on'}, fps ${RN_Q.get('fps') === '30' ? 30 : 60}`);
      // ?env=RN_TRACE=1,RN_API=Present: the debug switches of the native build
      for (const kv of (RN_Q.get('env') || '').split(',').filter(Boolean)) {
        const k = kv.indexOf('=');
        m.ENV[k < 0 ? kv : kv.slice(0, k)] = k < 0 ? '1' : kv.slice(k + 1);
      }
      // ?world=1: the open world (docs/OPENWORLD.md): the 16 street tracks load one merged collision, no fences (host/openworld.c)
      if (RN_Q.get('world') === '1') m.ENV.RN_WORLD = '1';
      // ?ai=0: WORLD rivals drive the shipped skill records, no nervous, clean or aggressive personalities (host/rivals.c), and the WORLD
      // keeps the plain free mode AI: 6 rivals, 19 traffic cars (host/free.c world_ai). Read at each race.
      if (RN_Q.get('ai') === '0') m.ENV.RN_AI = '0';
      // ?trafyield=0: traffic does not move aside for the player closing from behind (host/rivals.c traffic_tick)
      if (RN_Q.get('trafyield') === '0') m.ENV.RN_TRAFYIELD = '0';
      // ?rivalopen=0: Free Run rivals stay on the start grid until the 10 s respawn rules move them (host/free.c free_respawn)
      if (RN_Q.get('rivalopen') === '0') m.ENV.RN_RIVALOPEN = '0';
      // ?pool=1 (OWNER 2026-11-03): the car pool: neon puddle, liveries, personas, warm car light (host/rivals.c, web/gpu.js livery). Off until approved.
      if (RN_Q.get('pool') === '1') { m.ENV.RN_POOL = '1'; m.ENV.RN_TRAFMODELS = '1'; m.ENV.RN_TRAFREFILL = '1'; m.ENV.RN_FREETMOVE = '0'; }
      // RN_JCLOG: one log line a second plus one per airborne sample (host/d3d9.c jumpcam_log): why a jump did or did not get the jump camera, in build/web.log
      m.ENV.RN_JCLOG = '1';
      // AI evidence in every F10 (OWNER 2026-10-31, "the AI is still bad"): rivals' speed, skill, actions, distance (host/free.c RN_FREELOG),
      // traffic near the player, reactions, hits (host/rivals.c RN_AILOG). Log lines only, no behaviour change.
      m.ENV.RN_FREELOG = '1'; m.ENV.RN_AILOG = '1';
      // Lanes 1-3 evidence in every F10 (OWNER 2026-11-04, docs/archive/SCOPE_2026-11-04.md): log lines only. RST/RSTA/RSTW = each reset 0x427c50 + 120 frames (pos, ground height); HORNL = each traffic honk; FEEL = speed, camera, FOV.
      m.ENV.RN_RESETLOG = '1'; m.ENV.RN_HORNLOG = '1'; m.ENV.RN_FEELLOG = '1';
      // ?hornfix=1: no traffic honk from a parked, undrawn or just-recycled car (host/horn.c)
      if (RN_Q.get('hornfix') === '1') m.ENV.RN_HORNFIX = '1';
      // ?aistuck=1: rivals count as stuck after 1.5 s under 3 m/s, not 0.4 s under 5 m/s (host/rivals.c ai_tune)
      if (RN_Q.get('aistuck') === '1') m.ENV.RN_AI_STUCK = '1';
      // Shipped rear grip assist by default (OWNER 2026-10-31: the feel must be the original's); ?handling=1: the 0.18 cap (host/rivals.c)
      if (RN_Q.get('handling') !== '1') m.ENV.RN_HANDLING = '0';
      // Traffic (host/rivals.c): ?trafmodels=0 no bus, ambulance, fire truck in WORLD (default on), =1 on any track; ?trafrefill=1 traffic_refill in place of free_tmove;
      // ?traffic=<n> free mode's traffic count, x1.5 = cars, 23 at most with 6 rivals (0x4322a0)
      if (RN_Q.has('trafmodels')) m.ENV.RN_TRAFMODELS = RN_Q.get('trafmodels');
      if (RN_Q.get('trafrefill') === '1') { m.ENV.RN_TRAFREFILL = '1'; m.ENV.RN_FREETMOVE = '0'; }
      if (RN_Q.has('traffic')) m.ENV.RN_FREETRAFFIC = RN_Q.get('traffic');
      // Always on: an F10 session then shows the menus and files of a normal play, so it can answer a gap row without a test (tools/playindex.py)
      m.ENV.RN_FLOWLOG = '1';
      // ?keys=: an RN_KEYS script (host/input.c; it holds commas, so not in ?env=), e.g. a tools/completion.py row
      const keys = RN_Q.get('keys');
      if (keys) m.ENV.RN_KEYS = keys;
      // ?jump=5:1201,6:1304: RN_JUMP (host/input.c). On Quick Race, each race of the list starts at once (mode:track;
      // 0 circuit, 1 sprint, 2 lap KO, 3 free run, 5 drag, 6 drift), the next one when a race comes back to the menu
      const jump = RN_Q.get('jump');
      if (jump) m.ENV.RN_JUMP = jump;
      // ?fast=1 (the launcher, web/index.html): no intro movies, no splash (PATCH 0x4de395, tools/recomp/patches_launcher.py); the profile screen takes the game's own
      // Accept: Enter 1.5 s after it shows, then twice more 3 s apart unless the main menu is already up (the game loads the last profile; a tap is dropped once MU_Main_PC shows).
      if (RN_Q.get('fast') === '1') {
        m.ENV.RN_FAST = '1';
        if (!keys && !RN_Q.get('jump')) m.ENV.RN_KEYS = '1500@=MU_UG_NewOrLoad_PC2:RETURN,3000@!MU_Main_PC:RETURN,3000@!MU_Main_PC:RETURN,3000@!MU_Main_PC:RETURN';
      }
      // ?pool=1 opens WORLD directly (the menu path of tools/completion.py jump 3:1010); ?keys= or ?jump= take over
      if (RN_Q.get('pool') === '1' && !keys && !jump) {
        m.ENV.RN_JUMP = '3:1010';
        m.ENV.RN_KEYS = '20000:RETURN,3000@!MU_UG_NewOrLoad_PC2:RETURN,3000@!MU_UG_NewOrLoad_PC2:RETURN,3000@!MU_UG_NewOrLoad_PC2:RETURN,3000@!MU_UG_NewOrLoad_PC2:RETURN,1500@=MU_UG_NewOrLoad_PC2:RETURN,1500@=MU_Main_PC:RETURN';
        // no RETURN after flow 6: in a race RETURN changes the camera (taps at flow 6/3 and 6/4 cycled POV 1 -> 2 -> 0, FEEL log 2026-11-10)
      }
      // ?carlook=0: the car paint as car.efx draws it (host/sm1.c clearcoat bridge off), 2003: also at the shipped strength,
      // 1: the clearcoat (OWNER: flat), 2: the sharp clearcoat candidate, 3 (default): live, the 2003 strength with contrast
      // ?steer=pad: the keyboard steers through the game's gamepad model (PATCH 0x460a80, host/win32.c RN_STEER)
      if (RN_Q.get('steer') === 'pad') m.ENV.RN_STEER = 'pad';
      // ?career=normal: the Underground as shipped, events open one by one (unlock patches off: PATCH 0x63b370 caves read
      // [0x7677ac] alone, debug byte 0x735ec1 = 0; host/win32.c RN_UNLOCK). Default: everything unlocked
      if (RN_Q.get('career') === 'normal') m.ENV.RN_UNLOCK = '0';
      // ?cardetail=0: the car paint without the occlusion and grime terms (host/sm1.c car_ps_detail); =split: right half only
      const cd = RN_Q.get('cardetail');
      if (cd !== null) m.ENV.RN_CARDETAIL = cd;
      // ?roadrefl=game|sq|cube|off: how strongly the road reflects. sq / cube: the reflection weight (vertex alpha x texture alpha) squared /
      // cubed (host/sm1.c); off: the game's own ROADREFLECTION level 1, no mirrored world (PATCH 0x410c1b, host/win32.c). Read at boot.
      // Remaster default is off, a dry road (OWNER 2026-10-30: too much reflection); Original mode sets game (web/mode.js).
      m.ENV.RN_ROADREFL = RN_Q.get('roadrefl') ?? 'off';
      // ?car=<name|index>: the player's car in every race is a career rival's car (RN_CAR, host/free.c player_car; ?car=list logs the choices)
      const car = RN_Q.get('car');
      if (car) m.ENV.RN_CAR = car;
      const look = RN_Q.get('carlook');
      if (look !== null) m.ENV.RN_CARLOOK = look;
    }],
  });
  // F-Max
  if (maxChar)
    import('./maxpayne/boot.js').then(m => m.start(M, s => line(s))).catch(e => line('[F-Max] STOP ' + e.message, 'stop'));
  const telem = startTelemetry(M, t0, s => line(s), allLog);
  const onFrame = (s, t, ms) => { if (s.present && !up && !FAST) { up = true; RN_APP.set('run'); } telem?.frame?.(s, t, ms); };
  startGpu(M, document.getElementById('screen'), s => line(s, 'api'), onFrame).catch(e => line('gpu.js: ' + e.message, 'stop'));
  // RN_STEERLOG (host/input.c): also each key at the page and each present's GPU completion, on the page's clock
  const input = startInput(M, document.getElementById('screen'), /RN_STEERLOG/.test(location.search) ? s => line(s) : null);
  startPad(input);                          // web/pad.js: a gamepad into the same ring
  startTouch(input);                        // web/touch.js: the touch overlay (coarse pointer or ?touch=1) into the same ring
  startTune(M);
  startAudio(M, s => line(s)).catch(e => line('audio.js: ' + e.message, 'stop'));
  window.RN_M = M;                          // for checks from the console or tools/webcheck.mjs
  // Memory line when it moves by 16 MB or more (host/win32.c rn_mem_mb): what an iPhone tab (~1.5 GB, then iOS kills it) holds.
  let memLast = '';
  setInterval(() => {
    const v = [0, 1, 2].map(k => M._rn_mem_mb(k)), key = v.map(x => x >> 4).join();
    if (key !== memLast) { memLast = key; line(`mem: wasm break ${v[0]} MB (guest 1024 untouched until used), guest heap ${v[1]} MB, guest virtual ${v[2]} MB`); }
  }, 2000);
})();
