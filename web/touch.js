// Touch overlay (iPad / iPhone: 'ontouchstart' in window; ?touch=1 forces it, ?touch=0 hides it) -> the keyboard path of
// web/input.js: every control presses DIK keys through startInput's setKey (same ring and held set as the keyboard and web/pad.js).
// Keys are the game's default action table (exe 0x702c98, docs/re/hud_input.md): arrows steer / gas / brake,
// Left Shift handbrake, Space nitrous, C camera, R respot, Esc pause; menus: arrows, Enter select, Esc back.
// It steps aside when a real keyboard key or a gamepad is used, and comes back on the next touch.
// Two layouts. drive: two steer pads (bottom left), gas / brake / nitro / handbrake (bottom right), camera / respot (top right). menu: d-pad, OK, BACK.
// Both: pause, full screen and the MENÚ/MANEJAR switch (top left). The game's mouse cursor is parked off screen.
// The page cannot read the race state, so the layout follows pad.js's heuristic (inputNextMode): drive after the gas is
// touched, menu on pause / d-pad / BACK or after 10 s with nothing held; the MENU/DRIVE button switches by hand.
'use strict';
const TOUCH_DIK = { ...PAD_DIK, camera: 0x2e, respot: 0x13 };
const TOUCH_IDLE_MS = 10000, TOUCH_MIN_HOLD_MS = 60, TOUCH_STEER_DEAD = 0.08;

