#!/usr/bin/env python3
"""ug2_gaps_map.py: map of the full UG2 Bayview vs what the port draws and drives today (plan row 12, first deliverable).

usage: .venv/bin/python -I tools/probe/ug2_gaps_map.py [--city web/ug2/city.bin] [--out web/plan/shots/ug2_bayview_gaps.png]
Reads only the UG2 install (STREAML4R?.BUN, L4R?.BUN, ROUTESL4RA, TRACKMAP4000, GLOBALB.BUN), web/ug2/city.bin, and the repo decoders
(ug2_world, ug2_roads, ug2_traffic, ug2_tex). Prints every number used in census/ug2/bayview_gaps.md. Writes no game file.
Frame of the main panel: raw UG2 units (x east, y north) = the frame of STREAML4RA, of TRACKMAP4000 and of PathsFreeRoam.bin.
Window of the picture: X0 -3425.43, Y0 3287.26, S 5633.16 (GLOBALB 0x34201 row 4000, census/ug2/map.md section 2).
Layouts decoded here (addresses in census/ug2/names.tsv):
  L4R?.BUN chunk 0x34110 = StreamSection table, 80 B entries (loader 0x5da7a0): +0 name u32 ('A21'), +8 section id, +0x14 offset in STREAML4R?.BUN,
  +0x24 f32 x,y,z. PathsFreeRoam.bin chunk 0x3414a = 671 records: +0 type, +0x20 f32 bbox, +0x30 name hash (cshash 0x43db50), +0x40 u16 n, u16 id,
  +0x44 n x f32 (x,y); type 0x11 records whose hash is one of the 13 district names at 0x7a50cc.. are the district polygons."""
import argparse, bisect, collections, math, os, struct, sys
import numpy as np
from PIL import Image, ImageDraw, ImageFont

HERE = os.path.dirname(os.path.abspath(__file__))
REPO = os.path.abspath(os.path.join(HERE, '..', '..'))
sys.path.insert(0, os.path.join(REPO, 'tools'))
os.environ.setdefault('NFSU1_MAIN', REPO)
import ug2_world as W      # noqa: E402
import ug2_roads as R      # noqa: E402
import ug2_traffic as U    # noqa: E402
import ug2_tex as X        # noqa: E402

T = W.TRACKS
UG2 = os.path.dirname(T)
X0, Y0, S = -3425.4299, 3287.2600, 5633.1602
DISTRICTS = ['JACKSON_HEIGHTS', 'PIGEON_PARK', 'BEACON_HILL_EAST', 'BEACON_HILL_WEST', 'HOTELS', 'FINANCE', 'FORT_UNION', 'EL_NORTE',
             'SOUTH_MARKET', 'STADIUM', 'AIRPORT', 'COAL_HARBOUR_EAST', 'COAL_HARBOUR_WEST']   # table at 0x800c38 (reverse order in file)
MOUTH = U.MOUTH
# gap badges on the map (ids match census/ug2/bayview_gaps.md): G1 no traffic (south, ring, north-west), G2 sky sheets, G3 scenery beyond reach,
# G5 airport past the data edge, G8 RD-only scenery
GAP_TAGS = [('G1', -1500, -1500), ('G1', 1081, -93), ('G1', -2100, 1900), ('G2', -1050, 1670), ('G3', -1450, -1990), ('G5', 2040, -520), ('G8', 90, -760)]
CELL, O, N = 8.0, -8192.0, 2048
FONT = '/System/Library/Fonts/Supplemental/Arial.ttf'
FONTB = '/System/Library/Fonts/Supplemental/Arial Bold.ttf'


def cshash(s):
    x = 0xffffffff
    for c in s.encode():
        x = (x * 33 + c) & 0xffffffff
    return x


def kids(d, p, e):
    while p + 8 <= e:
        i, s = struct.unpack_from('<II', d, p)
        yield i, p + 8, s
        p += 8 + s


