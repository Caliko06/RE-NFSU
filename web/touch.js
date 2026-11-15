// Touch overlay (iPad / iPhone: 'ontouchstart' in window; ?touch=1 forces it, ?touch=0 hides it) -> the keyboard path of
// web/input.js (DIK keys through startInput's setKey, same ring and held set as the keyboard and web/pad.js) and, in menus, its mouse path.
// Keys are the game's default action table (exe 0x702c98, docs/re/hud_input.md): arrows steer / gas / brake,
// Left Shift handbrake, Space nitrous, C camera, R respot, Esc pause.
// It steps aside when a real keyboard key or a gamepad is used, and comes back on the next touch.
// Layouts, chosen by the game itself: web/boot.js passes each "flow fe" line (host/d3d9.c flow_log: the front-end
// packages on screen) as window.RN_FE + an 'rn-fe' event.
//   drive: only HUD_*.fng / Chyron*.fng are up. The screen below the top bar is two invisible halves, one per thumb; the visible marks are small.
//          gas auto (default; GRID Autosport's Arrow Touch): the car accelerates by itself, a thumb on a half steers to that side,
//          both thumbs brake (the thumb that was down first keeps steering). gas manual: left half steers (slide across the two
//          chevrons), right half is the gas, brake is a button beside it. Nitro and handbrake sit above the thumbs.
//   menu : any other package (menus, MU_Pause*, post race). A touch is the game's own mouse (the PC game's menus take it): touch = move
//          there and press, slide = drag, lift = release. One back button. With no package up (intro movies) a touch is Enter.
//   wait : PC_Loading.fng. Nothing but the top bar.
// Look (Apple HIG game controls, Xbox touch designer's guide): no fill and no colour at rest, a thin white line at --t-o; a pressed
// control takes the race HUD's own blue (sampled from the position counter, 144 184 248) with a halo that shows around the thumb.
// The race HUD owns the top corners (timer left, position and standings right), so in drive the small buttons sit top centre.
'use strict';
const TOUCH_MIN_HOLD_MS = 60, TOUCH_STEER_DEAD_PX = 6, TOUCH_BRAKE_MS = 120, TOUCH_BOTH_MS = 120;
const touchLayout = fe => fe.some(p => p.startsWith('PC_Loading')) ? 'wait' : fe.length && fe.every(p => /^(HUD_|Chyron)/.test(p)) ? 'drive' : 'menu';

