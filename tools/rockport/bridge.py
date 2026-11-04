"""bridge.py: a road bridge from Olympic City's north dead end to the Rockport block's south-east exit (OWNER 2026-11-02).
merge.py calls make(city_rows, block_rows) with the TrackPolygon rows (32 B) of both and gets the bridge's NFSU section row, its
collision rows, the wall rows it opens and the spawn at its city foot. Ends measured on the collision (2026-11-02 survey):
- city: a 27.6 m strip running NNE between infinite walls (flags 0x16), capped at y 789..823 (walls 1553.6,796.6 -> 1503,822.5), z 51;
- block: the C54 street mouth at y ~1385 (walls 1677,1397 -> 1693,1367 and 1719,1393 -> 1702,1428; road TRN_TC_RoadB_CHOP_C14), z 99..101.
Textures come from the block's TEX row (preloaded): asphalt 0x28cd68e6 (the mouth's own road), barrier 0x43ad0af8, concrete 0x089fd9a2."""
import struct, zlib
import numpy as np
import build, nfsu

ID = 3034                       # after the block rows 3020..3033; id%100 >= 20 (build.ID_BASE)
A, A_DIR = np.array([1526.0, 770.0]), np.array([0.453, 0.891])    # centre of the walled city strip (walls 0x16 1503.8,752.8 -> 1522.2,789 and 1521.2,733.1 -> 1553.6,796.6), along it
B, B_DIR = np.array([1696.0, 1404.0]), np.array([-0.47, 0.88])   # 20 m inside the block mouth (ground x 1678..1714 at y 1397), heading in
STEP, HALF, THICK = 4.0, 8.0, 1.2                                # station spacing, half deck width (4 lanes of 4 m), deck depth m
BAR_H, BAR_T = 0.9, 0.4                                          # barrier height and thickness
BLEND = 60.0                                                     # m of each end where the grade eases from flat
PILLAR_EVERY, PILLAR_HALF, PILLAR_DROP = 60.0, 1.2, 45.0
ASPHALT, BARRIER, CONCRETE = 0x28cd68e6, 0x43ad0af8, 0x089fd9a2
UNLIT = 26                                                       # NFSU unlit road luminance (build.NIGHT_BASE middle)


def dec(r):
    """TrackPolygon -> (flags, verts f64[n,3]) (build.poly_row is the inverse)."""
    fl, base = r[3], struct.unpack_from('<h', r, 4)[0]
    n = 4 if fl & 0x10 else 3
    v = np.c_[np.array(struct.unpack_from('<4h', r, 8)) / 8, np.array(struct.unpack_from('<4h', r, 16)) / 8,
              np.array(struct.unpack_from('<4h', r, 24)) / 256 + base]
    if fl & 4:
        v[:, 2] *= 4
    return fl, v[:n]


class Ground:
    """Height of the ground polygons (no 0x2 wall flag) under a point, from an 8 m grid."""
    def __init__(self, rows):
        self.cells = {}
        for r in rows:
            fl, v = dec(r)
            if fl & 2:
                continue
            tris = [v[[0, 1, 2]]] + ([v[[0, 2, 3]]] if len(v) == 4 else [])
            for t in tris:
                lo, hi = np.floor(t[:, :2].min(0) / 8).astype(int), np.floor(t[:, :2].max(0) / 8).astype(int)
                for i in range(lo[0], hi[0] + 1):
                    for j in range(lo[1], hi[1] + 1):
                        self.cells.setdefault((i, j), []).append(t)

    def z(self, p, ref=None):
        best = None
        for t in self.cells.get((int(np.floor(p[0] / 8)), int(np.floor(p[1] / 8))), []):
            a, b, c = t
            d = (b[1] - c[1]) * (a[0] - c[0]) + (c[0] - b[0]) * (a[1] - c[1])
            if abs(d) < 1e-9:
                continue
            l1 = ((b[1] - c[1]) * (p[0] - c[0]) + (c[0] - b[0]) * (p[1] - c[1])) / d
            l2 = ((c[1] - a[1]) * (p[0] - c[0]) + (a[0] - c[0]) * (p[1] - c[1])) / d
            if min(l1, l2, 1 - l1 - l2) < -1e-6:
                continue
            z = l1 * a[2] + l2 * b[2] + (1 - l1 - l2) * c[2]
            if best is None or (ref is not None and abs(z - ref) < abs(best - ref)) or (ref is None and z > best):
                best = z
        return best


