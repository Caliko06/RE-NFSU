// Touch overlay (iPad / iPhone: 'ontouchstart' in window; ?touch=1 forces it, ?touch=0 hides it) -> the keyboard path of
// web/input.js: every control presses DIK keys through startInput's setKey (same ring and held set as the keyboard and web/pad.js).
// Keys are the game's default action table (exe 0x702c98, docs/re/hud_input.md): arrows steer / gas / brake,
// Left Shift handbrake, Space nitrous, C camera, R respot, Esc pause; menus: arrows, Enter select, Esc back.
// It steps aside when a real keyboard key or a gamepad is used, and comes back on the next touch.
// Three layouts, chosen by the game itself: web/boot.js passes each "flow fe" line (host/d3d9.c flow_log: the front-end
// packages on screen) as window.RN_FE + an 'rn-fe' event.
//   drive: only HUD_*.fng / Chyron*.fng are up. A steering rocker (left thumb); gas, brake, nitro and handbrake on an arc
//          around the right thumb; pause, camera and respot on the top bar.
//   menu : any other package (menus, MU_Pause*, PreRaceStats, post race). One round d-pad (left), OK and back (right).
//   pause: menu, with the d-pad at the bottom centre (MU_Pause*.fng draws its list in the left 40 % of the screen: at the edge in
//          Original, further in on a wide Remaster screen).
//   wait : PC_Loading.fng. Nothing but the top bar.
// The race HUD owns the top corners (timer left, position and standings right), so in drive the small buttons sit top centre.
// The game's mouse cursor is parked off screen.
'use strict';
const TOUCH_MIN_HOLD_MS = 60, TOUCH_STEER_DEAD = 0.08;
const touchLayout = fe => fe.some(p => p.startsWith('PC_Loading')) ? 'wait' : fe.length && fe.every(p => /^(HUD_|Chyron)/.test(p)) ? 'drive'
  : fe.some(p => p.startsWith('MU_Pause')) ? 'pause' : 'menu';

