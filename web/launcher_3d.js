// Pre-game launcher v3: a real 3D street corner (three.js, vendored in web/launcher/vendor/three) with the menu standing inside it.
// Defines window.RN_SCENE (same calls as v2, see launcher.js): start(canvas,{base}) -> Promise, onIntroDone(cb), select(i,n,screen), screen(name),
// confirm() -> Promise, motion(on), pointer(x,y), screenPos(i) -> {x,y}; plus stats() when the URL has #perf.
// Walls, floor and signs use textures from the game's own files (web/launcher/v3/tex, extracted from web/remaster/ and build/launcher_ref/picks).
// The menu labels are drawn with the game's font atlas (launcher/v2/ui/game_font.*). If WebGL2 or an asset fails, start() rejects and the page shows the static plate.
import * as THREE from 'three';
import { createRain } from './launcher_rain.js';
import { createLampSparks } from './launcher_sparks.js';
import { EffectComposer } from 'three/addons/postprocessing/EffectComposer.js';
import { RenderPass } from 'three/addons/postprocessing/RenderPass.js';
import { UnrealBloomPass } from 'three/addons/postprocessing/UnrealBloomPass.js';
import { ShaderPass } from 'three/addons/postprocessing/ShaderPass.js';
import { Reflector } from 'three/addons/objects/Reflector.js';
import { GLTFLoader } from 'three/addons/loaders/GLTFLoader.js';
import { mergeGeometries } from 'three/addons/utils/BufferGeometryUtils.js';

const { Vector3: V3, Color } = THREE;
const clamp = (v, a, b) => Math.max(a, Math.min(b, v));
const lerp = (a, b, t) => a + (b - a) * t;
const sm = (a, b, x) => { const t = clamp((x - a) / (b - a), 0, 1); return t * t * (3 - 2 * t); };
const hash = n => { const s = Math.sin(n * 127.1 + 311.7) * 43758.5453; return s - Math.floor(s); };
const noise1 = x => { const i = Math.floor(x), f = x - i, u = f * f * (3 - 2 * f); return lerp(hash(i), hash(i + 1), u); };
const PERF = /perf/.test(location.hash);
const ACC = [0xff2a3c, 0xff3fa4, 0x3e8ffb, 0x4ddc32];            // Jugar / Perfiles / Opciones / Controles: the game's neon palette

// neon tube: steady with fast dips and the odd dropout (a = amount)
const flick = (t, s, a = 1) => {
  let v = .93 + .07 * Math.sin(t * 41 + s * 5);
  if (noise1(t * 2.6 + s * 17) > .88) v *= .2 + .8 * hash(Math.floor(t * 28) + s * 9);
  return lerp(1, v, a);
};
// fluorescent strike: a few hard on/off steps in the first half second, then steady
const strike = s => s < 0 ? 0 : s > .55 ? 1 : (hash(Math.floor(s * 38) + 3.1) > .45 ? 1 : .12) * sm(0, .08, s);
const ease = t => t < .5 ? 4 * t * t * t : 1 - Math.pow(-2 * t + 2, 3) / 2;

// ---------------------------------------------------------------- state
let renderer, scene, camera, composer, finalPass, bloomPass, reflector, base = 'launcher/v3/', canvas;
let W = 1, H = 1, pr = 1, running = false, started = false, tNow = 0, lastT = 0, introDone = false, introCb = null;
let motion = true, screenName = 'main', selIdx = 0, hover = -1, going = null, perfSamples = [], glTimer = null;
const ptr = { x: 0, y: 0, sx: 0, sy: 0 };
const L = {};                       // named lights: { light, base (intensity), t0 (strike time), seed, mats[] }
const neons = [];                   // emissive things that flicker: { mat, base, light, seed }
const panels = [];                  // menu light-boxes
let car = null, totem = null, sky = null, rain = null, steam = [], cones = [], carLights = null, lampPos = new V3();
const layoutPos = { car: new V3(1.2, 0, -.5), totem: new V3(-4.7, 0, 1.3) };
const rig = { az: .3, el: .1, r: 9.2, tx: -.9, ty: 1.35, tz: 0, fov: 36, sx: 0, sy: 0, focus: 9 };
const goal = { ...rig };
const SHOTS = {
  main: { az: .32, el: .1, r: 11.4, tx: -.5, ty: 1.75, tz: 0, fov: 36, sx: 0, sy: 0 },
  presets: { az: .62, el: .2, r: 11.5, tx: 1.6, ty: 1.2, tz: -1.6, fov: 36, sx: 0, sy: -.34 },
  opts: { az: .5, el: .12, r: 9.0, tx: 1.2, ty: 1.2, tz: -.5, fov: 36, sx: -.5, sy: 0 },
  ctrl: { az: .5, el: .12, r: 9.0, tx: 1.2, ty: 1.2, tz: -.5, fov: 36, sx: -.5, sy: 0 },
};

// ---------------------------------------------------------------- shared GLSL
const GLSL_WET = /* glsl */`
float h21(vec2 p){ p = fract(p * vec2(123.34, 456.21)); p += dot(p, p + 45.32); return fract(p.x * p.y); }
vec2 h22(vec2 p){ float n = h21(p); return vec2(n, h21(p + n)); }
float vnoise(vec2 p){ vec2 i = floor(p), f = fract(p); f = f * f * (3. - 2. * f); return mix(mix(h21(i), h21(i + vec2(1, 0)), f.x), mix(h21(i + vec2(0, 1)), h21(i + vec2(1, 1)), f.x), f.y); }
float fbm(vec2 p){ float a = .5, s = 0.; for (int i = 0; i < 4; i++){ s += a * vnoise(p); p *= 2.03; a *= .5; } return s; }
// rain rings: xy = surface slope, z = ring energy
vec3 ripples(vec2 p, float t){
  vec2 g = p * 1.9, id = floor(g), f = fract(g); vec3 acc = vec3(0.);
  for (int j = -1; j <= 1; j++) for (int i = -1; i <= 1; i++){
    vec2 o = vec2(float(i), float(j)), c = id + o, h = h22(c);
    vec2 q = f - o - h; float d = length(q);
    float life = fract(t * .55 + h21(c + 7.3)), r = life * .62;
    float w = exp(-pow((d - r) * 15., 2.)) * (1. - life) * (1. - life);
    acc.xy += q / (d + 1e-4) * w * cos((d - r) * 34.); acc.z += w;
  }
  return acc;
}
// Broad low spots collect water; fine aggregate breaks only the damp areas.
float wetAt(vec2 p){
  vec2 q = p * vec2(.24, .18);
  float basin = fbm(q + vec2(vnoise(q * 1.7), vnoise(q * 1.7 + 19.)) * .65);
  float gutter = exp(-abs(p.x + 4.85) * 3.) * .12;
  return smoothstep(.43, .55, basin + gutter);
}
vec2 asphaltSlope(vec2 p){ return (vec2(vnoise(p * 38.), vnoise(p * 38. + 17.)) - .5) * .32; }
`;

// ---------------------------------------------------------------- loading
const TL = new THREE.TextureLoader();
const T = {};                                // name -> THREE.Texture
const TEX = ['asphalt2', 'shutter', 'fence', 'brick', 'stone', 'store', 'door', 'slab', 'junk', 'graf1', 'graf2', 'graf3', 'graf4', 'neon_shanghai', 'neon_open', 'neon_lounge', 'neon_gift', 'neon_open24', 'chev'];
const tex = (name, rx = 1, ry = 1, srgb = true) => {
  const t = T[name].clone(); t.needsUpdate = true; t.repeat.set(rx, ry);
  t.wrapS = t.wrapT = THREE.RepeatWrapping; t.colorSpace = srgb ? THREE.SRGBColorSpace : THREE.NoColorSpace; t.anisotropy = 8; return t;
};
async function loadAssets() {
  await Promise.all(TEX.map(async n => { const t = await TL.loadAsync(base + 'tex/' + n + '.webp'); t.colorSpace = THREE.SRGBColorSpace; T[n] = t; }));
}
// the game's font -> a function that draws a string into a canvas (white glyphs, transparent)
let FONT = null;
async function loadFont() {
  try {
    const [j, img] = await Promise.all([fetch('launcher/v2/ui/game_font.json').then(r => r.json()), new Promise((res, rej) => { const i = new Image(); i.onload = () => res(i); i.onerror = rej; i.src = 'launcher/v2/ui/game_font.png'; })]);
    const c = document.createElement('canvas'); c.width = img.naturalWidth; c.height = img.naturalHeight;
    const x = c.getContext('2d', { willReadFrequently: true }); x.drawImage(img, 0, 0);
    const d = x.getImageData(0, 0, c.width, c.height), px = d.data;
    let alpha = false; for (let i = 3; i < px.length; i += 4) if (px[i] < 250) { alpha = true; break; }
    if (!alpha) for (let i = 0; i < px.length; i += 4) { px[i + 3] = Math.max(px[i], px[i + 1], px[i + 2]); px[i] = px[i + 1] = px[i + 2] = 255; }
    x.putImageData(d, 0, 0);
    const g = j.chars || j.glyphs || {}, lh = +j.lineHeight || 124, bs = +j.base || lh * .75, cap = (g.H || g.E || { h: lh * .6 }).h, sp = (g[' '] && g[' '].adv) || cap * .4;
    FONT = { g, atlas: c, lh, bs, cap, sp };
  } catch { FONT = null; }
}
function labelCanvas(str, cw, ch, capFrac, left) {
  const c = document.createElement('canvas'); c.width = cw; c.height = ch; const x = c.getContext('2d');
  const s = String(str).toUpperCase();
  if (!FONT) { x.fillStyle = '#fff'; x.font = `italic 700 ${ch * capFrac * 1.4}px sans-serif`; x.textBaseline = 'middle'; x.fillText(s, left, ch / 2); return c; }
  const { g, atlas, lh, bs, cap, sp } = FONT, gl = k => g[k] || g[k.toLowerCase()];
  let w = 0; for (const k of s) { const q = gl(k); w += q ? q.adv : sp; }
  const t = document.createElement('canvas'); t.width = Math.ceil(w) + 4; t.height = Math.ceil(lh) + 4; const tx = t.getContext('2d'); let cx = 0;
  for (const k of s) { const q = gl(k); if (q) { if (q.w > 0 && q.h > 0) tx.drawImage(atlas, q.x, q.y, q.w, q.h, Math.round(cx + q.xo), Math.round(q.yo), q.w, q.h); cx += q.adv; } else cx += sp; }
  const k = ch * capFrac / cap, yc = bs - cap / 2;
  x.drawImage(t, 0, 0, t.width, t.height, left, ch / 2 - yc * k, t.width * k, t.height * k);
  return c;
}
const canvasTex = (c, srgb = true) => { const t = new THREE.CanvasTexture(c); t.colorSpace = srgb ? THREE.SRGBColorSpace : THREE.NoColorSpace; t.anisotropy = 8; return t; };

