#!/usr/bin/env python3
"""Per-system scoreboard: tagged / ran / named / diff-tested (docs/re/NIGHT_BRIEF.md).

  tagged  functions with a system tag of confidence med/high in census/systems.tsv, or with a name in names_*.tsv
          (the name's system overrides the graph tag: the external audit found 47% of named functions disagreed)
  ran     functions that were entered in the RN_COV scenarios (census/cov/union.json)
  named   functions with a row in census/names_*.tsv (named V = evidence state V, tools/census/evstate.py: an explicit
          V/I/U in confidence or the evidence prefix, never the word `high`; legacy `high` with no state is listed on stderr)
  fragments  lifted starts that are not Ghidra functions but lie inside a parent function (census/canon/fragments.tsv);
          they stay in `lifted` and `named` once; "frag/parent named" = unnamed fragments whose parent has a name
  difftested  census/difftest.json `compared_funcs` (written by tools/recomp/difftest.py since 2026-10-29). Older runs stored only the total (5,813), shown as U until difftest is re-run

Run: python3 tools/census/scoreboard.py [--md]   (--md prints the table for docs/re_scoreboard.md)
"""
import csv, glob, json, re, sys
sys.path.insert(0, __file__.rsplit('/', 1)[0])
from evstate import state
from collections import Counter, defaultdict

def a(s):
    return int(s.replace("0x", ""), 16)

lifted = set()   # every function the lifter emitted (same list as tools/census/systems.py)
for fn in glob.glob("build/gen/f*.c"):
    lifted.update(int(m, 16) for m in re.findall(r"^[a-z_0-9 ]+ f_([0-9a-f]{6})\(", open(fn, errors="replace").read(), re.M))

system, conf = {}, {}
TOP = {"blur": "render", "fe": None, "other": None, "system": None}   # names_*.tsv system -> systems.tsv system

def top(s):
    s = (s or "").strip().split(".")[0]
    return TOP.get(s, s) or None
for line in open("census/systems.tsv"):
    if line.startswith("#") or line.startswith("addr\t"):
        continue
    f = line.rstrip("\n").split("\t")
    if len(f) >= 3 and a(f[0]) not in system:
        system[a(f[0])], conf[a(f[0])] = f[1], f[2]

ran = {a(x) for x in json.load(open("census/cov/union.json"))["addrs"]}

named, named_v, legacy_v, explicit_v = set(), set(), set(), set()
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
        st, leg = state(r)
        if st == "V":
            named_v.add(x)
            (legacy_v if leg else explicit_v).add(x)

# hand-read reassignments (census/systems_override.tsv: addr, system, evidence) win over the graph; a name still wins over both
import os
if os.path.exists("census/systems_override.tsv"):
    for line in open("census/systems_override.tsv"):
        f = line.rstrip("\n").split("\t")
        if len(f) >= 2 and not line.startswith(("#", "addr")):
            try:
                x = a(f[0])
            except ValueError:
                continue
            if f[1] in ("render", "canon", "runtime", "audio", "rivals", "car", "track", "online", "hud", "camera", "traffic", "props", "assets", "input"):
                system[x], conf[x] = f[1], "high"

# unknown functions placed by their GameCube source file (tools/canon/tu_systems.py): inferred, so med
if os.path.exists("census/canon/systems_tu.tsv"):
    for r in csv.DictReader(open("census/canon/systems_tu.tsv"), delimiter="\t"):
        x = a(r["addr"])
        if system.get(x, "unknown") == "unknown" or (system[x] == r["system"] and conf.get(x) == "low"):   # or a low tag it confirms
            system[x], conf[x] = r["system"], "med"
# library regions with no GC source file, closed over the call graph (tools/canon/libs.py): inferred, so med
if os.path.exists("census/canon/systems_lib.tsv"):
    for r in csv.DictReader(open("census/canon/systems_lib.tsv"), delimiter="\t"):
        x = a(r["addr"])
        if conf.get(x) not in ("med", "high"):
            system[x], conf[x] = r["system"], "med"
