#!/usr/bin/env python3
"""ug2_collfile.py: the Free Run (track 1010) collision file = NFSU1 rows + the UG2 city rows, placed (OWNER 2026-11-10, docs/re/ug2_bridge.md rank 1).

Base = the live build/openworld/TRACKB1010.lzc (roads, routes, props, everything but the collision block stays; its old wsrc rows stay first,
row numbers unchanged). UG2 rows = build/ug2/coll_rows.bin (tools/ug2_coll.py) moved into NFSU1 space: rotate R270 (x,y) -> (y,-x), then t.
The result has more than 65,534 rows, so the 0x34133 chunk holds u32 entries behind 0xffffffff (PATCHES 0x441423 and 0x441660, patches_collision.py).
The road net (0x34121 / 0x34122) goes through the same writer: tools/ug2_traffic.py appends the UG2 streets near the bridge and a connector (census/ug2/roads.md section 8).
Row fields (layout tools/openworld/polys.py): x,y s16/8 are moved in integers; z = s16 base + s16/256 moves by tz (a multiple of 1/64, so exact for
flag 0x04 rows too) with a new base; byte +1 (bbox selectors, 0x441660) is recomputed from the new vertices; flag 0x04 rows are the infinite walls
(z -508..508 in every UG2 row) and keep their z; nothing else is stored (the plane is built at run time, 0x43ff30).
usage: ug2_collfile.py [--check]     writes build/openworld/TRACKB1010.lzc (old one kept as TRACKB1010.prev.lzc); --check only verifies the file on disk"""
import os, random, shutil, struct, sys
HERE = os.path.dirname(os.path.abspath(__file__))
REPO = os.path.abspath(os.path.join(HERE, '..'))
os.environ.setdefault('NFSU1_MAIN', REPO)
sys.path.insert(0, HERE)
sys.path.insert(0, os.path.join(HERE, 'hopper'))
import q_owcoll2_gen as gen  # noqa: E402
import q_owcoll2_lzc as lzc  # noqa: E402
import q_owcoll2_sim as sim  # noqa: E402
import q_owcoll2_write as w  # noqa: E402
import ug2_bridge  # noqa: E402
import ug2_traffic  # noqa: E402

OUT = os.path.join(REPO, 'build', 'openworld', 'TRACKB1010.lzc')
PREV = os.path.join(REPO, 'build', 'openworld', 'TRACKB1010.prev.lzc')
UG2 = os.path.join(REPO, 'build', 'ug2', 'coll_rows.bin')
MESH = os.path.join(REPO, 'web', 'ug2', 'bridge.bin')   # bridge deck + barriers, raw UG2 units, same format and model as city.bin; bridge_tex.bin = its UG2T side file
# t = (-1287.4, 812.2, -6.2) of the decision, rounded to what the rows hold: x,y to 1/8, z to 1/64 (flag 0x04 rows step 1/64)
TX8, TY8, TZ = round(-1287.4 * 8), round(812.2 * 8), round(-6.2 * 64) / 64
S16 = (-32768, 32767)


def move(r):
    """one raw UG2 row -> the row in NFSU1 space"""
    f, base = r[3], struct.unpack_from('<h', r, 4)[0]
    xs, ys, zs = (struct.unpack_from('<4h', r, o) for o in (8, 16, 24))
    nx = [y + TX8 for y in ys]                    # R270: x' = y, y' = -x, in 1/8 units
    ny = [-x + TY8 for x in xs]
    assert all(S16[0] <= v <= S16[1] for v in nx + ny), 'vertex outside +-4096'
    if f & 4:
        nb, nz = base, list(zs)
        assert all(abs((base + z / 256) * 4) == 508 for z in zs), 'a flag 0x04 row that is not an infinite wall'
    else:
        z = [base + v / 256 + TZ for v in zs]
        nb = round((min(z) + max(z)) / 2)
        nz = [round((v - nb) * 256) for v in z]
        assert all(abs(nb + v / 256 - u) < 1e-9 for v, u in zip(nz, z)) and all(S16[0] <= v <= S16[1] for v in nz) and S16[0] <= nb <= S16[1]
    sel = (nx.index(min(nx)) | ny.index(min(ny)) << 2 | nx.index(max(nx)) << 4 | ny.index(max(ny)) << 6)
    return struct.pack('<BBBBhh4h4h4h', 0, sel, r[2], f, nb, -1, *nx, *ny, *nz)


def ug2_rows():
    d = open(UG2, 'rb').read()
    rows = [move(d[o:o + 32]) for o in range(0, len(d), 32)]
    assert len(set(rows)) == len(rows)
    return rows


def old_rows(base):
    ch = {c[0]: c for c in w.top_chunks(base)}
    _, o, s = ch[0x34132]
    return [bytes(base[o + 8 + k:o + 8 + k + 32]) for k in range(0, s, 32)]


def build():
    if not os.path.exists(PREV):
        shutil.copy(OUT, PREV)
    base = lzc.exe_decode(open(PREV, 'rb').read())
    nf = old_rows(base)
    nf, uz, bridge, mesh, side = ug2_bridge.apply(nf, ug2_rows(), TX8, TY8, TZ)
    open(MESH, 'wb').write(mesh)
    open(MESH.replace('.bin', '_tex.bin'), 'wb').write(side)
    uz = uz + bridge
    base = ug2_traffic.apply(base, nf + uz)       # road chunks 0x34121 / 0x34122: + the UG2 streets near the bridge and the connector
    new = w.build_trackb(base, nf + uz, wide=True)
    blob = lzc.encode(new)
    open(OUT, 'wb').write(blob)
    print('NFSU1 rows %d + UG2 rows %d = %d; decompressed %d B, file %d B' % (len(nf), len(uz), len(nf) + len(uz), len(new), len(blob)))


