#!/usr/bin/env python3
# census/natural.json: the 167 rows (census/rows.json) finished naturally: RN_AUTOPILOT drives, no RN_FINISH (tools/completion.py
# queue, runs/natural/rows.txt). A race row is OK when every stage reached its results (6/8); Free Run has no results, so it is OK
# when it raced and came back to the menu; career.0 (prologue) has no results screen either (completion.py note), same rule.
# A row may be proven by a later rerun dir (<row>.0x01234, the same seed): its binary and fixes are named in 'run'.
# usage: natural.py SINCE_FILE   (only run dirs whose log.txt is newer than that file count)
import json, os, re, sys
R = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
since = os.path.getmtime(sys.argv[1])
sys.path.insert(0, f'{R}/tools'); _argv, sys.argv = sys.argv, ['completion.py']; import completion as C; sys.argv = _argv
MODE = {'circuit': 0, 'sprint': 1, 'lapko': 2, 'freerun': 3, 'drag': 5, 'drift': 6}
def run_name(row):
    g, *rest = row['id'].split('.')
    return f'cjump_{rest[0]}' if g == 'career' else f'jump_{MODE[rest[0]]}_{rest[1]}' if g == 'qr' else None
out, n, GAME = {}, 0, C.game_rows()
for row in json.load(open(f'{R}/census/rows.json'))['rows']:
    name, rid = run_name(row), row['id']
    if not name:   # game.* rows: proven by completion.py game_rows over this batch (garage, options, career0 runs)
        fresh = lambda k: os.path.getmtime(f"{R}/runs/{k.split('#')[0]}/log.txt") >= since if os.path.exists(f"{R}/runs/{k.split('#')[0]}/log.txt") else False
        g = {v['row']: v for k, v in GAME.items() if fresh(k)}.get(rid)
        out[rid] = dict(state='OK' if g else 'NO_RUN', run='game_rows', why=(g or {}).get('why', '')); n += bool(g); continue
    best = None
    for seed in ('0x01234', '0x1234', '0x5678'):   # the rerun (same seed) wins; 0x5678 = a second seed, named in 'run'
        d = f'{R}/runs/{name}.{seed}'
        if not os.path.exists(f'{d}/log.txt') or os.path.getmtime(f'{d}/log.txt') < since: continue
        log = open(f'{d}/log.txt', errors='replace').read()
        st = [(int(a), int(b)) for a, b in re.findall(r'^flow state (\d+)/(-?\d+) ', log, re.M)]
        res = sum(b == (6, 8) and a != (6, 8) for a, b in zip(st, st[1:]))
        seen = [s for s, _ in st]
        back = 6 in seen and 7 in seen[seen.index(6):] and 3 in seen[seen.index(6):][seen[seen.index(6):].index(7):]
        free = rid.startswith('qr.freerun') or rid == 'career.0'
        ok = (6 in seen and back) if free else res >= len(row.get('stages', [1]))
        stuck = len(re.findall(r'^RN_AUTOPILOT: (?:stuck|no progress)', log, re.M))
        best = dict(state='OK' if ok else 'NO_RESULTS', run=f'{name}.{seed}', results=res, stages=len(row.get('stages', [1])),
                    unstick=stuck, last=next((f'{a}/{b}' for a, b in reversed(st)), ''))
        if ok: break
    out[rid] = best or dict(state='NO_RUN', run=name)
    n += out[rid]['state'] == 'OK'
json.dump(dict(ok=n, total=len(out), rule='autopilot, no RN_FINISH; OK = every stage reached 6/8 (Free Run, prologue: raced and back to the menu)',
               rows=out), open(f'{R}/census/natural.json', 'w'), indent=1)
print(f'natural: {n}/{len(out)}', {s: sum(v["state"] == s for v in out.values()) for s in ('OK', 'NO_RESULTS', 'NO_RUN')})
