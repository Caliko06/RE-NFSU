#!/usr/bin/env python3
"""q_owcoll2_gen.py: re-derive TRACKB collision chunks 0x34130 wmap / 0x34131 wcell / 0x34133 widx / 0x34134 from the
wsrc rows (0x34132) of one real track, and compare byte for byte with the file. Also a writer for the same chunks
(derive()), reused by the merged-world builder.   usage: q_owcoll2_gen.py [track id ...]   (default: all 16)
Layouts and the query walk: build/openworld/re_coll.md (all from Speed.exe: loader 0x441380, walk 0x441530,
cell read 0x441660, box query 0x441c10)."""
import collections, math, os, struct, sys
HERE = os.path.dirname(os.path.abspath(__file__))
REPO = os.path.abspath(os.path.join(HERE, '..', '..'))
os.environ.setdefault('NFSU1_MAIN', REPO)
sys.path.insert(0, os.path.join(REPO, 'ref', 'tools', 'ug1-tracks'))
from lib import load, find, trackb_path, PC  # noqa: E402

CELL = 32          # world units per leaf cell (0x441530: (1<<1)*0.5*32 at the leaf level)
LEVELS = 10        # quadtree depth (0x441530 starts ecx = 10)
ORIGIN = -16384.0  # root box minimum on both axes (0x441530 local_8 = local_c = -16384.0)
SENT = 999999.0


def hull(pts):
    pts = sorted(set(pts))
    if len(pts) <= 2:
        return pts

    def cr(o, a, b):
        return (a[0] - o[0]) * (b[1] - o[1]) - (a[1] - o[1]) * (b[0] - o[0])
    lo = []
    for p in pts:
        while len(lo) >= 2 and cr(lo[-2], lo[-1], p) <= 0:
            lo.pop()
        lo.append(p)
    up = []
    for p in reversed(pts):
        while len(up) >= 2 and cr(up[-2], up[-1], p) <= 0:
            up.pop()
        up.append(p)
    return lo[:-1] + up[:-1]


def sat(h, x0, y0, x1, y1):
    """convex hull h (points or segment) vs the cell [x0, x1) x [y0, y1): bbox test half-open (poly.min < max edge,
    poly.max >= min edge), then separating axes of the polygon edges with the closed rectangle. This hybrid
    reproduces the files: a polygon touching only a corner (x1, y0) or (x0, y1) is listed, touching a max edge is not."""
    xs = [p[0] for p in h]
    ys = [p[1] for p in h]
    if not (x0 <= max(xs) and min(xs) < x1 and y0 <= max(ys) and min(ys) < y1):
        return False
    n = len(h)
    if n == 1:
        return True
    edges = [(h[(k + 1) % n][0] - h[k][0], h[(k + 1) % n][1] - h[k][1]) for k in range(n)] if n > 2 else \
        [(h[1][0] - h[0][0], h[1][1] - h[0][1])]
    for ex, ey in edges:
        ax, ay = -ey, ex
        pr = [ax * p[0] + ay * p[1] for p in h]
        rc = [ax * x + ay * y for x in (x0, x1) for y in (y0, y1)]
        if not (min(rc) <= max(pr) and min(pr) <= max(rc)):
            return False
    return True


def row_xy8(r):
    """vertices of a 32 B wsrc row in 1/8 units (0x43ff30: x = s16[+8+2i]/8, y = s16[+0x10+2i]/8; flag 0x10 = 4 verts)"""
    n = 4 if r[3] & 0x10 else 3
    xs = struct.unpack_from('<4h', r, 8)
    ys = struct.unpack_from('<4h', r, 16)
    return [(xs[k], ys[k]) for k in range(n)]


def cells_of(r):
    """leaf cells (i, j) [corner = 32*i, 32*j] that the polygon touches: closed polygon vs half-open cell"""
    h = hull(row_xy8(r))
    xs = [p[0] for p in h]
    ys = [p[1] for p in h]
    out = []
    for i in range(math.floor(min(xs) / 256) - 1, math.floor(max(xs) / 256) + 2):
        for j in range(math.floor(min(ys) / 256) - 1, math.floor(max(ys) / 256) + 2):
            if sat(h, i * 256, j * 256, i * 256 + 256, j * 256 + 256):
                out.append((i, j))
    return out