# library bands read by their strings and callers (docs/re/render_pc.md: D3DX9 render, EAGL anim runtime assets): they
# replace a graph or region tag, since the region closure took 'render' for the whole 0x5a-0x64 range
if os.path.exists("census/canon/systems_band.tsv"):
    for r in csv.DictReader(open("census/canon/systems_band.tsv"), delimiter="\t"):
        x = a(r["addr"])
        if conf.get(x) != "high":
            system[x], conf[x] = r["system"], "med"
# both address neighbours agree (tools/canon/adjacent.py): inferred, so med
if os.path.exists("census/canon/systems_adj.tsv"):
    for r in csv.DictReader(open("census/canon/systems_adj.tsv"), delimiter="\t"):
        x = a(r["addr"])
        if conf.get(x) not in ("med", "high"):
            system[x], conf[x] = r["system"], "med"

# a name with a system (V or I) wins over the graph tag
nsys = {}
for p in sorted(glob.glob("census/names_*.tsv")):
    if p.endswith("names_seed.tsv"):
        continue
    for r in csv.DictReader((l for l in open(p) if not l.startswith("#")), delimiter="\t"):
        try:
            x = a(r["addr"])
        except (ValueError, KeyError, TypeError):
            continue
        t = top(r.get("system"))
        if t and r.get("name") and (r.get("confidence") or "").strip() != "U" and x not in nsys:
            nsys[x] = t
changed = 0
for x, t in nsys.items():
    if x in lifted and system.get(x) != t:
        changed += system.get(x, "none") not in ("unknown", "none")
        system[x], conf[x] = t, "high"
print(f"# {len(nsys)} named addresses with a system; {changed} replaced a different graph tag", file=sys.stderr)

print(f"# {len(named_v)} named V; {len(legacy_v - explicit_v)} of them only by legacy `high` (review candidates, not proven false)", file=sys.stderr)

frag = {}   # lifter-only start -> parent function start; '?' parents are not fragments
if os.path.exists("census/canon/fragments.tsv"):
    for line in list(open("census/canon/fragments.tsv"))[1:]:
        f = line.rstrip("\n").split("\t")
        if len(f) >= 2 and f[1] != "?":
            frag[a(f[0])] = a(f[1])

dt = json.load(open("census/difftest.json"))
dtest = {a(x) for x in dt["compared_funcs"]} - {a(x) for x in dt.get("mismatch_funcs", [])} if "compared_funcs" in dt else None

tot, tag, rn, nm, nv, dc, fr, fp = Counter(), Counter(), Counter(), Counter(), Counter(), Counter(), Counter(), Counter()
for f in lifted:
    s = system.get(f, "none")
    tot[s] += 1
    if s not in ("unknown", "none") and (conf.get(f) in ("med", "high") or f in named):
        tag[s] += 1
    rn[s] += f in ran
    nm[s] += f in named
    nv[s] += f in named_v
    if dtest is not None:
        dc[s] += f in dtest
    if f in frag:
        fr[s] += 1
        fp[s] += f not in named and frag[f] in named

order = sorted(tot, key=lambda s: -tot[s])
md = "--md" in sys.argv
hdr = ["system", "lifted", "tagged", "ran", "named", "named V", "diff-tested", "fragments", "frag/parent named"]
rows = [[s, tot[s], tag[s], rn[s], nm[s], nv[s], dc[s] if dtest is not None else "U", fr[s], fp[s]] for s in order]
rows.append(["TOTAL", sum(tot.values()), sum(tag.values()), sum(rn.values()), sum(nm.values()), sum(nv.values()), sum(dc.values()) if dtest is not None else "5813 (no split)", sum(fr.values()), sum(fp.values())])
if md:
    print("| " + " | ".join(hdr) + " |\n|" + "---|" * len(hdr))
    for r in rows:
        print("| " + " | ".join(str(x) for x in r) + " |")
else:
    print("\t".join(hdr))
    for r in rows:
        print("\t".join(str(x) for x in r))
