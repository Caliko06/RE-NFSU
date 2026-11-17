// Launcher sound (WebAudio). window.RN_SND = { play(name), toggle(), set(on), isOn(), fadeOut(ms), onChange(cb) }.
// Files (same origin): launcher/v2/sfx/{move,accept,back,tab}.ogg. A missing file is never an error: the UI sounds fall back to
// a tiny synthesized tick. No background loop (OWNER 2026-11-17: the rain and idle engine bed is gone). Master gain 0.06, never above 0.1.
// Browsers start audio only after a user gesture: the context is made on the first pointer/key/touch (or pad button) press.
// State is remembered in localStorage 'rn_launch_snd' ('0' = off, anything else = on).
(() => {
  'use strict';
  const KEY = 'rn_launch_snd', MASTER = 0.06, CAP = 0.1, BASE = 'launcher/v2/sfx/';
  const LEVEL = { move: 1, accept: 1, back: 1, tab: 1 };
  const store = {
    get() { try { return localStorage.getItem(KEY) !== '0'; } catch { return true; } },
    set(on) { try { localStorage.setItem(KEY, on ? '1' : '0'); } catch {} },
  };
  let on = store.get(), ctx = null, master = null, started = false;
  const raw = {}, bufs = {}, subs = [];
  const gainValue = () => Math.min(CAP, on ? MASTER : 0);

  // Start fetching the files now (plain network reads, no context needed); decode once the context exists.
  for (const n of Object.keys(LEVEL)) {
    raw[n] = fetch(BASE + n + '.ogg').then(r => (r.ok ? r.arrayBuffer() : null)).catch(() => null);
  }

  async function decodeAll() {
    for (const n of Object.keys(LEVEL)) {
      const ab = await raw[n];
      if (!ab || !ctx) continue;
      try { bufs[n] = await ctx.decodeAudioData(ab.slice(0)); } catch { /* bad file: stay on the fallback */ }
    }
  }

  function init() {
    if (started) return;
    started = true;
    try {
      const AC = window.AudioContext || window.webkitAudioContext;
      if (!AC) return;
      ctx = new AC({ latencyHint: 'interactive' });
      master = ctx.createGain();
      master.gain.value = gainValue();
      master.connect(ctx.destination);
      ctx.resume().catch(() => {});
      decodeAll();
    } catch { ctx = null; }
  }
  for (const ev of ['pointerdown', 'keydown', 'touchend']) addEventListener(ev, init, { passive: true, capture: true });
  document.addEventListener('visibilitychange', () => {
    if (!ctx) return;
    if (document.hidden) ctx.suspend().catch(() => {}); else if (on) ctx.resume().catch(() => {});
  });

  // Fallback ticks: short, soft, in the same family as the FE clicks.
  const SYN = {
    move: [[1250, 900, 0.045, 'sine', 0.5]],
    tab: [[900, 1100, 0.05, 'triangle', 0.5]],
    accept: [[620, 880, 0.07, 'triangle', 0.55], [880, 1320, 0.09, 'sine', 0.45, 0.06]],
    back: [[700, 420, 0.09, 'triangle', 0.5]],
  };
  function synth(name) {
    const parts = SYN[name];
    if (!parts) return;
    const t0 = ctx.currentTime;
    for (const [f0, f1, dur, type, vol, delay = 0] of parts) {
      const o = ctx.createOscillator(), g = ctx.createGain(), t = t0 + delay;
      o.type = type;
      o.frequency.setValueAtTime(f0, t); o.frequency.exponentialRampToValueAtTime(f1, t + dur);
      g.gain.setValueAtTime(0.0001, t); g.gain.exponentialRampToValueAtTime(vol, t + 0.006); g.gain.exponentialRampToValueAtTime(0.0001, t + dur + 0.03);
      o.connect(g).connect(master);
      o.start(t); o.stop(t + dur + 0.05);
    }
  }

  function play(name) {
    if (!on || !ctx || ctx.state === 'closed') return;
    if (ctx.state === 'suspended') ctx.resume().catch(() => {});
    const b = bufs[name];
    if (!b) { synth(name); return; }
    const src = ctx.createBufferSource(), g = ctx.createGain();
    src.buffer = b; g.gain.value = LEVEL[name] || 1;
    src.connect(g).connect(master);
    src.start();
  }

  function set(v) {
    on = !!v;
    store.set(on);
    if (ctx) {
      master.gain.setTargetAtTime(gainValue(), ctx.currentTime, 0.04);
      if (on) ctx.resume().catch(() => {});
    }
    for (const f of subs) { try { f(on); } catch {} }
  }

  window.RN_SND = {
    play, set,
    toggle() { set(!on); return on; },
    isOn: () => on,
    onChange: f => { subs.push(f); },
    init,
    state: () => ({ on, ctx: ctx ? ctx.state : 'none', gain: master ? +master.gain.value.toFixed(3) : 0, files: Object.keys(bufs) }),
    fadeOut(ms = 500) { if (ctx && master) master.gain.setTargetAtTime(0, ctx.currentTime, ms / 3000); },
  };
})();
