// imported from maxpayne-re b28fb1a web/index.html, web/input.js, web/audio.js
import { createReader } from './gpu.js';
import { speedFrame } from './frame.js';

const api = window.MaxChar = {
  enabled: false,
  key() {},
  encode() {},
  // F-Speed may supply its guest base and later replace placement with the pedestrian matrix.
  guestBase: 0,
  place: null,
  scene(device, speed, encoder, rt, ds) {
    if (!api.enabled || !rt || !ds) return;
    if (!api.reader && api.module) api.reader = createReader(api.module, device);
    if (!api.reader) { api.why = 'no reader (Max module not up)'; return; }
    if (!api.guestBase) api.guestBase = speed._rn_mem_mb(3) >>> 0;   // host/win32.c rn_mem_mb(3) = wasm address of guest 0
    const frame = speedFrame(speed, api.guestBase, api.place);
    if (!frame) { api.why = 'no Speed frame (guest base ' + api.guestBase + ')'; return; }
    api.why = 'drawing';
    api.reader.frame = { ...frame, width: rt.w, height: rt.h, resolveTarget: rt.msView ? rt.view : undefined };
    api.encode(encoder, rt.msView || rt.view, ds.view, rt.sc);
  },
};

export async function start(speedM, log = console.log) {
  api.log = log;
  if (RN_MODE !== 'remaster' || new URLSearchParams(location.search).get('max') !== '1') return;
  api.enabled = true;
  const report = s => log('[F-Max] ' + s);
  report('start: loading /mp/out/maxpayne.js');
  const js = document.createElement('script');
  js.src = '/mp/out/maxpayne.js';
  await new Promise((ok, bad) => { js.onload = ok; js.onerror = () => bad(new Error('MaxPayne script load failed')); document.head.append(js); });
  const imgs = await (await fetch('/mp/img-files.json')).json();
  const data = await Promise.all(imgs.map(async ([f]) => {
    const r = await fetch('/mp/img/' + f.split('/').map(encodeURIComponent).join('/'));
    if (!r.ok) throw new Error('Max image ' + f + ': HTTP ' + r.status);
    return [f, new Uint8Array(await r.arrayBuffer())];
  }));
  const M = api.module = await window.MaxPayne({
    arguments: ['/game'],
    wasmMemory: new WebAssembly.Memory({ initial: 640 * 16, maximum: 640 * 16, shared: true }),
    locateFile: f => '/mp/out/' + f,
    print: report, printErr: report, onAbort: e => report('STOP ' + e),
    // The host proxies save_send to this page callback. Nothing reaches NFSU /save/.
    rnSave: async () => {}, rnSaveFailed: report,
    preRun: [m => {
      Object.assign(m.ENV, { RN_FILES: '/mp/files.json', RN_SCREEN: '640x480', RN_GUEST_MB: '448',
        RN_TEXDETAIL: '0', RN_MAXTEX: '1024', RN_FILECACHE_MB: '32', RN_LOWMEM: '1', RN_NOCURSOR: '1',
        RN_JUMP: 'maxpayne_gamemode->gm_init(startup_level);|x_modeswitch->s_modeswitch(game);' });
      m.FS.mkdirTree('/build/img');
      for (const [f, bytes] of data) m.FS.writeFile('/build/img/' + f, bytes);
    }],
  });
  const base = M._rn_input_ring() >>> 2;
  const keys = { KeyW: 0x11, KeyS: 0x1f, KeyA: 0x1e, KeyD: 0x20, ShiftLeft: 0x2a,
    ArrowUp: 0xc8, ArrowDown: 0xd0, ArrowLeft: 0xcb, ArrowRight: 0xcd };
  const held = new Set();
  api.key = (code, down) => {
    const dik = typeof code === 'number' ? code : keys[code];
    if (dik === undefined || held.has(dik) === !!down) return;
    const h = M.HEAP32, head = Atomics.load(h, base), tail = Atomics.load(h, base + 1);
    if (head - tail >= 1024) return;
    h[base + 8 + head % 1024] = dik | (down ? 0x100 : 0);
    Atomics.store(h, base, head + 1);
    if (down) held.add(dik); else held.delete(dik);
  };
  // No AudioContext, worklet or output. Consume PCM so the mixer can keep advancing.
  const audio = M._rn_audio_ring() >>> 2;
  setInterval(() => { const h = M.HEAP32; Atomics.store(h, audio + 1, Atomics.load(h, audio)); }, 20);
  api.encode = (...args) => api.reader?.encode(...args);
  setInterval(() => {
    const b = M._rn_gamestate_addr() >>> 2, h = M.HEAPU32;
    const level = new TextDecoder().decode(M.HEAPU8.slice((b + 32) * 4, (b + 40) * 4)).split('\0')[0];
    const r = api.reader;
    report(`mode=${h[b + 3]} level=${level} packets=${r?.stats.packets || 0} draws=${r?.stats.seen || 0} kept=${r?.stats.kept || 0} rejected noPlayer/notXyz/far/big=${r ? [r.stats.noPlayer, r.stats.notXyz, r.stats.far, r.stats.big].join('/') : '-'} nearest=${r ? r.stats.nearest.toFixed(2) : '-'} view=${r?.stats.view || 'unselected'} W=${r?.stats.world || '-'} player=${r?.stats.player || '-'} placement=${api.guestBase ? 'guest' : 'waiting-for-Speed-guest-base'} scene=${api.why || 'never called'}`);
  }, 1000);
}
