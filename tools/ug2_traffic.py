#!/usr/bin/env python3
"""NFSU1 WORLD traffic data: deduplicated UG2 trails plus the bridge connector.

UG2 0x34121/0x34122 -> corridor dedupe -> native junction graph -> connected
edge-disjoint trail partition -> unchanged NFSU1 chunk writer and checker.
Limits and the complete named consumer path: census/names_roadid.tsv and
docs/re/roadid.md (0x442bb2 signed node count, 0x4564b0 two slots,
0x443123 EBASE, 0x458c29/0x458cf0/0x458c95 11-bit entry cache).
Original NFSU1 nodes retain all bytes except their remapped entry slots.
Run: python tools/ug2_collfile.py; check: python tools/ug2_traffic.py --check.
"""
import collections, heapq, math, os, statistics, struct, sys
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

DUP_R = 3.0                   # citygraph.dedupe corridor radius; also separate stacked roads by height
MAX_SEC, MAX_ENT, RETAIL_ENT = 254, 2047, 255   # section ids are bytes (255 = none, widened table 0x796000), entries 11 bits (patches_road.py)
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
# lane speed in m/s = byte [node + 0x6a + lane] (0x5a7690 reads it at 0x5a76d2, docs/re/ai_traffic_speed.md), NOT a width. The template node's 11 / 17 bytes are 6:
# a slow driver did 3.5 m/s and a convoy formed behind it (TRAFUG2 run 2026-11-11). 20 = the most common value of lanes 11 and 17 on the anchor section 28 (55 / 38 of 360 nodes)
LANE_SPEED = 20


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
    def __init__(self, rows, box=(-3500, -1200, 1900, 4000)):     # the connector and the whole UG2 city in NFSU1 space (x -3360..1834, y -1079..3878)
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


