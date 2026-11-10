// imported from maxpayne-re b28fb1a web/gpu.js
import { maxPlayer, mul, inverse, identity, transpose, reproject } from './frame.js';
'use strict';
const GPU_ABI = 3, GPU_SLOTS = 2, GPU_STAGES = 4, GPU_USTEP = 1536;
const GPU_TARGET = 1, GPU_CLEAR = 2, GPU_PRESENT = 3, GPU_DRAW = 4, GPU_SHADER = 5, GPU_DECL = 6, GPU_TEXTURE = 7,
  GPU_TEXDATA = 8, GPU_FREE = 9, GPU_GAMMA = 10, GPU_READ = 11;
const D_TOPO = 0, D_NVERT = 1, D_NIDX = 2, D_VOFF = 3, D_IOFF = 4, D_UOFF = 5, D_STRIDE = 6, D_VS = 7, D_PS = 8, D_DECL = 9,
  D_RT = 10, D_DS = 11, D_VP = 12, D_ZEN = 18, D_ZWRITE = 19, D_ZFUNC = 20, D_CULL = 21, D_BLEND = 22, D_SRCB = 23,
  D_DSTB = 24, D_BOP = 25, D_CWRITE = 26, D_TEX = 27, D_TEXN = 7;
const T_ID = 0, T_AU = 1, T_AV = 2, T_MAG = 3, T_MIN = 4, T_MIP = 5, T_ANISO = 6;
// GpuBox, in u32 words: abi, seq, done, presents, shown, reads, then the slots (GpuPacket: 10 words).
const B_ABI = 0, B_SEQ = 1, B_DONE = 2, B_PRESENTS = 3, B_SHOWN = 4, B_READS = 5, B_SLOT = 6, B_SLOTN = 10;

const CMP = [null, 'never', 'less', 'equal', 'less-equal', 'greater', 'not-equal', 'greater-equal', 'always'];
const BLEND = [null, 'zero', 'one', 'src', 'one-minus-src', 'src-alpha', 'one-minus-src-alpha', 'dst-alpha',
  'one-minus-dst-alpha', 'dst', 'one-minus-dst', 'src-alpha-saturated'];
const BLENDOP = [null, 'add', 'subtract', 'reverse-subtract', 'min', 'max'];
// D3DTADDRESS: WRAP, MIRROR, CLAMP; BORDER and MIRRORONCE have no WebGPU mode (the driver sets 1 and 3).
const ADDRESS = [null, 'repeat', 'mirror-repeat', 'clamp-to-edge', 'clamp-to-edge', 'clamp-to-edge'];
// D3DDECLTYPE -> vertex format (the types a WGSL vec4f can take). D3DCOLOR is BGRA in memory.
const VFMT = ['float32', 'float32x2', 'float32x3', 'float32x4', 'unorm8x4-bgra', null, null, null, 'unorm8x4',
  'snorm16x2', 'snorm16x4', 'unorm16x2', 'unorm16x4', null, null, 'float16x2', 'float16x4'];
const COLOR = 'bgra8unorm', DEPTH = 'depth24plus';      // X8R8G8B8 / D24S8: stencil tests stop in host/d3d8.c

