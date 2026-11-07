import * as THREE from 'three';

// Atlas billboards follow the official three.js instanced-particle pattern:
// https://threejs.org/examples/webgl_buffergeometry_instancing_billboards.html
// One small electrical fault, not a continuous particle emitter.
export function createLampSparks({ scene, position, rain, atlasURL }) {
  const count = 24, gravity = 9.81, road = .025;
  const quad = new THREE.PlaneGeometry(1, 1), geo = new THREE.InstancedBufferGeometry();
  geo.index = quad.index;
  geo.setAttribute('position', quad.attributes.position);
  geo.setAttribute('uv', quad.attributes.uv);
  const centers = new Float32Array(count * 3), shapes = new Float32Array(count * 4);
  geo.setAttribute('aCenter', new THREE.InstancedBufferAttribute(centers, 3));
  geo.setAttribute('aShape', new THREE.InstancedBufferAttribute(shapes, 4));
  geo.instanceCount = count;
  const atlas = new THREE.TextureLoader().load(atlasURL);
  atlas.colorSpace = THREE.SRGBColorSpace;
  const mat = new THREE.ShaderMaterial({
    transparent: true, depthWrite: false, blending: THREE.AdditiveBlending,
    uniforms: { uAtlas: { value: atlas } },
    vertexShader: `
      attribute vec3 aCenter;
      attribute vec4 aShape;
      varying vec2 vUv;
      varying float vAlpha;
      void main() {
        float cell = aShape.w;
        vUv = (uv + vec2(mod(cell, 4.), 3. - floor(cell / 4.))) / 4.;
        vAlpha = aShape.z;
        vec4 mv = modelViewMatrix * vec4(aCenter, 1.);
        mv.xy += position.xy * aShape.xy;
        gl_Position = projectionMatrix * mv;
      }`,
    fragmentShader: `
      uniform sampler2D uAtlas;
      varying vec2 vUv;
      varying float vAlpha;
      void main() {
        vec4 spark = texture2D(uAtlas, vUv);
        gl_FragColor = vec4(spark.rgb * 2.4, spark.a * vAlpha);
        #include <tonemapping_fragment>
        #include <colorspace_fragment>
      }`,
  });
  const mesh = new THREE.Mesh(geo, mat);
  mesh.frustumCulled = false;
  mesh.visible = false;
  mesh.renderOrder = 7;
  scene.add(mesh);
  const flash = new THREE.PointLight(0xffbf74, 0, 11, 2);
  flash.position.copy(position);
  scene.add(flash);

  // Rain uses custom lighting: extend its shared uniforms instead of adding
  // another rain layer or changing the rain module owned by another worker.
  const sparkPos = { value: position.clone() }, sparkColor = { value: new THREE.Color(0, 0, 0) };
  rain.traverse(object => {
    const material = object.material;
    if (!material?.uniforms?.uLightPos) return;
    material.uniforms.uSparkPos = sparkPos;
    material.uniforms.uSparkColor = sparkColor;
    material.vertexShader = 'uniform vec3 uSparkPos, uSparkColor;\n' + material.vertexShader.replace(
      'return col;', 'vec3 faultDelta = p - uSparkPos;\n col += uSparkColor / (1. + dot(faultDelta, faultDelta) * .7);\n return col;');
    material.needsUpdate = true;
  });

  let clock = 0, nextBurst = 4.8, burstStart = -100;
  const particles = Array.from({ length: count }, () => ({}));
  const random = (a, b) => a + Math.random() * (b - a);
  function burst() {
    burstStart = clock;
    nextBurst = clock + random(4, 9);
    for (const p of particles) {
      p.vx = random(-.85, .85); p.vz = random(-.65, .65); p.vy = random(-2.4, .5);
      p.delay = random(0, .12); p.size = random(.07, .14);
      p.cell = Math.floor(random(0, 8));
      p.hit = (p.vy + Math.sqrt(p.vy * p.vy + 2 * gravity * (position.y - road))) / gravity;
      p.rebound = (gravity * p.hit - p.vy) * random(.13, .2);
      p.life = p.hit + 2 * p.rebound / gravity;
    }
  }

  return {
    update(dt, enabled) {
      if (!enabled) {
        mesh.visible = false; flash.intensity = 0; sparkColor.value.setRGB(0, 0, 0);
        return 1;
      }
      clock += Math.min(Math.max(dt, 0), .05);
      if (clock >= nextBurst) burst();
      const age = clock - burstStart;
      mesh.visible = age >= 0 && age < 2;
      let impact = 0;
      if (mesh.visible) {
        for (let i = 0; i < count; i++) {
          const p = particles[i], t = age - p.delay, bounced = t > p.hit, b = Math.max(0, t - p.hit);
          const x = position.x + p.vx * (bounced ? p.hit + b * .42 : t);
          const z = position.z + p.vz * (bounced ? p.hit + b * .42 : t);
          const y = bounced ? road + p.rebound * b - gravity * b * b / 2 : position.y + p.vy * t - gravity * t * t / 2;
          centers.set([x, Math.max(road, y), z], i * 3);
          const alive = t >= 0 && t < p.life;
          const fade = alive ? (bounced ? .6 * Math.max(0, 1 - b / (p.life - p.hit)) : .95 - .32 * t / p.hit) : 0;
          shapes.set([p.size, p.size * (bounced ? 1 : 2.3), fade, bounced ? 8 + p.cell : p.cell], i * 4);
          if (bounced && alive) impact = Math.max(impact, Math.exp(-b * 24));
        }
        geo.attributes.aCenter.needsUpdate = true;
        geo.attributes.aShape.needsUpdate = true;
      }
      const arc = age < .16 ? Math.exp(-age * 26) * (.65 + .35 * Math.sin(age * 140) ** 2) : 0;
      flash.position.copy(position);
      if (impact > arc) flash.position.y = .24;
      flash.intensity = Math.max(arc * 85, impact * 9);
      sparkPos.value.copy(flash.position);
      sparkColor.value.setRGB(1, .52, .16).multiplyScalar(Math.max(arc * 5, impact * 1.6));
      // Off -> electrical buzz -> two short strikes -> stable. No global flashing.
      const until = nextBurst - clock;
      if (until < .3) return until > .12 ? .08 : .35;
      if (age < .7) {
        if (age < .07 || (age > .17 && age < .23)) return 1.1;
        if (age < .31) return .04;
        return Math.floor(age * 28) % 3 ? .45 : .9;
      }
      return 1;
    },
  };
}
