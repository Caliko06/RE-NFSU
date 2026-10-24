# Pod: watch the game RNG [0x6f227c] of the Wine reference through /proc/PID/mem (the exe is mapped at its image base).
# Prints each change: seconds, value, steps since the last value (same step as host/d3d9.c RN_RNGLOG; -1 = not within
# 100000). At the end: the TRACKS files the game holds open (which track a menu path loaded). usage: rngwatch.py SECS CMD...  (runs CMD, e.g. race.sh, and watches the Speed.exe it starts).
# The pod has kernel.yama.ptrace_scope = 1 and no CAP_SYS_PTRACE: only an ancestor may read the memory, so this script
# starts the game itself and is a child subreaper (the game, started with setsid nohup, stays its descendant).
import ctypes, os, struct, subprocess, sys, time
ctypes.CDLL(None).prctl(36, 1, 0, 0, 0)   # PR_SET_CHILD_SUBREAPER
cmd = subprocess.Popen(sys.argv[2:], stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)

def step(y):
    u = y ^ 0x1d872b41; v = u ^ (u >> 5)
    return (v ^ (v << 27) ^ u) & 0xffffffff

def pid():
    for p in os.listdir('/proc'):
        if p.isdigit():
            try:
                if open(f'/proc/{p}/comm').read().strip().lower() == 'speed.exe': return int(p)
            except OSError: pass

end = time.time() + float(sys.argv[1])
while not (p := pid()) and time.time() < end: time.sleep(0.05)
mem, t0, prev, total, files, i = open(f'/proc/{p}/mem', 'rb', 0), time.time(), None, 0, set(), 0
while time.time() < end:
    i += 1
    try:
        for fd in os.listdir(f'/proc/{p}/fd') if i % 500 == 0 else ():   # ~1 s
            files.add(os.readlink(f'/proc/{p}/fd/{fd}'))
    except OSError: pass
    try:
        mem.seek(0x6f227c); x = struct.unpack('<I', mem.read(4))[0]
    except (OSError, struct.error):   # the game ended
        break
    os.waitpid(-1, os.WNOHANG) if cmd.poll() is not None else None
    if x != prev:
        n, y = 0, prev
        while prev is not None and y != x and n < 100000: y = step(y); n += 1
        total += n
        print(f'{time.time() - t0:8.3f} {x:08x} {n if n < 100000 else -1} {total}', flush=True)
        prev = x
    time.sleep(0.002)
print('open:', ' '.join(sorted(os.path.basename(f) for f in files if '/TRACKS/' in f.upper())))
