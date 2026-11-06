// Touch overlay (iPad / iPhone: 'ontouchstart' in window; ?touch=1 forces it, ?touch=0 hides it) -> the keyboard path of
// web/input.js: every control presses DIK keys through startInput's setKey (same ring and held set as the keyboard and web/pad.js).
// Keys are the game's default action table (exe 0x702c98, docs/re/hud_input.md): arrows steer / gas / brake,
// Left Shift handbrake, Space nitrous, C camera, R respot, Esc pause; menus: arrows, Enter select, Esc back.
// It steps aside when a real keyboard key or a gamepad is used, and comes back on the next touch.
// Two layouts. drive: steer zone (left), gas / brake / nitro / handbrake / camera / respot / pause (right). menu: d-pad, OK, BACK.
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
  css.textContent = `
    #touch { position: fixed; inset: 0; z-index: 8; pointer-events: none; touch-action: none; user-select: none; -webkit-user-select: none;
      -webkit-touch-callout: none; -webkit-tap-highlight-color: transparent; font: bold 15px system-ui, sans-serif; color: #fff;
      padding: env(safe-area-inset-top) env(safe-area-inset-right) env(safe-area-inset-bottom) env(safe-area-inset-left); box-sizing: border-box; }
    #touch .g { display: none; position: absolute; inset: 0; }
    #touch.drive .g.drive, #touch.menu .g.menu { display: block; }
    #touch .b { position: absolute; pointer-events: auto; touch-action: none; display: flex; align-items: center; justify-content: center;
      background: rgba(20,24,30,.42); border: 2px solid rgba(255,255,255,.35); border-radius: 18px; text-shadow: 0 1px 2px #000; }
    #touch .b.on { background: rgba(255,194,74,.6); border-color: #ffc24a; }
    #touch .round { border-radius: 50%; }
    #touch .steer { left: 0; top: 0; bottom: 0; width: 50vw; justify-content: space-between; padding: 0 4vmin; font-size: 8vmin;
      background: none; border: 0; border-radius: 0; }
    #touch .gas { right: 3vmin; bottom: 3vmin; width: 20vmin; height: 32vmin; background: rgba(63,185,80,.38); }
    #touch .brake { right: 26vmin; bottom: 3vmin; width: 18vmin; height: 18vmin; background: rgba(248,81,73,.38); }
    #touch .nitro { right: 26vmin; bottom: 24vmin; width: 18vmin; height: 18vmin; background: rgba(121,192,255,.38); }
    #touch .hand { right: 3vmin; bottom: 38vmin; width: 18vmin; height: 14vmin; }
    #touch .cam { right: 3vmin; top: 3vmin; width: 13vmin; height: 10vmin; font-size: 12px; }
    #touch .resp { right: 18vmin; top: 3vmin; width: 13vmin; height: 10vmin; font-size: 12px; }
    #touch .pause { left: 3vmin; top: 3vmin; width: 13vmin; height: 10vmin; font-size: 12px; }
    #touch .mode { left: 50%; top: 3vmin; transform: translateX(-50%); width: 18vmin; height: 8vmin; font-size: 12px; pointer-events: auto; }
    #touch .up { left: 14vmin; bottom: 31vmin; width: 14vmin; height: 14vmin; }
    #touch .down { left: 14vmin; bottom: 3vmin; width: 14vmin; height: 14vmin; }
    #touch .left { left: 1vmin; bottom: 17vmin; width: 14vmin; height: 14vmin; }
    #touch .right { left: 27vmin; bottom: 17vmin; width: 14vmin; height: 14vmin; }
    #touch .ok { right: 3vmin; bottom: 8vmin; width: 22vmin; height: 22vmin; background: rgba(63,185,80,.38); font-size: 20px; }
    #touch .back { right: 29vmin; bottom: 3vmin; width: 18vmin; height: 14vmin; background: rgba(248,81,73,.38); }`;
  document.head.appendChild(css);

  const btn = (cls, label, k, extra = '') => `<div class="b ${cls} ${extra}" data-k="${k}">${label}</div>`;
  const root = document.createElement('div');
  root.id = 'touch';
  root.innerHTML = `<div class="g drive">
      <div class="b steer" data-steer="1"><span>&#9664;</span><span>&#9654;</span></div>
      ${btn('gas', 'GAS', 'up')}${btn('brake', 'BRAKE', 'down')}${btn('nitro', 'NITRO', 'space')}${btn('hand', 'HAND', 'lshift')}
      ${btn('cam', 'CAM', 'camera')}${btn('resp', 'RESET', 'respot')}${btn('pause', 'PAUSE', 'esc')}
    </div><div class="g menu">
      ${btn('up round', '&#9650;', 'up')}${btn('down round', '&#9660;', 'down')}${btn('left round', '&#9664;', 'left')}${btn('right round', '&#9654;', 'right')}
      ${btn('ok round', 'OK', 'enter')}${btn('back', 'BACK', 'esc')}
    </div><div class="b mode" data-mode="1"></div>`;
  document.body.appendChild(root);

  // Held keys by DIK, counted over pointers (two thumbs on one key); a release waits out a minimum hold, so a quick tap
  // reaches the game's poll as a press and not as a down-up in one frame.
  const count = new Map(), downAt = new Map(), ptr = new Map();
  const st = { mode: 'menu', last: undefined };
  const layout = m => { st.mode = m; root.className = m; root.querySelector('.mode').textContent = m === 'drive' ? 'MENU' : 'DRIVE'; };
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
    return k;
  };
  const stop = e => {
    const p = ptr.get(e.pointerId);
    if (!p) return;
    p.el.classList.remove('on');
    setKeys(e.pointerId, new Set());
    ptr.delete(e.pointerId);
    sync();
  };
  root.addEventListener('pointerdown', e => {
    const el = e.target.closest('.b');
    if (!el) return;
    e.preventDefault();
    if (el.dataset.mode) { layout(st.mode === 'drive' ? 'menu' : 'drive'); st.last = performance.now(); return; }
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
  setInterval(() => { if (padUsed()) hide(); if (!ptr.size) sync(); }, 500);   // idle: back to the menu layout; a pad takes over
  layout('menu');
  return { layout };
}
