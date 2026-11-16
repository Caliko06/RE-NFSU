// Touch overlay (iPad / iPhone: 'ontouchstart' in window; ?touch=1 forces it, ?touch=0 hides it) -> the keyboard path of
// web/input.js (DIK keys through startInput's setKey, same ring and held set as the keyboard and web/pad.js). The game's arrow
// cursor stays parked off screen (OWNER 2026-11-15: no PC cursor on a phone); only a tap on a menu option borrows it for that tap.
// Keys are the game's default action table (exe 0x702c98, docs/re/hud_input.md): arrows steer / gas / brake, Left Shift handbrake,
// Space nitrous, A / Z shift up / down, C camera, R reset car, Esc pause; menus: arrows, Enter select, Esc back.
// It steps aside when a real keyboard key or a gamepad is used, and comes back on the next touch.
// Layouts, chosen by the game itself: web/boot.js passes each "flow fe" line (host/d3d9.c flow_log: the front-end
// packages on screen) as window.RN_FE + an 'rn-fe' event, and "flow manual" as window.RN_MANUAL.
//   drive: only HUD_*.fng / drag_HUD*.fng / Chyron*.fng are up. Left thumb: two arrows (the whole left half steers, by the side of
//          their middle the thumb is on). Right thumb: GAS and BRAKE above the game's tachometer, NITROUS beside it (it holds the
//          gas too: one thumb cannot hold both). HANDBRAKE only in a drift race, SHIFT - / + only in a drag race or with the manual
//          gearbox. Top centre: camera, pause, reset car. (OWNER 2026-11-15: no automatic gas; essential buttons; the tachometer stays in its corner.)
//   menu : any other package (menus, MU_Pause*, post race). Left, up, down in the left margin; right, BACK, OK in the right one (the menus keep the centred 4:3 column). BACK is Esc + Backspace
//          (web/pad.js PAD_DIK.back). A tap on the menu itself picks the option under the finger (web/input.js tapAt); a
//          sideways slide anywhere else is left / right (car and option pickers). With no package up (intro movies) a touch is Enter.
//   wait : PC_Loading.fng. Nothing but the top bar.
// One composition with the game's own HUD (OWNER 2026-11-15, plan.json rejected: the two were placed by separate rules): every
// place and size is in the HUD's own unit, --t-h = 1/480 of the picture's height, from the side the HUD starts at (--t-i). fit()
// lays the overlay on the picture the canvas really draws and measures the notch live; the host gets the same inset (input.inset). Measured on HUD_SingleRace at the edges: lap box y < 110, minimap x 24..149 y 171..306, standings
// x 437..611 y < 197, tachometer x 413..611 y 330..470 (so 29..227 from the right side).
// Look: every control is the same thin white circle at --t-o with its word (the game's own action names, in English: OWNER);
// a pressed one takes the race HUD's blue (144 184 248) with a halo that shows around the thumb. No icons that need learning.
'use strict';
const TOUCH_MIN_HOLD_MS = 60, TOUCH_STEER_DEAD_PX = 6, TOUCH_SWIPE_PX = 44;
const touchLayout = fe => fe.some(p => p.startsWith('PC_Loading')) ? 'wait' : fe.length && fe.every(p => /^(HUD_|drag_HUD|Chyron)/.test(p)) ? 'drive' : 'menu';
const touchRace = fe => fe.some(p => p.startsWith('drag_HUD')) ? 'drag' : fe.some(p => p.startsWith('HUD_Drift')) ? 'drift' : '';

