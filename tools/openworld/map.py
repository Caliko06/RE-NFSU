#!/usr/bin/env python3
"""map.py: top-down map of Olympic City (region L1RA) with the 16 street routes and their wall cells.

Reads (read-only): game/Tracks/TRACKB<id>.lzc for ids 1001-1008 (circuits) and 1102-1109 (sprints), and the base
world stream game/Tracks/STREAML1RA.BUN (section AABBs as background). Parsers are imported from ref/tools/ug1-tracks
(lib, streams). Layouts read here (inferred 2026-10-27, validated per track in the census "checks" block):
  route header 0x34148 (40 B): u32 flags (0x100 = closed), u16 N, u16 N, u32 0, f32 total length @+12
  route nodes  0x34149: records of 20 B, x f32 @+0, y f32 @+4, f32 cumulative distance @+16
               circuits: N+1 records, the last one closes the loop (distance 0); sprints: N records
  wall cells   0x34131: optional 0x11 pad, then rows of 16 B: x f32, y f32 (cell corner, 32 units, grid offset 16),
               u32 offset into wsrc, u32 count. Row 0 is the sentinel (999999, 999999).
  markers      0x34146: 0x11 pad, then records of 48 B; streams.start_pose() gives the start position.

Writes: build/openworld/map.png, census/openworld.json. Run: python3 tools/openworld/map.py
"""
import json, math, os, struct, sys
from collections import defaultdict