function startTouch(input) {
  const want = RN_Q.get('touch');
  if (!input || want === '0' || !(want === '1' || 'ontouchstart' in window)) return null;
  const D = PAD_DIK;
  // The player's choices (options panel, web/overlay.js): gas auto | manual, o = resting opacity in %, k = size. ?tgas= and ?to= set them for one visit.
  const S = { gas: 'auto', o: 35, k: 1 };
  try { Object.assign(S, JSON.parse(localStorage.getItem('rn-touch') || '{}')); } catch {}
  if (RN_Q.has('tgas')) S.gas = RN_Q.get('tgas') === 'manual' ? 'manual' : 'auto';
  if (+RN_Q.get('to')) S.o = +RN_Q.get('to');
  const css = document.createElement('style');
  // Sizes follow the phone's height (a landscape phone is 320-430 px tall): --t-u is one thumb unit. Every edge adds the
  // safe area (notch, rounded corners, home bar): children are absolute, so a padding on #touch would not move them.
  css.textContent = `
    :root { --t-l: max(16px, env(safe-area-inset-left)); --t-r: max(16px, env(safe-area-inset-right));
      --t-t: max(10px, env(safe-area-inset-top)); --t-b: max(14px, env(safe-area-inset-bottom));
      --t-o: .35; --t-k: 1; --t-u: calc(clamp(54px, 19vh, 96px) * var(--t-k)); --t-s: 36px; --t-c: 144,184,248; }
    #touch { position: fixed; inset: 0; z-index: 8; pointer-events: none; touch-action: none; user-select: none; -webkit-user-select: none;
      -webkit-touch-callout: none; -webkit-tap-highlight-color: transparent; color: rgba(255,255,255,calc(var(--t-o) + .25)); cursor: default; }
    #touch .g { position: absolute; inset: 0; opacity: 0; visibility: hidden; transition: opacity .16s ease-out, visibility 0s .16s; }
    #touch[data-m=drive] .g.drive, #touch[data-m=menu] .g.menu { opacity: 1; visibility: visible; transition: opacity .16s ease-out; }
    #touch .z, #touch .tapl { position: absolute; pointer-events: auto; touch-action: none; }
    #touch .z { top: 22%; bottom: 0; width: 50%; } #touch .zl { left: 0; } #touch .zr { right: 0; } #touch .tapl { inset: 0; }
    /* a dark hairline on both sides of the white line keeps it readable over a bright street */
    #touch .b, #ov-btn { position: absolute; box-sizing: border-box; pointer-events: auto; touch-action: none; display: flex; align-items: center; justify-content: center;
      border-radius: 50%; border: 1.5px solid rgba(255,255,255,var(--t-o)); background: none; box-shadow: 0 0 0 1px rgba(0,0,0,.16), inset 0 0 0 1px rgba(0,0,0,.16);
      transition: transform .12s cubic-bezier(.22,1,.36,1), border-color .1s ease-out, box-shadow .1s ease-out, color .1s ease-out, background-color .1s ease-out; }
    #touch .b.on { transform: scale(.97); color: rgb(var(--t-c)); border-color: rgb(var(--t-c)); background-color: rgba(var(--t-c),.14);
      box-shadow: 0 0 0 5px rgba(var(--t-c),.16), 0 0 26px 6px rgba(var(--t-c),.55); }
    #touch .b svg, #ov-btn svg { width: 46%; height: 46%; fill: none; stroke: currentColor; stroke-width: 2; stroke-linecap: round; stroke-linejoin: round; filter: drop-shadow(0 0 1.5px rgba(0,0,0,.6)); pointer-events: none; }
    #touch .mk { pointer-events: none; bottom: var(--t-b); width: calc(var(--t-u) * 1.25); height: calc(var(--t-u) * 1.25); }
    /* small circles. menus: full screen top left, options (web/overlay.js) top right. drive: one row top centre: pause, camera, respot, options, full screen */
    #touch .top { top: var(--t-t); width: var(--t-s); height: var(--t-s); --k: 0; left: calc(50% - var(--t-s) / 2 + var(--k) * (var(--t-s) + 10px)); }
    #touch .pause { --k: -2; } #touch .cam { --k: -1; } #touch .resp { --k: 0; }
    #touch .fs { left: var(--t-l); }
    #touch[data-m=drive] .fs { --k: 2; left: calc(50% - var(--t-s) / 2 + var(--k) * (var(--t-s) + 10px)); }
    #touch.fsok .fs { display: none; }
    body[data-touch=drive] #ov-btn { right: auto !important; left: calc(50% + var(--t-s) / 2 + 10px); }
    #ov-btn { position: fixed !important; top: var(--t-t) !important; right: var(--t-r) !important; width: var(--t-s) !important; height: var(--t-s) !important; opacity: 1 !important;
      color: rgba(255,255,255,calc(var(--t-o) + .25)) !important; background: none !important; border: 1.5px solid rgba(255,255,255,var(--t-o)) !important; }
    #ov-btn.on { color: rgb(var(--t-c)) !important; border-color: rgb(var(--t-c)) !important; }
    #ov { top: calc(var(--t-t) + var(--t-s) + 8px) !important; right: var(--t-r) !important; max-height: calc(100dvh - var(--t-t) - var(--t-s) - 20px); overflow: auto; }
    /* drive, gas auto: one chevron under each thumb, nitro above the left one, handbrake above the right one */
    #touch .mk.l { left: var(--t-l); } #touch .mk.r { right: var(--t-r); }
    #touch .nitro { left: calc(var(--t-l) + var(--t-u) * .45); bottom: calc(var(--t-b) + var(--t-u) * 1.6); width: calc(var(--t-u) * .95); height: calc(var(--t-u) * .95); }
    #touch .hand { right: calc(var(--t-r) + var(--t-u) * .45); bottom: calc(var(--t-b) + var(--t-u) * 1.6); width: calc(var(--t-u) * .95); height: calc(var(--t-u) * .95); }
    #touch .mk.gas, #touch .brake { display: none; }
    /* drive, gas manual: both chevrons under the left thumb; gas under the right thumb, brake beside it, nitro and handbrake on its arc */
    #touch.manual .mk.r { right: auto; left: calc(var(--t-l) + var(--t-u) * 1.4); }
    #touch.manual .mk.gas { display: flex; right: var(--t-r); width: calc(var(--t-u) * 1.35); height: calc(var(--t-u) * 1.35); }
    #touch.manual .brake { display: flex; right: calc(var(--t-r) + var(--t-u) * 1.51); bottom: var(--t-b); width: calc(var(--t-u) * 1.05); height: calc(var(--t-u) * 1.05); }
    #touch.manual .nitro { left: auto; right: calc(var(--t-r) + var(--t-u) * 1.14); bottom: calc(var(--t-b) + var(--t-u) * 1.14); width: calc(var(--t-u) * .9); height: calc(var(--t-u) * .9); }
    #touch.manual .hand { right: calc(var(--t-r) + var(--t-u) * .14); bottom: calc(var(--t-b) + var(--t-u) * 1.51); width: calc(var(--t-u) * .8); height: calc(var(--t-u) * .8); }
    /* menu: the whole screen is the game's mouse; back under the right thumb */
    #touch .back { right: var(--t-r); bottom: var(--t-b); width: calc(var(--t-u) * .95); height: calc(var(--t-u) * .95); }
    #touch .tip { position: absolute; left: 50%; top: calc(var(--t-t) + var(--t-s) + 12px); transform: translateX(-50%); max-width: min(80vw, 420px);
      padding: 10px 16px; border-radius: 14px; background: rgba(8,10,18,.88); border: 1px solid rgba(255,255,255,.2); text-align: center; color: #fff;
      font: 600 14px/1.4 system-ui, sans-serif; display: none; }
    #touch .tip.on { display: block; }
    @media (prefers-reduced-motion: reduce) { #touch .b, #touch .g, #touch[data-m] .g { transition: none; } }`;
  document.head.appendChild(css);

  const svg = d => `<svg viewBox="0 0 24 24" aria-hidden="true">${d}</svg>`;
  const disc = '<circle cx="12" cy="12" r="5.6"/><path d="M4.6 6.2a9.6 9.6 0 0 0 0 11.6M19.4 6.2a9.6 9.6 0 0 1 0 11.6"/>';   // the dashboard's brake lamp
  const I = {
    left: svg('<path d="M15 5l-7 7 7 7"/>'), right: svg('<path d="M9 5l7 7-7 7"/>'),
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
      <div class="z zl" data-z="l"></div><div class="z zr" data-z="r"></div>
      <div class="b mk l">${I.left}</div><div class="b mk r">${I.right}</div><div class="b mk gas">${I.gas}</div>
      ${btn('brake', I.brake, 'down', 'Frenar')}${btn('nitro', I.nitro, 'space', 'Nitro')}${btn('hand', I.hand, 'lshift', 'Freno de mano')}
      ${btn('top pause', I.pause, 'esc', 'Pausa')}${btn('top cam', I.cam, 'camera', 'Cámara')}${btn('top resp', I.resp, 'respot', 'Reiniciar auto')}
    </div><div class="g menu">
      <div class="tapl"></div>${btn('back', I.back, 'esc', 'Atrás')}
    </div><div class="b top fs" data-fs="1" role="button" aria-label="Pantalla completa">${I.fs}</div><div class="tip"></div>`;
  document.body.appendChild(root);
  const mkL = root.querySelector('.mk.l'), mkR = root.querySelector('.mk.r'), mkGas = root.querySelector('.mk.gas');

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

  // The two halves of the drive screen. Z.l / Z.r = the thumb on that half ({ id, t: when it came down, x }).
  const Z = { l: null, r: null };
  let zKeys = new Set(), zT = 0;
  const zoneSync = () => {
    clearTimeout(zT);
    const k = new Set(), now = performance.now();
    let sl = false, sr = false, brk = false, gas = false;
    if (driving() && S.gas === 'auto') {
      if (Z.l && Z.r) {
        // both thumbs: brake, once both have been down TOUCH_BRAKE_MS (a fast left-right change overlaps for less). The thumb that
        // was down first keeps steering; two thumbs landing together brake straight.
        const t2 = Math.max(Z.l.t, Z.r.t);
        brk = now - t2 >= TOUCH_BRAKE_MS;
        if (!brk) zT = setTimeout(zoneSync, TOUCH_BRAKE_MS - (now - t2) + 1);
        if (Math.abs(Z.l.t - Z.r.t) >= TOUCH_BOTH_MS) Z.l.t < Z.r.t ? sl = true : sr = true;
      } else { sl = !!Z.l; sr = !!Z.r; }
      k.add(brk ? D.down : D.up);
    } else if (driving()) {
      if (Z.l) { const x = Z.l.x - (mkL.getBoundingClientRect().right + mkR.getBoundingClientRect().left) / 2; sl = x < -TOUCH_STEER_DEAD_PX; sr = x > TOUCH_STEER_DEAD_PX; }
      if (Z.r) { gas = true; k.add(D.up); }
    }
    if (sl) k.add(D.left);
    if (sr) k.add(D.right);
    zKeys = swap(zKeys, k);
    mkL.classList.toggle('on', sl || brk); mkR.classList.toggle('on', sr || brk); mkGas.classList.toggle('on', gas);
  };

  // Menus: the touch drives the game's mouse, in order (move, press, release).
  let mq = Promise.resolve(), mAt = null;
  const later = ms => new Promise(r => setTimeout(r, ms));

  const stop = e => {
    for (const s of ['l', 'r']) if (Z[s]?.id === e.pointerId) { Z[s] = null; zoneSync(); }
    if (mAt?.id === e.pointerId) { mAt = null; mq = mq.then(() => later(TOUCH_MIN_HOLD_MS)).then(() => input.mouseBtn(false)); }
    const p = ptr.get(e.pointerId);
    if (!p) return;
    p.el.classList.remove('on');
    swap(p.keys, new Set());
    ptr.delete(e.pointerId);
  };
  root.addEventListener('pointerdown', e => {
    const el = e.target.closest('.b, .z, .tapl');
    if (!el) return;
    e.preventDefault();
    if (el.dataset.fs) { goFull(); return; }
    try { el.setPointerCapture(e.pointerId); } catch {}   // the pointer can be gone already (a very short tap): the keys still go down and up
    if (el.dataset.z) { Z[el.dataset.z] = { id: e.pointerId, t: performance.now(), x: e.clientX }; zoneSync(); return; }
    if (el.classList.contains('tapl')) {
      if (!(window.RN_FE || []).length) { press(D.enter); release(D.enter); return; }   // intro movies: no package to point at
      const x = e.clientX, y = e.clientY;
      mAt = { id: e.pointerId };
      mq = mq.then(() => input.mouseTo(x, y)).then(() => later(80)).then(() => input.mouseBtn(true));
      return;
    }
    navigator.vibrate?.(8);   // Android; an iPhone's Safari has no vibration
    el.classList.add('on');
    ptr.set(e.pointerId, { el, keys: swap(new Set(), new Set((el.dataset.k || '').split(',').filter(Boolean).map(n => D[n]))) });
  });
  root.addEventListener('pointermove', e => {
    if (Z.l?.id === e.pointerId) { Z.l.x = e.clientX; if (S.gas !== 'auto') zoneSync(); }
    if (mAt?.id === e.pointerId) { const x = e.clientX, y = e.clientY; mq = mq.then(() => input.mouseTo(x, y)); }
  });
  for (const t of ['pointerup', 'pointercancel', 'lostpointercapture']) root.addEventListener(t, stop);
  const releaseAll = () => { for (const id of [...ptr.keys(), Z.l?.id, Z.r?.id, mAt?.id]) if (id !== undefined) stop({ pointerId: id }); zoneSync(); };
  // The layout follows the game's screens; what a thumb held on the old layout is released.
  const layout = () => {
    const m = touchLayout(window.RN_FE || []);
    if (m === root.dataset.m) return;
    releaseAll(); root.dataset.m = document.body.dataset.touch = m; zoneSync();
    let seen = true;
    try { seen = !!localStorage.getItem('rn-touch-tip'); if (m === 'drive' && !seen) localStorage.setItem('rn-touch-tip', '1'); } catch {}
    if (m === 'drive' && !seen && S.gas === 'auto') say('El auto acelera solo. Un pulgar de cada lado gira; los dos juntos frenan.');
  };
  addEventListener('rn-fe', layout);
  // The options panel (web/overlay.js) reads and changes the choices; they apply at once.
  const apply = () => {
    root.classList.toggle('manual', S.gas !== 'auto');
    document.documentElement.style.setProperty('--t-o', S.o / 100);
    document.documentElement.style.setProperty('--t-k', S.k);
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
  // In a race the game's arrow cursor has no use: keep it parked off screen (web/input.js park). In menus it is where the last touch put it.
  setInterval(() => { if (padUsed()) hide(); if (shown() && root.dataset.m !== 'menu') input.park(); }, 500);   // a pad takes over
  layout();
}
