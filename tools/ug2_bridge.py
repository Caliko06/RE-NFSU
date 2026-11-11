#!/usr/bin/env python3
"""ug2_bridge.py: the bridge road between the NFSU1 dead end (120,499,z43) and the UG2 road side that lands at (117,601,z43)
(docs/re/ug2_bridge.md rank 1). Called by ug2_collfile.py: apply(nf, uz, tx8, ty8, tz) -> (nf, uz, rows, mesh), nothing else.
Every number is read from the real neighbouring rows (facts table in docs/re/ug2_bridge.md), nothing is typed in but the row indexes' predicates:
  ground rows : copy of the NFSU1 end rows (surface 1, flags 0x10: quad, ground), 4 columns on the 4 north-edge points of the dead end,
                8 segments to the UG2 south ground edge (the 4 vertices y 588.8..589.6 of the moved UG2 surface-1 rows); z linear between the two edges.
  side walls  : the two NFSU1 side walls end at y 506.2 (x 114.6 / 128.6, surface 20, flags 0x16 = quad|wall|x4 z, z -508..508); they are continued to the UG2 south wall.
  opened      : the NFSU1 cap wall (x 114.6..128.6 at y 506.2) becomes the west side wall (same row number, so NFSU1 numbering is unchanged);
                the UG2 south wall rows inside the opening: one becomes the east side wall (same row number), two are clipped to the opening edge.
Row indexes stay: nothing moves, 32 ground rows are appended. The mesh (deck + 1.2 m barriers) is returned in raw UG2 units (inverse of the placement),
so web/ug2 draws it with the same model as city.bin."""
import struct

S = 8          # x,y are s16/8
NSEG = 8       # ground segments along the bridge (NFSU1 and UG2 rows are about 10 units long; 82 / 8 = 10)
ROW = '<BBBBhh4h4h4h'


def unpack(r):
    t = struct.unpack(ROW, r)
    return dict(surf=t[2], fl=t[3], base=t[4], xs=list(t[6:10]), ys=list(t[10:14]), zs=list(t[14:18]))


def sel(xs, ys):
    return xs.index(min(xs)) | ys.index(min(ys)) << 2 | xs.index(max(xs)) << 4 | ys.index(max(ys)) << 6


def pack(surf, fl, base, xs, ys, zs):
    return struct.pack(ROW, 0, sel(xs, ys), surf, fl, base, -1, *xs, *ys, *zs)


def zof(d, i):
    return d['base'] + d['zs'][i] / 256


def pack_ground(surf, fl, pts):
    """pts: 4 x (x8, y8, z float) -> row; base and s16/256 offsets as ug2_collfile.move"""
    z = [p[2] for p in pts]
    nb = round((min(z) + max(z)) / 2)
    nz = [round((v - nb) * 256) for v in z]
    assert all(abs(nb + v / 256 - u) <= 1 / 512 for v, u in zip(nz, z)) and all(abs(v) < 32768 for v in nz)
    return pack(surf, fl, nb, [p[0] for p in pts], [p[1] for p in pts], nz)


def lerp_edge(poly, x):
    """y, z of the polyline poly [(x8, y8, z)...] (sorted by x) at integer x8"""
    for (x0, y0, z0), (x1, y1, z1) in zip(poly, poly[1:]):
        if x0 <= x <= x1:
            f = (x - x0) / (x1 - x0)
            return y0 + f * (y1 - y0), z0 + f * (z1 - z0)
    raise AssertionError(x)


