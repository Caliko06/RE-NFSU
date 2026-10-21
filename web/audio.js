// Plays what the dsound mixer (host/dsound.c) writes into its ring in the shared heap, with an
// AudioWorklet at 44.1 kHz. The mixer runs on the wall clock; the worklet follows it and resyncs when
// the two clocks drift apart. The browser starts audio only after a key or a click on the page.
'use strict';
const AUDIO_WORKLET = `
class Ring extends AudioWorkletProcessor {
  constructor() {
    super();
    this.fade = 0; this.resyncs = 0; this.l = this.r = 0;
    this.port.onmessage = e => {
      const { buffer, hdr } = e.data;
      this.h = new Uint32Array(buffer, hdr, 8);           // written, taken, ring address, ring frames, underruns, resyncs
      this.f = new Float32Array(buffer, this.h[2], 2 * this.h[3]);
      this.n = this.h[3];
    };
  }
  process(inputs, outputs) {
    const l = outputs[0][0], r = outputs[0][1] || l;
    if (!this.h) return true;
    const written = Atomics.load(this.h, 0);
    let taken = this.h[1];
    const behind = (written - taken) >>> 0;
    if (behind > 8192) {                                   // start, or the page was paused: catch up
      taken = (written - 1024) >>> 0;
      if (this.started) { this.fade = 64; Atomics.add(this.h, 5, 1); this.port.postMessage({ resync: ++this.resyncs, behind }); }
      else this.port.postMessage({ started: true });
      this.started = true;
    }
    let silent = 0;
    for (let i = 0; i < l.length; i++) {
      let a = 0, b = 0;
      if (taken !== written) {                             // else underrun: silence
        const k = 2 * (taken % this.n);
        a = this.f[k]; b = this.f[k + 1];
        taken = (taken + 1) >>> 0;
      } else if (this.started) silent++;
      if (this.fade > 0) {                                 // the jump: last sample fades out as the new one fades in
        const w = this.fade-- / 64;
        a = w * this.l + (1 - w) * a; b = w * this.r + (1 - w) * b;
      } else { this.l = a; this.r = b; }
      l[i] = a; r[i] = b;
    }
    Atomics.store(this.h, 1, taken);
    if (silent) Atomics.add(this.h, 4, silent);           // telemetry (web/telemetry.js)
    return true;
  }
}
registerProcessor('rn-ring', Ring);`;

// log gets one line per catch-up after the start (the resync counter).
async function startAudio(M, log) {
  const ctx = new AudioContext({ sampleRate: 44100 });
  const url = URL.createObjectURL(new Blob([AUDIO_WORKLET], { type: 'text/javascript' }));
  await ctx.audioWorklet.addModule(url);
  const node = new AudioWorkletNode(ctx, 'rn-ring', { numberOfInputs: 0, outputChannelCount: [2] });
  node.port.onmessage = e => log(e.data.started ? 'audio started' : `audio resync ${e.data.resync}: ${e.data.behind} frames behind, 64-frame fade`);
  node.port.postMessage({ buffer: M.HEAPU8.buffer, hdr: M._rn_audio_ring() });
  node.connect(ctx.destination);
  const resume = () => { if (ctx.state !== 'running') ctx.resume(); };
  addEventListener('keydown', resume, true);
  addEventListener('mousedown', resume, true);
  return ctx;
}
