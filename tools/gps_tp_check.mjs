// One bounded, headless, muted WORLD run. Reuses tools/webcheck.mjs CDP/input patterns.
// Start tools/serve.py 5182 first; run: RN_SECS=240 node tools/gps_tp_check.mjs
// No RN_SPAWN: the car must drive in NFSU1 before teleporting into Bayview.
import { spawn, spawnSync } from 'node:child_process';
import { mkdirSync, mkdtempSync, rmSync, writeFileSync } from 'node:fs';
import { tmpdir } from 'node:os';
import { join } from 'node:path';

const secs = Math.min(1800, Math.max(60, Number(process.env.RN_SECS || 240)));
const url = 'http://127.0.0.1:5182/?play=1&pool=1&mode=remaster&mute=1&env=RN_JCLOG=1';
const dest = [-1053.7, 993.1, -1.5, 9526]; // plan row 12: previously driven UG2 street, NFSU1 frame.
const out = 'web/plan/shots', evidence = { url, destination: dest, verified: false };
mkdirSync(out, { recursive: true });
mkdirSync('build', { recursive: true });
rmSync('build/save-headless', { recursive: true, force: true }); // same isolated test save as webcheck.
const gate = spawnSync('/Users/angeldamian/.claude/hooks/macgate.sh', [], { stdio: 'inherit', timeout: 60000 });
if (gate.status !== 0) throw new Error('macgate did not admit the Chrome launch');
const profile = mkdtempSync(join(tmpdir(), 'rn-gpstp-'));
const chrome = spawn('/Users/angeldamian/.local/bin/chrome-bot', [
  '--headless=new', '--remote-debugging-port=9383', `--user-data-dir=${profile}`,
  '--no-first-run', '--enable-unsafe-webgpu', '--mute-audio', '--window-size=1280,900', 'about:blank',
], { stdio: 'ignore' });
const sleep = ms => new Promise(r => setTimeout(r, ms));
const started = Date.now(), errors = [], pending = new Map();
let ws, id = 0, pageLog = '', before, after, later;
process.on('exit', () => { chrome.kill('SIGKILL'); rmSync(profile, { recursive: true, force: true }); });
const deadline = setTimeout(() => { console.error('GPS TP FAIL: run timeout'); process.exit(1); }, secs * 1000);
try {
  let tabs;
  for (let i = 0; i < 50 && !tabs; i++) {
    try { tabs = await (await fetch('http://127.0.0.1:9383/json')).json(); } catch { await sleep(200); }
  }
  if (!tabs) throw new Error('Chrome CDP did not become available');
  ws = new WebSocket(tabs.find(t => t.type === 'page').webSocketDebuggerUrl);
  await new Promise(r => ws.onopen = r);
  ws.onmessage = e => {
    const m = JSON.parse(e.data);
    if (m.id && pending.has(m.id)) { pending.get(m.id)(m); pending.delete(m.id); }
    if (m.method === 'Runtime.exceptionThrown') errors.push(m.params.exceptionDetails.exception?.description || m.params.exceptionDetails.text);
  };
  const send = (method, params = {}) => new Promise((resolve, reject) => {
    const timer = setTimeout(() => reject(new Error(`CDP timeout: ${method}`)), 15000);
    pending.set(++id, m => { clearTimeout(timer); m.error ? reject(new Error(JSON.stringify(m.error))) : resolve(m.result); });
    ws.send(JSON.stringify({ id, method, params }));
  });
  const evaluate = async expression => {
    const r = await send('Runtime.evaluate', { expression, returnByValue: true, awaitPromise: true });
    if (r.exceptionDetails) throw new Error(r.exceptionDetails.exception?.description || r.exceptionDetails.text);
    return r.result?.value;
  };
  const key = async down => {
    await evaluate("document.getElementById('screen').focus()");
    await send('Input.dispatchKeyEvent', { type: down ? 'keyDown' : 'keyUp', code: 'KeyW', key: 'w' });
  };
  const sample = async () => {
    const r = await evaluate(`(() => {
      const M = window.RN_M, log = document.getElementById('log')?.innerText || '';
      if (!M || !M._rn_gps_addr) return { log };
      const p = M._rn_gps_addr(), f = new Float32Array(M.HEAPU8.buffer, p, 3), h = M.HEAP32, b = p >> 2;
      const track = M.HEAP32[(M._rn_mc_state() + 176) >> 2];
      return { log, track, city: window.Ug2?.state, pose: [...f], frame: h[b+5], valid: h[b+4], req: Atomics.load(h,b+10), res: Atomics.load(h,b+11) };
    })()`);
    pageLog = r.log;
    if (/STOP|Falta COOP|JS rejection|JS error/.test(pageLog)) throw new Error('page stopped');
    const matches = [...pageLog.matchAll(/JC f(\d+) mode (\d+) wheels (\d+) speed ([\d.-]+) pos ([\d.-]+),([\d.-]+),([\d.-]+) yaw (-?\d+)/g)];
    const m = matches.at(-1);
    if (m) r.car = { frame: +m[1], wheels: +m[3], speed: +m[4], pos: m.slice(5, 8).map(Number), yaw16: +m[8] };
    delete r.log;
    return r;
  };
  const until = async (fn, label, limit = 180000) => {
    const t = Date.now();
    while (Date.now() - t < limit && Date.now() - started < secs * 1000) {
      const s = await sample();
      if (fn(s)) return s;
      await sleep(500);
    }
    throw new Error(`timeout waiting for ${label}`);
  };
  const shot = async name => {
    const p = await send('Page.captureScreenshot', { format: 'png' });
    writeFileSync(`${out}/${name}.png`, Buffer.from(p.data, 'base64'));
  };
  await send('Runtime.enable');
  await send('Emulation.setDeviceMetricsOverride', { width: 1000, height: 700, deviceScaleFactor: 1, mobile: false });
  await send('Page.navigate', { url });
  await until(s => s.track === 1010 && s.city === 'ready' && s.car?.wheels > 0 && /d3d9 race HUD /.test(pageLog), 'WORLD driving with Bayview loaded');
  await key(true);
  before = await until(s => s.car?.speed > 2, 'car moving before teleport', 30000);
  await sleep(1500);
  before = await sample();
  await key(false);
  await evaluate(`import('/gps/tp.js').then(() => window.rnGpsTeleport(${dest.join(',')}))`);
  after = await until(s => s.res !== 0 && s.req === 0, 'teleport result', 30000);
  if (after.res !== 1) throw new Error('teleport rejected');
  await sleep(1500);
  after = await sample();
  await shot('gps_teleport');
  await key(true);
  await sleep(3000);
  await key(false);
  await sleep(3000);
  later = await sample();
  await shot('gps_teleport_later');
  const distance = a => Math.hypot(a[0] - dest[0], a[1] - dest[1]);
  if (!after.car || !later.car || distance(after.car.pos) > 30 || distance(later.car.pos) > 200 || later.car.wheels === 0)
    throw new Error('target position/ground evidence failed');
  if (Math.hypot(later.car.pos[0] - after.car.pos[0], later.car.pos[1] - after.car.pos[1]) < 2)
    throw new Error('car did not drive after teleport');
  if (errors.length) throw new Error('browser exceptions');
  evidence.verified = true;
  console.log(`GPS TP PASS: ${JSON.stringify(before.car)} -> ${JSON.stringify(after.car)} -> ${JSON.stringify(later.car)}`);
} catch (e) {
  evidence.failure = String(e);
  console.error(`GPS TP FAIL: ${e}`);
  process.exitCode = 1;
} finally {
  clearTimeout(deadline);
  writeFileSync('build/gps_tp_check.log', pageLog);
  writeFileSync('build/gps_tp_check.json', JSON.stringify({ ...evidence, before, after, later, errors, elapsed: (Date.now() - started) / 1000 }, null, 2) + '\n');
  ws?.close();
  chrome.kill('SIGKILL');
}
