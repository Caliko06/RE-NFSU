// Runs the frames that host/gpu.c hands over (see host/gpu.h; the numbers below mirror it) with
// WebGPU, on the page's thread. The game thread waits in Present until the page has run the frame
// before the one it submits. Shaders arrive as WGSL (host/sm1.c); textures as RGBA8.
'use strict';
const GPU_TARGET = 1, GPU_CLEAR = 2, GPU_PRESENT = 3, GPU_DRAW = 4, GPU_SHADER = 5, GPU_DECL = 6, GPU_TEXTURE = 7,
  GPU_TEXDATA = 8;
const D_TOPO = 0, D_NVERT = 1, D_NIDX = 2, D_STRIDE = 3, D_VS = 4, D_PS = 5, D_DECL = 6, D_RT = 7, D_DS = 8, D_VP = 9,
  D_SC = 15, D_ZEN = 19, D_ZWRITE = 20, D_ZFUNC = 21, D_CULL = 22, D_BLEND = 23, D_SRCB = 24, D_DSTB = 25, D_BOP = 26,
  D_SEPA = 27, D_SRCBA = 28, D_DSTBA = 29, D_BOPA = 30, D_BFACTOR = 31, D_CWRITE = 32, D_AFUNC = 33, D_AREF = 34,
  D_FOG = 35, D_FOGC = 36, D_TEX = 37, D_TEXN = 8, D_NVC = 37 + 64, D_NPC = 38 + 64, D_HDR = 39 + 64;
const T_ID = 0, T_AU = 1, T_AV = 2, T_MAG = 3, T_MIN = 4, T_MIP = 5, T_TT = 6, T_ANISO = 7;
const U_SIZE = 4320, U_STEP = 4352;     // sm1.h SM1_U_SIZE, rounded to the 256-byte offset alignment

const CMP = [null, 'never', 'less', 'equal', 'less-equal', 'greater', 'not-equal', 'greater-equal', 'always'];
const BLEND = [null, 'zero', 'one', 'src', 'one-minus-src', 'src-alpha', 'one-minus-src-alpha', 'dst-alpha',
  'one-minus-dst-alpha', 'dst', 'one-minus-dst', 'src-alpha-saturated', null, null, 'constant', 'one-minus-constant'];
const BLENDOP = [null, 'add', 'subtract', 'reverse-subtract', 'min', 'max'];
const ADDRESS = [null, 'repeat', 'mirror-repeat', 'clamp-to-edge'];
// D3DDECLTYPE -> vertex format (the types WGSL vec4f can take). D3DCOLOR is BGRA in memory.
const VFMT = ['float32', 'float32x2', 'float32x3', 'float32x4', 'unorm8x4-bgra', null, null, null, 'unorm8x4',
  'snorm16x2', 'snorm16x4', 'unorm16x2', 'unorm16x4', null, null, 'float16x2', 'float16x4'];

