#!/usr/bin/env python3
"""Index of what the OWNER's downloaded sessions (F10, ~/Downloads/nfsu-session-*.json) already show. No game or Chrome run.
Check it before any test: run a test only when the fact is missing here. Reports per session (census/play_index.tsv),
then totals split by who drove (human, scripted) and which mode ran (original, remaster, unknown), and the human key timing.
Usage: python3 -I tools/playindex.py [dir]   (-I: the files are downloads, never load code next to them)
"""
import glob, json, os, re, sys
from collections import Counter

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
src = sys.argv[1] if len(sys.argv) > 1 else os.path.expanduser("~/Downloads")
SCRIPTED = re.compile(r"RN_AUTOPILOT|[?&]keys=|[?&]jump=")


def session(path):
    o = json.load(open(path))
    log, url = o.get("log") or [], o.get("url", "")
    text = "\n".join(log)
    if "st Wanted" in text:     # another game's page saved under this name
        return None
    cols, rows = o.get("cols", []), o.get("rows", [])
    col = lambda name: [r[cols.index(name)] for r in rows] if name in cols else []
    mode = re.search(r"mode: (\w+)", text)
    keys = [(float(m[1]), m[2], m[3]) for m in re.finditer(r"^([\d.]+) key (down|up) (\S+)", text, re.M)]
    return {
        "date": os.path.basename(path)[13:32],
        "driver": "scripted" if SCRIPTED.search(url) or "RN_JUMP:" in text or "CHEAT:" in text else "human",
        "mode": mode[1] if mode else "unknown",
        "world": "OPENWORLD:" in text or "rockport" in url,
        "normal_career": "career=normal" in url,
        "min": round((rows[-1][0] - rows[0][0]) / 60000, 1) if len(rows) > 1 else 0,
        "races": max(len(re.findall(r"race HUD", text)), len(re.findall(r"phase race \d+ begins", text))),   # a lower bound: older builds log the HUD once
        "finished": len(re.findall(r"phase race \d+ finished", text)),
        "flow": "flow fe " in text,
        "songs": len(re.findall(r"music song", text)),
        "stream_silent": len(re.findall(r"a whole lap with no Unlock", text)),
        "underrun": sum(col("underrun")),
        "starves": sum(col("starves")),
        "stops": re.findall(r"^[\d.]+ STOP in thread \w+ at (\w+): ([^\n(]+)", text, re.M),
        "keys": keys,
        "url": url,
    }


def human_timing(sessions):
    held = {}
    for s in sessions:
        down = {}
        for t, kind, code in s["keys"]:
            if kind == "down":
                down[code] = t
            elif code in down:
                held.setdefault(code, []).append(t - down.pop(code))
    for code, h in sorted(held.items(), key=lambda kv: -len(kv[1]))[:8]:
        h.sort()
        print(f"  {code:11} n {len(h):5}  p50 {h[len(h) // 2]:6.2f} s  p90 {h[int(len(h) * .9)]:6.2f} s")


files = [f for f in sorted(glob.glob(os.path.join(src, "nfsu-session-*.json"))) if " (" not in f]
sessions = [s for s in map(session, files) if s]
heads = ["date", "driver", "mode", "world", "normal_career", "min", "races", "finished", "flow", "songs", "stream_silent",
         "underrun", "starves", "stops", "url"]
with open(os.path.join(ROOT, "census", "play_index.tsv"), "w") as out:
    out.write("\t".join(heads) + "\n")
    for s in sessions:
        out.write("\t".join(str(s[h]) for h in heads) + "\n")

print(f"{len(sessions)} sessions -> census/play_index.tsv")
groups = Counter()
for s in sessions:
    groups[(s["driver"], s["mode"], "world" if s["world"] else "no-world")] += 1
for g, n in sorted(groups.items(), key=lambda kv: -kv[1]):
    group = [s for s in sessions if (s["driver"], s["mode"], "world" if s["world"] else "no-world") == g]
    print(f"{' / '.join(g):32} n {n:2}  min {sum(s['min'] for s in group):6.1f}  race HUD {sum(s['races'] for s in group):3}"
          f"  finished {sum(s['finished'] for s in group):2}  flow {sum(s['flow'] for s in group):2}  stops {sum(len(s['stops']) for s in group)}"
          f"  stream laps silent {sum(s['starves'] for s in group)}  underrun frames {sum(s['underrun'] for s in group)}")
print("stops:")
for s in sessions:
    for at, why in s["stops"]:
        print(f"  {s['date']} {s['driver']} {s['mode']} world={s['world']} {at}: {why.strip()}")
print("human key hold:")
human_timing([s for s in sessions if s["driver"] == "human"])
