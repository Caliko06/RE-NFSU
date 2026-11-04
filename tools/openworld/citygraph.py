#!/usr/bin/env python3
"""citygraph.py: how many road sections / junction entries a whole-city road graph needs (docs/openworld/re_citygraph.md).

Question: can traffic and rivals drive on EVERY street of the WORLD city (track 1010), not only the 42 km tour? The exe takes
at most 128 road sections (table @0x77af30) and 255 link entries (1-byte index). The 16 street tracks hold 331 list-0
sections (24,909 nodes). The same street shows up in many tracks, so:

  1. DEDUPE. A section node is "covered" when an already accepted road (longest sections first) passes within R metres of it
     with the same heading (directed mode) or either heading (undirected mode: the exe walks a section in both directions,
     entry byte +0xd = direction, sub_458bd0). The uncovered nodes of one section form RUNS (gaps <= 2 nodes are closed, runs
     <= 2 nodes dropped).
  2. MERGE CHAINS. Two runs where one ends and the other starts with nothing else around (one successor candidate each way,
     <= 14 m, same heading) are joined into one long section, until no join is left.
  3. LINKS (junction entries). A link u -> v leaves node u for node v of another section. Sources: (a) run ends and run starts
     that continue into / come from a master node within 14 m, (b) the tracks' own links (every type except 3, the node marker)
     mapped onto the master nodes. Links on the same pair of sections within 3 nodes of each other count once. A link is
     written as 2 entries (forward d=0 on the source, reverse d=1 on the target), like tools/openworld/tour.py does.
  4. SLOTS. A node has 2 link bytes (+0x81/+0x82); every entry sits on one node. Nodes that would need more than 2 are counted.

Reuses tour.py's readers (read_net) and its hop rule (14 m, cos > 0.92, not behind). Nothing is written.
usage: citygraph.py --stats [--radius R]      (default R = 3 m; prints directed and undirected, then a radius sweep)
       citygraph.py --write [--radius R]      (undirected, default R = 10 m: build/openworld_city/TRACKB1010.lzc; the TrackPath is the tour's)
       citygraph.py --slow <TRACKB.lzc>      (only the junction speed caps of --write, in place on a written file)
--noflags counts the flagless section margins as road (the first measurement); the default drops them (node+0x84 drive flags).
"""
import collections, itertools, json, math, os, random, struct, sys, time
HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import tour as T  # noqa: E402  (read_net; also puts tools/hopper and ref/tools on the path)

HOP_R, HOP_COS, BEHIND = T.HOP_R, T.HOP_COS, -2.0
MAX_SEC, MAX_ENT = 254, 2047                     # patches.py "WIDEN the road graph": section ids are bytes (255 = none), entry indexes 11 bits
RETAIL_ENT = 255                                 # up to here a node's slot byte is the global entry index (the exe sorts and remaps it)
CELL = 20.0
_NETS = {}


FWD_BITS = (1 << 6) | (1 << 25) | (1 << 27)       # node+0x84: forward drive flags, tested by the walker 0x4563d0 (0x4424d0)
BACK_BITS = (1 << 19) | (1 << 26) | (1 << 28)     # backward (0x442520); equal to the forward set on every street node
USE_FLAGS = '--noflags' not in sys.argv           # False = the first measurement (flagless margins counted as road)
DRV = {}


def nets():
    if not _NETS:
        for t in T.TR:
            _NETS[t] = T.read_net(t)
    return _NETS


def sections():
    """[(track, sid, [(x, y)], [(hx, hy)])] of every list 0 section, longest first (list 1 = traffic stubs, never roads)"""
    out = []
    for t, n in nets().items():
        for sid, s in n['secs'].items():
            if s['lst'] != 0 or len(s['nodes']) < 2:
                continue
            xy = [struct.unpack_from('<2f', nd, 0) for nd in s['nodes']]
            DRV[(t, sid)] = [not USE_FLAGS or bool(struct.unpack_from('<I', nd, 0x84)[0] & (FWD_BITS | BACK_BITS)) for nd in s['nodes']]
            hd = []
            for i in range(len(xy)):
                a, b = xy[min(i + 1, len(xy) - 1)], xy[max(i - 1, 0)]
                dx, dy = a[0] - b[0], a[1] - b[1]
                l = math.hypot(dx, dy) or 1.0
                hd.append((dx / l, dy / l))
            out.append((t, sid, xy, hd))
    out.sort(key=lambda s: (-len(s[2]), s[0], s[1]))
    return out


