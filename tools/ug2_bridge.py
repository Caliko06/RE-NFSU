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
import json, os, struct
import numpy as np

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


REPO = os.path.abspath(os.path.join(os.path.dirname(os.path.abspath(__file__)), '..'))
MOUTH = (195, 240, 1380, 1440)        # raw UG2 box around the road side the bridge leaves from (x 223.5 east edge, y 1402..1416)
DECK, WALL = 'RDP_LANEB_WD_AA_KT', 'XW_CONDO_WALLA_1A_00'   # the outer lane strip at the mouth; the wall solid lining that road edge


def sources():
    """measured from the UG2 data at the mouth: deck = texture index + median vertex colour of the DECK strip in city.bin/city_tex.bin;
    wall = the WALL solid (xyz, colour, uv, triangles, texture per triangle), its local length, and the cross scale of its instances there"""
    import ug2_world as W, ug2_tex as T
    ug = os.path.join(REPO, 'web', 'ug2')
    tex = json.load(open(os.path.join(ug, 'tex.json')))['textures']
    tid = {t['hash']: i for i, t in enumerate(tex)}
    b = open(os.path.join(ug, 'city.bin'), 'rb').read()
    nv, ni = struct.unpack_from('<II', b, 4)
    vb = np.frombuffer(b, np.uint8, 16 * nv, 16).reshape(-1, 16)
    xyz = vb[:, :12].copy().view('<f4').reshape(-1, 3)
    ix = np.frombuffer(b, '<u4', ni, 16 + 16 * nv).reshape(-1, 3)
    t = open(os.path.join(ug, 'city_tex.bin'), 'rb').read()
    assert t[:4] == b'UG2T' and struct.unpack_from('<II', t, 4) == (nv, ni // 3)
    tt = np.frombuffer(t, '<u2', ni // 3, 20 + 8 * nv)
    k = next(i for i, x in enumerate(tex) if x.get('name') == DECK)
    c = xyz[ix].mean(1)
    x0, x1, y0, y1 = MOUTH
    v = np.unique(ix[(tt == k) & (c[:, 0] > x0) & (c[:, 0] < x1) & (c[:, 1] > y0) & (c[:, 1] < y1)])
    assert len(v) > 20, len(v)
    deck = dict(tex=k, col=tuple(int(round(q)) for q in np.median(vb[v, 12:16], 0)))
    d, sol, secs = T.scan_solids(os.path.join(W.TRACKS, 'STREAML4RA.BUN'))
    s = next(x for x in sol.values() if x['name'] == WALL)
    st, co = W.STRIDE.get(s['mask'], (24, 12))
    rw = np.frombuffer(d, np.uint8, s['nv'] * st, s['v']).reshape(-1, st)
    wx = rw[:, :12].copy().view('<f4').reshape(-1, 3).astype(np.float64)
    wc = rw[:, co:co + 4][:, [2, 1, 0, 3]]
    wuv = rw[:, co + 4:co + 12].copy().view('<f4').reshape(-1, 2)
    wi = np.frombuffer(d, '<u2', s['ntri'] * 3, s['i']).reshape(-1, 3).astype(np.int64)
    wt = np.full(len(wi), 0xffff, np.int64)
    for start, cnt, ts, _ in s['groups']:
        if ts < len(s['tex']):
            wt[start // 3:(start + cnt) // 3] = tid.get('%08x' % s['tex'][ts], 0xffff)
    ok = (wi < s['nv']).all(1) & (wi[:, 0] != wi[:, 1]) & (wi[:, 1] != wi[:, 2]) & (wi[:, 0] != wi[:, 2])
    assert (wt[ok] != 0xffff).all(), 'wall texture missing from tex.json'
    wide = []
    for defs, inst in secs:
        for r in inst:
            w = r.tobytes(); di, fl = struct.unpack_from('<HH', w, 24); bb = struct.unpack_from('<6f', w, 0)
            hh = defs[di][0] if defs[di][0] in sol else defs[di][1]
            if hh == s['hash'] and not fl & 0x10 and x0 < bb[0] < x1 and y0 < bb[1] < y1:
                R = np.array(struct.unpack_from('<9h', w, 44)).reshape(3, 3) / 8192
                wide += [np.linalg.norm(R[1]), np.linalg.norm(R[2])]
    assert len(wide) >= 4, wide
    wall = dict(mesh=(wx, wc, wuv, wi[ok], wt[ok].tolist()), len=float(np.ptp(wx[:, 0])), wide=float(np.median(wide)))
    print('bridge sources: deck tex %d %s colour %s; wall %s %d tris, local length %.2f, cross scale %.3f (from %d instances)'
          % (k, DECK, deck['col'], WALL, ok.sum(), wall['len'], wall['wide'], len(wide) // 2))
    return deck, wall


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
    assert len(uw) == 3, uw   # rows 30238..30240 before the barrier-group rows left coll_rows.bin (tools/ug2_coll.py)
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
    uz[uw[0]], uz[uw[1]], uz[uw[2]] = pk(a2), pk(east), pk(c2)
    # --- ground: columns on the 5 north-edge points; edge vertices on the UG2 south polyline
    V = []
    for x, z0 in P:
        y1, z1 = lerp_edge(poly, x)
        V.append([(x, round(ytop + (y1 - ytop) * k / NSEG), z0 + (z1 - z0) * k / NSEG) for k in range(NSEG + 1)])
    ground = [pack_ground(1, 0x10, [V[i][k + 1], V[i][k], V[i + 1][k], V[i + 1][k + 1]]) for k in range(NSEG) for i in range(4)]
    # --- mesh, raw UG2 units: x = ty - y', y = x' - tx, z = z' - tz (inverse of ug2_collfile.move)
    raw = lambda x8, y8, z: (ty8 / S - y8 / S, x8 / S - tx8 / S, z - tz)
    deck, wall = sources()
    P_, C_, UV, T_, TX = [], [], [], [], []
    def quad(q, cols, uvs, t):
        n = len(P_); P_.extend(q); C_.extend(cols); UV.extend(uvs); T_.extend([n, n + 1, n + 2, n, n + 2, n + 3]); TX.extend([t, t])
    # deck: the UG2 outer lane strip it leaves from (RDP_LANEB_WD_AA_KT): u 1 per 8 units across, v 0.025 per unit along, its vertex colour
    for k in range(NSEG):
        for i in range(4):
            jm = ((i, k + 1), (i, k), (i + 1, k), (i + 1, k + 1))
            uvs = [(1 + (V[j][m][0] - V[0][m][0]) / S / 8, (V[j][m][1] - ytop) / S * 0.025) for j, m in jm]
            quad([raw(*V[j][m]) for j, m in jm], [deck['col']] * 4, uvs, deck['tex'])
    def zg(col, y):
        """ground z of a bridge edge column at y (1/8 units): piecewise linear over its vertices, 43.0 south of the dead end's north edge"""
        pts = [(v[1], v[2]) for v in V[col]]
        if y <= pts[0][0]:
            return pts[0][1]
        if y >= pts[-1][0]:
            return pts[-1][1]
        return next(z0 + (y - y0) * (z1 - z0) / (y1 - y0) for (y0, z0), (y1, z1) in zip(pts, pts[1:]) if y0 <= y <= y1)
    # side barriers: the road-edge wall solid of the mouth (XW_CONDO_WALLA_1A_00), one copy per segment, scaled as its real instances
    xyz, wc, wuv, wix, wtx = wall['mesh']
    for xw, col, y0, y1 in ((XW, 0, yW, ycap), (XE, 4, ycap, yE)):
        ya = [round(y0 + (y1 - y0) * k / NSEG) for k in range(NSEG + 1)]
        for k in range(NSEG):
            p0, p1 = (np.array(raw(xw, ya[k + j], zg(col, ya[k + j]))) for j in (0, 1))
            ax = p1 - p0
            ax2 = ax[:2] / np.hypot(*ax[:2])
            R = np.array([ax / wall['len'], [-ax2[1] * wall['wide'], ax2[0] * wall['wide'], 0], [0, 0, wall['wide']]])
            wp = xyz @ R + p0
            n = len(P_)
            P_.extend(map(tuple, wp)); C_.extend(map(tuple, wc)); UV.extend(map(tuple, wuv)); T_.extend((wix + n).ravel().tolist()); TX.extend(wtx)
    mesh = b'UG2M' + struct.pack('<III', len(P_), len(T_), 0) + b''.join(struct.pack('<fffBBBB', *p, *c) for p, c in zip(P_, C_)) + struct.pack('<%dI' % len(T_), *T_)
    side = b'UG2T' + struct.pack('<IIII', len(P_), len(TX), 0, 0) + struct.pack('<%df' % (2 * len(UV)), *(c for u in UV for c in u)) + struct.pack('<%dH' % len(TX), *TX)
    return nf, uz, ground, mesh, side


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
