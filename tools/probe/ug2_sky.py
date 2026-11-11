#!/usr/bin/env python3
"""Describe the SKYDOME solid (hash 0xbe43edbb = hash('SKYDOME'), exe 0x5c59ec) of STREAML4RA.BUN: mask, groups, texture hashes,
vertex extents and colours, and where the scenery sections place it. Reuses tools/ug2_world.py scan()/tree()/pay() (read only)."""
import importlib.util, os, struct, sys
import numpy as np
here = os.path.dirname(os.path.abspath(__file__))
spec = importlib.util.spec_from_file_location('ug2_world', os.path.join(here, '..', 'ug2_world.py'))
w = importlib.util.module_from_spec(spec); spec.loader.exec_module(w)
path = sys.argv[1] if len(sys.argv) > 1 else w.TRACKS + '/STREAML4RA.BUN'
d = open(path, 'rb').read()
t = w.tree(d)
SKY = 0xbe43edbb
def hsh(s):
    x = 0xffffffff
    for c in s.encode(): x = (x * 33 + c) & 0xffffffff
    return x
tex = {hsh(n): n for n in ['SKY_SUNRISE_A', 'SKY_SUNRISE_A_CAP', 'SKY_NIGHT_A', 'SKY_NIGHT_A_CAP', 'SKY_SUNSET_A', 'SKY_SUNSET_A_CAP']}
k = 0
while k < len(t):
    i, b, s, dep = t[k]
    if i == 0x80134010:
        end = b + s; k += 1; sol = {}; kids = []
        while k < len(t) and t[k][1] < end:
            kids.append(t[k]); k += 1
        for j, b2, s2, _ in kids:
            if j == 0x134011:
                q, _ = w.pay(d, b2, s2); sol['hash'] = struct.unpack_from('<I', d, q + 0x10)[0]; sol['name'] = d[q + 0xa4:q + 0xc0].split(b'\0')[0]
        if sol.get('hash') != SKY: continue
        print('SKYDOME solid, container chunk at', hex(b - 8), 'name', sol['name'])
        for j, b2, s2, _ in kids:
            q, l = w.pay(d, b2, s2)
            if j == 0x134900:
                h = struct.unpack_from('<16I', d, q); print(' mesh header 0x134900 u32[16]', [hex(x) for x in h], '-> mask', hex(h[3]), 'ntri', h[9], 'nv', h[13])
            elif j == 0x134012:
                hs = struct.unpack_from('<%dI' % (l // 8 * 2), d, q); print(' texture table 0x134012', [(hex(hs[n]), tex.get(hs[n], '?')) for n in range(0, len(hs), 2)])
            elif j == 0x134b02:
                n = l // 0x3c
                for g in range(n):
                    r = d[q + g * 0x3c:q + g * 0x3c + 0x3c]
                    print(' group', g, 'tex slot', r[0x1c], 'material slot', hex(r[0x20]), 'index count', struct.unpack_from('<I', r, 0xc)[0], 'start', struct.unpack_from('<I', r, 0x34)[0], 'bbox', np.frombuffer(r[:12], '<f').round(1), np.frombuffer(r[0x10:0x1c], '<f').round(1))
            elif j == 0x134b01:
                vq = w.pay(d, b2, s2, 128)[0]
                nv = [x for x in kids if x[0] == 0x134900]
                hq = w.pay(d, nv[0][1], nv[0][2])[0]; hh = struct.unpack_from('<16I', d, hq); n = hh[13]; stride = 36 if hh[3] == 0x4180 else 24; coff = 24 if hh[3] == 0x4180 else 12
                a = np.frombuffer(d, np.uint8, n * stride, vq).reshape(n, stride)
                xyz = a[:, :12].copy().view('<f4').reshape(n, 3); col = a[:, coff:coff + 4]
                print(' vertices', n, 'stride', stride, 'xyz min', xyz.min(0).round(1), 'max', xyz.max(0).round(1))
                for z in (xyz[:, 2].min(), xyz[:, 2].max()):
                    m = xyz[:, 2] == z
                    print('  at z=%.1f' % z, int(m.sum()), 'verts; colour BGRA mean', col[m].mean(0).round(1))
                print('  colour BGRA mean all', col.mean(0).round(1), 'min', col.min(0), 'max', col.max(0))
    else: k += 1
# placements: sections with a def whose solid hash == SKY
for j, (defs, inst) in enumerate([(None, None)]): pass
d2, sol2, secs = w.scan(path)
for si, (defs, inst) in enumerate(secs):
    ids = [n for n, (h0, h1) in enumerate(defs) if h0 == SKY or h1 == SKY]
    if not ids: continue
    for r in inst:
        defn = struct.unpack_from('<H', r.tobytes(), 24)[0]
        if defn in ids: print('section', si, 'instance def', defn, 'pos', np.frombuffer(r.tobytes()[32:44], '<f').round(1), 'flags', hex(struct.unpack_from('<H', r.tobytes(), 26)[0]), 'matrix s16/8192', (np.frombuffer(r.tobytes()[44:62], '<i2') / 8192).round(2))