def centreline():
    """Cubic Hermite A -> B, resampled every STEP m: points f64[n,2], unit tangents, arc length."""
    k = np.linalg.norm(B - A)
    ta, tb = A_DIR / np.linalg.norm(A_DIR) * k, B_DIR / np.linalg.norm(B_DIR) * k
    t = np.linspace(0, 1, 4001)[:, None]
    P = (2 * t**3 - 3 * t**2 + 1) * A + (t**3 - 2 * t**2 + t) * ta + (-2 * t**3 + 3 * t**2) * B + (t**3 - t**2) * tb
    s = np.r_[0, np.cumsum(np.linalg.norm(np.diff(P, axis=0), axis=1))]
    S = np.linspace(0, s[-1], int(np.ceil(s[-1] / STEP)) + 1)
    Q = np.c_[np.interp(S, s, P[:, 0]), np.interp(S, s, P[:, 1])]
    T = np.gradient(Q, axis=0); T /= np.linalg.norm(T, axis=1)[:, None]
    return Q, T, S


def grade(S, sa, sb, za, zb):
    """Deck height: flat before sa and after sb, straight grade between, eased over BLEND m at both ends (C1)."""
    L = sb - sa
    b = min(BLEND, L / 3)
    g = (zb - za) / (L - b)                       # grade of the straight part so the eased ends still reach zb
    def f(x):
        if x <= 0:
            return 0.0
        if x < b:
            return g * x * x / (2 * b)
        if x < L - b:
            return g * (b / 2 + (x - b))
        if x < L:
            y = L - x
            return (zb - za) - g * y * y / (2 * b)
        return zb - za
    return np.array([za + f(x - sa) for x in S])


class Mesh:
    """24 B vertices (pos, BGRA, uv0) grouped by texture; every face is emitted in both windings (no cull surprises)."""
    def __init__(self):
        self.v, self.g = [], {}

    def quad(self, tex, p, uv, col):
        base = len(self.v)
        for k in range(4):
            self.v.append((p[k], col[k], uv[k]))
        self.g.setdefault(tex, []).extend([base, base + 1, base + 2, base, base + 2, base + 3,
                                           base, base + 2, base + 1, base, base + 3, base + 2])

    def solid(self, name, centre):
        P = np.array([v[0] for v in self.v]) - centre
        vb = np.zeros(len(self.v), [('p', '<f4', 3), ('c', 'u1', 4), ('t', '<f4', 2)])
        vb['p'] = P; vb['c'] = [v[1] for v in self.v]; vb['t'] = [v[2] for v in self.v]
        assert len(self.v) <= 0xffff
        tex = sorted(self.g); groups = []; ib = []; start = 0
        for h in tex:
            ix = np.array(self.g[h])
            q = P[ix]
            groups.append(dict(bmin=q.min(0), bmax=q.max(0), nidx=len(ix), tex=tex.index(h), start=start, flags=0))
            ib.append(ix.astype('<u2').tobytes()); start += len(ix)
        ntris = start // 3
        return dict(hash=zlib.crc32(name.encode()), flags=0x13, f14=ntris & 0xffff, f18=len(tex) << 8, bmin=P.min(0), bmax=P.max(0),
                    name=name, tex=tex, light=None,
                    mesh=dict(vb=vb.tobytes(), ib=b''.join(ib), groups=groups, ntris=ntris, nverts=len(self.v), vfmt=0))


def lit(p, lamps):
    """NFSU night vertex colour: unlit grey plus the warm lamp pools of build.night() (BGRA, alpha 255 as convert_solid stores it)."""
    add = sum(build.LAMP_I * max(0.0, 1 - np.linalg.norm(p - L) / build.LAMP_R) ** 2 for L in lamps) if lamps else 0.0
    c = np.clip(np.round(UNLIT + add * build.LAMP_RGB), 0, 255).astype(int)
    return (int(c[0]), int(c[1]), int(c[2]), 255)


def segment_hits(a, b, strips):
    """True when the xy segment a-b crosses or touches any deck quad (sampled every metre)."""
    n = max(2, int(np.linalg.norm(b - a)) + 2)
    for t in np.linspace(0, 1, n):
        p = a + (b - a) * t
        for q in strips:
            s = [(q[(k + 1) % 4][0] - q[k][0]) * (p[1] - q[k][1]) - (q[(k + 1) % 4][1] - q[k][1]) * (p[0] - q[k][0]) for k in range(4)]
            if min(s) >= -1e-6 or max(s) <= 1e-6:
                return True
    return False


