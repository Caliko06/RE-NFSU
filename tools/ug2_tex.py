#!/usr/bin/env python3
"""ug2_tex.py: NFS Underground 2 world textures -> PNG + the mesh -> texture link (facts: census/ug2/tex.md).

usage: .venv/bin/python tools/ug2_tex.py [TRACKS_DIR]     (numpy, PIL; a few minutes)
Writes (all generated, git-ignored):
  web/ug2/tex/<hash8>.png   mip 0 of every texture a city solid uses, RGBA
  web/ug2/tex.json          {"textures":[{hash,file,w,h,fmt,alpha,pack}], "materials":[hash,...], stats}
  web/ug2/city_tex.bin      side file for city.bin ('UG2T'): u32 nverts, u32 ntri, u32 ntex, u32 nmat,
                            nverts x (f32 u, f32 v), ntri x u16 texture index (into tex.json textures, 0xffff = none),
                            ntri x u16 material index (into tex.json materials, 0xffff = default material).
                            Vertex and triangle order are exactly city.bin's (verified against it when present).
Proof for each layout: census/ug2/tex.md.
"""
import glob, json, os, struct, sys
import numpy as np
from PIL import Image

HERE = os.path.dirname(os.path.abspath(__file__))
REPO = os.path.abspath(os.path.join(HERE, '..'))
sys.path.insert(0, HERE)
import ug2_world as W  # tree(), pay(), SKIP, TRACKS: same chunk walk and same instance filter as city.bin

OUT = os.path.join(REPO, 'web', 'ug2')
GPU_FMT = {0x31545844: 'DXT1', 0x33545844: 'DXT3', 0x35545844: 'DXT5', 0x29: 'P8', 0x15: 'A8R8G8B8'}


def kids(d, o, e):
    while o + 8 <= e:
        i, s = struct.unpack_from('<II', d, o)
        if o + 8 + s > e:
            break
        yield o, i, s
        o += 8 + s


