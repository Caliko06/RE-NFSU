// One headless Chrome run of the page on 5180: prints the page log when it stops (or after the timeout)
// and saves a screenshot of the page.
// Usage: node tools/webcheck.mjs [url] [seconds] [screenshot.png] [keys]
// keys: "20:Enter,23:ArrowDown" = at that second, a tap of that KeyboardEvent.code on the canvas;
// "60:KeyW+6" holds it 6 seconds (released on the first check after that).
// node tools/webcheck.mjs --route: the regression route; exit 0 = PASS. It grows with each milestone met.
import { spawn } from 'node:child_process';
import { appendFileSync, mkdirSync, mkdtempSync, rmSync, writeFileSync } from 'node:fs';
import { tmpdir } from 'node:os';
import { join } from 'node:path';

// Title -> profile "asas" -> Quick Race, Olympic Square. PASS: no STOP, the race starts (its HUD at the window size: the
// device is made at the screen size since PATCH 0x408a24, so no Reset comes) and runs `hold` more seconds. M8.5: the page is 1920x1080 device pixels (dpr 1), so the
// race HUD and every present are 1920x1080.
const ROUTE = { keys: '20:Enter,23:Enter,26:ArrowRight,29:Enter,32:Enter,35:Enter,38:Enter,44:Enter,50:Enter',
  marker: /d3d9 race HUD 1920x1080 /, present: /present 1920x1080/, view: { width: 1920, height: 1080 }, hold: 20, secs: 150,
  shot: 'build/route.png' };
const route = process.argv[2] === '--route';
const arg = route ? [] : process.argv.slice(2);
const url = arg[0] || 'http://127.0.0.1:5180/';
const secs = route ? ROUTE.secs : Number(arg[1] || 120);
const shot = route ? ROUTE.shot : arg[2] || 'build/webcheck.png';
const keys = ((route ? ROUTE.keys : arg[3]) || '').split(',').filter(Boolean).map(k => k.split(':')).map(([t, c]) => ({ t: +t, code: c.split('+')[0], hold: +(c.split('+')[1] || 0) }));
// Each run starts from a fresh copy of the OWNER's save (tools/serve.py gives headless Chrome build/save-headless).
rmSync('build/save-headless', { recursive: true, force: true });
const port = Number(process.env.RN_CDP_PORT || 9333);   // another session may hold 9333: then use your own
const profileDir = mkdtempSync(join(tmpdir(), 'rn-'));
// RN_X11=1 (Pod, AGENTS.md): headless Chrome on Linux gets SwiftShader, so Chrome runs on an Xvfb DISPLAY with Vulkan,
// which gives WebGPU the NVIDIA. The user agent still says HeadlessChrome: tools/serve.py tells test runs apart by it.
const x11 = process.env.RN_X11 ? ['--ozone-platform=x11', '--enable-features=Vulkan', '--ignore-gpu-blocklist', '--no-sandbox',
  '--user-agent=Mozilla/5.0 (X11; Linux x86_64) HeadlessChrome webcheck'] : ['--headless=new'];
const chrome = spawn(process.env.RN_CHROME || '/Applications/Google Chrome.app/Contents/MacOS/Google Chrome', [
  ...x11, `--remote-debugging-port=${port}`, `--user-data-dir=${profileDir}`,
  '--no-first-run', '--enable-unsafe-webgpu', '--mute-audio', '--window-size=1280,1100', 'about:blank'], { stdio: 'ignore' });
