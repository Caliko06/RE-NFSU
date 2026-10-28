"""barricades.py: the breakable-barricade section of the open world (phase D2, docs/openworld/re_barricade.md, d2.md).

One stream section (0x80034100, id 2609, a slot no street track uses) holds the 690 barricade placements of
census/openworld_barricades.json (copied verbatim from the Z sections 2601..2617 of STREAML1RA.BUN, the closures at the old fences),
and one instance row (0x34027, 0x70 B) per placement makes it smackable (class = census/openworld_barricades.json class_key, set by
tools/openworld/barset.py from the OWNER's decision; models without a class are left out).
API: build() -> (section bytes, instance rows, stats); selftest() rebuilds the original section 2609 byte for byte.
usage: python3 tools/openworld/barricades.py selftest | build OUT.bin [ID]"""
import collections, itertools, json, os, struct, sys
sys.dont_write_bytecode = True
HERE = os.path.dirname(os.path.abspath(__file__))
REPO = os.path.abspath(os.path.join(HERE, '..', '..'))
sys.path.insert(0, HERE)
import mesh  # noqa: E402

SID = 2609
BARRICADES = os.path.join(REPO, 'census', 'openworld_barricades.json')

def chunk(base, cid, data, align):
    """chunk at absolute offset base; align=True pads (0x11) so the payload starts at (hdr+0x17)&~0xf. -> bytes"""
    pad = (((base + 0x17) & ~0xf) - (base + 8)) if align else 0
    body = b'\x11' * pad + data
    return struct.pack('<II', cid, len(body)) + body

def section(base, sid, defs, places, nodes):
    """defs: list of 72-byte records; places: list of 48-byte rows; nodes: list of 24-byte BVH nodes. base = absolute offset of the container."""
    body = b''
    pos = base + 8
    for cid, data, al in ((0x34101, b'\0' * 12 + struct.pack('<I', sid) + b'\0' * 44, False), (0x34103, b''.join(places), True),
                          (0x34102, b''.join(defs), False), (0x34104, b''.join(nodes), False)):
        c = chunk(pos, cid, data, al)
        body += c
        pos += len(c)
    return struct.pack('<II', 0x80034100, len(body)) + body