def stream_table(L):
    d = open('%s/L4R%s.BUN' % (T, L), 'rb').read()
    for i, b, s in kids(d, 0, len(d)):
        if i == 0x34110:
            out = []
            for k in range(s // 80):
                e = struct.unpack_from('<20I', d, b + 80 * k)
                out.append(dict(name=struct.pack('<I', e[0]).split(b'\0')[0].decode('latin1'), id=e[2], off=e[5], size=e[7],
                                pos=struct.unpack('<3f', struct.pack('<3I', e[9], e[10], e[11]))))
            return out


def coll_sections(L):
    """one dict per 0x80034130 chunk: file offset, ground-row bbox (x0, y0, x1, y1), rows, ground rows, all-row centres"""
    d = open('%s/STREAML4R%s.BUN' % (T, L), 'rb').read()
    out = []
    for i, b, s in kids(d, 0, len(d)):
        if i != 0x80034130:
            continue
        ch = {j: (b2, s2) for j, b2, s2 in kids(d, b, b + s)}
        b3, s3 = ch[0x34134]
        r = np.frombuffer(d, np.uint8, count=s3 // 32 * 32, offset=b3).reshape(-1, 32)
        sid = struct.unpack_from('<H', d, ch[0x34131][0])[0]
        if len(r) == 0:
            out.append(dict(off=b - 8, id=sid, n=0, g=0, bb=None, xy=np.zeros((0, 2)), gxy=np.zeros((0, 2)), barrier=0))
            continue
        x = r[:, 8:16].copy().view('<i2').astype(float) / 8
        y = r[:, 16:24].copy().view('<i2').astype(float) / 8
        m = np.ones_like(x, bool)
        m[:, 3] = (r[:, 3] & 0x10) != 0
        gr = (r[:, 3] & 0x0a) == 0
        ok = r[:, 0] == 0                                  # barrier-group rows are off in free roam (ug2_coll.py)
        c = np.c_[x[:, :3].mean(1), y[:, :3].mean(1)]
        gm = gr & ok
        bb = (x[gm][m[gm]].min(), y[gm][m[gm]].min(), x[gm][m[gm]].max(), y[gm][m[gm]].max()) if gm.any() else None
        out.append(dict(off=b - 8, id=sid, n=len(r), g=int(gm.sum()), bb=bb, xy=c[ok], gxy=c[gm], barrier=int((~ok).sum())))
    return out


def districts():
    d = open('%s/ROUTESL4RA/PathsFreeRoam.bin' % T, 'rb').read()
    H = {cshash(n): n for n in DISTRICTS}
    p = 0x10
    out = {}
    end = 0x10 + 69628                                       # chunk 0x3414a (container 0x80034147 @0)
    while p + 0x44 <= end:
        ty, = struct.unpack_from('<I', d, p)
        bb = struct.unpack_from('<4f', d, p + 0x20)
        h, = struct.unpack_from('<I', d, p + 0x30)
        n, i = struct.unpack_from('<HH', d, p + 0x40)
        pts = [struct.unpack_from('<2f', d, p + 0x44 + 8 * k) for k in range(n)]
        if ty == 0x11 and h in H:
            out[H[h]] = dict(bb=bb, pts=pts, off=p)
        p += 0x44 + 8 * n
    assert p == end
    return out


def inside(poly, x, y):
    ins = np.zeros(np.shape(x), bool)
    n = len(poly)
    for a in range(n):
        xa, ya = poly[a]
        xb, yb = poly[(a + 1) % n]
        if yb == ya:
            continue
        ins ^= ((ya > y) != (yb > y)) & (x < (xb - xa) * (y - ya) / (yb - ya) + xa)
    return ins


def dil(m, r):
    c = np.cumsum(np.cumsum(np.pad(m.astype(np.int32), ((r + 1, r), (r + 1, r))), 0), 1)
    k = 2 * r + 1
    s = c[k:, k:] - c[:-k, k:] - c[k:, :-k] + c[:-k, :-k]
    return s[:m.shape[0], :m.shape[1]] > 0


def classify_instances(coll):
    """the ug2_world.py main() filters on RA, one category per instance: -> list (x, y, cat)"""
    d, sol, secs = W.scan(T + '/STREAML4RA.BUN')
    cx, cy = np.concatenate([c['xy'][:, 0] for c in coll if c['n']]), np.concatenate([c['xy'][:, 1] for c in coll if c['n']])
    foot = np.zeros((16384 // W.CELL, 16384 // W.CELL), bool)
    foot[((cx + 8192) // W.CELL).astype(int), ((cy + 8192) // W.CELL).astype(int)] = True
    for _ in range(W.REACH // W.CELL):
        g = foot.copy(); g[1:] |= foot[:-1]; g[:-1] |= foot[1:]; g[:, 1:] |= foot[:, :-1]; g[:, :-1] |= foot[:, 1:]; foot = g
    out, seen = [], set()
    for defs, inst in secs:
        for r in inst:
            w = r.tobytes()
            di, fl = struct.unpack_from('<HH', w, 24)
            bb = struct.unpack_from('<6f', w, 0)
            px, py = struct.unpack_from('<2f', w, 32)
            if di >= len(defs):
                out.append((px, py, 'bad def')); continue
            if fl & W.HIDDEN:
                out.append((px, py, 'hidden')); continue
            hh = defs[di][0] if defs[di][0] in sol else defs[di][1]
            if hh in sol and sol[hh]['name'].upper().startswith(W.SKIP):
                out.append((px, py, 'sky/panorama')); continue
            i, j = int((bb[0] + bb[3]) / 2 + 8192) // W.CELL, int((bb[1] + bb[4]) / 2 + 8192) // W.CELL
            if not (0 <= i < foot.shape[0] and 0 <= j < foot.shape[1] and foot[i, j]):
                out.append((px, py, 'beyond reach')); continue
            key = (hh, w[32:62])
            if key in seen:
                out.append((px, py, 'duplicate')); continue
            seen.add(key)
            out.append((px, py, 'no solid' if hh not in sol else 'drawn'))
    return out


def rd_diff():
    """instances keyed (solid hash, position + matrix bytes) as ug2_world.py dedups them: RA only vs RD only"""
    ks = {}
    for L in 'AD':
        d, sol, secs = W.scan('%s/STREAML4R%s.BUN' % (T, L))
        ks[L] = {}
        for defs, inst in secs:
            for r in inst:
                w = r.tobytes()
                di, fl = struct.unpack_from('<HH', w, 24)
                if di < len(defs):
                    ks[L][(defs[di][0], w[32:62])] = (fl & W.HIDDEN != 0, struct.unpack_from('<2f', w, 32))
    both = ks['A'].keys() & ks['D'].keys()
    for a, b in (('A', 'D'), ('D', 'A')):
        only = [v for k, v in ks[a].items() if k not in ks[b]]
        vis = [v[1] for v in only if not v[0]]
        print('instances only in R%s: %d (%d hidden by flag 0x10, %d visible%s)' % (a, len(only), sum(v[0] for v in only), len(vis),
              ', at x %.0f..%.0f y %.0f..%.0f' % (min(p[0] for p in vis), max(p[0] for p in vis), min(p[1] for p in vis), max(p[1] for p in vis)) if vis else ''))
    print('instances in both RA and RD: %d' % len(both))


def seg_len(a, b):
    return math.dist((a['x'], a['y']), (b['x'], b['y']))


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--city', default=None)
    ap.add_argument('--out', default=os.path.join(REPO, 'web', 'plan', 'shots', 'ug2_bayview_gaps.png'))
    a = ap.parse_args()
    city = a.city or next(p for p in (os.path.join(REPO, 'web/ug2/city.bin'), '/Users/angeldamian/RE-NFSU/web/ug2/city.bin') if os.path.exists(p))
    print('city.bin', city)

    # ---- STREAML4R? footprints
    files = {}
    for L in 'ABCDFGHR':
        tb, cs = stream_table(L), coll_sections(L)
        ex = np.concatenate([c['gxy'] for c in cs if c['g']])
        files[L] = dict(table=tb, coll=cs, size=os.path.getsize('%s/STREAML4R%s.BUN' % (T, L)), ext=(ex[:, 0].min(), ex[:, 1].min(), ex[:, 0].max(), ex[:, 1].max()))
        print('STREAML4R%s %d B, %d table entries, %d collision sections, %d ground rows, ground extent x %.0f..%.0f y %.0f..%.0f' % (
            L, files[L]['size'], len(tb), len(cs), sum(c['g'] for c in cs), ex[:, 0].min(), ex[:, 0].max(), ex[:, 1].min(), ex[:, 1].max()))
    A = files['A']
    coll = A['coll']

    # ---- what draws: city.bin vertex coverage
    h = open(city, 'rb').read(16)
    nv = struct.unpack_from('<I', h, 4)[0]
    P = np.fromfile(city, dtype=[('p', '<f4', 3), ('c', 'u1', 4)], count=nv, offset=16)['p']
    ii, jj = ((P[:, 0] - O) / CELL).astype(int), ((P[:, 1] - O) / CELL).astype(int)
    ok = (ii >= 0) & (ii < N) & (jj >= 0) & (jj < N)
    D = np.zeros((N, N), bool)
    D[ii[ok], jj[ok]] = True
    print('city.bin vertices %d, bbox x %.0f..%.0f y %.0f..%.0f' % (nv, P[:, 0].min(), P[:, 0].max(), P[:, 1].min(), P[:, 1].max()))
    near40 = dil(D, 5)
    G = np.zeros((N, N), bool)
    gx = np.concatenate([c['gxy'] for c in coll if c['g']])
    G[((gx[:, 0] - O) / CELL).astype(int), ((gx[:, 1] - O) / CELL).astype(int)] = True
    print('ground-collision cells (8 m) %d, without city.bin vertex within 40 m: %d' % (G.sum(), (G & ~near40).sum()))

    rd_diff()
    inst = classify_instances(coll)
    cnt = collections.Counter(c for _, _, c in inst)
    print('RA instances %d: %s' % (len(inst), dict(cnt)))

    # ---- road graph and traffic subset
    g = R.load('A')
    keep, skipped = U.select(g, 175)
    K = set(keep)
    secs = g['sections']
    tot = sum(seg_len(x, y) for s in secs for x, y in zip(s['nodes'], s['nodes'][1:])) / 1000
    tk = sum(seg_len(x, y) for s in secs if s['id'] in K for x, y in zip(s['nodes'], s['nodes'][1:])) / 1000
    print('road graph: %d sections, %.1f km; traffic net (budget 175 ids): %d sections, %.1f km, %d duplicates skipped' % (len(secs), tot, len(K), tk, skipped))
    bycls = collections.defaultdict(lambda: [0, 0, 0.0, 0.0])
    for s in secs:
        c = bycls[s['cls'][-2:]]
        L = sum(seg_len(x, y) for x, y in zip(s['nodes'], s['nodes'][1:])) / 1000
        c[0] += 1; c[2] += L
        if s['id'] in K:
            c[1] += 1; c[3] += L
    for k in sorted(bycls):
        c = bycls[k]
        print('  class A%s: %3d sections %5.1f km, in traffic %3d sections %5.1f km' % (k, c[0], c[2], c[1], c[3]))

    # ---- districts
    dist = districts()
    print('districts found in PathsFreeRoam.bin 0x3414a: %d of 13 (%s)' % (len(dist), ', '.join(sorted(dist))))
    print('missing:', [n for n in DISTRICTS if n not in dist])
    rows = []
    for n, dd in dist.items():
        poly = dd['pts']
        x0, y0, x1, y1 = dd['bb']
        xs = np.arange(x0, x1, CELL) + CELL / 2
        ys = np.arange(y0, y1, CELL) + CELL / 2
        XX, YY = np.meshgrid(xs, ys, indexing='ij')
        ins = inside(poly, XX, YY)
        ci, cj = ((XX - O) / CELL).astype(int), ((YY - O) / CELL).astype(int)
        area = ins.sum() * CELL * CELL / 1e6
        covered = (D[ci, cj] | near40[ci, cj]) & ins
        gcell = (G[ci, cj]) & ins
        rl = tl = 0.0
        for s in secs:
            for p, q in zip(s['nodes'], s['nodes'][1:]):
                mx, my = (p['x'] + q['x']) / 2, (p['y'] + q['y']) / 2
                if x0 <= mx <= x1 and y0 <= my <= y1 and inside(poly, np.array(mx), np.array(my)):
                    L = seg_len(p, q) / 1000
                    rl += L
                    tl += L if s['id'] in K else 0
        ex_ = A['ext']
        outside = ins & ((XX < ex_[0]) | (XX > ex_[2]) | (YY < ex_[1]) | (YY > ex_[3]))
        rows.append((n, area, 100 * covered.sum() / max(ins.sum(), 1), int(gcell.sum()), rl, tl, 100 * tl / max(rl, 1e-9), 100 * outside.sum() / max(ins.sum(), 1)))
    print('district | polygon km2 | % of polygon within 40 m of city.bin | ground cells | road km | km in traffic net | % | % of polygon outside the RA ground-collision box')
    for r in sorted(rows, key=lambda r: -r[1]):
        print('  %-18s %5.2f %5.1f %6d %6.1f %6.1f %5.1f %5.1f' % r)

    # ---- render
    SS = 2
    W_ = 1000 * SS
    sc = W_ / S

    def px(x, y):
        return ((x - X0) * sc, (Y0 - y) * sc)
    d0 = open('%s/TRACKMAP4000.BIN' % T, 'rb').read()
    pk = X.packs(d0)[0]
    tm = X.decode(d0, pk, pk['recs'][0], 'DXT5')[:, :, :3]
    base = Image.fromarray(tm).resize((W_, W_), Image.LANCZOS)
    base = Image.eval(base, lambda v: int(v * 0.55))
    img = base.convert('RGBA')
    ov = Image.new('RGBA', img.size, (0, 0, 0, 0))
    dr = ImageDraw.Draw(ov)
    f9, f10, f12 = (ImageFont.truetype(FONT, s * SS) for s in (9, 10, 12))
    fb11, fb13 = (ImageFont.truetype(FONTB, s * SS) for s in (11, 13))

    # city.bin coverage: teal fill per 8 m cell, 3x3 smoothed so thin geometry reads as a surface
    cov = dil(D, 1)
    ci, cj = np.nonzero(cov)
    cx_, cy_ = O + ci * CELL, O + cj * CELL
    m = (cx_ > X0 - 50) & (cx_ < X0 + S) & (cy_ < Y0 + 50) & (cy_ > Y0 - S)
    cvimg = Image.new('L', (W_, W_), 0)
    cd = ImageDraw.Draw(cvimg)
    for x, y in zip(cx_[m], cy_[m]):
        u, v = px(x, y)
        cd.rectangle([u, v - CELL * sc, u + CELL * sc, v], fill=255)
    cvimg = cvimg.filter(__import__('PIL.ImageFilter', fromlist=['x']).MaxFilter(3))
    ov.paste(Image.new('RGBA', img.size, (30, 190, 200, 70)), (0, 0), cvimg)

    # collision section footprints (ground-row bbox per 0x80034130 chunk)
    for c in coll:
        if c['bb']:
            x0, y0, x1, y1 = c['bb']
            (u0, v0), (u1, v1) = px(x0, y1), px(x1, y0)
            dr.rectangle([u0, v0, u1, v1], outline=(255, 255, 255, 70), width=1)
    # table entries with a centre but no collision: dots
    named = {c['id'] for c in coll}
    geo_only = [e for e in A['table'] if e['id'] not in named and e['id'] > 100 and e['id'] < 2400]
    for e in geo_only:
        u, v = px(e['pos'][0], e['pos'][1])
        r = 2.2 * SS
        dr.ellipse([u - r, v - r, u + r, v + r], outline=(120, 190, 255, 220), width=SS)

    # districts
    for n, dd in dist.items():
        pts = [px(x, y) for x, y in dd['pts']]
        dr.line(pts + [pts[0]], fill=(255, 215, 90, 230), width=2 * SS)
    # roads: untaken (no traffic) orange, taken lime; classes A30/A31 thicker (widest lanes, INFERENCE: highways)
    for pas in (0, 1):
        for s in secs:
            if (s['id'] in K) != bool(pas):
                continue
            hw = s['cls'][-2:] in ('30', '31')
            col = (120, 255, 90, 255) if pas else (255, 120, 30, 235)
            w = (3 if hw else 1.6) * SS if pas else (2.4 if hw else 1.2) * SS
            dr.line([px(n['x'], n['y']) for n in s['nodes']], fill=col, width=int(w))
    # dropped instances
    col_of = {'beyond reach': (255, 40, 60, 255), 'sky/panorama': (200, 120, 255, 255), 'no solid': (255, 255, 255, 255), 'bad def': (255, 255, 255, 255)}
    for x, y, c in inst:
        if c in col_of and X0 < x < X0 + S and Y0 - S < y < Y0:
            u, v = px(x, y)
            r = 4 * SS
            dr.line([u - r, v - r, u + r, v + r], fill=col_of[c], width=2 * SS)
            dr.line([u - r, v + r, u + r, v - r], fill=col_of[c], width=2 * SS)
    # data edge: RA ground-collision extent
    ex = A['ext']
    (u0, v0), (u1, v1) = px(ex[0], ex[3]), px(ex[2], ex[1])
    for k in range(int(u0), int(u1), 16 * SS):
        dr.line([k, v0, k + 8 * SS, v0], fill=(255, 60, 60, 200), width=SS)
        dr.line([k, v1, k + 8 * SS, v1], fill=(255, 60, 60, 200), width=SS)
    for k in range(int(v0), int(v1), 16 * SS):
        dr.line([u0, k, u0, k + 8 * SS], fill=(255, 60, 60, 200), width=SS)
        dr.line([u1, k, u1, k + 8 * SS], fill=(255, 60, 60, 200), width=SS)
    # bridge mouth
    u, v = px(*MOUTH)
    dr.ellipse([u - 7 * SS, v - 7 * SS, u + 7 * SS, v + 7 * SS], outline=(255, 255, 255, 255), width=2 * SS)
    # labels
    def label(txt, u, v, font, fill=(255, 235, 150, 255)):
        for dx, dy in ((-1, 0), (1, 0), (0, -1), (0, 1)):
            dr.text((u + dx * SS, v + dy * SS), txt, font=font, fill=(0, 0, 0, 255), anchor='mm')
        dr.text((u, v), txt, font=font, fill=fill, anchor='mm')
    for n, dd in dist.items():
        x0, y0, x1, y1 = dd['bb']
        label(n.replace('_', ' '), *px((x0 + x1) / 2, (y0 + y1) / 2), fb11)
    label('bridge mouth', u + 38 * SS, v + 14 * SS, f10, (255, 255, 255, 255))
    label('RA data edge (ground collision x %.0f..%.0f, y %.0f..%.0f)' % (ex[0], ex[2], ex[1], ex[3]), px((ex[0] + ex[2]) / 2, ex[1])[0], px(0, ex[1])[1] + 9 * SS, f9, (255, 120, 120, 255))
    img = Image.alpha_composite(img, ov)
    d2 = ImageDraw.Draw(img)

    def tag(t, x, y):
        u, v = px(x, y)
        r = 9 * SS
        d2.ellipse([u - r, v - r, u + r, v + r], fill=(255, 60, 60, 255), outline=(255, 255, 255, 255), width=SS)
        d2.text((u, v), t, font=fb11, fill=(255, 255, 255, 255), anchor='mm')
    for t, x, y in GAP_TAGS:
        tag(t, x, y)
    d2.text(px(1700, 520), 'outer ring highway (A30/A31 = widest lanes; INFERENCE)', font=f10, fill=(255, 190, 120, 255), anchor='rm')

    # legend (top-left corner = sea in the picture)
    lg = [((255, 255, 255, 120), 'rect', 'STREAML4RA collision section footprint (255; RD repeats them)'),
          ((120, 190, 255, 255), 'circ', 'table entry with scenery only, no collision (%d)' % len(geo_only)),
          ((30, 190, 200, 255), 'rect', 'city.bin geometry (RA only)'),
          ((120, 255, 90, 255), 'line', 'road in the traffic net (%d sections, %.0f of %.0f km)' % (len(K), tk, tot)),
          ((255, 120, 30, 255), 'line', 'road with NO traffic (%d sections, %.0f km)' % (len(secs) - len(K), tot - tk)),
          ((255, 215, 90, 255), 'line', 'district polygon (PathsFreeRoam.bin 0x3414a)'),
          ((255, 40, 60, 255), 'x', 'scenery dropped: beyond 160 m of collision (%d)' % cnt['beyond reach']),
          ((200, 120, 255, 255), 'x', 'scenery dropped: sky/panorama sheets (%d)' % cnt['sky/panorama']),
          ((255, 60, 60, 255), 'line', 'edge of the RA data (no collision beyond it)')]
    lw, lh = 392 * SS, (len(lg) * 15 + 30) * SS
    d2.rounded_rectangle([8 * SS, 8 * SS, 8 * SS + lw, 8 * SS + lh], radius=6 * SS, fill=(8, 14, 18, 215))
    d2.text((16 * SS, 14 * SS), 'UG2 Bayview vs what the port draws and drives  (G# = gap row, thick road = A30/A31)', font=fb11, fill=(255, 255, 255, 255))
    for k, (colr, kind, txt) in enumerate(lg):
        y = (36 + 15 * k) * SS
        x = 18 * SS
        if kind == 'rect':
            d2.rectangle([x, y - 4 * SS, x + 14 * SS, y + 4 * SS], outline=colr, fill=colr if colr[3] < 200 and colr[0] < 100 else None)
        elif kind == 'circ':
            d2.ellipse([x + 3 * SS, y - 4 * SS, x + 11 * SS, y + 4 * SS], outline=colr, width=SS)
        elif kind == 'x':
            d2.line([x + 3 * SS, y - 4 * SS, x + 11 * SS, y + 4 * SS], fill=colr, width=2 * SS)
            d2.line([x + 3 * SS, y + 4 * SS, x + 11 * SS, y - 4 * SS], fill=colr, width=2 * SS)
        else:
            d2.line([x, y, x + 14 * SS, y], fill=colr, width=2 * SS)
        d2.text((x + 22 * SS, y), txt, font=f9, fill=(230, 235, 240, 255), anchor='lm')
    main = img.resize((1000, 1000), Image.LANCZOS).convert('RGB')

    # ---- bottom strip: the six other bundles, each in its own frame
    names = {'B': 'RB drag (city/industrial/airport)', 'C': 'RC drift (stadium, vacant lot)', 'F': 'RF Street X', 'G': 'RG speedway',
             'H': 'RH perf. tuning', 'R': 'RR replay cams'}
    strip_h = 214
    out = Image.new('RGB', (1000, 1000 + strip_h), (10, 16, 20))
    out.paste(main, (0, 0))
    sd = ImageDraw.Draw(out)
    fs9, fs10 = ImageFont.truetype(FONT, 9), ImageFont.truetype(FONT, 10)
    fsb = ImageFont.truetype(FONTB, 10)
    sd.text((10, 1000 + 8), 'Other bundles: separate content in their own frames (no shared object at the same place as RA, row 1 + this map). UNKNOWN where each sits in Bayview.', font=fsb, fill=(255, 255, 255))
    cell_w = 1000 // 6
    for k, L in enumerate('BCFGHR'):
        fl = files[L]
        x0 = k * cell_w + 8
        box = cell_w - 16
        e = fl['ext']
        span = max(e[2] - e[0], e[3] - e[1])
        sd.rectangle([x0, 1000 + 26, x0 + box, 1000 + 26 + box], fill=(20, 30, 36), outline=(60, 80, 90))
        sc2 = (box - 8) / span
        ox = x0 + 4 + ((box - 8) - (e[2] - e[0]) * sc2) / 2
        oy = 1000 + 26 + 4 + ((box - 8) - (e[3] - e[1]) * sc2) / 2
        pts = np.concatenate([c['gxy'] for c in fl['coll'] if c['g']])
        im2 = np.zeros((box, box), np.uint8)
        ui = np.clip(((pts[:, 0] - e[0]) * sc2 + ox - x0).astype(int), 0, box - 1)
        vi = np.clip(((e[3] - pts[:, 1]) * sc2 + oy - 1000 - 26).astype(int), 0, box - 1)
        im2[vi, ui] = 255
        out.paste(Image.new('RGB', (box, box), (90, 200, 220)), (x0, 1000 + 26), Image.fromarray(im2).filter(__import__('PIL.ImageFilter', fromlist=['x']).MaxFilter(3)))
        t = fl['table']
        sd.text((x0, 1000 + 26 + box + 4), names[L], font=fsb, fill=(255, 255, 255))
        sd.text((x0, 1000 + 26 + box + 17), '%d sections, %d MB; %.1f x %.1f km' % (len(fl['coll']), fl['size'] >> 20, (e[2] - e[0]) / 1000, (e[3] - e[1]) / 1000), font=fs9, fill=(200, 210, 215))
        sd.text((x0, 1000 + 26 + box + 29), 'table %d entries' % len(t), font=fs9, fill=(200, 210, 215))
    os.makedirs(os.path.dirname(a.out), exist_ok=True)
    out.save(a.out)
    print('wrote', a.out, out.size)


if __name__ == '__main__':
    main()
