// One visit in Playwright's WebKit (Safari's engine), headless. Usage: node tools/webkit/wk.mjs <out> <url> [secs]; NOGPU=1 removes WebGPU (INJ=<file> other init script).
// Needs playwright (npm i playwright@1.64.1 + npx playwright install webkit, outside the repo; NODE_PATH to it). Writes <out>.json, <out>.lines.txt, <out>.png; HUNG = page silent 3 s.
import { webkit } from 'playwright';
import { readFileSync, writeFileSync } from 'node:fs';
const [out, url, secs = '90'] = process.argv.slice(2);
const browser = await webkit.launch({ headless: true, env: process.env.MSL ? { ...process.env, Malloc: '1', __XPC_Malloc: '1', __XPC_MallocStackLogging: 'lite' } : process.env });
const ctx = await browser.newContext({ viewport: { width: 844, height: 390 }, deviceScaleFactor: 2, isMobile: true, hasTouch: true,
  userAgent: 'Mozilla/5.0 (iPhone; CPU iPhone OS 18_5 like Mac OS X) AppleWebKit/605.1.15 (KHTML, like Gecko) Version/18.5 Mobile/15E148 Safari/604.1' });
if (process.env.NOGPU) await ctx.addInitScript(readFileSync(process.env.INJ || '/Users/angeldamian/RE-NFSU/tools/nowebgpu.js', 'utf8'));
const page = await ctx.newPage();
const cons = [];
const t0 = Date.now(), now = () => ((Date.now() - t0) / 1000).toFixed(2);
page.on('console', m => cons.push(`${now()} ${m.type()} ${m.text().slice(0, Number(process.env.CMAX || 400))}`));
page.on('pageerror', e => cons.push(`${now()} PAGEERROR ${String(e.stack || e).slice(0, 600)}`));
page.on('crash', () => cons.push(`${now()} CRASH`));
await page.goto(url);
let hud = null, hung = 0, seen = 0; const lines = [];
const T = (p, ms = 5000) => Promise.race([p, new Promise(ok => setTimeout(() => ok(null), ms))]);
setTimeout(() => { console.log('hard timeout'); process.exit(2); }, (Number(secs) + 60) * 1000).unref();
for (let i = 0; i < Number(secs) * 2; i++) {
  await page.waitForTimeout(500);
  const r = await Promise.race([page.evaluate(k => { const a = typeof allLog === 'undefined' ? [] : allLog; return [a.length, a.slice(-1).join(''), a.slice(k), performance.memory ? 0 : 0]; }, seen), new Promise(ok => setTimeout(() => ok(null), 3000))]).catch(e => [-1, 'ERR ' + e.message]);
  if (!r) { cons.push(`${now()} HUNG: page did not answer in 3 s`); if (++hung >= 4) break; continue; }
  const [n, tail, fresh] = r; hung = 0; if (n < seen) { cons.push(`${now()} RELOADED`); seen = 0; } else { for (const l of fresh) lines.push(`${now()} | ${l}`); seen = n; }
  writeFileSync(out + '.lines.txt', lines.join('\n'));
  if (!hud && /race HUD/.test(tail)) hud = now();
  if (i % 10 === 0) cons.push(`${now()} TICK lines ${n} last: ${String(tail).slice(0, 160)}`);
}
const host = (await T(page.evaluate(() => typeof allLog === 'undefined' ? [] : allLog)).catch(() => null)) || (await T(page.evaluate(() => document.getElementById('log')?.textContent.split('\n') || []), 3000).catch(() => null)) || [];
await T(page.screenshot({ path: out + '.png', timeout: 5000 }).catch(e => cons.push('shot failed ' + e.message)), 6000);
writeFileSync(out + '.json', JSON.stringify({ url, hud, cons, host }));
console.log('hud', hud, 'console', cons.length, 'host', host.length);
await T(browser.close(), 3000); process.exit(0);
