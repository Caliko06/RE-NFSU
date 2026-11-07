import * as THREE from 'three';

// Short exposure streaks, lit by the scene. No ambient curtain or impact sprites.
export function createRain({ scene, lampPos }) {
  const group = new THREE.Group();
  const quad = new THREE.PlaneGeometry(1, 1);
  const geo = new THREE.InstancedBufferGeometry();
  geo.index = quad.index;
  geo.setAttribute('position', quad.getAttribute('position'));
  geo.setAttribute('uv', quad.getAttribute('uv'));
  const count = 1500, seeds = new Float32Array(count * 4);
  for (let i = 0; i < seeds.length; i++) seeds[i] = Math.random();
  geo.setAttribute('aSeed', new THREE.InstancedBufferAttribute(seeds, 4));
  geo.instanceCount = count;
  const keys = ['lamp', 'pink', 'cyan', 'open', 'lounge', 'headL', 'headR'];
  const uniforms = {
    uTime: { value: 0 },
    uLightPos: { value: keys.map(() => lampPos.clone()) },
    uLightColor: { value: keys.map(() => new THREE.Color()) },
    uLightDir: { value: keys.map(() => new THREE.Vector3(0, -1, 0)) },
    uCone: { value: keys.map(() => -1) },
  };
  const mesh = new THREE.Mesh(geo, new THREE.ShaderMaterial({
    uniforms, transparent: true, depthWrite: false, fog: false,
    blending: THREE.AdditiveBlending, side: THREE.DoubleSide,
    vertexShader: `
      attribute vec4 aSeed;
      uniform float uTime, uCone[7];
      uniform vec3 uLightPos[7], uLightColor[7], uLightDir[7];
      varying vec2 vUv;
      varying vec3 vLight;
      varying float vAlpha;
      void main() {
        float fall = fract(aSeed.y - uTime * (.7 + aSeed.w * .35));
        vec3 p = vec3(2. + (aSeed.x - .5) * 30., fall * 14., (aSeed.z - .5) * 30.);
        p.x -= fall * .65;
        vLight = vec3(0.);
        for (int i = 0; i < 7; i++) {
          vec3 delta = p - uLightPos[i];
          float cone = uCone[i] < 0. ? 1. : smoothstep(uCone[i], min(1., uCone[i] + .12), dot(normalize(delta), uLightDir[i]));
          vLight += uLightColor[i] * cone / (1. + dot(delta, delta) * .7);
        }
        float lit = max(vLight.r, max(vLight.g, vLight.b));
        float distanceToEye = length(cameraPosition - p);
        vAlpha = smoothstep(.12, .55, lit) * smoothstep(2., 5., distanceToEye);
        vAlpha *= (1. - smoothstep(20., 29., distanceToEye)) * smoothstep(.1, .6, p.y);
        vec4 mv = viewMatrix * vec4(p, 1.);
        vec3 streak = mat3(viewMatrix) * vec3(.045, 1., 0.);
        vec2 direction = normalize(streak.xy), right = vec2(direction.y, -direction.x);
        mv.xy += right * position.x * .009 + direction * position.y * (.15 + aSeed.w * .17);
        vec4 clip = projectionMatrix * mv;
        float screenX = clip.x / max(clip.w, .001) * .5 + .5;
        // The menu now occupies right-center.
        float menu = smoothstep(.43, .62, screenX) * (1. - smoothstep(.88, .98, screenX));
        vAlpha *= 1. - menu * .9;
        vUv = uv;
        gl_Position = clip;
      }`,
    fragmentShader: `
      varying vec2 vUv;
      varying vec3 vLight;
      varying float vAlpha;
      void main() {
        float core = exp(-pow((vUv.x - .5) * 5., 2.));
        float ends = smoothstep(0., .18, vUv.y) * (1. - smoothstep(.7, 1., vUv.y));
        float alpha = core * ends * vAlpha * .46;
        if (alpha < .006) discard;
        gl_FragColor = vec4(min(vLight, vec3(1.8)), alpha);
      }`,
  }));
  mesh.frustumCulled = false;
  group.add(mesh);
  scene.add(group);
  let lastTime = 0;
  const target = new THREE.Vector3();
  group.userData.update = (time, motion, car, lights) => {
    const dt = Math.max(0, Math.min(time - lastTime, .05));
    lastTime = time;
    if (motion) uniforms.uTime.value += dt;
    for (let i = 0; i < keys.length; i++) {
      const entry = lights[keys[i]], color = uniforms.uLightColor.value[i];
      if (!entry?.light) { color.setRGB(0, 0, 0); continue; }
      const light = entry.light;
      light.getWorldPosition(uniforms.uLightPos.value[i]);
      color.copy(light.color).multiplyScalar((entry.mult || 0) * (i === 0 ? 3 : 2));
      uniforms.uCone.value[i] = light.isSpotLight ? Math.cos(light.angle) : -1;
      if (light.isSpotLight) {
        light.target.getWorldPosition(target);
        uniforms.uLightDir.value[i].subVectors(target, uniforms.uLightPos.value[i]).normalize();
      }
    }
  };
  return group;
}
