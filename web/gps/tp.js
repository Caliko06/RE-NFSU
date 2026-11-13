// Connect the map's own teleport button to this function. Coordinates use the NFSU1 frame.
window.rnGpsTeleport = function (x, y, z, yaw16) {
  const M = window.RN_M;
  if (!M?._rn_gps_addr || ![x, y, z, yaw16].every(Number.isFinite)) return false;
  const base = M._rn_gps_addr() >>> 0, words = M.HEAP32, w = base >>> 2;
  if (Atomics.load(words, w + 10)) return false;
  new Float32Array(M.HEAPU8.buffer, base + 24, 3).set([x, y, z]);
  words[w + 9] = yaw16 & 65535;
  Atomics.store(words, w + 11, 0);
  Atomics.store(words, w + 10, 1);
  return true;
};
