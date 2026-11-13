#!/usr/bin/env python3
"""ug2_groundcheck.py: offline compare of the drawn UG2 ground (web/ug2/city.bin + bridge.bin) with the collision ground
(build/openworld/TRACKB1010.lzc wsrc rows) under every GPS road node (web/gps/roads.json, NFSU1 frame).
Mesh files are raw UG2 units: placed here as ug2world.js PLACE (x' = y + tx, y' = -x + ty, z' = z + tz).
Collision ground rows = flags & 0x0e == 0 (not wall 0x04 / 0x02 / 0x08), tris (v0 v1 v2), quad flag 0x10 adds (v0 v2 v3); layout as tools/ug2_coll.py verts().
Per node: visible = horizontal (|nz|>0.7) mesh tri covering (x,y), the one whose z is nearest the node z within +-6 m; collision likewise.
Kinds: cover (a drawn surface 0.25..4 m above collision), no_coll (visible road, no collision), no_vis (collision, nothing drawn), dz (>0.25 m apart), overlap (two drawn surfaces 0.03..0.5 m apart near ground).
usage: .venv/bin/python tools/ug2_groundcheck.py     writes census/ug2/ground_gaps.tsv and .png"""
import json, math, os, struct, sys
import numpy as np

HERE = os.path.dirname(os.path.abspath(__file__)); REPO = os.path.abspath(os.path.join(HERE, '..'))
sys.path.insert(0, HERE); sys.path.insert(0, os.path.join(HERE, 'hopper'))
TX, TY, TZ = -1287.375, 812.25, -6.203125
CELL, WIN, ZONE = 16.0, 6.0, 60.0
VT = np.dtype([('p', '<f4', 3), ('c', 'u1', 4)])


def mesh(name):
    b = open(os.path.join(REPO, 'web/ug2', name), 'rb').read()
    nv, ni = struct.unpack_from('<II', b, 4)
    v = np.frombuffer(b, VT, nv, 16)['p'].astype(np.float64)
    ix = np.frombuffer(b, '<u4', ni, 16 + 16 * nv).reshape(-1, 3)
    return np.stack([v[:, 1] + TX, -v[:, 0] + TY, v[:, 2] + TZ], 1)[ix]   # (N,3,3) placed


def coll_tris():
    import q_owcoll2_lzc as lzc, q_owcoll2_sim as sim
    d = lzc.exe_decode(open(os.path.join(REPO, 'build/openworld/TRACKB1010.lzc'), 'rb').read())
    wd = sim.World(d)
    a = np.frombuffer(d, np.uint8, wd.n_wsrc * 32, wd.wsrc).reshape(-1, 32)
    fl = a[:, 3]; base = a[:, 4:6].copy().view('<i2')[:, 0].astype(np.float64)
    xs, ys, zs = (a[:, o:o + 8].copy().view('<i2').astype(np.float64) for o in (8, 16, 24))
    ok = (fl & 0x0e) == 0
    P = np.stack([xs / 8, ys / 8, base[:, None] + zs / 256], 2)   # (N,4,3)
    t1, t2 = P[ok][:, [0, 1, 2]], P[ok & ((fl & 0x10) != 0)][:, [0, 2, 3]]
    return np.concatenate([t1, t2])


def horiz(T):
    n = np.cross(T[:, 1] - T[:, 0], T[:, 2] - T[:, 0])
    l = np.linalg.norm(n, axis=1)
    return T[(l > 1e-9) & (np.abs(n[:, 2]) > 0.7 * l)]


