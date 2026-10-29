#!/usr/bin/env python3
"""Merge census/names_<system>.tsv into census/names.tsv (addr, name, system, confidence V/I/U, tool, doc, from, aliases).
One row per address; on a clash the verified (V) row wins, then the first file; the other names stay in `aliases`
(name@file, " | " separated) so a V/V clash loses nothing. Rows whose addr is not hex (struct fields) are counted, not merged. names_seed.tsv has
doc mentions, not names, so it stays separate."""
import csv, glob
funcs = {int(l.split("\t")[0], 16) for l in list(open("census/hopper/funcs.tsv"))[1:]}   # Hopper function starts
def conf(r):
    c = (r.get("confidence") or "").strip(); e = (r.get("evidence") or "").strip()
    if c in ("V", "I", "U"): return c
    if c == "high" or e.startswith("V"): return "V"
    if e.startswith("U"): return "U"
    return "I"
best, alias, skipped = {}, {}, 0
for p in sorted(glob.glob("census/names_*.tsv")):
    if p.endswith("names_seed.tsv"): continue
    for r in csv.DictReader((l for l in open(p) if not l.startswith("#")), delimiter="\t"):
        if not r.get("name") or not r.get("addr"): continue
        try: a = int(r["addr"].replace("0x", ""), 16)
        except ValueError:
            skipped += 1; continue
        row = [f"0x{a:06x}", r["name"], r.get("system", ""), conf(r), r.get("tool", ""), r.get("doc", ""), p.split("names_")[1][:-4]]
        alias.setdefault(a, []).append((r["name"], row[6]))
        old = best.get(a)
        if not old or ("VIU".index(row[3]) < "VIU".index(old[3])): best[a] = row
with open("census/names.tsv", "w") as f:
    f.write("addr\tname\tsystem\tconfidence\ttool\tdoc\tfrom\taliases\tkind\n")
    for a in sorted(best):
        al = " | ".join(f"{n}@{w}" for n, w in alias[a] if n != best[a][1])
        f.write("\t".join(best[a] + [al, "func" if a in funcs else "data"]) + "\n")
from collections import Counter
print(len(best), "addresses;", dict(Counter(r[3] for r in best.values())), "; with aliases:", sum(1 for a in best if any(n != best[a][1] for n, _ in alias[a])), "; non-hex rows skipped:", skipped)
