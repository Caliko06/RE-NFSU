# M8.6 completion matrix (docs/PLAN.md), Pod side. One native build/speed per row, each in its own run dir (AGENTS.md:
# game/ as a hard-link copy, its own save/), the game's autopilot drives (RN_AUTOPILOT, RN_SEED), RN_RASTER keeps the CPU
# backend off the frames nobody looks at, RN_FLOWLOG logs the game-flow states and keeps a shot at each change.
# usage: completion.py launch ROW [ROW ...]   start rows in the background (nohup), runs/<row>/
#        completion.py collect                runs/*/log.txt -> census/completion.json (one row per run dir)
import json, os, re, subprocess, sys
R = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SECS, GAP = 600, 3000

def menu(mode, loc=0):   # title, profile, (main menu) Quick Race, mode, car, transmission, location, Accept (tools/abrun.py)
    return ['RETURN', 'RETURN', 'RIGHT', 'RETURN'] + ['DOWN'] * mode + ['RETURN'] * 3 + ['RIGHT'] * loc + ['RETURN', 'RETURN']

# Quick Race MODE rows: 0 Circuit, 1 Sprint, 2 Drag, 3 Drift, 4 Lap Knockout, 5 Free Run (the list wraps; explore_qr shots).
# The main menu starts on QUICK RACE (the RIGHT does nothing); GO UNDERGROUND is one UP.
# explore_*: a menu path tapped step by step with a kept frame every 120 (RN_KEEP), to learn a path before it is a row.
ROWS = {'explore_career': ','.join(f'{20000 + 4000 * i}:RETURN' for i in range(12)),
        'explore_qr': ','.join(f'{20000 + 3000 * i}:{k}' for i, k in enumerate(['RETURN', 'RETURN', 'RIGHT', 'RETURN'] + ['DOWN'] * 8)),
        'explore_ug': ','.join(f'{20000 + 4000 * i}:{k}' for i, k in enumerate(['RETURN', 'RETURN', 'UP'] + ['RETURN'] * 10)),
        'circuit': menu(0), 'sprint': menu(1), 'drag': menu(2), 'drift': menu(3), 'lapko': menu(4), 'freerun': menu(5)}

# After the race (flow state 6/8 = results): RETURN past the results, then DOWN DOWN RETURN = Leave Race on the post-race
# menu (Restart / Statistics / Leave Race). Taps "ms@6/8:" wait for that state and count from the tap before (host/input.c).
LEAVE = ['3000@6/8:RETURN', '3000@6/8:DOWN', '1000@6/8:DOWN', '1000@6/8:RETURN'] * 3

def keys(seq, post=LEAVE):
    # A tap lost in a menu transition stalls the row on Accept: four more RETURNs after the path (during the load they
    # do nothing; in the race too). Then the post-race taps.
    t, out = 20000, []
    for k in seq + ['RETURN'] * 4: out.append(f'{t}:{k}'); t += GAP if len(out) <= len(seq) else 4000
    return ','.join(out + post)

def launch(row):
    d = f'{R}/runs/{row}'
    subprocess.run(['rm', '-rf', d]); os.makedirs(d)
    subprocess.run(['cp', '-al', f'{R}/game', f'{d}/game'], check=True)
    subprocess.run(['cp', '-r', f'{R}/save', f'{d}/save'], check=True)
    seq = ROWS[row]
    env = dict(os.environ, RN_SECS=str(SECS), RN_SCREEN='640x480', RN_RASTER='300', RN_FLOWLOG='1', RN_SEED='0x1234',
               RN_AUTOPILOT='1', RN_KEYS=seq if isinstance(seq, str) else keys(seq))
    if row.startswith('explore'): env.update(RN_KEEP='120', RN_SECS='240')
    with open(f'{d}/log.txt', 'w') as log:
        subprocess.Popen(['nice', '-n', '5', f'{R}/build/speed', f'{R}/pc/Speed.exe', 'game', '--shot', 'shot.png'], cwd=d, env=env,
                         stdout=log, stderr=subprocess.STDOUT, stdin=subprocess.DEVNULL, start_new_session=True)

def row_of(d):
    log = open(f'{d}/log.txt', errors='replace').read().splitlines()
    st = [(int(m[1]), int(m[2]), int(m[3])) for m in (re.match(r'flow state (\d+)/(-?\d+) \(frame (\d+)\)', l) for l in log) if m]
    seen = [s for s, _, _ in st]
    raced = 6 in seen
    after = seen[seen.index(6):] if raced else []
    stop = next((l for l in reversed(log) if re.search(r'STOP|stop:|unimplemented|missing|fault|abort', l, re.I)), '')
    end = next((l for l in reversed(log) if l.startswith('RN_SECS')), 'running or killed')
    return {'reached': {'menu': 3 in seen, 'start': raced, 'racing': any(s == 6 and r not in (1, 255) for s, r, _ in st),
                        'results': any(s == 6 and r == 8 for s, r, _ in st),
                        'unload': 7 in after, 'back_to_menu': 7 in after and 3 in after[after.index(7):] if 7 in after else False},
            'states': [f'{s}/{r}@{f}' for s, r, f in st], 'stop': stop, 'end': end,
            'shots': sorted(f for f in os.listdir(d) if f.startswith('shot.png.'))}

if sys.argv[1] == 'launch':
    for r in sys.argv[2:]: launch(r)
elif sys.argv[1] == 'collect':
    rows = {r: row_of(f'{R}/runs/{r}') for r in sorted(os.listdir(f'{R}/runs')) if os.path.exists(f'{R}/runs/{r}/log.txt')}
    json.dump(rows, open(f'{R}/census/completion.json', 'w'), indent=1)
    for r, v in rows.items(): print(f'{r:10s}', ' '.join(k for k, x in v['reached'].items() if x) or '-', '|', v['end'], '|', v['stop'][:80])
