'use strict';
// NFSU2 city geometry drawn inside the NFSU1 Free Run scene (world only: no collision, no textures, no traffic).
// Same path as F-Max (web/maxpayne/boot.js): web/gpu.js calls Ug2.scene() at GPU_FXAA, when the scene colour and depth are bound and
// the HUD has not started; host/d3d9.c mc_hook has just copied the player's View and Projection into rn_mc.view / rn_mc.proj
// (host/mc.h, D3D row vectors, clip = v * V * P), which is what is read here. Remaster only (RN_MODE), like the MC lane.
// Mesh: web/ug2/city.bin or city_lod.bin, plus web/ug2/bridge.bin: 'UG2M', u32 nverts, u32 nidx, u32 0; nverts x (f32 xyz, u8 rgba); nidx x u32 triangle list.
(() => {
  // THE placement (one line to change): UG2 world units -> NFSU1 world (metres, z up, same units, no axis swap): p' = Rz(yaw) * p + (tx, ty, tz).
  // OWNER 2026-11-10, docs/re/ug2_bridge.md rank 1: rotate R270 (x,y)->(y,-x) = yaw -pi/2 (column0 (0,-1), column1 (1,0)), then t.
  // Same constant as the collision writer (slice/ug2coll); keeps every vertex inside the +-4096 collision range (s16/8 rows).
  const PLACE = { tx: -1287.375, ty: 812.25, tz: -6.203125, yaw: -Math.PI / 2 };   // quantized as in the collision file (tools/ug2_collfile.py)
  const FAR = 6000;            // this pass only: the game's far plane would clip a city this big (the depth test still matches: n << f)
  const FOG = [0.035, 0.045, 0.085], FOG_DENSITY = 1 / 900;   // night haze, exp2 fog

  const shader = `
struct U { view: mat4x4<f32>, proj: mat4x4<f32>, model: mat4x4<f32>, fog: vec4f };
@group(0) @binding(0) var<uniform> u: U;
struct O { @builtin(position) pos: vec4f, @location(0) col: vec3f, @location(1) world: vec3f, @location(2) dist: f32 };
@vertex fn vs(@location(0) p: vec3f, @location(1) c: vec4f) -> O {
  var o: O;
  let w = u.model * vec4f(p, 1);
  let v = u.view * w;
  o.pos = u.proj * v; o.col = c.rgb; o.world = w.xyz; o.dist = length(v.xyz);
  return o;
}
@fragment fn fs(i: O) -> @location(0) vec4f {
  // Flat face normal from screen derivatives, a cold moon from above-left, sodium-warm fill from below: night, no textures.
  let n = normalize(cross(dpdx(i.world), dpdy(i.world)));
  let moon = max(dot(n, normalize(vec3f(-0.4, 0.3, 0.85))), 0.0);
  let street = max(-n.z, 0.0) * 0.1;
  let lit = i.col * (vec3f(0.14, 0.16, 0.24) + vec3f(0.20, 0.24, 0.36) * moon + vec3f(0.30, 0.18, 0.08) * street);
  let f = 1.0 - exp(-(i.dist * u.fog.w) * (i.dist * u.fog.w));
  return vec4f(mix(lit, u.fog.xyz, f), 1.0);
}`;

  // Remaster only; ?ug2=0 turns it off.
  // One line to the console and to the page log (#log, which tools/webcheck.mjs prints).
  const say = t => { console.log(t); const l = document.getElementById('log'); if (l) { const d = document.createElement('div'); d.textContent = t; l.appendChild(d); } };
  const api = window.Ug2 = { on: RN_MODE === 'remaster' && RN_Q.get('ug2') !== '0', state: 'idle' };
  let device, mesh, pipes = new Map(), bind, uniform, module, loading = false;

  // One UG2M file -> {nv, ni, vb, ib}, or null when it is missing or not a UG2M mesh.
  async function read(name) {
    const r = await fetch('/ug2/' + name).catch(() => null);
    if (!r?.ok) return null;
    const b = await r.arrayBuffer(), h = new Uint32Array(b, 0, 4);
    if (new TextDecoder().decode(new Uint8Array(b, 0, 4)) !== 'UG2M' || b.byteLength !== 16 + 16 * h[1] + 4 * h[2]) { console.warn('ug2:', name, 'is not a UG2M mesh'); return null; }
    say(`ug2: ${name} ${h[1]} verts ${h[2] / 3} tris`);
    return { nv: h[1], ni: h[2], vb: new Uint8Array(b, 16, 16 * h[1]), ib: new Uint32Array(b, 16 + 16 * h[1], h[2]) };
  }

  // The city (city.bin, else city_lod.bin) plus the bridge deck (bridge.bin, tools/ug2_collfile.py): both raw UG2 units, one PLACE, one draw.
  async function load() {
    const city = await read('city.bin') || await read('city_lod.bin'), bridge = await read('bridge.bin');
    if (!city) { say('ug2: no web/ug2/city.bin or city_lod.bin, nothing drawn'); return null; }
    if (!bridge) return city;
    const vb = new Uint8Array(city.vb.length + bridge.vb.length), ib = new Uint32Array(city.ni + bridge.ni);
    vb.set(city.vb); vb.set(bridge.vb, city.vb.length);
    ib.set(city.ib); for (let k = 0; k < bridge.ni; k++) ib[city.ni + k] = bridge.ib[k] + city.nv;
    return { nv: city.nv + bridge.nv, ni: city.ni + bridge.ni, vb, ib };
  }

  function setup(dev, m) {
    device = dev;
    const make = (data, usage) => { const buf = device.createBuffer({ size: (data.byteLength + 3) & ~3, usage: usage | GPUBufferUsage.COPY_DST }); device.queue.writeBuffer(buf, 0, data); return buf; };
    mesh = { ...m, vbuf: make(m.vb, GPUBufferUsage.VERTEX), ibuf: make(m.ib, GPUBufferUsage.INDEX) };
    uniform = device.createBuffer({ size: 64 * 3 + 16, usage: GPUBufferUsage.UNIFORM | GPUBufferUsage.COPY_DST });
    const bgl = device.createBindGroupLayout({ entries: [{ binding: 0, visibility: GPUShaderStage.VERTEX | GPUShaderStage.FRAGMENT, buffer: { type: 'uniform' } }] });
    bind = device.createBindGroup({ layout: bgl, entries: [{ binding: 0, resource: { buffer: uniform } }] });
    module = device.createShaderModule({ code: shader });
    mesh.layout = device.createPipelineLayout({ bindGroupLayouts: [bgl] });
  }

  function pipeline(count) {
    if (pipes.has(count)) return pipes.get(count);
    const p = device.createRenderPipeline({ layout: mesh.layout,
      vertex: { module, entryPoint: 'vs', buffers: [{ arrayStride: 16, attributes: [
        { shaderLocation: 0, offset: 0, format: 'float32x3' }, { shaderLocation: 1, offset: 12, format: 'unorm8x4' }] }] },
      fragment: { module, entryPoint: 'fs', targets: [{ format: 'rgba8unorm' }] },
      // No culling: the handedness of the NFSU2 mesh is not proven; closed shells under the depth test look right either way.
      primitive: { topology: 'triangle-list', cullMode: 'none' },
      depthStencil: { format: 'depth24plus-stencil8', depthCompare: 'less-equal', depthWriteEnabled: true },
      multisample: { count } });
    pipes.set(count, p); return p;
  }

  // Called at GPU_FXAA with the scene targets (web/gpu.js res entries).
  api.scene = (dev, speed, enc, rt, ds) => {
    if (!api.on || !rt || !ds || !speed._rn_mc_state) return;
    if (!loading) {
      loading = true; api.state = 'loading';
      load().then(m => { if (m) { try { setup(dev, m); api.state = 'ready'; } catch (e) { api.state = 'failed'; console.warn('ug2 upload:', e.message); } } else api.state = 'nofile'; });
    }
    if (api.state !== 'ready') return;
    // Re-take the heap view every frame: wasm memory can grow.
    const a = speed._rn_mc_state() >>> 0, f = new Float32Array(speed.HEAPU8.buffer, a + 48, 32);
    if (!f[11 + 16]) return;       // no projection yet (m[11] of a D3D perspective matrix is 1)
    const u = new Float32Array(52);
    u.set(f);                      // View, Projection: row-major D3D row vectors read as WGSL columns = the transpose, so P_w * (V_w * p) = v * V * P
    // Far plane for this pass only: z = f/(f-n) * (1 - n/w), so only f changes (n = -m14/m10 from the game's own projection).
    const m10 = f[16 + 10], m14 = f[16 + 14], near = -m14 / m10, gameFar = m10 * near / (m10 - 1);
    u[16 + 10] = FAR / (FAR - near); u[16 + 14] = -near * FAR / (FAR - near);
    const c = Math.cos(PLACE.yaw), s = Math.sin(PLACE.yaw);
    // model, as WGSL columns: column k holds the image of axis k
    u.set([c, s, 0, 0, -s, c, 0, 0, 0, 0, 1, 0, PLACE.tx, PLACE.ty, PLACE.tz, 1], 32);
    u.set([...FOG, FOG_DENSITY], 48);
    if (!api.logged) { api.logged = true; say(`ug2: first frame, eye ${[0, 1, 2].map(j => (-(f[12] * f[4 * j] + f[13] * f[4 * j + 1] + f[14] * f[4 * j + 2])).toFixed(1))}, game near ${near.toFixed(3)} far ${gameFar.toFixed(0)} -> ${FAR}, target ${rt.w}x${rt.h} x${ds.tex.sampleCount}`); }
    device.queue.writeBuffer(uniform, 0, u);
    const pass = enc.beginRenderPass({
      colorAttachments: [{ view: rt.msView || rt.view, ...(rt.msView ? { resolveTarget: rt.view } : {}), loadOp: 'load', storeOp: 'store' }],
      depthStencilAttachment: { view: ds.view, depthLoadOp: 'load', depthStoreOp: 'store', stencilLoadOp: 'load', stencilStoreOp: 'store' } });
    pass.setPipeline(pipeline(ds.tex.sampleCount)); pass.setBindGroup(0, bind);
    pass.setVertexBuffer(0, mesh.vbuf); pass.setIndexBuffer(mesh.ibuf, 'uint32'); pass.drawIndexed(mesh.ni);
    pass.end();
  };
})();
