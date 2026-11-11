#!/usr/bin/env python3
"""Stand-in for web/ug2/city.bin until the real UG2 mesh exists: a grid of boxes in the same file format
(16-byte header 'UG2M', nverts, nidx, 0; verts f32 xyz + u8 rgba; u32 triangle-list indices).
usage: tools/probe/ug2_standin.py [out.bin]   (default web/ug2/city.bin). Never overwrites a real mesh: refuses if the file exists."""
import os, random, struct, sys
out = sys.argv[1] if len(sys.argv) > 1 else os.path.join(os.path.dirname(__file__), '..', '..', 'web', 'ug2', 'city.bin')
if os.path.exists(out): sys.exit(f'{out} exists, not overwriting')
random.seed(2)
V, I = [], []
def box(x, y, w, d, h, rgb):
    x0, x1, y0, y1 = x - w / 2, x + w / 2, y - d / 2, y + d / 2
    n = len(V)
    for z in (0, h):
        for px, py in ((x0, y0), (x1, y0), (x1, y1), (x0, y1)): V.append((px, py, z, *rgb, 255))
    for a, b, c, d_ in ((0, 1, 2, 3), (4, 7, 6, 5), (0, 4, 5, 1), (1, 5, 6, 2), (2, 6, 7, 3), (3, 7, 4, 0)):
        I.extend((n + a, n + b, n + c, n + a, n + c, n + d_))
for gx in range(-10, 11):
    for gy in range(-10, 11):
        h = random.choice((12, 20, 35, 60, 90)) * (1.8 if abs(gx) + abs(gy) < 4 else 1)
        g = random.randint(70, 150)
        box(gx * 100, gy * 100, 40, 40, h, (g + random.randint(0, 40), g, g - random.randint(0, 30)))
os.makedirs(os.path.dirname(out), exist_ok=True)
with open(out, 'wb') as f:
    f.write(b'UG2M' + struct.pack('<III', len(V), len(I), 0))
    for v in V: f.write(struct.pack('<fffBBBB', *v))
    f.write(struct.pack(f'<{len(I)}I', *I))
print(out, len(V), 'verts', len(I) // 3, 'tris')
