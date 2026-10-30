#!/usr/bin/env python3
"""Code with no GameCube source file (docs/re/canon_db.md "Libraries"): the PC d3d9 renderer, the EA sound library,
DirtySock (online), the MSVC CRT.

These regions have no GameCube source file (the GC build linked other libraries), so tu_systems.py cannot place them.
1. CRT names: Ghidra Function ID (vsOlder_x86) names in the CRT region that our ledgers lack -> census/names_lib.tsv (I).
2. Region closure: inside one region, an untagged function takes the system that >= 70 % (and >= 2) of its call-graph
   neighbours inside the same region have, repeated until nothing changes. Seeds: named or med/high functions, plus
   DirtySock seeds (they reference its strings or call WS2_32/TAPI32). -> census/canon/systems_lib.tsv (med, I).
   --check: the same closure with every known function hidden in turn (leave-one-out), to measure it.
"""
import csv, json, os, sys
from collections import Counter

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import canon   # noqa: E402  (chdir to the repo root)

REGIONS = [(0x5a0000, 0x640000, "PC renderer (d3d9, no GameCube counterpart)"),
           (0x640000, 0x662800, "EA sound library (Csis, SND*, AEMS)"),
           (0x662800, 0x670800, "DirtySock / ProtoSSL (comm/datamodem, 'ru paranoid?')"),
           (0x670800, 0x684000, "MSVC 7.x CRT (FID matches from 0x670c91)")]
MIN1 = "--strict" not in sys.argv   # also accept one neighbour when all agree (leave-one-out 182/189 vs 129/130 strict)
L = canon.lifted()
system, rows = canon.merged()
rows = {x: r for x, r in rows.items() if r["tool"] != "ghidra-fid"}   # our own last run
F = {int(j["addr"], 16): j for j in map(json.loads, open("census/canon/funcs.jsonl"))}


def region(x):
    return next((r for r in REGIONS if r[0] <= x < r[1]), None)


def solid(x):
    r = rows.get(x)
    if r and r["system"]:
        return r["system"]
    s, c = system.get(x, ("unknown", "low"))
    return s if c in ("med", "high") and s not in ("unknown", "none") else None


def code_callers_(x):
    return [c for c in F.get(x, {}).get("callers", []) if not c.startswith("d")]


def nbrs(x):
    j = F.get(x, {})
    out = [canon.a(c) for c in j.get("callers", []) + j.get("callees", []) if not c.startswith("d")]
    return [y for y in out if region(y) == region(x) and y != x]


DS_STR = ("comm/", "localhost", "ru paranoid", "connecting to", "TAPI", "GmUtil", "TCP:", "server ICMP")
WS = {x for x, r in rows.items() if r["name"].startswith("imp_") and r["system"] == "online"}


def closure(seed):
    tag = dict(seed)
    changed = True
    while changed:
        changed = False
        for x in sorted(L):
            if x in tag or not region(x):
                continue
            v = Counter(tag[y] for y in nbrs(x) if y in tag)
            if v:
                s, k = v.most_common(1)[0]
                if (k >= 2 and k * 10 >= 7 * sum(v.values())) or (k == sum(v.values()) >= 1 and MIN1):
                    tag[x] = s
                    changed = True
    return tag


seed = {x: solid(x) for x in L if region(x) and solid(x)}
import pefile   # noqa: E402
img = pefile.PE("pc/Speed.exe", fast_load=True).get_memory_mapped_image()
def cstr(a):
    return img[a - 0x400000:a - 0x400000 + 40].split(b"\0")[0].decode("latin1")
for x in L:
    if region(x) and region(x)[0] == 0x662800 and x not in seed:
        j = F.get(x, {})
        if any(cstr(canon.a(s)).startswith(DS_STR) for s in j.get("strings", [])) or WS & {canon.a(c) for c in j.get("callees", [])}:
            seed[x] = "online"

if "--check" in sys.argv:
    known = [x for x in seed if solid(x)]
    ok = bad = 0
    for i, x in enumerate(known):
        if i % 3:
            continue   # every third known function, to keep it fast
        s = {y: t for y, t in seed.items() if y != x}
        v = Counter(s[y] for y in nbrs(x) if y in s)
        if v:
            t, k = v.most_common(1)[0]
            if (k >= 2 and k * 10 >= 7 * sum(v.values())) or (k == sum(v.values()) >= 1 and MIN1):
                ok += t == seed[x]
                bad += t != seed[x]
    print(f"libs --check: one-step leave-one-out {ok}/{ok + bad} agree")
    sys.exit()

tag = closure(seed)
new = {x: s for x, s in tag.items() if not solid(x)}
with open("census/canon/systems_lib.tsv", "w") as o:
    o.write("addr\tsystem\tevidence\n")
    for x in sorted(new):
        why = "seed: DirtySock string or WS2/TAPI import" if x in seed else "region closure over call-graph neighbours"
        o.write(f"{x:#x}\t{new[x]}\tI: {region(x)[2]}; {why}\n")
fid = []
for x in sorted(L):
    j = F.get(x)
    if j and region(x) and region(x)[0] == 0x670800 and x not in rows and not j["name"].startswith(("FUN_", "FID_conflict", "thunk_")):
        fid.append((x, j["name"]))
with open("census/names_lib.tsv", "w") as o:
    o.write("# Made by tools/canon/libs.py: Ghidra Function ID (vsOlder_x86) names in the MSVC CRT region.\n")
    o.write("addr\tname\tsystem\tconfidence\tevidence\ttool\tdoc\n")
    for x, n in fid:
        o.write(f"{x:#x}\t{n}\truntime\tI\tI: Ghidra FID single match in the CRT region 0x670800-0x684000\tghidra-fid\tdocs/re/canon_db.md\n")
left = sum(1 for x in L if region(x) and x not in tag)
print(f"libs: {len(new)} region tags {dict(Counter(new.values()))}; {len(fid)} CRT FID names; {left} region functions stay untagged")
if "-v" in sys.argv:
    for r in REGIONS:
        xs = [x for x in L if r[0] <= x < r[1]]
        un = [x for x in xs if x not in tag]
        out = Counter(solid(canon.a(c)) or "untagged" for x in un for c in F.get(x, {}).get("callers", []) if not c.startswith("d") and not region(canon.a(c)))
        print(f"{r[2][:30]:30s} {len(xs)} funcs, tagged {len(xs) - len(un)}, untagged {len(un)}; outside callers of untagged {dict(out.most_common(6))}; no callers {sum(1 for x in un if not code_callers_(x))}")
