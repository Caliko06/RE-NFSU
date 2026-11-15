// Telemetry of a play session: one row per frame list the page runs, plus events. Every 2 s the new part goes to
// tools/serve.py (POST /telemetry -> build/telemetry.ndjson; build/webcheck.telemetry.ndjson for headless Chrome).
// tools/telemetry.py reads it with build/web.log (same clock: ms since the page started).
// F8 drops a mark ("this moment"), so a lag or a sound bug can be found in the file. F9 shows the same numbers live over
// the game (per frame: where its time went). The session report (web/boot.js rnReport: F10, the map, the stop card) takes
// its rows and events from dump(). ?telemetry=0 turns it off. On a plain host (RN_PUBLIC) nothing is sent.
'use strict';
// Row columns. Host totals (host.h Telem) go in as deltas since the previous row.
const TELEM_COLS = ['t', 'run', 'present', 'draws', 'clears', 'kwords', 'texKb', 'pipes', 'shaders', 'targets', 'hd',
  'gpuWait', 'gilMain', 'gilOther', 'read', 'idleMain', 'holdMain', 'holdOther', 'reads', 'readKb', 'presents', 'streamPm',
  'starves', 'starveBuf',
  'audioBehind', 'underrun', 'resyncs', 'clockCalls', 'handoffs', 'gilGap', 'heldMain', 'heldOther', 'holdWho'];

// F10 keeps the whole session in memory: a fixed ring, newest kept, so a long capture cannot grow without bound.
// It answers `length` and JSON (oldest first) like the array it replaces, for every existing reader and the exporter.
function telemRing(cap) {
  const a = new Array(cap);
  let head = 0, n = 0;
  return {
    get length() { return n; },
    push(v) { a[(head + n) % cap] = v; if (n < cap) n++; else head = (head + 1) % cap; return n; },
    toJSON() { const out = new Array(n); for (let i = 0; i < n; i++) out[i] = a[(head + i) % cap]; return out; },
  };
}

