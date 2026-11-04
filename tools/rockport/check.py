"""check.py: offline check of out/rockport_sections.bin + rockport_polys.bin, read back with NFSU-side readers only:
ref/tools/ug1-tracks streams.sections() (the repo's NFSU stream reader) for ids / AABBs / placement counts, nfsu.parse_solid for the solids,
tools/openworld/polys.decode for the collision. Every placement's def hash must resolve to a solid of its own row, every group's texture to
the TEX row, every index to its vertex buffer. Writes out/check_topview.png: the block drawn from the NFSU data (vertex colour = baked
night light, so lamp pools show), collision walls red. usage: check.py [m_per_px]"""
import json, os, struct, sys
import numpy as np
from PIL import Image, ImageDraw
HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
from bun import NFSU, tree, skip11
import nfsu
os.environ.setdefault('NFSU1_MAIN', NFSU)
sys.path.insert(0, os.path.join(NFSU, 'ref', 'tools', 'ug1-tracks'))
import streams
sys.path.insert(0, os.path.join(NFSU, 'tools', 'openworld'))
import polys

OUT = os.path.join(NFSU, 'runs', 'rockport', 'out')


def main(mpp=1.0):
    J = json.load(open(os.path.join(OUT, 'rockport_sections.json')))
    b = open(os.path.join(OUT, 'rockport_sections.bin'), 'rb').read()
    errs = []; tris = []; cols = []; texset = set()
    for r in J['rows']:
        if r['offset'] % 0x800:
            errs.append('%s not 0x800-aligned' % r['mw'])
        row = b[r['offset']:r['offset'] + r['size']]       # positions are absolute from the row start
        t = tree(row)
        if r['mw'] == 'TEX':
            for dep, i, p, s in t:
                if i == 0x33310002:
                    texset = {struct.unpack_from('<I', row, o)[0] for o in range(p, p + s - 7, 8)}
                if i == 0x33320002 and (skip11(row, p, s)) % 128:
                    errs.append('TEX pixels not 128-aligned')
            continue
        secs = streams.sections(row)
        if len(secs) != 1 or secs[0][0] != r['id'] or secs[0][2] != r['placements']:
            errs.append('%s: streams.sections -> %s' % (r['mw'], secs))
        sol = {}
        for k, (dep, i, p, s) in enumerate(t):
            if i == 0x80134010:
                x = nfsu.parse_solid(row, t, k); sol[x['hash']] = x
                m = x['mesh']; vb = np.frombuffer(m['vb'], np.uint8).reshape(-1, 24)
                if vb.shape[0] != m['nverts']:
                    errs.append('%s %s: vb size' % (r['mw'], x['name']))
                ib = np.frombuffer(m['ib'], '<u2')
                if ib.max() >= m['nverts']:
                    errs.append('%s %s: index out of range' % (r['mw'], x['name']))
                for g in m['groups']:
                    if x['tex'][g['tex']] not in texset:
                        errs.append('%s %s: texture %08x not in TEX' % (r['mw'], x['name'], x['tex'][g['tex']]))
            if i == 0x34102:
                defs = [struct.unpack_from('<I', row, o)[0] for o in range(p, p + s - 71, 72)]
            if i == 0x34103:
                q = skip11(row, p, s)
                places = [row[o:o + 48] for o in range(q, p + s - 47, 48)]
        for pl in places:
            h = defs[struct.unpack_from('<h', pl, 12)[0]]
            if h not in sol:
                errs.append('%s: def %08x has no solid in the row' % (r['mw'], h)); continue
            m = sol[h]['mesh']
            vb = np.frombuffer(m['vb'], np.uint8).reshape(-1, 24)
            pos = vb[:, :12].copy().view('<f4'); col = vb[:, 12:15]
            rot = np.array(struct.unpack_from('<9h', pl, 0x1c), float).reshape(3, 3) / 8192
            w = pos @ rot + np.array(struct.unpack_from('<3f', pl, 0x10))
            ix = np.frombuffer(m['ib'], '<u2').astype(int).reshape(-1, 3)
            tris.append(w[ix]); cols.append(col[ix].mean(1))
            lo = np.array(struct.unpack_from('<3h', pl, 0)); hi = np.array(struct.unpack_from('<3h', pl, 6))
            if (w.min(0) < lo - 1.01).any() or (w.max(0) > hi + 1.01).any():
                errs.append('%s %s: mesh outside its placement AABB' % (r['mw'], sol[h]['name']))
    pb = open(os.path.join(OUT, 'rockport_polys.bin'), 'rb').read()
    P = [polys.decode(pb[o:o + 32]) for o in range(0, len(pb), 32)]
    T = np.concatenate(tris); C = np.concatenate(cols)
    x0, y0 = T[..., 0].min(), T[..., 1].min(); x1, y1 = T[..., 0].max(), T[..., 1].max()
    W, H = int((x1 - x0) / mpp) + 1, int((y1 - y0) / mpp) + 1
    im = Image.new('RGB', (W, H), (0, 0, 0)); g = ImageDraw.Draw(im)
    for k in np.argsort(T[:, :, 2].mean(1)):
        c = C[k]
        g.polygon([((p[0] - x0) / mpp, (y1 - p[1]) / mpp) for p in T[k]], fill=(int(c[2]), int(c[1]), int(c[0])))
    for p in P:
        if p['wall']:
            v = p['verts']; g.line([((v[0][0] - x0) / mpp, (y1 - v[0][1]) / mpp), ((v[2][0] - x0) / mpp, (y1 - v[2][1]) / mpp)], fill=(200, 30, 30))
    png = os.path.join(OUT, 'check_topview.png'); im.save(png)
    print('rows', len(J['rows']), 'placements drawn', len(tris), 'triangles', len(T), 'textures', len(texset),
          'polygons', len(P), 'ground', sum(not p['wall'] for p in P), 'walls', sum(p['wall'] for p in P))
    print('errors', len(errs)); [print('  ' + e) for e in errs[:20]]
    print(png, W, H)
    return not errs


if __name__ == '__main__':
    sys.exit(0 if main(float(sys.argv[1]) if len(sys.argv) > 1 else 1.0) else 1)
