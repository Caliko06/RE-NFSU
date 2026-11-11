#!/usr/bin/env python3
"""ug2_traffic.py: NFSU1 traffic on the UG2 streets near the bridge (census/ug2/roads.md section 5, stage 1).

Called by ug2_collfile.py (the one writer of build/openworld/TRACKB1010.lzc): apply(base, rows) -> base' with the road chunks 0x34121 / 0x34122
extended, check(new, old, rows) -> static check numbers (asserts). Nothing else is rewritten; the NFSU1 part of the net stays byte for byte
(sections 0..77, entries 0..195) except ONE link slot byte of the anchor node (a link needs a source slot).

Built (every field says what proves it; sources in census/ug2/roads.md sections 1-3):
  UG2 part : the L4RA sections of RoutesFreeRoam.bin with a node within 600 m of the bridge mouth (UG2 211, 1405): moved by the placement
             R270 (x,y)->(y,-x) + t (tools/ug2_roads.to_nfsu1); node z = s16/8 + tz; tangent (tx,ty)->(ty,-tx), the back heading is its negative;
             drive flags bit 11/18/25/26/27/28 -> 6/19/25/26/27/28 (0x4424d0, 0x442520 vs 0x5dd550..); intersection bits 20..24 = 31 (as tour.py).
             Sections renumbered 79.. in UG2 id order, one per UG2 section, nodes 1:1 (226).
  connector: section 78, from the junction node 28:3 (221.6, 401.5, z 43.0) west along the stub road, north over the bridge, left onto the UG2
             road (ends at the road centre, heading west). Nodes every <= 8 m, z = the collision ground there.
  links    : the UG2 entries inside the set are 20 twin pairs; a pair is written as citygraph.py writes a link: d=0 entry (source -> target) and its
             d=1 twin (target side -> source side), both only if the landing is > AHEAD (0.1 m, [0x6cc7b8], citygraph.py:881; the grower at 0x5a58d0
             faults at 0x462a06 otherwise) ahead of the source along its heading for that direction (d=0 +0xc/+0x10, d=1 +0x14/+0x18). A source
             that fails is moved back up to 3 nodes (citygraph.py:802-813), hop <= 50 m. Pairs whose ends run against each other
             (the global walk direction cannot follow them) get no entry that passes the test and are dropped, counted in the report.
  types    : citygraph.py:742-747: the last way out of a section is type 2 / lane 2 (always taken), the others 0 / 7. The anchor link is 2 / 2.
  templates: header = live section 0 (the NFSU1 section whose nodes all carry traffic lanes), node = the live section 0 node with default
             widths nearest to that section's median; see TEMPLATE_* below. Lanes: only traffic lane 11 and 17 (offset 1.8 m right of the driver).
usage: python3 tools/ug2_traffic.py [--check]   (--check: read build/openworld/TRACKB1010.lzc and run the static check)"""
import collections, math, os, statistics, struct, sys
HERE = os.path.dirname(os.path.abspath(__file__))
REPO = os.path.abspath(os.path.join(HERE, '..'))
os.environ.setdefault('NFSU1_MAIN', REPO)
sys.path.insert(0, HERE)
sys.path.insert(0, os.path.join(HERE, 'hopper'))
sys.path.insert(0, os.path.join(HERE, 'openworld'))
import ug2_roads as R  # noqa: E402
import ug2_bridge as ub  # noqa: E402
import q_owcoll2_write as w  # noqa: E402
import tour as T  # noqa: E402
from lib import find  # noqa: E402

MOUTH = (211.0, 1405.0)       # UG2 bridge mouth, raw UG2 units (roads.md section 4)
RADIUS = 600.0
ANCHOR = (28, 3)              # NFSU1 node of the junction in front of the stub road (x 221.6, y 401.5)
AHEAD = 0.1                   # citygraph.py:881
MAX_SHIFT, MAX_HOP = 3, 50.0
SPACING, RAD = 8.0, 12.0
FWD_BITS = (1 << 6) | (1 << 25) | (1 << 27)
BACK_BITS = (1 << 19) | (1 << 26) | (1 << 28)
MAP_BITS = ((11, 6), (18, 19), (25, 25), (26, 26), (27, 27), (28, 28))     # UG2 node +0xc bit -> NFSU1 node +0x84 bit
MASK = sum(1 << b for _, b in MAP_BITS) | (0x1f << 20)
TEMPLATE_SEC = 0              # live section: all 98 nodes carry the traffic lanes 11..13 / 17..19, hdr[0x265+k] set for them
LANES = (11, 17)              # traffic lanes kept on the new nodes (offset 1.8 m, right of the driver)
UNUSED_LANES = (12, 13, 18, 19)


