// Atlas clip player: image grid + hand-written timeline in which every frame
// carries its own duration. No dependencies, plain ES module.

// Loads "<base><name>.webp" and "<base><name>.json" -> { img, w, h, cols, n }.
// The json is { cell:[w,h], cols, rows, frames }. Rejects if either load fails.
export async function loadAtlas(base, name) {
  const img = new Image();
  img.src = `${base}${name}.webp`;
  const [res] = await Promise.all([fetch(`${base}${name}.json`), img.decode()]);
  if (!res.ok) throw new Error(`atlas ${name}: HTTP ${res.status}`);
  const meta = await res.json();
  const [w, h] = meta.cell;
  return { img, w, h, cols: meta.cols, n: meta.frames };
}

// Plays a timeline of [frameIndex, ms] pairs. `t` is the ms already spent in
// the current cycle, `i` the index into keys, `done` flips on a non-loop end.
export class Clip {
  constructor(atlas, keys, opts = {}) {
    this.atlas = atlas;
    this.keys = keys;
    this.loop = opts.loop !== false;
    this.blend = opts.blend || 'screen';
    // Total positive duration; 0 means the timeline can never advance.
    this.total = keys.reduce((sum, k) => sum + (k[1] > 0 ? k[1] : 0), 0);
    this.t = 0;
    this.i = 0;
    this.done = false;
  }

  // PixiJS AnimatedSprite style: keep the extra time as carry so a long dt
  // cannot lose frames, and skip 0/negative durations instead of stalling.
  update(dtMs) {
    if (!this.keys.length || this.total <= 0) {
      this.done = true;
      this.t = 0;
      return;
    }
    if (this.done && !this.loop) return;
    let lag = this.t + dtMs;
    const k = this.keys;
    while (lag >= k[this.i][1]) {
      lag -= k[this.i][1] > 0 ? k[this.i][1] : 0;
      this.i++;
      if (this.i < k.length) continue;
      if (this.loop) {
        this.i = 0;
        continue;
      }
      this.i = k.length - 1;
      this.done = true;
      break;
    }
    this.t = lag;
  }

  frame() {
    return this.keys[this.i][0];
  }

  reset() {
    this.t = 0;
    this.i = 0;
    this.done = false;
  }

  // Draws the current cell of the atlas into (x, y, w, h), restoring ctx state.
  draw(ctx, x, y, w, h, alpha = 1) {
    const a = this.atlas;
    const f = this.frame();
    const sx = (f % a.cols) * a.w;
    const sy = Math.floor(f / a.cols) * a.h;
    ctx.save();
    ctx.globalCompositeOperation = this.blend;
    ctx.globalAlpha = alpha;
    ctx.drawImage(a.img, sx, sy, a.w, a.h, x, y, w, h);
    ctx.restore();
  }
}
// Timeline helper: '0:80 1:80 2:120 3:40' -> [[0,80],[1,80],[2,120],[3,40]].
export function keys(spec) {
  return String(spec)
    .trim()
    .split(/\s+/)
    .filter(Boolean)
    .map((pair) => {
      const [f, ms] = pair.split(':');
      return [Number(f), Number(ms)];
    });
}
