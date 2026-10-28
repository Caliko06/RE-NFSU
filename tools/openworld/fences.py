#!/usr/bin/env python3
"""fences.py: which TrackPolygon walls of the L1RA street tracks are fences (street closures), from the game's data.

Criterion (no tuning): the 16 tracks are cuts of one city mesh (polys.py). A wall W of track A is a fence when some
other track B has ground polygons on BOTH sides of W, right at W, and B's own wsrc does not hold W: Speed.exe, loading
B, lets the car drive straight through that spot. A wall that every track with ground there also carries is part of
the city (building, median, rail) and stays.

Ground = (flags & 0x0a) == 0, the polygons the car's ground query 0x440a40 uses. The probe points sit PROBE units off
the wall's base segment, on each side, at its midpoint.

Writes census/openworld_fences.json (per wall: key hex, owner tracks, the tracks that drive through it, base segment)
and build/openworld/fences.png (union walls grey, fences red). Run: python3 tools/openworld/fences.py

Mode --z (python3 tools/openworld/fences.py --z): the same question with the exe's ground rule, z included.
"ground of track B at p" = the ground polygons of B that contain p by the exe's own test (0x440b50: stored bbox
inclusive, edge test 0x4400e0 with the boundary inside, plane z = -((n.p_xy) - n.v0) / nz); the car's level is the
plane z, and the exe only accepts a plane with z < zq + 1.0 (0x6cc7bc), so a car at level g can continue onto ground
of height < g + 1.0 and, by the same rule read the other way, back. B drives through W when a car can cross in two
hops of PROBE: B has a ground level g at the middle of W's footprint inside W's z range (a wall only stops the
levels it spans), and on each side a level within < 1.0 of g. The 2D test above also counted a deck of another
level as ground. Writes census/openworld_fences_z.json and build/openworld/fences_z.png (grey walls, red
kept, blue removed vs the 2D set, green added). --z=top is the literal variant (zq = top of the wall, highest
ground below it per side). Sensitivity to the side offset: --z-sweep.
"""
import collections, json, math, os, sys
HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import polys  # noqa: E402

REPO = os.path.abspath(os.path.join(HERE, '..', '..'))
OUT = os.path.join(REPO, 'census', 'openworld_fences.json')
PNG = os.path.join(REPO, 'build', 'openworld', 'fences.png')
OUT_Z = os.path.join(REPO, 'census', 'openworld_fences_z.json')
PNG_Z = os.path.join(REPO, 'build', 'openworld', 'fences_z.png')
STEP = 1.0  # Speed.exe 0x6cc7bc (float 1.0 at 0x440b1a): a plane is accepted only when z < zq + STEP
CELL = 16
PROBE = 1.0


def inside(p, vs):  # point in the xy projection of a convex polygon
    s = 0
    for i in range(len(vs)):
        a, b = vs[i], vs[(i + 1) % len(vs)]
        c = (b[0] - a[0]) * (p[1] - a[1]) - (b[1] - a[1]) * (p[0] - a[0])
        if c and s and (c > 0) != (s > 0):
            return False
        s = s or c
    return True


def base(vs):  # the wall's footprint: its two most distant xy points
    best = (0, vs[0], vs[1])
    for i in range(len(vs)):
        for j in range(i + 1, len(vs)):
            d = math.dist(vs[i][:2], vs[j][:2])
            if d > best[0]:
                best = (d, vs[i], vs[j])
    return best[1][:2], best[2][:2]


