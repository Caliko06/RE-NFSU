#!/usr/bin/env python3
"""mesh.py: world-space triangles of Olympic City from STREAML1RA.BUN (the render geometry), decoded as Speed.exe does.

Layouts (all offsets from the exe, 2026-10-27; details and addresses in build/openworld/re_mesh.md):
  Solid list 0x80134000 > solid 0x80134010 > 0x134011 (header, loader 0x53ffd0), 0x134012 (texture hash pairs),
    0x80134100 (mesh, loader 0x40c690) > 0x134900 (mesh header), 0x134b01 (vertices), 0x134b02 (groups), 0x134b03 (u16 index).
  Draw (0x40ed50, D3D9 DrawIndexedPrimitive vtbl+0x148, type 4 = TRIANGLELIST): per group start index = group +0x34,
  index count = group +0xc, vertex count = mesh header +0x34; vertex stride 24 (x,y,z f32, u32 colour, u,v f32).
  Section 0x80034100 (loader 0x4457c0): 0x34101 id @+0xc, 0x34102 defs (72 B: 6 solid hashes, LOD slots), 0x34103 placements
  (48 B, drawn by 0x445ec0, matrix by 0x445580): s16 AABB @0, s16 def @12, s16 flags @14, f32 pos @16, 3x3 s16/8192 @0x1c.
usage: python3 tools/openworld/mesh.py   (numpy, scipy, PIL; ~1 minute) -> census/openworld_mesh.json, build/openworld/visual_vs_coll.png,
build/openworld/scratch_mesh/world.npz (world triangles). Findings and addresses: build/openworld/re_mesh.md"""
import collections, os, struct, sys
import numpy as np

HERE = os.path.dirname(os.path.abspath(__file__))
REPO = os.path.abspath(os.path.join(HERE, '..', '..'))
BUN = os.path.join(REPO, 'game', 'Tracks', 'STREAML1RA.BUN')


def binhash(s):  # the game's string hash (sub_445d00 loop: h = h*0x21 + c, seed -1)
    h = 0xFFFFFFFF
    for c in s.encode('latin1'):
        h = (h * 33 + c) & 0xFFFFFFFF
    return h


class Bun:
    def __init__(self, path=BUN):
        self.d = open(path, 'rb').read()
        self.t = []
        self._tree(0, len(self.d), 0)

    def _tree(self, o, e, dep):
        d, out = self.d, self.t
        while o + 8 <= e:
            i, s = struct.unpack_from('<II', d, o)
            if o + 8 + s > e:
                break
            out.append((dep, i, o + 8, s))
            if i & 0x80000000:  # container chunks have bit 31 set
                self._tree(o + 8, o + 8 + s, dep + 1)
            o += 8 + s

    def pay(self, b, s, align=16):
        """payload start as the loaders compute it ((chunk + 0x17) & ~0xf, vertices & ~0x7f): the file holds 0x11 filler up to
        that aligned byte, so skipping the filler lands on the same address."""
        q = (b + align - 1) & ~(align - 1)
        assert q <= b + s and set(self.d[b:q]) <= {0x11}, (hex(b), hex(q))  # the gap is 0x11 filler
        return q, b + s - q


def solids(B):
    """-> dict hash -> solid dict (name, local tris, groups)."""
    d, t = B.d, B.t
    out, order = {}, []
    k = 0
    n = len(t)
    while k < n:
        dep, i, b, s = t[k]
        if i == 0x80134010:
            end = b + s
            sol = dict(off=b, mesh=None, tex=[])
            k += 1
            while k < n and t[k][2] < end:
                dep2, j, b2, s2 = t[k]
                if j == 0x134011:
                    q, l = B.pay(b2, s2)
                    sol['hash'] = struct.unpack_from('<I', d, q + 0x10)[0]
                    sol['bmin'] = struct.unpack_from('<3f', d, q + 0x20)
                    sol['bmax'] = struct.unpack_from('<3f', d, q + 0x30)
                    sol['mat'] = struct.unpack_from('<16f', d, q + 0x40)
                    sol['name'] = d[q + 0x94:q + 0xb0].split(b'\0')[0].decode('latin1')
                elif j == 0x134012:
                    sol['tex'] = [struct.unpack_from('<I', d, o)[0] for o in range(b2, b2 + s2 - 7, 8)]
                elif j == 0x80134100:
                    sol['mesh'] = mesh(B, k)
                k += 1
            out[sol['hash']] = sol
            order.append(sol)
        else:
            k += 1
    return out, order


