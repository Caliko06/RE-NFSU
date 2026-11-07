// After Hours. Local Marble capture, real game car, GPU weather.
// Keep the RN_SCENE interface consumed by launcher.js and launcher_ui.js.
import * as THREE from 'three';
import { SparkRenderer, SplatMesh } from '@sparkjsdev/spark';
import { GLTFLoader } from 'three/addons/loaders/GLTFLoader.js';
import {
  EffectComposer, RenderPass, ShaderPass, EffectPass, SelectiveBloomEffect,
  ToneMappingEffect, ToneMappingMode, SMAAEffect, VignetteEffect,
} from 'postprocessing';

const WORLD = new URL('./launcher/world/', import.meta.url);
const asset = name => new URL(name, WORLD).href;
const reduced = matchMedia('(prefers-reduced-motion: reduce)');
const time = { value: 0 }, lampLevels = { value: new THREE.Vector3(1, 1, 1) };
const lampPositions = [new THREE.Vector3(0, 3.9, -4), new THREE.Vector3(6, 2.9, -10), new THREE.Vector3(5, 3.5, -15)];
let renderer, scene, camera, composer, spark, car, bloom, lensPass;
let running = false, moving = !reduced.matches, elapsed = 0, weatherTime = 0, previous = 0;
let introDone = false, introCallback, screenName = 'main';
const pointer = new THREE.Vector2(), damped = new THREE.Vector2();
const cameraHome = new THREE.Vector3(0, 1.15, .7);
const targetHome = new THREE.Vector3(-.5, 1.35, -6);
const target = new THREE.Vector3();
const flickering = [];
const ray = new THREE.Raycaster(), down = new THREE.Vector3(0, -1, 0);
const rayOrigin = new THREE.Vector3();

function fallback(error) {
  running = false;
  renderer?.setAnimationLoop(null);
  document.documentElement.classList.add('static');
  document.getElementById('scene')?.setAttribute('data-state', 'fallback');
  if (error) console.error('[launcher world]', error);
}