async function startGpu(M, canvas, report) {
  if (!navigator.gpu) throw new Error('WebGPU no disponible');
  const adapter = await navigator.gpu.requestAdapter();
  if (!adapter) throw new Error('WebGPU: sin adaptador');
  const device = await adapter.requestDevice();
  device.addEventListener('uncapturederror', e => report('webgpu: ' + e.error.message));
  const ctx = canvas.getContext('webgpu');
  const box = M._rn_gpu_mailbox() >> 2;     // u32 index: seq, done, ptr[2], len[2]
  const H = () => M.HEAPU32;                // the view of the shared wasm memory
  const res = new Map();                    // id -> {tex, w, h, depth} (targets and textures)
  const shaders = new Map(), decls = new Map();
  let canvasSize = '';
  const fail = msg => { throw new Error('gpu.js: ' + msg); };

  // Clear of a rectangle: a full-screen triangle under a scissor, writing the color, depth and
  // stencil the D3DCLEAR flags ask for. Uniforms come from a ring with 256-byte steps.
  const clearShader = device.createShaderModule({ code: `
    struct U { color: vec4f, z: f32 };
    @group(0) @binding(0) var<uniform> u: U;
    @vertex fn vs(@builtin(vertex_index) i: u32) -> @builtin(position) vec4f {
      let p = vec2f(f32((i << 1u) & 2u), f32(i & 2u)) * 2.0 - 1.0;
      return vec4f(p, u.z, 1.0);
    }
    struct O { @location(0) c: vec4f };
    @fragment fn fs() -> O { return O(u.color); }
    @fragment fn fs_none() {}` });
  const clearRing = device.createBuffer({ size: 256 * 1024, usage: GPUBufferUsage.UNIFORM | GPUBufferUsage.COPY_DST });
  const clearBgl = device.createBindGroupLayout({ entries: [{ binding: 0, visibility: GPUShaderStage.VERTEX | GPUShaderStage.FRAGMENT,
    buffer: { type: 'uniform', hasDynamicOffset: true, minBindingSize: 32 } }] });
  const clearBind = device.createBindGroup({ layout: clearBgl, entries: [{ binding: 0, resource: { buffer: clearRing, size: 32 } }] });
  const clearLayout = device.createPipelineLayout({ bindGroupLayouts: [clearBgl] });
  const clearPipes = new Map();
  function clearPipe(hasColor, hasDepth, flags) {
    const key = `${hasColor}${hasDepth}${flags}`;
    if (clearPipes.has(key)) return clearPipes.get(key);
    const st = { compare: 'always', passOp: (flags & 4) ? 'replace' : 'keep' };
    const p = device.createRenderPipeline({ layout: clearLayout,
      vertex: { module: clearShader, entryPoint: 'vs' },
      fragment: { module: clearShader, entryPoint: hasColor ? 'fs' : 'fs_none',
        targets: hasColor ? [{ format: 'rgba8unorm', writeMask: (flags & 1) ? GPUColorWrite.ALL : 0 }] : [] },
      primitive: { topology: 'triangle-list' },
      depthStencil: hasDepth ? { format: 'depth24plus-stencil8', depthWriteEnabled: !!(flags & 2), depthCompare: 'always',
        stencilFront: st, stencilBack: st, stencilWriteMask: (flags & 4) ? 0xff : 0 } : undefined });
    clearPipes.set(key, p);
    return p;
  }

  // ---- draws: one uniform block per draw (dynamic offset), textures + samplers in group 1 ----
  const drawBgl = device.createBindGroupLayout({ entries: [{ binding: 0, visibility: GPUShaderStage.VERTEX | GPUShaderStage.FRAGMENT,
    buffer: { type: 'uniform', hasDynamicOffset: true, minBindingSize: U_SIZE } }] });
  const texBgls = new Map();      // tex mask -> layout
  function texBgl(mask) {
    if (!texBgls.has(mask)) {
      const entries = [];
      for (let k = 0; k < 8; k++) if (mask >> k & 1) {
        entries.push({ binding: 2 * k, visibility: GPUShaderStage.FRAGMENT, sampler: { type: 'filtering' } });
        entries.push({ binding: 2 * k + 1, visibility: GPUShaderStage.FRAGMENT, texture: { sampleType: 'float' } });
      }
      texBgls.set(mask, device.createBindGroupLayout({ entries }));
    }
    return texBgls.get(mask);
  }
  const layouts = new Map();
  function drawLayout(mask) {
    if (!layouts.has(mask)) layouts.set(mask, device.createPipelineLayout({ bindGroupLayouts: [drawBgl, texBgl(mask)] }));
    return layouts.get(mask);
  }
  // Unbound stage: opaque black (what Wine binds; the D3D9 docs leave it open).
  const dummy = device.createTexture({ size: [1, 1], format: 'rgba8unorm', usage: GPUTextureUsage.TEXTURE_BINDING | GPUTextureUsage.COPY_DST });
  device.queue.writeTexture({ texture: dummy }, new Uint8Array([0, 0, 0, 255]), { bytesPerRow: 4 }, [1, 1]);
  const dummyView = dummy.createView();
  const samplers = new Map();
  function sampler(t) {
    const key = `${t[T_AU]},${t[T_AV]},${t[T_MAG]},${t[T_MIN]},${t[T_MIP]},${t[T_ANISO]}`;
    if (samplers.has(key)) return samplers.get(key);
    const au = ADDRESS[t[T_AU]], av = ADDRESS[t[T_AV]];
    if (!au || !av) fail(`texture address ${t[T_AU]}/${t[T_AV]}`);
    const filt = f => f >= 2 ? 'linear' : 'nearest';
    const d = { addressModeU: au, addressModeV: av, magFilter: filt(t[T_MAG]), minFilter: filt(t[T_MIN]),
      mipmapFilter: t[T_MIP] === 2 ? 'linear' : 'nearest' };
    if (!t[T_MIP]) d.lodMaxClamp = 0;      // D3DTEXF_NONE: level 0 only
    if ((t[T_MIN] === 3 || t[T_MAG] === 3) && t[T_MIP] === 2) d.maxAnisotropy = Math.min(16, Math.max(1, t[T_ANISO]));
    const s = device.createSampler(d);
    samplers.set(key, s);
    return s;
  }
  const pipes = new Map();
  function blendState(w) {
    if (!w[D_BLEND]) return undefined;
    const comp = (src, dst, op) => {
      let s = BLEND[src], d = BLEND[dst];
      if (src === 12) { s = 'src-alpha'; d = 'one-minus-src-alpha'; }       // BOTHSRCALPHA
      if (src === 13) { s = 'one-minus-src-alpha'; d = 'src-alpha'; }       // BOTHINVSRCALPHA
      if (!s || !d || !BLENDOP[op]) fail(`blend ${src}/${dst}/${op}`);
      if (op >= 4) { s = 'one'; d = 'one'; }                                 // MIN/MAX ignore the factors
      return { srcFactor: s, dstFactor: d, operation: BLENDOP[op] };
    };
    const color = comp(w[D_SRCB], w[D_DSTB], w[D_BOP]);
    return { color, alpha: w[D_SEPA] ? comp(w[D_SRCBA], w[D_DSTBA], w[D_BOPA]) : color };
  }
  function pipeline(w, hdr, stride) {
    const vs = shaders.get(w[hdr + D_VS]), ps = shaders.get(w[hdr + D_PS]), decl = decls.get(w[hdr + D_DECL]);
    if (!vs || !ps || !decl) fail('draw with an unknown shader or declaration');
    const g = i => w[hdr + i];
    const ds = g(D_DS) !== 0;
    const key = [g(D_VS), g(D_PS), g(D_DECL), stride, g(D_TOPO), ds, g(D_ZEN), g(D_ZWRITE), g(D_ZFUNC), g(D_CULL), g(D_BLEND),
      g(D_SRCB), g(D_DSTB), g(D_BOP), g(D_SEPA), g(D_SRCBA), g(D_DSTBA), g(D_BOPA), g(D_CWRITE)].join(',');
    if (pipes.has(key)) return pipes.get(key);
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
    const topo = g(D_TOPO) === 4 ? 'triangle-list' : g(D_TOPO) === 5 ? 'triangle-strip' : fail(`topology ${g(D_TOPO)}`);
    const cull = g(D_CULL) === 3 ? 'back' : g(D_CULL) === 2 ? 'front' : 'none';
    const st = { compare: 'always' };
    const p = device.createRenderPipeline({ layout: drawLayout(ps.texMask),
      vertex: { module: vs.module, entryPoint: 'main', buffers: [{ arrayStride: stride, attributes }] },
      fragment: { module: ps.module, entryPoint: 'main',
        targets: [{ format: 'rgba8unorm', blend: blendState(w.subarray(hdr)), writeMask: g(D_CWRITE) & 15 }] },
      // D3D9 front faces are clockwise on screen; CULL_CCW (the default) culls the back ones.
      primitive: { topology: topo, frontFace: 'cw', cullMode: cull,
        stripIndexFormat: topo === 'triangle-strip' && g(D_NIDX) ? 'uint32' : undefined },
      depthStencil: ds ? { format: 'depth24plus-stencil8', depthWriteEnabled: !!(g(D_ZEN) && g(D_ZWRITE)),
        depthCompare: g(D_ZEN) ? CMP[g(D_ZFUNC)] : 'always', stencilFront: st, stencilBack: st } : undefined });
    pipes.set(key, p);
    return p;
  }
  // Per-frame data: vertices, indices and uniforms gathered on the CPU, written once before submit.
  let vbuf = null, ibuf = null, ubuf = null, vcap = 0, icap = 0, ucap = 0;
  const grow = (buf, cap, need, usage) => {
    if (need <= cap) return [buf, cap];
    buf?.destroy();
    cap = Math.max(need, cap * 2, 1 << 20);
    return [device.createBuffer({ size: cap, usage: usage | GPUBufferUsage.COPY_DST }), cap];
  };

  function run(ptr, len) {
    const w = H().subarray(ptr >> 2, (ptr >> 2) + len);
    const f32 = new Float32Array(w.buffer, w.byteOffset, w.length);
    const u8 = new Uint8Array(w.buffer, w.byteOffset, w.length * 4);
    const enc = device.createCommandEncoder();
    const uni = new ArrayBuffer(256 * 1024), uf = new Float32Array(uni);
    let nuni = 0, stats = { clears: 0, draws: 0, present: '' };
    // First pass over the frame: sizes of the per-frame buffers.
    let vneed = 0, ineed = 0, uneed = 0;
    for (let i = 0; i < w.length;) {
      const op = w[i] & 0xff, n = w[i] >>> 8, a = i + 1;
      i += 1 + n;
      if (op === GPU_DRAW) {
        vneed += (w[a + D_NVERT] * w[a + D_STRIDE] + 3) & ~3;
        ineed += 4 * w[a + D_NIDX];
        uneed += U_STEP;
      }
    }
    [vbuf, vcap] = grow(vbuf, vcap, vneed, GPUBufferUsage.VERTEX);
    [ibuf, icap] = grow(ibuf, icap, ineed + 4, GPUBufferUsage.INDEX);
    [ubuf, ucap] = grow(ubuf, ucap, uneed + U_STEP, GPUBufferUsage.UNIFORM);
    const vdata = new Uint8Array(vneed), idata = new Uint32Array(ineed / 4 + 1), udata = new ArrayBuffer(uneed + U_STEP);
    const udw = new Uint32Array(udata), udf = new Float32Array(udata);
    const uBind = device.createBindGroup({ layout: drawBgl, entries: [{ binding: 0, resource: { buffer: ubuf, size: U_SIZE } }] });
    let voff = 0, ioff = 0, uoff = 0;
    let pass = null, passKey = '';
    const endPass = () => { if (pass) { pass.end(); pass = null; passKey = ''; } };

    for (let i = 0; i < w.length;) {
      const op = w[i] & 0xff, n = w[i] >>> 8, a = i + 1;
      i += 1 + n;
      if (op === GPU_TARGET) {
        endPass();
        const depth = w[a + 3] === 1;
        const tex = device.createTexture({ size: [w[a + 1], w[a + 2]], format: depth ? 'depth24plus-stencil8' : 'rgba8unorm',
          usage: GPUTextureUsage.RENDER_ATTACHMENT | (depth ? 0 : GPUTextureUsage.COPY_SRC | GPUTextureUsage.TEXTURE_BINDING) });
        res.get(w[a])?.tex.destroy();
        res.set(w[a], { tex, view: tex.createView(), w: w[a + 1], h: w[a + 2], depth });
      } else if (op === GPU_CLEAR) {
        endPass();
        const rt = w[a] ? res.get(w[a]) : null, ds = w[a + 1] ? res.get(w[a + 1]) : null, flags = w[a + 2];
        const c = w[a + 3], off = nuni * 256;
        if (nuni === 1024) fail('more than 1024 clears in a frame');
        uf.set([((c >>> 16) & 255) / 255, ((c >>> 8) & 255) / 255, (c & 255) / 255, (c >>> 24) / 255, f32[a + 4]], off / 4);
        nuni++;
        const p = enc.beginRenderPass({
          colorAttachments: rt ? [{ view: rt.view, loadOp: 'load', storeOp: 'store' }] : [],
          depthStencilAttachment: ds ? { view: ds.view, depthLoadOp: 'load', depthStoreOp: 'store',
            stencilLoadOp: 'load', stencilStoreOp: 'store' } : undefined });
        p.setPipeline(clearPipe(!!rt, !!ds, flags));
        p.setBindGroup(0, clearBind, [off]);
        p.setStencilReference(w[a + 5] & 0xff);
        p.setScissorRect(w[a + 6], w[a + 7], w[a + 8] - w[a + 6], w[a + 9] - w[a + 7]);
        p.draw(3);
        p.end();
        stats.clears++;
      } else if (op === GPU_SHADER) {
        const kind = w[a + 1], ntok = w[a + 2], nbytes = w[a + 3];
        const text = new TextDecoder().decode(u8.slice(4 * (a + 21 + ntok), 4 * (a + 21 + ntok) + nbytes));
        const module = device.createShaderModule({ code: text });
        const id = w[a];
        module.getCompilationInfo().then(info => {
          for (const m of info.messages) if (m.type === 'error') report(`gpu.js: shader ${id}: ${m.message} (line ${m.lineNum})`);
        });
        shaders.set(id, { kind, module, inputs: Array.from(w.subarray(a + 4, a + 20)), texMask: w[a + 20] });
      } else if (op === GPU_DECL) {
        const els = [];
        for (let k = 0; k < w[a + 1]; k++) {
          const x = w[a + 2 + 2 * k], y = w[a + 3 + 2 * k];
          els.push({ stream: x & 0xffff, offset: x >>> 16, type: y & 255, usage: (y >>> 16) & 255, index: y >>> 24 });
        }
        decls.set(w[a], els);
      } else if (op === GPU_TEXTURE) {
        res.get(w[a])?.tex.destroy();
        const tex = device.createTexture({ size: [w[a + 1], w[a + 2]], mipLevelCount: w[a + 3], format: 'rgba8unorm',
          usage: GPUTextureUsage.TEXTURE_BINDING | GPUTextureUsage.COPY_DST });
        res.set(w[a], { tex, view: tex.createView(), w: w[a + 1], h: w[a + 2], depth: false });
      } else if (op === GPU_TEXDATA) {
        // queue.writeTexture runs before this frame's commands: a texture changed after a draw of the
        // same frame that used it would show its new texels in that draw (not seen yet).
        const t = res.get(w[a]), tw = w[a + 2], th = w[a + 3];
        device.queue.writeTexture({ texture: t.tex, mipLevel: w[a + 1] }, u8.subarray(4 * (a + 4), 4 * (a + 4 + tw * th)),
          { bytesPerRow: 4 * tw }, [tw, th]);
      } else if (op === GPU_DRAW) {
        const g = k => w[a + k];
        const rt = res.get(g(D_RT)), ds = g(D_DS) ? res.get(g(D_DS)) : null;
        const key = `${g(D_RT)}/${g(D_DS)}`;
        if (key !== passKey) {
          endPass();
          pass = enc.beginRenderPass({
            colorAttachments: [{ view: rt.view, loadOp: 'load', storeOp: 'store' }],
            depthStencilAttachment: ds ? { view: ds.view, depthLoadOp: 'load', depthStoreOp: 'store',
              stencilLoadOp: 'load', stencilStoreOp: 'store' } : undefined });
          passKey = key;
        }
        const nv = g(D_NVERT), ni = g(D_NIDX), stride = g(D_STRIDE), nvc = g(D_NVC), npc = g(D_NPC);
        const ps = shaders.get(g(D_PS));
        // uniforms (sm1.h SM1_U_*)
        const ub = uoff / 4, src = a + D_HDR;
        udf.set(f32.subarray(src, src + 4 * nvc), ub);
        udf.set(f32.subarray(src + 4 * nvc, src + 4 * nvc + 4 * npc), ub + 1024);
        udf[ub + 1056] = 1 / g(D_VP + 2); udf[ub + 1057] = 1 / g(D_VP + 3);
        const fc = g(D_FOGC);
        udf[ub + 1060] = ((fc >>> 16) & 255) / 255; udf[ub + 1061] = ((fc >>> 8) & 255) / 255; udf[ub + 1062] = (fc & 255) / 255;
        udw[ub + 1064] = g(D_AFUNC); udw[ub + 1065] = g(D_FOG);
        udf[ub + 1068] = g(D_AREF) / 255;
        for (let k = 0; k < 8; k++) udw[ub + 1072 + k] = g(D_TEX + D_TEXN * k + T_TT);
        // vertices and indices
        const vsrc = 4 * (src + 4 * nvc + 4 * npc), vbytes = nv * stride;
        vdata.set(u8.subarray(vsrc, vsrc + vbytes), voff);
        if (ni) idata.set(w.subarray(src + 4 * nvc + 4 * npc + ((vbytes + 3) >> 2), src + 4 * nvc + 4 * npc + ((vbytes + 3) >> 2) + ni), ioff / 4);
        const sc = [g(D_SC), g(D_SC + 1), Math.min(g(D_SC + 2), rt.w), Math.min(g(D_SC + 3), rt.h)];
        if (sc[2] > sc[0] && sc[3] > sc[1]) {
          pass.setPipeline(pipeline(w, a, stride));
          pass.setBindGroup(0, uBind, [uoff]);
          const entries = [];
          for (let k = 0; k < 8; k++) if (ps.texMask >> k & 1) {
            const t = w.subarray(a + D_TEX + D_TEXN * k, a + D_TEX + D_TEXN * (k + 1));
            const img = t[T_ID] ? res.get(t[T_ID]) : null;
            entries.push({ binding: 2 * k, resource: sampler(t) }, { binding: 2 * k + 1, resource: img ? img.view : dummyView });
          }
          pass.setBindGroup(1, device.createBindGroup({ layout: texBgl(ps.texMask), entries }));
          pass.setViewport(g(D_VP), g(D_VP + 1), g(D_VP + 2), g(D_VP + 3), f32[a + D_VP + 4], f32[a + D_VP + 5]);
          pass.setScissorRect(sc[0], sc[1], sc[2] - sc[0], sc[3] - sc[1]);
          const bf = g(D_BFACTOR);
          if (g(D_BLEND)) pass.setBlendConstant([((bf >>> 16) & 255) / 255, ((bf >>> 8) & 255) / 255, (bf & 255) / 255, (bf >>> 24) / 255]);
          pass.setVertexBuffer(0, vbuf, voff, vbytes);
          if (ni) { pass.setIndexBuffer(ibuf, 'uint32', ioff, 4 * ni); pass.drawIndexed(ni); }
          else pass.draw(nv);
        }
        voff += (vbytes + 3) & ~3; ioff += 4 * ni; uoff += U_STEP;
        stats.draws++;
      } else if (op === GPU_PRESENT) {
        endPass();
        const t = res.get(w[a]), size = `${w[a + 1]}x${w[a + 2]}`;
        if (size !== canvasSize) {
          canvas.width = w[a + 1]; canvas.height = w[a + 2];
          ctx.configure({ device, format: 'rgba8unorm', alphaMode: 'opaque', usage: GPUTextureUsage.RENDER_ATTACHMENT | GPUTextureUsage.COPY_DST });
          canvasSize = size;
        }
        enc.copyTextureToTexture({ texture: t.tex }, { texture: ctx.getCurrentTexture() }, [w[a + 1], w[a + 2]]);
        stats.present = size;
      } else {
        fail('unknown command ' + op);
      }
    }
    endPass();
    if (nuni) device.queue.writeBuffer(clearRing, 0, uni, 0, nuni * 256);
    if (voff) device.queue.writeBuffer(vbuf, 0, vdata, 0, voff);
    if (ioff) device.queue.writeBuffer(ibuf, 0, idata, 0, ioff / 4);
    if (uoff) device.queue.writeBuffer(ubuf, 0, udata, 0, uoff);
    device.queue.submit([enc.finish()]);
    return stats;
  }

  // ?hold=N (debug): stop after the N-th Present, so a capture shows that frame (the game then waits).
  const hold = Number(new URLSearchParams(location.search).get('hold')) || 0;
  let frames = 0, presents = 0;
  function tick() {
    const h = H();
    try {
      while (Atomics.load(h, box + 1) < Atomics.load(h, box) && !(hold && presents >= hold)) {
        const k = Atomics.load(h, box + 1) + 1;
        const s = run(h[box + 2 + (k & 1)], h[box + 4 + (k & 1)]);
        frames++;
        if (s.present) presents++;
        if (frames <= 3 || frames % 300 === 0) report(`gpu.js: frame ${frames}: ${s.clears} clears, ${s.draws} draws, present ${s.present}`);
        Atomics.store(h, box + 1, k);
        Atomics.notify(M.HEAP32, box + 1);
      }
    } catch (e) {
      report(e.message);
      return;
    }
    requestAnimationFrame(tick);
  }
  requestAnimationFrame(tick);
}