def rbox(v, rng, pad):
    return ((v[0] - rng.uniform(0, pad), v[1] - rng.uniform(0, pad)), (v[2] + rng.uniform(0, pad), v[3] + rng.uniform(0, pad)))


def rows_at(d, wd, i):
    return bytes(d[wd.wsrc + 32 * i:wd.wsrc + 32 * i + 32])


def check():
    rng = random.Random(11)
    blob, prev = open(OUT, 'rb').read(), open(PREV, 'rb').read()
    assert lzc.exe_decode(blob) is not None
    new, old = lzc.exe_decode(blob), lzc.exe_decode(prev)
    wn, wo = sim.World(new), sim.World(old)
    nf = old_rows(old)
    nf[42877] = rows_at(new, wn, 42877)   # the dead-end cap wall is the bridge's west side wall (tools/ug2_bridge.py)
    assert wn.wide and not wo.wide
    assert [c[0] for c in w.top_chunks(new) if c[0]] == [c[0] for c in w.top_chunks(old) if c[0]], 'chunk ids differ from the old file'
    assert not w.check_alignment(old, new), 'misaligned chunks'
    rows = [bytes(new[wn.wsrc + 32 * i:wn.wsrc + 32 * i + 32]) for i in range(wn.n_wsrc)]
    assert rows[:len(nf)] == nf and len(rows) > 0xfffe
    print('rows %d (NFSU1 %d first, UG2 %d), widx u32 entries %d, wcell %d, wmap %d' % (wn.n_wsrc, len(nf), wn.n_wsrc - len(nf), wn.n_widx, wn.n_wcell, wn.n_wmap))
    g = gen.derive(rows, wide=True)
    ch = gen.chunks(new)
    assert ch[0x34130][0] == g['wmap'] and ch[0x34131][0] == g['wcell'] and ch[0x34133][0] == w.WIDE + g['widx'], 'tree/lists differ from the re-derived ones'
    # every UG2 vertex inside the grid, bbox selectors give the true min/max
    for i in range(len(nf), wn.n_wsrc):
        r = rows[i]
        xs, ys = struct.unpack_from('<4h', r, 8), struct.unpack_from('<4h', r, 16)
        s = r[1]
        assert xs[s & 3] == min(xs) and ys[(s >> 2) & 3] == min(ys) and xs[(s >> 4) & 3] == max(xs) and ys[s >> 6] == max(ys)
    # a) polygons found through their own box (UG2 and NFSU1)
    vals = [wn.row_vals(i) for i in range(wn.n_wsrc)]
    miss = 0
    pick = rng.sample(range(len(nf), wn.n_wsrc), 1500) + rng.sample(range(len(nf)), 500)
    for i in pick:
        v = vals[i]
        miss += i not in wn.query((v[0] - 1, v[1] - 1), (v[2] + 1, v[3] + 1), cap=10 ** 6)
    assert miss == 0, miss
    # b) random boxes over UG2 ground (car footprint + 8): not empty, and equal to the bbox test over the cells the box visits
    ground = [i for i in range(len(nf), wn.n_wsrc) if rows[i][3] & 0x0a == 0]
    fl = lambda v: (int(v * 65536) & -(1 << 21)) / 65536.0
    neq = empty = 0
    cc = {}
    for _ in range(150):
        v = vals[rng.choice(ground)]
        cx, cy = (v[0] + v[2]) / 2, (v[1] + v[3]) / 2
        q0, q1 = (cx - 6, cy - 6), (cx + 6, cy + 6)
        got = set(wn.query(q0, q1, cap=10 ** 6))
        empty += not got
        xs_ = {int(fl(x) // 32) for x in [fl(q0[0]) + 32 * k for k in range(3)] if x < q1[0]}
        ys_ = {int(fl(y) // 32) for y in [fl(q0[1]) + 32 * k for k in range(3)] if y < q1[1]}
        exp = set()
        for j, u in enumerate(vals):
            if u[0] < q1[0] and u[1] < q1[1] and q0[0] <= u[2] and q0[1] <= u[3]:
                cc.setdefault(j, gen.cells_of(rows[j]))
                if any(a in xs_ and b in ys_ for a, b in cc[j]):
                    exp.add(j)
        neq += got != exp
    assert not neq and not empty, (neq, empty)
    # c) NFSU1 part unchanged: boxes over NFSU1 rows give the old file's answer (row numbers are the same)
    d = 0
    for _ in range(300):
        v = vals[rng.randrange(len(nf))]
        q = rbox(v, rng, 40)
        a, b = set(wo.query(*q, cap=10 ** 6)) - {42877}, {i for i in wn.query(*q, cap=10 ** 6) if i < len(nf)} - {42877}
        d += a != b
    assert d == 0, d
    print('traffic net:', ug2_traffic.check(new, old, rows))
    out, cross = ug2_bridge.check(rows)
    for x, o in out.items():
        print('bridge lane x=%.1f: ground samples %d, gaps %d, interior overlaps y505..589 %d, max z step per 0.25 %.3f, z %.2f..%.2f, wall crossings y440..612: %d' % ((x,) + o + (cross[x],)))
        assert o[1] == 0 and o[2] == 0 and o[3] < 0.1 and cross[x] == 0, (x, o, cross[x])
    print('check OK: bbox selectors, own-box 2000/2000, UG2 boxes 150/150 == brute force, NFSU1 boxes 300/300 == old file')


if __name__ == '__main__':
    if '--check' not in sys.argv:
        build()
    check()
