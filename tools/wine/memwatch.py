# Pod: the Wine side of RN_WATCH (host/main.c): every 250 ms, print the listed dwords of the Wine Speed.exe (mapped at
# its image base) through /proc/PID/mem, and a shot at each SHOTS second. usage: memwatch.py SECS ADDRS SHOTDIR CMD...
# (ADDRS = 70fe28,77a920). Starts CMD itself and is a child subreaper, as rngwatch.py (ptrace_scope = 1).
import ctypes, os, struct, subprocess, sys, time
ctypes.CDLL(None).prctl(36, 1, 0, 0, 0)   # PR_SET_CHILD_SUBREAPER
secs, addrs, shots = float(sys.argv[1]), [int(a, 16) for a in sys.argv[2].split(',')], sys.argv[3]
cmd = subprocess.Popen(sys.argv[4:], stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)

def pid():
    for p in os.listdir('/proc'):
        if p.isdigit():
            try:
                if open(f'/proc/{p}/comm').read().strip().lower() == 'speed.exe': return int(p)
            except OSError: pass

end = time.time() + secs
while not (p := pid()) and time.time() < end: time.sleep(0.05)
mem, t0, nshot = open(f'/proc/{p}/mem', 'rb', 0), time.time(), 0
while time.time() < end:
    try:
        vals = []
        for a in addrs: mem.seek(a); vals.append(struct.unpack('<I', mem.read(4))[0])
    except (OSError, struct.error): break
    t = time.time() - t0
    print(f'watch {t:6.2f} ' + ' '.join(f'{a:x}={v}' for a, v in zip(addrs, vals)), flush=True)
    if t >= 5 * (nshot + 1):
        nshot += 1; subprocess.run(['import', '-window', 'root', f'{shots}/{nshot * 5}.png'], env=os.environ)
    os.waitpid(-1, os.WNOHANG) if cmd.poll() is not None else None
    time.sleep(0.25)
