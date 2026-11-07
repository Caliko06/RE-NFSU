// Launcher sound (WebAudio). window.RN_SND = { play(name), rev(), toggle(), set(on), isOn(), fadeOut(ms), onChange(cb) }.
// Files (same origin): launcher/v2/sfx/{move,accept,back,tab,idle,rain}.ogg. A missing file is never an error: the four UI
// sounds fall back to a tiny synthesized tick, idle/rain stay silent. Master gain 0.06, never above 0.1.
// Browsers start audio only after a user gesture: the context is made on the first pointer/key/touch (or pad button) press.
// State is remembered in localStorage 'rn_launch_snd' ('0' = off, anything else = on).
(() => {
  'use strict';
  const KEY = 'rn_launch_snd', MASTER = 0.06, CAP = 0.1, BASE = 'launcher/v2/sfx/';
  const LEVEL = { move: 1, accept: 1, back: 1, tab: 1, idle: 0.55, rain: 0.4 };
  const store = {
    get() { try { return localStorage.getItem(KEY) !== '0'; } catch { return true; } },
    set(on) { try { localStorage.setItem(KEY, on ? '1' : '0'); } catch {} },
  };
  let on = store.get(), ctx = null, master = null, loops = null, started = false;
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
    if (on) startLoops();
  }

  function startLoops() {
    if (loops || !ctx || !bufs.idle && !bufs.rain) return;
    loops = {};
    const mk = (name, level) => {
      if (!bufs[name]) return null;
      const src = ctx.createBufferSource(), g = ctx.createGain();
      src.buffer = bufs[name]; src.loop = true;
      g.gain.value = 0;
      src.connect(g).connect(master);
      src.start();
      g.gain.setTargetAtTime(level, ctx.currentTime + 0.05, 0.8);        // fade in over ~2 s
      return { src, g, level };
    };
    loops.idle = mk('idle', LEVEL.idle);
    loops.rain = mk('rain', LEVEL.rain);
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

  // Accept revs the idle engine: pitch up fast, settle back slowly.
  function rev() {
    if (!on || !ctx || !loops || !loops.idle) return;
    const { src, g, level } = loops.idle, t = ctx.currentTime;
    src.playbackRate.cancelScheduledValues(t);
    src.playbackRate.setValueAtTime(src.playbackRate.value, t);
    src.playbackRate.linearRampToValueAtTime(1.75, t + 0.16);
    src.playbackRate.exponentialRampToValueAtTime(1, t + 0.95);
    g.gain.cancelScheduledValues(t);
    g.gain.setValueAtTime(g.gain.value, t);
    g.gain.linearRampToValueAtTime(level * 1.8, t + 0.16);
    g.gain.linearRampToValueAtTime(level, t + 0.95);
  }

  function set(v) {
    on = !!v;
    store.set(on);
    if (ctx) {
      master.gain.setTargetAtTime(gainValue(), ctx.currentTime, 0.04);
      if (on) { ctx.resume().catch(() => {}); startLoops(); }
    }
    for (const f of subs) { try { f(on); } catch {} }
  }

  window.RN_SND = {
    play, rev, set,
    toggle() { set(!on); return on; },
    isOn: () => on,
    onChange: f => { subs.push(f); },
    init,
    state: () => ({ on, ctx: ctx ? ctx.state : 'none', gain: master ? +master.gain.value.toFixed(3) : 0, files: Object.keys(bufs), loops: loops ? Object.keys(loops).filter(k => loops[k]) : [] }),
    fadeOut(ms = 500) { if (ctx && master) master.gain.setTargetAtTime(0, ctx.currentTime, ms / 3000); },
  };
})();
