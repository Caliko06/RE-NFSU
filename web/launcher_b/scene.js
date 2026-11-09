import * as pc from './vendor/playcanvas.mjs';

// game/fx/*.efx are the shipped .fx sources XOR 0xAA (loader 0x40e180).

// TextureInfo +0x55 == 1: alpha reference 170/255 (0x40f436).
// +0x56: 0 opaque, 1 SRCALPHA/INVSRCALPHA, 2 SRCALPHA/ONE (0x40f4ab).
const textureStates = {"SGN_ALL_DAY_BREAKFAST_N":[0,2],"ARC_VENTS":[0,0],"OBJ_GREEN_BOX":[0,0],"SGN_COMMERCIALST":[0,0],"ARC_UNDERTHEBRIDGE":[0,0],"SGN_COMMERCIALSTB":[0,0],"SGN_NEON_OUTLINE":[0,2],"OBJ_NOPARKING":[0,0],"ARC_LI_STWL04_SD":[0,0],"ARC_LI_STWL05_SD":[0,0],"SGN_RJB_PARK_KING":[0,0],"ARC_COURTGD_01":[0,0],"ARC_LI_STWN04_ILLU":[0,2],"ARC_RJB_SHOPC_WINDOW":[0,0],"ARC_FACTORYBRICK_04":[0,0],"ARC_RJB_BLKSHNYMETL":[0,0],"ARC_LI_CLOTH04":[0,0],"ARC_LI_CLOTH15":[0,0],"ARC_CANOPYPOHINGJEWELRY":[0,0],"SGN_BACK_001":[0,0],"SGN_TOW_AWAY":[0,0],"RDP_ROADSTRIP_AC":[0,0],"RDP_ROADSTRIP_AD":[0,0],"RDP_ROADSTRIP_BC":[0,0],"RDP_ROADSTRIP_BG":[0,0],"RDP_ROADSTRIP_MC":[0,0],"OBJ_TELEPOLE01":[0,0],"OBJ_TELEPOLE_LITE_BRIGH":[0,1],"ARC_CT4STORY_APARTA":[0,0],"ARC_NOTRESPASS":[0,0],"SGN_BILLBOARD_GRAFB":[0,0],"ARC_CONC_TOPBOX":[0,0],"ARC_CONC_WALL2":[0,0],"OBJ_GARBAGE_BIN":[0,0],"ARC_RJB_SHOPE_SIDEA":[0,0],"ARC_BLDING_B_C":[0,0],"ARC_BLDING_D_F":[0,0],"ARC_BLDING_E_G":[0,0],"SGN_LIGHT_001":[1,0],"OBJ_FENCE_CHNLINK":[1,0],"ARC_RJB_SHOPA_WINDOW":[0,0],"ARC_CONCRETE_BLOCKA":[0,0],"ARC_LI_MTCN01":[0,0],"ARC_LI_MTSC01":[1,0],"ARC_OVERPASS_001":[0,0],"AR1_WALLBRKOLD":[0,0],"SGN_BUS_STOP":[0,0],"ARC_LI_PLBG01":[0,0],"SGN_NOPARKING":[0,0],"ARC_ST_BALC_BAR":[0,1],"ARC_CT6STORY_BANKB":[0,0],"ARC_LI_STRF02":[0,0],"ARC_LI_STST01":[0,0],"ARC_LI_STWL07":[0,0],"ARC_LI_STWL08":[1,0],"ARC_LI_STWL15":[0,0],"ARC_LI_STWL16":[0,0],"ARC_LI_STWL17":[0,0],"ARC_LI_STWN04":[0,0],"ARC_LI_STWN06":[0,0],"ARC_LI_STWN16":[0,0],"ARC_LI_STWN22":[0,0],"ARC_LI_STWN25":[0,0],"OBJ_WOOD_PLANKS":[0,0],"ARC_BARRIER_GREEN":[1,0],"SGN_ADV_AUTOZONE_SPARKP":[0,0],"TRN_GRASSC":[0,0],"ARC_RJB_SHOPD":[0,0],"ARC_RJB_SHOPE":[0,0],"ARC_RJB_SHOPF":[0,0],"ARC_RJB_STC_B":[0,0],"SGN_WALLACEST":[0,0],"ARC_CT3TOWERAPARTMENT_N":[0,2],"ARC_A_INSIDE":[0,0],"ORG_LEAVES6T":[1,0],"SGN_THE_IMPERIAL_NEON":[0,2],"SGN_METALROUND":[0,0],"SGN_LI_GATE01":[0,0],"SGN_LI_GATE03":[0,0],"ARC_WINDOW_GREY_CORRGTD":[0,0],"XW_CHAIN_FENCEB":[1,0],"ARC_CONCRETPAINTED_01":[0,0],"ARC_RJB_MONEY_SIGN_NEON":[0,2],"ARC_WIND_STORELIT":[1,0],"ARC_ST_BUILD01_SIDE":[0,0],"SGN_LI_OPEN01":[0,2],"ARC_CONC_WALL":[0,0],"SFX_TRAFFICLIGHTYELLOW":[0,0],"RDP_ROADSTRIP_COBBLESTO":[0,0],"RDP_ROADSTRIP_AADIRT":[0,0],"ARC_MARKETSTORE":[0,0],"ARC_RJB_BILLIARD_BALL":[0,0],"ARC_CANOPYKAMTRAVEL":[0,0],"RDP_ROADSTRIP_RSHLDR1":[0,0],"RDP_ROADSTRIP_RSHLDR3":[0,0],"SGN_WALLACESTB":[0,0],"SGN_RJB_LUNCH":[0,2],"ARC_SHINY_METAL":[0,0],"OBJ_TELEPOLE":[0,0],"SGN_THE_DIPLOMAT_NEON":[0,2],"ARC_SHOPPING_CENTER_01":[0,0],"RDP_RD_INTERSECT_MA":[0,0],"SGN_SIGNALAHEAD":[0,0],"SGN_HOTEL":[0,2],"ARC_CONCFREEWAY":[0,0],"ARC_SHOPPING_CENTER_PLA":[0,0],"ARC_A51CONCRETE":[0,0],"RDP_ROAD_JUNKYARD":[0,0],"OBJ_SMALLROUND":[0,0],"ARC_NORCHEMSIDE":[0,0],"ARC_DEADBRANCH":[1,0],"ARC_CT3TOWERAPARTMENT":[0,0],"SGN_BACKLARGESIGN":[0,0],"AR1_STORE01":[0,0],"ORG_GRASSSINGLE":[1,0],"SGN_RJB_PARK_KING_NEON":[0,2],"ARC_A_CROSSBEAM_GR":[0,0],"SGN_RJB_PARK_CROWN_NEON":[0,2],"ARC_OVERPASS_GRAFA":[0,0],"ARC_OVERPASS_GRAFC":[0,0],"ARC_OVERPASS_GRAFE":[0,0],"ARC_BRICK01":[0,0],"ARC_RJB_SHOPG_WINDOW":[0,0],"SGN_USED_FURNITURE":[0,0],"SGN_LIGHTBACK_001":[1,0],"ARC_BARRIERDIRTY":[0,0],"OBJ_FENCE_CHNLINK01_TOP":[1,0],"ARC_CANOPYMAHBAKERY":[0,0],"ARC_A51_CONCWALL1":[0,0],"OBJ_CARDBOARD_BOX2":[0,0],"OBJ_BARREL1":[0,0],"WAL_YELLOWBARRIER":[0,0],"ARC_RJB_SHOPF_WINDOW":[0,0],"ARC_POST_METALA":[1,0],"ARC_A_PILLERSIDE":[0,0],"ARC_NEONLIGHTS":[1,2],"ARC_CHAINA":[1,0],"SGN_WARNSIDERD":[0,0],"ARC_LI_WDWN01_L":[0,2],"RDP_INTERSECTMIDTILE":[0,0],"OBJ_POLE_001":[0,0],"ARC_RJB_SHOPE_WINDOW":[0,0],"ARC_IBEAM3":[0,0],"OBJ_VIOLATORS":[0,0],"ARC_LADDER":[1,0],"TRN_GRASS_001":[0,0],"ARC_METAL3":[0,0],"ARC_FENCEONBRIDGE":[1,0],"ARC_LI_STWN09_L":[0,2],"ARC_LI_STWN10_L":[0,2],"ARC_SIDEWALK_A":[0,0],"ARC_SIDEWALK_C":[0,0],"ARC_SIDEWALK_F":[0,0],"ARC_BRIDGESIDES":[1,0],"ARC_ST_BUILD06":[0,0],"ARC_RJB_STOREFRONTA":[0,0],"ARC_WAREHOUSE_ROOF02":[0,0],"OBJ_BARK":[0,0],"OBJ_SPOT":[0,2],"SGN_RJB_BLANCHARD_NEON":[0,2],"SGN_ADV_ZOOYORKA":[0,0],"ARC_BLDING_D_C":[0,0],"SGN_SUSHI_RYAN_NEON":[0,2],"SGN_RJB_THEATRE_PURPLE":[0,2],"SGN_STAR_NEON":[0,2],"SGN_SUSHI_NEON":[0,2],"BRAKE_GLOBAL":[0,1],"HEADLIGHTGLOW":[0,2],"DRIVER":[0,1],"WINDOW":[0,1],"CARBOTTOM":[0,0],"BRAKE_STYLE00":[1,0],"GRAY_MID_A":[0,0],"SKYLINE_KIT00_BRAKELIGH":[0,0],"SKYLINE_TIRE":[1,0],"SKYLINE_BADGING":[0,1],"SKYLINE_KIT00_HEADLIGHT":[0,0]};

