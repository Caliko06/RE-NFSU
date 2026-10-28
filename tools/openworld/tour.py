#!/usr/bin/env python3
"""tour.py: TRACKB1010.lzc, the WORLD track with its own closed city tour (phase E, docs/openworld/tour.md).

Why: the three Free Run rivals follow the ROAD GRAPH (sections 0x34121, links 0x34122), not the TrackPath: a racer
walks node by node (sub_5a53c0) and at a node with a link takes it when the link decider (sub_462840) accepts; a
type 2 link is ALWAYS taken, types 5/7 never, the others at random. The merged city (TRACKB1001 + the union
collision) still has the road net of base track 1001 (25 sections), so the rivals lap Olympic Square. Here the road
net is replaced by a tour of whole sections of the 16 street tracks, joined only by type 2 links (no random fork),
so the walk is one fixed closed loop across the city.

How the tour is made (RE of the data, measured with the same parsers):
  - a chain = the path of one open street track (1102..1109): start at the node nearest its TrackPath start, go
    node by node, take that track's own type 2 forward link (0x34122 d=0) when the node has one, stop at a section
    end (sections of 8 km routes: 9..15 chains of ~500 m);
  - a connector = the cheapest directed hop path between the end of one chain and the start of the next (a hop =
    leave node u for node v of another section when v is within 14 m, same heading cos > 0.92, not behind u);
  - the cycle (1104, 1106, 1109, 1107) is the longest feasible one with connectors under 25 % of the loop (searched over
    all sets of 3..5 chains, every chain section banned for the connectors: a section is entered once);
    it passes the base start grid (1687,-463) on 1106 section 21, heading east. The tour is rotated to start there.
  - output = base TRACKB1001 with: 0x34121 = the used sections renumbered 0..n-1 (header +0xa id, nodes +0x83 id,
    node +0x84 dword bits 20..24 = 31 "no 0x34123 record", link bytes +0x81/+0x82), 0x34122 = the hops as pairs
    (forward d=0 on the source node, reverse d=1 on the dest node, type 2), 0x34124 and 0x34123 absent (as the
    1008 file; Free Run does not use routes), TrackPath 0x34148/49 = the tour polyline (closed, flag 0x100).
  - then tools/openworld/build.py's build_file (merged collision, props, no fences) and its checks.
usage: tour.py [--plan]   (--plan: only print the plan and the self-check of the road net, no file)"""
import collections, heapq, itertools, json, math, os, random, struct, sys, time
HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import build as B  # noqa: E402  (also sets NFSU1_MAIN, puts tools/hopper and ref/tools/ug1-tracks on the path)
import polys  # noqa: E402
import q_owcoll2_gen as gen  # noqa: E402
import q_owcoll2_lzc as lzc  # noqa: E402
import q_owcoll2_write as w  # noqa: E402
from lib import load, find, trackb_path, PC  # noqa: E402

TR = polys.TRACKS
CYCLE = (1104, 1106, 1109, 1107)      # chains, in order; the loop closes from the last back to the first
START_XY = (1687.0, -463.0)           # the base start grid (rivals spawn here), heading east
HOP_R, HOP_COS, HOP_COST = 14.0, 0.92, 25.0
MAX_SEC, MAX_ENT = 128, 255
OUT_ID = 1010