// All random data, geometries, materials and uniforms are allocated at load time.
function instanced(points, seeds, vertexShader, fragmentShader, extra = {}) {
  const quad = new THREE.PlaneGeometry(1, 1);
  const geometry = new THREE.InstancedBufferGeometry();
  geometry.index = quad.index;
  geometry.attributes.position = quad.attributes.position;
  geometry.attributes.uv = quad.attributes.uv;
  geometry.setAttribute('origin', new THREE.InstancedBufferAttribute(new Float32Array(points), 3));
  geometry.setAttribute('seed', new THREE.InstancedBufferAttribute(new Float32Array(seeds), 2));
  geometry.instanceCount = seeds.length / 2;
  const material = new THREE.ShaderMaterial({
    uniforms: { uTime: time, uLamps: lampLevels, uLampPos: { value: lampPositions }, ...extra },
    vertexShader, fragmentShader, transparent: true, depthWrite: false,
    side: THREE.DoubleSide, blending: THREE.NormalBlending,
  });
  const mesh = new THREE.Mesh(geometry, material);
  mesh.frustumCulled = false;
  mesh.renderOrder = 4;
  scene.add(mesh);
  return mesh;
}
const illumination = /* glsl */`
  uniform vec3 uLampPos[3]; uniform vec3 uLamps;
  vec3 lit(vec3 p) {
    vec3 c=vec3(.10,.15,.21);
    c+=vec3(.65,.84,1.)*uLamps.x*2.5/(1.+distance(p,uLampPos[0])*distance(p,uLampPos[0]));
    c+=vec3(1.,.07,.10)*uLamps.y*2.8/(1.+distance(p,uLampPos[1])*distance(p,uLampPos[1]));
    c+=vec3(1.,.52,.15)*uLamps.z*3./(1.+distance(p,uLampPos[2])*distance(p,uLampPos[2]));
    return c;
  }
`;
function makeRain() {
  const points = [], seeds = [];
  // Separate near, middle and far volumes, each with its own density/length.
  for (let layer = 0; layer < 3; layer++) {
    const count = [280, 700, 1200][layer];
    for (let i = 0; i < count; i++) {
      points.push((Math.random() - .5) * [9, 19, 42][layer], 0,
        -[.5, 5, 13][layer] - Math.random() * [4.5, 8, 20][layer]);
      seeds.push(Math.random(), .7 + Math.random() * .6);
    }
  }
  instanced(points, seeds, /* glsl */`
    attribute vec3 origin; attribute vec2 seed; uniform float uTime;
    varying vec2 vUv; varying vec3 vLight;
    ${illumination}
    void main(){
      vUv=uv;
      float fall=fract(seed.x+uTime*(.65+seed.y*.18));
      vec3 p=origin+vec3(fall*.65,8.-fall*8.,0.);
      vLight=lit(p);
      vec4 view=modelViewMatrix*vec4(p,1.);
      float len=.10+seed.y*.10;
      view.xy+=vec2(position.x*.009-position.y*.035,position.y*len);
      gl_Position=projectionMatrix*view;
    }
  `, /* glsl */`
    varying vec2 vUv; varying vec3 vLight;
    void main(){
      float a=pow(max(0.,1.-abs(vUv.x*2.-1.)),1.7)*sin(vUv.y*3.14159)*.38;
      gl_FragColor=vec4(vLight,a);
    }
  `);
}
function groundAt(collider, x, z) {
  rayOrigin.set(x, 2.5, z); ray.set(rayOrigin, down);  // below the canopy roof: from higher up the first hit is the roof, not the ground
  const hit = ray.intersectObject(collider, true)[0];
  return hit ? hit.point.y : null;
}
function makeSplashes(collider) {
  const points = [], seeds = [], normals = [];
  for (let i = 0; i < 360; i++) {
    let x = (Math.random() - .5) * 19, z = -Math.random() * 23;
    let hit;
    if (i < 90) {
      // Raycast the real car once, so hood and roof droplets follow its mesh.
      rayOrigin.set((Math.random() - .5) * 1.5, 4, (Math.random() - .5) * 3.8);
      car.localToWorld(rayOrigin); ray.set(rayOrigin, down);
      hit = ray.intersectObject(car, true)[0];
    } else {
      rayOrigin.set(x, 2.5, z); ray.set(rayOrigin, down);
      hit = ray.intersectObject(collider, true)[0];
    }
    if (!hit?.face) continue;
    const normal = hit.face.normal.clone().applyNormalMatrix(new THREE.Matrix3().getNormalMatrix(hit.object.matrixWorld));
    if (normal.y < .35) continue;
    const point = hit.point.clone().addScaledVector(normal, .003);
    points.push(point.x, point.y, point.z); normals.push(normal.x, normal.y, normal.z);
    seeds.push(Math.random(), .5 + Math.random());
  }
  const splashes = instanced(points, seeds, /* glsl */`
    attribute vec3 origin, surfaceNormal; attribute vec2 seed; uniform float uTime;
    varying vec2 vUv; varying float vLife, vSeed; varying vec3 vLight;
    ${illumination}
    void main(){
      vLife=fract(seed.x+uTime*(.75+seed.y*.3)); vUv=uv; vSeed=seed.x;
      float age=clamp(vLife/.18,0.,1.);
      float radius=(.012+age*.035)*seed.y;
      vec3 tangent=normalize(cross(surfaceNormal,vec3(0.,0.,1.)));
      vec3 bitangent=cross(surfaceNormal,tangent);
      vec3 p=origin+(tangent*position.x+bitangent*position.y)*radius*2.;
      vLight=lit(origin);
      gl_Position=projectionMatrix*modelViewMatrix*vec4(p,1.);
    }
  `, /* glsl */`
    varying vec2 vUv; varying float vLife, vSeed; varying vec3 vLight;
    void main(){
      if(vLife>=.18) discard;
      vec2 p=vUv*2.-1.; float age=vLife/.18, burst=0.;
      // Separate tiny beads spread along the hit surface, with no annular base.
      for(int i=0;i<5;i++){
        float id=float(i), angle=id*1.256637+vSeed*6.28318;
        float reach=(.22+age*.48)*(.7+.3*sin(id*13.+vSeed*41.));
        vec2 bead=vec2(cos(angle),sin(angle))*reach;
        burst+=1.-smoothstep(.025,.11,length(p-bead));
      }
      float a=min(burst,1.)*sin(age*3.14159)*(1.-age)*.24;
      gl_FragColor=vec4(vLight,a);
    }
  `);
  splashes.geometry.setAttribute('surfaceNormal', new THREE.InstancedBufferAttribute(new Float32Array(normals), 3));
}
function makeMist() {
  instanced([0,.24,-8, 0,.48,-15], [.13,1, .73,1.5], /* glsl */`
    attribute vec3 origin; attribute vec2 seed; uniform float uTime;
    varying vec2 vUv; varying float vSeed;
    void main(){
      vUv=uv; vSeed=seed.x;
      vec3 p=origin+vec3(position.x*22.+sin(uTime*.025+seed.x*8.)*.7,position.y*.65,0.);
      gl_Position=projectionMatrix*modelViewMatrix*vec4(p,1.);
    }
  `, /* glsl */`
    uniform float uTime; varying vec2 vUv; varying float vSeed;
    void main(){
      float soft=sin(vUv.x*3.14159)*sin(vUv.y*3.14159);
      float folds=.5+.5*sin(vUv.x*19.+sin(vUv.x*9.+uTime*.04)+vSeed*7.);
      gl_FragColor=vec4(.33,.40,.46,soft*folds*.075);
    }
  `);
}