// ---------------------------------------------------------------- helpers
const lam = (name, rx, ry, o = {}) => new THREE.MeshLambertMaterial({ map: tex(name, rx, ry), color: new Color(2.1, 2.0, 2.0), ...o });   // game textures are dark: lift them
class Merge {                                // many boxes, one draw call
  constructor(mat) { this.mat = mat; this.g = []; }
  box(w, h, d, x, y, z, ry = 0, rx = 0, rz = 0) {
    const g = new THREE.BoxGeometry(w, h, d); const m = new THREE.Matrix4().compose(new V3(x, y, z), new THREE.Quaternion().setFromEuler(new THREE.Euler(rx, ry, rz)), new V3(1, 1, 1));
    g.applyMatrix4(m); this.g.push(g); return this;
  }
  cyl(r, h, x, y, z, seg = 8, rx = 0, rz = 0) {
    const g = new THREE.CylinderGeometry(r, r, h, seg, 1); g.applyMatrix4(new THREE.Matrix4().compose(new V3(x, y, z), new THREE.Quaternion().setFromEuler(new THREE.Euler(rx, 0, rz)), new V3(1, 1, 1))); this.g.push(g); return this;
  }
  mesh(parent, cast = true, recv = true) { const m = new THREE.Mesh(mergeGeometries(this.g.map(g => g.index ? g : g)), this.mat); m.castShadow = cast; m.receiveShadow = recv; parent.add(m); return m; }
}
const boxMesh = (parent, mat, w, h, d, x, y, z, ry = 0, cast = true) => { const m = new THREE.Mesh(new THREE.BoxGeometry(w, h, d), mat); m.position.set(x, y, z); m.rotation.y = ry; m.castShadow = cast; m.receiveShadow = true; parent.add(m); return m; };
const LK = .085;                            // lights are in candela (three r170): the numbers below are written for a 2 m to 10 m street
const addLight = (name, light, t0, seed = 0, o = {}) => { light.intensity *= LK; L[name] = { light, base: light.intensity, t0, seed, ...o }; scene.add(light); if (light.target) scene.add(light.target); return L[name]; };

function wire(a, b, sag, list, r = .024) {
  const mid = a.clone().lerp(b, .5); mid.y -= sag * 2;
  list.push(new THREE.TubeGeometry(new THREE.QuadraticBezierCurve3(a, mid, b), 28, r, 4, false));
}
function softTex(inner = 1, size = 128) {         // radial glow
  const c = document.createElement('canvas'); c.width = c.height = size; const x = c.getContext('2d');
  const g = x.createRadialGradient(size / 2, size / 2, 0, size / 2, size / 2, size / 2); g.addColorStop(0, `rgba(255,255,255,${inner})`); g.addColorStop(.4, `rgba(255,255,255,${inner * .35})`); g.addColorStop(1, 'rgba(255,255,255,0)');
  x.fillStyle = g; x.fillRect(0, 0, size, size); return canvasTex(c, false);
}
function windowTex() {                            // distant lit windows
  const c = document.createElement('canvas'); c.width = 128; c.height = 256; const x = c.getContext('2d'); x.fillStyle = '#05070c'; x.fillRect(0, 0, 128, 256);
  for (let j = 0; j < 32; j++) for (let i = 0; i < 12; i++) { const h = hash(i * 13.7 + j * 71.3); if (h > .42) { x.fillStyle = h > .9 ? '#ffd9a0' : h > .8 ? '#8fd2ff' : h > .7 ? '#ff9ad0' : '#c79b62'; x.globalAlpha = .45 + h * .5; x.fillRect(i * 10.6 + 2, j * 8 + 2, 6, 4); } }
  const t = canvasTex(c); t.wrapS = t.wrapT = THREE.RepeatWrapping; return t;
}

