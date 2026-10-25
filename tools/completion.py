# M8.6 completion matrix (docs/PLAN.md), Pod side. One native build/speed per row, each in its own run dir (AGENTS.md:
# game/ as a hard-link copy, its own save/), the game's autopilot drives (RN_AUTOPILOT, RN_SEED), RN_RASTER keeps the CPU
# backend off the frames nobody looks at, RN_FLOWLOG logs the game-flow states and keeps a shot at each change.
# usage: completion.py launch ROW[.SEED] ...     start rows in the background (nohup), runs/<row>.<seed>/
#        completion.py queue N ROW[.SEED] ...    the same, N at a time, blocking (run it under nohup)
#        completion.py collect                   runs/*/log.txt -> census/completion.json (one row per run dir), shots -> WebP
import json, os, re, shutil, subprocess, sys, time
R = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SECS, GAP = 1300, 3000   # 6/8 comes near 840 s with 4 rows on 10 cores; leaving takes ~30 s more
SEEDS = ['0x1234', '0x5678', '0x9abc']

# Drag and Drift: the mode's Accept can open the tutorial movie first (event 0xc519bfc8 -> MU_UG_MovieTheaterViewer.fng,
# HANDOFF 2026-10-25); RETURNs skip it and are dropped when the car list is already up.
MOVIE = ['4000@!MU_QuickRaceCarSelect:RETURN'] * 2

def menu(mode, loc=0):
    # Each tap waits for its screen (host/input.c: "=" anchors on a front-end package, rn_fe). Timed taps lost a stage:
    # the splash ate a RETURN and the RIGHT, so the mode DOWN landed on the profile screen (runs/sprint.0x1234
    # 2026-10-25: "flow fe" MU_UG_NewOrLoad_PC2 at the DOWN, mode stayed 0). Title RETURN, RETURNs until the profile
    # screen, profile, Quick Race (the main menu starts on it), mode, car, transmission dialog, track, options.
    q = lambda scr, k, ms=1500: f'{ms}@={scr}:{k}'
    return (['RETURN'] + ['3000@!MU_UG_NewOrLoad_PC2:RETURN'] * 4 + [q('MU_UG_NewOrLoad_PC2', 'RETURN'), q('MU_Main_PC', 'RETURN')]
            + [q('MU_QuickRaceModeSelect', 'DOWN')] * mode
            + [q('MU_QuickRaceModeSelect', 'RETURN')] + MOVIE * (mode in (2, 3)) + [q('MU_QuickRaceCarSelect', 'RETURN'), '1500@!MU_QuickRaceTrackSelect:RETURN']
            + [q('MU_QuickRaceTrackSelect', 'RIGHT')] * loc + [q('MU_QuickRaceTrackSelect', 'RETURN'), q('MU_QuickRaceOptions_PC', 'RETURN')])

# Quick Race MODE rows: 0 Circuit, 1 Sprint, 2 Drag, 3 Drift, 4 Lap Knockout, 5 Free Run (the list wraps; explore_qr shots).
# The main menu starts on QUICK RACE; GO UNDERGROUND is one UP.
# explore_*: a menu path tapped step by step with a kept frame every 120 (RN_KEEP), to learn a path before it is a row.
ROWS = {'explore_career': ','.join(f'{20000 + 4000 * i}:RETURN' for i in range(12)),
        'explore_qr': ','.join(f'{20000 + 3000 * i}:{k}' for i, k in enumerate(['RETURN', 'RETURN', 'RIGHT', 'RETURN'] + ['DOWN'] * 8)),
        'explore_ug': ','.join(f'{20000 + 4000 * i}:{k}' for i, k in enumerate(['RETURN', 'RETURN', 'UP'] + ['RETURN'] * 10)),
        'circuit': menu(0), 'sprint': menu(1), 'drag': menu(2), 'drift': menu(3), 'lapko': menu(4), 'freerun': menu(5)}

