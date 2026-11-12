#!/usr/bin/env python3
"""ug2_race.py: the WORLD race files (row 11): TRACKB1010_park.lzc = the live TRACKB1010 with its progress route, markers and road net swapped for UG2 race 4024 "Park Loop".

Why a file and not a patch: the exe has ONE route and one marker set per track file (TrackPath 0x4434d0 / TrackPositionMarker_Load 0x441ed0 read TRACKB<id>.LZC at
race load, 0x449760; census/names_racesetup.tsv). host/openworld.c rn_world_open serves this variant instead of TRACKB1010.lzc when the quick-race mode is Circuit.
Geometry first, ids never: the race is defined by UG2 data in the WORLD frame (UG2 race 4024 waypoints, Routes4024F.bin road graph, TrackPosMarkersAll.bin start grid; frame
tools/ug2_roads.py:18-24). The generator writes its own closed road section (sid 0, nodes along the route, ONE type 2 link last -> first: the racer rule 0x462840 takes
type 2 always, docs/openworld_e_re.md B1) and a new 0x34148/49 closed route, so it does not depend on the section ids of build/openworld/TRACKB1010.lzc
(NFSU1 net + UG2 net, whichever ug2_traffic.py wrote); it reads that file only for the collision ground (z), the template node and every other chunk.
usage: .venv/bin/python -I tools/ug2_race.py [park|bridge] [--png dir]      writes build/openworld/TRACKB1010_park.lzc and TRACKB1010_bridge.lzc"""
import collections, math, os, struct, sys
HERE = os.path.dirname(os.path.abspath(__file__))
REPO = os.path.abspath(os.path.join(HERE, '..'))
os.environ.setdefault('NFSU1_MAIN', REPO)
for p in (HERE, os.path.join(HERE, 'hopper'), os.path.join(HERE, 'openworld'), os.path.join(HERE, 'probe')):
    sys.path.insert(0, p)
import ug2_roads as R  # noqa: E402
import ug2_traffic as U  # noqa: E402
import ug2_collfile as CF  # noqa: E402
import q_owcoll2_lzc as lzc  # noqa: E402
import q_owcoll2_write as w  # noqa: E402
import race_proposals as RP  # noqa: E402

SRC = os.path.join(REPO, 'build', 'openworld', 'TRACKB1010.lzc')
STEP = 6.0            # node spacing of the road section (NFSU1 sections run 8 m, U.SPACING)
LANE_MARGIN = 3.0     # m kept between a racing lane and the nearest wall (car half width 1 m + drift)
RSTEP = 20.0          # progress route node spacing (the shipped paths are 25..45 m)
HASH = {n: RP.cshash(n) for n in RP.NAMES}


