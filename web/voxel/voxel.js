// Original street materials and scene-depth voxel rendering; shared layout: host/voxel.h.
'use strict';
(() => {
  const CH = 16, CELLS = 4096, SLOTS = 1024, VOX_SCALE = 1.0;
  const SLOT = 256, BLOCK = 35072, LIGHT = BLOCK + SLOTS * CELLS;
  const GLASS = 11, OIL = 13, transparent = b => b === GLASS || b === OIL;
  // Face order: +x, -x, +y, -y, +z (top), -z (bottom). Corners wind CCW outside.
  const faces = [
    [[1,0,0], [[1,0,0],[1,1,0],[1,1,1],[1,0,1]]],
    [[-1,0,0], [[0,1,0],[0,0,0],[0,0,1],[0,1,1]]],
    [[0,1,0], [[1,1,0],[0,1,0],[0,1,1],[1,1,1]]],
    [[0,-1,0], [[0,0,0],[1,0,0],[1,0,1],[0,0,1]]],
    [[0,0,1], [[0,0,1],[1,0,1],[1,1,1],[0,1,1]]],
    [[0,0,-1], [[0,1,0],[1,1,0],[1,0,0],[0,0,0]]]
  ];
  const uv = [[0,1],[1,1],[1,0],[0,0]], meshes = new Map();
  let M, pixels, gpu, cursor = 0;
  const key = (x,y,z) => `${x},${y},${z}`;
  function hash(x,y,b) {
    let h = Math.imul(x + 73, 374761393) ^ Math.imul(y + 29, 668265263) ^ Math.imul(b + 11, 1274126177);
    h = Math.imul(h ^ (h >>> 13), 1274126177);
    return ((h ^ (h >>> 16)) >>> 0) / 4294967296;
  }
  function materials() {
    const data = new Uint8Array(16 * 16 * 16 * 4);
    for (let b = 0; b < 16; b++) for (let y = 0; y < 16; y++) for (let x = 0; x < 16; x++) {
      const n = hash(x,y,b), g = n * 16 - 8;
      let c = [0,0,0], alpha = 255;
      switch (b) {
        case 0: alpha = 0; break;
        case 1: c = [22 + n*19,24 + n*19,27 + n*19]; break;
        case 2: c = x === 0 || y === 0 ? [149,151,149] : [184+g,186+g,181+g]; break;
        case 3: c = y % 5 === 0 || (x + (Math.floor(y/5)%2)*7) % 14 === 0 ? [47,44,42] : [104+g,48+g,41+g]; break;
        case 4: {
          const ridge = ((x+y)%8 === 2 && x%8 < 5) || ((x-y+16)%8 === 2 && x%8 >= 5);
          c = ridge ? [173,181,185] : [83+g,94+g,102+g]; break;
        }
        case 5: c = hash(x>>2,y>>2,b) > .48 ? [130+g,65+g,36+g] : [75+g,94+g,109+g]; break;
        case 6: {
          const ring = Math.abs(Math.hypot(x-7.5,(y%8-3.5)*1.5)-4.1) < 1.2;
          c = ring ? [31+g*.3,32+g*.3,34+g*.3] : [11,13,15]; break;
        }
        case 7: c = x%5 === 0 ? [48,33,23] : [128+g,88+g*.7,49+g*.4]; break;
        case 8: c = (x+y)%14 < 7 ? [232+g,104+g,25] : [222+g,219+g,201+g]; break;
        case 9: {
          const core = Math.max(0,1-Math.hypot(x-7.5,y-7.5)/9);
          c = [165+90*core,63+156*core,12+114*core]; break;
        }
        case 10: c = Math.abs(x-7.5) < 2 ? [250,77,218] : [37+g,13,39+g]; break;
        case 11: {
          const border = x < 2 || y < 2 || x > 13 || y > 13;
          c = border ? [135,163,176] : [151,190,207]; alpha = border ? 175 : 30; break;
        }
        case 12: {
          const stone = hash(x>>1,y>>1,b)*48;
          c = [83+stone+g,76+stone+g,63+stone+g]; break;
        }
        case 13: {
          const sheen = .5+.5*Math.sin((x+y*.6)*.8+n*.4);
          c = [13+sheen*15,15+sheen*11,22+sheen*29]; alpha = 217; break;
        }
      }
      const i = ((b*16+y)*16+x)*4;
      data[i] = c[0]; data[i+1] = c[1]; data[i+2] = c[2]; data[i+3] = alpha;
    }
    return data;
  }
  function init(module) { M = module; if (!pixels) pixels = materials(); }
  const shader = `
struct U { view: mat4x4<f32>, projection: mat4x4<f32>, tgt: vec4f };
@group(0) @binding(0) var<uniform> u: U;
@group(0) @binding(1) var atlas: texture_2d_array<f32>;
@group(0) @binding(2) var nearSampler: sampler;
struct V {
  @location(0) pos: vec3f, @location(1) uv: vec2f, @location(2) block: f32,
  @location(3) face: f32, @location(4) light: f32
};
struct Out {
  @builtin(position) pos: vec4f, @location(0) uv: vec2f,
  @location(1) @interpolate(flat) block: u32,
  @location(2) @interpolate(flat) face: u32, @location(3) @interpolate(flat) light: u32
};
@vertex fn vs(v: V) -> Out {
  var o: Out;
  o.pos = u.projection * (u.view * vec4f(v.pos,1));
  o.uv = v.uv; o.block = u32(v.block); o.face = u32(v.face); o.light = u32(v.light);
  return o;
}
@fragment fn fs(v: Out) -> @location(0) vec4f {
  let albedo = textureSample(atlas, nearSampler, v.uv, i32(v.block));
  let sky = f32(v.light >> 4u)/15.0;
  let blk = f32(v.light & 15u)/15.0;
  var shades = array<f32,6>(0.8,0.8,0.7,0.7,1.0,0.55);
  // Night street: blue-grey ambient under the open sky, sodium orange from emitting blocks.
  var colour = albedo.rgb * (vec3f(0.40,0.43,0.52)*(0.35+0.65*sky*sky)
    + vec3f(1.0,0.62,0.25)*blk*blk*1.3) * shades[v.face];
  if (v.block == 9u || v.block == 10u) { colour = albedo.rgb*1.3; }
  return vec4f(colour,albedo.a);
}
@vertex fn lineVs(@builtin(vertex_index) i: u32) -> @builtin(position) vec4f {
  var edges = array<vec2u,12>(vec2u(0,1),vec2u(2,3),vec2u(4,5),vec2u(6,7),
    vec2u(0,2),vec2u(1,3),vec2u(4,6),vec2u(5,7),vec2u(0,4),vec2u(1,5),vec2u(2,6),vec2u(3,7));
  let corner = edges[i/2u][i%2u];
  let offset = vec3f(f32(corner & 1u),f32((corner >> 1u) & 1u),f32((corner >> 2u) & 1u));
  let p = (u.tgt.xyz + offset*1.006 - vec3f(0.003))*${VOX_SCALE};
  return u.projection * (u.view * vec4f(p,1));
}
@fragment fn lineFs() -> @location(0) vec4f { return vec4f(0.94,0.96,1.0,0.7); }
`;
  function createGpu(device) {
    const atlas = device.createTexture({ size: [16,16,16], format: 'rgba8unorm',
      usage: GPUTextureUsage.TEXTURE_BINDING | GPUTextureUsage.COPY_DST });
    device.queue.writeTexture({ texture: atlas }, pixels, { bytesPerRow: 64, rowsPerImage: 16 }, [16,16,16]);
    const uniform = device.createBuffer({ size: 144, usage: GPUBufferUsage.UNIFORM | GPUBufferUsage.COPY_DST });
    const bgl = device.createBindGroupLayout({ entries: [
      { binding: 0, visibility: GPUShaderStage.VERTEX, buffer: { type: 'uniform' } },
      { binding: 1, visibility: GPUShaderStage.FRAGMENT, texture: { viewDimension: '2d-array' } },
      { binding: 2, visibility: GPUShaderStage.FRAGMENT, sampler: { type: 'filtering' } }
    ] });
    const bind = device.createBindGroup({ layout: bgl, entries: [
      { binding: 0, resource: { buffer: uniform } }, { binding: 1, resource: atlas.createView({ dimension: '2d-array' }) },
      { binding: 2, resource: device.createSampler({ minFilter: 'nearest', magFilter: 'nearest', mipmapFilter: 'nearest' }) }
    ] });
    return { uniform, bind, module: device.createShaderModule({ code: shader }),
      layout: device.createPipelineLayout({ bindGroupLayouts: [bgl] }), pipelines: new Map() };
  }
  function pipelines(device, count) {
    if (gpu.pipelines.has(count)) return gpu.pipelines.get(count);
    const blend = { color: { srcFactor: 'src-alpha', dstFactor: 'one-minus-src-alpha', operation: 'add' },
      alpha: { srcFactor: 'one', dstFactor: 'one-minus-src-alpha', operation: 'add' } };
    const make = (seeThrough, line) => device.createRenderPipeline({ layout: gpu.layout,
      vertex: { module: gpu.module, entryPoint: line ? 'lineVs' : 'vs', buffers: line ? [] : [{ arrayStride: 32, attributes: [
        { shaderLocation: 0, offset: 0, format: 'float32x3' }, { shaderLocation: 1, offset: 12, format: 'float32x2' },
        { shaderLocation: 2, offset: 20, format: 'float32' }, { shaderLocation: 3, offset: 24, format: 'float32' },
        { shaderLocation: 4, offset: 28, format: 'float32' }
      ] }] },
      fragment: { module: gpu.module, entryPoint: line ? 'lineFs' : 'fs',
        targets: [{ format: 'rgba8unorm', blend: seeThrough || line ? blend : undefined }] },
      // No culling: the game's view/projection handedness is not proven; closed cubes under the depth test look right either way.
      primitive: { topology: line ? 'line-list' : 'triangle-list', cullMode: 'none' },
      depthStencil: { format: 'depth24plus-stencil8', depthCompare: 'less-equal', depthWriteEnabled: !seeThrough && !line },
      multisample: { count }
    });
    const p = [make(false,false),make(true,false),make(true,true)];
    gpu.pipelines.set(count,p); return p;
  }
  function drop(mesh) { mesh.vb?.destroy(); mesh.ib?.destroy(); }
  // Culled faces: M. Lysenko, "Meshing in a Minecraft game" (2012), https://0fps.net/2012/06/30/meshing-in-a-minecraft-game/
  function remesh(device, bytes, base, slot, live, mesh) {
    const vertices = [], opaque = [], clear = [];
    const blockBase = base + BLOCK + slot.id*CELLS;
    for (let z = 0; z < CH; z++) for (let y = 0; y < CH; y++) for (let x = 0; x < CH; x++) {
      const block = bytes[blockBase+x+CH*(y+CH*z)];
      if (!block) continue;
      for (let face = 0; face < 6; face++) {
        const [normal,corners] = faces[face];
        const nx = x+normal[0], ny = y+normal[1], nz = z+normal[2];
        const neighbour = nx >= 0 && nx < CH && ny >= 0 && ny < CH && nz >= 0 && nz < CH ? slot
          : live.get(key(slot.x+Math.floor(nx/CH),slot.y+Math.floor(ny/CH),slot.z+Math.floor(nz/CH)));
        const cell = (nx & 15)+CH*((ny & 15)+CH*(nz & 15));
        const b = neighbour ? bytes[base+BLOCK+neighbour.id*CELLS+cell] : 0;
        if (b !== 0 && (!transparent(b) || b === block)) continue;
        const light = neighbour ? bytes[base+LIGHT+neighbour.id*CELLS+cell] : 0xf0;
        const first = vertices.length/8, indices = transparent(block) ? clear : opaque;
        for (let c = 0; c < 4; c++) vertices.push(
          (slot.x*CH+x+corners[c][0])*VOX_SCALE, (slot.y*CH+y+corners[c][1])*VOX_SCALE,
          (slot.z*CH+z+corners[c][2])*VOX_SCALE, ...uv[c], block, face, light);
        indices.push(first,first+1,first+2,first,first+2,first+3);
      }
    }
    const v = new Float32Array(vertices), indices = new Uint32Array(opaque.length+clear.length);
    indices.set(opaque); indices.set(clear,opaque.length);
    for (const [name,data,usage] of [['vb',v,GPUBufferUsage.VERTEX],['ib',indices,GPUBufferUsage.INDEX]]) {
      if (!data.byteLength) continue;
      if (!mesh[name] || mesh[name].size < data.byteLength) {
        mesh[name]?.destroy();
        mesh[name] = device.createBuffer({ size: data.byteLength, usage: usage | GPUBufferUsage.COPY_DST });
      }
      device.queue.writeBuffer(mesh[name],0,data);
    }
    mesh.opaque = opaque.length; mesh.clear = clear.length;
  }
  function draw(device, enc, rt, ds, f32, a, module) {
    init(module);
    // Re-take both heap views every frame: wasm memory can grow between frames.
    const base = M._rn_voxel_addr() >>> 0, bytes = M.HEAPU8, words = M.HEAP32;
    if (!words[(base+4)>>>2]) return;
    if (!gpu) gpu = createGpu(device);
    const live = new Map(), slots = new Map();
    for (let id = 0; id < SLOTS; id++) {
      const s = (base+SLOT+id*32)>>>2;
      if (words[s+3] !== 1) continue;
      const slot = { id, x: words[s], y: words[s+1], z: words[s+2], version: words[s+4] };
      live.set(key(slot.x,slot.y,slot.z),slot); slots.set(id,slot);
    }
    for (const [id,mesh] of meshes) {
      const slot = slots.get(id);
      if (!slot || mesh.coord !== key(slot.x,slot.y,slot.z)) { drop(mesh); meshes.delete(id); }
    }
    let budget = 4;
    for (let scanned = 0; scanned < SLOTS && budget; scanned++) {
      const id = cursor; cursor = (cursor+1)%SLOTS;
      const slot = slots.get(id); if (!slot) continue;
      const coord = key(slot.x,slot.y,slot.z);
      // Border faces also depend on neighbour versions and on chunks arriving or leaving.
      const neighbours = faces.map(([n]) => {
        const s = live.get(key(slot.x+n[0],slot.y+n[1],slot.z+n[2]));
        return s ? `${s.id}:${s.version}` : '-';
      }).join('/');
      const stamp = `${slot.version}/${neighbours}`;
      let mesh = meshes.get(id);
      if (mesh?.stamp === stamp) continue;
      if (!mesh) { mesh = { coord }; meshes.set(id,mesh); }
      remesh(device,bytes,base,slot,live,mesh); mesh.stamp = stamp; budget--;
    }
    const uniform = new Float32Array(36);
    // Row-major D3D row vectors uploaded as-is transpose into WGSL: P_w*(V_w*pos) = v*V*P.
    // WebGPU clip z is 0..1, the same as D3D; no depth remap is needed.
    uniform.set(f32.subarray(a,a+32));
    // Payload (host/voxel.h): target xyz are int32 cells; target_ok (word 35) is a flag.
    const iw = new Int32Array(f32.buffer, f32.byteOffset + 4 * (a + 32), 3);
    uniform[32] = iw[0]; uniform[33] = iw[1]; uniform[34] = iw[2];
    device.queue.writeBuffer(gpu.uniform,0,uniform);
    const p = pipelines(device,ds.tex.sampleCount);
    const pass = enc.beginRenderPass({ colorAttachments: [{ view: rt.msView || rt.view,
      ...(rt.msView ? { resolveTarget: rt.view } : {}), loadOp: 'load', storeOp: 'store' }],
      depthStencilAttachment: { view: ds.view, depthLoadOp: 'load', depthStoreOp: 'store',
        stencilLoadOp: 'load', stencilStoreOp: 'store' } });
    try {
      pass.setBindGroup(0,gpu.bind);
      for (let type = 0; type < 2; type++) {
        pass.setPipeline(p[type]);
        for (const mesh of meshes.values()) {
          const count = type ? mesh.clear : mesh.opaque; if (!count) continue;
          pass.setVertexBuffer(0,mesh.vb); pass.setIndexBuffer(mesh.ib,'uint32');
          pass.drawIndexed(count,1,type ? mesh.opaque : 0);
        }
      }
      const payload = new Int32Array(f32.buffer,f32.byteOffset,f32.length);
      if (payload[a+35]) { pass.setPipeline(p[2]); pass.draw(24); }
    } finally { pass.end(); }
  }
  window.rnVoxel = { init, draw, pixels: () => pixels || (pixels = materials()) };
})();