def parse(d):
    """(0x34121 offset and size, section list [(sid, offset, n)], entries) of a decoded TRACKB"""
    (b, s), = find(d, 0x34121)
    p, secs = b, []
    while p < b + s:
        secs.append((struct.unpack_from('<h', d, p + 0xa)[0], p, struct.unpack_from('<h', d, p + 0x10)[0]))
        p += 0x27c + secs[-1][2] * 0x88
    assert p == b + s
    (b2, s2), = find(d, 0x34122)
    return (b, s), secs, [bytes(d[o:o + 32]) for o in range(b2, b2 + s2, 32)]


class Ground:
    """collision ground (rows without the wall flags 0x0a) as triangles in 16 m cells, from the final row list"""
    def __init__(self, rows, box=(-700, 300, 600, 1750)):
        self.cell = collections.defaultdict(list)
        for r in rows:
            d = ub.unpack(r)
            if d['fl'] & 0x0a:                # walls (0x02, 0x08) are not ground; any surface id counts (the UG2 side roads are surface 11 / 16)
                continue
            n = 4 if d['fl'] & 0x10 else 3
            v = [(d['xs'][k] / 8, d['ys'][k] / 8, ub.zof(d, k)) for k in range(n)]
            x0, x1, y0, y1 = min(p[0] for p in v), max(p[0] for p in v), min(p[1] for p in v), max(p[1] for p in v)
            if x1 < box[0] or x0 > box[2] or y1 < box[1] or y0 > box[3]:
                continue
            for cx in range(int(x0 // 16), int(x1 // 16) + 1):
                for cy in range(int(y0 // 16), int(y1 // 16) + 1):
                    self.cell[(cx, cy)].append(v)

    @staticmethod
    def _tri(a, b, c, x, y):
        den = (b[1] - c[1]) * (a[0] - c[0]) + (c[0] - b[0]) * (a[1] - c[1])
        if den == 0:
            return None
        l1 = ((b[1] - c[1]) * (x - c[0]) + (c[0] - b[0]) * (y - c[1])) / den
        l2 = ((c[1] - a[1]) * (x - c[0]) + (a[0] - c[0]) * (y - c[1])) / den
        return l1 * a[2] + l2 * b[2] + (1 - l1 - l2) * c[2] if min(l1, l2, 1 - l1 - l2) >= -1e-9 else None

    def z(self, x, y, near):
        """ground z at (x, y) closest to `near` (roads can overlap), None if there is no ground"""
        out = []
        for v in self.cell.get((int(x // 16), int(y // 16)), ()):
            z = self._tri(v[0], v[1], v[2], x, y)
            if z is None and len(v) == 4:
                z = self._tri(v[0], v[2], v[3], x, y)
            if z is not None:
                out.append(z)
        return min(out, key=lambda q: abs(q - near)) if out else None


def ug2_part():
    """selected UG2 sections (sorted by UG2 id) with nodes in NFSU1 space, and their entry pairs"""
    g = R.load('A')
    sel = [s for s in g['sections'] if any(math.hypot(n['x'] - MOUTH[0], n['y'] - MOUTH[1]) <= RADIUS for n in s['nodes'])]
    sel.sort(key=lambda s: s['id'])
    ids = {s['id'] for s in sel}
    secs = []
    for s in sel:
        nodes = []
        for n in s['nodes']:
            x, y, z = R.to_nfsu1(n['x'], n['y'], n['z'])
            hx, hy = n['t'][1], -n['t'][0]
            l = math.hypot(hx, hy) or 1.0
            fl = sum(1 << b for a, b in MAP_BITS if n['fl'] >> a & 1)
            nodes.append(dict(x=x, y=y, z=z, h=(hx / l, hy / l), fl=fl))
        secs.append(dict(uid=s['id'], cls=s['cls'], nodes=nodes))
    pairs, seen = [], set()
    for e in g['entries']:
        if e['ss'] in ids and e['ds'] in ids:
            a, b = (e['ss'], e['sn']), (e['ds'], e['dn'])
            if (b, a) not in seen:          # every entry has its reverse twin (roads.md 1.3): one pair
                seen.add((a, b))
                pairs.append((a, b))
    return secs, pairs


def connector(ground, anchor_xyz):
    """connector nodes [(x, y, z, hx, hy)]: anchor -> west along the stub road -> north over the bridge -> left onto the UG2 road"""
    ax, ay, az = anchor_xyz
    yc = (394.0 + 407.75) / 2             # the stub road y extent at x 140..200 (ground probe): 394.0 .. 407.75
    xc = (114.75 + 128.5) / 2             # the N-S arm x extent at y 420..500: 114.75 .. 128.5; the bridge walls 114.6 / 128.6
    y_end = 600.6                         # UG2 road centre line at x ~114: between nodes 230:23 (124.1, 601.2) and 230:24 (74.4, 599.1)
    pts = [(ax, ay)]
    n = 40
    # corner 1: heading west -> north (right turn), centre (xc + RAD, yc + RAD)
    pts.append((xc + RAD, yc))
    for k in range(1, n):
        a = -math.pi / 2 - (math.pi / 2) * k / n
        pts.append((xc + RAD + RAD * math.cos(a), yc + RAD + RAD * math.sin(a)))
    pts.append((xc, yc + RAD))
    y_arc = y_end - RAD                   # corner 2: heading north -> west (left turn), centre (xc - RAD, y_arc)
    pts.append((xc, y_arc))
    for k in range(1, n):
        a = 0.0 + (math.pi / 2) * k / n
        pts.append((xc - RAD + RAD * math.cos(a), y_arc + RAD * math.sin(a)))
    pts.append((xc - RAD, y_end))
    cum = [0.0]
    for p, q in zip(pts, pts[1:]):
        cum.append(cum[-1] + math.dist(p, q))
    total = cum[-1]
    m = math.ceil(total / SPACING)
    out = []
    for i in range(m + 1):
        s = total * i / m
        j = max(k for k in range(len(cum) - 1) if cum[k] <= s)
        f = (s - cum[j]) / ((cum[j + 1] - cum[j]) or 1.0)
        out.append((pts[j][0] + f * (pts[j + 1][0] - pts[j][0]), pts[j][1] + f * (pts[j + 1][1] - pts[j][1])))
    res = []
    for i, (x, y) in enumerate(out):
        a, b = out[max(i - 1, 0)], out[min(i + 1, len(out) - 1)]
        hx, hy = b[0] - a[0], b[1] - a[1]
        l = math.hypot(hx, hy)
        z = ground.z(x, y, az)
        assert z is not None, 'no collision ground under the connector at (%.1f, %.1f)' % (x, y)
        az = z
        res.append((x, y, z, hx / l, hy / l))
    return res


def apply(base, rows):
    """base: decoded TRACKB (the NFSU1 net, 78 sections / 196 entries); rows: the final collision rows. -> new decoded TRACKB"""
    (b, s), secs0, ent0 = parse(base)
    assert [x[0] for x in secs0] == list(range(len(secs0)))
    n0, e0 = len(secs0), len(ent0)
    node = lambda sid, i: bytes(base[secs0[sid][1] + 0x27c + i * 0x88:secs0[sid][1] + 0x27c + (i + 1) * 0x88])
    # ---- templates (real NFSU1 bytes of the live section 0)
    tp, tn = secs0[TEMPLATE_SEC][1], secs0[TEMPLATE_SEC][2]
    hdr_t = bytes(base[tp:tp + 0x27c])
    cand = [node(TEMPLATE_SEC, i) for i in range(tn)]
    cand = [c for c in cand if set(c[0x75:0x81]) == {6} and struct.unpack_from('<h', c, 0x3c + 2 * 11)[0] == 464]
    med = [statistics.median(struct.unpack_from('<f', c, o)[0] for c in cand) for o in (0x24, 0x28)]
    tmpl = min(cand, key=lambda c: sum(abs(struct.unpack_from('<f', c, o)[0] - m) for o, m in zip((0x24, 0x28), med)))
    tidx = [node(TEMPLATE_SEC, i) for i in range(tn)].index(tmpl)
    # ---- the new geometry
    ug, pairs = ug2_part()
    ground = Ground(rows)
    ax, ay, az = struct.unpack_from('<3f', node(*ANCHOR), 0)
    con = connector(ground, (ax, ay, az))
    CID = n0
    sec_of = {s_['uid']: n0 + 1 + k for k, s_ in enumerate(ug)}          # UG2 section id -> NFSU1 id
    N = {}                                                                # (sec, i) -> dict(x, y, z, h, fl, off?)
    for i, (x, y, z, hx, hy) in enumerate(con):
        N[(CID, i)] = dict(x=x, y=y, z=z, h=(hx, hy), fl=sum(1 << b_ for _, b_ in MAP_BITS))
    for s_ in ug:
        for i, nd in enumerate(s_['nodes']):
            N[(sec_of[s_['uid']], i)] = nd
    sizes = {CID: len(con), **{sec_of[s_['uid']]: len(s_['nodes']) for s_ in ug}}
    for sid in range(n0):
        for i in range(secs0[sid][2]):
            x, y, z = struct.unpack_from('<3f', node(sid, i), 0)
            hx, hy = struct.unpack_from('<2f', node(sid, i), 0xc)
            N[(sid, i)] = dict(x=x, y=y, z=z, h=(hx, hy), fl=struct.unpack_from('<I', node(sid, i), 0x84)[0] & (FWD_BITS | BACK_BITS))
    free = collections.defaultdict(int)       # slots used per node (new + existing)
    for sid in range(n0):
        for i in range(secs0[sid][2]):
            nd = node(sid, i)
            free[(sid, i)] = sum(nd[k] != 0xff for k in (0x81, 0x82))
    drv = lambda k: bool(N[k]['fl'] & (FWD_BITS | BACK_BITS))
    f_of = lambda k, d: (N[k]['h'][0] * (-1 if d else 1), N[k]['h'][1] * (-1 if d else 1))

    def entry(src, dst, d):
        """src node key for direction d, or None: moved back along its section up to MAX_SHIFT nodes until dst is > AHEAD ahead"""
        for k in range(MAX_SHIFT + 1):
            c = (src[0], src[1] - k if d == 0 else src[1] + k)
            if not 0 <= c[1] < sizes.get(c[0], secs0[c[0]][2] if c[0] < n0 else 0) or c == dst or free[c] >= 2 or not drv(c):
                continue
            hx, hy = f_of(c, d)
            if (N[dst]['x'] - N[c]['x']) * hx + (N[dst]['y'] - N[c]['y']) * hy > AHEAD and math.dist((N[dst]['x'], N[dst]['y']), (N[c]['x'], N[c]['y'])) <= MAX_HOP:
                return c, k
        return None

    links, dropped = [], []       # links: (u, v, ty, lane, e0 src, e1 src); the d=0 entry u'->v, the d=1 entry v'->u

    def plan(u, v):
        if not (drv(u) and drv(v)):
            return None
        a = entry(u, v, 0)
        if a is None:
            return None
        free[a[0]] += 1
        bk = entry(v, u, 1)
        free[a[0]] -= 1
        return a, bk

    for pa, pb in pairs:
        ka, kb = (sec_of[pa[0]], pa[1]), (sec_of[pb[0]], pb[1])
        best = None
        for u, v in ((ka, kb), (kb, ka)):
            p = plan(u, v)
            if p is None:
                continue
            score = (p[1] is None, p[0][1] + (p[1][1] if p[1] else 0), u)
            if best is None or score < best[0]:
                best = (score, u, v, p)
        if best is None:
            dropped.append((ka, kb))
            continue
        _, u, v, (a0, a1) = best
        free[a0[0]] += 1
        if a1:
            free[a1[0]] += 1
        links.append([u, v, 0, 7, a0[0], a1[0] if a1 else None])
    # the two connector links, first the anchor (NFSU1 28:3 -> connector 0), then the end (connector last -> UG2 230:24)
    land = (sec_of[230], 24)
    for u, v in (((ANCHOR[0], ANCHOR[1]), (CID, 0)), ((CID, len(con) - 1), land)):
        p = plan(u, v)
        assert p is not None and p[1] is not None, 'connector link %s -> %s has no entry' % (u, v)
        free[p[0][0]] += 1
        free[p[1][0]] += 1
        links.append([u, v, 2, 2, p[0][0], p[1][0]])
    # last way out of each section = 2 / 2 (citygraph.py:742-747), counted over d=0 sources inside the new part
    last = {}
    for k, l in enumerate(links[:-2]):
        sec = l[4][0]
        if sec not in last or l[4][1] > links[last[sec]][4][1]:
            last[sec] = k
    for k in last.values():
        links[k][2], links[k][3] = 2, 2
    # ---- entries and slots
    ent = list(ent0)
    slot = collections.defaultdict(list)       # node -> entry indexes
    for u, v, ty, lane, s0, s1 in links:
        for src, dst, d in ((s0, v, 0), (s1, u, 1)):
            if src is None:
                continue
            e = bytearray(32)
            struct.pack_into('<fHH', e, 0, 0.0, dst[1], src[1])
            e[8], e[9], e[0xa], e[0xb], e[0xc], e[0xd] = 0, dst[0], src[0], ty, lane, d
            struct.pack_into('<IiII', e, 0x10, 0, -1, 0, 0)
            slot[src].append(len(ent))
            ent.append(bytes(e))
    assert len(ent) <= 255, len(ent)
    # ---- route distance +0x38: continuous along each new section, through the links from the anchor (citygraph.py route_offsets)
    cum = {}
    for sid, n in sizes.items():
        c = [0.0]
        for i in range(1, n):
            c.append(c[-1] + math.dist((N[(sid, i)]['x'], N[(sid, i)]['y']), (N[(sid, i - 1)]['x'], N[(sid, i - 1)]['y'])))
        cum[sid] = c
    adj = collections.defaultdict(list)       # d(b) = d(a) + dd for the d=0 entry a -> b of every link between new sections
    for u, v, ty, lane, s0, s1 in links:
        if v[0] >= n0 and s0[0] >= n0:
            dd = math.dist((N[s0]['x'], N[s0]['y']), (N[v]['x'], N[v]['y']))
            adj[s0[0]].append((v[0], s0[1], v[1], dd))
            adj[v[0]].append((s0[0], v[1], s0[1], -dd))
    a0 = links[-2][4]                          # the actual NFSU1 source of the anchor link
    d_a0 = struct.unpack_from('<f', node(*a0), 0x38)[0]
    off = {CID: d_a0 + math.dist((N[a0]['x'], N[a0]['y']), (N[(CID, 0)]['x'], N[(CID, 0)]['y']))}
    todo = [CID]
    while todo:
        sid = todo.pop()
        for s2, ia, ib, dd in adj[sid]:
            if s2 not in off:
                off[s2] = off[sid] + cum[sid][ia] + dd - cum[s2][ib]      # off[s2] + cum[s2][ib] = off[sid] + cum[sid][ia] + dd
                todo.append(s2)
    top = max(struct.unpack_from('<f', node(sid, i), 0x38)[0] for sid in range(n0) for i in range(secs0[sid][2]))
    for sid in sizes:
        if sid not in off:
            off[sid] = top + 100.0
            top = off[sid] + cum[sid][-1]
    # ---- bytes
    def make(sid, i):
        k = (sid, i)
        nd = bytearray(tmpl)
        n = sizes[sid]
        struct.pack_into('<3f', nd, 0, N[k]['x'], N[k]['y'], N[k]['z'])
        hx, hy = N[k]['h']
        struct.pack_into('<4f', nd, 0xc, hx, hy, -hx, -hy)
        nxt = math.dist((N[k]['x'], N[k]['y']), (N[(sid, i + 1)]['x'], N[(sid, i + 1)]['y'])) if i + 1 < n else None
        prv = math.dist((N[k]['x'], N[k]['y']), (N[(sid, i - 1)]['x'], N[(sid, i - 1)]['y'])) if i else None
        struct.pack_into('<2f', nd, 0x1c, nxt if nxt is not None else prv, prv if prv is not None else nxt)
        struct.pack_into('<f', nd, 0x38, off[sid] + cum[sid][i])
        for kk in UNUSED_LANES:
            struct.pack_into('<h', nd, 0x3c + 2 * kk, -1)
            nd[0x6a + kk] = 6
        nd[0x81] = nd[0x82] = 0xff
        for j, ei in enumerate(slot.get(k, ())):
            nd[0x81 + j] = ei
        nd[0x83] = sid
        fl = (struct.unpack_from('<I', tmpl, 0x84)[0] & ~MASK) | N[k]['fl'] | (0x1f << 20)
        struct.pack_into('<I', nd, 0x84, fl)
        return bytes(nd)

    sections = []
    for sid in range(n0, n0 + 1 + len(ug)):
        n = sizes[sid]
        hdr = bytearray(hdr_t)
        struct.pack_into('<h', hdr, 0xa, sid)
        struct.pack_into('<i', hdr, 0xc, 0)
        struct.pack_into('<hh', hdr, 0x10, n, n)
        xs, ys = [N[(sid, i)]['x'] for i in range(n)], [N[(sid, i)]['y'] for i in range(n)]
        struct.pack_into('<4f', hdr, 0x20, min(xs), min(ys), max(xs), max(ys))
        for kk in range(23):
            hdr[0x265 + kk] = int(kk in LANES)
        sections.append(bytes(hdr) + b''.join(make(sid, i) for i in range(n)))
    # ---- patch the anchor source slot, assemble the chunks
    p21 = bytearray(base[b:b + s])
    o = secs0[a0[0]][1] - b + 0x27c + a0[1] * 0x88
    sl = 0x81 if p21[o + 0x81] == 0xff else 0x82
    assert p21[o + sl] == 0xff
    p21[o + sl] = slot[a0][0]
    p21 += b''.join(sections)
    p22 = b''.join(ent)
    ch = w.top_chunks(base)
    ids = [c[0] for c in ch]
    i21 = ids.index(0x34121)
    assert ids[i21:i21 + 3] == [0x34121, 0x34122, 0] and ids[i21 + 3] == 0x34130
    old_pad_end = ch[i21 + 2][1] + 8 + ch[i21 + 2][2]           # the 0x34130 header offset: keep its phase mod 128
    out = bytearray(base[:ch[i21][1]])
    out += struct.pack('<II', 0x34121, len(p21)) + p21
    out += struct.pack('<II', 0x34122, len(p22)) + p22
    need = (old_pad_end - len(out)) % 128
    if need < 8:
        need += 128
    out += struct.pack('<II', 0, need - 8) + b'\0' * (need - 8)
    out += base[old_pad_end:]
    print('template node: section %d node %d' % (TEMPLATE_SEC, tidx))
    print('traffic net: %d sections (+%d), %d entries (+%d), %d links, dropped pairs %d, chunk 0x34121 %d -> %d B' % (
        n0 + 1 + len(ug), 1 + len(ug), len(ent), len(ent) - e0, len(links), len(dropped), s, len(p21)))
    return bytes(out)


def walk(C, secs, ent, which, dist=250.0):
    """citygraph.walk_stats (the teleporter walk 0x4563d0, any path) started only from the drivable nodes of the sections in `which`"""
    drv = lambda nd: bool(struct.unpack_from('<I', nd, 0x84)[0] & (FWD_BITS | BACK_BITS))
    seg = lambda nd: struct.unpack_from('<f', nd, 0x1c)[0]

    def go(s, i, fwd, rem, budget):
        nd = secs[s][i]
        rem -= seg(nd) if fwd else (seg(secs[s][i - 1]) if i else 0.0)
        if rem <= 0:
            return True
        budget[0] -= 1
        if budget[0] < 0:
            return False
        nxt = []
        for k in (0x81, 0x82):
            if nd[k] != 0xff:
                e = ent[nd[k]]
                if e[0xd] == (0 if fwd else 1) and e[0xb] != 3:
                    nxt.append((e[9], struct.unpack_from('<H', e, 4)[0]))
        j = i + 1 if fwd else i - 1
        if 0 <= j < len(secs[s]):
            nxt.append((s, j))
        return any(drv(secs[a][b]) and go(a, b, fwd, rem, budget) for a, b in nxt)
    res = {True: [0, 0], False: [0, 0]}
    for s in which:
        for i, nd in enumerate(secs[s]):
            if drv(nd):
                for fwd in (True, False):
                    res[fwd][1] += 1
                    res[fwd][0] += go(s, i, fwd, dist, [3000])
    return {('fwd' if f else 'back'): '%d of %d' % (a, b) for f, (a, b) in res.items()}


def check(new, old, rows):
    """static check on the written (decoded) file against the previous one; asserts, returns the numbers"""
    import citygraph as C
    net, onet = T.net_of(new), T.net_of(old)
    n0, e0 = len(onet['secs']), len(onet['ent'])
    ns, es = net['secs'], net['ent']
    assert sorted(ns) == list(range(len(ns))) and len(ns) <= 128 and len(es) <= 255, (len(ns), len(es))
    # NFSU1 part byte-identical, except one slot byte of the anchor source
    diff = []
    for sid in range(n0):
        a, b = onet['secs'][sid], ns[sid]
        assert a['hdr'] == b['hdr'] and a['lst'] == b['lst'] and len(a['nodes']) == len(b['nodes'])
        for i, (x, y) in enumerate(zip(a['nodes'], b['nodes'])):
            if x != y:
                diff += [(sid, i, k, x[k], y[k]) for k in range(0x88) if x[k] != y[k]]
    assert len(diff) == 1 and diff[0][2] in (0x81, 0x82) and diff[0][3] == 0xff, diff
    assert es[:e0] == onet['ent']
    # every link resolves: slot -> entry -> source is this node, landing valid and drivable; twins both ways
    byfrom = {}
    for sid in range(n0, len(ns)):
        for i, nd in enumerate(ns[sid]['nodes']):
            assert nd[0x83] == sid and (struct.unpack_from('<I', nd, 0x84)[0] >> 20) & 0x1f == 31
            for k in (0x81, 0x82):
                if nd[k] != 0xff:
                    e = es[nd[k]]
                    assert (e[0xa], struct.unpack_from('<H', e, 6)[0]) == (sid, i), (sid, i)
                    byfrom[(sid, i)] = byfrom.get((sid, i), 0) + 1
    new_e = es[e0:]
    drv = lambda sid, i: struct.unpack_from('<I', ns[sid]['nodes'][i], 0x84)[0] & (FWD_BITS | BACK_BITS)
    owners = collections.Counter()
    for k, e in enumerate(es):
        dn, sn = struct.unpack_from('<HH', e, 4)
        ds, ss = e[9], e[0xa]
        assert ds in ns and ss in ns and dn < len(ns[ds]['nodes']) and sn < len(ns[ss]['nodes'])
        if k >= e0:
            assert drv(ds, dn) and drv(ss, sn)
        nd = ns[ss]['nodes'][sn]
        owners[k] += (nd[0x81] == k) + (nd[0x82] == k)
    assert all(owners[k] == 1 for k in range(len(es))), 'an entry is not named by exactly one slot'
    pairs = collections.Counter()
    for e in new_e:
        dn, sn = struct.unpack_from('<HH', e, 4)
        pairs[(e[0xb], e[0xc], e[0xd])] += 1
    d0 = sum(1 for e in new_e if e[0xd] == 0)
    d1 = len(new_e) - d0
    bad = C.behind_entries([[nd for nd in ns[i]['nodes']] for i in range(len(ns))], es)
    assert not bad, bad[:5]
    # connector
    con = ns[n0]['nodes']
    xyz = [struct.unpack_from('<3f', nd, 0) for nd in con]
    ax = struct.unpack_from('<3f', ns[28]['nodes'][3], 0)
    assert math.dist(xyz[0][:2], ax[:2]) < 0.01 and abs(xyz[0][2] - ax[2]) < 0.01, 'connector does not start on the anchor'
    gaps = [math.dist(a[:2], b[:2]) for a, b in zip(xyz, xyz[1:])]
    assert max(gaps) <= SPACING + 0.01, max(gaps)
    ground = Ground(rows)
    land = [e for e in new_e if e[0xa] == n0 and e[0xd] == 0 and struct.unpack_from('<H', e, 6)[0] == len(con) - 1]
    assert len(land) == 1
    ldn, lds = struct.unpack_from('<H', land[0], 4)[0], land[0][9]
    lx = struct.unpack_from('<3f', ns[lds]['nodes'][ldn], 0)
    hop = math.dist(xyz[-1][:2], lx[:2])
    zmax, nsamp = 0.0, 0
    pts = list(xyz) + [lx]
    for a, b in zip(pts, pts[1:]):
        m = max(1, int(math.dist(a[:2], b[:2])))
        for j in range(m + 1):
            f = j / m
            x, y, z = (a[q] + f * (b[q] - a[q]) for q in range(3))
            g = ground.z(x, y, z)
            assert g is not None, 'no ground at %.1f %.1f' % (x, y)
            zmax = max(zmax, abs(g - z))
            nsamp += 1
    assert zmax < 2.0, zmax
    # UG2 nodes against the ground
    dz = []
    for sid in range(n0 + 1, len(ns)):
        for nd in ns[sid]['nodes']:
            x, y, z = struct.unpack_from('<3f', nd, 0)
            g = ground.z(x, y, z)
            if g is not None:
                dz.append(abs(g - z))
    secs_l = [[nd for nd in ns[i]['nodes']] for i in range(len(ns))]
    ws = walk(C, secs_l, es, range(n0, len(ns)))
    dr = [(sid, i) for sid in range(n0 + 1, len(ns)) for i, nd in enumerate(ns[sid]['nodes']) if struct.unpack_from('<I', nd, 0x84)[0] & (FWD_BITS | BACK_BITS)]
    noground = sum(ground.z(*struct.unpack_from('<3f', ns[a]['nodes'][b_], 0)[:2], struct.unpack_from('<f', ns[a]['nodes'][b_], 8)[0]) is None for a, b_ in dr)
    dd = [struct.unpack_from('<f', nd, 0x38)[0] for sid in range(n0, len(ns)) for nd in ns[sid]['nodes']]
    r = dict(sections=len(ns), entries=len(es), new_sections=len(ns) - n0, new_nodes=sum(len(ns[i]['nodes']) for i in range(n0, len(ns))), new_entries=len(new_e),
             d0=d0, d1=d1, types=dict(pairs), diff_bytes=diff, connector_nodes=len(con), connector_len=round(sum(gaps)), connector_max_gap=round(max(gaps), 2),
             last_hop=round(hop, 1), connector_z_max_dev=round(zmax, 3), z_samples=nsamp, ug2_nodes_with_ground=len(dz), ug2_dz_max=round(max(dz), 2),
             ug2_dz_within_2=round(sum(v < 2 for v in dz) / len(dz), 4), d_range=(round(min(dd), 1), round(max(dd), 1)), walk250_new_nodes=ws, ug2_drivable_nodes=len(dr), ug2_drivable_without_ground=noground)
    return r


if __name__ == '__main__':
    import q_owcoll2_lzc as lzc
    import q_owcoll2_sim as sim
    new = lzc.exe_decode(open(os.path.join(REPO, 'build', 'openworld', 'TRACKB1010.lzc'), 'rb').read())
    old = lzc.exe_decode(open(os.path.join(REPO, 'build', 'openworld', 'TRACKB1010.prev.lzc'), 'rb').read())
    wd = sim.World(new)
    rows = [bytes(new[wd.wsrc + 32 * i:wd.wsrc + 32 * i + 32]) for i in range(wd.n_wsrc)]
    print(check(new, old, rows))