const canvas = document.querySelector('#scene');
const status = document.querySelector('#status');
const started = performance.now();
window.RN_B = { ready: false };
const color = (r,g,b) => new pc.Color(r,g,b);

async function main() {
    const app = new pc.Application(canvas, { graphicsDeviceOptions: {
        antialias: false, alpha: false, powerPreference: 'high-performance' } });
    const device = app.graphicsDevice;
    device.maxPixelRatio = window.devicePixelRatio;
    app.scene.fog.type = pc.FOG_NONE;
    // D3D9 and gpu.js use raw UNORM samples and a UNORM framebuffer. This is
    // deliberately gamma-space arithmetic, not linear PBR plus another sRGB encode.
    const cameraOptions = { clearColor: color(.012,.022,.055), nearClip: .1, farClip: 650,
        toneMapping: pc.TONEMAP_NONE, gammaCorrection: pc.GAMMA_NONE };
    const skyLayer = new pc.Layer({ name: 'Night sky' });
    app.scene.layers.insertOpaque(skyLayer,0);
    const groundLayer = new pc.Layer({ name: 'RDP reflection receivers' });
    const carLayer = new pc.Layer({ name: 'Car effect' });
    const captureLayer = new pc.Layer({ name: 'Street reflection capture' });
    const cubeGroundLayer = new pc.Layer({ name: 'EnvMap road' });
    for (const layer of [groundLayer,carLayer,captureLayer,cubeGroundLayer]) {
        app.scene.layers.pushOpaque(layer); app.scene.layers.pushTransparent(layer);
    }
    const camera = new pc.Entity('Slow dolly');
    camera.addComponent('camera', { ...cameraOptions, fov: 43, priority: 1,
        layers: [skyLayer.id,pc.LAYERID_WORLD,groundLayer.id,carLayer.id] });
    app.root.addChild(camera);
    // PlayCanvas 2.22 CameraFrame supplies TAA; keep MSAA and other effects off.
    const frame = new pc.CameraFrame(app,camera.camera);
    frame.taa.enabled = true;
    frame.rendering.toneMapping = pc.TONEMAP_NONE;
    frame.update();
    const chunks = pc.ShaderChunks.get(device,pc.SHADERLANGUAGE_GLSL);
    // Compose normally forces sRGB output. This scene already shades in DX9
    // UNORM space: retain the engine pass, but make its gamma helper an identity.
    chunks.set('composePS','#undef GAMMA\n#define GAMMA NONE\n'+chunks.get('composePS'));
    // Small HDR-only halo in the existing compose pass, no extra full-scene pass.
    // Only additive signs and headlight glass can exceed 1.15 in our shaders.
    chunks.set('composeMainEndPS',`
        vec3 halo = vec3(0.0);
        for (int ring=1; ring<=3; ring++) {
            float radius = float(ring)*2.0;
            for (int tap=0; tap<8; tap++) {
                float angle = float(tap)*0.785398163;
                vec3 source = texture2DLod(sceneTexture,
                    uv+vec2(cos(angle),sin(angle))*sceneTextureInvRes*radius,0.0).rgb;
                float peak = max(source.r,max(source.g,source.b));
                halo += source * smoothstep(1.15,1.5,peak) * exp(-float(ring*ring)*.35);
            }
        }
        result = (min(result,vec3(1.0)) + halo*.018)*1.25;
    `);
    function target(name,w,h) {
        return new pc.RenderTarget({ colorBuffer: new pc.Texture(device, { name,
            width: w, height: h, format: pc.PIXELFORMAT_RGBA8, srgb: false,
            mipmaps: true, anisotropy: device.maxAnisotropy,
            minFilter: pc.FILTER_LINEAR_MIPMAP_LINEAR, magFilter: pc.FILTER_LINEAR,
            addressU: pc.ADDRESS_CLAMP_TO_EDGE, addressV: pc.ADDRESS_CLAMP_TO_EDGE }), depth: true });
    }
    let reflectionTarget = target('RDP reflection',1,1);
    const reflection = new pc.Entity('Planar reflection');
    reflection.addComponent('camera', { ...cameraOptions, fov: 43, priority: -1,
        layers: [skyLayer.id,captureLayer.id,carLayer.id], renderTarget: reflectionTarget });
    app.root.addChild(reflection);
    app.setCanvasFillMode(pc.FILLMODE_FILL_WINDOW);
    app.setCanvasResolution(pc.RESOLUTION_AUTO);
    let reflectionFrames = 2;
    let fitCamera = () => {};
    const resize = () => {
        reflectionFrames = 2; reflection.enabled = true;
        device.maxPixelRatio = window.devicePixelRatio;
        app.resizeCanvas(innerWidth,innerHeight);
        for (const [entity,old,name] of [[reflection,reflectionTarget,'RDP reflection']]) {
            const next = target(name,Math.max(1,device.width>>1),Math.max(1,device.height>>1));
            entity.camera.renderTarget = next;
            old.destroyTextureBuffers(); old.destroy();
            reflectionTarget = next;
            fitCamera();
        }
    };
    resize(); window.addEventListener('resize',resize);

    const load = url => new Promise((resolve,reject) => app.assets.loadFromUrl(url,'container',
        (err,asset) => err ? reject(new Error(String(err))) : resolve(asset.resource)));
    function rawMap(texture) {
        // glTF baseColor is tagged sRGB by the importer. Disable hardware decode
        // for the original DX9 equation; no shader decode/encode is applied either.
        texture.srgb = false;
        texture.anisotropy = device.maxAnisotropy;
        texture.mipmaps = true;
        texture.minFilter = pc.FILTER_LINEAR_MIPMAP_LINEAR;
        texture.magFilter = pc.FILTER_LINEAR;
        return texture;
    }
    const white = rawMap(new pc.Texture(device,{width:1,height:1,format:pc.PIXELFORMAT_RGBA8,srgb:false}));
    white.lock().set([255,255,255,255]); white.unlock();
    const textureOf = m => rawMap(m.emissiveMap || m.diffuseMap || white);
    // Original TPK pixels embedded here to keep the launcher self-contained.
    // SKYLINE_SHADOWIG: car TEXTURES.BIN; HEADLIGHTS/SHADOWRAMP: GLOBALB.BUN.
    const originalTextures = {"SKYLINE_SHADOWIG": "data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAIAAAABACAYAAADS1n9/AAAE4UlEQVR4nO1d7Y3kIAxlT9eAW5j+a7oW3ML9uUgs529sSLI8aZTZhBDAz88mOyStHfxofO1uQGsNkuvDdn/AXdr59QCDVw8WOtqQTVYN+AYCSIP2hgGFRe3DJxEANhLhFtIq9NHbPqzsXzYBgPkb/n0+3XcN2G2vj/WcqjDgRd9/K5DZSt+3E0AyfOuMHyHAHyMBKo3fA5zlPH0eCT9+ruN92a0E4AzPeX9PAg3SIGjnWYHNDw8BqI+lTdfnj9B/ihBu/J44F5TvIwHGAZAGo8+4+++WGUFfr7UsKuWoui1l+n5/HNe4jM9d7xqTfrucAJLB+2MRT+g7NU7BIgbWygJTzmtw6ljfX0/o68+jHCKFBBECaN4+Nt4T/6RrNaKTnnqt3g6BOjPqGs+hlC+dBBkhgGI4xfyZqd7MuTOkscKjAp46L8NawmWIBF4CWD2dI4DXu7hcwNvm6nsDEDxmqZfrNxUilyiAJdaP5azJn+W6d/F6CbCwDqqvWEEALvZbjT8TD5uT3ZkhI8OgUfkfz5VUMBQKoiHg+m4JBdQ2giwvzkoCIaEtESJw7S8NAdYYV2X8TNylHZEc6NrfDDlBWQigZJ+L85rxOamrxqpwIsEi1ZwCcGowlscVN4LGBliMn5EUPl0FYNhighq4VeCXo6HUBa0KMJY9+B+SSlLHU8YxOg3kDMll/bNTPy37vcpa7hVk3Fuo/pez5bY1FwpcYSA7CbQej0yLLMcs9e4KPzBJjMj/MlJCgARq6jfuH8ufEKCPiRYOtHLasRQCeJO7Y3gZ3vFKmV5rBOAM6mXeMf48os4FmQoQkfBjfDuyVBNW5QAH6yHlB24HzUoCrfsPboajAPfD0uQ5iwDSjaGDWpTOAg5ejuz7AAcPQ7UCVP8W7+DmBDgq8WICHO9+AbIUgFu3d0gyj9IxPLOA5xscdxLgePjDUaUA6Q8yODDBuoR+igDHoPcE53Q4Q4CxIstDCQ5B8rw3/YEQK5PAEwbqwD0tZNt9AOoRJlL5g++ITqGlMU9bFyBVps3/KUmzkOWnAI3GL5H/ipVB1G/tLb/pz8b42/mpx6go4NYjVPWNI0zIsbwEkNbda2vYdq39K/Oegvox2eCYEQK0C0jZKzeLOPgOy9h44n3J6mBK2puwb5RfrnGUdGp1Su2jlGgFgFiiJcGa5I1lR+/vy+CKHEAaYGpdmsVwnn1WyVutNqj8PVuv18CYSQDKkNwFOBKsxM5QA0n1SDfhuM94XtkswCLrUlIYuV42cOJcqR+eMKCBk3ktASzNASgVsEyxKoyfLbMaPHkF5QRWeDL/sPfP3gegki5OCaIq4O0Y3kRhYML4zSH1VM5TGgJGFRhJIJVvk8b3ZM2zwIy190Hia7G+PxZpU8osAIxksOQG3DWyOjqrHhh4+ITUb09btEQv4iRp7wug1qcDsf0Qj0y3DOZMdlsZMsB4vN9GcgDqfQHNsN32wgiOEB/B+JoKcPGOKrsj3oOyfzQ+BBM+zhGmw8DXggcX9N5vNX6GCnD1ZQOU/ZRjeKS/Cdvx+9aXRnHGHdetW1e/pnd2MQFmIPU5czxKXhtnNfCuVUNZJIBWAy0Zlcrc6sWRFcvFK//Bg47rr4Lk/Y96daw1c85CBUFmMPtjFHzjy6N3LhzFB4aAHwdt/ryTQO0t+AuGOtf+blfsGwAAAABJRU5ErkJggg==", "SHADOWRAMP": "data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAIAAAAAICAYAAAAx3fd+AAAAn0lEQVR4nO1XuxKAIAyLTiz+/4c62E1XzuPRQkRAs0GwLTWXowuAE2HsyEMy6/sem/fXR8F3UpiLXUeIs/KxM6l9rDECwJbgLMl9uEqeDUeIobl3q/rN90kJQOMA1uTSWTOFEKO1aKn1pwTwBN5s1hccoHsB9CYQIcT4HaBxw2d2pKEdgPFzR3wDCAYWa80UUPICnXEKcIQYmjiaMdCMC6cIME1DYB4cAAAAAElFTkSuQmCC", "HEADLIGHTS": "data:image/png;base64,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"};
    const effectTextures = {};
    await Promise.all(Object.entries(originalTextures).map(async ([name,url])=>{
        const image = new Image(); image.src=url; await image.decode();
        const texture=new pc.Texture(device,{name,srgb:false,mipmaps:true,
            minFilter:pc.FILTER_LINEAR_MIPMAP_LINEAR,magFilter:pc.FILTER_LINEAR,
            addressU:pc.ADDRESS_CLAMP_TO_EDGE,addressV:pc.ADDRESS_CLAMP_TO_EDGE});
        texture.setSource(image); effectTextures[name]=texture;
    }));
    const skyShader = new pc.ShaderMaterial({uniqueName:'NFSU_night_sky',attributes:{
        aPosition:pc.SEMANTIC_POSITION,aUv:pc.SEMANTIC_TEXCOORD0,aColor:pc.SEMANTIC_COLOR},
        vertexGLSL:`
            attribute vec3 aPosition; attribute vec2 aUv; attribute vec4 aColor;
            uniform mat4 matrix_model; uniform mat4 matrix_viewProjection;
            varying vec3 direction; varying vec2 uv; varying vec4 baked;
            void main(){
                direction=normalize(aPosition); uv=aUv; baked=aColor;
                gl_Position=matrix_viewProjection*matrix_model*vec4(aPosition,1.0);
                gl_Position.z=gl_Position.w*.99999;
            }`,fragmentGLSL:`
            precision highp float;
            uniform sampler2D skyMap; uniform float exportedSky; uniform float vertexLit;
            varying vec3 direction; varying vec2 uv; varying vec4 baked;
            void main(){
                vec3 night=mix(vec3(.027,.043,.09),vec3(.006,.012,.035),
                    smoothstep(-.1,.85,normalize(direction).y));
                vec3 original=texture2D(skyMap,uv).rgb*mix(vec3(1.0),2.0*baked.rgb,vertexLit);
                gl_FragColor=vec4(mix(night,original,exportedSky),1.0);
            }`});
    skyShader.cull=pc.CULLFACE_NONE; skyShader.depthTest=false;
    skyShader.depthWrite=false; skyShader.sceneTexturesWrite=false;
    skyShader.setParameter('skyMap',white); skyShader.setParameter('exportedSky',0);
    skyShader.setParameter('vertexLit',0);
    let sky=new pc.Entity('Night-navy sky');
    sky.addComponent('render',{type:'sphere',material:skyShader,layers:[skyLayer.id]});
    sky.setLocalScale(400,400,400); app.root.addChild(sky);
    const skyMetaResponse=await fetch(new URL('./track/sky_meta.json',import.meta.url));
    if(skyMetaResponse.ok){
        const skyMeta=await skyMetaResponse.json();
        const exported=(await load(new URL('./track/sky.glb',import.meta.url).href)).instantiateRenderEntity();
        for(const render of exported.findComponents('render')){
            render.layers=[skyLayer.id];
            for(const mesh of render.meshInstances){
                const m=skyShader.clone(); m.setParameter('skyMap',textureOf(mesh.material));
                m.setParameter('exportedSky',1);
                m.setParameter('vertexLit',mesh.mesh.vertexBuffer.format.elements.some(e=>e.name===pc.SEMANTIC_COLOR)?1:0);
                mesh.material=m;
            }
        }
        sky.destroy(); sky=exported; app.root.addChild(sky);
        window.RN_B.sky={source:'sky.glb',metadata:skyMeta};
    } else if(skyMetaResponse.status===404) window.RN_B.sky={source:'night-navy gradient'};
    else throw new Error(`Sky metadata HTTP ${skyMetaResponse.status}`);
    function applyTextureState(m,name) {
        const [test,blend] = textureStates[name] || [0,0]; // Runtime SKIN1 is opaque.
        m.setParameter('alphaRef',test ? 170/255 : -1);
        m.setParameter('glow',blend===2 ? 1 : 0);
        m.blendType = blend===2 ? pc.BLEND_ADDITIVEALPHA : blend===1 ? pc.BLEND_NORMAL : pc.BLEND_NONE;
        m.depthWrite = blend===0;
        m.sceneTexturesWrite = m.depthWrite;
        return blend;
    }
    const sceneVertex = `
        attribute vec3 aPosition;
        attribute vec2 aUv;
        attribute vec4 aColor;
        uniform mat4 matrix_model;
        uniform mat4 matrix_viewProjection;
        uniform mat4 matrix_view;
        varying float viewDepth;
        uniform mat4 reflectionVP;
        varying vec2 uv;
        varying vec4 baked;
        varying vec3 world;
        varying vec4 reflected;
        void main() {
            vec4 p = matrix_model * vec4(aPosition,1.0);
            viewDepth = -(matrix_view*p).z;
            world = p.xyz; uv = aUv;
            // track_export.py already swizzled D3DCOLOR BGRA -> RGBA. Do not swizzle twice.
            baked = aColor;
            reflected = reflectionVP * p;
            gl_Position = matrix_viewProjection * p;
        }`;
    const streetShader = new pc.ShaderMaterial({ uniqueName:'NFSU_world_efx', attributes: {
        aPosition:pc.SEMANTIC_POSITION,aUv:pc.SEMANTIC_TEXCOORD0,aColor:pc.SEMANTIC_COLOR },
        vertexGLSL:sceneVertex, fragmentGLSL:`
        precision highp float;
        varying float viewDepth;
        #include "sceneTexturesPS"
        #ifdef PREPASS_PASS
            #include "floatAsUintPS"
        #endif
        uniform sampler2D diffuseMap;
        uniform sampler2D reflectionMap;
        uniform float road;
        uniform float glow;
        uniform vec4 lamps[8];
        uniform mat4 worldToCar;
        uniform sampler2D shadowMap;
        uniform sampler2D headlightMap;
        uniform sampler2D headlightClipMap;
        uniform float alphaRef;
        varying vec2 uv;
        varying vec4 baked;
        varying vec3 world;
        varying vec4 reflected;
        void main() {
            vec4 dc = texture2D(diffuseMap,uv);
            vec4 base = clamp(2.0*dc*baked,0.0,1.0); // world.efx, including alpha
            if (base.a <= alphaRef) discard;
            #ifdef PREPASS_PASS
                gl_FragColor = float2vec4(viewDepth);
                return;
            #endif
            if (road > .5) {
                vec3 local = (worldToCar*vec4(world,1.0)).xyz;
                vec2 shadowUV = local.xz/vec2(2.7,5.5)+.5;
                float footprint = step(0.0,shadowUV.x)*step(shadowUV.x,1.0)*step(0.0,shadowUV.y)*step(shadowUV.y,1.0);
                float contact = texture2D(shadowMap,clamp(shadowUV,0.0,1.0)).a*footprint;
                float ao = exp(-dot(local.xz/vec2(1.05,2.1),local.xz/vec2(1.05,2.1))*2.0)*.25;
                vec3 illumination = vec3(0.0);
                for (int i=0; i<8; i++) {
                    vec3 delta = lamps[i].xyz-world;
                    float height = max(delta.y,.1);
                    float pool = exp(-dot(delta.xz,delta.xz)/(height*height*.45));
                    illumination += vec3(1.0,.78,.48)*pool*lamps[i].w;
                }
                // worldheadlight.efx: (headlight*clip*color + vertexColor)*texture*2.
                // HEADLIGHTS contains the original paired low-beam footprint.
                float ahead = local.z-2.013;
                float beamWidth = 1.4+max(ahead,0.0)*.19;
                vec2 beamUV = vec2(local.x/(2.0*beamWidth)+.5,1.0-ahead/16.0);
                float beamClip = step(0.0,ahead)*step(ahead,16.0)*step(abs(local.x),beamWidth);
                vec3 beam = texture2D(headlightMap,clamp(beamUV,0.0,1.0)).rgb;
                vec3 clip = texture2D(headlightClipMap,vec2(clamp(ahead*.005+.5,0.0,1.0),.5)).rgb;
                illumination += beam*clip*vec3(.72,.76,.82)*beamClip;
                base.rgb += 2.0*dc.rgb*illumination;

                vec2 ruv = reflected.xy / reflected.w * .5 + .5;
                vec3 r = texture2D(reflectionMap,ruv).rgb;
                float inside = step(0.0,ruv.x)*step(ruv.x,1.0)*step(0.0,ruv.y)*step(ruv.y,1.0)*step(0.0,reflected.w);
                // worldreflect.efx: vertex alpha * texture alpha, without extra Fresnel attenuation.
                // worldheadlightreflect.efx adds the projected reflected image.
                base.rgb += r*dc.a*baked.a*inside;
                base.rgb *= 1.0-max(contact*.72,ao); base.a = 1.0;
            }
            base.rgb = min(base.rgb,vec3(1.0));
            if (glow > .5) base.rgb *= 1.0+.75*smoothstep(.65,1.0,max(base.r,max(base.g,base.b)));
            gl_FragColor = base;
            writeSceneTextureDepth(viewDepth,1.0);
        }` });
    const roads = [], worldMaterials = [], carMaterials = [], captureMaterials = [];
    const carPosition = new pc.Vec3(-1.8,-.006289,10);
    const reflectedVP = new pc.Mat4(), reflectedView = new pc.Mat4();
    const roadY = -.010289;
    const street = (await load(new URL('./track/street.glb',import.meta.url).href)).instantiateRenderEntity();
    app.root.addChild(street);
    const streetMaterials = new Map();
    const lampCandidates=[];
    for(const render of street.findComponents('render')) {
        if(!/STREETLIGHT|PARKLAMP/i.test(render.entity.name)) continue;
        const bounds=new pc.BoundingBox(); let first=true;
        for(const mesh of render.meshInstances){if(first){bounds.copy(mesh.aabb);first=false;}else bounds.add(mesh.aabb);}
        if(first) continue;
        const p=bounds.center.clone(); p.y+=bounds.halfExtents.y-.15;
        lampCandidates.push(p);
    }
    lampCandidates.sort((a,b)=>a.distance(carPosition)-b.distance(carPosition));
    const lamps=new Float32Array(32);
    for(let i=0;i<Math.min(8,lampCandidates.length);i++) lamps.set([...lampCandidates[i].toArray(),.16],i*4);
    window.RN_B.street_lamps=Math.min(8,lampCandidates.length);
    for (const render of street.findComponents('render')) for (const mesh of render.meshInstances) {
        const original = mesh.material;
        let m = streetMaterials.get(original);
        if (!m) {
            m = streetShader.clone(); m.name = original.name; m.cull = pc.CULLFACE_NONE;
            m.setParameter('diffuseMap',textureOf(original));
            m.setParameter('road',/^RDP_/i.test(m.name)?1:0);
            const textureName = m.name.split('+')[0];
            applyTextureState(m,textureName);
            m.setParameter('lamps[0]',lamps);
            m.setParameter('shadowMap',effectTextures.SKYLINE_SHADOWIG);
            m.setParameter('headlightMap',effectTextures.HEADLIGHTS);
            m.setParameter('headlightClipMap',effectTextures.SHADOWRAMP);
            streetMaterials.set(original,m); worldMaterials.push(m);
        }
        mesh.material = m;
        // A separate binding is required: sampling reflectionTarget while writing
        // it is a WebGL feedback loop even when the road branch is not taken.
        const capture = m.clone(); captureMaterials.push(capture); capture.setParameter('road',0);
        capture.setParameter('reflectionMap',white);
        const captureReceiver=/^RDP_/i.test(m.name)?cubeGroundLayer:captureLayer;
        captureReceiver.addMeshInstances([new pc.MeshInstance(mesh.mesh,capture,mesh.node)]);
        if (/^RDP_/i.test(m.name)) roads.push(mesh);
    }
    app.scene.layers.getLayerById(pc.LAYERID_WORLD).removeMeshInstances(roads);
    groundLayer.addMeshInstances(roads);

    // Capture the real exported street into six faces, as the game's EnvMapTex does.
    // Exclude the car from its own cube; this is not an HDRI or a PBR environment.
    const cube = new pc.Texture(device,{name:'EnvMapTex',width:128,height:128,cubemap:true,
        format:pc.PIXELFORMAT_RGBA8,srgb:false,mipmaps:true,anisotropy:device.maxAnisotropy,
        minFilter:pc.FILTER_LINEAR_MIPMAP_LINEAR,magFilter:pc.FILTER_LINEAR});
    const faces = [[1,0,0,0,-1,0],[-1,0,0,0,-1,0],[0,1,0,0,0,1],
        [0,-1,0,0,0,-1],[0,0,1,0,-1,0],[0,0,-1,0,-1,0]];
    const cubeCameras = faces.map((f,face) => {
        const e = new pc.Entity(`EnvMapTex face ${face}`);
        e.addComponent('camera',{...cameraOptions,fov:90,priority:-10+face,
            layers:[skyLayer.id,captureLayer.id,cubeGroundLayer.id],aspectRatioMode:pc.ASPECT_MANUAL,aspectRatio:1,renderTarget:new pc.RenderTarget({colorBuffer:cube,face,depth:true})});
        app.root.addChild(e); e.setPosition(carPosition.x,roadY+.9,carPosition.z);
        e.lookAt(carPosition.x+f[0],roadY+.9+f[1],carPosition.z+f[2],f[3],f[4],f[5]); return e;
    });
    // EnvMapTex contains reflected surface colour, not incident illumination.
    // Use nearby exported vertex lighting for ambient; the cube supplies direction.
    const ambient = [0,0,0]; let ambientWeight = 0;
    for (const render of street.findComponents('render')) for (const mesh of render.meshInstances) {
        const distance = mesh.aabb.center.distance(new pc.Vec3(-1.8,roadY+.9,10));
        if (distance > 35) continue;
        const colors = []; mesh.mesh.getColors(colors);
        const element = mesh.mesh.vertexBuffer.format.elements.find(e=>e.name===pc.SEMANTIC_COLOR);
        const scale = element.normalize && element.dataType===pc.TYPE_UINT8 ? 2/255 : 2;
        const weight = 1 / (1 + distance * distance);
        for (let i=0;i<colors.length;i+=4) {
            for (let c=0;c<3;c++) ambient[c] += colors[i+c]*scale*weight;
            ambientWeight += weight;
        }
    }
    if (!ambientWeight) throw new Error('Missing local street vertex lighting');
    for (let c=0;c<3;c++) ambient[c] /= ambientWeight;
    // Ten polynomial coefficients, same basis and half-scale convention as car.efx.
    const harmonic = new Float32Array(40);
    function projectLighting() {
        const pixels = new Uint8Array(128*128*4);
        const previous = device.getRenderTarget();
        let weight = 0;
        harmonic.fill(0);
        for (let face=0;face<6;face++) {
            device.setRenderTarget(cubeCameras[face].camera.renderTarget); device.updateBegin();
            device.readPixels(0,0,128,128,pixels); device.updateEnd();
            for (let y=2;y<128;y+=4) for (let x=2;x<128;x+=4) {
                const u=2*(x+.5)/128-1, v=2*(y+.5)/128-1;
                const dirs=[[1,-v,-u],[-1,-v,u],[u,1,v],[u,-1,-v],[u,-v,1],[-u,-v,-1]];
                const n=dirs[face], len=Math.hypot(...n), w=1/(len*len*len);
                const [nx,ny,nz]=n.map(a=>a/len);
                // Clamped-cosine SH convolution, expressed as car.efx's polynomial.
                const b=[.25-.078125*(3*nz*nz-1),.234375*(nx*nx-ny*ny),
                    -.234375*(nx*nx-ny*ny),.234375*(3*nz*nz-1),
                    .9375*nx*ny,.9375*nz*nx,.9375*ny*nz,.5*nx,.5*ny,.5*nz];
                const i=(y*128+x)*4; weight+=w;
                for(let k=0;k<10;k++) for(let c=0;c<4;c++) {
                    const value=c===3?Math.max(pixels[i],pixels[i+1],pixels[i+2])/255:pixels[i+c]/255;
                    harmonic[k*4+c]+=b[k]*value*w;
                }
            }
        }
        device.setRenderTarget(previous);
        for(let i=0;i<40;i++) harmonic[i]*=4/weight;
        harmonic.set([...ambient,Math.max(...ambient)],0);
        window.RN_B.lighting = { ambient: [...ambient], harmonic: Array.from(harmonic) };
        for(const m of carMaterials) m.setParameter('harmonic[0]',harmonic);
    }
    const carShader = new pc.ShaderMaterial({uniqueName:'NFSU_car_efx',attributes:{
        aPosition:pc.SEMANTIC_POSITION,aNormal:pc.SEMANTIC_NORMAL,aUv:pc.SEMANTIC_TEXCOORD0},
        vertexGLSL:`
        attribute vec3 aPosition;
        attribute vec3 aNormal;
        attribute vec2 aUv;
        uniform mat4 matrix_model;
        uniform mat4 matrix_viewProjection;
        uniform mat4 matrix_view;
        varying float viewDepth;
        uniform vec3 eye;
        uniform vec4 harmonic[10];
        uniform vec4 dmin;
        uniform vec4 drange;
        uniform vec3 smin;
        uniform vec3 srange;
        uniform float spower;
        uniform float epower;
        varying vec2 uv;
        varying vec4 diffuse;
        varying vec4 specular;
        varying vec3 reflected;
        vec4 lighting(vec3 n) {
            return harmonic[0]+harmonic[1]*n.x*n.x+harmonic[2]*n.y*n.y+
                harmonic[3]*n.z*n.z+harmonic[4]*n.x*n.y+harmonic[5]*n.z*n.x+
                harmonic[6]*n.y*n.z+harmonic[7]*n.x+harmonic[8]*n.y+harmonic[9]*n.z;
        }
        void main() {
            vec4 p=matrix_model*vec4(aPosition,1.0);
            viewDepth=-(matrix_view*p).z;
            vec3 n=normalize(mat3(matrix_model)*aNormal);
            vec3 view=normalize(eye-p.xyz);
            float nv=max(.01,dot(view,n));
            vec4 ds=dmin+nv*drange;
            diffuse=lighting(n)*ds; diffuse.a=ds.a; diffuse=clamp(diffuse*.5,0.0,1.0);
            reflected=2.0*nv*n-view;
            vec4 sh=lighting(reflected);
            specular.rgb=sh.rgb*pow(clamp(sh.a,0.0,1.0),spower)*
                (smin+pow(nv,spower)*srange)*.5;
            specular.rgb=clamp(specular.rgb,0.0,1.0);
            specular.a=pow(nv,epower);
            uv=aUv; gl_Position=matrix_viewProjection*p;
        }`,fragmentGLSL:`
        precision highp float;
        varying float viewDepth;
        #include "sceneTexturesPS"
        #ifdef PREPASS_PASS
            #include "floatAsUintPS"
        #endif
        uniform sampler2D diffuseMap;
        uniform samplerCube envMap;
        uniform vec3 emin;
        uniform vec3 erange;
        uniform float alphaRef;
        uniform float headlamp;
        varying vec2 uv;
        varying vec4 diffuse;
        varying vec4 specular;
        varying vec3 reflected;
        void main() {
            vec4 dc=texture2D(diffuseMap,uv)*clamp(diffuse,0.0,1.0);
            vec3 env=textureCube(envMap,reflected).rgb*2.0*(emin+specular.a*erange);
            vec4 result=2.0*dc;
            result.rgb+=2.0*dc.a*(clamp(specular.rgb,0.0,1.0)+2.0*env);
            if(result.a<=alphaRef) discard;
            #ifdef PREPASS_PASS
                gl_FragColor=float2vec4(viewDepth);
                return;
            #endif
            result.rgb=min(result.rgb,vec3(1.0));
            if(headlamp>.5) result.rgb=max(result.rgb,texture2D(diffuseMap,uv).rgb*1.65);
            gl_FragColor=result;
            writeSceneTextureDepth(viewDepth,1.0);
        }`});
    const metaResponse = await fetch(new URL('./car/car_meta.json',import.meta.url));
    if(!metaResponse.ok) throw new Error(`Car metadata HTTP ${metaResponse.status}`);
    const carMeta = await metaResponse.json();
    const {gameMaterials} = carMeta;
    const carContainer = await load(new URL('./car/car.glb',import.meta.url).href);
    const bindings = new Map(carContainer.data.gltf.materials.map(m=>[m.name,m.extras]));
    const car = carContainer.instantiateRenderEntity();
    app.root.addChild(car);
    const materialCache = new Map();
    for(const render of car.findComponents('render')) {
        render.layers=[carLayer.id];
        for(const mesh of render.meshInstances) {
            const original=mesh.material;
            let m=materialCache.get(original);
            if(!m) {
                const binding=bindings.get(original.name);
                const data=gameMaterials[binding.sourceMaterial];
                if(!data) throw new Error(`Missing original material ${binding.sourceMaterial}`);
                m=carShader.clone(); m.name=`car.efx ${original.name}`; m.cull=original.cull;
                for(const [key,value] of Object.entries(data)) m.setParameter(key,Array.isArray(value)?new Float32Array(value):value);
                m.setParameter('diffuseMap',rawMap(original.diffuseMap || original.emissiveMap || white));
                // 0x7070d4 scales SpecularPower at 0x40fae0; stock PC value is 1.1.
                m.setParameter('spower',data.spower*1.100000023841858);
                // The game overrides the window material alpha in 0x40c4b0.
                if(binding.alphaGrazing !== undefined) {
                    m.setParameter('dmin',new Float32Array([...data.dmin.slice(0,3),binding.alphaGrazing]));
                    m.setParameter('drange',new Float32Array([...data.drange.slice(0,3),binding.alphaFacing-binding.alphaGrazing]));
                }
                m.setParameter('headlamp',binding.sourceMaterial==='HEADLIGHTGLASS'?1:0);
                m.setParameter('envMap',cube); m.setParameter('harmonic[0]',harmonic);
                const blend=applyTextureState(m,binding.resolvedTexture);
                // Car slot 5 retains ZWRITE even when translucent (0x40f50c).
                m.depthWrite=true; m.sceneTexturesWrite=true;
                m.cull=blend ? pc.CULLFACE_BACK : pc.CULLFACE_NONE;
                materialCache.set(original,m); carMaterials.push(m);
            }
            mesh.material=m;
        }
    }
    car.setLocalPosition(carPosition); car.setLocalEulerAngles(0,145,0);
    const worldToCar = new pc.Mat4().invert(car.getWorldTransform());
    for (const m of [...worldMaterials,...captureMaterials]) m.setParameter('worldToCar',worldToCar.data);
    const corners=[];
    for (const x of [carMeta.bbox.min[0],carMeta.bbox.max[0]])
        for (const y of [carMeta.bbox.min[1],carMeta.bbox.max[1]])
            for (const z of [carMeta.bbox.min[2],carMeta.bbox.max[2]])
                corners.push(car.getWorldTransform().transformPoint(new pc.Vec3(x,y,z)));
    // Fit the complete exported bounds, including the rear bumper, at any aspect.
    // Fixed camera height: 1.0 m above the road, front three-quarter view.
    fitCamera = () => {
        let distance=8, yaw=0, pitch=0;
        const q=new pc.Quat(), forward=new pc.Vec3(), up=new pc.Vec3();
        const carCenter=new pc.Vec3(carPosition.x,roadY+.67,carPosition.z);
        const aspect=device.width/device.height;
        const widthGoal=.40;
        const projection=new pc.Mat4().setPerspective(camera.camera.fov,aspect,.1,650);
        const view=new pc.Mat4(), vp=new pc.Mat4();
        let bounds;
        camera.camera.aspectRatio=aspect; reflection.camera.aspectRatio=aspect;
        for(let i=0;i<12;i++) {
            camera.setPosition(carPosition.x-distance*.10,roadY+1.0,carPosition.z-distance);
            camera.lookAt(carCenter);
            q.setFromEulerAngles(pitch,yaw,0); camera.setRotation(camera.getRotation().clone().mul(q));
            view.invert(camera.getWorldTransform()); vp.mul2(projection,view);
            const points=corners.map(p=>vp.transformVec4(new pc.Vec4(p.x,p.y,p.z,1)));
            const xs=points.map(p=>(p.x/p.w+1)*.5), ys=points.map(p=>(1-p.y/p.w)*.5);
            const lo=Math.min(...xs), hi=Math.max(...xs), top=Math.min(...ys), bottom=Math.max(...ys);
            const w=hi-lo, cx=(lo+hi)*.5, cy=(top+bottom)*.5;
            bounds={left:lo,right:hi,top,bottom,width:w};
            // Camera's local +x points screen-right; yaw/pitch correct composition.
            yaw -= (cx-(.70))*camera.camera.fov*aspect*.65;
            pitch -= (cy-.72)*camera.camera.fov*.65;
            distance *= Math.max(.85,Math.min(1.15,w/widthGoal));
        }
        window.RN_B.framing=bounds;
        reflection.setPosition(camera.getPosition().x,2*roadY-camera.getPosition().y,camera.getPosition().z);
        forward.copy(camera.forward); up.copy(camera.up);
        sky.setPosition(camera.getPosition());
        forward.y=-forward.y; up.y=-up.y;
        reflection.lookAt(reflection.getPosition().clone().add(forward),up);
        reflectedView.invert(reflection.getWorldTransform());
        reflectedVP.mul2(reflection.camera.projectionMatrix,reflectedView);
        const eye=new Float32Array([camera.getPosition().x,camera.getPosition().y,camera.getPosition().z]);
        for(const m of carMaterials) m.setParameter('eye',eye);
    };
    fitCamera();
    function update() {
        for(const m of worldMaterials) {
            m.setParameter('reflectionVP',reflectedVP.data);
            m.setParameter('reflectionMap',reflectionTarget.colorBuffer);
        }
    }
    update(); app.on('update',update);
    app.on('frameend',()=>{if(reflectionFrames>0 && --reflectionFrames===0) reflection.enabled=false;});
    app.once('frameend',()=>{
        projectLighting();for(const e of cubeCameras)e.enabled=false;
        app.once('frameend',()=>{
            Object.assign(window.RN_B,{ready:true,track:'street.glb',wet_road_meshes:roads.length,
                ms_to_first_frame:Math.round(performance.now()-started),
                render_size:[device.width,device.height],
                polish:{antialiasing:'PlayCanvas TAA',exposure:1.25,bloom:'emissive-only, threshold 1.15',camera_height_m:1.0,
                    anisotropy:device.maxAnisotropy,mipmaps:true},
                fidelity_limits:['SH ambient from local baked lighting; directional terms from street cube, not live game coefficients']});
            status.hidden=true;
        });
    });
    app.start();
}
main().catch(error=>{
    window.RN_B={ready:false,error:error.message};status.hidden=false;
    status.textContent=`SCENE B · ${error.message}`;console.error('[RN_B]',error);
});
