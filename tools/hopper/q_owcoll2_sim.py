#!/usr/bin/env python3
"""q_owcoll2_sim.py: Speed.exe's TrackPolygon loader and box query, ported line by line, run on a decompressed TRACKB.
  load()   = 0x441380 (chunks 0x34130..0x34134; alignment (hdr + 0x17) & ~0xf; counts size>>3, >>4, >>5, >>1)
  walk()   = 0x441530 (10-level quadtree from -16384, bit0 = x, bit1 = y, child 0 = empty, leaf value = wcell row)
  cell()   = 0x441660 (widx run -> wsrc rows, kept if byte0 == 0 and the 2-bit bbox selectors overlap the query box)
  query()  = 0x441c10 (cells of the box from floor32(min) while < max; at most `cap` = 0xa0 rows)
  usage: q_owcoll2_sim.py            (self test: merged vs per-track, on the files in game/Tracks)
"""
import os, struct, sys
HERE = os.path.dirname(os.path.abspath(__file__))
REPO = os.path.abspath(os.path.join(HERE, '..', '..'))
os.environ.setdefault('NFSU1_MAIN', REPO)
sys.path.insert(0, os.path.join(REPO, 'ref', 'tools', 'ug1-tracks'))
from lib import load as load_file, find, tree, trackb_path, PC  # noqa: E402


class World:
    def __init__(self, d, base=0):
        """d: decompressed TRACKB bytes; base: memory address of d[0] mod 16 (the loader aligns absolute addresses)"""
        self.d = d
        self.base = base
        for dep, cid, b, s in tree(d):
            if dep != 0:
                continue
            hdr = b - 8
            if cid == 0x34130:
                a = (base + hdr + 0x17) & ~0xf
                self.wmap, self.n_wmap = a - base, (s - (a - base - hdr - 8)) >> 3
            elif cid == 0x34131:
                a = (base + hdr + 0x17) & ~0xf
                self.wcell, self.n_wcell = a - base, (s - (a - base - hdr - 8)) >> 4
            elif cid == 0x34132:
                self.wsrc, self.n_wsrc = b, s >> 5
            elif cid == 0x34133:
                self.wide = s >= 4 and d[b:b + 4] == b'\xff\xff\xff\xff'   # u32 entries (PATCH 0x441423)
                self.widx, self.n_widx = (b + 4, (s - 4) >> 2) if self.wide else (b, s >> 1)
            elif cid == 0x34134:
                a = ((base + hdr + 0x17) & ~0xf) - base
                self.bbox = struct.unpack_from('<7f', d, a)

    def walk(self, x, y):
        """0x441530 with param_4 = 0: wcell row index for the point, 0 if none"""
        lx = ly = -16384.0
        node = self.wmap
        for lvl in range(10, 0, -1):
            half = (1 << lvl) * 32.0 * 0.5
            mx, my = lx + half, ly + half
            q = 0
            if mx <= x:
                q |= 1
                lx = mx
            if my <= y:
                q |= 2
                ly = my
            v = struct.unpack_from('<H', self.d, node + q * 2)[0]
            if v == 0:
                return 0
            if lvl == 1:
                return v
            node = self.wmap + v * 8
        return 0

    def row_vals(self, i):
        r = self.d[self.wsrc + 32 * i: self.wsrc + 32 * i + 32]
        xs = struct.unpack_from('<4h', r, 8)
        ys = struct.unpack_from('<4h', r, 16)
        sel = r[1]
        return (xs[sel & 3] / 8, ys[(sel >> 2) & 3] / 8, xs[(sel >> 4) & 3] / 8, ys[sel >> 6] / 8)

    def cell(self, row, qmin, qmax, out, seen, cap):
        """0x441660: row is a wcell row index"""
        cx, cy, off, cnt = struct.unpack_from('<2f2I', self.d, self.wcell + 16 * row)
        for k in range(off, off + cnt):
            i = struct.unpack_from('<I', self.d, self.widx + 4 * k)[0] if self.wide else struct.unpack_from('<H', self.d, self.widx + 2 * k)[0]
            if i in seen or self.d[self.wsrc + 32 * i] != 0:
                continue
            mnx, mny, mxx, mxy = self.row_vals(i)
            if mnx < qmax[0] and mny < qmax[1] and qmin[0] <= mxx and qmin[1] <= mxy and len(out) < cap:
                out.append(i)
                seen.add(i)  # the exe sets row byte 0 = 1 until the list is built, then clears it

    def query(self, qmin, qmax, cap=0xa0):
        out, seen = [], set()
        if not (-32768 < qmin[0] and qmax[0] < 32767 and -32768 < qmin[1] and qmax[1] < 32767):
            return out
        fl = lambda v: ((int(v * 65536) & -(1 << 21)) / 65536.0)  # 0x441500: ftol(v * 65536) & 0xffe00000 (32-bit signed mask)
        y = fl(qmin[1])
        while y < qmax[1]:
            x = fl(qmin[0])
            while x < qmax[0]:
                row = self.walk(x, y)
                if row:
                    self.cell(row, qmin, qmax, out, seen, cap)
                x += 32.0
            y += 32.0
        return out


def key(w, i):
    r = w.d[w.wsrc + 32 * i: w.wsrc + 32 * i + 32]
    return r[:6] + r[8:]


if __name__ == '__main__':
    import random
    ids = [int(a) for a in sys.argv[1:]] or [1001, 1102]
    for t in ids:
        d = load_file(trackb_path(PC, t))
        w = World(d)
        random.seed(t)
        n = hits = 0
        for k in range(2000):
            i = random.randrange(w.n_wsrc)
            r = w.row_vals(i)
            qmin = (r[0] - 1, r[1] - 1)
            qmax = (r[2] + 1, r[3] + 1)
            got = w.query(qmin, qmax, cap=100000)
            n += 1
            hits += i in got
        print(t, 'rows', w.n_wsrc, 'walk finds its own polygon in', hits, '/', n, 'random boxes; bbox', w.bbox)
