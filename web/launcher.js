// Pre-game launcher. Everything it shows comes from window.RN_LAUNCH (web/launcher_opts.js); "Jugar" goes to /?play=1&...
// A game-style front end: a vertical main menu (Jugar, Presets, Opciones, Controles), options as "Label < value >" rows.
// The selected item is the focused element. Input: mouse, touch, keyboard (arrows, Enter, Esc) and gamepad (d-pad/stick, A, B, LB/RB, Start).
(() => {
  'use strict';
  const $ = id => document.getElementById(id);
  const el = (tag, cls, txt) => { const e = document.createElement(tag); if (cls) e.className = cls; if (txt != null) e.textContent = txt; return e; };
  const eq = (a, b) => String(a) === String(b);
  const MODE_NAME = { original: 'Original 2003', remaster: 'Remaster' };
  const L = window.RN_LAUNCH;
  const playBtn = $('play');
  const screens = { main: $('s-main'), presets: $('s-presets'), opts: $('s-opts'), ctrl: $('s-ctrl') };
  const ok = !!(L && Array.isArray(L.opts) && Array.isArray(L.presets) && typeof L.query === 'function');
  let going = false;
  let cur = 'main';
  let play = () => { if (!going) go('play=1'); };         // replaced by build() when the data is there
  let onEnter = {};                                        // screen -> () => element to focus first

  const go = q => {
    going = true;
    playBtn.disabled = true;
    playBtn.firstElementChild.textContent = 'Cargando…';
    location.href = '/?' + q;
  };
  addEventListener('pageshow', e => { if (e.persisted) { going = false; playBtn.disabled = false; playBtn.firstElementChild.textContent = 'Jugar'; } });

  if (ok) build();
  else {
    for (const b of document.querySelectorAll('[data-go="presets"], [data-go="opts"]')) b.hidden = true;
    $('stPreset').textContent = 'Sin datos';
    $('stMode').textContent = '—';
  }


  // ---------- screens and focus ----------
  const items = () => [...screens[cur].querySelectorAll('.nav')].filter(e => !e.closest('[hidden]') && e.getClientRects().length);
  const here = () => { const a = document.activeElement; return a && a.closest ? a.closest('.nav') : null; };
  function show(name, focusEl) {
    for (const k in screens) screens[k].hidden = k !== name;
    cur = name;
    document.body.dataset.screen = name;
    scrollTo(0, 0);
    const it = items();
    const t = (focusEl && it.includes(focusEl) && focusEl) || (onEnter[name] && onEnter[name]()) || it[0];
    if (t) t.focus({ preventScroll: true });
    hints();
  }
  const back = () => { if (cur === 'main') return; show('main', document.querySelector(`[data-go="${cur}"]`)); };
  for (const b of document.querySelectorAll('[data-go]')) b.addEventListener('click', () => show(b.dataset.go));
  for (const b of document.querySelectorAll('[data-back]')) b.addEventListener('click', back);
  playBtn.addEventListener('click', () => play());

  function step(d) {
    const it = items();
    if (!it.length) return;
    const i = it.indexOf(here());
    (it[i < 0 ? 0 : (i + d + it.length) % it.length]).focus();
  }
  const adj = d => { const a = here(); if (a && a._adj) a._adj(d); };
  const activate = () => {
    const a = here();
    if (!a) { step(0); return; }
    if (a._ok) a._ok(); else if (a._adj) a._adj(1); else a.click();
  };
  const tabStep = d => { if (cur === 'opts' && $('tabs')._adj) { $('tabs')._adj(d); } };
  function act(name) {
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
    }
  }
  // Hover moves the selection like a game menu does.
  document.addEventListener('pointerover', e => {
    if (e.pointerType !== 'mouse') return;
    const n = e.target.closest && e.target.closest('.nav');
    if (n && n !== here() && items().includes(n)) n.focus({ preventScroll: true });
  });

  const KEYS = { ArrowUp: 'up', ArrowDown: 'down', ArrowLeft: 'left', ArrowRight: 'right', Escape: 'back', Backspace: 'back', PageUp: 'tab-', PageDown: 'tab+' };
  addEventListener('keydown', e => {
    if (e.altKey || e.ctrlKey || e.metaKey) return;
    const a = KEYS[e.key];
    if (a) {
      if (e.repeat && (a === 'back' || a === 'tab-' || a === 'tab+')) { e.preventDefault(); return; }
      e.preventDefault(); act(a); return;
    }
    if (e.key === 'Enter' || e.key === ' ') { e.preventDefault(); if (!e.repeat) act('ok'); }
  });
  addEventListener('keyup', e => { if (e.key === ' ' && here()) e.preventDefault(); });

  // ---------- key hints (change when a gamepad is in use) ----------
  let padSeen = false;
  const kb = (k, t) => `<span><b>${k}</b>${t}</span>`;
  function hints() {
    const k = $('keys');
    const sub = cur !== 'main';
    k.innerHTML = padSeen
      ? kb('↕', 'Mover') + (cur === 'opts' ? kb('↔', 'Cambiar') + kb('LB RB', 'Grupo') : '') + kb('A', 'Elegir') + (sub ? kb('B', 'Volver') : '') + kb('Start', 'Jugar')
      : kb('↑↓', 'Mover') + (cur === 'opts' ? kb('←→', 'Cambiar') : '') + kb('Enter', 'Elegir') + (sub ? kb('Esc', 'Volver') : '');
  }
  hints();

  // ---------- data-driven screens ----------
  function build() {
    const opts = L.opts, presets = L.presets;
    const modeOpt = opts.find(o => o.id === 'mode' || o.key === 'mode');
    const modeId = modeOpt ? modeOpt.id : 'mode';
    const storedMode = () => { try { return localStorage.getItem('rn_mode') === 'remaster' ? 'remaster' : 'original'; } catch { return 'original'; } };

    // ---- state ----
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
    const setOpt = (id, v) => { sel[id] = v; save(); refresh(); };
    function pickPreset(p) {
      const prev = sel[modeId];
      sel = defaults();
      if (!modeOpt) sel[modeId] = prev;
      Object.assign(sel, p.set || {});
      save(); refresh();
    }
    function reset() { sel = defaults(); if (!modeOpt) sel[modeId] = 'original'; save(); refresh(); }

    // ---- presets screen ----
    const presetBox = $('presetList'), presetDesc = $('presetDesc');
    const cards = presets.map(p => {
      const b = el('button', 'item nav');
      b.type = 'button'; b.setAttribute('role', 'radio');
      b.append(el('span', null, p.label), el('span', 'tag', 'Activo'));
      b.addEventListener('click', () => { pickPreset(p); show('main', playBtn); });
      b.addEventListener('focus', () => { presetDesc.textContent = p.desc || ''; });
      presetBox.append(b);
      return { p, b };
    });
    onEnter.presets = () => { const a = activePreset(); const c = cards.find(x => x.p === a); return c ? c.b : null; };

    // ---- options screen ----
    const groups = (L.groups || []).slice();
    for (const o of opts) if (!groups.some(g => g.id === o.group)) groups.push({ id: o.group, title: o.group, desc: '' });
    const used = groups.filter(g => opts.some(o => o.group === g.id));
    let tab = used.length ? used[0].id : null;
    const tabsBox = $('tabs'), listBox = $('optList'), help = $('help');
    const tabBtns = used.map(g => {
      const b = el('button', null, g.title);
      b.type = 'button'; b.tabIndex = -1; b.setAttribute('role', 'tab');
      b.addEventListener('mousedown', e => e.preventDefault());
      b.addEventListener('click', () => { tab = g.id; tabsBox.focus({ preventScroll: true }); refresh(); });
      tabsBox.append(b);
      return { g, b };
    });
    tabsBox._adj = d => {
      const i = Math.max(0, used.findIndex(g => g.id === tab));
      tab = used[(i + d + used.length) % used.length].id;
      refresh();
      listBox.scrollTop = 0;
    };
    tabsBox._ok = () => tabsBox._adj(1);
    tabsBox.addEventListener('focus', () => { const g = used.find(x => x.id === tab); help.textContent = g ? (g.desc || '') : ''; });

    const rows = opts.map(o => {
      const vals = valuesOf(o);
      const row = el('div', 'row nav');
      row.tabIndex = 0; row.setAttribute('role', 'spinbutton'); row.setAttribute('aria-label', o.label);
      const lbl = el('span', 'lbl', o.label);
      const val = el('span', 'val');
      const mkArr = (txt, d, name) => {
        const a = el('button', 'arr', txt);
        a.type = 'button'; a.tabIndex = -1; a.setAttribute('aria-label', name);
        a.addEventListener('mousedown', e => e.preventDefault());
        a.addEventListener('click', e => { e.stopPropagation(); row.focus({ preventScroll: true }); row._adj(d); });
        return a;
      };
      const v = el('span', 'v');
      v.addEventListener('click', () => { row.focus({ preventScroll: true }); row._adj(1); });
      const tag = el('span', 'tag', 'solo ' + (o.modes || []).map(m => (MODE_NAME[m] || m).replace(' 2003', '')).join(' / '));
      val.append(mkArr('‹', -1, 'Anterior'), v, mkArr('›', 1, 'Siguiente'));
      row.append(lbl, tag, val);
      row._adj = d => {
        if (!applies(o)) { row.classList.remove('no'); void row.offsetWidth; row.classList.add('no'); return; }
        const i = Math.max(0, vals.findIndex(x => eq(x.v, sel[o.id])));
        setOpt(o.id, vals[(i + d + vals.length) % vals.length].v);
      };
      row.addEventListener('focus', () => { help.textContent = (o.help || '') + (applies(o) ? '' : '  (' + tag.textContent + ')'); });
      listBox.append(row);
      return { o, row, v, vals };
    });
    const resetRow = el('div', 'row nav reset');
    resetRow.tabIndex = 0; resetRow.setAttribute('role', 'button');
    resetRow.append(el('span', 'lbl', 'Restablecer valores'));
    resetRow._ok = () => { reset(); resetRow.classList.remove('no'); void resetRow.offsetWidth; resetRow.classList.add('no'); };
    resetRow.addEventListener('click', () => resetRow._ok());
    resetRow.addEventListener('focus', () => { help.textContent = 'Vuelve todas las opciones a su valor de fábrica (Original 2003).'; });
    listBox.append(resetRow);
    onEnter.opts = () => rows.find(r => r.o.group === tab && !r.row.hidden)?.row || tabsBox;

    function refresh() {
      const act = activePreset();
      for (const { p, b } of cards) {
        b.setAttribute('aria-checked', String(act === p));
        b.classList.toggle('on', act === p);
        b.querySelector('.tag').style.display = act === p ? 'block' : 'none';
      }
      $('stPreset').textContent = act ? act.label : 'Personalizado';
      $('stMode').textContent = MODE_NAME[mode()];
      for (const { g, b } of tabBtns) b.setAttribute('aria-selected', String(g.id === tab));
      for (const r of rows) {
        const on = applies(r.o);
        r.row.hidden = r.o.group !== tab;
        r.row.classList.toggle('na', !on);
        r.row.setAttribute('aria-disabled', String(!on));
        const x = r.vals.find(y => eq(y.v, sel[r.o.id]));
        r.v.textContent = x ? x.label : String(sel[r.o.id]);
      }
      if (document.activeElement && document.activeElement.classList.contains('row')) document.activeElement.dispatchEvent(new Event('focus'));
    }

    play = () => {
      if (going) return;
      save();
      try { localStorage.setItem('rn_mode', mode()); } catch {}   // mode.js and F4 read it; a ?mode= in the URL would pin the mode and break F4
      // Options that do not apply in this mode go out at their default, so they cannot override the mode's own settings.
      const send = Object.assign({}, sel);
      for (const o of opts) if (!applies(o)) send[o.id] = o.def;
      let q = '';
      try { q = L.query(send) || ''; } catch {}
      const out = new URLSearchParams();
      out.set('play', '1');
      for (const [k, v] of new URLSearchParams(q)) if (k !== 'play' && k !== 'mode') out.append(k, v);
      go(out.toString());
    };
    refresh();
  }

  // ---------- gamepad ----------
  const held = {};                                     // control -> time of the next repeat
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
    press('l', b(14) || ax(0, -1), true, 'left');
    press('r', b(15) || ax(0, 1), true, 'right');
    press('u', b(12) || ax(1, -1), true, 'up');
    press('d', b(13) || ax(1, 1), true, 'down');
    press('a', b(0), false, 'ok');
    press('b', b(1), false, 'back');
    press('s', b(9), false, 'play');
    press('lb', b(4), false, 'tab-');
    press('rb', b(5), false, 'tab+');
    if (used && !padSeen) { padSeen = true; hints(); }
    requestAnimationFrame(poll);
  }
  const startPolling = () => { if (!polling) { polling = true; requestAnimationFrame(poll); } };
  addEventListener('gamepadconnected', startPolling);
  if (navigator.getGamepads && [...navigator.getGamepads()].some(Boolean)) startPolling();

  playBtn.focus({ preventScroll: true });
})();
