# M8.6 completion matrix (docs/PLAN.md), Pod side. One native build/speed per row, each in its own run dir (AGENTS.md:
# game/ as a hard-link copy, its own save/), the game's autopilot drives (RN_AUTOPILOT, RN_SEED), RN_RASTER keeps the CPU
# backend off the frames nobody looks at, RN_FLOWLOG logs the game-flow states and keeps a shot at each change.
# usage: completion.py launch ROW[.SEED] ...     start rows in the background (nohup), runs/<row>.<seed>/
#        completion.py queue N ROW[.SEED] ...    the same, N at a time, blocking (run it under nohup)
#        completion.py collect                   runs/*/log.txt -> census/completion.json (one row per run dir), shots -> WebP
import json, os, re, shutil, subprocess, sys, time
R = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SECS, GAP = 900, 3000
SEEDS = ['0x1234', '0x5678', '0x9abc']

def menu(mode, loc=0):   # title, profile, (main menu) Quick Race, mode, car, transmission, location, Accept (tools/abrun.py)
    return ['RETURN', 'RETURN', 'RIGHT', 'RETURN'] + ['DOWN'] * mode + ['RETURN'] * 3 + ['RIGHT'] * loc + ['RETURN', 'RETURN']

# Quick Race MODE rows: 0 Circuit, 1 Sprint, 2 Drag, 3 Drift, 4 Lap Knockout, 5 Free Run (the list wraps; explore_qr shots).
# The main menu starts on QUICK RACE (the RIGHT does nothing); GO UNDERGROUND is one UP.
# explore_*: a menu path tapped step by step with a kept frame every 120 (RN_KEEP), to learn a path before it is a row.
ROWS = {'explore_career': ','.join(f'{20000 + 4000 * i}:RETURN' for i in range(12)),
        'explore_qr': ','.join(f'{20000 + 3000 * i}:{k}' for i, k in enumerate(['RETURN', 'RETURN', 'RIGHT', 'RETURN'] + ['DOWN'] * 8)),
        'explore_ug': ','.join(f'{20000 + 4000 * i}:{k}' for i, k in enumerate(['RETURN', 'RETURN', 'UP'] + ['RETURN'] * 10)),
        'circuit': menu(0), 'sprint': menu(1), 'drag': menu(2), 'drift': menu(3), 'lapko': menu(4), 'freerun': menu(5)}

# After the race (flow state 6/8), RETURN walks Results -> Race Style Points -> the post-race menu (Restart, Statistics,
# Leave Race; RETURN there opens "Restart Race? OK / Cancel", runs/leave_ret 2026-10-25). So: two RETURNs, DOWN DOWN to
# Leave Race, RETURN, then the confirm. Which button the confirm starts on is not known yet: one variant per seed.
# Taps "ms@6/8:" wait for that state and count from the tap before (host/input.c). Then, back in the front end (state 3,
# any race state), RETURNs start the next race from wherever the menu lands.
_LEAVE = ['3000@6/8:RETURN', '4000@6/8:RETURN', '4000@6/8:DOWN', '1500@6/8:DOWN', '1500@6/8:RETURN']
LEAVE = [_LEAVE + ['3000@6:RETURN'], _LEAVE + ['3000@6:LEFT', '1500@6:RETURN'], _LEAVE + ['3000@6:RIGHT', '1500@6:RETURN']]
NEXT = ['8000@3:RETURN'] + ['3000@3:RETURN'] * 9

def keys(seq, post=()):
    # A tap lost in a menu transition stalls the row on Accept: four more RETURNs after the path (during the load they
    # do nothing; in the race too). Then the post-race taps.
    t, out = 20000, []
    for k in seq + ['RETURN'] * 4: out.append(f'{t}:{k}'); t += GAP if len(out) <= len(seq) else 4000
    return ','.join(out + list(post))

