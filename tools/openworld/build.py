#!/usr/bin/env python3
"""build.py: the merged TRACKB<id>.lzc of the open world (phase D1, docs/OPENWORLD.md), one per L1RA street track.

Each file is that track's own TRACKB (roads, routes, markers, zones, preload flags, everything else) with
  - collision 0x34130..0x34134 rebuilt from the UNION of the 16 tracks' wsrc rows (polys.key identity), minus the
    1,149 fence walls of census/openworld_fences.json (answers 1, 2, 5 and build/openworld/re_coll.md);
  - props 0x34027 = union of the 16 tracks' instance rows (0x70 B, sorted by (section, index) like each original),
    classes 0x34026 are identical in the 16 and stay (build/openworld/re_props.md);
  - the nested chunks 0x34153 (look-ahead filter) and 0x34154 (route section 2601..2617) removed from the stream
    container 0x80034150 (build/openworld/re_stream.md); the preload flags 0x34107 stay the base track's;
  - the tail pads re-laid so 0x34027/0x80034150 stay 16-aligned and 0x8003b000/0x3b200/0x3b300 128-aligned
    (re_coll.md section 5).
Output: build/openworld/TRACKB<id>.lzc (JDLZ v2) and census/openworld_build.json. Self-checks every file (exit 1 on any
failure): JDLZ decode by the exe's own algorithm == the library decoder == the bytes written; wmap/wcell/widx equal to the
quadtree derived from the file's own wsrc; the sim of the exe's query (0x441c10) finds every sampled polygon and equals a
brute-force box test; every fence key absent; every other union row present; counts under the caps; chunk ids as the base.
Reuses tools/hopper/q_owcoll2_{gen,lzc,write,sim}.py (the exe-checked collision writer) and tools/openworld/polys.py.
usage: build.py [id ...]     (default: all 16)"""
import hashlib, json, os, random, struct, sys, time
HERE = os.path.dirname(os.path.abspath(__file__))
REPO = os.path.abspath(os.path.join(HERE, '..', '..'))
os.environ.setdefault('NFSU1_MAIN', REPO)
sys.path.insert(0, HERE)
sys.path.insert(0, os.path.join(REPO, 'tools', 'hopper'))
import polys  # noqa: E402  (also puts ref/tools/ug1-tracks on the path)
import q_owcoll2_gen as gen  # noqa: E402
import q_owcoll2_lzc as lzc  # noqa: E402
import q_owcoll2_sim as sim  # noqa: E402
import q_owcoll2_write as w  # noqa: E402
from lib import load, find, trackb_path, PC  # noqa: E402
from jdlz import jdlz_decompress  # noqa: E402

OUT = os.path.join(REPO, 'build', 'openworld')
FENCES = os.path.join(REPO, 'census', 'openworld_fences.json')
MANIFEST = os.path.join(REPO, 'census', 'openworld_build.json')
TRACKS = polys.TRACKS
DROP = (0x34153, 0x34154)
INST = 0x70


def chunk_data(d, cid):
    (b, s), = find(d, cid)
    return b, s


def union_rows(fence_keys):
    seen, rows, dropped = set(), [], 0
    for t in TRACKS:
        for r in polys.rows(t):
            k = polys.key(r)
            if k in seen:
                continue
            seen.add(k)
            if k.hex() in fence_keys:
                dropped += 1
                continue
            rows.append(w.row_key(r))     # byte +6 = 0xffff, as the loader leaves it
    return rows, len(seen), dropped


def union_props(bases):
    """(class chunk payload, instance rows sorted by (section, index))"""
    cls = None
    uniq = {}
    for t in TRACKS:
        d = bases[t]
        b, s = chunk_data(d, 0x34026)
        c = bytes(d[b:b + s])
        assert cls is None or c == cls, 'classes 0x34026 differ between tracks'
        cls = c
        b, s = chunk_data(d, 0x34027)
        pad = s % INST
        assert pad == 8 and d[b:b + pad] == b'\x11' * 8
        for o in range(b + pad, b + s, INST):
            uniq.setdefault(bytes(d[o:o + INST]), None)
    rows = sorted(uniq, key=lambda r: (struct.unpack_from('<hh', r, 4), r))
    pos = {}
    for r in rows:
        k = struct.unpack_from('<hh', r, 4)
        assert k not in pos or pos[k] != r[:4] + r[8:12], 'two instance rows on one placement with one class/model'
        pos[k] = r[:4] + r[8:12]
    assert len(rows) < 0x8000      # smokeable stores the instance index as a sign-extended s16 (re_props.md)
    return cls, rows


def stream_container(d, o, size):
    """children of 0x80034150 with 0x34153/0x34154 removed; returns (the new chunk bytes, child ids before)"""
    kids, p, end = [], o + 8, o + 8 + size
    while p < end:
        cid, sz = struct.unpack_from('<II', d, p)
        kids.append((cid, bytes(d[p:p + 8 + sz])))
        p += 8 + sz
    assert p == end
    body = b''.join(k[1] for k in kids if k[0] not in DROP)
    return struct.pack('<II', 0x80034150, len(body)) + body, [hex(k[0]) for k in kids]


