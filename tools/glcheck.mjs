// Compiles every captured render pipeline through web/webgpu_gl.js (WGSL -> GLSL ES 3.00 -> WebGL 2) in headless Chrome, at once.
// Capture first: RN_INJECT=<pipes.js> RN_DUMP='Object.values(RN_PIPES)' tools/loadcap.mjs logs/pipes <url>  (pipes.js wraps
// GPUDevice.createShaderModule/createRenderPipeline). RN_SHOW=<i>: print pipeline i's GLSL. Usage (through macgate.sh): node tools/glcheck.mjs logs/pipes.dump.json
import { spawn } from 'node:child_process';
import { mkdtempSync, readFileSync, rmSync } from 'node:fs';
import { tmpdir } from 'node:os';
import { join } from 'node:path';
const pipes = JSON.parse(readFileSync(process.argv[2], 'utf8')), port = Number(process.env.RN_CDP || 9392);
const profile = mkdtempSync(join(tmpdir(), 'rn-glcheck-'));
const chrome = spawn('/Users/angeldamian/.local/bin/chrome-bot', ['--headless=new', '--mute-audio', '--no-first-run',
  `--remote-debugging-port=${port}`, `--user-data-dir=${profile}`, 'about:blank'], { stdio: 'ignore' });
process.on('exit', () => { chrome.kill('SIGKILL'); try { rmSync(profile, { recursive: true, force: true }); } catch {} });
const sleep = ms => new Promise(r => setTimeout(r, ms));
let tabs;
for (let i = 0; i < 50 && !tabs?.length; i++) { try { tabs = (await (await fetch(`http://127.0.0.1:${port}/json/list`)).json()).filter(t => t.type === 'page'); } catch { await sleep(200); } }
const ws = new WebSocket(tabs[0].webSocketDebuggerUrl);
await new Promise(r => ws.onopen = r);
let seq = 0; const pending = new Map();
ws.onmessage = e => { const m = JSON.parse(e.data); pending.get(m.id)?.(m); pending.delete(m.id); };
const ev = expression => new Promise(r => { const id = ++seq; pending.set(id, r); ws.send(JSON.stringify({ id, method: 'Runtime.evaluate', params: { expression, returnByValue: true } })); });
await ev(readFileSync(new URL('../web/webgpu_gl.js', import.meta.url), 'utf8'));
const r = await ev(`(() => { const P = ${JSON.stringify(pipes)}, gl = document.createElement('canvas').getContext('webgl2'), out = [];
  const W = window.webgpu_js; console.error = () => {};
  P.forEach((p, i) => { let st = 'vs';
    try { const v = W.compileWgsl(p.vs, 'vertex', p.ve); st = 'fs';
      const f = p.fs ? W.compileWgsl(p.fs, 'fragment', p.fe) : { glsl: '#version 300 es\\nprecision highp float;\\nvoid main() {}' };
      st = 'gl'; W.compileGlProgram(gl, v.glsl, f.glsl); out.push([i, 'ok', p.ve + '/' + p.fe, '', i === ${Number(process.env.RN_SHOW ?? -1)} ? 'VS\\n' + v.glsl + '\\nFS\\n' + f.glsl : '']);
    } catch (e) { const L = window.__webgpuLastShaderError; out.push([i, 'FAIL ' + st, p.ve + '/' + p.fe, String(e.message || e).slice(0, 400), L ? L.kind + '\\n' + L.src : '']); window.__webgpuLastShaderError = null; } });
  return out; })()`);
const res = r.result.result.value || [r.result];
let bad = 0;
for (const [i, st, ep, msg, src] of res) { console.log(i, st, ep, msg || ''); if (st !== 'ok') bad++; if (src && (process.env.RN_SRC || st === 'ok')) console.log(src.split('\n').map((l, n) => `${n + 1} ${l}`).join('\n')); }
console.log(`${res.length - bad}/${res.length} pipelines compile`);
process.exit(0);
