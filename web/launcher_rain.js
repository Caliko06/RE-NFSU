import * as THREE from 'three';

// GPU billboards: https://threejs.org/examples/webgl_buffergeometry_instancing_billboards.html
// Lens approach: moving drops + trails + refraction, inspired by Heartfelt (original implementation below).
// Prior art: https://www.youtube.com/watch?v=uiF5Tlw22PI (The Art of Code).
const lightCount = 7;
const lighting = `
  uniform vec3 uLightPos[7], uLightColor[7];
  vec3 rainLight(vec3 p) {
    vec3 col = vec3(.035, .055, .085);
    for (int i = 0; i < 7; i++) {
      vec3 delta = p - uLightPos[i];
      col += uLightColor[i] / (1. + dot(delta, delta) * .42);
    }
    return col;
  }
`;

function geometry(count) {
  const quad = new THREE.PlaneGeometry(1, 1);
  const geo = new THREE.InstancedBufferGeometry();
  geo.index = quad.index;
  geo.setAttribute('position', quad.getAttribute('position'));
  geo.setAttribute('uv', quad.getAttribute('uv'));
  const seeds = new Float32Array(count * 4);
  for (let i = 0; i < seeds.length; i++) seeds[i] = Math.random();
  geo.setAttribute('aSeed', new THREE.InstancedBufferAttribute(seeds, 4));
  geo.instanceCount = count;
  return geo;
}

// Called before ShaderPass clones the uniforms. Reuses its existing scene samples for refraction.
function lens(grading, clock) {
  grading.uniforms.uRainTime = clock;
  grading.fragmentShader = grading.fragmentShader.replace('void main(){', `
    uniform float uRainTime;
    vec2 lensRain(vec2 uv) {
      vec2 grid = vec2(uRes.x / uRes.y, 1.) * 6.;
      vec2 st = uv * grid;
      vec2 id = floor(st), cell = fract(st) - .5;
      float seed = h(id + 73.1);
      float cycle = uRainTime * (.018 + seed * .014) + seed * 13.;
      float age = fract(cycle);
      float alive = step(.93, h(id + floor(cycle) * 17.7));
      float envelope = smoothstep(0., .12, age) * (1. - smoothstep(.8, 1., age));
      float x = (h(id + 9.2) - .5) * .65 + sin(age * 9. + seed * 30.) * .025;
      float y = .38 - .78 * age * age;
      vec2 p = (cell - vec2(x, y)) / vec2(.052, .072);
      float bead = exp(-dot(p, p) * 2.8);
      // A thin, broken trail above the moving bead; never a full-screen water sheet.
      float trailX = (cell.x - x) / .009;
      float trail = exp(-trailX * trailX) *
        smoothstep(y, y + .06, cell.y) * (1. - smoothstep(y + .06, y + .24, cell.y));
      trail *= .45 + .55 * sin(cell.y * 110. + seed * 20.);
      vec2 normal = p * bead * .028 + vec2((cell.x - x) * trail * .09, 0.);
      float edge = smoothstep(.12, .35, length((uv - .5) * vec2(uRes.x / uRes.y, 1.)));
      return normal / grid * alive * envelope * (.3 + .7 * edge) * smoothstep(.25, .4, uv.x);
    }
    void main(){`);
  grading.fragmentShader = grading.fragmentShader.replace(
    'vec2 uv = vUv, c = uv - .5; float r2 = dot(c, c);',
    'vec2 uv = clamp(vUv + lensRain(vUv), vec2(.002), vec2(.998)), c = vUv - .5; float r2 = dot(c, c);');
}

