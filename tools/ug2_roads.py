#!/usr/bin/env python3
"""ug2_roads.py: decode the UG2 free-roam road graph (TRACKS/ROUTESL4RA/RoutesFreeRoam.bin) and plot it over the UG2 surface-1 collision.

Layouts (all read by SPEED2.EXE v1.2; facts and addresses in census/ug2/roads.md):
  chunk 0x34121 (loader 0x5deb80 -> 0x5de1c0): sections, header 0x8c B + n * 0x38 B nodes; n = s16 at +0x34, id = u16 at +0xa.
  chunk 0x34122 (0x5deb80): 4 B pad, then 32 B link entries (count = (size-4) >> 5).
  chunk 0x34123 (0x5deb80): 276 B (0x114) intersection records (count = size / 276).
  Section header: +0x10 char[16] class name "TrackRoutesA<d><d>", +0x34 s16 nodes, +0x40 f32 route length, +0x60 f32 x4 bbox (xmin ymin xmax ymax).
  Node: +0 f32 x, +4 f32 y, +8 f32 0 (unused), +0xc u32 (bits 0..10 own section id, bits 20..24 intersection group (record k has group k // 2, 31 = none), bits 11/25/27 forward and 18/26/28
        backward drivable flags), +0x12 s16 z * 8, +0x18/+0x1a s16 tangent x/y * 32768, +0x1c/+0x1e u16 link slots (entry index, 0xffff = none),
        +0x20..+0x2b 12 lane bytes, +0x2c/+0x2d 100/100, +0x2e..+0x35 8 width bytes.
  Entry: +4 u16 dst node, +6 u16 src node, +8 u16 dst section, +0xa u16 src section, +0xc/+0xd type nibbles, +0xe/+0xf flag bytes.
usage:  python3 -I tools/ug2_roads.py [--sec A] [--dump] [--png census/ug2/roads.png] [--coll build/ug2/coll_rows.bin] [--zcheck]
(numpy + PIL; read only: game files are not modified; with no option it prints the counts)"""
import argparse, collections, math, os, struct, sys

TRACKS = '/Users/angeldamian/RE-NFSU-UG2/Need For Speed Underground 2/TRACKS'
REPO = os.path.abspath(os.path.join(os.path.dirname(os.path.abspath(__file__)), '..'))
# UG2 -> NFSU1 placement (docs/re/ug2_bridge.md): R270 (x,y)->(y,-x), then + t
TX, TY, TZ = -1287.375, 812.25, -6.203125


def to_nfsu1(x, y, z):
    return y + TX, -x + TY, z + TZ


def chunks(d):
    p = 0
    while p + 8 <= len(d):
        cid, size = struct.unpack_from('<II', d, p)
        yield cid, p + 8, size
        p += 8 + size


