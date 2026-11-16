// Key and gamepad-button bindings, saved in localStorage ('rn_binds'), edited in a small overlay (key K, or pad Select).
// The game keeps its own action table (exe 0x702c98, docs/re/hud_input.md) on DIK codes, so a binding never changes what the
// game sees: it changes which browser key / pad button presses that DIK. Defaults = the game's own keys, so with nothing
// saved the page behaves as before.
//   keyboard : KeyboardEvent.code -> action -> the action's DIK (web/input.js asks dikFor)
//   pad      : action -> button index of the standard mapping (web/pad.js asks BINDS.pad); drive actions apply in the drive layout, accept / back in menus
// Esc and Enter stay fixed on the keyboard (menus need them); sticks, d-pad and triggers stay fixed on the pad.
'use strict';
const BIND_KEYS = [   // id, label, DIK the game reads, default KeyboardEvent.code
  ['left', 'Girar a la izquierda', 0xcb, 'ArrowLeft'], ['right', 'Girar a la derecha', 0xcd, 'ArrowRight'],
  ['gas', 'Acelerar', 0xc8, 'ArrowUp'], ['brake', 'Frenar / reversa', 0xd0, 'ArrowDown'],
  ['nitro', 'Nitro', 0x39, 'Space'], ['handbrake', 'Freno de mano', 0x2a, 'ShiftLeft'],
  ['camera', 'Cámara', 0x2e, 'KeyC'], ['respot', 'Reiniciar el coche', 0x13, 'KeyR'],
];
const BIND_PAD = [    // id, label, default button (standard mapping: 0 A, 1 B, 2 X, 3 Y, 4 LB, 5 RB, 9 Start)
  ['nitro', 'Nitro', 0], ['handbrake', 'Freno de mano', 1], ['camera', 'Cámara', 3], ['respot', 'Reiniciar el coche', 5],
  ['pause', 'Pausa (Esc)', 9], ['accept', 'Menú: aceptar', 0], ['back', 'Menú: atrás', 1],
];
const PAD_GROUPS = { nitro: 'drive', handbrake: 'drive', camera: 'drive', respot: 'drive', pause: 'drive', accept: 'menu', back: 'menu' };
const PAD_NAMES = ['A', 'B', 'X', 'Y', 'LB', 'RB', 'LT', 'RT', 'Select', 'Start', 'L3', 'R3', 'Up', 'Down', 'Left', 'Right', 'Home'];

const BINDS = (() => {
  const keys = {}, pad = {};   // live tables: action -> code / button
  const load = () => {
    for (const [id, , , code] of BIND_KEYS) keys[id] = code;
    for (const [id, , b] of BIND_PAD) pad[id] = b;
    let s = {};
    try { s = JSON.parse(localStorage.getItem('rn_binds') || '{}'); } catch {}
    for (const [id] of BIND_KEYS) if (typeof s.key?.[id] === 'string' && DIK[s.key[id]] !== undefined) keys[id] = s.key[id];
    for (const [id] of BIND_PAD) if (Number.isInteger(s.pad?.[id]) && s.pad[id] >= 0 && s.pad[id] < 16) pad[id] = s.pad[id];
  };
  const save = () => {
    const key = {}, p = {};
    for (const [id, , , code] of BIND_KEYS) if (keys[id] !== code) key[id] = keys[id];
    for (const [id, , b] of BIND_PAD) if (pad[id] !== b) p[id] = pad[id];
    try {
      if (Object.keys(key).length || Object.keys(p).length) localStorage.setItem('rn_binds', JSON.stringify({ key, pad: p }));
      else localStorage.removeItem('rn_binds');
    } catch {}
  };
  load();
  return { keys, pad, load, save, open: false, toggle: () => {} };   // toggle is replaced by the overlay
})();

// Browser key -> DIK. A key bound to an action presses that action's DIK; a key that is the default of an action
// that was moved elsewhere presses nothing; every other key is itself.
function dikFor(code) {
  for (const [id, , dik] of BIND_KEYS) if (BINDS.keys[id] === code) return dik;
  const d = DIK[code];
  if (d !== undefined && BIND_KEYS.some(([, , dik]) => dik === d)) return undefined;
  return d;
}

