# A/B of every quick-race track against the Wine reference (HANDOFF M2). Per track, at the same time: the original under
# Wine on the old pod GPU (tools/wine/race.sh, watched by rngwatch.py) and ours in headless Chrome on this Mac (webcheck
# RN_REC). Same menu keys, same seed (RN_SEED / mkexe.py --set parity --seed), same 1280x960. The car stays on the grid:
# the intro and the start are the frames both sides can show alike. Metrics on the pod GPU (tools/abmetrics.py); only the
# CSV and the worst-frames PNG come back to build/ab/. Videos are deleted on both sides as each track ends.
# usage: abrun.py [FIRST [LAST]]   (indexes into TRACKS)
import os, subprocess, sys, threading
POD = ['ssh', '-i', os.path.expanduser('~/.ssh/id_ed25519'), '-p', '24439', 'root@213.173.108.175']
SCP = ['scp', '-q', '-i', os.path.expanduser('~/.ssh/id_ed25519'), '-P', '24439']
SEED, REC, GAP = '0x1234', 45, 3
OUT = 'build/ab'
TMP = os.environ.get('AB_TMP', '/tmp/rn-ab')
# (QUICK RACE MODE row, SELECT LOCATION index): Circuit, Sprint, Drag, Drift (Lap Knockout = the circuit tracks), Free Run.
TRACKS = [(0, j) for j in range(8)] + [(1, j) for j in range(8)] + [(2, j) for j in range(6)] + [(3, j) for j in range(8)] + [(5, 0)]

def keys(mode, loc):   # title, profile, (main menu), Quick Race, mode, car, transmission, location, Accept
    return ['Enter', 'Enter', 'Right', 'Enter'] + ['Down'] * mode + ['Enter', 'Enter', 'Enter'] + ['Right'] * loc + ['Enter', 'Enter']

def run(k):
    mode, loc = TRACKS[k]
    name = f'{k:02d}_m{mode}_l{loc}'
    ks = keys(mode, loc)
    wine = ' '.join({'Enter': 'Return'}.get(x, x) for x in ks)
    sv = '/root/wine/pfx/drive_c/ProgramData/NFS Underground'
    w = subprocess.Popen(POD + [f'cd /root/wine && rm -rf "{sv}" && cp -r /root/ab/save0 "{sv}" && nice -n 5 python3 rngwatch.py 240 '
                                f'./race.sh /root/ab/{name}_wine.mp4 {REC} {wine} > /root/ab/{name}.rng 2>&1'])
    last = 20 + GAP * (len(ks) - 1)
    ours = ','.join(f'{20 + GAP * i}:{"Arrow" + x if x in ("Right", "Down") else x}' for i, x in enumerate(ks))
    rec = f'{TMP}/{name}'
    subprocess.run(['rm', '-rf', rec])
    env = dict(os.environ, RN_CDP_PORT='9341', RN_VIEW='1280x960@1', RN_REC=rec, RN_REC_AT=str(last - 1))
    with open(f'{OUT}/{name}.log', 'w') as log:
        subprocess.run(['node', 'tools/webcheck.mjs', f'http://127.0.0.1:5180/?env=RN_SEED={SEED}', str(last + REC + 2),
                        f'{OUT}/{name}.png', ours], env=env, stdout=log, stderr=subprocess.STDOUT)
    subprocess.run(['bash', 'tools/recvideo.sh', rec, f'{TMP}/{name}_ours.mp4'], cwd='.', check=True)
    subprocess.run(['rm', '-rf', rec])
    w.wait()
    subprocess.run(SCP + [f'{TMP}/{name}_ours.mp4', f'root@213.173.108.175:/root/ab/'], check=True)
    os.remove(f'{TMP}/{name}_ours.mp4')
    return name

def metrics(name):
    r = subprocess.run(POD + [f'cd /root/ab && OMP_NUM_THREADS=4 nice -n 10 /root/remaster/venv/bin/python abmetrics.py {name}_wine.mp4 {name}_ours.mp4 {name} '
                              f'2>/dev/null | tail -1; tail -1 {name}.rng; rm -f {name}_wine.mp4 {name}_ours.mp4'], capture_output=True, text=True)
    subprocess.run(SCP + [f'root@213.173.108.175:/root/ab/{name}.csv', f'root@213.173.108.175:/root/ab/{name}.png',
                          f'root@213.173.108.175:/root/ab/{name}.rng', f'{OUT}/'])
    with open(f'{OUT}/summary.txt', 'a') as f: f.write(r.stdout)
    print(r.stdout, end='', flush=True)

os.makedirs(OUT, exist_ok=True); os.makedirs(TMP, exist_ok=True)
first = int(sys.argv[1]) if len(sys.argv) > 1 else 0
last = int(sys.argv[2]) if len(sys.argv) > 2 else len(TRACKS) - 1
prev = None
for k in range(first, last + 1):
    name = run(k)
    if prev: prev.join()
    prev = threading.Thread(target=metrics, args=(name,)); prev.start()
if prev: prev.join()
