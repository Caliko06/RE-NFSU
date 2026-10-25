# geodump frames of one run -> unique world instances in world space (and cars in their own space), for bake.py.
# The world shaders (vs a96c3fef, 67da8f41, 102e066d, a9fb4c90) take clip = c0..c3 * v0 (WVP). In race frames the most
# common c0..c3 (M0) is the world VP: its draws are track chunks already in world space (median |x| or |y| > 150); FE
# frames (garage, ~100-unit tiles, |pos| ~ 20) are dropped. Each draw's world matrix inv(VP) * WVP is solved from the
# clip x, y, w rows only: the z row is almost the w row (z/w ~ 1), so the full 4x4 inverse was ill-conditioned (the old
# merge drifted up to 22 units). One instance = vb+idx hash + its world matrix (props reuse one vb at many places). The car body (vs 4728b668) has WVP in c10..c13; car parts with
# the same matrix in a frame are one car, kept in that car's space. usage: geo2mesh.py OUT.npz FRAME.bin...
import sys, hashlib, collections, numpy as np; sys.path.insert(0, __file__.rsplit('/', 1)[0]); import geodump
WORLD, CAR = {0xa96c3fef, 0x67da8f41, 0x102e066d, 0xa9fb4c90}, 0x4728b668
out, files = sys.argv[1], sys.argv[2:]
inst, cars, drift = {}, {}, []   # inst: (vb+idx hash, world matrix) -> (block key, tex0)
def tris(d):
    i = np.array(d['idx'], np.uint32)
    if d['type'] == 5:   # strip -> list, dropping degenerates
        t = np.stack([i[:-2], i[1:-1], i[2:]], 1); t[1::2] = t[1::2][:, [1, 0, 2]]
        i = t[(t[:, 0] != t[:, 1]) & (t[:, 1] != t[:, 2]) & (t[:, 0] != t[:, 2])].ravel()
    return i.reshape(-1, 3)
fe, blocks = 0, {}   # blocks: (vb hash, world matrix) -> (world pos, A, [tris of every draw of that vb])
for f in files:
    ds = [d for d in geodump.draws(f) if d['rt'][0] == 640 and d['type'] in (4, 5)]
    w = [d for d in ds if d['vs'] in WORLD]
    if w:
        k0 = collections.Counter(tuple(d['vsc'][:16]) for d in w).most_common(1)[0][0]
        P0 = np.concatenate([np.array(geodump.attr(d, 0)) for d in w if tuple(d['vsc'][:16]) == k0 and d['nvert']])
        if np.median(np.abs(P0[:, :2]), 0).max() < 150: fe += 1; continue
        N0 = np.array(k0).reshape(4, 4)[[0, 1, 3]]; iN0 = np.linalg.inv(N0[:, :3])
    for d in ds:
        pos = np.array(geodump.attr(d, 0), np.float64)
        if pos.size == 0: continue
        vh = hashlib.sha1(d['vb'] + np.array(d['idx'], np.uint32).tobytes()).hexdigest()[:16]
        vbh = hashlib.sha1(d['vb']).hexdigest()[:16]
        if d['vs'] in WORLD:
            N = np.array(d['vsc'][:16]).reshape(4, 4)[[0, 1, 3]]; N[:, 3] -= N0[:, 3]
            A = iN0 @ N                                   # rows 0..2 of the affine world matrix
            p = pos @ A[:, :3].T + A[:, 3]
            ak = (tuple(np.round(A[:, :3], 2).ravel()), tuple(np.round(A[:, 3], 0)))
            if (vh, ak) in inst: drift.append(np.abs(blocks[inst[vh, ak][0]][0] - p).max()); continue
            col = np.array(geodump.attr(d, 10), np.uint8)[:, [2, 1, 0, 3]]   # D3DCOLOR bytes are B, G, R, A
            b = blocks.setdefault((vbh, ak), (p, A, [], col))[2]; b.append((tris(d), d['tex0'])); inst[vh, ak] = ((vbh, ak), d['tex0'])
        elif d['vs'] == CAR:
            M = tuple(np.round(d['vsc'][40:56], 4))
            cars.setdefault((f, M), {})[vh] = (pos, tris(d), d['tex0'], vh)
# Flat npz (Blender's numpy 1 cannot read numpy 2 pickles). World: one vertex block per vb placed by one matrix (draws of
# one vb with other index ranges share its vertices, so their tris are one mesh, not coplanar copies); w.vh/w.blk/w.tex
# list the draws; w.col = the vertex colour (the game's baked light, RGBA), w.ttk = the tex0 key of each w.tri (for bake.py gi).
# Cars: c<k>.vh, c<k>.<j>.p, c<k>.<j>.t per distinct car (one set of part hashes, in its own space).
bk = list(blocks); bi = {k: i for i, k in enumerate(bk)}
boff = np.cumsum([0] + [len(blocks[k][0]) for k in bk])
T = np.concatenate([t + boff[i] for i, k in enumerate(bk) for t, _ in blocks[k][2]])
K = np.concatenate([np.full(len(t), x, np.uint64) for k in bk for t, x in blocks[k][2]])
T, u = np.unique(T, axis=0, return_index=True)
d = {'w.tri': T.astype(np.uint32), 'w.ttk': K[u], 'w.pos': np.concatenate([blocks[k][0] for k in bk]).astype(np.float32), 'w.boff': boff,
     'w.col': np.concatenate([blocks[k][3] for k in bk]),
     'w.A': np.array([blocks[k][1].ravel() for k in bk], np.float32), 'w.vbh': np.array([k[0] for k in bk]),
     'w.vh': np.array([k[0] for k in inst]), 'w.blk': np.array([bi[v[0]] for v in inst.values()], np.int32),
     'w.tex': np.array([v[1] for v in inst.values()], np.uint64)}
sets = {}
for c in cars.values(): sets.setdefault(tuple(sorted(c)), c)
for k, key in enumerate(sorted(sets)):
    parts = list(sets[key].values()); d[f'c{k}.vh'] = np.array([q[3] for q in parts])
    for j, q in enumerate(parts): d[f'c{k}.{j}.p'], d[f'c{k}.{j}.t'] = q[0].astype(np.float32), q[1].astype(np.uint32)
np.savez_compressed(out, **d)
print(f'{out}: {len(inst)} world draws in {len(bk)} vb blocks, {len(d["w.tri"])} tris, {len(sets)} distinct cars; '
      f'same draw in two frames: {len(drift)}, max drift {max(drift) if drift else 0:.4f}; FE frames dropped {fe}')
