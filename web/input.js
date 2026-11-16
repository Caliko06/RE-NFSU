// Browser keyboard and mouse -> the input ring in the shared heap (host/input.c reads it on the game thread).
// Keys are DirectInput scan codes (DIK), from KeyboardEvent.code, so the layout does not matter.
'use strict';
// DIK table: web/dik.js

// Ring (u32 words): [0] head (here), [1] tail (game), [2..4] mouse dx, dy, wheel, [5] exclusive mouse (game), [6] F3 cheat, [7] HUD inset in permille (web/touch.js), [8..8+1024) events:
// bit 31 = mouse button, bit 8 = down, low byte = DIK or button. The game thread reads it at its input calls.
function startInput(M, canvas, steerLog) {
  const base = M._rn_input_ring() >> 2, RING = 1024;
  const H = () => M.HEAP32;
  function push(e) {
    const h = H(), head = Atomics.load(h, base), tail = Atomics.load(h, base + 1);
    if (head - tail >= RING) return;                   // full: the game is not reading; drop
    h[base + 8 + (head % RING)] = e;
    Atomics.store(h, base, head + 1);
  }
  // F3: this race counts as won (host/input.c input_finish). Capture phase, so the game never gets the key.
  addEventListener('keydown', e => {
    if (e.code !== 'F3') return;
    e.preventDefault(); e.stopPropagation();
    if (e.repeat) return;
    Atomics.store(H(), base + 6, 1);
    window.rnToast?.('F3: esta carrera cuenta como ganada', 3000);
  }, true);
  addEventListener('keyup', e => { if (e.code === 'F3') { e.preventDefault(); e.stopPropagation(); } }, true);
  const held = new Set();
  // One key change by DIK code; web/pad.js uses it too, so a pad and the keyboard share the ring and the held set.
  function setKey(d, down, ts = performance.now()) {
    if (down === held.has(d)) return;                  // auto-repeat: DirectInput reports changes only
    down ? held.add(d) : held.delete(d);
    steerLog?.(`page key ${d.toString(16)} ${down ? 'down' : 'up'} t ${ts.toFixed(1)}`);
    push((down ? 0x100 : 0) | d);
  }
  function key(ev, down) {
    const d = dikFor(ev.code);                         // web/binds.js: the saved key bindings (default: the key's own DIK)
    if (d === undefined) return;
    ev.preventDefault();
    setKey(d, down, ev.timeStamp);
  }
  canvas.tabIndex = 0;
  canvas.addEventListener('keydown', e => key(e, true));
  canvas.addEventListener('keyup', e => key(e, false));
  canvas.addEventListener('blur', () => { for (const d of held) push(d); held.clear(); });
  // Mouse: relative motion while the pointer is over the canvas; buttons 0 left, 1 right, 2 middle.
  const btn = [0, 2, 1, 3, 4];
  // movementX/Y are CSS pixels; the game's cursor moves in back-buffer pixels (canvas.gameW, set by web/gpu.js at each
  // present; the canvas itself is at the screen's pixels), so scale by that / on-screen width
  // and carry the fraction (Atomics takes integers).
  let remX = 0, remY = 0;
  // While the game holds an exclusive mouse (host/dinput8.c), Windows shows no cursor of its own and keeps the
  // mouse in the window: hide ours and lock it at the first click, so the game's cursor is the only one.
  const exclusive = () => Atomics.load(H(), base + 5) !== 0;
  function mouseMode() {
    const ex = exclusive();
    canvas.style.cursor = ex ? 'none' : '';
    if (!ex && document.pointerLockElement === canvas) document.exitPointerLock();
  }
  setInterval(mouseMode, 250);
  // A tap makes the browser fire mouse events too (iOS without movementX): they would click wherever the game's cursor is.
  // Touch input goes through web/touch.js only, so mouse events within 1 s of a touch are dropped.
  let touchAt = -1e9;
  addEventListener('touchstart', () => { touchAt = performance.now(); }, { capture: true, passive: true });
  const fromTouch = e => e.sourceCapabilities?.firesTouchEvents || performance.now() - touchAt < 1000;
  const scale = () => { const r = canvas.getBoundingClientRect(); return { r, sx: (canvas.gameW || canvas.width) / (r.width || 1), sy: (canvas.gameH || canvas.height) / (r.height || 1) }; };
  function mouseMove(dx, dy) {
    const { sx, sy } = scale();
    remX += dx * sx; remY += dy * sy;
    const ix = Math.trunc(remX), iy = Math.trunc(remY);
    remX -= ix; remY -= iy;
    if (ix) Atomics.add(H(), base + 2, ix);
    if (iy) Atomics.add(H(), base + 3, iy);
  }
  canvas.addEventListener('mousemove', e => { if (!fromTouch(e)) mouseMove(e.movementX || 0, e.movementY || 0); });
  canvas.addEventListener('mousedown', e => {
    canvas.focus();
    if (fromTouch(e)) { e.preventDefault(); return; }
    if (exclusive() && document.pointerLockElement !== canvas) canvas.requestPointerLock?.()?.catch?.(() => {});   // iOS Safari has no pointer lock
    push(0x80000100 | btn[e.button]);
    e.preventDefault();
  });
  canvas.addEventListener('mouseup', e => { if (!fromTouch(e)) push(0x80000000 | btn[e.button]); });
  canvas.addEventListener('wheel', e => { Atomics.add(H(), base + 4, e.deltaY < 0 ? 120 : -120); e.preventDefault(); }, { passive: false });
  canvas.addEventListener('contextmenu', e => e.preventDefault());
  canvas.focus();
  // park: the game's own arrow cursor to the bottom-right corner, where it draws off screen. The game adds the mouse
  // delta to its cursor (0x4130d0, DIMOUSESTATE) and clamps it to the client rect (0x4131a0); FEng reads it at 0x4f6080
  // as x-320, y-240 in its 640x480 space, so the corner of the window is past the menu. web/touch.js calls it on phones.
  let busy = false;
  const park = () => { if (busy) return; Atomics.add(H(), base + 2, 1 << 20); Atomics.add(H(), base + 3, 1 << 20); };
  // tapAt: a finger tap on a menu option (web/touch.js). The PC menus take the option under the game's cursor at a left click, and the
  // cursor only takes motion: a far negative delta clamps it to the top-left corner (0x4131a0), then the point is added; the two must
  // reach the game in different mouse reads (host/dinput8.c sums what arrives between two reads). Then press, release, and the
  // cursor goes back off screen, so it shows only under the finger for the length of the tap.
  // The cursor is in the menus' own 640x480 units, drawn in the centred 4:3 part of a wider picture (checked 2026-11-15 at 844x390).
  const wait = ms => new Promise(r => setTimeout(r, ms));
  const taken = async () => { for (let i = 0; i < 60 && (Atomics.load(H(), base + 2) || Atomics.load(H(), base + 3)); i++) await wait(5); };
  async function tapAt(cx, cy) {
    if (busy) return;
    busy = true;
    try {
      const r = canvas.getBoundingClientRect();
      const fe = Math.min(1, r.height * 4 / 3 / r.width), u = Math.min(1, Math.max(0, ((cx - r.left) / r.width - (1 - fe) / 2) / fe));
      const x = Math.round(u * 640), y = Math.round(Math.min(1, Math.max(0, (cy - r.top) / r.height)) * 480);
      await taken();
      Atomics.add(H(), base + 2, -(1 << 20)); Atomics.add(H(), base + 3, -(1 << 20));
      await taken(); await wait(100);
      Atomics.add(H(), base + 2, x); Atomics.add(H(), base + 3, y);
      await taken(); await wait(100);
      push(0x80000100); await wait(90); push(0x80000000); await wait(120);
    } finally { busy = false; park(); }
  }
  const inset = p => Atomics.store(H(), base + 7, p);   // host/d3d9.c: the HUD's side groups stay this far from the picture's edge
  return { key: setKey, park, inset, tapAt };
}
