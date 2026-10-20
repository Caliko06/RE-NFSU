// One headless Chrome run of the page on 5180: prints the page log when it stops (or after the timeout).
// Usage: node tools/webcheck.mjs [url] [seconds]
import { spawn } from 'node:child_process';
import { mkdtempSync } from 'node:fs';
import { tmpdir } from 'node:os';
import { join } from 'node:path';

const url = process.argv[2] || 'http://127.0.0.1:5180/';
const secs = Number(process.argv[3] || 120);
const port = 9333;
const chrome = spawn('/Applications/Google Chrome.app/Contents/MacOS/Google Chrome', [
  '--headless=new', `--remote-debugging-port=${port}`, `--user-data-dir=${mkdtempSync(join(tmpdir(), 'rn-'))}`,
  '--no-first-run', '--enable-unsafe-webgpu', 'about:blank'], { stdio: 'ignore' });
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
  const r = await send('Runtime.evaluate', { expression: "document.getElementById('status')?.textContent + '\\n' + document.getElementById('log')?.innerText" });
  text = r?.result?.value || '';
  if (/STOP|Falta COOP/.test(text)) break;
}
console.log(`[${((Date.now() - t0) / 1000).toFixed(1)} s]`);
console.log(text);
if (errors.length) console.log('page errors:\n' + errors.join('\n'));
chrome.kill();
process.exit(0);
