"""nfsu.py: write NFSU (PC 2003) stream chunks: solid lists 0x80134000, scenery sections 0x80034100, texture packs 0xb3300000.
Alignment (measured over all of STREAML1RA.BUN, loaders 0x40c690, 0x4457c0): leaves marked A16 start their payload at a 16-byte
boundary (0x11 filler, loader reads (chunk + 0x17) & ~0xf), vertices and texture data at a 128-byte boundary ((chunk + 0x87) & ~0x7f).
Positions are absolute inside the row blob; the row must be loaded at an address with the same value mod 128 (rows start at 0x800 multiples).
usage: nfsu.py selftest   (rebuilds every solid of STREAML1RA.BUN and compares bytes)"""
import struct, sys, os
sys.path.insert(0, os.path.dirname(__file__))
from bun import *

A16 = {0x134011, 0x134900, 0x134b02, 0x134b03, 0x34101, 0x34103}
A128 = {0x134b01, 0x33320002}


def leaf(pos, cid, data):
    """bytes of one leaf chunk whose header sits at pos."""
    a = 128 if cid in A128 else 16 if cid in A16 else 0
    pad = ((pos + 8 + a - 1) & ~(a - 1)) - (pos + 8) if a else 0
    body = b'\x11' * pad + data
    return struct.pack('<II', cid, len(body)) + body


def pad_to(pos, a):
    """0x0 chunk so that the next chunk header lands on a multiple of a (or b'' if already there)."""
    if pos % a == 0:
        return b''
    n = (-(pos + 8)) % a
    return struct.pack('<II', 0, n) + b'\0' * n


def container(pos, cid, parts):
    """parts: list of callables f(pos) -> bytes, written in order."""
    body = b''
    p = pos + 8
    for f in parts:
        c = f(p)
        body += c
        p += len(c)
    return struct.pack('<II', cid, len(body)) + body


def solid_header(s):
    """0x134011, 176 B. s: dict(hash, flags, ntris, ngroups? , bmin, bmax, mat, name, f14, f18)"""
    h = bytearray(176)
    struct.pack_into('<I', h, 0xc, s.get('flags', 0x13))
    struct.pack_into('<I', h, 0x10, s['hash'])
    struct.pack_into('<I', h, 0x14, s['f14'])
    struct.pack_into('<I', h, 0x18, s['f18'])
    struct.pack_into('<3f', h, 0x20, *s['bmin'])
    struct.pack_into('<3f', h, 0x30, *s['bmax'])
    struct.pack_into('<16f', h, 0x40, *s.get('mat', (1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1)))
    struct.pack_into('<II', h, 0x88, 0x12f800, 0x12f800)
    nm = s['name'].encode('latin1')[:27]
    h[0x94:0x94 + len(nm)] = nm
    return bytes(h)


def group_rec(g):
    """0x134b02 row, 60 B: f32 min @0, u32 index count @0xc, f32 max @0x10, u8 texture slot @0x1c, u8 light slot @0x20 (+19 B list),
    u32 start index @0x34 (u16 units; 0x40c890 turns it into a pointer), u32 vertex format flags @0x38 (bit 0 read by 0x40c9d0)."""
    r = bytearray(60)
    struct.pack_into('<3f', r, 0, *g['bmin'])
    struct.pack_into('<I', r, 0xc, g['nidx'])
    struct.pack_into('<3f', r, 0x10, *g['bmax'])
    r[0x1c] = g['tex']
    r[0x20:0x34] = g.get('slots', b'\xff' + b'\0' * 19)
    struct.pack_into('<II', r, 0x34, g['start'], g.get('flags', 0))
    return bytes(r)


def mesh_header(m):
    """0x134900, 64 B: +8 = 0x10, +0xc vertex format mask, +0x10 group count, +0x24 triangle count, +0x34 vertex count (the rest are
    runtime pointers the loader 0x40c690 fills)."""
    h = bytearray(64)
    struct.pack_into('<I', h, 8, 0x10)
    struct.pack_into('<II', h, 0xc, m.get('vfmt', 0), len(m['groups']))
    struct.pack_into('<I', h, 0x24, m['ntris'])
    struct.pack_into('<I', h, 0x34, m['nverts'])
    return bytes(h)


