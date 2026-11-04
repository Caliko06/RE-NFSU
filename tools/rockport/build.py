"""build.py: one Downtown block of Rockport (NFS Most Wanted) -> NFSU stream rows.
Row ID_BASE ('TEX', preload) = one texture pack with every texture of the block (NFSU repeats textures across packs too, 220 hashes,
but one shared pack keeps the block at ~14 MB instead of 44 MB). Then per MW row (L2RA.BUN 0x34110): one NFSU row = solid list + one
scenery section, id = ID_BASE + 1 + running index (ORDER 1 of the engine window, then ID_BASE's note: ids from 3020, never 2500..2549 or 2600..2699, s16). The rows go into out/rockport_sections.bin, each at a 0x800
boundary (positions inside a row are absolute from its start: load it 128-aligned), and out/rockport_sections.json (id, mw, offset, size).
Collision of the block -> out/rockport_polys.bin (polys.py layout), see polys().
Formats: docs/openworld/re_rockport.md. usage: build.py [--offset X Y Z] [--rows C10,C50,...]"""
import collections, json, os, pickle, struct, sys
import numpy as np
sys.path.insert(0, os.path.dirname(__file__))
import mw, nfsu
from bun import NFSU, open_map, tree

OUT = os.path.join(NFSU, 'runs', 'rockport', 'out')
ROWS = 'C10 C50 C11 C51 C41 C46 C53 C54 C55 C56 C57 C58 C83'.split()
ID_BASE = 3020  # id%100 must stay >= 20: 0x544e90 indexes the flare table 0x740b50 by id with no bound for id%100 <= 9, and 10..19 go through id-10 (0x544fb7)
FALLBACK_TEX = None   # set in main: a texture every row carries for slots whose MW texture is missing


def nfsu_tpk_heads():
    """0x33310001 / 0x33320001 payloads of the first STREAML1RA.BUN pack ('Location1\\TempTextures.tpk', version 4)."""
    d = open_map(os.path.join(NFSU, 'game', 'Tracks', 'STREAML1RA.BUN'))
    h1 = h2 = None
    for dep, i, p, s in tree(d, 0, 1 << 22):
        if i == 0x33310001 and h1 is None:
            h1 = bytes(d[p:p + s])
        if i == 0x33320001 and h2 is None:
            h2 = bytes(d[p:p + s])
    return h1, h2


def nfsu_record(r):
    """MW TextureInfo -> NFSU. Same 124 B layout (format byte +0x4a: 0x22 DXT1, 0x24 DXT3, 0x26 DXT5 in both games).
    MW-only values, mapped to the NFSU ones they sit next to (measured over all 1,636 NFSU stream textures):
    class hash +0x28 -> 0x1a93cf; +0x50 = 1 -> 0; +0x51 = 4 -> 5 (NFSU alpha-blend textures use 5); +0x57 = 3 -> 1;
    +0x58 animation fields (u16 @0x5a, @0x5c, MW-only) -> 0."""
    r = bytearray(r)
    struct.pack_into('<I', r, 0x28, 0x1a93cf)
    if r[0x50] == 1: r[0x50] = 0
    if r[0x51] == 4: r[0x51] = 5
    if r[0x57] == 3: r[0x57] = 1
    r[0x58:0x60] = b'\0\0\x01\0' + b'\0' * 4
    return bytes(r)