class Grid:
    def __init__(self, T):
        self.T = T
        lo = np.floor(T[:, :, :2].min(1) / CELL).astype(np.int64); hi = np.floor(T[:, :, :2].max(1) / CELL).astype(np.int64)
        w = hi - lo + 1; cnt = (w[:, 0] * w[:, 1]); cnt = np.minimum(cnt, 4000)
        tid = np.repeat(np.arange(len(T)), cnt)
        k = np.arange(cnt.sum()) - np.repeat(np.cumsum(cnt) - cnt, cnt)
        cx = lo[tid, 0] + k % w[tid, 0]; cy = lo[tid, 1] + k // w[tid, 0]
        key = (cx + 20000) * 40000 + (cy + 20000)
        o = np.argsort(key, kind='stable'); self.key, self.tid = key[o], tid[o]

    def at(self, px, py, pz):
        """per point: sorted heights (list) of tris covering (px,py) within WIN of pz"""
        key = (np.floor(px / CELL).astype(np.int64) + 20000) * 40000 + np.floor(py / CELL).astype(np.int64) + 20000
        s, e = np.searchsorted(self.key, key, 'left'), np.searchsorted(self.key, key, 'right')
        c = e - s; pi = np.repeat(np.arange(len(px)), c)
        ti = self.tid[np.repeat(s, c) + np.arange(c.sum()) - np.repeat(np.cumsum(c) - c, c)]
        A, B, C = (self.T[ti, i] for i in range(3))
        x, y = px[pi], py[pi]
        d = (B[:, 1] - C[:, 1]) * (A[:, 0] - C[:, 0]) + (C[:, 0] - B[:, 0]) * (A[:, 1] - C[:, 1])
        d = np.where(np.abs(d) < 1e-12, 1e-12, d)
        l1 = ((B[:, 1] - C[:, 1]) * (x - C[:, 0]) + (C[:, 0] - B[:, 0]) * (y - C[:, 1])) / d
        l2 = ((C[:, 1] - A[:, 1]) * (x - C[:, 0]) + (A[:, 0] - C[:, 0]) * (y - C[:, 1])) / d
        l3 = 1 - l1 - l2; e0 = -1e-4
        m = (l1 >= e0) & (l2 >= e0) & (l3 >= e0)
        z = l1 * A[:, 2] + l2 * B[:, 2] + l3 * C[:, 2]
        m &= np.abs(z - pz[pi]) <= WIN
        return pi[m], z[m]


def nearest(pi, z, n, pz):
    best = np.full(n, np.nan); bd = np.full(n, 1e9)
    for i, zz in zip(pi, z):
        pass
    o = np.lexsort((np.abs(z - pz[pi]), pi)); pi, z = pi[o], z[o]
    f = np.r_[True, pi[1:] != pi[:-1]]
    best[pi[f]] = z[f]
    return best


