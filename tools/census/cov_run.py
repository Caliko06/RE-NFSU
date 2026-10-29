#!/usr/bin/env python3
"""Which guest functions ever ran: native scenarios on the RN_COV build, one bitmap each, and their union.
Method and numbers: docs/re/coverage_method.md.

usage: cov_run.py run [scenario ...]    run the scenarios (default: all) on build/speed_cov, at most JOBS at once, each bounded
       cov_run.py union                 build/cov/*.bin -> census/cov/union.{bin,json} and the three sanity checks
       cov_run.py list
build first:  RN_COV=1 .venv/bin/python tools/recomp/build.py native      (build/gen_cov, build/obj_cov, build/speed_cov)
Per scenario: build/cov/<s>.bin (host/cov.c format: "RNCV", u32 N, bitmap entered, bitmap seen by rn_call),
census/cov/<s>.json {hits, via_call, total, secs (wall), rn_secs (bound), end}. Run dirs: build/cov/run/<s>/ (game/ hard-linked,
save/ a copy: a run never touches the OWNER's save). Game launches go through ~/.claude/hooks/macgate.sh, off-screen (--shot).
The key sequences and RN_JUMP rows are tools/completion.py's, so a scenario drives the game the way the census runs do."""
import json, os, re, struct, subprocess, sys, time
HERE = os.path.dirname(os.path.abspath(__file__))
sys.path[:0] = [os.path.join(HERE, '..')]
import completion as C  # noqa: E402  (imported: routes only)
R = C.R
BIN = f'{R}/build/speed_cov'
JOBS = int(os.environ.get('COV_JOBS', 3))
GATE = os.path.expanduser('~/.claude/hooks/macgate.sh')


def jumprun(name):    # RN_JUMP row: (keys, RN_JUMP, bound)
    k, j, secs = C.jump(name)[:3]
    return dict(RN_KEYS=k, RN_JUMP=j), min(secs, 420)


def rowrun(row, secs):
    return dict(RN_KEYS=C.ROWS[row] if isinstance(C.ROWS[row], str) else C.keys(C.ROWS[row])), secs


def scenarios():
    s = {'title': ({}, 60)}                                   # no keys: intro movie, title, the front end's first screens
    # same first tap as every key run (20 s: skips the intro movie), then nothing: the title's own screens, comparable with a race run
    s['title_skip'] = (dict(RN_KEYS='20000:RETURN'), 30)
    for name, jmp in [('circuit', 'jump_0_1003'), ('sprint', 'jump_1_1103'), ('drag', 'jump_5_1201'), ('drift', 'jump_6_1304'),
                      ('lapko', 'jump_2_1002'), ('freerun', 'jump_3_1002')]:
        s[name] = jumprun(jmp)
    s['world'] = jumprun('jump_3_1010')                     # track 1010 (the merged city, RN_WORLD_DIR below)
    # garage/options: RN_OPEN switches the menu to the screen as the menus do (completion.py OPEN), then taps inside it
    s['garage'] = (dict(RN_KEYS=C.ROWS['garage'], RN_OPEN=C.OPEN['garage']), 45)
    s['options'] = (dict(RN_KEYS=C.ROWS['options'], RN_OPEN=C.OPEN['options'], RN_CALL=C.CALL['options']), 45)
    # movies: career0 = a new profile, MU_UG_NewCareerFMV (01_DAY.mad, 02_FAN_S.mad), the 1003 race, NewCareerExtroFMV; the
    # title movie E3_TITLE.mad plays in every scenario
    s['movies'] = (dict(RN_KEYS=C.ROWS['career0'], RN_AUTOPILOT='1', RN_FINISH='1'), 420)
    return s


def run_one(name, env_extra, secs):
    d = f'{R}/build/cov/run/{name}'
    subprocess.run(['rm', '-rf', d])
    os.makedirs(d)
    subprocess.run(['cp', '-al', f'{R}/game', f'{d}/game'], check=True)
    subprocess.run(['cp', '-r', f'{R}/save', f'{d}/save'], check=True)
    out = f'{R}/build/cov/{name}.bin'
    if os.path.exists(out): os.remove(out)
    env = dict(os.environ, RN_TURBO='4', RN_SECS=str(secs), RN_SCREEN='640x480', RN_RASTER='1000000', RN_FLOWLOG='1', RN_SEED='0x1234',
               RN_AUTOPILOT='1', RN_WORLD_DIR=f'{R}/build/openworld', RN_COV_OUT=out)
    env.update(env_extra)
    subprocess.run([GATE], check=True)
    t0 = time.time()
    with open(f'{d}/log.txt', 'w') as log:
        p = subprocess.Popen(['nice', '-n', '5', BIN, f'{R}/pc/Speed.exe', 'game', '--shot', 'shot.png'], cwd=d, env=env,
                             stdout=log, stderr=subprocess.STDOUT, stdin=subprocess.DEVNULL, start_new_session=True)
    return name, p, t0, secs


