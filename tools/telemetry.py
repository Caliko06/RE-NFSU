#!/usr/bin/env python3
"""Reads a play session's telemetry (web/telemetry.js -> build/telemetry.ndjson) next to its log (build/web.log)
and prints where the time went: frame times, the worst frames with what happened in each, audio stream starvation,
the F8 marks, and a 10 s timeline.
Usage: .venv/bin/python tools/telemetry.py [telemetry.ndjson | nfsu-session-*.json] [web.log]   (defaults: the OWNER's last
session; a .json from F10 in the page carries its own log)
A frame's time is the page's time between two presents. In it: gpuWait = the game waiting for the page (the page or
the GPU is slow), gilMain = the main thread waiting for another guest thread, read = file reads from the server,
idle = the main thread in Sleep or a wait (its own frame pacing), game = the rest (the game's translated code).
holdMain/holdOther = the longest time one thread kept the GIL: no other guest thread (the music streamer) ran then.
"""
import bisect, json, os, sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
tel = sys.argv[1] if len(sys.argv) > 1 else os.path.join(ROOT, "build", "telemetry.ndjson")
logp = sys.argv[2] if len(sys.argv) > 2 else os.path.join(ROOT, "build", "web.log")

head, rows, events, inlog = None, [], [], None
if tel.endswith(".json"):                   # F10 download: one object with rows, events and the page log
    o = json.load(open(tel))
    head, rows, events, inlog = o, o["rows"], o["events"], o.get("log")
for line in ([] if inlog is not None else open(tel)):
    if not line.strip():
        continue
    try:
        o = json.loads(line)
    except ValueError:
        continue                        # a line cut by the page closing
    if "rows" in o:
        rows += o["rows"]
    elif o.get("kind") == "session":
        head = o
    else:
        events.append(o)
if not head or not rows:
    sys.exit(f"{tel}: no session header or no frames")
C = {c: i for i, c in enumerate(head["cols"])}
col = lambda r, c: r[C[c]]

# The log: "secs text" lines (index.html), for what happened around a frame.
log = []
if inlog is not None or os.path.exists(logp):
    for l in (inlog if inlog is not None else open(logp, errors="replace")):
        p = l.split(" ", 1)
        try:
            log.append((float(p[0]) * 1000, p[1].rstrip()))
        except (ValueError, IndexError):
            pass
log_t = [t for t, _ in log]
NOISE = ("key up", "gpu.js: frame", "ShaderValidator")


def near(t, before=1500, after=300, n=4):
    a, b = bisect.bisect_left(log_t, t - before), bisect.bisect_right(log_t, t + after)
    out = [f"{x / 1000:.2f} {s}" for x, s in log[a:b] if not any(k in s for k in NOISE)]
    return out[-n:]


# Frames: sum the rows between two presents (a big load hands the list over in parts).
frames, acc = [], None
SUM = ["run", "draws", "kwords", "texKb", "pipes", "shaders", "targets", "gpuWait", "gilMain", "gilOther", "read", "idleMain",
       "reads", "readKb", "starves", "underrun", "resyncs", "clockCalls", "handoffs", "gilGap"]
MAX = ["streamPm", "holdMain", "holdOther"]
last_t = None
for r in rows:
    if acc is None:
        acc = {k: 0 for k in SUM + MAX}
    for k in SUM:
        acc[k] += col(r, k)
    for k in MAX:
        acc[k] = max(acc[k], col(r, k))
    if col(r, "present"):
        t = col(r, "t")
        if last_t is not None:
            acc["t"], acc["dt"] = t, t - last_t
            acc["game"] = max(0, acc["dt"] - acc["gpuWait"] - acc["gilMain"] - acc["read"] - acc["idleMain"])
            acc["behind"] = col(r, "audioBehind")
            frames.append(acc)
        last_t, acc = t, None

if not frames:
    sys.exit("no presented frames")
dts = sorted(f["dt"] for f in frames)
pct = lambda p: dts[min(len(dts) - 1, int(p / 100 * len(dts)))]
span = (frames[-1]["t"] - frames[0]["t"]) / 1000
print(f"session {head['date']}  {head['screen']}  {head['url']}")
print(f"{len(frames)} frames in {span:.0f} s = {len(frames) / span:.1f} fps")
print(f"frame ms: p50 {pct(50)}  p90 {pct(90)}  p99 {pct(99)}  max {dts[-1]}   "
      f">33 ms: {sum(d > 33 for d in dts)}  >50: {sum(d > 50 for d in dts)}  >100: {sum(d > 100 for d in dts)}  >250: {sum(d > 250 for d in dts)}")
tot = {k: sum(f[k] for f in frames) for k in ("dt", "game", "gpuWait", "gilMain", "read", "idleMain", "run")}
print("where the time went: " + "  ".join(f"{k} {100 * tot[k] / tot['dt']:.0f}%" for k in ("game", "idleMain", "gpuWait", "gilMain", "read")) +
      f"   (page run {100 * tot['run'] / tot['dt']:.0f}% of the page thread)")