class SegGrid:
    def __init__(self):
        self.segs, self.g = [], collections.defaultdict(list)

    def add(self, a, b):
        i = len(self.segs)
        self.segs.append((a, b))
        for cx in range(int(min(a[0], b[0]) // CELL), int(max(a[0], b[0]) // CELL) + 1):
            for cy in range(int(min(a[1], b[1]) // CELL), int(max(a[1], b[1]) // CELL) + 1):
                self.g[(cx, cy)].append(i)

    def near(self, p, h):
        """(distance to the nearest same-heading segment, to the nearest opposite-heading one)"""
        cx, cy = int(p[0] // CELL), int(p[1] // CELL)
        same = opp = 1e9
        seen = set()
        for dx in (-1, 0, 1):
            for dy in (-1, 0, 1):
                for i in self.g.get((cx + dx, cy + dy), ()):
                    if i in seen:
                        continue
                    seen.add(i)
                    a, b = self.segs[i]
                    vx, vy = b[0] - a[0], b[1] - a[1]
                    l2 = vx * vx + vy * vy or 1e-9
                    u = max(0.0, min(1.0, ((p[0] - a[0]) * vx + (p[1] - a[1]) * vy) / l2))
                    d = math.hypot(p[0] - a[0] - u * vx, p[1] - a[1] - u * vy)
                    c = (vx * h[0] + vy * h[1]) / math.sqrt(l2)
                    if c > 0.85:
                        same = min(same, d)
                    elif c < -0.85:
                        opp = min(opp, d)
        return same, opp


def dedupe(secs, radius, undirected):
    """accepted[(t,sid)] = list of bool per node; runs = [[(t,sid,i)...]]"""
    grid, acc = SegGrid(), {}
    for t, sid, xy, hd in secs:
        flags = []
        for i, p in enumerate(xy):
            s, o = grid.near(p, hd[i])
            flags.append(DRV[(t, sid)][i] and not ((min(s, o) if undirected else s) < radius))
        n = len(flags)
        drv = DRV[(t, sid)]
        i = 0
        while i < n:                      # close covered gaps of <= 2 nodes between accepted nodes
            if not flags[i]:
                j = i
                while j < n and not flags[j]:
                    j += 1
                if 0 < i and j < n and j - i <= 2 and all(drv[i:j]):
                    for k in range(i, j):
                        flags[k] = True
                i = j
            else:
                i += 1
        i = 0
        while i < n:                      # drop accepted runs of <= 2 nodes
            if flags[i]:
                j = i
                while j < n and flags[j]:
                    j += 1
                if j - i <= 2:
                    for k in range(i, j):
                        flags[k] = False
                i = j
            else:
                i += 1
        acc[(t, sid)] = flags
        for i in range(n - 1):
            if flags[i] and flags[i + 1]:
                grid.add(xy[i], xy[i + 1])
    return acc


def build(radius=3.0, undirected=False):
    secs = sections()
    acc = dedupe(secs, radius, undirected)
    info = {(t, sid): (xy, hd) for t, sid, xy, hd in secs}
    runs, rid = [], {}                   # run = list of (t, sid, i); rid[(t,sid,i)] = (run index, position)
    total_nodes = sum(len(x[2]) for x in secs)
    for t, sid, xy, hd in secs:
        f, i = acc[(t, sid)], 0
        while i < len(f):
            if f[i]:
                j = i
                while j < len(f) and f[j]:
                    j += 1
                runs.append([(t, sid, k) for k in range(i, j)])
                i = j
            else:
                i += 1
    P = lambda n: info[(n[0], n[1])][0][n[2]]
    H = lambda n: info[(n[0], n[1])][1][n[2]]
    # grid of accepted nodes
    ng = collections.defaultdict(list)
    for r, run in enumerate(runs):
        for pos, n in enumerate(run):
            x, y = P(n)
            ng[(int(x // CELL), int(y // CELL))].append((r, pos))

    def cands(p, h, pred):
        out = []
        cx, cy = int(p[0] // CELL), int(p[1] // CELL)
        for dx in (-1, 0, 1):
            for dy in (-1, 0, 1):
                for r, pos in ng.get((cx + dx, cy + dy), ()):
                    out.append((r, pos))
        return out

    def succ(r, pos, hcos=HOP_COS, hr=HOP_R):
        """best node (run, pos) to go to from node pos of run r: another run, within HOP_R, same heading, ahead, not its last node"""
        n = runs[r][pos]
        p, h = P(n), H(n)
        best = None
        for r2, p2 in cands(p, h, None):
            if r2 == r or p2 + 1 >= len(runs[r2]):
                continue
            m = runs[r2][p2]
            q, g = P(m), H(m)
            ex, ey = q[0] - p[0], q[1] - p[1]
            d = math.hypot(ex, ey)
            if d > hr or g[0] * h[0] + g[1] * h[1] < hcos or ex * h[0] + ey * h[1] < BEHIND:
                continue
            if best is None or d < best[0]:
                best = (d, r2, p2)
        return best and best[1:]

    def pred(r, pos, hcos=HOP_COS, hr=HOP_R):
        n = runs[r][pos]
        p, h = P(n), H(n)
        best = None
        for r2, p2 in cands(p, h, None):
            if r2 == r:
                continue
            m = runs[r2][p2]
            q, g = P(m), H(m)
            ex, ey = p[0] - q[0], p[1] - q[1]
            d = math.hypot(ex, ey)
            if d > hr or g[0] * h[0] + g[1] * h[1] < hcos or ex * g[0] + ey * g[1] < BEHIND:
                continue
            if best is None or d < best[0]:
                best = (d, r2, p2)
        return best and best[1:]

    # 2. merge chains: run A's end goes to run B's start and B's start comes from A's end, both unique
    merged = True
    nmerge = 0
    while merged:
        merged = False
        for r in range(len(runs)):
            if not runs[r]:
                continue
            s = succ(r, len(runs[r]) - 1)
            if not s or s[1] != 0 or not runs[s[0]]:
                continue
            p = pred(s[0], 0)
            if p and p[0] == r and p[1] == len(runs[r]) - 1:
                b = s[0]
                runs[r] = runs[r] + runs[b]
                runs[b] = []
                nmerge += 1
                merged = True
                # rebuild the node grid for the changed runs
                ng.clear()
                for r3, run in enumerate(runs):
                    for pos3, n in enumerate(run):
                        x, y = P(n)
                        ng[(int(x // CELL), int(y // CELL))].append((r3, pos3))
                break
    runs = [r for r in runs if r]
    ng.clear()
    rid.clear()
    for r, run in enumerate(runs):
        for pos, n in enumerate(run):
            x, y = P(n)
            ng[(int(x // CELL), int(y // CELL))].append((r, pos))
            rid[n] = (r, pos)

    # 3. links
    links = {}

    def add_link(a, b, ty=2, lane=2):
        """ty/lane = entry bytes +0xb/+0xc: a continuation is type 2 (racers always take it) with lane 2 (traffic at bit-25 nodes);
        a fork keeps the track's own pair"""
        (ra, pa), (rb, pb) = a, b
        if ra == rb and 0 < pb - pa <= 1:
            return
        links.setdefault((ra, pa // 3, rb, pb // 3), (a, b, ty, lane))     # one link per pair of sections per 3-node window (~29 m)

    for r, run in enumerate(runs):                # (a) run ends / starts
        s = succ(r, len(run) - 1)
        if s:
            add_link((r, len(run) - 1), s)
        p = pred(r, 0)
        if p:
            add_link(p, (r, 0))

    def master(t, sid, i):
        """(run, pos, sign) of the accepted node that stands for this original node: itself, else the nearest accepted one within
        HOP_R; sign -1 = the master runs against the original (undirected mode only)"""
        if (t, sid, i) in rid:
            return rid[(t, sid, i)] + (1,)
        xy, hd = info[(t, sid)]
        p, h = xy[i], hd[i]
        best = None
        for r2, p2 in cands(p, h, None):
            m = runs[r2][p2]
            q, g = P(m), H(m)
            d = math.hypot(q[0] - p[0], q[1] - p[1])
            c = g[0] * h[0] + g[1] * h[1]
            if d > HOP_R or (c < 0.85 and not (undirected and c < -0.85)):
                continue
            if best is None or d < best[0]:
                best = (d, r2, p2, 1 if c > 0 else -1)
        return best and best[1:]

    nown = 0
    for t, n in nets().items():                   # (b) the tracks' own links
        for e in n['ent']:
            _, dn, sn, _, ds, ss, ty, lane, d = struct.unpack_from('<fHHBBBBBB', e, 0)
            if d != 0 or ty == 3 or (t, ss) not in info or (t, ds) not in info:
                continue
            if sn >= len(info[(t, ss)][0]) or dn >= len(info[(t, ds)][0]):
                continue
            a, b = master(t, ss, sn), master(t, ds, dn)
            if a and b and a[0] != b[0] and a[2] == b[2]:     # both along or both against the original; a mixed pair is head-on
                nown += 1
                if a[2] > 0:
                    add_link(a[:2], b[:2], ty, lane)
                else:
                    add_link(b[:2], a[:2], ty, lane)          # driven against the original, the junction is entered from b

    # relaxed links: a run end that has no continuation at the tour.py angle (cos 0.92) may still join a street at a turn (cos > 0.3,
    # 25 m): the original links are all cos >= 0.95, so these turns are NEW links with no example in the data
    relaxed = 0
    dead_end = dead_start = 0
    for r, run in enumerate(runs):
        if not succ(r, len(run) - 1):
            s2 = succ(r, len(run) - 1, 0.3, 25.0)
            if s2:
                relaxed += 1
                add_link((r, len(run) - 1), s2)
            else:
                dead_end += 1
        if not pred(r, 0):
            p2 = pred(r, 0, 0.3, 25.0)
            if p2:
                relaxed += 1
                add_link(p2, (r, 0))
            else:
                dead_start += 1
    # coverage by the master net, and the part of it the 42 km tour (build/openworld/tour1010.json) does not reach
    def near_master(p):
        cx, cy = int(p[0] // CELL), int(p[1] // CELL)
        return any(math.hypot(P(runs[r][q])[0] - p[0], P(runs[r][q])[1] - p[1]) < 12.0
                   for dx in (-1, 0, 1) for dy in (-1, 0, 1) for r, q in ng.get((cx + dx, cy + dy), ()))
    cov = sum(near_master(p) for t, sid, xy, hd in secs for p in xy[::5]) / sum(len(x[2][::5]) for x in secs)
    off_tour = None
    try:
        import json
        tm = json.load(open(os.path.join(HERE, '..', '..', 'build', 'openworld', 'tour1010.json')))['sections_map']
        tg = collections.defaultdict(list)
        for k in tm:
            t, sid = map(int, k.split(':'))
            for q in info[(t, sid)][0]:
                tg[(int(q[0] // CELL), int(q[1] // CELL))].append(q)
        def on_tour(p):
            cx, cy = int(p[0] // CELL), int(p[1] // CELL)
            return any(math.hypot(q[0] - p[0], q[1] - p[1]) < 12.0 for dx in (-1, 0, 1) for dy in (-1, 0, 1) for q in tg.get((cx + dx, cy + dy), ()))
        seg = [(P(r[i]), P(r[i + 1])) for r in runs for i in range(len(r) - 1)]
        off_tour = sum(math.hypot(a[0] - b[0], a[1] - b[1]) for a, b in seg if not on_tour(((a[0] + b[0]) / 2, (a[1] + b[1]) / 2))) / 1000
    except (OSError, KeyError):
        pass
    # 4. slots: entries per node window (the link sits on a node; shift to a neighbour within 3 nodes is allowed)
    load = collections.Counter()
    for ra, wa, rb, wb in links:
        load[(ra, wa)] += 1
        load[(rb, wb)] += 1
    over = sum(1 for v in load.values() if v > 6)      # > 2 slots per node x 3 nodes of the window
    kept = sum(len(r) for r in runs)
    lens = sorted(len(r) for r in runs)
    return dict(runs=runs, info=info, link_list=list(links.values()), nodes_total=total_nodes, nodes_kept=kept, sections_raw=len(secs), runs_before_merge=len(runs) + nmerge,
                sections=len(runs), merges=nmerge, links=len(links), entries=2 * len(links), entries_oneway_turns=2 * (len(links) - relaxed) + relaxed, own_links=nown,
                overloaded_windows=over, dead_end=dead_end, relaxed=relaxed, links_strict=len(links) - relaxed, dead_start=dead_start, coverage=cov, off_tour_km=off_tour, len_min=lens[0], len_med=lens[len(lens) // 2], len_max=lens[-1],
                km=sum(math.hypot(P(r[i])[0] - P(r[i + 1])[0], P(r[i])[1] - P(r[i + 1])[1]) for r in runs for i in range(len(r) - 1)) / 1000)


def fmt(name, r):
    fit = 'FITS' if r['sections'] <= MAX_SEC and r['entries'] <= MAX_ENT else 'fits only with turn links d=0 only' if r['sections'] <= MAX_SEC and r['entries_oneway_turns'] <= MAX_ENT else 'over: %d sections (%+d), %d entries (%+d)' % (
        r['sections'], r['sections'] - MAX_SEC, r['entries'], r['entries'] - MAX_ENT)
    print('%-22s sections %3d (before chain merge %3d)  links %3d -> entries %3d (%d if turn links are d=0 only)  nodes %5d of %5d  road %6.1f km  '
          'nodes/section min %d med %d max %d  slot-overloaded windows %d  (turn links %d) dead ends %d/starts %d  original road within 12 m of the net %.1f%%  net km off the tour %s  [%s]' % (
              name, r['sections'], r['runs_before_merge'], r['links'], r['entries'], r['entries_oneway_turns'], r['nodes_kept'], r['nodes_total'], r['km'],
              r['len_min'], r['len_med'], r['len_max'], r['overloaded_windows'], r['relaxed'], r['dead_end'], r['dead_start'], 100 * r['coverage'],
              '%.1f' % r['off_tour_km'] if r['off_tour_km'] is not None else '?', fit))


# ---- v2 planner: one-way walker (docs/openworld/re_citygraph.md "v2") -----------------------------------------------------
# A driver walks every section in ONE direction (d=0 entries forward, d=1 = the transposed graph backward), so the graph the
# walker sees is directed: node p -> p+1 of every section plus the links a -> b. Its strongly connected part is what a
# racer can drive for ever. v1 joined only straight continuations (SCC 446 of 3816). v2 (a) offers a link at any angle wherever
# two runs come within JUNCTION_D metres (cands), (b) orients every run (flip = write its nodes in reverse) and picks the
# links under the entry budget (<= MAX_ENT // 2 links) by simulated annealing on the size of the biggest strongly connected part.
JUNCTION_D = 30.0
LINK_BUDGET = MAX_ENT // 2
SA_FLIPS_S, SA_LINKS_S = 25.0, 90.0          # seconds of annealing (flips with every link on; flips + link swaps under the budget)


def junction_pairs(runs_xy, D):
    """[(r, p, r2, p2, d)]: per pair of runs, mutually close node pairs (<= D m), one per cluster (3 nodes on both runs)"""
    grid = collections.defaultdict(list)
    for r, xs in enumerate(runs_xy):
        for p, (x, y) in enumerate(xs):
            grid[(int(x // 25), int(y // 25))].append((r, p))
    cell = max(1, int(math.ceil(D / 25.0)))
    found = {}
    for r, xs in enumerate(runs_xy):
        for p, (x, y) in enumerate(xs):
            cx, cy = int(x // 25), int(y // 25)
            for dx in range(-cell, cell + 1):
                for dy in range(-cell, cell + 1):
                    for r2, p2 in grid.get((cx + dx, cy + dy), ()):
                        if r2 > r:
                            d = math.hypot(x - runs_xy[r2][p2][0], y - runs_xy[r2][p2][1])
                            if d <= D:
                                found.setdefault((r, r2), []).append((d, p, p2))
    out = []
    for (r, r2), lst in sorted(found.items()):
        taken = []
        for d, p, p2 in sorted(lst):
            if not any(abs(p - a) <= 3 and abs(p2 - b) <= 3 for a, b in taken):
                taken.append((p, p2))
                out.append((r, p, r2, p2, d))
    return out


def cond_scc(L, flip, links):
    """biggest strongly connected part of the walker's graph, counted in nodes. The graph is condensed to the link ends of each
    run (the nodes between two ends join the part when both ends do). links: [((r, p), (r2, p2))] in the runs' original order;
    flip[r] = run r is written reversed. Returns (nodes, component id of the biggest, component of every end, ends)"""
    pts = collections.defaultdict(set)
    ol = []
    for a, b in links:
        qa = (a[0], L[a[0]] - 1 - a[1] if flip[a[0]] else a[1])
        qb = (b[0], L[b[0]] - 1 - b[1] if flip[b[0]] else b[1])
        ol.append((qa, qb))
        pts[qa[0]].add(qa[1])
        pts[qb[0]].add(qb[1])
    idx, vs, adj, gap = {}, [], [], {}
    for r, ps in pts.items():
        prev = None
        for q in sorted(ps):
            i = len(vs)
            idx[(r, q)] = i
            vs.append((r, q))
            adj.append([])
            if prev is not None:
                adj[i - 1].append(i)
                gap[(i - 1, i)] = q - vs[i - 1][1] - 1
            prev = q
    for qa, qb in ol:
        adj[idx[qa]].append(idx[qb])
    n = len(vs)
    index, low, on, stack, comp, ncomp, t = [-1] * n, [0] * n, [False] * n, [], [-1] * n, 0, 0
    for s0 in range(n):                                   # Tarjan, iterative
        if index[s0] >= 0:
            continue
        work = [(s0, 0)]
        index[s0] = low[s0] = t
        t += 1
        stack.append(s0)
        on[s0] = True
        while work:
            v, i = work.pop()
            if i < len(adj[v]):
                work.append((v, i + 1))
                w = adj[v][i]
                if index[w] < 0:
                    index[w] = low[w] = t
                    t += 1
                    stack.append(w)
                    on[w] = True
                    work.append((w, 0))
                elif on[w]:
                    low[v] = min(low[v], index[w])
            else:
                if low[v] == index[v]:
                    while True:
                        w = stack.pop()
                        on[w] = False
                        comp[w] = ncomp
                        if w == v:
                            break
                    ncomp += 1
                if work:
                    u = work[-1][0]
                    low[u] = min(low[u], low[v])
    wt = [0] * ncomp
    for i in range(n):
        wt[comp[i]] += 1
    for (i, j), g_ in gap.items():
        if comp[i] == comp[j]:
            wt[comp[i]] += g_
    best = max(range(ncomp), key=lambda c: wt[c]) if ncomp else -1
    return (wt[best] if best >= 0 else 0), best, comp, vs


PLAN_AHEAD = 1.0                                   # planning margin over AHEAD: the written heading of a node is the track's own


def heading(xs, p, flip):
    """unit heading of node p (original index) of a run written reversed when flip"""
    n = len(xs)
    a, b = (p, p + 1) if not flip else (p, p - 1)
    if not 0 <= b < n:
        a, b = (p - 1, p) if not flip else (p + 1, p)
    dx, dy = xs[b][0] - xs[a][0], xs[b][1] - xs[a][1]
    l = math.hypot(dx, dy) or 1.0
    return dx / l, dy / l


def ahead_source(runs_xy, a, b, flip):
    """the source node for link a -> b on a run written reversed when flip: a itself or up to 3 nodes before it (in walk order)
    from which b lies > PLAN_AHEAD m ahead (the grower's rule, AHEAD); None when there is none (original index)"""
    (r, p), (r2, p2) = a, b
    xs, (tx, ty) = runs_xy[r], runs_xy[r2][p2]
    for k in range(4):
        q = p + k if flip else p - k
        if not 0 <= q < len(xs):
            break
        hx, hy = heading(xs, q, flip)
        if (tx - xs[q][0]) * hx + (ty - xs[q][1]) * hy > PLAN_AHEAD:
            return q
    return None


MAX_TURN = float(sys.argv[sys.argv.index('--maxturn') + 1]) if '--maxturn' in sys.argv else None   # degrees; off = the served net. On: plan_net refuses links this sharp in the walk direction (the tracks' own stay <= 45)


def link_turn(runs_xy, a, b, fa, fb):
    """degrees the walker turns on link a -> b, runs written reversed when fa / fb"""
    hx, hy = heading(runs_xy[a[0]], a[1], fa)
    kx, ky = heading(runs_xy[b[0]], b[1], fb)
    return math.degrees(math.acos(max(-1.0, min(1.0, hx * kx + hy * ky))))


def plan_net(runs_xy, D=JUNCTION_D, budget=LINK_BUDGET, flips_s=SA_FLIPS_S, links_s=SA_LINKS_S, seed=3):
    """(flip per run, [((r, p), (r2, p2))] directed links in original positions, nodes of the biggest SCC). Phase 1 anneals the
    orientation with every candidate link (both ways) on; the links that add nothing are dropped, the least useful ones one by one
    down to the budget; phase 2 anneals flips and link swaps together."""
    L = [len(x) for x in runs_xy]
    DL = []
    for r, p, r2, p2, d in junction_pairs(runs_xy, D):
        DL.append(((r, p), (r2, p2)))
        DL.append(((r2, p2), (r, p)))
    SRC = [{f: ahead_source(runs_xy, a, b, f) for f in (False, True)} for a, b in DL]
    rng = random.Random(seed)
    flip = [False] * len(L)
    keep = set(range(len(DL)))
    TURN = {(i, fa, fb): link_turn(runs_xy, (DL[i][0][0], SRC[i][fa]), DL[i][1], fa, fb) for i in range(len(DL)) for fa in (False, True) for fb in (False, True)
            if MAX_TURN is not None and SRC[i][fa] is not None}
    ok = lambda i: SRC[i][flip[DL[i][0][0]]] is not None and (MAX_TURN is None or TURN[i, flip[DL[i][0][0]], flip[DL[i][1][0]]] < MAX_TURN)
    real = lambda ks: [((DL[i][0][0], SRC[i][flip[DL[i][0][0]]]), DL[i][1]) for i in sorted(ks) if ok(i)]
    W = lambda: cond_scc(L, flip, real(keep))[0]
    cur = best = W()
    bf, t0 = flip[:], time.time()
    while time.time() - t0 < flips_s:
        temp = 60 * (1 - (time.time() - t0) / flips_s) + 1
        r = rng.randrange(len(L))
        flip[r] = not flip[r]
        s = W()
        if s >= cur or rng.random() < math.exp((s - cur) / temp):
            cur = s
        else:
            flip[r] = not flip[r]
        if cur > best:
            best, bf = cur, flip[:]
    flip = bf[:]
    cur = W()
    for i in rng.sample(sorted(keep), len(keep)):         # links that add nothing
        keep.discard(i)
        if W() < cur:
            keep.add(i)
    while len(keep) > budget:                             # the least useful one at a time
        bm = None
        for i in sorted(keep):
            keep.discard(i)
            w = W()
            keep.add(i)
            if bm is None or w > bm[0]:
                bm = (w, i)
        keep.discard(bm[1])
    cur = W()
    out, kl = [i for i in range(len(DL)) if i not in keep], sorted(keep)
    best, bst, t0 = cur, (flip[:], set(keep)), time.time()
    while time.time() - t0 < links_s:
        temp = 25 * (1 - (time.time() - t0) / links_s) + 0.5
        if rng.random() < 0.3:
            r = rng.randrange(len(L))
            flip[r] = not flip[r]
            s = W()
            if s >= cur or rng.random() < math.exp((s - cur) / temp):
                cur = s
            else:
                flip[r] = not flip[r]
        else:
            ai, bi = rng.randrange(len(kl)), rng.randrange(len(out))
            a, b = kl[ai], out[bi]
            keep.discard(a)
            keep.add(b)
            s = W()
            if s >= cur or rng.random() < math.exp((s - cur) / temp):
                cur, kl[ai], out[bi] = s, b, a
            else:
                keep.discard(b)
                keep.add(a)
        if cur > best:
            best, bst = cur, (flip[:], set(keep))
    flip, keep = bst[0], bst[1]
    links = real(keep)
    w, bc, comp, vs = cond_scc(L, flip, links)
    ends = {v for v, c in zip(vs, comp) if c == bc}     # (run, oriented position) of the link ends inside the SCC
    inside = lambda a: (a[0], L[a[0]] - 1 - a[1] if flip[a[0]] else a[1]) in ends
    links = [l for l in links if inside(l[0]) and inside(l[1])]    # a link that leaves the SCC only leads into a dead tail
    return flip, links, cond_scc(L, flip, links)[0]


def slot_entry(ent, nd, k):
    """the entry that node nd's slot byte nd[k] (0x81/0x82) names, the way the exe reads it: the file index up to 255 entries, else the rank
    inside the node's section (nd[0x83]) on top of the section's first entry"""
    if len(ent) <= RETAIL_ENT:
        return ent[nd[k]]
    return ent[next(i for i, e in enumerate(ent) if e[0xa] == nd[0x83]) + nd[k]]


def scc_of_file(secs, ent):
    """exact check on the written chunks: nodes of the biggest strongly connected part of 'next node + d=0 links'
    (the transposed walk of the d=1 entries has the same parts). secs = parse_net's nodes, ent = entries"""
    off = [0]
    for ns in secs:
        off.append(off[-1] + len(ns))
    N = off[-1]
    adj = [[] for _ in range(N)]
    radj = [[] for _ in range(N)]
    for s, ns in enumerate(secs):
        for i, nd in enumerate(ns):
            u = off[s] + i
            outs = [off[s] + i + 1] if i + 1 < len(ns) else []
            for k in (0x81, 0x82):
                if nd[k] != 0xff and slot_entry(ent, nd, k)[0xd] == 0 and slot_entry(ent, nd, k)[0xb] != 3:
                    e = slot_entry(ent, nd, k)
                    outs.append(off[e[9]] + struct.unpack_from('<H', e, 4)[0])
            for v in outs:
                adj[u].append(v)
                radj[v].append(u)
    seen, order = [False] * N, []
    for s0 in range(N):
        if seen[s0]:
            continue
        seen[s0] = True
        st = [(s0, 0)]
        while st:
            v, i = st.pop()
            if i < len(adj[v]):
                st.append((v, i + 1))
                w = adj[v][i]
                if not seen[w]:
                    seen[w] = True
                    st.append((w, 0))
            else:
                order.append(v)
    comp, best = [-1] * N, 0
    for s0 in reversed(order):
        if comp[s0] >= 0:
            continue
        comp[s0] = s0
        todo, cnt = [s0], 1
        while todo:
            for w in radj[todo.pop()]:
                if comp[w] < 0:
                    comp[w] = s0
                    cnt += 1
                    todo.append(w)
        best = max(best, cnt)
    return best, N



# ---- the writer: TRACKB1010 with the whole-city road net (build/openworld_city) ------------------------------------------
OUT_DIR = os.path.join(T.B.REPO, 'build', 'openworld_city')


def assign_slots(runs, link_list):
    """each link = 2 entries (forward d=0 on the source, reverse d=1 on the target); a node holds 2. A node that is full or
    would be landed on at a run end shifts by up to 2 nodes along its run; the source only to a node the landing stays ahead of.
    Returns (placed links, dropped count)"""
    used, placed, dropped = collections.defaultdict(list), [], 0

    def pick(r, p, landing_fwd, landing_back, ok=lambda q: True):
        for sh in (0, -1, 1, -2, 2):
            q = p + sh
            if not 0 <= q < len(runs[r]) or len(used[(r, q)]) >= 2:
                continue
            if landing_fwd and q + 1 >= len(runs[r]) or landing_back and q < 1 or not ok(q):
                continue
            return q
        return None

    def ahead(r, q, b):
        hx, hy = heading([PXY[(r, i)] for i in range(len(runs[r]))], q, False)
        return (PXY[b][0] - PXY[(r, q)][0]) * hx + (PXY[b][1] - PXY[(r, q)][1]) * hy > PLAN_AHEAD

    for (ra, pa), (rb, pb), ty, lane in sorted(link_list, key=lambda l: (l[0], l[1])):
        qb = pick(rb, pb, True, False)
        qa = pick(ra, pa, False, True, lambda q: qb is not None and ahead(ra, q, (rb, qb)))
        if qa is None or qb is None or (ra == rb and qa == qb):
            dropped += 1
            continue
        used[(ra, qa)].append(len(placed))
        used[(rb, qb)].append(len(placed))
        placed.append(((ra, qa), (rb, qb), ty, lane))
    return placed, dropped


def route_offsets(runs, placed, seglen):
    """node+0x38 is the route distance the teleporter subtracts (0x442570 -> 0x443d60): make it continuous along every run and,
    through a spanning tree of the links, across junctions too (a car 250 m ahead across a link is then 250 m ahead in +0x38)"""
    cum = [[0.0] + list(itertools.accumulate(sl)) for sl in seglen]
    adj = collections.defaultdict(list)
    for (ra, pa), (rb, pb), _, _ in placed:
        d = math.hypot(*[a - b for a, b in zip(PXY[(ra, pa)], PXY[(rb, pb)])])
        adj[ra].append((rb, cum[ra][pa] + d - cum[rb][pb]))        # off_b = off_a + (cum_a[pa] + d - cum_b[pb])
        adj[rb].append((ra, cum[rb][pb] - d - cum[ra][pa]))
    off, top = {}, 0.0
    for r0 in sorted(range(len(runs)), key=lambda r: -len(runs[r])):
        if r0 in off:
            continue
        comp, off[r0], todo = [r0], 0.0, [r0]
        while todo:
            r = todo.pop()
            for r2, delta in adj[r]:
                if r2 not in off:
                    off[r2] = off[r] + delta
                    comp.append(r2)
                    todo.append(r2)
        lo = min(off[r] for r in comp)                    # each connected part sits above the previous one
        for r in comp:
            off[r] += top - lo
        top = max(off[r] + cum[r][-1] for r in comp) + 100.0
    return [off[r] for r in range(len(runs))], cum


def city_chunks(g):
    """(0x34121 payload, 0x34122 payload, stats): one section per run, one pair of entries per placed link"""
    global PXY
    runs, info = g['runs'], g['info']
    rev0 = g.get('rev') or [False] * len(runs)
    nets_ = nets()
    st = min(range(len(runs)), key=lambda r: min(math.hypot(info[(n[0], n[1])][0][n[2]][0] - T.START_XY[0],
                                                           info[(n[0], n[1])][0][n[2]][1] - T.START_XY[1]) for n in runs[r]))
    order = [st] + [r for r in range(len(runs)) if r != st]
    runs = [runs[r] for r in order]
    rev = [rev0[r] for r in order]
    remap = {old: new for new, old in enumerate(order)}
    links = [((remap[a[0]], a[1]), (remap[b[0]], b[1]), ty, lane) for a, b, ty, lane in g['link_list']]
    assert len(runs) <= MAX_SEC, '%d sections > %d' % (len(runs), MAX_SEC)
    xy = lambda n: info[(n[0], n[1])][0][n[2]]
    PXY = {(r, p): xy(n) for r, run in enumerate(runs) for p, n in enumerate(run)}
    placed, dropped = assign_slots(runs, links)
    if g.get('typed'):                                 # v2: the last way out of each run is forced (type 2: racers always take it,
        last = {}                                      # sub_462840), so no racer drives on into a dead tail; the others are forks
        for k, ((ra, pa), _, _, _) in enumerate(placed):    # that a racer may take (type 0, lane 7: the tracks' own 45 forks)
            if ra not in last or pa > placed[last[ra]][0][1]:
                last[ra] = k
        placed = [(a, b, 2, 2) if last[a[0]] == k else (a, b, 0, 7) for k, (a, b, _, _) in enumerate(placed)]
    seglen = [[math.hypot(*[a - b for a, b in zip(xy(run[p + 1]), xy(run[p]))]) for p in range(len(run) - 1)] for run in runs]
    off, cum = route_offsets(runs, placed, seglen)
    secs = []
    for r, run in enumerate(runs):
        t0, s0, _ = run[0]
        hdr = bytearray(nets_[t0]['secs'][s0]['hdr'])
        struct.pack_into('<h', hdr, 0xa, r)
        struct.pack_into('<i', hdr, 0xc, 0)
        struct.pack_into('<hh', hdr, 0x10, len(run), len(run))
        pts = [xy(n) for n in run]
        struct.pack_into('<4f', hdr, 0x20, min(x for x, y in pts), min(y for x, y in pts), max(x for x, y in pts), max(y for x, y in pts))
        nodes = []
        for p, (t, sid, i) in enumerate(run):
            nd = bytearray(nets_[t]['secs'][sid]['nodes'][i])
            if rev[r]:                                  # written against the section's own order: swap what is "next" and "back"
                for a_, b_, w_ in ((0xc, 0x14, 8), (0x1c, 0x20, 4), (0x24, 0x28, 4), (0x30, 0x34, 4)):
                    nd[a_:a_ + w_], nd[b_:b_ + w_] = nd[b_:b_ + w_], nd[a_:a_ + w_]
                # and the lanes with them (re_answers_0b Q1): per lane id k an offset s16 [+0x3c + 2k] (1/256 m, right of the driver)
                # and a speed byte [+0x6a + k]; ids 0..4 / 11..16 drive along the node order, 5..9 / 17..22 against it. The driver who now
                # goes along is the old "against" one: swap k <-> k+5 and k <-> k+6, no negation (offsets are in the driver's frame).
                for k, k2 in [(k, k + 5) for k in range(5)] + [(k, k + 6) for k in range(11, 17)]:
                    o1, o2 = 0x3c + 2 * k, 0x3c + 2 * k2
                    nd[o1:o1 + 2], nd[o2:o2 + 2] = nd[o2:o2 + 2], nd[o1:o1 + 2]
                    nd[0x6a + k], nd[0x6a + k2] = nd[0x6a + k2], nd[0x6a + k]
            nd[0x81] = nd[0x82] = 0xff
            nd[0x83] = r
            struct.pack_into('<I', nd, 0x84, struct.unpack_from('<I', nd, 0x84)[0] | (0x1f << 20))
            struct.pack_into('<f', nd, 0x38, off[r] + cum[r][p])
            d_ = -1 if rev[r] else 1
            if p + 1 < len(run) and run[p + 1] != (t, sid, i + d_):         # a join: new heading and segment lengths
                hx, hy = pts[p + 1][0] - pts[p][0], pts[p + 1][1] - pts[p][1]
                l = math.hypot(hx, hy) or 1.0
                struct.pack_into('<4f', nd, 0xc, hx / l, hy / l, -hx / l, -hy / l)
                struct.pack_into('<f', nd, 0x1c, l)
            if p > 0 and run[p - 1] != (t, sid, i - d_):
                struct.pack_into('<f', nd, 0x20, seglen[r][p - 1])
            nodes.append(nd)
        # The traffic lane picker 0x599660 takes lane id k only if hdr[0x265 + k] != 0 (0x454ff0); the header was copied from the run's
        # first source section, so a run made of other sections' nodes could get no traffic at all (v2b: 31 of 80). The shipped table:
        # the traffic ids 11..13 / 17..19 that any node of the run has (offset != -1), the others 0.
        for k in range(23):
            hdr[0x265 + k] = int(11 <= k <= 13 or 17 <= k <= 19) and int(any(struct.unpack_from('<h', nd, 0x3c + 2 * k)[0] != -1 for nd in nodes))
        secs.append((hdr, nodes))
    def ahead(sr, sp, dr, dp, d):                       # the grower's test on the written bytes (behind_entries)
        nd = secs[sr][1][sp]
        x, y = struct.unpack_from('<2f', nd, 0)
        hx, hy = struct.unpack_from('<2f', nd, 0x14 if d else 0xc)
        tx, ty_ = struct.unpack_from('<2f', secs[dr][1][dp], 0)
        return (tx - x) * hx + (ty_ - y) * hy > AHEAD

    # the planned heading is the run's polyline; a node keeps the track's own heading unless it is a join, so a source can still
    # miss by a little: move it back along its run (a node with a free slot) until the written bytes pass, else drop the link
    nslot = collections.Counter(n for a, b_, _, _ in placed for n in (a, b_))
    fixed, moved, cut = [], 0, 0
    for (ra, pa), (rb, pb), ty, lane in placed:
        q = pa
        while q >= 0 and not ahead(ra, q, rb, pb, 0):
            q -= 1
            while q >= 0 and nslot[(ra, q)] >= 2:
                q -= 1
        if q < 0 or pa - q > 3 or (ra == rb and q == pb):
            cut += 1
            continue
        if q != pa:
            nslot[(ra, pa)] -= 1
            nslot[(ra, q)] += 1
            moved += 1
        fixed.append(((ra, q), (rb, pb), ty, lane))
    placed = fixed

    items, kinds, no_rev = [], collections.Counter(), 0
    for (ra, pa), (rb, pb), ty, lane in placed:
        kinds[(ty, lane)] += 1
        for (sr, sp), (dr, dp), d in (((ra, pa), (rb, pb), 0), ((rb, pb), (ra, pa), 1)):
            if d and not ahead(sr, sp, dr, dp, d):          # a backward driver would land behind: no reverse entry
                no_rev += 1
                continue
            e = bytearray(32)
            struct.pack_into('<fHH', e, 0, 0.0, dp, sp)
            e[8], e[9], e[0xa], e[0xb], e[0xc], e[0xd] = 0, dr, sr, ty, lane, d
            struct.pack_into('<IiII', e, 0x10, 0, -1, 0, 0)
            items.append((sr, sp, bytes(e)))
    assert len(items) <= MAX_ENT, '%d entries > %d' % (len(items), MAX_ENT)
    # Up to 255 entries a node's slot byte is the entry's index in the file. Above that the exe skips its sort and a slot byte is the
    # rank inside the node's section (entry = first entry of the section + byte, patches.py EBASE), so the entries are grouped by source.
    wide = len(items) > RETAIL_ENT
    if wide:
        items.sort(key=lambda it: (it[0], it[1]))
    ent, rank = [], collections.Counter()
    for sr, sp, e in items:
        node = secs[sr][1][sp]
        slot = 0x81 if node[0x81] == 0xff else 0x82
        assert node[slot] == 0xff
        node[slot] = rank[sr] if wide else len(ent)
        rank[sr] += 1
        assert node[slot] < 0xff
        ent.append(e)
    p21 = b''.join(bytes(h) + b''.join(bytes(n) for n in ns) for h, ns in secs)
    return p21, b''.join(ent), dict(sections=len(runs), entries=len(ent), links=len(placed), dropped_links=dropped, src_moved=moved, src_cut=cut, no_reverse=no_rev, kinds=dict(kinds),
                                    nodes=sum(len(r) for r in runs), route_max=round(max(off[r] + cum[r][-1] for r in range(len(runs)))))


def orient_net(g):
    """v2: orient the runs and choose the links (plan_net); keep only the runs the biggest strongly connected part touches (a run
    with no link is a trap: a walker that enters it stops at its end). Returns g with runs written in walk order, rev flags, typed links"""
    runs, info = g['runs'], g['info']
    xy = [[info[(t, sid)][0][i] for t, sid, i in run] for run in runs]
    flip, links, scc = plan_net(xy)
    print('plan: SCC %d of %d nodes in %d runs, %d links before the drop of unlinked runs' % (scc, sum(map(len, runs)), len(runs), len(links)), flush=True)
    used = sorted({a[0] for a, b in links} | {b[0] for a, b in links})
    new = {r: k for k, r in enumerate(used)}
    pos = lambda r, p: len(runs[r]) - 1 - p if flip[r] else p
    g2 = dict(g)
    g2['runs'] = [runs[r][::-1] if flip[r] else runs[r] for r in used]
    g2['rev'] = [flip[r] for r in used]
    g2['link_list'] = [((new[a[0]], pos(*a)), (new[b[0]], pos(*b)), 2, 2) for a, b in links]
    g2['typed'] = True
    return g2


def parse_net(d):
    """(sections [[(x, y, flags, [slots])]], seg lengths, entries) of a TRACKB's road chunks, the way the exe reads them"""
    (b, s), = T.find(d, 0x34121)
    p, secs = b, []
    while p < b + s:
        n = struct.unpack_from('<h', d, p + 0x10)[0]
        secs.append([bytes(d[p + 0x27c + i * 0x88:p + 0x27c + (i + 1) * 0x88]) for i in range(n)])
        p += 0x27c + n * 0x88
    assert p == b + s
    (b, s), = T.find(d, 0x34122)
    return secs, [bytes(d[o:o + 32]) for o in range(b, b + s, 32)]


AHEAD = 0.1                                       # [0x6cc7b8]: the grower 0x5a58d0 appends a link's landing only this far ahead


def behind_entries(secs, ent):
    """[(entry, source sec, node, proj)] of every entry whose landing node is not > AHEAD m ahead of its source along the source's
    heading for that direction (d=0 node+0xc/+0x10, d=1 +0x14/+0x18; vt+0x10 0x4550d0 / 0x455490). The grower then re-steps from
    the landing without appending, a 2nd link leaves a node with +0x60 set that its predecessor has no link to -> 0x5a6d20 NULL ->
    fault at 0x462a06"""
    bad = []
    for s, ns in enumerate(secs):
        for i, nd in enumerate(ns):
            for k in (0x81, 0x82):
                if nd[k] == 0xff:
                    continue
                e = slot_entry(ent, nd, k)
                if e[0xb] == 3:
                    continue
                x, y = struct.unpack_from('<2f', nd, 0)
                hx, hy = struct.unpack_from('<2f', nd, 0x14 if e[0xd] else 0xc)
                tx, ty = struct.unpack_from('<2f', secs[e[9]][struct.unpack_from('<H', e, 4)[0]], 0)
                pr = (tx - x) * hx + (ty - y) * hy
                if not pr > AHEAD:
                    bad.append((nd[k], s, i, pr))
    return bad


def walk_stats(secs, ent, dist=250.0):
    """the share of drivable nodes from which a 250 m walk (the teleporter's, 0x4563d0) can succeed, forward and backward; a branch
    ring makes the walker try the links AND the straight node, so 'any path' counts"""
    drv = lambda nd: bool(struct.unpack_from('<I', nd, 0x84)[0] & (FWD_BITS | BACK_BITS))
    seg = lambda nd: struct.unpack_from('<f', nd, 0x1c)[0]
    sys.setrecursionlimit(10000)

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
                e = slot_entry(ent, nd, k)
                if e[0xd] == (0 if fwd else 1) and e[0xb] != 3:
                    nxt.append((e[9], struct.unpack_from('<H', e, 4)[0]))
        j = i + 1 if fwd else i - 1
        if 0 <= j < len(secs[s]):
            nxt.append((s, j))
        return any(drv(secs[a][b]) and go(a, b, fwd, rem, budget) for a, b in nxt)

    res = {True: [0, 0], False: [0, 0]}
    for s, ns in enumerate(secs):
        for i, nd in enumerate(ns):
            if not drv(nd):
                continue
            for fwd in (True, False):
                res[fwd][1] += 1
                res[fwd][0] += go(s, i, fwd, dist, [3000])
    return {('fwd' if f else 'back'): '%.1f%% of %d' % (100.0 * a / max(b, 1), b) for f, (a, b) in res.items()}


def slow_junctions(d):
    """Caps the racer lane speeds before every sharp link, in place on a decoded TRACKB. Why (OWNER 2026-10-31, "the AI is dumb";
    rivals hit walls at ~44 m/s in JustDrive): a racer's route speed is the speed byte [+0x6a + lane] of the node at its own node
    index + [racer+0x404] (0x44c550; 0x404 is a random -(k+1)..k+1, clamped to the section), so it has no look ahead and the bytes
    must already hold the braking. Lanes 0..4 drive along the node order, 5..9 against it (0x59bb80). The original tracks have
    no link that turns more than 45 deg; this net has many (forced type 2 near U-turns at run ends, 90 deg junctions) whose
    source nodes ask ~60 m/s. Cap = sqrt(v_turn^2 + 2 * BRAKE * metres to the link node), on the nodes that lead to it in the
    walker's direction (d=0: lanes 0..4 up to the node, d=1: lanes 5..9 down to it); v_turn 34 m/s at 30 deg, 16 at 90, 10 at
    180. Returns the number of bytes lowered."""
    BRAKE, MIN_TURN = 9.0, 30.0
    secs, ent = parse_net(d)
    (b, s), = T.find(d, 0x34121)
    base, p = [], b
    for ns in secs:
        base.append(p + 0x27c)
        p += 0x27c + len(ns) * 0x88
    xy = lambda s_, i: struct.unpack_from('<2f', secs[s_][i], 0)
    def head(s_, i, fwd):                      # travel heading at node i of section s_ for a walker along (fwd) or against the order
        n, st = len(secs[s_]), 1 if fwd else -1
        a, c = (i, i + st) if 0 <= i + st < n else (i - st, i)
        (x0, y0), (x1, y1) = xy(s_, a), xy(s_, c)
        return math.atan2(y1 - y0, x1 - x0)
    cap = {}                                   # (section, node, lanes along) -> m/s
    def mark(s_, i, v, fwd):
        j, dist, back = i, 0.0, -1 if fwd else 1
        while 0 <= j < len(secs[s_]):
            c = math.sqrt(v * v + 2 * BRAKE * dist)
            if c >= 80:
                break
            cap[(s_, j, fwd)] = min(cap.get((s_, j, fwd), 255.0), c)
            if not 0 <= j + back < len(secs[s_]):
                break
            dist += math.dist(xy(s_, j), xy(s_, j + back))
            j += back
    for e in ent:
        if e[0xb] == 3:
            continue
        dst, src = struct.unpack_from('<HH', e, 4)
        ds, ss, fwd = e[9], e[0xa], e[0xd] == 0
        if ss >= len(secs) or ds >= len(secs) or src >= len(secs[ss]) or dst >= len(secs[ds]):
            continue
        turn = math.degrees(abs((head(ds, dst, fwd) - head(ss, src, fwd) + math.pi) % (2 * math.pi) - math.pi))
        if turn >= MIN_TURN:
            mark(ss, src, max(10.0, 16.0 * (90.0 / turn) ** 0.7), fwd)
    low = 0
    for (s_, i, fwd), c in cap.items():
        o = base[s_] + i * 0x88 + (0x6a if fwd else 0x6f)
        for k in range(5):
            if d[o + k] > c:
                d[o + k] = max(1, int(c))
                low += 1
    return low


def write(radius=10.0):
    t0 = time.time()
    g = build(radius, True)
    g = orient_net(g)
    p21, p22, st = city_chunks(g)
    print('city road net:', st, '(%.0fs)' % (time.time() - t0), flush=True)
    tp = T.load(os.path.join(T.B.OUT, 'TRACKB1010.lzc'))          # the TrackPath stays the tour's polyline
    (hb, hs), (nb, ns) = T.find(tp, 0x34148)[0], T.find(tp, 0x34149)[0]
    head, body = bytes(tp[hb:hb + hs]), bytes(tp[nb:nb + ns])
    base = T.load(T.trackb_path(T.PC, 1001))
    base2 = T.make_base(base, p21, p22, head, body)
    secs, ent = parse_net(base2)
    assert len(secs) == st['sections'] and len(ent) == st['entries']
    bad = behind_entries(secs, ent)
    assert not bad, 'entries landing behind their source: %s' % bad[:8]
    scc, nn = scc_of_file(secs, ent)
    print('SCC: biggest strongly connected part %d of %d nodes (%.1f%%)' % (scc, nn, 100.0 * scc / nn), flush=True)
    assert scc >= 0.9 * nn, 'SCC %d < 90%% of %d nodes' % (scc, nn)
    print('walk 250 m from drivable nodes:', walk_stats(secs, ent), flush=True)
    B = T.B
    fences = json.load(open(B.FENCES))
    fence_keys = {f['key'] for f in fences['fences']}
    rows, n_union, n_fence = B.union_rows(fence_keys)
    union_keys = {T.polys.key(r) for r in rows}
    bases = {t: T.load(T.trackb_path(T.PC, t)) for t in T.TR}
    cls, props = B.union_props(bases)
    gg = T.gen.derive(rows)
    print('collision derived (%.0fs)' % (time.time() - t0), flush=True)
    new = bytearray(B.build_file(base2, gg, rows, props))
    print('junction speed caps: %d lane bytes lowered' % slow_junctions(new), flush=True)
    blob = T.lzc.encode(bytes(new))
    os.makedirs(OUT_DIR, exist_ok=True)
    path = os.path.join(OUT_DIR, 'TRACKB%d.lzc' % T.OUT_ID)
    if os.path.lexists(path):
        os.remove(path)                                            # a clone of build/openworld's file must not be written through
    open(path, 'wb').write(blob)
    f = B.check(T.OUT_ID, base2, new, blob, gg, rows, props, fence_keys, union_keys, T.random.Random(7))
    secs, ent = parse_net(new)
    assert len(secs) <= MAX_SEC and len(ent) <= MAX_ENT and not behind_entries(secs, ent)
    print('wrote', path, len(blob), 'bytes', dict(f), 'sections %d entries %d' % (len(secs), len(ent)), '(%.0fs)' % (time.time() - t0))


def main():
    if '--slow' in sys.argv:                  # the caps of slow_junctions on an already written file, in place (no rebuild)
        path = sys.argv[sys.argv.index('--slow') + 1]
        d = bytearray(T.load(path))
        print(path, 'junction speed caps: %d lane bytes lowered' % slow_junctions(d))
        blob = T.lzc.encode(bytes(d))
        assert T.lzc.exe_decode(blob) == d, 'lzc round trip'
        os.remove(path)
        open(path, 'wb').write(blob)
        return
    if '--write' in sys.argv:
        write(float(sys.argv[sys.argv.index('--radius') + 1]) if '--radius' in sys.argv else 10.0)
        return
    if '--stats' not in sys.argv:
        print(__doc__)
        return
    R = float(sys.argv[sys.argv.index('--radius') + 1]) if '--radius' in sys.argv else 3.0
    secs = sections()
    print('input: %d tracks, %d list-0 sections, %d nodes, %d own entries (all tracks, d=0 and d=1), limits %d sections / %d entries' % (
        len(T.TR), len(secs), sum(len(s[2]) for s in secs), sum(len(n['ent']) for n in nets().values()), MAX_SEC, MAX_ENT))
    for name, und in (('directed R=%g m' % R, False), ('undirected R=%g m' % R, True)):
        fmt(name, build(R, und))
    print('radius sweep (directed / undirected):')
    for r in (1.5, 3.0, 6.0, 8.0, 10.0, 12.0):
        for name, und in (('directed R=%g' % r, False), ('undirected R=%g' % r, True)):
            fmt(name, build(r, und))


if __name__ == '__main__':
    main()
