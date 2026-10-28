#!/usr/bin/env python3
"""barset.py: which barricade placements of STREAML1RA.BUN belong to a street closure, and which smackable class (if any) the exe
builds for each barricade model (phase D2; rules and addresses in docs/openworld/d2.md).

Pool: placements of the barrier models XO_TRACKBARRIER* / XO_TRACKTURNBARRIER* in the per-track Z sections 2601..2617 (2609 is the
slot of track 1101, which has no street track). One barricade = one (model, position 0.1 m, rotation) over the tracks that carry it.
Set (no tuned distance): a barricade is in the set when the placement AABB of one of its own rows (s16 xyz min/max at row +0, world
metres, the box the section BVH 0x446140 and the draw 0x445ec0 use) intersects, in xy, the base segment of a fence wall of the SAME
track (census/openworld_fences.json: walls that the track carries and another track drives through).
Class: the smackable body is the class hull (shape verts 0x39201, loader 0x472b00/0x472c60; body frame = model frame, 0x597140 + 0x472e40)
so a class fits a model when its hull box equals the model's solid box (0x134011 +0x20/+0x30). Metric: largest face difference in
metres, ranked over all 77 classes and compared with the 68 model/class pairs the game ships (STREETSIGN_B has two hulls: pairs listed,
excluded from the statistics). Nothing is chosen here: `class` stays null unless the OWNER's decision is passed as MODEL=CLASS.
usage: python3 tools/openworld/barset.py [MODEL=CLASS ...]   -> census/openworld_barricades.json, census/openworld_barricade_class.json"""
import collections, json, os, pickle, struct, sys
sys.dont_write_bytecode = True
HERE = os.path.dirname(os.path.abspath(__file__))
REPO = os.path.abspath(os.path.join(HERE, '..', '..'))
sys.path.insert(0, HERE)
import mesh  # noqa: E402
import polys  # noqa: E402  (also puts ref/tools on the path)
import numpy as np  # noqa: E402
from lib import load, find, trackb_path  # noqa: E402


def hulls(track=1001):
    """class shape name -> raw hull verts box, from the 0x80034020 shape container of a TRACKB (loader 0x472b00: groups 0x39200 header /
    0x39201 48-byte vertex entries, xyz at +0x10 / 0x39202 adjacency; payload start (chunk+0x17)&~0xf). -> {name: dict(key, n, mn, mx)}"""
    d = load(trackb_path(polys.PC, track))
    (b, s), = find(d, 0x80034020)
    o, e, kids = b, b + s, []
    while o < e:
        i, sz = struct.unpack_from('<II', d, o)
        kids.append((o, i, sz))
        o += 8 + sz
    out = {}
    k = 0
    while k < len(kids):
        o, i, sz = kids[k]
        assert i == 0x39200 and kids[k + 1][1] == 0x39201 and kids[k + 2][1] == 0x39202
        a = (o + 0x17) & ~0xf
        key = struct.unpack_from('<I', d, a + 0x18)[0]
        nm = d[a + 0x1c:a + 0x3c].split(b'\0')[0].decode('latin1')
        ob, _, sb = kids[k + 1]
        va = (ob + 0x17) & ~0xf
        n = (ob + 8 + sb - va) // 48
        V = np.array([struct.unpack_from('<3f', d, va + 48 * j + 16) for j in range(n)])
        out.setdefault(nm, dict(key=key, n=n, mn=V.min(0).tolist(), mx=V.max(0).tolist()))  # first row wins, as the class list does
        k += 3
    return out

SEC = {1001: 2601, 1002: 2602, 1003: 2603, 1004: 2604, 1005: 2605, 1006: 2606, 1007: 2607, 1008: 2608,
       1102: 2610, 1103: 2611, 1104: 2612, 1105: 2613, 1106: 2614, 1107: 2615, 1108: 2616, 1109: 2617}


def isbar(n):
    return bool(n) and (n.startswith('XO_TRACKBARRIER') or n.startswith('XO_TRACKTURNBARRIER'))


def seg_rect(a, b, r):
    """closed segment a-b vs closed rectangle r=(x0,y0,x1,y1) (Liang-Barsky)"""
    (x0, y0), (x1, y1) = a, b
    dx, dy = x1 - x0, y1 - y0
    t0, t1 = 0.0, 1.0
    for p, q in ((-dx, x0 - r[0]), (dx, r[2] - x0), (-dy, y0 - r[1]), (dy, r[3] - y0)):
        if p == 0:
            if q < 0:
                return False
        else:
            u = q / p
            if p < 0:
                if u > t1:
                    return False
                t0 = max(t0, u)
            else:
                if u < t0:
                    return False
                t1 = min(u, t1)
    return True