def mesh(B, k):
    d, t = B.d, B.t
    dep, i, b, s = t[k]
    end = b + s
    m = {}
    k += 1
    while k < len(t) and t[k][2] < end:
        dep2, j, b2, s2 = t[k]
        if j == 0x134900:
            q, l = B.pay(b2, s2)
            m['h'] = struct.unpack_from('<16I', d, q)
        elif j == 0x134b01:
            q, l = B.pay(b2, s2, 128)  # loader 0x40c690 aligns the vertex chunk to 0x80 (the file does too)
            m['v'] = (q, l)
        elif j == 0x134b02:
            q, l = B.pay(b2, s2)
            m['g'] = (q, l)
        elif j == 0x134b03:
            q, l = B.pay(b2, s2)
            m['i'] = (q, l)
        k += 1
    return m


def tris(B, sol):
    """local triangles of a solid: (positions (n,3,3) f32, group ids (n,), texture hashes per group)"""
    m = sol['mesh']
    if not m or 'h' not in m or not m['h'][13] or 'v' not in m:
        return None
    h, d = m['h'], B.d
    nv, ng = h[13], h[4]
    stride = 60 if h[3] & 1 else 24  # measured: mask bit 0 selects the 60-byte format (table 0x701440, desc 0x71abb8+idx*0x38)
    vq, vl = m['v']
    iq, il = m['i']
    gq, gl = m['g']
    v = np.frombuffer(d, dtype='<f4', count=nv * stride // 4, offset=vq).reshape(nv, stride // 4)[:, :3]
    ix = np.frombuffer(d, dtype='<u2', count=il // 2, offset=iq)
    P, G = [], []
    for g in range(ng):
        cnt, = struct.unpack_from('<I', d, gq + g * 60 + 0xc)
        st, = struct.unpack_from('<I', d, gq + g * 60 + 0x34)
        ti = d[gq + g * 60 + 0x1c]
        t3 = ix[st:st + cnt].reshape(-1, 3)
        P.append(v[t3])
        G.append(np.full(len(t3), g, dtype=np.int32))
        sol.setdefault('gtex', {})[g] = sol['tex'][ti] if ti < len(sol['tex']) else 0
    if not P:
        return None
    return np.concatenate(P), np.concatenate(G)


def sections(B):
    """-> list of dict(id, defs [(6 hashes, lod s16[4])], places [(aabb, def, flags, pos, rot3x3)]) from 0x80034100."""
    d, t = B.d, B.t
    out = []
    k = 0
    while k < len(t):
        dep, i, b, s = t[k]
        if i == 0x80034100:
            end = b + s
            sec = dict(id=None, defs=[], places=[])
            k += 1
            while k < len(t) and t[k][2] < end:
                dep2, j, b2, s2 = t[k]
                if j == 0x34101:
                    q, l = B.pay(b2, s2)
                    sec['id'] = struct.unpack_from('<I', d, q + 12)[0]
                elif j == 0x34102:  # loader 0x4457c0 keeps ecx+8 (unaligned), 72-byte records
                    for o in range(b2, b2 + s2 - 71, 72):
                        sec['defs'].append((struct.unpack_from('<6I', d, o), struct.unpack_from('<4h', d, o + 0x18)))
                elif j == 0x34103:  # aligned, 48-byte records
                    q, l = B.pay(b2, s2)
                    for o in range(q, q + l - 47, 48):
                        aabb = struct.unpack_from('<6h', d, o)
                        dfn, fl = struct.unpack_from('<2h', d, o + 12)
                        pos = struct.unpack_from('<3f', d, o + 16)
                        rot = np.array(struct.unpack_from('<9h', d, o + 0x1c), dtype=np.float64).reshape(3, 3) / 8192.0
                        sec['places'].append((aabb, dfn, fl, pos, rot))
                k += 1
            out.append(sec)
        else:
            k += 1
    return out


SKIP_HASH = {0, 0xbe43edbb, 0x72923c81}  # 0x4457c0 skips these three slot values when resolving a def's solids


def texnames(B):
    """texture hash -> name, from the texture packs 0xb3300000 > 0xb3310000 > 0x33310004: each record holds a 24-byte name field
    (NUL-terminated, cut at 23 characters) followed by the u32 hash. For names under 24 characters the hash is the game's
    binhash of the name (confirmed: binhash('OBJ_WIRES_HANGING') == 0x2a0535fe stored right after it); longer names are cut
    in the field but keep the hash of the full name, which is why the stored u32 is the key."""
    import re
    tn = {}
    for dep, i, b, s in B.t:
        if i == 0x33310004:
            seg = B.d[b:b + s]
            for m in re.finditer(rb'[A-Za-z0-9_\-\.\$]{3,23}\x00', seg):
                nm = m.group()[:-1].decode()
                o = m.start() + 24
                if o + 4 <= len(seg):
                    h, = struct.unpack_from('<I', seg, o)
                    if h == binhash(nm) or len(nm) == 23:
                        tn[h] = nm
    return tn


def world_tris(B, S, secs, ndip=0.0):
    """every placed triangle of the LOD0 solid of each placement (def slots 0..3, first resolvable one), in world space.
    -> dict arrays: P (n,3,3) f32, tex (n,) u32 hash, sec (n,) u16 section id, sol (n,) solid index, fl (n,) placement flags s16; plus solid names list."""
    cache, names = {}, []
    P, T, SE, SO, FL = [], [], [], [], []
    for sec in secs:
        for aabb, dfn, fl, pos, rot in sec['places']:
            if not 0 <= dfn < len(sec['defs']):
                continue
            hs, lod = sec['defs'][dfn]
            h = next((x for x in hs[:4] if x not in SKIP_HASH and x in S), None)
            if h is None:
                continue
            if h not in cache:
                r = tris(B, S[h])
                if r is None:
                    cache[h] = None
                else:
                    gt = np.array([S[h]['gtex'][g] for g in range(int(r[1].max()) + 1)], dtype=np.uint32)
                    names.append(S[h]['name'])
                    cache[h] = (r[0].astype(np.float64), gt[r[1]], len(names) - 1)
            c = cache[h]
            if c is None:
                continue
            W = c[0] @ rot + np.array(pos)  # row vectors, as D3D / 0x445580 lay the matrix out (validated vs the AABBs)
            P.append(W.astype(np.float32))
            T.append(c[1])
            SE.append(np.full(len(W), sec['id'], dtype=np.uint16))
            SO.append(np.full(len(W), c[2], dtype=np.int32))
            FL.append(np.full(len(W), fl & 0xffff, dtype=np.uint16))
    return dict(P=np.concatenate(P), tex=np.concatenate(T), sec=np.concatenate(SE), sol=np.concatenate(SO), fl=np.concatenate(FL)), names


# ---------------------------------------------------------------- classification and rasterization
X0, Y0, W_M, H_M = -700, -2000, 3100, 2800  # the frame of build/openworld/fences.png (1 m per sample)
ROAD_PREFIX = ('RDP_ROAD', 'RDP_INTERSECT', 'RDP_RD_', 'RDP_PLAIN', 'RDP_CARPARK', 'RDD_VIADUCT', 'ARC_VIADUCTTOP', 'RDP_BRIDGEGRATE')


def is_road(name):
    return name.startswith(ROAD_PREFIX)


def raster(tri, step=1.0):
    """sample the xy projection of triangles (n,3,3) on a `step` grid (cell centres): -> (ix, iy, z) arrays; every triangle gets
    at least its centroid so slivers below one cell still count."""
    IX, IY, Z = [], [], []
    for t in tri.astype(np.float64):
        x, y, z = t[:, 0], t[:, 1], t[:, 2]
        d = (y[1] - y[2]) * (x[0] - x[2]) + (x[2] - x[1]) * (y[0] - y[2])
        cx, cy = x.mean(), y.mean()
        if abs(d) < 1e-9:
            continue
        i0, i1 = int(np.floor((x.min() - X0) / step)), int(np.floor((x.max() - X0) / step))
        j0, j1 = int(np.floor((y.min() - Y0) / step)), int(np.floor((y.max() - Y0) / step))
        gx = X0 + (np.arange(i0, i1 + 1) + 0.5) * step
        gy = Y0 + (np.arange(j0, j1 + 1) + 0.5) * step
        GX, GY = np.meshgrid(gx, gy, indexing='ij')
        a = ((y[1] - y[2]) * (GX - x[2]) + (x[2] - x[1]) * (GY - y[2])) / d
        b = ((y[2] - y[0]) * (GX - x[2]) + (x[0] - x[2]) * (GY - y[2])) / d
        c = 1 - a - b
        m = (a >= 0) & (b >= 0) & (c >= 0)
        ii, jj = np.nonzero(m)
        zz = a[m] * z[0] + b[m] * z[1] + c[m] * z[2]
        if len(ii) == 0:  # sliver: centroid only
            IX.append(np.array([int(np.floor((cx - X0) / step))])); IY.append(np.array([int(np.floor((cy - Y0) / step))]))
            Z.append(np.array([z.mean()]))
        else:
            IX.append(ii + i0); IY.append(jj + j0); Z.append(zz)
    if not IX:
        return np.zeros(0, np.int64), np.zeros(0, np.int64), np.zeros(0)
    return np.concatenate(IX).astype(np.int64), np.concatenate(IY).astype(np.int64), np.concatenate(Z)


def comp(ix, iy, z):  # sortable composite: cell key then z (z offset keeps it positive)
    return (ix * 4096 + iy) * 4096.0 + (z + 1024.0)


def covered(vis, col, tol, shifts=((0, 0),)):
    """vis, col = (ix, iy, z); True where the collision has a sample within `tol` in z in the same cell (or a shifted neighbour)."""
    cs = np.sort(comp(*col))
    out = np.zeros(len(vis[0]), bool)
    for dx, dy in shifts:
        lo = comp(vis[0] + dx, vis[1] + dy, vis[2] - tol)
        k = np.searchsorted(cs, lo)
        hi = comp(vis[0] + dx, vis[1] + dy, vis[2] + tol)
        out |= (k < len(cs)) & (cs[np.minimum(k, len(cs) - 1)] <= hi)
    return out


def collision(tracks=None):
    """ground triangles (n,3,3) and wall footprints [(a, b, flags)] of the union of the 16 tracks' TrackPolygons (polys.py)."""
    import polys
    seen, G, Wl = set(), [], []
    for t in tracks or polys.TRACKS:
        for r in polys.rows(t):
            k = polys.key(r)
            if k in seen:
                continue
            seen.add(k)
            d = polys.decode(r)
            v = d['verts']
            if d['flags'] & 0x0a:
                best = max(((np.hypot(v[i][0] - v[j][0], v[i][1] - v[j][1]), i, j) for i in range(len(v)) for j in range(i + 1, len(v))))
                Wl.append((v[best[1]][:2], v[best[2]][:2], d['flags']))
            else:
                G.append(v[:3])
                if len(v) == 4:
                    G.append([v[0], v[2], v[3]])
    return np.array(G, dtype=np.float32), Wl


def thin(img):
    """Zhang-Suen thinning of a boolean image (vectorized); -> skeleton."""
    im = img.copy().astype(np.uint8)
    while True:
        changed = False
        for step in (0, 1):
            p = np.pad(im, 1)
            P2, P3, P4, P5, P6, P7, P8, P9 = (p[:-2, 1:-1], p[:-2, 2:], p[1:-1, 2:], p[2:, 2:], p[2:, 1:-1], p[2:, :-2], p[1:-1, :-2], p[:-2, :-2])
            B = P2 + P3 + P4 + P5 + P6 + P7 + P8 + P9
            seq = [P2, P3, P4, P5, P6, P7, P8, P9, P2]
            A = sum(((seq[i] == 0) & (seq[i + 1] == 1)).astype(np.uint8) for i in range(8))
            if step == 0:
                c = (P2 * P4 * P6 == 0) & (P4 * P6 * P8 == 0)
            else:
                c = (P2 * P4 * P8 == 0) & (P2 * P6 * P8 == 0)
            m = (im == 1) & (B >= 2) & (B <= 6) & (A == 1) & c
            if m.any():
                im[m] = 0
                changed = True
        if not changed:
            return im.astype(bool)


PAVED_PREFIX = ('ARC_SIDEWALK', 'ARC_CONC', 'ARC_COURTGD', 'RDP_WATERFRONTPAVEMENT', 'TRN_DUSTYCONCRETE', 'RDP_BRICK', 'RDP_DIRT')
TOL_Z = 1.0     # measured: where both exist the visual road and the collision ground differ by < 3 cm (98 %), see re_mesh.md
NZ_MIN = 0.8    # near-horizontal: normal.z > 0.8 (slope < 37 deg); the road meshes wind consistently (all road triangles face up)


def grid_of(ix, iy, m=None):
    g = np.zeros((W_M, H_M), bool)
    ok = (ix >= 0) & (ix < W_M) & (iy >= 0) & (iy < H_M)
    if m is not None:
        ok &= m
    g[ix[ok], iy[ok]] = True
    return g


def skeleton_ends(g2, spur=6):
    """endpoints of the thinned ground mask (2 m cells) whose branch to the next junction is longer than `spur` cells."""
    from scipy import ndimage as ndi
    sk = thin(g2)
    nb = ndi.convolve(sk.astype(int), np.ones((3, 3)), mode='constant') - 1
    out = []
    for x, y in zip(*np.nonzero(sk & (nb == 1))):
        path, prev, cur = [(x, y)], None, (x, y)
        while len(path) < 40:
            nxt = [(cur[0] + dx, cur[1] + dy) for dx in (-1, 0, 1) for dy in (-1, 0, 1)
                   if (dx or dy) and 0 <= cur[0] + dx < sk.shape[0] and 0 <= cur[1] + dy < sk.shape[1]
                   and sk[cur[0] + dx, cur[1] + dy] and (cur[0] + dx, cur[1] + dy) not in path]
            if not nxt:
                break
            cur = nxt[0]
            path.append(cur)
            if nb[cur] >= 3:
                break
        if len(path) > spur or nb[path[-1]] < 3:
            out.append(path)
    return out


def main():
    import json, pickle, time
    from scipy import ndimage as ndi
    from PIL import Image, ImageDraw
    t0 = time.time()
    B = Bun()
    S, order = solids(B)
    secs = sections(B)
    Wd, names = world_tris(B, S, secs)
    tn = texnames(B)
    P = Wd['P'].astype(np.float64)
    n = np.cross(P[:, 1] - P[:, 0], P[:, 2] - P[:, 0])
    nz = n[:, 2] / np.maximum(np.linalg.norm(n, axis=1), 1e-12)
    tname = np.array([tn.get(int(t), '%08x' % t) for t in Wd['tex']])
    trs = np.array([names[i].startswith('TRS') for i in Wd['sol']])
    up = nz > NZ_MIN
    road_any = up & np.array([is_road(t) for t in tname])
    road = road_any & trs  # ground solids are the TRS* family; a road-textured prop (barge deck, XO_*) is not street
    print('road-textured up triangles outside TRS solids (dropped):', int((road_any & ~road).sum()))
    paved = up & trs & ~road & np.array([t.startswith(PAVED_PREFIX) for t in tname])
    fl_road = collections.Counter()
    for f_, a_ in zip(Wd['fl'][road], np.linalg.norm(n, axis=1)[road] / 2):
        fl_road[hex(int(f_))] += float(a_)
    print('world triangles', len(P), 'road', road.sum(), 'paved', paved.sum(), '%.1fs' % (time.time() - t0))
    vis = raster(P[road].astype(np.float32))
    pav = raster(P[paved].astype(np.float32))
    G, Wl = collision()
    col = raster(G)
    print('samples road %d paved %d coll %d  %.1fs' % (len(vis[0]), len(pav[0]), len(col[0]), time.time() - t0))
    sh = [(a, b) for a in (-1, 0, 1) for b in (-1, 0, 1)]
    cov = covered(vis, col, TOL_Z, sh)
    cov_any = covered(vis, col, 1e3, sh)  # a collision sample in the cell at any z
    gcol, gvall = grid_of(col[0], col[1]), grid_of(vis[0], vis[1])
    gvc, gvo = grid_of(vis[0], vis[1], cov), grid_of(vis[0], vis[1], ~cov)
    gvo_noz = grid_of(vis[0], vis[1], ~cov_any)
    gpav = grid_of(pav[0], pav[1])
    gvo2 = ndi.binary_opening(gvo, structure=np.ones((3, 3)))  # drop slivers narrower than 3 m
    lab, nc = ndi.label(gvo2, structure=np.ones((3, 3)))
    ids = np.arange(1, nc + 1)
    area = ndi.sum(gvo2, lab, ids)
    com = ndi.center_of_mass(gvo2, lab, ids)
    sl = ndi.find_objects(lab)
    dist_to_col = ndi.distance_transform_edt(~gcol)  # metres to the nearest collision ground cell
    comps = []
    for k in np.argsort(-area):
        if area[k] < 100:
            break
        s0 = sl[k]
        comps.append(dict(label=int(k + 1), area_m2=int(area[k]), cx=round(X0 + com[k][0] + 0.5), cy=round(Y0 + com[k][1] + 0.5),
                          bbox=[X0 + s0[0].start, Y0 + s0[1].start, X0 + s0[0].stop, Y0 + s0[1].stop],
                          min_dist_to_coll_m=round(float(dist_to_col[lab == k + 1].min()), 1)))
    print('components >= 100 m2: %d, %.1fs' % (len(comps), time.time() - t0))

    # ---- stub ends: endpoints of the thinned collision ground (2 m cells)
    g2 = gcol.reshape(W_M // 2, 2, H_M // 2, 2).any(axis=(1, 3))
    g2 = ndi.binary_closing(g2, structure=np.ones((3, 3)))
    ends = skeleton_ends(g2)
    dvis = ndi.binary_dilation(gvall, iterations=2)
    dpav = ndi.binary_dilation(gpav, iterations=2)
    wallseg = [(np.array(a), np.array(b), f) for a, b, f in Wl]
    stubs = []
    for path in ends:
        e = np.array(path[0], float)
        back = np.array(path[min(6, len(path) - 1)], float)
        u = e - back
        u /= np.linalg.norm(u) or 1
        E = np.array([X0, Y0]) + (e + 0.5) * 2  # world metres
        # tip of the ground: march along u while collision ground is within 1.5 m of the ray
        def cell(p):
            i, j = int(np.floor(p[0] - X0)), int(np.floor(p[1] - Y0))
            return i, j
        def hit(g, p, half=0):
            i, j = cell(p)
            return 0 <= i < W_M and 0 <= j < H_M and g[max(0, i - half):i + half + 1, max(0, j - half):j + half + 1].any()
        t = 0.0
        while t < 120 and hit(gcol, E + u * (t + 1), 1):
            t += 1
        T = E + u * t
        def run(g, half):  # how far past the tip a surface keeps going along u (gaps up to 4 m allowed)
            gap, d, last = 0, 0, 0
            for d in range(1, 600):
                p = T + u * d
                lat = [p + np.array([-u[1], u[0]]) * w for w in (-4, 0, 4)]
                if any(hit(g, q, half) for q in lat):
                    last, gap = d, 0
                else:
                    gap += 1
                    if gap > 4:
                        break
            return last
        road_run, pav_run = run(gvall, 1), run(gpav, 1)
        width = 0
        if road_run >= 10:  # width of the visual road across the axis, 10 m past the tip
            q, nv = T + u * 10, np.array([-u[1], u[0]])
            for sgn in (-1, 1):
                w_ = 0
                while w_ < 40 and hit(gvall, q + nv * sgn * (w_ + 1), 0):
                    w_ += 1
                width += w_
        # visual-only road components that touch the stub end: any cell within 10 m of the tip and not behind it
        touch = {}
        i0, j0 = cell(T)
        for i in range(max(0, i0 - 10), min(W_M, i0 + 11)):
            for j in range(max(0, j0 - 10), min(H_M, j0 + 11)):
                if lab[i, j] > 0 and np.hypot(i - i0, j - j0) <= 10 and (np.array([X0 + i + 0.5, Y0 + j + 0.5]) - T) @ u >= -1:
                    touch[int(lab[i, j])] = True
        tc = []
        for lid in touch:
            xs, ys = np.nonzero(lab == lid)
            d_ = np.hypot(X0 + xs + 0.5 - T[0], Y0 + ys + 0.5 - T[1]).max()
            tc.append(dict(area_m2=int(area[lid - 1]), extent_m=int(d_), mean_width_m=round(float(area[lid - 1] / max(d_, 1)), 1)))
        wd = [(np.linalg.norm(np.clip(((T - a) @ (b - a)) / max((b - a) @ (b - a), 1e-9), 0, 1)[None] * (b - a) + a - T), f) for a, b, f in wallseg
              if min(a[0], b[0]) - 20 < T[0] < max(a[0], b[0]) + 20 and min(a[1], b[1]) - 20 < T[1] < max(a[1], b[1]) + 20]
        w = min(wd) if wd else (None, None)
        stubs.append(dict(x=round(float(T[0]), 1), y=round(float(T[1]), 1), dir=[round(float(u[0]), 2), round(float(u[1]), 2)],
                          visual_road_continues_m=int(road_run), road_width_10m_past_m=int(width), paved_other_continues_m=int(pav_run), touching_visual_only_components=tc,
                          wall_dist_m=None if w[0] is None else round(float(w[0]), 1), wall_flags=None if w[1] is None else hex(w[1])))
    cont = [s for s in stubs if s['visual_road_continues_m'] >= 10]
    print('stub ends %d, visual road continues >= 10 m past the tip: %d  %.1fs' % (len(stubs), len(cont), time.time() - t0))

    # ---- picture: collision ground grey, visual-only road red, walls black (1 m per pixel, y up)
    a = np.full((H_M, W_M, 3), 255, np.uint8)
    a[gcol.T[::-1]] = (190, 190, 190)
    a[gvo2.T[::-1]] = (220, 0, 0)
    im = Image.fromarray(a)
    dr = ImageDraw.Draw(im)
    for p, q, f in Wl:
        dr.line([(p[0] - X0, H_M - (p[1] - Y0)), (q[0] - X0, H_M - (q[1] - Y0))], fill=(0, 0, 0), width=1)
    for st in stubs:  # ring at each stub end: blue = visual road continues >= 10 m past the ground tip, green = it does not
        cx, cy = st['x'] - X0, H_M - (st['y'] - Y0)
        dr.ellipse((cx - 7, cy - 7, cx + 7, cy + 7), outline=(0, 70, 255) if st['visual_road_continues_m'] >= 10 else (0, 160, 0), width=2)
    im.save(os.path.join(REPO, 'build', 'openworld', 'visual_vs_coll.png'))

    res = dict(
        frame=dict(x0=X0, y0=Y0, w=W_M, h=H_M, cell_m=1),
        params=dict(nz_min=NZ_MIN, tol_z_m=TOL_Z, road_texture_prefixes=list(ROAD_PREFIX), paved_prefixes=list(PAVED_PREFIX)),
        counts=dict(solids_unique=len(S), solids_total=len(order), sections=len(secs), placements=sum(len(s['places']) for s in secs),
                    world_triangles=int(len(P)), up_triangles=int(up.sum()), road_triangles=int(road.sum())),
        area_m2=dict(collision_ground=int(gcol.sum()), visual_road=int(gvall.sum()), visual_road_collided=int(gvc.sum()),
                     visual_road_only=int(gvo.sum()), visual_road_only_after_opening=int(gvo2.sum()),
                     visual_only_no_collision_at_any_z=int(gvo_noz.sum()), visual_paved_other=int(gpav.sum()),
                     visual_paved_other_over_no_collision=int((gpav & ~gcol).sum()), collision_without_visual_road=int((gcol & ~gvall).sum())),
        stub_summary=dict(total=len(stubs), ground_ends_at_a_wall_le_4m=sum(1 for q in stubs if q['wall_dist_m'] is not None and q['wall_dist_m'] <= 4),
                          road_continues_ge_10m=len(cont), road_continues_ge_30m=sum(1 for q in stubs if q['visual_road_continues_m'] >= 30),
                          road_continues_ge_60m=sum(1 for q in stubs if q['visual_road_continues_m'] >= 60),
                          touched_by_visual_only_component=sum(1 for q in stubs if q['touching_visual_only_components'])),
        z_of_visual_only_road_m=[round(float(v), 1) for v in np.percentile(vis[2][~cov], [0, 5, 50, 95, 100])],
        road_area_by_placement_flags={k: int(v) for k, v in sorted(fl_road.items(), key=lambda kv: -kv[1])},
        components=comps, stubs=stubs)
    json.dump(res, open(os.path.join(REPO, 'census', 'openworld_mesh.json'), 'w'), indent=0)
    np.savez_compressed(os.path.join(HERE, '..', '..', 'build', 'openworld', 'scratch_mesh', 'world.npz'), P=Wd['P'], tex=Wd['tex'], sec=Wd['sec'], sol=Wd['sol'], names=np.array(names))
    print(json.dumps(res['area_m2']), json.dumps(res['counts']))
    print('done %.1fs' % (time.time() - t0))


if __name__ == '__main__':
    main()