function startTouch(input) {
  const want = RN_Q.get('touch');
  if (!input || want === '0' || !(want === '1' || 'ontouchstart' in window)) return null;
  const D = PAD_DIK;
  const css = document.createElement('style');
  // Sizes follow the phone's height (a landscape phone is 320-430 px tall): --t-u is one thumb unit. Every edge adds the
  // safe area (notch, rounded corners, home bar): children are absolute, so a padding on #touch would not move them.
  // One look for every control: dark glass with a top light and a soft drop shadow; colour only where it means something
  // (orange to crimson = go / accept, the page's accent in web/app.js; blue = nitrous; red ring = brake; amber = handbrake).
  css.textContent = `
    :root { --t-l: max(16px, env(safe-area-inset-left)); --t-r: max(16px, env(safe-area-inset-right));
      --t-t: max(10px, env(safe-area-inset-top)); --t-b: max(14px, env(safe-area-inset-bottom));
      --t-u: clamp(54px, 19vh, 96px); --t-s: 42px; }
    #touch { position: fixed; inset: 0; z-index: 8; pointer-events: none; touch-action: none; user-select: none; -webkit-user-select: none;
      -webkit-touch-callout: none; -webkit-tap-highlight-color: transparent; color: #fff; cursor: default;
      font: italic 800 calc(var(--t-u) * .36)/1 "Avenir Next Condensed", "DIN Condensed", "Roboto Condensed", "Arial Narrow", system-ui, sans-serif; letter-spacing: .04em; }
    #touch .g { position: absolute; inset: 0; opacity: 0; visibility: hidden; transition: opacity .16s ease-out, visibility 0s .16s; }
    #touch[data-m=drive] .g.drive, #touch[data-m=menu] .g.menu, #touch[data-m=pause] .g.menu { opacity: 1; visibility: visible; transition: opacity .16s ease-out; }
    #touch .b { --c1: rgba(38,44,76,.58); --c2: rgba(6,8,18,.62); --glow: rgba(150,175,255,.6); --edge: rgba(255,255,255,.24);
      position: absolute; box-sizing: border-box; pointer-events: auto; touch-action: none; display: flex; align-items: center; justify-content: center;
      border-radius: 50%; border: 1.5px solid var(--edge); text-shadow: 0 1px 3px rgba(0,0,0,.7);
      background: radial-gradient(90% 70% at 32% 14%, rgba(255,255,255,.3), rgba(255,255,255,0) 60%), linear-gradient(165deg, var(--c1), var(--c2));
      box-shadow: inset 0 1px 0 rgba(255,255,255,.3), inset 0 -.16em .5em rgba(0,0,0,.35), 0 8px 22px rgba(0,0,0,.42);
      transition: transform .12s cubic-bezier(.22,1,.36,1); }
    #touch .b.on { transform: scale(.97); --edge: rgba(255,255,255,.85); filter: brightness(1.3);
      box-shadow: inset 0 1px 0 rgba(255,255,255,.4), 0 0 0 4px rgba(255,255,255,.1), 0 0 28px var(--glow); }
    #touch .b svg { width: 46%; height: 46%; fill: none; stroke: currentColor; stroke-width: 2.2; stroke-linecap: round; stroke-linejoin: round; filter: drop-shadow(0 1px 2px rgba(0,0,0,.6)); pointer-events: none; }
    #touch .go { --c1: rgba(255,146,40,.9); --c2: rgba(196,10,62,.86); --glow: rgba(255,96,40,.85); --edge: rgba(255,214,170,.6); }
    /* small glass circles. menus: full screen top left, options (web/overlay.js) top right. drive: one row top centre:
       pause, camera, respot, options, full screen */
    #touch .top { top: var(--t-t); width: var(--t-s); height: var(--t-s); opacity: .82; --k: 0; left: calc(50% - var(--t-s) / 2 + var(--k) * (var(--t-s) + 10px)); }
    #touch .top svg { width: 50%; height: 50%; stroke-width: 2; }
    #touch .pause { --k: -2; } #touch .cam { --k: -1; } #touch .resp { --k: 0; }
    #touch .fs { left: var(--t-l); }
    #touch[data-m=drive] .fs { --k: 2; left: calc(50% - var(--t-s) / 2 + var(--k) * (var(--t-s) + 10px)); }
    #touch.fsok .fs { display: none; }
    body[data-touch=drive] #ov-btn { right: auto !important; left: calc(50% + var(--t-s) / 2 + 10px); }
    #ov-btn { top: var(--t-t) !important; right: var(--t-r) !important; width: var(--t-s) !important; height: var(--t-s) !important; opacity: .82 !important;
      border: 1.5px solid rgba(255,255,255,.24) !important; box-shadow: inset 0 1px 0 rgba(255,255,255,.3), 0 8px 22px rgba(0,0,0,.42);
      background: radial-gradient(90% 70% at 32% 14%, rgba(255,255,255,.3), rgba(255,255,255,0) 60%), linear-gradient(165deg, rgba(38,44,76,.58), rgba(6,8,18,.62)) !important; }
    #ov { top: calc(var(--t-t) + var(--t-s) + 8px) !important; right: var(--t-r) !important; max-height: calc(100dvh - var(--t-t) - var(--t-s) - 20px); overflow: auto; }
    /* drive, left thumb: one rocker, slide across it to change side */
    #touch .steer { left: var(--t-l); bottom: var(--t-b); width: calc(var(--t-u) * 3); height: calc(var(--t-u) * 1.2); border-radius: 999px; overflow: hidden; }
    #touch .steer.on { transform: none; filter: none; box-shadow: inset 0 1px 0 rgba(255,255,255,.3), 0 8px 22px rgba(0,0,0,.42); --edge: rgba(255,255,255,.24); }
    #touch .steer i { flex: 1; align-self: stretch; display: flex; align-items: center; justify-content: center; }
    #touch .steer i + i { box-shadow: -1px 0 0 rgba(255,255,255,.16); }
    #touch .steer i.on { background: linear-gradient(165deg, rgba(255,146,40,.92), rgba(196,10,62,.88)); box-shadow: inset 0 0 22px rgba(255,220,170,.45); }
    #touch .steer svg { width: 34%; height: 34%; stroke-width: 2.6; }
    /* drive, right thumb: an arc around the corner. Gas is the big one under the thumb, brake beside it, nitro and handbrake above */
    #touch .gas { right: var(--t-r); bottom: var(--t-b); width: calc(var(--t-u) * 1.35); height: calc(var(--t-u) * 1.35); }
    #touch .brake { right: calc(var(--t-r) + var(--t-u) * 1.51); bottom: var(--t-b); width: calc(var(--t-u) * 1.05); height: calc(var(--t-u) * 1.05);
      --c1: rgba(96,20,44,.66); --c2: rgba(20,4,12,.7); --edge: rgba(255,96,124,.8); --glow: rgba(255,60,96,.85); color: #ffc2cc; }
    #touch .nitro { right: calc(var(--t-r) + var(--t-u) * 1.14); bottom: calc(var(--t-b) + var(--t-u) * 1.14); width: calc(var(--t-u) * .9); height: calc(var(--t-u) * .9);
      --c1: rgba(56,214,255,.88); --c2: rgba(44,64,236,.86); --glow: rgba(80,170,255,.9); --edge: rgba(190,236,255,.7); }
    #touch .hand { right: calc(var(--t-r) + var(--t-u) * .14); bottom: calc(var(--t-b) + var(--t-u) * 1.51); width: calc(var(--t-u) * .8); height: calc(var(--t-u) * .8);
      --edge: rgba(255,210,138,.6); --glow: rgba(255,190,90,.8); color: #ffd28a; }
    /* menu: one round d-pad cut in four wedges (left thumb); OK and back like a pad's A / B (right thumb) */
    #touch .dpad { position: absolute; left: var(--t-l); bottom: var(--t-b); width: calc(var(--t-u) * 2.4); height: calc(var(--t-u) * 2.4); border-radius: 50%; overflow: hidden;
      box-sizing: border-box; border: 1.5px solid rgba(255,255,255,.24); box-shadow: inset 0 1px 0 rgba(255,255,255,.3), 0 8px 22px rgba(0,0,0,.42);
      background: radial-gradient(90% 70% at 32% 14%, rgba(255,255,255,.24), rgba(255,255,255,0) 60%), linear-gradient(165deg, rgba(38,44,76,.58), rgba(6,8,18,.62)); }
    #touch[data-m=pause] .dpad { left: 42vw; }
    #touch .dpad::before { content: ""; position: absolute; inset: 0; pointer-events: none;
      background: linear-gradient(45deg, transparent calc(50% - .5px), rgba(255,255,255,.14) 0, rgba(255,255,255,.14) calc(50% + .5px), transparent 0),
        linear-gradient(-45deg, transparent calc(50% - .5px), rgba(255,255,255,.14) 0, rgba(255,255,255,.14) calc(50% + .5px), transparent 0); }
    #touch .dpad::after { content: ""; position: absolute; inset: 36%; border-radius: 50%; pointer-events: none; background: linear-gradient(165deg, #2a3052, #080a14);
      box-shadow: inset 0 1px 0 rgba(255,255,255,.3), 0 2px 10px rgba(0,0,0,.5); }
    #touch .dpad .b { inset: 0; border: 0; border-radius: 0; background: none; box-shadow: none; transition: none; }
    #touch .dpad .b.on { transform: none; filter: none; background: radial-gradient(circle at 50% 50%, rgba(196,10,62,.2) 30%, rgba(255,146,40,.92) 72%); }
    #touch .dpad svg { position: absolute; width: 17%; height: 17%; stroke-width: 2.8; }
    #touch .dpad .up { clip-path: polygon(0 0, 100% 0, 50% 50%); } #touch .dpad .up svg { top: 8%; left: 41.5%; }
    #touch .dpad .right { clip-path: polygon(100% 0, 100% 100%, 50% 50%); } #touch .dpad .right svg { right: 8%; top: 41.5%; }
    #touch .dpad .down { clip-path: polygon(0 100%, 100% 100%, 50% 50%); } #touch .dpad .down svg { bottom: 8%; left: 41.5%; }
    #touch .dpad .left { clip-path: polygon(0 0, 0 100%, 50% 50%); } #touch .dpad .left svg { left: 8%; top: 41.5%; }
    #touch .ok { right: var(--t-r); bottom: calc(var(--t-b) + var(--t-u) * .5); width: calc(var(--t-u) * 1.35); height: calc(var(--t-u) * 1.35); font-size: calc(var(--t-u) * .44); }
    #touch .back { right: calc(var(--t-r) + var(--t-u) * 1.5); bottom: var(--t-b); width: var(--t-u); height: var(--t-u); }
    #touch .tip { position: absolute; left: 50%; top: calc(var(--t-t) + var(--t-s) + 12px); transform: translateX(-50%); max-width: min(80vw, 420px);
      padding: 10px 16px; border-radius: 14px; background: rgba(8,10,18,.88); border: 1px solid rgba(255,255,255,.2); text-align: center;
      font: 600 14px/1.4 system-ui, sans-serif; letter-spacing: 0; display: none; }
    #touch .tip.on { display: block; }
    @media (prefers-reduced-motion: reduce) { #touch .b, #touch .g, #touch[data-m] .g { transition: none; } }`;
  document.head.appendChild(css);

  const svg = d => `<svg viewBox="0 0 24 24" aria-hidden="true">${d}</svg>`;
  const disc = '<circle cx="12" cy="12" r="5.6"/><path d="M4.6 6.2a9.6 9.6 0 0 0 0 11.6M19.4 6.2a9.6 9.6 0 0 1 0 11.6"/>';   // the dashboard's brake lamp
  const I = {
    left: svg('<path d="M15 5l-7 7 7 7"/>'), right: svg('<path d="M9 5l7 7-7 7"/>'),
    up: svg('<path d="M5 15l7-7 7 7"/>'), down: svg('<path d="M5 9l7 7 7-7"/>'),
    gas: svg('<path d="M5 12.5l7-7 7 7M5 19l7-7 7 7"/>'),
    brake: svg(disc + '<path d="M12 9.4v3"/><path d="M12 14.7v.1"/>'),
    hand: svg(disc + '<path d="M10.7 14.8V9.3h1.5a1.7 1.7 0 0 1 0 3.4h-1.5"/>'),
    nitro: svg('<path d="M12.5 2.5c.6 3.6 5 5.6 5 10.6a5.5 5.5 0 0 1-11 0c0-2.2 1-3.6 2.2-4.8.2 1.8.9 2.7 1.9 3 -.6-3.4.5-6.6 1.9-8.8z"/>'),
    back: svg('<path d="M8.5 5.5L4 10l4.5 4.5"/><path d="M4 10h10.5a4.5 4.5 0 0 1 0 9H11"/>'),
    pause: svg('<path d="M9 6v12M15 6v12"/>'), fs: svg('<path d="M4 9V4h5M20 9V4h-5M4 15v5h5M20 15v5h-5"/>'),
    cam: svg('<path d="M4 8h3l2-2h6l2 2h3v11H4z"/><circle cx="12" cy="13" r="3.2"/>'),
    resp: svg('<path d="M4 12a8 8 0 1 0 2.4-5.7"/><path d="M4 4v4h4"/>'),
  };
  const btn = (cls, label, k, title) => `<div class="b ${cls}" data-k="${k}" role="button" aria-label="${title}">${label}</div>`;
  const root = document.createElement('div');
  root.id = 'touch';
  root.innerHTML = `<div class="g drive">
      <div class="b steer" data-steer="1" role="button" aria-label="Volante"><i>${I.left}</i><i>${I.right}</i></div>
      ${btn('gas go', I.gas, 'up', 'Acelerar')}${btn('brake', I.brake, 'down', 'Frenar')}${btn('nitro', I.nitro, 'space', 'Nitro')}${btn('hand', I.hand, 'lshift', 'Freno de mano')}
      ${btn('top pause', I.pause, 'esc', 'Pausa')}${btn('top cam', I.cam, 'camera', 'Cámara')}${btn('top resp', I.resp, 'respot', 'Reiniciar auto')}
    </div><div class="g menu">
      <div class="dpad">${btn('up', I.up, 'up', 'Arriba')}${btn('right', I.right, 'right', 'Derecha')}${btn('down', I.down, 'down', 'Abajo')}${btn('left', I.left, 'left', 'Izquierda')}</div>
      ${btn('ok go', 'OK', 'enter', 'Aceptar')}${btn('back', I.back, 'esc', 'Atrás')}
    </div><div class="b top fs" data-fs="1" role="button" aria-label="Pantalla completa">${I.fs}</div><div class="tip"></div>`;
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
  };
  root.addEventListener('pointerdown', e => {
    const el = e.target.closest('.b');
    if (!el) return;
    e.preventDefault();
    if (el.dataset.fs) { goFull(); return; }
    try { el.setPointerCapture(e.pointerId); } catch {}   // the pointer can be gone already (a very short tap): the keys still go down and up
    const names = (el.dataset.k || '').split(',').filter(Boolean);
    ptr.set(e.pointerId, { el, keys: new Set() });
    el.classList.add('on');
    setKeys(e.pointerId, el.dataset.steer ? steerKeys(e, el) : new Set(names.map(n => D[n])));
  });
  root.addEventListener('pointermove', e => {
    const p = ptr.get(e.pointerId);
    if (p && p.el.dataset.steer) setKeys(e.pointerId, steerKeys(e, p.el));
  });
  for (const t of ['pointerup', 'pointercancel', 'lostpointercapture']) root.addEventListener(t, stop);
  const releaseAll = () => { for (const id of [...ptr.keys()]) stop({ pointerId: id }); };
  // The layout follows the game's screens; what a thumb held on the old layout is released.
  const layout = () => { const m = touchLayout(window.RN_FE || []); if (m !== root.dataset.m) { releaseAll(); root.dataset.m = document.body.dataset.touch = m; } };
  addEventListener('rn-fe', layout);
  // A keyboard key or a pad means a real controller is in hand: the overlay hides (releasing what it held) and returns on the next touch.
  const hide = () => { if (root.style.display !== 'none') { releaseAll(); root.style.display = 'none'; delete document.body.dataset.touch; } };
  const show = () => { if (root.style.display === 'none') { root.style.display = ''; document.body.dataset.touch = root.dataset.m; } };
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
  setInterval(() => { if (padUsed()) hide(); if (root.style.display !== 'none') input.park(); }, 500);   // a pad takes over
  layout();
}