def solid(pos, s):
    """s: header fields + tex (list of hashes) + light (raw 0x134013 or None) + mesh dict(vb bytes, ib bytes, groups, ntris, nverts, vfmt)."""
    m = s['mesh']
    parts = [lambda p: leaf(p, 0x134011, solid_header(s)),
             lambda p: leaf(p, 0x134012, b''.join(struct.pack('<II', h, 0) for h in s['tex']))]
    if s.get('light') is not None:
        parts.append(lambda p: leaf(p, 0x134013, s['light']))
    parts.append(lambda p: container(p, 0x80134100, [
        lambda q: leaf(q, 0x134900, mesh_header(m)),
        lambda q: leaf(q, 0x134b01, m['vb']),
        lambda q: leaf(q, 0x134b02, b''.join(group_rec(g) for g in m['groups'])),
        lambda q: leaf(q, 0x134b03, m['ib'])]))
    return container(pos, 0x80134010, parts)


def list_header(listname, secname, n, version=0x1c):
    """0x134002, 128 B: +8 version 0x1c, +0xc solid count, +0x10 path char[56], +0x48 section name char[...]."""
    h = bytearray(128)
    struct.pack_into('<II', h, 8, version, n)
    a = listname.encode()[:55]; h[0x10:0x10 + len(a)] = a
    b = secname.encode()[:15]; h[0x48:0x48 + len(b)] = b
    return bytes(h)


def solid_list(pos, listname, secname, solids, head=None):
    """0x80134000: 0x80134001 (0x134002 header, 0x134003 sorted (hash, 0) pairs, empty 0x80134008) then the solids."""
    keys = sorted(s['hash'] for s in solids)
    parts = [lambda p: pad_to(p, 16),
             lambda p: container(p, 0x80134001, [
                 lambda q: leaf(q, 0x134002, head if head is not None else list_header(listname, secname, len(solids))),
                 lambda q: leaf(q, 0x134003, b''.join(struct.pack('<II', k, 0) for k in keys)),
                 lambda q: container(q, 0x80134008, [])])]
    for s in solids:
        parts.append(lambda p, s=s: solid(p, s))
    return container(pos, 0x80134000, parts)


# ---------------------------------------------------------------- self test: parse NFSU solids, rebuild, compare
def parse_solid(d, t, k):
    dep, i, p, n = t[k]
    s = dict(light=None)
    j = k + 1
    while j < len(t) and t[j][2] < p + n:
        _, c, p2, n2 = t[j]
        q = skip11(d, p2, n2) if c in A16 | A128 else p2
        L = p2 + n2 - q
        if c == 0x134011:
            h = d[q:q + 176]
            s.update(flags=struct.unpack_from('<I', h, 0xc)[0], hash=struct.unpack_from('<I', h, 0x10)[0],
                     f14=struct.unpack_from('<I', h, 0x14)[0], f18=struct.unpack_from('<I', h, 0x18)[0],
                     bmin=struct.unpack_from('<3f', h, 0x20), bmax=struct.unpack_from('<3f', h, 0x30), mat=struct.unpack_from('<16f', h, 0x40),
                     name=h[0x94:].split(b'\0')[0].decode('latin1'), rawhdr=bytes(h))
        elif c == 0x134012:
            s['tex'] = [struct.unpack_from('<I', d, o)[0] for o in range(p2, p2 + n2 - 7, 8)]
        elif c == 0x134013:
            s['light'] = bytes(d[p2:p2 + n2])
        elif c == 0x134900:
            hh = struct.unpack_from('<16I', d, q)
            m = dict(vfmt=hh[3], ntris=hh[9], nverts=hh[13]); s['mesh'] = m
        elif c == 0x134b01:
            m['vb'] = bytes(d[q:q + L])
        elif c == 0x134b02:
            m['groups'] = []
            for o in range(q, q + L - 59, 60):
                m['groups'].append(dict(bmin=struct.unpack_from('<3f', d, o), nidx=struct.unpack_from('<I', d, o + 0xc)[0],
                                        bmax=struct.unpack_from('<3f', d, o + 0x10), tex=d[o + 0x1c], slots=bytes(d[o + 0x20:o + 0x34]),
                                        start=struct.unpack_from('<I', d, o + 0x34)[0], flags=struct.unpack_from('<I', d, o + 0x38)[0],
                                        raw=bytes(d[o:o + 60])))
        elif c == 0x134b03:
            m['ib'] = bytes(d[q:q + L])
        j += 1
    return s


