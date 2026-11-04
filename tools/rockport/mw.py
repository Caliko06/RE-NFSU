"""mw.py: read NFS Most Wanted (PC) track data: sections, solids (meshes), scenery placements, collision.
Layouts and where they come from: docs/openworld/re_rockport.md."""
import os, struct, sys
import numpy as np
sys.path.insert(0, os.path.dirname(__file__))
from bun import *

STREAM = os.path.join(MW_TRACKS, 'STREAML2RA.BUN')
_d = None


def data():
    global _d
    if _d is None:
        _d = open_map(STREAM)
    return _d


def section_rows():
    return {r['name']: r for r in mw_section_table() if r['size']}


def _mesh(d, t, k):
    """t[k] = 0x80134100 (mesh container). Loader 0x6e3ee0. -> dict(groups=[...], vbs=[np arrays])"""
    dep, i, b, s = t[k]
    hdr = None; groups = []; ib = None; vbs = []; mats = []
    j = k + 1
    while j < len(t) and t[j][2] < b + s:
        _, c, p, n = t[j]
        if c == 0x134900:
            q = (p - 8 + 0x17) & ~0xf
            hdr = struct.unpack_from('<16I', d, q)
        elif c == 0x134b02:
            q = (p - 8 + 0x17) & ~0xf
            for g in range(hdr[4]):
                o = q + g * 0x68
                groups.append(dict(bmin=struct.unpack_from('<3f', d, o), bmax=struct.unpack_from('<3f', d, o + 0xc),
                                   tex=list(d[o + 0x18:o + 0x1d]), fmt=struct.unpack_from('<I', d, o + 0x30)[0],
                                   flags=struct.unpack_from('<I', d, o + 0x38)[0], nverts=struct.unpack_from('<I', d, o + 0x3c)[0],
                                   ntris=struct.unpack_from('<I', d, o + 0x40)[0], start=struct.unpack_from('<I', d, o + 0x44)[0],
                                   nidx=struct.unpack_from('<I', d, o + 0x5c)[0], raw=bytes(d[o:o + 0x68])))
        elif c == 0x134b03:
            q = (p - 8 + 0x17) & ~0xf
            ib = np.frombuffer(d, '<u2', hdr[11], q)
        elif c == 0x134b01:
            q = (p - 8 + 0x87) & ~0x7f
            vbs.append(bytes(d[q:p + n]))
        elif c == 0x134c02:
            mats.append(d[p:p + n].split(b'\0')[0].decode('latin1'))
        j += 1
    # 0x6e3ee0: each VB goes to the next group; following groups with the same format (+0x30) share it.
    vb_of = []; v = -1; prev = None
    for g in groups:
        if prev is None or g['fmt'] != prev:
            v += 1
        vb_of.append(v); prev = g['fmt']
    for g, v, in zip(groups, vb_of):
        g['vb'] = v
    for g, m in zip(groups, mats):
        g['mat'] = m
    return dict(hdr=hdr, groups=groups, ib=ib, vbs=vbs)


def vb_array(raw, nverts):
    """-> (stride, pos[n,3], color u8[n,4] BGRA, uv[n,2], normal[n,3])"""
    stride = len(raw) // nverts if nverts else 0
    a = np.frombuffer(raw, np.uint8)[:stride * nverts].reshape(nverts, stride)
    pos = a[:, 0:12].copy().view('<f4')
    nrm = a[:, 12:24].copy().view('<f4')
    col = a[:, 24:28].copy()
    uv = a[:, 28:36].copy().view('<f4')
    return stride, pos, col, uv, nrm