def derive(rows, order='yx', node_order='cell', wide=False):
    """rows: list of 32 B wsrc rows. returns dict of chunk payloads (unpadded) + helpers"""
    cell_polys = collections.OrderedDict()
    for pi, r in enumerate(rows):
        cs = cells_of(r)
        cs.sort(key=(lambda c: (c[0], c[1])) if order == 'xy' else (lambda c: (c[1], c[0])))
        for c in cs:
            cell_polys.setdefault(c, []).append(pi)
    return build(cell_polys, node_order, wide)


def build(cell_polys, node_order='cell', wide=False):
    """cell_polys: ordered {(i, j): [poly idx ascending]} -> wcell rows, widx, wmap rows"""
    wcell = [struct.pack('<2f2I', SENT, SENT, 0, 0)]
    widx = []
    for (i, j), pl in cell_polys.items():
        wcell.append(struct.pack('<2f2I', i * CELL + CELL / 2, j * CELL + CELL / 2, len(widx), len(pl)))
        widx.extend(pl)
    nodes = [[0, 0, 0, 0]]
    for row, (i, j) in enumerate(cell_polys.keys(), 1):
        bx, by = i + 512, j + 512  # cell index from the root-box origin (-16384 / 32 = -512)
        assert 0 <= bx < 1024 and 0 <= by < 1024, 'cell outside the quadtree'
        n = 0
        for lvl in range(LEVELS, 0, -1):
            b = lvl - 1  # bit of the cell index decided at this level (level 10 = bit 9)
            q = ((bx >> b) & 1) | (((by >> b) & 1) << 1)
            if lvl == 1:
                assert nodes[n][q] == 0
                nodes[n][q] = row
            else:
                if nodes[n][q] == 0:
                    nodes.append([0, 0, 0, 0])
                    nodes[n][q] = len(nodes) - 1
                n = nodes[n][q]
    return dict(wmap=b''.join(struct.pack('<4H', *n) for n in nodes), wcell=b''.join(wcell),
                widx=struct.pack('<%d%s' % (len(widx), 'I' if wide else 'H'), *widx), nodes=len(nodes), cells=len(cell_polys))


def chunks(d):
    """real chunk payloads of one TRACKB (decompressed bytes): (data after the alignment pad, pad length)"""
    out = {}
    for cid in (0x34130, 0x34131, 0x34132, 0x34133, 0x34134):
        (b, s), = find(d, cid)
        a = (b + 15) & ~15 if cid in (0x34130, 0x34131, 0x34134) else b
        out[cid] = (bytes(d[a:b + s]), a - b)
    return out


def main():
    ids = [int(x) for x in sys.argv[1:]] or list(range(1001, 1009)) + list(range(1102, 1110))
    tot = ok = 0
    for t in ids:
        d = load(trackb_path(PC, t))
        ch = chunks(d)
        ws = ch[0x34132][0]
        rows = [ws[o:o + 32] for o in range(0, len(ws), 32)]
        best = derive(rows)
        line = [str(t)]
        for k, c in (('wmap', 0x34130), ('wcell', 0x34131), ('widx', 0x34133)):
            a, b = best[k], ch[c][0]
            if k == 'widx' and (len(a) // 2) % 2:
                a += b'\0\0'  # odd entry count: one u16 0 pads the chunk to a multiple of 4 B
            same = sum(1 for x, y in zip(a, b) if x == y) if len(a) == len(b) else 0
            line.append('%s %d/%d B (%.2f%%) %s' % (k, same, len(b), 100.0 * same / max(1, len(b)),
                                                      'MATCH' if a == b else 'len %d vs %d' % (len(a), len(b))))
            tot += len(b)
            ok += same
        print(' | '.join(line), flush=True)
    print('total match %.4f%% (%d/%d bytes)' % (100.0 * ok / max(1, tot), ok, tot))


if __name__ == '__main__':
    main()
