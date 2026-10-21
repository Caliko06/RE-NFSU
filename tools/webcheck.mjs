// One headless Chrome run of the page on 5180: prints the page log when it stops (or after the timeout)
// and saves a screenshot of the page.
// Usage: node tools/webcheck.mjs [url] [seconds] [screenshot.png] [keys]
// keys: "20:Enter,23:ArrowDown" = at that second, a tap of that KeyboardEvent.code on the canvas;
// "60:KeyW+6" holds it 6 seconds (released on the first check after that).
// node tools/webcheck.mjs --route: the regression route; exit 0 = PASS. It grows with each milestone met.
import { spawn } from 'node:child_process';
import { mkdtempSync, writeFileSync } from 'node:fs';
import { tmpdir } from 'node:os';
import { join } from 'node:path';

// Title -> profile "asas" -> Quick Race, Olympic Square. PASS: no STOP, the race starts (the device Reset to the
// window size, PATCH 0x40877e) and runs `hold` more seconds.
const ROUTE = { keys: '20:Enter,23:Enter,26:ArrowRight,29:Enter,32:Enter,35:Enter,38:Enter,44:Enter,50:Enter',
  marker: /d3d9 Reset: \d+x\d+/, hold: 20, secs: 150, shot: 'build/route.png' };
const route = process.argv[2] === '--route';
const arg = route ? [] : process.argv.slice(2);
const url = arg[0] || 'http://127.0.0.1:5180/';
const secs = route ? ROUTE.secs : Number(arg[1] || 120);
const shot = route ? ROUTE.shot : arg[2] || 'build/webcheck.png';
const keys = ((route ? ROUTE.keys : arg[3]) || '').split(',').filter(Boolean).map(k => k.split(':')).map(([t, c]) => ({ t: +t, code: c.split('+')[0], hold: +(c.split('+')[1] || 0) }));
const port = 9333;
const chrome = spawn('/Applications/Google Chrome.app/Contents/MacOS/Google Chrome', [
  '--headless=new', `--remote-debugging-port=${port}`, `--user-data-dir=${mkdtempSync(join(tmpdir(), 'rn-'))}`,
  '--no-first-run', '--enable-unsafe-webgpu', '--mute-audio', '--window-size=1280,1100', 'about:blank'], { stdio: 'ignore' });
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
const send = (method, params = {}) => new Promise(r => { pending.set(++id, r); ws.send(JSON.stringify({ id, method, params })); });
await send('Runtime.enable');
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
  const r = await send('Runtime.evaluate', { expression: "document.getElementById('status')?.textContent + '\\n' + document.getElementById('log')?.innerText" });
  text = r?.result?.value || '';
  if (/STOP|Falta COOP/.test(text)) break;
  if (route && !seen && ROUTE.marker.test(text)) seen = Date.now();
  if (seen && Date.now() - seen >= ROUTE.hold * 1000) break;
}
await sleep(500);   // let the last frame reach the canvas
const png = await send('Page.captureScreenshot', { format: 'png' });
if (png?.data) { writeFileSync(shot, Buffer.from(png.data, 'base64')); console.log(`screenshot: ${shot}`); }
console.log(`[${((Date.now() - t0) / 1000).toFixed(1)} s]`);
console.log(text);
if (errors.length) console.log('page errors:\n' + errors.join('\n'));
chrome.kill('SIGKILL');   // headless Chrome can ignore SIGTERM and keep the game (and its sound) running
if (route) {
  const why = /STOP/.test(text) ? 'a STOP' : !seen ? `no ${ROUTE.marker} in ${secs} s` : Date.now() - seen < ROUTE.hold * 1000 ? 'ended early' : '';
  console.log(why ? `ROUTE FAIL: ${why}` : `ROUTE PASS: race started at ${((seen - t0) / 1000).toFixed(0)} s and ran ${ROUTE.hold} s`);
  process.exit(why ? 1 : 0);
}
process.exit(0);