// ---------------------------------------------------------------- the world
function buildWorld() {
  scene.fog = new THREE.FogExp2(0x0b1224, .021);
  // --- sky dome and far skyline
  sky = new THREE.Mesh(new THREE.SphereGeometry(220, 24, 12), new THREE.ShaderMaterial({
    side: THREE.BackSide, depthWrite: false, fog: false, uniforms: { uT: { value: 0 } },
    vertexShader: 'varying vec3 vP; void main(){ vP = position; gl_Position = projectionMatrix * modelViewMatrix * vec4(position, 1.); }',
    fragmentShader: `varying vec3 vP; uniform float uT; void main(){ vec3 d = normalize(vP); float h = clamp(d.y, 0., 1.);
      vec3 hz = vec3(.30, .13, .19), mid = vec3(.05, .07, .15), top = vec3(.012, .02, .045);
      vec3 c = mix(hz, mid, smoothstep(0., .22, h)); c = mix(c, top, smoothstep(.15, .8, h));
      c += vec3(.22, .09, .05) * exp(-pow((d.x + .25) * 3.2, 2.)) * exp(-h * 9.) * step(d.z, 0.);   // sodium glow over the avenue
      gl_FragColor = vec4(c, 1.); }`,
  }));
  sky.renderOrder = -10; sky.frustumCulled = false; scene.add(sky);
  const wt = windowTex(), sk = [];
  for (let i = 0; i < 64; i++) {
    const a = lerp(-1.35, 1.35, i / 63) + (hash(i) - .5) * .05, R = 62 + hash(i + 9) * 55, h = 24 + hash(i + 3) * 70, w = 9 + hash(i + 5) * 14;
    const t = wt.clone(); t.needsUpdate = true; t.repeat.set(w / 14, h / 28); t.offset.set(hash(i), hash(i + 1));
    const m = new THREE.Mesh(new THREE.BoxGeometry(w, h, w), new THREE.MeshBasicMaterial({ map: t, color: new Color(.55, .6, .8), fog: false }));
    m.position.set(R * Math.sin(a), h / 2 - 2, -R * Math.cos(a) - 8); scene.add(m); sk.push(m);
  }

  // --- ground: road (lit, wet, ripples) + sidewalks + the reflection overlay
  const uTime = { value: 0 };
  const roadMap = tex('asphalt2', 9, 9); roadMap.anisotropy = 16;
  const floorMat = new THREE.MeshStandardMaterial({ map: roadMap, color: 0x8c8c94, roughness: .6, metalness: 0 });
  floorMat.onBeforeCompile = sh => {
    sh.uniforms.uTime = uTime;
    sh.vertexShader = 'varying vec3 vWP;\n' + sh.vertexShader.replace('#include <project_vertex>', '#include <project_vertex>\n vWP = (modelMatrix * vec4(transformed, 1.)).xyz;');
    sh.fragmentShader = 'varying vec3 vWP; uniform float uTime;\n' + GLSL_WET + sh.fragmentShader
      .replace('#include <map_fragment>', '#include <map_fragment>\n float wetF = wetAt(vWP.xz); diffuseColor.rgb *= mix(.78, .42, wetF);')
      .replace('#include <roughnessmap_fragment>', '#include <roughnessmap_fragment>\n roughnessFactor = mix(.86, .045, wetF); vec3 rip = ripples(vWP.xz, uTime); vec2 slope = mix(asphaltSlope(vWP.xz), rip.xy * .045, wetF);')
      .replace('#include <normal_fragment_maps>', '#include <normal_fragment_maps>\n normal = normalize(normal + (viewMatrix * vec4(slope.x, 0., slope.y, 0.)).xyz);');
  };
  const floor = new THREE.Mesh(new THREE.PlaneGeometry(90, 70), floorMat); floor.rotation.x = -Math.PI / 2; floor.position.set(10, 0, 0); floor.receiveShadow = true; scene.add(floor);
  roadMap.repeat.set(24, 18);

  const rShader = {
    name: 'WetReflector',
    uniforms: { color: { value: null }, tDiffuse: { value: null }, textureMatrix: { value: null }, uTime, uStr: { value: 1 } },
    vertexShader: 'uniform mat4 textureMatrix; varying vec4 vUv; varying vec3 vWP; void main(){ vUv = textureMatrix * vec4(position, 1.); vec4 w = modelMatrix * vec4(position, 1.); vWP = w.xyz; gl_Position = projectionMatrix * viewMatrix * w; }',
    fragmentShader: `uniform vec3 color; uniform sampler2D tDiffuse; uniform float uTime, uStr; varying vec4 vUv; varying vec3 vWP;
      ${GLSL_WET}
      void main(){
        float wet = wetAt(vWP.xz), rough = 1. - wet; vec3 rp = ripples(vWP.xz, uTime);
        vec3 V = normalize(cameraPosition - vWP);
        vec2 slope = mix(asphaltSlope(vWP.xz), rp.xy * .045, wet);
        vec3 N = normalize(vec3(slope.x, 1., slope.y));
        // Water IOR 1.33: Schlick Fresnel, with stronger reflection at grazing angles.
        float F = .02 + .98 * pow(1. - max(dot(N, V), 0.), 5.);
        vec2 uv = vUv.xy / vUv.w + slope * mix(.014, .035, wet);
        vec3 acc = texture2D(tDiffuse, clamp(uv, vec2(.002), vec2(.998))).rgb;
        if (rough > .025){
          acc *= 3.; float ws = 3.;
          // Seven taps total: a narrow horizontal lobe and a long vertical wet-road streak.
          float spread = mix(.00025, .027, rough * rough);
          for (int i = -3; i <= 3; i++){
            if (i == 0) continue;
            float f = float(i), w = exp(-f * f * .22);
            vec2 o = vec2(sin(f * 2.4) * spread * .12, f * spread);
            acc += texture2D(tDiffuse, clamp(uv + o, vec2(.002), vec2(.998))).rgb * w; ws += w;
          }
          acc /= ws;
        }
        float k = mix(.19, .96, wet);
        gl_FragColor = vec4(acc + rp.z * wet * vec3(.008, .012, .016), clamp(F * k * uStr, 0., .96));
      }`,
  };
  reflector = new Reflector(new THREE.PlaneGeometry(90, 70), { textureWidth: 640, textureHeight: 360, clipBias: .003, shader: rShader, multisample: 0 });
  reflector.rotation.x = -Math.PI / 2; reflector.position.set(10, .004, 0);
  Object.assign(reflector.material, { transparent: true, blending: THREE.NormalBlending, depthWrite: false, polygonOffset: true, polygonOffsetFactor: -2, polygonOffsetUnits: -2 });
  scene.add(reflector);
  // Prior art: https://github.com/mrdoob/three.js/blob/r170/examples/jsm/objects/Reflector.js (cloned uniforms).
  // Share the live clock with the road material.
  reflector.material.uniforms.uTime = uTime;
  reflector.userData.uTime = uTime;

  // road paint: yellow double line along the street, white stop bar and crosswalk (planes on the asphalt: they also make the vanishing lines)
  const paint = new THREE.MeshBasicMaterial({ color: 0x8a7a2a, transparent: true, opacity: .75, depthWrite: false, polygonOffset: true, polygonOffsetFactor: -1 });
  const white = new THREE.MeshBasicMaterial({ color: 0x9aa0a6, transparent: true, opacity: .6, depthWrite: false, polygonOffset: true, polygonOffsetFactor: -1 });
  const strip = (m, w, d, x, z, ry = 0) => { const p = new THREE.Mesh(new THREE.PlaneGeometry(w, d), m); p.rotation.x = -Math.PI / 2; p.rotation.z = ry; p.position.set(x, .006, z); scene.add(p); };
  strip(paint, 60, .1, 10, 5.2); strip(paint, 60, .1, 10, 5.45);
  for (let i = 0; i < 8; i++) strip(white, .5, 3, -2.2 + i * .9 - 11.5, 8.4);          // crosswalk bars at left
  for (let i = 0; i < 9; i++) strip(white, 2.2, .35, -14 + i * 4.2, 11.6 + 0);          // lane dashes
  strip(white, .3, 5.2, 9.4, 8.2); strip(white, .3, 5.2, 17.8, 8.2);

  // --- walls
  const wallsG = new THREE.Group(); scene.add(wallsG);
  const emissiveBrick = (() => {                  // the brick tile's own lit windows -> an emissive map
    const im = T.brick.image, c = document.createElement('canvas'); c.width = c.height = 512; const x = c.getContext('2d', { willReadFrequently: true }); x.drawImage(im, 0, 0, 512, 512);
    const d = x.getImageData(0, 0, 512, 512), p = d.data;
    for (let i = 0; i < p.length; i += 4) { const r = p[i], g = p[i + 1], b = p[i + 2]; const on = r > 175 && g > 130 && b < 170 && r - b > 40; if (on) { p[i] = Math.min(255, r * 1.1); p[i + 1] = g; p[i + 2] = b * .8; } else { p[i] = p[i + 1] = p[i + 2] = 0; } }
    x.putImageData(d, 0, 0); return canvasTex(c);
  })();
  const brickMat = (rx, ry) => { const m = lam('brick', rx, ry); const e = emissiveBrick.clone(); e.needsUpdate = true; e.wrapS = e.wrapT = THREE.RepeatWrapping; e.repeat.set(rx, ry); m.emissiveMap = e; m.emissive = new Color(1, .8, .5); m.emissiveIntensity = 1.6; return m; };
  const dark = new THREE.MeshLambertMaterial({ color: 0x14161a });
  const tin = new THREE.MeshStandardMaterial({ color: 0x3a3f46, metalness: .8, roughness: .4 });
  const wall = (x0, x1, y1, z0, z1, mat, y0 = 0) => boxMesh(wallsG, mat, x1 - x0, y1 - y0, z1 - z0, (x0 + x1) / 2, (y0 + y1) / 2, (z0 + z1) / 2, 0, false);
  // left building: brick with lit windows / recessed storefront / brick again; stepping in z gives real depth
  wall(-14, -8, 18, -9.2, -2.5, brickMat(2.4, 3));
  wall(-14, -8.7, 18, -2.5, 3.5, lam('store', 2.2, 2.6));
  wall(-14, -7.6, 18, 3.5, 20, brickMat(3.2, 3));
  // back wall: stone / garage / alley / doorway / junk-yard front
  wall(-14, -1, 16, -14, -9, lam('stone', 2.2, 2.6));
  wall(-1, .8, 16, -14, -9, lam('stone', .6, 2.6)); wall(4.5, 5.5, 16, -14, -9, lam('stone', .4, 2.6)); wall(.8, 4.5, 16, -14, -9, lam('store', 1.2, 1.2), 3.3);
  wall(.8, 4.5, 3.3, -14, -11, dark);                                   // garage interior
  wall(8.5, 17, 16, -14, -9, lam('door', 2.2, 2.6));
  wall(17, 44, 14, -14, -9, lam('junk', 5, 3));
  // alley: two side walls and a far wall
  wall(4.4, 5.5, 15, -26, -9, lam('slab', 4, 2.4)); wall(8.5, 9.6, 15, -26, -9, lam('slab', 4, 2.4)); wall(4.4, 9.6, 15, -28, -26, lam('door', 1.2, 2));
  // sidewalks and curbs
  const sidewalk = lam('slab', 3, 1); sidewalk.color.set(0x7c7f86);
  boxMesh(scene, sidewalk, 2.9, .18, 29, -6.65, .09, 5.5, 0, false); boxMesh(scene, sidewalk, 2.9, .18, 29, -6.65, .09, 5.5, 0, false).visible = false;
  boxMesh(scene, sidewalk, 21.5, .18, 2.9, -3.2, .09, -7.55, 0, false);
  boxMesh(scene, sidewalk, 35, .18, 2.9, 26.5, .09, -7.55, 0, false);
  const curb = new THREE.MeshLambertMaterial({ color: 0x9a9a9a });
  boxMesh(scene, curb, .22, .2, 29, -5.1, .1, 5.5, 0, false); boxMesh(scene, curb, 21.5, .2, .22, -3.2, .1, -6.0, 0, false); boxMesh(scene, curb, 35, .2, .22, 26.5, .1, -6.0, 0, false);

  // wall detail (merged): cornices, plinths, pilasters, ledges, awnings, pipes, A/C units
  const trim = new Merge(new THREE.MeshLambertMaterial({ color: 0x4b4540 }));
  trim.box(.9, .5, 29, -7.7, 17.5, 5, 0).box(.5, .35, 29, -7.9, 11, 5).box(.5, .4, 7.5, -8.4, 7.5, 0).box(.6, .25, 7.5, -8.9, 12.8, 0);
  trim.box(31, .6, .9, 8, 15.5, -8.6).box(31, .35, .5, 8, 9.5, -8.8).box(31, .5, .5, 8, .25, -8.8);
  for (const x of [-7.7, -4, -.2, 5.6, 8.4, 12, 16.5]) trim.box(.7, 15, .55, x, 7.5, -8.7);
  for (const z of [-8.5, -2.5, 3.8, 9, 14]) trim.box(.55, 16, .7, -7.7, 8, z);
  trim.mesh(wallsG);
  const pipes = new Merge(new THREE.MeshStandardMaterial({ color: 0x2a2d31, metalness: .7, roughness: .5 }));
  pipes.cyl(.09, 16, -7.8, 8, -4.4, 8).cyl(.09, 16, 5.3, 8, -8.6, 8).cyl(.07, 14, 9.9, 7, -8.65, 8).cyl(.1, 2.5, -7.45, 2.2, 1.0, 8, 0, Math.PI / 2);
  pipes.box(1.2, .8, .9, -7.3, 4.4, -6.4).box(1.1, .75, .8, -7.3, 7.5, -5.2).box(1.4, .9, 1, -4.3, 4.8, -8.4);   // A/C boxes
  pipes.mesh(wallsG);
  // fire escape on the left building: platforms, rails, stairs
  const fe = new Merge(new THREE.MeshStandardMaterial({ color: 0x1c1e22, metalness: .75, roughness: .55 }));
  for (const y of [3.4, 6.6, 9.8]) {
    fe.box(1.6, .08, 5.2, -7.2, y, -6.2);
    fe.box(.05, .9, 5.2, -6.45, y + .5, -6.2).box(1.6, .05, .05, -7.2, y + .95, -8.75).box(1.6, .05, .05, -7.2, y + .95, -3.65);
    for (let k = 0; k < 10; k++) fe.box(.04, .85, .04, -6.45, y + .5, -8.7 + k * .55);
    fe.box(.05, .05, 5.2, -6.45, y + .95, -6.2);
    fe.box(.05, 3.3, .05, -6.5, y - 1.6, -3.7).box(.05, 3.3, .05, -6.5, y - 1.6, -8.7);
  }
  for (const y of [5, 8.2]) { fe.box(.9, .05, 3.5, -7.1, y, -4.5, 0, 0, .0); for (let k = 0; k < 6; k++) fe.box(.7, .04, .12, -7.1, y - 1.5 + k * .27, -4.6 + k * .12); }
  fe.mesh(wallsG);
  // garage: jambs, a half-raised shutter, warm interior glow
  const shutterMat = new THREE.MeshStandardMaterial({ map: tex('shutter', 2.4, 1.2), color: 0x9a9a9a, metalness: .7, roughness: .5 });
  const sh = boxMesh(wallsG, shutterMat, 3.6, 1.9, .12, 2.65, 4.0 - .95 - 0.0, -8.8, 0, false); sh.position.y = 2.35;
  const glowMat = new THREE.MeshBasicMaterial({ color: new Color(1, .62, .26).multiplyScalar(2.2) }); glowMat.map = null;
  const garageBack = new THREE.Mesh(new THREE.PlaneGeometry(3.7, 3.3), new THREE.ShaderMaterial({
    uniforms: { uI: { value: 1 } }, vertexShader: 'varying vec2 vU; void main(){ vU = uv; gl_Position = projectionMatrix * modelViewMatrix * vec4(position, 1.); }',
    fragmentShader: 'varying vec2 vU; uniform float uI; void main(){ float g = smoothstep(1., 0., vU.y) * .8 + .2; vec3 c = mix(vec3(1., .5, .18), vec3(1., .7, .4), 1. - vU.y) * g * .4 * uI; gl_FragColor = vec4(c, 1.); }' }));
  garageBack.position.set(2.65, 1.65, -10.9); wallsG.add(garageBack); L.garageGlow = { mat: garageBack.material };
  // light spilled on the road from the garage: an additive fan on the asphalt
  const spill = new THREE.Mesh(new THREE.PlaneGeometry(5.6, 6), new THREE.MeshBasicMaterial({ map: softTex(.6), color: new Color(1, .55, .2), transparent: true, blending: THREE.AdditiveBlending, depthWrite: false, opacity: .0 }));
  spill.rotation.x = -Math.PI / 2; spill.position.set(2.65, .008, -6.2); scene.add(spill); L.spill = { mat: spill.material };
  const crates = new Merge(new THREE.MeshStandardMaterial({ color: 0x2b2118, roughness: .9 }));
  crates.box(.9, .6, .9, 1.2, .3, -10.3).box(.7, .5, .7, 1.25, .85, -10.2, .3).box(1.2, 1.1, .6, 3.9, .55, -10.5).box(.6, 2.4, .6, 0.9, 1.2, -12);
  crates.mesh(wallsG);
  // dumpsters and bags in the alley, a chain-link fence across it
  const dump = new Merge(new THREE.MeshStandardMaterial({ color: 0x1b3a2a, roughness: .55, metalness: .4 }));
  dump.box(2.1, 1.25, 1.1, 5.4 + 1.15, .62, -13).box(2.2, .12, 1.2, 6.55, 1.3, -13.1, 0, 0, .06).box(2.1, 1.25, 1.1, 7.55, .62, -17.5);
  dump.mesh(wallsG);
  const bags = new Merge(new THREE.MeshStandardMaterial({ color: 0x0a0a0c, roughness: .35, metalness: .1 }));
  for (let i = 0; i < 7; i++) bags.box(.5, .4, .45, 8.1 - hash(i) * 1.4, .2 + (i % 3) * .05, -10.4 - hash(i + 4) * 2.8, hash(i) * 3);
  bags.mesh(wallsG);
  const fence = new THREE.Mesh(new THREE.PlaneGeometry(4.2, 3.2), new THREE.MeshBasicMaterial({ map: tex('fence', 5, 4), alphaTest: .35, side: THREE.DoubleSide, color: 0x66707a, fog: true }));
  fence.position.set(7, 1.6, -21); wallsG.add(fence);
  // graffiti slabs as pieces on the walls
  const decal = (name, w, h, x, y, z, ry, dim = 1) => { const m = new THREE.Mesh(new THREE.PlaneGeometry(w, h), new THREE.MeshLambertMaterial({ map: tex(name), color: new Color(dim, dim, dim), polygonOffset: true, polygonOffsetFactor: -1 })); m.position.set(x, y, z); m.rotation.y = ry; wallsG.add(m); return m; };
  decal('graf3', 7, 3.5, 24, 2.4, -8.97, 0); decal('graf4', 6, 3, 31, 3, -8.97, 0, .9); decal('graf1', 4.2, 4.2, 6.97, 2.6, -17, -Math.PI / 2, .9); decal('graf2', 3.8, 3.8, 5.58, 3, -14.5, Math.PI / 2, .8);

  // --- signs (additive neon on a black box)
  const neonGlow = softTex(.8);
  const neon = (name, w, h, x, y, z, ry, col, I, light, lightPos, key) => {
    const g = new THREE.Group(); g.position.set(x, y, z); g.rotation.y = ry; scene.add(g);
    const back = new THREE.Mesh(new THREE.BoxGeometry(w + .2, h + .2, .16), new THREE.MeshStandardMaterial({ color: 0x07080a, metalness: .6, roughness: .5 })); back.position.z = -.09; g.add(back);
    const m = new THREE.MeshBasicMaterial({ map: tex(name), color: col.clone().multiplyScalar(I), transparent: true, blending: THREE.AdditiveBlending, depthWrite: false, side: THREE.DoubleSide, toneMapped: false });
    const p = new THREE.Mesh(new THREE.PlaneGeometry(w, h), m); g.add(p); p.renderOrder = 4;
    const n = { mat: m, base: I, col, seed: neons.length * 3.7 + 1, key, mult: 0 }; neons.push(n);
    if (light) { n.light = light; light.position.set(...lightPos); }
    // Soft spill cards supplement the existing point lights without another lighting pass.
    const tint = light ? light.color : new Color(key === 'lounge' ? 0xff54bb : 0xff4333);
    const spillMat = new THREE.MeshBasicMaterial({ map: neonGlow, color: tint, transparent: true, opacity: 0, blending: THREE.AdditiveBlending, depthWrite: false, polygonOffset: true, polygonOffsetFactor: -1 });
    const wallGlow = new THREE.Mesh(new THREE.PlaneGeometry(w + 3.8, h + 3.2), spillMat);
    wallGlow.position.z = -.174; g.add(wallGlow);
    if (key === 'pink') { wallGlow.position.set(-1.79, -.6, 2.55); wallGlow.rotation.y = Math.PI / 2; }
    const roadMat = spillMat.clone();
    const roadGlow = new THREE.Mesh(new THREE.PlaneGeometry(w + 3., 7.), roadMat);
    roadGlow.rotation.x = -Math.PI / 2; roadGlow.position.set(x + (key === 'pink' ? 2. : 0), .009, z + 2.8); scene.add(roadGlow);
    n.spills = [spillMat, roadMat];
    return g;
  };
  const pk = new THREE.PointLight(0xff3fa4, 210, 16, 2); addLight('pink', pk, .55, 2); L.pink.mats = [];
  const op = new THREE.PointLight(0xff2a50, 105, 12, 2); addLight('open', op, .9, 5);
  const cy = new THREE.PointLight(0x3ef0e6, 110, 12, 2); addLight('cyan', cy, 1.25, 7);
  const lg = null; L.lounge = { t0: 1.0 };
  const blade = neon('neon_shanghai', 1.1, 4.4, -6.9, 7.1, -2.55, 0, new Color(1, 1, 1), 2.6, pk, [-6.2, 6.4, -1.2], 'pink');
  const bracket = new Merge(tin); bracket.box(1.4, .08, .08, -7.6, 9.4, -2.55).box(1.4, .08, .08, -7.6, 4.9, -2.55).box(.08, 4.7, .08, -6.35, 7.1, -2.58);
  bracket.mesh(scene);
  neon('neon_open', 1.9, .95, 3.0, 4.4, -8.82, 0, new Color(1, 1, 1), 2.4, op, [3.2, 3.6, -7.6], 'open');
  neon('neon_gift', 3.2, .8, 12.5, 4.7, -8.78, 0, new Color(1, 1, 1), 2.2, cy, [12.5, 4.1, -7.5], 'cyan');
  neon('neon_lounge', 1.8, .9, -4.6, 4.4, -8.82, 0, new Color(1, 1, 1), 2.4, lg, [-4.4, 3.7, -7.5], 'lounge');
  neon('neon_open24', 1.8, .45, 20.5, 3.6, -8.8, 0, new Color(1, 1, 1), 2.0, null, null, 'o24');
  // alley: a far red lamp and its light
  const redLamp = new THREE.Mesh(new THREE.SphereGeometry(.22, 8, 6), new THREE.MeshBasicMaterial({ color: new Color(1, .2, .1).multiplyScalar(5), fog: false })); redLamp.position.set(7, 3.4, -25.6); scene.add(redLamp); L.alleyLamp = { mat: redLamp.material };
  const al = new THREE.PointLight(0xff3a1a, 90, 16, 2); al.position.set(7, 3.1, -23.5); addLight('alley', al, 1.4, 11);
  const gl = new THREE.PointLight(0xffa850, 90, 12, 2); gl.position.set(2.65, 1.6, -7.8); addLight('garage', gl, 1.15, 13);

  // --- utility pole on the right, lamp post, wires
  const pole = new Merge(new THREE.MeshStandardMaterial({ color: 0x2a2018, roughness: .9 }));
  pole.cyl(.17, 11, 13.5, 5.5, -4.5, 8).box(.14, .14, 4.2, 13.5, 10.3, -4.5, 0).box(.12, .12, 3.4, 13.5, 9.2, -4.5);
  pole.box(.5, .8, .5, 13.9, 7.6, -4.2).cyl(.25, .9, 14.15, 7.5, -4.8, 10);
  pole.mesh(scene);
  const post = new Merge(new THREE.MeshStandardMaterial({ color: 0x23272d, metalness: .8, roughness: .4 }));
  post.cyl(.11, 7.4, 4.3, 3.7, -7.1, 10).box(.5, .5, .5, 4.3, .4, -7.1).box(.12, .12, 1.9, 4.3, 7.35, -6.2, 0).box(.09, .09, 1.7, 4.3, 7.2, -6.4, 0, 0, 0);
  post.box(.45, .16, .7, 4.3, 7.38, -5.1).box(.3, .1, .45, 4.3, 7.5, -5.1);
  post.mesh(scene);
  lampPos.set(4.3, 7.2, -5.15);
  const lampBulb = new THREE.Mesh(new THREE.BoxGeometry(.4, .06, .6), new THREE.MeshBasicMaterial({ color: new Color(1, .7, .35).multiplyScalar(5), toneMapped: false })); lampBulb.position.set(4.3, 7.3, -5.1); scene.add(lampBulb); L.lampBulb = { mat: lampBulb.material };
  // Low broken fixture in the visible gap between the menu and the car.
  // Its own dim pool preserves the original overhead lamp's scene lighting.
  const brokenPost = new Merge(new THREE.MeshStandardMaterial({ color: 0x23272d, metalness: .8, roughness: .4 }));
  brokenPost.cyl(.065, 3.55, -2.9, 1.775, .05, 8).box(.26, .12, .26, -2.9, .06, .05);
  brokenPost.box(.7, .075, .09, -2.58, 3.54, .05, 0, 0, -.12);
  brokenPost.box(.52, .16, .33, -2.22, 3.45, .05, 0, .14, -.48);
  brokenPost.mesh(scene);
  const brokenBulb = new THREE.Mesh(new THREE.BoxGeometry(.41, .045, .25), new THREE.MeshBasicMaterial({ color: new Color(1, .48, .12).multiplyScalar(3), toneMapped: false }));
  brokenBulb.position.set(-2.21, 3.37, .05); brokenBulb.rotation.set(.14, 0, -.48); scene.add(brokenBulb);
  const brokenLight = new THREE.PointLight(0xffa34b, 7, 5, 2); brokenLight.position.set(-2.21, 3.32, .05); scene.add(brokenLight);
  L.faultBulb = { mat: brokenBulb.material, light: brokenLight, base: 7, t0: .1, seed: 19 };
  const wires = [];
  const pt = (x, y, z) => new V3(x, y, z);
  for (const o of [-.12, 0, .12, .24]) {
    wire(pt(-7.4, 9.8 + o, -2 + o), pt(4.3, 7.0 + o, -7.1), .8, wires); wire(pt(4.3, 7.0 + o, -7.1), pt(13.5, 10.3 + o * .3, -4.5 + o), 1.1, wires);
    wire(pt(-7.4, 9.9 + o, 1 + o), pt(13.5, 9.2 + o * .3, -4.5 + o), 1.7, wires);
  }
  wire(pt(4.3, 7.0, -7.1), pt(2.2, 6.3, -8.7), .3, wires); wire(pt(13.5, 8.6, -4.5), pt(10.5, 7.3, -8.7), .5, wires); wire(pt(-7.5, 11.5, -4), pt(0.6, 9.5, -8.6), .6, wires);
  wire(pt(13.5, 10.3, -2.3), pt(24, 8.5, -8.7), 1.2, wires); wire(pt(-7.4, 11.5, 6), pt(-7.4, 12.2, 15), .6, wires);
  const wm = new THREE.Mesh(mergeGeometries(wires), new THREE.MeshBasicMaterial({ color: 0x07090c })); scene.add(wm);

  // --- road bits: manhole, drain, a traffic barrier
  const mh = new THREE.Mesh(new THREE.CircleGeometry(.5, 16), new THREE.MeshStandardMaterial({ color: 0x1c1c1e, metalness: .9, roughness: .45 })); mh.rotation.x = -Math.PI / 2; mh.position.set(3.4, .007, -1.8); scene.add(mh);
  const barrier = new Merge(new THREE.MeshStandardMaterial({ color: 0xc8c8c0, roughness: .8 }));
  barrier.box(2.4, .9, .5, 9.5, .45, -4.5, .2).box(2.4, .9, .5, 12.2, .45, -3.2, .5);
  barrier.mesh(scene);
  const stripe = new THREE.Mesh(new THREE.BoxGeometry(2.42, .2, .52), new THREE.MeshBasicMaterial({ color: new Color(1, .25, .1).multiplyScalar(1.4) })); stripe.position.set(9.5, .75, -4.5); stripe.rotation.y = .2; scene.add(stripe);
  const stripe2 = stripe.clone(); stripe2.position.set(12.2, .75, -3.2); stripe2.rotation.y = .5; scene.add(stripe2);

  // steam from the manhole
  const st = softTex(.8); for (let i = 0; i < 9; i++) { const s = new THREE.Sprite(new THREE.SpriteMaterial({ map: st, color: new Color(.5, .55, .68), transparent: true, depthWrite: false, opacity: 0, blending: THREE.AdditiveBlending })); s.userData = { ph: i / 9, sd: hash(i) }; scene.add(s); steam.push(s); }

  // lights that are not tied to a sign
  const hemi = new THREE.HemisphereLight(0x6a86c0, 0x2a1d14, 1.15); scene.add(hemi); L.hemi = { light: hemi, base: 1.15, t0: 0, seed: 0 };
  const lamp = new THREE.SpotLight(0xffb464, 2600, 30, .72, .6, 2); lamp.position.copy(lampPos); lamp.target.position.set(layoutPos.car.x + .3, 0, layoutPos.car.z + .4);
  lamp.castShadow = true; lamp.shadow.mapSize.set(1024, 1024); lamp.shadow.bias = -.0004; lamp.shadow.normalBias = .03; lamp.shadow.camera.near = 1; lamp.shadow.camera.far = 26;
  addLight('lamp', lamp, .1, 4, { flicker: .5 });
  // volumetric cone from the lamp
  const coneH = 7.3, coneR = 4.6;
  const coneGeo = new THREE.ConeGeometry(coneR, coneH, 28, 1, true); coneGeo.translate(0, -coneH / 2, 0);
  const cone = new THREE.Mesh(coneGeo, coneMaterial(new Color(1, .62, .28), .09)); cone.position.copy(lampPos); cone.position.y += -.05;
  const dirv = new V3().subVectors(lamp.target.position, lampPos).normalize(); cone.quaternion.setFromUnitVectors(new V3(0, -1, 0), dirv); cone.scale.set(1, 1.06, 1);
  cone.renderOrder = 6; scene.add(cone); cones.push({ mesh: cone, light: 'lamp', base: .09 });
  // Passing traffic on the avenue: one wide, unshadowed beam catches the clearcoat.
  const passing = new THREE.SpotLight(0xd9e8ff, 0, 44, .5, .85, 2);
  passing.position.set(-18, .9, 8.5); passing.target.position.set(0, 1.4, -7.8);
  addLight('passing', passing, 0, 0, { manual: true });

  // Rain owns its particles and injects lens refraction into the existing grading pass.
  rain = createRain({ scene, lampPos, grading: FINAL });
  L.lampFault = createLampSparks({ scene, position: new V3(-2.02, 3.32, .05), rain, atlasURL: base + 'fx/lamp_sparks.png' });
}