export function createRain({ scene, lampPos, grading }) {
  const group = new THREE.Group();
  const clock = { value: 0 };
  const loader = new THREE.TextureLoader();
  const sheet = name => {
    const texture = loader.load(new URL(`./launcher/v3/fx/${name}.png`, import.meta.url).href);
    texture.colorSpace = THREE.NoColorSpace; // Atlas RGB is a coverage mask; scene lights supply color.
    texture.minFilter = THREE.LinearMipmapLinearFilter;
    texture.magFilter = THREE.LinearFilter;
    return { value: texture };
  };
  const uniforms = {
    uCrowns: sheet('rain_crowns'), uStreaks: sheet('rain_streaks'),
    uTime: clock, uWind: { value: new THREE.Vector2(.8, .18) },
    uCar: { value: new THREE.Matrix4() }, uHasCar: { value: 0 },
    uLightPos: { value: Array.from({ length: lightCount }, () => lampPos.clone()) },
    uLightColor: { value: Array.from({ length: lightCount }, () => new THREE.Color(0, 0, 0)) },
  };
  lens(grading, clock);
  const material = (vertexShader, fragmentShader) => new THREE.ShaderMaterial({
    uniforms, vertexShader, fragmentShader, transparent: true, depthWrite: false,
    blending: THREE.AdditiveBlending, side: THREE.DoubleSide, fog: false,
  });
  const streaks = new THREE.Mesh(geometry(4200), material(`
    attribute vec4 aSeed;
    uniform float uTime;
    uniform vec2 uWind;
    varying vec2 vUv;
    varying vec3 vColor;
    varying float vAlpha, vNear, vVariant;
    ${lighting}
    void main() {
      float speed = 10. + aSeed.w * 6.;
      float fall = fract(aSeed.y - uTime * speed / 15.);
      vec3 p = vec3(2. + (aSeed.x - .5) * 34., fall * 15., (aSeed.z - .5) * 38.);
      p.xz -= uWind * (fall - .5) * 1.8;
      float distanceToEye = length(cameraPosition - p);
      vNear = 1. - smoothstep(3., 15., distanceToEye);
      vec3 direction = normalize(vec3(uWind.x * .12, -1., uWind.y * .12));
      vec3 right = normalize(cross(direction, normalize(cameraPosition - p)));
      // Tight atlas crops now fill these genuinely thin world-space quads.
      float width = mix(.012, .032, vNear);
      float exposure = mix(.32, .62, vNear) * (.75 + .5 * aSeed.w);
      vec3 vertex = p + right * position.x * width + direction * position.y * exposure;
      vColor = min(rainLight(p) * 1.8, vec3(1.2));
      vVariant = floor(aSeed.w * 3.999);
      vAlpha = smoothstep(.7, 2.5, distanceToEye) * (1. - smoothstep(22., 36., distanceToEye));
      vAlpha *= smoothstep(0., .3, p.y) * (.45 + aSeed.w * .55);
      vec4 clip = projectionMatrix * viewMatrix * vec4(p, 1.);
      float screenX = clip.x / max(clip.w, .001) * .5 + .5;
      // Thin density, rather than just dimming a curtain across the menu.
      float menu = 1. - smoothstep(.29, .40, screenX);
      vAlpha *= 1. - menu * step(aSeed.x, .83) * mix(.65, 1., vNear);
      vUv = uv;
      gl_Position = projectionMatrix * viewMatrix * vec4(vertex, 1.);
    }`, `
    varying vec2 vUv;
    varying vec3 vColor;
    varying float vAlpha, vNear, vVariant;
    uniform sampler2D uStreaks;
    void main() {
      vec2 tile = vec2(mod(vVariant, 2.), 1. - floor(vVariant / 2.));
      // Measured per-cell bounds: cores occupy only .8-4.5% of the source cell.
      float center = vVariant < .5 ? .503 : (vVariant < 1.5 ? .501 : (vVariant < 2.5 ? .504 : .498));
      float halfWidth = vVariant < .5 ? .022 : (vVariant < 1.5 ? .030 : (vVariant < 2.5 ? .023 : .013));
      float gain = vVariant < .5 ? 1. : (vVariant < 1.5 ? 1.05 : (vVariant < 2.5 ? 2.6 : 6.8));
      vec2 crop = vec2(center + (vUv.x * 2. - 1.) * halfWidth, mix(.025, .975, vUv.y));
      vec4 sprite = texture2D(uStreaks, (tile + crop) / 2.);
      float coverage = min(dot(sprite.rgb, vec3(.3333)) * sprite.a * gain, 1.);
      float softEdge = smoothstep(0., .14, vUv.x) * (1. - smoothstep(.86, 1., vUv.x));
      float a = coverage * softEdge * vAlpha * mix(.75, .60, vNear);
      gl_FragColor = vec4(vColor, a);
    }`));
  streaks.frustumCulled = false;
  streaks.renderOrder = 7;
  group.add(streaks);

  // One photographed crown per impact, not three independent bright points.
  const carSplashCount = 12, splashCount = 480, splashGeo = geometry(splashCount);
  const seeds = splashGeo.getAttribute('aSeed');
  const hits = new Float32Array(splashCount * 3);
  for (let i = 0; i < splashCount; i++) hits[i * 3 + 1] = i < carSplashCount ? -100 : .025;
  splashGeo.setAttribute('aHit', new THREE.InstancedBufferAttribute(hits, 3));
  const splashes = new THREE.Mesh(splashGeo, material(`
    attribute vec4 aSeed;
    attribute vec3 aHit;
    uniform float uTime, uHasCar;
    uniform mat4 uCar;
    varying vec2 vUv;
    varying vec3 vColor;
    varying float vAlpha, vFrame;
    ${lighting}
    void main() {
      float onCar = step(.1, aHit.y);
      // Concentrate visible road impacts around the car and the lamp footprint.
      vec2 center = mix(uCar[3].xz, uLightPos[0].xz, step(.6, aSeed.w)) * uHasCar;
      vec3 road = vec3((aSeed.x - .5) * 13. + center.x, .025, (aSeed.z - .5) * 13. + center.y);
      vec3 impact = onCar > .5 ? (uCar * vec4(aHit, 1.)).xyz : road;
      float cycle = fract(uTime * (.38 + aSeed.w * .18) + aSeed.y);
      // A .22-.28 second impact, followed by ~2 seconds without a sprite.
      float age = min(cycle / ((.22 + .06 * aSeed.x) * (.38 + aSeed.w * .18)), 1.);
      vFrame = min(floor(age * 16.), 15.);
      float size = (.15 + aSeed.z * .07) * mix(1., .42, onCar);
      vec4 mv = viewMatrix * vec4(impact, 1.);
      // Low-angle photographic ellipse is already baked into the sheet.
      mv.xy += (position.xy + vec2(0., .15)) * size;
      vec3 rel = road - uCar[3].xyz;
      vec2 local = vec2(dot(rel, uCar[0].xyz), dot(rel, uCar[2].xyz));
      float underCar = (1. - step(1., abs(local.x))) * (1. - step(2.35, abs(local.y))) * uHasCar;
      vAlpha = smoothstep(0., .06, age) * (1. - smoothstep(.55, 1., age));
      // Unsampled car slots remain off; never emit phantom street impacts.
      vAlpha *= onCar > .5 ? uHasCar * .07 : (1. - underCar) * step(-1., aHit.y) * .8;
      vColor = min(rainLight(impact) * 1.8, vec3(.95));
      vUv = uv;
      gl_Position = projectionMatrix * mv;
    }`, `
    uniform sampler2D uCrowns;
    varying vec2 vUv;
    varying vec3 vColor;
    varying float vAlpha, vFrame;
    void main() {
      vec2 tile = vec2(mod(vFrame, 4.), 3. - floor(vFrame / 4.));
      vec4 sprite = texture2D(uCrowns, (tile + clamp(vUv, .008, .992)) / 4.);
      // Keep water edges, suppress the broad gray fill in the photographed puddle.
      float edge = smoothstep(.22, .72, dot(sprite.rgb, vec3(.3333)));
      vec2 pad = smoothstep(vec2(0.), vec2(.10), vUv) * (1. - smoothstep(vec2(.9), vec2(1.), vUv));
      gl_FragColor = vec4(vColor, sprite.a * edge * pad.x * pad.y * vAlpha);
    }`));
  splashes.frustumCulled = false;
  splashes.renderOrder = 7;
  group.add(splashes);
  scene.add(group);

  let bodySampled = false, rainTime = 0, lastTime = 0;
  const down = new THREE.Vector3(0, -1, 0), point = new THREE.Vector3();
  const ray = new THREE.Raycaster();
  const keys = ['lamp', 'pink', 'cyan', 'open', 'lounge', 'headL', 'headR'];
  group.userData.update = (time, motion, car, lights, gradingUniforms) => {
    const dt = Math.max(0, Math.min(time - lastTime, .05));
    lastTime = time;
    rainTime += dt * (motion ? 1 : .12);
    clock.value = rainTime;
    gradingUniforms.uRainTime.value = rainTime;
    // Two slow gust scales prevent lockstep swaying and keep reduced motion gentle.
    const gust = motion ? Math.sin(time * .61) * .46 + Math.sin(time * 1.17 + 2.) * .19 : 0;
    uniforms.uWind.value.set(.85 + gust, .14 + gust * .24);
    for (let i = 0; i < keys.length; i++) {
      const entry = lights[keys[i]], color = uniforms.uLightColor.value[i];
      if (!entry?.light) { color.setRGB(0, 0, 0); continue; }
      entry.light.getWorldPosition(uniforms.uLightPos.value[i]);
      color.copy(entry.light.color).multiplyScalar((entry.mult || 0) * (i === 0 ? 2.5 : 1.7));
    }
    if (!car) return;
    car.root.updateMatrixWorld(true);
    uniforms.uCar.value.copy(car.root.matrixWorld);
    uniforms.uHasCar.value = 1;
    if (bodySampled) return;
    bodySampled = true;
    // Sample the shipped SKYLINE once, so roof/hood impacts follow its actual surface and layout.
    for (let i = 0; i < carSplashCount; i++) {
      const k = i * 4;
      const x = (seeds.array[k] - .5) * 1.35;
      const z = i < 8 ? -.72 + seeds.array[k + 2] * .95 : 1.05 + seeds.array[k + 2] * .8;
      point.set(x, 3., z).applyMatrix4(car.root.matrixWorld);
      ray.set(point, down);
      const hit = ray.intersectObject(car.root, true).find(hit => hit.face && hit.face.normal.y > .55 && hit.object.isMesh);
      if (!hit) continue;
      point.copy(hit.point);
      car.root.worldToLocal(point);
      const offset = i * 3;
      hits[offset] = point.x; hits[offset + 1] = point.y + .012; hits[offset + 2] = point.z;
    }
    splashGeo.getAttribute('aHit').needsUpdate = true;
  };
  return group;
}