def apply(nf, uz, tx8, ty8, tz):
    nf, uz = list(nf), list(uz)
    D = lambda r: unpack(r)
    # --- NFSU1 end: ground rows whose north edge is the last one (y 507.9) and the three wall rows around it
    ends = [i for i, r in enumerate(nf) if D(r)['surf'] == 1 and D(r)['fl'] == 0x10 and max(D(r)['ys']) == max(D(nf[38417])['ys'])
            and 110 * S < min(D(r)['xs']) and max(D(r)['xs']) < 130 * S and 490 * S < max(D(r)['ys']) < 510 * S]
    assert ends == [38417, 38418, 38419, 38420], ends
    ytop = max(D(nf[38417])['ys'])
    top = {}
    for i in ends:
        d = D(nf[i])
        for x, y, z in zip(d['xs'], d['ys'], (zof(d, k) for k in range(4))):
            if y == ytop:
                top[x] = z
    P = sorted(top.items())                       # 5 points (x8, z) on the north edge y = ytop
    assert len(P) == 5 and len(set(z for _, z in P)) == 1, P
    walls = [i for i, r in enumerate(nf) if D(r)['surf'] == 20 and D(r)['fl'] == 0x16 and all(110 * S < x < 130 * S for x in D(r)['xs'])
             and all(450 * S < y < 520 * S for y in D(r)['ys'])]
    assert walls == [42876, 42877, 42878], walls
    wW, cap, wE = D(nf[42878]), D(nf[42877]), D(nf[42876])
    XW, XE = wW['xs'][0], wE['xs'][0]
    ycap = cap['ys'][0]
    assert set(wW['xs']) == {XW} and set(wE['xs']) == {XE} and set(cap['ys']) == {ycap} and sorted(set(cap['xs'])) == [XW, XE]
    assert ycap in wW['ys'] and ycap in wE['ys']            # the side walls end on the cap line
    # --- UG2 side (rows already in NFSU1 space)
    def inbox(d, x0, x1, y0, y1):
        return all(x0 * S <= x <= x1 * S for x in d['xs']) and all(y0 * S <= y <= y1 * S for y in d['ys'])
    g = {}
    for r in uz:
        d = D(r)
        if d['surf'] == 1 and d['fl'] in (0x00, 0x10):
            for k in range(4 if d['fl'] & 0x10 else 3):
                if 588 * S <= d['ys'][k] <= 590 * S and 100 * S <= d['xs'][k] <= 140 * S:
                    g[d['xs'][k]] = (d['ys'][k], zof(d, k))
    poly = [(x, y, z) for x, (y, z) in sorted(g.items())]
    assert len(poly) == 4 and [round(p[0] / S, 1) for p in poly] == [105.2, 115.1, 125.1, 135.1], poly
    uw = [i for i, r in enumerate(uz) if D(r)['surf'] == 20 and D(r)['fl'] == 0x16 and inbox(D(r), 105, 134.5, 588, 593)]
    assert uw == [30238, 30239, 30240], uw
    a, b, c = (D(uz[i]) for i in uw)
    assert a['xs'][2] < XW < a['xs'][3] or a['xs'][3] > XW > a['xs'][0]
    # wall line y at the opening edges, 1/8 grid
    def wall_y(d, x):
        x0, x1, y0, y1 = d['xs'][1], d['xs'][2], d['ys'][1], d['ys'][2]
        return round(y0 + (x - x0) * (y1 - y0) / (x1 - x0))
    yW = wall_y(a, XW)                                         # a spans x 105.2..115.1, XW inside
    assert c['xs'][1] < XE < c['xs'][2]
    yE = wall_y(c, XE)                                         # c spans x 125.0..134.2, XE inside
    # clipped rows (same z fields: infinite walls)
    a2 = dict(a); a2['xs'] = a['xs'][:2] + [XW, XW]; a2['ys'] = a['ys'][:2] + [yW, yW]
    c2 = dict(c); c2['xs'] = [XE, XE] + c['xs'][2:]; c2['ys'] = [yE, yE] + c['ys'][2:]
    pk = lambda d: pack(d['surf'], d['fl'], d['base'], d['xs'], d['ys'], d['zs'])
    # b (30239, x 115.1..125.0) lies wholly inside the opening: it becomes the east side wall, cap becomes the west side wall
    west = dict(cap); west['xs'] = [XW] * 4; west['ys'] = [yW, yW, ycap, ycap]            # heading south, road on its left (east), like 42878
    east = dict(b); east['xs'] = [XE] * 4; east['ys'] = [ycap, ycap, yE, yE]              # heading north, road on its left (west), like 42876
    assert cap['xs'] == [XE, XE, XW, XW] and wW['ys'][:2] == [ycap, ycap]
    nf[42877] = pk(west)
    uz[30238], uz[30239], uz[30240] = pk(a2), pk(east), pk(c2)
    # --- ground: columns on the 5 north-edge points; edge vertices on the UG2 south polyline
    V = []
    for x, z0 in P:
        y1, z1 = lerp_edge(poly, x)
        V.append([(x, round(ytop + (y1 - ytop) * k / NSEG), z0 + (z1 - z0) * k / NSEG) for k in range(NSEG + 1)])
    ground = [pack_ground(1, 0x10, [V[i][k + 1], V[i][k], V[i + 1][k], V[i + 1][k + 1]]) for k in range(NSEG) for i in range(4)]
    # --- mesh, raw UG2 units: x = ty - y', y = x' - tx, z = z' - tz (inverse of ug2_collfile.move)
    raw = lambda x8, y8, z: (ty8 / S - y8 / S, x8 / S - tx8 / S, z - tz)
    GR, BA = (80, 80, 80, 255), (184, 184, 184, 255)      # city.bin grey verts on the UG2 road end (x 90..330, y 1360..1460, z 49.2 +- 0.6): median 87
    P_, C_, T_ = [], [], []
    def quad(q, col):
        n = len(P_); P_.extend(q); C_.extend([col] * 4); T_.extend([n, n + 1, n + 2, n, n + 2, n + 3])
    for k in range(NSEG):
        for i in range(4):
            quad([raw(*V[j][m]) for j, m in ((i, k + 1), (i, k), (i + 1, k), (i + 1, k + 1))], GR)
    H = 1.2
    def zg(col, y):
        """ground z of a bridge edge column at y (1/8 units): piecewise linear over its vertices, 43.0 south of the dead end's north edge"""
        pts = [(v[1], v[2]) for v in V[col]]
        if y <= pts[0][0]:
            return pts[0][1]
        if y >= pts[-1][0]:
            return pts[-1][1]
        return next(z0 + (y - y0) * (z1 - z0) / (y1 - y0) for (y0, z0), (y1, z1) in zip(pts, pts[1:]) if y0 <= y <= y1)
    for xw, col, y0, y1 in ((XW, 0, yW, ycap), (XE, 4, ycap, yE)):
        ya = [round(y0 + (y1 - y0) * k / NSEG) for k in range(NSEG + 1)]
        for k in range(NSEG):
            z0, z1 = zg(col, ya[k]), zg(col, ya[k + 1])
            quad([raw(xw, ya[k], z0), raw(xw, ya[k], z0 + H), raw(xw, ya[k + 1], z1 + H), raw(xw, ya[k + 1], z1)], BA)
    mesh = b'UG2M' + struct.pack('<III', len(P_), len(T_), 0) + b''.join(struct.pack('<fffBBBB', *p, *c) for p, c in zip(P_, C_)) + struct.pack('<%dI' % len(T_), *T_)
    return nf, uz, ground, mesh