# ---------------------------------------------------------------- texture packs (loader 0x494ea0 -> header parser 0x494380)
def packs(d):
    """top-level 0xb3300000 packs (+ stand-alone 0xb3320000 data bound by key, 0x494f2e) -> list of dicts"""
    out, blobs = [], {}

    def header(o, e):
        pk = {'recs': [], 'gpu': []}
        for o3, i3, s3 in kids(d, o, e):
            p = o3 + 8
            if i3 == 0x33310001:   # 0x494380: edi = header, +0x60 = key (0x494f2e looks the data up by it)
                pk['name'] = d[p + 4:p + 0x20].split(b'\0')[0].decode('latin1')
                pk['key'] = struct.unpack_from('<I', d, p + 0x60)[0]
            elif i3 == 0x33310004:  # 0x494380: count = size / 0x7c
                for k in range(s3 // 0x7c):
                    r = p + 0x7c * k
                    v = struct.unpack_from('<8I2h', d, r + 0x24)
                    pk['recs'].append(dict(name=d[r + 0xc:r + 0x24].split(b'\0')[0].decode('latin1'), hash=v[0],
                                           pix=v[3], pal=v[4], npix=v[5], npal=v[6], mip0=v[7], w=v[8], h=v[9],
                                           mips=d[r + 0x4e], atest=d[r + 0x55], blend=d[r + 0x56]))
            elif i3 == 0x33310005:  # 0x494380: count = size >> 5; D3DFORMAT at +0x14
                pk['gpu'] = [struct.unpack_from('<I', d, p + 0x20 * k + 0x14)[0] for k in range(s3 // 32)]
        return pk

    def data(o, e, pk):
        node = None
        for o3, i3, s3 in kids(d, o, e):
            if i3 == 0x33320001:
                node = struct.unpack_from('<I', d, o3 + 8 + 0xc)[0]
            elif i3 == 0x33320002:
                blobs.setdefault(node, []).append(((o3 + 8 + 0x7f) & ~0x7f, o3 + 8 + s3))  # 128-byte aligned (0x494f49)
                if pk is not None:
                    pk['blob'] = blobs[node][-1]

    for o, i, s in kids(d, 0, len(d)):
        if i == 0xb3300000:
            pk = None
            for o2, i2, s2 in kids(d, o + 8, o + 8 + s):
                if i2 == 0xb3310000:
                    pk = header(o2 + 8, o2 + 8 + s2)
                    out.append(pk)
                elif i2 == 0xb3320000:
                    data(o2 + 8, o2 + 8 + s2, pk)
        elif i == 0xb3320000:
            data(o + 8, o + 8 + s, None)
    for pk in out:
        if 'blob' not in pk and blobs.get(pk.get('key')):
            pk['blob'] = blobs[pk['key']].pop(0)
    return out


def mip_bytes(fmt, w, h, n):
    t = 0
    for _ in range(max(n, 1)):
        if fmt.startswith('DXT'):
            t += max(1, (w + 3) // 4) * max(1, (h + 3) // 4) * (8 if fmt == 'DXT1' else 16)
        else:
            t += w * h * (1 if fmt == 'P8' else 4)
        w, h = max(1, w // 2), max(1, h // 2)
    return t


# ---------------------------------------------------------------- pixel decoders (standard S3TC / D3D9 layouts)
def rgb565(c):
    r, g, b = (c >> 11) & 31, (c >> 5) & 63, c & 31
    return np.stack([(r * 255 + 15) // 31, (g * 255 + 31) // 63, (b * 255 + 15) // 31], -1).astype(np.int32)


def color_blocks(blk, dxt1):
    """blk (n, 8) u8 -> (n, 16, 4) RGBA (index order row-major 4x4)"""
    c0 = blk[:, 0].astype(np.int32) | blk[:, 1].astype(np.int32) << 8
    c1 = blk[:, 2].astype(np.int32) | blk[:, 3].astype(np.int32) << 8
    p0, p1 = rgb565(c0), rgb565(c1)
    pal = np.zeros((len(blk), 4, 4), np.int32)
    pal[:, :, 3] = 255
    pal[:, 0, :3], pal[:, 1, :3] = p0, p1
    four = (c0 > c1) | (not dxt1)
    pal[:, 2, :3] = np.where(four[:, None], (2 * p0 + p1) // 3, (p0 + p1) // 2)
    pal[:, 3, :3] = np.where(four[:, None], (p0 + 2 * p1) // 3, 0)
    if dxt1:
        pal[:, 3, 3] = np.where(four, 255, 0)
    bits = blk[:, 4].astype(np.uint32) | blk[:, 5].astype(np.uint32) << 8 | blk[:, 6].astype(np.uint32) << 16 | blk[:, 7].astype(np.uint32) << 24
    idx = (bits[:, None] >> (2 * np.arange(16, dtype=np.uint32))[None]) & 3
    return np.take_along_axis(pal, idx[:, :, None].astype(np.int64).repeat(4, 2), 1)


def decode_dxt(raw, w, h, fmt):
    bw, bh = max(1, (w + 3) // 4), max(1, (h + 3) // 4)
    bs = 8 if fmt == 'DXT1' else 16
    blk = np.frombuffer(raw, np.uint8, count=bw * bh * bs).reshape(-1, bs)
    px = color_blocks(blk[:, bs - 8:], fmt == 'DXT1')
    if fmt == 'DXT3':
        a = blk[:, :8].astype(np.int32)
        nib = np.stack([a & 15, a >> 4], -1).reshape(-1, 16)   # low nibble first
        px[:, :, 3] = nib * 17
    elif fmt == 'DXT5':
        a0, a1 = blk[:, 0].astype(np.int32), blk[:, 1].astype(np.int32)
        al = np.zeros((len(blk), 8), np.int32)
        al[:, 0], al[:, 1] = a0, a1
        for k in range(2, 8):
            al[:, k] = np.where(a0 > a1, ((8 - k) * a0 + (k - 1) * a1) // 7,
                                np.where(k < 6, ((6 - k) * a0 + (k - 1) * a1) // 5, 0 if k == 6 else 255))
        bits = np.zeros(len(blk), np.uint64)
        for k in range(6):
            bits |= blk[:, 2 + k].astype(np.uint64) << np.uint64(8 * k)
        idx = ((bits[:, None] >> (3 * np.arange(16, dtype=np.uint64))[None]) & np.uint64(7)).astype(np.int64)
        px[:, :, 3] = np.take_along_axis(al, idx, 1)
    img = px.reshape(bh, bw, 4, 4, 4).transpose(0, 2, 1, 3, 4).reshape(bh * 4, bw * 4, 4)
    return img[:h, :w].astype(np.uint8)


def decode(d, pk, r, fmt):
    base = pk['blob'][0]
    w, h = r['w'], r['h']
    if fmt.startswith('DXT'):
        return decode_dxt(d[base + r['pix']:base + r['pix'] + r['mip0']], w, h, fmt)
    if fmt == 'P8':   # palette 256 x u32 at record +0x34. Exe 0x5ce1e9..0x5ce23b copies palette[index] (a whole dword) into a
        # D3DFMT_A8R8G8B8 (0x15) texture, so the file bytes are B,G,R,A like every A8R8G8B8 pixel.
        idx = np.frombuffer(d, np.uint8, count=w * h, offset=base + r['pix'])
        pal = np.frombuffer(d, np.uint8, count=1024, offset=base + r['pal']).reshape(256, 4)[:, [2, 1, 0, 3]]
        return pal[idx].reshape(h, w, 4)
    if fmt == 'A8R8G8B8':
        a = np.frombuffer(d, np.uint8, count=w * h * 4, offset=base + r['pix']).reshape(h, w, 4)
        return a[:, :, [2, 1, 0, 3]]
    return None


# ---------------------------------------------------------------- solids: texture table, material table, draw groups, uv
def scan_solids(path):
    """-> (data, solids {hash: dict}, sections) like ug2_world.scan, plus per solid: tex hashes, mat hashes, groups"""
    d = open(path, 'rb').read()
    t = W.tree(d)
    solids, sections = {}, []
    k, n = 0, len(t)
    while k < n:
        i, b, s, dep = t[k]
        if i == 0x80134010:
            end, sol = b + s, {'tex': [], 'mat': [], 'groups': []}
            k += 1
            while k < n and t[k][1] < end:
                j, b2, s2, _ = t[k]
                if j == 0x134011:
                    q, _ = W.pay(d, b2, s2)
                    sol['hash'] = struct.unpack_from('<I', d, q + 0x10)[0]
                    sol['name'] = d[q + 0xa4:q + 0xc0].split(b'\0')[0].decode('latin1')
                elif j == 0x134012:   # solid loader 0x493c02: solid+0x2c = chunk payload (+8, unaligned); pairs (hash, ptr)
                    sol['tex'] = [struct.unpack_from('<I', d, b2 + 8 * m)[0] for m in range(s2 // 8)]
                elif j == 0x134013:   # 0x493c14: solid+0x3c = payload +8
                    sol['mat'] = [struct.unpack_from('<I', d, b2 + 8 * m)[0] for m in range(s2 // 8)]
                elif j == 0x134900:
                    q, _ = W.pay(d, b2, s2)
                    h = struct.unpack_from('<16I', d, q)
                    sol['nv'], sol['ntri'], sol['ngrp'], sol['mask'] = h[13], h[9], h[4], h[3]   # +0x10 group count (0x5c58a4), +0xc vertex mask
                elif j == 0x134b01:
                    sol['v'] = W.pay(d, b2, s2, 128)[0]
                elif j == 0x134b02:   # 0x5cc2dd: mesh+0x14 = payload aligned 16; groups 0x3c apart (0x5c58c7)
                    sol['gq'] = W.pay(d, b2, s2)[0]
                elif j == 0x134b03:
                    sol['i'] = W.pay(d, b2, s2)[0]
                k += 1
            if sol.get('gq') is not None:
                for g in range(sol.get('ngrp', 0)):
                    o = sol['gq'] + 0x3c * g
                    cnt = struct.unpack_from('<I', d, o + 0x0c)[0]
                    start = struct.unpack_from('<I', d, o + 0x34)[0]
                    sol['groups'].append((start, cnt, d[o + 0x1c], d[o + 0x20]))   # start idx, idx count, tex slot, mat slot
            if 'hash' in sol and sol.get('nv') and sol.get('ntri') and 'v' in sol and 'i' in sol:
                solids.setdefault(sol['hash'], sol)
        elif i == 0x80034100:
            end, defs, inst, empty6 = b + s, [], None, False
            k += 1
            while k < n and t[k][1] < end:
                j, b2, s2, _ = t[k]
                if j == 0x34102:
                    for o in range(b2, b2 + s2 - 67, 68):
                        defs.append(struct.unpack_from('<II', d, o + 32))
                elif j == 0x34103:
                    q, l = W.pay(d, b2, s2)
                    inst = np.frombuffer(d, dtype=np.uint8, count=l // 64 * 64, offset=q).reshape(-1, 64)
                elif j == 0x34106:   # 128 B rows read by the loader at 0x5dfa51 into section +0x30 (count = size >> 7); all zero in the 23 backdrop sections
                    empty6 = not any(d[b2:b2 + s2])
                k += 1
            if inst is not None and not empty6:   # SKYDOME, every single-object PAN_ section and OBJECT01 (section 397, the coast LOD): backdrops, not city
                sections.append((defs, inst))
        else:
            k += 1
    return d, solids, sections


BLEND = {0: 'none', 1: 'alpha', 2: 'add'}   # record +0x56; exe 0x5bcce0 table: 1 SRCALPHA/INVSRCALPHA, 2 SRCALPHA/ONE (3..6 never occur in UG2 data)


def footprint():
    """same collision footprint as ug2_world.main (near()): grid of REACH-grown cells around the collision rows"""
    rows = np.frombuffer(open(W.COLL, 'rb').read(), np.uint8).reshape(-1, 32)
    cx = (rows[:, 8:16].copy().view('<i2')[:, :3] / 8).mean(1)
    cy = (rows[:, 16:24].copy().view('<i2')[:, :3] / 8).mean(1)
    foot = np.zeros((16384 // W.CELL, 16384 // W.CELL), bool)
    foot[((cx + 8192) // W.CELL).astype(int), ((cy + 8192) // W.CELL).astype(int)] = True
    for _ in range(W.REACH // W.CELL):
        g = foot.copy(); g[1:] |= foot[:-1]; g[:-1] |= foot[1:]; g[:, 1:] |= foot[:, :-1]; g[:, :-1] |= foot[:, 1:]; foot = g

    def near(bb):
        i, j = int((bb[0] + bb[3]) / 2 + 8192) // W.CELL, int((bb[1] + bb[4]) / 2 + 8192) // W.CELL
        return 0 <= i < foot.shape[0] and 0 <= j < foot.shape[1] and foot[i, j]
    return near


STRIDE = {0x4180: (36, 28)}   # vertex mask -> (stride, uv offset); every other mask seen: (24, 16). Measured, census/ug2/tex.md


def walk(data, sol, secs, near, fixed):
    """the instance walk of ug2_world.main, collecting uv + per-triangle texture/material instead of colour.
    fixed=False reproduces ug2_world's hardcoded 24-byte vertex for positions; fixed=True uses the per-mask stride."""
    cache, tlist, tindex, mlist, mindex = {}, [], {}, [], {}

    def tid(h):
        if h not in tindex:
            tindex[h] = len(tlist)
            tlist.append(h)
        return tindex[h]

    def mid(h):
        if h not in mindex:
            mindex[h] = len(mlist)
            mlist.append(h)
        return mindex[h]

    def local(h):
        if h in cache:
            return cache[h]
        s, r = sol.get(h), None
        if s:
            d = data[s['f']]
            stride, uvo = STRIDE.get(s['mask'], (24, 16))
            ps = stride if fixed else 24
            raw = np.frombuffer(d, np.uint8, count=s['nv'] * ps, offset=s['v']).reshape(-1, ps)
            xyz = raw[:, :12].copy().view('<f4').reshape(-1, 3)
            rw = np.frombuffer(d, np.uint8, count=s['nv'] * stride, offset=s['v']).reshape(-1, stride)
            uv = rw[:, uvo:uvo + 8].copy().view('<f4').reshape(-1, 2)
            ix = np.frombuffer(d, '<u2', count=s['ntri'] * 3, offset=s['i']).reshape(-1, 3).astype(np.int64)
            ok = (ix < s['nv']).all(1) & (ix[:, 0] != ix[:, 1]) & (ix[:, 1] != ix[:, 2]) & (ix[:, 0] != ix[:, 2])
            if ok.any() and np.isfinite(xyz).all():
                tt = np.full(len(ix), 0xffff, np.int64)
                mm = np.full(len(ix), 0xffff, np.int64)
                for start, cnt, ts, ms in s['groups']:
                    a, b = start // 3, (start + cnt) // 3
                    if ts < len(s['tex']):
                        tt[a:b] = tid(s['tex'][ts])
                    if ms != 0xff and ms < len(s['mat']):
                        mm[a:b] = mid(s['mat'][ms])
                r = (xyz, uv, ix[ok], tt[ok], mm[ok])
        cache[h] = r
        return r

    UV, TT, MM, XYZ, seen = [], [], [], [], set()
    for fi, defs, inst in secs:
        for row in inst:
            w = row.tobytes()
            di, fl = struct.unpack_from('<HH', w, 24)
            if di >= len(defs) or fl & W.HIDDEN:   # hidden scenery-group instances, as ug2_world.main
                continue
            hh = defs[di][0] if defs[di][0] in sol else defs[di][1]
            if hh in sol and sol[hh]['name'].upper().startswith(W.SKIP):
                continue
            if not near(struct.unpack_from('<6f', w, 0)):
                continue
            key = (hh, w[32:62])
            if key in seen:
                continue
            seen.add(key)
            m = local(hh)
            if m is None:
                continue
            xyz, uv, ix, tt, mm = m
            R = np.array(struct.unpack_from('<9h', w, 44), dtype=np.float64).reshape(3, 3) / 8192.0
            pos = np.array(struct.unpack_from('<3f', w, 32), dtype=np.float64)
            with np.errstate(all='ignore'):
                wp = (xyz.astype(np.float64) @ R + pos).astype(np.float32)
            if not np.isfinite(wp).all() or np.abs(wp).max() > 1e5:
                continue
            used = np.unique(ix)
            XYZ.append(wp[used]); UV.append(uv[used]); TT.append(tt); MM.append(mm)
    return (np.concatenate(XYZ), np.concatenate(UV).astype('<f4'), np.concatenate(TT).astype('<u2'),
            np.concatenate(MM).astype('<u2'), tlist, mlist)


def main():
    tracks = sys.argv[1] if len(sys.argv) > 1 else W.TRACKS
    # city = STREAML4RA only (ug2_world.main); the other streams are only a texture-hash source
    files = sorted(glob.glob(os.path.join(tracks, 'STREAML4R?.BUN')))
    data, sol, secs, texsrc, npk, ntexrec = [], {}, [], {}, 0, 0
    for f in files:
        isra = os.path.basename(f) == 'STREAML4RA.BUN'
        d, s, c = scan_solids(f) if isra else (open(f, 'rb').read(), {}, [])
        fi = len(data)
        data.append(d)
        if isra:
            for h, v in s.items():
                sol.setdefault(h, dict(v, f=fi))
            secs += [(fi, defs, inst) for defs, inst in c]
        for pk in packs(d):
            npk += 1
            for r, g in zip(pk['recs'], pk['gpu']):
                ntexrec += 1
                texsrc.setdefault(r['hash'], (fi, pk, r, GPU_FMT.get(g, hex(g))))
    print('packs', npk, 'texture records', ntexrec, 'distinct hashes', len(texsrc))
    # game-wide texture packs (GLOBAL/, FRONTEND/FrontB.lzc) are searched for hashes the track packs lack
    root = os.path.dirname(tracks.rstrip('/'))
    for f in sorted(glob.glob(os.path.join(root, 'GLOBAL', '*.[bB][iIuU][nN]')) + glob.glob(os.path.join(root, 'GLOBAL', '*.lzc'))
                    + glob.glob(os.path.join(root, 'FRONTEND', 'FrontB.lzc'))):
        d = open(f, 'rb').read()   # no first-chunk filter: GLOBALB.BUN starts with chunk 0x00135200 and holds HEADLIGHTGLOW (3394fe62, 12,446 city triangles)
        fi, got = len(data), 0
        data.append(d)
        for pk in packs(d):
            for r, g in zip(pk['recs'], pk['gpu']):
                if r['hash'] not in texsrc and 'blob' in pk:
                    texsrc[r['hash']] = (fi, pk, r, GPU_FMT.get(g, hex(g)))
                    got += 1
        print(os.path.basename(f), 'new hashes', got)

    near = footprint()
    cb = os.path.join(OUT, 'city.bin')
    nv = ni = None
    if os.path.exists(cb):
        with open(cb, 'rb') as f:
            nv, ni = struct.unpack_from('<II', f.read(16), 4)
            f.seek(16)
            rec = np.frombuffer(f.read(nv * 16), dtype=[('p', '<f4', 3), ('c', 'u1', 4)])
    fixed_used = False
    for fixed in (False, True):
        P, UVa, Tt, Mm, tlist, mlist = walk(data, sol, secs, near, fixed)
        same = nv is not None and nv == len(P) and ni == 3 * len(Tt) and np.array_equal(rec['p'], P)
        print('stride per mask' if fixed else 'ug2_world 24-byte stride', ': verts', len(P), 'tris', len(Tt),
              '| city.bin', (nv, ni // 3 if ni else None), '->', 'IDENTICAL' if same else 'DIFFERENT')
        if same or nv is None:
            fixed_used = fixed
            break
    else:
        sys.exit('city.bin order differs: side file not written')
    print('distinct textures referenced', len(tlist), 'materials', len(mlist))

    # ---- decode the referenced textures
    os.makedirs(os.path.join(OUT, 'tex'), exist_ok=True)
    texes, fmtcount, missing, undec = [], {}, 0, 0
    for h in tlist:
        e = texsrc.get(h)
        if e is None:
            texes.append({'hash': '%08x' % h, 'file': None})
            missing += 1
            continue
        fi, pk, r, fmt = e
        img = decode(data[fi], pk, r, fmt) if 'blob' in pk else None
        if img is None:
            texes.append({'hash': '%08x' % h, 'file': None, 'fmt': fmt})
            undec += 1
            continue
        fn = 'tex/%08x.png' % h
        used = r['atest'] != 0 or r['blend'] != 0   # exe 0x5bcca7/0x5bccbc: alpha only matters with record +0x55 / +0x56 set
        raw_alpha = bool((img[:, :, 3] < 255).any())
        if not used:   # alpha test and blending both off: the palette/DXT alpha is never used by the draw, so store opaque
            img = img.copy()
            img[:, :, 3] = 255
        Image.fromarray(np.ascontiguousarray(img), 'RGBA').save(os.path.join(OUT, fn))
        fmtcount[fmt] = fmtcount.get(fmt, 0) + 1
        texes.append({'hash': '%08x' % h, 'file': fn, 'w': r['w'], 'h': r['h'], 'fmt': fmt,
                      'alpha': r['atest'] == 1 or r['blend'] != 0, 'raw_alpha': raw_alpha, 'name': r['name'], 'pack': pk.get('name'),
                      'alpha_test': r['atest'] == 1,   # exe 0x5bcca7: record +0x55 == 1 -> ALPHATESTENABLE, ALPHAREF 0x5f
                      'blend': BLEND.get(r['blend'], 'mode%d' % r['blend']),   # record +0x56, exe 0x5bccbc
                      'flag55': r['atest'], 'flag56': r['blend']})
    stats = {'referenced': len(tlist), 'decoded': len(tlist) - missing - undec, 'no_pack_record': missing,
             'undecoded_format': undec, 'formats': fmtcount, 'packs_scanned': npk, 'records_scanned': ntexrec,
             'positions_with_per_mask_stride': fixed_used}
    json.dump({'textures': texes, 'materials': ['%08x' % h for h in mlist], 'stats': stats},
              open(os.path.join(OUT, 'tex.json'), 'w'), indent=0)
    with open(os.path.join(OUT, 'city_tex.bin'), 'wb') as f:
        f.write(b'UG2T' + struct.pack('<IIII', len(P), len(Tt), len(tlist), len(mlist)))
        f.write(UVa.tobytes()); f.write(Tt.tobytes()); f.write(Mm.tobytes())
    dec_ok = np.array([t['file'] is not None for t in texes] + [False])
    tri_dec = dec_ok[np.where(Tt == 0xffff, len(texes), Tt)]
    bl = np.array([t.get('blend', 'none') for t in texes] + ['none'])[np.where(Tt == 0xffff, len(texes), Tt)]
    at = np.array([t.get('alpha_test', False) for t in texes] + [False])[np.where(Tt == 0xffff, len(texes), Tt)]
    print('stats', json.dumps(stats))
    print('triangles', len(Tt), 'with texture slot', int((Tt != 0xffff).sum()), 'decoded', int(tri_dec.sum()),
          '| alpha-test', int(at.sum()), 'blend alpha', int((bl == 'alpha').sum()), 'additive', int((bl == 'add').sum()))


if __name__ == '__main__':
    main()
