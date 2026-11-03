#!/usr/bin/env python3
"""Numbers from one WORLD ghost log (tools/openworld/ghost.sh): traffic presence, ghosts, impacts, rivals. usage: ghostreport.py runs/w_a/log.txt"""
import re, sys, collections as C, statistics as S
L = open(sys.argv[1], errors='replace').read().split('\n')
T = [l for l in L if l.startswith('TRAFLOG')]
g = lambda k, l: int(re.search(k + r' (\d+)', l).group(1))
T2 = T[len(T) // 5:]
if T2:
    q = lambda k: (min(g(k, l) for l in T2), int(S.median(g(k, l) for l in T2)), max(g(k, l) for l in T2))
    print('traffic min/med/max: parked', q('parked'), 'near250', q('near250'), 'near100', q('near100'), 'polys', q('polys'))
    print('last:', re.search(r'refill.*?flashf \d+', T[-1]).group(0)[:150])
A = [l for l in L if l.startswith('AIT')]
if A:
    print('AIT rows', len(A), 'parked,draw', C.Counter(re.search(r'parked (\d) .*draw (\d)', l).groups() for l in A).most_common())
    close = [l for l in A if 'draw 0' in l and abs(int(re.search(r' d ([+-]\d+)', l).group(1))) < 60 and abs(float(re.search(r'lat ([+-][\d.]+)', l).group(1))) < 10]
    print('ghosts on the road within 60 m:', len(close))
H = [l for l in L if l.startswith('AIHIT')]
kinds = C.Counter()
drops = C.defaultdict(list); who = C.Counter()
for l in H:
    m = re.search(r'kind (\d) car (\w+) sp ([\d.]+) -> ([\d.]+) act (-?\d+) (wall|car)', l)
    if m:
        kinds[(m.group(1), m.group(6))] += 1; drops[(m.group(1), m.group(6))].append(float(m.group(3)) - float(m.group(4))); who[m.group(2)] += 1
frames = g('TRAFLOG', T[-1]) if T else 1
print('impacts', len(H), 'per min', round(len(H) / (frames / 3600), 1), {k: (v, round(S.median(drops[k]), 1)) for k, v in kinds.items()}, 'top cars', who.most_common(4))
R = C.defaultdict(list)
for l in L:
    m = re.match(r'AIR f(\d+) (\S+) d ([+-]\d+) lat [+-]\d+ sp ([\d.]+) act (-?\d+)/(-?\d+) route (-?\d+) own ([\d.-]+) .* stuck ([\d.]+) s', l)
    if m: R[m.group(2)].append((int(m.group(3)), float(m.group(4)), float(m.group(9))))
for k, v in R.items():
    v2 = v[len(v) // 5:]
    print(f'rival {k}: |d| med {int(S.median(abs(x[0]) for x in v2))} sp med {S.median(x[1] for x in v2):.0f} m/s, stuck max {max(x[2] for x in v2):.0f} s')
for w in ('NOSKIN', 'STOP'):
    print(w, sum(l.startswith(w) for l in L))
