#!/usr/bin/env python3
"""polys.py: TrackPolygons (TRACKB chunk 0x34132 'wsrc') of the L1RA street tracks, decoded as Speed.exe does.

Layout from the exe (2026-10-27):
  - loader 0x441380 (manager 0x77b130: +0 wmap 8 B rows, +8 wcell 16 B, +0x10 wsrc 32 B, +0x18 widx u16); it sets
    s16 @+6 of every row to -1 (runtime body index).
  - body build 0x43ff30 / 0x43fd20: byte +2 = surface (body+0xb), byte +3 = flags (body+10); vertex i:
    x = s16[+8+2i]/8, y = s16[+0x10+2i]/8, z = s16[+4] + s16[+0x18+2i]/256; flag 0x10 = 4 vertices (else 3),
    flag 0x04 = whole z times 4; plane normal at body+0x70.
  - ground query 0x440a40: only polygons with (flags & 0x0a) == 0 (car list built by 0x4407b0); off them the game
    returns 'no ground'. Measured: flags 0x00/0x10/0x11 are horizontal (ground), 0x12/0x16 vertical (walls);
    0x16 walls span z -508..508 (infinite).
usage: polys.py   (prints per-track counts and how many polygons the 16 tracks share byte for byte)"""
import collections, os, struct, sys
HERE = os.path.dirname(os.path.abspath(__file__))
os.environ.setdefault('NFSU1_MAIN', os.path.abspath(os.path.join(HERE, '..', '..')))
sys.path.insert(0, os.path.join(HERE, '..', '..', 'ref', 'tools', 'ug1-tracks'))
from lib import load, find, trackb_path, PC  # noqa: E402

TRACKS = list(range(1001, 1009)) + list(range(1102, 1110))


def rows(tid):
    d = load(trackb_path(PC, tid))
    (b, s), = find(d, 0x34132)
    return [bytes(d[o:o + 32]) for o in range(b, b + s - 31, 32)]


def key(r):  # the row without the runtime field s16 @+6
    return r[:6] + r[8:]


def decode(r):
    surf, flags, base = r[2], r[3], struct.unpack_from('<h', r, 4)[0]
    xs, ys, zs = (struct.unpack_from('<4h', r, o) for o in (8, 16, 24))
    k = 4 if flags & 4 else 1
    v = [(xs[i] / 8, ys[i] / 8, (base + zs[i] / 256) * k) for i in range(4 if flags & 0x10 else 3)]
    return dict(surf=surf, flags=flags, wall=bool(flags & 2), verts=v)


def main():
    own = collections.defaultdict(set)
    for t in TRACKS:
        rs = rows(t)
        for r in rs:
            own[key(r)].add(t)
        print(t, len(rs))
    n = sum(len(v) for v in own.values())
    print('summed %d, unique %d, shared by 2+ tracks %d' % (n, len(own), sum(1 for v in own.values() if len(v) > 1)))


if __name__ == '__main__':
    main()