// Each profile is ~330 MB: 107 left behind filled 29 GB of the Mac. Removed on every exit.
process.on('exit', () => { chrome.kill('SIGKILL'); try { rmSync(profileDir, { recursive: true, force: true }); } catch {} });
const sleep = ms => new Promise(r => setTimeout(r, ms));
let tabs;
for (let i = 0; i < 50 && !tabs; i++) { try { tabs = await (await fetch(`http://127.0.0.1:${port}/json`)).json(); } catch { await sleep(200); } }
const ws = new WebSocket(tabs.find(t => t.type === 'page').webSocketDebuggerUrl);
await new Promise(r => ws.onopen = r);
let id = 0; const pending = new Map(); const errors = [];
ws.onmessage = e => {
  const m = JSON.parse(e.data);
  if (m.id && pending.has(m.id)) { pending.get(m.id)(m.result); pending.delete(m.id); }
  if (m.method === 'Runtime.exceptionThrown') errors.push(m.params.exceptionDetails.exception?.description || m.params.exceptionDetails.text);
  if (m.method === 'Runtime.consoleAPICalled' && m.params.type === 'error') errors.push(m.params.args.map(a => a.value ?? a.description).join(' '));
};
const send = (method, params = {}, sessionId) => new Promise(r => { pending.set(++id, r); ws.send(JSON.stringify({ id, method, params, sessionId })); });
await send('Runtime.enable');
// RN_PROFILE=start:secs: a CPU sampling profile of every worker (the game runs in them) from second `start` for `secs`
// seconds -> build/profile.txt, functions by self and total time. Names need a web build with RN_PROF=1.
const prof = process.env.RN_PROFILE?.split(':').map(Number), workers = new Map();
if (prof) {
  const onmsg = ws.onmessage;
  ws.onmessage = e => { const m = JSON.parse(e.data); if (m.method === 'Target.attachedToTarget') workers.set(m.params.sessionId, m.params.targetInfo); onmsg(e); };
  await send('Target.setAutoAttach', { autoAttach: true, waitForDebuggerOnStart: false, flatten: true });
}
// RN_NETLOG=file: each game file the page reads (first request per path, any worker), with the page second -> file.
// Which files a menu path loads, without RN_TRACE (its log slows the game down so much that timed keys miss).
const netlog = process.env.RN_NETLOG;
if (netlog) {
  writeFileSync(netlog, '');
  const seen = new Set(), onmsg = ws.onmessage, n0 = Date.now();
  ws.onmessage = e => {
    const m = JSON.parse(e.data);
    if (m.method === 'Target.attachedToTarget') send('Network.enable', {}, m.params.sessionId);
    if (m.method === 'Network.requestWillBeSent') {
      const u = decodeURIComponent(new URL(m.params.request.url).pathname);
      if (u.startsWith('/game/') && !seen.has(u)) { seen.add(u); appendFileSync(netlog, `${((Date.now() - n0) / 1000).toFixed(1)} ${u.slice(6)}\n`); }
    }
    onmsg(e);
  };
  await send('Network.enable');
  await send('Target.setAutoAttach', { autoAttach: true, waitForDebuggerOnStart: false, flatten: true });
}
let profState = 0;
const afterHud = process.env.RN_AFTER_HUD ? Number(process.env.RN_AFTER_HUD) : -1;
let hudAt = 0;
async function profile() {
  if (profState === 0 && Date.now() - t0 >= prof[0] * 1000) {
    profState = 1;
    workers.set(undefined, { url: 'page' });       // the page's own thread (gpu.js runs the frames there)
    for (const s of workers.keys()) { await send('Profiler.enable', {}, s); await send('Profiler.setSamplingInterval', { interval: 250 }, s); await send('Profiler.start', {}, s); }
  } else if (profState === 1 && Date.now() - t0 >= (prof[0] + prof[1]) * 1000) {
    profState = 2;
    let out = `CPU profile ${prof[1]} s from ${prof[0]} s, ${url}; per worker: samples, then functions by self and total %\n`;
    for (const s of workers.keys()) {
      const p = (await send('Profiler.stop', {}, s))?.profile;
      if (!p) continue;
      const byId = new Map(p.nodes.map(n => [n.id, n])), parent = new Map();
      for (const n of p.nodes) for (const c of n.children || []) parent.set(c, n.id);
      const self = new Map(), total = new Map(), n = p.samples.length;
      for (const id of p.samples) {
        const name = k => byId.get(k).callFrame.functionName || '(anon)';
        self.set(name(id), (self.get(name(id)) || 0) + 1);
        const seen = new Set();
        for (let k = id; k; k = parent.get(k)) seen.add(name(k));
        for (const x of seen) total.set(x, (total.get(x) || 0) + 1);
      }
      const idle = (self.get('(idle)') || 0) + (self.get('(program)') || 0);
      if (n - idle < 200) continue;
      const pct = v => (100 * v / n).toFixed(1).padStart(5);
      out += `\n== ${s ? 'worker' : 'page'} ${workers.get(s).url.split('/').pop()} ${(s || '').slice(0, 8)}: ${n} samples, idle/program ${pct(idle)}%\n self:\n`;
      for (const [k, v] of [...self].sort((a, b) => b[1] - a[1]).slice(0, 40)) out += `${pct(v)}  ${k}\n`;
      out += ' total (self + callees):\n';
      for (const [k, v] of [...total].sort((a, b) => b[1] - a[1]).slice(0, 40)) out += `${pct(v)}  ${k}\n`;
    }
    writeFileSync('build/profile.txt', out);
    console.log('profile: build/profile.txt');
  }
}
if (route) await send('Emulation.setDeviceMetricsOverride', { ...ROUTE.view, deviceScaleFactor: 1, mobile: false });
// RN_VIEW=WxH@dpr: the page at the OWNER's window size and pixel ratio (a stop can depend on the back buffer size).
const view = process.env.RN_VIEW?.match(/^(\d+)x(\d+)@([\d.]+)$/);
if (view) await send('Emulation.setDeviceMetricsOverride', { width: +view[1], height: +view[2], deviceScaleFactor: +view[3], mobile: false });
// RN_REC=dir: every frame the compositor makes (CDP screencast, jpeg) -> dir/<page ms>.jpg; tools/recvideo.sh turns them
// into a video with the real frame times (A/B against the Wine reference recording, tools/wine/rec.sh).
const rec = process.env.RN_REC;
if (rec) {
  mkdirSync(rec, { recursive: true });
  const onmsg = ws.onmessage;
  ws.onmessage = e => {
    const m = JSON.parse(e.data);
    if (m.method === 'Page.screencastFrame') {
      writeFileSync(join(rec, `${Math.round(m.params.metadata.timestamp * 1000)}.jpg`), Buffer.from(m.params.data, 'base64'));
      ws.send(JSON.stringify({ id: ++id, method: 'Page.screencastFrameAck', params: { sessionId: m.params.sessionId } }));
    }
    onmsg(e);
  };
}
// RN_REC_AT=s: start that recording at second s of the page (the race start), not at load: the disk is tight.
const recAt = rec ? Number(process.env.RN_REC_AT || 0) : -1;
let recOn = false;
async function recStart() { recOn = true; await send('Page.startScreencast', { format: 'jpeg', quality: 90, everyNthFrame: 1 }); }
if (recAt === 0) await recStart();
await send('Page.navigate', { url });
const t0 = Date.now();
let text = '', seen = 0;
while (Date.now() - t0 < secs * 1000) {
  await sleep(1000);
  for (const k of keys.filter(k => !k.done && Date.now() - t0 >= k.t * 1000)) {
    k.done = true;
    await send('Runtime.evaluate', { expression: "document.getElementById('screen').focus()" });
    await send('Input.dispatchKeyEvent', { type: 'keyDown', code: k.code, key: k.code });
    if (k.hold) continue;
    await sleep(100);
    await send('Input.dispatchKeyEvent', { type: 'keyUp', code: k.code, key: k.code });
  }
  for (const k of keys.filter(k => k.done && k.hold && !k.up && Date.now() - t0 >= (k.t + k.hold) * 1000)) {
    k.up = true;
    await send('Input.dispatchKeyEvent', { type: 'keyUp', code: k.code, key: k.code });
  }
  if (recAt > 0 && !recOn && Date.now() - t0 >= recAt * 1000) await recStart();
  if (prof) await profile();
  const r = await send('Runtime.evaluate', { expression: "document.getElementById('status')?.textContent + '\\n' + document.getElementById('log')?.innerText" });
  text = r?.result?.value || '';
  if (/STOP|Falta COOP/.test(text)) break;
  if (route && !seen && ROUTE.marker.test(text)) seen = Date.now();
  if (seen && Date.now() - seen >= ROUTE.hold * 1000) break;
  // RN_AFTER_HUD=s: the shot s seconds after the race HUD appears (the race starts at a different second each run, so a
  // shot at a fixed page time shows a different moment: camera-dependent effects then look like regressions).
  if (afterHud >= 0 && !hudAt && /d3d9 race HUD /.test(text)) hudAt = Date.now();
  if (hudAt && Date.now() - hudAt >= afterHud * 1000) break;
}
await sleep(500);   // let the last frame reach the canvas
const png = await send('Page.captureScreenshot', { format: 'png' });
if (png?.data) { writeFileSync(shot, Buffer.from(png.data, 'base64')); console.log(`screenshot: ${shot}`); }
console.log(`[${((Date.now() - t0) / 1000).toFixed(1)} s]`);
console.log(text);
if (errors.length) console.log('page errors:\n' + errors.join('\n'));
chrome.kill('SIGKILL');   // headless Chrome can ignore SIGTERM and keep the game (and its sound) running
if (route) {
  const why = /STOP/.test(text) ? 'a STOP' : errors.length ? 'a page error' : !seen ? `no ${ROUTE.marker} in ${secs} s`
    : Date.now() - seen < ROUTE.hold * 1000 ? 'ended early' : !ROUTE.present.test(text) ? `no ${ROUTE.present}` : '';
  console.log(why ? `ROUTE FAIL: ${why}` : `ROUTE PASS: race started at ${((seen - t0) / 1000).toFixed(0)} s and ran ${ROUTE.hold} s, present 1920x1080`);
  process.exit(why ? 1 : 0);
}
process.exit(0);