def selftest():
    import collections
    d = open_map(os.path.join(NFSU, 'game', 'Tracks', 'STREAML1RA.BUN'))
    t = tree(d)
    ok = bad = 0; why = collections.Counter(); hdr_bad = collections.Counter()
    for k, (dep, i, p, n) in enumerate(t):
        if i != 0x80134010:
            continue
        s = parse_solid(d, t, k)
        out = solid(p - 8, s)
        if out == bytes(d[p - 8:p + n]):
            ok += 1
            continue
        bad += 1
        h = solid_header(s)
        for o in range(0, 176, 4):
            if h[o:o + 4] != s['rawhdr'][o:o + 4]:
                hdr_bad[hex(o)] += 1
        for g in s['mesh']['groups']:
            if group_rec(g) != g['raw']:
                why['group'] += 1
        if len(out) != n + 8:
            why['len'] += 1
    print('solids rebuilt byte-exact %d, differ %d' % (ok, bad), dict(why), dict(hdr_bad.most_common(8)))
    # solid lists
    ok = bad = 0
    for k, (dep, i, p, n) in enumerate(t):
        if i != 0x80134000:
            continue
        sols = []; head = None
        j = k + 1
        while j < len(t) and t[j][2] < p + n:
            if t[j][1] == 0x80134010:
                sols.append(parse_solid(d, t, j))
            if t[j][1] == 0x134002:
                head = bytes(d[t[j][2]:t[j][2] + t[j][3]])
            j += 1
        out = solid_list(p - 8, '', '', sols, head)
        if out == bytes(d[p - 8:p + n]): ok += 1
        else: bad += 1
    print('solid lists rebuilt byte-exact %d, differ %d' % (ok, bad))


if __name__ == '__main__' and sys.argv[1:] == ['selftest']:
    selftest()


# ---------------------------------------------------------------- scenery section 0x80034100 (copied from build/openworld/scratch_bar/mksec.py,
# whose section() rebuilt NFSU section 2609 byte-exact)
def section(pos, sid, defs, places, nodes):
    """defs: 72 B records; places: 48 B rows; nodes: 24 B BVH nodes. Child order 0x34101, 0x34103, 0x34102, 0x34104 (as the game files)."""
    return container(pos, 0x80034100, [
        lambda p: leaf(p, 0x34101, b'\0' * 12 + struct.pack('<I', sid) + b'\0' * 44),
        lambda p: leaf(p, 0x34103, b''.join(places)),
        lambda p: leaf(p, 0x34102, b''.join(defs)),
        lambda p: leaf(p, 0x34104, b''.join(nodes))])


def bvh(places):
    """BVH for 48 B placement rows (loader 0x4457c0, walk 0x446140): 24 B node = s16 min xyz, s16 max xyz, s16 n (<= 5), 5 x s16 entries
    (>= 0 placement index, < 0 child node -e). Root = node 0, fan-out 5, split on the longest axis, nodes numbered breadth-first."""
    P = [(i, struct.unpack_from('<6h', r, 0)) for i, r in enumerate(places)]

    def box(its):
        return tuple(min(a[k] for _, a in its) for k in range(3)) + tuple(max(a[k] for _, a in its) for k in range(3, 6))

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


# ---------------------------------------------------------------- texture pack 0xb3300000 (inline pixels, no 0x33310003 stream rows)
def tpk(pos, header, texs, data_head):
    """texs: list of (record 124 B, compression 32 B, pixels). header = 0x33310001 payload (124 B), data_head = 0x33320001 payload (24 B).
    Layout as STREAML1RA.BUN: 0xb3310000 {01 header, 02 sorted (hash, 0), 04 records, 05 compression}, 0x0 pad, 0xb3320000 {0x33320001,
    0x0 pad (the loader 0x545580 takes the 3rd child after it: always present), 0x33320002 pixels at a 128 B boundary}. Record +0x30 =
    offset of the pixels from the 0x33320002 data start (each texture 128-aligned), +0x38 size. Arrays sorted by hash (0x53e400 bisects)."""
    texs = sorted(texs, key=lambda t: struct.unpack_from('<I', t[0], 0x24)[0])
    recs = []; pool = b''
    for r, c, px in texs:
        r = bytearray(r)
        pool += b'\0' * (-len(pool) % 128)
        struct.pack_into('<I', r, 0x30, len(pool)); struct.pack_into('<I', r, 0x38, len(px))
        pool += px; recs.append(bytes(r))
    keys = b''.join(struct.pack('<II', struct.unpack_from('<I', r, 0x24)[0], 0) for r in recs)

    def pad128(p):
        n = (-(p + 8)) % 128
        return struct.pack('<II', 0, n) + b'\0' * n
    return container(pos, 0xb3300000, [
        lambda p: container(p, 0xb3310000, [
            lambda q: leaf(q, 0x33310001, header),
            lambda q: leaf(q, 0x33310002, keys),
            lambda q: leaf(q, 0x33310004, b''.join(recs)),
            lambda q: leaf(q, 0x33310005, b''.join(c for _, c, _ in texs))]),
        lambda p: pad_to(p, 16),
        lambda p: container(p, 0xb3320000, [
            lambda q: leaf(q, 0x33320001, data_head),
            pad128,
            lambda q: leaf(q, 0x33320002, pool)])])
