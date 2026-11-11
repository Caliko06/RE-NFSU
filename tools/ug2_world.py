#!/usr/bin/env python3
"""ug2_world.py: NFS Underground 2 city scenery -> one world-space triangle mesh (web/ug2/city.bin).

usage: python3 -I tools/ug2_world.py [TRACKS_DIR]  (reads STREAML4RA.BUN only)     (numpy; ~1-2 min; writes web/ug2/city.bin, city_lod.bin, prints stats)
Layouts (docs in census/ug2/world.md; same engine as NFSU1, see docs/openworld/re_mesh.md and tools/openworld/mesh.py):
  chunk = u32 id, u32 size, payload; id bit 31 = container. Payload start = (chunk + 0x17) & ~0xf (file has 0x11 filler).
  0x80134010 solid > 0x134011 (u32 hash @0x10, bbox f32 @0x20/@0x30, name @0xa4) and 0x80134100 > 0x134900 (mesh header),
  0x134b01 vertices (24 B: f32 xyz, u32 BGRA colour, f32 uv; 36 B for mesh mask 0x4180, see STRIDE), 0x134b03 u16 triangle list (h[9] triangles).
  0x80034100 section > 0x34102 defs (68 B: name[32], solid hash @32 = LOD0, @36 = LOD1), 0x34103 instances (64 B:
  f32 bbox min/max @0, u16 def @24, u16 flags @26, f32 pos @32, s16 3x3 @44 / 8192; world = local * R + pos, row vectors).
Output web/ug2/city.bin: 'UG2M', u32 nverts, u32 nidx, u32 0, nverts x (f32 x,y,z, u8 r,g,b,a), nidx x u32. Raw UG2 world units."""
import os, struct, sys
import numpy as np

REPO = os.path.abspath(os.path.join(os.path.dirname(os.path.abspath(__file__)), '..'))
TRACKS = '/Users/angeldamian/RE-NFSU-UG2/Need For Speed Underground 2/TRACKS'
OUT = os.path.join(REPO, 'web', 'ug2')
SKIP = ('SKYDOME', 'PAN_', 'XO_VISTA')  # sky dome, far panorama backdrops (km away, z -900..), vista spotlights
LOD_CENTER = None  # set below from the city bbox when None
LOD_TRIS = 800_000
# Keep only scenery near the drivable city: an instance whose bbox centre (UG2 units) lies within REACH of a UG2 collision row
# (build/ug2/coll_rows.bin, tools/ug2_coll.py). FACT 2026-11-10: the full scenery spans x -3967..6750, y -5119..4989 against the
# collision's -3093..1898, -2079..3149 (backdrop walls up to z 1100); placed at R270+t, 18,745 of its vertices land on NFSU1 ground.
COLL = os.path.join(REPO, 'build', 'ug2', 'coll_rows.bin')
REACH, CELL = 160, 16
# Vertex stride and colour offset by the mesh mask (0x134900 +0xc): 24 B (xyz, BGRA @12, uv @16) for masks 0, 0x40, 0x1000;
# 36 B (xyz, normal @12, BGRA @24, uv @28) for 0x4180. Measured on STREAML4RA.BUN: vertex-buffer bytes / nv = 24.0 and 36.0
# exactly (census/ug2/tex.md, slice/ug2tex 3e17901); the exe picks the shader object from the mask at 0x5c58cf..0x5c591b.
STRIDE = {0x4180: (36, 24)}


def tree(d):
    """flat list of (id, payload offset, size, depth) for every chunk"""
    out, stack = [], [(0, len(d), 0)]
    while stack:
        o, e, dep = stack.pop()
        sub = []
        while o + 8 <= e:
            i, s = struct.unpack_from('<II', d, o)
            if o + 8 + s > e:
                break
            out.append((i, o + 8, s, dep))
            if i & 0x80000000:
                sub.append((o + 8, o + 8 + s, dep + 1))
            o += 8 + s
        stack.extend(reversed(sub))
    out.sort(key=lambda t: t[1])  # file order, parents before children
    return out


def pay(d, b, s, align=16):
    q = (b + align - 1) & ~(align - 1)
    if q > b + s:
        q = b
    return q, b + s - q