def solids(a, b):
    """All solids in the byte range [a, b) of the stream. -> dict hash -> solid"""
    d = data()
    t = tree(d, a, b)
    out = {}
    k = 0
    while k < len(t):
        dep, i, p, s = t[k]
        if i == 0x80134010:
            sol = dict(tex=[], mesh=None)
            j = k + 1
            while j < len(t) and t[j][2] < p + s:
                _, c, p2, n2 = t[j]
                if c == 0x134011:
                    q = skip11(d, p2, n2)
                    sol['hash'] = struct.unpack_from('<I', d, q + 0x10)[0]
                    sol['bmin'] = struct.unpack_from('<3f', d, q + 0x20)
                    sol['bmax'] = struct.unpack_from('<3f', d, q + 0x30)
                    sol['mat'] = struct.unpack_from('<16f', d, q + 0x40)
                    sol['name'] = d[q + 0xa0:p2 + n2].split(b'\0')[0].decode('latin1')
                elif c == 0x134012:
                    sol['tex'] = [struct.unpack_from('<I', d, o)[0] for o in range(p2, p2 + n2 - 7, 8)]
                elif c == 0x80134100:
                    sol['mesh'] = _mesh(d, t, j)
                j += 1
            out[sol['hash']] = sol
            k = j
        else:
            k += 1
    return out


def scenery(a, b):
    """Scenery sections 0x80034100 in [a, b): LoaderScenery (MW 0x7311f0, decomp Scenery.hpp).
    0x34101 header (+0xc section number), 0x34102 SceneryInfo 72 B (name[24], 4 LOD solid hashes @0x18),
    0x34103 SceneryInstance 64 B (bbox f32 x6, exclude flags @0x18, pos f32 @0x20, rot s16[9] @0x2c /8192, info index s16 @0x3e)."""
    d = data()
    res = []
    for dep, i, p, s in tree(d, a, b, maxdep=0):
        if i != 0x80034100:
            continue
        sec = dict(infos=[], inst=[])
        for c, p2, n2 in children(d, p, s):
            q = skip11(d, p2, n2); L = p2 + n2 - q
            if c == 0x34101:
                sec['number'] = struct.unpack_from('<I', d, q + 0xc)[0]
            elif c == 0x34102:
                q = p2 + (n2 % 72)
                for o in range(q, p2 + n2 - 71, 72):
                    sec['infos'].append(dict(name=d[o:o + 24].split(b'\0')[0].decode('latin1'), hashes=struct.unpack_from('<4I', d, o + 0x18)))
            elif c == 0x34103:
                q = p2 + (n2 % 64)
                for o in range(q, p2 + n2 - 63, 64):
                    rot = np.array(struct.unpack_from('<9h', d, o + 0x2c), float).reshape(3, 3) / 8192.0
                    res_i = dict(bmin=struct.unpack_from('<3f', d, o), bmax=struct.unpack_from('<3f', d, o + 0xc),
                                 flags=struct.unpack_from('<I', d, o + 0x18)[0], pos=struct.unpack_from('<3f', d, o + 0x20),
                                 rot=rot, info=struct.unpack_from('<h', d, o + 0x3e)[0])
                    sec['inst'].append(res_i)
        res.append(sec)
    return res


def solid_index():
    """hash -> list of row names that hold that solid (headers only)."""
    d = data(); idx = {}
    for r in mw_section_table():
        if not r['size']:
            continue
        for dep, i, p, s in tree(d, r['off'], r['off'] + r['size']):
            if i == 0x134011:
                q = skip11(d, p, s)
                idx.setdefault(struct.unpack_from('<I', d, q + 0x10)[0], []).append(r['name'])
    return idx


def world_tris(rows, solid_rows=None):
    """Triangles in world space for every scenery instance in the given L2RA rows.
    -> list of (inst_name, solid, group, tri xyz [n,3,3], colors [n,3,4], uvs [n,3,2])"""
    R = section_rows()
    cache = {}
    def rowsolids(nm):
        if nm not in cache:
            r = R[nm]; cache[nm] = solids(r['off'], r['off'] + r['size'])
        return cache[nm]
    idx = solid_rows or {}
    out = []
    for nm in rows:
        r = R[nm]
        for sec in scenery(r['off'], r['off'] + r['size']):
            for ins in sec['inst']:
                if ins['info'] < 0 or ins['info'] >= len(sec['infos']):
                    continue
                info = sec['infos'][ins['info']]
                h = info['hashes'][0]
                sol = rowsolids(nm).get(h)
                if sol is None:
                    for other in idx.get(h, []):
                        sol = rowsolids(other).get(h)
                        if sol: break
                if sol is None or not sol['mesh']:
                    continue
                m = sol['mesh']
                arrays = {}
                for g in m['groups']:
                    if g['vb'] not in arrays:
                        nv = sum(x['nverts'] for x in m['groups'] if x['vb'] == g['vb'])
                        arrays[g['vb']] = vb_array(m['vbs'][g['vb']], nv)
                    stride, pos, col, uv, nrm = arrays[g['vb']]
                    ix = m['ib'][g['start']:g['start'] + g['nidx']].astype(int).reshape(-1, 3)
                    w = pos @ ins['rot'] + np.array(ins['pos'])
                    out.append((info['name'], sol, g, w[ix], col[ix], uv[ix], sec['number']))
    return out


