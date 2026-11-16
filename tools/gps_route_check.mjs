// One bounded integration check: map click, real cross-city route, driving HUD, clear, teleport and arrival.
// Serve the slice on 5183; RN_SECS=300 node tools/gps_route_check.mjs. GPS_PORT=5180 GPS_FINAL=1: main, launcher WORLD path, teleport only by the map button.
import { spawn, spawnSync } from 'node:child_process';
import { mkdirSync, mkdtempSync, rmSync, writeFileSync } from 'node:fs';
import { tmpdir } from 'node:os';
import { join } from 'node:path';

const secs = Math.min(1800, Math.max(60, Number(process.env.RN_SECS || 300)));
const FINAL = process.env.GPS_FINAL === '1';
const url = `http://127.0.0.1:${process.env.GPS_PORT || 5183}/?play=1&pool=1&start=world&mode=remaster&mute=1&env=RN_JCLOG=1`;
const dest = [-1053.7, 993.1]; // map click in Bayview; route.js selects the actual street-node XYZ and yaw.
const out = 'web/plan/shots', evidence = { url, destination: dest, verified: false };
mkdirSync(out, { recursive: true });
mkdirSync('build', { recursive: true });
rmSync('build/save-headless', { recursive: true, force: true }); // same isolated test save as webcheck.
const gate = spawnSync('/Users/angeldamian/.claude/hooks/macgate.sh', [], { stdio: 'inherit', timeout: 60000 });
if (gate.status !== 0) throw new Error('macgate did not admit the Chrome launch');
const profile = mkdtempSync(join(tmpdir(), 'rn-gpsroute-'));
const chrome = spawn('/Users/angeldamian/.local/bin/chrome-bot', [
  '--headless=new', '--remote-debugging-port=9384', `--user-data-dir=${profile}`,
  '--no-first-run', '--enable-unsafe-webgpu', '--mute-audio', '--window-size=1280,900', 'about:blank',
], { stdio: 'ignore' });
const sleep = ms => new Promise(r => setTimeout(r, ms));
const started = Date.now(), errors = [], pending = new Map();
let ws, id = 0, pageLog = '', before, after, later;
const chromeClosed = new Promise(resolve => chrome.once('close', resolve));
process.on('exit', () => { chrome.kill('SIGKILL'); });
const deadline = setTimeout(() => { console.error('GPS ROUTE FAIL: run timeout'); process.exit(1); }, secs * 1000);
try {
  let tabs;
  for (let i = 0; i < 50 && !tabs; i++) {
    try { tabs = await (await fetch('http://127.0.0.1:9384/json')).json(); } catch { await sleep(200); }
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
  const press = async (code, key) => {
    await send('Input.dispatchKeyEvent', { type: 'keyDown', code, key });
    await send('Input.dispatchKeyEvent', { type: 'keyUp', code, key });
  };
  const clickDestination = async () => {
    const xy = await evaluate(`(() => { const p=RN_GPS.project(${dest[0]},${dest[1]}); const r=RN_GPS.canvas.getBoundingClientRect(); return [p[0]+r.left,p[1]+r.top]; })()`);
    await send('Input.dispatchMouseEvent', {type:'mousePressed',x:xy[0],y:xy[1],button:'left',clickCount:1});
    await send('Input.dispatchMouseEvent', {type:'mouseReleased',x:xy[0],y:xy[1],button:'left',clickCount:1});
  };
  const routeState = () => evaluate(`(() => {
    const r=RN_GPS.route, M=RN_M, base=M._rn_gps_addr()>>>2;
    if (!r) return { route:null, count:Atomics.load(M.HEAP32,base+12), status:document.querySelector('.gps-route-info').textContent };
    const edges=new Set(RN_GPS.roads.edges.map(([a,b])=>a<b?a+':'+b:b+':'+a));
    const valid=r.ids.slice(1).every((b,i)=>{const a=r.ids[i];return edges.has(a<b?a+':'+b:b+':'+a)});
    const sections=RN_GPS.roads.sections.filter(s=>s.nodes.some(id=>r.ids.includes(id))).map(s=>s.id);
    return {metres:r.metres,nodes:r.ids.length,start:r.start,destination:r.destination,snapped:RN_GPS.roads.nodes[r.destination],sections,valid,count:Atomics.load(M.HEAP32,base+12),status:document.querySelector('.gps-route-info').textContent};
  })()`);
  await press('KeyM','m');
  for(let i=0;i<40 && !await evaluate('!!RN_GPS.roads');i++) await sleep(250);
  await sleep(300);
  await shot('gps_map');
  await clickDestination(); await sleep(400);
  evidence.route=await routeState();
  if(!evidence.route.valid || !evidence.route.sections.includes(78) || !evidence.route.sections.some(id=>id>=79) || evidence.route.count<2) throw new Error('cross-city route/host publication failed');
  await shot('gps_route');
  await press('KeyM','m');
  await key(true);
  before = await until(s => s.car?.speed > 2, 'car driving with route', 30000);
  await sleep(1800); before=await sample();
  await shot('gps_route_hud');
  evidence.hudBeforeTurn=before;
  await send('Input.dispatchKeyEvent',{type:'keyDown',code:'KeyD',key:'d'});
  await sleep(700);
  await send('Input.dispatchKeyEvent',{type:'keyUp',code:'KeyD',key:'d'});
  await sleep(400); evidence.hudAfterTurn=await sample();
  await shot('gps_route_hud_turn');
  await key(false);
  await press('KeyM','m'); await sleep(200);
  await evaluate("document.querySelector('.gps-clear').click()"); await sleep(300);
  evidence.clear=await routeState();
  if(evidence.clear.route!==null || evidence.clear.count!==0) throw new Error('clear did not remove route');
  await shot('gps_route_clear');
  await clickDestination(); await sleep(300);
  // A nearby verified NPC street is well off the selected route. Use the real teleport
  // helper to exercise rerouting, without modifying the pose or planner from the test.
  const oldRoute=await routeState(), offRoad=[2021.4556884765625,-550.87939453125,67.74585723876953];
  evidence.offRouteDistance=await evaluate(`(() => {
    const p=${JSON.stringify(offRoad)}, ids=RN_GPS.route.ids, nodes=RN_GPS.roads.nodes;
    let best=Infinity;
    for(let i=1;i<ids.length;i++) {
      const a=nodes[ids[i-1]], b=nodes[ids[i]], d=b.map((v,j)=>v-a[j]);
      const l=d.reduce((s,v)=>s+v*v,0), t=l?Math.max(0,Math.min(1,d.reduce((s,v,j)=>s+(p[j]-a[j])*v,0)/l)):0;
      best=Math.min(best,Math.hypot(...d.map((v,j)=>p[j]-a[j]-v*t)));
    } return best;
  })()`);
  if(!FINAL) {
  if(evidence.offRouteDistance<=40) throw new Error('reroute probe is not off the actual selected route');
  if(!await evaluate(`rnGpsTeleport(${offRoad.join(',')},27453)`)) throw new Error('off-route teleport not queued');
  await until(s=>s.req===0 && s.res!==0,'off-route teleport',30000);
  await sleep(800); evidence.recalculated=await routeState();
  if(!evidence.recalculated.valid || evidence.recalculated.start===oldRoute.start || evidence.recalculated.destination!==oldRoute.destination) throw new Error('off-route reroute failed');
  await shot('gps_route_recalculated');
  }
  await evaluate("document.querySelector('.gps-teleport').click()");
  after=await until(s=>s.res!==0 && s.req===0,'map teleport result',30000);
  if(after.res!==1) throw new Error('map teleport refused');
  await sleep(1500); after=await sample();
  evidence.arrival=await routeState();
  if(evidence.arrival.route!==null || evidence.arrival.count!==0 || !evidence.arrival.status.includes('Llegaste')) throw new Error('arrival did not clear route');
  await shot('gps_route_arrival');
  await press('KeyM','m'); await sleep(500);
  await shot('gps_teleport');
  await key(true); await sleep(3000); await key(false); await sleep(1500);
  later=await sample();
  await shot('gps_teleport_later');
  if(!later.car || !after.car || later.car.wheels===0 || Math.hypot(later.car.pos[0]-after.car.pos[0],later.car.pos[1]-after.car.pos[1])<2) throw new Error('did not drive on after map teleport');
  if (errors.length) throw new Error('browser exceptions');
  evidence.verified = true;
  console.log(`GPS ROUTE PASS: ${JSON.stringify(before.car)} -> ${JSON.stringify(after.car)} -> ${JSON.stringify(later.car)}`);
} catch (e) {
  evidence.failure = String(e);
  console.error(`GPS ROUTE FAIL: ${e}`);
  process.exitCode = 1;
} finally {
  writeFileSync('build/gps_route_check.log', pageLog);
  writeFileSync('build/gps_route_check.json', JSON.stringify({ ...evidence, before, after, later, errors, elapsed: (Date.now() - started) / 1000 }, null, 2) + '\n');
  // Let Chrome close its profile writers before removing the isolated profile.
  if (ws?.readyState === WebSocket.OPEN) ws.send(JSON.stringify({id:++id,method:'Browser.close'}));
  else chrome.kill('SIGKILL');
  await chromeClosed;
  ws?.close();
  rmSync(profile, { recursive: true, force: true });
  clearTimeout(deadline);
}
