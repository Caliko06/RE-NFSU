#!/usr/bin/env python3
"""Merge census/names_<system>.tsv into census/names.tsv (addr, name, system, confidence V/I/U, tool, doc, from).
One row per address; on a clash the verified (V) row wins, then the one with more evidence. names_seed.tsv has
doc mentions, not names, so it stays separate."""
import csv, glob
def conf(r):
    c = (r.get("confidence") or "").strip(); e = (r.get("evidence") or "").strip()
    if c in ("V", "I", "U"): return c
    if c == "high" or e.startswith("V"): return "V"
    if e.startswith("U"): return "U"
    return "I"
best = {}
for p in sorted(glob.glob("census/names_*.tsv")):
    if p.endswith("names_seed.tsv"): continue
    for r in csv.DictReader((l for l in open(p) if not l.startswith("#")), delimiter="\t"):
        if not r.get("name") or not r.get("addr"): continue
        try: a = int(r["addr"].replace("0x", ""), 16)
        except ValueError: continue
        row = [f"0x{a:06x}", r["name"], r.get("system", ""), conf(r), r.get("tool", ""), r.get("doc", ""), p.split("names_")[1][:-4]]
        old = best.get(a)
        if not old or ("VIU".index(row[3]) < "VIU".index(old[3])): best[a] = row
with open("census/names.tsv", "w") as f:
    f.write("addr\tname\tsystem\tconfidence\ttool\tdoc\tfrom\n")
    for a in sorted(best): f.write("\t".join(best[a]) + "\n")
from collections import Counter
print(len(best), "addresses;", dict(Counter(r[3] for r in best.values())))