print(f"files: {sum(f['reads'] for f in frames)} reads, {sum(f['readKb'] for f in frames) / 1024:.0f} MB, "
      f"{tot['read'] / 1000:.1f} s   textures {sum(f['texKb'] for f in frames) / 1024:.0f} MB   "
      f"pipelines {sum(f['pipes'] for f in frames)}  shaders {sum(f['shaders'] for f in frames)}\n"
      f"clock calls per frame: {sum(f['clockCalls'] for f in frames) / len(frames):.0f} (hundreds = the game busy-waits; "
      f"then 'game' is mostly waiting, not work)")

print("\nworst frames (ms): dt = game + idle + gpuWait + gilMain + read; page run = the page building the frame")
hdr = (f"{'t s':>8} {'dt':>5} {'game':>5} {'idle':>5} {'gpuW':>5} {'gilM':>5} {'read':>5} {'hldM':>5} {'hldO':>5} {'run':>5} "
       f"{'rdKB':>6} {'texKB':>6} {'pipe':>4} {'shdr':>4} {'draw':>5}")
print(hdr)
for f in sorted(frames, key=lambda f: -f["dt"])[:15]:
    print(f"{f['t'] / 1000:8.2f} {f['dt']:5.0f} {f['game']:5.0f} {f['idleMain']:5.0f} {f['gpuWait']:5.0f} {f['gilMain']:5.0f} "
          f"{f['read']:5.0f} {f['holdMain']:5.0f} {f['holdOther']:5.0f} {f['run']:5.0f} {f['readKb']:6} {f['texKb']:6} "
          f"{f['pipes']:4} {f['shaders']:4} {f['draws']:5}")
    for s in near(f["t"], 1000, 100, 2):
        print(f"{'':10}| {s[:110]}")

starves = [f for f in frames if f["starves"]]
print(f"\naudio: {sum(f['starves'] for f in frames)} stream laps with no refill (stale audio repeats), "
      f"{sum(f['underrun'] for f in frames)} frames of silence (underrun), {sum(f['resyncs'] for f in frames)} resyncs")
for f in starves[:10]:
    w = [g for g in frames if f["t"] - 2000 <= g["t"] <= f["t"]]
    print(f"  {f['t'] / 1000:8.2f} s: in the 2 s before: worst frame {max(g['dt'] for g in w):.0f} ms, "
          f"longest GIL hold main {max(g['holdMain'] for g in w):.0f} ms / other {max(g['holdOther'] for g in w):.0f} ms, "
          f"read {sum(g['read'] for g in w):.0f} ms ({sum(g['readKb'] for g in w)} KB)")

loafs = [e for e in events if e["kind"] == "loaf"]
if loafs:
    print(f"\nbrowser long animation frames (>= 50 ms): {len(loafs)}; worst:")
    for e in sorted(loafs, key=lambda e: -e["dur"])[:5]:
        print(f"  {e['t'] / 1000:8.2f} s {e['dur']} ms (blocking {e['block']}) {'; '.join(e['scripts'])[:100]}")
other = [e for e in events if e["kind"] in ("mark", "visibility", "focus")]
if other:
    print("\nmarks (F8) and focus:")
    for e in other:
        line = f"  {e['t'] / 1000:8.2f} s {e['kind']} {e.get('n', e.get('state', ''))}"
        if e["kind"] == "mark":
            w = [g for g in frames if e["t"] - 3000 <= g["t"] <= e["t"]]
            if w:
                line += (f": 3 s before: {len(w) / 3:.0f} fps, worst {max(g['dt'] for g in w):.0f} ms, starves "
                         f"{sum(g['starves'] for g in w)}, read {sum(g['read'] for g in w):.0f} ms")
        print(line)

print("\ntimeline (10 s): fps, worst frame ms, game/idle/gpuWait/gilMain/read ms per frame, MB read, starves, longest main GIL hold")
t0 = frames[0]["t"]
for k in range(0, int(span) + 10, 10):
    w = [f for f in frames if t0 + k * 1000 <= f["t"] < t0 + (k + 10) * 1000]
    if not w:
        continue
    n = len(w)
    print(f"  {(t0 / 1000 + k):6.0f} s {n / 10:5.1f} fps  worst {max(f['dt'] for f in w):5.0f}  "
          f"{sum(f['game'] for f in w) / n:4.1f}/{sum(f['idleMain'] for f in w) / n:4.1f}/{sum(f['gpuWait'] for f in w) / n:4.1f}/"
          f"{sum(f['gilMain'] for f in w) / n:4.1f}/{sum(f['read'] for f in w) / n:4.1f}  {sum(f['readKb'] for f in w) / 1024:5.1f} MB  "
          f"{sum(f['starves'] for f in w)}  hold {max(f['holdMain'] for f in w):4.0f}  draws {sum(f['draws'] for f in w) // n}")
