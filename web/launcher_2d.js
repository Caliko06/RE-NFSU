// Pre-game launcher v4: a painted 2D street (web/launcher/v4, atlases painted by Codex image_gen) animated frame by frame.
// Defines window.RN_SCENE with the calls launcher.js makes: start(canvas,{base}) -> Promise, onIntroDone(cb), select(i,n,screen),
// screen(name), confirm() -> Promise, motion(on), pointer(x,y), screenPos(i) -> null.
// Every moving thing is an atlas Clip with a hand-keyed timeline: [frame, ms] pairs, each frame held for its own time
// (Aseprite's per-frame "duration"; the lag carry-over is PixiJS AnimatedSprite.update, see web/launcher/v4/atlas.js).
// World space = the plate's pixels (2400 x 1080). If any asset fails, start() rejects and the page shows the static plate.
import { loadAtlas, Clip, keys } from './launcher/v4/atlas.js';

const WW = 2400, WH = 1080;
// ---- hand-keyed timelines (ms per frame). Holds are long, stutters are short: that is what makes them read as real. ----
const T = {
  rain:     keys('0:42 1:42 2:42 3:42 4:42 5:42 6:42 7:42'),                    // 24 fps sheet, even
  rainNear: keys('0:33 1:33 2:33 3:33 4:33 5:33 6:33 7:33'),                    // near drops fall faster
  // a tired ballast: long on, a buzz, one tube drops out twice, a full dropout and a restart with a flash
  neon:     keys('0:2600 1:70 0:1800 2:50 0:40 2:60 0:3200 1:90 3:60 4:140 5:40 4:60 5:50 6:110 0:2400'),
  neonIn:   keys('4:260 5:40 4:90 5:30 4:50 6:120 0:60', ),                     // the intro start-up, once
  steam:    keys('0:90 1:90 2:95 3:95 4:100 5:100 6:105 7:110 8:110 9:115 10:115 11:120 12:120 13:125 14:130 15:140'),
  exhaust:  keys('0:55 1:60 2:65 3:75 4:85 5:100 6:120 7:150'),                  // fast birth, slow fade
  splash:   keys('0:28 1:30 2:42 3:55 4:65 5:80 6:95 7:220'),                    // impact snaps, ring eases out by hand
  sweep:    keys('0:40 1:40 2:45 3:50 4:55 5:65 6:85 7:130'),                    // a car passes right to left
  streak:   keys('0:30 1:30 2:35 3:40 4:45 5:55 6:70 7:400'),                    // menu highlight glint
  spark:    keys('0:30 1:35 2:45 3:60 4:70 5:80 6:90 7:110'),
};
// car idle: engine rumble as hand-placed pixel offsets (y) per 60 ms, and the headlight glow alpha per frame
const BOB = [0, 1, 1, 0, 0, 1, 0, -1, 0, 0, 1, 0];
const GLOW = [1, .96, 1, .93, 1, 1, .97, 1];
// intro: headlights snap on (alpha keys at ms), the camera settles from a push-in (scale keys)
const INTRO_GLOW = [[0, 0], [700, 0], [760, .8], [800, .2], [860, 1]];
const INTRO_ZOOM = [[0, 1.08], [300, 1.06], [700, 1.025], [1100, 1.008], [1500, 1]];
const INTRO_MS = 1500;

// layout in world px; tuned against the painted plates
const L = {
  car:   { x: 1150, y: 520, w: 940 },              // top-left + width; height from the image ratio
  neon:  { x: 1660, y: 330, w: 340, a: .95 },
  steam: [{ x: 1330, y: 300, w: 170, a: .4 }],
  exhaust: { x: 1970, y: 700, w: 230, a: .55 },
  sweep: { x: 500, y: 330, w: 1400, a: .8 },
  splashZone: { x0: 60, x1: 2340, y0: 640, y1: 1070 },
};
const DEPTH = { street: .6, car: .9, rain: 1.25 };   // parallax weight per layer (pointer)

let cv, cx, W = 0, H = 0, dpr = 1, raf = 0, motion = true, started = false, introDone = false, introCb = null;
let A = {}, I = {}, C = {}, t0 = 0, last = 0, introT = 0, going = null, sel = { i: 0, scr: 'main', t: 0 };
const ptr = { x: 0, y: 0, sx: 0, sy: 0 };
const splashes = [];
let nextSweep = 0, bobT = 0, glowT = 0;

