# Block 3 gate (docs/archive/PLAN.md): in Chrome, the game saves, the page is opened again on that save, the career goes on.
# A: career event 3 (RN_JUMP e3, RN_FINISH 1) on a fresh copy of the OWNER's save; the race's autosave (0x4c96f0,
#    <profile>_autosave.ugd) goes to build/save-headless through tools/serve.py.
# B: a new page on A's save (RN_KEEP_SAVE): the profile load must bring back A's career status (host/d3d9.c "flow
#    career": count and FNV of the 256 status bytes at 0x75eef8+0x34c), then event 4 runs and saves again.
# C: a new page on B's save, to the career map: B's last status.
# usage: tools/savegate.py   (exit 0 = PASS; logs in build/savegate_{a,b,c}.log)
import os, re, shutil, subprocess, sys, urllib.parse
sys.path.insert(0, os.path.dirname(__file__))
import completion

R = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
GATE = os.path.expanduser('~/.claude/hooks/macgate.sh')

def page(name, keys, jump=None, until='RN_JUMP: done@15', keep=True, secs=600):
    q = '&'.join(x for x in (f'jump={jump}' if jump else '', 'env=RN_FINISH=1,RN_AUTOPILOT=1,RN_FLOWLOG=1',
                              'keys=' + urllib.parse.quote(keys)) if x)
    env = dict(os.environ, RN_UNTIL=until, **({'RN_KEEP_SAVE': '1'} if keep else {}))
    subprocess.run([GATE], check=True)
    with open(f'{R}/build/savegate_{name}.out', 'w') as f:
        subprocess.run(['node', 'tools/webcheck.mjs', f'http://127.0.0.1:5180/?{q}', str(secs), f'build/savegate_{name}.png'],
                       cwd=R, env=env, stdout=f, stderr=subprocess.STDOUT)
    shutil.copy(f'{R}/build/webcheck.log', f'{R}/build/savegate_{name}.log')
    st = re.findall(r'flow career (\d+) status (\w+)', open(f'{R}/build/savegate_{name}.log', errors='replace').read())
    st = [s for s in st if s[0] != '0']   # before the profile load
    print(f'{name}: career status {" -> ".join("/".join(s) for s in st) or "none"}')
    return st

def main():
    a = page('a', *completion.cjump('cjump_3')[:2], keep=False)
    b = page('b', *completion.cjump('cjump_4')[:2])
    to_map = completion.cjump('cjump_0')[0].split(',')[:-len(completion._LEAVE) - 4] + ['4000@=MU_UG_MapScreen:RIGHT']
    c = page('c', ','.join(to_map), until=r'flow fe .*MU_UG_MapScreen@5', secs=240)
    ok = bool(a and b and c) and b[0] == a[-1] and b[-1] != b[0] and c[0] == b[-1]
    print('SAVEGATE', 'PASS' if ok else 'FAIL', f'A saved {a[-1:]}, B loaded {b[:1]} and saved {b[-1:]}, C loaded {c[:1]}')
    sys.exit(0 if ok else 1)

main()
