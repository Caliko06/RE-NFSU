// Motion blur and race projection. host/d3d9.c tune_apply copies the 4 blur floats into the game's .data at the next Present:
// ramp start/end m/s 0x702a38/0x702a3c, cap of t 0x702a40, streak length 0x702a44 (all read by the blur 0x40cd40).
// Both modes use the PC ramp as shipped: 25 -> 125 m/s, so there is no blur under 56 mph
// (docs/re/feel_2026-10-31.md 2). The PS2 ramp (0.1 -> 25 m/s) blurred city speeds.
// Light-trail strength (PATCH 0x409bdb, [0x707fcc]): a still lamp is s times its flare. Shipped 0x1fffffff makes still lamps
// 2.0/2.4/3.4x (blue-white): Original keeps it, Remaster uses s = 1.5 on every channel.
// Remaster caps t at 0.45 (OWNER 2026-10-31: blur at high speed too strong): composite alpha min(1.5 t, 1) tops at 0.68, not 0.98;
// the ramp is untouched, so the blur starts at the same speed and grows the same way until it meets the lower cap.
// Race projection k (word 6, host/d3d9.c hfov_frame): Remaster = 4/3, the PC's 4:3 view widened to 16:9; Original = 0, the patch's k.
// Chase framing (word 7, host/d3d9.c chase_rows): Remaster = 1, the chase camera closer, higher and pitched down; Original = 0.
const BLUR_RAMP = [25, 125], BLUR_CAP = 0.65, BLUR_CAP_REMASTER = 0.45, STREAK = 0.00625;   // 0x702a38..0x702a44 as shipped
const DECAY = [0x82, 0x96, 0xb4];   // BLENDFACTOR 0x008296b4 at 0x409bca, R G B
// D3DCOLOR 0x1fRRGGBB with channel = s (1 - k): the add weight that makes a still light s times its flare.
const trailColor = s => (0x1f000000 | DECAY.reduce((c, k) => c << 8 | Math.min(255, Math.round(s * (255 - k))), 0)) >>> 0;

function startTune(M) {
  const base = M._rn_tune_addr() >> 2, h = M.HEAPU32;
  const f = new Float32Array(1), u = new Uint32Array(f.buffer);
  const bits = x => (f[0] = x, u[0]);
  const orig = RN_MODE === 'original';
  h[base + 1] = bits(BLUR_RAMP[0]); h[base + 2] = bits(BLUR_RAMP[1]); h[base + 3] = bits(orig ? BLUR_CAP : BLUR_CAP_REMASTER); h[base + 4] = bits(STREAK);
  h[base + 5] = orig ? 0x1fffffff : trailColor(1.5);
  h[base + 6] = orig ? 0 : bits(4 / 3);
  h[base + 7] = 0;   // off: OWNER 2026-10-31 found the closer, pitched chase worse
  h[base + 8] = 0;   // off: OWNER 2026-10-31 night, streaks off looked worse (host/d3d9.c streaks_frame)
  Atomics.add(h, base, 1);
}