function makeLens() {
  // Original implementation of height-map refraction, inspired by the technique
  // described in Codrops RainEffect. No source or assets from that repository.
  const canvas = document.createElement('canvas'); canvas.width = canvas.height = 64;
  const context = canvas.getContext('2d');
  const pixels = context.createImageData(64, 64);
  for (let y = 0; y < 64; y++) for (let x = 0; x < 64; x++) {
    const px = (x - 31.5) / 30, py = (y - 31.5) / 30;
    const angle = Math.atan2(py, px);
    const contour = .87 + .065 * Math.sin(angle * 3 + .8) + .045 * Math.sin(angle * 5 - .4);
    const radius = Math.hypot(px + .09 * py * py, py) / contour;
    const height = Math.round(Math.sqrt(Math.max(0, 1 - radius * radius)) * 255);
    const i = (y * 64 + x) * 4;
    pixels.data[i] = pixels.data[i + 1] = pixels.data[i + 2] = height; pixels.data[i + 3] = 255;
  }
  context.putImageData(pixels, 0, 0);
  const heightMap = new THREE.CanvasTexture(canvas); heightMap.generateMipmaps = false;
  const material = new THREE.ShaderMaterial({
    depthTest: false, depthWrite: false,
    uniforms: { inputBuffer: { value: null }, heightMap: { value: heightMap }, uTime: time,
      aspect: { value: 1 }, intro: { value: 0 } },
    vertexShader: 'varying vec2 vUv; void main(){vUv=uv;gl_Position=vec4(position.xy,0.,1.);}',
    fragmentShader: /* glsl */`
      uniform sampler2D inputBuffer,heightMap; uniform float uTime,aspect,intro; varying vec2 vUv;
      void main(){
        vec2 refractUV=vec2(0.); float highlight=0.,innerEdge=0.,wet=0.;
        for(int i=0;i<8;i++){
          float id=float(i), phase=uTime*.035+id*.618;
          float life=fract(phase), cycle=floor(phase);
          float hash=fract(sin(id*81.17+cycle*17.1)*43758.5453);
          vec2 center=vec2(.06+hash*.88,.94-life*life*1.15);
          vec2 size=vec2(.008/aspect,.013)*(.65+fract(id*.371));
          float growth=smoothstep(0.,.15,life)*(1.-smoothstep(.85,1.,life));
          float slide=life*life*1.15;
          float trailLength=min(slide,.045)*growth;
          vec2 trailDelta=vUv-center;
          float trailWidth=size.x*.12*growth;
          float trail=(1.-smoothstep(trailWidth*.35,max(trailWidth,.000001),abs(trailDelta.x)))
            *smoothstep(0.,size.y,trailDelta.y)*(1.-smoothstep(0.,max(trailLength,.000001),trailDelta.y));
          refractUV.x+=trail*sin(trailDelta.x/max(trailWidth,.000001)*3.)*.0007;
          wet=max(wet,trail*.2);
          vec2 q=(vUv-center)/size/max(growth,.001)*.5+.5;
          float angle=id*2.4;
          q=mat2(cos(angle),-sin(angle),sin(angle),cos(angle))*(q-.5)+.5;
          if(all(greaterThan(q,vec2(0.)))&&all(lessThan(q,vec2(1.)))){
            float h=texture2D(heightMap,q).r;
            float dx=texture2D(heightMap,q+vec2(.015625,0.)).r-texture2D(heightMap,q-vec2(.015625,0.)).r;
            float dy=texture2D(heightMap,q+vec2(0.,.015625)).r-texture2D(heightMap,q-vec2(0.,.015625)).r;
            float mask=smoothstep(.015,.10,h);
            vec2 slope=mat2(cos(angle),sin(angle),-sin(angle),cos(angle))*vec2(dx,dy);
            refractUV+=vec2(slope.x/aspect,slope.y)*.026*growth*mask;
            wet=max(wet,mask);
            float edge=(1.-smoothstep(.16,.43,h))*mask;
            float lightSide=dot(normalize(-slope+vec2(.00001)),normalize(vec2(-.6,.8)));
            highlight+=edge*pow(max(lightSide,0.),5.)*.16;
            innerEdge+=smoothstep(.08,.18,h)*(1.-smoothstep(.22,.48,h))*max(-lightSide,0.)*.2;
          }
        }
        vec2 sampleUV=clamp(vUv+refractUV,.001,.999);
        vec3 color=texture2D(inputBuffer,sampleUV).rgb;
        if(wet>0.){
          vec2 blur=vec2(.00045/aspect,.00045);
          vec3 soft=(texture2D(inputBuffer,clamp(sampleUV+vec2(blur.x,0.),.001,.999)).rgb
            +texture2D(inputBuffer,clamp(sampleUV-vec2(blur.x,0.),.001,.999)).rgb
            +texture2D(inputBuffer,clamp(sampleUV+vec2(0.,blur.y),.001,.999)).rgb
            +texture2D(inputBuffer,clamp(sampleUV-vec2(0.,blur.y),.001,.999)).rgb)*.25;
          color=mix(color,soft,wet*.3);
        }
        gl_FragColor=vec4((color*(1.-innerEdge)+highlight)*intro,1.);
        #include <colorspace_fragment>
      }
    `,
  });
  return new ShaderPass(material, 'inputBuffer');
}