function startTouch(input) {
  const want = RN_Q.get('touch');
  if (!input || want === '0' || !(want === '1' || 'ontouchstart' in window)) return null;
  const D = TOUCH_DIK;
  const css = document.createElement('style');
  // Sizes follow the phone's height (a landscape phone is 320-430 px tall): --u is one thumb button. Every edge adds the
  // safe area (notch, rounded corners, home bar): children are absolute, so a padding on #touch would not move them.
  css.textContent = `
    :root { --t-l: max(14px, env(safe-area-inset-left)); --t-r: max(14px, env(safe-area-inset-right));
      --t-t: max(10px, env(safe-area-inset-top)); --t-b: max(12px, env(safe-area-inset-bottom));
      --t-u: clamp(58px, 20vh, 104px); --t-g: clamp(8px, 2.8vh, 16px); --t-s: 44px; }
    #touch { position: fixed; inset: 0; z-index: 8; pointer-events: none; touch-action: none; user-select: none; -webkit-user-select: none;
      -webkit-touch-callout: none; -webkit-tap-highlight-color: transparent; color: #fff; cursor: default;
      font: 800 13px/1 "Avenir Next Condensed", "Roboto Condensed", "Arial Narrow", system-ui, sans-serif; letter-spacing: .1em; }
    #touch .g { display: none; position: absolute; inset: 0; }
    #touch.drive .g.drive, #touch.menu .g.menu { display: block; }
    #touch .b { position: absolute; box-sizing: border-box; pointer-events: auto; touch-action: none; display: flex; align-items: center; justify-content: center;
      border-radius: 20px; text-shadow: 0 1px 3px rgba(0,0,0,.8); background: linear-gradient(160deg, rgba(40,46,66,.55), rgba(8,10,18,.55));
      border: 1.5px solid rgba(255,255,255,.22); box-shadow: inset 0 1px 0 rgba(255,255,255,.18), 0 6px 18px rgba(0,0,0,.35);
      transition: transform .12s ease-out, filter .12s ease-out, background-color .12s; }
    #touch .b.on { transform: scale(.94); filter: brightness(1.5) saturate(1.2); border-color: rgba(255,255,255,.7); }
    #touch .b svg { width: 46%; height: 46%; fill: none; stroke: currentColor; stroke-width: 2.4; stroke-linecap: round; stroke-linejoin: round; filter: drop-shadow(0 1px 2px rgba(0,0,0,.7)); }
    #touch .round { border-radius: 50%; }
    /* top bar: small round icon buttons, left = pause, full screen, layout; right = camera, reset (+ the options button of web/overlay.js) */
    #touch .top { top: var(--t-t); width: var(--t-s); height: var(--t-s); border-radius: 50%; }
    #touch .pause { left: var(--t-l); }
    #touch .fs { left: calc(var(--t-l) + var(--t-s) + 10px); }
    #touch .mode { top: var(--t-t); left: calc(var(--t-l) + 2 * var(--t-s) + 20px); height: var(--t-s); padding: 0 16px; border-radius: 999px; font-size: 12px; gap: 6px; }
    #touch.fsok .fs { display: none; }
    #touch.fsok .mode { left: calc(var(--t-l) + var(--t-s) + 10px); }
    #touch .resp { right: calc(var(--t-r) + var(--t-s) + 10px); }
    #touch .cam { right: calc(var(--t-r) + 2 * var(--t-s) + 20px); }
    #ov-btn { top: var(--t-t) !important; right: var(--t-r) !important; width: var(--t-s) !important; height: var(--t-s) !important; opacity: .8 !important; font-size: 20px !important; }
    #ov { top: calc(var(--t-t) + var(--t-s) + 8px) !important; right: var(--t-r) !important; }
    /* drive: steering pads bottom-left; pedals bottom-right (gas tall on the outside, brake inside, nitro and handbrake above) */
    #touch .steer { left: var(--t-l); bottom: var(--t-b); width: calc(var(--t-u) * 2.7 + var(--t-g)); height: calc(var(--t-u) * 1.3);
      background: none; border: 0; box-shadow: none; border-radius: 0; gap: var(--t-g); transition: none; }
    #touch .steer.on { transform: none; filter: none; }
    #touch .steer i { flex: 1; align-self: stretch; display: flex; align-items: center; justify-content: center; border-radius: 22px;
      background: linear-gradient(160deg, rgba(40,46,66,.55), rgba(8,10,18,.55)); border: 1.5px solid rgba(255,255,255,.22);
      box-shadow: inset 0 1px 0 rgba(255,255,255,.18), 0 6px 18px rgba(0,0,0,.35); transition: transform .12s ease-out, background .12s; }
    #touch .steer i.on { transform: scale(.95); background: linear-gradient(160deg, rgba(255,176,64,.85), rgba(214,72,20,.75)); border-color: #ffd28a; }
    #touch .steer svg { width: 40%; height: 40%; }
    #touch .gas { right: var(--t-r); bottom: var(--t-b); width: calc(var(--t-u) * 1.1); height: calc(var(--t-u) * 1.85); border-radius: 22px;
      background: linear-gradient(170deg, rgba(64,236,150,.7), rgba(8,128,84,.65)); }
    #touch .brake { right: calc(var(--t-r) + var(--t-u) * 1.1 + var(--t-g)); bottom: var(--t-b); width: calc(var(--t-u) * 1.1); height: calc(var(--t-u) * 1.1);
      background: linear-gradient(170deg, rgba(255,92,112,.7), rgba(160,14,48,.65)); }
    #touch .nitro { right: calc(var(--t-r) + var(--t-u) * 1.1 + var(--t-g)); bottom: calc(var(--t-b) + var(--t-u) * 1.1 + var(--t-g));
      width: calc(var(--t-u) * 1.1); height: calc(var(--t-u) * .72); border-radius: 999px; background: linear-gradient(170deg, rgba(96,200,255,.75), rgba(60,70,255,.65)); }
    #touch .hand { right: var(--t-r); bottom: calc(var(--t-b) + var(--t-u) * 1.85 + var(--t-g)); width: calc(var(--t-u) * 1.1); height: calc(var(--t-u) * .72);
      border-radius: 999px; color: #ffd28a; }
    /* menu: a d-pad bottom-left, OK and BACK bottom-right like a pad's A / B */
    #touch .dpad { position: absolute; left: var(--t-l); bottom: var(--t-b); width: calc(var(--t-u) * 2.5); height: calc(var(--t-u) * 2.5);
      display: grid; grid-template: repeat(3, 1fr) / repeat(3, 1fr); gap: 4px; }
    #touch .dpad .b { position: static; border-radius: 16px; }
    #touch .dpad .up { grid-area: 1 / 2; } #touch .dpad .left { grid-area: 2 / 1; } #touch .dpad .right { grid-area: 2 / 3; } #touch .dpad .down { grid-area: 3 / 2; }
    #touch .ok { right: var(--t-r); bottom: calc(var(--t-b) + var(--t-u) * .55); width: calc(var(--t-u) * 1.25); height: calc(var(--t-u) * 1.25); font-size: 18px;
      background: linear-gradient(170deg, rgba(64,236,150,.7), rgba(8,128,84,.65)); }
    #touch .back { right: calc(var(--t-r) + var(--t-u) * 1.25 + var(--t-g)); bottom: var(--t-b); width: var(--t-u); height: var(--t-u); font-size: 12px;
      background: linear-gradient(170deg, rgba(255,92,112,.7), rgba(160,14,48,.65)); }
    #touch .tip { position: absolute; left: 50%; top: calc(var(--t-t) + var(--t-s) + 12px); transform: translateX(-50%); max-width: min(80vw, 420px);
      padding: 10px 16px; border-radius: 14px; background: rgba(8,10,18,.88); border: 1px solid rgba(255,255,255,.2); text-align: center;
      font: 600 14px/1.4 system-ui, sans-serif; letter-spacing: 0; display: none; }
    #touch .tip.on { display: block; }
    @media (prefers-reduced-motion: reduce) { #touch .b, #touch .steer i { transition: none; } }`;
  document.head.appendChild(css);

  const svg = d => `<svg viewBox="0 0 24 24" aria-hidden="true">${d}</svg>`;
  const I = {
    left: svg('<path d="M15 5l-7 7 7 7"/>'), right: svg('<path d="M9 5l7 7-7 7"/>'),
    up: svg('<path d="M5 15l7-7 7 7"/>'), down: svg('<path d="M5 9l7 7 7-7"/>'),
    pause: svg('<path d="M9 6v12M15 6v12"/>'), fs: svg('<path d="M4 9V4h5M20 9V4h-5M4 15v5h5M20 15v5h-5"/>'),
    cam: svg('<path d="M4 8h3l2-2h6l2 2h3v11H4z"/><circle cx="12" cy="13" r="3.2"/>'),
    resp: svg('<path d="M4 12a8 8 0 1 0 2.4-5.7"/><path d="M4 4v4h4"/>'),
  };
  const btn = (cls, label, k, title = '') => `<div class="b ${cls}" data-k="${k}"${title ? ` aria-label="${title}"` : ''}>${label}</div>`;
  const root = document.createElement('div');
  root.id = 'touch';
  root.innerHTML = `<div class="g drive">
      <div class="b steer" data-steer="1"><i>${I.left}</i><i>${I.right}</i></div>
      ${btn('gas', 'GAS', 'up')}${btn('brake', 'FRENO', 'down')}${btn('nitro', 'NITRO', 'space')}${btn('hand', 'MANO', 'lshift')}
      ${btn('top cam', I.cam, 'camera', 'Cámara')}${btn('top resp', I.resp, 'respot', 'Reiniciar auto')}
    </div><div class="g menu">
      <div class="dpad">${btn('up', I.up, 'up')}${btn('left', I.left, 'left')}${btn('right', I.right, 'right')}${btn('down', I.down, 'down')}</div>
      ${btn('ok round', 'OK', 'enter')}${btn('back round', 'ATRÁS', 'esc')}
    </div>${btn('top pause', I.pause, 'esc', 'Pausa')}<div class="b top fs" data-fs="1" aria-label="Pantalla completa">${I.fs}</div>
    <div class="b mode" data-mode="1"></div><div class="tip"></div>`;
  document.body.appendChild(root);

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
    else say('En iPhone: toca Compartir y luego "Agregar a inicio". Ábrelo desde ese ícono y el juego llena la pantalla.');
  };

  // Held keys by DIK, counted over pointers (two thumbs on one key); a release waits out a minimum hold, so a quick tap
  // reaches the game's poll as a press and not as a down-up in one frame.
  const count = new Map(), downAt = new Map(), ptr = new Map();
  const st = { mode: 'menu', last: undefined };
  const layout = m => { st.mode = m; root.className = m; root.querySelector('.mode').textContent = m === 'drive' ? 'MENÚ' : 'MANEJAR'; };
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
  const sync = () => {
    const ps = [...ptr.values()];
    layout(inputNextMode(st, performance.now(), { drive: ps.some(p => p.gas), menu: ps.some(p => p.nav), active: ps.length > 0 }, TOUCH_IDLE_MS));
  };
  const setKeys = (id, keys) => {
    const p = ptr.get(id);
    for (const d of p.keys) if (!keys.has(d)) release(d);
    for (const d of keys) if (!p.keys.has(d)) press(d);
    p.keys = keys;
  };
  const steerKeys = (e, el) => {
    const r = el.getBoundingClientRect(), x = (e.clientX - r.left) / r.width - 0.5, k = new Set();
    if (x < -TOUCH_STEER_DEAD) k.add(D.left); else if (x > TOUCH_STEER_DEAD) k.add(D.right);
    const [l, rt] = el.children;
    l.classList.toggle('on', k.has(D.left)); rt.classList.toggle('on', k.has(D.right));
    return k;
  };
  const stop = e => {
    const p = ptr.get(e.pointerId);
    if (!p) return;
    p.el.classList.remove('on');
    if (p.el.dataset.steer) for (const c of p.el.children) c.classList.remove('on');
    setKeys(e.pointerId, new Set());
    ptr.delete(e.pointerId);
    sync();
  };
  root.addEventListener('pointerdown', e => {
    const el = e.target.closest('.b');
    if (!el) return;
    e.preventDefault();
    if (el.dataset.mode) { layout(st.mode === 'drive' ? 'menu' : 'drive'); st.last = performance.now(); return; }
    if (el.dataset.fs) { goFull(); return; }
    el.setPointerCapture?.(e.pointerId);
    const names = (el.dataset.k || '').split(',').filter(Boolean);
    const p = { el, keys: new Set(), gas: el.dataset.k === 'up' && st.mode === 'drive', nav: st.mode === 'menu' || el.dataset.k === 'esc' };
    ptr.set(e.pointerId, p);
    el.classList.add('on');
    setKeys(e.pointerId, el.dataset.steer ? steerKeys(e, el) : new Set(names.map(n => D[n])));
    sync();
  });
  root.addEventListener('pointermove', e => {
    const p = ptr.get(e.pointerId);
    if (p && p.el.dataset.steer) setKeys(e.pointerId, steerKeys(e, p.el));
  });
  for (const t of ['pointerup', 'pointercancel', 'lostpointercapture']) root.addEventListener(t, stop);
  const releaseAll = () => { for (const id of [...ptr.keys()]) stop({ pointerId: id }); };
  // A keyboard key or a pad means a real controller is in hand: the overlay hides (releasing what it held) and returns on the next touch.
  const hide = () => { if (root.style.display !== 'none') { releaseAll(); root.style.display = 'none'; } };
  const show = () => { if (root.style.display === 'none') { root.style.display = ''; sync(); } };
  const padUsed = () => {
    if (!navigator.getGamepads) return false;
    const p = [...navigator.getGamepads()].find(g => g && g.connected);
    return !!p && (p.buttons.some(b => b && b.pressed) || Math.abs(p.axes[0] || 0) > 0.4 || Math.abs(p.axes[1] || 0) > 0.4);
  };
  addEventListener('keydown', hide, true);
  addEventListener('pointerdown', e => { if (e.pointerType === 'touch') show(); }, true);
  addEventListener('touchstart', show, { capture: true, passive: true });   // iOS: the first touch after the keyboard
  addEventListener('blur', releaseAll);
  document.addEventListener('visibilitychange', () => { if (document.hidden) releaseAll(); });
  for (const t of ['gesturestart', 'gesturechange', 'dblclick', 'contextmenu']) document.addEventListener(t, e => e.preventDefault());   // Safari pinch / double-tap zoom, long-press menu
  // The game's arrow cursor has no use on a touch screen: keep it parked off screen while the overlay is up (web/input.js park).
  setInterval(() => { if (padUsed()) hide(); if (!ptr.size) sync(); if (root.style.display !== 'none') input.park?.(); }, 500);   // idle: back to the menu layout; a pad takes over
  layout('menu');
  return { layout };
}
