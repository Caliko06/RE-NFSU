#!/usr/bin/env python3
"""merge.py: the WORLD track with a Rockport block and a bridge to it, off unless RN_ROCKPORT (docs/openworld/re_rockport_engine.md).
Input build/openworld/TRACKB1010.lzc and runs/rockport/out/ (tools/rockport/build.py). Output build/openworld/rockport/:
  STREAML1RA_1010.BUN  the block's sections + the bridge row (tools/rockport/bridge.py), read as file 2 of the 0x34107 rows
  TRACKB1010.lzc       rows added to 0x34107 (all preload), boundaries 1401 (block) and 1402 (gap) added, Rockport ids appended
                       to the lists of 1201 (bridge foot) and 1209 (north strip), block and bridge polygons added, walls across the joins removed."""
import json, os, struct, sys
ROOT = os.path.abspath(os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', '..'))
os.environ.setdefault('NFSU1_MAIN', ROOT)
os.chdir(ROOT)
sys.path[:0] = ['tools/hopper', 'ref/tools/ug1-tracks']
import bridge
import numpy as np
import nfsu
from bun import tree, skip11
import q_owcoll2_gen as gen, q_owcoll2_lzc as lzc, q_owcoll2_write as w
from lib import load

OUT, SRC = 'build/openworld/rockport', 'runs/rockport/out'
BLOCK, GAP = 1401, 1402   # letter N, numbers 1-2: free, and the same id shape as the shipped city boundaries (0x446db0)
CITY, NORTH = 1201, 1209  # shipped boundaries over the bridge's city foot and the empty strip north of it (bnd survey 2026-11-02)
MARGIN = 10.0             # m around the block


def poly_in(pt, poly):
    x, y = pt; r = False
    for (x1, y1), (x2, y2) in zip(poly, poly[1:] + poly[:1]):
        if (y1 > y) != (y2 > y) and x < (x2 - x1) * (y - y1) / (y2 - y1) + x1:
            r = not r
    return r


def boundary(d, o, size, new, add):
    """0x80034150 with rows added to 0x34151 (0x8c B, polygon <= 16 verts) and 0x34152 (0x94 B, <= 64 ids; 0x444b50 reads the
    list of the viewer's polygon, 0x446400 draws it), plus ids appended to shipped lists. new: [(id, verts, ids)], add: {id: ids}.
    Also returns the shipped lists (id -> ids) as read."""
    out, p, e, shipped = bytearray(), o + 8, o + 8 + size, {}
    while p < e:
        cid, n = struct.unpack_from('<II', d, p)
        body = bytearray(d[p + 8:p + 8 + n])
        if cid == 0x34151:
            assert n % 0x8c == 0
            polys = []
            for k in range(0, n, 0x8c):
                i, nv = struct.unpack_from('<hh', body, k + 8)
                assert i not in [x[0] for x in new]
                polys.append(list(zip(*[iter(struct.unpack_from('<%df' % (2 * nv), body, k + 0xc))] * 2)))
            for i, verts, _ in new:          # a new polygon must not cover a shipped one (the first hit wins in 0x446fd0)
                xs, ys = [v[0] for v in verts], [v[1] for v in verts]
                for x in range(int(min(xs)) + 1, int(max(xs)), 10):
                    for y in range(int(min(ys)) + 1, int(max(ys)), 10):
                        assert not (poly_in((x, y), verts) and any(poly_in((x, y), q) for q in polys)), (i, x, y)
                assert 4 <= len(verts) <= 16
                r = bytearray(body[:0x8c]); r[8:] = bytes(0x8c - 8)
                struct.pack_into('<hh%df' % (2 * len(verts)), r, 8, i, len(verts), *[c for v in verts for c in v])
                body += r
        elif cid == 0x34152:
            assert n % 0x94 == 0
            for k in range(0, n, 0x94):
                i, m = struct.unpack_from('<h', body, k + 8)[0], struct.unpack_from('<i', body, k + 0x10)[0]
                ids = list(struct.unpack_from('<%dh' % m, body, k + 0x14)); shipped[i] = list(ids)
                ids += [x for x in dict.fromkeys(add.get(i, [])) if x not in ids]
                assert len(ids) <= 64, (i, len(ids))
                struct.pack_into('<i%dh' % len(ids), body, k + 0x10, len(ids), *ids)
            for i, _, ids in new:
                ids = list(dict.fromkeys(ids)); assert len(ids) <= 64, (i, len(ids))
                r = bytearray(body[:0x94]); r[8:] = bytes(0x94 - 8)
                struct.pack_into('<h', r, 8, i); struct.pack_into('<i%dh' % len(ids), r, 0x10, len(ids), *ids)
                body += r
        out += struct.pack('<II', cid, len(body)) + body
        p += 8 + n
    return struct.pack('<II', 0x80034150, len(out)) + out, shipped


def lists_of(d, ch):
    c = [x for x in ch if x[0] == 0x80034150][0]
    return boundary(d, c[1], c[2], [], {})[1]


def in_vol(P, vol):
    """mask: points f64[n,3] inside any (xy quad, z lo, z hi) of the bridge volume."""
    m = np.zeros(len(P), bool)
    for q, lo, hi in vol:
        ok = (P[:, 2] > lo) & (P[:, 2] < hi) & (P[:, 0] >= q[:, 0].min()) & (P[:, 0] <= q[:, 0].max()) & (P[:, 1] >= q[:, 1].min()) & (P[:, 1] <= q[:, 1].max())
        if not ok.any():
            continue
        s = [(q[(k + 1) % 4, 0] - q[k, 0]) * (P[:, 1] - q[k, 1]) - (q[(k + 1) % 4, 1] - q[k, 1]) * (P[:, 0] - q[k, 0]) for k in range(4)]
        m |= ok & ((np.min(s, 0) >= 0) | (np.max(s, 0) <= 0))
    return m


def clear_path(rows, vol):
    """rows: [(key, bytes)] NFSU section rows. Returns {key: new bytes} for rows with a placement whose mesh (def slot 0 solid, through the
    placement's rot/pos: world = local @ R + t) has a triangle point inside vol; those placements get rot = 0, so the mesh collapses to its
    origin (the game draws nothing; data only, nothing else in the row moves). Triangles are sampled every <= 1.5 m."""
    box = np.array([min(q[:, 0].min() for q, _, _ in vol), min(q[:, 1].min() for q, _, _ in vol), min(lo for _, lo, _ in vol),
                    max(q[:, 0].max() for q, _, _ in vol), max(q[:, 1].max() for q, _, _ in vol), max(hi for _, _, hi in vol)])
    trees = {k: tree(d) for k, d in rows}
    where = {}                                      # solid hash -> (row key, tree index)
    for k, d in rows:
        for j, (_, i, p, s) in enumerate(trees[k]):
            if i == 0x134011:
                where.setdefault(struct.unpack_from('<I', d, skip11(d, p, s) + 0x10)[0], (k, j - 1))
    data = dict(rows); out = {}; cache = {}; names = []
    for k, d in rows:
        t = trees[k]
        defs = [struct.unpack_from('<I', d, o)[0] for _, i, p, s in t if i == 0x34102 for o in range(skip11(d, p, s), p + s - 71, 72)]
        hide = []
        for _, i, p, s in t:
            if i != 0x34103:
                continue
            for o in range(skip11(d, p, s), p + s - 47, 48):
                bb = np.array(struct.unpack_from('<6h', d, o), float)
                if (bb[3:] < box[:3]).any() or (bb[:3] > box[3:]).any():
                    continue
                di = struct.unpack_from('<h', d, o + 12)[0]
                h = defs[di] if 0 <= di < len(defs) else 0
                if h not in where:
                    continue
                if h not in cache:
                    rk, j = where[h]
                    sol = nfsu.parse_solid(data[rk], trees[rk], j); m = sol['mesh']
                    st = len(m['vb']) // m['nverts']
                    pos = np.frombuffer(m['vb'], np.uint8).reshape(-1, st)[:, :12].copy().view('<f4').astype(float)
                    cache[h] = (pos[np.frombuffer(m['ib'], '<u2').astype(int)[:len(m['ib']) // 6 * 3].reshape(-1, 3)], sol['name'])
                tri, nm = cache[h]
                rot = np.array(struct.unpack_from('<9h', d, o + 0x1c), float).reshape(3, 3) / 8192
                tw = tri @ rot + np.array(struct.unpack_from('<3f', d, o + 0x10))
                tw = tw[((tw.max(1) >= box[:3]) & (tw.min(1) <= box[3:])).all(1)]
                pts = [tw.reshape(-1, 3), tw.mean(1)]
                for tr in tw[np.linalg.norm(tw[:, [1, 2, 0]] - tw, axis=2).max(1) > 1.5]:
                    n = min(200, int(np.ceil(np.linalg.norm(tr[[1, 2, 0]] - tr, axis=1).max() / 1.5)))
                    uv = np.array([(a / n, b / n) for a in range(n + 1) for b in range(n + 1 - a)])
                    pts.append(tr[0] + uv[:, :1] * (tr[1] - tr[0]) + uv[:, 1:] * (tr[2] - tr[0]))
                if in_vol(np.concatenate(pts), vol).any():
                    hide.append(o); names.append((k, nm, bb.astype(int).tolist()))
        if hide:
            nd = bytearray(d)
            for o in hide:
                nd[o + 0x1c:o + 0x2e] = bytes(18)
            out[k] = bytes(nd)
    return out, names


def section_rows(meta):
    out = bytearray()
    for r in meta['rows']:
        row = bytearray(56)
        row[:8] = r['mw'].encode()[:7].ljust(8, b'\0')
        struct.pack_into('<hB', row, 8, r['id'], 1)     # every Rockport row preloads: the pool (0x449996) grows by their size, city + block fit
        struct.pack_into('<IIII', row, 0x10, 2, r['offset'], r['size'], r['size'])
        out += row
    return bytes(out)


def main():
    meta = json.load(open(SRC + '/rockport_sections.json'))
    blob = open(SRC + '/rockport_polys.bin', 'rb').read()
    assert len(blob) % 32 == 0
    block = [blob[k:k + 32] for k in range(0, len(blob), 32)]
    xy = [p for r in block for p in gen.row_xy8(r)]
    box = (min(p[0] for p in xy) / 8 - MARGIN, min(p[1] for p in xy) / 8 - MARGIN,
           max(p[0] for p in xy) / 8 + MARGIN, max(p[1] for p in xy) / 8 + MARGIN)
    base = load('build/openworld/TRACKB1010.lzc')
    ch = w.top_chunks(base)
    ids = [c[0] for c in ch]
    i0 = ids.index(0x34130)
    assert ids[i0:i0 + 5] == list(w.COLL)
    o32, s32 = ch[i0 + 2][1:]
    city = [base[o32 + 8 + k:o32 + 8 + k + 32] for k in range(0, s32, 32)]
    br = bridge.make(city, block)
    rows = ([r for k, r in enumerate(city) if k not in br['drop_city']] + [r for k, r in enumerate(block) if k not in br['drop_block']]
            + br['polys'])
    assert len(rows) <= 0xfffe
    g = gen.derive(rows)
    widx = g['widx'] + (b'\0\0' if (len(g['widx']) // 2) % 2 else b'')
    secs = open(SRC + '/rockport_sections.bin', 'rb').read()
    meta['rows'].append(dict(id=bridge.ID, mw='BRIDGE', offset=len(secs), size=len(br['section'])))
    # clear the scenery the bridge runs through: city rows (file 1, the game's STREAML1RA.BUN) are copied into our file 2 and repointed;
    # block rows are ours and change in place (same size)
    c107 = [c for c in ch if c[0] == 0x34107][0]
    srcs = []
    with open('game/TRACKS/STREAML1RA.BUN', 'rb') as f:
        for k in range(0, c107[2], 56):
            fi, off, size = struct.unpack_from('<III', base, c107[1] + 8 + k + 0x10)
            if fi == 1 and size:
                f.seek(off); srcs.append((('c', k // 56), f.read(size)))
    srcs += [(('b', r['id']), secs[r['offset']:r['offset'] + r['size']]) for r in meta['rows'][:-1]]
    cleared, gone = clear_path(srcs, br['vol'])
    secs = bytearray(secs)
    for r in meta['rows'][:-1]:
        if ('b', r['id']) in cleared:
            secs[r['offset']:r['offset'] + r['size']] = cleared[('b', r['id'])]
    tail = bytearray(br['section']); tail += bytes(-len(tail) % 0x800); repoint = {}
    for key, d in cleared.items():
        if key[0] == 'c':
            repoint[key[1]] = len(secs) + len(tail); tail += d + bytes(-len(d) % 0x800)
    secs = bytes(secs)
    new_rows = section_rows(meta)
    rp = [r['id'] for r in meta['rows']]          # TEX first: it must be in before the solids that use it
    shipped = lists_of(base, ch)
    pre = sum(1 for k in range(0, [c for c in ch if c[0] == 0x34107][0][2], 56)
              if base[[c for c in ch if c[0] == 0x34107][0][1] + 8 + k + 0xa])
    assert pre + len(rp) <= 256, 'preload rows over the 0x444b50 cap'
    gap = [(box[0], 1117.0), (box[2], 1117.0), (box[2], box[1]), (box[0], box[1])]   # between NORTH's top edge and the block
    nb = [(BLOCK, [(box[0], box[1]), (box[2], box[1]), (box[2], box[3]), (box[0], box[3])], rp + shipped[CITY]),
           (GAP, gap, rp + shipped[CITY] + shipped[NORTH])]
    add = {CITY: rp, NORTH: rp + shipped[CITY]}
    out = bytearray()


    def copy(c):
        cid, o, size = c
        if cid == 0x34107:
            assert size % 56 == 0
            body = bytearray(base[o + 8:o + 8 + size])
            for k, off in repoint.items():
                struct.pack_into('<II', body, k * 56 + 0x10, 2, off)
            out.extend(struct.pack('<II', cid, size + len(new_rows)) + body + new_rows)
        elif cid == 0x80034150:
            out.extend(boundary(base, o, size, nb, add)[0])
        else:
            out.extend(base[o:o + 8 + size])

    def run(chunks):
        k = 0
        while k < len(chunks):
            j = k
            while j < len(chunks) and chunks[j][0] == 0:
                j += 1
            c = chunks[j] if j < len(chunks) else None
            aligned = c is not None and c[1] % 128 == 0
            for p in chunks[k:j]:
                if not aligned or p[2] >= 1024:
                    out.extend(base[p[1]:p[1] + 8 + p[2]])
            if c is not None:
                if aligned:
                    n = (-len(out)) % 128
                    if n and n < 8:
                        n += 128
                    if n:
                        out.extend(struct.pack('<II', 0, n - 8) + b'\0' * (n - 8))
                copy(c)
            k = j + 1

    run(ch[:i0])
    for cid, payload, al in ((0x34130, g['wmap'], True), (0x34131, g['wcell'], True), (0x34132, b''.join(rows), False),
                             (0x34133, widx, False), (0x34134, w.bbox_payload(rows), True)):
        out.extend(w.chunk(cid, len(out), payload, al))
    run(ch[i0 + 5:])
    # checks on the file as written
    new = bytes(out)
    c2 = w.top_chunks(new)
    assert [c[0] for c in c2 if c[0]] == [c[0] for c in ch if c[0]], 'chunk order changed'
    for a, b in zip([c for c in ch if c[0]], [c for c in c2 if c[0]]):
        assert a[1] % 128 != 0 or b[1] % 128 == 0 or a[0] in w.COLL, hex(a[0])
    os.makedirs(OUT, exist_ok=True)
    open(OUT + '/TRACKB1010.lzc', 'wb').write(lzc.encode(new))
    bun = OUT + '/STREAML1RA_1010.BUN'
    if os.path.lexists(bun):
        os.remove(bun)
    open(bun, 'wb').write(secs + tail)
    print('rows %d (preload %d + %d), polygons %d city - %d + %d block - %d + %d bridge = %d, boundaries %d %s + %d, %d B' % (
        len(meta['rows']), pre, len(rp), len(city), len(br['drop_city']), len(block), len(br['drop_block']), len(br['polys']), len(rows),
        BLOCK, [round(v) for v in box], GAP, len(new)))
    print('bridge', br['stats'])
    print('cleared %d placements in %d rows:' % (len(gone), len(cleared)), gone)
    print('spawn x %.2f y %.2f z %.2f yaw16 %d (host/openworld.c rockport_tick)' % br['spawn'])

if __name__ == '__main__':
    main()