def main():
    B = mesh.Bun()
    S, order = mesh.solids(B)
    secs = {s['id']: s for s in mesh.sections(B) if 2600 <= s['id'] < 2700}
    fences = json.load(open(os.path.join(REPO, 'census', 'openworld_fences.json')))['fences']
    bytrack = collections.defaultdict(list)
    for f in fences:
        for o in f['owners']:
            bytrack[o].append(f)
    dd = collections.OrderedDict()
    pool_rows = 0
    for tr, sid in SEC.items():
        s = secs[sid]
        for k, (aabb, dfn, fl, pos, rot) in enumerate(s['places']):
            h = s['defs'][dfn][0][0]
            nm = S[h]['name'] if h in S else None
            if not isbar(nm):
                continue
            pool_rows += 1
            key = (nm, round(pos[0], 1), round(pos[1], 1), round(pos[2], 1), tuple(round(float(x), 2) for row in rot.tolist() for x in row))
            if key not in dd:
                dd[key] = dict(model=nm, hash=h, pos=[round(float(x), 3) for x in pos], rot=[[round(float(x), 5) for x in row] for row in rot.tolist()], src=[])
            r = (aabb[0], aabb[1], aabb[3], aabb[4])
            hits = sorted({f['key'] for f in bytrack[tr] if seg_rect(f['seg'][0], f['seg'][1], r)})
            dd[key]['src'].append(dict(track=tr, section=sid, placement=k, aabb=list(aabb), fence_hits=hits))
    out = []
    for v in dd.values():
        if not any(s['fence_hits'] for s in v['src']):
            continue
        rot = np.array(v['rot'])
        v['heading_rad'] = round(float(np.arctan2(rot[0][1], rot[0][0])), 5)
        v['fence_keys'] = sorted({k for s in v['src'] for k in s['fence_hits']})
        out.append(v)
    # class fit: hull box (raw shape verts) vs model solid box
    P = json.load(open(os.path.join(REPO, 'census', 'openworld_props.json')))
    H = hulls()
    byname = {s['name']: s for s in S.values()}

    def dev(hn, mn):
        h, s = H[hn], byname[mn]
        a = np.array(h['mn'] + h['mx'])
        b = np.array(list(s['bmin']) + list(s['bmax']))
        return float(np.abs(a - b).max())
    ship = sorted((dev(c['name'], m), c['name'], m) for c in P['classes'] for m in (c.get('models') or {}) if m in byname and c['name'] in H)
    fit = {}
    for mn in sorted({v['model'] for v in out}):
        r = sorted((dev(h, mn), h) for h in H)
        fit[mn] = dict(model_box=[list(map(lambda x: round(x, 3), byname[mn]['bmin'])), list(map(lambda x: round(x, 3), byname[mn]['bmax']))],
                       best=[dict(dist_m=round(d, 3), cls=h, hull=[[round(x, 3) for x in H[h]['mn']], [round(x, 3) for x in H[h]['mx']]]) for d, h in r[:4]])
    med = ship[len(ship) // 2][0]
    ckey = {c['name']: c['key'] for c in P['classes']}
    choice = dict(a.split('=') for a in sys.argv[1:])
    for mn, f in fit.items():
        f['class'] = choice.get(mn)
        f['class_key'] = ckey[f['class']] if f['class'] else None
    for v in out:
        v['class'] = fit[v['model']]['class']
        v['class_key'] = fit[v['model']]['class_key']
    nd = sorted(d for d, c, m in ship if c != 'CS_STREETSIGN_B')
    json.dump(dict(shipped_pairs=len(ship), shipped_median_m_without_STREETSIGN_B=round(nd[len(nd) // 2], 3), shipped_p75_m=round(nd[len(nd) * 3 // 4], 3), shipped_dist_m=[[round(d, 3), c, m] for d, c, m in ship], fit=fit),
              open(os.path.join(REPO, 'census', 'openworld_barricade_class.json'), 'w'), indent=1)
    json.dump(dict(criterion=__doc__.split('Set (no tuned distance):')[1].split('Class:')[0].strip(), pool_rows=pool_rows, unique_pool=len(dd),
                   count=len(out), barricades=out), open(os.path.join(REPO, 'census', 'openworld_barricades.json'), 'w'))
    print('pool rows', pool_rows, 'unique', len(dd), 'in set', len(out), dict(collections.Counter(v['model'] for v in out)))
    for mn, f in fit.items():
        print(mn, f['best'][0]['cls'], f['best'][0]['dist_m'], '->', f['class'])


if __name__ == '__main__':
    main()
