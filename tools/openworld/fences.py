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
"""
import collections, json, math, os, sys
HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import polys  # noqa: E402

REPO = os.path.abspath(os.path.join(HERE, '..', '..'))
OUT = os.path.join(REPO, 'census', 'openworld_fences.json')
PNG = os.path.join(REPO, 'build', 'openworld', 'fences.png')
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


if __name__ == '__main__':
    main()