def main():
    R = json.load(open(os.path.join(REPO, 'web/gps/roads.json')))
    N = np.array(R['nodes'], np.float64); n = len(N)
    vis = horiz(np.concatenate([mesh('city.bin'), mesh('bridge.bin')])); print('visible horizontal tris', len(vis))
    col = horiz(coll_tris()); print('collision ground tris', len(col))
    gv, gc = Grid(vis), Grid(col)
    # in the city = a drawn surface within 48 m of the node (any height); else an NFSU1 node, skipped
    foot = set(map(tuple, np.unique(np.floor(vis[:, :, :2].mean(1) / CELL).astype(np.int64), axis=0)))
    cx, cy = np.floor(N[:, 0] / CELL).astype(int), np.floor(N[:, 1] / CELL).astype(int)
    incity = np.array([any((a + i, b + j) in foot for i in (-3, -2, -1, 0, 1, 2, 3) for j in (-3, -2, -1, 0, 1, 2, 3)) for a, b in zip(cx, cy)])
    print('nodes in city footprint', incity.sum(), 'of', n)
    pv, zv = gv.at(N[:, 0], N[:, 1], N[:, 2]); pc, zc = gc.at(N[:, 0], N[:, 1], N[:, 2])
    vh, ch = nearest(pv, zv, n, N[:, 2]), nearest(pc, zc, n, N[:, 2])
    # overlap: two drawn surfaces 0.03..0.5 m apart at the node
    ov = np.zeros(n, bool); ovd = np.zeros(n)
    o = np.lexsort((zv, pv)); p2, z2 = pv[o], zv[o]
    same = p2[1:] == p2[:-1]; dz = np.diff(z2)
    for i in np.nonzero(same & (dz > 0.03) & (dz < 0.5))[0]:
        ov[p2[i]] = True; ovd[p2[i]] = max(ovd[p2[i]], dz[i])
    hv, hc = ~np.isnan(vh), ~np.isnan(ch)
    delta = np.where(hv & hc, vh - ch, 0)
    kind = np.full(n, '', object)
    kind[incity & hv & ~hc] = 'no_coll'; kind[incity & ~hv & hc] = 'no_vis'
    kind[incity & hv & hc & (np.abs(delta) > 0.25)] = 'dz'
    # cover: a drawn horizontal surface 0.25..4 m above the collision ground (or the node z): the car drives inside it
    ref = np.where(hc, ch, N[:, 2]); up = zv - ref[pv]
    cv = np.zeros(n, bool); cvd = np.zeros(n)
    for i, u in zip(pv[(up > 0.25) & (up <= 4)], up[(up > 0.25) & (up <= 4)]): cv[i] = True; cvd[i] = max(cvd[i], u)
    kind[incity & cv & (kind != 'no_coll')] = 'cover'
    kind[incity & hv & hc & (kind == '') & ov] = 'overlap'
    mag = np.where(kind == 'no_coll', 99, np.where(kind == 'no_vis', 98, np.where(kind == 'dz', np.abs(delta), np.where(kind == 'cover', cvd, ovd))))
    fl = np.nonzero(kind != '')[0]
    print('flagged', len(fl), {k: int((kind == k).sum()) for k in ('no_coll', 'no_vis', 'dz', 'cover', 'overlap')})
    # zones: 60 m grid-flood on flagged nodes, per kind
    edges = np.array(R['edges']); nb = {}
    for a, b in edges: nb.setdefault(a, []).append(b); nb.setdefault(b, []).append(a)
    rows, zid = [], np.full(n, -1)
    cell = {}
    for i in fl: cell.setdefault((kind[i], int(N[i, 0] // ZONE), int(N[i, 1] // ZONE)), []).append(i)
    # merge neighbouring cells of one kind (union find)
    par = {k: k for k in cell}
    def f(k):
        while par[k] != k: par[k] = par[par[k]]; k = par[k]
        return k
    for (k, a, b) in cell:
        for i in (-1, 0, 1):
            for j in (-1, 0, 1):
                if (k, a + i, b + j) in cell: par[f((k, a, b))] = f((k, a + i, b + j))
    groups = {}
    for key, ids in cell.items(): groups.setdefault(f(key), []).extend(ids)
    out = []
    for g in groups.values():
        g = np.array(g); k = kind[g[0]]
        w = g[np.argmax(mag[g])]; ctr = N[g].mean(0)
        j = g[np.argmin(np.linalg.norm(N[g, :2] - ctr[:2], axis=1))]    # node nearest the centre, so the spawn sits on a road
        z = vh[j] if hv[j] else (ch[j] if hc[j] else N[j, 2])
        nbs = nb.get(j, [j]); q = N[nbs[0]] - N[j]
        head = int(round(math.atan2(q[1], q[0]) / (2 * math.pi) * 65536)) % 65536
        out.append((k, len(g), mag[w], N[j, 0], N[j, 1], z, head))
    out.sort(key=lambda r: (-r[1]))
    with open(os.path.join(REPO, 'census/ug2/ground_gaps.tsv'), 'w') as fo:
        fo.write('zone\tx\ty\tz\tkind\tnodes\tworst_delta\tRN_SPAWN\n')
        for zi, (k, c, m, x, y, z, h) in enumerate(out, 1):
            wd = {'no_coll': 'no collision', 'no_vis': 'no drawn ground'}.get(k, '%.2f' % m)
            fo.write('%d\t%.1f\t%.1f\t%.1f\t%s\t%d\t%s\t%.1f:%.1f:%.1f:%d\n' % (zi, x, y, z, k, c, wd, x, y, z + 0.5, h))
    print('zones', len(out), {k: sum(1 for r in out if r[0] == k) for k in ('no_coll', 'no_vis', 'dz', 'cover', 'overlap')})
    # map (PIL): street edges grey, zones ringed
    from PIL import Image, ImageDraw
    ic = N[incity]; x0, y0, x1, y1 = ic[:, 0].min() - 50, ic[:, 1].min() - 50, ic[:, 0].max() + 50, ic[:, 1].max() + 50
    S = 1000 / max(x1 - x0, y1 - y0)
    T = lambda x, y: ((x - x0) * S, (y1 - y) * S)
    im = Image.new('RGB', (int((x1 - x0) * S) + 1, int((y1 - y0) * S) + 1), 'black'); dr = ImageDraw.Draw(im)
    for a, b in edges:
        if incity[a] or incity[b]: dr.line([T(*N[a, :2]), T(*N[b, :2])], fill=(90, 90, 110))
    col_ = {'no_coll': 'red', 'no_vis': 'cyan', 'dz': 'yellow', 'cover': 'orange', 'overlap': 'magenta'}
    for k, c, m, x, y, z, h in out:
        u, v = T(x, y); r = 4 + min(c, 100) ** 0.5
        dr.ellipse([u - r, v - r, u + r, v + r], outline=col_[k], width=2)
    dr.text((6, 6), 'red no_coll  cyan no_vis  yellow dz  orange cover  magenta overlap  (60 m zones)', fill='white')
    im.save(os.path.join(REPO, 'census/ug2/ground_gaps.png')); print('done', im.size)

if __name__ == '__main__':
    main()
