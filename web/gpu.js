// Runs the frames that host/gpu.c hands over (see host/gpu.h) with WebGPU, on the page's thread.
// The game thread waits in Present until the page has run the frame before the one it submits.
'use strict';
const GPU_TARGET = 1, GPU_CLEAR = 2, GPU_PRESENT = 3, GPU_DRAW = 4;

async function startGpu(M, canvas, report) {
  if (!navigator.gpu) throw new Error('WebGPU no disponible');
  const adapter = await navigator.gpu.requestAdapter();
  if (!adapter) throw new Error('WebGPU: sin adaptador');
  const device = await adapter.requestDevice();
  device.addEventListener('uncapturederror', e => report('webgpu: ' + e.error.message));
  const ctx = canvas.getContext('webgpu');
  const box = M._rn_gpu_mailbox() >> 2;     // u32 index: seq, done, ptr[2], len[2]
  const H = () => M.HEAPU32;                // the view of the shared wasm memory
  const targets = new Map();                // id -> {tex, w, h, depth}
  let canvasSize = '';

  // Clear of a rectangle: a full-screen triangle under a scissor, writing the color, depth and
  // stencil the D3DCLEAR flags ask for. Uniforms come from a ring with 256-byte steps.
  const shader = device.createShaderModule({ code: `
    struct U { color: vec4f, z: f32 };
    @group(0) @binding(0) var<uniform> u: U;
    @vertex fn vs(@builtin(vertex_index) i: u32) -> @builtin(position) vec4f {
      let p = vec2f(f32((i << 1u) & 2u), f32(i & 2u)) * 2.0 - 1.0;
      return vec4f(p, u.z, 1.0);
    }
    struct O { @location(0) c: vec4f };
    @fragment fn fs() -> O { return O(u.color); }
    @fragment fn fs_none() {}` });
  const ring = device.createBuffer({ size: 256 * 1024, usage: GPUBufferUsage.UNIFORM | GPUBufferUsage.COPY_DST });
  const bgl = device.createBindGroupLayout({ entries: [{ binding: 0, visibility: GPUShaderStage.VERTEX | GPUShaderStage.FRAGMENT,
    buffer: { type: 'uniform', hasDynamicOffset: true, minBindingSize: 32 } }] });
  const bind = device.createBindGroup({ layout: bgl, entries: [{ binding: 0, resource: { buffer: ring, size: 32 } }] });
  const layout = device.createPipelineLayout({ bindGroupLayouts: [bgl] });
  const pipes = new Map();
  function clearPipe(hasColor, hasDepth, flags) {
    const key = `${hasColor}${hasDepth}${flags}`;
    if (pipes.has(key)) return pipes.get(key);
    const st = { compare: 'always', passOp: (flags & 4) ? 'replace' : 'keep' };
    const p = device.createRenderPipeline({ layout,
      vertex: { module: shader, entryPoint: 'vs' },
      fragment: { module: shader, entryPoint: hasColor ? 'fs' : 'fs_none',
        targets: hasColor ? [{ format: 'rgba8unorm', writeMask: (flags & 1) ? GPUColorWrite.ALL : 0 }] : [] },
      primitive: { topology: 'triangle-list' },
      depthStencil: hasDepth ? { format: 'depth24plus-stencil8', depthWriteEnabled: !!(flags & 2), depthCompare: 'always',
        stencilFront: st, stencilBack: st, stencilWriteMask: (flags & 4) ? 0xff : 0 } : undefined });
    pipes.set(key, p);
    return p;
  }

  function run(ptr, len) {
    const w = H().subarray(ptr >> 2, (ptr >> 2) + len);
    const f32 = new Float32Array(w.buffer, w.byteOffset, w.length);
    const enc = device.createCommandEncoder();
    const uni = new ArrayBuffer(256 * 1024), uf = new Float32Array(uni);
    let nuni = 0, stats = { clears: 0, draws: 0, present: '' };
    for (let i = 0; i < w.length;) {
      const op = w[i] & 0xff, n = w[i] >>> 8, a = i + 1;
      i += 1 + n;
      if (op === GPU_TARGET) {
        const depth = w[a + 3] === 1;
        const tex = device.createTexture({ size: [w[a + 1], w[a + 2]], format: depth ? 'depth24plus-stencil8' : 'rgba8unorm',
          usage: GPUTextureUsage.RENDER_ATTACHMENT | (depth ? 0 : GPUTextureUsage.COPY_SRC | GPUTextureUsage.TEXTURE_BINDING) });
        targets.get(w[a])?.tex.destroy();
        targets.set(w[a], { tex, w: w[a + 1], h: w[a + 2], depth });
      } else if (op === GPU_CLEAR) {
        const rt = w[a] ? targets.get(w[a]) : null, ds = w[a + 1] ? targets.get(w[a + 1]) : null, flags = w[a + 2];
        const c = w[a + 3], off = nuni * 256;
        if (nuni === 1024) throw new Error('gpu.js: more than 1024 clears in a frame');
        uf.set([((c >>> 16) & 255) / 255, ((c >>> 8) & 255) / 255, (c & 255) / 255, (c >>> 24) / 255, f32[a + 4]], off / 4);
        nuni++;
        const pass = enc.beginRenderPass({
          colorAttachments: rt ? [{ view: rt.tex.createView(), loadOp: 'load', storeOp: 'store' }] : [],
          depthStencilAttachment: ds ? { view: ds.tex.createView(), depthLoadOp: 'load', depthStoreOp: 'store',
            stencilLoadOp: 'load', stencilStoreOp: 'store' } : undefined });
        pass.setPipeline(clearPipe(!!rt, !!ds, flags));
        pass.setBindGroup(0, bind, [off]);
        pass.setStencilReference(w[a + 5] & 0xff);
        pass.setScissorRect(w[a + 6], w[a + 7], w[a + 8] - w[a + 6], w[a + 9] - w[a + 7]);
        pass.draw(3);
        pass.end();
        stats.clears++;
      } else if (op === GPU_DRAW) {
        stats.draws++;
      } else if (op === GPU_PRESENT) {
        const t = targets.get(w[a]), size = `${w[a + 1]}x${w[a + 2]}`;
        if (size !== canvasSize) {
          canvas.width = w[a + 1]; canvas.height = w[a + 2];
          ctx.configure({ device, format: 'rgba8unorm', alphaMode: 'opaque', usage: GPUTextureUsage.RENDER_ATTACHMENT | GPUTextureUsage.COPY_DST });
          canvasSize = size;
        }
        enc.copyTextureToTexture({ texture: t.tex }, { texture: ctx.getCurrentTexture() }, [w[a + 1], w[a + 2]]);
        stats.present = size;
      } else {
        throw new Error('gpu.js: unknown command ' + op);
      }
    }
    if (nuni) device.queue.writeBuffer(ring, 0, uni, 0, nuni * 256);
    device.queue.submit([enc.finish()]);
    return stats;
  }

  let frames = 0;
  function tick() {
    const h = H();
    while (Atomics.load(h, box + 1) < Atomics.load(h, box)) {
      const k = Atomics.load(h, box + 1) + 1;
      const s = run(h[box + 2 + (k & 1)], h[box + 4 + (k & 1)]);
      frames++;
      if (frames <= 3) report(`gpu.js: frame ${frames}: ${s.clears} clears, ${s.draws} draws not rendered yet, present ${s.present}`);
      Atomics.store(h, box + 1, k);
      Atomics.notify(M.HEAP32, box + 1);
    }
    requestAnimationFrame(tick);
  }
  requestAnimationFrame(tick);
}