def scan(path):
    """-> (data, solids {hash: (v offset, nv, i offset, ntri, name)}, sections [(defs [(h0, h1)], instances ndarray)])"""
    d = open(path, 'rb').read()
    t = tree(d)
    solids, sections = {}, []
    k, n = 0, len(t)
    while k < n:
        i, b, s, dep = t[k]
        if i == 0x80134010:
            end, sol = b + s, {}
            k += 1
            while k < n and t[k][1] < end:
                j, b2, s2, _ = t[k]
                if j == 0x134011:
                    q, _ = pay(d, b2, s2)
                    sol['hash'] = struct.unpack_from('<I', d, q + 0x10)[0]
                    sol['name'] = d[q + 0xa4:q + 0xc0].split(b'\0')[0].decode('latin1')
                elif j == 0x134900:
                    q, _ = pay(d, b2, s2)
                    h = struct.unpack_from('<16I', d, q)
                    sol['nv'], sol['ntri'], sol['mask'] = h[13], h[9], h[3]
                elif j == 0x134b01:
                    sol['v'] = pay(d, b2, s2, 128)[0]
                elif j == 0x134b03:
                    sol['i'] = pay(d, b2, s2)[0]
                k += 1
            if 'hash' in sol and sol.get('nv') and sol.get('ntri') and 'v' in sol and 'i' in sol:
                solids.setdefault(sol['hash'], sol)
        elif i == 0x80034100:
            end, defs, inst = b + s, [], None
            k += 1
            while k < n and t[k][1] < end:
                j, b2, s2, _ = t[k]
                if j == 0x34102:  # 68-byte defs, unaligned
                    for o in range(b2, b2 + s2 - 67, 68):
                        defs.append(struct.unpack_from('<II', d, o + 32))
                elif j == 0x34103:  # 64-byte instances, aligned
                    q, l = pay(d, b2, s2)
                    inst = np.frombuffer(d, dtype=np.uint8, count=l // 64 * 64, offset=q).reshape(-1, 64)
                k += 1
            if inst is not None:
                sections.append((defs, inst))
        else:
            k += 1
    return d, solids, sections


def main():
    tracks = sys.argv[1] if len(sys.argv) > 1 else TRACKS
    # RA only: each STREAML4R?.BUN carries its own collision (0x80034130 sections: RA 255, RB 15, RC 24, RD 255, RF 16, RG 26,
    # RH 4, RR 4), so they are separate tracks drawn in their own frames (RH, RR centred on the origin); the city collision is RA's.
    files = [os.path.join(tracks, 'STREAML4RA.BUN')]
    data, sol, secs = [], {}, []
    for f in files:
        d, s, c = scan(f)
        fi = len(data)
        data.append(d)
        for h, v in s.items():
            sol.setdefault(h, dict(v, f=fi))
        secs += [(fi, defs, inst) for defs, inst in c]
        print(os.path.basename(f), 'solids', len(s), 'sections', len(c), flush=True)
    print('distinct solids', len(sol), 'sections', len(secs))

    rows = np.frombuffer(open(COLL, 'rb').read(), np.uint8).reshape(-1, 32)
    cx = (rows[:, 8:16].copy().view('<i2')[:, :3] / 8).mean(1)
    cy = (rows[:, 16:24].copy().view('<i2')[:, :3] / 8).mean(1)
    foot = np.zeros((16384 // CELL, 16384 // CELL), bool)
    foot[((cx + 8192) // CELL).astype(int), ((cy + 8192) // CELL).astype(int)] = True
    for _ in range(REACH // CELL):  # grow by REACH (4-neighbour steps)
        g = foot.copy(); g[1:] |= foot[:-1]; g[:-1] |= foot[1:]; g[:, 1:] |= foot[:, :-1]; g[:, :-1] |= foot[:, 1:]; foot = g

    def near(bb):
        i, j = int((bb[0] + bb[3]) / 2 + 8192) // CELL, int((bb[1] + bb[4]) / 2 + 8192) // CELL
        return 0 <= i < foot.shape[0] and 0 <= j < foot.shape[1] and foot[i, j]

    cache = {}

    def local(h):
        """-> (xyz f32 (nv,3), colour u8 (nv,4) BGRA->RGBA, tri idx (ntri,3) i64) or None"""
        if h in cache:
            return cache[h]
        s, r = sol.get(h), None
        if s:
            d = data[s['f']]
            st, co = STRIDE.get(s['mask'], (24, 12))
            raw = np.frombuffer(d, dtype=np.uint8, count=s['nv'] * st, offset=s['v']).reshape(-1, st)
            xyz = raw[:, :12].copy().view('<f4').reshape(-1, 3)
            col = raw[:, co:co + 4][:, [2, 1, 0, 3]].copy()
            ix = np.frombuffer(d, dtype='<u2', count=s['ntri'] * 3, offset=s['i']).reshape(-1, 3).astype(np.int64)
            ok = (ix < s['nv']).all(1) & (ix[:, 0] != ix[:, 1]) & (ix[:, 1] != ix[:, 2]) & (ix[:, 0] != ix[:, 2])
            r = (xyz, col, ix[ok]) if ok.any() and np.isfinite(xyz).all() else None
        cache[h] = r
        return r

    V, C, I, T0, FI = [], [], [], [], []  # per instance chunks
    seen, nv_tot, bad, miss, mism, skipped, far = set(), 0, 0, 0, 0, 0, 0
    center = []
    for fi, defs, inst in secs:
        for r in inst:
            w = r.tobytes()
            di = struct.unpack_from('<H', w, 24)[0]
            if di >= len(defs):
                bad += 1
                continue
            hh = defs[di][0] if defs[di][0] in sol else defs[di][1]
            if hh in sol and sol[hh]['name'].upper().startswith(SKIP):
                skipped += 1
                continue
            if not near(struct.unpack_from('<6f', w, 0)):
                far += 1
                continue
            key = (hh, w[32:62])  # same solid, position and matrix = the same object (RD repeats most of RA)
            if key in seen:
                continue
            seen.add(key)
            m = local(hh)
            if m is None:
                miss += 1
                continue
            xyz, col, ix = m
            R = np.array(struct.unpack_from('<9h', w, 44), dtype=np.float64).reshape(3, 3) / 8192.0
            pos = np.array(struct.unpack_from('<3f', w, 32), dtype=np.float64)
            wp = (xyz.astype(np.float64) @ R + pos).astype(np.float32)
            if not np.isfinite(wp).all() or np.abs(wp).max() > 1e5:
                bad += 1
                continue
            bb = np.array(struct.unpack_from('<6f', w, 0))
            if (np.abs(wp.min(0) - bb[:3]) > 2).any() or (np.abs(wp.max(0) - bb[3:]) > 2).any():
                mism += 1
            used = np.unique(ix)
            remap = np.zeros(len(wp), dtype=np.int64)
            remap[used] = np.arange(len(used))
            V.append(wp[used])
            C.append(col[used])
            I.append(remap[ix] + nv_tot)
            nv_tot += len(used)
            T0.append(len(ix))
            FI.append(fi)
            center.append(wp[used].mean(0))
    print('instances', len(V), 'bad def', bad, 'unresolved solid', miss, 'skipped sky/panorama', skipped, 'beyond REACH of collision', far, 'bbox mismatch >2 m', mism)
    for fi in sorted(set(FI)):
        q = np.concatenate([V[k] for k in range(len(V)) if FI[k] == fi])
        print(os.path.basename(files[fi]), 'instances', FI.count(fi), 'bbox', q.min(0).round(0), q.max(0).round(0))
    P = np.concatenate(V)
    Col = np.concatenate(C)
    Tri = np.concatenate(I).astype(np.uint32)
    ntri = len(Tri)
    assert np.isfinite(P).all() and Tri.max() < len(P)
    print('verts', len(P), 'tris', ntri, 'bbox', P.min(0), P.max(0))

    # colour: vertex colour; a mesh without any (all zero) would be grey by normal, none seen so far
    flat = Col[:, :3].sum(1) == 0
    if flat.any():
        a, b2, c = P[Tri[:, 0]], P[Tri[:, 1]], P[Tri[:, 2]]
        nrm = np.cross(b2 - a, c - a)
        nrm /= np.maximum(np.linalg.norm(nrm, axis=1, keepdims=True), 1e-9)
        g = (110 + 100 * np.abs(nrm[:, 2])).clip(0, 255).astype(np.uint8)
        for k in range(3):
            fv = flat[Tri[:, k]]
            Col[Tri[fv, k], :3] = g[fv, None]
        Col[flat, 3] = 255
        print('flat-coloured verts shaded by normal:', int(flat.sum()))

    os.makedirs(OUT, exist_ok=True)
    write(os.path.join(OUT, 'city.bin'), P, Col, Tri)

    if ntri > 3_000_000:
        c = np.median(P, axis=0) if LOD_CENTER is None else np.array(LOD_CENTER)
        cen = np.array(center)
        order = np.argsort(np.linalg.norm(cen[:, :2] - c[:2], axis=1))
        keep, tot = [], 0
        for ii in order:
            keep.append(ii)
            tot += T0[ii]
            if tot >= LOD_TRIS:
                break
        keep.sort()
        off = np.cumsum([0] + [len(x) for x in V])
        P2 = np.concatenate([V[k] for k in keep])
        C2 = np.concatenate([C[k] for k in keep])
        base = np.cumsum([0] + [len(V[k]) for k in keep])
        T2 = np.concatenate([(I[k] - off[k] + base[j]) for j, k in enumerate(keep)]).astype(np.uint32)
        write(os.path.join(OUT, 'city_lod.bin'), P2, C2, T2)
        print('lod centre', c, 'instances', len(keep), 'tris', len(T2))


def write(path, P, C, T):
    rec = np.zeros(len(P), dtype=[('p', '<f4', 3), ('c', 'u1', 4)])
    rec['p'], rec['c'] = P, C
    with open(path, 'wb') as f:
        f.write(b'UG2M' + struct.pack('<III', len(P), T.size, 0))
        f.write(rec.tobytes())
        f.write(T.astype('<u4').tobytes())
    print('wrote', path, os.path.getsize(path), 'bytes')


if __name__ == '__main__':
    main()