def build_file(base, g, rows, props):
    """base: decompressed base TRACKB. g: gen.derive(rows). returns the new decompressed bytes"""
    ch = w.top_chunks(base)
    ids = [c[0] for c in ch]
    i0 = ids.index(0x34130)
    assert ids[i0:i0 + 5] == list(w.COLL)
    widx = g['widx'] + (b'\0\0' if (len(g['widx']) // 2) % 2 else b'')
    out = bytearray(base[:ch[i0][1]])
    for cid, payload, al in ((0x34130, g['wmap'], True), (0x34131, g['wcell'], True), (0x34132, b''.join(rows), False),
                             (0x34133, widx, False), (0x34134, w.bbox_payload(rows), True)):
        out += w.chunk(cid, len(out), payload, al)
    tail = ch[i0 + 5:]

    def emit(c):
        cid, o, size = c
        if cid == 0x34027:
            assert len(out) % 16 == 0
            return struct.pack('<II', cid, 8 + INST * len(props)) + b'\x11' * 8 + b''.join(props)
        if cid == 0x80034150:
            return stream_container(base, o, size)[0]
        return bytes(base[o:o + 8 + size])

    k = 0
    while k < len(tail):
        j = k
        while j < len(tail) and tail[j][0] == 0:
            j += 1
        pads, c = tail[k:j], (tail[j] if j < len(tail) else None)
        if c is not None and pads and c[1] % 128 == 0:
            # the packer put this chunk's header at a multiple of 128 (re_coll.md section 5): keep the pads when the
            # phase still fits, else the fixed 1024 B pad plus one pad chunk of (-(hdr + 8)) mod 128 data bytes
            probe = len(out) + sum(8 + p[2] for p in pads)
            if probe % 128 != 0:
                for p in pads:
                    if p[2] == 1024:
                        out += base[p[1]:p[1] + 8 + p[2]]
                need = (-len(out)) % 128
                if need:
                    assert need >= 8
                    out += struct.pack('<II', 0, need - 8) + b'\0' * (need - 8)
            else:
                for p in pads:
                    out += base[p[1]:p[1] + 8 + p[2]]
        else:
            for p in pads:
                out += base[p[1]:p[1] + 8 + p[2]]
        if c is not None:
            out += emit(c)
        k = j + 1
    return bytes(out)


def check(tid, base, new, blob, g, rows, props, fence_keys, union_keys, rng):
    """returns a dict of facts; raises AssertionError on any failure"""
    facts = {}
    # 1. container: the exe's JDLZ decoder, the library decoder and the bytes written agree; csize is the file size
    assert blob[:4] == b'JDLZ' and blob[4] == 2
    usize, csize = struct.unpack_from('<II', blob, 8)
    assert usize == len(new) and csize == len(blob), 'JDLZ header sizes'
    assert lzc.exe_decode(blob) == new, 'exe JDLZ decode differs'
    assert jdlz_decompress(blob) == new, 'library JDLZ decode differs'
    # 2. chunk structure: same top-level ids (pads aside), alignments of the exe
    a = [c[0] for c in w.top_chunks(base) if c[0]]
    b = [c[0] for c in w.top_chunks(new) if c[0]]
    assert a == b, 'top-level chunk ids differ from the base'
    bad = w.check_alignment(base, new)
    assert not bad, 'misaligned chunks %s' % bad
    for cid in DROP:
        assert not find(new, cid), 'chunk %x still present' % cid
    # 3. caps
    ws = chunk_data(new, 0x34132)
    n_rows = ws[1] >> 5
    assert n_rows == len(rows) <= 0xfffe
    w_ = sim.World(new)
    assert w_.n_wsrc == len(rows) and w_.n_wmap <= 0xffff and w_.n_wcell <= 0xffff
    assert len(props) < 0x8000
    facts.update(polygons=n_rows, wmap_rows=w_.n_wmap, wcell_rows=w_.n_wcell, widx_u16=w_.n_widx,
                 instances=len(props), bytes=len(new), file=len(blob))
    # 4. quadtree and cell lists: the file's own wsrc re-derived == what is in the file
    d = gen.chunks(new)
    got = [bytes(new[ws[0] + o:ws[0] + o + 32]) for o in range(0, ws[1], 32)]
    assert got == rows, 'wsrc rows differ'
    g2 = gen.derive(got)
    assert d[0x34130][0] == g2['wmap'] and d[0x34131][0] == g2['wcell'], 'wmap/wcell differ from the re-derived quadtree'
    assert d[0x34133][0][:len(g2['widx'])] == g2['widx'], 'widx differs from the re-derived lists'
    # 5. fences absent, every other union row present
    have = {polys.key(r) for r in got}
    assert len(have) == len(got), 'duplicate rows'
    assert not any(k.hex() in fence_keys for k in have), 'a fence key is present'
    assert have == union_keys, 'rows differ from the union minus fences'
    facts['fences_absent'] = len(fence_keys)
    facts['union_present'] = len(union_keys)
    # 6. the exe's query (ported) finds samples, and equals a brute-force box test
    vals = [w_.row_vals(i) for i in range(n_rows)]
    miss = 0
    for i in rng.sample(range(n_rows), 1500):
        v = vals[i]
        miss += i not in w_.query((v[0] - 1, v[1] - 1), (v[2] + 1, v[3] + 1), cap=100000)
    assert miss == 0, '%d polygons not found through their own box' % miss
    neq = 0
    cells_cache = {}
    fl = lambda v: (int(v * 65536) & -(1 << 21)) / 65536.0     # 0x441500
    frange = lambda a, b: [a + 32.0 * k for k in range(int(max(0, (b - a) // 32)) + 2) if a + 32.0 * k < b]
    for _ in range(200):
        i = rng.randrange(n_rows)
        v = vals[i]
        x0, y0 = v[0] - rng.uniform(0, 40), v[1] - rng.uniform(0, 40)
        x1, y1 = v[2] + rng.uniform(0, 40), v[3] + rng.uniform(0, 40)
        q = set(w_.query((x0, y0), (x1, y1), cap=100000))
        # expected: the bbox test of 0x441660 on every row that is listed in a cell the box visits (0x441c10: cells from
        # floor32(min) while < max); the cell membership comes from cells_of (SAT), not from the file's tree
        cx = {int(fl(x) // 32) for x in frange(fl(x0), x1)}
        cy = {int(fl(y) // 32) for y in frange(fl(y0), y1)}
        bf = set()
        for j, u in enumerate(vals):
            if u[0] < x1 and u[1] < y1 and x0 <= u[2] and y0 <= u[3]:
                if j not in cells_cache:
                    cells_cache[j] = gen.cells_of(got[j])
                if any(i in cx and k in cy for i, k in cells_cache[j]):
                    bf.add(j)
        neq += q != bf
    assert neq == 0, '%d boxes differ from brute force' % neq
    facts['query_checks'] = 1700
    # 7. props chunk
    pb, ps = chunk_data(new, 0x34027)
    assert ps == 8 + INST * len(props) and (pb - 8) % 16 == 0 and new[pb:pb + 8] == b'\x11' * 8
    assert [bytes(new[o:o + INST]) for o in range(pb + 8, pb + ps, INST)] == props
    return facts


def main():
    ids = [int(a) for a in sys.argv[1:]] or TRACKS
    t0 = time.time()
    fences = json.load(open(FENCES))
    fence_keys = {f['key'] for f in fences['fences']}
    assert len(fence_keys) == len(fences['fences'])
    rows, n_union, n_fence = union_rows(fence_keys)
    assert n_fence == len(fence_keys), 'fence keys not all in the union (%d of %d)' % (n_fence, len(fence_keys))
    union_keys = {polys.key(r) for r in rows}
    print('union %d rows, fences removed %d, kept %d (%.0fs)' % (n_union, n_fence, len(rows), time.time() - t0), flush=True)
    bases = {t: load(trackb_path(PC, t)) for t in TRACKS}
    cls, props = union_props(bases)
    print('props: %d classes, %d union instances' % (len(cls) // 256, len(props)), flush=True)
    g = gen.derive(rows)
    print('derived quadtree: %d nodes, %d cells (%.0fs)' % (g['nodes'], g['cells'], time.time() - t0), flush=True)
    os.makedirs(OUT, exist_ok=True)
    rng = random.Random(7)
    man = dict(source='tools/openworld/build.py', fences_removed=n_fence, union_polygons=n_union, polygons=len(rows),
               instances=len(props), files={})
    for t in ids:
        base = bases[t]
        new = build_file(base, g, rows, props)
        blob = lzc.encode(new)
        path = os.path.join(OUT, 'TRACKB%d.lzc' % t)
        open(path, 'wb').write(blob)
        f = check(t, base, new, blob, g, rows, props, fence_keys, union_keys, rng)
        sc = [(o, s) for cid, o, s in w.top_chunks(base) if cid == 0x80034150][0]
        f.update(md5=hashlib.md5(blob).hexdigest(), base_file=os.path.getsize(trackb_path(PC, t)),
                 stream_children_before=stream_container(base, *sc)[1])
        man['files'][str(t)] = f
        print(t, 'OK', {k: v for k, v in f.items() if k != 'stream_children_before'}, '(%.0fs)' % (time.time() - t0), flush=True)
    if len(ids) == len(TRACKS):
        json.dump(man, open(MANIFEST, 'w'), indent=1)
        print('wrote', MANIFEST)
    print('ALL OK' if len(ids) == len(TRACKS) else 'OK (partial run, manifest not written)')


if __name__ == '__main__':
    main()