# After the race (flow state 6/8), RETURN walks Results -> Race Style Points -> the post-race menu (Restart, Statistics,
# Leave Race; RETURN there opens "Restart Race? OK / Cancel", runs/leave_ret 2026-10-25). So: three RETURNs, DOWN DOWN to
# Leave Race, RETURN, then the confirm: it starts on Cancel, LEFT moves to OK (runs/circuit.0x5678 2026-10-25: 6/8 ->
# 7/0 at 9543 -> front end 3 at 9575 -> second race; the RETURN and RIGHT variants stayed on the dialog).
# Taps "ms@6/8:" wait for that state and count from the tap before (host/input.c). Then, back in the front end (state 3,
# any race state), RETURNs start the next race from wherever the menu lands.
# Race Style Points takes two RETURNs (the first skips the tally): runs/circuit.0x1234 DILOG, RETURN 8641 -> Points,
# RETURN 8701 -> tally 77..457 done, DOWN DOWN 8761/8810 lost on Points, RETURN 8821 -> menu (8880, cursor on Restart),
# RETURN 8881 -> "Restart Race?" (8940). The menu reads keys on edges only (0x5744b0), so a tap on Points is gone.
# The screens before the menu vary (0x49e100: Results, StyleAnimator, RewardPopup only with a reward, runs/lapko.0x5678
# "Style Reward" ate a RETURN), so RETURNs walk them until the flow log sees PostRaceMenu (host/d3d9.c rn_screen) and the
# rest are dropped; the menu taps wait for it.
_LEAVE = ['3000@6/8:RETURN'] + ['4000@!PostRaceMenu:RETURN'] * 6 + ['1500@=PostRaceMenu:DOWN'] * 2 + ['1500@=PostRaceMenu:RETURN']
LEAVE = [_LEAVE + ['3000@6:LEFT', '1500@6:RETURN']] * 3
NEXT = ['8000@3:RETURN'] + ['3000@3:RETURN'] * 9

def keys(seq, post=()):
    # The first tap at 20 s (the intro movie), then each waits for its screen; in the race, two RETURNs leave PreRaceStats.
    return ','.join([f'20000:{seq[0]}'] + seq[1:] + ['3000@6:RETURN'] * 2 + list(post))

# sweep_<mode>: every track of a mode in one run. After Leave Race the front end comes back on MU_QuickRaceModeSelect
# with the cursor on the mode (runs/sprint.0x1234 2026-10-25, "flow fe" at 15060); each next race takes one more RIGHT
# on the track list (the list keeps its cursor: assumed, the "flow open" TRACKB ids show it).
SWEEP = {'circuit': (0, 8), 'sprint': (1, 8), 'drag': (2, 6), 'drift': (3, 8), 'lapko': (4, 8), 'freerun': (5, 8)}
def sweep(mode, start=0):   # sweep_<mode>-<k>: from the k-th track of the list on (the tracks a short run missed)
    m, n = SWEEP[mode]
    q = lambda scr, k: f'1500@={scr}:{k}'
    race = ['3000@6:RETURN'] * 2 + _LEAVE + ['3000@6:LEFT', '1500@6:RETURN']
    out = keys(menu(m, start)).split(',')[:-2] + race
    for i in range(start + 1, n):
        out += [q('MU_QuickRaceModeSelect', 'RETURN')] + MOVIE * (m in (2, 3)) + [q('MU_QuickRaceCarSelect', 'RETURN'), '1500@!MU_QuickRaceTrackSelect:RETURN',
                q('MU_QuickRaceTrackSelect', 'RIGHT'), q('MU_QuickRaceTrackSelect', 'RETURN'), q('MU_QuickRaceOptions_PC', 'RETURN')] + race
    return ','.join(out)
ROWS.update({f'sweep_{k}': sweep(k) for k in SWEEP})

def launch(run):
    row, seed = (run.split('.') + [SEEDS[0]])[:2]
    d = f'{R}/runs/{row}.{seed}'
    subprocess.run(['rm', '-rf', d]); os.makedirs(d)
    subprocess.run(['cp', '-al', f'{R}/game', f'{d}/game'], check=True)
    subprocess.run(['cp', '-r', f'{R}/save', f'{d}/save'], check=True)
    seq = ROWS[row] if '-' not in row else sweep(row[6:].split('-')[0], int(row.split('-')[1]))
    # RN_TURBO 4: the guest clocks run 4x (host/win32.c now_us); a sprint race + leave took ~10 min at 1x, ~3.3 min at 4x.
    secs = 330 * (SWEEP[row[6:].split('-')[0]][1] - int((row + '-0').split('-')[1])) + 120 if row.startswith('sweep_') else SECS
    env = dict(os.environ, RN_TURBO='4', RN_SECS=str(secs), RN_SCREEN='640x480', RN_RASTER='300', RN_FLOWLOG='1', RN_SEED=seed,
               RN_AUTOPILOT='1', RN_KEYS=seq if isinstance(seq, str) else keys(seq, LEAVE[SEEDS.index(seed) % 3] + NEXT))
    if row.startswith('explore'): env.update(RN_KEEP='120', RN_SECS='240')
    with open(f'{d}/log.txt', 'w') as log:
        return subprocess.Popen(['nice', '-n', '5', f'{R}/build/speed', f'{R}/pc/Speed.exe', 'game', '--shot', 'shot.png'], cwd=d, env=env,
                         stdout=log, stderr=subprocess.STDOUT, stdin=subprocess.DEVNULL, start_new_session=True)