function startTouch(input) {
  const want = RN_Q.get('touch');
  if (!input || want === '0' || !(want === '1' || 'ontouchstart' in window)) return null;
  const D = PAD_DIK;
  // The player's choice (options panel, web/overlay.js): o = resting opacity in %. ?to= sets it for one visit.
  const S = { o: 35 };
  try { const v = JSON.parse(localStorage.getItem('rn-touch') || '{}'); if (v.o) S.o = v.o; } catch {}
  if (+RN_Q.get('to')) S.o = +RN_Q.get('to');
  const css = document.createElement('style');
  css.textContent = `
    :root { --t-h: 1px; --t-i: 0px; --t-t: max(10px, env(safe-area-inset-top)); --t-o: .35; --t-s: 44px; --t-c: 144,184,248; }
    #touch { position: fixed; z-index: 8; pointer-events: none; touch-action: none; user-select: none; -webkit-user-select: none;
      -webkit-touch-callout: none; -webkit-tap-highlight-color: transparent; color: rgba(255,255,255,calc(var(--t-o) + .3)); cursor: default;
      font: 700 max(10px, calc(var(--t-h) * 14))/1.15 system-ui, sans-serif; letter-spacing: .07em; text-align: center; }
    #touch .g { position: absolute; inset: 0; opacity: 0; visibility: hidden; transition: opacity .16s ease-out, visibility 0s .16s; }
    #touch[data-m=drive] .g.drive, #touch[data-m=menu] .g.menu { opacity: 1; visibility: visible; transition: opacity .16s ease-out; }
    #touch .z, #touch .sw { position: absolute; pointer-events: auto; touch-action: none; }
    #touch .z { top: 22%; bottom: 0; left: 0; width: 50%; } #touch .sw { inset: 0; }
    /* a dark hairline on both sides of the white line keeps it readable over a bright street */
    #touch .b, #ov-btn { position: absolute; box-sizing: border-box; pointer-events: auto; touch-action: none; display: flex; align-items: center; justify-content: center;
      width: calc(var(--t-h) * var(--d)); height: calc(var(--t-h) * var(--d)); top: calc(var(--t-h) * var(--y)); text-shadow: 0 0 3px rgba(0,0,0,.7);
      border-radius: 50%; border: 1.5px solid rgba(255,255,255,var(--t-o)); background: none; box-shadow: 0 0 0 1px rgba(0,0,0,.16), inset 0 0 0 1px rgba(0,0,0,.16);
      transition: transform .12s cubic-bezier(.22,1,.36,1), border-color .1s ease-out, box-shadow .1s ease-out, color .1s ease-out, background-color .1s ease-out; }
    #touch .b.on { transform: scale(.97); color: rgb(var(--t-c)); border-color: rgb(var(--t-c)); background-color: rgba(var(--t-c),.14);
      box-shadow: 0 0 0 5px rgba(var(--t-c),.16), 0 0 26px 6px rgba(var(--t-c),.55); }
    #touch .b svg, #ov-btn svg { width: 42%; height: 42%; fill: none; stroke: currentColor; stroke-width: 2; stroke-linecap: round; stroke-linejoin: round; filter: drop-shadow(0 0 1.5px rgba(0,0,0,.6)); pointer-events: none; }
    #touch .b::after { content: ''; position: absolute; inset: -7px; border-radius: 50%; }   /* the thumb's margin around the line */
    #touch .lf { left: calc(var(--t-i) + var(--t-h) * var(--x)); } #touch .rt { right: calc(var(--t-i) + var(--t-h) * var(--x)); }
    /* drive, left: the arrows under the minimap; shift beside it. right: gas and brake between the standings and the tachometer, nitrous left of it */
    #touch .mk { pointer-events: none; --d: 116; --y: 340; } #touch .mk.l { --x: 14; } #touch .mk.r { --x: 142; }
    #touch .gdn, #touch .gup { --d: 92; --y: 236; display: none; } #touch .gdn { --x: 164; } #touch .gup { --x: 266; }
    #touch[data-g="1"] .gdn, #touch[data-g="1"] .gup { display: flex; }
    #touch .gas { --d: 112; --y: 210; --x: 14; } #touch .brake { --d: 96; --y: 224; --x: 136; }
    #touch .nitro { --d: 96; --y: 356; --x: 240; }
    #touch .hand { --d: 96; --y: 236; --x: 242; display: none; } #touch[data-r=drift] .hand { display: flex; }
    /* menu: the game's menus sit in the centred 4:3 column, so the buttons keep to the margins: up over down left, BACK over OK right */
    #touch .nav { --d: 92; --x: 14; } #touch .nav.up { --y: 262; } #touch .nav.dn { --y: 364; } #touch .nav.lt, #touch .nav.rg { --y: 160; }
    #touch .ok { --d: 92; --y: 364; --x: 14; } #touch .back { --d: 92; --y: 262; --x: 14; }
    /* small circles on top. drive: pause, centre. menus: full screen left, options (web/overlay.js) right */
    #touch .top { top: var(--t-t); width: var(--t-s); height: var(--t-s); }
    /* camera and reset car flank the pause (OWNER 2026-11-15: both back, as word buttons) */
    #touch .cam, #touch .resp { --d: 72; top: var(--t-t); font-size: max(9px, calc(var(--t-h) * 12)); }
    #touch .cam { left: calc(50% - var(--t-s) / 2 - 14px - var(--t-h) * 72); } #touch .resp { left: calc(50% + var(--t-s) / 2 + 14px); }
    #touch .pause { left: calc(50% - var(--t-s) / 2); } #touch .fs { left: max(16px, var(--t-i)); }
    #touch[data-m=drive] .fs, #touch.fsok .fs, body[data-touch=drive] #ov-btn { display: none !important; }
    #ov-btn { position: fixed !important; top: var(--t-t) !important; right: max(16px, var(--t-i)) !important; width: var(--t-s) !important; height: var(--t-s) !important; opacity: 1 !important;
      color: rgba(255,255,255,calc(var(--t-o) + .25)) !important; background: none !important; border: 1.5px solid rgba(255,255,255,var(--t-o)) !important; }
    #ov-btn.on { color: rgb(var(--t-c)) !important; border-color: rgb(var(--t-c)) !important; }
    #ov { top: calc(var(--t-t) + var(--t-s) + 8px) !important; right: max(16px, var(--t-i)) !important; max-height: calc(100dvh - var(--t-t) - var(--t-s) - 20px); overflow: auto; }
    #touch .tip { position: absolute; left: 50%; top: calc(var(--t-t) + var(--t-s) + 12px); transform: translateX(-50%); max-width: min(80vw, 420px);
      padding: 10px 16px; border-radius: 14px; background: rgba(8,10,18,.88); border: 1px solid rgba(255,255,255,.2); text-align: center; color: #fff;
      font: 600 14px/1.4 system-ui, sans-serif; letter-spacing: 0; display: none; }
    #touch .tip.on { display: block; }
    @media (prefers-reduced-motion: reduce) { #touch .b, #touch .g, #touch[data-m] .g { transition: none; } }`;
  document.head.appendChild(css);

  const svg = d => `<svg viewBox="0 0 24 24" aria-hidden="true">${d}</svg>`;
  const I = {
    left: svg('<path d="M15 5l-7 7 7 7"/>'), right: svg('<path d="M9 5l7 7-7 7"/>'), up: svg('<path d="M5 15l7-7 7 7"/>'), down: svg('<path d="M5 9l7 7 7-7"/>'),
    pause: svg('<path d="M9 6v12M15 6v12"/>'), fs: svg('<path d="M4 9V4h5M20 9V4h-5M4 15v5h5M20 15v5h-5"/>'),
  };
  const btn = (cls, label, k, title) => `<div class="b ${cls}" data-k="${k}" role="button" aria-label="${title}">${label}</div>`;
  const root = document.createElement('div');
  root.id = 'touch';
  root.innerHTML = `<div class="g drive">
      <div class="z"></div>
      <div class="b lf mk l">${I.left}</div><div class="b lf mk r">${I.right}</div>
      ${btn('lf gdn', '<span>SHIFT<br>−</span>', 'gdn', 'Shift down')}${btn('lf gup', '<span>SHIFT<br>+</span>', 'gup', 'Shift up')}
      ${btn('rt gas', 'GAS', 'up', 'Gas')}${btn('rt brake', 'BRAKE', 'down', 'Brake')}${btn('rt nitro', 'NITROUS', 'space,up', 'Nitrous')}${btn('rt hand', '<span>HAND<br>BRAKE</span>', 'lshift', 'Handbrake')}
      ${btn('top pause', I.pause, 'esc', 'Pause')}${btn('cam', 'CAMERA', 'camera', 'Camera')}${btn('resp', 'RESET', 'respot', 'Reset car')}
    </div><div class="g menu">
      <div class="sw"></div>${btn('lf nav up', I.up, 'up', 'Up')}${btn('lf nav dn', I.down, 'down', 'Down')}${btn('lf nav lt', I.left, 'left', 'Left')}${btn('rt nav rg', I.right, 'right', 'Right')}${btn('rt ok', 'OK', 'enter', 'OK')}${btn('rt back', 'BACK', 'esc,back', 'Back')}
    </div><div class="b top fs" data-fs="1" role="button" aria-label="Pantalla completa">${I.fs}</div><div class="tip"></div>`;
  document.body.appendChild(root);
  // The picture: the canvas keeps the back buffer's aspect inside the window (object-fit: contain, web/index.html), and the game's HUD
  // is drawn in it. The overlay takes that rect; the inset is what the notch covers of it on either side (?hudin=<px> for a test).
  const screenEl = document.getElementById('screen'), probe = document.createElement('div');
  probe.style.cssText = 'position:fixed;visibility:hidden;pointer-events:none;padding:0 env(safe-area-inset-right) 0 env(safe-area-inset-left)';
  document.body.appendChild(probe);
  const fit = () => {
    const r = screenEl.getBoundingClientRect(), a = (screenEl.gameW || screenEl.width) / (screenEl.gameH || screenEl.height) || r.width / r.height;
    const w = Math.min(r.width, r.height * a), h = w / a, x = r.left + (r.width - w) / 2, y = r.top + (r.height - h) / 2;
    if (!(w > 0 && h > 0)) return;
    const c = getComputedStyle(probe);
    const px = RN_Q.has('hudin') ? +RN_Q.get('hudin') : Math.max(0, (parseFloat(c.paddingLeft) || 0) - x, (parseFloat(c.paddingRight) || 0) - (innerWidth - x - w));
    Object.assign(root.style, { left: `${x}px`, top: `${y}px`, width: `${w}px`, height: `${h}px` });
    const ds = document.documentElement.style; ds.setProperty('--t-h', `${h / 480}px`); ds.setProperty('--t-i', `${px}px`);   // on the document: web/overlay.js' button reads --t-i too
    input.inset(Math.round(1000 * px / w));
  };
  fit(); addEventListener('resize', fit);
  const mkL = root.querySelector('.mk.l'), mkR = root.querySelector('.mk.r');

  // Full screen: Android has the API (web/app.js asks on every touch too); an iPhone has none for a page, only a web app
  // added to the home screen runs without the browser bars (web/app.webmanifest), so the button says how.
  const standalone = () => matchMedia('(display-mode: fullscreen), (display-mode: standalone)').matches || navigator.standalone;
  const fsSync = () => root.classList.toggle('fsok', !!(document.fullscreenElement || standalone()));
  document.addEventListener('fullscreenchange', fsSync);
  fsSync();
  const tip = root.querySelector('.tip');
  let tipT = 0;
  const say = t => { tip.textContent = t; tip.classList.add('on'); clearTimeout(tipT); tipT = setTimeout(() => tip.classList.remove('on'), 5000); };
  const goFull = () => {
    if (document.documentElement.requestFullscreen) RN_APP.full();
    else say('iPhone no deja pantalla completa en el navegador. Toca Compartir (Safari: abajo; Chrome: arriba a la derecha) y "Agregar a inicio". Ábrelo desde ese ícono y llena la pantalla.');
  };

  // Held keys by DIK, counted over pointers (two thumbs on one key); a release waits out a minimum hold, so a quick tap
  // reaches the game's poll as a press and not as a down-up in one frame.
  const count = new Map(), downAt = new Map(), ptr = new Map();
  const press = d => {
    const n = (count.get(d) || 0) + 1;
    count.set(d, n);
    if (n === 1) { downAt.set(d, performance.now()); input.key(d, true); }
  };
  const release = d => {
    const n = (count.get(d) || 0) - 1;
    count.set(d, Math.max(0, n));
    if (n > 0) return;
    const wait = TOUCH_MIN_HOLD_MS - (performance.now() - (downAt.get(d) ?? 0));
    const up = () => { if (!count.get(d)) input.key(d, false); };
    wait > 0 ? setTimeout(up, wait) : up();
  };
  const swap = (old, keys) => { for (const d of old) if (!keys.has(d)) release(d); for (const d of keys) if (!old.has(d)) press(d); return keys; };
  const shown = () => root.style.display !== 'none';
  const driving = () => shown() && !document.hidden && root.dataset.m === 'drive';

  // The left half of the drive screen steers: zl = the thumb on it ({ id, x }), left or right of the middle between the two arrows.
  let zl = null, zKeys = new Set();
  const zoneSync = () => {
    const k = new Set();
    if (driving() && zl) {
      const x = zl.x - (mkL.getBoundingClientRect().right + mkR.getBoundingClientRect().left) / 2;
      if (x < -TOUCH_STEER_DEAD_PX) k.add(D.left);
      if (x > TOUCH_STEER_DEAD_PX) k.add(D.right);
    }
    zKeys = swap(zKeys, k);
    mkL.classList.toggle('on', k.has(D.left)); mkR.classList.toggle('on', k.has(D.right));
  };

  // Menus: a sideways slide on the open screen is one left / right step per TOUCH_SWIPE_PX.
  let sw = null;
  const tapKey = d => { press(d); release(d); };

  const stop = e => {
    if (zl?.id === e.pointerId) { zl = null; zoneSync(); }
    if (sw?.id === e.pointerId) { if (sw.tap && e.type === 'pointerup') input.tapAt(sw.x, sw.y); sw = null; }   // a tap, not a slide: the option under the finger
    const p = ptr.get(e.pointerId);
    if (!p) return;
    p.el.classList.remove('on');
    swap(p.keys, new Set());
    ptr.delete(e.pointerId);
  };
  root.addEventListener('pointerdown', e => {
    const el = e.target.closest('.b, .z, .sw');
    if (!el) return;
    e.preventDefault();
    if (el.dataset.fs) { goFull(); return; }
    try { el.setPointerCapture(e.pointerId); } catch {}   // the pointer can be gone already (a very short tap): the keys still go down and up
    if (el.classList.contains('z')) { zl = { id: e.pointerId, x: e.clientX }; zoneSync(); return; }
    if (el.classList.contains('sw')) {
      if (!(window.RN_FE || []).length) tapKey(D.enter);   // intro movies: no package to move in
      else sw = { id: e.pointerId, x: e.clientX, y: e.clientY, tap: true };
      return;
    }
    if (el.classList.contains('pause')) releaseAll();   // a gas still held would reach the pause list as 'up' and move its choice (seen: Leave Race)
    navigator.vibrate?.(8);   // Android; an iPhone's Safari has no vibration
    el.classList.add('on');
    ptr.set(e.pointerId, { el, keys: swap(new Set(), new Set((el.dataset.k || '').split(',').filter(Boolean).map(n => D[n]))) });
  });
  root.addEventListener('pointermove', e => {
    if (zl?.id === e.pointerId) { zl.x = e.clientX; zoneSync(); }
    if (sw?.id === e.pointerId && Math.abs(e.clientX - sw.x) >= TOUCH_SWIPE_PX) { tapKey(e.clientX < sw.x ? D.left : D.right); sw.x = e.clientX; sw.tap = false; }
  });
  for (const t of ['pointerup', 'pointercancel', 'lostpointercapture']) root.addEventListener(t, stop);
  const releaseAll = () => { for (const id of [...ptr.keys(), zl?.id, sw?.id]) if (id !== undefined) stop({ pointerId: id }); zoneSync(); };
  // The layout follows the game's screens; what a thumb held on the old layout is released.
  const layout = () => {
    const fe = window.RN_FE || [], m = touchLayout(fe), r = touchRace(fe);
    root.dataset.r = r; root.dataset.g = r === 'drag' || window.RN_MANUAL ? 1 : 0;   // drift: handbrake; drag or manual gearbox: shift
    if (m === root.dataset.m) return;
    releaseAll(); root.dataset.m = document.body.dataset.touch = m; zoneSync();
  };
  addEventListener('rn-fe', layout);
  // The options panel (web/overlay.js) reads and changes the choices; they apply at once.
  const apply = () => {
    document.documentElement.style.setProperty('--t-o', S.o / 100);
    releaseAll();
  };
  window.RN_TOUCH = { get: () => ({ ...S }), set: o => { Object.assign(S, o); try { localStorage.setItem('rn-touch', JSON.stringify(S)); } catch {} apply(); } };
  apply();
  // A keyboard key or a pad means a real controller is in hand: the overlay hides (releasing what it held) and returns on the next touch.
  const hide = () => { if (shown()) { root.style.display = 'none'; releaseAll(); delete document.body.dataset.touch; } };
  const show = () => { if (!shown()) { root.style.display = ''; document.body.dataset.touch = root.dataset.m; zoneSync(); } };
  const padUsed = () => {
    if (!navigator.getGamepads) return false;
    const p = [...navigator.getGamepads()].find(g => g && g.connected);
    return !!p && (p.buttons.some(b => b && b.pressed) || Math.abs(p.axes[0] || 0) > 0.4 || Math.abs(p.axes[1] || 0) > 0.4);
  };
  addEventListener('keydown', hide, true);
  addEventListener('pointerdown', e => { if (e.pointerType === 'touch') show(); }, true);
  addEventListener('touchstart', show, { capture: true, passive: true });   // iOS: the first touch after the keyboard
  addEventListener('blur', releaseAll);
  document.addEventListener('visibilitychange', releaseAll);
  for (const t of ['gesturestart', 'gesturechange', 'dblclick', 'contextmenu']) document.addEventListener(t, e => e.preventDefault());   // Safari pinch / double-tap zoom, long-press menu
  // The game's arrow cursor has no use on a phone: keep it parked off screen (web/input.js park).
  setInterval(() => { if (padUsed()) hide(); if (shown()) input.park(); fit(); }, 500);   // a pad takes over
  layout();
}