function coneMaterial(col, k) {
  return new THREE.ShaderMaterial({
    transparent: true, depthWrite: false, blending: THREE.AdditiveBlending, side: THREE.DoubleSide, forceSinglePass: true, fog: false,
    uniforms: { uCol: { value: col.clone() }, uK: { value: k }, uTime: { value: 0 } },
    vertexShader: 'varying vec3 vN, vP; varying vec2 vU; void main(){ vN = normalize(normalMatrix * normal); vec4 mv = modelViewMatrix * vec4(position, 1.); vP = mv.xyz; vU = uv; gl_Position = projectionMatrix * mv; }',
    fragmentShader: `varying vec3 vN, vP; varying vec2 vU; uniform vec3 uCol; uniform float uK, uTime;
      void main(){
        float facing = pow(abs(dot(normalize(vN), normalize(-vP))), 1.8);
        float taper = smoothstep(0., .22, vU.y) * (1. - smoothstep(.92, 1., vU.y));
        float falloff = .18 + .82 * vU.y * vU.y;
        // Sparse drifting density in the shaft, rather than a solid glowing cone.
        float mist = .82 + .10 * sin(vU.y * 38. + sin(vU.x * 31.) - uTime * .7)
                         + .08 * sin(vU.x * 57. + vU.y * 19. + uTime * .45);
        float a = facing * taper * falloff * mist * uK;
        gl_FragColor = vec4(uCol * a, 1.);
      }`,
  });
}