def _ugroup(d, o):
    """Serialized UGroup at o (UGroup.hpp): tag, flags (group count = flags >> 5), data count, offset (16-B units)
    -> (tag, [subgroups], {(type, index): (data_addr, count, size)})"""
    tag, fl, nd, off = struct.unpack_from('<4I', d, o)
    ng = fl >> 5
    arr = o + off * 16
    groups = [_ugroup(d, arr + g * 16) for g in range(ng)]
    datas = {}
    for k in range(nd):
        e = arr + ng * 16 + k * 16
        t, f, c, of = struct.unpack_from('<4I', d, e)
        datas[(t >> 16, t & 0xffff)] = (e + of, c, f >> 8)
    return tag, groups, datas


def collision_packs(a, b):
    """Collision packs 0x3b801 in [a, b) (LoaderWCollisionPack 0x64ad80, WCollisionPack::Resolve 0x7639b0).
    -> list of dict(section, tris [n,3,3] world (MW render axes, z up), surface u8[n], flags u8[n], inst idx[n],
                    walls [m,4,3] vertical quads (bottom a, bottom b, top b, top a), wall_surface u16[m], wall_inst[m])
    Barriers (walls): article + 0x10 + strips size, 32 B each (pt0 vec4, pt1 vec4; WCollision.h), surface u16 @+0xc.
    Code facts (MW 1.3): instance matrix 0x7632b0 = rows (inv row0, (0,1,0) or cross when flags&3, inv row2, inv pos):
    world -> local (0x486610, row vectors); local -> world inverts it (0x763b40 -> 0x5c8cc0).
    Article 'ca'<n> picked by instance +0x1a. Strip sphere i at article + 0x10 + 16 i (centre f32x3, radius u16 / 16,
    offset u16 @0xe); strip at article + 0x10 + offset (0x76c9b0). Strip = packed verts 8 B (s16 x,y,z / 128 + sphere centre,
    u8 surface, u8 flags); vertex count = u16 @+6, strip flags u16 @+0xe; triangle k = verts k..k+2 (0x762530/0x762640),
    surface of the third vertex. Face flags & 8 = skipped by the ground query (0x763bb0)."""
    d = data(); out = []
    for dep, i, p, s in tree(d, a, b, maxdep=0):
        if i != 0x3b801:
            continue
        q = (p + 15) & ~15
        crp, sec = struct.unpack_from('<2I', d, q)
        tag, (arti,), _ = _ugroup(d, q + 16)
        _, _, datas = arti
        ci = datas.get((0x6369, 0))  # 'ci'
        tris = []; surf = []; fl = []; who = []; walls = []; wsurf = []; wwho = []
        if ci:
            for n in range(ci[1]):
                o = ci[0] + n * 64
                r0 = np.array(struct.unpack_from('<3f', d, o))
                flags, = struct.unpack_from('<H', d, o + 0x12)
                art_i, = struct.unpack_from('<H', d, o + 0x1a)
                r2 = np.array(struct.unpack_from('<3f', d, o + 0x20))
                ip = np.array(struct.unpack_from('<3f', d, o + 0x30))
                r1 = np.cross(r2, r0) if flags & 3 else np.array([0., 1., 0.])
                M = np.eye(4); M[0, :3] = r0; M[1, :3] = r1; M[2, :3] = r2; M[3, :3] = ip
                W = np.linalg.inv(M)
                ca = datas.get((0x6361, art_i))  # 'ca'
                if not ca:
                    continue
                art = ca[0]
                nstrips, ssize, nedges, esize = struct.unpack_from('<4H', d, art)
                for k in range(nedges):  # WCollisionBarrier 32 B: pt0 (x,y,z,w), pt1 (x,y,z,1/xz length); y bot/top = min/max
                    e = np.frombuffer(d, '<f4', 8, art + 0x10 + ssize + 32 * k).astype(float)
                    a, b = e[0:3], e[4:7]
                    y0, y1 = min(a[1], b[1]), max(a[1], b[1])
                    quad = np.array([[a[0], y0, a[2]], [b[0], y0, b[2]], [b[0], y1, b[2]], [a[0], y1, a[2]]])
                    walls.append((np.c_[quad, np.ones(4)] @ W)[:, :3])
                    wsurf.append(struct.unpack_from('<H', d, art + 0x10 + ssize + 32 * k + 0xc)[0]); wwho.append(n)
                for k in range(nstrips):
                    sp = art + 0x10 + 16 * k
                    c = np.array(struct.unpack_from('<3f', d, sp))
                    soff, = struct.unpack_from('<H', d, sp + 0xe)
                    st = art + 0x10 + soff
                    nv, = struct.unpack_from('<H', d, st + 6)
                    v = np.frombuffer(d, '<i2', nv * 4, st).reshape(nv, 4)
                    pts = v[:, :3] / 128.0 + c
                    sb = (v[:, 3].astype(np.int32) & 0xffff)
                    loc = np.stack([pts[0:nv - 2], pts[1:nv - 1], pts[2:nv]], 1)
                    w = np.concatenate([loc, np.ones(loc.shape[:2] + (1,))], 2) @ W
                    tris.append(w[..., :3]); surf.append(sb[2:] & 0xff); fl.append(sb[2:] >> 8)
                    who.append(np.full(nv - 2, n))
        cat = lambda L, shape: np.concatenate(L) if L else np.zeros(shape)
        out.append(dict(section=sec, tris=phys_to_render(cat(tris, (0, 3, 3))), surface=cat(surf, 0).astype(int),
                        flags=cat(fl, 0).astype(int), inst=cat(who, 0).astype(int),
                        walls=phys_to_render(np.array(walls).reshape(-1, 4, 3)), wall_surface=np.array(wsurf, int),
                        wall_inst=np.array(wwho, int)))
    return out


