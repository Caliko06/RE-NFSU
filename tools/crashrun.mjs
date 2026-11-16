// One bounded, headless, muted WORLD run that drives until the page stops ("STOP in thread"), for the 0x5838c3 / 0x44c56e crash
// family (host/crashwatch.c). Start tools/serve.py 5183 first; run: RN_SECS=600 node tools/crashrun.mjs [RN_SPAWN=x:y:z:yaw16]
// The page log goes to build/crashrun.log in full; stdout gets only the STOP / CW / DUEL lines (head -c 6000).
import { spawn, spawnSync } from 'node:child_process';
import { mkdirSync, mkdtempSync, rmSync, writeFileSync } from 'node:fs';
import { tmpdir } from 'node:os';
import { join } from 'node:path';

const secs = Math.min(1800, Math.max(60, Number(process.env.RN_SECS || 600)));
const spawnAt = process.argv[2] || 'RN_SPAWN=-1053.7:993.1:-1.5:9526';
const port = process.env.RN_PORT || '5183', cdp = process.env.RN_CDP_PORT || '9385';
const url = `http://127.0.0.1:${port}/?play=1&pool=1&start=world&mode=remaster&mute=1&env=RN_CRASHWATCH=1,${spawnAt},RN_FREELOG=1${process.env.RN_EXTRA ? ',' + process.env.RN_EXTRA : ''}`;   // RN_EXTRA=RN_CWFILL=1: the full-cache stress test
mkdirSync('build', { recursive: true });
rmSync('build/save-headless', { recursive: true, force: true });
const gate = spawnSync('/Users/angeldamian/.claude/hooks/macgate.sh', [], { stdio: 'inherit', timeout: 60000 });
if (gate.status !== 0) throw new Error('macgate did not admit the Chrome launch');
const profile = mkdtempSync(join(tmpdir(), 'rn-crash-'));
const chrome = spawn('/Users/angeldamian/.local/bin/chrome-bot', [
  '--headless=new', `--remote-debugging-port=${cdp}`, `--user-data-dir=${profile}`,
  '--no-first-run', '--enable-unsafe-webgpu', '--mute-audio', '--window-size=1280,900', 'about:blank'], { stdio: 'ignore' });
const sleep = ms => new Promise(r => setTimeout(r, ms));
const started = Date.now(), pending = new Map();
let ws, id = 0, pageLog = '', stopped = false;
const finish = (why) => {
  writeFileSync('build/crashrun.log', pageLog);
  const lines = pageLog.split('\n').filter(l => /STOP|CW|DUEL|stack:|eax=|SPAWN|JS error|JS rejection/.test(l));
  console.log(`crashrun: ${why} after ${((Date.now() - started) / 1000).toFixed(0)} s, ${pageLog.length} log chars`);
  console.log(lines.join('\n').slice(0, 9000));
  chrome.kill('SIGKILL'); rmSync(profile, { recursive: true, force: true });
  process.exit(stopped ? 2 : 0);
};
process.on('exit', () => { chrome.kill('SIGKILL'); rmSync(profile, { recursive: true, force: true }); });
let tabs;
for (let i = 0; i < 50 && !tabs; i++) { try { tabs = await (await fetch(`http://127.0.0.1:${cdp}/json`)).json(); } catch { await sleep(200); } }
ws = new WebSocket(tabs.find(t => t.type === 'page').webSocketDebuggerUrl);
await new Promise(r => ws.onopen = r);
ws.onmessage = e => { const m = JSON.parse(e.data); if (m.id && pending.has(m.id)) { pending.get(m.id)(m); pending.delete(m.id); } };
const send = (method, params = {}) => new Promise((resolve, reject) => {
  const t = setTimeout(() => reject(new Error('CDP timeout ' + method)), 15000);
  pending.set(++id, m => { clearTimeout(t); m.error ? reject(new Error(JSON.stringify(m.error))) : resolve(m.result); });
  ws.send(JSON.stringify({ id, method, params }));
});
const evaluate = async expression => (await send('Runtime.evaluate', { expression, returnByValue: true, awaitPromise: true })).result?.value;
const key = async (code, k, down) => { await evaluate("document.getElementById('screen')?.focus()"); await send('Input.dispatchKeyEvent', { type: down ? 'keyDown' : 'keyUp', code, key: k }); };
await send('Runtime.enable');
await send('Emulation.setDeviceMetricsOverride', { width: 1000, height: 700, deviceScaleFactor: 1, mobile: false });
await send('Page.navigate', { url });
let driving = false, tick = 0;
while ((Date.now() - started) / 1000 < secs) {
  pageLog = (await evaluate("document.getElementById('log')?.innerText || ''")) || pageLog;
  if (/STOP in thread|JS error|JS rejection/.test(pageLog)) { stopped = true; break; }
  if (!driving && /d3d9 race HUD /.test(pageLog)) { await sleep(8000); await key('KeyW', 'w', true); driving = true; }
  // steer a little in turns so the car keeps moving through the streets instead of stopping on the first wall
  if (driving && ++tick % 20 === 0) { const c = (tick / 20) % 4; await key('ArrowLeft', 'ArrowLeft', c === 1); await key('ArrowRight', 'ArrowRight', c === 3); if (c === 0) { await key('KeyW', 'w', false); await key('ArrowDown', 'ArrowDown', true); await sleep(1500); await key('ArrowDown', 'ArrowDown', false); await key('KeyW', 'w', true); } }
  await sleep(500);
}
await sleep(stopped ? 1500 : 0);
pageLog = (await evaluate("document.getElementById('log')?.innerText || ''")) || pageLog;
finish(stopped ? 'STOPPED' : 'time limit, no stop');