# ---- reading a track's road net ------------------------------------------------------------------------------------
def read_net(tid):
    d = load(trackb_path(PC, tid))
    secs = {}
    (b, s), = find(d, 0x34121)
    p = b
    while p < b + s:
        sid = struct.unpack_from('<h', d, p + 0xa)[0]
        lst = struct.unpack_from('<i', d, p + 0xc)[0]
        n = struct.unpack_from('<h', d, p + 0x10)[0]
        nodes = [bytes(d[p + 0x27c + i * 0x88:p + 0x27c + (i + 1) * 0x88]) for i in range(n)]
        secs[sid] = dict(hdr=bytes(d[p:p + 0x27c]), lst=lst, nodes=nodes)
        p += 0x27c + n * 0x88
    assert p == b + s
    (b, s), = find(d, 0x34122)
    ent = [bytes(d[o:o + 32]) for o in range(b, b + s, 32)]
    tp = None
    h, n = find(d, 0x34148), find(d, 0x34149)
    if h and n:
        nb, ns = n[0]
        tp = [struct.unpack_from('<2f', d, nb + i * 20) for i in range(ns // 20)]
    return dict(secs=secs, ent=ent, tp=tp)


class City:
    def __init__(self):
        self.net = {t: read_net(t) for t in TR}
        self.nodes, self.key = [], {}                  # node = [track, sid, idx, x, y, hx, hy]
        for t in TR:
            for sid, s in self.net[t]['secs'].items():
                if s['lst'] != 0:
                    continue                           # list 1 = the dead-end stubs of traffic routes
                for i, nd in enumerate(s['nodes']):
                    x, y = struct.unpack_from('<2f', nd, 0)
                    self.key[(t, sid, i)] = len(self.nodes)
                    self.nodes.append([t, sid, i, x, y, 0.0, 0.0])
        for k, (t, sid, i, x, y, _, _) in enumerate(self.nodes):
            a, b = self.key.get((t, sid, i + 1)), self.key.get((t, sid, i - 1))
            if a is not None:
                dx, dy = self.nodes[a][3] - x, self.nodes[a][4] - y
            else:
                dx, dy = x - self.nodes[b][3], y - self.nodes[b][4]
            l = math.hypot(dx, dy) or 1.0
            self.nodes[k][5], self.nodes[k][6] = dx / l, dy / l
        cell = collections.defaultdict(list)
        for k, n in enumerate(self.nodes):
            cell[(int(n[3] // HOP_R), int(n[4] // HOP_R))].append(k)
        self.adj = [[] for _ in self.nodes]
        for k, n in enumerate(self.nodes):
            nx = self.key.get((n[0], n[1], n[2] + 1))
            if nx is not None:
                self.adj[k].append((nx, self.dist(k, nx)))
            for dx in (-1, 0, 1):
                for dy in (-1, 0, 1):
                    for v in cell.get((int(n[3] // HOP_R) + dx, int(n[4] // HOP_R) + dy), ()):
                        m = self.nodes[v]
                        if (m[0], m[1]) == (n[0], n[1]):
                            continue
                        ex, ey = m[3] - n[3], m[4] - n[4]
                        d = math.hypot(ex, ey)
                        if d > HOP_R or m[5] * n[5] + m[6] * n[6] < HOP_COS or ex * n[5] + ey * n[6] < -2:
                            continue
                        if (m[0], m[1], m[2] + 1) not in self.key:
                            continue                   # never land on the last node of a section
                        self.adj[k].append((v, d + HOP_COST))

    def dist(self, a, b):
        return math.hypot(self.nodes[a][3] - self.nodes[b][3], self.nodes[a][4] - self.nodes[b][4])

    def sec(self, k):
        return self.nodes[k][0], self.nodes[k][1]

    def links(self, t):
        """the track's own type 2 forward links: (sid, idx) -> (dsid, didx)"""
        out = {}
        for e in self.net[t]['ent']:
            _, dn, sn, _, ds, ss, ty, _, d = struct.unpack_from('<fHHBBBBBB', e, 0)
            if ty == 2 and d == 0 and (ds, dn) != (ss, sn):
                out[(ss, sn)] = (ds, dn)
        return out

    def chain(self, t):
        """node ids along the track's own route"""
        L = self.links(t)
        sx, sy = self.net[t]['tp'][0]
        k = min((k for k, n in enumerate(self.nodes) if n[0] == t), key=lambda k: math.hypot(self.nodes[k][3] - sx, self.nodes[k][4] - sy))
        sid, idx = self.nodes[k][1], self.nodes[k][2]
        path, seen = [(sid, idx)], {(sid, idx)}
        while True:
            if (sid, idx) in L:
                sid, idx = L[(sid, idx)]
            elif (t, sid, idx + 1) in self.key:
                idx += 1
            else:
                break
            if (sid, idx) in seen:
                break
            seen.add((sid, idx))
            path.append((sid, idx))
        return [self.key[(t, s, i)] for s, i in path]

    def connector(self, a, b, banned):
        """cheapest hop path a -> b through sections not in banned (the two end sections are allowed)"""
        ban = set(banned) - {self.sec(a), self.sec(b)}
        dist, prev, h = {a: 0.0}, {}, [(0.0, a)]
        while h:
            d, u = heapq.heappop(h)
            if d > dist[u]:
                continue
            if u == b:
                break
            for v, c in self.adj[u]:
                if self.sec(v) in ban:
                    continue
                if d + c < dist.get(v, 1e18):
                    dist[v], prev[v] = d + c, u
                    heapq.heappush(h, (d + c, v))
        if b not in dist:
            return None
        seg = [b]
        while seg[-1] != a:
            seg.append(prev[seg[-1]])
        return seg[::-1]


def plan_cycle(city, order, first):
    """chains in this order, connectors placed from connector number `first` (a section is entered once, so the
    connectors ban each other's sections); returns the node list or None"""
    chains = [city.chain(t) for t in order]
    banned = {city.sec(k) for c in chains for k in c}
    mids = {}
    for j in range(len(order)):
        i = (first + j) % len(order)
        c, nxt = chains[i], chains[(i + 1) % len(order)][0]
        conn = city.connector(c[-1], nxt, banned)
        if not conn:
            return None
        banned |= {city.sec(k) for k in conn[1:-1]}
        mids[i] = conn[1:-1]
    tour = []
    for i, c in enumerate(chains):
        tour += c + mids[i]
    return tour


def plan(city):
    """the closed tour as a node list (the first node is where the rivals start): the CYCLE chains, any order that
    closes with every section entered once, the shortest; rotated to start on the grid"""
    best = None
    for perm in itertools.permutations(CYCLE[1:]):
        for first in range(len(CYCLE)):
            tour = plan_cycle(city, (CYCLE[0],) + perm, first)
            if tour:
                ln = sum(city.dist(a, b) for a, b in zip(tour, tour[1:]))
                if best is None or ln < best[0]:
                    best = (ln, tour, (CYCLE[0],) + perm)
    assert best, 'no closed tour for %s' % (CYCLE,)
    print('order', best[2], '%.0f m' % best[0])
    tour = best[1]
    s = min(range(len(tour)), key=lambda i: math.hypot(city.nodes[tour[i]][3] - START_XY[0], city.nodes[tour[i]][4] - START_XY[1]))
    return tour[s:] + tour[:s]


# ---- the new chunks ------------------------------------------------------------------------------------------------
def hops(city, tour):
    """(from node id, to node id) of every move that is not the next node of the same section; the tour wraps"""
    out = []
    for i, a in enumerate(tour):
        b = tour[(i + 1) % len(tour)]
        na, nb = city.nodes[a], city.nodes[b]
        if (na[0], na[1]) == (nb[0], nb[1]) and nb[2] == na[2] + 1:
            continue
        out.append((a, b))
    return out


def road_chunks(city, tour):
    """returns (0x34121 payload, 0x34122 payload, hop list, new ids {(t,sid): id}, entry count)"""
    order = []
    for k in tour:
        s = city.sec(k)
        if s not in order:
            order.append(s)
    assert len(order) == len({city.sec(k) for k in tour}), 'a section is entered twice'
    ids = {s: i for i, s in enumerate(order)}
    assert len(order) <= MAX_SEC, '%d sections > %d' % (len(order), MAX_SEC)
    secs = {}
    for (t, sid), nid in ids.items():
        s = city.net[t]['secs'][sid]
        hdr = bytearray(s['hdr'])
        struct.pack_into('<h', hdr, 0xa, nid)
        struct.pack_into('<i', hdr, 0xc, 0)
        nodes = []
        for nd in s['nodes']:
            nd = bytearray(nd)
            nd[0x81] = nd[0x82] = 0xff
            nd[0x83] = nid
            v = struct.unpack_from('<I', nd, 0x84)[0] | (0x1f << 20)
            struct.pack_into('<I', nd, 0x84, v)
            nodes.append(nd)
        secs[nid] = (hdr, nodes)
    ent = []
    hp = hops(city, tour)
    for a, b in hp:
        na, nb = city.nodes[a], city.nodes[b]
        sa, sb = ids[(na[0], na[1])], ids[(nb[0], nb[1])]
        for src, dst, d in (((sa, na[2]), (sb, nb[2]), 0), ((sb, nb[2]), (sa, na[2]), 1)):
            e = bytearray(32)
            struct.pack_into('<fHH', e, 0, 0.0, dst[1], src[1])
            e[8], e[9], e[0xa], e[0xb], e[0xc], e[0xd] = 0, dst[0], src[0], 2, 7, d
            struct.pack_into('<IiII', e, 0x10, 0, -1, 0, 0)
            node = secs[src[0]][1][src[1]]
            slot = 0x81 if node[0x81] == 0xff else 0x82
            assert node[slot] == 0xff, 'node (%d,%d) has no free link slot' % src
            node[slot] = len(ent)
            ent.append(bytes(e))
    assert len(ent) <= MAX_ENT, '%d entries > %d' % (len(ent), MAX_ENT)
    p21 = b''.join(bytes(secs[i][0]) + b''.join(bytes(n) for n in secs[i][1]) for i in range(len(order)))
    return p21, b''.join(ent), hp, ids, len(ent)


def trackpath(city, tour):
    """closed TrackPath 0x34148 / 0x34149 along the tour (every ~45 m of the node polyline)"""
    pts = [(city.nodes[k][3], city.nodes[k][4]) for k in tour]
    keep, acc = [0], 0.0
    for i in range(1, len(pts)):
        acc += math.hypot(pts[i][0] - pts[i - 1][0], pts[i][1] - pts[i - 1][1])
        if acc >= 45.0:
            keep.append(i)
            acc = 0.0
    sel = [pts[i] for i in keep]
    hx, hy = pts[1][0] - pts[0][0], pts[1][1] - pts[0][1]
    l = math.hypot(hx, hy) or 1.0
    last = (sel[0][0] + 0.5 * hx / l, sel[0][1] + 0.5 * hy / l)       # the base files close with a node 0.6 m past the first
    sel.append(last)
    cum, total = [0.0], 0.0
    for i in range(1, len(sel) - 1):
        total += math.hypot(sel[i][0] - sel[i - 1][0], sel[i][1] - sel[i - 1][1])
        cum.append(total)
    cum.append(0.0)
    total += math.hypot(sel[-1][0] - sel[-2][0], sel[-1][1] - sel[-2][1])
    n = len(sel) - 1
    body = b''.join(struct.pack('<ffHhhhf', x, y, 0, -1, -1, -1, c) for (x, y), c in zip(sel, cum))   # +8 path 0, +10..+14 grid refs -1, +16 distance
    head = struct.pack('<IHHI7f', 0x100, n, n, 0, total, 1.0, sel[0][0], sel[0][1], sel[n - 1][0], sel[n - 1][1], 0.0)
    assert len(head) == 40
    return head, body, total


def make_base(base, p21, p22, head, body):
    """the base TRACKB1001 with the road chunks and the TrackPath replaced; offsets after them keep their phase"""
    ch = w.top_chunks(base)
    ids = [c[0] for c in ch]
    iz, i21 = ids.index(0x80034147), ids.index(0x34121)
    i24 = ids.index(0x34124)
    assert ids[i21:i21 + 3] == [0x34121, 0x34122, 0x34124] and ids[iz + 1] == 0 and ch[iz + 1][2] == 2048
    kids, p, (_, o, size) = [], ch[iz][1] + 8, ch[iz]
    while p < o + 8 + size:
        cid, sz = struct.unpack_from('<II', base, p)
        kids.append((cid, bytes(base[p + 8:p + 8 + sz])))
        p += 8 + sz
    assert [k[0] for k in kids] == [0x34148, 0x34149, 0x3414a]
    kids[0], kids[1] = (0x34148, head), (0x34149, body)
    zbody = b''.join(struct.pack('<II', c, len(d)) + d for c, d in kids)
    zc = struct.pack('<II', 0x80034147, len(zbody)) + zbody
    old_zone = 8 + size
    out = bytearray(base[:ch[iz][1]])
    out += zc
    pad = ch[iz + 1][2]                                       # build_file asserts the 2048 B pad and re-lays its phase
    out += struct.pack('<II', 0, pad) + b'\0' * pad
    out += struct.pack('<II', 0x34121, len(p21)) + p21
    out += struct.pack('<II', 0x34122, len(p22)) + p22
    old_end = ch[i24][1] + 8 + ch[i24][2]
    new_len = len(out)
    # one id-0 chunk where 0x34124 was: the rest of the file keeps its offset phase mod 128 (the packer's alignments)
    need = (old_end - new_len) % 128
    if need < 8:
        need += 128
    out += struct.pack('<II', 0, need - 8) + b'\0' * (need - 8)
    out += base[old_end:]
    return bytes(out)


def selfcheck(city, tour, new_base):
    """walk the new road net the way the racer does (sub_5a53c0: link slot 0 then 1 if its type-2 d=0 link exists, else the next node)"""
    d = new_base
    (b, s), = find(d, 0x34121)
    secs, p = {}, b
    while p < b + s:
        sid = struct.unpack_from('<h', d, p + 0xa)[0]
        n = struct.unpack_from('<h', d, p + 0x10)[0]
        assert struct.unpack_from('<i', d, p + 0xc)[0] == 0
        secs[sid] = [bytes(d[p + 0x27c + i * 0x88:p + 0x27c + (i + 1) * 0x88]) for i in range(n)]
        p += 0x27c + n * 0x88
    assert p == b + s and len(secs) <= MAX_SEC and sorted(secs) == list(range(len(secs)))
    (b, s), = find(d, 0x34122)
    ent = [bytes(d[o:o + 32]) for o in range(b, b + s, 32)]
    assert len(ent) <= MAX_ENT
    assert not find(d, 0x34124) and not find(d, 0x34123)
    for sid, ns in secs.items():
        for i, nd in enumerate(ns):
            assert nd[0x83] == sid and (struct.unpack_from('<I', nd, 0x84)[0] >> 20) & 0x1f == 31
    # the start: the node nearest to the grid
    best = min(((math.hypot(struct.unpack_from('<f', nd, 0)[0] - START_XY[0], struct.unpack_from('<f', nd, 4)[0] - START_XY[1]), s_, i) for s_, ns in secs.items() for i, nd in enumerate(ns)))
    _, sid, idx = best
    start = (sid, idx)
    visited, length, nsteps = collections.OrderedDict(), 0.0, 0
    cur = start
    xy = lambda c: struct.unpack_from('<2f', secs[c[0]][c[1]], 0)
    while True:
        nd = secs[cur[0]][cur[1]]
        nxt = None
        for slot in (0x81, 0x82):
            if nd[slot] != 0xff:
                e = ent[nd[slot]]
                dn, sn, ds, ss, ty, dr = struct.unpack_from('<H', e, 4)[0], struct.unpack_from('<H', e, 6)[0], e[9], e[0xa], e[0xb], e[0xd]
                assert (ss, sn) == cur
                if ty == 2 and dr == 0:
                    nxt = (ds, dn)
                    break
        if nxt is None:
            nxt = (cur[0], cur[1] + 1)
            assert nxt[1] < len(secs[cur[0]]), 'the walk stops at the end of section %d' % cur[0]
        a, b2 = xy(cur), xy(nxt)
        length += math.hypot(a[0] - b2[0], a[1] - b2[1])
        nsteps += 1
        visited[cur] = 1
        cur = nxt
        if cur == start:
            break
        assert cur not in visited, 'the walk loops without passing the start: %s' % (cur,)
        assert nsteps < 20000
    # every tour node visited, in the tour's number of steps
    assert nsteps == len(tour), 'walk %d steps, tour %d nodes' % (nsteps, len(tour))
    return dict(sections=len(secs), entries=len(ent), steps=nsteps, walk_m=round(length), start=start)


def main():
    plan_only = '--plan' in sys.argv
    t0 = time.time()
    city = City()
    print('graph: %d nodes (%.0fs)' % (len(city.nodes), time.time() - t0), flush=True)
    tour = plan(city)
    secs = []
    for k in tour:
        if city.sec(k) not in secs:
            secs.append(city.sec(k))
    xs = [city.nodes[k][3] for k in tour]
    ys = [city.nodes[k][4] for k in tour]
    print('tour: %d nodes, %d sections %s, x %.0f..%.0f y %.0f..%.0f' % (len(tour), len(secs), '(%s)' % ','.join('%d:%d' % s for s in secs[:6]) + '..',
                                                                          min(xs), max(xs), min(ys), max(ys)), flush=True)
    p21, p22, hp, ids, nent = road_chunks(city, tour)
    head, body, total = trackpath(city, tour)
    print('hops %d, entries %d, sections %d, TrackPath %d nodes %.0f m' % (len(hp), nent, len(ids), len(body) // 20, total), flush=True)
    base = load(trackb_path(PC, 1001))
    base2 = make_base(base, p21, p22, head, body)
    print('road net self-check:', selfcheck(city, tour, base2), flush=True)
    if plan_only:
        return
    fences = json.load(open(B.FENCES))
    fence_keys = {f['key'] for f in fences['fences']}
    rows, n_union, n_fence = B.union_rows(fence_keys)
    union_keys = {polys.key(r) for r in rows}
    bases = {t: load(trackb_path(PC, t)) for t in TR}
    cls, props = B.union_props(bases)
    g = gen.derive(rows)
    print('collision derived (%.0fs)' % (time.time() - t0), flush=True)
    new = B.build_file(base2, g, rows, props)
    blob = lzc.encode(new)
    path = os.path.join(B.OUT, 'TRACKB%d.lzc' % OUT_ID)
    open(path, 'wb').write(blob)
    f = B.check(OUT_ID, base2, new, blob, g, rows, props, fence_keys, union_keys, random.Random(7))
    print('selfcheck of the written file:', selfcheck(city, tour, new), flush=True)
    meta = dict(source='tools/openworld/tour.py', cycle=list(CYCLE), nodes=len(tour), sections=len(ids), entries=nent, hops=len(hp),
                trackpath_nodes=len(body) // 20, tour_m=round(total), file=os.path.basename(path), bytes=len(blob),
                start_xy=list(START_XY), sections_map={'%d:%d' % k: v for k, v in ids.items()})
    json.dump(meta, open(os.path.join(B.OUT, 'tour1010.json'), 'w'), indent=1)
    print('wrote', path, len(blob), 'bytes', {k: v for k, v in f.items()}, '(%.0fs)' % (time.time() - t0))


if __name__ == '__main__':
    main()
