#!/usr/bin/env python3
"""zones.py: TRACKB zone rows (chunk 0x3414a, inside container 0x80034147) of the L1RA street tracks, and where the
RESET / RESET_TO_POINT zones sit against the streets of the other tracks (what the open world joins).

Layout of a zone row, 0xb4 B (docs/openworld/re_stream.md, 0x4436d0 search, 0x427ed0 / 0x430e00 consumers):
  +0 u32 type (name table 0x700964)   +4 f32 x, +8 f32 y (RESET_TO_POINT teleport target)
  +0xc, +0x10 f32 direction x, y (WRONG_WAY: the "wrong" heading source; RESET_TO_POINT: heading after the teleport)
  +0x14 f32 height limit: 0 = none, else the zone acts only while car z (car+0x68) < this   (0x427ed0, 0x52b3b0)
  +0x18 s8 selector (-1 any, else must equal the driver's track direction [0x78a2fc]; 0x4436d0)
  +0x1a u16 runtime "already fired" flag (SHORTCUT 0x43fb87; cleared for all zones at 0x41f913)
  +0x1c..+0x24 3 f32 (not read by the zone consumers; look like route distances, UNREAD)
  +0x28..+0x34 bbox xmin ymin xmax ymax   +0x38 u32 nverts   +0x3c nverts x (f32 x, f32 y)
  +0x7c s16 boundary id (type 10) / tunnel id (type 5)   +0x80 13 x s32 track ids (0 ends, empty = every track)

usage: zones.py [--detail]   (census per type, RESET-vs-other-tracks overlap, coverage; --detail lists every zone)"""
import collections, os, struct, sys
HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import polys  # noqa: E402  (sets up the ug1-tracks lib path)
from polys import load, find, trackb_path, PC, TRACKS  # noqa: E402

NAMES = ['NO_WRONG_WAY', 'WRONG_WAY', 'RESET', 'RESET_TO_POINT', 'TRAFFIC_DENSITY', 'TUNNEL', 'DRIFT_GATE',
         'DRIFT_HOT_SPOT', 'TUTORIAL', 'SHORTCUT', 'STREAMER_PREDICTION']
RESETS = (2, 3)


def zones(tid):
    d = load(trackb_path(PC, tid))
    out = []
    for b, s in find(d, 0x3414a):
        for o in range(b, b + s - 0xb3, 0xb4):
            ty, x, y, dx, dy, hl = struct.unpack_from('<I5f', d, o)
            nv = struct.unpack_from('<I', d, o + 0x38)[0]
            out.append(dict(
                type=ty, name=NAMES[ty] if ty < 11 else str(ty), x=x, y=y, dir=(dx, dy), zlim=hl,
                sel=struct.unpack_from('<b', d, o + 0x18)[0], bbox=struct.unpack_from('<4f', d, o + 0x28),
                poly=[struct.unpack_from('<2f', d, o + 0x3c + 8 * i) for i in range(min(nv, 8))],
                bid=struct.unpack_from('<h', d, o + 0x7c)[0],
                tracks=[t for t in struct.unpack_from('<13i', d, o + 0x80) if t]))
    return out


def applies(z, tid):
    return not z['tracks'] or tid in z['tracks']


def inside(poly, x, y):  # even-odd, like the exe's point-in-polygon 0x5679b0
    c = False
    for i in range(len(poly)):
        (x1, y1), (x2, y2) = poly[i], poly[i - 1]
        if (y1 > y) != (y2 > y) and x < (x2 - x1) * (y - y1) / (y2 - y1) + x1:
            c = not c
    return c


def ground():
    """key -> (cx, cy, cz, set(track ids)) of every ground polygon (flags & 0x0a == 0, as the ground query 0x440a40)."""
    g = {}
    for t in TRACKS:
        for r in polys.rows(t):
            p = polys.decode(r)
            if p['flags'] & 0x0a:
                continue
            v = p['verts']
            k = polys.key(r)
            if k not in g:
                g[k] = [sum(a[0] for a in v) / len(v), sum(a[1] for a in v) / len(v), sum(a[2] for a in v) / len(v), set()]
            g[k][3].add(t)
    return list(g.values())


def census():
    rows = {}
    for t in TRACKS:
        c = collections.Counter()
        for z in zones(t):
            c[(z['name'], 'all' if not z['tracks'] else 'me' if t in z['tracks'] else 'other')] += 1
        rows[t] = c
    return rows