def bvh(places):
    """BVH nodes for the 48-byte placement rows (loader 0x4457c0 keeps [sec+0x28]=chunk data, count=size/24; walk 0x446140):
    24 B node = s16 min xyz, s16 max xyz, s16 n (<=5), 5 x s16 entries (>=0 placement index, <0 child node |e|). Root = node 0.
    Fan-out 5, split on the longest axis; nodes are numbered breadth-first (children after parents)."""
    P = [(i, struct.unpack_from('<6h', r, 0)) for i, r in enumerate(places)]
    def box(its):
        return (min(a[0] for _, a in its), min(a[1] for _, a in its), min(a[2] for _, a in its),
                max(a[3] for _, a in its), max(a[4] for _, a in its), max(a[5] for _, a in its))
    def split(its):
        if len(its) <= 5:
            return ('leaf', its)
        b = box(its)
        ax = max(range(3), key=lambda k: b[3 + k] - b[k])
        its = sorted(its, key=lambda it: it[1][ax] + it[1][3 + ax])
        sz = -(-len(its) // 5)
        return ('node', [split(its[j:j + sz]) for j in range(0, len(its), sz)])
    def items_of(t):
        return t[1] if t[0] == 'leaf' else [x for c in t[1] for x in items_of(c)]
    ts = [split(P)]
    i = 0
    while i < len(ts):
        if ts[i][0] == 'node':
            ts.extend(ts[i][1])
        i += 1
    pos = {id(t): k for k, t in enumerate(ts)}
    res = []
    for t in ts:
        ent = [it[0] for it in t[1]] if t[0] == 'leaf' else [-pos[id(c)] for c in t[1]]
        res.append(struct.pack('<6h', *box(items_of(t))) + struct.pack('<h', len(ent)) + struct.pack('<5h', *(ent + [0] * (5 - len(ent)))))
    return res

def selftest():
    B = mesh.Bun(); d = B.d
    # find the 0x80034100 of id 2609 and its children
    t = B.t
    for k, (dep, i, b, s) in enumerate(t):
        if i == 0x80034100:
            q, l = B.pay(t[k + 1][2], t[k + 1][3])
            if struct.unpack_from('<I', d, q + 12)[0] == 2609:
                base = b - 8; end = b + s; break
    ch = {}
    j = k + 1
    while t[j][2] < end:
        dep2, i2, b2, s2 = t[j]; ch[i2] = (b2, s2); j += 1
    defs = [d[o:o + 72] for o in range(ch[0x34102][0], ch[0x34102][0] + ch[0x34102][1] - 71, 72)]
    q, l = B.pay(*ch[0x34103])
    places = [d[o:o + 48] for o in range(q, q + l - 47, 48)]
    nodes = [d[o:o + 24] for o in range(ch[0x34104][0], ch[0x34104][0] + ch[0x34104][1] - 23, 24)]
    out = section(base, 2609, defs, places, nodes)
    orig = d[base:end]
    print('rebuild 2609 byte-exact:', out == orig, len(out), len(orig))
    # BVH writer: same children set as the original? compare leaf coverage
    mine = bvh(places)
    cover = set(); 
    for n in mine:
        c = struct.unpack_from('<h', n, 12)[0]
        for e in struct.unpack_from('<5h', n, 14)[:c]:
            if e >= 0: cover.add(e)
    print('bvh nodes', len(mine), 'orig', len(nodes), 'placements covered', len(cover), '/', len(places))

def build(sid=SID):
    """-> (section bytes, [0x70-byte instance rows ordered by placement index], stats)"""
    import numpy as np
    B = mesh.Bun(); d = B.d
    S, order = mesh.solids(B)
    raw = {}
    t = B.t
    for k, (dep, i, b, s) in enumerate(t):
        if i != 0x80034100: continue
        j = k + 1; ch = {}
        while j < len(t) and t[j][2] < b + s:
            ch[t[j][1]] = t[j][2:]; j += 1
        q, l = B.pay(*ch[0x34101]); id_ = struct.unpack_from('<I', d, q + 12)[0]
        q3, l3 = B.pay(*ch[0x34103])
        raw[id_] = ([d[o:o + 72] for o in range(ch[0x34102][0], ch[0x34102][0] + ch[0x34102][1] - 71, 72)],
                    [d[o:o + 48] for o in range(q3, q3 + l3 - 47, 48)])
    J = json.load(open(BARRICADES))['barricades']
    defs, dmap, places, inst, per = [], {}, [], [], collections.Counter()
    for b in J:
        if not b.get('class_key'):
            continue  # no class chosen for this model: a placement without a body would be a ghost (census/openworld_barricade_class.json)
        s0 = b['src'][0]
        D, Pl = raw[s0['section']]
        row = bytearray(Pl[s0['placement']])
        dr = D[struct.unpack_from('<h', row, 12)[0]]
        if dr not in dmap: dmap[dr] = len(defs); defs.append(dr)
        struct.pack_into('<h', row, 12, dmap[dr])
        idx = len(places); places.append(bytes(row))
        key = int(b['class_key'], 16)
        h0 = struct.unpack_from('<I', dr, 0)[0]
        sol = S[h0]
        bmn, bmx = np.array(sol['bmin']), np.array(sol['bmax'])
        rot = np.array(struct.unpack_from('<9h', row, 0x1c), float).reshape(3, 3) / 8192.0
        pos = np.array(struct.unpack_from('<3f', row, 16))
        w = np.array(list(itertools.product(*zip(bmn, bmx)))) @ rot + pos
        mn, mx = w.min(0), w.max(0)
        r = struct.pack('<IhhI', key, sid, idx, h0) + struct.pack('<I', 0) + struct.pack('<3f', *mn) + struct.pack('<f', 0) + \
            struct.pack('<3f', *mx) + struct.pack('<f', 0) + struct.pack('<16f', *np.hstack([np.hstack([rot, np.zeros((3, 1))]).ravel(), pos, [1.0]]))
        assert len(r) == 0x70
        inst.append(r); per[b['model']] += 1
    nodes = bvh(places)
    sec = section(0, sid, defs, places, nodes)
    return sec, inst, dict(placements=len(places), defs=len(defs), bvh_nodes=len(nodes), section_bytes=len(sec),
                           instances=len(inst), per_model=dict(per))


if __name__ == '__main__':
    if sys.argv[1] == 'selftest':
        selftest()
    elif sys.argv[1] == 'build':
        sec, inst, st = build(int(sys.argv[3]) if len(sys.argv) > 3 else SID)
        open(sys.argv[2], 'wb').write(sec)
        open(sys.argv[2] + '.inst', 'wb').write(b''.join(inst))
        print(st)
