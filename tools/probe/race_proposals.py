#!/usr/bin/env python3
"""race_proposals.py: row 11 proposal map. Both cities as joined in WORLD (NFSU1 Olympic City + bridge + UG2 Bayview) with 12 numbered
race proposals, plus the numbers behind census/race_proposals.md. Read only: writes web/plan/shots/race_proposals.png, prints the table.

usage: .venv/bin/python -I tools/probe/race_proposals.py [--out web/plan/shots/race_proposals.png]
Sources (all read here, none run):
  UG2 races   TRACKS/ROUTESL4RA/Paths<id>.bin chunk 0x3414c = 60 rows x 272 B: u16 track id, u8 waypoint count, u8 closed, u8 ?, u8 ?, then 32 x (f32 x, f32 y)
              (checked: sprint wp0 lies within 15..200 m of the ForwardStartLine, last wp within 9..140 m of the ForwardFinishLine; closed = circuits 40xx).
              TrackPosMarkersAll.bin chunk 0x34146: 1290 rows x 0x30 B, +8 name hash, +0xc ordinal, +0x10 xyz, +0x20 u16 angle, +0x24 u16 TRACK ID.
              Routes<id>F.bin: the race's own road graph (same section ids as RoutesFreeRoam.bin, its entries are a subset, type bytes re-tagged).
              Route drawn = shortest road path through the waypoints on that graph (INFERENCE: how UG2 joins waypoints is not decoded).
  WORLD net   build/openworld/TRACKB1010.lzc chunk 0x34121 / 0x34122 (254 sections: 0..77 NFSU1 tour net, 78 connector, 79..253 UG2).
  NFSU1 races game/Tracks/TRACKB<id>.lzc 0x34148/0x34149 route + 0x34146 markers (tools/openworld/map.py readers).
Frame: UG2 -> WORLD (y-1287.375, -x+812.25, z-6.203125), tools/ug2_roads.py:18-24."""
import argparse, collections, heapq, math, os, struct, sys
from PIL import Image, ImageDraw, ImageFont

HERE = os.path.dirname(os.path.abspath(__file__))
REPO = os.path.abspath(os.path.join(HERE, '..', '..'))
os.environ.setdefault('NFSU1_MAIN', REPO)
sys.path[:0] = [os.path.join(REPO, 'tools'), os.path.join(REPO, 'tools', 'openworld'), os.path.join(REPO, 'tools', 'hopper'),
                os.path.join(REPO, 'ref', 'tools', 'ug1-tracks')]
import ug2_roads as R        # noqa: E402
import ug2_traffic as U      # noqa: E402
import map as M              # noqa: E402  (tools/openworld/map.py: NFSU1 route reader)
from lib import load, find, trackb_path, PC  # noqa: E402

RT = R.TRACKS + '/ROUTESL4RA/'
FONT = '/System/Library/Fonts/Supplemental/Arial.ttf'
FONTB = '/System/Library/Fonts/Supplemental/Arial Bold.ttf'
NAMES = ['ForwardStartingPosition', 'BackwardStartingPosition', 'ForwardStartLine', 'BackwardStartLine', 'ForwardFinishLine', 'BackwardFinishLine']


def cshash(s):
    x = 0xffffffff
    for c in s.encode():
        x = (x * 33 + c) & 0xffffffff
    return x


HASH = {cshash(n): n for n in NAMES}


def w2(x, y):
    return R.to_nfsu1(x, y, 0)[:2]


