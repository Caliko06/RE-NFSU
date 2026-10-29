#!/usr/bin/env python3
"""System of unknown functions from their GameCube source file (docs/re/canon_db.md).

Source file of a PC function: its census/canon/prior_gc.tsv row, or, when it sits between two aligned functions of
the same file, that file (link order). System of a file: majority of our med/high/named functions in it
(>= 4 votes, >= 70 %); GameCube-only files are skipped; else the same vote on its directory. Writes census/canon/systems_tu.tsv (addr, system, evidence),
which tools/census/scoreboard.py reads as confidence med (inferred, not read).
"""
import bisect, csv, os, sys
from collections import Counter, defaultdict

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import canon   # noqa: E402  (chdir to the repo root)

L = canon.lifted()
system, rows = canon.merged()


def sysof(x):
    r = rows.get(x)
    if r and r["system"]:
        return r["system"], "name"
    return system.get(x, ("unknown", "low"))


gc = {int(r["addr"], 16): r for r in csv.DictReader(open("census/canon/prior_gc.tsv"), delimiter="\t")}
ga = sorted(gc)
def portable(t):   # GameCube-only files (SDK, MSL, compiler temp units) hold different code on PC
    return t and "GameCube" not in t and not t.startswith("libc") and not t.endswith(".tmp")

tu = {x: gc[x]["tu"] for x in ga if portable(gc[x]["tu"])}
how = {x: "aligned " + gc[x]["grade"] for x in tu}
for x in sorted(L):
    if x in tu:
        continue
    i = bisect.bisect_left(ga, x)
    if 0 < i < len(ga) and portable(gc[ga[i]]["tu"]) and gc[ga[i - 1]]["tu"] == gc[ga[i]]["tu"]:
        tu[x], how[x] = gc[ga[i]]["tu"], f"between {ga[i - 1]:#x} and {ga[i]:#x}"

def d(t):
    return "/".join(t.split("/")[:5])

votes, dvotes = defaultdict(Counter), defaultdict(Counter)
for x, t in tu.items():
    s, c = sysof(x)
    if s not in ("unknown", "online") and c != "low":
        votes[t][s] += 1
        dvotes[d(t)][s] += 1

out, left = [], 0
for x in sorted(L):
    if sysof(x)[0] != "unknown":
        continue
    t = tu.get(x)
    for key, V, lvl in ((t, votes, "file"), (t and d(t), dvotes, "dir")):
        v = V.get(key) if key else None
        n = sum(v.values()) if v else 0
        if n >= 4:
            top, k = v.most_common(1)[0]
            if k / n >= 0.7:
                out.append((x, top, f"I: GC {lvl} {key} votes {top} {k}/{n}; {how[x]} (nfsug align)"))
                break
    else:
        left += 1
with open("census/canon/systems_tu.tsv", "w") as o:
    o.write("addr\tsystem\tevidence\n")
    for x, s, e in out:
        o.write(f"{x:#x}\t{s}\t{e}\n")
print(f"tu_systems: {len(out)} unknown functions get a system {dict(Counter(s for _, s, _ in out))}; {left} stay unknown")
