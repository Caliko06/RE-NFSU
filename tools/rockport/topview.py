"""topview.py: top view PNG of MW sections, drawn from their real meshes (painter order by z, shaded by height and slope).
usage: topview.py OUT.png LETTERS_OR_ROWS [m_per_px] [x0 y0 x1 y1] [--coll]    e.g. topview.py out.png BCDET 2
--coll draws the MW collision (ground green, walls red) over the meshes."""
import os, pickle, sys
import numpy as np
from PIL import Image, ImageDraw
sys.path.insert(0, os.path.dirname(__file__))
import mw

OUT = os.path.join(mw.NFSU, 'runs', 'rockport', 'out')


def index():
    p = os.path.join(OUT, 'solid_index.pkl')
    if not os.path.exists(p):
        pickle.dump(mw.solid_index(), open(p, 'wb'))
    return pickle.load(open(p, 'rb'))


def pick(spec):
    R = mw.section_rows()
    if ',' in spec or any(c.isdigit() for c in spec):
        return spec.split(',')
    return sorted(n for n in R if n[0] in spec and R[n]['r'] and R[n]['r'] < 2000 and not n[1:].isdigit() is False and int(n[1:]) < 90)


def draw(out, rows, mpp=2.0, box=None, label=True):
    T = mw.world_tris(rows, index())
    tri = np.concatenate([w for *_, w, c, uv, s in [(a, b, g, w, c, uv, s) for a, b, g, w, c, uv, s in T]]) if T else np.zeros((0, 3, 3))
    secs = np.concatenate([np.full(len(w), s) for a, b, g, w, c, uv, s in T])
    xy = tri.reshape(-1, 3)
    if box is None:
        x0, y0 = xy[:, 0].min(), xy[:, 1].min(); x1, y1 = xy[:, 0].max(), xy[:, 1].max()
    else:
        x0, y0, x1, y1 = box
    W, H = int((x1 - x0) / mpp) + 1, int((y1 - y0) / mpp) + 1
    im = Image.new('RGB', (W, H), (20, 20, 30)); g = ImageDraw.Draw(im)
    n = np.cross(tri[:, 1] - tri[:, 0], tri[:, 2] - tri[:, 0]); L = np.linalg.norm(n, axis=1) + 1e-9
    up = np.abs(n[:, 2]) / L
    zc = tri[:, :, 2].mean(1)
    zlo, zhi = np.percentile(zc, 2), np.percentile(zc, 98)
    order = np.argsort(zc)
    for k in order:
        t = tri[k]
        if t[:, 0].max() < x0 or t[:, 0].min() > x1 or t[:, 1].max() < y0 or t[:, 1].min() > y1:
            continue
        h = np.clip((zc[k] - zlo) / (zhi - zlo + 1e-6), 0, 1)
        s = 0.45 + 0.55 * up[k]
        col = (int((60 + 195 * h) * s), int((90 + 120 * (1 - abs(h - 0.5) * 2)) * s), int((200 - 150 * h) * s))
        g.polygon([((p[0] - x0) / mpp, (y1 - p[1]) / mpp) for p in t], fill=col)
    if label:
        R = mw.section_rows()
        for nm in rows:
            r = R[nm]
            g.text(((r['x'] - x0) / mpp, (y1 - r['y']) / mpp), nm, fill=(255, 255, 255))
    im.save(out)
    print(out, W, H, 'tris', len(tri), 'frame', round(x0), round(y0), round(x1), round(y1))
    return tri


def coll_overlay(out, rows, mpp, box):
    """Collision over the visual top view: ground triangles green outline, barriers (walls) red."""
    draw(out, rows, mpp, box, label=False)
    im = Image.open(out); g = ImageDraw.Draw(im); x0, y0, x1, y1 = box
    R = mw.section_rows(); nt = nw = 0
    P = lambda p: ((p[0] - x0) / mpp, (y1 - p[1]) / mpp)
    for nm in rows:
        r = R[nm]
        for c in mw.collision_packs(r['off'], r['off'] + r['size']):
            for t in c['tris']:
                g.polygon([P(p) for p in t], outline=(60, 255, 90)); nt += 1
            for w in c['walls']:
                g.line([P(w[0]), P(w[1])], fill=(255, 40, 40), width=2); nw += 1
    im.save(out)
    print(out, 'ground tris', nt, 'walls', nw)


if __name__ == '__main__':
    a = [x for x in sys.argv if x != '--coll']
    box = tuple(map(float, a[4:8])) if len(a) >= 8 else None
    if '--coll' in sys.argv:
        coll_overlay(a[1], pick(a[2]), float(a[3]), box)
    else:
        draw(a[1], pick(a[2]), float(a[3]) if len(a) > 3 else 2.0, box)
