// After Hours owns navigation; reuse the game's catalog, DIK table and BINDS persistence.
(() => {
  'use strict';
  let handleKey;
  // Installed before binds.js: its K overlay must not own this launcher's keyboard.
  addEventListener('keydown', e => handleKey?.(e), true);
  addEventListener('keyup', e => { e.stopImmediatePropagation(); }, true);
  addEventListener('DOMContentLoaded', () => {
    const $ = id => document.getElementById(id);
    const node = (tag, text, cls) => {
      const n = document.createElement(tag); if (text != null) n.textContent = text;
      if (cls) n.className = cls; return n;
    };
    const button = (text, fn, cls) => {
      const b = node('button', text, cls); b.type = 'button'; b.addEventListener('click', fn); return b;
    };
    // Only the shared binding model is used. Remove the stock overlay and its injected style.
    $('binds')?.remove();
    for (const s of document.head.querySelectorAll('style')) if (s.textContent.includes('#binds .box')) s.remove();
    BINDS.toggle = () => openPanel('controls');
    const L = window.RN_LAUNCH, selection = L.load();
    const rm = matchMedia('(prefers-reduced-motion: reduce)');
    gsap.registerPlugin(CustomEase);
    CustomEase.create('afterHours', '0.2,0.7,0.25,1');
    const tween = (target, vars) => gsap.to(target, {
      ease: 'afterHours', overwrite: 'auto', ...vars, duration: rm.matches ? 0 : (vars.duration ?? .18),
    });
    const status = message => { $('status').textContent = message; };
    const menu = [...$('menu').querySelectorAll('button')];
    const content = $('panelContent'), panel = $('panel');
    let screen = 'main', active = menu[0], capture = null, busy = false, transition = 0;
    let profiles = [], files = [], confirmName = null, padRelease = false;
    const controls = () => [...(screen === 'main' ? $('menu') : panel).querySelectorAll('button:not(:disabled), select:not(:disabled), a[href]')]
      .filter(n => n.getClientRects().length);
    const focus = n => { n?.focus({ preventScroll: true }); n?.scrollIntoView({ block: 'nearest' }); };
    const mark = b => {
      if (!menu.includes(b)) return;
      active = b; menu.forEach(n => n.classList.toggle('active', n === b));
      tween($('underline'), { y: b.offsetTop + b.offsetHeight - 3, width: b.offsetWidth, duration: .16 });
    };
    const refreshMode = () => { $('modeLabel').textContent = selection.mode === 'remaster' ? 'Remaster' : 'Original 2003'; };
    const saveOptions = () => { L.save(selection); refreshMode(); };
    function closePanel() {
      if (busy) return;
      capture = null; confirmName = null;
      const token = ++transition;
      tween(panel, { opacity: 0, x: 12, duration: .12, onComplete: () => {
        if (token !== transition) return;
        panel.hidden = true; screen = 'main'; document.body.dataset.screen = screen;
        window.RN_SCENE?.screen?.('main'); status(''); focus(active);
      } });
    }
    function openPanel(name) {
      if (busy || document.body.classList.contains('leaving')) return;
      ++transition; capture = null; confirmName = null; screen = name;
      document.body.dataset.screen = name;
      $('panelTitle').textContent = { profiles: 'Elige tu perfil', options: 'Opciones', controls: 'Controles' }[name];
      content.replaceChildren(); panel.hidden = false; status('');
      window.RN_SCENE?.screen?.(name);
      gsap.set(panel, { opacity: rm.matches ? 1 : 0, x: rm.matches ? 0 : 16 });
      tween(panel, { opacity: 1, x: 0, duration: .2 });
      if (name === 'options') renderOptions();
      if (name === 'controls') renderBindings();
      if (name === 'profiles') loadProfiles();
      focus($('back'));
    }
    $('back').addEventListener('click', closePanel);
    for (const b of menu) {
      b.addEventListener('focus', () => mark(b));
      b.addEventListener('pointerenter', () => mark(b));
      if (b.dataset.panel) b.addEventListener('click', () => openPanel(b.dataset.panel));
    }
    $('play').addEventListener('click', () => {
      if (busy) return;
      Promise.resolve(window.RN_LAUNCH_GAME(selection)).catch(e => {
        document.body.classList.remove('leaving'); gsap.set('#fade', { opacity: 0 }); status(e.message);
      });
    });
    document.addEventListener('click', e => {
      const b = e.target.closest('button');
      if (b && !rm.matches) gsap.fromTo(b, { scale: .97 }, { scale: 1, duration: .12, overwrite: 'auto' });
    });
    rm.addEventListener('change', () => {
      gsap.globalTimeline.getChildren(true, true, false).forEach(t => t.progress(1));
      mark(active);
    });
    addEventListener('resize', () => mark(active));

    function renderOptions() {
      content.replaceChildren();
      for (const group of L.groups) {
        const opts = L.opts.filter(o => o.group === group.id);
        if (!opts.length) continue;
        content.append(node('h3', group.title));
        for (const o of opts) {
          const label = node('label', null, 'option');
          const text = node('span', o.label); text.append(node('small', o.help));
          const select = node('select'); select.id = 'option-' + o.id;
          for (const value of o.values) {
            const option = node('option', value.label); option.value = value.v; select.append(option);
          }
          select.value = selection[o.id]; select.disabled = !o.modes.includes(selection.mode);
          if (select.disabled) text.append(node('small', 'Disponible en Remaster.'));
          select.addEventListener('change', () => {
            selection[o.id] = select.value; saveOptions();
            if (o.id === 'mode') { renderOptions(); focus($('option-mode')); }
            status('Opciones guardadas. Se aplican al entrar a la calle.');
          });
          label.append(text, select); content.append(label);
        }
      }
    }

    const labels = { left: 'Girar a la izquierda', right: 'Girar a la derecha', gas: 'Acelerar', brake: 'Frenar / reversa', nitro: 'Nitro', handbrake: 'Freno de mano', camera: 'Cámara', respot: 'Reubicar coche', pause: 'Pausa', accept: 'Aceptar en menús', back: 'Volver en menús' };
    const keyName = code => ({ ArrowLeft: '←', ArrowRight: '→', ArrowUp: '↑', ArrowDown: '↓', Space: 'Espacio' })[code] || code.replace(/^Key|^Digit/, '');
    function renderBindings(focusId) {
      content.replaceChildren();
      for (const [kind, title, table] of [['key', 'Teclado', BIND_KEYS], ['pad', 'Mando', BIND_PAD]]) {
        content.append(node('h3', title));
        for (const [id] of table) {
          const row = node('div', null, 'binding'); row.append(node('span', labels[id]));
          const waiting = capture?.kind === kind && capture.id === id;
          const value = kind === 'key' ? keyName(BINDS.keys[id]) : PAD_NAMES[BINDS.pad[id]];
          const b = button(waiting ? 'Pulsa ' + (kind === 'key' ? 'una tecla…' : 'un botón…') : value, () => {
            capture = { kind, id }; renderBindings(kind + '-' + id);
            status('Esc cancela. Enter y Esc, sticks, cruceta y gatillos permanecen fijos.');
          }, waiting ? 'capture' : '');
          b.id = 'bind-' + kind + '-' + id; b.setAttribute('aria-label', labels[id] + ': ' + value);
          row.append(b); content.append(row);
        }
      }
      content.append(node('p', 'Sticks: dirección. RT / LT: acelerar y frenar. Cruceta: navegar. Enter y Esc permanecen fijos.'));
      content.append(button('Restablecer controles', () => {
        for (const [id, , , code] of BIND_KEYS) BINDS.keys[id] = code;
        for (const [id, , b] of BIND_PAD) BINDS.pad[id] = b;
        BINDS.save(); capture = null; renderBindings(); focus($('back')); status('Controles restablecidos.');
      }, 'text-action'));
      if (focusId) focus($('bind-' + focusId));
    }
    function bind(value) {
      const { kind, id } = capture;
      if (kind === 'key' && (DIK[value] === undefined || ['Escape', 'Enter'].includes(value))) {
        status('Esa tecla no se puede reasignar. Pulsa otra o Esc para cancelar.'); return;
      }
      const table = kind === 'key' ? BINDS.keys : BINDS.pad;
      const other = Object.keys(table).find(o => o !== id && table[o] === value && (kind === 'key' || PAD_GROUPS[o] === PAD_GROUPS[id]));
      if (other) table[other] = table[id];
      table[id] = value; BINDS.save(); capture = null;
      if (kind === 'pad') padRelease = true;
      renderBindings(kind + '-' + id); status('Asignación guardada.');
    }

    const saveURL = name => '/save/' + encodeURIComponent(name);
    async function request(url, init) {
      const r = await fetch(url, { cache: 'no-store', ...init });
      if (!r.ok) throw new Error('No se pudo ' + (init?.method || 'GET') + ' ' + url + ' (' + r.status + ').');
      return r;
    }
    // ProfileList__Load 0x41d140: LE u32 count followed by count * 0x20 bytes.
    // ProfileList__Touch 0x41d2a0 moves the selected existing record to the front.
    // Preserve all record bytes, including the game's unused trailing data.
    async function readIndex() {
      const bytes = new Uint8Array(await (await request(saveURL('Profiles.usr'))).arrayBuffer());
      if (bytes.length < 4) throw new Error('Profiles.usr está incompleto.');
      const count = new DataView(bytes.buffer).getUint32(0, true);
      if (count > 10000 || bytes.length !== 4 + count * 32) throw new Error('Profiles.usr tiene un formato no reconocido.');
      const records = [];
      for (let i = 0; i < count; i++) {
        const raw = bytes.slice(4 + i * 32, 36 + i * 32), end = raw.indexOf(0);
        if (end <= 0) throw new Error('Profiles.usr contiene un nombre sin terminación válida.');
        const name = new TextDecoder('windows-1252').decode(raw.slice(0, end));
        if (/[\\/]/.test(name) || name === '.' || name === '..') throw new Error('Nombre de perfil no válido.');
        records.push({ name, raw });
      }
      return records;
    }
    async function writeIndex(records) {
      const bytes = new Uint8Array(4 + records.length * 32);
      new DataView(bytes.buffer).setUint32(0, records.length, true);
      records.forEach((r, i) => bytes.set(r.raw, 4 + i * 32));
      await request(saveURL('Profiles.usr'), { method: 'PUT', body: bytes });
    }
    const same = (a, b) => a.toLowerCase() === b.toLowerCase();
    function ownedFiles(name) {
      // Longest known profile prefix avoids consuming another profile's numbered slots.
      return files.filter(([file]) => {
        const owner = [...profiles].sort((a, b) => b.name.length - a.name.length).find(p => {
          if (same(file, p.name + '.cfg') || same(file, p.name + '.opt') || same(file, p.name + '.ugd') || same(file, p.name + '_autosave.ugd')) return true;
          const tail = file.slice(p.name.length);
          return same(file.slice(0, p.name.length), p.name) && /^\d+\.ugd$/i.test(tail);
        });
        return owner && same(owner.name, name);
      });
    }
    async function loadProfiles() {
      content.replaceChildren(node('p', 'Leyendo partidas guardadas…'));
      try {
        files = await (await request('/save-files.json')).json();
        profiles = files.some(([f]) => f === 'Profiles.usr') ? await readIndex() : [];
        if (screen === 'profiles') renderProfiles();
        updateProfileLabel();
      } catch (e) {
        if (screen === 'profiles') {
          content.replaceChildren(node('p', e.message)); content.append(button('Reintentar', loadProfiles));
        }
        status(e.message);
      }
    }
    function updateProfileLabel() {
      $('profileMenu').textContent = profiles.length ? 'Perfil: ' + profiles[0].name : 'Perfil'; mark(active);
    }
    async function mutateProfile(fn) {
      if (busy) return;
      busy = true; panel.setAttribute('aria-busy', 'true');
      for (const b of panel.querySelectorAll('button')) b.disabled = true;
      try { await fn(); status('Perfiles guardados.'); }
      catch (e) { status(e.message + ' Revisa la lista antes de continuar.'); }
      finally {
        busy = false; panel.removeAttribute('aria-busy'); $('back').disabled = false;
        confirmName = null; await loadProfiles(); focus($('back'));
      }
    }
    function renderProfiles() {
      content.replaceChildren();
      if (!profiles.length) content.append(node('p', 'No hay perfiles registrados por el juego. Crea uno dentro del juego.'));
      profiles.forEach((p, i) => {
        const row = node('div', null, 'profile'); row.setAttribute('aria-current', String(i === 0));
        row.append(button(p.name + (i === 0 ? ' ✓' : ''), () => mutateProfile(async () => {
          const fresh = await readIndex(), index = fresh.findIndex(r => same(r.name, p.name));
          if (index < 0) throw new Error('El perfil ya no existe.');
          const [selected] = fresh.splice(index, 1); await writeIndex([selected, ...fresh]);
        })));
        row.append(button('Eliminar', () => { confirmName = p.name; renderProfiles(); focus($('cancelDelete')); }, 'text-action'));
        content.append(row);
        const links = node('div', null, 'profile-files');
        for (const [file, size] of ownedFiles(p.name)) {
          const a = node('a', file + ' · ' + size + ' B'); a.href = saveURL(file); a.download = file; links.append(a);
        }
        content.append(links);
        if (confirmName === p.name) {
          const confirm = node('div', null, 'confirm');
          confirm.append(node('p', '¿Eliminar ' + p.name + ' y todos sus archivos guardados? Esta acción no se puede deshacer.'));
          const cancel = button('Cancelar', () => { confirmName = null; renderProfiles(); focus($('back')); }); cancel.id = 'cancelDelete';
          confirm.append(cancel, button('Sí, eliminar', () => mutateProfile(async () => {
            profiles = await readIndex(); files = await (await request('/save-files.json')).json();
            const owned = ownedFiles(p.name);
            // All requests are checked; a partial deletion is surfaced, never reported as success.
            for (const [file] of owned) await request(saveURL(file), { method: 'DELETE' });
            await writeIndex(profiles.filter(r => !same(r.name, p.name)));
          }), 'danger'));
          content.append(confirm);
        }
      });
    }

    function move(dir) {
      const list = controls(), current = list.indexOf(document.activeElement);
      focus(list[(current + dir + list.length) % list.length]);
    }
    function adjust(dir) {
      const select = document.activeElement;
      if (select?.tagName !== 'SELECT') { move(dir); return; }
      select.selectedIndex = (select.selectedIndex + dir + select.options.length) % select.options.length;
      select.dispatchEvent(new Event('change', { bubbles: true }));
    }
    function action(name) {
      if (busy || document.body.classList.contains('leaving')) return;
      if (name === 'back') {
        if (capture) { capture = null; renderBindings(); focus($('back')); status('Asignación cancelada.'); }
        else if (confirmName) { confirmName = null; renderProfiles(); focus($('back')); }
        else closePanel();
      } else if (!capture) {
        if (name === 'up') move(-1);
        if (name === 'down') move(1);
        if (name === 'left') adjust(-1);
        if (name === 'right') adjust(1);
        if (name === 'ok') {
          if (document.activeElement?.tagName === 'SELECT') adjust(1);
          else (controls().includes(document.activeElement) ? document.activeElement : active).click();
        }
      }
    }
    handleKey = e => {
      e.stopImmediatePropagation();
      if (e.ctrlKey || e.metaKey || e.altKey) return;
      if (capture) {
        e.preventDefault();
        if (e.repeat) return;
        if (e.code === 'Escape') action('back');
        else if (capture.kind === 'key') bind(e.code);
        return;
      }
      const name = { ArrowUp: 'up', ArrowDown: 'down', ArrowLeft: 'left', ArrowRight: 'right', Escape: 'back', Enter: 'ok', Space: 'ok' }[e.code];
      // Native select owns its keyboard interaction; gamepad uses adjust().
      if (e.target.tagName === 'SELECT' && name !== 'back') return;
      if (name) { e.preventDefault(); if (!e.repeat || ['up', 'down', 'left', 'right'].includes(name)) action(name); }
      if (e.code === 'Tab') {
        const list = controls(), first = list[0], last = list.at(-1);
        if (e.shiftKey && (document.activeElement === first || !list.includes(document.activeElement))) { e.preventDefault(); focus(last); }
        else if (!e.shiftKey && (document.activeElement === last || !list.includes(document.activeElement))) { e.preventDefault(); focus(first); }
      }
    };
    // pad.js's game-driving heuristic does not fit launcher selects or remapping.
    // Reuse its PAD_STICK threshold and BINDS.pad menu actions, with launcher-only navigation.
    let running = false, previous = [], held = {};
    function poll(now) {
      const pad = [...navigator.getGamepads()].find(p => p?.connected);
      if (!pad) { running = false; previous = []; held = {}; return; }
      const buttons = pad.buttons.map(b => b.pressed || b.value > .5);
      if (padRelease) {
        previous = buttons; held = {};
        padRelease = buttons.some(Boolean);
        requestAnimationFrame(poll); return;
      }
      if (capture?.kind === 'pad') {
        const index = buttons.findIndex((down, i) => down && !previous[i] && i < 16 && ![6, 7, 8, 12, 13, 14, 15].includes(i));
        if (index >= 0) bind(index);
        else if (buttons[8] && !previous[8]) action('back');
        held = {};
      } else {
        const input = {
          up: buttons[12] || pad.axes[1] < -PAD_STICK,
          down: buttons[13] || pad.axes[1] > PAD_STICK,
          left: buttons[14] || pad.axes[0] < -PAD_STICK,
          right: buttons[15] || pad.axes[0] > PAD_STICK,
          ok: buttons[BINDS.pad.accept], back: buttons[BINDS.pad.back],
        };
        for (const [name, down] of Object.entries(input)) {
          if (!down) { delete held[name]; continue; }
          const repeat = ['up', 'down', 'left', 'right'].includes(name);
          if (held[name] === undefined || (repeat && now >= held[name])) {
            held[name] = now + (held[name] === undefined ? 360 : 130);
            $('hints').textContent = 'Cruceta / stick: elegir　' + PAD_NAMES[BINDS.pad.accept] + ': entrar　' + PAD_NAMES[BINDS.pad.back] + ': volver';
            action(name);
          }
        }
      }
      previous = buttons; requestAnimationFrame(poll);
    }
    const start = () => { if (!running) { running = true; requestAnimationFrame(poll); } };
    addEventListener('gamepadconnected', start);
    if (navigator.getGamepads && [...navigator.getGamepads()].some(Boolean)) start();
    document.addEventListener('pointerdown', () => { $('hints').textContent = '↑ ↓ Elegir　↵ Entrar　Esc Volver'; });
    refreshMode(); mark(active); focus(active);
    if (!rm.matches) gsap.from(menu, { opacity: 0, x: -14, duration: .16, stagger: .035, ease: 'afterHours' });
    // Fetch the real active label without opening a panel.
    (async () => {
      try {
        const listing = await (await request('/save-files.json')).json();
        if (listing.some(([f]) => f === 'Profiles.usr') && screen === 'main') {
          profiles = await readIndex(); updateProfileLabel();
        }
      } catch (e) { status(e.message); }
    })();
  });
})();
