// Mode: one address (5180) for everything. 'remaster' (default) = every bridge and effect we added; 'original' = the
// game as Speed.exe ships it, for A/B. F4 asks, F4 again within 3 s switches and reloads (most switches are read at boot).
// The choice is kept in this browser. A ?key=value in the URL still wins over the mode (tests, webcheck).
// RN_Q replaces new URLSearchParams(location.search) in every page script.
const RN_ORIGINAL = {
  remaster: '0',      // texture pack (world and cars), web/gpu.js
  skinhd: '0',        // HD car skin composite, web/gpu.js
  bloom: '0', fxaa: '0', grade: '0', sharp: 'off', aniso: '1',
  carlook: '2003',    // host/sm1.c: car.efx at the shipped strength
  cardetail: '0',     // host/sm1.c: no AO/grime terms
  carvol: '0',        // host/sm1.c: no volume / panel-edge terms on the diffuse
  carpack: '0',       // host/sm1.c, host/lights.c, web/gpu.js: no car look pack (paint gain, HD layer skins, held lamps)
  speedfov: '0',      // web/tune.js, host/d3d9.c: the chase camera's FOV stays at the shipped 71.5 deg
  chasecam: '0',      // web/tune.js, host/d3d9.c: the chase camera keeps the car's shipped distance and height rows
  nitrocam: '0',      // web/tune.js, host/d3d9.c: no extra pull-back while the nitrous burns
  shadows: '0',       // web/tune.js, host/d3d9.c, web/gpu.js: the game's own flat car decal, no shadow map
  roadrefl: 'game',   // host/sm1.c: the road reflection as worldreflect.efx weights it
};   // blur: web/tune.js starts the original mode at 'PC original' (shipped blur and flare colour)
// Native switches of the same mode (host/: traffic pool and pace, rivals, car smoothing, HUD places, night lights, free mode).
const RN_ORIGINAL_ENV = { RN_TRAFFIC: '0', RN_RIVALS: '0', RN_SMOOTH: '0', RN_HUD: '43', RN_LIGHTS: '0', RN_CARLOD: '0', RN_FREE: '0' };

// ?mode=original|remaster: one run in that mode without touching the stored choice (tools/webcheck.mjs).
const RN_MODE = (() => {
  const q = new URLSearchParams(location.search).get('mode');
  if (q === 'original' || q === 'remaster') return q;
  try { return localStorage.getItem('rn_mode') === 'original' ? 'original' : 'remaster'; } catch { return 'remaster'; }
})();
const RN_Q = (() => {
  const q = new URLSearchParams(location.search);
  if (RN_MODE === 'original') for (const [k, v] of Object.entries(RN_ORIGINAL)) if (!q.has(k)) q.set(k, v);
  return q;
})();

(() => {
  const toast = document.createElement('div');
  Object.assign(toast.style, { position: 'fixed', left: '50%', top: '44px', transform: 'translateX(-50%)', padding: '6px 14px',
    background: 'rgba(0,0,0,0.75)', color: '#ffd479', font: '14px system-ui, sans-serif', borderRadius: '6px',
    pointerEvents: 'none', display: 'none', zIndex: 10 });
  const show = (s, ms) => { toast.textContent = s; toast.style.display = 'block'; clearTimeout(show.t); show.t = setTimeout(() => toast.style.display = 'none', ms); };
  addEventListener('DOMContentLoaded', () => {
    document.body.appendChild(toast);
    show(RN_MODE === 'original' ? 'Modo ORIGINAL (2003)   ·   F4 = Remaster' : 'Modo Remaster   ·   F4 = Original', 2500);
  });
  let armed = 0;
  // Capture phase on window: the canvas (web/input.js) never sees F4, so the game does not get it.
  addEventListener('keydown', e => {
    if (e.code !== 'F4') return;
    e.preventDefault(); e.stopPropagation();
    if (e.repeat) return;
    const next = RN_MODE === 'original' ? 'remaster' : 'original';
    if (performance.now() - armed > 3000) {
      armed = performance.now();
      show(`F4 otra vez: cambiar a ${next === 'original' ? 'ORIGINAL (2003)' : 'Remaster'} (el juego reinicia)`, 3000);
      return;
    }
    try { localStorage.setItem('rn_mode', next); } catch {}
    show('Reiniciando…', 5000);
    setTimeout(() => location.reload(), 150);
  }, true);
  addEventListener('keyup', e => { if (e.code === 'F4') { e.preventDefault(); e.stopPropagation(); } }, true);
})();
