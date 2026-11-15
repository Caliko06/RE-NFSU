'use strict';
// NFSU2 city geometry drawn inside the NFSU1 Free Run scene, textured as UG2 draws its world (no traffic; collision is TRACKB1010).
// Same path as F-Max (web/maxpayne/boot.js): web/gpu.js calls Ug2.scene() at GPU_FXAA, when the scene colour and depth are bound and
// the HUD has not started; host/d3d9.c mc_hook has just copied the player's View and Projection into rn_mc.view / rn_mc.proj
// (host/mc.h, D3D row vectors, clip = v * V * P), which is what is read here. WORLD only: the game's track id 1010 (rn_mc.track), in any mode (Original: the main menu's WORLD button or ?pool=1 reaches it; nothing is fetched before).
// Files (tools/ug2_world.py, tools/ug2_collfile.py, tools/ug2_tex.py; facts census/ug2/tex.md):
//   city.bin, bridge.bin 'UG2M': u32 nverts, u32 nidx, u32 0; nverts x (f32 xyz, u8 rgba); nidx x u32 triangle list
//   city_tex.bin, bridge_tex.bin 'UG2T': u32 nverts, ntri, ntex, nmat; nverts x (f32 u, v); ntri x u16 texture (0xffff none); ntri x u16 material
//   tex.json textures[i] = {file, w, h, alpha_test, blend}; tex/<hash>.png RGBA mip 0
(() => {
  // THE placement (one line to change): UG2 world units -> NFSU1 world (metres, z up, same units, no axis swap): p' = Rz(yaw) * p + (tx, ty, tz).
  // OWNER 2026-11-10, docs/re/ug2_bridge.md rank 1: rotate R270 (x,y)->(y,-x) = yaw -pi/2 (column0 (0,-1), column1 (1,0)), then t.
  // Same constant as the collision writer (slice/ug2coll); keeps every vertex inside the +-4096 collision range (s16/8 rows).
  const PLACE = { tx: -1287.375, ty: 812.25, tz: -6.203125, yaw: -Math.PI / 2 };   // quantized as in the collision file (tools/ug2_collfile.py)
  const WORLD_ID = 1010, TRACK_AT = 48 + 128;   // WORLD's track id (host/openworld.c); rn_mc.track sits after view and proj (host/mc.h)
  const FAR = 6000;            // this pass only: the game's far plane would clip a city this big (the depth test still matches: n << f)
  const ALPHA_REF = 0x5f / 255;   // texture record +0x55 == 1: alpha test, ALPHAREF 0x5f (state setter 0x5bcc30, census/ug2/tex.md)

  // UG2's world pixel shader, IDI_WORLD_FX in SPEED2.EXE (PE resource at file offset 0x420d70, ps_1_1 at +0x222c):
  //   tex t0; mul r0, t0, v0; add r0.xyz, r0, r0   = texture x vertex colour x 2 (alpha = texture a x vertex a), no lighting.
  // Its vertex shader passes the colour as is (mov oD0, v1) and uv + TextureOffset (add oT0, v2, c7). No fog and no UG2 sky here:
  // the city sits in NFSU1's world look (OWNER 2026-11-10), and NFSU1 PC draws no fog (its only FOGENABLE write is 0 at 0x408bb0,
  // docs/re/render_pc.md); the sky is NFSU1's own. UG2's fog tables are reference only (census/ug2/light.md).
  const shader = `
struct U { view: mat4x4<f32>, proj: mat4x4<f32>, model: mat4x4<f32> };
@group(0) @binding(0) var<uniform> u: U;
@group(1) @binding(0) var tex: texture_2d_array<f32>;
@group(1) @binding(1) var samp: sampler;
struct O { @builtin(position) pos: vec4f, @location(0) col: vec4f, @location(1) uv: vec2f, @location(2) @interpolate(flat) layer: u32 };
@vertex fn vs(@location(0) p: vec3f, @location(1) c: vec4f, @location(2) uv: vec2f, @builtin(instance_index) layer: u32) -> O {
  var o: O;
  o.pos = u.proj * (u.view * (u.model * vec4f(p, 1)));
  o.col = c; o.uv = uv; o.layer = layer;
  return o;
}
fn shade(i: O) -> vec4f {
  let t = textureSample(tex, samp, i.uv, i.layer) * i.col;
  return vec4f(t.rgb * 2.0, t.a);
}
@fragment fn fs(i: O) -> @location(0) vec4f { return shade(i); }
@fragment fn fs_test(i: O) -> @location(0) vec4f {
  let c = shade(i);
  if (c.a < ${ALPHA_REF}) { discard; }
  return c;
}`;
  // Mip maker: one full-screen triangle sampling the level above (linear).
  const blit = `
@group(0) @binding(0) var src: texture_2d<f32>;
@group(0) @binding(1) var samp: sampler;
struct O { @builtin(position) pos: vec4f, @location(0) uv: vec2f };
@vertex fn vs(@builtin(vertex_index) i: u32) -> O {
  let p = vec2f(f32((i << 1u) & 2u), f32(i & 2u));
  var o: O; o.pos = vec4f(p * 2.0 - 1.0, 0, 1); o.uv = vec2f(p.x, 1.0 - p.y); return o;
}
@fragment fn fs(i: O) -> @location(0) vec4f { return textureSample(src, samp, i.uv); }`;

  // Remaster, or any mode once the race's track id is 1010 (scene() sees it each frame; before that Original has it off: nothing fetched, no depth kept); ?ug2=0 turns it off, ?ug2tex=0 draws vertex colour x 2 only (the untextured baseline).
  // One line to the page log (web/boot.js line(): the page and build/webcheck.log through tools/serve.py).
  const say = t => line(t);
  const allowed = RN_Q.get('ug2') !== '0';
  let world = false;   // the race's track id is 1010 (scene() reads it before anything else)
  const api = window.Ug2 = { get on() { return allowed && (RN_MODE === 'remaster' || world); }, state: 'idle' };
  const TEXTURED = RN_Q.get('ug2tex') !== '0';
  let device, gpu, loading = false;

  // Prepared by tools/pack_loadfast.py. Explicit gzip works on plain static hosts too.
  async function packed(name) {
    const r = await fetch('/ug2/' + name + '.gz');
    if (!r.ok) throw new Error(`${name}.gz: HTTP ${r.status}; run tools/pack_loadfast.py`);
    return new Response(r.body.pipeThrough(new DecompressionStream('gzip'))).arrayBuffer();
  }
  async function textures() {
    const b = await packed('tex.pack'), n = new DataView(b).getUint32(0, true);
    const index = JSON.parse(new TextDecoder().decode(new Uint8Array(b, 4, n)));
    const blob = new Blob([new Uint8Array(b, 4 + n)]);
    return file => { const [at, len] = index[file]; return blob.slice(at, at + len, 'image/png'); };
  }
  // One UG2M file -> {nv, ni, vb, ib}, or null when it is not a UG2M mesh.
  async function read(name) {
    const b = await packed(name), h = new Uint32Array(b, 0, 4);
    if (new TextDecoder().decode(new Uint8Array(b, 0, 4)) !== 'UG2M' || b.byteLength !== 16 + 16 * h[1] + 4 * h[2]) { console.warn('ug2:', name, 'is not a UG2M mesh'); return null; }
    say(`ug2: ${name} ${h[1]} verts ${h[2] / 3} tris`);
    return { nv: h[1], ni: h[2], vb: new Uint8Array(b, 16, 16 * h[1]), ib: new Uint32Array(b, 16 + 16 * h[1], h[2]) };
  }

  // city_tex.bin -> {uv Float32Array (2 per vertex), tri Uint16Array (texture per triangle)}, only when it matches city.bin.
  async function readSide(city, name = 'city_tex.bin') {
    const b = await packed(name), h = new Uint32Array(b, 0, 5);
    if (new TextDecoder().decode(new Uint8Array(b, 0, 4)) !== 'UG2T' || h[1] !== city.nv || h[2] !== city.ni / 3) { say(`ug2: ${name} (${h[1]} verts, ${h[2]} tris) does not match its mesh, untextured`); return null; }
    return { uv: new Float32Array(b, 20, 2 * h[1]), tri: new Uint16Array(b, 20 + 8 * h[1], h[2]) };
  }

  // Draw classes, in draw order (0x5bcc30: +0x56 non-zero = blended and no depth write).
  const OPAQUE = 0, TEST = 1, BLEND = 2, ADD = 3;
  const klass = t => !t ? OPAQUE : t.blend === 'add' ? ADD : t.blend === 'alpha' ? BLEND : t.alpha_test ? TEST : OPAQUE;

  async function load(dev) {
    const t0 = performance.now();
    const [city, bridge, png] = await Promise.all([read('city.bin'), read('bridge.bin'), TEXTURED ? textures() : null]);
    if (!city) { say('ug2: no web/ug2/city.bin or city_lod.bin, nothing drawn'); return null; }
    const [side, bside] = TEXTURED ? await Promise.all([readSide(city), bridge ? readSide(bridge, 'bridge_tex.bin') : null]) : [null, null];
    const info = side ? (await (await fetch('/ug2/tex.json')).json()).textures : [];
    const nv = city.nv + (bridge?.nv || 0), ntri = (city.ni + (bridge?.ni || 0)) / 3;
    // Vertices, 24 B: f32 xyz, u8 rgba, f32 uv (untextured: uv 0).
    const vb = new ArrayBuffer(24 * nv), vf = new Float32Array(vb), vu = new Uint32Array(vb);
    const put = (m, base) => {
      const f = new Float32Array(m.vb.buffer, m.vb.byteOffset, m.nv * 4), w = new Uint32Array(m.vb.buffer, m.vb.byteOffset, m.nv * 4);
      for (let k = 0, o = base * 6; k < m.nv; k++, o += 6) { vf[o] = f[4 * k]; vf[o + 1] = f[4 * k + 1]; vf[o + 2] = f[4 * k + 2]; vu[o + 3] = w[4 * k + 3]; }
    };
    put(city, 0); if (bridge) put(bridge, city.nv);
    if (side) for (let k = 0; k < city.nv; k++) { vf[6 * k + 4] = side.uv[2 * k]; vf[6 * k + 5] = side.uv[2 * k + 1]; }
    if (bside) for (let k = 0, o = 6 * city.nv; k < bridge.nv; k++, o += 6) { vf[o + 4] = bside.uv[2 * k]; vf[o + 5] = bside.uv[2 * k + 1]; }
    // Textures: one 2D array per size (layer = instance index of its draws), plus a 1x1 white layer for "no texture".
    const buckets = new Map(), slot = new Int32Array(info.length + 1).fill(-1);   // texture -> bucket*65536 + layer
    const white = { w: 1, h: 1, list: [-1] }; buckets.set('1x1', white);
    const maxLayers = dev.limits.maxTextureArrayLayers;   // 256 by default: a size with more textures takes several arrays
    info.forEach((t, i) => {
      if (!t.file) return;
      let n = 0, k;
      while (buckets.get(k = `${t.w}x${t.h}#${n}`)?.list.length >= maxLayers) n++;
      if (!buckets.has(k)) buckets.set(k, { w: t.w, h: t.h, list: [] });
      buckets.get(k).list.push(i);
    });
    const blist = [...buckets.values()];
    blist.forEach((b, bi) => b.list.forEach((ti, li) => { if (ti >= 0) slot[ti] = bi * 65536 + li; }));
    // Triangles sorted by (class, bucket, layer): one draw per texture.
    const NONE = 0, key = new Uint32Array(info.length + 1);   // index info.length = no texture (white, opaque)
    const order = [];
    for (let i = 0; i <= info.length; i++) {
      const t = i < info.length && slot[i] >= 0 ? info[i] : null;
      order.push({ i, cls: klass(t), s: t ? slot[i] : NONE });
    }
    order.sort((a, b) => a.cls - b.cls || a.s - b.s);
    order.forEach((o, r) => key[o.i] = r);
    const triKey = new Uint32Array(ntri);
    for (let k = 0; k < ntri; k++) {
      const t = k < city.ni / 3 ? (side ? side.tri[k] : 0xffff) : (bside ? bside.tri[k - city.ni / 3] : 0xffff);
      triKey[k] = key[t < info.length && slot[t] >= 0 ? t : info.length];
    }
    const count = new Uint32Array(order.length + 1);
    for (let k = 0; k < ntri; k++) count[triKey[k] + 1]++;
    for (let r = 0; r < order.length; r++) count[r + 1] += count[r];
    const start = count.slice(), ib = new Uint32Array(3 * ntri), pos = count.slice(0, order.length);
    for (let k = 0; k < ntri; k++) {
      const d = 3 * pos[triKey[k]]++, cityTri = k < city.ni / 3;
      const src = cityTri ? city.ib : bridge.ib, s = cityTri ? 3 * k : 3 * k - city.ni, add = cityTri ? 0 : city.nv;
      ib[d] = src[s] + add; ib[d + 1] = src[s + 1] + add; ib[d + 2] = src[s + 2] + add;
    }
    const draws = [];
    order.forEach((o, r) => { const n = start[r + 1] - start[r]; if (n) draws.push({ cls: o.cls, bucket: o.s >> 16, layer: o.s & 0xffff, first: 3 * start[r], count: 3 * n }); });
    const tMesh = performance.now();
    // Upload the pixels: each PNG into its layer, then the mips on the GPU.
    const texs = blist.map(b => dev.createTexture({ size: [b.w, b.h, b.list.length], format: 'rgba8unorm', dimension: '2d',
      mipLevelCount: Math.floor(Math.log2(Math.max(b.w, b.h))) + 1,
      usage: GPUTextureUsage.TEXTURE_BINDING | GPUTextureUsage.COPY_DST | GPUTextureUsage.RENDER_ATTACHMENT }));
    dev.queue.writeTexture({ texture: texs[0] }, new Uint8Array([255, 255, 255, 255]), { bytesPerRow: 4 }, [1, 1, 1]);
    const jobs = []; blist.forEach((b, bi) => b.list.forEach((ti, li) => { if (ti >= 0) jobs.push([bi, li, info[ti].file]); }));
    let failed = 0;
    const worker = async () => {
      for (let j; (j = jobs.pop());) {
        const [bi, li, file] = j;
        try {
          const img = await createImageBitmap(png(file), { premultiplyAlpha: 'none', colorSpaceConversion: 'none' });
          dev.queue.copyExternalImageToTexture({ source: img }, { texture: texs[bi], origin: [0, 0, li] }, [img.width, img.height]);
          img.close();
        } catch { failed++; }
      }
    };
    await Promise.all(Array.from({ length: 16 }, worker));
    const mipPipe = dev.createRenderPipeline({ layout: 'auto', vertex: { module: dev.createShaderModule({ code: blit }), entryPoint: 'vs' },
      fragment: { module: dev.createShaderModule({ code: blit }), entryPoint: 'fs', targets: [{ format: 'rgba8unorm' }] } });
    const lin = dev.createSampler({ minFilter: 'linear', magFilter: 'linear' }), enc = dev.createCommandEncoder();
    texs.forEach(tx => {
      for (let l = 0; l < tx.depthOrArrayLayers; l++) for (let m = 1; m < tx.mipLevelCount; m++) {
        const v = o => tx.createView({ dimension: '2d', baseArrayLayer: l, arrayLayerCount: 1, baseMipLevel: o, mipLevelCount: 1 });
        const p = enc.beginRenderPass({ colorAttachments: [{ view: v(m), loadOp: 'clear', storeOp: 'store' }] });
        p.setPipeline(mipPipe);
        p.setBindGroup(0, dev.createBindGroup({ layout: mipPipe.getBindGroupLayout(0), entries: [{ binding: 0, resource: v(m - 1) }, { binding: 1, resource: lin }] }));
        p.draw(3); p.end();
      }
    });
    dev.queue.submit([enc.finish()]);
    const mb = texs.reduce((a, t) => a + t.width * t.height * t.depthOrArrayLayers * 4 * 4 / 3, 0) / 1e6;
    say(`ug2: ${side ? 'textured' : 'untextured'}: ${nv} verts ${ntri} tris, ${draws.length} draws, ${info.filter(t => t.file).length} textures in ${blist.length} arrays (${mb.toFixed(0)} MB with mips, ${failed} failed), mesh ${(tMesh - t0).toFixed(0)} ms, total load ${(performance.now() - t0).toFixed(0)} ms`);
    return { vb: new Uint8Array(vb), ib, draws, texs };
  }

  function setup(dev, m) {
    device = dev;
    const make = (data, usage) => { const buf = dev.createBuffer({ size: (data.byteLength + 3) & ~3, usage: usage | GPUBufferUsage.COPY_DST }); dev.queue.writeBuffer(buf, 0, data); return buf; };
    const uniform = dev.createBuffer({ size: 64 * 3, usage: GPUBufferUsage.UNIFORM | GPUBufferUsage.COPY_DST });
    const bgl0 = dev.createBindGroupLayout({ entries: [{ binding: 0, visibility: GPUShaderStage.VERTEX, buffer: { type: 'uniform' } }] });
    const bgl1 = dev.createBindGroupLayout({ entries: [
      { binding: 0, visibility: GPUShaderStage.FRAGMENT, texture: { viewDimension: '2d-array' } },
      { binding: 1, visibility: GPUShaderStage.FRAGMENT, sampler: {} }] });
    // D3D's default address mode is WRAP and the terrain uvs are world-planar (census/ug2/tex.md): repeat, trilinear.
    const samp = dev.createSampler({ addressModeU: 'repeat', addressModeV: 'repeat', minFilter: 'linear', magFilter: 'linear', mipmapFilter: 'linear', maxAnisotropy: 8 });
    gpu = { vbuf: make(m.vb, GPUBufferUsage.VERTEX), ibuf: make(m.ib, GPUBufferUsage.INDEX), draws: m.draws, uniform, pipes: new Map(),
      module: dev.createShaderModule({ code: shader }), layout: dev.createPipelineLayout({ bindGroupLayouts: [bgl0, bgl1] }),
      bind0: dev.createBindGroup({ layout: bgl0, entries: [{ binding: 0, resource: { buffer: uniform } }] }),
      bind1: m.texs.map(t => dev.createBindGroup({ layout: bgl1, entries: [{ binding: 0, resource: t.createView({ dimension: '2d-array' }) }, { binding: 1, resource: samp }] })) };
  }

  function pipeline(cls, count) {
    const k = cls * 64 + count;
    if (gpu.pipes.has(k)) return gpu.pipes.get(k);
    const blend = cls === BLEND ? { color: { srcFactor: 'src-alpha', dstFactor: 'one-minus-src-alpha' }, alpha: { srcFactor: 'one', dstFactor: 'one-minus-src-alpha' } }
      : cls === ADD ? { color: { srcFactor: 'src-alpha', dstFactor: 'one' }, alpha: { srcFactor: 'zero', dstFactor: 'one' } } : undefined;
    const p = device.createRenderPipeline({ layout: gpu.layout,
      vertex: { module: gpu.module, entryPoint: 'vs', buffers: [{ arrayStride: 24, attributes: [
        { shaderLocation: 0, offset: 0, format: 'float32x3' }, { shaderLocation: 1, offset: 12, format: 'unorm8x4' }, { shaderLocation: 2, offset: 16, format: 'float32x2' }] }] },
      fragment: { module: gpu.module, entryPoint: cls === TEST ? 'fs_test' : 'fs', targets: [{ format: 'rgba8unorm', blend }] },
      // UG2 culls: its state setter 0x5bcd15..0x5bcd8c writes D3DRS_CULLMODE (state 0x16) only when [[0x870910]+4] == 5 (NONE for opaque, CW for blended);
      // in every other pass the D3D default CULLMODE = CCW holds, so one face of each triangle is never drawn. The light cones (SFX_LIGHT_BEAMA/B) carry
      // both windings in 171 of 244 cones (duplicated faces, only right with culling): without it every cone adds twice. Added to ADD only: a run with
      // 'cw' culling on every class removed the road (94 % of road triangles have (v1-v0)x(v2-v0).z > 0), so the visible side is 'ccw' in this frame, and
      // the other classes stay not culled because their winding was not checked (UNKNOWN).
      primitive: { topology: 'triangle-list', cullMode: cls === ADD ? 'back' : 'none', frontFace: 'ccw' },
      depthStencil: { format: 'depth24plus-stencil8', depthCompare: 'less-equal', depthWriteEnabled: cls <= TEST },
      multisample: { count } });
    gpu.pipes.set(k, p); return p;
  }

  // Frame rate while the city is drawn: one line per 600 frames, six times (load and frame cost, OWNER rule: measure before/after).
  let frames = 0, since = 0, cpu = 0, reports = 0;

  // Called at GPU_FXAA with the scene targets (web/gpu.js res entries).
  api.scene = (dev, speed, enc, rt, ds, tsw) => {
    if (!allowed || !speed._rn_mc_state) return;
    // WORLD = the race's track id 1010 (host/d3d9.c mc_hook writes it after the matrices, rn_mc.track, 0 outside a race): no load, no draw elsewhere.
    // Read first, so Original turns the pass on by itself (the depth is kept from the next frame) when the menu's WORLD button starts the race.
    world = new Int32Array(speed.HEAPU8.buffer, (speed._rn_mc_state() >>> 0) + TRACK_AT, 1)[0] === WORLD_ID;
    if (!world || !rt || !ds) return;
    if (!loading) {
      loading = true; api.state = 'loading'; say(`ug2: WORLD (track ${WORLD_ID}) in ${RN_MODE} mode, loading the city`);
      load(dev).then(m => { if (m) { try { setup(dev, m); api.state = 'ready'; } catch (e) { api.state = 'failed'; say('ug2 upload: ' + e.message); } } else api.state = 'nofile'; },
        e => { api.state = 'failed'; say('ug2 load: ' + e.message); });
    }
    if (api.state !== 'ready') return;
    const c0 = performance.now();
    // Re-take the heap view every frame: wasm memory can grow.
    const a = speed._rn_mc_state() >>> 0, f = new Float32Array(speed.HEAPU8.buffer, a + 48, 32);
    if (!f[11 + 16]) return;       // no projection yet (m[11] of a D3D perspective matrix is 1)
    const u = new Float32Array(48);
    u.set(f);                      // View, Projection: row-major D3D row vectors read as WGSL columns = the transpose, so P_w * (V_w * p) = v * V * P
    // Far plane for this pass only: z = f/(f-n) * (1 - n/w), so only f changes (n = -m14/m10 from the game's own projection).
    const m10 = f[16 + 10], m14 = f[16 + 14], near = -m14 / m10;
    u[16 + 10] = FAR / (FAR - near); u[16 + 14] = -near * FAR / (FAR - near);
    const c = Math.cos(PLACE.yaw), s = Math.sin(PLACE.yaw);
    u.set([c, s, 0, 0, -s, c, 0, 0, 0, 0, 1, 0, PLACE.tx, PLACE.ty, PLACE.tz, 1], 32);   // model, as WGSL columns: column k = image of axis k
    device.queue.writeBuffer(gpu.uniform, 0, u);
    const pass = enc.beginRenderPass({ timestampWrites: tsw?.('ug2 city'),   // GPU time of this pass in ?gpuprof=1 (gpu.js tsw)
      colorAttachments: [{ view: rt.msView || rt.view, ...(rt.msView ? { resolveTarget: rt.view } : {}), loadOp: 'load', storeOp: 'store' }],
      depthStencilAttachment: { view: ds.view, depthLoadOp: 'load', depthStoreOp: 'store', stencilLoadOp: 'load', stencilStoreOp: 'store' } });
    pass.setBindGroup(0, gpu.bind0); pass.setVertexBuffer(0, gpu.vbuf); pass.setIndexBuffer(gpu.ibuf, 'uint32');
    let cls = -1, bucket = -1;
    for (const d of gpu.draws) {
      if (d.cls !== cls) { cls = d.cls; pass.setPipeline(pipeline(cls, ds.tex.sampleCount)); }
      if (d.bucket !== bucket) { bucket = d.bucket; pass.setBindGroup(1, gpu.bind1[bucket]); }
      pass.drawIndexed(d.count, 1, d.first, 0, d.layer);
    }
    pass.end();
    const now = performance.now();
    cpu += now - c0;
    if (!since) since = now;
    if (++frames === 600 && reports < 6) {
      reports++;
      say(`ug2: ${(600 * 1000 / (now - since)).toFixed(1)} fps over 600 frames, ug2 pass ${(cpu / 1200).toFixed(2)} ms cpu per frame (${TEXTURED ? 'textured' : 'ug2tex=0'}), eye ${[0, 1, 2].map(j => (-(f[12] * f[4 * j] + f[13] * f[4 * j + 1] + f[14] * f[4 * j + 2])).toFixed(1))}`);
      frames = 0; since = now; cpu = 0;
    }
  };
})();