def check(rows):
    """static check on the final row list: drives 5 lanes from y 440 to 612 (UG2 north wall at 613.1) in 0.25 steps."""
    sub = []
    for r in rows:
        d = unpack(r)
        n = 4 if d['fl'] & 0x10 else 3
        v = [(d['xs'][k] / S, d['ys'][k] / S, zof(d, k) * (4 if d['fl'] & 4 else 1)) for k in range(n)]
        if max(p[0] for p in v) >= 100 and min(p[0] for p in v) <= 140 and max(p[1] for p in v) >= 440 and min(p[1] for p in v) <= 620:
            sub.append((d, v))
    def inside(v, x, y, eps=-1e-9):
        tri = [(v[0], v[1], v[2])] + ([(v[0], v[2], v[3])] if len(v) == 4 else [])
        for a, b, c in tri:
            den = (b[1] - c[1]) * (a[0] - c[0]) + (c[0] - b[0]) * (a[1] - c[1])
            if den == 0:
                continue
            l1 = ((b[1] - c[1]) * (x - c[0]) + (c[0] - b[0]) * (y - c[1])) / den
            l2 = ((c[1] - a[1]) * (x - c[0]) + (a[0] - c[0]) * (y - c[1])) / den
            if min(l1, l2, 1 - l1 - l2) >= eps:
                return l1 * a[2] + l2 * b[2] + (1 - l1 - l2) * c[2]
        return None
    out = {}
    for x in (116.0, 119.0, 121.7, 124.0, 127.0):
        zs, miss, multi = [], 0, 0
        y = 440.0
        while y <= 612.0:
            hit = [z for d, v in sub if d['fl'] & 0x0a == 0 and (z := inside(v, x, y)) is not None]
            if not hit:
                miss += 1
            elif 505 <= y <= 589 and sum(inside(v, x, y, 1e-6) is not None for d, v in sub if d['fl'] & 0x0a == 0) > 1:
                multi += 1
            else:
                zs.append(hit[0])
            y += 0.25
        out[x] = (len(zs), miss, multi, round(max(abs(b - a) for a, b in zip(zs, zs[1:])), 3), round(min(zs), 2), round(max(zs), 2))
    # lanes crossing a vertical-infinite wall segment (2D segment test of x=const line from y 440 to 612 (UG2 north wall at 613.1))
    cross = {}
    for x in out:
        c = 0
        for d, v in sub:
            if d['surf'] == 20 and d['fl'] & 2 and d['fl'] & 4:
                a, b = v[1], v[2]
                if (a[0] - x) * (b[0] - x) < 0:
                    yy = a[1] + (x - a[0]) * (b[1] - a[1]) / (b[0] - a[0])
                    c += 440 <= yy <= 612
        cross[x] = c
    return out, cross
