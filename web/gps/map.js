// WORLD map. Streets: TRACKB1010 chunks 0x34121/22, tools/gps_roads.py.
// Integration: RN_GPS.pose(), .roads, .canvas, .project(x,y), .unproject(px,py), .isOpen.
// rn-gps-mapclick detail {x,y}; rn-gps-draw detail {ctx,project,pose}; rn-gps-toggle detail {open}.
(() => {
  'use strict';
  const sheet = document.createElement('link');
  sheet.rel = 'stylesheet'; sheet.href = 'gps/map.css'; document.head.append(sheet);
  const panel = document.createElement('section');
  panel.id = 'gps-map'; panel.hidden = true;
  panel.setAttribute('aria-label', 'Mapa de WORLD');
  panel.innerHTML = `<canvas aria-label="Calles de Olympic City, puente y Bayview"></canvas>
    <header><div><small>WORLD / GPS</small><h1>Olympic City + Bayview</h1></div>
    <button type="button" aria-label="Cerrar mapa">Cerrar <kbd>M / Esc</kbd></button></header>
    <footer><span class="gps-status" role="status">Cargando calles…</span><span>La conducción continúa con el mapa abierto</span></footer>`;
  document.body.append(panel);
  const canvas = panel.querySelector('canvas'), ctx = canvas.getContext('2d');
  const status = panel.querySelector('.gps-status'), closeButton = panel.querySelector('button');
  const api = window.RN_GPS = { roads: null, canvas, isOpen: false, pose, project, unproject };
  let loading = false, failure = '', transform, roadLayer, previousFocus;
  // Re-create the view on every read: WebAssembly memory may grow. ABI: host/gps.h +0..+20.
  function pose() {
    const m = window.RN_M;
    if (!m?._rn_gps_addr) return null;
    const d = new DataView(m.HEAPU8.buffer, m._rn_gps_addr() >>> 0, 24);
    if (!d.getInt32(16, true)) return null;
    return { x: d.getFloat32(0, true), y: d.getFloat32(4, true), z: d.getFloat32(8, true),
      yaw16: d.getInt32(12, true), frame: d.getUint32(20, true) };
  }
  function project(x, y) { return [transform.ox + x * transform.s, transform.oy - y * transform.s]; }
  function unproject(x, y) { return { x: (x - transform.ox) / transform.s, y: (transform.oy - y) / transform.s }; }
  async function load() {
    if (loading || api.roads) return;
    loading = true; failure = '';
    try {
      const r = await fetch('gps/roads.json');
      if (!r.ok) throw new Error(`HTTP ${r.status}`);
      api.roads = await r.json(); roadLayer = null;
      if (!api.roads.nodes.length) throw new Error('No streets');
    } catch (e) { failure = 'No se pudieron cargar las calles. Cierra y abre el mapa para reintentar.'; }
    finally { loading = false; }
  }
  function toggle(open) {
    if (open && !pose()) return;
    api.isOpen = open; panel.hidden = !open;
    if (open) {
      previousFocus = document.activeElement;
      if (document.pointerLockElement) document.exitPointerLock();
      // Keep #screen focused: driving keys continue to reach input.js.
      load(); requestAnimationFrame(draw);
    } else (previousFocus?.isConnected ? previousFocus : document.getElementById('screen'))?.focus({ preventScroll: true });
    dispatchEvent(new CustomEvent('rn-gps-toggle', { detail: { open } }));
  }
  closeButton.onclick = () => toggle(false);
  // Capture before input.js: M is the game's Debug Camera Select (0x702c98 row 32).
  // Swallow the release after closing, too; Esc must not pause the running game.
  const captured = new Set();
  for (const type of ['keydown', 'keyup']) addEventListener(type, e => {
    const down = type === 'keydown';
    const intercept = e.code === 'KeyM' && (pose() || captured.has(e.code)) ||
      e.code === 'Escape' && (api.isOpen || captured.has(e.code));
    if (!intercept) return;
    e.preventDefault(); e.stopImmediatePropagation();
    if (down) {
      captured.add(e.code);
      if (!e.repeat) toggle(e.code === 'KeyM' ? !api.isOpen : false);
    } else captured.delete(e.code);
  }, true);
  canvas.addEventListener('click', e => {
    if (!api.roads || !transform) return;
    const r = canvas.getBoundingClientRect();
    dispatchEvent(new CustomEvent('rn-gps-mapclick', { detail: unproject(e.clientX - r.left, e.clientY - r.top) }));
  });
  function streets(w, h) {
    const [x0, y0, x1, y1] = api.roads.bounds;
    const pad = Math.min(w, h) * .065, top = h < 500 ? 82 : 112, bottom = 58;
    const s = Math.min((w - pad * 2) / (x1 - x0), (h - top - bottom) / (y1 - y0));
    transform = { s, ox: (w - (x0 + x1) * s) / 2, oy: top + (h - top - bottom + (y0 + y1) * s) / 2 };
    roadLayer = document.createElement('canvas'); roadLayer.width = canvas.width; roadLayer.height = canvas.height;
    const c = roadLayer.getContext('2d'); c.scale(devicePixelRatio, devicePixelRatio);
    const p = new Path2D();
    for (const section of api.roads.sections) {
      section.nodes.forEach((id, i) => {
        const n = api.roads.nodes[id], [x, y] = project(n[0], n[1]);
        if (i) p.lineTo(x, y); else p.moveTo(x, y);
      });
    }
    // Draw the recorded section links as well as the polylines, including both bridge joins.
    for (const [a, b] of api.roads.edges) {
      const n = api.roads.nodes[a], m = api.roads.nodes[b];
      p.moveTo(...project(n[0], n[1])); p.lineTo(...project(m[0], m[1]));
    }
    c.lineCap = 'round'; c.lineJoin = 'round';
    c.strokeStyle = '#030812'; c.lineWidth = 6; c.stroke(p);
    const ink = c.createLinearGradient(0, h, w, 0);
    ink.addColorStop(0, '#4d96cc'); ink.addColorStop(.5, '#6ef5de'); ink.addColorStop(1, '#bbaaff');
    c.strokeStyle = ink; c.lineWidth = 1.5; c.stroke(p);
  }
  function draw() {
    if (!api.isOpen) return;
    const car = pose();
    if (!car) { toggle(false); return; }
    const w = innerWidth, h = innerHeight, dpr = devicePixelRatio;
    if (canvas.width !== Math.round(w * dpr) || canvas.height !== Math.round(h * dpr)) {
      canvas.width = Math.round(w * dpr); canvas.height = Math.round(h * dpr); roadLayer = null;
    }
    ctx.setTransform(dpr, 0, 0, dpr, 0, 0); ctx.clearRect(0, 0, w, h);
    status.textContent = failure || (api.roads ? '● Tu coche · posición en vivo' : 'Cargando calles…');
    if (api.roads) {
      if (!roadLayer) streets(w, h);
      ctx.drawImage(roadLayer, 0, 0, w, h);
      dispatchEvent(new CustomEvent('rn-gps-draw', { detail: { ctx, project, pose: car } }));
      const [x, y] = project(car.x, car.y);
      ctx.save(); ctx.translate(x, y);
      const glow = ctx.createRadialGradient(0, 0, 2, 0, 0, 27);
      glow.addColorStop(0, '#ff805899'); glow.addColorStop(1, '#ff805800');
      ctx.fillStyle = glow; ctx.beginPath(); ctx.arc(0, 0, 27, 0, Math.PI * 2); ctx.fill();
      // yaw16 rotates +X toward +Y in the ground plane; canvas Y is inverted.
      ctx.rotate(-car.yaw16 * Math.PI * 2 / 65536);
      ctx.beginPath(); ctx.moveTo(12, 0); ctx.lineTo(-8, -7); ctx.lineTo(-4, 0); ctx.lineTo(-8, 7); ctx.closePath();
      ctx.fillStyle = '#fff4d7'; ctx.strokeStyle = '#ff7c54'; ctx.lineWidth = 2; ctx.fill(); ctx.stroke(); ctx.restore();
    }
    requestAnimationFrame(draw);
  }
})();
