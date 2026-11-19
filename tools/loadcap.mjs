// One cold visit, headless and muted: every request of the page and its workers with its times, and a shot at the end.
// Usage (through macgate.sh): node tools/loadcap.mjs <out prefix> <url>   -> <out>.json (rows: tools/entry_hint.py reads them), <out>.png
// Ends 12 s after the race HUD line of the page log, or at RN_SECS (150). RN_MOBILE=1: a phone (coarse pointer, 844x390).
// RN_PROFILE=<dir>: a normal profile kept on disk (run twice for the second visit; the default is a fresh private one).
// The round trip of a real visit: serve dist with RN_RTT_MS=80 tools/static_server.py (CDP cannot delay worker requests).
import { spawn } from 'node:child_process';
import { mkdtempSync, readFileSync, rmSync, writeFileSync } from 'node:fs';
import { tmpdir } from 'node:os';
import { join } from 'node:path';
const out = process.argv[2], url = process.argv[3], port = Number(process.env.RN_CDP || 9391);   // RN_CDP: one per slice (9382-9386)
const KEEP = process.env.RN_PROFILE, profile = KEEP || mkdtempSync(join(tmpdir(), 'rn-livecap-'));
const chrome = spawn('/Users/angeldamian/.local/bin/chrome-bot', ['--headless=new', '--mute-audio', '--enable-unsafe-webgpu',
  '--no-first-run', `--remote-debugging-port=${port}`, `--user-data-dir=${profile}`, 'about:blank'], { stdio: 'ignore' });