def phys_to_render(t):
    """MW physics axes (x, y up, z) -> render axes (x, y, z up): render = (z, -x, y). Measured: C56 pack lands on the
    row centre (1454, 111) with z 92..106; ground check against the visual mesh in re_rockport.md."""
    return np.stack([t[..., 2], -t[..., 0], t[..., 1]], -1)


def textures(a, b):
    """Texture packs 0xb3300000 in [a, b) -> dict hash -> (record 124 B, compression 32 B, pixel bytes).
    Record +0x24 hash, +0x30 pixel offset from the 0x33320002 data start (128-aligned, 0x11 filler before it), +0x38 size."""
    d = data(); out = {}
    for dep, i, p, s in tree(d, a, b, maxdep=0):
        if i != 0xb3300000:
            continue
        recs = []; cmps = []; base = None
        for dep2, j, p2, s2 in tree(d, p, p + s):
            if j == 0x33310004:
                recs = [bytes(d[o:o + 124]) for o in range(p2, p2 + s2 - 123, 124)]
            elif j == 0x33310005:
                cmps = [bytes(d[o:o + 32]) for o in range(p2, p2 + s2 - 31, 32)]
            elif j == 0x33320002:
                base = (p2 - 8 + 0x87) & ~0x7f
        for r, c in zip(recs, cmps):
            off, = struct.unpack_from('<I', r, 0x30); n, = struct.unpack_from('<I', r, 0x38)
            out[struct.unpack_from('<I', r, 0x24)[0]] = (r, c, bytes(d[base + off:base + off + n]))
    return out