def overlap(g):
    """per track: RESET / RESET_TO_POINT zones that apply to it, split by what ground their polygon covers."""
    res = {}
    for t in TRACKS:
        zs = [z for z in zones(t) if z['type'] in RESETS and applies(z, t)]
        cnt = collections.Counter()
        det = []
        for z in zs:
            x0, y0, x1, y1 = z['bbox']
            own = oth = 0
            for cx, cy, cz, ts in g:
                if x0 <= cx <= x1 and y0 <= cy <= y1 and inside(z['poly'], cx, cy):
                    if (z['zlim'] == 0 or cz < z['zlim']):
                        if t in ts:
                            own += 1
                        else:
                            oth += 1
            kind = 'own+other' if own and oth else 'other only' if oth else 'own only' if own else 'no ground'
            cnt[(z['name'], kind)] += 1
            det.append((z, own, oth, kind))
        res[t] = (cnt, det)
    return res


def cover(g):
    """per base track: how much of the whole city's ground (union of the 16 tracks) lies inside the track's own RESET zones
    (the zones a merged TRACKB of that base keeps): polygons, and the share that is not ground of the base track."""
    out = {}
    for t in TRACKS:
        zs = [z for z in zones(t) if z['type'] in RESETS and applies(z, t)]
        n = new = 0
        for cx, cy, cz, ts in g:
            if any(z['bbox'][0] <= cx <= z['bbox'][2] and z['bbox'][1] <= cy <= z['bbox'][3] and inside(z['poly'], cx, cy)
                   and (z['zlim'] == 0 or cz < z['zlim']) for z in zs):
                n += 1
                new += t not in ts
        out[t] = (n, new, len(g))
    return out


def main():
    print('## Census by track (rows of chunk 0x3414a; me/other = the track list holds / lacks this track, all = empty list)')
    cen = census()
    names = sorted({k[0] for c in cen.values() for k in c}, key=NAMES.index)
    print('| track | ' + ' | '.join(names) + ' |')
    print('|---|' + '---|' * len(names))
    for t in TRACKS:
        cells = []
        for n in names:
            parts = ['%d%s' % (cen[t][(n, s)], s[0]) for s in ('all', 'me', 'other') if cen[t][(n, s)]]
            cells.append(' '.join(parts) or '.')
        print('| %d | %s |' % (t, ' | '.join(cells)))
    zl = collections.Counter()
    sel = collections.Counter()
    for t in TRACKS:
        for z in zones(t):
            if z['type'] in RESETS:
                zl[(z['name'], 'zlim=0' if z['zlim'] == 0 else 'zlim>0')] += 1
                sel[(z['name'], z['sel'])] += 1
    print('\nheight limit (+0x14):', dict(sorted(zl.items())))
    print('selector (+0x18):', dict(sorted(sel.items())))
    print('\n## RESET / RESET_TO_POINT vs ground of other tracks (zones that apply to the track; centroids of ground polygons in the zone polygon)')
    ov = overlap(ground())
    kinds = ['own only', 'own+other', 'other only', 'no ground']
    print('| track | zones | ' + ' | '.join(kinds) + ' | ground polys of other tracks inside |')
    print('|---|---|' + '---|' * (len(kinds) + 1))
    tot = collections.Counter()
    for t in TRACKS:
        cnt, det = ov[t]
        k = collections.Counter()
        for (n, kind), v in cnt.items():
            k[kind] += v
        tot.update(k)
        print('| %d | %d | %s | %d |' % (t, sum(k.values()), ' | '.join(str(k[x]) for x in kinds), sum(d[2] for d in det)))
    print('| all | %d | %s | |' % (sum(tot.values()), ' | '.join(str(tot[x]) for x in kinds)))
    cv = cover(ground())
    print('\n## City ground (union of the 16 tracks) inside the RESET zones a base track keeps')
    print('| base track | ground polys inside | of them not ground of the base track | share of the city |')
    print('|---|---|---|---|')
    for t in TRACKS:
        n, new, tot_ = cv[t]
        print('| %d | %d | %d | %.1f %% |' % (t, n, new, 100.0 * n / tot_))
    if '--detail' in sys.argv:
        for t in TRACKS:
            for z, own, oth, kind in ov[t][1]:
                print(t, z['name'], '(%.0f,%.0f)' % (z['x'], z['y']), 'zlim', z['zlim'], 'own', own, 'other', oth, kind)


if __name__ == '__main__':
    main()