process.on('exit', () => { chrome.kill('SIGKILL'); if (!KEEP) try { rmSync(profile, { recursive: true, force: true, maxRetries: 10, retryDelay: 200 }); } catch { console.log('left behind: ' + profile); } });
const sleep = ms => new Promise(r => setTimeout(r, ms));
let info;
for (let i = 0; i < 50 && !info; i++) { try { info = await (await fetch(`http://127.0.0.1:${port}/json/version`)).json(); } catch { await sleep(200); } }
const ws = new WebSocket(info.webSocketDebuggerUrl);
await new Promise(r => ws.onopen = r);
let seq = 0; const pending = new Map();
const send = (method, params = {}, sessionId) => new Promise((resolve, reject) => {
  const id = ++seq; pending.set(id, { resolve, reject, method }); ws.send(JSON.stringify({ id, method, params, sessionId }));
});
let event = () => {};
ws.onmessage = e => { const m = JSON.parse(e.data); if (pending.has(m.id)) {
  const p = pending.get(m.id); pending.delete(m.id); m.error ? p.reject(new Error(p.method + ': ' + JSON.stringify(m.error))) : p.resolve(m.result);
} else event(m); };
setTimeout(() => { console.error('timeout'); process.exit(1); }, 280000).unref();
const { browserContextId } = KEEP ? {} : await send('Target.createBrowserContext');
const { targetId } = await send('Target.createTarget', { url: 'about:blank', browserContextId });
const { sessionId: page } = await send('Target.attachToTarget', { targetId, flatten: true });
const net = new Map(), cons = [];
let t0 = Date.now(); const now = () => (Date.now() - t0) / 1000;
async function configure(s) {
  await send('Network.enable', {}, s); await send('Runtime.enable', {}, s).catch(() => {});
  if (s === page) await send('Target.setAutoAttach', { autoAttach: true, flatten: true, waitForDebuggerOnStart: true }, s);
}
event = m => {
  const p = m.params, k = `${m.sessionId}:${p?.requestId}`;
  if (m.method === 'Target.attachedToTarget') configure(p.sessionId).then(() => send('Runtime.runIfWaitingForDebugger', {}, p.sessionId)).catch(() => {});
  if (m.method === 'Network.requestWillBeSent') net.set(k, { path: new URL(p.request.url).pathname, range: p.request.headers.Range,
    who: m.sessionId === page ? 'page' : 'worker', start: now(), bytes: 0 });
  if (m.method === 'Network.responseReceived' && net.has(k)) Object.assign(net.get(k), { status: p.response.status, ttfb: now(), cf: p.response.headers['cf-cache-status'], disk: p.response.fromDiskCache });
  if (m.method === 'Network.loadingFinished' && net.has(k)) Object.assign(net.get(k), { bytes: p.encodedDataLength, end: now() });
  if (m.method === 'Network.loadingFailed' && net.has(k)) net.get(k).error = p.errorText;
  if (m.method === 'Runtime.consoleAPICalled') cons.push([now(), p.args.map(a => a.value ?? a.description ?? '').join(' ').slice(0, Number(process.env.RN_CONS_MAX || 300))]);
};
await configure(page);
// RN_INJECT=<file>: a script run before the page's own (Page.addScriptToEvaluateOnNewDocument); RN_DUMP=<expr>: its value -> <out>.dump.json.
if (process.env.RN_INJECT) await send('Page.enable', {}, page), await send('Page.addScriptToEvaluateOnNewDocument', { source: readFileSync(process.env.RN_INJECT, 'utf8') }, page);
const MOBILE = process.env.RN_MOBILE === '1';
await send('Emulation.setDeviceMetricsOverride', MOBILE ? { width: 844, height: 390, deviceScaleFactor: 2, mobile: true } : { width: 1280, height: 720, deviceScaleFactor: 1, mobile: false }, page);
// RN_CPU=<n>: the page's CPU n times slower (an old phone; workers are not throttled by CDP).
if (process.env.RN_CPU) await send('Emulation.setCPUThrottlingRate', { rate: Number(process.env.RN_CPU) }, page);
if (MOBILE) await send('Emulation.setTouchEmulationEnabled', { enabled: true, maxTouchPoints: 5 }, page);
// RN_HEAPPROF=1: sample the page's JS allocations (garbage included) -> <out>.heap.json, by function.
if (process.env.RN_HEAPPROF) await send('HeapProfiler.enable', {}, page), await send('HeapProfiler.startSampling', { samplingInterval: 16384, includeObjectsCollectedByMajorGC: true, includeObjectsCollectedByMinorGC: true }, page);
t0 = Date.now();
await send('Page.navigate', { url }, page);
let seen = 0, hud = null; const lines = [];
while (now() < Number(process.env.RN_SECS || 150)) {
  await sleep(250);
  const log = (await send('Runtime.evaluate', { expression: "document.getElementById('log')?.textContent || ''", returnByValue: true }, page)).result.value || '';
  const all = log.split('\n');
  for (; seen < all.length - 1; seen++) lines.push([now(), all[seen]]);
  if (!hud && /d3d9 race HUD /.test(log)) { hud = now(); if (process.env.RN_HEAPPROF === 'race') { await send('HeapProfiler.stopSampling', {}, page); await send('HeapProfiler.startSampling', { samplingInterval: 16384, includeObjectsCollectedByMajorGC: true, includeObjectsCollectedByMinorGC: true }, page); } }   // 'race': only the race
  if (hud && now() > hud + 12) break;
  if (/STOP|JS rejection|JS error/.test(log)) break;
}
const { data } = await send('Page.captureScreenshot', { format: 'png' }, page);
writeFileSync(out + '.png', Buffer.from(data, 'base64'));
const host = (await send('Runtime.evaluate', { expression: "typeof allLog === 'undefined' ? [] : allLog", returnByValue: true }, page)).result.value || [];   // web/boot.js keep(): every host line
if (process.env.RN_HEAPPROF) writeFileSync(out + '.heap.json', JSON.stringify((await send('HeapProfiler.stopSampling', {}, page)).profile));
if (process.env.RN_DUMP) writeFileSync(out + '.dump.json', JSON.stringify((await send('Runtime.evaluate', { expression: process.env.RN_DUMP, returnByValue: true }, page)).result.value ?? null));
writeFileSync(out + '.json', JSON.stringify({ url, hud, rows: [...net.values()], lines, cons, host }));
console.log('hud', hud, 'requests', net.size, 'lines', lines.length, 'console', cons.length);
if (KEEP) { await send('Browser.close').catch(() => {}); await sleep(3000); }   // let the disk cache land
process.exit(0);
