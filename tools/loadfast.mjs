// One paired measurement: separate cold browser contexts, local then 50 Mbit/s.
// Run through macgate.sh. RN_URL / RN_CDP_PORT select this slice's server/browser.
import { spawn } from 'node:child_process';
import { mkdtempSync, rmSync, mkdirSync, writeFileSync, copyFileSync } from 'node:fs';
import { tmpdir } from 'node:os';
import { join } from 'node:path';
const out = process.argv[2] || 'build/loadfast/before';
mkdirSync(out, { recursive: true });
const port = Number(process.env.RN_CDP_PORT || 9382);
const url = process.env.RN_URL || 'http://127.0.0.1:5181/?play=1&pool=1&start=world&mode=remaster&mute=1';
const profile = mkdtempSync(join(tmpdir(), 'rn-loadfast-'));
const chrome = spawn('/Users/angeldamian/.local/bin/chrome-bot', ['--headless=new', '--mute-audio', '--enable-unsafe-webgpu',
  '--no-first-run', `--remote-debugging-port=${port}`, `--user-data-dir=${profile}`, 'about:blank'], { stdio: 'ignore' });
process.on('exit', () => { chrome.kill('SIGKILL'); rmSync(profile, { recursive: true, force: true }); });
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
  const p = pending.get(m.id); pending.delete(m.id); m.error ? p.reject(new Error(p.method + ": " + JSON.stringify(m.error))) : p.resolve(m.result);
} else event(m); };
// Both cases fit within a 300 second paired run; hard stop also covers stuck CDP.
setTimeout(() => { console.error('paired run timeout'); process.exit(1); }, 295000).unref();
for (const mbps of [0, 50]) {
  rmSync('build/save-headless', { recursive: true, force: true });
  const { browserContextId } = await send('Target.createBrowserContext');
  const { targetId } = await send('Target.createTarget', { url: 'about:blank', browserContextId });
  const { sessionId: page } = await send('Target.attachToTarget', { targetId, flatten: true });
  const net = new Map(), setup = [], errors = [];
  let t0 = Date.now();
  async function configure(s) {
    await send('Network.enable', {}, s);
    // A new context is already cold. Leave HTTP caching on to measure production behavior.
    if (s === page) await send('Network.emulateNetworkConditions', { offline: false, latency: 0,
      downloadThroughput: mbps ? mbps * 1e6 / 8 : -1, uploadThroughput: mbps ? mbps * 1e6 / 8 : -1 }, s);
    if (s === page) await send('Target.setAutoAttach', { autoAttach: true, flatten: true, waitForDebuggerOnStart: true }, s);
  }
  event = m => {
    const p = m.params, k = `${m.sessionId}:${p?.requestId}`;
    if (m.method === 'Target.attachedToTarget') setup.push(configure(p.sessionId).then(() => send('Runtime.runIfWaitingForDebugger', {}, p.sessionId)));
    if (m.method === 'Network.requestWillBeSent') net.set(k, { path: new URL(p.request.url).pathname, range: p.request.headers.Range,
      session: m.sessionId === page ? 'page' : 'worker', start: (Date.now() - t0) / 1000, bytes: 0 });
    if (m.method === 'Network.dataReceived' && net.has(k)) { const r = net.get(k); (r.chunks ||= []).push([(Date.now() - t0) / 1000, p.encodedDataLength]); }
    if (m.method === 'Network.loadingFinished' && net.has(k)) Object.assign(net.get(k), { bytes: p.encodedDataLength, end: (Date.now() - t0) / 1000 });
    if (m.method === 'Network.loadingFailed' && net.has(k)) net.get(k).error = p.errorText;
  };
  await configure(page);
  await send('Emulation.setDeviceMetricsOverride', { width: 1280, height: 720, deviceScaleFactor: 1, mobile: false }, page);
  t0 = Date.now();
  await send('Page.navigate', { url }, page);
  let log = '', menu = null, hud = null, city = null;
  while (Date.now() - t0 < 140000) {
    await sleep(200);
    log = (await send('Runtime.evaluate', { expression: "document.getElementById('log')?.innerText || ''", returnByValue: true }, page)).result.value;
    if (!menu && /flow state 3\/255/.test(log)) menu = (Date.now() - t0) / 1000;
    if (!hud && /d3d9 race HUD /.test(log)) hud = (Date.now() - t0) / 1000;
    if (!city && /ug2: textured:/.test(log)) city = (Date.now() - t0) / 1000;
    if (hud && city) break;
    if (/STOP|JS rejection|JS error/.test(log)) { errors.push('page stopped'); break; }
  }
  // Hold a little beyond HUD so the screenshot shows the world, recording HUD costs separately.
  if (hud) await sleep(1500);
  const name = mbps ? '50mbit' : 'local';
  const { data } = await send('Page.captureScreenshot', { format: 'png' }, page);
  writeFileSync(`${out}/${name}.png`, Buffer.from(data, 'base64'));
  writeFileSync(`${out}/${name}.log`, log);
  copyFileSync('build/webcheck.log', `${out}/${name}.timed.log`);
  const rows = [...net.values()];
  const phase = end => end === null ? null : rows.filter(r => r.start <= end).reduce((a, r) => {
    a.requests++; a.bytes += r.end <= end ? r.bytes : (r.chunks || []).filter(c => c[0] <= end).reduce((n, c) => n + c[1], 0); return a;
  }, { seconds: end, requests: 0, bytes: 0 });
  const result = { url, mbps, throttle: 'CDP page network conditions (worker traffic logged), zero added RTT; fresh isolated browser context',
    menu: phase(menu), driving: phase(hud), cityReady: phase(city), errors, rows };
  writeFileSync(`${out}/${name}.json`, JSON.stringify(result, null, 1));
  console.log(JSON.stringify({ name, menu: result.menu, driving: result.driving, cityReady: result.cityReady, errors }));
  await Promise.all(setup);
  event = () => {};
  await send('Target.disposeBrowserContext', { browserContextId });
}
process.exit(0);
