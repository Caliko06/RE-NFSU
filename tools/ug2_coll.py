#!/usr/bin/env python3
"""ug2_coll.py: UG2 city collision (STREAML4RA.BUN) -> NFSU1 TrackPolygon rows.

UG2 keeps collision in 255 section chunks 0x80034130, each holding:
  0x34131 48 B header: u16 section id, u16 0, u16, u16, then f32 bbox-ish values (section corner, min, max).
  0x34134 32 B rows: the SAME layout as NFSU1 wsrc 0x34132 (tools/openworld/polys.py, Speed.exe 0x43ff30),
          absolute world coordinates (x, y = s16/8; z = s16 base + s16/256, x4 when flag 0x04).
  0x34136, 0x34137: per-section index tables (not needed: NFSU1 rebuilds its own wmap/wcell/widx).
Row byte +0 = barrier group: index into L4RA.BUN chunk 0x3412f (32 B entries: u32 hash, u32, byte +8 on/off, name +9;
  entry 0 "NONE", 1..125 PLAYER_BARRIERS_<race> / BARRIERS_<race>). The loader 0x5d8430 turns every entry off but 0;
  the collision queries 0x5e75c9 and 0x5e1027 skip a row whose group is off; 0x5d80f0 (callers 0x5f54f0..) turns one on
  for a race. Free Run enables none, so rows with byte +0 != 0 (12,049 rows, all finite surface-20 walls) are dropped here.
Output, in raw UG2 world units (the transform to NFSU1 space is applied later, by whoever places the city):
  build/ug2/coll_rows.bin  unique rows, 32 B each, byte +0 = 0, s16 +6 = -1 (as the NFSU1 loader expects)
usage: ug2_coll.py [STREAML4RA.BUN]   prints the counts written to census/ug2/coll.md
"""
import collections, os, struct, sys

REPO = os.path.abspath(os.path.join(os.path.dirname(os.path.abspath(__file__)), '..'))
BUN = '/Users/angeldamian/RE-NFSU-UG2/Need For Speed Underground 2/TRACKS/STREAML4RA.BUN'


def chunks(d, off, end):
    while off + 8 <= end:
        cid, size = struct.unpack_from('<II', d, off)
        yield off + 8, cid, size
        off += 8 + size


def sections(d):
    for p, cid, size in chunks(d, 0, len(d)):
        if cid == 0x80034130:
            yield {c: d[q:q + s] for q, c, s in chunks(d, p, p + size)}


def verts(r):
    fl, base = r[3], struct.unpack_from('<h', r, 4)[0]
    xs, ys, zs = (struct.unpack_from('<4h', r, o) for o in (8, 16, 24))
    k = 4 if fl & 4 else 1
    return [(xs[i] / 8, ys[i] / 8, (base + zs[i] / 256) * k) for i in range(4 if fl & 0x10 else 3)]


def main():
    d = open(sys.argv[1] if len(sys.argv) > 1 else BUN, 'rb').read()
    seen, rows, nsec, total, barrier = set(), [], 0, 0, 0
    flags = collections.Counter()
    for sec in sections(d):
        nsec += 1
        body = sec[0x34134]
        for o in range(0, len(body) - 31, 32):
            r = bytearray(body[o:o + 32])
            if r[0]:                    # race barrier wall, off unless its group is on (0x5e75c9)
                barrier += 1
                continue
            r[6:8] = b'\xff\xff'
            total += 1
            if bytes(r) in seen:
                continue
            seen.add(bytes(r))
            rows.append(bytes(r))
            flags[r[3]] += 1
    out = os.path.join(REPO, 'build', 'ug2', 'coll_rows.bin')
    os.makedirs(os.path.dirname(out), exist_ok=True)
    open(out, 'wb').write(b''.join(rows))
    vs = [v for r in rows for v in verts(r)]
    ground = sum(n for f, n in flags.items() if f & 0x0a == 0)
    print('sections', nsec, 'rows', total, 'barrier rows dropped', barrier, 'unique', len(rows), 'ground (flags & 0x0a == 0)', ground)
    for a, name in ((0, 'x'), (1, 'y'), (2, 'z')):
        print(name, min(v[a] for v in vs), max(v[a] for v in vs))
    print('flags', ' '.join('%02x:%d' % kv for kv in flags.most_common()))
    print('wrote', out, len(rows) * 32, 'B')


if __name__ == '__main__':
    main()