def select(g, budget):
    """Partition the deduplicated centreline into edge-disjoint trails.

    Corridor dedupe follows citygraph.dedupe (3m, |cos|>.85), retaining
    elevation to keep stacked roads apart. Native 0x34122 links supply junctions;
    proximity alone never joins crossing roads. Degree-2 chains are the units
    of pruning: discard the cheapest odd-to-odd chain which keeps bridge reachability
    until the trail lower bound (odd vertices / 2) fits the byte section budget.
    """
    from citygraph import SegGrid
    grid, runs, heights = SegGrid(), [], []

    def covered(n):
        p, h = (n['x'], n['y']), n['t']
        cx, cy = int(p[0] // 20), int(p[1] // 20)  # citygraph.CELL
        for k in {k for dx in (-1, 0, 1) for dy in (-1, 0, 1) for k in grid.g.get((cx + dx, cy + dy), ())}:
            a, b = grid.segs[k]
            vx, vy = b[0] - a[0], b[1] - a[1]
            l2 = vx * vx + vy * vy
            if not l2 or abs(vx * h[0] + vy * h[1]) < .85 * math.sqrt(l2):
                continue
            t = max(0., min(1., ((p[0] - a[0]) * vx + (p[1] - a[1]) * vy) / l2))
            za, zb = heights[k]
            if math.hypot(p[0] - a[0] - t * vx, p[1] - a[1] - t * vy) < DUP_R and abs(n['z'] - za - t * (zb - za)) < DUP_R:
                return True
        return False
    drive = lambda n: bool(n['fl'] & sum(1 << a for a, _ in MAP_BITS))
    # Keep the established citygraph longest-first corridor representative.
    for s in sorted(g['sections'], key=lambda s: (-len(s['nodes']), s['id'])):
        ns = s['nodes']
        xy = [(n['x'], n['y']) for n in ns]
        flags = [drive(n) and not covered(n) for n in ns]
        for width in (1, 2):  # citygraph.dedupe closes <=2-node holes, only inside drivable road
            for i in range(1, len(flags) - width):
                if flags[i - 1] and flags[i + width] and all(drive(n) for n in ns[i:i + width]):
                    flags[i:i + width] = [True] * width
        i = 0
        while i < len(flags):
            if not flags[i]:
                i += 1
                continue
            j = i
            while j < len(flags) and flags[j]:
                j += 1
            if j - i >= 2:
                runs.append([(s['id'], k, ns[k]) for k in range(i, j)])
                for k in range(i, j - 1):
                    grid.add(xy[k], xy[k + 1])
                    heights.append((ns[k]['z'], ns[k + 1]['z']))
            i = j
    points, parent, refs, segs, owners = [], [], {}, [], []
    cells, cuts = collections.defaultdict(list), collections.defaultdict(list)

    def new(p, owner):
        k = len(points)
        points.append(p)
        owners.append(owner)
        parent.append(k)
        return k

    def root(k):
        while parent[k] != k:
            parent[k] = parent[parent[k]]
            k = parent[k]
        return k

    def union(a, b):
        a, b = root(a), root(b)
        parent[max(a, b)] = min(a, b)

    for ri, run in enumerate(runs):
        ids = []
        for sid, i, n in run:
            ids.append(new(tuple(n[c] for c in ('x', 'y', 'z')), ri))
            refs[sid, i] = ids[-1]
        for a, b in zip(ids, ids[1:]):
            k = len(segs)
            segs.append((a, b))
            p, q = points[a], points[b]
            for cx in range(int(min(p[0], q[0]) // MAX_HOP), int(max(p[0], q[0]) // MAX_HOP) + 1):
                for cy in range(int(min(p[1], q[1]) // MAX_HOP), int(max(p[1], q[1]) // MAX_HOP) + 1):
                    cells[cx, cy].append(k)

    def nearest(n):
        p, h = tuple(n[c] for c in ('x', 'y', 'z')), n['t']
        cx, cy = int(p[0] // MAX_HOP), int(p[1] // MAX_HOP)
        best = None
        for k in sorted({k for dx in (-1, 0, 1) for dy in (-1, 0, 1) for k in cells.get((cx + dx, cy + dy), ())}):
            a, b = (points[v] for v in segs[k])
            v = tuple(b[i] - a[i] for i in range(3))
            l2 = v[0] ** 2 + v[1] ** 2
            if not l2 or abs(v[0] * h[0] + v[1] * h[1]) < .85 * math.sqrt(l2):
                continue
            t = max(0., min(1., sum((p[i] - a[i]) * v[i] for i in range(2)) / l2))
            q = tuple(a[i] + t * v[i] for i in range(3))
            d = math.dist(p[:2], q[:2])
            if d <= MAX_HOP and abs(q[2] - p[2]) < DUP_R and (best is None or (d, k) < best[:2]):
                best = d, k, t, q
        if best is None:
            return None
        _, k, t, q = best
        a, b = segs[k]
        if t == 0:
            return a
        if t == 1:
            return b
        v = new(q, owners[a])
        cuts[k].append((t, v))
        return v

    for s in g['sections']:
        for i, n in enumerate(s['nodes']):
            if (s['id'], i) not in refs:
                v = nearest(n)
                if v is not None:
                    refs[s['id'], i] = v
    joins = []
    # A flagless margin can still carry a native entry. Keep its source path
    # to the mapped corridor instead of deleting that junction from the graph.
    for source in g['sections']:
        absent = set()
        for i, n in enumerate(source['nodes']):
            if (source['id'], i) not in refs:
                absent.add(i)
                refs[source['id'], i] = new(tuple(n[c] for c in ('x', 'y', 'z')), ('margin', source['id']))
        for i in range(len(source['nodes']) - 1):
            if i in absent or i + 1 in absent:
                joins.append((refs[source['id'], i], refs[source['id'], i + 1]))
    for run in runs:
        for (sid, i, _), step in ((run[0], -1), (run[-1], 1)):
            a, b = refs[sid, i], refs.get((sid, i + step))
            if b is not None and owners[a] != owners[b] and math.dist(points[a], points[b]) <= MAX_HOP:
                if math.dist(points[a], points[b]) < DUP_R:
                    union(a, b)
                else:
                    joins.append((a, b))
    missing = 0
    for e in g['entries']:
        a, b = refs.get((e['ss'], e['sn'])), refs.get((e['ds'], e['dn']))
        if a is None or b is None:
            missing += 1
        elif owners[a] == owners[b]:
            continue  # deduplicated overlap already follows the same chain
        elif math.dist(points[a], points[b]) <= MAX_HOP:
            union(a, b)
        else:
            joins.append((a, b))
    raw_edges = []
    for k, (a, b) in enumerate(segs):
        cc = sorted([(0., a), (1., b)] + cuts[k])
        for (ta, u), (tb, v) in zip(cc, cc[1:]):
            # Two float32 ULPs at the WORLD coordinate bound (4096m).
            # Repeated projections at one cut must be ONE junction node.
            if (tb - ta) * math.dist(points[a], points[b]) <= 1 / 1024:
                union(u, v)
            else:
                raw_edges.append((u, v, True))
    raw_edges += [(a, b, False) for a, b in joins]
    edges, seen = [], set()
    for a, b, unique in raw_edges:
        u, v = root(a), root(b)
        # Keep original geometry: contracting a junction must never move a road.
        pa, pb = points[a], points[b]
        key = tuple(sorted((pa, pb)))
        if key in seen or math.dist(pa[:2], pb[:2]) < 1e-6:
            continue
        seen.add(key)
        edges.append((u, v, pa, pb, math.dist(pa[:2], pb[:2]), unique))
    # The corridor split can fall between two covered samples. Reconnect those
    # components through the ORIGINAL consecutive source nodes, not a proximity
    # guess. Only a spanning set is needed; internal junctions came from entries.
    connected = list(range(len(points)))

    def comp(k):
        while connected[k] != k:
            connected[k] = connected[connected[k]]
            k = connected[k]
        return k

    for a, b, *_ in edges:
        connected[comp(a)] = comp(b)
    continuity = []
    for source in g['sections']:
        for i in range(len(source['nodes']) - 1):
            a, b = refs[source['id'], i], refs[source['id'], i + 1]
            u, v = root(a), root(b)
            if comp(u) != comp(v):
                continuity.append((math.dist(points[a], points[b]), u, v, a, b))
    for _, u, v, a, b in sorted(continuity):
        if comp(u) != comp(v):
            connected[comp(u)] = comp(v)
            edges.append((u, v, points[a], points[b], math.dist(points[a][:2], points[b][:2]), False))
    adj = collections.defaultdict(set)
    for k, (a, b, *_) in enumerate(edges):
        adj[a].add(k)
        adj[b].add(k)
    bridge = root(refs[230, 24])

    def component(active):
        seen, todo = {bridge}, [bridge]
        while todo:
            u = todo.pop()
            for k in adj[u] & active:
                a, b = edges[k][:2]
                v = b if a == u else a
                if v not in seen:
                    seen.add(v)
                    todo.append(v)
        return {k for u in seen for k in adj[u] & active}

    active = component({k for k, e in enumerate(edges) if e[0] != e[1]})
    # A native junction contracts its internal approach segments. Traversing a
    # contracted self-edge as a road would create a centre->arm->centre U-turn.
    # These segments stay in the denominator, never claimed as road coverage.
    total = sum(e[4] for e in edges if e[5])
    initial = len(active)

    def degrees():
        d = collections.Counter()
        for k in active:
            a, b = edges[k][:2]
            d[a] += 1
            d[b] += 1
        return d

    full_odd = sum(v % 2 for v in degrees().values())
    # Preserve a connected footprint over the whole city, then trim the shortest
    # redundant branches. A whole-source-section budget biases toward the bridge disc.
    while True:
        deg = degrees()
        odd = sum(v % 2 for v in deg.values())
        if odd <= 2 * budget:
            break
        candidates = []
        visited = set()
        for u in sorted(deg):
            if deg[u] == 2:
                continue
            for start in sorted(adj[u] & active):
                if start in visited:
                    continue
                path, v, k = [], u, start
                while True:
                    path.append(k)
                    visited.add(k)
                    a, b = edges[k][:2]
                    v = b if a == v else a
                    if deg[v] != 2:
                        break
                    nxt = (adj[v] & active) - {k}
                    if not nxt:
                        break
                    k = min(nxt)
                new_odd = odd + (1 if deg[u] % 2 == 0 else -1) + (1 if deg[v] % 2 == 0 else -1)
                if u != v and new_odd < odd:
                    candidates.append((sum(edges[k][4] for k in path), tuple(path)))
        removed = False
        for _, path in sorted(candidates):
            trial = active - set(path)
            reached = component(trial)
            if reached == trial:
                active = trial
                removed = True
                break
        if not removed:
            # General odd-to-odd shortest path, including even-degree junctions.
            best = None
            for u in sorted(v for v in deg if deg[v] % 2):
                pq, dist = [(0., u, ())], {u: 0.}
                while pq:
                    d, v, path = heapq.heappop(pq)
                    if d != dist[v] or (best and d >= best[0]):
                        continue
                    if v != u and deg[v] % 2:
                        trial = active - set(path)
                        if component(trial) == trial:
                            best = d, path
                            break
                    for k in sorted(adj[v] & active):
                        a, b = edges[k][:2]
                        w = b if a == v else a
                        nd = d + edges[k][4]
                        if nd < dist.get(w, math.inf):
                            dist[w] = nd
                            heapq.heappush(pq, (nd, w, path + (k,)))
            assert best is not None, 'no connected partition inside section budget'
            active -= set(best[1])
    # Euler decomposition with an artificial hub at odd vertices attains odd/2
    # trails. Artificial edges are removed; they never become road geometry.
    deg = degrees()
    ea = {u: list(sorted(adj[u] & active)) for u in deg}
    hub = -1
    ee = {k: edges[k][:2] for k in active}
    for u in sorted(deg):
        if deg[u] % 2:
            k = len(edges) + len(ee)
            ee[k] = u, hub
            ea[u].append(k)
            ea.setdefault(hub, []).append(k)
    start = hub if hub in ea else bridge
    stack, circuit, used = [(start, None)], [], set()
    while stack:
        u, _ = stack[-1]
        while ea[u] and ea[u][-1] in used:
            ea[u].pop()
        if not ea[u]:
            circuit.append(stack.pop())
            continue
        k = ea[u].pop()
        used.add(k)
        a, b = ee[k]
        stack.append((b if u == a else a, (k, u)))
    trails, trail = [], []
    for _, step in reversed(circuit):
        if step is None:
            continue
        k, u = step
        if k not in active:
            if trail:
                trails.append(trail)
                trail = []
        else:
            trail.append((k, u))
    if trail:
        trails.append(trail)
    assert len(trails) <= budget and sum(map(len, trails)) == len(active)
    # Orient the bridge's trail with the original UG2 230 tangent, preserving
    # the connector's two-way link without any writer or executable change.
    source = next(s for s in g['sections'] if s['id'] == 230)['nodes'][24]
    bp = tuple(source[c] for c in ('x', 'y', 'z'))
    best = min((min(math.dist(bp, e[2]), math.dist(bp, e[3])), ti, j)
               for ti, tr in enumerate(trails) for j, (k, _) in enumerate(tr) for e in [edges[k]])
    _, ti, j = best
    k, u = trails[ti][j]
    e = edges[k]
    pa, pb = (e[2], e[3]) if u == e[0] else (e[3], e[2])
    if (pb[0] - pa[0]) * source['t'][0] + (pb[1] - pa[1]) * source['t'][1] < 0:
        trails[ti] = [(k, ee[k][1] if u == ee[k][0] else ee[k][0]) for k, u in reversed(trails[ti])]
    select.stats = dict(unique_total_km=total / 1000,
                        unique_covered_km=sum(edges[k][4] for k in active if edges[k][5]) / 1000,
                        omitted_before_budget_edges=len(edges) - initial,
                        full_component_min_sections=max(1, full_odd // 2),
                        sections=len(trails), missing_source_entries=missing, contracted_junction_km=sum(e[4] for e in edges if e[0] == e[1] and e[5]) / 1000,
                        removed_edges=initial - len(active))
    return edges, trails, bridge, bp, {u: points[u] for u in deg}


def ug2_part(budget, entry_budget):
    """Long UG2 trails and junction pairs in the unchanged writer's key format."""
    g = R.load('A')
    edges, trails, bridge, bp, centres = select(g, budget)
    sections, visits = [], collections.defaultdict(lambda: [[], []])
    implicit = set()
    # Record inbound and outbound appearances of each physical junction. A
    # continuation inside a chain consumes no entry; every alternative does.
    for sid, trail in enumerate(trails):
        xyz, incoming, outgoing = [], [], []

        def append(p):
            if not xyz:
                xyz.append(p)
                return
            last = xyz[-1]
            n = max(1, math.ceil(math.dist(last[:2], p[:2]) / SPACING))
            if math.dist(last, p) > 1e-6:
                xyz.extend(tuple(last[c] + (p[c] - last[c]) * j / n for c in range(3)) for j in range(1, n + 1))

        for k, u in trail:
            a, b, pa, pb, _, _ = edges[k]
            if u != a:
                a, b, pa, pb = b, a, pb, pa
            append(centres[a])
            if incoming:
                implicit.add(((sid, incoming[-1][1]), (sid, len(xyz) - 1)))
            outgoing.append((a, len(xyz) - 1))
            append(pa)
            append(pb)
            append(centres[b])
            incoming.append((b, len(xyz) - 1))
        for v, i in incoming:
            visits[v][0].append((sid, i))
        for v, i in outgoing:
            visits[v][1].append((sid, i))
        nodes = []
        for i, p in enumerate(xyz):
            q, r = xyz[max(0, i - 1)], xyz[min(len(xyz) - 1, i + 1)]
            hx, hy = r[0] - q[0], r[1] - q[1]
            l = math.hypot(hx, hy) or 1.
            x, y, z = R.to_nfsu1(*p)
            nodes.append(dict(x=x, y=y, z=z, h=(hy / l, -hx / l), fl=FWD_BITS | BACK_BITS))
        assert len(nodes) <= 32767, (sid, len(nodes))  # signed count, 0x442bb2
        sections.append(dict(uid=sid, nodes=nodes))
    pairs, seen = [], set()
    junctions = 0
    for v, (ins, outs) in sorted(visits.items()):
        local = 0
        for a in ins:
            for b in outs:
                if (a, b) in implicit:
                    continue  # this visit continues along the chain
                key = tuple(sorted((a, b)))
                if key not in seen:
                    seen.add(key)
                    pairs.append((a, b))
                    local += 1
        junctions += bool(local)
    # Locate the unchanged bridge landing geometrically, not by a removed UG2 id.
    lx, ly, lz = R.to_nfsu1(*bp)
    source = next(s for s in g['sections'] if s['id'] == 230)['nodes'][24]
    h = source['t'][1], -source['t'][0]
    _, sid, i = min((math.dist((n['x'], n['y'], n['z']), (lx, ly, lz)), s['uid'], i)
                    for s in sections for i, n in enumerate(s['nodes']) if sum(a * b for a, b in zip(n['h'], h)) > .85)
    sections[sid]['bridge_node'] = i
    usage = collections.Counter()

    def candidates(key, step):
        sid, start = key
        ns = sections[sid]['nodes']
        out, distance, previous = [], 0., None
        for j in range(start, len(ns) if step > 0 else -1, step):
            n = ns[j]
            if previous is not None:
                distance += math.dist((n['x'], n['y']), (previous['x'], previous['y']))
            if distance > MAX_HOP:
                break
            out.append(((sid, j), distance))
            previous = n
        return out

    def source(src, dst, direction):
        target = sections[dst[0]]['nodes'][dst[1]]
        for shift in range(MAX_SHIFT + 1):
            c = src[0], src[1] + (shift if direction else -shift)
            if not 0 <= c[1] < len(sections[c[0]]['nodes']) or c == dst or usage[c] >= 2:
                continue
            n = sections[c[0]]['nodes'][c[1]]
            dx, dy = target['x'] - n['x'], target['y'] - n['y']
            ahead = (dx * n['h'][0] + dy * n['h'][1]) * (-1 if direction else 1)
            if ahead > AHEAD and math.hypot(dx, dy) <= MAX_HOP:
                return c, shift
        return None

    def paired(a, b):
        choices = []
        for u, v in ((a, b), (b, a)):
            f = source(u, v, 0)
            if f is None:
                continue
            usage[f[0]] += 1
            r = source(v, u, 1)
            usage[f[0]] -= 1
            if r is not None:
                choices.append(((f[1] + r[1], u), f[0], r[0]))
        return min(choices) if choices else None

    pinned = []
    for a, b in pairs:
        options = []
        # The writer's exact four-point rule: forward source may move back,
        # reverse source forward, while BOTH original landings are retained.
        # Search nearby cut points before serialization, never drop a junction.
        for origin, destination in ((a, b), (b, a)):
            for ka, da in candidates(origin, -1):
                for kb, db in candidates(destination, 1):
                    choice = paired(ka, kb)
                    if choice is not None:
                        options.append((da + db, ka, kb, choice))
        assert options, ('junction has no two-way ahead landing', a, b)
        _, ka, kb, choice = min(options)
        usage[choice[1]] += 1
        usage[choice[2]] += 1
        pinned.append((ka, kb))
    pairs = pinned
    per_section = collections.Counter()
    for (sid, _), count in usage.items():
        per_section[sid] += count
    assert max(per_section.values(), default=0) < 255
    assert 2 * len(pairs) <= entry_budget, ('STOP: global entry cap; no executable patch', 2 * len(pairs), entry_budget)
    select.stats.update(junctions=junctions, junction_pairs=len(pairs),
                        planned_global_entries=MAX_ENT - entry_budget + 2 * len(pairs))
    print('UG2 partition:', select.stats, flush=True)
    return sections, pairs


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
    # straight on west to one SPACING short of 80:24 = UG2 230:24 (74.4, 599.1): with the end at 109.6 the 35 m hop let eastbound cars aim from 80:24 straight at node 36
    # and stop on the bridge's west wall end (114.6, 589); RN_SPAWN=116:555 run 2026-11-11, TRAFUG2 log: one car parked at 113,592 heading -35, a queue behind it
    pts.append((74.4 + SPACING, y_end))
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
    ug, pairs = ug2_part(MAX_SEC - n0 - 1, MAX_ENT - e0 - 4)
    ground = Ground(rows)
    ax, ay, az = struct.unpack_from('<3f', node(*ANCHOR), 0)
    con = connector(ground, (ax, ay, az))
    CID = n0
    sec_of = {s_['uid']: n0 + 1 + k for k, s_ in enumerate(ug)}          # partition id -> NFSU1 id
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
    assert not dropped and all(l[5] is not None for l in links), ('junctions lost', len(dropped), sum(l[5] is None for l in links), dropped[:8])
    # the two connector links, first the anchor (NFSU1 28:3 -> connector 0), then the geometric bridge landing in the new partition
    land = next((sec_of[s['uid']], s['bridge_node']) for s in ug if 'bridge_node' in s)
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
    items = []                                 # (source node, entry bytes): the NFSU1 entries in node / slot order, then the new ones
    for sid in range(n0):
        for i in range(secs0[sid][2]):
            nd = node(sid, i)
            items += [((sid, i), ent0[nd[k]]) for k in (0x81, 0x82) if nd[k] != 0xff]
    assert len(items) == e0
    # the connector's two mid-section sources are forks, not the last way out of their section (citygraph.py:742-747 rule): NFSU1 28:2 (28 runs on to
    # 28:359) and UG2 230:24 (230 runs on east). Type 2 is always taken (0x462840) and at a bit-25 node at once (0x456553), so 2/2 there sent every
    # car on 28 southbound onto the bridge (TRAFUG2 5 min run 2026-11-11: 0 cars on 28 south of the junction). The connector's own ends stay 2/2.
    fork = {(len(links) - 2, 0), (len(links) - 1, 1)}
    for k, (u, v, ty, lane, s0, s1) in enumerate(links):
        for src, dst, d in ((s0, v, 0), (s1, u, 1)):
            if src is None:
                continue
            e = bytearray(32)
            struct.pack_into('<fHH', e, 0, 0.0, dst[1], src[1])
            t = (0, 7) if (k, d) in fork else (ty, lane)
            e[8], e[9], e[0xa], e[0xb], e[0xc], e[0xd] = 0, dst[0], src[0], t[0], t[1], d
            struct.pack_into('<IiII', e, 0x10, 0, -1, 0, 0)
            items.append((src, bytes(e)))
    # Up to 255 entries a slot byte is the file index (the exe sorts and remaps at PostLoad). Above, PostLoad hook H (patches_road.py stage 3,
    # 0x443123 -> cave 0x797000) skips the sort: EBASE[s] = first entry whose source is s and a slot byte is the rank inside that run
    # (readers 0x4564bd, 0x5a53f8, 0x5a56ce, 0x5a6da9 -> caves E1..E4), so entries are grouped by source section (citygraph.city_chunks).
    assert len(items) <= MAX_ENT, len(items)
    wide = len(items) > RETAIL_ENT
    if wide:
        items.sort(key=lambda it: it[0])       # stable: a node keeps its slot order
    ent, slot, rank = [], collections.defaultdict(list), collections.Counter()
    for src, e in items:
        slot[src].append(rank[src[0]] if wide else len(ent))
        rank[src[0]] += 1
        ent.append(e)
    assert max(max(v) for v in slot.values()) < 0xff and all(len(v) <= 2 for v in slot.values())
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
        for kk in LANES:
            nd[0x6a + kk] = LANE_SPEED
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
    # ---- the NFSU1 slot bytes (new indexes or ranks; the anchor source gets its link), assemble the chunks
    p21 = bytearray(base[b:b + s])
    for sid in range(n0):
        for i in range(secs0[sid][2]):
            o = secs0[sid][1] - b + 0x27c + i * 0x88
            v = slot.get((sid, i), [])
            p21[o + 0x81], p21[o + 0x82] = (v + [0xff, 0xff])[:2]
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
    print('traffic net: %d sections (+%d), %d entries (+%d, %s path), %d links, dropped pairs %d, chunk 0x34121 %d -> %d B' % (
        n0 + 1 + len(ug), 1 + len(ug), len(ent), len(ent) - e0, 'wide' if wide else 'retail', len(links), len(dropped), s, len(p21)))
    return bytes(out)


def slot_index(ent):
    """node, slot offset -> entry index, read the way the exe does: the file index up to 255 entries, else EBASE[node +0x83] + byte
    (EBASE[s] = the first entry whose source is s: PostLoad hook H, patches_road.py stage 3)"""
    first = {}
    for i, e in enumerate(ent):
        first.setdefault(e[0xa], i)
    wide = len(ent) > RETAIL_ENT
    return lambda nd, k: first[nd[0x83]] + nd[k] if wide else nd[k]


def walk(C, secs, ent, which, dist=250.0):
    """citygraph.walk_stats (the teleporter walk 0x4563d0, any path) started only from the drivable nodes of the sections in `which`"""
    ix = slot_index(ent)
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
                e = ent[ix(nd, k)]
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
    assert sorted(ns) == list(range(len(ns))) and len(ns) <= MAX_SEC and len(es) <= MAX_ENT, (len(ns), len(es))
    ix, oix = slot_index(es), slot_index(onet['ent'])
    # NFSU1 part: byte-identical but for the slot bytes; every NFSU1 node names the same entries as before, the anchor source one more (-> connector)
    added = []
    for sid in range(n0):
        a, b = onet['secs'][sid], ns[sid]
        assert a['hdr'] == b['hdr'] and a['lst'] == b['lst'] and len(a['nodes']) == len(b['nodes'])
        for i, (x, y) in enumerate(zip(a['nodes'], b['nodes'])):
            assert x[:0x81] == y[:0x81] and x[0x83:] == y[0x83:], (sid, i)
            was = [onet['ent'][oix(x, k)] for k in (0x81, 0x82) if x[k] != 0xff]
            now = [es[ix(y, k)] for k in (0x81, 0x82) if y[k] != 0xff]
            if was != now:
                assert now[:len(was)] == was and len(now) == len(was) + 1 and now[-1][9] == n0, (sid, i)
                added.append((sid, i))
    assert len(added) == 1, added
    diff = added
    # every link resolves: slot -> entry -> source is this node, landing valid and drivable; twins both ways
    for sid in range(n0, len(ns)):
        for i, nd in enumerate(ns[sid]['nodes']):
            assert nd[0x83] == sid and (struct.unpack_from('<I', nd, 0x84)[0] >> 20) & 0x1f == 31
            for k in (0x81, 0x82):
                if nd[k] != 0xff:
                    e = es[ix(nd, k)]
                    assert (e[0xa], struct.unpack_from('<H', e, 6)[0]) == (sid, i), (sid, i)
    new_e = [e for e in es if e[9] >= n0 or e[0xa] >= n0]
    assert len(es) - len(new_e) == e0
    drv = lambda sid, i: struct.unpack_from('<I', ns[sid]['nodes'][i], 0x84)[0] & (FWD_BITS | BACK_BITS)
    owners = collections.Counter()
    for sid in ns:
        for nd in ns[sid]['nodes']:
            for k in (0x81, 0x82):
                if nd[k] != 0xff:
                    owners[ix(nd, k)] += 1
    for k, e in enumerate(es):
        dn, sn = struct.unpack_from('<HH', e, 4)
        ds, ss = e[9], e[0xa]
        assert ds in ns and ss in ns and dn < len(ns[ds]['nodes']) and sn < len(ns[ss]['nodes'])
        if ds >= n0 or ss >= n0:
            assert drv(ds, dn) and drv(ss, sn)
    assert all(owners[k] == 1 for k in range(len(es))) and len(owners) == len(es), 'an entry is not named by exactly one slot'
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
    scc = C.scc_of_file(secs_l, es)
    dr = [(sid, i) for sid in range(n0 + 1, len(ns)) for i, nd in enumerate(ns[sid]['nodes']) if struct.unpack_from('<I', nd, 0x84)[0] & (FWD_BITS | BACK_BITS)]
    noground = sum(ground.z(*struct.unpack_from('<3f', ns[a]['nodes'][b_], 0)[:2], struct.unpack_from('<f', ns[a]['nodes'][b_], 8)[0]) is None for a, b_ in dr)
    dd = [struct.unpack_from('<f', nd, 0x38)[0] for sid in range(n0, len(ns)) for nd in ns[sid]['nodes']]
    r = dict(sections=len(ns), entries=len(es), new_sections=len(ns) - n0, new_nodes=sum(len(ns[i]['nodes']) for i in range(n0, len(ns))), new_entries=len(new_e),
             d0=d0, d1=d1, types=dict(pairs), anchor_node=diff, scc_nodes='%d of %d' % scc, connector_nodes=len(con), connector_len=round(sum(gaps)), connector_max_gap=round(max(gaps), 2),
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