ALL_ROWS = {r['id']: r['group'] for r in json.load(open(f'{R}/census/rows.json'))['rows']}
QR_ROWS = {k for k, g in ALL_ROWS.items() if g == 'quick_race'}

def rows_of(d):
    # flow.txt: only the flow lines of a log that was too big to keep (2026-10-24: 5-8 GB each, Pod disk full)
    log = open(f'{d}/log.txt' if os.path.exists(f'{d}/log.txt') else f'{d}/flow.txt', errors='replace').read().splitlines()
    # A run can chain races (menu, race, back to menu, the next race): one row per race. A race's lines run from the
    # front end it starts in to the front end it comes back to (the first "flow state 3/" after a "flow state 7/").
    cut, unl = [0], False
    for i, l in enumerate(log):
        if l.startswith('flow state 7/'): unl = True
        elif unl and l.startswith('flow state 3/'): cut.append(i); unl = False
    return [row_of(d, log[a:b + 1]) for a, b in zip(cut, cut[1:] + [len(log)])]

def row_of(d, log):
    st = [(int(m[1]), int(m[2]), int(m[3])) for m in (re.match(r'flow state (\d+)/(-?\d+) \(frame (\d+)\)', l) for l in log) if m]
    seen = [s for s, _, _ in st]
    raced = 6 in seen
    after = seen[seen.index(6):] if raced else []
    back = 7 in after and 3 in after[after.index(7):]
    again = back and 6 in after[after.index(7):]
    # The row (census/rows.json id): the track is the TRACKB<id>.LZC the game opened (host/win32.c RN_FLOWLOG), the mode is
    # [0x777cc8] at the Accept (host/d3d9.c "flow mode"). A track the mode does not list (rows.json, 0x4ab470) is no row (2026-10-25: sprint/drag/drift taps loaded 1002).
    ids = {0: 'circuit', 1: 'sprint', 2: 'lapko', 3: 'freerun', 5: 'drag', 6: 'drift'}
    modes = [int(m[1]) for m in (re.match(r'flow mode (\d+)', l) for l in log[:next((i for i, l in enumerate(log) if l.startswith('flow state 6/')), len(log))]) if m]
    # No "flow mode" line, no mode: the timed taps of those runs put the mode DOWNs on the profile screen (2026-10-25).
    mode = ids.get(modes[-1], f'mode{modes[-1]}') if modes else None
    trk = [int(m[1]) for m in (re.search(r'flow open .*TRACKB(\d{4})\.LZC', l, re.I) for l in log) if m]
    row = f'qr.{mode}.{trk[0]}' if trk and f'qr.{mode}.{trk[0]}' in QR_ROWS else None
    # A career run: the event under the cursor at the race start ([0x735dc8], host/d3d9.c "flow event").
    ev = [int(m[1]) for m in (re.match(r'flow event (\d+)', l) for l in log[:next((i for i, l in enumerate(log) if l.startswith('flow state 6/')), len(log))]) if m]
    if os.path.basename(d).startswith(('career', 'explore_ug')) and ev and f'career.{ev[-1]}' in ALL_ROWS: row = f'career.{ev[-1]}'
    stop = next((l for l in reversed(log) if re.search(r'STOP|stop:|unimplemented|missing|fault|abort', l, re.I)), '')
    end = next((l for l in reversed(log) if l.startswith('RN_SECS')), 'running or killed')
    return {'row': row, 'mode': mode, 'track': trk[0] if trk else None, 'reached': {'menu': 3 in seen, 'start': raced, 'racing': any(s == 6 and r not in (1, 255) for s, r, _ in st),
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
    def live():   # every native row of this repo, also those another queue started (one game process at a time)
        ps = subprocess.run(['ps', '-axo', 'command='], capture_output=True, text=True).stdout.splitlines()
        return sum(l.startswith(f'{R}/build/speed') for l in ps)
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
    rows = {f'{r}#{i}' if i else r: v for r in runs for i, v in enumerate(rows_of(f'{R}/runs/{r}')) if not i or v['reached']['start']}
    json.dump(rows, open(f'{R}/census/completion.json', 'w'), indent=1)
    for r, v in rows.items(): print(f'{r:10s}', ' '.join(k for k, x in v['reached'].items() if x) or '-', '|', v['end'], '|', v['stop'][:80])
