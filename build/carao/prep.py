# Assemblies of one car at LOD A for bake_car.py. Job j (0..19): kit = j % 16 (j >= 16: stock) bumpers + skirt, style = j + 1 hood/roof/spoiler/headlight/brakelight
# (those that exist), on the stock shell: BASE_A, KIT00 body/trunk/mirrors/exhaust/wheel/(hood/roof/head/brake when no style part). usage: prep.py CAR OUT.npz [NJOBS]; env LODS=ABCD (default A) repeats the jobs per LOD letter. Jobs 20,21 of each LOD: wide body KITW01/02 on the stock kit (when the car has it).
# Job index = lodIndex * (NJOBS + 2) + j.
import sys, re, numpy as np; sys.path.insert(0, '.'); import geobin
car, out = sys.argv[1], sys.argv[2]; nj = int(sys.argv[3]) if len(sys.argv) > 3 else 20
S = {}
for s in geobin.solids(f'../../game/Cars/{car}/GEOMETRY.BIN'):
    if s['nv'] == 0 or not len(s['idx']): continue
    n = s['name'][len(car) + 1:]; n = n if n not in S else n + '#2'
    S[n] = s
def pick(base):   # LOD A solids by prefix (mirrors / decals have no LOD letter)
    return [n for n in S if n == base + '_A' or n.startswith(base) and re.fullmatch(r'_?[A-Z]?', n[len(base):]) is not None and not re.search(r'_[B-D]$', n)]
def lodA(prefix):
    return [n for n in S if n.startswith(prefix) and (n.endswith('_' + L) or not re.search(r'_[A-D]$', n))]
import os
d, used, jobs = {}, set(), []
for L in os.environ.get('LODS', 'A'):
  for j in range(nj + 2):
    wide = j >= nj; kit = 0 if wide else j % 16 if j < 16 else 0; sty = (1 if wide else j + 1)
    body = f'KITW{j - nj + 1:02d}_BODY' if wide else 'KIT00_BODY'
    if wide and not lodA(body): continue
    names = ['BASE_' + L]
    for part in (body, 'KIT00_TRUNK', 'KIT00_EXHAUST', 'KIT00_WHEEL', 'KIT00_LEFT_SIDE_MIRR', 'KIT00_RIGHT_SIDE_MIR'):
        names += lodA(part)
    for part in ('FRONT_BUMPER', 'REAR_BUMPER', 'SKIRT'):
        names += lodA(f'KIT{kit:02d}_{part}')
    for part in ('HOOD', 'ROOF', 'SPOILER', 'HEADLIGHT', 'BRAKELIGHT'):
        sn = lodA(f'STYLE{sty:02d}_{part}')
        names += sn if sn else (lodA(f'KIT00_{part}') if part != 'SPOILER' else [])
    names = [n for n in dict.fromkeys(names) if n in S]
    jobs.append((L, j, names))
    used.update(names)
allp = sorted(used)
for i, (L, j, names) in enumerate(jobs): d[f'j{i}.names'] = np.array(names); d[f'j{i}.meta'] = np.array([ord(L), j])
for n in allp: d['p.' + n] = S[n]['pos']; d['t.' + n] = S[n]['idx'].reshape(-1, 3).astype(np.uint32)
np.savez(out, **d)
print(car, len(jobs), 'jobs', len(allp), 'solids', sum(len(S[n]['idx']) // 3 for n in jobs[0][2]), 'tris in job 0')