// ---------------------------------------------------------------- the car: SKYLINE exported from the game (web/launcher/v3/car.glb + car_meta.json)
const carPaint = () => new THREE.MeshPhysicalMaterial({ color: 0x0e3fa8, metalness: .38, roughness: .36, clearcoat: 1, clearcoatRoughness: .04, sheen: .25, sheenColor: new Color(.25, .4, 1), sheenRoughness: .5, envMapIntensity: .75 });
async function loadCar() {
  const [gltf, meta] = await Promise.all([new GLTFLoader().loadAsync(base + 'car.glb'), fetch(base + 'car_meta.json').then(r => r.json())]);
  const root = gltf.scene, paint = [], lamps = [];
  root.traverse(o => {
    if (!o.isMesh) return; o.castShadow = true; o.receiveShadow = false;
    const mats = Array.isArray(o.material) ? o.material : [o.material];
    mats.forEach((m, i) => {
      const n = (m.name || '').toUpperCase(); let r = m;
      if (n.startsWith('CARSKIN')) { r = carPaint(); paint.push(r); }
      else if (n.startsWith('WINDSHIELD') || n.startsWith('WINDOWMASK')) r = new THREE.MeshPhysicalMaterial({ color: 0x03060a, metalness: .9, roughness: .05, transparent: true, opacity: .86, clearcoat: 1, envMapIntensity: 1.6 });
      else if (n.startsWith('HEADLIGHTGLASS')) r = new THREE.MeshPhysicalMaterial({ color: 0xffffff, roughness: .05, transparent: true, opacity: .35, clearcoat: 1 });
      else if (n.startsWith('BRAKELIGHT')) { r = new THREE.MeshBasicMaterial({ color: new Color(1, .06, .04).multiplyScalar(1.6), toneMapped: false }); lamps.push(r); }
      else if (n.startsWith('HEADLIGHTREFLECTOR')) { r = new THREE.MeshBasicMaterial({ map: m.map, color: new Color(1, .93, .75).multiplyScalar(2.4), toneMapped: false }); lamps.push(r); }
      else if (/ALUMINUM|MAGGUNMETAL|BRAKEDISC/.test(n)) { m.metalness = 1; m.roughness = Math.min(m.roughness, .35); m.envMapIntensity = 1.4; }
      else if (/RUBBER/.test(n)) { m.roughness = .85; m.metalness = 0; }
      if (r !== m) { r.name = m.name; if (Array.isArray(o.material)) o.material[i] = r; else o.material = r; }
    });
  });
  const v = a => new V3(a[0], a[1], a[2]);
  return { root: (() => { const g = new THREE.Group(); g.add(root); return g; })(), headL: v(meta.headlights.L).add(new V3(0, 0, .12)), headR: v(meta.headlights.R).add(new V3(0, 0, .12)), tailL: v(meta.taillights.L), tailR: v(meta.taillights.R),
    dir: new V3(0, -.05, 1).normalize(), length: meta.bbox.max[2] - meta.bbox.min[2], width: meta.bbox.max[0] - meta.bbox.min[0], paint, lamps, wheels: [root.getObjectByName('wheel_FL'), root.getObjectByName('wheel_FR'), root.getObjectByName('wheel_RL'), root.getObjectByName('wheel_RR')].filter(Boolean) };
}
function placeCar(info) {
  car = info; const g = car.root; g.position.copy(layoutPos.car); g.rotation.y = -.5; scene.add(g);
  const sp = (name, p) => { const s = new THREE.SpotLight(0xfff0cc, 110, 26, .5, .55, 2); s.position.copy(p); s.target.position.copy(p).addScaledVector(car.dir, 6); g.add(s); g.add(s.target); L[name] = { light: s, base: 110, t0: 1.5, seed: 21, local: true }; return s; };
  sp('headL', car.headL); sp('headR', car.headR);
  L.headL.light.castShadow = true; L.headL.light.shadow.mapSize.set(512, 512); L.headL.light.shadow.bias = -.0005; L.headL.light.shadow.camera.near = .5; L.headL.light.shadow.camera.far = 18;
  // headlight beams (faint volumetric cones along the car's forward)
  for (const [n, p] of [['headL', car.headL], ['headR', car.headR]]) {
    const h = 6, geo = new THREE.ConeGeometry(1.5, h, 20, 1, true); geo.translate(0, -h / 2, 0); geo.rotateX(Math.PI / 2);   // apex at origin, axis +z
    const m = new THREE.Mesh(geo, coneMaterial(new Color(1, .95, .8), .07)); m.position.copy(p); g.add(m); m.renderOrder = 6; cones.push({ mesh: m, light: n, base: .07 });
  }
  L.tailL = { t0: 1.6 };               // tail lamps are emissive only (no light: the reflection pass lights every fragment per light)
  // underglow: a coloured light and an additive pool on the asphalt
  
  const pool = new THREE.Mesh(new THREE.PlaneGeometry(3.8, 6.2), new THREE.MeshBasicMaterial({ map: softTex(.7), color: new Color(.2, .45, 1), transparent: true, blending: THREE.AdditiveBlending, depthWrite: false, opacity: .55 }));
  pool.rotation.x = -Math.PI / 2; pool.position.y = .012; g.add(pool); L.pool = { mat: pool.material };
  const blob = new THREE.Mesh(new THREE.PlaneGeometry(2.6, 5.4), new THREE.MeshBasicMaterial({ map: softTex(1), color: 0x000000, transparent: true, opacity: .8, depthWrite: false, blending: THREE.NormalBlending }));
  blob.rotation.x = -Math.PI / 2; blob.position.y = .014; g.add(blob);
}

