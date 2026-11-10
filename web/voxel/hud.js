'use strict';
// Canvas pixel export: https://developer.mozilla.org/en-US/docs/Web/API/Canvas_API/Pixel_manipulation_with_canvas
function startVoxelHud(M) {
  const canvas = document.getElementById('screen');
  const base = M._rn_voxel_addr() >>> 2;
  const names = ['', 'asfalto', 'concreto', 'ladrillo', 'placa', 'chatarra', 'llantas', 'caja',
    'barrera', 'lámpara de sodio', 'neón', 'vidrio', 'grava', 'aceite'];
  const style = document.createElement('style');
  style.textContent = `
    #vx-hud { --glass:rgba(12,10,24,.9); --edge:rgba(255,255,255,.14); --ink:#e8e6f2;
      --accent:linear-gradient(135deg,#ffb347,#ff3fb4); --ease:cubic-bezier(.22,1,.36,1);
      position:fixed; inset:0; z-index:14; pointer-events:none; color:var(--ink); font:13px system-ui,sans-serif; }
    #vx-hud[hidden] { display:none; }
    #vx-hud * { box-sizing:border-box; }
    #vx-cross { position:absolute; top:50%; left:50%; width:14px; height:14px; transform:translate(-50%,-50%); }
    #vx-cross::before, #vx-cross::after { content:''; position:absolute; background:rgba(255,255,255,.85);
      box-shadow:0 0 0 1px rgba(0,0,0,.9); }
    #vx-cross::before { width:14px; height:2px; left:0; top:6px; }
    #vx-cross::after { width:2px; height:14px; left:6px; top:0; }
    #vx-bar { position:absolute; bottom:18px; left:50%; transform:translateX(-50%); display:flex; gap:6px;
      padding:6px; border:1px solid var(--edge); border-radius:14px; background:var(--glass); backdrop-filter:blur(8px);
      box-shadow:0 8px 28px rgba(0,0,0,.4); }
    #vx-hud .vx-slot { position:relative; display:grid; place-items:center; width:48px; height:48px; flex:none;
      border:2px solid transparent; border-radius:8px; background:rgba(255,255,255,.04); }
    #vx-hud .vx-slot.selected { background:linear-gradient(#201725,#201725) padding-box,var(--accent) border-box;
      box-shadow:0 0 12px rgba(255,63,180,.23); }
    #vx-hud .vx-tile { width:32px; height:32px; image-rendering:pixelated; background-size:100% 100%; border-radius:3px;
      box-shadow:inset 0 1px 1px rgba(255,255,255,.45),inset 0 -2px 2px rgba(0,0,0,.65); }
    #vx-hud .vx-count { font-size:11px; font-variant-numeric:tabular-nums; text-shadow:0 1px 2px #000,0 0 3px #000; }
    #vx-bar .vx-count { position:absolute; bottom:2px; right:3px; }
    #vx-hud .vx-number { position:absolute; top:1px; left:3px; font-size:9px; color:rgba(255,255,255,.6); }
    #vx-panel { position:absolute; top:50%; left:50%; width:540px; max-width:calc(100vw - 24px);
      max-height:calc(100vh - 150px); overflow:auto; padding:18px; border:1px solid var(--edge); border-radius:12px;
      background:var(--glass); backdrop-filter:blur(8px); box-shadow:0 18px 60px rgba(0,0,0,.55);
      opacity:0; visibility:hidden; transform:translate(-50%,-50%) scale(.97); pointer-events:none;
      transition:opacity 120ms var(--ease),transform 120ms var(--ease),visibility 0s 120ms; }
    #vx-panel.open { opacity:1; visibility:visible; transform:translate(-50%,-50%) scale(1); pointer-events:auto;
      transition:opacity 200ms var(--ease),transform 200ms var(--ease),visibility 0s; }
    #vx-panel h2 { margin:0 0 14px; font-size:17px; font-weight:600; }
    #vx-grid { display:grid; grid-template-columns:repeat(5,minmax(0,1fr)); gap:8px; }
    #vx-grid button { display:flex; flex-direction:column; align-items:center; gap:6px; padding:10px 4px;
      border:1px solid var(--edge); border-radius:8px; background:rgba(255,255,255,.06); color:inherit; font:inherit;
      cursor:pointer; transition:transform 120ms var(--ease); }
    #vx-grid button:hover { background:rgba(255,179,71,.12); border-color:#ffb347; }
    #vx-grid button:focus-visible { outline:2px solid #ffb347; outline-offset:2px; }
    #vx-grid button:active { transform:scale(.97); }
    #vx-grid .vx-name { font-size:11px; text-align:center; min-height:2.6em; overflow-wrap:anywhere; }
    @media (prefers-reduced-motion:reduce) {
      #vx-panel, #vx-panel.open { transform:translate(-50%,-50%); transition-property:opacity,visibility; }
      #vx-grid button { transition:none; } #vx-grid button:active { transform:none; }
    }`;
  document.head.appendChild(style);
  const make = (tag, cls, parent, text) => {
    const node = document.createElement(tag);
    if (cls) node.className = cls;
    if (text !== undefined) node.textContent = text;
    parent.appendChild(node);
    return node;
  };
  const root = make('div', '', document.body); root.id = 'vx-hud'; root.hidden = true;
  const cross = make('div', '', root); cross.id = 'vx-cross'; cross.setAttribute('aria-hidden', 'true');
  const bar = make('div', '', root); bar.id = 'vx-bar'; bar.setAttribute('aria-label', 'Barra de bloques');
  const panel = make('div', '', root); panel.id = 'vx-panel'; panel.inert = true;
  panel.setAttribute('role', 'dialog'); panel.setAttribute('aria-labelledby', 'vx-title');
  make('h2', '', panel, 'Bloques').id = 'vx-title';
  const grid = make('div', '', panel); grid.id = 'vx-grid';
  const pixels = window.rnVoxel.pixels();
  const urls = Array.from({ length: 16 }, (_, id) => {
    const tile = document.createElement('canvas'); tile.width = tile.height = 16;
    const ctx = tile.getContext('2d');
    ctx.putImageData(new ImageData(new Uint8ClampedArray(pixels.slice(id * 1024, (id + 1) * 1024)), 16, 16), 0, 0);
    return tile.toDataURL();
  });
  const slots = Array.from({ length: 9 }, (_, i) => {
    const node = make('div', 'vx-slot', bar);
    const tile = make('div', 'vx-tile', node);
    make('span', 'vx-number', node, String(i + 1));
    return { node, tile, count: make('span', 'vx-count', node), id: -1, value: -1 };
  });
  const blocks = names.slice(1).map((name, i) => {
    const id = i + 1, node = make('button', '', grid); node.type = 'button';
    const tile = make('div', 'vx-tile', node); tile.style.backgroundImage = `url("${urls[id]}")`;
    make('span', 'vx-name', node, name);
    const count = make('span', 'vx-count', node);
    node.addEventListener('click', () => {
      const h = M.HEAP32, slot = Atomics.load(h, base + 4);
      if (Atomics.load(h, base + 1) === 1 && slot < 9 && slot >= 0) Atomics.store(h, base + 5 + slot, id);
    });
    return { node, tile, count, value: -1 };
  });
  let open = false, active = false, selected = -1;
  function toggle(value, focus = true) {
    if (open === value) return;
    open = value; panel.inert = !open; panel.classList.toggle('open', open);
    if (open) {
      if (document.pointerLockElement === canvas) document.exitPointerLock();
      const id = Atomics.load(M.HEAP32, base + 5 + Atomics.load(M.HEAP32, base + 4));
      (blocks[id - 1] || blocks[0]).node.focus({ preventScroll: true });
    } else if (focus) canvas.focus({ preventScroll: true });
  }
  function key(e) {
    if (Atomics.load(M.HEAP32, base + 1) !== 1 || (e.code !== 'KeyI' && !(e.code === 'Escape' && open))) return;
    e.stopImmediatePropagation(); e.preventDefault();
    if (!e.repeat) toggle(e.code === 'Escape' ? false : !open);
  }
  canvas.addEventListener('keydown', key, true);
  panel.addEventListener('keydown', key, true);
  function count(entry, value) {
    if (entry.value === value) return;
    entry.value = value; entry.count.textContent = String(value); entry.tile.style.opacity = value ? '1' : '.35';
  }
  function frame() {
    const h = M.HEAPU32, on = Atomics.load(h, base + 1) === 1;
    if (active !== on) {
      active = on; root.hidden = !on;
      if (!on) toggle(false, panel.contains(document.activeElement));
    }
    if (on) {
      const slot = Atomics.load(h, base + 4);
      if (slot !== selected) {
        slots[selected]?.node.classList.remove('selected'); slots[slot]?.node.classList.add('selected'); selected = slot;
      }
      slots.forEach((entry, i) => {
        const id = Atomics.load(h, base + 5 + i);
        if (entry.id !== id) {
          entry.id = id; entry.tile.style.backgroundImage = `url("${urls[id] || urls[0]}")`;
          entry.node.setAttribute('aria-label', `${i + 1}: ${names[id] || 'vacío'}`);
        }
        count(entry, id < 16 ? Atomics.load(h, base + 22 + id) : 0);
      });
      blocks.forEach((entry, i) => count(entry, Atomics.load(h, base + 23 + i)));
    }
    requestAnimationFrame(frame);
  }
  requestAnimationFrame(frame);
}
