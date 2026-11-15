// On-screen keyboard for the profile name (phones and tablets: no hardware keyboard, and the game's field opens none).
// The game takes the name on MU_UG_NewOrLoad_PC2.fng (handler 0x4183b0, vtable 0x6cbc18): Enter on NEW DRIVER PROFILE opens
// the field, WM_CHAR fills it (host/user32.c TranslateMessage_ from the DIK ring), Enter accepts into 0x777b74.
// So this is a plain keyboard: each key goes through startInput's key(DIK) like a real one and the game's own field shows
// the text. A chip shows while that screen is up (boot.js RN_FE + 'rn-fe'); it opens the keys. Nothing is read from the game.
'use strict';
const NAMEKEYS_SCREEN = 'MU_UG_NewOrLoad_PC2.fng';
const NAMEKEYS_HOLD_MS = 70, NAMEKEYS_GAP_MS = 45;   // one key down, up, then the next: the ring keeps changes only, so "LL" needs the up between

function startNameKeys(input) {
  const want = RN_Q.get('touch');
  if (!input || want === '0' || !(want === '1' || 'ontouchstart' in window)) return null;
  const css = document.createElement('style');
  css.textContent = `
    #nk-chip, #nk { position: fixed; z-index: 12; font: 600 14px/1 system-ui, sans-serif; color: #e8eeff; user-select: none; -webkit-user-select: none;
      -webkit-touch-callout: none; -webkit-tap-highlight-color: transparent; touch-action: none; }
    #nk-chip { left: 50%; bottom: max(14px, env(safe-area-inset-bottom)); transform: translateX(-50%); display: none; align-items: center; gap: 8px;
      height: 44px; padding: 0 18px; border-radius: 22px; border: 1px solid rgba(144,184,248,.7); background: rgba(8,12,24,.82);
      letter-spacing: .08em; box-shadow: 0 0 14px rgba(144,184,248,.35); }
    #nk-chip.on { display: flex; } #nk-chip:active { transform: translateX(-50%) scale(.97); }
    #nk-chip svg { width: 20px; height: 20px; fill: none; stroke: currentColor; stroke-width: 1.8; stroke-linecap: round; }
    #nk { left: 0; right: 0; bottom: 0; display: none; flex-direction: column; gap: 5px;
      padding: 8px max(8px, env(safe-area-inset-right)) max(8px, env(safe-area-inset-bottom)) max(8px, env(safe-area-inset-left));
      background: linear-gradient(180deg, rgba(10,16,32,.9), rgba(4,6,14,.97)); border-top: 1px solid rgba(144,184,248,.45); }
    #nk.on { display: flex; }
    #nk .r { display: flex; gap: 5px; justify-content: center; }
    #nk .k { flex: 1 1 0; max-width: 76px; height: clamp(34px, 10.5vh, 46px); display: flex; align-items: center; justify-content: center;
      border-radius: 7px; border: 1px solid rgba(144,184,248,.28); background: rgba(144,184,248,.1); font-size: 17px;
      transition: transform .1s ease-out, background .1s ease-out; }
    #nk .k.w { flex: 1.6 1 0; max-width: 124px; font-size: 13px; letter-spacing: .06em; }
    #nk .k.sp { flex: 4 1 0; max-width: 300px; }
    #nk .k.go { background: rgba(144,184,248,.85); color: #060a16; border-color: transparent; }
    #nk .k.on, #nk .k.lock { background: rgba(144,184,248,.5); transform: scale(.97); }
    #nk .k.go.on { background: #fff; }
    @media (prefers-reduced-motion: reduce) { #nk .k { transition: none; } }`;
  document.head.appendChild(css);

  const chip = document.createElement('div');
  chip.id = 'nk-chip';
  chip.setAttribute('role', 'button');
  chip.innerHTML = '<svg viewBox="0 0 24 24"><rect x="2.5" y="6" width="19" height="12" rx="2"/><path d="M6 10h.01M10 10h.01M14 10h.01M18 10h.01M7 14h10"/></svg>TECLADO';
  const kb = document.createElement('div');
  kb.id = 'nk';
  const rows = ['1234567890', 'QWERTYUIOP', 'ASDFGHJKL', 'ZXCVBNM'];
  const cell = (label, k, cls = '') => `<div class="k ${cls}" data-k="${k}">${label}</div>`;
  kb.innerHTML = rows.map((r, i) => `<div class="r">${i === 3 ? cell('abc', 'case', 'w') : ''}${[...r].map(c => cell(c, c)).join('')}${i === 3 ? cell('BORRAR', 'Backspace', 'w') : ''}</div>`).join('')
    + `<div class="r">${cell('CERRAR', 'close', 'w')}${cell('', 'Space', 'sp')}${cell('LISTO', 'Enter', 'w go')}</div>`;
  document.body.append(chip, kb);

  // Typing: a queue, so fast taps keep their order and every key is released before the next one goes down.
  // Capitals go through Caps Lock (host/input.c input_char_of flips A-Z on its toggle), switched while the keys are open: a Shift
  // held around one letter is lost when the game reads the letter and the Shift release in one batch (a slow frame gave "Full").
  let q = Promise.resolve(), upper = true, caps = false;
  const later = ms => new Promise(r => setTimeout(r, ms));
  const tap = d => {
    q = q.then(async () => {
      input.key(d, true);
      await later(NAMEKEYS_HOLD_MS);
      input.key(d, false);
      await later(NAMEKEYS_GAP_MS);
    });
    return q;
  };
  const up = () => (window.RN_FE || []).includes(NAMEKEYS_SCREEN);
  const isOpen = () => kb.classList.contains('on');
  const sync = () => { if (caps !== (isOpen() && upper)) { caps = !caps; tap(DIK.CapsLock); } };
  const setCase = u => {
    upper = u;
    for (const el of kb.querySelectorAll('.k')) if (/^[A-Z]$/.test(el.dataset.k)) el.textContent = u ? el.dataset.k : el.dataset.k.toLowerCase();
    kb.querySelector('[data-k=case]').textContent = u ? 'abc' : 'ABC';
    sync();
  };
  const open = on => { kb.classList.toggle('on', on); chip.classList.toggle('on', !on && up()); sync(); };

  kb.addEventListener('pointerdown', e => {
    e.preventDefault(); e.stopPropagation();
    const el = e.target.closest('.k');
    if (!el) return;
    el.classList.add('on'); setTimeout(() => el.classList.remove('on'), 130);
    navigator.vibrate?.(6);
    const k = el.dataset.k;
    if (k === 'close') open(false);
    else if (k === 'case') setCase(!upper);
    else if (k === 'Enter') { tap(DIK.Enter); open(false); }
    else if (k === 'Backspace' || k === 'Space') tap(DIK[k]);
    else if (/^\d$/.test(k)) tap(DIK['Digit' + k]);
    else tap(DIK['Key' + k]);
  });
  chip.addEventListener('pointerdown', e => { e.preventDefault(); e.stopPropagation(); open(true); });
  // The chip follows the screen; leaving the screen closes the keys.
  addEventListener('rn-fe', () => { if (!up()) open(false); else if (!isOpen()) chip.classList.add('on'); });
  window.RN_NAMEKEYS = { open, tap };
  return window.RN_NAMEKEYS;
}