def dxt5_to_dxt3(px):
    """DXT5 blocks -> DXT3 (NFSU stream packs hold only DXT1/DXT3): interpolated alpha decoded and stored as 4-bit explicit alpha."""
    b = np.frombuffer(px[:len(px) // 16 * 16], np.uint8).reshape(-1, 16)
    a0 = b[:, 0].astype(int); a1 = b[:, 1].astype(int)
    bits = np.zeros(len(b), np.uint64)
    for k in range(6):
        bits |= b[:, 2 + k].astype(np.uint64) << np.uint64(8 * k)
    idx = np.stack([(bits >> np.uint64(3 * i)) & np.uint64(7) for i in range(16)], 1).astype(int)
    pal = np.zeros((len(b), 8), int); pal[:, 0] = a0; pal[:, 1] = a1
    big = a0 > a1
    for i in range(1, 7):
        pal[:, i + 1] = np.where(big, ((7 - i) * a0 + i * a1) // 7, 0)
    for i in range(1, 5):
        pal[:, i + 1] = np.where(big, pal[:, i + 1], ((5 - i) * a0 + i * a1) // 5)
    pal[:, 6] = np.where(big, pal[:, 6], 0); pal[:, 7] = np.where(big, pal[:, 7], 255)
    al = np.take_along_axis(pal, idx, 1) >> 4
    a4 = (al[:, 0::2] | (al[:, 1::2] << 4)).astype(np.uint8)
    out = np.concatenate([a4, b[:, 8:]], 1)
    return out.tobytes() + px[len(px) // 16 * 16:]


def convert_tex(rec, cmp, px):
    r = nfsu_record(rec); c = bytearray(cmp)
    if r[0x4a] == 0x26:
        px = dxt5_to_dxt3(px); r = bytearray(r); r[0x4a] = 0x24; r = bytes(r)
        c[0x14:0x18] = b'DXT3'
    return r, bytes(c), px


# ---- night bake (docs/night_re.md: world = (headlight + vertex colour) * diffuse * 2, so the vertex colour IS the baked night light).
# Measured on NFSU road solids (TRS*, 278k vertices): unlit vertices are neutral grey, luminance 14..35 (p5 10, p50 45);
# lamp-lit ones are warm, BGR ratio (0.78, 0.95, 1.0), up to ~220 (p95 153, p99 217). MW vertex colour is daylight occlusion
# (luminance 47..92, p50 62) and MW has no light sources: lamps are taken from lamp-post placements (LAMP_NAMES).
NIGHT_BASE = ((0.0, 8), (0.05, 12), (0.5, 28), (0.95, 42), (1.0, 50))   # MW luminance quantile -> NFSU unlit luminance
LAMP_RGB = np.array([0.78, 0.95, 1.0])    # B, G, R of NFSU lamp light
LAMP_I, LAMP_R = 190.0, 16.0              # peak added luminance, reach in m (3D distance from the lamp head)
LAMP_NAMES = ('ParkLamp', 'StreetLight', 'IronLamp', 'CathedralGlobe')
MW_LUM_Q = None                           # MW luminance quantiles of the block, set in main


def night(col, world, lamps):
    """col u8[n,4] BGRA (MW), world f32[n,3] or None (shared solid: base only) -> u8[n,4]."""
    lum = col[:, :3].astype(float).mean(1)
    q = np.interp(lum, MW_LUM_Q, np.linspace(0, 1, len(MW_LUM_Q)))
    base = np.interp(q, [a for a, _ in NIGHT_BASE], [b for _, b in NIGHT_BASE])
    out = np.repeat(base[:, None], 3, 1)
    if world is not None and len(lamps):
        add = np.zeros(len(world))
        for L in lamps:
            dd = np.linalg.norm(world - L, axis=1)
            add += LAMP_I * np.clip(1 - dd / LAMP_R, 0, 1) ** 2
        out += add[:, None] * LAMP_RGB
    res = col.copy()
    res[:, :3] = np.clip(np.round(out), 0, 255).astype(np.uint8)
    return res


def convert_solid(sol, texmap, place=None, lamps=()):
    """MW solid -> nfsu.solid() dict. One VB (24 B: pos, BGRA colour with alpha * 2, uv0); indices offset by each MW VB's base.
    place = (rot, pos) when the solid has exactly one placement in the block (night() then adds lamp light in world space).
    texmap: MW texture hash -> True if a pixel source exists. Texture list = the diffuse textures the groups use (slot 0)."""
    m = sol['mesh']
    vbase = {}; parts = []; n = 0
    for g in m['groups']:
        if g['vb'] not in vbase:
            nv = sum(x['nverts'] for x in m['groups'] if x['vb'] == g['vb'])
            stride, pos, col, uv, nrm = mw.vb_array(m['vbs'][g['vb']], nv)
            vbase[g['vb']] = n; n += nv
            world = pos @ place[0] + place[1] if place is not None else None
            c = night(col, world, lamps).astype(int); c[:, 3] = np.minimum(255, c[:, 3] * 255 // 127)
            v = np.zeros(nv, [('p', '<f4', 3), ('c', 'u1', 4), ('t', '<f4', 2)])
            v['p'] = pos; v['c'] = c.astype(np.uint8); v['t'] = uv
            parts.append(v.tobytes())
    if n > 0xffff:
        raise ValueError('%s: %d vertices > 65535' % (sol['name'], n))
    tex = []; groups = []; ib = []; start = 0
    for g in m['groups']:
        slot = g['tex'][0]
        h = sol['tex'][slot] if slot < len(sol['tex']) else None
        if h is None or h not in texmap:
            h = FALLBACK_TEX
        if h not in tex:
            tex.append(h)
        ix = m['ib'][g['start']:g['start'] + g['nidx']].astype(np.int64) + vbase[g['vb']]
        ib.append(ix.astype('<u2').tobytes())
        groups.append(dict(bmin=g['bmin'], bmax=g['bmax'], nidx=g['nidx'], tex=tex.index(h), start=start, flags=0))
        start += g['nidx']
    ntris = sum(g['ntris'] for g in m['groups'])
    return dict(hash=sol['hash'], flags=0x13, f14=ntris & 0xffff, f18=len(tex) << 8, bmin=sol['bmin'], bmax=sol['bmax'],
                name=sol['name'], tex=tex, light=None,
                mesh=dict(vb=b''.join(parts), ib=b''.join(ib), groups=groups, ntris=ntris, nverts=n, vfmt=0))


def placements(row, sid, offset, get_solid):
    """MW SceneryInstances of every scenery section in the row -> (defs 72 B, places 48 B, solids used).
    NFSU def: u32 solid hash x6 @0 (slot 0 = MW LOD 0; 0 = none), s16 LOD distance x4 @0x18 (0 = always drawn, 0x445ec0), f32 radius @0x44.
    NFSU placement: s16 AABB @0, s16 def @0xc, u16 flags @0xe = 0x60 (never excluded by the view mask), f32 pos @0x10, s16 rot[9] @0x1c
    (/8192, row-major, world = local @ R + t: same convention as MW)."""
    R = mw.section_rows()[row]
    defs, dmap, places, used, xf = [], {}, [], {}, []
    for sec in mw.scenery(R['off'], R['off'] + R['size']):
        for ins in sec['inst']:
            if not 0 <= ins['info'] < len(sec['infos']):
                continue
            info = sec['infos'][ins['info']]
            h = info['hashes'][0]
            sol = get_solid(h)
            if sol is None or not sol['mesh'] or not sol['mesh']['groups']:
                continue
            used[h] = sol
            if h not in dmap:
                dr = bytearray(72)
                struct.pack_into('<I', dr, 0, h)
                struct.pack_into('<f', dr, 0x44, float(np.linalg.norm(np.array(sol['bmax']) - np.array(sol['bmin'])) / 2))
                dmap[h] = len(defs); defs.append(bytes(dr))
            pos = np.array(ins['pos']) + offset
            # world AABB of the solid's box through the placement (MW instance bbox is the same within float error)
            c = np.array([[x, y, z] for x in (sol['bmin'][0], sol['bmax'][0]) for y in (sol['bmin'][1], sol['bmax'][1])
                          for z in (sol['bmin'][2], sol['bmax'][2])]) @ ins['rot'] + pos
            lo = np.floor(c.min(0)).astype(int); hi = np.ceil(c.max(0)).astype(int)
            p = bytearray(48)
            struct.pack_into('<6h', p, 0, *np.clip(np.r_[lo, hi], -32768, 32767))
            struct.pack_into('<hH', p, 0xc, dmap[h], 0x60)
            struct.pack_into('<3f', p, 0x10, *pos)
            struct.pack_into('<9h', p, 0x1c, *np.round(ins['rot'] * 8192).astype(int).ravel())
            places.append(bytes(p)); xf.append((h, ins['rot'], pos, info['name'], c))
    return defs, places, used, xf


def poly_row(v, surf, flags):
    """TrackPolygon (wsrc 0x34132) 32 B, tools/openworld/polys.py + docs/openworld/re_coll.md: +0 0, +1 bbox selectors
    (min x = x[b & 3], min y = y[(b >> 2) & 3], max x = x[(b >> 4) & 3], max y = y[b >> 6]), +2 surface, +3 flags, +4 s16 z base,
    +6 0xffff (runtime), s16 x[4] /8 @8, y[4] /8 @0x10, z[4] /256 + base @0x18 (whole z times 4 with flag 4). A triangle repeats its
    3rd vertex as the 4th."""
    v = np.array(v, float)
    if len(v) == 3:
        v = np.vstack([v, v[2]])
    k = 4 if flags & 4 else 1
    z = v[:, 2] / k
    base = int(np.round((z.min() + z.max()) / 2))
    xs = np.round(v[:, 0] * 8).astype(int); ys = np.round(v[:, 1] * 8).astype(int)
    zs = np.round((z - base) * 256).astype(int)
    if np.abs(xs).max() > 32767 or np.abs(ys).max() > 32767 or np.abs(zs).max() > 32767 or abs(base) > 32767:
        raise ValueError('polygon out of the s16 range: %s' % v)
    b = int(np.argmin(xs)) | int(np.argmin(ys)) << 2 | int(np.argmax(xs)) << 4 | int(np.argmax(ys)) << 6
    return struct.pack('<BBBBhH4h4h4h', 0, b, surf, flags, base, 0xffff, *xs, *ys, *zs)


GROUND_SURF = 1    # NFSU road surface (6,110 + 13,341 rows of 1001/1002/1102 ground use 1)
WALL_SURF = 20     # NFSU wall surface (most common on 0x12 and 0x16 walls)


def polys(rows, offset):
    """MW collision of the rows (mw.collision_packs) -> TrackPolygon rows. Ground triangles: winding with normal z > 0 (as every NFSU
    ground row), flags 0, MW faces with flag 8 dropped (the MW ground query skips them). Walls: vertical quads (a low, a high, b high,
    b low), flags 0x12, or 0x16 (z times 4, clipped to -508..508 like NFSU's) when taller than 250 m (MW 1152 m 'infinite' barriers); the normal of
    cross(v1 - v0, v2 - v0) faces the side with more MW ground within 4 m (NFSU walls face their road: 85 % measured), MW's own
    order on a tie."""
    RT = mw.section_rows(); out = []; G = []; W = []
    for nm in rows:
        r = RT[nm]
        for c in mw.collision_packs(r['off'], r['off'] + r['size']):
            G += [t for t, f in zip(c['tris'], c['flags']) if not f & 8]
            W += list(c['walls'])
    G = np.array(G) + offset; W = np.array(W).reshape(-1, 4, 3) + offset
    grid = collections.Counter(map(tuple, np.floor(G.mean(1)[:, :2] / 2).astype(int)))

    def near(pt):
        i, j = np.floor(pt / 2).astype(int)
        return sum(grid.get((i + a, j + b), 0) for a in (-1, 0, 1) for b in (-1, 0, 1))
    st = collections.Counter()
    for t in G:
        if np.cross(t[1] - t[0], t[2] - t[0])[2] < 0:
            t = t[[0, 2, 1]]
        out.append(poly_row(t, GROUND_SURF, 0)); st['ground'] += 1
    for w in W:
        a, b = w[0], w[1]; lo, hi = w[0, 2], w[2, 2]
        if hi - lo > 250:      # MW 'infinite' barrier (-128..1024) -> NFSU infinite wall span -508..508 (0x16, z times 4)
            lo, hi = max(lo, -508.0), min(hi, 508.0)
        if np.linalg.norm(b[:2] - a[:2]) < 0.05:
            st['wall too short'] += 1
            continue
        quad = np.array([[a[0], a[1], lo], [a[0], a[1], hi], [b[0], b[1], hi], [b[0], b[1], lo]])
        n = np.cross(quad[1] - quad[0], quad[2] - quad[0])[:2]; n /= np.linalg.norm(n)
        m = (a[:2] + b[:2]) / 2
        if near(m - 4 * n) > near(m + 4 * n):
            quad = quad[[3, 2, 1, 0]]; st['wall flipped'] += 1
        fl = 0x16 if hi - lo > 250 else 0x12
        out.append(poly_row(quad, WALL_SURF, fl)); st['wall 0x%x' % fl] += 1
    return out, st


def main(argv):
    global FALLBACK_TEX
    offset = np.zeros(3)
    rows = ROWS
    if '--offset' in argv:
        k = argv.index('--offset'); offset = np.array(list(map(float, argv[k + 1:k + 4])))
    if '--rows' in argv:
        rows = argv[argv.index('--rows') + 1].split(',')
    os.makedirs(OUT, exist_ok=True)
    RT = mw.section_rows()
    sidx = pickle.load(open(os.path.join(OUT, 'solid_index.pkl'), 'rb'))
    tidx = pickle.load(open(os.path.join(OUT, 'tex_index.pkl'), 'rb'))
    scache = {}; tcache = {}

    def row_solids(nm):
        if nm not in scache:
            r = RT[nm]; scache[nm] = mw.solids(r['off'], r['off'] + r['size'])
        return scache[nm]

    def row_tex(nm):
        if nm not in tcache:
            r = RT[nm]; tcache[nm] = mw.textures(r['off'], r['off'] + r['size'])
        return tcache[nm]

    def get_solid(h, here):
        s = row_solids(here).get(h)
        if s is None:
            for o in sidx.get(h, []):
                s = row_solids(o).get(h)
                if s:
                    break
        return s

    def get_tex(h):
        for o in tidx.get(h, []):
            t = row_tex(o).get(h)
            if t:
                return t
        return None
    h1, h2 = nfsu_tpk_heads()
    blob = bytearray(); table = []; stats = collections.Counter()

    def emit(sid, name, parts, **info):
        rb = b''; p = 0
        for f in parts:
            c = f(p); rb += c; p += len(c)
        off = len(blob)
        blob.extend(rb + b'\0' * (-len(rb) % 0x800))
        table.append(dict(id=sid, mw=name, offset=off, size=len(rb), **info))
        print(name, sid, 'bytes', len(rb), info)
    built = []; alltex = {}
    for k, nm in enumerate(rows):
        sid = ID_BASE + 1 + k
        assert sid <= 0x7fff and not (2500 <= sid <= 2549 or 2600 <= sid <= 2699)
        defs, places, used, xf = placements(nm, sid, offset, lambda h: get_solid(h, nm))
        for s in used.values():
            for g in s['mesh']['groups']:
                sl = g['tex'][0]
                if sl < len(s['tex']) and s['tex'][sl] not in alltex:
                    alltex[s['tex'][sl]] = get_tex(s['tex'][sl])
        built.append((sid, nm, defs, places, used, xf))
    global MW_LUM_Q
    nplace = collections.Counter(h for b in built for h, *_ in b[5])
    one = {h: (rot, pos) for b in built for h, rot, pos, *_ in b[5] if nplace[h] == 1}
    lamps = [np.r_[c[:, :2].mean(0), c[:, 2].max() - 0.5] for b in built for h, rot, pos, name, c in b[5]
             if any(k.lower() in name.lower() for k in LAMP_NAMES)]
    lums = np.concatenate([mw.vb_array(v, sum(g['nverts'] for g in sol['mesh']['groups'] if g['vb'] == k))[2][:, :3].mean(1)
                           for b in built for sol in b[4].values() for k, v in enumerate(sol['mesh']['vbs'])])
    MW_LUM_Q = np.percentile(lums, np.linspace(0, 100, 21))
    stats['lamps'] = len(lamps); stats['baked with lamps'] = len(one)
    have = {h: t for h, t in alltex.items() if t is not None}
    stats['tex missing'] = len(alltex) - len(have)
    FALLBACK_TEX = sorted(have)[0]
    texs = [convert_tex(*have[h]) for h in sorted(have)]
    stats['dxt5'] = sum(1 for h in have if have[h][0][0x4a] == 0x26); stats['textures'] = len(texs)
    emit(ID_BASE, 'TEX', [lambda p: nfsu.tpk(p, h1, texs, h2)], preload=True, textures=len(texs))
    for sid, nm, defs, places, used, xf in built:
        sols = [convert_solid(s, have, one.get(h), lamps) for h, s in used.items()]
        nodes = nfsu.bvh(places) if places else []
        emit(sid, nm, [lambda p: nfsu.solid_list(p, 'Location1\\Rockport\\%s.bin' % nm, 'R%d' % sid, sols),
                       lambda p: nfsu.pad_to(p, 16),
                       lambda p: nfsu.section(p, sid, defs, places, nodes)],
             placements=len(places), solids=len(sols), x=RT[nm]['x'] + offset[0], y=RT[nm]['y'] + offset[1], radius=RT[nm]['r'])
        stats['placements'] += len(places); stats['solids'] += len(sols)
    P, pst = polys(rows, offset)
    open(os.path.join(OUT, 'rockport_polys.bin'), 'wb').write(b''.join(P))
    stats.update(pst)
    open(os.path.join(OUT, 'rockport_sections.bin'), 'wb').write(blob)
    json.dump(dict(id_base=ID_BASE, offset=list(offset), align=0x800, rows=table), open(os.path.join(OUT, 'rockport_sections.json'), 'w'), indent=1)
    print('total', len(blob), dict(stats))


if __name__ == '__main__':
    main(sys.argv[1:])