const img = src => new Promise((res, rej) => { const i = new Image(); i.onload = () => i.decode().then(() => res(i), () => res(i)); i.onerror = () => rej(new Error(src)); i.src = src; });
const lerpKeys = (k, t) => { if (t <= k[0][0]) return k[0][1]; for (let j = 1; j < k.length; j++) if (t <= k[j][0]) { const [a, va] = k[j - 1], [b, vb] = k[j]; return va + (vb - va) * (t - a) / (b - a); } return k[k.length - 1][1]; };

function size() {
  dpr = Math.min(devicePixelRatio || 1, 2); W = innerWidth; H = innerHeight;
  cv.width = Math.round(W * dpr); cv.height = Math.round(H * dpr); if (!motion) draw(0);
}
// world -> screen: cover-fit with 8 % slack for parallax, focus at the car side
function view(depth, zoom) {
  const s = Math.max(W / (WW * .92), H / (WH * .92)) * zoom;
  const ox = (W - WW * s) * .58 - ptr.sx * depth * 28, oy = (H - WH * s) * .5 - ptr.sy * depth * 16;
  return [s, ox, oy];
}
function put(depth, zoom) { const [s, ox, oy] = view(depth, zoom); cx.setTransform(s * dpr, 0, 0, s * dpr, ox * dpr, oy * dpr); return s; }

function spawnSplash() {
  const z = L.splashZone, y = z.y0 + Math.random() * (z.y1 - z.y0), k = .5 + (y - z.y0) / (z.y1 - z.y0);
  const c = new Clip(A.splash, T.splash, { loop: false }); splashes.push({ c, x: z.x0 + Math.random() * (z.x1 - z.x0), y, w: 70 * k });
}

function draw(dt) {
  const zoom = introDone ? 1 : lerpKeys(INTRO_ZOOM, introT);
  cx.setTransform(1, 0, 0, 1, 0, 0); cx.fillStyle = '#05080d'; cx.fillRect(0, 0, cv.width, cv.height);
  put(DEPTH.street, zoom); cx.drawImage(I.street, 0, 0);
  (introDone ? C.neon : C.neonIn).draw(cx, L.neon.x, L.neon.y, L.neon.w, L.neon.w / 2, L.neon.a);
  for (const s of L.steam) C.steam.draw(cx, s.x, s.y, s.w, s.w * 1.5, s.a);
  for (const s of splashes) s.c.draw(cx, s.x - s.w / 2, s.y - s.w / 2, s.w, s.w, .8);
  // car: contact shadow, body with the idle rumble, its own light
  put(DEPTH.car, zoom);
  const ch = L.car.w * I.car.height / I.car.width, by = BOB[Math.floor(bobT / 60) % BOB.length];
  const g = cx.createRadialGradient(L.car.x + L.car.w * .5, L.car.y + ch * .93, 10, L.car.x + L.car.w * .5, L.car.y + ch * .93, L.car.w * .55);
  g.addColorStop(0, 'rgba(0,0,0,.75)'); g.addColorStop(1, 'rgba(0,0,0,0)');
  cx.save(); cx.translate(0, L.car.y + ch * .93); cx.scale(1, .16); cx.fillStyle = g; cx.fillRect(L.car.x - 100, -L.car.w * 3, L.car.w + 200, L.car.w * 6); cx.restore();
  cx.drawImage(I.car, L.car.x, L.car.y + by, L.car.w, ch);
  const ga = (introDone ? 1 : lerpKeys(INTRO_GLOW, introT)) * GLOW[Math.floor(glowT / 70) % GLOW.length];
  if (I.glow) { cx.save(); cx.globalCompositeOperation = 'screen'; cx.globalAlpha = ga; cx.drawImage(I.glow, L.car.x, L.car.y + by, L.car.w, ch); cx.restore(); }
  C.exhaust.draw(cx, L.exhaust.x, L.exhaust.y + by, L.exhaust.w, L.exhaust.w, L.exhaust.a);
  put(DEPTH.street, zoom);
  if (C.sweep.on) C.sweep.draw(cx, L.sweep.x, L.sweep.y, L.sweep.w, L.sweep.w / 2, L.sweep.a);
  // rain: tiled sheets in screen space, far layer then near
  cx.setTransform(dpr, 0, 0, dpr, 0, 0);
  const tile = (c, sz, a, depth) => { const px = -ptr.sx * depth * 20; for (let y = 0; y < H; y += sz) for (let x = -sz + (px % sz); x < W; x += sz) c.draw(cx, x, y, sz, sz, a); };
  tile(C.rain, 512, .55, DEPTH.rain); tile(C.rainNear, 768, .35, DEPTH.rain * 1.6);
  // menu glint behind the selected DOM item (main screen only)
  if (sel.scr === 'main' && C.streak.on) {
    const it = document.querySelectorAll('#menu .item')[sel.i];
    if (it) { const r = it.getBoundingClientRect(); C.streak.draw(cx, r.left - r.height * .4, r.top - r.height * .2, r.width + r.height * .8, r.height * 1.4, .9); }
  }
  if (going) { const r = going.el; C.spark.draw(cx, r.x - 90, r.y - 90, 180, 180, 1); }
}

