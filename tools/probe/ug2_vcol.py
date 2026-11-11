#!/usr/bin/env python3
"""ug2_vcol.py: vertex colour statistics of the UG2 RA city (census/ug2/light.md).
usage: python3 -I tools/probe/ug2_vcol.py [city.bin] [STREAML4RA.BUN]
 A) city.bin ('UG2M', u32 nverts @4, 16-byte records f32 xyz + u8 R,G,B,A @12..15): drawn vertices (instance weighted).
 B) raw solids of STREAML4RA.BUN per vertex mask (mesh header 0x134900 u32[3]), per-solid (unweighted), colour = bytes 12..15 BGRA."""
import os, struct, sys
import numpy as np
sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), '..'))
import ug2_world as W

REPO = os.path.abspath(os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', '..'))
CITY = sys.argv[1] if len(sys.argv) > 1 else os.path.join(REPO, 'web', 'ug2', 'city.bin')
BUN = sys.argv[2] if len(sys.argv) > 2 else os.path.join(W.TRACKS, 'STREAML4RA.BUN')
PCT = [1, 5, 25, 50, 75, 95, 99]


def report(title, c):  # c: (n,4) uint8 in order R,G,B,A
    print('\n' + title, 'n =', len(c))
    for k, nm in enumerate('RGBA'):
        x = c[:, k]
        print('  %s mean %6.2f  pct %s  min %d max %d' % (nm, x.mean(), ' '.join('p%d=%d' % (p, v) for p, v in zip(PCT, np.percentile(x, PCT))), x.min(), x.max()))
    lum = (0.299 * c[:, 0] + 0.587 * c[:, 1] + 0.114 * c[:, 2])
    print('  luma mean %.2f  p50 %.0f ; share rgb<=64: %.3f  rgb>=128 (x2 overbright): %.3f  rgb==255: %.3f' % (
        lum.mean(), np.percentile(lum, 50), (c[:, :3].max(1) <= 64).mean(), (c[:, :3].max(1) >= 128).mean(), (c[:, :3].min(1) == 255).mean()))
    a = c[:, 3]
    print('  alpha: ==255 %.4f  ==0 %.4f  1..254 %.4f ; distinct values %d' % ((a == 255).mean(), (a == 0).mean(), ((a > 0) & (a < 255)).mean(), len(np.unique(a))))
    print('  x2 modulate (min(2*v,255)) mean R %.1f G %.1f B %.1f ; share of vertices where 2x saturates a channel: %.3f' % (
        np.minimum(c[:, 0] * 2, 255).mean(), np.minimum(c[:, 1] * 2, 255).mean(), np.minimum(c[:, 2] * 2, 255).mean(), (c[:, :3].max(1) >= 128).mean()))


def main():
    with open(CITY, 'rb') as f:
        hd = f.read(16)
        nv = struct.unpack_from('<I', hd, 4)[0]
    rec = np.memmap(CITY, dtype=np.uint8, mode='r', offset=16, shape=(nv, 16))
    report('A) city.bin drawn vertices (RGBA)', np.asarray(rec[:, 12:16]))
    d = open(BUN, 'rb').read()
    t = W.tree(d)
    by = {}
    k, n = 0, len(t)
    while k < n:
        i, b, s, dep = t[k]
        if i == 0x80134010:
            end, sol = b + s, {}
            k += 1
            while k < n and t[k][1] < end:
                j, b2, s2, _ = t[k]
                if j == 0x134900:
                    q, _ = W.pay(d, b2, s2)
                    h = struct.unpack_from('<16I', d, q)
                    sol['nv'], sol['mask'] = h[13], h[3]
                elif j == 0x134b01:
                    sol['v'], sol['vs'] = W.pay(d, b2, s2, 128)[0], s2
                k += 1
            if sol.get('nv') and 'v' in sol:
                st = 36 if sol['mask'] == 0x4180 else 24
                off = 24 if st == 36 else 12
                if sol['v'] + sol['nv'] * st <= len(d):
                    raw = np.frombuffer(d, dtype=np.uint8, count=sol['nv'] * st, offset=sol['v']).reshape(-1, st)
                    by.setdefault(sol['mask'], []).append(raw[:, off:off + 4][:, [2, 1, 0, 3]])
        else:
            k += 1
    for m, l in sorted(by.items()):
        report('B) raw solids mask 0x%x (%d chunks, colour at +%d)' % (m, len(l), 24 if m == 0x4180 else 12), np.concatenate(l))


main()
