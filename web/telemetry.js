// Telemetry of a play session: one row per frame list the page runs, plus events. Every 2 s the new part goes to
// tools/serve.py (POST /telemetry -> build/telemetry.ndjson; build/webcheck.telemetry.ndjson for headless Chrome).
// tools/telemetry.py reads it with build/web.log (same clock: ms since the page started).
// F8 drops a mark ("this moment"), so a lag or a sound bug can be found in the file. F9 shows the same numbers live over
// the game (per frame: where its time went). F10 downloads the whole session as one .json (rows, events, the page log),
// like NFSU1-RE's F9 black box. ?telemetry=0 turns it off.
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

function startTelemetry(M, t0, log, logLines) {
  if (RN_Q.get('telemetry') === '0') return null;
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
  addEventListener('keydown', e => {
    if (e.code !== 'F8') return;
    e.preventDefault(); e.stopPropagation();
    if (!e.repeat) { event('mark', { n: ++marks }); log(`telemetry: mark ${marks}`); show(`marca ${marks} guardada`, 1500); }
  }, true);
  // F9: the live panel (top right). "juego+espera" = the game's code, its own busy wait for the next frame included. Stacked bars per frame: game code, waiting for the page/GPU, waiting for another
  // guest thread (GIL), file reads. Lines at 16.7 ms (60 fps) and 33 ms (30 fps).
  const panel = document.createElement('div');
  Object.assign(panel.style, { position: 'fixed', top: '8px', right: '8px', width: '400px', padding: '8px 10px',
    background: 'rgba(8,10,14,.82)', color: '#d6dde6', font: '12px/1.45 ui-monospace, Menlo, monospace', borderRadius: '6px',
    pointerEvents: 'none', display: 'none', zIndex: 9, whiteSpace: 'pre' });
  const graph = document.createElement('canvas'), text = document.createElement('div');
  graph.width = 720; graph.height = 160; graph.style.width = '400px'; graph.style.height = '80px';
  panel.append(text, graph);
  document.body.appendChild(panel);
  let shown = false;
  try { shown = localStorage.getItem('rn-live') === '1'; } catch {}
  const COLORS = { game: '#4c8dff', gpuWait: '#f0a030', gil: '#e5484d', read: '#e8d44d' };
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
    g.fillStyle = 'rgba(255,255,255,.35)';
    g.fillRect(0, H - 16.7 * sy, graph.width, 1); g.fillRect(0, H - 33.3 * sy, graph.width, 1);
    const last = live.slice(-60), recent = live.slice(-300);
    const span = (last[last.length - 1].t - last[0].t) / 1000 || 1;
    const avg = k => last.reduce((a, f) => a + f[k], 0) / last.length;
    const worst = Math.max(...recent.map(f => f.dt));
    const sum = (k, a = recent) => a.reduce((x, f) => x + f[k], 0);
    const rspan = (recent[recent.length - 1].t - recent[0].t) / 1000 || 1;
    const lag = recent.filter(f => f.dt > 50).length;
    const f1 = x => x.toFixed(1).padStart(5);
    text.textContent =
      `${(last.length - 1) / span >= 0 ? ((last.length - 1) / span).toFixed(0) : '-'} fps   frame ${f1(avg('dt'))} ms   peor ${worst.toFixed(0)} ms   lagazos ${lag}\n` +
      `juego+espera ${f1(avg('game'))}  gpu ${f1(avg('gpuWait'))}  hilos ${f1(avg('gil'))}  disco ${f1(avg('read'))} ms\n` +
      `draws ${Math.round(avg('draws'))}   texturas ${(sum('texKb') / 1024 / rspan).toFixed(1)} MB/s   pipelines ${sum('pipes')}\n` +
      `disco ${(sum('readKb') / 1024 / rspan).toFixed(1)} MB/s   GIL max ${Math.max(...recent.map(f => f.hold)).toFixed(0)} ms   página ${f1(avg('run'))} ms\n` +
      `audio ${(last[last.length - 1].behind / 44.1).toFixed(0)} ms   silencios ${underruns}   cortes stream ${starves}   marcas ${marks}`;
  }
  setInterval(draw, 250);
  addEventListener('keydown', e => {
    if (e.code !== 'F9') return;
    e.preventDefault(); e.stopPropagation();
    if (e.repeat) return;
    shown = !shown; panel.style.display = shown ? 'block' : 'none';
    try { localStorage.setItem('rn-live', shown ? '1' : '0'); } catch {}
  }, true);
  if (shown) panel.style.display = 'block';
  setInterval(() => event('heap', { mb: performance.memory ? Math.round(performance.memory.usedJSHeapSize / 1048576) : -1 }), 5000);

  const head = { kind: 'session', url: location.href, date: new Date().toISOString(), ua: navigator.userAgent,
    screen: `${innerWidth}x${innerHeight} dpr ${devicePixelRatio}`, cols: TELEM_COLS };
  fetch('/telemetry?new', { method: 'POST', body: JSON.stringify(head) + '\n' }).then(r => {
    if (r.ok) return;
    log(`telemetry: the server answered ${r.status}: restart tools/serve.py`);
    show('telemetría sin guardar: reinicia tools/serve.py', 8000);
  }).catch(() => {});
  function flush() {
    if (!rows.length && !events.length) return;
    let body = rows.length ? JSON.stringify({ rows }) + '\n' : '';
    for (const e of events) body += JSON.stringify(e) + '\n';
    rows = []; events = [];
    fetch('/telemetry', { method: 'POST', body, keepalive: body.length < 60000 }).catch(() => {});
  }
  setInterval(flush, 2000);
  addEventListener('pagehide', flush);
  // F10: the session as one file the browser saves (Downloads): head, cols, rows, events, log.
  addEventListener('keydown', e => {
    if (e.code !== 'F10') return;
    e.preventDefault(); e.stopPropagation();
    if (e.repeat) return;
    event('download', {});
    const name = `nfsu-session-${head.date.replace(/[:.]/g, '-')}.json`;
    const blob = new Blob([JSON.stringify({ format: 'rn-session-1', ...head, saved: ms(), rows: allRows, events: allEvents,
      log: logLines || [] })], { type: 'application/json' });
    const a = document.createElement('a');
    a.href = URL.createObjectURL(blob); a.download = name; a.click();
    setTimeout(() => URL.revokeObjectURL(a.href), 10000);
    log(`telemetry: session saved as ${name} (${allRows.length} rows)`);
    show(`sesión descargada: ${name}`, 3000);
  }, true);
  log('telemetry: on (build/telemetry.ndjson), F8 = mark, F9 = live panel, F10 = download the session');
  return { frame, event };
}
