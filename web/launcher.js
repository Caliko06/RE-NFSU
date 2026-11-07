// Pre-game launcher v2 (UI). Data comes from window.RN_LAUNCH (web/launcher_opts.js); "Jugar" goes to /?play=1&...
// The scene behind is window.RN_SCENE (web/launcher_3d.js, a module that runs before this one), sound is window.RN_SND (web/launcher_audio.js). Both are optional:
// every call is guarded, so the UI works over a still image and in silence.
// Game font: launcher/v2/ui/game_font.png + game_font.json (BMFont-like: glyph rects + advance; see GF below). When present, labels
// are drawn from it (mask sprites); otherwise the condensed italic system stack in launcher.css is used.
(() => {
  'use strict';
  const $ = id => document.getElementById(id);
  const el = (tag, cls, txt) => { const e = document.createElement(tag); if (cls) e.className = cls; if (txt != null) e.textContent = txt; return e; };
  const eq = (a, b) => String(a) === String(b);
  const clamp = (v, a, b) => Math.max(a, Math.min(b, v));
  const root = document.documentElement, body = document.body;
  // Display copy: noun phrases, neutral Mexican Spanish. The catalog (launcher_opts.js) keeps its own strings; these win when present.
  const COPY = {
    preset: { original: ['Original 2003', 'El juego tal como salió.'], remaster: ['Remaster', 'Texturas y efectos mejorados.'], modesto: ['Ligero', 'Original a 30 fps, sin efectos.'] },
    label: { blur: 'Desenfoque de velocidad' },
    group: { camara: 'Cámara' },
  };
  const MODE_NAME = { original: 'Original 2003', remaster: 'Remaster' };
  const L = window.RN_LAUNCH;
  const ok = !!(L && Array.isArray(L.opts) && Array.isArray(L.presets) && typeof L.query === 'function');
  const scene = (fn, ...a) => { try { const s = window.RN_SCENE; if (s && typeof s[fn] === 'function') return s[fn](...a); } catch (e) { console.warn('RN_SCENE.' + fn, e); } };
  const snd = n => { try { window.RN_SND && window.RN_SND.play(n); } catch {} };
  const store = { get(k, d) { try { const v = localStorage.getItem(k); return v == null ? d : v; } catch { return d; } }, set(k, v) { try { localStorage.setItem(k, v); } catch {} } };
  const wait = ms => new Promise(r => setTimeout(r, ms));

  // ---------- motion switch (default ON, ignores the OS reduce-motion setting) ----------
  let motion = store.get('rn_launch_motion', '1') !== '0';
  const A = (node, frames, opt) => {      // WAAPI; calm mode keeps only opacity and halves the time
    if (!motion) { frames = frames.map(f => { const g = { ...f }; delete g.transform; return g; }); opt = { ...opt, duration: Math.min(opt.duration || 150, 140), delay: Math.min(opt.delay || 0, 60) }; }
    try { return node.animate(frames, opt); } catch { return null; }
  };

  // ---------- the game's font (optional) ----------
  const GF = (() => {
    const g = { ready: false, cbs: [], onReady(f) { if (g.ready) f(); else g.cbs.push(f); }, pending: new Set(), glyphs: null, atlas: null, lh: 0, cap: 0, space: 0 };
    const norm = j => {
      const m = {}; const common = j.common || {};
      const put = (ch, o) => { if (ch == null || !o) return; m[ch] = { x: +o.x, y: +o.y, w: +(o.w ?? o.width), h: +(o.h ?? o.height), ox: +(o.ox ?? o.xo ?? o.xoffset ?? 0), oy: +(o.oy ?? o.yo ?? o.yoffset ?? 0), adv: +(o.adv ?? o.advance ?? o.xadvance ?? (o.w ?? o.width)) }; };
      const src = j.glyphs || j.chars || j;
      if (Array.isArray(src)) for (const o of src) put(o.ch ?? o.char ?? (o.id != null ? String.fromCodePoint(o.id) : null), o);
      else for (const k in src) if (k.length <= 2 && typeof src[k] === 'object') put(k, src[k]);
      g.lh = +(j.lineHeight ?? common.lineHeight ?? j.size ?? j.cell ?? 0); g.base = +(j.base ?? common.base ?? 0);
      return m;
    };
    (async () => {
      try {
        const [jr, img] = await Promise.all([fetch('launcher/v2/ui/game_font.json'), new Promise((res, rej) => { const i = new Image(); i.onload = () => res(i); i.onerror = rej; i.src = 'launcher/v2/ui/game_font.png'; })]);
        if (!jr.ok) return;
        const glyphs = norm(await jr.json());
        if (!Object.keys(glyphs).length) return;
        // make an alpha-only atlas: use the PNG's own alpha, or its brightness when it has none
        const c = el('canvas'); c.width = img.naturalWidth; c.height = img.naturalHeight;
        const x = c.getContext('2d', { willReadFrequently: true }); x.drawImage(img, 0, 0);
        const d = x.getImageData(0, 0, c.width, c.height), px = d.data;
        let hasAlpha = false; for (let i = 3; i < px.length; i += 4) if (px[i] < 250) { hasAlpha = true; break; }
        if (!hasAlpha) for (let i = 0; i < px.length; i += 4) { px[i + 3] = Math.max(px[i], px[i + 1], px[i + 2]); px[i] = px[i + 1] = px[i + 2] = 255; }
        x.putImageData(d, 0, 0);
        g.glyphs = glyphs; g.atlas = c;
        if (!g.lh) g.lh = Math.max(...Object.values(glyphs).map(q => q.oy + q.h));
        g.cap = (glyphs.H || glyphs.E || glyphs.A || { h: g.lh * .7 }).h;
        g.space = (glyphs[' '] && glyphs[' '].adv) || g.cap * .45;
        if (!g.base) g.base = g.lh * .8;
        g.ready = true;
        for (const s of g.pending) g.draw(s);
        g.pending.clear();
        for (const f of g.cbs) f();
        root.classList.add('gfont');
      } catch { /* no game font: the system stack stays */ }
    })();
    g.draw = s => {
      const text = (s._text || '').toUpperCase();
      const S = 1;                                   // atlas pixels are already large enough for a 1080p label
      let w = 0; const gl = ch => g.glyphs[ch] || g.glyphs[ch.toLowerCase()];
      for (const ch of text) { const q = gl(ch); w += q ? q.adv : g.space; }
      if (!w) return;
      const c = el('canvas'); c.width = Math.ceil(w) + 2; c.height = Math.ceil(g.lh) + 2;
      const x = c.getContext('2d'); let cx = 0;
      for (const ch of text) { const q = gl(ch); if (q) { if (q.w > 0 && q.h > 0) x.drawImage(g.atlas, q.x, q.y, q.w, q.h, Math.round(cx + q.ox), Math.round(q.oy), q.w, q.h); cx += q.adv; } else cx += g.space; }
      const hEm = (c.height / g.cap) * 0.72;          // cap height = .72 em, like the system face
      s.style.setProperty('--w', (hEm * c.width / c.height).toFixed(3) + 'em');
      s.style.setProperty('--h', hEm.toFixed(3) + 'em');
      s.style.setProperty('--dy', (((g.lh / 2 - (g.base - g.cap / 2)) / c.height) * hEm).toFixed(3) + 'em');   // centre the capitals, not the line box
      s.style.setProperty('--m', 'url(' + c.toDataURL('image/png') + ')');
      s.classList.add('gf');
    };
    g.apply = s => { if (g.ready) g.draw(s); else g.pending.add(s); };
    return g;
  })();
  const T = text => { const s = el('span', 't', text); s._text = text; GF.apply(s); return s; };
  const setT = (s, text) => { s._text = text; s.textContent = text; s.classList.remove('gf'); GF.apply(s); };

  // ---------- the one sliding light (spring) ----------
  function Light(node, box) {
    node.innerHTML = '<i class="bg"></i><i class="ln t"></i><i class="ln b"></i><span class="chevs"><i></i><i></i><i></i></span><i class="flash"></i>';
    let y = 0, h = 0, vy = 0, vh = 0, ty = 0, th = 0, raf = 0, last = 0, first = true, target = null, lastH = -1;
    const apply = () => {
      node.style.transform = `translate3d(0,${y.toFixed(2)}px,0) scaleY(${(1 + Math.min(Math.abs(vy) * 0.00004, .05)).toFixed(3)})`;
      if (Math.abs(h - lastH) > .4) { node.style.height = h.toFixed(1) + 'px'; lastH = h; }
    };
    const tick = t => {
      const K = motion ? 520 : 800, D = motion ? 31 : 56;       // ~160 ms to arrive, about 5 % overshoot (critical in calm mode)
      const dt = Math.min((t - last) / 1000, .033); last = t;
      const n = Math.max(1, Math.ceil(dt / (1 / 240))), s = dt / n;
      for (let i = 0; i < n; i++) {
        vy += (-K * (y - ty) - D * vy) * s; y += vy * s;
        vh += (-K * (h - th) - D * vh) * s; h += vh * s;
      }
      if (Math.abs(y - ty) < .05 && Math.abs(vy) < .5 && Math.abs(h - th) < .05 && Math.abs(vh) < .5) { y = ty; h = th; vy = vh = 0; raf = 0; apply(); return; }
      apply(); raf = requestAnimationFrame(tick);
    };
    const api = {
      node,
      to(t, snap) {
        target = t; ty = t.offsetTop; th = t.offsetHeight;
        if (first || snap || !th) { y = ty; h = th; vy = vh = 0; apply(); first = false; node.classList.add('on'); return; }
        if (!raf) { last = performance.now(); raf = requestAnimationFrame(tick); }
      },
      resnap() { if (target && target.offsetParent) { ty = target.offsetTop; th = target.offsetHeight; y = ty; h = th; vy = vh = 0; apply(); } },
      press(v) { node.classList.toggle('press', v); },
      hide() { node.classList.remove('on'); first = true; },
    };
    if (window.ResizeObserver) new ResizeObserver(() => api.resnap()).observe(box);
    return api;
  }

  // tube warm-up: a few hard on/off steps, then steady
  function flicker(item) {
    const t = item.querySelector('.t, .lbl') || item;
    if (!motion) { A(t, [{ opacity: .55 }, { opacity: 1 }], { duration: 120 }); return; }
    const s = 'steps(1)';
    t.animate([{ opacity: .12, easing: s }, { opacity: 1, offset: .1, easing: s }, { opacity: .28, offset: .2, easing: s }, { opacity: 1, offset: .33, easing: s },
      { opacity: .6, offset: .46, easing: s }, { opacity: 1, offset: .6, easing: s }, { opacity: .86, offset: .78, easing: s }, { opacity: 1 }], { duration: 320 });
  }

  // ---------- state ----------
  let cur = 'main', going = false, revealed = false, kind = (matchMedia('(hover: none)').matches && matchMedia('(pointer: coarse)').matches) ? 'touch' : 'key';
  const scr = {};                                      // name -> { root, items(), sel, light, onSel(el), onEnter() -> el }
  const names = { main: 'main', presets: 'presets', opts: 'opts', ctrl: 'ctrl' };
  const launchHook = { query: () => 'play=1' };       // build() replaces query() once the catalog is read
  let play = () => launch();

  const setLine = (box, text) => {
    const old = box.querySelector('.dl:last-child');
    if (old && old._v === text) return;
    const nw = el('span', 'dl', text); nw._v = text;
    box.append(nw);
    if (old) {
      A(old, [{ opacity: 1, transform: 'translateY(0)' }, { opacity: 0, transform: 'translateY(-.8rem)' }], { duration: 130, fill: 'forwards' });
      setTimeout(() => old.remove(), 150);
      A(nw, [{ opacity: 0, transform: 'translateY(.9rem)' }, { opacity: 1, transform: 'none' }], { duration: 200, delay: 60, easing: 'cubic-bezier(.16,1,.3,1)', fill: 'backwards' });
    }
  };

  // ---------- selection ----------
  const itemsOf = () => (scr[cur].items ? scr[cur].items() : []);
  function choose(node, o = {}) {
    const sc = scr[cur], list = itemsOf(), i = list.indexOf(node);
    if (i < 0 || sc.sel === node) return;
    if (sc.sel) sc.sel.classList.remove('sel');
    sc.sel = node; node.classList.add('sel');
    if (document.activeElement !== node) node.focus({ preventScroll: true });
    if (sc.light) sc.light.to(node, o.snap);
    if (sc.scrolls) {                                  // keep the row in view (only the list scrolls, never the page)
      const box = node.parentElement, t = node.offsetTop, b = t + node.offsetHeight, beh = motion ? 'smooth' : 'auto';
      if (t < box.scrollTop + 8) box.scrollTo({ top: Math.max(0, t - 8), behavior: beh });
      else if (b > box.scrollTop + box.clientHeight - 8) box.scrollTo({ top: b - box.clientHeight + 8, behavior: beh });
    }
    if (!o.quiet) { flicker(node); snd('move'); }
    if (sc.onSel) sc.onSel(node, o);
    if (!o.noscene) scene('select', i, list.length, cur);
  }
  function step(d) {
    const list = itemsOf(); if (!list.length) return;
    const i = list.indexOf(scr[cur].sel);
    choose(list[i < 0 ? 0 : (i + d + list.length) % list.length]);
  }
  const adj = d => { const s = scr[cur].sel; if (s && s._adj) s._adj(d); else if (cur === 'presets') step(d); };
  const activate = () => { const s = scr[cur].sel; if (!s) { step(0); return; } const lg = scr[cur].light; if (lg) { lg.press(true); setTimeout(() => lg.press(false), 110); } if (s._ok) s._ok(); else if (s._adj) s._adj(1); else s.click(); };
  const tabStep = d => { if (cur === 'opts' && scr.opts.tabStep) { scr.opts.tabStep(d); snd('tab'); } };

  // ---------- screens ----------
  let swapToken = 0;
  function enter(sc, base = 0) {
    // panels/heads first, then the selectable things one after the other (70 ms)
    const r = sc.root, x = 'translateX(-3rem)', e = 'cubic-bezier(.16,1,.3,1)';
    let k = 0;
    for (const n of r.querySelectorAll(':scope > [data-in], :scope > .covers, :scope .tabbar')) { A(n, [{ opacity: 0, transform: x }, { opacity: 1, transform: 'none' }], { duration: 460, delay: base + k * 70, easing: e, fill: 'backwards' }); k++; }
    const ch = [...r.querySelectorAll('.item, .row:not([hidden]), .cover')].slice(0, 10);
    ch.forEach((n, i) => {
      const cover = n.classList.contains('cover');
      A(n, cover ? [{ opacity: 0, transform: 'translateY(5rem) rotate(-3deg) scale(.9)' }, { opacity: 1, transform: n.classList.contains('sel') ? 'translateY(-2.6rem) scale(1.07)' : 'scale(.93)' }] : [{ opacity: 0, transform: x }, { opacity: 1, transform: n.classList.contains('sel') ? 'translateX(1.4rem)' : 'none' }],
        { duration: 480, delay: base + 120 + i * 70, easing: e, fill: 'backwards' });
    });
    if (sc.light) A(sc.light.node, [{ opacity: 0 }, { opacity: 1 }], { duration: 300, delay: base + 120 + ch.length * 40, fill: 'backwards' });
  }
  function show(name, focusEl, o = {}) {
    if (!scr[name] || name === cur && !o.force) return;
    const prev = scr[cur], next = scr[name], tok = ++swapToken;
    for (const k in scr) if (k !== cur && k !== name) scr[k].root.hidden = true;
    A(prev.root, [{ opacity: 1, transform: 'none' }, { opacity: 0, transform: 'translateX(-2rem)' }], { duration: 130, easing: 'ease-in', fill: 'forwards' });
    setTimeout(() => { if (tok === swapToken && prev !== scr[cur]) { prev.root.hidden = true; prev.root.getAnimations().forEach(a => a.cancel()); } }, 140);
    cur = name; body.dataset.screen = name;
    next.root.hidden = false;
    next.root.getAnimations().forEach(a => a.cancel());
    if (next.onShow) next.onShow();
    next.sel = null;
    const list = itemsOf();
    const t = (focusEl && list.includes(focusEl) && focusEl) || (next.onEnter && next.onEnter()) || list[0];
    if (t) choose(t, { snap: true, quiet: true });
    if (next.light) next.light.resnap();
    enter(next, 90);
    scene('screen', names[name]);
    hints();
  }
  const back = () => { if (cur === 'main' || going) return; snd('back'); show('main', document.querySelector(`#s-main [data-go="${cur}"]`)); };

  // main
  scr.main = { root: $('s-main'), items: () => [...$('menu').querySelectorAll('.item:not([hidden])')], light: Light($('menu').querySelector('.light'), $('menu')) };
  scr.main.onSel = n => { const d = n.dataset.desc; setLine(scr.main.root.querySelector('.desc'), d === 'play' ? scr.main.playLine() : d || ''); };
  scr.main.playLine = () => 'Perfil: ' + (scr.main.profile || 'Original 2003') + '.';
  for (const b of $('menu').querySelectorAll('.item')) {
    b.addEventListener('click', () => { if (b.dataset.go) { snd('accept'); show(b.dataset.go); } else if (b.id === 'play') play(); });
  }

  // controls
  scr.ctrl = { root: $('s-ctrl'), items: () => [...$('ctrlList').querySelectorAll('.item')], light: Light($('ctrlList').querySelector('.light'), $('ctrlList')) };
  scr.ctrl.onSel = n => setLine(scr.ctrl.root.querySelector('.desc'), n.dataset.desc || '');
  (() => {
    const k = (s, c = '') => `<kbd class="${c}">${s}</kbd>`, p = (c, t) => `<p>${c}<span>${t}</span></p>`;
    const cols = [
      ['Teclado', [k('Flechas', 'wide'), 'dirección, acelerar y frenar'], [k('Espacio', 'wide'), 'nitro'], [k('Shift', 'wide'), 'freno de mano'], [k('C'), 'cámara'], [k('R'), 'reiniciar el coche'], [k('Esc'), 'pausa y atrás']],
      ['Mando', [k('LS', 'wide'), 'dirección'], [k('RT', 'wide') + k('LT', 'wide'), 'acelerar / frenar'], [k('A', 'pad a'), 'nitro'], [k('B', 'pad b'), 'freno de mano'], [k('Y', 'pad y'), 'cámara'], [k('RB', 'wide'), 'reiniciar el coche'], [k('Start', 'wide'), 'pausa']],
      ['En el juego', [k('F4'), 'Original / Remaster'], [k('K') + k('Select', 'wide'), 'reasignar teclas y botones'], [k('F2'), 'registro del juego'], [k('Táctil', 'wide'), 'controles en pantalla']],
    ];
    $('ctrlGrid').innerHTML = cols.map(c => `<div><h3>${c[0]}</h3>${c.slice(1).map(r => p(r[0], r[1])).join('')}</div>`).join('');
  })();
  $('ctrlList').querySelector('.item').addEventListener('click', back);

  // presets and options (data driven)
  if (ok) build(); else {
    for (const b of document.querySelectorAll('[data-go="presets"], [data-go="opts"]')) b.hidden = true;
    scr.presets = { root: $('s-presets'), items: () => [] }; scr.opts = { root: $('s-opts'), items: () => [] };
  }

  function build() {
    const opts = L.opts, presets = L.presets;
    const modeOpt = opts.find(o => o.id === 'mode' || o.key === 'mode');
    const modeId = modeOpt ? modeOpt.id : 'mode';
    const storedMode = () => store.get('rn_mode', 'original') === 'remaster' ? 'remaster' : 'original';
    const defaults = () => Object.fromEntries(opts.map(o => [o.id, o.def]));
    const valuesOf = o => (o.values && o.values.length) ? o.values : [{ v: '0', label: 'No' }, { v: '1', label: 'Sí' }];
    const valid = (o, v) => v !== undefined && v !== null && valuesOf(o).some(x => eq(x.v, v));
    let sel = (() => {
      let saved = {};
      try { const s = L.load && L.load(); if (s && typeof s === 'object') saved = s; } catch {}
      const s = defaults();
      for (const o of opts) if (valid(o, saved[o.id])) s[o.id] = saved[o.id];
      if (!modeOpt) s[modeId] = saved[modeId] === 'remaster' || saved[modeId] === 'original' ? saved[modeId] : storedMode();
      return s;
    })();
    const mode = () => sel[modeId] === 'remaster' ? 'remaster' : 'original';
    const save = () => { try { L.save && L.save(sel); } catch {} };
    const applies = o => !o.modes || o.modes.includes(mode());
    const presetState = p => { const s = defaults(); if (!modeOpt) s[modeId] = mode(); return Object.assign(s, p.set || {}); };
    const activePreset = () => presets.find(p => { const s = presetState(p); return Object.keys(s).every(k => eq(s[k], sel[k])); });
    const setOpt = (id, v, dir) => { sel[id] = v; save(); refresh(dir); };
    function pickPreset(p) {
      const prev = sel[modeId];
      sel = defaults();
      if (!modeOpt) sel[modeId] = prev;
      Object.assign(sel, p.set || {});
      save(); refresh(0);
    }
    function reset() { sel = defaults(); if (!modeOpt) sel[modeId] = 'original'; save(); refresh(0); }

    // ---- presets: magazine covers ----
    const MAG = ['mag_01_dub_clocktower', 'mag_03_turbo_neon', 'mag_02_scc_chinatown'], MAGOF = { original: 0, remaster: 1, modesto: 2 }, MAGB = [1.3, 1, 1.5];   // MAGB: per-cover exposure (the SCC cover is very dark)
    const covBox = $('covers'), track = el('div', 'track'), presetLine = $('presetLine');
    covBox.append(track);
    const cards = presets.map((p0, i) => {
      const cp = COPY.preset[p0.id], p = cp ? { ...p0, label: cp[0], desc: cp[1] } : p0;
      const c = el('div', 'cover'); c.tabIndex = 0; c.setAttribute('role', 'radio'); c.setAttribute('aria-label', p.label + '. ' + (p.desc || ''));
      const tilt = el('div', 'tilt'), img = new Image();
      img.src = `launcher/v2/ui/${MAG[MAGOF[p.id] ?? (i % MAG.length)]}.webp`; img.alt = ''; img.draggable = false; img.width = 340; img.height = 452; img.style.filter = `brightness(${MAGB[MAGOF[p.id] ?? (i % MAG.length)]})`;
      const clip = el('div', 'clip'); clip.append(el('i', 'shine'));
      tilt.append(img, clip, el('i', 'dimmer'));
      const strip = el('div', 'strip'); strip.style.setProperty('--len', p.label.length); strip.append(el('i', 'mk'), T(p.label));
      const badge = el('span', 'badge', 'Activo'); badge.hidden = true;
      c.append(tilt, strip, badge);
      c._ok = () => { pickPreset(p); snd('accept'); show('main', $('play')); };
      c._adj = d => step(d);
      c.addEventListener('click', () => { if (scr.presets.sel === c) c._ok(); else choose(c); });
      c.addEventListener('focus', () => choose(c));
      track.append(c);
      return { p: p0, shown: p, c, tilt, badge };
    });
    let centers = [];
    const place = () => {
      const bw = covBox.clientWidth, tw = track.scrollWidth, s = scr.presets.sel;
      let sh = bw * .56 - tw / 2;
      if (bw < 1500) sh = (bw - tw) / 2;
      if (tw > bw && s) sh = bw / 2 - (s.offsetLeft + s.offsetWidth / 2);
      track.style.transform = `translate3d(${sh.toFixed(1)}px,0,0)`;
      centers = cards.map(x => { const r = x.c.getBoundingClientRect(); return [r.left + r.width / 2, r.top + r.height / 2, r.width, r.height]; });
    };
    scr.presets = { root: $('s-presets'), items: () => cards.map(x => x.c) };
    scr.presets.onSel = n => { const x = cards.find(q => q.c === n); setLine(presetLine, x ? x.shown.desc || '' : ''); place(); setTimeout(place, 520); };
    scr.presets.onEnter = () => { const a = activePreset(), x = cards.find(q => q.p === a); return x ? x.c : null; };
    scr.presets.onShow = () => requestAnimationFrame(place);
    addEventListener('resize', () => { if (cur === 'presets') place(); });
    // covers tilt toward the cursor (all of them, by their own centre)
    let px = -1e4, py = -1e4, tiltRaf = 0;
    const tiltAll = () => {
      tiltRaf = 0;
      if (cur !== 'presets' || !motion) return;
      cards.forEach((x, i) => {
        const cc = centers[i]; if (!cc) return;
        const dx = clamp((px - cc[0]) / (cc[2] * 2.2), -1, 1), dy = clamp((py - cc[1]) / (cc[3] * 1.6), -1, 1);
        x.tilt.style.transform = `rotateY(${(dx * 13).toFixed(2)}deg) rotateX(${(-dy * 10).toFixed(2)}deg)`;
      });
    };
    addEventListener('pointermove', e => { if (e.pointerType === 'touch' || cur !== 'presets') return; px = e.clientX; py = e.clientY; if (!tiltRaf) tiltRaf = requestAnimationFrame(tiltAll); });
    for (const x of cards) x.tilt.style.transition = 'transform .18s ease-out';

    // ---- options ----
    const groups = (L.groups || []).slice();
    for (const o of opts) if (!groups.some(g => g.id === o.group)) groups.push({ id: o.group, title: o.group, desc: '' });
    const used = groups.filter(g => opts.some(o => o.group === g.id));
    let tab = used.length ? used[0].id : null;
    const tabsBox = $('tabs'), listBox = $('optList'), tabline = tabsBox.querySelector('.tabline'), optsRoot = $('s-opts');
    const tabBtns = used.map(g => {
      const gt = COPY.group[g.id] || g.title, b = el('button'); b.append(T(gt)); b.setAttribute('aria-label', gt);
      b.type = 'button'; b.tabIndex = -1; b.setAttribute('role', 'tab');
      b.addEventListener('click', () => { if (g.id !== tab) { setTab(g.id); snd('tab'); } });
      tabsBox.append(b);
      return { g, b };
    });
    const setTab = id => {
      if (id === tab && scr.opts.ready) return;
      const dir = used.findIndex(g => g.id === id) - used.findIndex(g => g.id === tab);
      tab = id; scr.opts.ready = true;
      refresh(0);
      listBox.scrollTop = 0;
      const first = itemsFor()[0];
      scr.opts.sel = null;
      if (first) choose(first, { snap: true, quiet: true });
      for (const [i, r] of itemsFor().slice(0, 9).entries()) A(r, [{ opacity: 0, transform: `translateX(${dir >= 0 ? 3 : -3}rem)` }, { opacity: 1, transform: r.classList.contains('sel') ? 'translateX(1rem)' : 'none' }], { duration: 360, delay: i * 35, easing: 'cubic-bezier(.16,1,.3,1)', fill: 'backwards' });
      placeTab();
    };
    const placeTab = () => {
      const t = tabBtns.find(x => x.g.id === tab); if (!t) return;
      tabBtns.forEach(x => x.b.setAttribute('aria-selected', String(x === t)));
      tabline.style.transform = `translate(${t.b.offsetLeft}px, ${t.b.offsetTop + t.b.offsetHeight - tabline.offsetHeight}px) scaleX(${(t.b.offsetWidth / 10).toFixed(3)})`;
      if (tabsBox.scrollWidth > tabsBox.clientWidth + 2) {      // phone: one scrolling row
        const want = t.b.offsetLeft + t.b.offsetWidth / 2 - tabsBox.clientWidth / 2;
        tabsBox.scrollTo({ left: clamp(want, 0, tabsBox.scrollWidth), behavior: motion ? 'smooth' : 'auto' });
      }
    };
    const tabStepFn = d => { const i = Math.max(0, used.findIndex(g => g.id === tab)); setTab(used[(i + d + used.length) % used.length].id); };
    for (const b of optsRoot.querySelectorAll('.bump')) b.addEventListener('click', () => { tabStepFn(+b.dataset.tab); snd('tab'); });

    const rows = opts.map(o => {
      const vals = valuesOf(o);
      const row = el('div', 'row'); row.tabIndex = 0; row.setAttribute('role', 'spinbutton'); row.setAttribute('aria-label', COPY.label[o.id] || o.label);
      const lname = COPY.label[o.id] || o.label;
      const lbl = T(lname); lbl.classList.add('lbl');
      const val = el('span', 'val'), vv = el('span', 'vv');
      const mkArr = (dir, name) => {
        const a = el('button', 'arr ' + (dir < 0 ? 'l' : 'r')); a.type = 'button'; a.tabIndex = -1; a.setAttribute('aria-label', name);
        a.addEventListener('mousedown', e => e.preventDefault());
        a.addEventListener('click', e => { e.stopPropagation(); choose(row); row._adj(dir); });
        return a;
      };
      const al = mkArr(-1, 'Anterior'), ar = mkArr(1, 'Siguiente');
      val.append(al, vv, ar);
      row.append(lbl, val);
      row._adj = d => {
        const i = Math.max(0, vals.findIndex(x => eq(x.v, sel[o.id])));
        const bt = (d < 0 ? al : ar); bt.classList.remove('bump-l', 'bump-r'); void bt.offsetWidth; bt.classList.add(d < 0 ? 'bump-l' : 'bump-r');
        snd('tab');
        setOpt(o.id, vals[(i + d + vals.length) % vals.length].v, d);
      };
      row.addEventListener('focus', () => choose(row));
      row.addEventListener('click', e => { if (!e.target.closest('.arr')) { choose(row); row._adj(1); } });
      listBox.append(row);
      return { o, row, vv, vals, cur: null };
    });
    // In Original mode the Remaster-only options are not drawn as a wall of dead rows: one row per group stands for them.
    const moreRow = el('div', 'row more'); moreRow.tabIndex = 0; moreRow.setAttribute('role', 'button');
    const mlbl = T('Mejoras del Remaster'); mlbl.classList.add('lbl');
    moreRow.append(mlbl, el('span', 'tag', 'Solo Remaster'));
    moreRow._ok = () => { if (!modeOpt) return; sel[modeId] = 'remaster'; save(); snd('accept'); scr.opts.sel = null; refresh(1); const f = itemsFor()[0]; if (f) choose(f, { snap: true, quiet: true }); };
    moreRow.addEventListener('click', () => { choose(moreRow); moreRow._ok(); });
    moreRow.addEventListener('focus', () => choose(moreRow));
    listBox.append(moreRow);
    const resetRow = el('div', 'row reset'); resetRow.tabIndex = 0; resetRow.setAttribute('role', 'button');
    resetRow.append(T('Restablecer valores'));
    resetRow.firstChild.classList.add('lbl');
    resetRow._ok = () => { reset(); snd('accept'); resetRow.classList.remove('nope'); };
    resetRow.addEventListener('click', () => { choose(resetRow); resetRow._ok(); });
    resetRow.addEventListener('focus', () => choose(resetRow));
    listBox.append(resetRow);
    const rowsFor = () => rows.filter(r => r.o.group === tab && applies(r.o));
    const hasNa = () => rows.some(r => r.o.group === tab && !applies(r.o));
    const itemsFor = () => [...rowsFor().map(r => r.row), ...(hasNa() ? [moreRow] : []), resetRow];
    scr.opts = { root: optsRoot, items: itemsFor, light: Light(listBox.querySelector('.light'), listBox), scrolls: true, tabStep: tabStepFn };
    scr.opts.onEnter = () => itemsFor()[0];
    scr.opts.onShow = () => requestAnimationFrame(() => { placeTab(); fit(); });
    scr.opts.onSel = n => {
      const r = rows.find(x => x.row === n);
      const txt = n === resetRow ? 'Todo vuelve a su valor de fábrica.' : n === moreRow ? 'Se abren en modo Remaster. Enter lo activa.' : (r.o.help || '');
      setLine(optsRoot.querySelector('.desc'), txt);
    };
    scr.opts.ready = false;
    addEventListener('resize', () => { if (cur === 'opts') placeTab(); });

    function refresh(dir) {
      const act = activePreset();
      for (const { p, c, badge } of cards) { c.setAttribute('aria-checked', String(act === p)); badge.hidden = act !== p; }
      scr.main.profile = act ? (COPY.preset[act.id] ? COPY.preset[act.id][0] : act.label) : 'tu configuración';
      const mp = scr.main.sel; if (mp && mp.dataset.desc === 'play') setLine(scr.main.root.querySelector('.desc'), scr.main.playLine());
      const rowsNow = rowsFor();
      moreRow.hidden = !hasNa();
      for (const r of rows) {
        const on = applies(r.o);
        r.row.hidden = r.o.group !== tab || !on;
        const x = r.vals.find(y => eq(y.v, sel[r.o.id])), label = x ? x.label : String(sel[r.o.id]);
        if (r.cur !== label) {
          const nw = T(label), old = r.vv.firstElementChild;
          r.vv.append(nw); r.row.setAttribute('aria-valuetext', label);
          if (old && !r.row.hidden && dir !== undefined) {
            const d = dir || 0, dist = d ? 1.6 : 0;
            A(old, [{ opacity: 1, transform: 'none' }, { opacity: 0, transform: `translateX(${-d * dist}rem)` }], { duration: 120, easing: 'ease-in', fill: 'forwards' });
            setTimeout(() => old.remove(), 140);
            A(nw, [{ opacity: 0, transform: `translateX(${d * dist}rem)` }, { opacity: 1, transform: 'none' }], { duration: 200, delay: 40, easing: 'cubic-bezier(.16,1,.3,1)', fill: 'backwards' });
          } else if (old) old.remove();
          r.cur = label;
        }
      }
      requestAnimationFrame(() => { fit(); if (scr.opts.light && rowsNow.length) scr.opts.light.resnap(); });
    }
    // long labels and values shrink to their cell (the game font is a picture, it cannot wrap)
    function fit() {
      const vis = rows.filter(r => !r.row.hidden && r.row.offsetParent);
      listBox.style.setProperty('--k', 1);
      for (const r of vis) for (const t of r.vv.querySelectorAll('.t')) t.style.removeProperty('--kv');
      let k = 1;                                         // one size for every label of the group
      const vals = vis.map(r => {
        const l = r.row.querySelector('.lbl'), val = r.row.querySelector('.val'), t = r.vv.lastElementChild;
        const lb = l.getBoundingClientRect(), vb = val.getBoundingClientRect();
        const stop = vb.top >= lb.bottom - 2 ? r.row.getBoundingClientRect().right - 24 : vb.left - 16;   // phone: the value sits under the label
        k = Math.min(k, (stop - lb.left) / (l.offsetWidth || 1));
        return [t, Math.min(1, (r.vv.clientWidth - 6) / ((t && t.offsetWidth) || 1))];
      });
      if (moreRow.offsetParent) {
        const l = moreRow.querySelector('.lbl'), tg = moreRow.querySelector('.tag'), lb = l.getBoundingClientRect(), tb = tg.getBoundingClientRect();
        k = Math.min(k, ((tb.top >= lb.bottom - 2 ? moreRow.getBoundingClientRect().right - 24 : tb.left - 16) - lb.left) / (l.offsetWidth || 1));
      }
      listBox.style.setProperty('--k', Math.max(.6, Math.min(1, k)).toFixed(3));
      for (const [t, b] of vals) if (t && b < 1) t.style.setProperty('--kv', b.toFixed(3));
    }
    addEventListener('resize', () => { if (cur === 'opts') requestAnimationFrame(fit); });
    scr.opts.fit = fit;
    refresh();
    placeTab();
    scr.opts.ready = true;
    GF.onReady(() => requestAnimationFrame(() => { placeTab(); fit(); for (const k in scr) if (scr[k].light) scr[k].light.resnap(); place(); }));

    launchHook.query = () => {
      save();
      store.set('rn_mode', mode());                  // mode.js and F4 read it; a ?mode= in the URL would pin the mode and break F4
      // Options that do not apply in this mode go out at their default, so they cannot override the mode's own settings.
      const send = Object.assign({}, sel);
      for (const o of opts) if (!applies(o)) send[o.id] = o.def;
      let q = '';
      try { q = L.query(send) || ''; } catch {}
      const out = new URLSearchParams();
      out.set('play', '1');
      for (const [k, v] of new URLSearchParams(q)) if (k !== 'play' && k !== 'mode') out.append(k, v);
      return out.toString();
    };
  }

  // ---------- confirm: headlights, push-in (RN_SCENE.confirm), fade, then go ----------
  async function launch() {
    if (going) return;
    going = true;
    const q = launchHook.query();
    const s = scr.main.sel; if (s && scr.main.light) scr.main.light.node.classList.add('go');
    for (const it of scr.main.items()) if (it !== s) it.classList.add('out');
    snd('accept'); try { window.RN_SND && window.RN_SND.rev(); window.RN_SND && window.RN_SND.fadeOut(900); } catch {}
    body.classList.add('leaving');
    const done = Promise.resolve(scene('confirm'));
    await Promise.race([done.catch(() => 0), wait(1800)]);
    $('fade').classList.add('on');
    await wait(motion ? 220 : 120);
    location.href = '/?' + q;
  }
  addEventListener('pageshow', e => {
    if (e.persisted) { going = false; body.classList.remove('leaving'); $('fade').classList.remove('on'); for (const it of scr.main.items()) it.classList.remove('out'); scr.main.light.node.classList.remove('go'); }
  });
  document.addEventListener('pointerdown', e => { const lg = scr[cur].light; if (lg && e.target.closest && e.target.closest('.item, .row')) lg.press(true); });
  addEventListener('pointerup', () => { for (const k of ['main', 'ctrl', 'opts']) if (scr[k].light) scr[k].light.press(false); });

  // ---------- key hints ----------
  const bar = $('keys');
  const K = (c, t) => `<kbd class="${c || ''}">${t}</kbd>`;
  function hints() {
    const sub = cur !== 'main', pad = kind === 'pad', touch = kind === 'touch';
    const h = (kbds, label, act) => act ? `<button type="button" class="hint" data-act="${act}">${kbds}<span>${label}</span></button>` : `<span class="hint nb">${kbds}<span>${label}</span></span>`;
    const out = [];
    if (pad) {
      out.push(h(K('wide', '↕'), 'Elegir'));
      if (cur === 'opts') out.push(h(K('wide', '↔'), 'Cambiar'), h(K('wide', 'LB') + K('wide', 'RB'), 'Grupo'));
      if (cur === 'presets') out.push(h(K('wide', '↔'), 'Elegir'));
      out.push(h(K('pad a', 'A'), 'Aceptar', 'ok'));
      if (sub) out.push(h(K('pad b', 'B'), 'Atrás', 'back'));
      out.push(h(K('wide', 'Start'), 'Jugar', 'play'));
    } else if (!touch) {
      out.push(h(K('wide', '↑↓'), cur === 'presets' ? 'Elegir' : 'Elegir'));
      if (cur === 'opts') out.push(h(K('wide', '←→'), 'Cambiar'), h(K('', 'Q') + K('', 'E'), 'Grupo'));
      if (cur === 'presets') out.push(h(K('wide', '←→'), 'Elegir'));
      out.push(h(K('wide', '↵'), 'Aceptar', 'ok'));
      if (sub) out.push(h(K('wide', 'Esc'), 'Atrás', 'back'));
    } else if (sub) out.push(h(K('wide', '←'), 'Atrás', 'back'));
    bar.innerHTML = out.join('');
    for (const b of optsBumps) b.innerHTML = pad ? '<span>' + (b.dataset.tab < 0 ? 'LB' : 'RB') + '</span>' : touch ? '<span>' + (b.dataset.tab < 0 ? '‹' : '›') + '</span>' : '<span>' + (b.dataset.tab < 0 ? 'Q' : 'E') + '</span>';
  }
  const optsBumps = [...document.querySelectorAll('.bump')];
  bar.addEventListener('click', e => { const b = e.target.closest('[data-act]'); if (b) act(b.dataset.act); });
  const setKind = k => { if (k !== kind) { kind = k; body.classList.toggle('touch', k === 'touch'); hints(); } };

  // ---------- sound and animation switches ----------
  const btnSnd = $('btnSnd'), btnMot = $('btnMot');
  const sndOn = () => !window.RN_SND || window.RN_SND.isOn();
  const paintSnd = () => { const on = sndOn(); btnSnd.setAttribute('aria-pressed', String(on)); };
  if (window.RN_SND) window.RN_SND.onChange(paintSnd); else btnSnd.hidden = true;
  btnSnd.addEventListener('click', () => { window.RN_SND.init(); window.RN_SND.toggle(); if (sndOn()) snd('accept'); });
  paintSnd();
  const setMotion = on => {
    motion = on; root.classList.toggle('calm', !on); btnMot.setAttribute('aria-pressed', String(on)); btnMot.querySelector('.ml').textContent = on ? 'Animación: sí' : 'Animación: no'; store.set('rn_launch_motion', on ? '1' : '0'); scene('motion', on);
  };
  btnMot.addEventListener('click', () => setMotion(!motion));
  setMotion(motion);

  // ---------- input ----------
  function act(name) {
    if (going) return;
    if (!revealed) { reveal(); return; }
    switch (name) {
      case 'up': step(-1); break;
      case 'down': step(1); break;
      case 'left': adj(-1); break;
      case 'right': adj(1); break;
      case 'ok': activate(); break;
      case 'back': back(); break;
      case 'play': play(); break;
      case 'tab-': tabStep(-1); break;
      case 'tab+': tabStep(1); break;
      case 'home': { const l = itemsOf(); if (l[0]) choose(l[0]); break; }
      case 'end': { const l = itemsOf(); if (l.length) choose(l[l.length - 1]); break; }
    }
  }
  // hover moves the selection, like a game menu does
  document.addEventListener('pointerover', e => {
    if (e.pointerType === 'touch' || going || !revealed) return;
    const n = e.target.closest && e.target.closest('.item, .row, .cover');
    if (n && itemsOf().includes(n)) choose(n);
  });
  document.addEventListener('pointerdown', e => {
    setKind(e.pointerType === 'touch' ? 'touch' : 'key');
    if (!revealed) { reveal(); return; }
    const n = e.target.closest && e.target.closest('.item, .row, .cover');
    if (n && itemsOf().includes(n) && n !== scr[cur].sel) choose(n);
  });
  const KEYS = { ArrowUp: 'up', ArrowDown: 'down', ArrowLeft: 'left', ArrowRight: 'right', Escape: 'back', Backspace: 'back', PageUp: 'tab-', PageDown: 'tab+', q: 'tab-', Q: 'tab-', e: 'tab+', E: 'tab+', Home: 'home', End: 'end' };
  addEventListener('keydown', e => {
    if (e.altKey || e.ctrlKey || e.metaKey) return;
    setKind('key');
    if (e.key === 'm' || e.key === 'M') { e.preventDefault(); if (!e.repeat && window.RN_SND) { window.RN_SND.init(); window.RN_SND.toggle(); if (sndOn()) snd('accept'); } return; }
    const a = KEYS[e.key];
    if (a) {
      e.preventDefault();
      if (e.repeat && (a === 'back' || a === 'tab-' || a === 'tab+')) return;
      act(a); return;
    }
    if (e.key === 'Enter' || e.key === ' ') {
      const t = e.target;
      if (t && t.closest && t.closest('.tool, .keys button, .bump, .arr')) return;      // native button behaviour
      e.preventDefault(); if (!e.repeat) act('ok');
    }
  });

  // pointer -> scene parallax
  let pRaf = 0, pxn = 0, pyn = 0;
  const sendPointer = () => { pRaf = 0; scene('pointer', pxn, pyn); };
  const setPointer = (x, y) => { pxn = clamp(x, -1, 1); pyn = clamp(y, -1, 1); if (!pRaf) pRaf = requestAnimationFrame(sendPointer); };
  addEventListener('pointermove', e => { if (e.pointerType !== 'touch') setPointer(e.clientX / innerWidth * 2 - 1, e.clientY / innerHeight * 2 - 1); });
  root.addEventListener('mouseleave', () => setPointer(0, 0));

  // gamepad: d-pad / left stick = move, A / B / LB / RB / Start, right stick = parallax
  const held = {};
  let polling = false;
  const fire = (name, down, now, repeat) => {
    if (!down) { delete held[name]; return false; }
    if (!(name in held)) { held[name] = now + (repeat ? 380 : Infinity); return true; }
    if (repeat && now >= held[name]) { held[name] = now + 130; return true; }
    return false;
  };
  function poll(now) {
    const pads = (navigator.getGamepads ? [...navigator.getGamepads()] : []).filter(Boolean);
    if (!pads.length) { polling = false; return; }
    const b = i => pads.some(p => p.buttons[i] && p.buttons[i].pressed);
    const ax = (i, s) => pads.some(p => (p.axes[i] || 0) * s > 0.55);
    let used = false;
    const press = (name, down, repeat, a) => { if (fire(name, down, now, repeat)) { used = true; act(a); } };
    press('l', b(14) || ax(0, -1), true, 'left'); press('r', b(15) || ax(0, 1), true, 'right');
    press('u', b(12) || ax(1, -1), true, 'up'); press('d', b(13) || ax(1, 1), true, 'down');
    press('a', b(0), false, 'ok'); press('b', b(1), false, 'back'); press('s', b(9), false, 'play');
    press('lb', b(4), false, 'tab-'); press('rb', b(5), false, 'tab+');
    const p0 = pads[0], rx = p0.axes[2] || 0, ry = p0.axes[3] || 0;
    if (Math.abs(rx) > .15 || Math.abs(ry) > .15) setPointer(rx, ry);
    if (used) { setKind('pad'); try { window.RN_SND && window.RN_SND.init(); } catch {} }
    requestAnimationFrame(poll);
  }
  const startPolling = () => { if (!polling) { polling = true; requestAnimationFrame(poll); } };
  addEventListener('gamepadconnected', startPolling);
  if (navigator.getGamepads && [...navigator.getGamepads()].some(Boolean)) startPolling();

  // the 3D light-boxes in the scene are the menu: they call back here (hover = move the selection, click = accept)
  window.RN_UI = {
    hover(i) { if (cur === 'main' && !going && revealed) { const n = itemsOf()[i]; if (n) choose(n); } },
    click(i) { if (going) return; if (!revealed) { reveal(); return; } if (cur !== 'main') return; const n = itemsOf()[i]; if (!n) return; choose(n); n.click(); },
  };

  // ---------- start: scene intro, then the UI comes in ----------
  const sweeper = document.querySelector('.sweep');
  function reveal() {
    if (revealed) return;
    revealed = true;
    body.classList.remove('boot');
    for (const n of document.querySelectorAll('.brand, .tools, .keys')) A(n, [{ opacity: 0, transform: n.classList.contains('keys') ? 'translateY(3rem)' : 'translateX(-4rem)' }, { opacity: 1, transform: 'none' }], { duration: 520, easing: 'cubic-bezier(.16,1,.3,1)', fill: 'backwards' });
    enter(scr.main, 120);
    setTimeout(() => { if (sweeper) { sweeper.classList.remove('go'); void sweeper.offsetWidth; if (motion) sweeper.classList.add('go'); } }, 380);
    setInterval(() => { if (sweeper && motion && !going && revealed && !document.hidden) { sweeper.classList.remove('go'); void sweeper.offsetWidth; sweeper.classList.add('go'); } }, 11000);
    // a tube that hums: now and then the selected label dips for a moment
    (function hum() {
      setTimeout(() => {
        const s = scr[cur] && scr[cur].sel, t = s && s.querySelector('.t');
        if (motion && t && !going && !document.hidden) t.animate([{ opacity: 1, easing: 'steps(1)' }, { opacity: .55, offset: .15, easing: 'steps(1)' }, { opacity: 1, offset: .3, easing: 'steps(1)' }, { opacity: .8, offset: .45, easing: 'steps(1)' }, { opacity: 1 }], { duration: 240 });
        hum();
      }, 4500 + Math.random() * 6500);
    })();
  }
  const staticMode = () => root.classList.add('static');
  const S = window.RN_SCENE;
  body.classList.toggle('touch', kind === 'touch');
  hints();
  // JUGAR selected on load; the first key or click while the intro still runs just brings the menu in
  choose($('play'), { snap: true, quiet: true, noscene: true });
  if (S && typeof S.start === 'function') {
    let p;
    try { p = S.start($('scene'), { base: 'launcher/v3/' }); } catch (e) { console.warn('RN_SCENE.start', e); p = Promise.reject(e); }
    Promise.resolve(p).then(() => { root.classList.add('w3d'); scene('motion', motion); scene('screen', cur); if (typeof S.onIntroDone === 'function') S.onIntroDone(reveal); else setTimeout(reveal, 2500); },
      () => { staticMode(); setTimeout(reveal, 300); });
    setTimeout(reveal, 7000);                        // never leave the menu hidden
  } else { staticMode(); setTimeout(reveal, 350); }
})();