def world_markers(tid):
    """UG2 TrackPosMarkersAll.bin rows of one race id in the WORLD frame: {hash name: [(ordinal, x, y, z, angle16)]}; the angle turns with the frame (R270 = -90 deg = -16384)"""
    d = open(RP.RT + 'TrackPosMarkersAll.bin', 'rb').read()
    out = collections.defaultdict(list)
    for k in range((len(d) - 16) // 48):
        r = d[16 + k * 48:16 + (k + 1) * 48]
        if struct.unpack_from('<H', r, 0x24)[0] != tid:
            continue
        h, o = struct.unpack_from('<II', r, 8)
        x, y, z = struct.unpack_from('<3f', r, 0x10)
        a, = struct.unpack_from('<H', r, 0x20)
        X, Y, Z = R.to_nfsu1(x, y, z)
        out[RP.HASH.get(h, hex(h))].append((o, X, Y, Z, (a - 16384) & 0xffff))
    return out


def resample(poly, step):
    """polyline -> points every <= step metres along it, keeping every vertex"""
    out = [poly[0]]
    for a, b in zip(poly, poly[1:]):
        L = math.dist(a, b)
        n = max(1, math.ceil(L / step))
        for k in range(1, n + 1):
            out.append((a[0] + (b[0] - a[0]) * k / n, a[1] + (b[1] - a[1]) * k / n))
    return out


def drop_spurs(p, tol=7.0):
    """cut the out-and-back excursions a shortest path through off-road waypoints leaves: at a reversal r, while p[r-k] and p[r+k] are within tol, the loop between is dead"""
    changed = True
    while changed:
        changed = False
        for r in range(2, len(p) - 2):
            v1 = (p[r][0] - p[r - 2][0], p[r][1] - p[r - 2][1]); v2 = (p[r + 2][0] - p[r][0], p[r + 2][1] - p[r][1])
            if v1[0] * v2[0] + v1[1] * v2[1] >= -0.3 * math.hypot(*v1) * math.hypot(*v2):
                continue
            k = 1
            while r - k >= 0 and r + k < len(p) and math.dist(p[r - k], p[r + k]) < tol:
                k += 1
            if k > 1:
                p = p[:r - k + 1] + p[r + k:]
                changed = True
                break
    return p


def park_loop(ground):
    """-> (points [(x, y, z)] closed loop without the repeated first point, starting at the node nearest the start line, driven in the marker heading; markers dict)"""
    tid = 4024
    wp = RP.ug2_waypoints()[tid]
    _, poly, _ = RP.ug2_route(tid, wp)
    pts = [R.to_nfsu1(x, y, 0)[:2] for x, y in poly]
    pts = [p for i, p in enumerate(pts) if i == 0 or p != pts[i - 1]]
    pts = drop_spurs(resample(pts, 2.0))
    pts = resample(pts, STEP)[:-1] if math.dist(pts[0], pts[-1]) < 1.0 else resample(pts, STEP)
    mk = world_markers(tid)
    sl = mk['ForwardStartLine'][0]
    i0 = min(range(len(pts)), key=lambda i: math.dist(pts[i], sl[1:3]))
    pts = pts[i0:] + pts[:i0]
    a = math.atan2(pts[1][1] - pts[0][1], pts[1][0] - pts[0][0])
    h = sl[4] * 2 * math.pi / 65536
    if math.cos(a - h) < 0:                    # waypoint order runs against the marker heading: drive the other way
        pts = [pts[0]] + pts[:0:-1]
        print('route reversed to match the start marker heading')
    out, z = [], sl[3]
    for x, y in pts:
        g = ground.z(x, y, z)
        z = g if g is not None else z
        out.append((x, y, z))
    return out, mk


def heading(pts, i, closed=True):
    a, b = (pts[(i - 1) % len(pts)], pts[(i + 1) % len(pts)]) if closed else (pts[max(i - 1, 0)], pts[min(i + 1, len(pts) - 1)])
    hx, hy = b[0] - a[0], b[1] - a[1]
    l = math.hypot(hx, hy)
    return hx / l, hy / l


def road_chunks(base, pts, closed=True, room=None):
    """chunks 0x34121 / 0x34122 payloads: one section sid 0 over pts (a closed race: + one type 2 entry last -> first, an open one has no entry)"""
    (b, s), secs0, ent0 = U.parse(base)
    tp = secs0[U.TEMPLATE_SEC]
    hdr_t = bytes(base[tp[1]:tp[1] + 0x27c])
    nodeb = lambda i: bytes(base[tp[1] + 0x27c + i * 0x88:tp[1] + 0x27c + (i + 1) * 0x88])
    cand = [nodeb(i) for i in range(tp[2])]
    cand = [c for c in cand if set(c[0x75:0x81]) == {6} and struct.unpack_from('<h', c, 0x3c + 2 * 11)[0] == 464]
    import statistics
    med = [statistics.median(struct.unpack_from('<f', c, o)[0] for c in cand) for o in (0x24, 0x28)]
    tmpl = min(cand, key=lambda c: sum(abs(struct.unpack_from('<f', c, o)[0] - m) for o, m in zip((0x24, 0x28), med)))
    n = len(pts)
    if room is not None:       # racing lanes 0..9 (template: 2.7..5.5 m left, 3.7..4.7 m right) pulled inside the walls; the smallest room of the 4 nodes behind and 4 ahead, as the aim reads nodes ahead
        room = [(min(room[j][0] for j in range(max(0, i - 4), min(n, i + 5))), min(room[j][1] for j in range(max(0, i - 4), min(n, i + 5)))) for i in range(n)]
    cum = [0.0]
    for i in range(1, n):
        cum.append(cum[-1] + math.dist(pts[i][:2], pts[i - 1][:2]))
    total = cum[-1] + (math.dist(pts[-1][:2], pts[0][:2]) if closed else 0.0)
    fl = sum(1 << b_ for _, b_ in U.MAP_BITS)
    nodes = []
    for i, (x, y, z) in enumerate(pts):
        nd = bytearray(tmpl)
        struct.pack_into('<3f', nd, 0, x, y, z)
        hx, hy = heading(pts, i, closed)
        struct.pack_into('<4f', nd, 0xc, hx, hy, -hx, -hy)
        nxt = math.dist(pts[i][:2], pts[(i + 1) % n][:2]) if closed or i + 1 < n else math.dist(pts[i][:2], pts[i - 1][:2])
        prv = math.dist(pts[i][:2], pts[i - 1][:2]) if closed or i else nxt
        struct.pack_into('<2f', nd, 0x1c, nxt, prv)
        struct.pack_into('<f', nd, 0x38, cum[i])
        if room is not None:
            for kk in range(10):
                o = struct.unpack_from('<h', nd, 0x3c + 2 * kk)[0]
                lim = max(0.0, (room[i][0] if o < 0 else room[i][1]) - LANE_MARGIN)
                struct.pack_into('<h', nd, 0x3c + 2 * kk, int(math.copysign(min(abs(o), lim * 256), o)))
        for kk in U.UNUSED_LANES:
            struct.pack_into('<h', nd, 0x3c + 2 * kk, -1)
            nd[0x6a + kk] = 6
        for kk in U.LANES:
            nd[0x6a + kk] = U.LANE_SPEED
        nd[0x81] = nd[0x82] = 0xff
        nd[0x83] = 0
        struct.pack_into('<I', nd, 0x84, (struct.unpack_from('<I', tmpl, 0x84)[0] & ~U.MASK) | fl | (0x1f << 20))
        nodes.append(nd)
    if closed:
        nodes[-1][0x81] = 0                   # slot 0 of the last node = entry 0
    e = bytearray(32)
    struct.pack_into('<fHH', e, 0, 0.0, 0, n - 1)           # dst node 0, src node n - 1
    e[8], e[9], e[0xa], e[0xb], e[0xc], e[0xd] = 0, 0, 0, 2, 2, 0   # dst sec 0, src sec 0, type 2, lane 2, forward
    struct.pack_into('<IiII', e, 0x10, 0, -1, 0, 0)
    hdr = bytearray(hdr_t)
    struct.pack_into('<h', hdr, 0xa, 0)
    struct.pack_into('<i', hdr, 0xc, 0)
    struct.pack_into('<hh', hdr, 0x10, n, n)
    struct.pack_into('<4f', hdr, 0x20, min(p[0] for p in pts), min(p[1] for p in pts), max(p[0] for p in pts), max(p[1] for p in pts))
    for kk in range(23):
        hdr[0x265 + kk] = int(kk in U.LANES)
    return bytes(hdr) + b''.join(bytes(x) for x in nodes), bytes(e) if closed else b'', total


def route_chunks(old_container, pts, closed):
    """container 0x80034147 payload: route 0x34148 (40 B: flags 0x100 = closed, N, N, 0, length, 1.0, start xy, end xy, 0) + 0x34149 nodes of 20 B (x, y, u16 0, 3 x s16 -1, cumulative m;
    a closed route has N + 1 records, the closing one with distance 0; docs/openworld_e_re.md B1, tools/openworld/map.py read_route) + the old zone rows 0x3414a unchanged (docs/re/track.md)"""
    sel, acc = [pts[0]], 0.0
    for a, b in zip(pts, pts[1:] + ([pts[0]] if closed else [])):
        acc += math.dist(a[:2], b[:2])
        if acc >= RSTEP and b is not pts[0]:
            acc = 0.0
            sel.append(b)
    if not closed and sel[-1] is not pts[-1]:
        sel.append(pts[-1])
    if closed and len(sel) > 3 and math.dist(sel[-1][:2], pts[0][:2]) < RSTEP / 2:
        sel.pop()
    cum = [0.0]
    for a, b in zip(sel, sel[1:]):
        cum.append(cum[-1] + math.dist(a[:2], b[:2]))
    length = cum[-1] + (math.dist(sel[-1][:2], sel[0][:2]) if closed else 0.0)
    n = len(sel)
    recs = b''.join(struct.pack('<2fH3hf', q[0], q[1], 0, -1, -1, -1, c) for q, c in zip(sel, cum))
    if closed:
        recs += struct.pack('<2fH3hf', sel[0][0], sel[0][1], 0, -1, -1, -1, 0.0)
    hdr = struct.pack('<IHHIffffffI', 0x100 if closed else 0, n, n, 0, length, 1.0, sel[0][0], sel[0][1], sel[-1][0], sel[-1][1], 0)
    out = struct.pack('<II', 0x34148, len(hdr)) + hdr + struct.pack('<II', 0x34149, len(recs)) + recs
    p = 0
    while p < len(old_container):
        cid, sz = struct.unpack_from('<II', old_container, p)
        if cid == 0x3414a:
            out += old_container[p:p + 8 + sz]
        p += 8 + sz
    return out, length, n


def marker_chunk(rows_in):
    """chunk 0x34146 payload from [(hash name, ordinal, x, y, z, angle16)]: rows 0x30 B, +0/+4 0x0b (the file's own list link words), +8 hash, +0xc ordinal, +0x10 xyz, +0x20 u16 angle;
    8 B of 0x11 first (the payload rows start 16-aligned)"""
    rows = []
    for name, o, x, y, z, a in rows_in:
        r = bytearray(48)
        struct.pack_into('<II', r, 0, 0x0b, 0x0b)
        struct.pack_into('<II', r, 8, HASH[name], o)
        struct.pack_into('<3f', r, 0x10, x, y, z)
        struct.pack_into('<H', r, 0x20, a)
        rows.append(bytes(r))
    return b'\x11' * 8 + b''.join(rows), len(rows)


def swap(base, pts, closed, markers, room=None):
    ch = w.top_chunks(base)
    ids = [c[0] for c in ch]
    i46, i47 = ids.index(0x34146), ids.index(0x80034147)
    i21 = ids.index(0x34121)
    assert ids[i21:i21 + 3] == [0x34121, 0x34122, 0] and i46 < i47 < i21
    p21, p22, total = road_chunks(base, pts, closed, room)
    cont, length, nroute = route_chunks(bytes(base[ch[i47][1] + 8:ch[i47][1] + 8 + ch[i47][2]]), pts, closed)
    p46, nmk = marker_chunk(markers)

    def pad_to(buf, phase):
        need = (phase - len(buf)) % 128
        if need < 8:
            need += 128
        return struct.pack('<II', 0, need - 8) + b'\0' * (need - 8)
    out = bytearray(base[:ch[i46][1]])
    for cid, off in ((0x34146, i46), (0x80034147, i47), (0x34121, i21)):
        # keep each header's phase mod 128 (and so mod 16) as in the old file
        if cid != 0x34146:
            out += pad_to(out, ch[off][1])
        assert len(out) % 128 == ch[off][1] % 128, (hex(cid), len(out) % 128, ch[off][1] % 128)
        payload = {0x34146: p46, 0x80034147: cont, 0x34121: p21}[cid]
        out += struct.pack('<II', cid, len(payload)) + payload
        if cid == 0x34121:
            out += struct.pack('<II', 0x34122, len(p22)) + p22
    old_pad_end = ch[i21 + 2][1] + 8 + ch[i21 + 2][2]
    need = (old_pad_end - len(out)) % 128
    if need < 8:
        need += 128
    out += struct.pack('<II', 0, need - 8) + b'\0' * (need - 8)
    out += base[old_pad_end:]
    assert not w.check_alignment(base, bytes(out)), 'misaligned'
    print('%s: %d road nodes (%.0f m), route %d nodes (%.0f m), %d markers' % ('closed' if closed else 'open', len(pts), total, nroute, length, nmk))
    return bytes(out)


def side_room(rows, pts, reach=20.0):
    """metres from each node to the nearest wall edge (collision rows with flag 0x02 / 0x08, z overlapping the node) along the node's left and right normals -> [(left, right)], capped at reach.
    The racers' lanes sit at node +0x3c + 2 * lane (s16 / 256 m; AIActionGetUnstuck::GetGoalPoint 0x451cb0, census/names_rivals.tsv), copied from a 23 m wide NFSU1 node, so on a narrow
    UG2 road the outer lanes land on the wall"""
    cell = collections.defaultdict(list)
    for r in rows:
        d = U.ub.unpack(r)
        if not d['fl'] & 0x0a:
            continue
        n = 4 if d['fl'] & 0x10 else 3
        k4 = 4 if d['fl'] & 4 else 1
        v = [(d['xs'][k] / 8, d['ys'][k] / 8, U.ub.zof(d, k) * k4) for k in range(n)]
        for a, b in zip(v, v[1:] + v[:1]):
            if math.dist(a[:2], b[:2]) < 0.05:
                continue
            e = (a[0], a[1], b[0], b[1], min(p[2] for p in v), max(p[2] for p in v))
            for cx in range(int(min(a[0], b[0]) // 16), int(max(a[0], b[0]) // 16) + 1):
                for cy in range(int(min(a[1], b[1]) // 16), int(max(a[1], b[1]) // 16) + 1):
                    cell[(cx, cy)].append(e)
    out = []
    for i, (x, y, z) in enumerate(pts):
        hx, hy = heading(pts, i, False)
        res = []
        for nx, ny in ((-hy, hx), (hy, -hx)):
            best, seen = reach, set()
            for t in range(0, int(reach) + 1, 8):
                for e in cell.get((int((x + nx * t) // 16), int((y + ny * t) // 16)), ()):
                    if id(e) in seen or e[5] < z or e[4] > z + 2.0:
                        continue
                    seen.add(id(e))
                    ex, ey = e[2] - e[0], e[3] - e[1]
                    den = nx * ey - ny * ex
                    if abs(den) < 1e-9:
                        continue
                    t1 = ((e[0] - x) * ey - (e[1] - y) * ex) / den
                    u1 = ((e[0] - x) * ny - (e[1] - y) * nx) / den
                    if 0.05 < t1 < best and -1e-6 <= u1 <= 1 + 1e-6:
                        best = t1
            res.append(best)
        out.append(tuple(res))
    return out


def park_markers(mk, ground):
    rows = []
    for name in ('ForwardStartingPosition', 'ForwardStartLine'):
        for o, x, y, z, a in sorted(mk[name]):
            g = ground.z(x, y, z)
            rows.append((name, o, x, y, g if g is not None else z, a))
    return rows


def along(pts, d, back):
    """point and unit heading at arc length d from pts[0] along the polyline (d < 0: before the start, along the first segment's line)"""
    cum = [0.0]
    for a, b in zip(pts, pts[1:]):
        cum.append(cum[-1] + math.dist(a[:2], b[:2]))
    d = max(0.0, min(cum[-1], d))
    j = max(k for k in range(len(cum) - 1) if cum[k] <= d)
    f = (d - cum[j]) / ((cum[j + 1] - cum[j]) or 1.0)
    a, b = pts[j], pts[j + 1]
    hx, hy = b[0] - a[0], b[1] - a[1]
    l = math.hypot(hx, hy)
    return (a[0] + f * hx, a[1] + f * hy, a[2] + f * (b[2] - a[2])), (hx / l, hy / l)


def bridge_race(ground):
    """Rival challenge over the bridge (row 11 #11): from the NFSU1 junction (222, 402) over the connector to the finish of UG2 4121 (WORLD frame). Resolved on whatever net
    TRACKB1010.lzc holds: nearest net node to the anchor, a start ~100 m before it on the road that arrives from the north, the shortest net path to the node nearest the 4121
    ForwardFinishLine, then 80 m on along the same section for the run-out. -> (points, markers)"""
    W = RP.World()
    anchor = W.snap((222.0, 402.0))
    ax, ay = W.P[anchor]
    # start: the node about 100 m (road distance) from the anchor lying north of it (the road arrives from section 12 in today's net)
    dist, prev, pq = {anchor: 0.0}, {}, [(0.0, anchor)]
    while pq:
        d, u = RP.heapq.heappop(pq)
        if d > dist[u]:
            continue
        for v, wgt in W.adj[u]:
            if d + wgt < dist.get(v, 1e18) and d + wgt <= 140:
                dist[v] = d + wgt; prev[v] = u; RP.heapq.heappush(pq, (d + wgt, v))
    cands = [k for k, d in dist.items() if 95 <= d <= 110 and W.P[k][1] > ay + 60 and abs(W.P[k][0] - ax) < 30]
    assert cands, 'no node north of the junction'
    back = min(cands, key=lambda k: abs(dist[k] - 100))
    fin = world_markers(4121)['ForwardFinishLine'][0]
    # NFSU1 part on the live net: start -> anchor -> the connector's far end (the bridge landing, WORLD 82.4, 600.6: the connector is section 78 whatever the UG2 net is)
    land = W.snap((82.4, 600.6))
    assert math.dist(W.P[land], (82.4, 600.6)) < 1.0, 'connector end not found'
    _, p1 = RP.dijkstra(W.adj, back, anchor)
    _, p2 = RP.dijkstra(W.adj, anchor, land)
    head = [W.P[k] for k in p1 + p2[1:]]
    # UG2 part on UG2's own free-roam graph (ids of the WORLD net never enter): landing -> finish, then 80 m on along the same section for the run-out
    inv = lambda p: (812.25 - p[1], p[0] + 1287.375)
    P, adj = RP.graph(R.load('A'))
    snap = lambda p: min(P, key=lambda k: (P[k][0] - p[0]) ** 2 + (P[k][1] - p[1]) ** 2)
    _, pk = RP.dijkstra(adj, snap(inv(W.P[land])), snap(inv(fin[1:3])))
    (s1, i1), (s2, i2) = pk[-2], pk[-1]
    step = 1 if s1 != s2 or i2 > i1 else -1
    sec = {sc['id']: sc for sc in R.load('A')['sections']}[s2]['nodes']
    acc, j = 0.0, i2
    while acc < 80 and 0 <= j + step < len(sec):
        acc += math.dist((sec[j]['x'], sec[j]['y']), (sec[j + step]['x'], sec[j + step]['y'])); j += step; pk.append((s2, j))
    pts = head + [R.to_nfsu1(P[k][0], P[k][1], 0)[:2] for k in pk]
    pts = [q for i, q in enumerate(pts) if i == 0 or q != pts[i - 1]]
    pts = resample(drop_spurs(resample(pts, 2.0)), STEP)
    out, z = [], 43.0
    for x, y in pts:
        g = ground.z(x, y, z)
        z = g if g is not None else z
        out.append((x, y, z))
    # markers: start line at the anchor, 8 grid slots in 4 rows of 2 behind it (8 m apart, 2.4 m either side), finish at the 4121 marker
    cum = [0.0]
    for a, b in zip(out, out[1:]):
        cum.append(cum[-1] + math.dist(a[:2], b[:2]))
    ia = min(range(len(out)), key=lambda i: math.dist(out[i][:2], (ax, ay)))
    s0 = cum[ia]
    ang = lambda h: int(round(math.atan2(h[1], h[0]) * 65536 / (2 * math.pi))) & 0xffff
    rows = []
    for k in range(8):
        (x, y, z), h = along(out, s0 - 8 - 8 * (k // 2), True)
        lat = 2.4 * (1 if k % 2 else -1)
        rows.append(('ForwardStartingPosition', k, x - h[1] * lat, y + h[0] * lat, z, ang(h)))
    (x, y, z), h = along(out, s0, True)
    rows.append(('ForwardStartLine', 0, x, y, z, ang(h)))
    jf = min(range(len(out)), key=lambda i: math.dist(out[i][:2], fin[1:3]))
    (x, y, z), h = along(out, cum[jf], True)
    rows.append(('ForwardFinishLine', 1, x, y, z, ang(h)))
    print('bridge: start line %.0f m from route start, finish at %.0f of %.0f m' % (s0, cum[jf], cum[-1]))
    return out, rows


def png(path, pts, rows, closed):
    from PIL import Image, ImageDraw
    xs, ys = [p[0] for p in pts], [p[1] for p in pts]
    x0, x1, y0, y1 = min(xs) - 50, max(xs) + 50, min(ys) - 50, max(ys) + 50
    sc = 900 / max(x1 - x0, y1 - y0)
    im = Image.new('RGB', (int((x1 - x0) * sc) + 1, int((y1 - y0) * sc) + 1), (20, 20, 24))
    dr = ImageDraw.Draw(im)
    T = lambda p: ((p[0] - x0) * sc, (y1 - p[1]) * sc)
    dr.line([T(p) for p in pts + (pts[:1] if closed else [])], fill=(255, 140, 0), width=3)
    for name, o, x, y, z, a in rows:
        c = {'ForwardStartingPosition': (0, 200, 255), 'ForwardStartLine': (255, 255, 255), 'ForwardFinishLine': (80, 255, 80)}[name]
        q = T((x, y))
        dr.ellipse([q[0] - 4, q[1] - 4, q[0] + 4, q[1] + 4], fill=c)
    im.save(path)


def main():
    base = lzc.exe_decode(open(SRC, 'rb').read())
    ground = U.Ground(CF.old_rows(base))
    which = [a for a in sys.argv[1:] if a in ('park', 'bridge')] or ['park', 'bridge']
    for name in which:
        room = None
        if name == 'park':
            pts, mk = park_loop(ground)
            rows, closed = park_markers(mk, ground), True
        else:
            pts, rows = bridge_race(ground)
            closed = False
            room = side_room(CF.old_rows(base), pts)
        out = os.path.join(REPO, 'build', 'openworld', 'TRACKB1010_%s.lzc' % name)
        open(out, 'wb').write(lzc.encode(swap(base, pts, closed, rows, room)))
        print('wrote', out, os.path.getsize(out), 'B')
        if '--png' in sys.argv:
            png(os.path.join(sys.argv[sys.argv.index('--png') + 1], name + '.png'), pts, rows, closed)


if __name__ == '__main__':
    main()
