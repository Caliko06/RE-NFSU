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
      vec2 grid = vec2(uRes.x / uRes.y, 1.) * 7.;
      vec2 st = uv * grid;
      vec2 id = floor(st), cell = fract(st) - .5;
      float seed = h(id + 73.1);
      float cycle = uRainTime * (.06 + seed * .055) + seed * 13.;
      float age = fract(cycle);
      float alive = step(.73, h(id + floor(cycle) * 17.7));
      float envelope = smoothstep(0., .12, age) * (1. - smoothstep(.8, 1., age));
      float x = (h(id + 9.2) - .5) * .65 + sin(age * 9. + seed * 30.) * .025;
      float y = .38 - .78 * age * age;
      vec2 p = (cell - vec2(x, y)) / vec2(.09, .12);
      float bead = exp(-dot(p, p) * 2.8);
      // A thin, broken trail above the moving bead; never a full-screen water sheet.
      float trailX = (cell.x - x) / .018;
      float trail = exp(-trailX * trailX) *
        smoothstep(y, y + .06, cell.y) * (1. - smoothstep(y + .08, y + .4, cell.y));
      trail *= .45 + .55 * sin(cell.y * 110. + seed * 20.);
      vec2 normal = p * bead * .045 + vec2((cell.x - x) * trail * .16, 0.);
      float edge = smoothstep(.12, .35, length((uv - .5) * vec2(uRes.x / uRes.y, 1.)));
      return normal / grid * alive * envelope * (.3 + .7 * edge);
    }
    void main(){`);
  grading.fragmentShader = grading.fragmentShader.replace(
    'vec2 uv = vUv, c = uv - .5; float r2 = dot(c, c);',
    'vec2 uv = clamp(vUv + lensRain(vUv), vec2(.002), vec2(.998)), c = vUv - .5; float r2 = dot(c, c);');
}

export function createRain({ scene, lampPos, grading }) {
  const group = new THREE.Group();
  const clock = { value: 0 };
  const uniforms = {
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
    varying float vAlpha, vNear;
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
      float width = mix(.009, .055, vNear);
      float exposure = mix(.32, .74, vNear) * (.75 + .5 * aSeed.w);
      vec3 vertex = p + right * position.x * width + direction * position.y * exposure;
      vColor = rainLight(p);
      vAlpha = smoothstep(.7, 2.5, distanceToEye) * (1. - smoothstep(22., 36., distanceToEye));
      vAlpha *= smoothstep(0., .3, p.y) * (.45 + aSeed.w * .55);
      vUv = uv;
      gl_Position = projectionMatrix * viewMatrix * vec4(vertex, 1.);
    }`, `
    varying vec2 vUv;
    varying vec3 vColor;
    varying float vAlpha, vNear;
    void main() {
      float x = abs(vUv.x - .5) * 2.;
      float core = exp(-x * x * mix(9., 3., vNear));
      float ends = smoothstep(0., .17, vUv.y) * (1. - smoothstep(.65, 1., vUv.y));
      float a = core * ends * vAlpha * mix(.65, .35, vNear);
      gl_FragColor = vec4(vColor * 1.8, a);
    }`));
  streaks.frustumCulled = false;
  streaks.renderOrder = 7;
  group.add(streaks);

  // Three ballistic droplets per impact; shared seeds keep each crown in sync on the GPU.
  const splashCount = 720, splashGeo = geometry(splashCount * 3);
  const seeds = splashGeo.getAttribute('aSeed');
  const hits = new Float32Array(splashCount * 9);
  const lobes = new Float32Array(splashCount * 3);
  for (let i = 0; i < splashCount; i++) {
    for (let j = 0; j < 3; j++) {
      const k = i * 3 + j;
      if (j) seeds.array.copyWithin(k * 4, i * 12, i * 12 + 4);
      lobes[k] = j;
      // First 160 crowns land on the body; the rest on the street.
      hits[k * 3 + 1] = i < 160 ? -100 : .025;
    }
  }
  splashGeo.setAttribute('aHit', new THREE.InstancedBufferAttribute(hits, 3));
  splashGeo.setAttribute('aLobe', new THREE.InstancedBufferAttribute(lobes, 1));
  const splashes = new THREE.Mesh(splashGeo, material(`
    attribute vec4 aSeed;
    attribute vec3 aHit;
    attribute float aLobe;
    uniform float uTime, uHasCar;
    uniform mat4 uCar;
    uniform vec2 uWind;
    varying vec2 vUv;
    varying vec3 vColor;
    varying float vAlpha;
    ${lighting}
    void main() {
      float onCar = step(.1, aHit.y);
      vec3 road = vec3((aSeed.x - .5) * 25. + 2., .025, (aSeed.z - .5) * 24.);
      vec3 impact = onCar > .5 ? (uCar * vec4(aHit, 1.)).xyz : road;
      float age = fract(uTime * (1.8 + aSeed.w) + aSeed.y);
      float life = .23 + .08 * aSeed.x;
      float seconds = age * life;
      float angle = aLobe * 2.0944 + aSeed.x * 31.;
      vec2 spread = vec2(cos(angle), sin(angle)) * (.5 + aSeed.z * .6);
      vec3 p = impact + vec3(spread.x * seconds, (1.15 + aSeed.z * .5) * seconds - 5. * seconds * seconds, spread.y * seconds);
      p.xz += uWind * seconds * .12;
      vec4 mv = viewMatrix * vec4(p, 1.);
      float size = mix(.018, .009, age);
      mv.xy += position.xy * vec2(size, size * (1.5 - age * .5));
      vec3 carPos = uCar[3].xyz;
      // No street impacts beneath the car's footprint (rotation about Y only).
      vec3 rel = road - carPos;
      vec2 local = vec2(dot(rel, uCar[0].xyz), dot(rel, uCar[2].xyz));
      float underCar = (1. - step(1., abs(local.x))) * (1. - step(2.35, abs(local.y))) * uHasCar;
      vAlpha = (1. - age) * smoothstep(0., .045, age) * (1. - step(p.y, impact.y - .005));
      vAlpha *= onCar > .5 ? uHasCar : (1. - underCar) * step(-1., aHit.y);
      vColor = rainLight(impact) * 2.8;
      vUv = uv;
      gl_Position = projectionMatrix * mv;
    }`, `
    varying vec2 vUv;
    varying vec3 vColor;
    varying float vAlpha;
    void main() {
      vec2 p = vUv * 2. - 1.;
      float a = exp(-dot(p, p) * 3.5) * vAlpha;
      gl_FragColor = vec4(vColor, a);
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
    rainTime += dt * (motion ? 1 : .4);
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
    for (let i = 0; i < 160; i++) {
      const k = i * 12;
      const x = (seeds.array[k] - .5) * 1.35;
      const z = i < 85 ? -.72 + seeds.array[k + 2] * .95 : 1.05 + seeds.array[k + 2] * .8;
      point.set(x, 3., z).applyMatrix4(car.root.matrixWorld);
      ray.set(point, down);
      const hit = ray.intersectObject(car.root, true).find(hit => hit.face && hit.face.normal.y > .55 && hit.object.isMesh);
      if (!hit) continue;
      point.copy(hit.point);
      car.root.worldToLocal(point);
      for (let j = 0; j < 3; j++) {
        const offset = (i * 3 + j) * 3;
        hits[offset] = point.x; hits[offset + 1] = point.y + .012; hits[offset + 2] = point.z;
      }
    }
    splashGeo.getAttribute('aHit').needsUpdate = true;
  };
  return group;
}
