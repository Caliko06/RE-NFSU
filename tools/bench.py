# The 60 fps / load bench: one quick race per run in headless Chrome on this Mac, at the OWNER's window (1920x871 css, dpr 2),
# page defaults (remaster, MSAA, FXAA), the game's autopilot driving (RN_AUTOPILOT, same seed as tools/abrun.py).
# Prints the load times from the game-flow labels (RN_FLOWLOG, host/d3d9.c) and the race frames from the telemetry.
# usage: bench.py MODE LOC SECS [NAME]   (QUICK RACE MODE row / SELECT LOCATION index; row 2 = Drift, measured 2026-10-24)
#        bench.py --report NAME           (only re-read build/bench/NAME.*)
import json, os, re, shutil, subprocess, sys
from completion import _PROFILE

OUT = 'build/bench'
GAP = 3
VIEW = os.environ.get('RN_VIEW', '1920x871@2')

def keys(mode, loc):   # same menu path as tools/abrun.py
    return ['Enter', 'Enter', 'Right', 'Enter'] + ['Down'] * mode + ['Enter', 'Enter', 'Enter'] + ['Right'] * loc + ['Enter', 'Enter']

def run(mode, loc, secs, name):
    # BENCH_JUMP='0:1003': the menu keys stop on MU_QuickRaceModeSelect and RN_JUMP starts that race (host/input.c);
    # the car select's GenericDialog took a key of the full menu path (build/bench/b4_base, 2026-10-25).
    # The keys to that screen wait for each screen (RN_KEYS anchors, tools/completion.py's profile path): timed taps hung a
    # jump run when the title movie ended later than the 20 s tap (build/bench/g_short: 20 ms of margin), so every later
    # tap landed one screen early and MU_QuickRaceModeSelect never showed.
    jump = os.environ.get('BENCH_JUMP')
    ks = [] if jump else keys(mode, loc)
    ours = ','.join(f'{20 + GAP * i}:{"Arrow" + x if x in ("Right", "Down") else x}' for i, x in enumerate(ks))
    nav = ','.join(['20000:RETURN'] + _PROFILE[1:] + ['1500@=MU_Main_PC:RETURN']) if jump else ''
    url = os.environ.get('BENCH_URL', 'http://127.0.0.1:5180/') + '?env='   # BENCH_URL: another server, e.g. a worktree's on 5181
    url += 'RN_SEED=0x1234,RN_AUTOPILOT=1,RN_FLOWLOG=1' + os.environ.get('BENCH_ENV', '') + (f'&jump={jump}&keys={nav}' if jump else '') + os.environ.get('BENCH_Q', '')   # BENCH_Q='&gpuprof=1'
    env = dict(os.environ, RN_CDP_PORT=os.environ.get('RN_CDP_PORT', '9341'), RN_VIEW=VIEW)
    with open(f'{OUT}/{name}.out', 'w') as f:
        subprocess.run(['node', 'tools/webcheck.mjs', url, str(20 + GAP * (len(ks) or 6) + secs), f'{OUT}/{name}.png', ours],
                       env=env, stdout=f, stderr=subprocess.STDOUT)
    shutil.copy('build/webcheck.log', f'{OUT}/{name}.log')
    open(f'{OUT}/{name}.load', 'w').write(f'{os.getloadavg()[1]:.1f}\n')   # 5-minute load at the end of the run
    shutil.copy('build/webcheck.telemetry.ndjson', f'{OUT}/{name}.ndjson')

