// Mode: one address (5180) for everything. 'remaster' (default) = every bridge and effect we added; 'original' = the
// game as Speed.exe ships it, for A/B. F4 asks, F4 again within 3 s switches and reloads (most switches are read at boot).
// The choice is kept in this browser. A ?key=value in the URL still wins over the mode (tests, webcheck).
// RN_Q replaces new URLSearchParams(location.search) in every page script.
const RN_ORIGINAL = {
  remaster: '0',      // texture pack (world and cars), web/gpu.js
  skinhd: '0',        // HD car skin composite, web/gpu.js
  bloom: '0', fxaa: '0', sharp: 'off', aniso: '1',
  carlook: '2003',    // host/sm1.c: car.efx at the shipped strength
  cardetail: '0',     // host/sm1.c: no AO/grime terms
  handling: '0',      // host/rivals.c: the shipped rear grip assist
  trafyield: '0',     // host/rivals.c: traffic never sees a car closing from behind
  ai: '0',            // host/rivals.c: rival personalities off, the shipped skill records
  speedfov: '0',      // web/tune.js, host/d3d9.c: the chase camera's FOV stays at the shipped 71.5 deg
  chasecam: '0',      // web/tune.js, host/d3d9.c: the chase camera keeps the car's shipped distance and height rows
  nitrocam: '0',      // web/tune.js, host/d3d9.c: no extra pull-back while the nitrous burns
  roadrefl: 'game',   // host/sm1.c: the road reflection as worldreflect.efx weights it
};   // blur: web/tune.js starts the original mode at 'PC original' (shipped blur and flare colour)
// Native switches of the same mode (host/: traffic pool and pace, rivals, car smoothing, HUD places, night lights, free mode).
const RN_ORIGINAL_ENV = { RN_TRAFFIC: '0', RN_RIVALS: '0', RN_SMOOTH: '0', RN_HUD: '43', RN_LIGHTS: '0', RN_CARLOD: '0', RN_FREE: '0', RN_WORLDROW: '0', RN_TRAFPAINT: '0', RN_TRAFLEAN: '0', RN_FEEL: '0', RN_WALLSOFTEN: '0', RN_NPCSMOOTH: '0', RN_MC: '0' };

// ?mode=original|remaster: one run in that mode without touching the stored choice (tools/webcheck.mjs).
const RN_MODE = (() => {
  const q = new URLSearchParams(location.search).get('mode');
  if (q === 'original' || q === 'remaster') return q;
  // Default remaster (OWNER 2026-11-10: the UG2 city lives in Free Run's WORLD row, which original mode turns off); original only when picked.
  try { return localStorage.getItem('rn_mode') === 'original' ? 'original' : 'remaster'; } catch { return 'remaster'; }
})();
// Degradation switches for weaker devices (OWNER 2026-11-02: accepted, each a switch, off by default):
// ?fx=0: the remaster's visual effects off (texture pack, HD skins, bloom, FXAA, sharpen, aniso, car and road shader
//        terms back to the shipped ones); the remaster's gameplay and camera keys stay. ?fps=30: host RN_FPS (frame pacer).
const RN_FX_OFF = ['remaster', 'skinhd', 'bloom', 'fxaa', 'sharp', 'aniso', 'carlook', 'cardetail', 'roadrefl'];
const RN_Q = (() => {
  const q = new URLSearchParams(location.search);
  if (RN_MODE === 'original') for (const [k, v] of Object.entries(RN_ORIGINAL)) if (!q.has(k)) q.set(k, v);
  if (q.get('fx') === '0') for (const k of RN_FX_OFF) if (!q.has(k)) q.set(k, RN_ORIGINAL[k]);
  // Coarse pointer (iPad, phone): 30 fps unless ?fps= says otherwise (host RN_FPS, web/boot.js)
  if (!q.has('fps') && matchMedia('(pointer: coarse)').matches) q.set('fps', '30');
  return q;
})();
// WORLD asked for in the URL (?pool=1 opens the WORLD row of Free Run, ?world=1 shows it): the only way Original mode gets the UG2 city
// (web/boot.js turns the WORLD row on, web/ug2/ug2world.js draws it, and only while the game's track id is 1010). Original without it is as shipped.
const RN_WORLD = RN_Q.get('pool') === '1' || RN_Q.get('world') === '1';

(() => {
  const toast = document.createElement('div');
  Object.assign(toast.style, { position: 'fixed', left: '50%', top: '44px', transform: 'translateX(-50%)', padding: '6px 14px',
    background: 'rgba(0,0,0,0.75)', color: '#ffd479', font: '14px system-ui, sans-serif', borderRadius: '6px',
    pointerEvents: 'none', display: 'none', zIndex: 10 });
  const show = (s, ms) => { toast.textContent = s; toast.style.display = 'block'; clearTimeout(show.t); show.t = setTimeout(() => toast.style.display = 'none', ms); };
  window.rnToast = show;
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