def launch(run):
    row, seed = (run.split('.') + [SEEDS[0]])[:2]
    d = f'{R}/runs/{row}.{seed}'
    subprocess.run(['rm', '-rf', d]); os.makedirs(d)
    subprocess.run(['cp', '-al', f'{R}/game', f'{d}/game'], check=True)
    subprocess.run(['cp', '-r', f'{R}/save', f'{d}/save'], check=True)
    seq = ROWS[row]
    env = dict(os.environ, RN_SECS=str(SECS), RN_SCREEN='640x480', RN_RASTER='300', RN_FLOWLOG='1', RN_SEED=seed,
               RN_AUTOPILOT='1', RN_KEYS=seq if isinstance(seq, str) else keys(seq, LEAVE[SEEDS.index(seed) % 3] + NEXT))
    if row.startswith('explore'): env.update(RN_KEEP='120', RN_SECS='240')
    with open(f'{d}/log.txt', 'w') as log:
        return subprocess.Popen(['nice', '-n', '5', f'{R}/build/speed', f'{R}/pc/Speed.exe', 'game', '--shot', 'shot.png'], cwd=d, env=env,
                         stdout=log, stderr=subprocess.STDOUT, stdin=subprocess.DEVNULL, start_new_session=True)

def row_of(d):
    # flow.txt: only the flow lines of a log that was too big to keep (2026-10-24: 5-8 GB each, Pod disk full)
    log = open(f'{d}/log.txt' if os.path.exists(f'{d}/log.txt') else f'{d}/flow.txt', errors='replace').read().splitlines()
    st = [(int(m[1]), int(m[2]), int(m[3])) for m in (re.match(r'flow state (\d+)/(-?\d+) \(frame (\d+)\)', l) for l in log) if m]
    seen = [s for s, _, _ in st]
    raced = 6 in seen
    after = seen[seen.index(6):] if raced else []
    back = 7 in after and 3 in after[after.index(7):]
    again = back and 6 in after[after.index(7):]
    stop = next((l for l in reversed(log) if re.search(r'STOP|stop:|unimplemented|missing|fault|abort', l, re.I)), '')
    end = next((l for l in reversed(log) if l.startswith('RN_SECS')), 'running or killed')
    return {'reached': {'menu': 3 in seen, 'start': raced, 'racing': any(s == 6 and r not in (1, 255) for s, r, _ in st),
                        'results': any(s == 6 and r == 8 for s, r, _ in st),
                        'unload': 7 in after, 'back_to_menu': back, 'second_race': again},
            'states': [f'{s}/{r}@{f}' for s, r, f in st], 'stop': stop, 'end': end,
            'shots': sorted(f for f in os.listdir(d) if f.endswith('.webp'))}

def webp(d):   # the PNG shots -> WebP (only these and completion.json come down to the Mac)
    from PIL import Image
    for f in os.listdir(d):
        if f.startswith('shot.png') and f.endswith('.png') and not os.path.exists(f'{d}/{f[:-4]}.webp'):
            Image.open(f'{d}/{f}').save(f'{d}/{f[:-4]}.webp', quality=80)

if sys.argv[1] == 'launch':
    for r in sys.argv[2:]: launch(r)
elif sys.argv[1] == 'queue':
    def live():   # every native row of this repo, also those another queue started (the cgroup budget is shared)
        n = 0
        for p in os.listdir('/proc'):
            try: n += p.isdigit() and open(f'/proc/{p}/cmdline', 'rb').read().startswith(f'{R}/build/speed'.encode())
            except OSError: pass
        return n
    n, todo, kids = int(sys.argv[2]), sys.argv[3:], []
    while todo:
        kids = [k for k in kids if k.poll() is None]   # reap
        free = shutil.disk_usage(R).free >> 30   # the Pod disk is shared (Most Wanted): never launch under 5 GB free
        if live() < n and free >= 5: kids.append(launch(todo.pop(0)))
        elif free < 5: print(f'{time.strftime("%T")} {free} GB free: {todo[0]} waits', flush=True)
        time.sleep(10)
elif sys.argv[1] == 'collect':
    runs = [r for r in sorted(os.listdir(f'{R}/runs')) if any(os.path.exists(f'{R}/runs/{r}/{f}') for f in ('log.txt', 'flow.txt'))]
    for r in runs: webp(f'{R}/runs/{r}')
    rows = {r: row_of(f'{R}/runs/{r}') for r in runs}
    json.dump(rows, open(f'{R}/census/completion.json', 'w'), indent=1)
    for r, v in rows.items(): print(f'{r:10s}', ' '.join(k for k, x in v['reached'].items() if x) or '-', '|', v['end'], '|', v['stop'][:80])
