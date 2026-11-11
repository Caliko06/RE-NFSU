// Drives chunk.wasm (all world logic lives there) and draws its mesh with WebGPU.
const canvas = document.getElementById("c"), msg = document.getElementById("msg"), bar = document.getElementById("bar");
const SWATCH = ["", "#5fa83a", "#7a5232", "#7d7d86", "#b9874a", "#a5432f", "#dcc68a"];
let kind = 1;
for (let i = 1; i <= 6; i++) {
  const d = document.createElement("div");
  d.style.background = SWATCH[i];
  d.innerHTML = `<span>${i}</span>`;
  bar.append(d);
}
const pick = (k) => { kind = k; [...bar.children].forEach((d, i) => d.classList.toggle("on", i + 1 === k)); };
pick(1);

const fail = (t) => { msg.hidden = false; msg.textContent = t; throw new Error(t); };
if (!navigator.gpu) fail("WebGPU is not available in this browser.");
const adapter = await navigator.gpu.requestAdapter();
if (!adapter) fail("No WebGPU adapter.");
const device = await adapter.requestDevice();
const ctx = canvas.getContext("webgpu");
const format = navigator.gpu.getPreferredCanvasFormat();
ctx.configure({ device, format, alphaMode: "opaque" });

// The module needs no host calls; any import it lists gets a stub that does nothing.
const mod = await WebAssembly.compileStreaming(fetch("chunk.wasm"));
const imports = {};
for (const i of WebAssembly.Module.imports(mod)) (imports[i.module] ??= {})[i.name] = () => 0;
const wasm = (await WebAssembly.instantiate(mod, imports)).exports;
wasm._initialize?.();
wasm.init();
const mem = () => wasm.memory.buffer;

