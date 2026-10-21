// Telemetry of a play session: one row per frame list the page runs, plus events. Every 2 s the new part goes to
// tools/serve.py (POST /telemetry -> build/telemetry.ndjson; build/webcheck.telemetry.ndjson for headless Chrome).
// tools/telemetry.py reads it with build/web.log (same clock: ms since the page started).
// F8 drops a mark ("this moment"), so a lag or a sound bug can be found in the file. ?telemetry=0 turns it off.
'use strict';
// Row columns. Host totals (host.h Telem) go in as deltas since the previous row.
const TELEM_COLS = ['t', 'run', 'present', 'draws', 'clears', 'kwords', 'texKb', 'pipes', 'shaders', 'targets', 'hd',
  'gpuWait', 'gilMain', 'gilOther', 'read', 'idleMain', 'holdMain', 'holdOther', 'reads', 'readKb', 'presents', 'streamPm',
  'starves', 'starveBuf',
  'audioBehind', 'underrun', 'resyncs', 'clockCalls'];

function startTelemetry(M, t0, log) {
  if (new URLSearchParams(location.search).get('telemetry') === '0') return null;
  const base = M._rn_telem_addr(), audio = M._rn_audio_ring() >> 2;
  const F = () => M.HEAPF64, U = () => M.HEAPU32;
  // host.h Telem: 7 doubles (gpu_wait, gil_main, gil_other, read, idle_main, hold_main_max, hold_other_max),
  // then u32 presents, reads, read_kb, stream_pm, starves, starve_buf, clock_calls.
  const W = (base + 56) >> 2;
  const host = () => {
    const f = F(), u = U(), d = base >> 3;
    return [f[d], f[d + 1], f[d + 2], f[d + 3], f[d + 4], f[d + 5], f[d + 6], u[W], u[W + 1], u[W + 2], u[W + 3], u[W + 4], u[W + 6]];
  };
  let prev = host(), prevUnder = 0, prevResync = 0, rows = [], events = [];
  const ms = () => Math.round(performance.now() - t0);
  const r1 = x => Math.round(x * 10) / 10;
  const event = (kind, data) => events.push({ t: ms(), kind, ...data });

  function frame(s, t, runMs) {
    const h = host(), u = U();
    const d = k => h[k] - prev[k];
    const under = u[audio + 4], resync = u[audio + 5];
    rows.push([Math.round(t - t0), r1(runMs), s.present ? 1 : 0, s.draws, s.clears, s.words >> 10, s.texKb, s.pipes,
      s.shaders, s.targets, s.hd, r1(d(0)), r1(d(1)), r1(d(2)), r1(d(3)), r1(d(4)), r1(h[5]), r1(h[6]), d(8), d(9), d(7),
      h[10], h[11] - prev[11], h[11] !== prev[11] ? u[W + 5] : -1, (u[audio] - u[audio + 1]) | 0, under - prevUnder,
      resync - prevResync, d(12)]);
    F()[(base >> 3) + 5] = F()[(base >> 3) + 6] = 0; u[W + 3] = 0;     // the maxima are since the last row
    prev = h; prevUnder = under; prevResync = resync;
  }

  // The browser's own view of a slow frame: long animation frames (Chrome) with the scripts that ran in them.
  try {
    new PerformanceObserver(list => {
      for (const e of list.getEntries()) if (e.duration >= 50)
        events.push({ t: Math.round(e.startTime - t0), kind: 'loaf', dur: Math.round(e.duration), block: Math.round(e.blockingDuration || 0),
          scripts: (e.scripts || []).slice(0, 3).map(x => `${x.invoker || x.name} ${Math.round(x.duration)}ms`) });
    }).observe({ type: 'long-animation-frame', buffered: true });
  } catch {}
  addEventListener('visibilitychange', () => event('visibility', { state: document.visibilityState }));
  addEventListener('blur', () => event('focus', { state: 'blur' }));
  addEventListener('focus', () => event('focus', { state: 'focus' }));
  let marks = 0;
  addEventListener('keydown', e => {
    if (e.code !== 'F8') return;
    e.preventDefault(); e.stopPropagation();
    if (!e.repeat) { event('mark', { n: ++marks }); log(`telemetry: mark ${marks}`); }
  }, true);
  setInterval(() => event('heap', { mb: performance.memory ? Math.round(performance.memory.usedJSHeapSize / 1048576) : -1 }), 5000);

  const head = { kind: 'session', url: location.href, date: new Date().toISOString(), ua: navigator.userAgent,
    screen: `${innerWidth}x${innerHeight} dpr ${devicePixelRatio}`, cols: TELEM_COLS };
  fetch('/telemetry?new', { method: 'POST', body: JSON.stringify(head) + '\n' }).catch(() => {});
  function flush() {
    if (!rows.length && !events.length) return;
    let body = rows.length ? JSON.stringify({ rows }) + '\n' : '';
    for (const e of events) body += JSON.stringify(e) + '\n';
    rows = []; events = [];
    fetch('/telemetry', { method: 'POST', body, keepalive: body.length < 60000 }).catch(() => {});
  }
  setInterval(flush, 2000);
  addEventListener('pagehide', flush);
  log('telemetry: on (build/telemetry.ndjson), F8 = mark');
  return { frame, event };
}