# ---------------------------------------------------------------- UG2 race data
def ug2_waypoints():
    d = open(RT + 'Paths4001.bin', 'rb').read()
    p = 8
    while p < len(d):
        i, s = struct.unpack_from('<II', d, p)
        if i == 0x3414c:
            break
        p += 8 + s
    out = {}
    for k in range(s // 272):
        r = d[p + 8 + k * 272:p + 8 + (k + 1) * 272]
        tid, = struct.unpack_from('<H', r, 0)
        out[tid] = dict(n=r[2], closed=bool(r[3]), pts=[struct.unpack_from('<2f', r, 8 + 8 * j) for j in range(r[2])])
    return out


def ug2_markers():
    d = open(RT + 'TrackPosMarkersAll.bin', 'rb').read()
    out = collections.defaultdict(lambda: collections.defaultdict(list))
    for k in range((len(d) - 16) // 48):
        r = d[16 + k * 48:16 + (k + 1) * 48]
        h, o = struct.unpack_from('<II', r, 8)
        x, y, z = struct.unpack_from('<3f', r, 0x10)
        tid, = struct.unpack_from('<H', r, 0x24)
        out[tid][HASH.get(h, hex(h))].append((o, x, y))
    return out


def graph(g):
    P, adj = {}, collections.defaultdict(list)
    for s in g['sections']:
        for i, n in enumerate(s['nodes']):
            P[(s['id'], i)] = (n['x'], n['y'])
            if i:
                a, b = (s['id'], i - 1), (s['id'], i)
                d = math.dist(P[a], P[b])
                adj[a].append((b, d)); adj[b].append((a, d))
    for e in g['entries']:
        a, b = (e['ss'], e['sn']), (e['ds'], e['dn'])
        if a in P and b in P:
            d = math.dist(P[a], P[b])
            adj[a].append((b, d)); adj[b].append((a, d))
    return P, adj


def dijkstra(adj, a, b):
    dist, prev, pq = {a: 0.0}, {}, [(0.0, a)]
    while pq:
        d, u = heapq.heappop(pq)
        if u == b:
            break
        if d > dist[u]:
            continue
        for v, w in adj[u]:
            if d + w < dist.get(v, 1e18):
                dist[v] = d + w; prev[v] = u; heapq.heappush(pq, (d + w, v))
    path = [b]
    while path[-1] != a:
        path.append(prev[path[-1]])
    return dist[b], path[::-1]


def ug2_route(tid, wp):
    """(length m, polyline in UG2 raw xy, {section id: metres on it}) through the waypoints on Routes<tid>F.bin"""
    P, adj = graph(R.load('A', 'Routes%dF.bin' % tid))
    snap = [min(P, key=lambda k: (P[k][0] - x) ** 2 + (P[k][1] - y) ** 2) for x, y in wp['pts']]
    seq = snap + ([snap[0]] if wp['closed'] else [])
    tot, poly, used = 0.0, [], collections.Counter()
    for a, b in zip(seq, seq[1:]):
        if a == b:
            continue
        d, path = dijkstra(adj, a, b)
        tot += d
        for k1, k2 in zip(path, path[1:]):
            used[k2[0]] += math.dist(P[k1], P[k2])
        poly += [P[k] for k in path]
    return tot, poly, used


# ---------------------------------------------------------------- WORLD net
def world_net():
    d = load(os.path.join(REPO, 'build', 'openworld', 'TRACKB1010.lzc'))
    (b, s), = find(d, 0x34121)
    p, secs = b, []
    while p < b + s:
        sid = struct.unpack_from('<h', d, p + 0xa)[0]
        n = struct.unpack_from('<h', d, p + 0x10)[0]
        nodes = [struct.unpack_from('<2f', d, p + 0x27c + i * 0x88) for i in range(n)]
        lanes = tuple(k for k in range(20) if d[p + 0x265 + k])
        secs.append(dict(id=sid, nodes=nodes, lanes=lanes))
        p += 0x27c + n * 0x88
    (b2, s2), = find(d, 0x34122)
    ents = [bytes(d[o:o + 32]) for o in range(b2, b2 + s2, 32)]
    return secs, ents


class World:
    def __init__(self):
        self.secs, ents = world_net()
        self.S = {s['id']: s for s in self.secs}
        self.P, self.adj = {}, collections.defaultdict(list)
        for s in self.secs:
            for i, (x, y) in enumerate(s['nodes']):
                self.P[(s['id'], i)] = (x, y)
                if i:
                    a, b = (s['id'], i - 1), (s['id'], i)
                    dd = math.dist(self.P[a], self.P[b])
                    self.adj[a].append((b, dd)); self.adj[b].append((a, dd))
        for r in ents:
            dn, sn = struct.unpack_from('<2H', r, 4)
            a, b = (r[0xa], sn), (r[9], dn)
            if a in self.P and b in self.P:
                dd = math.dist(self.P[a], self.P[b])
                self.adj[a].append((b, dd)); self.adj[b].append((a, dd))
        self.n_ent = len(ents)
        self.grid = {'u': collections.defaultdict(list), 'n': collections.defaultdict(list)}
        for s in self.secs:
            g = self.grid['u'] if s['id'] >= 79 else self.grid['n']
            for a, b in zip(s['nodes'], s['nodes'][1:]):
                for cx in range(int(min(a[0], b[0]) // 20), int(max(a[0], b[0]) // 20) + 1):
                    for cy in range(int(min(a[1], b[1]) // 20), int(max(a[1], b[1]) // 20) + 1):
                        g[(cx, cy)].append((a, b))

    def comps(self):
        comp, c = {}, 0
        for k in self.P:
            if k in comp:
                continue
            st = [k]; comp[k] = c
            while st:
                u = st.pop()
                for v, _ in self.adj[u]:
                    if v not in comp:
                        comp[v] = c; st.append(v)
            c += 1
        return comp

    def snap(self, pt):
        return min(self.P, key=lambda k: (self.P[k][0] - pt[0]) ** 2 + (self.P[k][1] - pt[1]) ** 2)

    def path(self, a, b):
        d, p = dijkstra(self.adj, self.snap(a), self.snap(b))
        return d, [self.P[k] for k in p]

    def cover(self, poly, which, r, step=8.0):
        g = self.grid[which]
        tot = on = 0.0
        for a, b in zip(poly, poly[1:]):
            L = math.dist(a, b)
            if L == 0:
                continue
            n = max(1, int(L // step))
            for k in range(n):
                f = (k + .5) / n
                p = (a[0] + (b[0] - a[0]) * f, a[1] + (b[1] - a[1]) * f)
                cx, cy = int(p[0] // 20), int(p[1] // 20)
                best = 1e9
                for dx in (-1, 0, 1):
                    for dy in (-1, 0, 1):
                        for s0, s1 in g.get((cx + dx, cy + dy), ()):
                            vx, vy = s1[0] - s0[0], s1[1] - s0[1]
                            L2 = vx * vx + vy * vy
                            t = 0 if L2 == 0 else max(0, min(1, ((p[0] - s0[0]) * vx + (p[1] - s0[1]) * vy) / L2))
                            best = min(best, math.hypot(p[0] - s0[0] - t * vx, p[1] - s0[1] - t * vy))
                tot += L / n
                on += (L / n) * (best <= r)
        return tot, on


def straights(W, minlen=330.0, tol=8.0):
    """longest straight chains of the WORLD net (follow a section, hop by the straightest entry), distinct by 150 m"""
    nxt = collections.defaultdict(list)
    for k, vs in W.adj.items():
        for v, _ in vs:
            if v[0] != k[0]:
                nxt[k].append(v)
    S = W.S

    def walk(sec, i0, maxlen=2500.0):
        path, (s_, i), L, seen = [(sec, i0)], (sec, i0), 0.0, {(sec, i0)}
        while L < maxlen:
            nodes = S[s_]['nodes']
            if i + 1 < len(nodes):
                nn = (s_, i + 1)
            else:
                c = [x for x in nxt.get((s_, i), []) if x not in seen]
                if not c or len(path) < 2:
                    break
                a, bb = S[path[-2][0]]['nodes'][path[-2][1]], nodes[i]
                h = math.atan2(bb[1] - a[1], bb[0] - a[0])
                c.sort(key=lambda x: abs((math.atan2(S[x[0]]['nodes'][x[1]][1] - nodes[i][1], S[x[0]]['nodes'][x[1]][0] - nodes[i][0]) - h + math.pi) % (2 * math.pi) - math.pi))
                nn = c[0]
                if math.dist(S[nn[0]]['nodes'][nn[1]], nodes[i]) > 60:
                    break
            if nn in seen:
                break
            seen.add(nn)
            L += math.dist(S[nn[0]]['nodes'][nn[1]], S[s_]['nodes'][i])
            path.append(nn); s_, i = nn
        return path

    out = []
    for sid, sc in S.items():
        for i0 in range(0, len(sc['nodes']), max(1, len(sc['nodes']) // 6)):
            pth = walk(sid, i0)
            pts = [S[a]['nodes'][b] for a, b in pth]
            cum = [0.0]
            for u, v in zip(pts, pts[1:]):
                cum.append(cum[-1] + math.dist(u, v))
            best = None
            for i in range(len(pts)):
                far, k = None, i + 1
                while k < len(pts):
                    L = math.dist(pts[i], pts[k])
                    if L < 1:
                        k += 1; continue
                    ax, ay = pts[i]; bx, by = pts[k]
                    if max(abs((bx - ax) * (ay - py) - (ax - px) * (by - ay)) / L for px, py in pts[i:k + 1]) > tol:
                        break
                    far = k; k += 1
                if far and cum[far] - cum[i] >= minlen and (best is None or cum[far] - cum[i] > best[0]):
                    best = (cum[far] - cum[i], pts[i], pts[far], sorted({a for a, _ in pth[i:far + 1]}))
            if best:
                out.append(best)
    out.sort(key=lambda t: -t[0])
    keep = []
    for r in out:
        if all(math.dist(r[1], q[1]) > 150 for q in keep):
            keep.append(r)
    return keep


def nfsu1_data():
    out = {}
    for tid in M.TRACKS:
        d = load(trackb_path(PC, tid))
        r = M.read_route(d)
        (mb, ms), = find(d, 0x34146)
        q = mb
        while d[q] == 0x11:
            q += 1
        mk = {}
        for o in range(q, mb + ms - 47, 48):
            h, od = struct.unpack_from('<II', d, o + 8)
            x, y, z = struct.unpack_from('<3f', d, o + 0x10)
            mk.setdefault(HASH.get(h, hex(h)), []).append((od, x, y))
        out[tid] = dict(route=r, mk=mk)
    return out


def nfsu1_background():
    segs = []
    for tid in M.TRACKS:
        d = load(trackb_path(PC, tid))
        (b, s), = find(d, 0x34121)
        p = b
        while p < b + s:
            n = struct.unpack_from('<h', d, p + 0x10)[0]
            segs.append([struct.unpack_from('<2f', d, p + 0x27c + i * 0x88) for i in range(n)])
            p += 0x27c + n * 0x88
    return segs


# ---------------------------------------------------------------- drawing
X0, Y1, SPAN = -3450.0, 3960.0, 5950.0
MAP = 1000
COL = dict(circuit=(255, 150, 40), sprint=(70, 170, 255), drag=(90, 220, 110), drift=(240, 90, 230), challenge=(255, 230, 70))


def px(p):
    return ((p[0] - X0) / SPAN * MAP, (Y1 - p[1]) / SPAN * MAP)


def draw(props, bg_n, bg_u, tour, ug2net, out):
    LEG = 190
    img = Image.new('RGB', (MAP, MAP + LEG), (14, 18, 24))
    dr = ImageDraw.Draw(img, 'RGBA')
    fb = ImageFont.truetype(FONTB, 13); fbs = ImageFont.truetype(FONTB, 11); fr = ImageFont.truetype(FONT, 12); ft = ImageFont.truetype(FONTB, 17)
    for sec in bg_u:
        dr.line([px(p) for p in sec], fill=(74, 98, 126), width=1)
    for sec in bg_n:
        dr.line([px(p) for p in sec], fill=(70, 98, 80), width=1)
    for sec in ug2net:
        dr.line([px(p) for p in sec], fill=(105, 140, 175), width=2)
    for sec in tour:
        dr.line([px(p) for p in sec], fill=(120, 175, 130), width=2)
    # bridge
    dr.line([px((121.8, 394)), px((121.8, 589))], fill=(255, 255, 255), width=3)
    dr.text(px((300, 520)), 'bridge', font=fbs, fill=(255, 255, 255), stroke_width=2, stroke_fill=(14, 18, 24))
    dr.text(px((600, 1250)), 'Olympic City (NFSU1)', font=ft, fill=(170, 220, 180), stroke_width=3, stroke_fill=(14, 18, 24))
    dr.text(px((-2300, 3500)), 'Bayview (UG2)', font=ft, fill=(170, 200, 235), stroke_width=3, stroke_fill=(14, 18, 24))
    # routes
    marks = []
    for pr in props:
        col = COL[pr['kind']]
        pts = [px(p) for p in pr['poly']]
        if len(pts) > 1:
            dr.line(pts, fill=(10, 12, 16, 230), width=7, joint='curve')
            dr.line(pts, fill=col + (255,), width=4, joint='curve')
            # chevron at 55 % of the length, pointing along the route
            cum = [0.0]
            for a, b in zip(pts, pts[1:]):
                cum.append(cum[-1] + math.dist(a, b))
            tgt = cum[-1] * 0.55
            j = max(k for k in range(len(cum) - 1) if cum[k] <= tgt)
            a, b = pts[j], pts[j + 1]
            ang = math.atan2(b[1] - a[1], b[0] - a[0])
            f = (tgt - cum[j]) / ((cum[j + 1] - cum[j]) or 1)
            cx, cy = a[0] + (b[0] - a[0]) * f, a[1] + (b[1] - a[1]) * f
            tri = [(cx + 8 * math.cos(ang), cy + 8 * math.sin(ang)), (cx + 6 * math.cos(ang + 2.5), cy + 6 * math.sin(ang + 2.5)), (cx + 6 * math.cos(ang - 2.5), cy + 6 * math.sin(ang - 2.5))]
            dr.polygon(tri, fill=(255, 255, 255, 255), outline=(10, 12, 16, 255))
        if pr.get('finish'):
            fx, fy = px(pr['finish'])
            dr.rectangle([fx - 6, fy - 6, fx + 6, fy + 6], fill=col + (255,), outline=(255, 255, 255, 255), width=2)
        marks.append([pr['id'], list(px(pr['start'])), col, pr['src'] == 'UG2'])
    # start markers, pushed apart when two numbers would overlap
    for it in range(30):
        for i in range(len(marks)):
            for j in range(i + 1, len(marks)):
                a, b = marks[i][1], marks[j][1]
                d = math.dist(a, b)
                if d < 26:
                    ux, uy = ((a[0] - b[0]) / d, (a[1] - b[1]) / d) if d > 0.1 else (1.0, 0.0)
                    a[0] += ux * 2; a[1] += uy * 2; b[0] -= ux * 2; b[1] -= uy * 2
    for pid, (x, y), col, ug in marks:
        dr.ellipse([x - 12, y - 12, x + 12, y + 12], fill=col + (255,), outline=(255, 255, 255, 255), width=3 if ug else 1)
        t = str(pid)
        w = dr.textlength(t, font=fb)
        dr.text((x - w / 2, y - 8), t, font=fb, fill=(10, 12, 16))
    # legend strip
    y0 = MAP + 8
    dr.text((10, y0), 'numbered disc = start (white ring = UG2 own race), square = finish, arrow = direction.  Bright roads = in the WORLD net today, dim = not.', font=fr, fill=(190, 198, 208))
    kx = 10
    for k, c in COL.items():
        dr.rectangle([kx, y0 + 22, kx + 22, y0 + 28], fill=c)
        dr.text((kx + 28, y0 + 18), k if k != 'challenge' else 'rival challenge', font=fr, fill=(220, 224, 230))
        kx += 150
    cw = MAP // 3
    for n, pr in enumerate(props):
        cx, cy = 10 + (n % 3) * cw, y0 + 48 + (n // 3) * 34
        dr.ellipse([cx, cy + 1, cx + 22, cy + 23], fill=COL[pr['kind']] + (255,), outline=(255, 255, 255, 255), width=2 if pr['src'] == 'UG2' else 1)
        t = str(pr['id'])
        dr.text((cx + 11 - dr.textlength(t, font=fbs) / 2, cy + 6), t, font=fbs, fill=(10, 12, 16))
        dr.text((cx + 28, cy - 1), pr['label'], font=fb, fill=(235, 238, 242))
        dr.text((cx + 28, cy + 15), pr['sub'], font=fr, fill=(160, 170, 182))
    img.save(out)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--out', default=os.path.join(REPO, 'web', 'plan', 'shots', 'race_proposals.png'))
    a = ap.parse_args()
    W = World()
    comp = W.comps()
    main_c = collections.Counter(comp.values()).most_common(1)[0][0]
    print('WORLD net: %d sections, %d nodes, %d entries; one connected piece: %d nodes, outside it: sections %s' % (
        len(W.secs), len(W.P), W.n_ent, sum(1 for k in comp if comp[k] == main_c), sorted({k[0] for k in comp if comp[k] != main_c})))
    fr = R.load('A')
    keep, _ = U.select(fr, 175)
    K = set(keep)
    WP, MK = ug2_waypoints(), ug2_markers()
    N1 = nfsu1_data()
    props = []

    def ug2_prop(pid, tid, kind, label):
        wp = WP[tid]
        L, poly, used = ug2_route(tid, wp)
        wpoly = [w2(*p) for p in poly]
        tot, on = W.cover(wpoly, 'u', 8.0)
        ss = {s for s, m in used.items() if m > 20}
        st = MK[tid]['ForwardStartLine'][0]
        fin = MK[tid].get('ForwardFinishLine')
        row = dict(id=pid, kind=kind, src='UG2', tid=tid, label=label, length=L, cover=on / tot, secs=len(ss), new=len(ss - K), poly=wpoly,
                   start=w2(st[1], st[2]), finish=w2(fin[0][1], fin[0][2]) if fin else None, closed=wp['closed'], nwp=wp['n'])
        row['sub'] = 'UG2 %d, %.1f km, %s' % (tid, L / 1000, ('%d%% on the net now' % round(100 * on / tot)) if on / tot > 0.5 else ('%d%% on net, %d sections to add' % (round(100 * on / tot), len(ss - K))))
        return row

    def n1_prop(pid, tid, kind, label):
        r = N1[tid]
        pts = r['route']['pts']
        tot, on = W.cover(pts, 'n', 25.0)
        st = r['mk']['ForwardStartLine'][0]
        fin = r['mk'].get('ForwardFinishLine')
        row = dict(id=pid, kind=kind, src='NFSU1', tid=tid, label=label, length=r['route']['total'], cover=on / tot, poly=list(pts) + ([pts[0]] if r['route']['closed'] else []),
                   start=(st[1], st[2]), finish=(fin[0][1], fin[0][2]) if fin else None, closed=r['route']['closed'], nwp=r['route']['n_nodes'])
        row['sub'] = 'NFSU1 %d, %.1f km, %d%% on the net now' % (tid, row['length'] / 1000, round(100 * on / tot))
        return row

    props.append(ug2_prop(1, 4024, 'circuit', 'Park Loop circuit'))
    props.append(ug2_prop(2, 4083, 'circuit', 'UC-CC Circuit #3'))
    props.append(ug2_prop(3, 4121, 'sprint', 'UC Sprint #1'))
    props.append(ug2_prop(4, 4122, 'sprint', 'UC Sprint #2'))
    props.append(n1_prop(5, 1001, 'circuit', 'Olympic Square circuit'))
    props.append(n1_prop(6, 1104, 'sprint', 'Street sprint 1104'))
    # drag: the longest straight whose sections all carry two same-direction traffic lanes (NFSU1 half), and the UG2 one (one lane per direction only)
    st = straights(W)
    print('straights (WORLD net, >= 330 m, <= 8 m off the chord):')
    for r in st[:8]:
        print('  %.0f m (%.0f,%.0f)->(%.0f,%.0f) sections %s lanes %s' % ((r[0],) + r[1] + r[2] + (r[3][:5], [W.S[s]['lanes'] for s in r[3][:2]])))
    d1 = next(r for r in st if r[3][0] < 78 and all({11, 12} <= set(W.S[x]['lanes']) or {17, 18} <= set(W.S[x]['lanes']) for x in r[3]))
    d2 = next(r for r in st if r[3][0] >= 79)
    for pid, r, lab in ((7, d1, 'Drag, Olympic City'), (8, d2, 'Drag, Bayview west')):
        props.append(dict(id=pid, kind='drag', src='new', label=lab, length=r[0], cover=1.0, poly=[r[1], r[2]], start=r[1], finish=r[2],
                          sub='new, %.0f m straight, WORLD sections %s' % (r[0], r[3][:3])))
    # drift: UG2's shortest drift route
    props.append(ug2_prop(9, 4176, 'drift', 'SH Drift Medium #1'))
    # rival challenges: shortest net path from where a rival is met to a destination in either city
    sq = (1687.0, -463.0)
    f4121 = props[2]['finish']
    anchor = (221.6, 401.5)
    s4121 = props[2]['start']
    f4122 = props[3]['finish']
    n1104f = props[5]['finish']
    for pid, a_, b_, lab in ((10, sq, n1104f, 'Challenge, Olympic City'), (11, anchor, f4121, 'Challenge over the bridge'), (12, s4121, f4122, 'Challenge, Bayview')):
        L, poly = W.path(a_, b_)
        props.append(dict(id=pid, kind='challenge', src='new', label=lab, length=L, cover=1.0, poly=poly, start=poly[0], finish=poly[-1],
                          sub='new, %.1f km on the WORLD net' % (L / 1000)))
    for p in props:
        print('%2d %-9s %-5s %s len %.0f m cover %.0f%% start (%.0f, %.0f) finish %s%s' % (
            p['id'], p['kind'], p['src'], p.get('tid', ''), p['length'], 100 * p['cover'], p['start'][0], p['start'][1],
            ('(%.0f, %.0f)' % p['finish']) if p.get('finish') else '-', ('  sections %d new %d waypoints %d' % (p['secs'], p['new'], p['nwp'])) if 'secs' in p else ''))
    # background
    bg_u = [[w2(n['x'], n['y']) for n in s['nodes']] for s in fr['sections']]
    bg_n = nfsu1_background()
    tour = [s['nodes'] for s in W.secs if s['id'] < 79]
    ug2net = [s['nodes'] for s in W.secs if s['id'] >= 79]
    draw(props, bg_n, bg_u, tour, ug2net, a.out)
    print('wrote', a.out)
    return props


if __name__ == '__main__':
    main()