function sourceMesh(geometry, color, intensity, position, rotation) {
  const material = new THREE.MeshBasicMaterial({ color, toneMapped: false });
  material.color.multiplyScalar(intensity);
  const mesh = new THREE.Mesh(geometry, material);
  mesh.position.copy(position); if (rotation) mesh.rotation.copy(rotation);
  scene.add(mesh); bloom.selection.add(mesh);
  return mesh;
}
function makeLights() {
  scene.add(new THREE.HemisphereLight(0x8ba9cc, 0x15131b, .55));
  const tube = sourceMesh(new THREE.CylinderGeometry(.018,.018,2.5,8), 0xc1efff, 5,
    lampPositions[0], new THREE.Euler(0,0,Math.PI/2));
  const tubeLight = new THREE.PointLight(0xb7e7ff, 30, 12, 2);
  tubeLight.position.copy(lampPositions[0]); scene.add(tubeLight);
  flickering.push({ material: tube.material, color: tube.material.color.clone(), light: tubeLight, intensity: 30, seed: 3 });
  // Separate glyph strokes preserve legibility and let the whole sign flicker.
  const signCanvas = document.createElement('canvas'); signCanvas.width = 512; signCanvas.height = 128;
  const ctx = signCanvas.getContext('2d');
  ctx.font = '500 84px "Barlow Condensed"'; ctx.textAlign = 'center'; ctx.fillStyle = 'white';
  ctx.fillText('TUNING',256,96);
  const signMap = new THREE.CanvasTexture(signCanvas);
  const neon = sourceMesh(new THREE.PlaneGeometry(1.7,.43), 0xff2034, 5, lampPositions[1], new THREE.Euler(0,-Math.PI/2,0));
  neon.material.map = signMap; neon.material.transparent = true;
  const neonLight = new THREE.PointLight(0xff1632, 18, 10, 2);
  neonLight.position.copy(lampPositions[1]); scene.add(neonLight);
  flickering.push({ material: neon.material, color: neon.material.color.clone(), light: neonLight, intensity: 18, seed: 19 });
  const sodium = new THREE.PointLight(0xffac4e, 45, 24, 2);
  sodium.position.copy(lampPositions[2]); scene.add(sodium);
  sourceMesh(new THREE.SphereGeometry(.065,8,6),0xffb85e,7,lampPositions[2]);
}
function prepareCar(model, collider) {
  car = model; car.rotation.y = -.67;
  car.position.set(1.65, 0, -5.3);
  car.updateMatrixWorld(true);
  const bounds = new THREE.Box3().setFromObject(car);
  const ground = groundAt(collider, car.position.x, car.position.z);
  if (ground === null) throw new Error('Collider has no ground beneath the car');
  car.position.y += ground - bounds.min.y;
  const paint = new THREE.MeshPhysicalMaterial({ color: 0x061d73, metalness: .78, roughness: .23,
    clearcoat: 1, clearcoatRoughness: .075, envMapIntensity: 1.25 });
  car.traverse(mesh => {
    if (!mesh.isMesh) return;
    const original = mesh.material;
    if (/CARSKIN/.test(original.name)) mesh.material = paint;
    else if (/HEADLIGHT/.test(original.name)) {
      mesh.material = new THREE.MeshPhysicalMaterial({ color: 0xddeaff, emissive: 0xd7edff,
        emissiveIntensity: /GLASS/.test(original.name) ? 3 : 1.5, roughness: .12, metalness: .35 });
      bloom.selection.add(mesh);
    }
  });
  const poolCanvas = document.createElement('canvas'); poolCanvas.width = poolCanvas.height = 64;
  const poolContext = poolCanvas.getContext('2d');
  const poolGradient = poolContext.createRadialGradient(32,32,0,32,32,32);
  poolGradient.addColorStop(0,'white'); poolGradient.addColorStop(.45,'#888'); poolGradient.addColorStop(1,'black');
  poolContext.fillStyle=poolGradient; poolContext.fillRect(0,0,64,64);
  const poolMask = new THREE.CanvasTexture(poolCanvas);
  for (const x of [-.60,.60]) {
    const light = new THREE.SpotLight(0xe3eeff, 55, 15, .29, .85, 2);
    light.position.set(x,.67,1.94); light.target.position.set(x,.025,8);
    car.add(light,light.target);
    // A thin wet receiver lets the physical SpotLights illuminate the splat floor.
    const pool = new THREE.Mesh(new THREE.PlaneGeometry(1.8,6), new THREE.MeshPhysicalMaterial({
      color: 0x26333d, roughness: .19, metalness: .65, clearcoat: 1,
      transparent: true, opacity: .24, alphaMap: poolMask, depthWrite: false,
    }));
    pool.rotation.x = -Math.PI/2; pool.position.set(x,ground+.018-car.position.y,4.8);
    pool.renderOrder = 2; car.add(pool);
  }
  scene.add(car); car.updateMatrixWorld(true);
}

