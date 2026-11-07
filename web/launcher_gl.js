/* NFSU launcher scene (v2): one WebGL2 canvas, no libraries. Exposes window.RN_SCENE (contract: build/launcher_ref/CONTRACT.md).
 *
 * Pipeline per frame (all in gamma space, PS2-style):
 *   scene    plate displaced by its depth map (iterative parallax), car plane + wet reflection + contact shadow, near occluders,
 *            region-driven neon flicker, passing-car headlight sweep, steam, rain layers, splashes -> RGBA16F (alpha = depth)
 *   dof      gather blur by |depth - focus| (rack focus)
 *   bloom    bright pass -> 3 levels (320x180, 160x90, 80x45), 7-tap separable blurs
 *   composite  50 % bloom, light spill on surfaces, lens dirt + lens drops lit by bloom, chromatic aberration, grade, grain, interlace, vignette
 * Assets (web/launcher/v2/): plate, plate_depth, plate_emissive, car, car_lights, fg_left, fg_top, steam,
 * lens_dirt, raindrops (.webp). Any missing optional layer is skipped; depth and emissive are generated in code when missing.
 */
(function () {
  'use strict';

  // ---- tunables (plate-uv units: x 0..1 over plate width, y 0..1 over plate height, top-down) ----
  const CFG = {
    horizon: 0.46,        // screen y of the vanishing line in the plate
    groundK: 1.0,         // ground depth at the bottom edge (depth is disparity-like: d = k * (y - horizon) / (1 - horizon))
    carCX: 0.625,         // car sprite: alpha bbox centre x, bottom y, width as a fraction of the plate width
    carBottom: 0.905,
    carWidth: 0.45,
    carContact: [0.455, 0.97, 0.86, 0.707], // car.png ground line in alpha-bbox units: front wheel bottom -> rear wheel bottom (x,y,x,y)
    carDepthBias: -0.02,  // car plane depth relative to the ground depth under its wheels
    steamPos: [0.165, 0.862], // manhole (plate uv)
    baseZoom: 1.06,       // overscan so parallax never shows the plate border
    introSecs: 2.5,
    maxPixels: 1.8e6,
    maxScale: 1.5,
    fpsCap: 60,
    portraitZoom: 0.52,    // phone portrait: total zoom (the plate no longer fills the height; the rest fades to black)
    portraitCarY: 0.32,   // phone portrait: screen y of the car's middle (the menu panel owns the lower half)
  };
  const DPR_CAP = () => Math.min(window.devicePixelRatio || 1, CFG.maxScale);

  // ---- small utils ----
  const clamp = (x, a, b) => (x < a ? a : x > b ? b : x);
  const lerp = (a, b, t) => a + (b - a) * t;
  const smooth01 = (x) => { x = x < 0 ? 0 : x > 1 ? 1 : x; return x * x * (3 - 2 * x); };
  function bezier(x1, y1, x2, y2) {            // CSS cubic-bezier
    const cx = 3 * x1, bx = 3 * (x2 - x1) - cx, ax = 1 - cx - bx;
    const cy = 3 * y1, by = 3 * (y2 - y1) - cy, ay = 1 - cy - by;
    return function (x) {
      if (x <= 0) return 0; if (x >= 1) return 1;
      let t = x;
      for (let i = 0; i < 6; i++) {
        const e = ((ax * t + bx) * t + cx) * t - x;
        const d = (3 * ax * t + 2 * bx) * t + cx;
        if (Math.abs(e) < 1e-5 || Math.abs(d) < 1e-6) break;
        t -= e / d;
      }
      t = clamp(t, 0, 1);
      return ((ay * t + by) * t + cy) * t;
    };
  }
  const easeIntro = bezier(0.16, 1, 0.3, 1);
  const easeScreen = bezier(0.25, 0.8, 0.25, 1);
  const easeInOut = bezier(0.65, 0, 0.35, 1);
  function hash1(n) { const s = Math.sin(n * 127.1) * 43758.5453; return s - Math.floor(s); }
  function vnoise(x) { const i = Math.floor(x), f = x - i, u = f * f * (3 - 2 * f); return lerp(hash1(i), hash1(i + 1), u); }
  function smoothNoise(x, seed) { return (vnoise(x + seed * 17.3) * 0.65 + vnoise(x * 2.3 + seed * 5.1 + 3.7) * 0.35) * 2 - 1; } // -1..1, smooth

  // ---- shaders ----
  const VS = `#version 300 es
void main(){ vec2 p=vec2(float((gl_VertexID<<1)&2), float(gl_VertexID&2)); gl_Position=vec4(p*2.0-1.0,0.0,1.0); }`;

  const HDR = `#version 300 es
precision highp float; precision highp sampler2D;
float hash11(float p){ p=fract(p*.1031); p*=p+33.33; p*=p+p; return fract(p); }
float hash21(vec2 p){ vec3 p3=fract(vec3(p.xyx)*.1031); p3+=dot(p3,p3.yzx+33.33); return fract((p3.x+p3.y)*p3.z); }
float vnoise(float x){ float i=floor(x), f=fract(x); f=f*f*(3.-2.*f); return mix(hash11(i),hash11(i+1.),f); }
float vn2(vec2 p){ vec2 i=floor(p), f=fract(p); f=f*f*(3.-2.*f);
  return mix(mix(hash21(i),hash21(i+vec2(1,0)),f.x), mix(hash21(i+vec2(0,1)),hash21(i+vec2(1,1)),f.x), f.y); }
float lum(vec3 c){ return dot(c, vec3(.299,.587,.114)); }
`;

  const FS_SCENE = HDR + `
uniform sampler2D uPlate,uDepth,uEmis,uRegion,uCar,uCarL,uFgL,uFgT,uSteamT,uKind;
uniform vec2 uRes;
uniform float uT,uIntro,uTint,uFlash,uPulse,uSteamLum,uDbg,uPortrait,uHasKind;
uniform vec4 uView;     // centre.xy, visible size.xy (plate uv)
uniform vec4 uCam;      // parallax cam.xy, dolly, plate aspect
uniform vec4 uHas;      // car, carLights, fgLeft, fgTop
uniform vec4 uCarRect, uCarBB, uCarLine, uFgLRect, uFgTRect;   // uCarLine: ground contact line a.xy -> b.zw (plate uv)
uniform vec4 uPass;     // passing car: x, y, dir, envelope
uniform vec2 uPass2;    // headlight weight, tail weight
uniform vec4 uGround;   // horizon, groundK, car depth, rain amount
uniform vec4 uSteamP;   // x, y, hasSteam, 0
uniform vec4 uHL1, uHL2;  // the two headlamps (plate uv)
out vec4 oC;

#define ASP uCam.w
float dG(float y){ return clamp((y-uGround.x)/(1.0-uGround.x),0.,1.)*uGround.y; }
float yG(float d){ return uGround.x + d*(1.0-uGround.x)/uGround.y; }
vec2 camUV(vec2 s,float d){
  float mag=1.0-uCam.z*0.085*(0.25+d);
  vec2 p=uView.xy+(s-0.5)*uView.zw/mag;
  p+=uCam.xy*(d-0.45);
  return p;
}
float dAt(vec2 q){ return textureLod(uDepth,q,1.2).r; }

// ---- light state per region: (flicker * strike-on), decoded from the region map ----
float strikeOn(float t0){
  float x=uIntro-t0; if(x<0.) return 0.;
  if(x<0.45) return hash11(floor(x*18.)+t0*13.7)>0.42 ? 1.0 : 0.12;
  return 1.0;
}
float lightState(vec4 R, float tw){
  float id=floor(R.r*255.0/5.0+0.5), cat=floor(R.g*255.0/60.0+0.5), rank=R.b;
  float h=hash11(id*7.13+1.7);
  float f=1.0, t0;
  if(cat<0.5){            // windows, small steady lights: slow breath
    f=1.0+0.06*(vnoise(tw*0.4+h*40.)-0.5); t0=0.45+0.9*rank;
  } else if(cat<1.5){     // sodium lamp: buzz + rare dip
    float buzz=(vnoise(tw*41.+h*50.)-0.5)*0.10 + (vnoise(tw*9.+h*9.)-0.5)*0.08;
    float g=vnoise(tw*0.42+h*33.);
    float dip=smoothstep(0.84,0.94,g)*(0.25+0.6*step(0.5,vnoise(tw*27.+h*5.)));
    f=1.0+buzz-dip; t0=0.04+0.4*rank;
  } else if(cat<2.5){     // neon: slow wander, stutter + dropout
    float n=vnoise(tw*(1.1+h)+h*30.);
    f=0.90+0.20*n+0.03*(vnoise(tw*23.+h*3.)-0.5);
    float g=vnoise(tw*0.33+h*91.);
    float drop=smoothstep(0.80,0.88,g);
    float st=step(0.5,vnoise(tw*29.+h*7.));
    f*=mix(1.0, 0.08+0.92*st, drop);
    t0=0.2+0.9*rank;
  } else {                // large warm spill (garage): gentle, lights late
    f=1.0+0.05*(vnoise(tw*0.7+h*20.)-0.5)+0.03*(vnoise(tw*13.)-0.5); t0=1.25;
  }
  return f*strikeOn(t0);
}

// ---- rain splashes / ripples on the ground: xy = uv offset, z = ring brightness ----
vec3 ripples(vec2 q){
  float y=q.y-uGround.x;
  if(y<0.03) return vec3(0.);
  float z=1.0/(y+0.02);
  vec2 gp=vec2((q.x-0.5)*ASP*z*0.5, z);
  vec3 res=vec3(0.);
  for(int k=0;k<2;k++){
    float sc=(k==0)?4.0:9.0;
    vec2 g=gp*sc+vec2(float(k)*17.3, float(k)*5.7);
    vec2 id=floor(g), f=fract(g);
    float h=hash21(id+float(k)*31.), h2=hash21(id.yx+7.7);
    float per=0.8+0.9*h2;
    float life=fract(uT/per+h);
    float live=step(0.5,hash21(id+3.1));
    vec2 c=0.3+0.4*vec2(h,h2);
    vec2 dv=f-c; float r=length(dv);
    float ring=exp(-pow((r-life*0.28)/0.02,2.0))*pow(1.0-life,2.0)*live;
    res.xy+=dv/(r+1e-3)*ring*0.0045;
    res.z+=ring;
  }
  return res*smoothstep(0.03,0.2,y);
}

// ---- passing car light: cone on walls (stronger on near surfaces), via albedo multiply ----
vec3 passLight(vec2 q,float d,float tk){
  if(uPass.w<=0.001) return vec3(0.);
  vec2 r=q-uPass.xy; r.x*=ASP;
  float al=r.x*uPass.z;
  float ah=max(al,0.);
  float spread=0.05+ah*0.6;
  float yc=-0.02-ah*0.075;
  float vert=exp(-pow((r.y-yc)/spread,2.0));
  float fwd=smoothstep(-0.05,0.06,al)*exp(-ah/0.6);
  float dg=mix(0.2,1.7,d*d);
  vec3 L=vec3(1.0,0.84,0.58)*uPass2.x*fwd*vert*dg*1.7;
  float bl=max(-al,0.);
  L+=tk*vec3(1.0,0.10,0.07)*uPass2.y*smoothstep(0.0,0.04,bl)*exp(-bl/0.16)*exp(-pow(r.y/0.06,2.0))*dg*1.2;
  return L*uPass.w;
}
// bright sources + anamorphic streak + wet ground streaks
vec3 passSrc(vec2 q,float ground){
  if(uPass.w<=0.001) return vec3(0.);
  vec2 r=q-uPass.xy; r.x*=ASP;
  float dir=uPass.z;
  vec3 c=vec3(0.);
  vec2 hp=r-vec2(0.012*dir*0.0,0.0);
  float hd=length(vec2(hp.x,(hp.y+0.0)*1.0));
  c+=vec3(1.0,0.92,0.75)*uPass2.x*(exp(-hd*hd/0.00003)*3.0+exp(-hd*hd/0.0008)*0.6+exp(-pow(hp.y/0.0035,2.0))*exp(-abs(hp.x)/0.18)*0.7);
  vec2 tp=r+vec2(0.075*dir,0.0);
  float td=length(tp);
  c+=vec3(1.0,0.08,0.05)*uPass2.y*(exp(-td*td/0.00004)*2.2+exp(-td*td/0.001)*0.5+exp(-pow(tp.y/0.004,2.0))*exp(-abs(tp.x)/0.12)*0.5);
  if(ground>0.0){
    float dy=q.y-uPass.y;
    float sx=exp(-pow(r.x/(0.05+dy*0.2),2.0));
    float sy=smoothstep(0.0,0.02,dy)*exp(-dy/0.22);
    c+=vec3(1.0,0.82,0.55)*uPass2.x*sx*sy*0.9;
    float tx=exp(-pow((r.x+0.075*dir)/(0.04+dy*0.15),2.0));
    c+=vec3(1.0,0.1,0.06)*uPass2.y*tx*sy*0.8;
  }
  return c*uPass.w;
}

// ---- rain streak layer: screen-space, slanted, motion-blurred tail, lit by local light ----
float rainLayer(vec2 s,float cols,float rows,float speed,float len,float dens,float wid,float seed,float slant){
  vec2 p=vec2(s.x*uRes.x/uRes.y+s.y*slant, s.y);
  float cx=floor(p.x*cols);
  float lx=fract(p.x*cols);
  float hc=hash21(vec2(cx,seed));
  float v=p.y*rows - uT*speed*(0.75+0.5*hc) + hc*23.0;
  float cy=floor(v), fv=fract(v);
  float hr=hash21(vec2(cx,cy)+seed*3.1);
  float present=step(1.0-dens,hr);
  float c=0.5+(hash21(vec2(cx,cy+9.))-0.5)*0.5;
  float start=hash21(vec2(cx+4.,cy))*(1.0-len);
  float f=(fv-start)/len;
  float prof=(f>0.&&f<1.)? f*f : 0.;
  float w=exp(-pow((lx-c)/wid,2.0));
  return present*prof*w;
}

void main(){
  vec2 fc=gl_FragCoord.xy;
  vec2 s=vec2(fc.x/uRes.x, 1.0-fc.y/uRes.y);   // top-down screen uv
  float T=uT;
  float amb=mix(0.2,1.0,smoothstep(0.0,2.3,uIntro));
  amb=amb*amb*(3.0-2.0*amb)*0.4+amb*0.6;

  // ---- plate: iterative parallax against the depth map; at a depth jump fall back to the far side ----
  vec2 q=camUV(s,0.45); float d=dAt(q);
  vec2 q1=camUV(s,d); float d1=dAt(q1);
  vec2 q2=camUV(s,d1); float d2=dAt(q2);
  vec2 q3=camUV(s,d2); float d3=dAt(q3);
  float df=mix(d3,min(d3,d2),smoothstep(0.03,0.09,abs(d3-d2)));
  q=clamp(camUV(s,df),0.001,0.999);
  float dp=dAt(q);

  vec2 q0=camUV(s,0.45); vec2 pgx=dFdx(q0), pgy=dFdy(q0);
  vec3 a=textureGrad(uPlate,q,pgx,pgy).rgb;
  vec3 E=textureGrad(uEmis,q,pgx,pgy).rgb;
  vec4 R=texture(uRegion,q);
  float m=clamp(max(E.r,max(E.g,E.b))*1.5,0.,1.);
  float fl=lightState(R,T);
  vec3 col=a*amb;
  col*=mix(1.0,fl,m);
  vec3 kd=texture(uKind,q).rgb;
  float kg=(uHasKind>0.5)?mix(0.8,kd.r*0.6+kd.g*0.85+kd.b*0.6,step(0.15,max(kd.r,max(kd.g,kd.b)))):1.0;   // windows / neon / lamps: capped bloom per kind
  col+=E*fl*0.5*kg*smoothstep(0.1,0.7,uIntro+m);

  // ground: wet, rippled reflection of the lights (screen-space march along the depth map)
  vec2 qraw=camUV(s,df);
  float inM=mix(1.0,smoothstep(-0.01,0.06,min(min(qraw.x,1.-qraw.x),min(qraw.y,1.-qraw.y))),uPortrait);
  float dg=dG(q.y);
  float gnd=(q.y>uGround.x+0.01)?(1.0-smoothstep(0.05,0.16,abs(dp-dg))):0.0;
  gnd*=inM;
  vec3 rip=ripples(q);
  vec3 localLight=textureLod(uEmis,q,5.5).rgb;
  if(gnd>0.01){
    vec3 acc=vec3(0.);
    vec2 qr=q+vec2(rip.x, rip.y*0.5)+vec2((vnoise(q.y*90.+T*1.3)-0.5)*0.0035,0.);
    for(int i=1;i<=10;i++){
      float u=float(i)/10.0;
      float so=u*u*0.5;
      vec2 qs=vec2(qr.x,q.y-so);
      if(qs.y<0.0) break;
      float ds=textureLod(uDepth,qs,1.5).r;
      vec3 es=textureLod(uEmis,qs,1.0+u*1.5).rgb;
      float ms=max(es.r,max(es.g,es.b));
      float stands=smoothstep(0.02,0.1,ds-dG(qs.y)) + step(0.3,ms)*0.6;
      float pred=2.0*yG(ds)-qs.y;
      float w=exp(-pow((q.y-pred)/0.03,2.0))*clamp(stands,0.,1.);
      vec4 Rs=texture(uRegion,qs);
      acc+=es*w*lightState(Rs,T)/(1.0+u*1.2);
    }
    float fres=smoothstep(uGround.x,uGround.x+0.35,q.y);
    col+=acc*gnd*0.42*(0.5+0.5*fres)*smoothstep(0.6,2.0,uIntro+0.3);
    col+=rip.z*gnd*(0.05+localLight*1.6)*0.8;
  }

  // contact shadow + underglow pool (animated) along the car's ground line
  vec2 la=uCarLine.xy*vec2(ASP,1.), lb=uCarLine.zw*vec2(ASP,1.);
  vec2 lp=q*vec2(ASP,1.);
  vec2 lab=lb-la; float lt=clamp(dot(lp-la,lab)/dot(lab,lab),-0.55,1.45);
  float segD=length(lp-(la+lab*clamp(lt,-0.25,1.25)));
  float ell=exp(-pow(segD/0.028,2.0))*0.75+exp(-pow(segD/0.075,2.0))*0.35;
  vec2 pc=la+lab*0.52; vec2 pr=lp-pc; vec2 ax=normalize(lab); vec2 ay=vec2(-ax.y,ax.x);
  float pool=exp(-(pow(dot(pr,ax)/(length(lab)*0.78),2.0)+pow(dot(pr,ay)/0.11,2.0)));
  vec3 poolC=mix(vec3(1.0,0.22,0.62),vec3(0.15,0.65,1.0),clamp(0.5+0.5*uTint+0.25*sin(T*0.35),0.,1.));
  poolC=mix(poolC,vec3(1.0,0.5,0.2),clamp(-uTint,0.,1.)*0.35);
  if(uHas.x>0.5){
    col*=1.0-clamp(ell,0.,0.85)*smoothstep(0.0,0.3,uIntro)*(0.35+0.65*gnd);
    col+=poolC*pool*(0.30+0.14*sin(T*0.9)+0.06*uPulse)*smoothstep(1.4,1.9,uIntro)*(0.4+0.6*gnd);
  }

  // haze by depth, lit by nearby lights
  float hz=pow(clamp(1.0-dp,0.,1.),1.8);
  col=mix(col,vec3(0.035,0.06,0.10)*amb+localLight*0.5*amb,hz*0.22);
  col+=hz*textureLod(uEmis,q,5.0).rgb*0.55*amb;

  // passing car light on plate (multiplies albedo; stronger near) + sources
  vec3 PL=passLight(q,dp,1.0);
  col+=a*amb*PL*3.2+PL*0.07;

  // steam from the manhole (sprites rising, lit by the lamp)
  float dS=dG(uSteamP.y);
  vec2 qS=camUV(s,dS);
  if(uSteamP.z>0.5){
    vec3 lampL=textureLod(uEmis,uSteamP.xy+vec2(0.0,-0.3),5.5).rgb;
    for(int i=0;i<4;i++){
      float ph=fract(T/11.0+float(i)*0.25);
      float hh=0.075+ph*0.12;                          // plume height (plate v)
      vec2 pos=vec2(uSteamP.x+(vnoise(T*0.15+float(i)*9.)-0.5)*0.035+ph*0.012, uSteamP.y+0.012-ph*0.035);
      vec2 uvp=vec2(0.5+(qS.x-pos.x)*ASP/(hh*0.85), 1.0-(pos.y-qS.y)/hh);
      if(uvp.x<0.||uvp.x>1.||uvp.y<0.||uvp.y>1.) continue;
      vec4 st=textureGrad(uSteamT,uvp,dFdx(qS)*vec2(ASP,1.)/hh,dFdy(qS)*vec2(ASP,1.)/hh);
      float sa=(uSteamLum>0.5)? st.r*st.a : st.a;
      float al=sa*sin(3.14159*ph)*0.55;
      vec3 sc=vec3(0.28,0.33,0.42)*amb+vec3(1.0,0.62,0.30)*(0.1+lampL*2.0)*amb;
      sc+=PL*0.6;
      col=mix(col,sc*1.05,al*smoothstep(0.7,1.5,uIntro));
    }
  }

  col*=inM;
  float outD=dp;

  // ---- car plane ----
  float dCar=uGround.z;
  vec2 qc=camUV(s,dCar);
  vec2 cuA=(qc-uCarRect.xy)/uCarRect.zw; vec2 cgx=dFdx(cuA), cgy=dFdy(cuA);
  float carA=0.;
  if(uHas.x>0.5){
    // reflection on the wet ground: the sprite mirrored about its own ground line, stretched, smeared, rippled
    float lineY=uCarLine.y+(uCarLine.w-uCarLine.y)*(qc.x-uCarLine.x)/(uCarLine.z-uCarLine.x);
    lineY=min(lineY,uCarBB.w+0.004);
    float below=qc.y-lineY;
    if(gnd>0.01 && below>-0.006){
      vec2 rr=vec2(rip.x*1.8+(vnoise(qc.y*70.+T*1.1)-0.5)*0.004, rip.y);
      float acc=0.; vec3 rc=vec3(0.);
      for(int k=0;k<5;k++){
        float kk=float(k)/4.0;
        float my=lineY-max(below,0.)*(1.15-0.3*kk);
        vec2 cu=vec2((qc.x+rr.x-uCarRect.x)/uCarRect.z,(my+rr.y*0.5+kk*0.012-uCarRect.y)/uCarRect.w);
        if(cu.x>0.&&cu.x<1.&&cu.y>0.&&cu.y<1.){ vec4 cs=textureGrad(uCar,cu,cgx,cgy*2.0); rc+=cs.rgb; acc+=cs.a; }
      }
      float fade=exp(-max(below,0.)/0.16)*smoothstep(-0.006,0.012,below);
      col=col*(1.0-0.45*clamp(acc*0.2,0.,1.)*fade)+rc*0.2*fade*0.95*amb*gnd;
    }
    vec2 cu=cuA;
    if(cu.x>0.&&cu.x<1.&&cu.y>0.&&cu.y<1.){
      vec4 cs=textureGrad(uCar,cu,cgx,cgy);
      float front=smoothstep(dp-0.02,dp+0.08,dCar+0.1);   // plate pixels nearer than the car hide it
      float ca=cs.a*front; carA=ca;
      vec3 cl=cs.rgb*amb*(0.9+0.1*fl);
      vec3 PLc=passLight(qc,dCar,0.0);
      cl+=cs.rgb*PLc*2.0*amb;
      // light from the underglow pool onto the lower body
      cl+=poolC*cs.a*smoothstep(0.55,1.0,cu.y)*0.12*(0.6+0.4*sin(T*0.9))*amb;
      if(uHas.y>0.5){
        vec4 ls=textureGrad(uCarL,cu,cgx,cgy);
        float on=smoothstep(1.55,1.75,uIntro)*(0.92+0.08*vnoise(T*3.0));
        cl+=ls.rgb*on*(1.1+2.2*uFlash);
      }
      col=cl*front+col*(1.0-ca);
      outD=mix(outD,dCar,ca);
    }
  }

  // sources of the passing car on top of everything behind the near layers
  col+=passSrc(q,gnd)*(1.0-carA*0.97);   // the passing car is behind the parked one: its glow never paints the paint

  // ---- rain: far/mid layers hidden by nearer surfaces; lit by local light ----
  float rainAmt=uGround.w;
  if(rainAmt>0.0){
    vec3 rainL=vec3(0.30,0.38,0.52)*0.6*amb;
    vec3 lp=textureLod(uEmis,q,4.0).rgb;
    vec3 rcol=rainL+lp*2.2+passLight(q,dp,0.0)*0.8;
    vec2 pr=uCam.xy;
    float far=rainLayer(s+pr*0.2,70.0,7.0,3.2,0.45,0.30,0.10,3.0,0.10);
    float mid=rainLayer(s+pr*0.45,38.0,4.2,4.4,0.55,0.26,0.13,11.0,0.12);
    float vf=smoothstep(0.1,0.28,0.25+0.4-dp*0.8+0.2*0.0);  // far rain only where the plate is far
    vf=1.0-smoothstep(0.30,0.55,dp);
    float vm=1.0-smoothstep(0.62,0.9,dp);
    col+=rcol*far*0.9*max(vf,0.12)*rainAmt;
    col+=rcol*mid*1.15*max(vm,0.2)*rainAmt;
    // near: big, blurred and fast, in front of the car
    float near=rainLayer(s+pr*1.2,16.0,2.6,7.0,0.7,0.20,0.16,23.0,0.14);
    vec3 nl=rainL*1.3+textureLod(uEmis,q,6.0).rgb*3.0+PL;
    col+=nl*near*0.75*rainAmt;
    outD=mix(outD,0.93,clamp(near*0.5,0.,0.6));
  }

  // ---- near occluders ----
  if(uHas.z>0.5){
    vec2 qf=camUV(s,0.97);
    vec2 fu=(qf-uFgLRect.xy)/uFgLRect.zw;
    vec2 fgx=dFdx(fu), fgy=dFdy(fu);
    if(fu.x>0.&&fu.x<1.&&fu.y>0.&&fu.y<1.){
      vec4 f=textureGrad(uFgL,fu,fgx,fgy);
      vec3 fc2=f.rgb*(amb*0.95)+f.rgb*passLight(qf,0.97,0.0)*1.5*amb+f.rgb*textureLod(uEmis,qf,5.0).rgb*0.4;
      col=fc2+col*(1.0-f.a);
      outD=mix(outD,0.97,f.a);
    }
  }
  if(uHas.w>0.5){
    vec2 qf=camUV(s,0.92);
    vec2 fu=(qf-uFgTRect.xy)/uFgTRect.zw;
    vec2 fgx=dFdx(fu), fgy=dFdy(fu);
    if(fu.x>0.&&fu.x<1.&&fu.y>0.&&fu.y<1.){
      vec4 f=textureGrad(uFgT,fu,fgx,fgy);
      // the red signal lamp keeps glowing: its red pixels are emissive
      float red=clamp((f.r-max(f.g,f.b)-0.25)*3.0,0.,1.);
      vec3 fc2=f.rgb*amb*0.8+f.rgb*passLight(qf,0.92,0.0)*1.2*amb+vec3(1.0,0.12,0.08)*red*f.a*0.3*smoothstep(0.7,1.1,uIntro)*(0.9+0.1*vnoise(T*7.));
      col=fc2+col*(1.0-f.a);
      outD=mix(outD,0.92,f.a);
    }
  }

  // confirm flash: the two headlamps burn white-hot (core + halo + anamorphic streak); the car stays readable
  if(uFlash>0.0){
    float mag=1.0-uCam.z*0.085*(0.25+dCar);
    float asp=uRes.x/uRes.y;
    for(int i=0;i<2;i++){
      vec2 hp=(i==0)?uHL1.xy:uHL2.xy;
      vec2 sl=(hp-uCam.xy*(dCar-0.45)-uView.xy)*mag/uView.zw+0.5;
      vec2 dv=(s-sl)*vec2(asp,1.0);
      float rd2=dot(dv,dv);
      float core=exp(-rd2/0.00016)*2.0+exp(-rd2/(0.0012+0.0015*uFlash))*0.6;
      float streak=exp(-pow(dv.y/0.004,2.0))*exp(-abs(dv.x)/0.25)*0.9+exp(-pow(dv.x/0.004,2.0))*exp(-abs(dv.y)/0.07)*0.25;
      col+=vec3(1.0,0.93,0.78)*uFlash*(core+streak);
    }
  }
  if(uDbg>0.5){ if(uDbg<1.5) col=a; else if(uDbg<2.5) col=vec3(dp); else if(uDbg<3.5) col=E; else if(uDbg<4.5) col=R.rgb; else if(uDbg<5.5) col=vec3(gnd); else if(uDbg<6.5) col=texture(uPlate,s).rgb; else if(uDbg<7.5) col=vec3(q,0.); else col=vec3(uView.xy,uCam.w*0.5); }
  oC=vec4(col,outD);
}
`;

  const FS_DOF = HDR + `
uniform sampler2D uScene; uniform vec2 uRes; uniform float uFocus,uAmt,uMaxR,uT;
out vec4 oC;
float cocOf(float d){ float x=d-uFocus; return clamp(abs(x)*(x>0.?1.7:1.3)-0.05,0.,1.)*uAmt; }
void main(){
  vec2 uv=gl_FragCoord.xy/uRes;
  vec4 c=texture(uScene,uv);
  float R=cocOf(c.a)*uMaxR;
  if(R<0.5){ oC=vec4(c.rgb,1.); return; }
  float rot=hash21(gl_FragCoord.xy+fract(uT)*13.)*6.2831;
  vec3 acc=c.rgb; float ws=1.0;
  for(int i=0;i<16;i++){
    float r=sqrt((float(i)+0.5)/16.0);
    float ang=float(i)*2.39996+rot;
    vec2 o=vec2(cos(ang),sin(ang))*r*R;
    vec4 t=texture(uScene,uv+o/uRes);
    float ct=cocOf(t.a)*uMaxR;
    float w=clamp(ct-r*R+1.0,0.,1.)*(1.0+3.0*smoothstep(0.8,2.0,lum(t.rgb)));
    acc+=t.rgb*w; ws+=w;
  }
  oC=vec4(acc/ws,1.);
}`;

  const FS_BRIGHT = HDR + `
uniform sampler2D uSrc; uniform vec2 uTexel; out vec4 oC;
void main(){
  vec2 uv=gl_FragCoord.xy*uTexel;
  vec3 c=vec3(0.);
  // 4-tap box over the (4x bigger) source
  vec2 o=uTexel*1.5;
  c+=texture(uSrc,uv+vec2(-o.x,-o.y)).rgb; c+=texture(uSrc,uv+vec2(o.x,-o.y)).rgb;
  c+=texture(uSrc,uv+vec2(-o.x,o.y)).rgb; c+=texture(uSrc,uv+vec2(o.x,o.y)).rgb;
  c*=0.25;
  float l=max(c.r,max(c.g,c.b));
  c*=1.0/(1.0+0.5*max(l-1.3,0.));    // cap the hottest sources so no single lamp owns the bloom
  oC=vec4(c*smoothstep(0.55,1.15,l),1.);
}`;
  const FS_DOWN = HDR + `
uniform sampler2D uSrc; uniform vec2 uTexel; out vec4 oC;
void main(){
  vec2 uv=gl_FragCoord.xy*uTexel; vec2 o=uTexel*0.5;
  oC=vec4((texture(uSrc,uv+vec2(-o.x,-o.y)).rgb+texture(uSrc,uv+vec2(o.x,-o.y)).rgb+texture(uSrc,uv+vec2(-o.x,o.y)).rgb+texture(uSrc,uv+vec2(o.x,o.y)).rgb)*0.25,1.);
}`;
  // 7-tap separable blur
  const FS_BLUR = HDR + `
uniform sampler2D uSrc; uniform vec2 uDir; uniform vec2 uTexel; out vec4 oC;
void main(){
  vec2 uv=gl_FragCoord.xy*uTexel;
  vec3 c=texture(uSrc,uv).rgb*0.2270;
  c+=(texture(uSrc,uv+uDir*uTexel*1.4).rgb+texture(uSrc,uv-uDir*uTexel*1.4).rgb)*0.3162;
  c+=(texture(uSrc,uv+uDir*uTexel*3.3).rgb+texture(uSrc,uv-uDir*uTexel*3.3).rgb)*0.0703;
  c+=(texture(uSrc,uv+uDir*uTexel*5.2).rgb+texture(uSrc,uv-uDir*uTexel*5.2).rgb)*0.0162;
  oC=vec4(c*1.02,1.);
}`;

  const FS_COMP = HDR + `
uniform sampler2D uScene,uB1,uB2,uB3,uDirt,uDrops;
uniform vec2 uRes; uniform vec4 uView;
uniform float uT,uFade,uTint,uHasDirt,uHasDrops,uBloom,uFlash;
out vec4 oC;
vec3 shoulder(vec3 c){ vec3 k=max(c-0.72,0.); return min(c,vec3(0.72))+0.28*(1.0-exp(-k/0.28)); }
void main(){
  vec2 uv=gl_FragCoord.xy/uRes;
  vec2 dv=uv-0.5; float r2=dot(dv,dv);
  vec3 b1=texture(uB1,uv).rgb, b2=texture(uB2,uv).rgb, b3=texture(uB3,uv).rgb;
  vec3 bloom=b1*0.34+b2*0.36+b3*0.30;

  // lens drops: a few, low opacity, refract and catch the lights
  vec2 off=vec2(0.);
  vec4 dr=vec4(0.);
  if(uHasDrops>0.5){
    vec2 du=vec2(uv.x,1.0-uv.y-uT*0.0025);
    float msk=smoothstep(0.52,0.7,vn2(uv*vec2(3.0,2.0)+7.3)+0.12*vnoise(uT*0.05));
    vec2 e=vec2(2.5/1920.,2.5/1080.);
    float aL=textureLod(uDrops,du-vec2(e.x,0.),0.5).a, aR=textureLod(uDrops,du+vec2(e.x,0.),0.5).a;
    float aU=textureLod(uDrops,du-vec2(0.,e.y),0.5).a, aD=textureLod(uDrops,du+vec2(0.,e.y),0.5).a;
    dr=textureLod(uDrops,du,0.5); dr*=msk;
    off=vec2(aR-aL,aD-aU)*0.006*msk;
  }
  vec2 cauv=uv+off;
  float ca=0.0035*r2*4.0+0.0004;
  vec3 col;
  col.r=texture(uScene,cauv+dv*ca).r;
  col.g=texture(uScene,cauv).g;
  col.b=texture(uScene,cauv-dv*ca).b;

  // light spill on the surfaces (bloom lights what is under it) + 50 % bloom
  col+=col*bloom*0.6;
  col+=bloom*0.55*uBloom;
  // lens dirt and drops only glow where bloom is
  vec3 glow=b3*1.2+b2*0.7+b1*0.3;
  if(uHasDirt>0.5){
    vec3 dirt=texture(uDirt,vec2(uv.x,1.0-uv.y)).rgb;
    col+=dirt*glow*5.0;
  } else {
    float n=vn2(uv*vec2(5.,3.))*0.6+vn2(uv*vec2(17.,9.)+3.)*0.4;
    col+=smoothstep(0.55,0.9,n)*glow*0.8;
  }
  if(uHasDrops>0.5){
    float da=dr.a*0.28;
    vec3 dl=dr.rgb*(0.10+glow*2.6)+vec3(0.0);
    col=col*(1.0-da*0.25)+dl*0.28;
  }

  // PS2 finish: tone shoulder, crushed blacks + S curve, split-tone, tint
  col=shoulder(col);
  float l=lum(col);
  col=mix(col,vec3(l),clamp(l-0.88,0.,1.)*0.7);
  col=max(col-0.028,0.)/(1.0-0.028);
  vec3 sc=col*col*(3.0-2.0*col);
  col=mix(col,sc,0.35);
  col+=vec3(-0.004,0.008,0.016)*(1.0-smoothstep(0.0,0.45,l));      // teal shadows
  col*=mix(vec3(1.05,1.0,0.93),vec3(0.94,1.0,1.07),0.5+0.5*uTint*0.0)* 1.0;
  col*=mix(vec3(1.045,1.0,0.945),vec3(0.945,1.0,1.06),clamp(0.5+0.5*uTint,0.,1.));
  col*=1.0-0.48*smoothstep(0.08,0.62,r2);
  // grain at 24 Hz + faint interlace
  float f24=floor(uT*24.);
  float g=hash21(gl_FragCoord.xy+vec2(f24*17.1,f24*31.7))-0.5;
  float g2=hash21(gl_FragCoord.xy*0.5+vec2(f24*7.7,f24*3.3))-0.5;
  col+=g*0.075*(0.55+0.45*(1.0-l))+vec3(g2,-g2,g2*0.5)*0.01;
  float line=mod(floor(gl_FragCoord.y/max(1.0,floor(uRes.y/600.))),2.0);
  float fld=mod(floor(uT*30.),2.0);
  col*=1.0-0.03*abs(line-fld);
  col*=uFade;
  oC=vec4(max(col,0.),1.);
}`;

  // ---- state ----
  let canvas = null, gl = null, base = 'launcher/v2/';
  let started = false, ready = false, dead = false, ctxLost = false;
  let rafId = 0, lastNow = 0, lastDraw = 0, tScene = 0, introT = 0, introDone = false;
  const introCbs = [];
  let motionOn = true, ptrX = 0, ptrY = 0, curPX = 0, curPY = 0;
  let selTint = 0, selTintT = 0, kickX = 0, kickY = 0, selNX = 0, selNY = 0, selNXt = 0, selNYt = 0, pulse = 0;
  let fallbackImg = null;
  const SCREENS = {
    main:    { cx: 0.0,    cy: 0.0,    zoom: 1.0,  dof: 1.0,  focus: 0.0 },
    presets: { cx: 0.075,  cy: 0.012,  zoom: 1.12, dof: 1.25, focus: 0.0 },
    opts:    { cx: -0.05,  cy: 0.0,    zoom: 1.06, dof: 1.5,  focus: -0.12 },
    ctrl:    { cx: -0.02,  cy: -0.02,  zoom: 1.03, dof: 1.5,  focus: -0.2 },
  };
  const frame = { cx: 0, cy: 0, zoom: 1, dof: 1, focus: 0 };       // current
  const frameFrom = { cx: 0, cy: 0, zoom: 1, dof: 1, focus: 0 };
  let frameTo = SCREENS.main, frameT0 = -10, frameDur = 0.8;
  let confirmT0 = -1, confirmResolve = null, confirmTimer = 0, confirmDone = false;
  // passing car
  let passT0 = -1, passDur = 3.6, passDir = 1, nextPass = 0;
  const passY = 0.545;
  // assets
  const A = {};          // decoded images: plate, depth, emis, car, carL, fgL, fgT, steam, dirt, drops
  const T = {};          // gl textures
  const P = {};          // programs {prog, u:{}}
  let fbScene = null, fbDof = null, bloom = [];
  let W = 0, H = 0, scale = 1;
  let carRect = [0, 0, 1, 1], carBB = [0.4, 0.5, 0.8, 0.9], carLine = [0.5, 0.9, 0.7, 0.8], fgLRect = [0, 0, 0.47, 1], fgTRect = [0, 0, 1, 0.35];
  let hl1 = [0.5, 0.78], hl2 = [0.55, 0.78];
  let dCar = 0.8, plateAsp = 16 / 9;
  let hasSteamLum = 0;
  // perf
  const cpuMs = new Float32Array(240); let cpuN = 0, cpuI = 0;
  const dtMs = new Float32Array(240); let dtN = 0, dtI = 0;
  let timerExt = null, queries = [], qIdx = 0; const gpuMs = new Float32Array(240); let gpuN = 0, gpuI = 0;
  let slowFrames = 0, perfOn = false;
  const uni = {};        // reusable uniform scratch

  // ---- loading ----
  async function loadImg(name, premult) {
    const tryUrls = [base + name + '.webp'];
    for (const u of tryUrls) {
      try {
        const r = await fetch(u);
        if (!r.ok) continue;
        const blob = await r.blob();
        return await createImageBitmap(blob, { premultiplyAlpha: premult ? 'premultiply' : 'none', colorSpaceConversion: 'none' });
      } catch (e) { /* next */ }
    }
    return null;
  }
  function readPixels(img, w, h) {
    const c = document.createElement('canvas'); c.width = w; c.height = h;
    const x = c.getContext('2d', { willReadFrequently: true });
    x.imageSmoothingQuality = 'high';
    // two-step downscale keeps small bright lights (bilinear alone skips them)
    let sw = img.width, sh = img.height, src = img;
    while (sw / 2 > w * 1.0 && sh / 2 > h * 1.0) {
      const t = document.createElement('canvas'); t.width = (sw = Math.ceil(sw / 2)); t.height = (sh = Math.ceil(sh / 2));
      const tx = t.getContext('2d'); tx.imageSmoothingQuality = 'high'; tx.drawImage(src, 0, 0, sw, sh); src = t;
    }
    x.drawImage(src, 0, 0, w, h);
    return x.getImageData(0, 0, w, h).data;
  }
  function alphaBBox(img) {
    const w = 400, h = Math.max(8, Math.round(400 * img.height / img.width));
    const d = readPixels(img, w, h);
    let x0 = w, y0 = h, x1 = 0, y1 = 0;
    for (let y = 0; y < h; y++) for (let x = 0; x < w; x++) if (d[(y * w + x) * 4 + 3] > 60) { if (x < x0) x0 = x; if (x > x1) x1 = x; if (y < y0) y0 = y; if (y > y1) y1 = y; }
    if (x1 < x0) return [0, 0, 1, 1];
    return [x0 / w, y0 / h, (x1 + 1) / w, (y1 + 1) / h];
  }
  function hasAlpha(img) {
    const d = readPixels(img, 64, 64);
    for (let i = 3; i < d.length; i += 4) if (d[i] < 240) return true;
    return false;
  }
  // placeholder depth: ground gradient + side walls, as disparity (white near)
  function makeDepth(w, h) {
    const px = new Uint8Array(w * h * 4);
    const yH = CFG.horizon;
    for (let y = 0; y < h; y++) for (let x = 0; x < w; x++) {
      const u = x / (w - 1), v = y / (h - 1);
      const g = Math.max(0, (v - yH) / (1 - yH)) * CFG.groundK;
      const sm = (a, b, t) => { t = clamp((t - a) / (b - a), 0, 1); return t * t * (3 - 2 * t); };
      const wall = 0.08 + 0.7 * Math.max(sm(0.34, 0.0, u), sm(0.58, 1.0, u) * 0.85);
      const d = clamp(Math.max(g, wall), 0, 1);
      const o = (y * w + x) * 4; px[o] = px[o + 1] = px[o + 2] = Math.round(d * 255); px[o + 3] = 255;
    }
    return { w, h, px };
  }
  // placeholder emissive: bright or saturated-hot pixels of the upper plate
  function makeEmis(plate) {
    const w = 640, h = Math.round(640 * plate.height / plate.width);
    const d = readPixels(plate, w, h);
    const px = new Uint8Array(w * h * 4);
    for (let y = 0; y < h; y++) {
      const v = y / h; const fade = 1 - clamp((v - (CFG.horizon + 0.08)) / 0.05, 0, 1);
      for (let x = 0; x < w; x++) {
        const o = (y * w + x) * 4;
        const r = d[o] / 255, g = d[o + 1] / 255, b = d[o + 2] / 255;
        const mx = Math.max(r, g, b), mn = Math.min(r, g, b), sat = mx > 0 ? (mx - mn) / mx : 0;
        const k = clamp((mx - 0.66) / 0.24, 0, 1) * clamp((sat - 0.12) / 0.3 + (mx > 0.93 ? 1 : 0), 0, 1) * fade;
        px[o] = r * k * 255; px[o + 1] = g * k * 255; px[o + 2] = b * k * 255; px[o + 3] = 255;
      }
    }
    return { w, h, px };
  }
  // region map: connected light blobs -> id, category, left-to-right rank (for the intro and per-light flicker)
  function makeRegions(emisPx, ew, eh, kindPx) {
    const GW = 192, GH = 108;
    const v = new Float32Array(GW * GH), hue = new Float32Array(GW * GH), sat = new Float32Array(GW * GH);
    // emisPx is RGBA at ew x eh; box-average into the grid keeping the max (lights are small)
    const sx = ew / GW, sy = eh / GH;
    for (let gy = 0; gy < GH; gy++) for (let gx = 0; gx < GW; gx++) {
      let bv = 0, br = 0, bg = 0, bb = 0;
      const x0 = Math.floor(gx * sx), x1 = Math.max(x0 + 1, Math.floor((gx + 1) * sx)), y0 = Math.floor(gy * sy), y1 = Math.max(y0 + 1, Math.floor((gy + 1) * sy));
      for (let y = y0; y < y1 && y < eh; y += 1) for (let x = x0; x < x1 && x < ew; x += 1) {
        const o = (y * ew + x) * 4; const m = Math.max(emisPx[o], emisPx[o + 1], emisPx[o + 2]);
        if (m > bv) { bv = m; br = emisPx[o]; bg = emisPx[o + 1]; bb = emisPx[o + 2]; }
      }
      const i = gy * GW + gx; v[i] = bv / 255;
      const mx = Math.max(br, bg, bb), mn = Math.min(br, bg, bb);
      sat[i] = mx ? (mx - mn) / mx : 0;
      let hh = 0; if (mx !== mn) { const d = mx - mn; if (mx === br) hh = ((bg - bb) / d) % 6; else if (mx === bg) hh = (bb - br) / d + 2; else hh = (br - bg) / d + 4; hh *= 60; if (hh < 0) hh += 360; }
      hue[i] = hh;
    }
    const lab = new Int32Array(GW * GH).fill(-1);
    const regs = [];
    const stack = new Int32Array(GW * GH);
    for (let i0 = 0; i0 < GW * GH; i0++) {
      if (v[i0] < 0.3 || lab[i0] >= 0) continue;
      let sp = 0; stack[sp++] = i0; lab[i0] = regs.length;
      const r = { lab: regs.length, n: 0, sx: 0, sy: 0, vs: 0, hx: 0, hy: 0, vmax: 0, ymin: 1e9, id: -1 };
      while (sp) {
        const i = stack[--sp]; const x = i % GW, y = (i / GW) | 0;
        r.n++; r.sx += x; r.sy += y; r.vs += v[i]; r.hx += Math.cos(hue[i] * Math.PI / 180) * v[i]; r.hy += Math.sin(hue[i] * Math.PI / 180) * v[i];
        if (v[i] > r.vmax) r.vmax = v[i]; if (y < r.ymin) r.ymin = y;
        for (let dy = -1; dy <= 1; dy++) for (let dx = -1; dx <= 1; dx++) {
          const nx = x + dx, ny = y + dy; if (nx < 0 || ny < 0 || nx >= GW || ny >= GH) continue;
          const j = ny * GW + nx; if (v[j] >= 0.3 && lab[j] < 0) { lab[j] = regs.length; stack[sp++] = j; }
        }
      }
      regs.push(r);
    }
    const keep = regs.filter(r => r.n >= 2).sort((a, b) => b.n - a.n).slice(0, 48);
    const warm = (r) => { let h = Math.atan2(r.hy, r.hx) * 180 / Math.PI; if (h < 0) h += 360; return h > 12 && h < 62; };
    keep.sort((a, b) => a.sx / a.n - b.sx / b.n);
    const N = keep.length;
    keep.forEach((r, k) => {
      r.id = k + 1; r.rank = N > 1 ? k / (N - 1) : 0;
      const big = r.n > GW * GH * 0.004;
      let kk = -1;
      if (kindPx) {   // plate_emissive_kind: R windows, G neon, B lamps; the region takes the majority kind of its cells
        const cnt = [0, 0, 0];
        for (let i = 0; i < GW * GH; i++) if (lab[i] === r.lab) for (let c = 0; c < 3; c++) if (kindPx[i * 4 + c] > 90) cnt[c]++;
        const mx = Math.max(cnt[0], cnt[1], cnt[2]); if (mx > 0) kk = cnt.indexOf(mx);
      }
      if (kk >= 0) r.cat = (kk === 2 && big && warm(r)) ? 3 : [0, 2, 1][kk];
      else if (warm(r) && big) r.cat = 3;
      else if (warm(r) && r.vmax > 0.9 && r.n <= 14 && r.ymin < GH * 0.5) r.cat = 1;     // sodium lamp head
      else if (warm(r) && r.sy / r.n > GH * 0.2 && r.n < 30 && r.sat < 0.5) r.cat = 1;
      else if (!warm(r) || r.n > 10) r.cat = 2;       // neon
      else r.cat = 0;                                  // windows and small steady lights
    });
    const idOf = new Int32Array(GW * GH).fill(-1);
    for (let i = 0; i < GW * GH; i++) if (lab[i] >= 0 && regs[lab[i]].id > 0) idOf[i] = lab[i];
    // dilate by 2 cells so the soft glow around a tube belongs to it
    for (let pass = 0; pass < 2; pass++) {
      const nxt = idOf.slice();
      for (let y = 0; y < GH; y++) for (let x = 0; x < GW; x++) {
        const i = y * GW + x; if (idOf[i] >= 0) continue;
        for (let dy = -1; dy <= 1 && nxt[i] < 0; dy++) for (let dx = -1; dx <= 1; dx++) {
          const nx = x + dx, ny = y + dy; if (nx < 0 || ny < 0 || nx >= GW || ny >= GH) continue;
          if (idOf[ny * GW + nx] >= 0) { nxt[i] = idOf[ny * GW + nx]; break; }
        }
      }
      idOf.set(nxt);
    }
    const out = new Uint8Array(GW * GH * 4);
    for (let i = 0; i < GW * GH; i++) {
      const o = i * 4; const ri = idOf[i];
      if (ri < 0) { out[o] = 0; out[o + 1] = 0; out[o + 2] = 128; out[o + 3] = 255; continue; }
      const r = regs[ri]; out[o] = r.id * 5; out[o + 1] = r.cat * 60; out[o + 2] = Math.round(r.rank * 255); out[o + 3] = 255;
    }
    return { w: GW, h: GH, px: out, n: N };
  }

  async function loadAssets() {
    const names = ['plate', 'plate_depth', 'plate_emissive', 'plate_emissive_kind', 'car', 'car_lights', 'fg_left', 'fg_top', 'steam', 'lens_dirt', 'raindrops'];
    const PRE = { car: 1, car_lights: 1, fg_left: 1, fg_top: 1, raindrops: 1 };   // ImageBitmaps ignore UNPACK_PREMULTIPLY: choose at decode
    const res = await Promise.all(names.map(n => loadImg(n, PRE[n])));
    const g = {}; names.forEach((n, i) => { g[n] = res[i]; });
    return g;
  }
  function prepareAssets(g) {
    if (!g.plate) throw new Error('plate missing');
    A.plate = g.plate; plateAsp = g.plate.width / g.plate.height;
    A.depth = g.plate_depth ? { bmp: g.plate_depth } : { raw: makeDepth(256, 144) };
    let emisPx, ew, eh;
    if (g.plate_emissive) { A.emis = { bmp: g.plate_emissive }; ew = 640; eh = Math.round(640 * g.plate_emissive.height / g.plate_emissive.width); emisPx = readPixels(g.plate_emissive, ew, eh); }
    else { const e = makeEmis(g.plate); A.emis = { raw: e }; emisPx = e.px; ew = e.w; eh = e.h; }
    A.kind = g.plate_emissive_kind || null;
    A.region = makeRegions(emisPx, ew, eh, A.kind ? readPixels(A.kind, 192, 108) : null);
    A.car = g.car; A.carL = g.car_lights; A.fgL = g.fg_left; A.fgT = g.fg_top; A.steam = g.steam; A.dirt = g.lens_dirt; A.drops = g.raindrops;
    // car sprite placement: alpha bbox on the underglow pool, ~45 % of the plate width
    if (A.car) {
      const bb = alphaBBox(A.car); const wb = bb[2] - bb[0];
      const Wc = CFG.carWidth / wb;
      const Hc = Wc * plateAsp * (A.car.height / A.car.width);
      const rx = CFG.carCX - (bb[0] + wb / 2) * Wc, ry = CFG.carBottom - bb[3] * Hc;
      carRect = [rx, ry, Wc, Hc];
      carBB = [rx + bb[0] * Wc, ry + bb[1] * Hc, rx + bb[2] * Wc, ry + bb[3] * Hc];
      { const mid = (carBB[3] + (carBB[1] + CFG.carContact[3] * (carBB[3] - carBB[1]))) * 0.5; dCar = clamp(clamp((mid - CFG.horizon) / (1 - CFG.horizon), 0, 1) * CFG.groundK + CFG.carDepthBias, 0.05, 0.98); }
      { const c = CFG.carContact, bw = carBB[2] - carBB[0], bh = carBB[3] - carBB[1]; carLine = [carBB[0] + c[0] * bw, carBB[1] + c[1] * bh, carBB[0] + c[2] * bw, carBB[1] + c[3] * bh]; }
      // the two headlamps: 2-means over the bright pixels of car_lights (else guessed on the front of the car)
      hl1 = [carBB[0] + (carBB[2] - carBB[0]) * 0.12, carBB[1] + (carBB[3] - carBB[1]) * 0.58]; hl2 = [hl1[0] + 0.06, hl1[1] + 0.02];
      if (A.carL) {
        const cw = 240, d = readPixels(A.carL, cw, Math.round(cw * A.carL.height / A.carL.width)), ch = d.length / 4 / cw;
        const pts = []; for (let y = 0; y < ch; y++) for (let x = 0; x < cw; x++) { const o = (y * cw + x) * 4; const w = d[o + 3] > 40 ? d[o] + d[o + 1] + d[o + 2] : 0; if (w > 300) pts.push(x, y, w); }
        if (pts.length > 30) {
          let sx = 0, sw = 0; for (let i = 0; i < pts.length; i += 3) { sx += pts[i] * pts[i + 2]; sw += pts[i + 2]; }
          let c1 = [sx / sw - 10, 0], c2 = [sx / sw + 10, 0]; let m1 = [0, 0, 0], m2 = [0, 0, 0];
          for (let it = 0; it < 4; it++) {
            m1 = [0, 0, 0]; m2 = [0, 0, 0];
            for (let i = 0; i < pts.length; i += 3) { const m = Math.abs(pts[i] - c1[0]) <= Math.abs(pts[i] - c2[0]) ? m1 : m2; m[0] += pts[i] * pts[i + 2]; m[1] += pts[i + 1] * pts[i + 2]; m[2] += pts[i + 2]; }
            if (m1[2] > 0) c1 = [m1[0] / m1[2], m1[1] / m1[2]]; if (m2[2] > 0) c2 = [m2[0] / m2[2], m2[1] / m2[2]];
          }
          hl1 = [rx + (c1[0] / cw) * Wc, ry + (c1[1] / ch) * Hc]; hl2 = [rx + (c2[0] / cw) * Wc, ry + (c2[1] / ch) * Hc];
        }
      }
    }
    if (A.fgL) fgLRect = [0, 0, A.fgL.width / g.plate.width, A.fgL.height / g.plate.height];
    if (A.fgT) fgTRect = [0, 0, A.fgT.width / g.plate.width, A.fgT.height / g.plate.height];
    hasSteamLum = A.steam && !hasAlpha(A.steam) ? 1 : 0;
  }

  // ---- GL setup ----
  function compile(type, src) {
    const s = gl.createShader(type); gl.shaderSource(s, src); gl.compileShader(s);
    if (!gl.getShaderParameter(s, gl.COMPILE_STATUS)) throw new Error('shader: ' + gl.getShaderInfoLog(s) + '\n' + src.split('\n').map((l, i) => (i + 1) + ': ' + l).join('\n').slice(0, 6000));
    return s;
  }
  function program(name, fs) {
    const p = gl.createProgram(); gl.attachShader(p, compile(gl.VERTEX_SHADER, VS)); gl.attachShader(p, compile(gl.FRAGMENT_SHADER, fs)); gl.linkProgram(p);
    if (!gl.getProgramParameter(p, gl.LINK_STATUS)) throw new Error('link ' + name + ': ' + gl.getProgramInfoLog(p));
    const u = {}; const n = gl.getProgramParameter(p, gl.ACTIVE_UNIFORMS);
    for (let i = 0; i < n; i++) { const info = gl.getActiveUniform(p, i); u[info.name] = gl.getUniformLocation(p, info.name); }
    P[name] = { p, u };
  }
  function tex(opts) {
    const t = gl.createTexture(); gl.bindTexture(gl.TEXTURE_2D, t);
    gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_MIN_FILTER, opts.mip ? gl.LINEAR_MIPMAP_LINEAR : (opts.nearest ? gl.NEAREST : gl.LINEAR));
    gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_MAG_FILTER, opts.nearest ? gl.NEAREST : gl.LINEAR);
    const wr = opts.repeat ? gl.REPEAT : gl.CLAMP_TO_EDGE;
    gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_WRAP_S, wr); gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_WRAP_T, wr);
    return t;
  }
  function uploadBitmap(bmp, opts) {
    const t = tex(opts);
    gl.pixelStorei(gl.UNPACK_PREMULTIPLY_ALPHA_WEBGL, !!opts.premult);
    gl.texImage2D(gl.TEXTURE_2D, 0, gl.RGBA8, gl.RGBA, gl.UNSIGNED_BYTE, bmp);
    if (opts.mip) gl.generateMipmap(gl.TEXTURE_2D);
    return t;
  }
  function uploadRaw(r, opts) {
    const t = tex(opts);
    gl.pixelStorei(gl.UNPACK_PREMULTIPLY_ALPHA_WEBGL, false);
    gl.texImage2D(gl.TEXTURE_2D, 0, gl.RGBA8, r.w, r.h, 0, gl.RGBA, gl.UNSIGNED_BYTE, r.px);
    if (opts.mip) gl.generateMipmap(gl.TEXTURE_2D);
    return t;
  }
  let hdrFmt = false;
  function target(w, h, hdr) {
    const t = gl.createTexture(); gl.bindTexture(gl.TEXTURE_2D, t);
    if (hdr && hdrFmt) gl.texImage2D(gl.TEXTURE_2D, 0, gl.RGBA16F, w, h, 0, gl.RGBA, gl.HALF_FLOAT, null);
    else gl.texImage2D(gl.TEXTURE_2D, 0, gl.RGBA8, w, h, 0, gl.RGBA, gl.UNSIGNED_BYTE, null);
    gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_MIN_FILTER, gl.LINEAR); gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_MAG_FILTER, gl.LINEAR);
    gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_WRAP_S, gl.CLAMP_TO_EDGE); gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_WRAP_T, gl.CLAMP_TO_EDGE);
    const f = gl.createFramebuffer(); gl.bindFramebuffer(gl.FRAMEBUFFER, f);
    gl.framebufferTexture2D(gl.FRAMEBUFFER, gl.COLOR_ATTACHMENT0, gl.TEXTURE_2D, t, 0);
    return { t, f, w, h };
  }
  function freeTarget(x) { if (x) { gl.deleteTexture(x.t); gl.deleteFramebuffer(x.f); } }
  function buildTargets() {
    freeTarget(fbScene); freeTarget(fbDof); bloom.forEach(b => { freeTarget(b.a); freeTarget(b.b); }); bloom = [];
    fbScene = target(W, H, true); fbDof = target(W, H, true);
    const bw = [320, 160, 80];
    for (let i = 0; i < 3; i++) { const w = bw[i], h = Math.max(8, Math.round(w * H / W)); bloom.push({ a: target(w, h, false), b: target(w, h, false), w, h }); }
  }
  function initGL() {
    ctxLost = false;
    const e1 = gl.getExtension('EXT_color_buffer_float') || gl.getExtension('EXT_color_buffer_half_float');
    hdrFmt = !!e1;
    for (const k of Object.keys(P)) delete P[k];
    program('scene', FS_SCENE); program('dof', FS_DOF); program('bright', FS_BRIGHT); program('down', FS_DOWN); program('blur', FS_BLUR); program('comp', FS_COMP);
    const a = A;
    T.plate = uploadBitmap(a.plate, { mip: true });
    T.depth = a.depth.bmp ? uploadBitmap(a.depth.bmp, { mip: true }) : uploadRaw(a.depth.raw, { mip: true });
    T.emis = a.emis.bmp ? uploadBitmap(a.emis.bmp, { mip: true }) : uploadRaw(a.emis.raw, { mip: true });
    T.region = uploadRaw(a.region, { nearest: true });
    T.kind = a.kind ? uploadBitmap(a.kind, { mip: true }) : uploadRaw({ w: 1, h: 1, px: new Uint8Array(4) }, {});
    const blank = { w: 1, h: 1, px: new Uint8Array(4) };
    T.car = a.car ? uploadBitmap(a.car, { premult: true, mip: true }) : uploadRaw(blank, {});
    T.carL = a.carL ? uploadBitmap(a.carL, { premult: true, mip: true }) : uploadRaw(blank, {});
    T.fgL = a.fgL ? uploadBitmap(a.fgL, { premult: true, mip: true }) : uploadRaw(blank, {});
    T.fgT = a.fgT ? uploadBitmap(a.fgT, { premult: true, mip: true }) : uploadRaw(blank, {});
    T.steam = a.steam ? uploadBitmap(a.steam, { premult: false, mip: true }) : uploadRaw(blank, {});
    T.dirt = a.dirt ? uploadBitmap(a.dirt, { mip: true }) : uploadRaw(blank, {});
    T.drops = a.drops ? uploadBitmap(a.drops, { premult: true, mip: true, repeat: true }) : uploadRaw(blank, {});
    gl.pixelStorei(gl.UNPACK_PREMULTIPLY_ALPHA_WEBGL, false);
    gl.disable(gl.DEPTH_TEST); gl.disable(gl.BLEND);
    resize(true);
    // GPU timer (only when asked: ?perf=1 or RN_SCENE.perf(true))
    timerExt = gl.getExtension('EXT_disjoint_timer_query_webgl2');
  }
  function resize(force) {
    const r = canvas.getBoundingClientRect();
    const cw = Math.max(2, r.width || window.innerWidth), ch = Math.max(2, r.height || window.innerHeight);
    let s = Math.min(DPR_CAP(), 1.5) * qualityMul;
    const px = cw * ch * s * s; if (px > CFG.maxPixels) s *= Math.sqrt(CFG.maxPixels / px);
    const nw = Math.max(2, Math.round(cw * s)), nh = Math.max(2, Math.round(ch * s));
    if (!force && nw === W && nh === H) return;
    W = nw; H = nh; scale = s; canvas.width = W; canvas.height = H;
    buildTargets();
  }
  let qualityMul = 1, dbgView = 0;

  // ---- per-frame ----
  const camState = { x: 0, y: 0 };
  function setU1(u, n, v) { if (u[n] != null) gl.uniform1f(u[n], v); }
  function setU2(u, n, a, b) { if (u[n] != null) gl.uniform2f(u[n], a, b); }
  function setU3(u, n, a, b, c) { if (u[n] != null) gl.uniform3f(u[n], a, b, c); }
  function setU4(u, n, a, b, c, d) { if (u[n] != null) gl.uniform4f(u[n], a, b, c, d); }
  function bindTex(unit, t, u, name) { gl.activeTexture(gl.TEXTURE0 + unit); gl.bindTexture(gl.TEXTURE_2D, t); if (u[name] != null) gl.uniform1i(u[name], unit); }
  function pass(p) { gl.useProgram(p.p); return p.u; }
  function draw(fb, w, h) { gl.bindFramebuffer(gl.FRAMEBUFFER, fb ? fb.f : null); gl.viewport(0, 0, w, h); gl.drawArrays(gl.TRIANGLES, 0, 3); }

  function updateCamera(dt) {
    const T = tScene;
    // screen framing
    const k = frameT0 < 0 ? 1 : clamp((T - frameT0) / frameDur, 0, 1);
    const e = motionOn ? easeScreen(k) : 1;
    frame.cx = lerp(frameFrom.cx, frameTo.cx, e); frame.cy = lerp(frameFrom.cy, frameTo.cy, e);
    frame.zoom = lerp(frameFrom.zoom, frameTo.zoom, e); frame.dof = lerp(frameFrom.dof, frameTo.dof, e); frame.focus = lerp(frameFrom.focus, frameTo.focus, e);
    // pointer + select nudge (exponential smoothing)
    const a = 1 - Math.exp(-dt * 3.2);
    curPX += (ptrX - curPX) * a; curPY += (ptrY - curPY) * a;
    selNX += (selNXt - selNX) * (1 - Math.exp(-dt * 4)); selNY += (selNYt - selNY) * (1 - Math.exp(-dt * 4));
    kickX *= Math.exp(-dt * 5); kickY *= Math.exp(-dt * 5);
    selTint += (selTintT - selTint) * (1 - Math.exp(-dt * 2.5));
    let hx = 0, hy = 0;
    if (motionOn) {
      hx = smoothNoise(T * 0.21, 1) * 0.0065 + smoothNoise(T * 0.77, 4) * 0.0014;
      hy = smoothNoise(T * 0.17, 2) * 0.0045 + smoothNoise(T * 0.61, 5) * 0.001;
      camState.x = hx + curPX * 0.030 + selNX + kickX; camState.y = hy + curPY * 0.020 + selNY + kickY;
    } else { camState.x = 0; camState.y = 0; }
  }

  function uploadScene(u, introFlash) {
    const tt = tScene;
    const vis0x = Math.min(1, (W / H) / plateAsp), vis0y = Math.min(1, plateAsp / (W / H));
    // portrait: zoom out, car in the upper part (the menu panel takes the lower half); out-of-plate area fades to black in the shader
    const asp = W / H, pf = smooth01((0.85 - asp) / 0.3);
    let zoom = lerp(CFG.baseZoom * frame.zoom, CFG.portraitZoom, pf);
    // intro dolly + confirm push-in
    let dolly = 0;
    if (motionOn) {
      if (introT < CFG.introSecs) dolly = 1 - easeIntro(introT / CFG.introSecs);
      if (confirmT0 >= 0) dolly -= 2.0 * easeInOut(clamp((tt - confirmT0) / 0.65, 0, 1));
    }
    const vx = vis0x / zoom, vy = vis0y / zoom;
    const nar = 1 - vis0x;
    let cx = 0.5 + 0.1 * nar + frame.cx * (motionOn ? 1 : 1), cy = 0.5 + frame.cy;
    cx = clamp(cx, vx / 2, 1 - vx / 2); cy = clamp(cy, vy / 2, 1 - vy / 2);
    if (pf > 0) {
      const carMidY = (carBB[1] + carBB[3]) * 0.5, carMidX = (carBB[0] + carBB[2]) * 0.5;
      cx = lerp(cx, carMidX, pf); cy = lerp(cy, carMidY + (0.5 - CFG.portraitCarY) * vy, pf);
    }
    setU1(u, 'uPortrait', pf);
    setU1(u, 'uT', tt); setU1(u, 'uIntro', introT); setU1(u, 'uTint', selTint);
    setU1(u, 'uFlash', introFlash); setU1(u, 'uDbg', dbgView); setU1(u, 'uPulse', pulse);
    setU2(u, 'uRes', W, H);
    setU4(u, 'uView', cx, cy, vx, vy);
    setU4(u, 'uCam', camState.x, camState.y * plateAsp * 0.5625 * 1.0, dolly, plateAsp);
    setU4(u, 'uHas', A.car ? 1 : 0, A.carL ? 1 : 0, A.fgL ? 1 : 0, A.fgT ? 1 : 0);
    setU4(u, 'uCarRect', carRect[0], carRect[1], carRect[2], carRect[3]);
    setU4(u, 'uCarBB', carBB[0], carBB[1], carBB[2], carBB[3]);
    setU4(u, 'uCarLine', carLine[0], carLine[1], carLine[2], carLine[3]);
    setU4(u, 'uFgLRect', fgLRect[0], fgLRect[1], fgLRect[2], fgLRect[3]);
    setU4(u, 'uFgTRect', fgTRect[0], fgTRect[1], fgTRect[2], fgTRect[3]);
    // passing car
    let px = 0, env = 0, hw = 0, tw = 0;
    if (passT0 >= 0) {
      const ph = (tt - passT0) / passDur;
      if (ph >= 1) { passT0 = -1; nextPass = tt + 6 + Math.random() * 8; }
      else {
        const e = ph + 0.12 * Math.sin(ph * Math.PI * 2) * -0.0; // linear travel
        px = passDir > 0 ? lerp(-0.25, 1.3, e) : lerp(1.3, -0.25, e);
        env = Math.min(1, ph / 0.1) * Math.min(1, (1 - ph) / 0.1);
        hw = 1 - clamp((ph - 0.42) / 0.18, 0, 1); tw = clamp((ph - 0.38) / 0.18, 0, 1);
        // the car recedes: its lights shrink in intensity as it leaves
        tw *= 0.9;
      }
    }
    setU4(u, 'uPass', px, passY, passDir, env); setU2(u, 'uPass2', hw, tw);
    setU4(u, 'uGround', CFG.horizon, CFG.groundK, dCar, 1.0);
    setU4(u, 'uSteamP', CFG.steamPos[0], CFG.steamPos[1], A.steam ? 1 : 0, 0);
    setU1(u, 'uSteamLum', hasSteamLum);
    setU4(u, 'uHL1', hl1[0], hl1[1], 0, 0); setU4(u, 'uHL2', hl2[0], hl2[1], 0, 0);
    bindTex(0, T.plate, u, 'uPlate'); bindTex(1, T.depth, u, 'uDepth'); bindTex(2, T.emis, u, 'uEmis'); bindTex(3, T.region, u, 'uRegion');
    bindTex(4, T.car, u, 'uCar'); bindTex(5, T.carL, u, 'uCarL'); bindTex(6, T.fgL, u, 'uFgL'); bindTex(7, T.fgT, u, 'uFgT'); bindTex(8, T.steam, u, 'uSteamT'); bindTex(9, T.kind, u, 'uKind'); setU1(u, 'uHasKind', A.kind ? 1 : 0);
  }

  function render(now) {
    if (dead || ctxLost) return;
    rafId = requestAnimationFrame(render);
    if (document.hidden) return;
    const ms = now - lastDraw;
    if (lastDraw && ms < 1000 / CFG.fpsCap - 1.5) return;
    let dt = lastNow ? (now - lastNow) / 1000 : 0.016; lastNow = now; lastDraw = now;
    dt = Math.min(dt, 0.05);
    const t0 = performance.now();
    tScene += dt;
    dtMs[dtI] = ms; dtI = (dtI + 1) % dtMs.length; if (dtN < dtMs.length) dtN++;
    if (!introDone) {
      introT += dt;
      if (introT >= CFG.introSecs) { introDone = true; for (let i = 0; i < introCbs.length; i++) { try { introCbs[i](); } catch (e) { console.error(e); } } introCbs.length = 0; if (nextPass === 0) nextPass = tScene + 2.5 + Math.random() * 2.5; }
    } else introT = Math.max(introT, CFG.introSecs) + dt;
    if (introDone && passT0 < 0 && tScene >= nextPass) { passT0 = tScene; passDir = Math.random() < 0.5 ? 1 : -1; }
    pulse = 0.5 + 0.5 * Math.sin(tScene * 0.55);
    updateCamera(dt);

    // confirm timeline
    let flash = 0.45 * Math.exp(-Math.pow((introT - 1.78) / 0.16, 2)), fade = 1;
    if (confirmT0 >= 0) {
      const c = tScene - confirmT0;
      flash = Math.max(flash, smooth01(c / 0.16) * (1 - 0.45 * smooth01((c - 0.3) / 0.3)));
      fade = 1 - smooth01((c - 0.42) / 0.28);
      if (c >= 0.7 && !confirmDone) { confirmDone = true; clearTimeout(confirmTimer); if (confirmResolve) { const r = confirmResolve; confirmResolve = null; r(); } }
    }

    // focus: rack from the foreground to the car
    const rk = easeInOut(clamp((introT - 0.25) / 2.1, 0, 1));
    const focus = lerp(0.99, dCar - 0.12, rk) + frame.focus;
    const dofAmt = lerp(1.7, 1.0, rk) * frame.dof * (1.0 + 0.9 * (confirmT0 >= 0 ? 0 : 0));
    const maxR = 0.0075 * H;

    let q = null;
    if (perfOn && timerExt) { q = gl.createQuery(); gl.beginQuery(timerExt.TIME_ELAPSED_EXT, q); }

    // scene
    let p = P.scene, u = pass(p); uploadScene(u, flash);
    draw(fbScene, W, H);
    // dof
    p = P.dof; u = pass(p); bindTex(0, fbScene.t, u, 'uScene'); setU2(u, 'uRes', W, H); setU1(u, 'uFocus', focus); setU1(u, 'uAmt', dofAmt); setU1(u, 'uMaxR', maxR); setU1(u, 'uT', tScene);
    draw(fbDof, W, H);
    // bloom chain
    p = P.bright; u = pass(p); bindTex(0, fbDof.t, u, 'uSrc'); setU2(u, 'uTexel', 1 / bloom[0].w, 1 / bloom[0].h); draw(bloom[0].a, bloom[0].w, bloom[0].h);
    for (let i = 0; i < 3; i++) {
      const b = bloom[i];
      if (i > 0) { p = P.down; u = pass(p); bindTex(0, bloom[i - 1].a.t, u, 'uSrc'); setU2(u, 'uTexel', 1 / b.w, 1 / b.h); draw(b.a, b.w, b.h); }
      p = P.blur; u = pass(p);
      bindTex(0, b.a.t, u, 'uSrc'); setU2(u, 'uTexel', 1 / b.w, 1 / b.h); setU2(u, 'uDir', 1, 0); draw(b.b, b.w, b.h);
      bindTex(0, b.b.t, u, 'uSrc'); setU2(u, 'uDir', 0, 1); draw(b.a, b.w, b.h);
    }
    // composite
    p = P.comp; u = pass(p);
    bindTex(0, fbDof.t, u, 'uScene'); bindTex(1, bloom[0].a.t, u, 'uB1'); bindTex(2, bloom[1].a.t, u, 'uB2'); bindTex(3, bloom[2].a.t, u, 'uB3');
    bindTex(4, T.dirt, u, 'uDirt'); bindTex(5, T.drops, u, 'uDrops');
    setU2(u, 'uRes', W, H); setU1(u, 'uT', tScene); setU1(u, 'uFade', fade); setU1(u, 'uTint', selTint); setU1(u, 'uHasDirt', A.dirt ? 1 : 0); setU1(u, 'uHasDrops', A.drops ? 1 : 0);
    setU1(u, 'uBloom', 1); setU1(u, 'uFlash', flash);
    draw(null, W, H);
    if (q) { gl.endQuery(timerExt.TIME_ELAPSED_EXT); queries.push(q); }
    if (queries.length) {
      const q0 = queries[0];
      if (gl.getQueryParameter(q0, gl.QUERY_RESULT_AVAILABLE)) {
        if (!gl.getParameter(timerExt.GPU_DISJOINT_EXT)) { gpuMs[gpuI] = gl.getQueryParameter(q0, gl.QUERY_RESULT) / 1e6; gpuI = (gpuI + 1) % gpuMs.length; if (gpuN < gpuMs.length) gpuN++; }
        gl.deleteQuery(q0); queries.shift();
      }
    }
    const c = performance.now() - t0; cpuMs[cpuI] = c; cpuI = (cpuI + 1) % cpuMs.length; if (cpuN < cpuMs.length) cpuN++;
    // adaptive resolution: sustained slow frames (rAF delta well above the 60 fps cap) lower the internal scale
    if (ms > 22 && introDone) slowFrames++; else if (slowFrames > 0) slowFrames--;
    if (slowFrames > 40 && qualityMul > 0.6) { qualityMul *= 0.85; slowFrames = 0; resize(true); }
  }

  function pct(arr, n, p) { if (!n) return 0; const a = Array.from(arr.subarray(0, n)).sort((x, y) => x - y); return a[Math.min(n - 1, Math.floor(n * p))]; }

  // ---- fallback ----
  function fallback() {
    const img = document.createElement('img');
    img.alt = ''; img.src = base + 'plate.webp';
    img.style.cssText = 'position:absolute;inset:0;width:100%;height:100%;object-fit:cover;pointer-events:none';
    if (canvas.parentNode) canvas.parentNode.insertBefore(img, canvas);
    canvas.style.display = 'none'; fallbackImg = img;
    introDone = true;
    queueMicrotask(() => { introCbs.forEach(f => { try { f(); } catch (e) { console.error(e); } }); introCbs.length = 0; });
  }

  // ---- public API ----
  const API = {
    start(cv, opts) {
      if (started) return Promise.resolve();
      started = true; canvas = cv; if (opts && opts.base) base = opts.base.endsWith('/') ? opts.base : opts.base + '/';
      if (/[?&]perf=1/.test(location.search)) perfOn = true;
      return (async () => {
        gl = canvas.getContext('webgl2', { alpha: false, antialias: false, depth: false, stencil: false, powerPreference: 'high-performance', preserveDrawingBuffer: /[?&]keep=1/.test(location.search) });
        if (!gl) { fallback(); return; }
        let g;
        try { g = await loadAssets(); prepareAssets(g); initGL(); }
        catch (e) { console.error('RN_SCENE', e); gl = null; fallback(); return; }
        canvas.addEventListener('webglcontextlost', (e) => { e.preventDefault(); ctxLost = true; cancelAnimationFrame(rafId); });
        canvas.addEventListener('webglcontextrestored', () => { try { for (const k of Object.keys(queries)) delete queries[k]; queries = []; initGL(); lastNow = 0; rafId = requestAnimationFrame(render); } catch (e) { console.error('RN_SCENE restore', e); fallback(); } });
        if (window.ResizeObserver) new ResizeObserver(() => { if (gl && !ctxLost) resize(false); }).observe(canvas); else window.addEventListener('resize', () => resize(false));
        document.addEventListener('visibilitychange', () => { lastNow = 0; });
        ready = true; lastNow = 0;
        // first frame; resolve once it is on screen
        return new Promise((res) => {
          rafId = requestAnimationFrame((t) => { render(t); res(); });
        });
      })();
    },
    onIntroDone(cb) { if (introDone) { try { cb(); } catch (e) { console.error(e); } } else introCbs.push(cb); },
    select(i, n) {
      const f = n > 1 ? i / (n - 1) : 0.5;
      selTintT = (f - 0.5) * 1.1;                 // first item warmer, last cooler
      if (motionOn) { selNXt = (f - 0.5) * 0.010; selNYt = (f - 0.5) * 0.006; kickX = (Math.random() - 0.5) * 0.004; kickY = 0.0035; }
      pulse = 1;
    },
    screen(name) {
      const to = SCREENS[name] || SCREENS.main;
      frameFrom.cx = frame.cx; frameFrom.cy = frame.cy; frameFrom.zoom = frame.zoom; frameFrom.dof = frame.dof; frameFrom.focus = frame.focus;
      frameTo = to; frameT0 = tScene; frameDur = 0.6 + 0.3 * Math.min(1, Math.hypot(to.cx - frame.cx, (to.zoom - frame.zoom) * 0.5) / 0.15);
      if (!motionOn) { frameFrom.cx = to.cx; frameFrom.cy = to.cy; frameFrom.zoom = to.zoom; frameFrom.dof = to.dof; frameFrom.focus = to.focus; }
    },
    confirm() {
      if (!gl || ctxLost || !ready) return new Promise((r) => setTimeout(r, 400));
      if (confirmT0 >= 0) return new Promise((r) => setTimeout(r, 300));
      confirmT0 = tScene; confirmDone = false;
      return new Promise((res) => { confirmResolve = res; confirmTimer = setTimeout(() => { if (confirmResolve) { const r = confirmResolve; confirmResolve = null; r(); } }, 1100); });
    },
    motion(on) { motionOn = !!on; if (!motionOn) { selNXt = selNYt = 0; } },
    pointer(x, y) { ptrX = clamp(+x || 0, -1, 1); ptrY = clamp(+y || 0, -1, 1); },
    // measurement and test hooks
    perf(on) { perfOn = on !== false; return perfOn; },
    stats() {
      return { cpuP50: pct(cpuMs, cpuN, 0.5), cpuP95: pct(cpuMs, cpuN, 0.95), gpuP50: pct(gpuMs, gpuN, 0.5), gpuP95: pct(gpuMs, gpuN, 0.95), gpuN,
        dtP50: pct(dtMs, dtN, 0.5), dtP95: pct(dtMs, dtN, 0.95), frames: dtN, W, H, scale, qualityMul, hdr: hdrFmt, timer: !!timerExt, regions: A.region ? A.region.n : 0 };
    },
    dbg: {
      view(n) { dbgView = n | 0; },
      pass(dir) { passT0 = tScene; passDir = dir || (Math.random() < 0.5 ? 1 : -1); },
      time() { return { t: tScene, intro: introT }; },
      skipIntro() { introT = CFG.introSecs + 0.01; introDone = false; },
    },
  };
  window.RN_SCENE = API;
})();
