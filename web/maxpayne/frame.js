// imported from maxpayne-re b28fb1a host/d3d8.c (fixed-function matrix constants), web/telemetry.js (guest reader)
export const identity = () => [1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1];
export function mul(a, b) {
  const r = new Array(16).fill(0);
  for (let i = 0; i < 4; i++) for (let j = 0; j < 4; j++)
    for (let k = 0; k < 4; k++) r[4 * i + j] += a[4 * i + k] * b[4 * k + j];
  return r;
}
export function inverse(m) {
  const a = Array.from({ length: 4 }, (_, i) => [...m.slice(4 * i, 4 * i + 4), ...identity().slice(4 * i, 4 * i + 4)]);
  for (let k = 0; k < 4; k++) {
    let p = k;
    for (let i = k + 1; i < 4; i++) if (Math.abs(a[i][k]) > Math.abs(a[p][k])) p = i;
    if (Math.abs(a[p][k]) < 1e-12) return null;
    [a[k], a[p]] = [a[p], a[k]];
    const d = a[k][k];
    for (let j = 0; j < 8; j++) a[k][j] /= d;
    for (let i = 0; i < 4; i++) if (i !== k) {
      const f = a[i][k];
      for (let j = 0; j < 8; j++) a[i][j] -= f * a[k][j];
    }
  }
  return a.flatMap(r => r.slice(4));
}
export function transpose(m) { return m.map((_, i) => m[(i % 4) * 4 + (i >>> 2)]); }
// docs/re/mc_max_bridge.md ## Units: both worlds in metres (s = 1); Max (x, y up, z forward) -> Speed (z, -x, y), det -1.
export function convert(v) { return [v[2], -v[0], v[1]]; }
const conversion = () => [...convert([1, 0, 0]), 0, ...convert([0, 1, 0]), 0, ...convert([0, 0, 1]), 0, 0, 0, 0, 1];

function guest(M, base, size) {
  const v = new DataView(M.HEAPU8.buffer);
  const valid = (a, n = 4) => base > 0 && a >= 0x10000 && a + n <= size && base + a + n <= v.byteLength;
  return {
    u: a => valid(a) ? v.getUint32(base + a, true) : 0,
    f: a => valid(a) ? v.getFloat32(base + a, true) : NaN,
    matrix: a => valid(a, 64) ? Array.from({ length: 16 }, (_, i) => v.getFloat32(base + a + 4 * i, true)) : null,
  };
}
export function maxPlayer(M) {
  const h = M.HEAPU32, f = new Float32Array(h.buffer), b = M._rn_gamestate_addr() >>> 2;
  const seq = Atomics.load(h, b + 1);
  if ((seq & 1) || !(h[b + 4] & 2)) return null;
  const pos = Array.from(f.subarray(b + 6, b + 9));
  const body = identity();
  for (let i = 0; i < 3; i++) for (let j = 0; j < 3; j++) body[4 * i + j] = f[b + 9 + i * 3 + j];
  body.splice(12, 3, ...pos);
  if (Atomics.load(h, b + 1) !== seq) return null; // skip this packet's draws during a concurrent publication
  const base = h[(M._rn_telem_addr() + 120) >>> 2];
  const g = guest(M, base, 448 * 1048576);
  // 0x8a6338 is theApp itself, not a pointer (host/gamestate.c at b28fb1a).
  const ms = g.u(0x8a6338 + 0xc8), gm = ms && g.u(ms + 0x80), camera = gm && g.u(gm + 0x1074);
  if (!camera) return null;
  const view = identity();
  for (let i = 0; i < 4; i++) for (let j = 0; j < 3; j++) view[4 * i + j] = g.f(camera + 0x8c + 4 * (i * 3 + j));
  const invView = inverse(view), invBody = inverse(body);
  return invView && invBody && view.every(Number.isFinite) ? { pos, invBody, view, invView } : null;
}

// NFSU host/lights.c car_world and player selection, read directly on the page once F-Speed supplies the guest base.
export function speedFrame(M, base, place) {
  if (!base) return null;
  const g = guest(M, base, 0x40000000), camera = g.u(0x7404c0);
  if (!camera) return null;
  const view = g.matrix(camera), projection = g.matrix(camera + 0x40);
  if (!view || !projection || !view.every(Number.isFinite) || !projection.every(Number.isFinite)) return null;
  if (place) return { view, projection, place, conversion: conversion() };
  const projector = g.u(0x740760), pv = projector && g.matrix(projector), cam = pv && inverse(pv);
  if (!cam) return null;
  const head = g.u(0x7361f8);
  let player = 0, best = 9, count = 0;
  for (let r = head && g.u(head); r && r !== head && count++ < 200; r = g.u(r)) {
    const d = [0, 1, 2].reduce((s, k) => s + (g.f(r + 0x50 + 4 * k) - cam[12 + k]) ** 2, 0);
    if (d < best) { best = d; player = r; }
  }
  if (!player) return null;
  const b = (g.u(player + 0x530) >>> 1) & 1;
  const rot = player + (b ? 0x4e0 : 0x90), pos = player + (b ? 0x520 : 0x50);
  // Speed car local X is forward (host/lights.c); keep its heading and world Z, offset along its right axis.
  const heading = Math.atan2(g.f(rot + 4), g.f(rot)), c = Math.cos(heading), s = Math.sin(heading);
  // Rows: body forward (converted Max +Z = Speed local +X) along the car heading, left, up.
  const placement = [c, s, 0, 0, -s, c, 0, 0, 0, 0, 1, 0,
    g.f(pos) + 3 * s, g.f(pos + 4) - 3 * c, g.f(pos + 8), 1];
  return placement.every(Number.isFinite) ? { view, projection, place: placement, conversion: conversion() } : null;
}
export function reproject(uniform, world, player, frame) {
  const local = mul(world, player.invBody);
  const w = mul(mul(local, frame.conversion), frame.place);
  const wv = mul(w, frame.view), wvp = mul(wv, frame.projection), inv = inverse(wv);
  if (!inv) return false;
  uniform.set(transpose(wvp), 0);
  uniform.set(transpose(wv), 16);
  for (let r = 0; r < 3; r++) for (let c = 0; c < 3; c++) uniform[32 + 4 * r + c] = inv[4 * r + c];
  uniform[368] = 1 / frame.width; uniform[369] = 1 / frame.height; // GpuU.hp after vc[84], pc[8]
  return true;
}