// No canvas, adapter, audio or standalone presentation. Resource IDs belong to this reader alone.
export function createReader(M, device) {
  const report = s => (window.MaxChar?.log || console.log)('[F-Max] ' + s);
  const box = M._rn_gpu_mailbox() >>> 2;
  const fail = msg => { throw new Error('MaxChar: ' + msg); };
  if (M.HEAPU32[box + B_ABI] !== GPU_ABI) fail('packet ABI mismatch');
  const res = new Map(), shaders = new Map(), decls = new Map();
  const pk = { present: 0, draws: 0, passes: 0, clears: 0, kb: 0, texKb: 0, pipes: 0, shaders: 0, targets: 0, reads: 0 };
  const stats = { packets: 0, seen: 0, kept: 0, view: 'unselected', world: '-', player: '-', noPlayer: 0, noView: 0, level: 0, notXyz: 0, far: 0, big: 0, nearest: Infinity, nearestW: Infinity, cam: '-' };
  const lut = device.createTexture({ size: [256, 1], format: 'rgba8unorm', usage: GPUTextureUsage.TEXTURE_BINDING | GPUTextureUsage.COPY_DST });
  const lutData = new Uint8Array(1024);
  for (let i = 0; i < 256; i++) lutData.set([i, i, i, 255], 4 * i);
  device.queue.writeTexture({ texture: lut }, lutData, { bytesPerRow: 1024 }, [256, 1]);
  let sampleCount = 1, pending = [], current = null, unshown = 0, view = null;
  // Match Max's Present cadence without creating a canvas or an audio clock.
  setInterval(() => {
    if (!unshown) return;
    unshown--;
    Atomics.add(M.HEAP32, box + B_SHOWN, 1);
    Atomics.notify(M.HEAP32, box + B_SHOWN);
  }, 1000 / 60);
  const reader = { stats, frame: null, encode };
  // Wait until the caller has submitted its encoder, then retire after all queued use.
  function retire(resource) { setTimeout(() => device.queue.onSubmittedWorkDone().then(() => resource.destroy()), 0); }
  function release(frame) {
    if (!frame) return;
    retire(frame.vbuf); retire(frame.ibuf);
    for (const d of frame.draws) for (const t of d.textures) {
      if (--t.refs === 0 && t.retired) retire(t.tex);
    }
  }

  // ---- draws: one uniform block per draw (dynamic offset), textures + samplers in group 1 ----------------
  const drawBgl = device.createBindGroupLayout({ entries: [{ binding: 0, visibility: GPUShaderStage.VERTEX | GPUShaderStage.FRAGMENT,
    buffer: { type: 'uniform', hasDynamicOffset: true, minBindingSize: GPU_USTEP } }] });
  const texBgls = new Map(), layouts = new Map();
  function texBgl(mask) {
    let l = texBgls.get(mask);
    if (!l) {
      const entries = [];
      for (let k = 0; k < GPU_STAGES; k++) if (mask >> k & 1) {
        entries.push({ binding: 2 * k, visibility: GPUShaderStage.FRAGMENT, sampler: { type: 'filtering' } });
        entries.push({ binding: 2 * k + 1, visibility: GPUShaderStage.FRAGMENT, texture: { sampleType: 'float' } });
      }
      texBgls.set(mask, l = device.createBindGroupLayout({ entries }));
    }
    return l;
  }
  function drawLayout(mask) {
    let l = layouts.get(mask);
    if (!l) layouts.set(mask, l = device.createPipelineLayout({ bindGroupLayouts: [drawBgl, texBgl(mask)] }));
    return l;
  }
  // Unbound stage: opaque black (what Wine binds; the CPU backend in host/gpu.c does the same).
  const dummy = device.createTexture({ size: [1, 1], format: 'rgba8unorm', usage: GPUTextureUsage.TEXTURE_BINDING | GPUTextureUsage.COPY_DST });
  device.queue.writeTexture({ texture: dummy }, new Uint8Array([0, 0, 0, 255]), { bytesPerRow: 4 }, [1, 1]);
  const dummyView = dummy.createView();
  const samplers = new Map();
  function sampler(key, w, t) {
    let s = samplers.get(key);
    if (s) return s;
    const filt = f => f >= 2 ? 'linear' : 'nearest', mip = w[t + T_MIP], min = w[t + T_MIN], mag = w[t + T_MAG];
    const d = { addressModeU: ADDRESS[w[t + T_AU]], addressModeV: ADDRESS[w[t + T_AV]], magFilter: filt(mag), minFilter: filt(min),
      mipmapFilter: mip ? 'linear' : 'nearest' };     // sharper textures at a distance than the game asked for
    if (!d.addressModeU || !d.addressModeV) fail(`texture address ${w[t + T_AU]}/${w[t + T_AV]}`);
    if (!mip) d.lodMaxClamp = 0;            // D3DTEXF_NONE: level 0 only
    if (min >= 2 && mag >= 2 && mip) d.maxAnisotropy = Math.min(16, matchMedia('(pointer: coarse)').matches ? 8 : 16);
    samplers.set(key, s = device.createSampler(d));
    return s;
  }
  const bindCache = new Map();              // stages' textures and samplers -> group 1; emptied when a texture goes
  function texBind(w, a, mask) {
    let key = mask, sk = ['', '', '', ''];
    for (let k = 0; k < GPU_STAGES; k++) if (mask >> k & 1) {
      const t = a + D_TEX + D_TEXN * k;
      sk[k] = (w[t + T_AU] << 4 | w[t + T_AV]) << 12 | w[t + T_MAG] << 8 | w[t + T_MIN] << 4 | w[t + T_MIP] | w[t + T_ANISO] << 20;
      key += ':' + w[t + T_ID] + ',' + sk[k];
    }
    let b = bindCache.get(key);
    if (!b) {
      const entries = [];
      for (let k = 0; k < GPU_STAGES; k++) if (mask >> k & 1) {
        const t = a + D_TEX + D_TEXN * k, r = res.get(w[t + T_ID]);
        entries.push({ binding: 2 * k, resource: sampler(sk[k], w, t) });
        entries.push({ binding: 2 * k + 1, resource: r ? r.view : dummyView });
      }
      bindCache.set(key, b = device.createBindGroup({ layout: texBgl(mask), entries }));
    }
    return b;
  }
  const pipes = new Map();    // key -> pipeline; keys still compiling; keys the device refused
  function blendState(w, a) {
    if (!w[a + D_BLEND]) return undefined;
    const src = w[a + D_SRCB], dst = w[a + D_DSTB], op = w[a + D_BOP];
    let s = BLEND[src], d = BLEND[dst];
    if (src === 12) { s = 'src-alpha'; d = 'one-minus-src-alpha'; }         // BOTHSRCALPHA
    if (src === 13) { s = 'one-minus-src-alpha'; d = 'src-alpha'; }         // BOTHINVSRCALPHA
    if (op >= 4) { s = 'one'; d = 'one'; }                                  // MIN/MAX ignore the factors
    if (!s || !d || !BLENDOP[op]) fail(`blend ${src}/${dst}/${op}`);
    const color = { srcFactor: s, dstFactor: d, operation: BLENDOP[op] };
    return { color, alpha: color };
  }
  function pipeline(w, a, hasDepth) {
    const key = sampleCount + ':' + w[a + D_VS] + ',' + w[a + D_PS] + ',' + w[a + D_DECL] + ',' + w[a + D_STRIDE] + ',' + w[a + D_TOPO] + ',' +
      (hasDepth ? (w[a + D_ZEN] ? 1 + w[a + D_ZWRITE] * 2 + w[a + D_ZFUNC] * 4 : 16 * 4) : -1) + ',' + w[a + D_CULL] + ',' +
      (w[a + D_BLEND] ? w[a + D_SRCB] + ',' + w[a + D_DSTB] + ',' + w[a + D_BOP] : '') + ',' + w[a + D_CWRITE];
    const p = pipes.get(key);
    if (p) return p;
    const vs = shaders.get(w[a + D_VS]), ps = shaders.get(w[a + D_PS]), decl = decls.get(w[a + D_DECL]);
    if (!vs || !ps || !decl) fail('draw with an unknown shader or declaration');
    const attributes = [];
    for (let k = 0; k < 16; k++) {
      const inp = vs.inputs[k];
      if (!inp) continue;
      const usage = (inp >>> 8) & 255, index = inp & 255;
      const e = decl.find(e => e.stream === 0 && e.usage === usage && e.index === index);
      if (!e) fail(`vs input v${k} (usage ${usage}/${index}) not in the declaration`);
      if (!VFMT[e.type]) fail(`vertex element type ${e.type}`);
      attributes.push({ shaderLocation: k, offset: e.offset, format: VFMT[e.type] });
    }
    const topo = { 2: 'line-list', 3: 'line-strip', 4: 'triangle-list', 5: 'triangle-strip' }[w[a + D_TOPO]] || fail(`topology ${w[a + D_TOPO]}`);
    const cull = w[a + D_CULL] === 3 ? 'back' : w[a + D_CULL] === 2 ? 'front' : 'none';
    const strip = topo.endsWith('strip') ? 'uint32' : undefined;    // only drawIndexed reads it
    pk.pipes++;
    const desc = { layout: drawLayout(ps.texMask),
      vertex: { module: vs.module, entryPoint: 'main', buffers: [{ arrayStride: w[a + D_STRIDE], attributes }] },
      fragment: { module: ps.module, entryPoint: 'main',
        targets: [{ format: 'rgba8unorm', blend: blendState(w, a), writeMask: w[a + D_CWRITE] & 15 }] },
      // D3D front faces are clockwise on screen; CULL_CCW (the default) culls the back ones.
      primitive: { topology: topo, frontFace: 'cw', cullMode: cull, stripIndexFormat: strip },
      multisample: { count: sampleCount },
      depthStencil: hasDepth ? { format: 'depth24plus-stencil8', depthWriteEnabled: !!(w[a + D_ZEN] && w[a + D_ZWRITE]),
        depthCompare: w[a + D_ZEN] ? CMP[w[a + D_ZFUNC]] : 'always' } : undefined };
    const compiled = device.createRenderPipeline(desc);
    pipes.set(key, compiled);
    return compiled;
  }

  // ---- encoder and passes -----------------------------------------------------------------------------
  // writeTexture runs at queue time, before the commands of the encoder still being recorded: a texture changed after a
  // draw that used it ends the encoder first (encN stamps which one used it).
  let enc = null, encN = 1, pass = null;
  const ibuf = device.createBuffer({ size: 4, usage: GPUBufferUsage.INDEX });
  const encoder = () => enc || (enc = device.createCommandEncoder());
  function endPass() { if (pass) { pass.end(); pass = null; } }
  function flushEnc() {
    endPass();
    if (enc) { device.queue.submit([enc.finish()]); enc = null; encN++; }
  }
  // Max's own targets are never drawn here (only player draws reach Speed's scene), so its clears are only counted.
  function clear() { pk.clears++; }
  function capture(h, f32, a, slot, player) {
    stats.seen++;
    if (!player) { stats.noPlayer++; return; }
    const decl = decls.get(h[a + D_DECL]);
    const pos = decl?.find(e => e.stream === 0 && e.usage === 0 && e.index === 0);
    if (!pos || pos.type !== 2) { stats.notXyz++; return; } // XYZ only: exclude pretransformed loading/menu/HUD draws
    const up = h[slot + 6] + h[a + D_UOFF], vp = h[slot + 2] + h[a + D_VOFF];
    const uniform = new Float32Array(M.HEAPU8.slice(up, up + GPU_USTEP).buffer);
    const wv = transpose(Array.from(uniform.subarray(16, 32)));
    if (!view) { stats.noView++; return; }
    const near = q => Math.hypot(...[0, 1, 2].map(k => q[k] - player.pos[k]));
    const distance = w => near(w.slice(12, 15));
    const world = mul(wv, view.inv);
    const dW = distance(world);
    stats.nearestW = Math.min(stats.nearestW, dW);
    if (!(dW <= 30)) { stats.far++; return; }   // cheap cut before reading vertices: a body's root is within a metre or two of its bounds
    const n = h[a + D_NVERT], stride = h[a + D_STRIDE];
    const vertices = M.HEAPU8.slice(vp, vp + n * stride), v = new DataView(vertices.buffer);
    const lo = [Infinity, Infinity, Infinity], hi = [-Infinity, -Infinity, -Infinity];
    for (let i = 0; i < n; i++) for (let k = 0; k < 3; k++) {
      const x = v.getFloat32(i * stride + pos.offset + k * 4, true);
      lo[k] = Math.min(lo[k], x); hi[k] = Math.max(hi[k], x);
    }
    // Skinned vertices are in the root object's space and W is its object-to-world (0x57d510:276-345, setupPass 0x10415ef0:210-212),
    // so the player test uses the bounds centre carried through W.
    const c = [0, 1, 2].map(k => (lo[k] + hi[k]) / 2);
    const cw = [0, 1, 2].map(k => c[0] * world[k] + c[1] * world[4 + k] + c[2] * world[8 + k] + world[12 + k]);
    const dC = near(cw);
    stats.nearest = Math.min(stats.nearest, dC);
    if (!(dC <= 1.5)) { stats.far++; return; }
    const scale = Math.max(...[0, 4, 8].map(i => Math.hypot(...world.slice(i, i + 3))));
    const radius = Math.hypot(...hi.map((x, k) => (x - lo[k]) * 0.5)) * scale;
    if (!(radius < 2.5)) { stats.big++; return; }
    const hdr = h.slice(a, a + 55), mask = shaders.get(hdr[D_PS])?.texMask || 0;
    const textures = [];
    for (let k = 0; k < GPU_STAGES; k++) if (mask >> k & 1) {
      const t = res.get(hdr[D_TEX + k * D_TEXN]);
      if (t) { t.refs = (t.refs || 0) + 1; textures.push(t); }
    }
    const indices = M.HEAPU8.slice(h[slot + 4] + hdr[D_IOFF], h[slot + 4] + hdr[D_IOFF] + hdr[D_NIDX] * 4);
    pending.push({ hdr, uniform, vertices, indices, world, lo, hi, c, radius, dW, player, textures, binding: texBind(hdr, 0, mask) });
    stats.kept++;
    if (pending.length === 1) {
      stats.view = 'dominant WV x' + stats.viewN;
      stats.world = world.slice(12, 15).map(x => x.toFixed(3)).join(',');
      stats.player = player.pos.map(x => x.toFixed(3)).join(',');
    }
  }
  function publish() {
    release(current);
    let draws = pending; pending = [];
    // Body = the draw whose W sits on the player (run 5: 0.12 m; a level piece's W is its own origin). Each draw's local = W_i * W_body^-1, then the body's lowest point and its xz centre
    // (object space, Y up) moved to the origin: the feet stand on the placement point.
    const body = draws.reduce((m, d) => !m || d.dW < m.dW ? d : m, null);
    if (body) {
      // Into the player's own frame (gamestate rot rows + pos, Y up): Max's yaw and position in his level drop out and the
      // body keeps its object-to-world tilt (run 1 of the join: W_body^-1 alone left him lying on the road). Feet = the body's lowest point there.
      const r = body.player.rot, q = body.player.pos;
      const inv = inverse([r[0], r[1], r[2], 0, r[3], r[4], r[5], 0, r[6], r[7], r[8], 0, q[0], q[1], q[2], 1]);
      const rel = inv && mul(body.world, inv);
      let low = Infinity;
      if (rel) for (let k = 0; k < 8; k++) {
        const v = [0, 1, 2].map(a => (k >> a & 1 ? body.hi : body.lo)[a]);
        low = Math.min(low, v[0] * rel[1] + v[1] * rel[5] + v[2] * rel[9] + rel[13]);
      }
      const feet = identity(); feet[13] = -low;
      for (const d of draws) d.local = inv ? mul(mul(d.world, inv), feet) : null;
    }
    // Keep the body (draws on the body's W: one skinned object) and the weapon (a small object at hand height inside the
    // body's reach); every other kept draw is a piece of Max's level that happened to be near the player.
    const same = d => d.world.every((x, k) => Math.abs(x - body.world[k]) < 1e-3);
    const inHand = d => {
      if (!d.local || d.radius > 0.6) return false;
      const q = [0, 1, 2].map(k => d.c[0] * d.local[k] + d.c[1] * d.local[4 + k] + d.c[2] * d.local[8 + k] + d.local[12 + k]);
      return q[1] > 0.5 && q[1] < 1.9 && Math.hypot(q[0], q[2]) < 0.9;
    };
    const keep = body ? draws.filter(d => same(d) || inHand(d)) : [];
    for (const d of draws) if (!keep.includes(d)) for (const t of d.textures) if (--t.refs === 0 && t.retired) retire(t.tex);
    stats.level += draws.length - keep.length;
    draws = keep;
    let nv = 0, ni = 0;
    for (const d of draws) {
      d.voff = nv; d.ioff = ni;
      nv += (d.vertices.length + 3) & ~3; ni += d.indices.length;
    }
    const vb = new Uint8Array(Math.max(4, nv)), ib = new Uint8Array(Math.max(4, ni));
    for (const d of draws) { vb.set(d.vertices, d.voff); ib.set(d.indices, d.ioff); }
    const vbuf = device.createBuffer({ size: vb.length, usage: GPUBufferUsage.VERTEX | GPUBufferUsage.COPY_DST });
    const ibuf = device.createBuffer({ size: ib.length, usage: GPUBufferUsage.INDEX | GPUBufferUsage.COPY_DST });
    device.queue.writeBuffer(vbuf, 0, vb); device.queue.writeBuffer(ibuf, 0, ib);
    current = { draws, vbuf, ibuf };
  }
  // Public render hook: called with Speed's scene attachments before its HUD/postprocessing.
  function encode(encoder, colorView, depthView, samples) {
    const frame = reader.frame;
    if (!current?.draws.length || !frame) return;
    sampleCount = samples;
    const bytes = new Uint8Array(GPU_USTEP * current.draws.length), valid = [];
    for (let i = 0; i < current.draws.length; i++) {
      const d = current.draws[i], u = new Float32Array(bytes.buffer, GPU_USTEP * i, GPU_USTEP / 4);
      u.set(d.uniform);
      if (d.local && reproject(u, d.local, frame)) valid.push([d, i]);
    }
    if (!valid.length) return;
    const uniform = device.createBuffer({ size: bytes.length, usage: GPUBufferUsage.UNIFORM | GPUBufferUsage.COPY_DST });
    device.queue.writeBuffer(uniform, 0, bytes);
    const bind = device.createBindGroup({ layout: drawBgl, entries: [{ binding: 0, resource: { buffer: uniform, size: GPU_USTEP } }] });
    const pass = encoder.beginRenderPass({
      colorAttachments: [{ view: colorView, resolveTarget: frame.resolveTarget, loadOp: 'load', storeOp: 'store' }],
      depthStencilAttachment: { view: depthView, depthLoadOp: 'load', depthStoreOp: 'store', stencilLoadOp: 'load', stencilStoreOp: 'store' },
    });
    pass.setViewport(0, 0, frame.width, frame.height, 0, 1);
    pass.setScissorRect(0, 0, frame.width, frame.height);
    pass.setIndexBuffer(current.ibuf, 'uint32');
    for (const [d, i] of valid) {
      const p = pipeline(d.hdr, 0, true);
      pass.setPipeline(p); pass.setBindGroup(0, bind, [i * GPU_USTEP]); pass.setBindGroup(1, d.binding);
      pass.setVertexBuffer(0, current.vbuf, d.voff, d.vertices.length);
      if (d.hdr[D_NIDX]) pass.drawIndexed(d.hdr[D_NIDX], 1, d.ioff >>> 2);
      else pass.draw(d.hdr[D_NVERT]);
    }
    pass.end();
    retire(uniform);
  }
  // One packet, in order.
  function run(slot) {
    const h = M.HEAPU32, f32 = new Float32Array(h.buffer), u8 = M.HEAPU8, s = box + B_SLOT + slot * B_SLOTN;
    const blob = h[s + 8], end = (h[s] >>> 2) + h[s + 1];
    const player = maxPlayer(M);
    stats.packets++;
    // V = the WV most draws of this packet share: static level geometry has W = identity (or its room's transform, the frame of
    // the gamestate position), so its WV is the view. Kept across packets; replaced when a packet has 16+ draws on one WV.
    const count = new Map();
    for (let i = h[s] >>> 2; i < end;) {
      const op = h[i] & 255, a = i + 1;
      i = a + (h[i] >>> 8);
      if (op !== GPU_DRAW) continue;
      const up = (h[s + 6] + h[a + D_UOFF]) >>> 2, key = Array.from(f32.subarray(up + 16, up + 32), x => x.toFixed(3)).join(',');
      count.set(key, (count.get(key) || 0) + 1);
    }
    let best = null, bestN = 0;
    for (const [k, n] of count) if (n > bestN) { best = k; bestN = n; }
    if (bestN >= 16) {
      const v = transpose(best.split(',').map(Number)), inv = inverse(v);
      if (inv) { view = { v, inv }; stats.viewN = bestN; }
    }
    if (player && view) stats.cam = Math.hypot(...[0, 1, 2].map(k => view.inv[12 + k] - player.pos[k])).toFixed(1);
    for (let i = h[s] >>> 2; i < end;) {
      const op = h[i] & 255, a = i + 1;
      i = a + (h[i] >>> 8);
      switch (op) {
      case GPU_DRAW: capture(h, f32, a, s, player); break;
      case GPU_CLEAR: clear(h, f32, a); break;
      case GPU_TEXDATA: {
        const t = res.get(h[a]);
        if (!t) fail(`data for texture ${h[a]}`);
        if (t.used === encN) flushEnc();
        const w = h[a + 2], th = h[a + 3], p = blob + h[a + 4];
        pk.texKb += (4 * w * th) >> 10;
        device.queue.writeTexture({ texture: t.tex, mipLevel: h[a + 1] }, u8.subarray(p, p + 4 * w * th), { bytesPerRow: 4 * w, rowsPerImage: th }, [w, th]);
        break;
      }
      case GPU_TEXTURE: {
        free(h[a]);
        const tex = device.createTexture({ size: [h[a + 1], h[a + 2]], mipLevelCount: h[a + 3], format: COLOR,
          usage: GPUTextureUsage.TEXTURE_BINDING | GPUTextureUsage.COPY_DST | GPUTextureUsage.COPY_SRC });
        res.set(h[a], { tex, view: tex.createView(), w: h[a + 1], h: h[a + 2] });
        break;
      }
      case GPU_TARGET: {
        pk.targets++;
        free(h[a]);
        const depth = h[a + 3] !== 0;
        const tex = device.createTexture({ size: [h[a + 1], h[a + 2]], format: depth ? DEPTH : COLOR,
          usage: GPUTextureUsage.RENDER_ATTACHMENT | (depth ? 0 : GPUTextureUsage.TEXTURE_BINDING | GPUTextureUsage.COPY_SRC) });
        res.set(h[a], { tex, view: tex.createView(), w: h[a + 1], h: h[a + 2], depth });
        break;
      }
      case GPU_FREE: free(h[a]); break;
      case GPU_SHADER: {
        pk.shaders++;
        const n = h[a + 2], m = h[a + 3], p = (a + 21 + n) * 4;
        shaders.set(h[a], { module: device.createShaderModule({ code: new TextDecoder().decode(u8.slice(p, p + m)) }),
          inputs: Array.from(h.subarray(a + 4, a + 20)), texMask: h[a + 20] });
        break;
      }
      case GPU_DECL: {
        const list = [];
        for (let k = 0; k < h[a + 1]; k++) {
          const w0 = h[a + 2 + 2 * k], w1 = h[a + 3 + 2 * k];
          list.push({ stream: w0 & 0xffff, offset: w0 >>> 16, type: w1 & 255, usage: w1 >>> 16 & 255, index: w1 >>> 24 });
        }
        decls.set(h[a], list);
        break;
      }
      case GPU_GAMMA: {
        const r = (blob + h[a]) >>> 1, h16 = new Uint16Array(h.buffer);
        for (let k = 0; k < 256; k++) for (let c = 0; c < 3; c++) lutData[4 * k + c] = h16[r + 256 * c + k] >>> 8;
        device.queue.writeTexture({ texture: lut }, lutData, { bytesPerRow: 1024 }, [256, 1]);
        break;
      }
      case GPU_PRESENT: {
        flushEnc();
        publish();
        unshown++;
        break;
      }
      case GPU_READ: read(h, a); break;
      default: fail(`unknown command ${op}`);
      }
    }
    flushEnc();
  }
  function free(id) {
    const t = res.get(id);
    if (!t) return;
    if (t.used === encN) flushEnc();
    t.retired = true;
    if (!t.refs) retire(t.tex);
    res.delete(id);
    bindCache.clear();
  }
  // The rows reach the guest when the GPU has drawn them; the game thread waits on box.reads.
  function read(h, a) {
    const t = res.get(h[a]), level = h[a + 1], w = h[a + 2], th = h[a + 3], dst = h[a + 4];
    endPass();
    const row = (4 * w + 255) & ~255;
    pk.reads++;
    const buf = device.createBuffer({ size: row * th, usage: GPUBufferUsage.MAP_READ | GPUBufferUsage.COPY_DST });
    encoder().copyTextureToBuffer({ texture: t.tex, mipLevel: level }, { buffer: buf, bytesPerRow: row }, [w, th]);
    flushEnc();
    buf.mapAsync(GPUMapMode.READ).then(() => {
      const src = new Uint8Array(buf.getMappedRange());
      for (let r = 0; r < th; r++) M.HEAPU8.set(src.subarray(r * row, r * row + 4 * w), dst + r * 4 * w);
    }).catch(e => report('STOP gpu.js: read failed: ' + e.message)).finally(() => {   // a lost device still frees the game
      buf.destroy();
      Atomics.add(M.HEAP32, box + B_READS, 1);
      Atomics.notify(M.HEAP32, box + B_READS);
    });
  }

  const ch = new MessageChannel(), yields = [];
  ch.port1.onmessage = () => yields.shift()?.();
  const yieldTask = () => new Promise(f => { yields.push(f); ch.port2.postMessage(0); });
  async function pump() {
    let task = performance.now();
    for (;;) {
      const h = M.HEAP32, seq = Atomics.load(h, box + B_SEQ), done = Atomics.load(h, box + B_DONE);
      if (done !== seq) {
        run(done % GPU_SLOTS);
        Atomics.store(M.HEAP32, box + B_DONE, done + 1);
        Atomics.notify(M.HEAP32, box + B_DONE);
        if (performance.now() - task > 8) { await yieldTask(); task = performance.now(); }
        continue;
      }
      const r = Atomics.waitAsync(h, box + B_SEQ, seq);
      if (r.async) { await r.value; task = performance.now(); }
    }
  }
  pump().catch(e => report('STOP ' + e.message + '\n' + e.stack));
  return reader;
}

