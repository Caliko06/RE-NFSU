# One AO per solid from its "home" assembly (kit k -> job k, style s -> job s-1, wide KITW0n -> wide job n, everything else job 0 of its LOD),
# as uint8 (AO*255). out/final/<CAR>.npz: <solid name> -> u8[nv] in the solid's own vertex order (= the game's vertex buffer order);
# out/final/<CAR>.tsv: name, nv, fnv64 of the position bytes (the key the host can compute from a draw's vertices).
import sys, re, os, numpy as np; sys.path.insert(0, '.'); import geobin
def fnv64(b):
    h = 0xcbf29ce484222325
    for x in b: h = ((h ^ x) * 0x100000001b3) & 0xffffffffffffffff
    return h
car = sys.argv[1]; nj = 20
zi = np.load(f'out/{car}.in.npz'); za = np.load(f'out/{car}.ao.npz')
meta = {}
for k in zi.files:
    if k.endswith('.meta'): meta[tuple(int(x) for x in zi[k])] = k.split('.')[0][1:]   # (letter, j) -> job index
S = {}
for s in geobin.solids(f'../../game/Cars/{car}/GEOMETRY.BIN'):
    n = s['name'][len(car) + 1:]; S[n if n not in S else n + '#2'] = s
def home(n):
    L = ord(n.rstrip('#2')[-1]) if re.search(r'_[A-D](#2)?$', n) else ord('A')
    m = re.match(r'KITW(\d+)_', n)
    if m: return meta.get((L, nj + int(m.group(1)) - 1))
    m = re.match(r'KIT(\d+)_', n)
    if m and int(m.group(1)) < 16: return meta.get((L, int(m.group(1))))
    m = re.match(r'STYLE(\d+)_', n)
    if m and 1 <= int(m.group(1)) <= 20: return meta.get((L, int(m.group(1)) - 1))
    return meta.get((L, 0))
out, rows = {}, []
for n, s in S.items():
    j = home(n)
    if j is None or f'{j}|{n}' not in za.files: continue
    a = za[f'{j}|{n}'].astype(np.float32)
    out[n] = np.round(a * 255).astype(np.uint8)
    rows.append((n, s['nv'], '%016x' % fnv64(s['pos'].tobytes())))
os.makedirs('out/final', exist_ok=True)
np.savez_compressed(f'out/final/{car}.npz', **out)
open(f'out/final/{car}.tsv', 'w').write(''.join('\t'.join(map(str, r)) + '\n' for r in rows))
print(car, len(out), 'of', len(S), 'solids', sum(len(v) for v in out.values()), 'verts', os.path.getsize(f'out/final/{car}.npz') // 1024, 'KB')
