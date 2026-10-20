// One headless Chrome run of the page on 5180: prints the page log when it stops (or after the timeout)
// and saves a screenshot of the page.
// Usage: node tools/webcheck.mjs [url] [seconds] [screenshot.png] [keys]
// keys: "20:Enter,23:ArrowDown" = at that second, a tap of that KeyboardEvent.code on the canvas.
import { spawn } from 'node:child_process';
import { mkdtempSync, writeFileSync } from 'node:fs';
import { tmpdir } from 'node:os';
import { join } from 'node:path';

const url = process.argv[2] || 'http://127.0.0.1:5180/';
const secs = Number(process.argv[3] || 120);
const shot = process.argv[4] || 'build/webcheck.png';
const keys = (process.argv[5] || '').split(',').filter(Boolean).map(k => k.split(':')).map(([t, code]) => ({ t: +t, code }));
const port = 9333;
const chrome = spawn('/Applications/Google Chrome.app/Contents/MacOS/Google Chrome', [
  '--headless=new', `--remote-debugging-port=${port}`, `--user-data-dir=${mkdtempSync(join(tmpdir(), 'rn-'))}`,
  '--no-first-run', '--enable-unsafe-webgpu', '--window-size=1280,1100', 'about:blank'], { stdio: 'ignore' });
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
let text = '';
while (Date.now() - t0 < secs * 1000) {
  await sleep(1000);
  for (const k of keys.filter(k => !k.done && Date.now() - t0 >= k.t * 1000)) {
    k.done = true;
    await send('Runtime.evaluate', { expression: "document.getElementById('screen').focus()" });
    await send('Input.dispatchKeyEvent', { type: 'keyDown', code: k.code, key: k.code });
    await sleep(100);
    await send('Input.dispatchKeyEvent', { type: 'keyUp', code: k.code, key: k.code });
  }
  const r = await send('Runtime.evaluate', { expression: "document.getElementById('status')?.textContent + '\\n' + document.getElementById('log')?.innerText" });
  text = r?.result?.value || '';
  if (/STOP|Falta COOP/.test(text)) break;
}
await sleep(500);   // let the last frame reach the canvas
const png = await send('Page.captureScreenshot', { format: 'png' });
if (png?.data) { writeFileSync(shot, Buffer.from(png.data, 'base64')); console.log(`screenshot: ${shot}`); }
console.log(`[${((Date.now() - t0) / 1000).toFixed(1)} s]`);
console.log(text);
if (errors.length) console.log('page errors:\n' + errors.join('\n'));
chrome.kill();
process.exit(0);
