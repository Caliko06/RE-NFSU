#!/usr/bin/env python3
"""Address neighbours (docs/re/canon_db.md): the linker keeps one object file's functions together, so a function whose
previous and next lifted functions have the same solid system (named, med/high, systems_tu.tsv, systems_lib.tsv) takes
that system when it has none or only a low graph tag. Measured on solid functions: 5124/5362 (95.6 %). The low graph
tag alone is right 1273/3108 times, so it does not vote. One pass, no chaining. -> census/canon/systems_adj.tsv (med, I)
"""
import csv, os, sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import canon   # noqa: E402  (chdir to the repo root)

L = canon.lifted()
system, rows = canon.merged()
more = {}
for p in ("census/canon/systems_tu.tsv", "census/canon/systems_lib.tsv"):
    for r in csv.DictReader(open(p), delimiter="\t"):
        more.setdefault(canon.a(r["addr"]), r["system"])


def solid(x):
    r = rows.get(x)
    if r and r["system"]:
        return r["system"]
    s, c = system.get(x, ("unknown", "low"))
    return s if c in ("med", "high") and s not in ("unknown", "none") else more.get(x)


xs = sorted(L)
out = [(x, solid(p)) for p, x, n in zip(xs, xs[1:], xs[2:]) if not solid(x) and solid(p) and solid(p) == solid(n)]
with open("census/canon/systems_adj.tsv", "w") as o:
    o.write("addr\tsystem\tevidence\n")
    for x, s in out:
        o.write(f"{x:#x}\t{s}\tI: both address neighbours are {s}\n")
print(f"adjacent: {len(out)} tags")
