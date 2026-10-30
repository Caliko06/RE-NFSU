#!/usr/bin/env python3
"""Sums up a run's RN_AILOG lines (host/rivals.c ai_log). Usage: tools/ailog.py [--frames N] <webcheck.log> [...]
--frames N: only the first N race frames, so runs with RN_FIXEDCLOCK compare at the same moment.
Per racer: mean speed, last route metres, finish rank, overtakes (rank changes won), and the counts of AI actions and nitro starts."""
import re, sys, collections

NAMES = {0: 'pass', 1: 'avoid', 5: 'block', 0xa: 'unstuck', 0xc: 'hit', 0xe: 'crash'}

args = sys.argv[1:]
limit = int(args[1]) if args[0] == '--frames' else 1 << 30
for path in args[2 if args[0] == '--frames' else 0:]:
    sp, route, rank, won, draft = collections.defaultdict(list), {}, {}, collections.Counter(), 0
    ev, frames, sl = collections.defaultdict(collections.Counter), [], collections.defaultdict(list)
    start = None
    for line in open(path, errors='replace'):
        f = re.search(r'AI(?:LOG|EV) (\d+)', line)
        if f:
            start = start or int(f[1])
            if int(f[1]) - start > limit: break
        m = re.search(r'AILOG (\d+) draft (\d+) (.*)', line)
        if m:
            frames.append(int(m[1])); draft = int(m[2])
            for rec in m[3].split():
                name, kind, r, v, pos, slip = rec.rsplit(':', 5)
                sp[name].append(float(v)); route[name] = float(r); sl[name].append(float(slip))
                if name in rank and int(pos) < rank[name]: won[name] += rank[name] - int(pos)
                rank[name] = int(pos)
        m = re.search(r'AIEV \d+ (\S+) (act (\d+)|nos)', line)
        if m:
            k = 'nos' if m[2] == 'nos' else NAMES.get(int(m[3]))
            if k: ev[m[1]][k] += 1
    print(f'{path}: {len(frames)} s of race, {draft} drafts')
    for n in sorted(sp, key=lambda n: rank[n]):
        v = sp[n]
        print(f'  {n:10} rank {rank[n]} mean {sum(v) / len(v) * 3.6:5.1f} km/h max {max(v) * 3.6:5.1f} route {route[n]:7.0f} m slip {sum(sl[n]) / len(sl[n]):4.1f} deg overtakes {won[n]:2}  '
              + ' '.join(f'{k} {c}' for k, c in sorted(ev[n].items())))