const WGSL = /* wgsl */ `
struct U { vp: mat4x4f, eye: vec4f, sel: vec4f };
@group(0) @binding(0) var<uniform> u: U;
struct O { @builtin(position) p: vec4f, @location(0) w: vec3f, @location(1) @interpolate(flat) a: u32, @location(2) ao: f32 };
@vertex fn vs(@location(0) p: vec3f, @location(1) a: u32) -> O {
  return O(u.vp * vec4f(p, 1), p, a, f32((a >> 12u) & 3u));
}
fn h2(p: vec2f) -> f32 { return fract(sin(dot(p, vec2f(127.1, 311.7))) * 43758.5453); }
const SKY_LO = vec3f(0.98, 0.62, 0.42);
const SKY_HI = vec3f(0.22, 0.24, 0.52);
fn tex(b: u32, f: u32, w: vec3f) -> vec3f {
  var uv: vec2f;
  if (f < 2u) { uv = w.zy; } else if (f < 4u) { uv = w.xz; } else { uv = w.xy; }
  var nrm = array<vec3f, 6>(vec3f(1, 0, 0), vec3f(-1, 0, 0), vec3f(0, 1, 0), vec3f(0, -1, 0), vec3f(0, 0, 1), vec3f(0, 0, -1));
  let cell = floor(w - nrm[f] * 0.5);
  let t = floor(fract(uv) * 16.0);
  let n = h2(t + cell.xz * 17.0 + cell.y * 3.1);
  let ty = t.y;
  switch b {
    case 1u: {
      if (f == 2u) { return mix(vec3f(0.30, 0.58, 0.20), vec3f(0.45, 0.72, 0.26), n); }
      if (f != 3u && ty > 12.0 - floor(n * 2.0)) { return mix(vec3f(0.30, 0.58, 0.20), vec3f(0.42, 0.68, 0.24), n); }
      return mix(vec3f(0.42, 0.28, 0.17), vec3f(0.55, 0.37, 0.22), n);
    }
    case 2u: { return mix(vec3f(0.42, 0.28, 0.17), vec3f(0.55, 0.37, 0.22), n); }
    case 3u: { return mix(vec3f(0.42, 0.42, 0.46), vec3f(0.56, 0.56, 0.60), n * n); }
    case 4u: {
      let line = select(1.0, 0.72, (u32(ty) % 4u) == 0u);
      return mix(vec3f(0.62, 0.45, 0.25), vec3f(0.74, 0.55, 0.31), h2(vec2f(floor(ty / 4.0), cell.x + cell.z))) * line * (0.92 + 0.08 * n);
    }
    case 5u: {
      let row = u32(ty) / 4u;
      let shift = select(0.0, 4.0, (row % 2u) == 1u);
      let mortar = (u32(ty) % 4u) == 0u || (u32(t.x + shift) % 8u) == 0u;
      return select(mix(vec3f(0.60, 0.24, 0.17), vec3f(0.72, 0.30, 0.20), n), vec3f(0.72, 0.68, 0.62), mortar);
    }
    default: { return mix(vec3f(0.82, 0.74, 0.50), vec3f(0.90, 0.83, 0.58), n); }
  }
}
@fragment fn fs(i: O) -> @location(0) vec4f {
  let b = i.a & 255u; let f = (i.a >> 8u) & 7u;
  var shades = array<f32, 6>(0.80, 0.68, 1.0, 0.45, 0.88, 0.62);
  let shade = shades[f];
  let c = tex(b, f, i.w) * shade * (0.45 + 0.55 * i.ao / 3.0);
  let warm = c * vec3f(1.08, 0.98, 0.88);
  let d = distance(i.w, u.eye.xyz);
  let fog = smoothstep(18.0, 46.0, d);
  return vec4f(mix(warm, SKY_LO * 0.9, fog), 1);
}
struct S { @builtin(position) p: vec4f, @location(0) y: f32 };
@vertex fn skyv(@builtin(vertex_index) k: u32) -> S {
  let p = vec2f(f32((k << 1u) & 2u), f32(k & 2u)) * 2.0 - 1.0;
  return S(vec4f(p, 0, 1), p.y);
}
@fragment fn skyf(i: S) -> @location(0) vec4f {
  let pitch = u.eye.w;
  let y = clamp(i.y * 0.5 + 0.5 + pitch * 0.6, 0.0, 1.0);
  return vec4f(mix(SKY_LO, SKY_HI, smoothstep(0.35, 1.0, y)), 1);
}
@vertex fn linev(@location(0) p: vec3f) -> @builtin(position) vec4f {
  var q = u.vp * vec4f(p, 1);
  q.z -= 0.0004 * q.w;
  return q;
}
@fragment fn linef() -> @location(0) vec4f { return vec4f(0.08, 0.06, 0.1, 1); }
`;
const sm = device.createShaderModule({ code: WGSL });
const ubuf = device.createBuffer({ size: 96, usage: GPUBufferUsage.UNIFORM | GPUBufferUsage.COPY_DST });
const bgl = device.createBindGroupLayout({ entries: [{ binding: 0, visibility: GPUShaderStage.VERTEX | GPUShaderStage.FRAGMENT, buffer: {} }] });
const layout = device.createPipelineLayout({ bindGroupLayouts: [bgl] });
const bind = device.createBindGroup({ layout: bgl, entries: [{ binding: 0, resource: { buffer: ubuf } }] });
const depthState = (write) => ({ format: "depth24plus", depthWriteEnabled: write, depthCompare: "less" });
const world = device.createRenderPipeline({
  layout, primitive: { topology: "triangle-list", cullMode: "none" }, depthStencil: depthState(true),
  vertex: { module: sm, entryPoint: "vs", buffers: [{ arrayStride: 16, attributes: [{ shaderLocation: 0, offset: 0, format: "float32x3" }, { shaderLocation: 1, offset: 12, format: "uint32" }] }] },
  fragment: { module: sm, entryPoint: "fs", targets: [{ format }] },
});
const sky = device.createRenderPipeline({
  layout, depthStencil: { ...depthState(false), depthCompare: "always" },
  vertex: { module: sm, entryPoint: "skyv" }, fragment: { module: sm, entryPoint: "skyf", targets: [{ format }] },
});
const lines = device.createRenderPipeline({
  layout, primitive: { topology: "line-list" }, depthStencil: depthState(false),
  vertex: { module: sm, entryPoint: "linev", buffers: [{ arrayStride: 12, attributes: [{ shaderLocation: 0, offset: 0, format: "float32x3" }] }] },
  fragment: { module: sm, entryPoint: "linef", targets: [{ format }] },
});

let vbuf = null, count = 0;
function upload() {
  count = wasm.mesh();
  const bytes = count * 16;
  if (!vbuf || vbuf.size < bytes) { vbuf?.destroy(); vbuf = device.createBuffer({ size: Math.max(bytes * 2, 1 << 20), usage: GPUBufferUsage.VERTEX | GPUBufferUsage.COPY_DST }); }
  device.queue.writeBuffer(vbuf, 0, mem(), wasm.verts(), bytes);
}
upload();

