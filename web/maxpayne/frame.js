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

export function maxPlayer(M) {
  const h = M.HEAPU32, f = new Float32Array(h.buffer), b = M._rn_gamestate_addr() >>> 2;
  const seq = Atomics.load(h, b + 1);
  if ((seq & 1) || !(h[b + 4] & 2)) return null;
  const pos = Array.from(f.subarray(b + 6, b + 9));
  if (Atomics.load(h, b + 1) !== seq) return null; // skip this packet's draws during a concurrent publication
  // View: not read from guest memory (the GM+0x1074 camera read gave no player in run 4); gpu.js takes it from the draws.
  return { pos, vel: Array.from(f.subarray(b + 18, b + 21)), control: h[b + 351] };
}

export function pedFrame(M) {
  const a = M._rn_mc_state() >>> 0, v = new DataView(M.HEAPU8.buffer);
  if (!v.getInt32(a, true)) return null;               // driving: no pedestrian to draw
  const f = o => v.getFloat32(a + o, true), m = o => Array.from({ length: 16 }, (_, i) => f(o + 4 * i));
  const h = f(16), c = Math.cos(h), s = Math.sin(h);
  return { view: m(48), projection: m(112), place: [c, s, 0, 0, -s, c, 0, 0, 0, 0, 1, 0, f(4), f(8), f(12), 1], conversion: conversion() };
}
export function reproject(uniform, local, frame) {
  const w = mul(mul(local, frame.conversion), frame.place);
  const wv = mul(w, frame.view), wvp = mul(wv, frame.projection), inv = inverse(wv);
  if (!inv) return false;
  uniform.set(transpose(wvp), 0);
  uniform.set(transpose(wv), 16);
  for (let r = 0; r < 3; r++) for (let c = 0; c < 3; c++) uniform[32 + 4 * r + c] = inv[4 * r + c];
  uniform[368] = 1 / frame.width; uniform[369] = 1 / frame.height; // GpuU.hp after vc[84], pc[8]
  return true;
}
