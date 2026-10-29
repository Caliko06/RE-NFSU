#!/usr/bin/env python3
"""Per-system scoreboard: tagged / ran / named / diff-tested (docs/re/NIGHT_BRIEF.md).

  tagged  functions with a system tag (census/systems.tsv, not 'unknown'/'none')
  ran     functions that were entered in the RN_COV scenarios (census/cov/union.json)
  named   functions with a row in census/names_*.tsv (V = verified with a second tool)
  difftested  census/difftest.json stores only a total (5,813 compared), not which functions: shown as U per system

Run: python3 tools/census/scoreboard.py [--md]   (--md prints the table for docs/re_scoreboard.md)
"""
import csv, glob, json, re, sys
from collections import Counter, defaultdict

def a(s):
    return int(s.replace("0x", ""), 16)

lifted = set()   # every function the lifter emitted (same list as tools/census/systems.py)
for fn in glob.glob("build/gen/f*.c"):
    lifted.update(int(m, 16) for m in re.findall(r"^[a-z_0-9 ]+ f_([0-9a-f]{6})\(", open(fn, errors="replace").read(), re.M))

system, conf = {}, {}
for line in open("census/systems.tsv"):
    if line.startswith("#") or line.startswith("addr\t"):
        continue
    f = line.rstrip("\n").split("\t")
    if len(f) >= 3 and a(f[0]) not in system:
        system[a(f[0])], conf[a(f[0])] = f[1], f[2]

ran = {a(x) for x in json.load(open("census/cov/union.json"))["addrs"]}

named, named_v = set(), set()
for p in glob.glob("census/names_*.tsv"):
    if p.endswith(("names_seed.tsv",)):
        continue
    rows = csv.DictReader((l for l in open(p) if not l.startswith("#")), delimiter="\t")
    for r in rows:
        if not r.get("name") or not r.get("addr"):
            continue
        try:
            x = a(r["addr"])
        except ValueError:
            continue
        named.add(x)
        c = (r.get("confidence") or "").strip()
        e = (r.get("evidence") or "").strip()
        if c in ("V", "high") or e.startswith("V"):
            named_v.add(x)

tot, tag, rn, nm, nv = Counter(), Counter(), Counter(), Counter(), Counter()
for f in lifted:
    s = system.get(f, "none")
    tot[s] += 1
    if s not in ("unknown", "none"):
        tag[s] += 1
    rn[s] += f in ran
    nm[s] += f in named
    nv[s] += f in named_v

order = sorted(tot, key=lambda s: -tot[s])
md = "--md" in sys.argv
hdr = ["system", "lifted", "tagged", "ran", "named", "named V", "diff-tested"]
rows = [[s, tot[s], tag[s], rn[s], nm[s], nv[s], "U"] for s in order]
rows.append(["TOTAL", sum(tot.values()), sum(tag.values()), sum(rn.values()), sum(nm.values()), sum(nv.values()), "5813 (no split)"])
if md:
    print("| " + " | ".join(hdr) + " |\n|" + "---|" * len(hdr))
    for r in rows:
        print("| " + " | ".join(str(x) for x in r) + " |")
else:
    print("\t".join(hdr))
    for r in rows:
        print("\t".join(str(x) for x in r))
