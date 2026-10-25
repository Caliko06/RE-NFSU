# Reader of save/geodump/f<frame>.bin (host/d3d9.c RN_GEODUMP). usage: geodump.py census FILE...
import struct, sys, collections
DTYPE = {0: ('f', 1), 1: ('f', 2), 2: ('f', 3), 3: ('f', 4), 4: ('B', 4), 5: ('B', 4), 6: ('h', 2), 7: ('h', 4), 8: ('B', 4)}
USAGE = {0: 'POS', 1: 'BW', 2: 'BI', 3: 'NRM', 4: 'PSIZE', 5: 'UV', 6: 'TAN', 7: 'BIN', 10: 'COL'}

def draws(path):
    b = open(path, 'rb').read(); o = 0
    while o < len(b):
        h = struct.unpack_from('<16I', b, o); o += 64
        caller, vsh, psh, stride, nvert, nidx, typ, k0l, k0h, k1l, k1h, ne, fvf, rtw, rth, bv = h
        els = []
        for k in range(ne):
            s, off, t, meth, use, ui = struct.unpack_from('<HHBBBB', b, o + 8 * k)
            if s != 0xff: els.append((off, t, use, ui))
        o += 8 * ne
        vsc = struct.unpack_from('<384f', b, o); o += 1536
        xf = struct.unpack_from('<48f', b, o); o += 192
        vb = b[o:o + nvert * stride]; o += nvert * stride
        idx = struct.unpack_from(f'<{nidx}I', b, o); o += 4 * nidx
        yield dict(caller=caller, vs=vsh, ps=psh, stride=stride, nvert=nvert, nidx=nidx, type=typ, tex0=k0h << 32 | k0l,
                   tex1=k1h << 32 | k1l, els=els, fvf=fvf, rt=(rtw, rth), vsc=vsc, xf=xf, vb=vb, idx=idx)

def attr(d, use, ui=0):
    """Rows of one vertex element as tuples, or None."""
    for off, t, u, i in d['els']:
        if u == use and i == ui and t in DTYPE:
            f, n = DTYPE[t]; sz = struct.calcsize(f) * n
            return [struct.unpack_from(f'<{n}{f}', d['vb'], v * d['stride'] + off) for v in range(d['nvert'])]
    return None

if __name__ == '__main__' and sys.argv[1] == 'census':
    g = collections.defaultdict(lambda: [0, 0, 0, None, None, set()])
    for p in sys.argv[2:]:
        for d in draws(p):
            k = (d['vs'], d['stride'], d['rt'])
            e = g[k]; e[0] += 1; e[1] += d['nidx'] // 3; e[2] += d['nvert']; e[3] = ' '.join(f"{USAGE.get(u, u)}{i}:{t}@{off}" for off, t, u, i in d['els']); e[4] = hex(d['caller']); e[5].add(d['type'])
    for k, e in sorted(g.items(), key=lambda x: -x[1][1]):
        print(f"vs {k[0]:08x} stride {k[1]:3d} rt {k[2][0]}x{k[2][1]} draws {e[0]:5d} tris {e[1]:7d} verts {e[2]:7d} types {sorted(e[5])} caller {e[4]} | {e[3]}")
