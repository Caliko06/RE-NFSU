#!/usr/bin/env python3
"""Names from vtable slots (docs/re/canon_db.md). An inherited method keeps the same function pointer at the same slot in
every derived vtable; vtables linked that way form a family. In a family, slot k has one method name M (from any named
function there); the function at slot k of a vtable whose class is C is C::M.

  vtables.py [--check]   -> census/canon/prior_vt.tsv (addr, name, vtable, slot, evidence)
--check: run on named functions only and report how often the proposal equals the existing name.
"""
import json, os, sys
from collections import Counter, defaultdict

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import canon   # noqa: E402  (chdir to the repo root)

V = [json.loads(l) for l in open("census/canon/data.jsonl") if '"vtable"' in l]
V = [(int(v["addr"], 16), [int(s, 16) for s in v["slots"].split(",")]) for v in V]
_, rows = canon.merged()
name = {x: r["name"] for x, r in rows.items()}

# families: union vtables sharing a function at the same slot
par = list(range(len(V)))
def find(i):
    while par[i] != i:
        par[i] = par[par[i]]
        i = par[i]
    return i
size = {int(j["addr"], 16): j["size"] for j in map(json.loads, open("census/canon/funcs.jsonl"))}
use0 = Counter(f for _, slots in V for f in set(slots))
seen = {}
for i, (_, slots) in enumerate(V):
    for k, f in enumerate(slots):
        if size.get(f, 0) <= 16 or use0[f] > 12:
            continue   # folded stubs (return 0, empty) are shared by unrelated classes: they do not link families
        if (k, f) in seen:
            par[find(i)] = find(seen[k, f])
        else:
            seen[k, f] = i
use = Counter(f for _, slots in V for f in set(slots))   # functions shared by several vtables are inherited


def cls_of(i):
    """Class of vtable i: the class of its own (not shared) named slots, if they agree."""
    c = Counter(name[f].rsplit("::", 1)[0] for f in V[i][1] if use[f] == 1 and "::" in name.get(f, ""))
    if not c:
        return None
    top, n = c.most_common(1)[0]
    return top if n / sum(c.values()) >= 0.75 else None


def method_at(fam, k, skip):
    m = Counter(name[f].rsplit("::", 1)[1] for j in fam for f in V[j][1][k:k + 1]
                if f != skip and "::" in name.get(f, ""))
    if not m:
        return None, 0
    top, n = m.most_common(1)[0]
    return (top, n) if n / sum(m.values()) >= 0.75 else (None, 0)


fams = defaultdict(list)
for i in range(len(V)):
    fams[find(i)].append(i)
check = "--check" in sys.argv
out, agree, total = {}, 0, 0
for i, (va, slots) in enumerate(V):
    c = cls_of(i)
    if not c:
        continue
    fam = fams[find(i)]
    for k, f in enumerate(slots):
        if use[f] != 1:
            continue   # inherited: belongs to the base class, named there
        m, n = method_at(fam, k, f)
        if not m:
            continue
        prop = f"{c}::{m}"
        if check and f in name:
            total += 1
            agree += name[f] == prop
        elif not check and f not in name and f not in out:
            out[f] = (prop, va, k, f"vtable {va:#x} slot {k}: class {c} (own named slots), method {m} ({n} named in family)")
if check:
    print(f"vtables --check: {agree}/{total} proposals equal the existing name")
else:
    with open("census/canon/prior_vt.tsv", "w") as o:
        o.write("addr\tname\tvtable\tslot\tevidence\n")
        for f in sorted(out):
            p, va, k, e = out[f]
            o.write(f"{f:#x}\t{p}\t{va:#x}\t{k}\t{e}\n")
    print(f"vtables: {len(V)} vtables, {len(fams)} families, {len(out)} proposals -> census/canon/prior_vt.tsv")