// ---------------------------------------------------------------- the menu light-boxes
function buildTotem(labels) {
  const g = new THREE.Group(); totem = { g, items: [], frames: [] }; scene.add(g);
  const PW = 2.9, PH = .66, PD = .2, GAP = .84, Y0 = 1.15;
  const metal = new THREE.MeshStandardMaterial({ color: 0x23272d, metalness: .85, roughness: .38 });
  const post = new Merge(metal);
  for (const sx of [-1, 1]) { post.box(.14, 4.5, .14, sx * 1.75, 2.25, -.2).box(.5, .08, .5, sx * 1.75, .04, -.2); post.box(.1, .1, .5, sx * 1.75, 3.7, -.05); }
  post.box(3.9, .12, .12, 0, 4.5, -.2).box(3.6, .06, .06, 0, 1.0, -.3).box(.07, 3.9, .07, -.75, 2.5, -.32).box(.07, 3.9, .07, .75, 2.5, -.32);
  post.mesh(g);
  const hood = new THREE.Mesh(new THREE.BoxGeometry(3.4, .12, .55), metal); hood.position.set(0, 4.7, .05); g.add(hood);
  // no plates: the label floats, a thin accent strip runs under it, the selected one gets a neon bar on its left edge
  const stripTex = stripTexture();
  const stripGeo = new THREE.PlaneGeometry(PW - .1, .034), barGeo = new THREE.PlaneGeometry(.07, PH - .08), pickGeo = new THREE.PlaneGeometry(PW + .1, PH + .14);
  const glow = (map, o = {}) => new THREE.MeshBasicMaterial({ map, transparent: true, blending: THREE.AdditiveBlending, depthWrite: false, toneMapped: false, ...o });
  labels.forEach((txt, i) => {
    const p = new THREE.Group(); p.position.set(0, Y0 + (labels.length - 1 - i) * GAP, 0); g.add(p);
    const pick = new THREE.Mesh(pickGeo, new THREE.MeshBasicMaterial({ transparent: true, opacity: 0, depthWrite: false, colorWrite: false })); pick.userData.idx = i; p.add(pick); totem.frames.push(pick);
    const label = new THREE.Mesh(new THREE.PlaneGeometry(PW, PW * 244 / 1024), glow(canvasTex(labelCanvas(txt, 1024, 244, .4, 120)), { color: new Color(1, 1, 1) }));
    label.position.z = .02; p.add(label); label.renderOrder = 5;
    const strip = new THREE.Mesh(stripGeo, glow(stripTex, { color: new Color(ACC[i % 4]).multiplyScalar(.2) }));
    strip.position.set(0, -PH / 2 + .1, .02); p.add(strip); strip.renderOrder = 5;
    const bar = new THREE.Mesh(barGeo, glow(null, { color: new Color(ACC[i % 4]), opacity: 0 }));
    bar.position.set(-PW / 2 - .02, 0, .02); p.add(bar); bar.renderOrder = 5;
    const chev = new THREE.Mesh(new THREE.PlaneGeometry(.3, .15), glow(tex('chev'), { opacity: 0, color: new Color(2, 2, 2) }));
    chev.position.set(-PW / 2 + .22, 0, .03); p.add(chev); chev.renderOrder = 5;
    totem.items.push({ p, label, chev, strip, bar, sel: 0, vel: 0, pr: 0, base: p.position.clone(), acc: new Color(ACC[i % 4]), lit: 0, t0: 1.9 + i * .16, seed: 40 + i });
  });
  const sel = new THREE.PointLight(0xff2a3c, 0, 9, 2); sel.position.set(0, 2.4, 1.6); g.add(sel); L.sel = { light: sel, base: 1, t0: 0, seed: 0, local: true, manual: true };
  // road lamp on top of the totem
  const lamp = new THREE.Mesh(new THREE.BoxGeometry(.5, .08, .3), new THREE.MeshBasicMaterial({ color: new Color(.7, .9, 1).multiplyScalar(3) })); lamp.position.set(0, 4.62, .1); g.add(lamp); totem.lamp = lamp;
  placeTotem();
}
function stripTexture() {                                      // thin line, bright at the left, fading to the right
  const c = document.createElement('canvas'); c.width = 256; c.height = 4; const x = c.getContext('2d');
  const gr = x.createLinearGradient(0, 0, 256, 0); gr.addColorStop(0, 'rgba(255,255,255,1)'); gr.addColorStop(.55, 'rgba(255,255,255,.55)'); gr.addColorStop(1, 'rgba(255,255,255,0)');
  x.fillStyle = gr; x.fillRect(0, 0, 256, 4); return canvasTex(c);
}
function placeTotem() { totem.g.position.copy(layoutPos.totem); totem.g.rotation.y = .5; }

// ---------------------------------------------------------------- post: bloom + one grading pass (DoF, aberration, grain, tone map)
const FINAL = {
  uniforms: { tDiffuse: { value: null }, tDepth: { value: null }, uRes: { value: new THREE.Vector2(1, 1) }, uTime: { value: 0 }, uFocus: { value: 9 }, uAper: { value: .55 }, uNear: { value: .1 }, uFar: { value: 250 }, uFade: { value: 0 }, uExp: { value: .95 }, uGrain: { value: .03 }, uCA: { value: 0 }, uFlash: { value: 0 } },
  vertexShader: 'varying vec2 vUv; void main(){ vUv = uv; gl_Position = vec4(position.xy, 0., 1.); }',
  fragmentShader: `uniform sampler2D tDiffuse, tDepth; uniform vec2 uRes; uniform float uTime, uFocus, uAper, uNear, uFar, uFade, uExp, uGrain, uCA, uFlash; varying vec2 vUv;
    float linD(float d){ float z = d * 2. - 1.; return 2. * uNear * uFar / (uFar + uNear - z * (uFar - uNear)); }
    vec3 aces(vec3 x){ return clamp((x * (2.51 * x + .03)) / (x * (2.43 * x + .59) + .14), 0., 1.); }
    float h(vec2 p){ p = fract(p * vec2(443.897, 441.423)); p += dot(p, p + 19.19); return fract(p.x * p.y); }
    const vec2 D[10] = vec2[10](vec2(.00,.00), vec2(.70,.00), vec2(-.35,.61), vec2(-.35,-.61), vec2(1.35,.35), vec2(.55,1.25), vec2(-.9,1.0), vec2(-1.3,-.4), vec2(-.2,-1.3), vec2(.95,-.95));
    void main(){
      vec2 uv = vUv, c = uv - .5; float r2 = dot(c, c);
      float d = linD(texture2D(tDepth, uv).x);
      float coc = clamp(abs(1. / d - 1. / uFocus) * uAper, 0., 1.) * .016;
      vec2 asp = vec2(uRes.y / uRes.x, 1.), ca = c * r2 * uCA * 6.;
      vec3 col = vec3(0.);
      if (coc < .0006){ col = vec3(texture2D(tDiffuse, uv + ca).r, texture2D(tDiffuse, uv).g, texture2D(tDiffuse, uv - ca).b); }
      else { for (int i = 0; i < 10; i++){ vec2 o = D[i] * coc * asp; col += vec3(texture2D(tDiffuse, uv + o + ca).r, texture2D(tDiffuse, uv + o).g, texture2D(tDiffuse, uv + o - ca).b); } col /= 10.; }
      col = col * uExp + uFlash * vec3(1., .85, .7);
      col = aces(col);
      col *= 1. - smoothstep(.25, .75, r2 * 1.6) * .55;                         // vignette
      float g = h(uv * uRes + floor(uTime * 24.) * 17.17) - .5; col += g * uGrain * (.4 + col * .8);
      col = mix(col, vec3(dot(col, vec3(.3, .59, .11))), .06) * vec3(.99, 1., 1.03);
      col *= 1. - uFade;
      gl_FragColor = vec4(pow(col, vec3(1. / 2.2)), 1.);
    }`,
};