REPO = os.path.abspath(os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', '..'))
os.environ.setdefault('NFSU1_MAIN', REPO)  # lib.py reads game/ from here; the repo holds game/
sys.path.insert(0, os.path.join(REPO, 'ref', 'tools', 'ug1-tracks'))
import lib, streams  # noqa: E402
from lib import load, find, trackb_path, PC  # noqa: E402
from PIL import Image, ImageDraw, ImageFont  # noqa: E402

CIRCUITS = list(range(1001, 1009))
SPRINTS = list(range(1102, 1110))
TRACKS = CIRCUITS + SPRINTS
BBOX = (-607, -1931, 2338, 706)  # brief: where the bulk of the city lies (p2..p98 of section AABBs)
CELL = 32
GRID_OFF = 16
PNG = os.path.join(REPO, 'build', 'openworld', 'map.png')
CENSUS = os.path.join(REPO, 'census', 'openworld.json')
BASE_STREAM = os.path.join(PC, 'Tracks', 'STREAML1RA.BUN')

PALETTE = [(230, 25, 75), (60, 180, 75), (0, 130, 200), (245, 130, 48), (145, 30, 180), (70, 200, 200),
           (240, 50, 230), (128, 128, 0), (170, 110, 40), (0, 0, 128), (128, 0, 0), (0, 128, 128),
           (200, 150, 0), (255, 105, 180), (75, 0, 130), (105, 105, 105)]
COLOR = {tid: PALETTE[k] for k, tid in enumerate(TRACKS)}


def read_route(d):
    (hb, hs), = find(d, 0x34148)
    flags, n1, n2, _, total = struct.unpack_from('<IHHIf', d, hb)
    (rb, rs), = find(d, 0x34149)
    assert rs % 20 == 0, 'rnode size %d not multiple of 20' % rs
    n = rs // 20
    pts = [struct.unpack_from('<2f', d, rb + 20 * k) for k in range(n)]
    dist = [struct.unpack_from('<f', d, rb + 20 * k + 16)[0] for k in range(n)]
    closed = bool(flags & 0x100)
    assert n1 == n2
    if closed:
        assert n == n1 + 1 and dist[-1] == 0.0, 'closed route: expected N+1 records, last distance 0'
    else:
        assert n == n1, 'sprint: expected N records'
    return dict(closed=closed, n_nodes=n1, n_records=n, total=total, pts=pts, dist=dist)


def read_walls(d):
    (wb, ws), = find(d, 0x34131)
    q = wb
    while d[q] == 0x11:
        q += 1
    assert (wb + ws - q) % 16 == 0, 'wcell table not a multiple of 16 B after pad'
    rows = [struct.unpack_from('<2f2I', d, o) for o in range(q, wb + ws, 16)]
    sentinel_ok = rows[0][0] == 999999.0 and rows[0][1] == 999999.0
    cells, zero = [], 0
    for x, y, off, cnt in rows[1:]:
        if cnt == 0:
            zero += 1
            continue
        assert float(x).is_integer() and float(y).is_integer(), 'non-integer cell corner'
        cells.append((int(x), int(y)))
    assert len(set(cells)) == len(cells), 'duplicate cells in one track'
    return dict(cells=cells, pad=q - wb, rows=len(rows) - 1, zero_count=zero, sentinel_ok=sentinel_ok)


def in_bbox(x, y):
    return BBOX[0] <= x <= BBOX[2] and BBOX[1] <= y <= BBOX[3]


def polyline_length(pts):
    return sum(math.dist(pts[k], pts[k + 1]) for k in range(len(pts) - 1))


def load_track(tid):
    d = load(trackb_path(PC, tid))
    r = read_route(d)
    w = read_walls(d)
    start = streams.start_pose(tid)
    return dict(route=r, walls=w, start=(start[0], start[1]) if start else None)


def build_census(data, sections):
    tracks_out, cell_sets = {}, {}
    for tid in TRACKS:
        t = data[tid]; r = t['route']; w = t['walls']
        xs = [p[0] for p in r['pts']]; ys = [p[1] for p in r['pts']]
        cell_sets[tid] = set(w['cells'])
        tracks_out[str(tid)] = dict(
            kind='circuit' if tid in CIRCUITS else 'sprint',
            closed=r['closed'],
            n_nodes=r['n_nodes'],
            n_records=r['n_records'],
            route_length_header=round(r['total'], 1),
            route_length_polyline=round(polyline_length(r['pts']), 1),
            route_bbox=[round(min(xs), 1), round(min(ys), 1), round(max(xs), 1), round(max(ys), 1)],
            start=[round(t['start'][0], 1), round(t['start'][1], 1)] if t['start'] else None,
            n_wall_cells=len(w['cells']),
            wall_cells=sorted([list(c) for c in w['cells']]),
            checks=dict(sentinel_ok=w['sentinel_ok'], wall_pad_bytes=w['pad'], wall_rows=w['rows'],
                        wall_rows_zero_count=w['zero_count'],
                        route_points_outside_bbox=sum(1 for x, y in r['pts'] if not in_bbox(x, y)),
                        cells_outside_bbox=sum(1 for x, y in w['cells'] if not in_bbox(x, y))))
    union = set().union(*cell_sets.values())
    count = defaultdict(int)
    for c in union:
        n = sum(1 for tid in TRACKS if c in cell_sets[tid])
        count[c] = n
    shared = [c for c in union if count[c] >= 2]
    pairs = []
    for i, a in enumerate(TRACKS):
        for b in TRACKS[i + 1:]:
            k = len(cell_sets[a] & cell_sets[b])
            if k:
                pairs.append([a, b, k])
    pairs.sort(key=lambda p: -p[2])
    glob = dict(
        cell_size=CELL, grid_offset_mod32=GRID_OFF,
        wall_cells_union=len(union),
        wall_cells_sum_per_track=sum(len(s) for s in cell_sets.values()),
        cells_shared_by_2plus_tracks=len(shared),
        cells_shared_by_3plus_tracks=sum(1 for c in shared if count[c] >= 3),
        max_tracks_on_one_cell=max(count.values()) if count else 0,
        pairs_sharing_cells=len(pairs),
        pairs=pairs,
        tracks_sharing_no_cells=[t for t in TRACKS if not any(p[0] == t or p[1] == t for p in pairs)],
        base_sections=len(sections),
        base_section_aabb_xy_range=[min(bb[0] for _, bb, _ in sections if bb), min(bb[1] for _, bb, _ in sections if bb),
                                    max(bb[3] for _, bb, _ in sections if bb), max(bb[4] for _, bb, _ in sections if bb)],
    )
    return dict(
        source=dict(tracks='game/Tracks/TRACKB<id>.lzc', base_stream='game/Tracks/STREAML1RA.BUN',
                    layouts='see tools/openworld/map.py docstring (inferred 2026-10-27, validated here)',
                    brief_bbox=list(BBOX)),
        tracks=tracks_out, **{'global': glob}), cell_sets


def draw_map(data, sections):
    allx, ally = [], []
    for tid in TRACKS:
        t = data[tid]
        allx += [p[0] for p in t['route']['pts']]
        ally += [p[1] for p in t['route']['pts']]
        for x, y in t['walls']['cells']:
            allx += [x, x + CELL]; ally += [y, y + CELL]
    m = 40
    x0, x1 = min(allx) - m, max(allx) + m
    y0, y1 = min(ally) - m, max(ally) + m
    W = 2000
    s = (W) / (x1 - x0)
    H = int(round((y1 - y0) * s))
    assert H <= 2000, 'map too tall: %d' % H

    def px(x): return (x - x0) * s
    def py(y): return (y1 - y) * s  # north (y up) at the top

    img = Image.new('RGBA', (W, H), (255, 255, 255, 255))
    d = ImageDraw.Draw(img)
    for _, bb, _ in sections:
        if not bb:
            continue
        if bb[3] < x0 or bb[0] > x1 or bb[4] < y0 or bb[1] > y1:
            continue
        d.rectangle([px(bb[0]), py(bb[4]), px(bb[3]), py(bb[1])], fill=(236, 236, 236, 255), outline=(204, 204, 204, 255))
    for tid in TRACKS:
        col = COLOR[tid]
        ov = Image.new('RGBA', (W, H), (0, 0, 0, 0))
        od = ImageDraw.Draw(ov)
        for x, y in data[tid]['walls']['cells']:
            od.rectangle([px(x), py(y + CELL), px(x + CELL) - 1, py(y) - 1], fill=col + (70,))
        img.alpha_composite(ov)
    d = ImageDraw.Draw(img)
    try:
        font = ImageFont.load_default(size=16)
    except TypeError:
        font = ImageFont.load_default()
    for tid in TRACKS:
        col = COLOR[tid]
        pts = [(px(x), py(y)) for x, y in data[tid]['route']['pts']]
        d.line(pts, fill=col + (255,), width=4 if tid in CIRCUITS else 3, joint='curve')
        st = data[tid]['start']
        if st:
            sx, sy = px(st[0]), py(st[1])
            d.ellipse([sx - 4, sy - 4, sx + 4, sy + 4], fill=(255, 255, 255, 255), outline=col + (255,), width=2)
        lx, ly = pts[0]
        d.text((lx + 6, ly - 8), str(tid), fill=col + (255,), font=font, stroke_width=3, stroke_fill=(255, 255, 255, 255))
    d.text((12, 10), 'L1RA Olympic City: 16 routes (circuits 1001-1008, sprints 1102-1109), wall cells tinted per track',
           fill=(0, 0, 0, 255), font=font, stroke_width=3, stroke_fill=(255, 255, 255, 255))
    os.makedirs(os.path.dirname(PNG), exist_ok=True)
    img.convert('RGB').save(PNG, optimize=True)
    return W, H


def main():
    sections = streams.sections(load(BASE_STREAM))
    data = {tid: load_track(tid) for tid in TRACKS}
    census, _ = build_census(data, sections)
    W, H = draw_map(data, sections)
    os.makedirs(os.path.dirname(CENSUS), exist_ok=True)
    with open(CENSUS, 'w') as f:
        json.dump(census, f, indent=1)
    g = census['global']
    print('PNG %s %dx%d' % (PNG, W, H))
    print('CENSUS %s' % CENSUS)
    print('%-5s %-7s %5s %5s %9s %9s %6s %s' % ('id', 'kind', 'nodes', 'recs', 'len_hdr', 'len_poly', 'cells', 'bbox'))
    for tid in TRACKS:
        t = census['tracks'][str(tid)]
        print('%-5d %-7s %5d %5d %9.1f %9.1f %6d %s' % (tid, t['kind'], t['n_nodes'], t['n_records'], t['route_length_header'],
              t['route_length_polyline'], t['n_wall_cells'], t['route_bbox']))
    print('global: sections=%d cells_union=%d cells_sum=%d shared_2plus=%d shared_3plus=%d pairs=%d' % (
        g['base_sections'], g['wall_cells_union'], g['wall_cells_sum_per_track'], g['cells_shared_by_2plus_tracks'],
        g['cells_shared_by_3plus_tracks'], g['pairs_sharing_cells']))
    print('pairs (a,b,shared cells): %s' % ' '.join('%d-%d:%d' % tuple(p) for p in g['pairs']))
    print('tracks with no shared cells: %s' % g['tracks_sharing_no_cells'])


if __name__ == '__main__':
    main()
