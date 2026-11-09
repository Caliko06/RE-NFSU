// The one small overlay on the running game (proposal A): a corner button opens a panel with the preset, mute and controls.
// The full pre-game launcher stays at /launcher. A choice is saved like the launcher does (RN_LAUNCH.save) and the game reloads with it.
(() => {
  const L = window.RN_LAUNCH;
  if (!L) return;
  const sel = L.load(), defs = Object.fromEntries(L.opts.map(o => [o.id, o.def]));
  const modeNow = () => sel.mode === 'remaster' ? 'remaster' : 'original';
  const stateOf = p => Object.assign({ ...defs }, p.set);
  const active = () => L.presets.find(p => { const s = stateOf(p); return Object.keys(s).every(k => s[k] === sel[k]); });
  // mode is not sent: L.save stores it for web/mode.js, and a ?mode= in the URL would pin it and break F4 (same as web/launcher.js)
  const go = () => { L.save(sel); const q = L.query(sel).split('&').filter(x => x !== 'play=1' && !x.startsWith('mode=')).join('&'); location.href = '/' + (q ? '?' + q : ''); };

  const css = document.createElement('style');
  css.textContent = `
    #ov-btn { position: fixed; top: 10px; right: 10px; z-index: 15; width: 34px; height: 34px; border-radius: 50%; border: 1px solid rgba(255,255,255,.25);
      background: linear-gradient(135deg, #ff7a18, #af002d); color: #fff; font: 17px/1 system-ui; cursor: pointer; opacity: .35; padding: 0;
      transition: opacity .16s, transform .12s; }
    #ov-btn:hover, #ov-btn.on { opacity: 1; } #ov-btn:active { transform: scale(.97); }
    #ov { position: fixed; top: 52px; right: 10px; z-index: 15; width: 250px; padding: 12px; display: none; flex-direction: column; gap: 8px;
      background: rgba(12,10,24,.9); backdrop-filter: blur(8px); border: 1px solid rgba(255,255,255,.14); border-radius: 12px; color: #e8e6f2; font: 13px system-ui, sans-serif; }
    #ov.on { display: flex; } #ov h4 { margin: 0; font-size: 11px; letter-spacing: .08em; text-transform: uppercase; color: #9a93c0; }
    #ov button, #ov a { font: inherit; color: inherit; text-align: left; padding: 7px 10px; border-radius: 8px; border: 1px solid rgba(255,255,255,.14);
      background: rgba(255,255,255,.06); cursor: pointer; text-decoration: none; transition: transform .12s; }
    #ov button:active { transform: scale(.97); } #ov .sel { background: linear-gradient(135deg, #ff7a18, #af002d); border-color: transparent; }
    #ov small { color: #9a93c0; }
    @media (prefers-reduced-motion: reduce) { #ov-btn, #ov button { transition: none; } }`;
  document.head.appendChild(css);

  const btn = Object.assign(document.createElement('button'), { id: 'ov-btn', textContent: '⚙', title: 'Opciones' });
  btn.tabIndex = -1;
  const panel = Object.assign(document.createElement('div'), { id: 'ov' });
  const toggle = on => { panel.classList.toggle('on', on); btn.classList.toggle('on', on); if (on) render(); else document.getElementById('screen')?.focus(); };
  btn.onclick = () => toggle(!panel.classList.contains('on'));
  function render() {
    const a = active(), muted = sel.mute === '1';
    panel.replaceChildren();
    const add = (tag, text, cls, fn, href) => { const e = Object.assign(document.createElement(tag), { textContent: text }); if (cls) e.className = cls; if (fn) e.onclick = fn; if (href) e.href = href; e.tabIndex = -1; panel.appendChild(e); };
    add('h4', 'Perfil');
    for (const p of L.presets) add('button', p.label, a === p ? 'sel' : '', () => { Object.assign(sel, stateOf(p), { mute: sel.mute }); go(); });
    add('h4', 'Sonido');
    add('button', muted ? 'Silenciado (clic para activar)' : 'Sonido activo (clic para silenciar)', muted ? 'sel' : '', () => { sel.mute = muted ? '0' : '1'; go(); });
    add('h4', 'Controles');
    add('button', 'Teclas y mando (K)', '', () => { toggle(false); BINDS.toggle(); });
    add('small', 'Cambiar perfil o sonido reinicia el juego.');
    add('a', 'Launcher completo', '', null, '/launcher');
  }
  document.body.append(btn, panel);
  addEventListener('keydown', e => { if (e.code === 'Escape' && panel.classList.contains('on')) { e.stopPropagation(); toggle(false); } }, true);
})();