const box = device.createBuffer({ size: 24 * 12, usage: GPUBufferUsage.VERTEX | GPUBufferUsage.COPY_DST });
const E = [[0,0,0,1,0,0],[1,0,0,1,0,1],[1,0,1,0,0,1],[0,0,1,0,0,0],[0,1,0,1,1,0],[1,1,0,1,1,1],[1,1,1,0,1,1],[0,1,1,0,1,0],[0,0,0,0,1,0],[1,0,0,1,1,0],[1,0,1,1,1,1],[0,0,1,0,1,1]];

let depth = null;
function resize() {
  const dpr = Math.min(devicePixelRatio, 2);
  const w = Math.max(1, Math.floor(innerWidth * dpr)), h = Math.max(1, Math.floor(innerHeight * dpr));
  if (canvas.width === w && canvas.height === h && depth) return;
  canvas.width = w; canvas.height = h;
  depth?.destroy();
  depth = device.createTexture({ size: [w, h], format: "depth24plus", usage: GPUTextureUsage.RENDER_ATTACHMENT });
}

const keys = new Set();
let mdx = 0, mdy = 0;
addEventListener("keydown", (e) => { keys.add(e.code); if (/^Digit[1-6]$/.test(e.code)) pick(+e.code.slice(5)); if (e.code === "Space") e.preventDefault(); });
addEventListener("keyup", (e) => keys.delete(e.code));
addEventListener("blur", () => keys.clear());
msg.addEventListener("click", () => canvas.requestPointerLock());
canvas.addEventListener("click", () => { if (document.pointerLockElement !== canvas) canvas.requestPointerLock(); });
document.addEventListener("pointerlockchange", () => { msg.hidden = document.pointerLockElement === canvas; if (!msg.hidden) msg.textContent = "Click to play"; });
addEventListener("mousemove", (e) => { if (document.pointerLockElement === canvas) { mdx += e.movementX; mdy += e.movementY; } });
canvas.addEventListener("mousedown", (e) => { if (document.pointerLockElement === canvas && wasm.click(e.button, kind)) upload(); });
canvas.addEventListener("contextmenu", (e) => e.preventDefault());
addEventListener("wheel", (e) => pick(((kind - 1 + (e.deltaY > 0 ? 1 : 5)) % 6) + 1));
msg.textContent = "Click to play";

// Test hook for headless checks: same calls the input handlers make.
window.chunk = { wasm, upload, keys, look: (dx, dy) => { mdx += dx; mdy += dy; }, pick };

let last = performance.now();
function frame(now) {
  const dt = (now - last) / 1000; last = now;
  resize();
  const ax = (keys.has("KeyD") ? 1 : 0) - (keys.has("KeyA") ? 1 : 0), az = (keys.has("KeyW") ? 1 : 0) - (keys.has("KeyS") ? 1 : 0);
  wasm.look(mdx, mdy, canvas.width / canvas.height); mdx = mdy = 0;
  wasm.step(dt, az, ax, keys.has("Space") ? 1 : 0);
  const pl = new Float32Array(mem(), wasm.player(), 5);
  const u = new Float32Array(24);
  u.set(new Float32Array(mem(), wasm.view(), 16));
  u.set([pl[0], pl[1] + 1.62, pl[2], pl[4]], 16);
  device.queue.writeBuffer(ubuf, 0, u);
  const hit = new Int32Array(mem(), wasm.hit(), 7);
  if (hit[0]) {
    const s = 0.002, v = new Float32Array(72);
    E.forEach((e, i) => v.set([hit[1] + e[0] * (1 + 2 * s) - s, hit[2] + e[1] * (1 + 2 * s) - s, hit[3] + e[2] * (1 + 2 * s) - s, hit[1] + e[3] * (1 + 2 * s) - s, hit[2] + e[4] * (1 + 2 * s) - s, hit[3] + e[5] * (1 + 2 * s) - s], i * 6));
    device.queue.writeBuffer(box, 0, v);
  }
  const enc = device.createCommandEncoder();
  const pass = enc.beginRenderPass({
    colorAttachments: [{ view: ctx.getCurrentTexture().createView(), loadOp: "clear", storeOp: "store", clearValue: { r: 0, g: 0, b: 0, a: 1 } }],
    depthStencilAttachment: { view: depth.createView(), depthLoadOp: "clear", depthClearValue: 1, depthStoreOp: "store" },
  });
  pass.setBindGroup(0, bind);
  pass.setPipeline(sky); pass.draw(3);
  pass.setPipeline(world); pass.setVertexBuffer(0, vbuf); pass.draw(count);
  if (hit[0]) { pass.setPipeline(lines); pass.setVertexBuffer(0, box); pass.draw(24); }
  pass.end();
  device.queue.submit([enc.finish()]);
  requestAnimationFrame(frame);
}
requestAnimationFrame(frame);