def main():
    own, dec = collections.defaultdict(set), {}
    for t in polys.TRACKS:
        for r in polys.rows(t):
            k = polys.key(r)
            own[k].add(t)
            dec.setdefault(k, polys.decode(r))
    grid = collections.defaultdict(list)
    for k, d in dec.items():
        if d['flags'] & 0x0a:
            continue
        xs, ys = [v[0] for v in d['verts']], [v[1] for v in d['verts']]
        for cx in range(int(min(xs) // CELL), int(max(xs) // CELL) + 1):
            for cy in range(int(min(ys) // CELL), int(max(ys) // CELL) + 1):
                grid[(cx, cy)].append(k)

    def ground_tracks(p):
        ts = set()
        for k in grid.get((int(p[0] // CELL), int(p[1] // CELL)), ()):
            if inside(p, [v[:2] for v in dec[k]['verts']]):
                ts |= own[k]
        return ts

    walls = [k for k, d in dec.items() if d['wall']]
    fences = []
    for k in walls:
        a, b = base(dec[k]['verts'])
        L = math.dist(a, b)
        if L < 1e-3:
            continue
        m = ((a[0] + b[0]) / 2, (a[1] + b[1]) / 2)
        nx, ny = -(b[1] - a[1]) / L, (b[0] - a[0]) / L
        through = (ground_tracks((m[0] + nx * PROBE, m[1] + ny * PROBE)) &
                   ground_tracks((m[0] - nx * PROBE, m[1] - ny * PROBE))) - own[k]
        if through:
            fences.append(dict(key=k.hex(), flags=dec[k]['flags'], owners=sorted(own[k]), through=sorted(through),
                               seg=[list(a), list(b)]))
    byflag = collections.Counter(f['flags'] for f in fences)
    print('walls %d, fences %d (%s)' % (len(walls), len(fences), dict(byflag)))
    json.dump(dict(criterion=__doc__.split('\n\n')[1], walls=len(walls), fences=fences), open(OUT, 'w'), indent=0)

    from PIL import Image, ImageDraw
    x0, y0, x1, y1 = -700, -2000, 2400, 800
    S = 1.0
    im = Image.new('RGB', (int((x1 - x0) * S), int((y1 - y0) * S)), (255, 255, 255))
    dr = ImageDraw.Draw(im)
    P = lambda p: ((p[0] - x0) * S, (y1 - p[1]) * S)
    for k in walls:
        a, b = base(dec[k]['verts'])
        dr.line([P(a), P(b)], fill=(170, 170, 170), width=1)
    for f in fences:
        dr.line([P(f['seg'][0]), P(f['seg'][1])], fill=(220, 0, 0), width=3)
    im.save(PNG)
    print('wrote', OUT, PNG)


# ---- --z: the exe's ground rule with z ------------------------------------------------------------------------

def load():
    own, dec = collections.defaultdict(set), {}
    for t in polys.TRACKS:
        for r in polys.rows(t):
            k = polys.key(r)
            own[k].add(t)
            dec.setdefault(k, polys.decode(r))
    return own, dec


class ExeGround:
    """Ground polygons as 0x440b50 sees them: per polygon the stored bbox, the CCW vertices (v3 = v2 for a triangle)
    and the plane (0x43ff30: n = (v1-v0) x (v2-v0), d = n.v0; z = -((nx x + ny y) - d) / nz)."""

    def __init__(self, own, dec):
        self.own, self.dec, self.grid, self.poly = own, dec, collections.defaultdict(list), {}
        for k, d in dec.items():
            if d['flags'] & 0x0a:  # not ground (0x4407b0 keeps (flags & 10) == 0 first)
                continue
            vs = d['verts']
            (x0, y0, z0), (x1, y1, z1), (x2, y2, z2) = vs[:3]
            ux, uy, uz, vx, vy, vz = x1 - x0, y1 - y0, z1 - z0, x2 - x0, y2 - y0, z2 - z0
            nx, ny, nz = uy * vz - uz * vy, uz * vx - ux * vz, ux * vy - uy * vx
            if nz == 0:
                continue
            xs, ys = [v[0] for v in vs], [v[1] for v in vs]
            self.poly[k] = (min(xs), min(ys), max(xs), max(ys), [v[:2] for v in vs], nx, ny, nz, nx * x0 + ny * y0 + nz * z0)
            for cx in range(int(min(xs) // CELL), int(max(xs) // CELL) + 1):
                for cy in range(int(min(ys) // CELL), int(max(ys) // CELL) + 1):
                    self.grid[(cx, cy)].append(k)

    def stack(self, p):
        """[(z, owner tracks)] of every ground polygon the exe's test accepts at p, any z."""
        out = []
        for k in self.grid.get((int(p[0] // CELL), int(p[1] // CELL)), ()):
            x0, y0, x1, y1, vs, nx, ny, nz, d = self.poly[k]
            if not (x0 <= p[0] <= x1 and y0 <= p[1] <= y1):  # bbox, inclusive (0x440b54-0x440b8e)
                continue
            if any((p[0] - a[0]) * (b[1] - a[1]) - (b[0] - a[0]) * (p[1] - a[1]) > 0
                   for a, b in zip(vs, vs[1:] + vs[:1])):  # 0x4400e0: > 0 is outside, 0 (edge) is inside
                continue
            out.append((-((nx * p[0] + ny * p[1]) - d) / nz, self.own[k]))
        return out


def z_through(g, dec, own, k, probe, mode):
    d = dec[k]
    a, b = base(d['verts'])
    L = math.dist(a, b)
    if L < 1e-3:
        return None
    m = ((a[0] + b[0]) / 2, (a[1] + b[1]) / 2)
    nx, ny = -(b[1] - a[1]) / L, (b[0] - a[0]) / L
    zs = [v[2] for v in d['verts']]
    z0, z1 = min(zs), max(zs)
    sides = [g.stack((m[0] + nx * probe * s, m[1] + ny * probe * s)) for s in (1, -1)]
    mid = g.stack(m)
    through = []
    for B in polys.TRACKS:
        if B in own[k]:
            continue
        lv = [sorted(z for z, o in st if B in o) for st in sides]
        if not (lv[0] and lv[1]):
            continue
        if mode == 'top':  # zq = top of the wall; the car's level = the highest ground below zq + STEP
            hi = [max((z for z in l if z < z1 + STEP), default=None) for l in lv]
            if None not in hi and abs(hi[0] - hi[1]) < STEP:
                through.append(B)
        elif any(z0 <= c <= z1 and any(abs(u - c) < STEP for u in lv[0]) and any(abs(v - c) < STEP for v in lv[1])
                 for c in (z for z, o in mid if B in o)):
            through.append(B)
    return through, a, b


def z_set(own, dec, g, probe=PROBE, mode='levels'):
    res = {}
    for k, d in dec.items():
        if d['wall']:
            r = z_through(g, dec, own, k, probe, mode)
            if r and r[0]:
                res[k] = r
    return res


def main_z(mode):
    own, dec = load()
    g = ExeGround(own, dec)
    walls = [k for k, d in dec.items() if d['wall']]
    new = z_set(own, dec, g, PROBE, mode)
    old = {bytes.fromhex(f['key']): f for f in json.load(open(OUT))['fences']}
    kept = [k for k in new if k in old]
    added = [k for k in new if k not in old]
    removed = [k for k in old if k not in new]
    print('mode %s: walls %d, z fences %d, 2D fences %d: kept %d, added %d, removed %d' %
          (mode, len(walls), len(new), len(old), len(kept), len(added), len(removed)))
    fl = lambda ks: dict(collections.Counter(dec[k]['flags'] for k in ks))
    print('flags z', fl(new), 'removed', fl(removed), 'added', fl(added))
    fences = [dict(key=k.hex(), flags=dec[k]['flags'], owners=sorted(own[k]), through=sorted(t),
                   seg=[list(a), list(b)]) for k, (t, a, b) in new.items()]
    seg = lambda k: [list(x) for x in base(dec[k]['verts'])]
    json.dump(dict(criterion=__doc__.split('\n\n')[-1], mode=mode, probe=PROBE, step=STEP, walls=len(walls),
                   fences=fences,
                   removed=[dict(key=k.hex(), flags=dec[k]['flags'], owners=sorted(own[k]), through2d=old[k]['through'],
                                 seg=old[k]['seg']) for k in removed],
                   added=[dict(key=k.hex(), flags=dec[k]['flags'], owners=sorted(own[k]), seg=seg(k)) for k in added]),
              open(OUT_Z, 'w'), indent=0)
    from PIL import Image, ImageDraw
    x0, y0, x1, y1 = -700, -2000, 2400, 800
    im = Image.new('RGB', (x1 - x0, y1 - y0), (255, 255, 255))
    dr = ImageDraw.Draw(im)
    P = lambda p: (p[0] - x0, y1 - p[1])
    for k in walls:
        a, b = base(dec[k]['verts'])
        dr.line([P(a), P(b)], fill=(170, 170, 170), width=1)
    for ks, col in ((kept, (220, 0, 0)), (removed, (0, 80, 255)), (added, (0, 170, 0))):
        for k in ks:
            a, b = base(dec[k]['verts'])
            dr.line([P(a), P(b)], fill=col, width=3)
    im.save(PNG_Z)
    print('wrote', OUT_Z, PNG_Z)


def sweep():
    own, dec = load()
    g = ExeGround(own, dec)
    old = {bytes.fromhex(f['key']) for f in json.load(open(OUT))['fences']}
    for mode in ('levels', 'top'):
        for probe in (0.05, 0.25, 0.5, 1.0, 2.0, 4.0):
            s = set(z_set(own, dec, g, probe, mode))
            print('%-6s probe %-4s fences %4d (of 2D-1.0 set %4d, new %d)' % (mode, probe, len(s), len(s & old), len(s - old)))


if __name__ == '__main__':
    if '--z-sweep' in sys.argv:
        sweep()
    elif '--z' in sys.argv or '--z=top' in sys.argv:
        main_z('top' if '--z=top' in sys.argv else 'levels')
    else:
        main()