function sizeAll() {
  const cw = Math.max(2, canvas.clientWidth || innerWidth), ch = Math.max(2, canvas.clientHeight || innerHeight);
  const dpr = devicePixelRatio || 1; pr = Math.min(dpr, 1.25, Math.max(.5, 1400 / cw));
  renderer.setPixelRatio(pr); renderer.setSize(cw, ch, false);
  W = Math.round(cw * pr); H = Math.round(ch * pr);
  composer.setSize(W, H); bloomPass.resolution.set(W / 2, H / 2); bloomPass.setSize(W, H);
  FINAL.uniforms.uRes.value.set(W, H);
  const rt = reflector.getRenderTarget(); rt.setSize(Math.round(W * .5), Math.round(H * .5));
  camera.aspect = cw / ch; layout(cw / ch); camera.updateProjectionMatrix();
}
// portrait screens: the totem and the car come closer to the middle and the lens opens up
function layout(aspect) {
  const p = clamp((1.25 - aspect) / .65, 0, 1);
  layoutPos.totem.set(lerp(-4.7, -.6, p), 0, lerp(1.3, 3.2, p)); layoutPos.car.set(lerp(1.2, .6, p), 0, lerp(-.5, -2.2, p));
  if (totem) placeTotem(); if (car) car.root.position.copy(layoutPos.car);
  L.lamp && L.lamp.light.target.position.set(layoutPos.car.x + .3, 0, layoutPos.car.z + .4);
  layout.p = p;
}
layout.p = 0;
const shotFor = name => {
  const s = { ...(SHOTS[name] || SHOTS.main) }, p = layout.p;
  if (p > 0) { s.fov = lerp(s.fov, 66, p); s.r = lerp(s.r, s.r + 3.4, p); s.sx = lerp(s.sx, 0, p); s.ty = lerp(s.ty, s.ty + (name === 'main' ? 0.3 : .6), p); s.tx = lerp(s.tx, name === 'main' ? -.3 : .6, p); if (name === 'presets') s.sy = lerp(s.sy, -.1, p); if (name === 'opts' || name === 'ctrl') s.sy = lerp(0, -.45, p); }
  return s;
};

// ---------------------------------------------------------------- frame
const tmpV = new V3(), tmpV2 = new V3(), tmpC = new Color();
const rc = new THREE.Raycaster();
function updateRig(dt) {
  const g = shotFor(screenName), k = 1 - Math.exp(-dt * (motion ? 2.6 : 8));
  // the selected light-box pulls the camera a little toward it (main screen only)
  let ax = 0, ay = 0, az = 0;
  if (screenName === 'main' && panels.length) { const it = totem.items[selIdx]; const f = (selIdx - (totem.items.length - 1) / 2); az = f * -.02; ay = -f * .09; ax = it ? .0 : 0; }
  for (const key of ['az', 'el', 'r', 'tx', 'ty', 'tz', 'fov', 'sx', 'sy']) rig[key] = lerp(rig[key], g[key] + (key === 'az' ? az : key === 'ty' ? ay : 0), k);
  const it = totem && totem.items[selIdx];
  let fd = 9.4; if (it && screenName === 'main') { it.p.getWorldPosition(tmpV); fd = lerp(9.6, tmpV.distanceTo(camera.position), .85); } else if (screenName !== 'main') fd = rig.r;
  rig.focus = lerp(rig.focus, fd, 1 - Math.exp(-dt * 4));
  const orb = motion ? Math.sin(tNow * .16) * .17 + Math.sin(tNow * .07 + 1) * .05 : 0, bob = motion ? Math.sin(tNow * .23) * .035 : 0;
  // intro dolly: starts low and far, settles in 2.6 s
  const ti = ease(clamp(tNow / 2.6, 0, 1)), intro = 1 - ti;
  ptr.sx = lerp(ptr.sx, motion ? ptr.x : 0, 1 - Math.exp(-dt * 3.5)); ptr.sy = lerp(ptr.sy, motion ? ptr.y : 0, 1 - Math.exp(-dt * 3.5));
  const A = rig.az + orb + intro * .3 - ptr.sx * .12, E = rig.el + bob + intro * -.05 - ptr.sy * .03, R = rig.r + intro * 5.5;
  const cx = rig.tx + Math.sin(A) * Math.cos(E) * R, cy = rig.ty + Math.sin(E) * R, cz = rig.tz + Math.cos(A) * Math.cos(E) * R;
  camera.position.set(cx, cy, cz); camera.lookAt(rig.tx - ptr.sx * .35, rig.ty + ptr.sy * -.2, rig.tz);
  camera.fov = rig.fov - (going ? going.u * 18 : 0);
  if (going) {                                           // confirm: the camera flies into the selected light-box
    const u = going.u = clamp((performance.now() - going.t0) / 850, 0, 1), e = ease(u);
    camera.position.lerpVectors(going.from, going.to, e); camera.lookAt(going.at); camera.fov = lerp(rig.fov, 26, e);
  }
  camera.updateProjectionMatrix(); camera.projectionMatrix.elements[8] = rig.sx * (going ? 1 - going.u : 1); camera.projectionMatrix.elements[9] = rig.sy * (going ? 1 - going.u : 1);
  camera.projectionMatrixInverse.copy(camera.projectionMatrix).invert();
}
function updateLights(dt) {
  const t = tNow, calm = motion ? 1 : .25;
  for (const k in L) {
    const l = L[k]; if (!l.light) continue;
    const m = strike(t - l.t0) * (l.flicker ? lerp(1, flick(t, l.seed, 1), l.flicker * calm) : 1);
    l.mult = m; if (!l.manual) l.light.intensity = l.base * m * (going && /head/.test(k) ? 2.5 : 1);
  }
  if (L.lampFault) {
    const fault = L.lampFault.update(dt, motion, introDone);
    L.faultBulb.light.intensity = L.faultBulb.base * fault;
    L.faultBulb.mat.color.setRGB(1, .48, .12).multiplyScalar(3 * fault);
  }
  for (const n of neons) {
    const owner = L[n.key];
    // A tired tube briefly loses its ballast once per 23 seconds; spill follows the tube.
    const phase = (t + n.seed * 1.7) % 23;
    const dropout = motion && n.key === 'pink' ? 1. - .78 * sm(17., 17.07, phase) * (1. - sm(17.28, 17.65, phase)) : 1;
    const m = (owner ? strike(t - owner.t0) : strike(t - 1.6)) * (motion ? flick(t, n.seed, 1) : 1) * dropout; n.mult = m;
    n.mat.color.copy(n.col).multiplyScalar(n.base * m); if (n.light) n.light.intensity = (L[n.key] ? L[n.key].base : 80) * m;
    n.spills[0].opacity = .26 * m; n.spills[1].opacity = .17 * m;
  }
  if (L.passing) {
    const phase = (t + 10) % 29, u = clamp(phase / 7., 0, 1);
    const envelope = motion ? sm(0., 1.2, phase) * (1. - sm(5.2, 7., phase)) : 0;
    const pass = L.passing.light;
    pass.intensity = 640 * envelope;
    pass.position.set(lerp(-17, 19, u), 1.05, 8.5);
    pass.target.position.set(lerp(-4., 8., u), 1.25, -8.7);
    L.passing.mult = envelope;
  }
  if (L.garageGlow) { const m = strike(t - 1.15); L.garageGlow.mat.uniforms.uI.value = m; L.spill.mat.opacity = .5 * m; }
  if (L.alleyLamp) L.alleyLamp.mat.color.setRGB(1, .2, .1).multiplyScalar(5 * strike(t - 1.4) * flick(t, 11, calm));
  if (L.lampBulb) L.lampBulb.mat.color.setRGB(1, .7, .35).multiplyScalar(5 * L.lamp.mult);
  L.tailL.mult = strike(t - 1.6);
  if (car) for (const m of car.lamps) { if (!m.userData.b) m.userData.b = m.color.clone(); m.color.copy(m.userData.b).multiplyScalar(m.map ? (L.headL.mult || 0) : (L.tailL.mult || 0) * (.8 + .2 * Math.sin(t * 2))); }
  if (L.pool) L.pool.mat.opacity = .5 * strike(t - 1.7) * (.85 + .15 * Math.sin(t * 1.3));
  for (const c of cones) { const m = L[c.light] ? L[c.light].mult || 0 : 1; c.mesh.material.uniforms.uK.value = c.base * m * (going && /head/.test(c.light) ? 2.2 : 1); c.mesh.material.uniforms.uTime.value = t; }
  // menu light-boxes: spring to selected / hovered, light up one after the other
  let nl = 0; const col = tmpC.set(0, 0, 0);
  totem.hide = lerp(totem.hide || 0, screenName === 'main' ? 0 : 1, 1 - Math.exp(-dt * 6)); totem.g.position.x = layoutPos.totem.x - 3.6 * totem.hide; totem.g.rotation.y = .5 - .6 * totem.hide;
  totem.items.forEach((it, i) => {
    const on = strike(t - it.t0) * (1 - .85 * totem.hide), tgt = (i === selIdx && screenName === 'main') ? 1 : 0;
    const K = motion ? 210 : 600, D = motion ? 15 : 50; it.vel += (K * (tgt - it.sel) - D * it.vel) * dt; it.sel += it.vel * dt;
    const s = it.sel, sc = clamp(s, 0, 1.15); it.lit = on;
    it.pr = lerp(it.pr, going && i === selIdx ? 1 : 0, 1 - Math.exp(-dt * 30));
    it.p.position.z = it.base.z + .3 * s; it.p.position.x = it.base.x + .24 * s - .05 * it.pr; it.p.rotation.y = -.04 * s; it.p.scale.setScalar(1 + .035 * s - .03 * it.pr);
    const hot = clamp(s, 0, 1.1), fl = i === selIdx ? flick(t, it.seed, .6 * (motion ? 1 : .2)) : 1;
    it.label.material.color.setRGB(.62, .78, .9).lerp(tmpC.setRGB(1, 1, 1), hot).multiplyScalar((.45 + 1.1 * hot + .5 * it.pr) * on * fl);
    it.bar.material.opacity = clamp(s, 0, 1) * on; it.bar.material.color.copy(it.acc).multiplyScalar((1.6 + 1.4 * it.pr) * fl);
    it.chev.material.opacity = clamp(s, 0, 1) * on * (.5 + .5 * Math.abs(Math.sin(t * 5 - i)));
    it.strip.scale.y = 1 + 1.2 * hot + 1.5 * it.pr; it.strip.material.color.setRGB(.55, .58, .62).lerp(it.acc, clamp(hot * 1.4, 0, 1)).multiplyScalar((.22 + 2.6 * hot + 1.5 * it.pr) * on * fl);   // accent color only on the active item (OWNER 2026-11-07)
    if (s > .02 && tgt) { col.r += it.acc.r * s; col.g += it.acc.g * s; col.b += it.acc.b * s; nl = s; }
  });
  if (L.sel) { const sel = L.sel.light; sel.color.copy(L.sel.col || (L.sel.col = new Color(1, 1, 1))).setRGB(col.r, col.g, col.b); const it = totem.items[selIdx]; if (it) { it.p.getWorldPosition(tmpV); totem.g.worldToLocal(tmpV); sel.position.set(tmpV.x, tmpV.y, tmpV.z + 1.4); } sel.intensity = lerp(sel.intensity, 9 * nl * (L.sel.mult = 1), 1 - Math.exp(-dt * 14)); }
  if (totem.lamp) totem.lamp.material.color.setRGB(.7, .9, 1).multiplyScalar(3 * strike(t - 1.9));
  // steam
  for (const s of steam) {
    const u = (t * .09 + s.userData.ph) % 1, sd = s.userData.sd;
    s.position.set(3.4 + (sd - .5) * .6 + u * .9, .15 + u * 3.2, -1.8 + (hash(sd * 9) - .5) * .5); const sz = .8 + u * 2.6; s.scale.set(sz, sz, 1); s.material.opacity = Math.sin(u * Math.PI) * .09 * (.4 + .6 * L.lamp.mult);
  }
}
function pickAt(x, y) {                                         // client px -> panel index or -1
  if (!totem || screenName !== 'main' || going) return -1;
  const r = canvas.getBoundingClientRect(); rc.setFromCamera(new THREE.Vector2(((x - r.left) / r.width) * 2 - 1, -(((y - r.top) / r.height) * 2 - 1)), camera);
  const hit = rc.intersectObjects(totem.frames, false)[0]; return hit ? hit.object.userData.idx : -1;
}

