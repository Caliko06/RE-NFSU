# geodump frames of one run -> unique world instances in world space (and cars in their own space), for bake.py.
# The world shaders (vs a96c3fef, 67da8f41, 102e066d, a9fb4c90) take oPos = v0 * c0..c3 (WVP, rows); the most common
# c0..c3 of a frame is the frame's view-projection (geometry already in world space), every other draw's world matrix is
# inv(VP) * WVP (affine on every dump checked, 2026-10-25). The car body (vs 4728b668) has WVP in c10..c13; car parts with
# the same matrix in a frame are one car, kept in that car's space. usage: geo2mesh.py OUT.npz FRAME.bin...
import sys, hashlib, collections, numpy as np; sys.path.insert(0, __file__.rsplit('/', 1)[0]); import geodump
WORLD, CAR = {0xa96c3fef, 0x67da8f41, 0x102e066d, 0xa9fb4c90}, 0x4728b668
out, files = sys.argv[1], sys.argv[2:]
inst, cars, drift = {}, {}, []
def tris(d):
    i = np.array(d['idx'], np.uint32)
    if d['type'] == 5:   # strip -> list, dropping degenerates
        t = np.stack([i[:-2], i[1:-1], i[2:]], 1); t[1::2] = t[1::2][:, [1, 0, 2]]
        i = t[(t[:, 0] != t[:, 1]) & (t[:, 1] != t[:, 2]) & (t[:, 0] != t[:, 2])].ravel()
    return i.reshape(-1, 3)
for f in files:
    ds = [d for d in geodump.draws(f) if d['rt'][0] == 640 and d['type'] in (4, 5)]
    w = [d for d in ds if d['vs'] in WORLD]
    if w:
        iVP = np.linalg.inv(np.array(collections.Counter(tuple(d['vsc'][:16]) for d in w).most_common(1)[0][0]).reshape(4, 4))
    for d in ds:
        pos = np.array(geodump.attr(d, 0), np.float64)
        if pos.size == 0: continue
        vh = hashlib.sha1(d['vb'] + np.array(d['idx'], np.uint32).tobytes()).hexdigest()[:16]
        if d['vs'] in WORLD:
            W = iVP @ np.array(d['vsc'][:16]).reshape(4, 4)
            p = (np.c_[pos, np.ones(len(pos))] @ W.T)[:, :3]
            key = (vh, tuple(np.round(W[:3, 3], 0)))
            if key in inst: drift.append(np.abs(inst[key][0] - p).max()); continue
            inst[key] = (p, tris(d), d['tex0'], vh)
        elif d['vs'] == CAR:
            M = tuple(np.round(d['vsc'][40:56], 4))
            cars.setdefault((f, M), {})[vh] = (pos, tris(d), d['tex0'], vh)
keys = list(inst)
np.savez_compressed(out, n=len(keys), vh=[inst[k][3] for k in keys], tex=np.array([inst[k][2] for k in keys], np.uint64),
                    pos=np.array([inst[k][0].astype(np.float32) for k in keys], dtype=object),
                    tri=np.array([inst[k][1] for k in keys], dtype=object),
                    cars=np.array([[(v[3], v[0].astype(np.float32), v[1], v[2]) for v in c.values()] for c in cars.values()], dtype=object))
print(f'{out}: {len(keys)} world instances, {sum(len(v[1]) for v in inst.values())} tris, {len(cars)} car groups; '
      f'same instance in two frames: {len(drift)}, max drift {max(drift) if drift else 0:.4f}')
