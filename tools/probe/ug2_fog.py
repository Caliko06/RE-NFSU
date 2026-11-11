#!/usr/bin/env python3
"""Decode the UG2 fog tunable tables (chunk 0x8003b600 / 0x8003b601) of a TRACKS/L4Rx.BUN.
Layout proven from SPEED2.EXE loader 0x5fa3b0 (child ids 0x3b602..0x3b608), lookup 0x5f0930 (0x3b607, 4-byte quadtree) / 0x5f0a30 (0x3b608, u16) and 0x5fa4e0 (row = b605 + idx*hdr[+0x1c]).
usage: ug2_fog.py L4RA.BUN [x y]   -> prints tables; with x y also the leaf row for that position."""
import struct, sys
def h(s):
    x = 0xffffffff
    for c in s.encode(): x = (x * 33 + c) & 0xffffffff
    return x
NAMES = {h(n): n for n in ["Normal Fog", "Night Normal Fog", "Night Raining Fog", "Fog Blend Distance"]}
def entries(d):
    o = d.find(struct.pack('<I', 0x8003b600))
    while o >= 0:
        sz = struct.unpack_from('<I', d, o + 4)[0]
        p, end = o + 8, o + 8 + sz
        while p < end:
            cid, s = struct.unpack_from('<II', d, p)
            if cid == 0x8003b601:
                yield p + 8, s
            p += 8 + s
        o = d.find(struct.pack('<I', 0x8003b600), o + 1)
        break
def parse(d, p, s):
    kids, q = {}, p
    while q < p + s:
        cid, cs = struct.unpack_from('<II', d, q)
        kids[cid] = (q + 8, cs); q += 8 + cs
    ho, _ = kids[0x0003b602]
    hdr = struct.unpack_from('<I4f4I', d, ho)
    name = NAMES.get(hdr[0])
    e = dict(hash=hdr[0], name=name, bounds=hdr[1:5], nodes=hdr[5], rows=hdr[6], stride=hdr[7], cols=hdr[8], kids=kids)
    g = lambda c: d[kids[c][0]:kids[c][0] + kids[c][1]] if c in kids else b''
    e['b603'] = struct.unpack('<%di' % (len(g(0x0003b603)) // 4), g(0x0003b603))
    e['b604'] = struct.unpack('<%di' % (len(g(0x0003b604)) // 4), g(0x0003b604))
    e['b605'] = g(0x0003b605); e['n8'] = g(0x0003b607); e['n16'] = g(0x0003b608)
    return e
def leaf(e, a1, a2):
    """quadtree walk of 0x5f0930 (bytes, chunk 0x3b607) or 0x5f0a30 (u16, chunk 0x3b608); a1 in x-bounds, a2 in y-bounds"""
    x0, y0, x1, y1 = e['bounds']
    if not (x0 < a1 <= x1 and y0 < a2 <= y1): return None
    w = 1 if e['n8'] else 2
    t = e['n8'] or e['n16']
    f = (lambda n, k: t[4 * n + k]) if w == 1 else (lambda n, k: struct.unpack_from('<H', t, 8 * n + 2 * k)[0])
    n = 0
    while f(n, 0) != 0:
        mx, my = (x1 + x0) * .5, (y1 + y0) * .5
        if a1 < mx:
            if a2 < my: n, y1 = f(n, 0), my
            else: n, y0 = f(n, 1), my
            x1 = mx
        else:
            if a2 < my: n, y1 = f(n, 2), my
            else: n, y0 = f(n, 3), my
            x0 = mx
    return f(n, 1)
def row(e, i):
    st = e['stride']; return struct.unpack('<%df' % (st // 4), e['b605'][i * st:(i + 1) * st])
if __name__ == '__main__':
    d = open(sys.argv[1], 'rb').read()
    for p, s in entries(d):
        e = parse(d, p, s)
        if not e['name']: continue
        print('==', e['name'], hex(e['hash']), 'chunk@', hex(p - 8), 'bounds', e['bounds'], 'nodes', e['nodes'], 'rows', e['rows'], 'stride', e['stride'], 'cols', e['cols'])
        print(' b603', e['b603'], 'b604', e['b604'], '0x3b607 bytes', len(e['n8']), '0x3b608 bytes', len(e['n16']))
        for i in range(e['rows']): print(' row', i, [round(v, 4) for v in row(e, i)])
        if len(sys.argv) > 3: print(' leaf', leaf(e, float(sys.argv[2]), float(sys.argv[3])))
