// Runs the frames that host/gpu.c hands over (see host/gpu.h; the numbers below mirror it) with
// WebGPU, on the page's thread. The game thread waits in Present until the page has run the frame
// before the one it submits. Shaders arrive as WGSL (host/sm1.c); textures as RGBA8.
'use strict';
const GPU_TARGET = 1, GPU_CLEAR = 2, GPU_PRESENT = 3, GPU_DRAW = 4, GPU_SHADER = 5, GPU_DECL = 6, GPU_TEXTURE = 7,
  GPU_TEXDATA = 8, GPU_TEXKEY = 9, GPU_CUBE = 10, GPU_FXAA = 11, GPU_SKIN = 12;
const D_TOPO = 0, D_NVERT = 1, D_NIDX = 2, D_STRIDE = 3, D_VS = 4, D_PS = 5, D_DECL = 6, D_RT = 7, D_DS = 8, D_VP = 9,
  D_SC = 15, D_ZEN = 19, D_ZWRITE = 20, D_ZFUNC = 21, D_CULL = 22, D_BLEND = 23, D_SRCB = 24, D_DSTB = 25, D_BOP = 26,
  D_SEPA = 27, D_SRCBA = 28, D_DSTBA = 29, D_BOPA = 30, D_BFACTOR = 31, D_CWRITE = 32, D_AFUNC = 33, D_AREF = 34,
  D_FOG = 35, D_FOGC = 36, D_TEX = 37, D_TEXN = 8, D_NVC = 37 + 64, D_NPC = 38 + 64, D_HDR = 39 + 64;
const T_ID = 0, T_AU = 1, T_AV = 2, T_MAG = 3, T_MIN = 4, T_MIP = 5, T_TT = 6, T_ANISO = 7, T_CUBE = 0x10000;
const U_SIZE = 4320, U_STEP = 4352;     // sm1.h SM1_U_SIZE, rounded to the 256-byte offset alignment

const CMP = [null, 'never', 'less', 'equal', 'less-equal', 'greater', 'not-equal', 'greater-equal', 'always'];
const BLEND = [null, 'zero', 'one', 'src', 'one-minus-src', 'src-alpha', 'one-minus-src-alpha', 'dst-alpha',
  'one-minus-dst-alpha', 'dst', 'one-minus-dst', 'src-alpha-saturated', null, null, 'constant', 'one-minus-constant'];
const BLENDOP = [null, 'add', 'subtract', 'reverse-subtract', 'min', 'max'];
const ADDRESS = [null, 'repeat', 'mirror-repeat', 'clamp-to-edge'];
// D3DDECLTYPE -> vertex format (the types WGSL vec4f can take). D3DCOLOR is BGRA in memory.
const VFMT = ['float32', 'float32x2', 'float32x3', 'float32x4', 'unorm8x4-bgra', null, null, null, 'unorm8x4',
  'snorm16x2', 'snorm16x4', 'unorm16x2', 'unorm16x4', null, null, 'float16x2', 'float16x4'];