function startTelemetry(M, t0, log) {
  if (RN_Q.get('telemetry') === '0') return null;
  const SEND = !window.RN_PUBLIC;   // tools/build_public.py: no server takes it, the session stays in the page for the report
  const base = M._rn_telem_addr(), audio = M._rn_audio_ring() >> 2;
  const F = () => M.HEAPF64, U = () => M.HEAPU32;
  // host.h Telem: 7 doubles (gpu_wait, gil_main, gil_other, read, idle_main, hold_main_max, hold_other_max),
  // then u32 presents, reads, read_kb, stream_pm, starves, starve_buf, clock_calls, gil_handoffs, gil_gap_us,
  // hold_main_us, hold_other_us, hold_other_who.
  const W = (base + 56) >> 2;
  const host = () => {
    const f = F(), u = U(), d = base >> 3;
    return [f[d], f[d + 1], f[d + 2], f[d + 3], f[d + 4], f[d + 5], f[d + 6], u[W], u[W + 1], u[W + 2], u[W + 3], u[W + 4], u[W + 6], u[W + 7], u[W + 8], u[W + 9], u[W + 10], u[W + 11]];
  };
  let prev = host(), prevUnder = 0, prevResync = 0, rows = [], events = [];
  const allRows = telemRing(36000), allEvents = telemRing(20000);   // the whole session, for F10 (36000 rows = 10 min at 60 fps)
  // Live view: the last N presented frames, each the sum of its rows (a load hands a frame over in parts).
  const N = 300, live = [];
  let acc = null, lastPresent = 0, starves = 0, underruns = 0;
  const ms = () => Math.round(performance.now() - t0);
  const r1 = x => Math.round(x * 10) / 10;
  const push = e => { events.push(e); allEvents.push(e); };
  const event = (kind, data) => push({ t: ms(), kind, ...data });

  function frame(s, t, runMs) {
    const h = host(), u = U();
    const d = k => h[k] - prev[k];
    const under = u[audio + 4], resync = u[audio + 5];
    // t at 0.01 ms: whole ms made a 60 fps limiter (0x585b40, 1/60 s) read as intervals 16, 17, 17 and a p50 of 17.
    rows.push([Math.round((t - t0) * 100) / 100, r1(runMs), s.present ? 1 : 0, s.draws, s.clears, s.words >> 10, s.texKb, s.pipes,
      s.shaders, s.targets, s.hd, r1(d(0)), r1(d(1)), r1(d(2)), r1(d(3)), r1(d(4)), r1(h[5]), r1(h[6]), d(8), d(9), d(7),
      h[10], h[11] - prev[11], h[11] !== prev[11] ? u[W + 5] : -1, (u[audio] - u[audio + 1]) | 0, under - prevUnder,
      resync - prevResync, d(12), d(13), r1(((h[14] - prev[14]) >>> 0) / 1000), r1(((h[15] - prev[15]) >>> 0) / 1000),
      r1(((h[16] - prev[16]) >>> 0) / 1000), h[17]]);
    F()[(base >> 3) + 5] = F()[(base >> 3) + 6] = 0; u[W + 3] = u[W + 11] = 0;     // the maxima are since the last row
    starves += h[11] - prev[11]; underruns += under - prevUnder;
    const r = rows[rows.length - 1];
    allRows.push(r);
    acc = acc || { gpuWait: 0, gil: 0, read: 0, run: 0, draws: 0, texKb: 0, pipes: 0, readKb: 0, clock: 0, hold: 0 };
    acc.gpuWait += r[11]; acc.gil += r[12]; acc.read += r[14]; acc.run += r[1]; acc.draws += r[3]; acc.texKb += r[6];
    acc.pipes += r[7]; acc.readKb += r[19]; acc.clock += r[27]; acc.hold = Math.max(acc.hold, r[16], r[17]);
    if (s.present) {
      if (lastPresent) {
        acc.t = t; acc.dt = t - lastPresent; acc.behind = r[24];
        acc.game = Math.max(0, acc.dt - acc.gpuWait - acc.gil - acc.read);
        live.push(acc);
        if (live.length > N) live.shift();
        const stab = stabRead();
        sampleRace(acc.dt, t, stab);
        if (acc.dt > STAB_LIMIT && !stab.racing) loadSpikes++;   // grid load or pause: shown apart, not in the verdict
        else if (acc.dt > STAB_LIMIT) {
          const cause = [['juego', acc.game], ['GPU', acc.gpuWait], ['hilos', acc.gil], ['disco', acc.read]].sort((a, b) => b[1] - a[1])[0][0];
          const matched = stab && Math.abs(acc.dt - stab.lastMs) <= 2.5;
          spikeHistory.push({ t: Math.round((t - t0) / 1000), ms: acc.dt, cause,
            site: matched ? stab.sites[0] : null, readsKb: matched ? stab.readKb : null });
          if (spikeHistory.length > 5) spikeHistory.shift();
        }
      }
      lastPresent = t; acc = null;
    }
    prev = h; prevUnder = under; prevResync = resync;
  }

  // The browser's own view of a slow frame: long animation frames (Chrome) with the scripts that ran in them.
  try {
    new PerformanceObserver(list => {
      for (const e of list.getEntries()) if (e.duration >= 50)
        push({ t: Math.round(e.startTime - t0), kind: 'loaf', dur: Math.round(e.duration), block: Math.round(e.blockingDuration || 0),
          scripts: (e.scripts || []).slice(0, 3).map(x => `${x.invoker || x.name} ${Math.round(x.duration)}ms`) });
    }).observe({ type: 'long-animation-frame', buffered: true });
  } catch {}
  // Display pacing: the game paces itself on QPC (limiter 0x585b40, 1/60 s), the screen on its own refresh, web/gpu.js
  // RN_PACE counts the frames that reached the canvas. Per animation frame: none = the screen showed the previous frame
  // again (a repeat); n > 1 = n - 1 frames never shown (drops, plus the ones the present queue threw away). Every 5 s:
  // event 'vsync' with the refresh rate seen and both counts.
  let vt = 0, vShown = 0, vDropped = 0, vTicks = 0, vRep = 0, vDrop = 0, vSum = 0, vMax = 0;
  const vtick = now => {
    const P = globalThis.RN_PACE || { shown: 0, dropped: 0 }, n = P.shown - vShown;
    if (vt) {
      const dt = now - vt; vTicks++; vSum += dt; vMax = Math.max(vMax, dt);
      if (n === 0) vRep++; else vDrop += n - 1;
      vDrop += P.dropped - vDropped;
      if (vSum >= 5000) {
        event('vsync', { hz: r1(1000 * vTicks / vSum), ticks: vTicks, rep: vRep, drop: vDrop, maxMs: r1(vMax) });
        vTicks = vRep = vDrop = vSum = vMax = 0;
      }
    }
    vt = now; vShown = P.shown; vDropped = P.dropped;
    requestAnimationFrame(vtick);
  };
  requestAnimationFrame(vtick);
  addEventListener('visibilitychange', () => event('visibility', { state: document.visibilityState }));
  addEventListener('blur', () => event('focus', { state: 'blur' }));
  addEventListener('focus', () => event('focus', { state: 'focus' }));
  // A short note over the game (a mark, or the server refusing the data).
  const note = document.createElement('div');
  Object.assign(note.style, { position: 'fixed', top: '12px', left: '50%', transform: 'translateX(-50%)', padding: '6px 14px',
    background: 'rgba(0,0,0,.75)', color: '#fff', font: '15px ui-monospace, Menlo, monospace', borderRadius: '6px',
    pointerEvents: 'none', display: 'none', zIndex: 10 });
  document.body.appendChild(note);
  let noteTimer = 0;
  const show = (text, ms) => { note.textContent = text; note.style.display = 'block'; clearTimeout(noteTimer); noteTimer = setTimeout(() => note.style.display = 'none', ms); };
  let marks = 0;
  // F9 or E: live frame and race stability. E is unbound in GameActionTable 0x702c98.
  const panel = document.createElement('div');
  Object.assign(panel.style, { position: 'fixed', top: '8px', right: '8px', width: '430px', padding: '12px 14px',
    background: 'linear-gradient(145deg, rgba(8,15,28,.96), rgba(15,10,27,.94))', color: '#e7f2ff', font: '12px/1.45 ui-monospace, Menlo, monospace',
    border: '1px solid rgba(89,190,255,.55)', borderTop: '3px solid #48d9ff', borderRadius: '10px',
    boxShadow: '0 8px 36px rgba(0,0,0,.5), 0 0 22px rgba(20,175,255,.15)',
    pointerEvents: 'none', display: 'none', zIndex: 9, whiteSpace: 'pre' });
  const graph = document.createElement('canvas'), text = document.createElement('div');
  graph.width = 860; graph.height = 180; graph.style.width = '430px'; graph.style.height = '90px';
  panel.append(text);
  document.body.appendChild(panel);
  let shown = RN_Q.get('live') === '1', panelTimer = 0;
  try { shown = localStorage.getItem('rn-live') === '1'; } catch {}
  if (RN_Q.get('live') === '1') shown = true;
  const COLORS = { game: '#4c8dff', gpuWait: '#f0a030', gil: '#e5484d', read: '#e8d44d' };
  const STAB_LIMIT = 23, FPS_LIMIT = 16.7;
  // Clock-read call sites seen in spikes (docs/re/hitches.md, census/spikes_history.tsv)
  const SITE = { 0x474c24: 'física subpasos', 0x585bf7: 'limitador 60 fps', 0x477de0: 'por coche', 0x403a7a: 'reloj del frame', 0x540698: 'buscar modelo' };   // 0x540698 inside Solid_FindInAllLists 0x540680 (census/names_assets)
  let loadSpikes = 0, f32 = new Float32Array(0), stabPtr = 0, raceId = -1, race = null, raceWasOn = false;
  const raceHistory = [], spikeHistory = [];
  const stabRead = () => {
    if (!stabPtr) stabPtr = M._rn_stab_addr();   // host.h RnStab (host/d3d9.c spike_log)
    const u = U(), w = stabPtr >> 2;
    if (f32.buffer !== u.buffer) f32 = new Float32Array(u.buffer);   // HEAPF32 is not exported (build.py); a grown heap is a new buffer
    const f = f32;
    return { racing: u[w], id: u[w + 1], spikes: u[w + 2], lastFrame: u[w + 3], lastMs: f[w + 4],
      sites: [u[w + 5], u[w + 6], u[w + 7]], siteN: [u[w + 8], u[w + 9], u[w + 10]],
      reads: u[w + 11], readKb: u[w + 12], readMs: f[w + 13], holdMs: f[w + 14] };
  };
  const newRace = (id, t) => ({ id, start: t, end: t, frames: 0, over23: 0, under167: 0, worst: 0, hist: new Map() });
  const raceSummary = r => {
    const rank = Math.max(1, Math.ceil(r.frames * .99)); let seen = 0, p99 = 0;
    for (const [bucket, count] of [...r.hist].sort((a, b) => a[0] - b[0])) { seen += count; if (seen >= rank) { p99 = bucket / 1000; break; } }
    return { raceId: r.id, frames: r.frames, over23ms: r.over23, p99ms: p99, worstMs: r.worst,
      atOrBelow16_7Pct: r.frames ? 100 * r.under167 / r.frames : 0, elapsedSec: Math.max(0, (r.end - r.start) / 1000),
      verdict: r.over23 === 0 ? 'ESTABLE' : 'INESTABLE' };   // OWNER 2026-11-14: no race frame over 23 ms (p99 shown, the 1/60 limiter keeps it near 18)
  };
  const finishRace = () => {
    if (!race || !race.frames) return;
    raceHistory.push(raceSummary(race)); if (raceHistory.length > 100) raceHistory.shift();
  };
  const sampleRace = (dt, t, h) => {
    if (!h) return;
    if (h.id !== raceId) { finishRace(); raceId = h.id; race = h.racing ? newRace(h.id, t) : null; raceWasOn = !!h.racing; }
    if (!h.racing) { if (raceWasOn) finishRace(); race = null; raceWasOn = false; return; }
    if (!race) race = newRace(h.id, t);
    raceWasOn = true; race.end = t; race.frames++; race.worst = Math.max(race.worst, dt);
    if (dt > STAB_LIMIT) race.over23++;
    if (dt <= FPS_LIMIT) race.under167++;
    const bin = Math.floor(dt * 1000); race.hist.set(bin, (race.hist.get(bin) || 0) + 1);
  };
  const panelTitle = document.createElement('div'), panelBody = document.createElement('div');
  Object.assign(panelTitle.style, { color: '#58dcff', font: 'bold 14px/1.3 ui-monospace,Menlo,monospace', letterSpacing: '.08em', marginBottom: '5px' });
  text.append(panelTitle, panelBody); panel.append(graph);
  function draw() {
    if (!shown || !live.length) return;
    const g = graph.getContext('2d'), H = graph.height, sy = H / 50;           // 50 ms tall
    g.clearRect(0, 0, graph.width, H);
    const bw = graph.width / N;
    live.forEach((f, i) => {
      let y = H;
      for (const k of ['game', 'gpuWait', 'gil', 'read']) {
        const h = Math.min(f[k], 50) * sy;
        g.fillStyle = COLORS[k]; g.fillRect(i * bw, y - h, Math.max(1, bw - .5), h); y -= h;
      }
      if (f.dt > 50) { g.fillStyle = '#ff3b3b'; g.fillRect(i * bw, 0, Math.max(2, bw), 6); }
    });
    g.fillStyle = 'rgba(255,255,255,.28)'; g.fillRect(0, H - FPS_LIMIT * sy, graph.width, 1);
    g.fillStyle = '#ff6b59'; g.fillRect(0, H - STAB_LIMIT * sy, graph.width, 2);
    g.fillStyle = 'rgba(255,255,255,.18)'; g.fillRect(0, H - 33.3 * sy, graph.width, 1);
    const last = live.slice(-60), recent = live.slice(-300);
    const span = (last[last.length - 1].t - last[0].t) / 1000 || 1;
    const avg = k => last.reduce((a, f) => a + f[k], 0) / last.length;
    const worst = Math.max(...recent.map(f => f.dt));
    const sum = (k, a = recent) => a.reduce((x, f) => x + f[k], 0);
    const rspan = (recent[recent.length - 1].t - recent[0].t) / 1000 || 1;
    const lag = recent.filter(f => f.dt > 50).length, over23 = recent.filter(f => f.dt > STAB_LIMIT).length;
    const f1 = x => x.toFixed(1).padStart(5);
    const h = stabRead(), rs = race ? raceSummary(race) : raceHistory[raceHistory.length - 1];
    const badge = rs ? rs.verdict : 'FUERA DE CARRERA';
    panelTitle.textContent = `ESTABILIDAD / 60 FPS   ${badge}`;
    panelTitle.style.color = badge === 'ESTABLE' ? '#55eea2' : badge === 'INESTABLE' ? '#ff5575' : '#8fa7bd';
    const raceData = race ? rs : rs || {};
    panelBody.textContent =
      `carrera ${h?.id || 0}   ${h?.racing ? 'EN CURSO' : 'ESPERANDO'}   ${raceData.frames || 0} frames   >23 ms ${raceData.over23ms ?? race?.over23 ?? 0}\n` +
      `p99 ${f1(raceData.p99ms || 0)} ms   peor ${f1(raceData.worstMs || 0)} ms   <=16.7 ${(raceData.atOrBelow16_7Pct || 0).toFixed(1)}%   ${(raceData.elapsedSec || 0).toFixed(1)} s\n` +
      `ahora ${((last.length - 1) / span).toFixed(0)} fps  ${f1(avg('dt'))} ms   >23: ${over23}   lagazos >50: ${lag}   carga >23: ${loadSpikes}\n` +
      `juego ${f1(avg('game'))}   GPU ${f1(avg('gpuWait'))}   hilos ${f1(avg('gil'))}   disco ${f1(avg('read'))} ms\n` +
      `draws ${Math.round(avg('draws'))}   texturas ${(sum('texKb') / 1024 / rspan).toFixed(1)} MB/s   pipes ${sum('pipes')}\n` +
      `disco ${(sum('readKb') / 1024 / rspan).toFixed(1)} MB/s   hilos max ${Math.max(...recent.map(f => f.hold)).toFixed(0)} ms   página ${f1(avg('run'))} ms\n` +
      `audio ${(last[last.length - 1].behind / 44.1).toFixed(0)} ms   silencios ${underruns}   cortes ${starves}   marcas ${marks}\n` +
      `PICOS >23 ms:\n${spikeHistory.map(s => `  ${s.t}s ${s.ms.toFixed(1)} ms ${s.cause}${s.site == null ? '' : ` · ${SITE[s.site] || '0x' + s.site.toString(16)} · ${s.readsKb} KB`}`).join('\n') || '  ninguno'}`;
  }
  const setPanel = v => {
    shown = v; panel.style.display = shown ? 'block' : 'none';
    if (panelTimer) clearInterval(panelTimer);
    panelTimer = shown ? setInterval(draw, 250) : 0;
    if (shown) draw();
    try { localStorage.setItem('rn-live', shown ? '1' : '0'); } catch {}
  };
  addEventListener('keydown', e => {
    // E only while driving (HUD up) and not in a text field: the front end takes typed letters (profile name).
    if (e.code !== 'F9' && !(e.code === 'KeyE' && stabRead().racing && !e.target.closest?.('input,textarea'))) return;
    e.preventDefault(); e.stopImmediatePropagation();
    if (e.repeat) return;
    setPanel(!shown);
  }, true);
  if (shown) { panel.style.display = 'block'; panelTimer = setInterval(draw, 250); }
  setInterval(() => event('heap', { mb: performance.memory ? Math.round(performance.memory.usedJSHeapSize / 1048576) : -1 }), 5000);

  let renderer = '';
  try {
    const c = document.createElement('canvas'), gl = c.getContext('webgl') || c.getContext('webgl2');
    renderer = gl?.getExtension('WEBGL_debug_renderer_info')?.UNMASKED_RENDERER_WEBGL &&
      gl.getParameter(gl.getExtension('WEBGL_debug_renderer_info').UNMASKED_RENDERER_WEBGL) || gl?.getParameter(gl.RENDERER) || '';
  } catch {}
  const machine = { hardwareConcurrency: navigator.hardwareConcurrency || null, deviceMemoryGb: navigator.deviceMemory || null,
    gpuRenderer: renderer || null, dev: RN_Q.get('dev') || null };
  const head = { kind: 'session', url: location.href, date: new Date().toISOString(), ua: navigator.userAgent,
    screen: `${innerWidth}x${innerHeight} dpr ${devicePixelRatio}`, machine, cols: TELEM_COLS };
  if (SEND) fetch('/telemetry?new', { method: 'POST', body: JSON.stringify(head) + '\n' }).then(r => {
    if (r.ok) return;
    log(`telemetry: the server answered ${r.status}: restart tools/serve.py`);
    show('telemetría sin guardar: reinicia tools/serve.py', 8000);
  }).catch(() => {});
  function flush() {
    if (!rows.length && !events.length) return;
    if (!SEND) { rows = []; events = []; return; }
    let body = rows.length ? JSON.stringify({ rows }) + '\n' : '';
    for (const e of events) body += JSON.stringify(e) + '\n';
    rows = []; events = [];
    const wd = globalThis.RN_WD, was = wd ? wd[1] : 0;   // web/gpu.js ?watchdog=1: phase 3 while the flush call runs
    if (wd) wd[1] = 3;
    fetch('/telemetry', { method: 'POST', body, keepalive: body.length < 60000 }).catch(() => {});
    if (wd) wd[1] = was;
  }
  setInterval(flush, 2000);
  addEventListener('pagehide', flush);
  // ?stopafter=N: after N s the page saves what it has and leaves for about:blank, so a headed bench tab stops the
  // game by itself (nobody has to close it). 1.5 s covers the next log flush (web/boot.js, every 1 s).
  const stopAfter = +RN_Q.get('stopafter');
  if (stopAfter > 0) setTimeout(() => {
    log(`telemetry: stopafter ${stopAfter} s reached, leaving for about:blank`);
    event('stop', {}); flush();
    setTimeout(() => location.replace('about:blank'), 1500);
  }, stopAfter * 1000);
  log('telemetry: on, B/F8 = marca, E/F9 = panel (?live=1), F10 = reporte');
  return { frame, event: (kind, data) => { if (kind === 'mark') marks = data.n; event(kind, data); },
    dump: () => ({ cols: TELEM_COLS, rows: allRows, events: allEvents, machine,
      stability: { races: [...raceHistory, ...(race && race.frames ? [raceSummary(race)] : [])], spikes: spikeHistory } }) };
}