def load(sec='A', name='RoutesFreeRoam.bin'):
    d = open('%s/ROUTESL4R%s/%s' % (TRACKS, sec, name), 'rb').read()
    ch = {cid: (b, s) for cid, b, s in chunks(d)}
    g = dict(file=d, sections=[], entries=[], inters=[])
    if 0x34121 not in ch:
        return g
    b, s = ch[0x34121]
    p = b
    while p < b + s:
        n = struct.unpack_from('<h', d, p + 0x34)[0]
        h = d[p:p + 0x8c]
        sec_ = dict(id=struct.unpack_from('<H', h, 0xa)[0], cls=h[0x10:0x20].split(b'\0')[0].decode(), n=n,
                    length=struct.unpack_from('<f', h, 0x40)[0], bbox=struct.unpack_from('<4f', h, 0x60), off=p, nodes=[])
        for i in range(n):
            q = p + 0x8c + i * 0x38
            x, y = struct.unpack_from('<2f', d, q)
            fl = struct.unpack_from('<I', d, q + 0xc)[0]
            z = struct.unpack_from('<h', d, q + 0x12)[0] / 8
            tx, ty = (v / 32768 for v in struct.unpack_from('<2h', d, q + 0x18))
            lk = struct.unpack_from('<2H', d, q + 0x1c)
            sec_['nodes'].append(dict(x=x, y=y, z=z, fl=fl, t=(tx, ty), lk=lk, lane=d[q + 0x20:q + 0x2c], wid=d[q + 0x2e:q + 0x36]))
        g['sections'].append(sec_)
        p += 0x8c + n * 0x38
    assert p == b + s
    b, s = ch.get(0x34122, (0, 0))
    for o in range(b + 4, b + 4 + (max(s - 4, 0) >> 5) * 32, 32):
        dn, sn, ds, ss = struct.unpack_from('<4H', d, o + 4)
        g['entries'].append(dict(dn=dn, sn=sn, ds=ds, ss=ss, c=d[o + 0xc], c2=d[o + 0xd], f=d[o + 0xe], f2=d[o + 0xf], twin=struct.unpack_from('<4H', d, o + 0x18)))
    if 0x34123 in ch:
        b, s = ch[0x34123]
        for o in range(b, b + s // 276 * 276, 276):
            a, bb, na, nb = struct.unpack_from('<2H', d, o + 4) + struct.unpack_from('<2H', d, o + 0xa)
            g['inters'].append(dict(sa=a, sb=bb, na=na, nb=nb))
    return g


def check(g):
    """self-consistency of the decode; returns a dict of counts that must hold"""
    S = {s['id']: s for s in g['sections']}
    r = collections.Counter()
    ne = len(g['entries'])
    for s in g['sections']:
        for i, nd in enumerate(s['nodes']):
            r['node id == section id'] += (nd['fl'] & 0x7ff) == s['id']
            for l in nd['lk']:
                if l == 0xffff:
                    continue
                if l >= ne:
                    r['link beyond FreeRoam entries (race-only)'] += 1
                    continue
                e = g['entries'][l]
                r['link -> entry whose source is this node'] += (e['ss'], e['sn']) == (s['id'], i)
                r['link -> entry total'] += 1
    for e in g['entries']:
        r['entry ends valid'] += e['ds'] in S and e['dn'] < S[e['ds']]['n'] and e['ss'] in S and e['sn'] < S[e['ss']]['n']
    for k, it in enumerate(g['inters']):
        for sec_, nd in ((it['sa'], it['na']), (it['sb'], it['nb'])):
            if sec_ in S and nd < S[sec_]['n']:
                r['intersection ends valid'] += 1
                r['intersection ends whose node bits 20..24 == record//2'] += ((S[sec_]['nodes'][nd]['fl'] >> 20) & 0x1f) == k // 2
    return r


def stats(g):
    S = g['sections']
    print('sections %d  nodes %d  entries %d  intersections %d' % (len(S), sum(s['n'] for s in S), len(g['entries']), len(g['inters'])))
    print('section id %d..%d  nodes/section %d..%d' % (min(s['id'] for s in S), max(s['id'] for s in S), min(s['n'] for s in S), max(s['n'] for s in S)))
    print('route length sum %.1f m' % sum(s['length'] for s in S))
    drv = sum(1 for s in S for n in s['nodes'] if n['fl'] >> 11 & 1)
    print('nodes with forward flag bit 11: %d' % drv)
    print('entries per source section max', max(collections.Counter(e['ss'] for e in g['entries']).values()))
    print('classes', sorted(collections.Counter(s['cls'] for s in S).items()))
    for k, v in sorted(check(g).items()):
        print('  check:', k, v)


def dump(g):
    for s in g['sections']:
        print('S %d %s n=%d len=%.1f' % (s['id'], s['cls'], s['n'], s['length']))
        for i, n in enumerate(s['nodes']):
            print('  N %d %.2f %.2f %.3f fl=%08x lk=%s' % (i, n['x'], n['y'], n['z'], n['fl'], n['lk']))
    for i, e in enumerate(g['entries']):
        print('E %d %d:%d -> %d:%d c=%02x%02x f=%02x%02x' % (i, e['ss'], e['sn'], e['ds'], e['dn'], e['c'], e['c2'], e['f'], e['f2']))


def coll_rows(path):
    import numpy as np
    d = open(path, 'rb').read()
    n = len(d) // 32
    a = np.frombuffer(d, dtype=np.uint8).reshape(n, 32)
    surf, fl = a[:, 2], a[:, 3]
    xs = np.frombuffer(d, dtype='<i2').reshape(n, 16)
    base = xs[:, 2].astype(np.float32)
    keep = (surf == 1) & ((fl & 0x0a) == 0)
    k = np.where(fl & 4, 4.0, 1.0)
    X = xs[:, 4:8].astype(np.float32) / 8
    Y = xs[:, 8:12].astype(np.float32) / 8
    Z = (base[:, None] + xs[:, 12:16].astype(np.float32) / 256) * k[:, None]
    nv = np.where(fl & 0x10, 4, 3)
    return keep, X, Y, Z, nv


def zcheck(g, path):
    """node z (s16/8) against the surface-1 ground rows: nearest row vertex within 12 units, z difference"""
    import numpy as np
    keep, X, Y, Z, nv = coll_rows(path)
    px, py, pz = [], [], []
    for i in np.where(keep)[0]:
        for j in range(nv[i]):
            px.append(X[i, j]), py.append(Y[i, j]), pz.append(Z[i, j])
    px, py, pz = map(np.array, (px, py, pz))
    cell = collections.defaultdict(list)
    for k, (x, y) in enumerate(zip(px, py)):
        cell[(int(x // 16), int(y // 16))].append(k)
    dz, miss = [], 0
    for s in g['sections']:
        for nd in s['nodes']:
            best = None
            cx, cy = int(nd['x'] // 16), int(nd['y'] // 16)
            for a in (-1, 0, 1):
                for b in (-1, 0, 1):
                    for k in cell.get((cx + a, cy + b), ()):
                        d2 = (px[k] - nd['x']) ** 2 + (py[k] - nd['y']) ** 2
                        if d2 < 144 and (best is None or abs(pz[k] - nd['z']) < abs(best - nd['z'])):
                            best = pz[k]
            if best is None:
                miss += 1
            else:
                dz.append(nd['z'] - best)
    dz = np.array(dz)
    print('z check: %d nodes with a surface-1 vertex within 12: dz median %.2f p5 %.2f p95 %.2f, |dz|<2: %.1f %%; no road vertex near: %d' % (
        len(dz), np.median(dz), np.percentile(dz, 5), np.percentile(dz, 95), 100 * np.mean(np.abs(dz) < 2), miss))


def plot(g, path, coll):
    import numpy as np
    from PIL import Image, ImageDraw
    keep, X, Y, Z, nv = coll_rows(coll)
    xs = [n['x'] for s in g['sections'] for n in s['nodes']]
    ys = [n['y'] for s in g['sections'] for n in s['nodes']]
    x0, x1, y0, y1 = min(xs) - 60, max(xs) + 60, min(ys) - 60, max(ys) + 60
    sc = 0.4
    W, H = int((x1 - x0) * sc), int((y1 - y0) * sc)
    img = Image.new('RGB', (W, H), (14, 16, 22))
    dr = ImageDraw.Draw(img)

    def P(x, y):
        return ((x - x0) * sc, (y1 - y) * sc)
    for i in np.where(keep)[0]:
        dr.polygon([P(X[i, j], Y[i, j]) for j in range(nv[i])], fill=(70, 74, 86))
    pal = {'1': (255, 90, 90), '2': (255, 170, 60), '3': (90, 220, 120), '4': (80, 160, 255)}
    for s in g['sections']:
        c = pal.get(s['cls'][-2], (255, 255, 255))
        pts = [P(n['x'], n['y']) for n in s['nodes']]
        if len(pts) > 1:
            dr.line(pts, fill=c, width=2)
    S = {s['id']: s for s in g['sections']}
    for e in g['entries']:
        a, b = S[e['ss']]['nodes'][e['sn']], S[e['ds']]['nodes'][e['dn']]
        if (a['x'] - b['x']) ** 2 + (a['y'] - b['y']) ** 2 > 0.25:
            dr.line([P(a['x'], a['y']), P(b['x'], b['y'])], fill=(255, 255, 255), width=1)
    dr.text((8, 8), 'UG2 RoutesFreeRoam (L4RA): %d sections %d nodes %d links; grey = surface-1 ground collision; colour = class digit 1 red 2 orange 3 green 4 blue; white = links' % (
        len(g['sections']), sum(s['n'] for s in g['sections']), len(g['entries'])), fill=(240, 240, 240))
    img.save(path)
    print('wrote', path, img.size)


if __name__ == '__main__':
    ap = argparse.ArgumentParser()
    ap.add_argument('--sec', default='A')
    ap.add_argument('--dump', action='store_true')
    ap.add_argument('--png')
    ap.add_argument('--coll', default=os.path.join(REPO, 'build/ug2/coll_rows.bin'))
    ap.add_argument('--zcheck', action='store_true')
    a = ap.parse_args()
    g = load(a.sec)
    stats(g)
    if a.dump:
        dump(g)
    if a.zcheck:
        zcheck(g, a.coll)
    if a.png:
        plot(g, a.png, a.coll)