async function startGpu(M, canvas, report, onFrame) {
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

  // Remaster pack (web/remaster, tools/remaster/index.py): FNV-1a 64 of a DXT level 0 -> an upscaled PNG.
  // A texture keeps its original; while its contents match the index it is drawn with the PNG (own mip chain).
  // ?remaster=0 turns it off. No index file = off.
  const pack = new Map(), hd = new Map();   // key -> png name; png name -> {view} once loaded, null while loading
  let packed = 0;
  if (new URLSearchParams(location.search).get('remaster') !== '0') {
    // ?worldhd=1 adds the world textures (STREAML1R*.BUN, tools/remaster/world_pod.sh): opt-in, the world look stays 2003 by default.
    const lists = ['remaster/index.tsv'].concat(new URLSearchParams(location.search).get('worldhd') === '1' ? ['remaster/index_world.tsv'] : []);
    for (const u of lists) try {
      const r = await fetch(u);
      if (r.ok) for (const l of (await r.text()).split('\n')) { const f = l.split('\t'); if (f[1]) pack.set(f[0], f[1]); }
    } catch {}
    if (pack.size) report(`gpu.js: remaster pack ${pack.size} textures`);
  }
  const HD_MAX = Number(new URLSearchParams(location.search).get('hdmax') || 1024);
  async function loadHd(name) {
    // A name with a path is a file under remaster/ (world pack: world/<hash>.webp); a bare key is png/<key>.png.
    const blob = await (await fetch(name.includes('/') ? `remaster/${name}` : `remaster/png/${name}.png`)).blob();
    const opt = { premultiplyAlpha: 'none', colorSpaceConversion: 'none' };
    // Level 0 is at most HD_MAX on a side (?hdmax=, default 1024): the 2048 car PNGs cost 22 MB each and, with ~80 in a
    // race, made the GPU wait 60-110 ms a frame at 2560x1116 (OWNER 2026-10-22 session).
    const full = await createImageBitmap(blob, opt), f = Math.min(1, HD_MAX / Math.max(full.width, full.height));
    const W = Math.round(full.width * f), H = Math.round(full.height * f);
    const base = f < 1 ? await createImageBitmap(blob, { ...opt, resizeWidth: W, resizeHeight: H, resizeQuality: 'high' }) : full;
    const levels = Math.floor(Math.log2(Math.max(W, H))) + 1;
    const tex = device.createTexture({ size: [W, H], mipLevelCount: levels, format: 'rgba8unorm',
      usage: GPUTextureUsage.TEXTURE_BINDING | GPUTextureUsage.COPY_DST | GPUTextureUsage.RENDER_ATTACHMENT });
    for (let l = 0; l < levels; l++) {
      const w = Math.max(1, W >> l), h = Math.max(1, H >> l);
      const bmp = l ? await createImageBitmap(blob, { ...opt, resizeWidth: w, resizeHeight: h, resizeQuality: 'high' }) : base;
      device.queue.copyExternalImageToTexture({ source: bmp }, { texture: tex, mipLevel: l }, [w, h]);
    }
    return { view: tex.createView() };
  }
  function useHd(t, key) {
    const name = pack.get(key);
    if (!name) { t.view = t.own; return; }
    const h = hd.get(name);
    if (h) { t.view = h.view; return; }
    t.view = t.own;
    if (h === null) return;
    hd.set(name, null);
    loadHd(name).then(v => {
      hd.set(name, v); packed++;
      for (const x of res.values()) if (x.key && pack.get(x.key) === name) x.view = v.view;
    }, e => report(`gpu.js: remaster ${name}: ${e.message}`));
  }

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
  // BRIDGE: remaster, OWNER 2026-10-22: 4x MSAA on the screen-sized targets, opt-in with ?msaa=4 (OWNER 2026-10-22: it lagged;
  // headless race 1280x956: hitches >33 ms 369 with it, 153 without, GPU wait p90 46 -> 18 ms). Each colour target keeps
  // its single-sample texture (what the game samples and presents) and a multisampled twin that the passes draw into and
  // resolve from; depth targets are multisampled themselves. Size decides, so a pass's colour and depth always agree.
  const MSAA = new URLSearchParams(location.search).get('msaa') === '4' ? 4 : 1;
  // BRIDGE: FXAA over the 3D scene (FXAA 3.11 quality, T. Lottes, public domain), not in the original. The host sends GPU_FXAA at the first HUD quad of a race
  // frame. Pixels whose neighbourhood has little contrast are returned untouched, so textures keep their detail. ?fxaa=0 turns it off.
  const FXAA_MODE = new URLSearchParams(location.search).get('fxaa');   // '0' off, '2' debug: edges in red
  const FXAA_ON = FXAA_MODE !== '0';
  const fxaaMod = device.createShaderModule({ code: `
const DBG = ${FXAA_MODE === '2' ? 1 : 0};
@group(0) @binding(0) var src: texture_2d<f32>;
@group(0) @binding(1) var smp: sampler;
@vertex fn vs(@builtin(vertex_index) i: u32) -> @builtin(position) vec4f {
  let p = vec2f(f32((i << 1u) & 2u), f32(i & 2u));
  return vec4f(p * 2.0 - 1.0, 0.0, 1.0);
}
fn lum(c: vec3f) -> f32 { return dot(c, vec3f(0.299, 0.587, 0.114)); }
fn L(uv: vec2f) -> f32 { return lum(textureSampleLevel(src, smp, uv, 0.0).rgb); }
const Q = array<f32, 12>(1.0, 1.0, 1.0, 1.0, 1.0, 1.5, 2.0, 2.0, 2.0, 2.0, 4.0, 8.0);
@fragment fn fs(@builtin(position) pos: vec4f) -> @location(0) vec4f {
  let rcp = 1.0 / vec2f(textureDimensions(src));
  let uv0 = pos.xy * rcp;
  let m4 = textureSampleLevel(src, smp, uv0, 0.0);
  let lumaM = lum(m4.rgb);
  var lumaN = L(uv0 + vec2f(0.0, -rcp.y)); var lumaS = L(uv0 + vec2f(0.0, rcp.y));
  let lumaW0 = L(uv0 + vec2f(-rcp.x, 0.0)); let lumaE0 = L(uv0 + vec2f(rcp.x, 0.0));
  let rangeMax = max(max(lumaN, lumaW0), max(lumaE0, max(lumaS, lumaM)));
  let rangeMin = min(min(lumaN, lumaW0), min(lumaE0, min(lumaS, lumaM)));
  let range = rangeMax - rangeMin;
  if (range < max(0.0625, rangeMax * 0.125)) { return m4; }
  if (DBG == 1) { return vec4f(1.0, 0.0, 0.0, m4.a); }
  let lumaNW = L(uv0 + vec2f(-rcp.x, -rcp.y)); let lumaNE = L(uv0 + vec2f(rcp.x, -rcp.y));
  let lumaSW = L(uv0 + vec2f(-rcp.x, rcp.y)); let lumaSE = L(uv0 + vec2f(rcp.x, rcp.y));
  let lumaNS = lumaN + lumaS; let lumaWE = lumaW0 + lumaE0;
  let subpixNSWE = lumaNS + lumaWE;
  let edgeHorz1 = -2.0 * lumaM + lumaNS; let edgeVert1 = -2.0 * lumaM + lumaWE;
  let lumaNESE = lumaNE + lumaSE; let lumaNWNE = lumaNW + lumaNE;
  let edgeHorz2 = -2.0 * lumaE0 + lumaNESE; let edgeVert2 = -2.0 * lumaN + lumaNWNE;
  let lumaNWSW = lumaNW + lumaSW; let lumaSWSE = lumaSW + lumaSE;
  let edgeHorz4 = abs(edgeHorz1) * 2.0 + abs(edgeHorz2); let edgeVert4 = abs(edgeVert1) * 2.0 + abs(edgeVert2);
  let edgeHorz3 = -2.0 * lumaW0 + lumaNWSW; let edgeVert3 = -2.0 * lumaS + lumaSWSE;
  let edgeHorz = abs(edgeHorz3) + edgeHorz4; let edgeVert = abs(edgeVert3) + edgeVert4;
  let subpixNWSWNESE = lumaNWSW + lumaNESE;
  let horzSpan = edgeHorz >= edgeVert;
  var lengthSign = rcp.x;
  let subpixA = subpixNSWE * 2.0 + subpixNWSWNESE;
  if (!horzSpan) { lumaN = lumaW0; lumaS = lumaE0; } else { lengthSign = rcp.y; }
  let subpixB = subpixA * (1.0 / 12.0) - lumaM;
  let gradientN = lumaN - lumaM; let gradientS = lumaS - lumaM;
  var lumaNN = lumaN + lumaM; let lumaSS = lumaS + lumaM;
  let pairN = abs(gradientN) >= abs(gradientS);
  let gradient = max(abs(gradientN), abs(gradientS));
  if (pairN) { lengthSign = -lengthSign; }
  let subpixC = clamp(abs(subpixB) / range, 0.0, 1.0);
  var posB = uv0;
  let offNP = select(vec2f(0.0, rcp.y), vec2f(rcp.x, 0.0), horzSpan);
  if (!horzSpan) { posB.x = posB.x + lengthSign * 0.5; } else { posB.y = posB.y + lengthSign * 0.5; }
  var posN = posB - offNP * Q[0]; var posP = posB + offNP * Q[0];
  let subpixD = -2.0 * subpixC + 3.0;
  var lumaEndN = L(posN); let subpixE = subpixC * subpixC; var lumaEndP = L(posP);
  if (!pairN) { lumaNN = lumaSS; }
  let gradientScaled = gradient * 0.25;
  let lumaMM = lumaM - lumaNN * 0.5;
  let subpixF = subpixD * subpixE;
  let lumaMLTZero = lumaMM < 0.0;
  lumaEndN = lumaEndN - lumaNN * 0.5; lumaEndP = lumaEndP - lumaNN * 0.5;
  var doneN = abs(lumaEndN) >= gradientScaled; var doneP = abs(lumaEndP) >= gradientScaled;
  for (var i = 1; i < 12 && !(doneN && doneP); i++) {
    if (!doneN) { posN = posN - offNP * Q[i]; lumaEndN = L(posN) - lumaNN * 0.5; doneN = abs(lumaEndN) >= gradientScaled; }
    if (!doneP) { posP = posP + offNP * Q[i]; lumaEndP = L(posP) - lumaNN * 0.5; doneP = abs(lumaEndP) >= gradientScaled; }
  }
  let dstN = select(uv0.y - posN.y, uv0.x - posN.x, horzSpan);
  let dstP = select(posP.y - uv0.y, posP.x - uv0.x, horzSpan);
  let directionN = dstN < dstP;
  let lumaEndG = select(lumaEndP, lumaEndN, directionN);
  let goodSpan = (lumaEndG < 0.0) != lumaMLTZero;
  let spanLength = dstP + dstN;
  let dstM = select(dstP, dstN, directionN);
  let pixelOffset = dstM * (-1.0 / spanLength) + 0.5;
  let pixelOffsetGood = select(0.0, pixelOffset, goodSpan);
  let pixelOffsetSubpix = max(pixelOffsetGood, subpixF * subpixF * 0.75);
  var uv = uv0;
  if (!horzSpan) { uv.x = uv.x + pixelOffsetSubpix * lengthSign; } else { uv.y = uv.y + pixelOffsetSubpix * lengthSign; }
  return vec4f(textureSampleLevel(src, smp, uv, 0.0).rgb, m4.a);
}` });
  const fxaaPipe = device.createRenderPipeline({ layout: 'auto', vertex: { module: fxaaMod, entryPoint: 'vs' },
    fragment: { module: fxaaMod, entryPoint: 'fs', targets: [{ format: 'rgba8unorm' }] }, primitive: { topology: 'triangle-list' } });
  const fxaaSamp = device.createSampler({ magFilter: 'linear', minFilter: 'linear', addressModeU: 'clamp-to-edge', addressModeV: 'clamp-to-edge' });
  let fxaaTmp = null;
  const msFor = (w, h) => MSAA > 1 && w >= 1000 && h >= 500 ? MSAA : 1;
  const colorAtt = rt => rt.msView ? { view: rt.msView, resolveTarget: rt.view, loadOp: 'load', storeOp: 'store' }
    : { view: rt.view, loadOp: 'load', storeOp: 'store' };
  const clearPipes = new Map();
  function clearPipe(hasColor, hasDepth, flags, sc) {
    const key = `${hasColor}${hasDepth}${flags}${sc}`;
    if (clearPipes.has(key)) return clearPipes.get(key);
    const st = { compare: 'always', passOp: (flags & 4) ? 'replace' : 'keep' };
    const p = device.createRenderPipeline({ layout: clearLayout,
      vertex: { module: clearShader, entryPoint: 'vs' },
      fragment: { module: clearShader, entryPoint: hasColor ? 'fs' : 'fs_none',
        targets: hasColor ? [{ format: 'rgba8unorm', writeMask: (flags & 1) ? GPUColorWrite.ALL : 0 }] : [] },
      primitive: { topology: 'triangle-list' }, multisample: { count: sc },
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
        entries.push({ binding: 16 + k, visibility: GPUShaderStage.FRAGMENT, texture: { sampleType: 'float', viewDimension: 'cube' } });
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
  const dummyCube = device.createTexture({ size: [1, 1, 6], format: 'rgba8unorm', usage: GPUTextureUsage.TEXTURE_BINDING | GPUTextureUsage.COPY_DST });
  device.queue.writeTexture({ texture: dummyCube }, new Uint8Array(24).map((_, i) => i % 4 === 3 ? 255 : 0),
    { bytesPerRow: 4, rowsPerImage: 1 }, [1, 1, 6]);
  const dummyCubeView = dummyCube.createView({ dimension: 'cube' });
  const ANISO = Number(new URLSearchParams(location.search).get('aniso') ?? 16);   // ?aniso=1 turns the bridge off
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
    // BRIDGE: remaster, OWNER 2026-10-22: every linear sampler of a mipmapped texture is trilinear with 16x anisotropy
    // (the game asks for point mips or no anisotropy). WebGPU needs all three filters linear for maxAnisotropy > 1.
    if (ANISO > 1 && t[T_MIP] && filt(t[T_MIN]) === 'linear' && filt(t[T_MAG]) === 'linear') { d.mipmapFilter = 'linear'; d.maxAnisotropy = ANISO; }
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
  function pipeline(w, hdr, stride, sc) {
    const vs = shaders.get(w[hdr + D_VS]), ps = shaders.get(w[hdr + D_PS]), decl = decls.get(w[hdr + D_DECL]);
    if (!vs || !ps || !decl) fail('draw with an unknown shader or declaration');
    const g = i => w[hdr + i];
    const ds = g(D_DS) !== 0;
    const key = [g(D_VS), g(D_PS), g(D_DECL), stride, g(D_TOPO), ds, g(D_ZEN), g(D_ZWRITE), g(D_ZFUNC), g(D_CULL), g(D_BLEND),
      g(D_SRCB), g(D_DSTB), g(D_BOP), g(D_SEPA), g(D_SRCBA), g(D_DSTBA), g(D_BOPA), g(D_CWRITE), sc].join(',');
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
      multisample: { count: sc },
      primitive: { topology: topo, frontFace: 'cw', cullMode: cull,
        stripIndexFormat: topo === 'triangle-strip' && g(D_NIDX) ? 'uint32' : undefined },
      depthStencil: ds ? { format: 'depth24plus-stencil8', depthWriteEnabled: !!(g(D_ZEN) && g(D_ZWRITE)),
        depthCompare: g(D_ZEN) ? CMP[g(D_ZFUNC)] : 'always', stencilFront: st, stencilBack: st } : undefined });
    pipes.set(key, p);
    newPipes++;
    return p;
  }
  let newPipes = 0;     // telemetry: pipelines made in this frame (each is a shader compile in the browser)
  // Per-frame data: vertices, indices and uniforms gathered on the CPU, written once before submit.
  let vbuf = null, ibuf = null, ubuf = null, vcap = 0, icap = 0, ucap = 0;
  const grow = (buf, cap, need, usage) => {
    if (need <= cap) return [buf, cap];
    buf?.destroy();
    cap = Math.max(need, cap * 2, 1 << 20);
    return [device.createBuffer({ size: cap, usage: usage | GPUBufferUsage.COPY_DST }), cap];
  };

  // BRIDGE: HD car skins (host/d3d9.c skin_bridge; OWNER 2026-10-23, remaster scope). GPU_SKIN replays the game's CPU composite
  // 0x5a8a50 of DUMMY_SKINn on the GPU at 4x (at most 2048), with the 512 layers and masks sampled bilinear, so mask edges
  // follow a smooth curve instead of the 512 grid. Per texel, as 0x5a8a50/0x5a8640 do (V, Hopper): m = mask blue byte;
  // m = 0 keeps; a recolour layer first becomes sum_k ftol(colour_k * w_k), w = layer (R, G, B) * 1/255 rounded to f32, only
  // w > 1/255 counted (alpha: the largest term); m >= 128 replaces, 1..127 blends ftol(L * m/128) + ftol(D * (1 - m/128)), alpha
  // summed; every channel stops at 255. Then the marker texels (the 4 colours of the spec) are written.
  // ?skinhd=0 off; ?skinhd=check runs it at 512 with nearest texels and reports the texels that differ from the game's result.
  const SKIN_MODE = new URLSearchParams(location.search).get('skinhd');
  const skinMod = device.createShaderModule({ code: `
struct U { mode: u32, recolour: u32, nmark: u32, exact: u32, src: vec2f, k: f32, pad: f32, cols: array<vec4f, 4>, marks: array<vec4u, 64> };
@group(0) @binding(0) var prev: texture_2d<f32>;
@group(0) @binding(1) var layer: texture_2d<f32>;
@group(0) @binding(2) var mask: texture_2d<f32>;
@group(0) @binding(3) var smp: sampler;
@group(0) @binding(4) var<uniform> u: U;
@vertex fn vs(@builtin(vertex_index) i: u32) -> @builtin(position) vec4f {
  let p = vec2f(f32((i << 1u) & 2u), f32(i & 2u));
  return vec4f(p * 2.0 - 1.0, 0.0, 1.0);
}
// ftol(c * w) for a colour byte c and an f32 weight w < 2, from the exact product as the x87 makes it: c * mantissa fits 32 bits.
fn mulfloor(c: f32, w: f32) -> f32 {
  let b = bitcast<u32>(w); let e = (b >> 23u) & 255u;
  if (e == 0u || e > 150u || 150u - e >= 32u) { return 0.0; }
  return f32((u32(c) * ((b & 0x7fffffu) | 0x800000u)) >> (150u - e));
}
@fragment fn fs(@builtin(position) p: vec4f) -> @location(0) vec4f {
  let size = vec2f(textureDimensions(prev));
  let uv = p.xy / size;
  var d = round(textureLoad(prev, vec2i(p.xy), 0) * 255.0);
  if (u.mode == 1u) {
    let t = vec2u(uv * u.src); let i = t.y * u32(u.src.x) + t.x;
    for (var m = 0u; m < u.nmark; m++) { if (u.marks[m].x == i) { return u.cols[u.marks[m].y] / 255.0; } }
    return d / 255.0;
  }
  var l = textureSampleLevel(layer, smp, uv, 0.0) * 255.0;
  var m = textureSampleLevel(mask, smp, uv, 0.0).b * 255.0;
  if (u.exact == 1u) { l = round(l); m = round(m); }
  if (m <= 0.0) { return d / 255.0; }
  if (u.recolour == 1u) {
    let w = vec3f(l.r * u.k, l.g * u.k, l.b * u.k);
    var acc = vec3f(0.0); var a = 0.0;
    for (var k = 0u; k < 3u; k++) {
      if (w[k] > u.k) {
        let c = u.cols[k];
        acc += vec3f(mulfloor(c.r, w[k]), mulfloor(c.g, w[k]), mulfloor(c.b, w[k]));
        a = max(a, mulfloor(c.a, w[k]));
      }
    }
    l = min(vec4f(acc, a), vec4f(255.0));
  }
  if (m >= 128.0) { return l / 255.0; }
  let t = m * (1.0 / 128.0); let r = 1.0 - t;
  var s = vec4f(0.0);
  if (t > u.k) { s += floor(l * t); }
  if (r > u.k) { s += floor(d * r); }
  return min(s, vec4f(255.0)) / 255.0;
}` });
  const mipMod = device.createShaderModule({ code: `
@group(0) @binding(0) var down: texture_2d<f32>;
@group(0) @binding(1) var smp: sampler;
@vertex fn vs(@builtin(vertex_index) i: u32) -> @builtin(position) vec4f {
  let p = vec2f(f32((i << 1u) & 2u), f32(i & 2u));
  return vec4f(p * 2.0 - 1.0, 0.0, 1.0);
}
@fragment fn fs(@builtin(position) p: vec4f) -> @location(0) vec4f {
  return textureSampleLevel(down, smp, 2.0 * p.xy / vec2f(textureDimensions(down)), 0.0);
}` });
  const skinPipe = device.createRenderPipeline({ layout: 'auto', vertex: { module: skinMod, entryPoint: 'vs' },
    fragment: { module: skinMod, entryPoint: 'fs', targets: [{ format: 'rgba8unorm' }] }, primitive: { topology: 'triangle-list' } });
  const mipPipe = device.createRenderPipeline({ layout: 'auto', vertex: { module: mipMod, entryPoint: 'vs' },
    fragment: { module: mipMod, entryPoint: 'fs', targets: [{ format: 'rgba8unorm' }] }, primitive: { topology: 'triangle-list' } });
  const skinLin = device.createSampler({ magFilter: 'linear', minFilter: 'linear', addressModeU: 'clamp-to-edge', addressModeV: 'clamp-to-edge' });
  const skinNear = device.createSampler({ magFilter: 'nearest', minFilter: 'nearest' });
  const skinTmp = new Map();     // size -> [ping, pong]
  const argb = c => [(c >>> 16) & 255, (c >>> 8) & 255, c & 255, c >>> 24];
  function skin(w, a) {
    const t = res.get(w[a]);
    if (!t || SKIN_MODE === '0') return;
    const check = SKIN_MODE === 'check', S = check ? t.w : Math.min(2048, 4 * t.w);
    if (!skinTmp.has(S)) skinTmp.set(S, [0, 1].map(() => device.createTexture({ size: [S, S], format: 'rgba8unorm',
      usage: GPUTextureUsage.RENDER_ATTACHMENT | GPUTextureUsage.TEXTURE_BINDING | GPUTextureUsage.COPY_SRC })));
    const [A, B] = skinTmp.get(S), e = device.createCommandEncoder();
    const n = w[a + 2], fill = argb(w[a + 1]);
    const step = (dst, bind) => {
      const p = e.beginRenderPass({ colorAttachments: [{ view: dst.createView(), loadOp: 'load', storeOp: 'store' }] });
      p.setPipeline(skinPipe); p.setBindGroup(0, bind); p.draw(3); p.end();
    };
    const uni = (mode, recolour, cols, marks) => {
      const b = new ArrayBuffer(96 + 64 * 16), u = new Uint32Array(b), f = new Float32Array(b);
      u[0] = mode; u[1] = recolour; u[2] = marks.length / 2; u[3] = check ? 1 : 0; f[4] = t.w; f[5] = t.h;
      f[6] = 0.003921569;    // the 1/255 of 0x5a8d1a and 0x5a8681 (f32)
      cols.forEach((c, k) => f.set(argb(c), 8 + 4 * k));
      for (let m = 0; m < marks.length / 2; m++) { u[24 + 4 * m] = marks[2 * m]; u[25 + 4 * m] = marks[2 * m + 1]; }
      const g = device.createBuffer({ size: b.byteLength, usage: GPUBufferUsage.UNIFORM | GPUBufferUsage.COPY_DST });
      device.queue.writeBuffer(g, 0, b); return g;
    };
    const bind = (src, l, m, buf) => device.createBindGroup({ layout: skinPipe.getBindGroupLayout(0), entries: [
      { binding: 0, resource: src.createView() }, { binding: 1, resource: l.own }, { binding: 2, resource: m.own },
      { binding: 3, resource: check ? skinNear : skinLin }, { binding: 4, resource: { buffer: buf } }] });
    e.beginRenderPass({ colorAttachments: [{ view: A.createView(), loadOp: 'clear', storeOp: 'store',
      clearValue: { r: fill[0] / 255, g: fill[1] / 255, b: fill[2] / 255, a: fill[3] / 255 } }] }).end();
    let src = A, dst = B, o = a + 3;
    for (let i = 0; i < n; i++, o += 7) {
      const l = res.get(w[o]), m = res.get(w[o + 1]);
      if (!l || !m) return;
      step(dst, bind(src, l, m, uni(0, w[o + 2], [w[o + 3], w[o + 4], w[o + 5], w[o + 6]], [])));
      [src, dst] = [dst, src];
    }
    const nm = w[o + 4];
    step(dst, bind(src, t, t, uni(1, 0, [w[o], w[o + 1], w[o + 2], w[o + 3]], Array.from(w.subarray(o + 5, o + 5 + 2 * nm)))));
    if (check) {
      const bufs = [dst, t.tex].map(x => { const b = device.createBuffer({ size: S * S * 4, usage: GPUBufferUsage.COPY_DST | GPUBufferUsage.MAP_READ });
        e.copyTextureToBuffer({ texture: x }, { buffer: b, bytesPerRow: S * 4 }, [S, S]); return b; });
      device.queue.submit([e.finish()]);
      Promise.all(bufs.map(b => b.mapAsync(GPUMapMode.READ))).then(() => {
        const [x, y] = bufs.map(b => new Uint8Array(b.getMappedRange()));
        let diff = 0, max = 0, first = '';
        for (let k = 0; k < x.length; k += 4) {
          let dk = 0; for (let c = 0; c < 4; c++) dk = Math.max(dk, Math.abs(x[k + c] - y[k + c]));
          if (dk && !first) first = ` first at texel ${k / 4}: gpu ${x.subarray(k, k + 4).join(',')} game ${y.subarray(k, k + 4).join(',')}`;
          if (dk) diff++; max = Math.max(max, dk);
        }
        report(`gpu.js: skinhd check id ${w[a]} ${S}x${S} layers ${n} markers ${nm}: ${diff} texels differ, max ${max}${first}`);
      });
      return;
    }
    if (!t.skin || t.skin.width !== S) {
      t.skin?.destroy();
      t.skin = device.createTexture({ size: [S, S], mipLevelCount: Math.log2(S) + 1, format: 'rgba8unorm',
        usage: GPUTextureUsage.TEXTURE_BINDING | GPUTextureUsage.RENDER_ATTACHMENT | GPUTextureUsage.COPY_DST });
    }
    e.copyTextureToTexture({ texture: dst }, { texture: t.skin }, [S, S]);
    for (let l = 1; l <= Math.log2(S); l++) {
      const p = e.beginRenderPass({ colorAttachments: [{ view: t.skin.createView({ baseMipLevel: l, mipLevelCount: 1 }), loadOp: 'clear', storeOp: 'store' }] });
      p.setPipeline(mipPipe);
      p.setBindGroup(0, device.createBindGroup({ layout: mipPipe.getBindGroupLayout(0), entries: [
        { binding: 0, resource: t.skin.createView({ baseMipLevel: l - 1, mipLevelCount: 1 }) }, { binding: 1, resource: skinLin }] }));
      p.draw(3); p.end();
    }
    device.queue.submit([e.finish()]);
    t.view = t.skin.createView();
  }

  function run(ptr, len) {
    const w = H().subarray(ptr >> 2, (ptr >> 2) + len);
    const f32 = new Float32Array(w.buffer, w.byteOffset, w.length);
    const u8 = new Uint8Array(w.buffer, w.byteOffset, w.length * 4);
    const enc = device.createCommandEncoder();
    const uni = new ArrayBuffer(256 * 1024), uf = new Float32Array(uni);
    let nuni = 0, stats = { clears: 0, draws: 0, present: '', words: w.length, texKb: 0, pipes: 0, shaders: 0, targets: 0 };
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
        const sc = msFor(w[a + 1], w[a + 2]);
        const tex = device.createTexture({ size: [w[a + 1], w[a + 2]], format: depth ? 'depth24plus-stencil8' : 'rgba8unorm',
          sampleCount: depth ? sc : 1,
          usage: GPUTextureUsage.RENDER_ATTACHMENT | (depth ? 0 : GPUTextureUsage.COPY_SRC | GPUTextureUsage.TEXTURE_BINDING) });
        const ms = !depth && sc > 1 ? device.createTexture({ size: [w[a + 1], w[a + 2]], format: 'rgba8unorm', sampleCount: sc,
          usage: GPUTextureUsage.RENDER_ATTACHMENT }) : null;
        const old = res.get(w[a]);
        old?.tex.destroy(); old?.ms?.destroy();
        res.set(w[a], { tex, view: tex.createView(), w: w[a + 1], h: w[a + 2], depth, sc, ms, msView: ms?.createView() });
        stats.targets++;
      } else if (op === GPU_CLEAR) {
        endPass();
        const rt = w[a] ? res.get(w[a]) : null, ds = w[a + 1] ? res.get(w[a + 1]) : null, flags = w[a + 2];
        const c = w[a + 3], off = nuni * 256;
        if (nuni === 1024) fail('more than 1024 clears in a frame');
        uf.set([((c >>> 16) & 255) / 255, ((c >>> 8) & 255) / 255, (c & 255) / 255, (c >>> 24) / 255, f32[a + 4]], off / 4);
        nuni++;
        const p = enc.beginRenderPass({
          colorAttachments: rt ? [colorAtt(rt)] : [],
          depthStencilAttachment: ds ? { view: ds.view, depthLoadOp: 'load', depthStoreOp: 'store',
            stencilLoadOp: 'load', stencilStoreOp: 'store' } : undefined });
        p.setPipeline(clearPipe(!!rt, !!ds, flags, (rt || ds)?.sc || 1));
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
        stats.shaders++;
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
          usage: GPUTextureUsage.TEXTURE_BINDING | GPUTextureUsage.COPY_DST | GPUTextureUsage.COPY_SRC });
        const own = tex.createView();
        res.set(w[a], { tex, own, view: own, w: w[a + 1], h: w[a + 2], depth: false });
      } else if (op === GPU_CUBE) {
        // One texture, six layers: each face target draws into its layer, the stage samples the cube view.
        const e = w[a + 1], f0 = w[a + 2];
        const tex = device.createTexture({ size: [e, e, 6], format: 'rgba8unorm',
          usage: GPUTextureUsage.RENDER_ATTACHMENT | GPUTextureUsage.TEXTURE_BINDING | GPUTextureUsage.COPY_SRC });
        for (let k = 0; k < 6; k++) {
          res.get(f0 + k)?.tex.destroy();
          res.set(f0 + k, { tex, view: tex.createView({ dimension: '2d', baseArrayLayer: k, arrayLayerCount: 1 }), w: e, h: e, depth: false });
        }
        res.set(w[a], { tex, cube: tex.createView({ dimension: 'cube' }), w: e, h: e, depth: false });
        stats.targets++;
      } else if (op === GPU_TEXKEY) {
        const t = res.get(w[a]);
        if (t && pack.size) { t.key = (w[a + 2] >>> 0).toString(16).padStart(8, '0') + (w[a + 1] >>> 0).toString(16).padStart(8, '0'); useHd(t, t.key); }
      } else if (op === GPU_TEXDATA) {
        // queue.writeTexture runs before this frame's commands: a texture changed after a draw of the
        // same frame that used it would show its new texels in that draw (not seen yet).
        const t = res.get(w[a]), tw = w[a + 2], th = w[a + 3];
        device.queue.writeTexture({ texture: t.tex, mipLevel: w[a + 1] }, u8.subarray(4 * (a + 4), 4 * (a + 4 + tw * th)),
          { bytesPerRow: 4 * tw }, [tw, th]);
        stats.texKb += tw * th >> 8;
      } else if (op === GPU_DRAW) {
        const g = k => w[a + k];
        const rt = res.get(g(D_RT)), ds = g(D_DS) ? res.get(g(D_DS)) : null;
        const key = `${g(D_RT)}/${g(D_DS)}`;
        if (key !== passKey) {
          endPass();
          pass = enc.beginRenderPass({
            colorAttachments: [colorAtt(rt)],
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
          pass.setPipeline(pipeline(w, a, stride, rt.sc || 1));
          pass.setBindGroup(0, uBind, [uoff]);
          const entries = [];
          for (let k = 0; k < 8; k++) if (ps.texMask >> k & 1) {
            const t = w.subarray(a + D_TEX + D_TEXN * k, a + D_TEX + D_TEXN * (k + 1));
            const img = t[T_ID] ? res.get(t[T_ID]) : null, cube = (t[T_TT] & T_CUBE) !== 0;
            entries.push({ binding: 2 * k, resource: sampler(t) },
              { binding: 2 * k + 1, resource: !cube && img?.view || dummyView },
              { binding: 16 + k, resource: cube && img?.cube || dummyCubeView });
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
      } else if (op === GPU_FXAA) {
        endPass();
        const rt = res.get(w[a]);
        if (FXAA_ON && rt && !rt.depth && !rt.msView) {
          if (!fxaaTmp || fxaaTmp.width !== rt.w || fxaaTmp.height !== rt.h) {
            fxaaTmp?.destroy();
            fxaaTmp = device.createTexture({ size: [rt.w, rt.h], format: 'rgba8unorm', usage: GPUTextureUsage.COPY_DST | GPUTextureUsage.TEXTURE_BINDING });
          }
          enc.copyTextureToTexture({ texture: rt.tex }, { texture: fxaaTmp }, [rt.w, rt.h]);
          const p = enc.beginRenderPass({ colorAttachments: [{ view: rt.view, loadOp: 'load', storeOp: 'store' }] });
          p.setPipeline(fxaaPipe);
          p.setBindGroup(0, device.createBindGroup({ layout: fxaaPipe.getBindGroupLayout(0),
            entries: [{ binding: 0, resource: fxaaTmp.createView() }, { binding: 1, resource: fxaaSamp }] }));
          p.draw(3);
          p.end();
        }
      } else if (op === GPU_SKIN) {
        skin(w, a);
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
    stats.pipes = newPipes; newPipes = 0;
    stats.hd = packed;
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
        const t = performance.now();
        const s = run(h[box + 2 + (k & 1)], h[box + 4 + (k & 1)]);
        onFrame?.(s, t, performance.now() - t);
        frames++;
        if (s.present) presents++;
        if (frames <= 3 || frames % 300 === 0) report(`gpu.js: frame ${frames}: ${s.clears} clears, ${s.draws} draws, present ${s.present}` +
          (pack.size ? `, remaster ${packed}` : ''));
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
