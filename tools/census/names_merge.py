#!/usr/bin/env python3
"""Merge census/names_<system>.tsv into census/names.tsv (or argv[1]) (addr, name, system, confidence V/I/U, tool, doc, from, aliases).
One row per address; on a clash the verified (V) row wins, then the first file; the other names stay in `aliases`
(name@file, " | " separated) so a V/V clash loses nothing. Rows whose addr is not hex (struct fields) are counted, not merged. names_seed.tsv has
doc mentions, not names, so it stays separate.
confidence is the evidence state from tools/census/evstate.py (explicit V/I/U, then the evidence prefix; `high` alone is
a legacy V and is counted apart). kind: func = Hopper start; fragment = lifter start inside a named parent function
(census/canon/fragments.tsv, parent column); nonhopper = neither (not proven to be data)."""
import csv, glob, os, sys
from evstate import state
funcs = {int(l.split("\t")[0], 16) for l in list(open("census/hopper/funcs.tsv"))[1:]}   # Hopper function starts
frag = {}   # lifter-only start -> parent function start (census/canon/fragments.tsv; '?' parents are not fragments)
if os.path.exists("census/canon/fragments.tsv"):
    for l in list(open("census/canon/fragments.tsv"))[1:]:
        f = l.rstrip("\n").split("\t")
        if len(f) >= 2 and f[1] != "?": frag[int(f[0], 16)] = f[1]
best, alias, skipped, legacy = {}, {}, 0, set()
for p in sorted(glob.glob("census/names_*.tsv")):
    if p.endswith("names_seed.tsv"): continue
    for r in csv.DictReader((l for l in open(p) if not l.startswith("#")), delimiter="\t"):
        if not r.get("name") or not r.get("addr"): continue
        try: a = int(r["addr"].replace("0x", ""), 16)
        except ValueError:
            skipped += 1; continue
        st, leg = state(r)
        row = [f"0x{a:06x}", r["name"], r.get("system", ""), st, r.get("tool", ""), r.get("doc", ""), p.split("names_")[1][:-4]]
        alias.setdefault(a, []).append((r["name"], row[6]))
        old = best.get(a)
        if not old or (("VIU".index(row[3]), leg) < ("VIU".index(old[3]), a in legacy)):   # a real V beats a legacy one
            best[a] = row; legacy.discard(a)
            if leg: legacy.add(a)
with open(sys.argv[1] if len(sys.argv) > 1 else "census/names.tsv", "w") as f:   # optional output path (tests)
    f.write("addr\tname\tsystem\tconfidence\ttool\tdoc\tfrom\taliases\tkind\tparent\n")
    for a in sorted(best):
        al = " | ".join(f"{n}@{w}" for n, w in alias[a] if n != best[a][1])
        f.write("\t".join(best[a] + [al, "func" if a in funcs else "fragment" if a in frag else "nonhopper", frag.get(a, "") if a not in funcs else ""]) + "\n")
from collections import Counter
print(len(best), "addresses;", dict(Counter(r[3] for r in best.values())), "; with aliases:", sum(1 for a in best if any(n != best[a][1] for n, _ in alias[a])), "; legacy high-as-V (no explicit state):", len(legacy), "; non-hex rows skipped:", skipped)
