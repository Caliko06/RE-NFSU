#!/usr/bin/env python3
"""city_run.py: one bounded native free run on a WORLD road net, then where the traffic cars stood still (re_citygraph.md step 3).

usage: city_run.py <tag> [world dir=build/openworld_city] [secs=200] ["x,y,z,heading" RN_WORLD_AT = start spot]
  -> runs/city_<tag>/log.txt (jump 3:1010, RN_AUTOPILOT, RN_FREELOG, RN_CARPOS: a "carpos" line per car every 2 s of watch time),
     then prints the car-to-car intervals with < 1 m moved: parked (P, the teleporter recycles them) and the others, each with the
     section / node index it stands on (a section start would be idx 0..2 or the last nodes).
env BIN=<speed binary> (default build/speed; RN_CARPOS needs a build with host/main.c of 2026-10-28 or later). Start it through
~/.claude/hooks/macgate.sh. Defaults reproduce the 2026-10-28 run: "50.1,-747.2,29.4,-15824" is sec 80 node 19, off the tour."""
import collections, math, os, struct, subprocess, sys
HERE = os.path.dirname(os.path.abspath(__file__))
sys.path[:0] = [HERE, os.path.join(HERE, '..')]
import completion as C  # noqa: E402
R = C.R


def run(tag, world, secs, at):
    keys, rnjump, _ = C.jump('jump_3_1010')
    d = f'{R}/runs/city_{tag}'
    subprocess.run(['rm', '-rf', d])
    os.makedirs(d)
    subprocess.run(['cp', '-al', f'{R}/game', f'{d}/game'], check=True)
    subprocess.run(['cp', '-r', f'{R}/save', f'{d}/save'], check=True)
    env = dict(os.environ, RN_TURBO='4', RN_SECS=str(secs), RN_SCREEN='640x480', RN_RASTER='1000000', RN_FLOWLOG='1', RN_SEED='1',
               RN_AUTOPILOT='1', RN_KEYS=keys, RN_JUMP=rnjump, RN_FREELOG='1', RN_CARPOS='1', RN_WORLD_DIR=f'{R}/{world}', RN_WORLD_LOG='240')
    if at:
        env.update(RN_WORLD_AT=at, RN_WORLD_MOVE='40')
    with open(f'{d}/log.txt', 'w') as log:
        subprocess.run(['nice', '-n', '5', os.environ.get('BIN', f'{R}/build/speed'), f'{R}/pc/Speed.exe', 'game', '--shot', 'shot.png'],
                       cwd=d, env=env, stdout=log, stderr=subprocess.STDOUT, stdin=subprocess.DEVNULL, timeout=secs + 120)
    return f'{d}/log.txt'


def stuck(log, world):
    import citygraph as G
    secs, _ = G.parse_net(G.T.load(f'{R}/{world}/TRACKB1010.lzc'))
    pts = [(*struct.unpack_from('<2f', nd, 0), s, i, len(nodes)) for s, nodes in enumerate(secs) for i, nd in enumerate(nodes)]
    cars = collections.defaultdict(list)
    for l in open(log, errors='replace'):
        f = l.split()
        if f[:1] == ['carpos'] and f[3] == 'k3':
            cars[int(f[2])].append((float(f[1]), float(f[4]), float(f[5]), ''.join(f[6:])))
    n = parked = 0
    for i, v in sorted(cars.items()):
        for a, b in zip(v, v[1:]):
            n += 1
            if math.hypot(b[1] - a[1], b[2] - a[2]) >= 1.0:
                continue
            if 'P' in b[3]:
                parked += 1
                continue
            p = min(pts, key=lambda q: (q[0] - b[1]) ** 2 + (q[1] - b[2]) ** 2)
            print('still, not parked: car %d t=%.0f flags=%s sec %d node %d/%d (%.0f m from it)' % (i, b[0], b[3] or '-', p[2], p[3], p[4], math.hypot(p[0] - b[1], p[1] - b[2])))
    print('traffic car intervals %d, still and parked %d' % (n, parked))


if __name__ == '__main__':
    a = sys.argv[1:]
    if not a:
        sys.exit(__doc__)
    world = a[1] if len(a) > 1 else 'build/openworld_city'
    stuck(run(a[0], world, int(a[2]) if len(a) > 2 else 200, a[3] if len(a) > 3 else '50.1,-747.2,29.4,-15824'), world)