(function bindsOverlay() {
  const css = document.createElement('style');
  css.textContent = `
    #binds { position: fixed; inset: 0; z-index: 20; display: none; background: rgba(0,0,0,.78); color: #e6edf3; font: 14px system-ui, sans-serif;
      align-items: center; justify-content: center; outline: none; }
    #binds.on { display: flex; }
    #binds .box { background: #0d1117; border: 1px solid #30363d; border-radius: 10px; padding: 16px 20px; max-height: 90vh; overflow: auto; }
    #binds h3 { margin: 0 0 8px; font-size: 15px; } #binds .cols { display: flex; gap: 28px; }
    #binds table { border-collapse: collapse; } #binds td { padding: 3px 6px; }
    #binds button { background: #21262d; color: #e6edf3; border: 1px solid #30363d; border-radius: 6px; padding: 3px 10px; min-width: 84px; font: inherit; cursor: pointer; }
    #binds button.cap { background: #ffc24a; color: #000; } #binds .foot { margin-top: 10px; color: #8b949e; display: flex; gap: 12px; align-items: center; }`;
  document.head.appendChild(css);
  const root = document.createElement('div');
  root.id = 'binds'; root.tabIndex = -1;
  document.body.appendChild(root);

  let cap = null, padPrev = [], raf = 0;       // cap = { kind: 'key'|'pad', id } while a row waits for its key / button
  const canvas = () => document.getElementById('screen');
  const keyName = c => ({ ArrowLeft: '←', ArrowRight: '→', ArrowUp: '↑', ArrowDown: '↓' })[c] || c.replace(/^Key|^Digit/, '');

  function render() {
    const tr = window.RN_TR || (s => s);
    const row = (kind, id, label, val) =>
      `<tr><td>${label}</td><td><button data-k="${kind}" data-id="${id}" class="${cap && cap.kind === kind && cap.id === id ? 'cap' : ''}">${cap && cap.kind === kind && cap.id === id ? (window.RN_TR || (s => s))('pulsa…') : val}</button></td></tr>`;
    root.innerHTML = `<div class="box"><div class="cols">
      <div><h3>${tr('Teclado')}</h3><table>${BIND_KEYS.map(([id, label]) => row('key', id, tr(label), keyName(BINDS.keys[id]))).join('')}</table></div>
      <div><h3>${tr('Mando')}</h3><table>${BIND_PAD.map(([id, label]) => row('pad', id, tr(label), PAD_NAMES[BINDS.pad[id]] ?? 'B' + BINDS.pad[id])).join('')}</table></div></div>
      <div class="foot"><button data-reset="1">${tr('Valores de fábrica')}</button><span>${tr('Clic en una acción y luego la tecla o el botón. Palanca, cruceta y gatillos son fijos. Esc, K o Select cierra.')}</span></div></div>`;
  }

  // Binding one id to a value swaps with whoever had it (same layout group on the pad).
  function bindKey(id, code) {
    if (DIK[code] === undefined || code === 'Escape' || code === 'Enter') return;
    const other = Object.keys(BINDS.keys).find(o => o !== id && BINDS.keys[o] === code);
    if (other) BINDS.keys[other] = BINDS.keys[id];
    BINDS.keys[id] = code;
  }
  function bindPad(id, b) {
    const other = Object.keys(BINDS.pad).find(o => o !== id && PAD_GROUPS[o] === PAD_GROUPS[id] && BINDS.pad[o] === b);
    if (other) BINDS.pad[other] = BINDS.pad[id];
    BINDS.pad[id] = b;
  }

  function padLoop() {
    if (!BINDS.open) return;
    const p = [...(navigator.getGamepads?.() || [])].find(g => g && g.connected);
    const now = p ? p.buttons.map(b => b && (b.pressed || b.value > 0.5)) : [];
    if (cap && cap.kind === 'pad') {
      const i = now.findIndex((v, n) => v && !padPrev[n] && n !== 8 && n < 16 && !(n >= 12 && n <= 15) && n !== 6 && n !== 7);
      if (i >= 0) { bindPad(cap.id, i); cap = null; BINDS.save(); render(); }
    }
    padPrev = now;
    raf = requestAnimationFrame(padLoop);
  }

  function setOpen(on) {
    if (on === BINDS.open) return;
    BINDS.open = on; cap = null;
    root.classList.toggle('on', on);
    if (on) { padPrev = []; render(); root.focus(); raf = requestAnimationFrame(padLoop); }   // focusing blurs the canvas, which frees held keys
    else { cancelAnimationFrame(raf); canvas()?.focus(); }
  }
  BINDS.toggle = () => setOpen(!BINDS.open);

  root.addEventListener('click', e => {
    const b = e.target.closest('button');
    if (!b) return;
    if (b.dataset.reset) { localStorage.removeItem('rn_binds'); BINDS.load(); cap = null; render(); return; }
    cap = { kind: b.dataset.k, id: b.dataset.id }; render();
  });

  // Capture phase on window: the game's canvas never sees these keys. K opens; while open, keys bind or close.
  addEventListener('keydown', e => {
    if (e.code === 'KeyK' && !BINDS.open && !e.repeat && !e.ctrlKey && !e.metaKey && !e.altKey) { e.preventDefault(); e.stopPropagation(); setOpen(true); return; }
    if (!BINDS.open) return;
    e.preventDefault(); e.stopPropagation();
    if (e.repeat) return;
    if (cap && cap.kind === 'key') {
      if (e.code !== 'Escape') { bindKey(cap.id, e.code); BINDS.save(); }
      cap = null; render(); return;
    }
    if (e.code === 'Escape' || e.code === 'KeyK') setOpen(false);
  }, true);
  addEventListener('keyup', e => { if (BINDS.open || e.code === 'KeyK') { e.preventDefault(); e.stopPropagation(); } }, true);
})();