function flicker(t, seed) {
  const cycle = Math.floor(t / 8 + seed);
  const chance = Math.sin(cycle * 127.1 + seed * 31.7) * 43758.5453;
  const trigger = chance - Math.floor(chance);
  const local = (t + seed * .31) % 8;
  return trigger > .68 && local < .24 ? .15 + .85 * Math.pow(Math.sin(local * 137 + seed), 2) : 1;
}
function resize() {
  const w = innerWidth, h = innerHeight;
  renderer.setPixelRatio(Math.min(devicePixelRatio || 1, 1.5));
  renderer.setSize(w,h,false); composer.setSize(w,h);
  camera.aspect = w/h; camera.updateProjectionMatrix();
  lensPass.fullscreenMaterial.uniforms.aspect.value = w/h;
}
function frame(now) {
  if (!running) return;
  const dt = previous ? Math.min((now-previous)/1000,.05) : 0; previous = now;
  elapsed += dt; weatherTime += dt * (moving ? 1 : .25); time.value = weatherTime;
  const damping = 1-Math.exp(-dt*3);
  damped.x += ((moving ? pointer.x : 0)-damped.x)*damping;
  damped.y += ((moving ? pointer.y : 0)-damped.y)*damping;
  camera.position.copy(cameraHome);
  // Combined drift and pointer displacement stay below ~1.5 degrees.
  if (moving) { camera.position.x += Math.sin(elapsed*.17)*.018; camera.position.y += Math.sin(elapsed*.23)*.012; }
  target.copy(targetHome);
  if (moving) { target.x += damped.x*.13; target.y -= damped.y*.08; }
  camera.lookAt(target);
  for (let i=0;i<flickering.length;i++) {
    const item = flickering[i], level = flicker(elapsed,item.seed);
    item.material.color.copy(item.color).multiplyScalar(level); item.light.intensity = item.intensity*level;
    if (i===0) lampLevels.value.x=level; else lampLevels.value.y=level;
  }
  lensPass.fullscreenMaterial.uniforms.intro.value = Math.min(1,elapsed/1.2);
  composer.render(dt);
  if (!introDone && elapsed >= 1.2) { introDone=true; introCallback?.(); }
}
async function start(canvas) {
  if (renderer) return;
  canvas.dataset.state = 'loading';
  try {
    const gl = canvas.getContext('webgl2',{ alpha:false, antialias:false, powerPreference:'high-performance' });
    if (!gl) throw new Error('WebGL2 unavailable');
    renderer = new THREE.WebGLRenderer({canvas,context:gl,antialias:false});
    renderer.toneMapping = THREE.NoToneMapping;
    renderer.outputColorSpace = THREE.SRGBColorSpace;
    scene = new THREE.Scene(); scene.background = new THREE.Color(0x070b10);
    camera = new THREE.PerspectiveCamera(50,1,.08,180);
    camera.position.copy(cameraHome); camera.lookAt(targetHome);
    spark = new SparkRenderer({renderer,enableLod:false,minSortIntervalMs:32});
    spark.renderOrder = -10; scene.add(spark);
    const loader = new GLTFLoader();
    const metadata = fetch(asset('meta.json')).then(response => {
      if (!response.ok) throw new Error('Marble metadata unavailable'); return response.json();
    });
    const world = new SplatMesh({url:asset(new URLSearchParams(location.search).get('hq')==='1' ? 'world_full_res.spz' : 'world_500k.spz')});
    const [meta, colliderGLTF, carGLTF, pano] = await Promise.all([
      metadata, loader.loadAsync(asset('collider.glb')),
      loader.loadAsync(new URL('./launcher/v3/car.glb',import.meta.url).href),
      new THREE.TextureLoader().loadAsync(asset('pano.jpg')), world.initialized,
      document.fonts.load('500 84px "Barlow Condensed"'),
    ]);
    const collider = colliderGLTF.scene;
    const scale = Number(meta.metric_scale_factor), offset = Number(meta.ground_plane_offset);
    if (!(scale>0) || !Number.isFinite(offset)) throw new Error('Invalid Marble metric metadata');
    // OpenCV (+y down,+z forward) -> three (+y up,-z forward).
    for (const object of [world,collider]) {
      object.rotation.x = Math.PI; object.scale.setScalar(scale); object.position.y = offset*scale;
      object.updateMatrixWorld(true);
    }
    // Remove residual reconstruction bias at the capture origin; ground is y=0.
    collider.traverse(mesh => { if (mesh.isMesh) mesh.material = new THREE.MeshBasicMaterial({side:THREE.DoubleSide}); });
    const captureGround = groundAt(collider,0,0);
    if (captureGround === null) throw new Error('Collider ground unavailable at capture origin');
    world.position.y -= captureGround; collider.position.y -= captureGround;
    collider.updateMatrixWorld(true); collider.visible = false;
    scene.add(world); // Collider is only a load-time placement/raycast surface.
    pano.mapping = THREE.EquirectangularReflectionMapping; pano.colorSpace = THREE.SRGBColorSpace;
    const pmrem = new THREE.PMREMGenerator(renderer);
    scene.environment = pmrem.fromEquirectangular(pano).texture; pmrem.dispose(); pano.dispose();
    composer = new EffectComposer(renderer,{frameBufferType:THREE.HalfFloatType,multisampling:0});
    composer.addPass(new RenderPass(scene,camera));
    bloom = new SelectiveBloomEffect(scene,camera,{mipmapBlur:true,intensity:.55,luminanceThreshold:1,luminanceSmoothing:.2});
    bloom.ignoreBackground = true;
    prepareCar(carGLTF.scene,collider); makeLights(); makeRain(); makeSplashes(collider); makeMist();
    // Bloom selects only luminous fixtures and headlight meshes, never the paint/world.
    composer.addPass(new EffectPass(camera,bloom,new ToneMappingEffect({mode:ToneMappingMode.AGX}),
      new SMAAEffect(),new VignetteEffect({offset:.25,darkness:.25})));
    lensPass = makeLens(); composer.addPass(lensPass);
    resize(); addEventListener('resize',resize);
    canvas.addEventListener('webglcontextlost',event => { event.preventDefault(); fallback(new Error('WebGL context lost')); });
    canvas.dataset.state = 'ready'; running = true; renderer.setAnimationLoop(frame);
  } catch (error) { fallback(error); throw error; }
}
window.RN_SCENE = {
  start,
  motion(on) { moving=Boolean(on)&&!reduced.matches; if (!moving) damped.set(0,0); },
  pointer(x,y) { pointer.set(Math.max(-1,Math.min(1,x)),Math.max(-1,Math.min(1,y))); },
  screen(name) { screenName=name; },
  confirm() {},
  resume() { if (renderer && !document.documentElement.classList.contains('static')) { previous=0; running=true; renderer.setAnimationLoop(frame); } },
  onIntroDone(callback) { introCallback=callback; if (introDone) callback(); },
  stats() { return { world: new URLSearchParams(location.search).get('hq')==='1' ? 'full' : '500k', screen:screenName, ready:running }; },
};
addEventListener('pagehide',() => { running=false; renderer?.setAnimationLoop(null); });
