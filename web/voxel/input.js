'use strict';
// Capture listeners: https://dom.spec.whatwg.org/#dom-eventtarget-addeventlistener
function startVoxelInput(M, canvas) {
  const base = M._rn_voxel_addr() >>> 2;
  canvas.addEventListener('mousedown', e => {
    const h = M.HEAP32;
    if (Atomics.load(h, base + 1) !== 1) return;
    if (e.button === 0) Atomics.add(h, base + 2, 1);
    if (e.button === 2) Atomics.add(h, base + 3, 1);
  }, true);
  canvas.addEventListener('contextmenu', e => {
    const h = M.HEAP32;
    if (Atomics.load(h, base + 1) === 1) e.preventDefault();
  }, true);
  canvas.addEventListener('keydown', e => {
    const h = M.HEAP32;
    if (Atomics.load(h, base + 1) !== 1 || !/^Digit[1-9]$/.test(e.code)) return;
    Atomics.store(h, base + 4, Number(e.code.slice(5)) - 1);
    e.stopImmediatePropagation();
    e.preventDefault();
  }, true);
  canvas.addEventListener('wheel', e => {
    const h = M.HEAP32;
    if (Atomics.load(h, base + 1) !== 1) return;
    if (e.deltaY !== 0) {
      const step = e.deltaY > 0 ? 1 : -1;
      Atomics.store(h, base + 4, (Atomics.load(h, base + 4) + step + 9) % 9);
    }
    e.preventDefault();
  }, { capture: true, passive: false });
}
