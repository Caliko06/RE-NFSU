# Headed-race frame report: reads a finished bench run (webcheck log + telemetry NDJSON) and prints the
# race frame stats and the gate. It never opens a browser, so a run made by hand can be read later.
# usage: bench_headed.py report NDJSON LOG [--warm 10] [--secs 180]
#        bench_headed.py url PORT [--stop 300]   (race 1103, autopilot, same key profile as tools/bench.py)
import json, re, sys
from completion import _PROFILE

HUD = 'd3d9 race HUD'


def args(argv):
    # small option reader: first two words are the command and its file arguments
    opts = {'warm': 10.0, 'secs': 180.0, 'stop': 300.0}
    pos = []
    i = 0
    while i < len(argv):
        a = argv[i]
        if a in ('--warm', '--secs', '--stop'):
            opts[a[2:]] = float(argv[i + 1])
            i += 2
        else:
            pos.append(a)
            i += 1
    return pos, opts


def start_time(log_path, warm):
    # race start = T of the first race HUD line, plus the warm-up time
    with open(log_path, errors='replace') as f:
        for line in f:
            if HUD in line:
                head = line.split(None, 1)[0] if line.split() else ''
                try:
                    return float(head) + warm
                except ValueError:
                    continue
    return None


def telemetry(ndjson_path):
    # collect the column names, all rows and the vsync events from the JSON lines
    cols, rows, vsync = None, [], []
    with open(ndjson_path, errors='replace') as f:
        for line in f:
            try:
                o = json.loads(line)
            except ValueError:
                continue
            if not isinstance(o, dict):
                continue
            if o.get('kind') == 'session':
                cols = list(o.get('cols') or [])
            elif o.get('kind') == 'vsync':
                vsync.append(o)
            if 'rows' in o and cols:
                rows += o['rows']
    return cols, rows, vsync


def report(ndjson_path, log_path, warm, secs):
    start = start_time(log_path, warm)
    if start is None:
        print(f'no "{HUD}" line in {log_path}')
        return 1
    end = start + secs
    cols, rows, vsync = telemetry(ndjson_path)
    if not cols:
        print(f'no session line with cols in {ndjson_path}')
        return 1
    c = {name: i for i, name in enumerate(cols)}
    ts = [r[c['t']] / 1000 for r in rows if r[c['present']]]   # presented frames, in seconds

    dts, paused = [], []
    for a, b in zip(ts, ts[1:]):
        if a < start or a >= end:
            continue
        dt = (b - a) * 1000
        if dt > 1000:
            paused.append((b, dt))
        else:
            dts.append(dt)

    print(f'{ndjson_path}: race window {start:.2f}..{end:.2f} s')
    for t, dt in paused:
        print(f'  paused (window hidden?) at {t:7.2f} s, gap {dt:.0f} ms')
    if not dts:
        print('frames 0: nothing measured')
        return 1

    dts.sort()
    n = len(dts)
    p50 = dts[n // 2]
    p99 = dts[min(n - 1, int(n * .99))]
    slow20 = sum(d > 20 for d in dts)
    slow33 = sum(d > 33.4 for d in dts)
    fps = 1000 * n / sum(dts)
    ok = p99 <= 20 and slow33 == 0
    print(f'frames {n}: p50 {p50:.1f}  p99 {p99:.1f}  max {dts[-1]:.0f} ms   '
          f'>20 ms {slow20}   >33.4 ms {slow33}   {fps:.1f} fps')
    print(f'{"PASS" if ok else "FAIL"}')

    win = [v for v in vsync if (v.get('t', 0) / 1000) >= start and (v.get('t', 0) / 1000) < end]
    rep = sum(v.get('rep', 0) for v in win)
    drop = sum(v.get('drop', 0) for v in win)
    top = max((v.get('maxMs', 0) for v in win), default=0)
    print(f'vsync {len(win)} events: rep {rep}  drop {drop}  maxMs {top:.1f}')
    causes(rows, c, start, end)
    sites(log_path, start, end)
    return 0


def causes(rows, c, start, end):
    # each frame > 20 ms by the bucket that took most of it (telemetry rows between two presents): page = waiting for the
    # page/GPU (gpuWait), gil = waiting for another guest thread, read = file reads, wait = the game's own busy wait (many
    # clock reads), work = the game's code (few clock reads)
    seg, last, n = [], None, {}
    for r in rows:
        seg.append(r)
        if not r[c['present']]:
            continue
        t = r[c['t']]
        if last is not None and start <= last / 1000 < end and 20 < t - last <= 1000:
            dt = t - last
            S = lambda k: sum(x[c[k]] for x in seg if x[c[k]] < 1e9) if k in c else 0
            b = {'page': S('gpuWait'), 'gil': S('gilMain'), 'read': S('read')}
            b['wait' if S('clockCalls') > 1000 else 'work'] = dt - sum(b.values())
            k = max(b, key=b.get)
            x = n.setdefault(k, [0, 0]); x[0] += 1; x[1] += dt > 33.4
        last, seg = t, []
    print('frames > 20 ms by cause (count, of them > 33.4 ms):', '  '.join(f'{k} {v[0]} ({v[1]})' for k, v in sorted(n.items(), key=lambda kv: -kv[1][0])))


def sites(log_path, start, end):
    # 'spike:' lines (host/d3d9.c, frames > 25 ms): the top clock-read call site names the loop the frame ran
    n = {}
    for line in open(log_path, errors='replace'):
        m = re.match(r'([\d.]+) spike: frame \d+ ([\d.]+) ms, clock \d+: (0x[0-9a-f]+)?.*reads (\d+)', line)
        if not m or not start <= float(m.group(1)) < end:
            continue
        k = 'reads' if int(m.group(4)) else (m.group(3) or 'none')
        x = n.setdefault(k, [0, 0]); x[0] += 1; x[1] += float(m.group(2)) > 33.4
    print('spike lines by top clock site (count, of them > 33.4 ms):', '  '.join(f'{k} {v[0]} ({v[1]})' for k, v in sorted(n.items(), key=lambda kv: -kv[1][0])[:8]))


def url(port, stop=300):
    # race 1103 from the menu: the jump env and the key profile mirror tools/bench.py. stopafter: the page leaves for
    # about:blank after that many seconds (web/telemetry.js), so a headed tab does not keep the game running.
    nav = ','.join(['20000:RETURN'] + _PROFILE[1:] + ['1500@=MU_Main_PC:RETURN'])
    print(f'http://127.0.0.1:{port}/?mute=1&stopafter={stop:.0f}&env=RN_SEED=0x1234,RN_AUTOPILOT=1,RN_FLOWLOG=1'
          f'&jump=0:1103&keys={nav}')
    return 0


if __name__ == '__main__':
    pos, opts = args(sys.argv[1:])
    if not pos:
        print(__doc__ or 'usage: bench_headed.py report NDJSON LOG [--warm 10] [--secs 180] | url PORT')
        sys.exit(2)
    if pos[0] == 'report' and len(pos) >= 3:
        sys.exit(report(pos[1], pos[2], opts['warm'], opts['secs']))
    if pos[0] == 'url' and len(pos) >= 2:
        sys.exit(url(pos[1], opts['stop']))
    print('usage: bench_headed.py report NDJSON LOG [--warm 10] [--secs 180] | url PORT')
    sys.exit(2)
