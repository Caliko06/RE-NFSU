// Launcher scene motion: parallax of the image layers (mouse, touch, gamepad right stick, slow idle sway), rain with
// splashes on the wet street (one Canvas2D), and random neon dropouts. Decoration only; web/launcher.js owns the menu.
(() => {
  'use strict';
  const bg = document.querySelector('.bg');
  if (!bg) return;
  const still = matchMedia('(prefers-reduced-motion: reduce)').matches;
  for (const l of bg.querySelectorAll('.layer')) l.style.setProperty('--d', l.dataset.d || 0);

  // ---------- parallax: target from the pointer or the right stick, eased every frame ----------
  let tx = 0, ty = 0, px = 0, py = 0, lastInput = 0;
  addEventListener('pointermove', e => { tx = e.clientX / innerWidth * 2 - 1; ty = e.clientY / innerHeight * 2 - 1; lastInput = performance.now(); }, { passive: true });

  // ---------- rain ----------
  const cv = document.getElementById('rain'), cx = cv.getContext('2d');
  let W = 0, H = 0, drops = [], splashes = [];
  const DPR = Math.min(devicePixelRatio || 1, 1.5);
  function size() {
    W = cv.width = Math.round(innerWidth * DPR); H = cv.height = Math.round(innerHeight * DPR);
    const n = Math.round(Math.min(420, W * H / 5200));
    drops = Array.from({ length: n }, () => drop(true));
  }
  // z: 0 far .. 1 near; near drops are longer, faster, brighter
  function drop(any) {
    const z = Math.random();
    return { x: Math.random() * W * 1.2 - W * .1, y: any ? Math.random() * H : -Math.random() * H * .3, z,
      v: (9 + z * 16) * DPR, l: (10 + z * 26) * DPR, floor: H * (.68 + z * .3) };
  }
  const wind = -.18;
  function rain() {
    cx.clearRect(0, 0, W, H);
    cx.lineCap = 'round';
    for (const d of drops) {
      d.x += d.v * wind - px * d.z * .6; d.y += d.v;
      if (d.y > d.floor) {
        if (d.z > .35 && splashes.length < 160) splashes.push({ x: d.x, y: d.floor, r: 0, a: .5 * d.z, z: d.z });
        Object.assign(d, drop(false));
      }
      cx.strokeStyle = `rgba(${d.z > .7 ? '200,230,255' : '150,180,230'},${.12 + d.z * .3})`;
      cx.lineWidth = (.6 + d.z * 1.1) * DPR;
      cx.beginPath(); cx.moveTo(d.x, d.y); cx.lineTo(d.x - d.l * wind, d.y - d.l); cx.stroke();
    }
    // splashes: flat rings on the asphalt, tinted by the neon above
    for (let i = splashes.length - 1; i >= 0; i--) {
      const s = splashes[i];
      s.r += (1 + s.z * 1.6) * DPR; s.a -= .03;
      if (s.a <= 0) { splashes.splice(i, 1); continue; }
      cx.strokeStyle = `rgba(${s.x / W < .5 ? '255,170,80' : '120,220,255'},${s.a})`;
      cx.lineWidth = DPR;
      cx.beginPath(); cx.ellipse(s.x, s.y, s.r, s.r * .28, 0, 0, Math.PI * 2); cx.stroke();
    }
  }

  // ---------- neon: now and then one sign drops out for a few frames ----------
  const neons = [...bg.querySelectorAll('.neon')];
  function kickNeon() {
    const n = neons[Math.random() * neons.length | 0];
    if (n) {
      let k = 0;
      const t = setInterval(() => { n.classList.toggle('off'); if (++k > 3 + Math.random() * 5) { clearInterval(t); n.classList.remove('off'); } }, 60 + Math.random() * 90);
    }
    setTimeout(kickNeon, 1800 + Math.random() * 4200);
  }

  // ---------- loop ----------
  function frame(now) {
    if (!document.hidden) {
      const pad = navigator.getGamepads ? [...navigator.getGamepads()].find(Boolean) : null;
      if (pad && Math.hypot(pad.axes[2] || 0, pad.axes[3] || 0) > .15) { tx = pad.axes[2]; ty = pad.axes[3]; lastInput = now; }
      // with no input for a while, drift slowly so the scene never stands still
      const idle = now - lastInput > 3000;
      const gx = idle ? Math.sin(now / 5200) * .45 : tx, gy = idle ? Math.sin(now / 7300) * .25 : ty;
      px += (gx - px) * .05; py += (gy - py) * .05;
      bg.style.setProperty('--px', px.toFixed(4)); bg.style.setProperty('--py', py.toFixed(4));
      rain();
    }
    requestAnimationFrame(frame);
  }
  if (still) return;
  size();
  addEventListener('resize', size);
  kickNeon();
  requestAnimationFrame(frame);
})();
