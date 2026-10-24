// Blur bank: presets for the game's own motion blur (0x40cd40). host/d3d9.c tune_apply copies the 4 floats into its .data
// (ramp start/end m/s 0x702a38/0x702a3c, cap of t 0x702a40, streak length 0x702a44) at the next Present.
// ?blur=0..5 picks one; F6 / F7 step down / up in game (the game maps neither key). The choice is kept in this browser.
// Composite alpha at full speed = min(1.5 cap, 1). PC original: 25 -> 125 m/s, cap 0.65; PS2 ramp 0.1 -> 25 m/s
// (SLUS_208.11 0x4ff95c/0x4ff960), strongest PS2 copy alpha 50/128 (0x4485f0) = cap 0.26.
const BLUR = [
  { name: 'off',          ramp: [0.1, 25], cap: 0 },
  { name: 'light',        ramp: [0.1, 25], cap: 0.10 },
  { name: 'medium',       ramp: [0.1, 25], cap: 0.18 },
  { name: 'PS2',          ramp: [0.1, 25], cap: 0.26 },
  { name: 'strong',       ramp: [0.1, 25], cap: 0.45 },
  { name: 'PC original',  ramp: [25, 125], cap: 0.65 },
];
const BLUR_DEFAULT = 2;
const STREAK = 0.00625;     // 0x702a44 as shipped

function startTune(M) {
  const base = M._rn_tune_addr() >> 2;
  const f = new Float32Array(1), u = new Uint32Array(f.buffer);
  const bits = x => (f[0] = x, u[0]);
  let level = BLUR_DEFAULT;
  try { const s = localStorage.getItem('rn_blur'); if (s !== null && BLUR[+s]) level = +s; } catch {}
  const q = new URLSearchParams(location.search).get('blur');
  if (q !== null && BLUR[+q]) level = +q;

  const toast = document.createElement('div');
  Object.assign(toast.style, { position: 'fixed', left: '50%', top: '12px', transform: 'translateX(-50%)', padding: '6px 14px',
    background: 'rgba(0,0,0,0.75)', color: '#9fe3ff', font: '14px system-ui, sans-serif', borderRadius: '6px',
    pointerEvents: 'none', display: 'none', zIndex: 10 });
  document.body.appendChild(toast);
  let hide = 0;

  function apply(show) {
    const p = BLUR[level], h = M.HEAPU32;
    h[base + 1] = bits(p.ramp[0]); h[base + 2] = bits(p.ramp[1]); h[base + 3] = bits(p.cap); h[base + 4] = bits(STREAK);
    Atomics.add(h, base, 1);
    try { localStorage.setItem('rn_blur', String(level)); } catch {}
    if (!show) return;
    toast.textContent = `Blur ${level}/${BLUR.length - 1}: ${p.name}   (F6 / F7)`;
    toast.style.display = 'block';
    clearTimeout(hide); hide = setTimeout(() => toast.style.display = 'none', 1500);
  }
  // Capture phase on window: the canvas (web/input.js) never sees F6/F7, so the game does not get them.
  window.addEventListener('keydown', e => {
    if (e.code !== 'F6' && e.code !== 'F7') return;
    e.preventDefault(); e.stopPropagation();
    if (e.repeat) return;
    level = Math.max(0, Math.min(BLUR.length - 1, level + (e.code === 'F7' ? 1 : -1)));
    apply(true);
  }, true);
  window.addEventListener('keyup', e => { if (e.code === 'F6' || e.code === 'F7') { e.preventDefault(); e.stopPropagation(); } }, true);
  apply(false);
}