def report(name):
    log = [l.rstrip('\n') for l in open(f'{OUT}/{name}.log', errors='replace')]
    ev = []
    for l in log:
        m = re.match(r'([\d.]+) (flow (state \S+|\S+)|key down (\S+)|d3d9 first Present|d3d9 race HUD)', l)
        if m: ev.append((float(m.group(1)), m.group(3) or (m.group(4) and 'key ' + m.group(4)) or m.group(2)))
    rows, cols = [], None
    for l in open(f'{OUT}/{name}.ndjson'):
        try: o = json.loads(l)
        except ValueError: continue
        if o.get('kind') == 'session': cols = {c: i for i, c in enumerate(o['cols'])}
        elif 'rows' in o: rows += o['rows']
    pres = [r[cols['t']] / 1000 for r in rows if r[cols['present']]]
    print(f'{name}: {len(pres)} presents, {len(ev)} events')
    for t, e in ev:
        if not e.startswith('key '): print(f'  {t:7.2f}  {e}')
    keys_t = [t for t, e in ev if e.startswith('key ')]
    hud = next((t for t, e in ev if e == 'd3d9 race HUD'), None)
    first = next((t for t, e in ev if e == 'd3d9 first Present'), None)
    fe = next((t for t, e in ev if e == 'EndGameFlowLoadingFrontEnd'), None)
    unl = next((t for t, e in ev if e == 'UnloadingFrontEnd'), None)
    if fe: print(f'LOAD boot->front end: page start -> EndGameFlowLoadingFrontEnd = {fe:.2f} s (first Present {first:.2f})')
    if unl and hud: print(f'LOAD menu->race: UnloadingFrontEnd {unl:.2f} -> race HUD {hud:.2f} = {hud - unl:.2f} s')
    back = next((t for t, e in ev if hud and t > hud and e == 'EndGameFlowLoadingFrontEnd'), None)
    leave = next((t for t, e in ev if hud and t > hud and e.startswith('Unloading')), None)
    if back and leave: print(f'LOAD race->menu: {leave:.2f} -> EndGameFlowLoadingFrontEnd {back:.2f} = {back - leave:.2f} s')
    if hud:   # race frames: from 3 s after the HUD (the countdown starts) to the end of the run
        if 'holdMain' in cols:   # CPU headroom: longest main-thread GIL hold per race present (not total CPU)
            cpu, longest = [], 0
            for r in rows:
                longest = max(longest, r[cols['holdMain']])
                if r[cols['present']]:
                    if r[cols['t']] / 1000 >= hud + 3:
                        cpu.append(longest)
                    longest = 0
            cpu.sort()
            if cpu:
                print(f'CPU holdMain p50 {cpu[len(cpu) // 2]:.1f} ms ({len(cpu)} race presents)')
        dts = [b - a for a, b in zip(pres, pres[1:]) if a >= hud + 3]
        if dts:
            ms = sorted(d * 1000 for d in dts)
            n = len(ms)
            print(f'RACE frames {n}: p50 {ms[n // 2]:.1f}  p99 {ms[int(n * .99)]:.1f}  max {ms[-1]:.0f} ms   '
                  f'>33 ms: {sum(m > 33.4 for m in ms)}   >20 ms: {100 * sum(m > 20 for m in ms) / n:.2f} %   {1000 * n / sum(ms):.1f} fps')
            # gate60 (AGENTS.md): p50 at the game's own 60 Hz cap (0x585b40: 16.67 ms; c_clk2 read 16.7004 and failed on
            # <= 16.7) and no frame over 33 ms. Only on a quiet Mac (load < 6).
            print(f'GATE60 {"PASS" if ms[n // 2] <= 16.75 and ms[-1] <= 33.4 else "FAIL"}   load {open(f"{OUT}/{name}.load").read().strip() if os.path.exists(f"{OUT}/{name}.load") else "?"} (valid < 6)')
        # Each slow frame: who had the GIL (host/threads.c). heldMain ~ the frame = the main thread's own work;
        # gilMain ~ the frame = it waited for another thread (who = the start address of the longest other hold).
        if hud and 'heldMain' in cols:
            C = lambda r, k: r[cols[k]]
            ip = [i for i, r in enumerate(rows) if C(r, 'present')]
            print('SLOW frames (> 33 ms): t s, dt, heldMain, gilMain, idleMain, read, heldOther, longest other hold @ who, clock calls')
            for a, b in zip(ip, ip[1:]):
                dt = C(rows[b], 't') - C(rows[a], 't')
                if dt <= 33.4 or C(rows[a], 't') / 1000 < hud + 3: continue
                seg = rows[a + 1:b + 1]
                s = lambda k: sum(C(r, k) for r in seg)
                top = max(seg, key=lambda r: C(r, 'holdOther'))
                print(f'  {C(rows[b], "t") / 1000:7.2f} {dt:5.0f} {s("heldMain"):6.1f} {s("gilMain"):6.1f} {s("idleMain"):5.1f} '
                      f'{s("read"):5.1f} {s("heldOther"):6.1f} {C(top, "holdOther"):5.1f} @ {C(top, "holdWho"):08x} {s("clockCalls"):6}')

if __name__ == '__main__':
    os.makedirs(OUT, exist_ok=True)
    if sys.argv[1] == '--report':
        report(sys.argv[2])
    else:
        mode, loc, secs = int(sys.argv[1]), int(sys.argv[2]), int(sys.argv[3])
        name = sys.argv[4] if len(sys.argv) > 4 else f'm{mode}_l{loc}'
        run(mode, loc, secs, name)
        report(name)