let glq = null, glExt = null, frameNo = 0;
function frame(now) {
  if (!running) return;
  requestAnimationFrame(frame);
  if (document.hidden) { lastT = now; return; }
  const dt = Math.min((now - lastT) / 1000 || .016, .05); lastT = now; tNow += dt;
  updateRig(dt); updateLights(dt);
  if ((frameNo++ & 7) === 0) renderer.shadowMap.needsUpdate = true;          // the lamp and the headlights light a still scene: 1 shadow pass in 8 frames is enough
  const t = tNow, u = reflector.userData.uTime; u.value = t;
  rain.userData.update(t, motion, car, L, finalPass.uniforms);
  sky.material.uniforms.uT.value = t;
  FINAL.uniforms.uTime.value = t; finalPass.uniforms.uFocus.value = rig.focus; finalPass.uniforms.uFade.value = going && going.fade ? going.fade : 0;
  finalPass.uniforms.uFlash.value = going ? Math.max(0, 1 - Math.abs(going.u - .78) * 7) * .9 : 0;
  if (!introDone && tNow > 2.9) { introDone = true; if (introCb) introCb(); }
  if (PERF && glExt) { const q = renderer.getContext().createQuery(); renderer.getContext().beginQuery(glExt.TIME_ELAPSED_EXT, q); composer.render(dt); renderer.getContext().endQuery(glExt.TIME_ELAPSED_EXT); (glq = glq || []).push(q); pollQueries(); }
  else composer.render(dt);
  if (PERF) perfSamples.push(dt * 1000);
}
function pollQueries() {
  const gl = renderer.getContext();
  while (glq.length) {
    const q = glq[0]; if (!gl.getQueryParameter(q, gl.QUERY_RESULT_AVAILABLE)) break;
    const disjoint = gl.getParameter(glExt.GPU_DISJOINT_EXT); const ns = gl.getQueryParameter(q, gl.QUERY_RESULT); gl.deleteQuery(q); glq.shift();
    if (!disjoint && tNow > 3.2) (glTimer = glTimer || []).push(ns / 1e6);
  }
}

// ---------------------------------------------------------------- public API
const API = {
  async start(cv, opts = {}) {
    canvas = cv; base = opts.base || base;
    renderer = new THREE.WebGLRenderer({ canvas, antialias: false, alpha: false, stencil: false, powerPreference: 'high-performance' });
    if (!renderer.capabilities.isWebGL2) throw new Error('WebGL2 missing');
    renderer.toneMapping = THREE.NoToneMapping; renderer.shadowMap.enabled = true; renderer.shadowMap.type = THREE.PCFSoftShadowMap; renderer.shadowMap.autoUpdate = false; renderer.setClearColor(0x05080d, 1);
    canvas.addEventListener('webglcontextlost', e => { e.preventDefault(); running = false; document.documentElement.classList.add('static'); document.documentElement.classList.remove('w3d'); });
    scene = new THREE.Scene(); camera = new THREE.PerspectiveCamera(36, 16 / 9, .1, 250);
    await Promise.all([loadAssets(), loadFont()]);
    const labels = [...document.querySelectorAll('#menu .item .t')].map(e => e._text || e.textContent);
    buildWorld();
    placeCar(await loadCar());
    buildTotem(labels.length ? labels : ['Jugar', 'Perfiles', 'Opciones', 'Controles']);
    panels.push(...totem.items);
    layout(innerWidth / innerHeight);
    // composer: scene in HDR with MSAA and a depth texture, bloom at half size, then the grading pass to the screen
    const depth = new THREE.DepthTexture(2, 2); depth.type = THREE.UnsignedIntType;
    const rt = new THREE.WebGLRenderTarget(2, 2, { type: THREE.HalfFloatType, samples: 0, depthTexture: depth });
    composer = new EffectComposer(renderer, rt);
    composer.addPass(new RenderPass(scene, camera));
    bloomPass = new UnrealBloomPass(new THREE.Vector2(2, 2), .5, .6, .9); composer.addPass(bloomPass);
    finalPass = new ShaderPass(FINAL); FINAL.uniforms = finalPass.uniforms; finalPass.uniforms.tDepth.value = depth; finalPass.uniforms.uNear.value = camera.near; finalPass.uniforms.uFar.value = camera.far; composer.addPass(finalPass);
    sizeAll(); addEventListener('resize', sizeAll);
    Object.assign(rig, shotFor('main')); rig.focus = 9.4;
    // environment reflections for the car paint: the finished scene seen from the car, with every light on
    for (const k in L) if (L[k].light && !L[k].manual) L[k].light.intensity = L[k].base;
    neons.forEach(n => n.mat.color.copy(n.col).multiplyScalar(n.base));
    car.root.visible = false; reflector.visible = false; rain.visible = false; cones.forEach(c => c.mesh.visible = false);
    const pm = new THREE.PMREMGenerator(renderer); const env = (() => { const rt2 = new THREE.WebGLCubeRenderTarget(128, { type: THREE.HalfFloatType }); const cc = new THREE.CubeCamera(.1, 200, rt2); cc.position.set(layoutPos.car.x, 1.1, layoutPos.car.z); scene.add(cc); cc.update(renderer, scene); const out = pm.fromCubemap(rt2.texture); scene.remove(cc); rt2.dispose(); return out; })();
    for (const p of car.paint || []) { p.envMap = env.texture; p.needsUpdate = true; }
    car.root.traverse(o => { if (o.isMesh && o.material && o.material.isMeshPhysicalMaterial && !o.material.envMap) o.material.envMap = env.texture; });
    pm.dispose(); car.root.visible = true; reflector.visible = true; rain.visible = true; cones.forEach(c => c.mesh.visible = true);
    for (const k in L) if (L[k].light && !L[k].manual) L[k].light.intensity = 0;
    if (PERF) { glExt = renderer.getContext().getExtension('EXT_disjoint_timer_query_webgl2'); }
    running = true; lastT = performance.now(); tNow = 0;
    updateRig(.016); updateLights(.016); composer.render(.016);
    requestAnimationFrame(frame);
    started = true;
  },
  onIntroDone(cb) { if (introDone) cb(); else introCb = cb; },
  select(i, n, scr) { if (scr && scr !== 'main') return; selIdx = clamp(i, 0, (totem ? totem.items.length : n || 1) - 1); },
  screen(name) { screenName = name; },
  motion(on) { motion = !!on; },
  pointer(x, y) { ptr.x = x; ptr.y = y; },
  screenPos(i) {
    if (!totem) return null; const it = totem.items[clamp(i | 0, 0, totem.items.length - 1)]; it.p.getWorldPosition(tmpV2); tmpV2.project(camera);
    const r = canvas.getBoundingClientRect(); return { x: r.left + (tmpV2.x * .5 + .5) * r.width, y: r.top + (-tmpV2.y * .5 + .5) * r.height };
  },
  confirm() {
    if (!totem || going) return Promise.resolve();
    const it = totem.items[selIdx]; it.p.getWorldPosition(tmpV); const n = new V3(0, 0, 1).applyQuaternion(it.p.getWorldQuaternion(new THREE.Quaternion()));
    going = { t0: performance.now(), u: 0, from: camera.position.clone(), to: tmpV.clone().addScaledVector(n, .75), at: tmpV.clone(), fade: 0 };
    return new Promise(r => setTimeout(() => { if (going) going.fade = 0; r(); }, 880));
  },
  resume() { going = null; },
  hit: pickAt,
  stats() {
    const q = a => { const s = [...a].sort((x, y) => x - y); return { n: s.length, p50: s[Math.floor(s.length * .5)], p95: s[Math.floor(s.length * .95)], max: s[s.length - 1] }; };
    return { gpu: glTimer && glTimer.length ? q(glTimer) : null, frame: perfSamples.length ? q(perfSamples.slice(60)) : null, timerExt: !!glExt, size: [W, H], pr, calls: renderer.info.render.calls, tris: renderer.info.render.triangles };
  },
};
window.RN_SCENE = API;

// pointer on the 3D menu: hover selects, a tap or click accepts
addEventListener('pointermove', e => {
  if (!started || e.pointerType === 'touch' || e.target !== canvas || !window.RN_UI) return;
  const i = pickAt(e.clientX, e.clientY); canvas.style.cursor = i >= 0 ? 'pointer' : ''; if (i >= 0 && i !== hover) { hover = i; window.RN_UI.hover(i); } if (i < 0) hover = -1;
});
addEventListener('pointerdown', e => {
  if (!started || e.target !== canvas || !window.RN_UI) return;
  const i = pickAt(e.clientX, e.clientY); if (i >= 0) { e.preventDefault(); window.RN_UI.click(i); }
});
addEventListener('pageshow', e => { if (e.persisted) going = null; });