function frame(now) {
  raf = requestAnimationFrame(frame);
  const dt = Math.min(100, now - (last || now)); last = now;
  if (document.hidden) return;
  if (!introDone) { introT += dt; if (introT >= INTRO_MS) { introDone = true; if (introCb) introCb(); } }
  bobT += dt; glowT += dt;
  for (const k of ['rain', 'rainNear', 'steam', 'exhaust']) C[k].update(dt);
  if (introDone) C.neon.update(dt); else C.neonIn.update(dt);
  if (C.sweep.on) { C.sweep.update(dt); if (C.sweep.done) C.sweep.on = false; }
  else if (now > nextSweep) { C.sweep.reset(); C.sweep.on = true; nextSweep = now + 7000 + Math.random() * 7000; }
  if (C.streak.on) { C.streak.update(dt); if (C.streak.done) C.streak.on = false; }
  if (going) C.spark.update(dt);
  if (Math.random() < dt / 90) spawnSplash();
  for (let j = splashes.length - 1; j >= 0; j--) { splashes[j].c.update(dt); if (splashes[j].c.done) splashes.splice(j, 1); }
  ptr.sx += (ptr.x - ptr.sx) * Math.min(1, dt / 220); ptr.sy += (ptr.y - ptr.sy) * Math.min(1, dt / 220);
  draw(dt);
}

const API = {
  async start(canvas, { base = 'launcher/v4/' } = {}) {
    cv = canvas; cx = cv.getContext('2d', { alpha: false });
    const [street, car, glow] = await Promise.all(['bg_street.webp', 'car.webp', 'car_glow.webp'].map(n => img(base + n)));
    I = { street, car, glow };
    const names = ['rain', 'rain_near', 'neon', 'steam', 'exhaust', 'splash', 'sweep', 'streak', 'spark'];
    const at = await Promise.all(names.map(n => loadAtlas(base, n)));
    names.forEach((n, j) => { A[n] = at[j]; });
    const mk = (a, t, o) => new Clip(A[a], T[t], o);
    C = { rain: mk('rain', 'rain'), rainNear: mk('rain_near', 'rainNear'), neon: mk('neon', 'neon'), neonIn: mk('neon', 'neonIn', { loop: false }),
      steam: mk('steam', 'steam'), exhaust: mk('exhaust', 'exhaust'), sweep: mk('sweep', 'sweep', { loop: false }),
      streak: mk('streak', 'streak', { loop: false }), spark: mk('spark', 'spark', { loop: false }) };
    nextSweep = performance.now() + 2600;
    size(); addEventListener('resize', size);
    started = true; raf = requestAnimationFrame(frame);
  },
  onIntroDone(cb) { if (introDone) cb(); else introCb = cb; },
  select(i, n, scr) { if (scr && scr !== 'main') return; if (i !== sel.i && C.streak) { C.streak.reset(); C.streak.on = motion; } sel.i = i; },
  screen(name) { sel.scr = name || 'main'; },
  motion(on) {
    motion = !!on; if (!started) return;
    if (motion && !raf) { last = 0; raf = requestAnimationFrame(frame); }
    if (!motion) { cancelAnimationFrame(raf); raf = 0; introDone = true; if (introCb) { introCb(); introCb = null; } draw(0); }
  },
  pointer(x, y) { ptr.x = x; ptr.y = y; if (!motion) { ptr.sx = x; ptr.sy = y; } },
  screenPos() { return null; },
  confirm() {
    if (going) return Promise.resolve();
    const it = document.querySelectorAll('#menu .item')[sel.i], r = it ? it.getBoundingClientRect() : { left: W / 2, top: H / 2, height: 0 };
    going = { el: { x: r.left + 24, y: r.top + r.height / 2 } }; C.spark.reset(); C.sweep.reset(); C.sweep.on = true;
    return new Promise(res => setTimeout(res, 520));
  },
  resume() { going = null; },
};
window.RN_SCENE = API;