def finish(name, p, t0, secs):
    try:
        p.wait(timeout=max(0, secs + 90 - (time.time() - t0)))
    except subprocess.TimeoutExpired:
        p.kill(); p.wait()
    wall = time.time() - t0
    log = open(f'{R}/build/cov/run/{name}/log.txt', errors='replace').read()
    m = re.search(r'^coverage: (\d+) of (\d+) \(rn_call alone saw (\d+)\)', log, re.M)
    end = next((l for l in reversed(log.splitlines()) if l.startswith(('RN_SECS', 'RN_JUMP: done', 'STOP', 'career done'))), 'no end line (killed)')
    rec = dict(scenario=name, hits=int(m[1]) if m else None, via_call=int(m[3]) if m else None, total=int(m[2]) if m else None,
               secs=round(wall, 1), rn_secs=secs, end=end[:120])
    os.makedirs(f'{R}/census/cov', exist_ok=True)
    json.dump(rec, open(f'{R}/census/cov/{name}.json', 'w'), indent=1)
    print(json.dumps(rec), flush=True)


def run(names):
    sc = scenarios()
    todo, live = list(names or sc), []
    os.makedirs(f'{R}/build/cov/run', exist_ok=True)
    while todo or live:
        while todo and len(live) < JOBS:
            n = todo.pop(0)
            live.append(run_one(n, *sc[n]))
        a = live.pop(0)
        finish(*a)


def load(path):
    b = open(path, 'rb').read()
    assert b[:4] == b'RNCV', path
    n = struct.unpack_from('<I', b, 4)[0]
    k = (n + 7) // 8
    bits = lambda o: {i for i in range(n) if b[o + i // 8] >> (i % 8) & 1}
    return n, bits(8), bits(8 + k)


def addrs():
    t = open(f'{R}/build/gen_cov/table.c').read()
    return [int(x, 16) for x in re.findall(r'0x([0-9a-f]+)', t.split('rn_fn_addr[]')[1].split('}')[0])]


def union():
    A = addrs()
    runs = {os.path.basename(f)[:-4]: load(f'{R}/build/cov/{f}') for f in sorted(os.listdir(f'{R}/build/cov')) if f.endswith('.bin') and f != 'union.bin'}
    n = len(A)
    assert all(v[0] == n for v in runs.values())
    U, V = set(), set()
    for _, e, v in runs.values(): U |= e; V |= v
    k = (n + 7) // 8
    img = bytearray(b'RNCV' + struct.pack('<I', n) + bytes(2 * k))
    for i in U: img[8 + i // 8] |= 1 << (i % 8)
    for i in V: img[8 + k + i // 8] |= 1 << (i % 8)
    open(f'{R}/census/cov/union.bin', 'wb').write(img)
    chk = {}
    # (a) a title-only run's set is a subset of the circuit run's set
    for tn in ('title', 'title_skip'):      # title = no keys (the whole intro movie plays); title_skip = the race runs' first tap
        if tn in runs and 'circuit' in runs:
            t, c = runs[tn][1], runs['circuit'][1]
            chk[f'a_{tn}_subset_of_circuit'] = dict(title=len(t), circuit=len(c), title_not_in_circuit=len(t - c),
                                                     examples=[hex(A[i]) for i in sorted(t - c)[:10]])
    # (b) functions entered but never seen by rn_call in any run: direct-call-only. 0x674898 is the brief's example
    direct_only = U - V
    ex = A.index(0x674898) if 0x674898 in A else None
    chk['b_direct_call_only'] = dict(count=len(direct_only), f_674898_entered=ex in U, f_674898_seen_by_rn_call=ex in V,
                                      per_run_f_674898={n_: (ex in e, ex in v) for n_, (_, e, v) in runs.items()},
                                      examples=[hex(A[i]) for i in sorted(direct_only)[:10]])
    # (c) the old rn_call-only bitmap against the entry bitmap, same runs
    chk['c_union_vs_rn_call_only'] = dict(union_entry=len(U), union_rn_call_only=len(V), old_is_subset=V <= U, old_not_in_new=len(V - U),
                                           missed_by_old=len(U - V), pct_old=round(100 * len(V) / len(U), 1))
    rec = dict(total=n, hits=len(U), pct=round(100 * len(U) / n, 1), via_call=len(V), scenarios={k_: len(v[1]) for k_, v in runs.items()},
               checks=chk, addrs=[f'{A[i]:x}' for i in sorted(U)])
    json.dump(rec, open(f'{R}/census/cov/union.json', 'w'), indent=1)
    print(json.dumps({k_: v for k_, v in rec.items() if k_ != 'addrs'}, indent=1))


if __name__ == '__main__':
    a = sys.argv[1:]
    if a[:1] == ['run']: run(a[1:])
    elif a[:1] == ['union']: union()
    elif a[:1] == ['list']: print(' '.join(scenarios()))
    else: sys.exit(__doc__)