def make(city_rows, block_rows):
    Q, T, S = centreline()
    N = np.c_[-T[:, 1], T[:, 0]]                                  # left of travel
    gc, gb = Ground(city_rows), Ground(block_rows)
    on_c = np.array([gc.z(q) is not None for q in Q]); on_b = np.array([gb.z(q) is not None for q in Q])
    ia = int(np.argmin(on_c)) - 1                                 # last station over the city street
    ib = len(Q) - int(np.argmin(on_b[::-1]))                      # first station over the block street
    assert 0 < ia < ib < len(Q) - 1, (ia, ib)
    za, zb = gc.z(Q[ia]), gb.z(Q[ib])
    Z = grade(S, S[ia], S[ib], za, zb)
    lo, hi = max(0, ia - 3), min(len(Q) - 1, ib + 3)             # the deck reaches 12 m onto each street
    L, R = Q + N * HALF, Q - N * HALF

    def zat(i, p):                                                # deck height; over a street it follows that street
        g = gc.z(p, Z[i]) if i <= ia else gb.z(p, Z[i]) if i >= ib else None
        return g if g is not None else Z[i]
    lamps = [np.r_[Q[i] + N[i] * (HALF + 0.5) * (1 if (i // 12) % 2 else -1), Z[i] + 8.0]
             for i in range(ia, ib, 12)]                          # every 48 m, alternating sides, 8 m up
    m, polys, strips = Mesh(), [], []
    cols = 5                                                      # lane boundaries across the deck
    for i in range(lo, hi):
        j = i + 1
        across = [[Q[k] + N[k] * HALF * (1 - 2 * c / (cols - 1)) for c in range(cols)] for k in (i, j)]
        top = [[np.r_[p, zat(k, p) + 0.02] for p in across[n]] for n, k in enumerate((i, j))]
        for c in range(cols - 1):
            p = [top[0][c], top[0][c + 1], top[1][c + 1], top[1][c]]
            uv = [(0, S[i] / 32), (1, S[i] / 32), (1, S[j] / 32), (0, S[j] / 32)]
            m.quad(ASPHALT, p, uv, [lit(x, lamps) for x in p])
        strips.append(np.array([L[i], R[i], R[j], L[j]]))
        ground = [np.r_[L[i], zat(i, L[i])], np.r_[L[j], zat(j, L[j])], np.r_[R[j], zat(j, R[j])], np.r_[R[i], zat(i, R[i])]]
        g = np.array(ground)
        if np.cross(g[1] - g[0], g[2] - g[0])[2] < 0:
            g = g[[0, 3, 2, 1]]
        polys.append(build.poly_row(g, build.GROUND_SURF, 0x10))
        if not ia <= i < ib:
            continue                                              # the streets keep their own walls, kerbs and sides
        for side, E in ((1, L), (-1, R)):
            n_out = N * side
            a, b = E[i], E[j]
            za_, zb_ = Z[i], Z[j]
            w = np.array([[a[0], a[1], za_ - 2], [a[0], a[1], za_ + 3], [b[0], b[1], zb_ + 3], [b[0], b[1], zb_ - 2]])
            nrm = np.cross(w[1] - w[0], w[2] - w[0])[:2]
            if np.dot(nrm, -n_out[i]) < 0:                        # NFSU walls face their road (build.polys)
                w = w[[3, 2, 1, 0]]
            polys.append(build.poly_row(w, build.WALL_SURF, 0x12))
            ao, bo = a + n_out[i] * BAR_T, b + n_out[j] * BAR_T
            v0, v1 = S[i] / 8, S[j] / 8
            for p, uv in ((  # barrier inner face, top, outer face
                    [np.r_[a, za_], np.r_[b, zb_], np.r_[b, zb_ + BAR_H], np.r_[a, za_ + BAR_H]], [(v0, 1), (v1, 1), (v1, 0), (v0, 0)]),
                    ([np.r_[a, za_ + BAR_H], np.r_[b, zb_ + BAR_H], np.r_[bo, zb_ + BAR_H], np.r_[ao, za_ + BAR_H]], [(v0, 0), (v1, 0), (v1, 0.1), (v0, 0.1)]),
                    ([np.r_[ao, za_ + BAR_H], np.r_[bo, zb_ + BAR_H], np.r_[bo, zb_ - THICK], np.r_[ao, za_ - THICK]], [(v0, 0), (v1, 0), (v1, 1), (v0, 1)])):
                m.quad(BARRIER, p, uv, [lit(x, lamps) for x in p])
        p = [np.r_[L[i] + N[i] * BAR_T, Z[i] - THICK], np.r_[L[j] + N[j] * BAR_T, Z[j] - THICK],
             np.r_[R[j] - N[j] * BAR_T, Z[j] - THICK], np.r_[R[i] - N[i] * BAR_T, Z[i] - THICK]]
        m.quad(CONCRETE, p, [(0, S[i] / 8), (0, S[j] / 8), (4, S[j] / 8), (4, S[i] / 8)], [(14, 14, 14, 255)] * 4)   # underside
    for s in np.arange(S[ia] + PILLAR_EVERY / 2, S[ib] - 20, PILLAR_EVERY):
        i = int(round(s / STEP)); c = Q[i]; z0 = Z[i] - THICK
        d = [T[i] * PILLAR_HALF + N[i] * PILLAR_HALF, -T[i] * PILLAR_HALF + N[i] * PILLAR_HALF,
             -T[i] * PILLAR_HALF - N[i] * PILLAR_HALF, T[i] * PILLAR_HALF - N[i] * PILLAR_HALF]
        for k in range(4):
            a, b = c + d[k], c + d[(k + 1) % 4]
            p = [np.r_[a, z0], np.r_[b, z0], np.r_[b, z0 - PILLAR_DROP], np.r_[a, z0 - PILLAR_DROP]]
            m.quad(CONCRETE, p, [(0, 0), (1, 0), (1, PILLAR_DROP / 4), (0, PILLAR_DROP / 4)],
                   [(20, 20, 20, 255), (20, 20, 20, 255), (4, 4, 4, 255), (4, 4, 4, 255)])
    # walls that close either street where the deck joins it (the city's infinite caps, any block wall across the mouth)
    reach_c = [q for k, q in enumerate(strips) if lo + k <= ia + 2]
    reach_b = [q for k, q in enumerate(strips) if lo + k >= ib - 3]

    def opened(rows, reach):
        out = set()
        for k, r in enumerate(rows):
            fl, v = dec(r)
            if fl & 2 and segment_hits(v[0, :2], v[2 if len(v) > 2 else 1, :2], reach):
                out.add(k)
        return out
    drop_c, drop_b = opened(city_rows, reach_c), opened(block_rows, reach_b)
    centre = np.r_[Q[(lo + hi) // 2], (za + zb) / 2]
    sol = m.solid('XB_ROCKPORT_BRIDGE', centre)
    corners = np.array([v[0] for v in m.v])
    d = bytearray(72)
    struct.pack_into('<I', d, 0, sol['hash'])
    struct.pack_into('<f', d, 0x44, float(np.linalg.norm(corners.max(0) - corners.min(0)) / 2))
    pl = bytearray(48)
    struct.pack_into('<6h', pl, 0, *np.r_[np.floor(corners.min(0)), np.ceil(corners.max(0))].astype(int))
    struct.pack_into('<hH', pl, 0xc, 0, 0x60)
    struct.pack_into('<3f', pl, 0x10, *centre)
    struct.pack_into('<9h', pl, 0x1c, 8192, 0, 0, 0, 8192, 0, 0, 0, 8192)
    rb = b''; p = 0
    for f in (lambda p: nfsu.solid_list(p, 'Location1\\Rockport\\BRIDGE.bin', 'R%d' % ID, [sol]),
              lambda p: nfsu.pad_to(p, 16),
              lambda p: nfsu.section(p, ID, [bytes(d)], [bytes(pl)], nfsu.bvh([bytes(pl)]))):
        c = f(p); rb += c; p += len(c)
    back = Q[max(0, ia - 12)]                                     # spawn 48 m before the deck leaves the city street, facing it
    yaw = int(round(np.arctan2(T[ia, 1], T[ia, 0]) * 32768 / np.pi))
    spawn = (float(back[0]), float(back[1]), float(gc.z(back) + 0.7), yaw)
    # the volume a car sweeps over the deck, from 16 m before it leaves the city street to where it meets the block street: scenery
    # with a triangle inside it is cleared by merge.clear_path (the city's north edge is ringed with backdrop buildings)
    vol = [(np.array([L[i] + N[i] * 2, R[i] - N[i] * 2, R[i + 1] - N[i + 1] * 2, L[i + 1] + N[i + 1] * 2]), Z[i] + 0.3, Z[i] + 25.0)
           for i in range(max(0, ia - 4), ib)]
    return dict(section=rb, polys=polys, drop_city=drop_c, drop_block=drop_b, spawn=spawn, vol=vol,
                stats=dict(length=round(S[ib] - S[ia]), z=(round(za, 2), round(zb, 2)), max_grade=round(float(np.abs(np.diff(Z)).max() / STEP), 3),
                           verts=len(m.v), tris=sol['mesh']['ntris'], polys=len(polys), opened=(len(drop_c), len(drop_b)), bytes=len(rb)))
