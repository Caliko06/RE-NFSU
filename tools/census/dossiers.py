#!/usr/bin/env python3
"""Dossier for every unnamed function of pc/Speed.exe.

Unnamed = no census/names_*.tsv row with a name, and the export name starts with FUN_.
Inputs:  /root/re/named_export/decomp_*.c (headers `// <8 hex> <name>`), funcs_*.tsv (entry, name, bytes),
         census/names_*.tsv (names_seed.tsv skipped). Systems are read as tools/census/scoreboard.py reads them.
Output:  /root/re/dossiers/<addr8>.txt per unnamed function, and INDEX.tsv sorted by score (bottom-up first).
         score = named_callees + named_callers. guessed_system = most common system among named neighbours.
References come from the full decompile text: FUN_<addr> tokens, and identifiers equal to a named function's name.

Run: python3 tools/census/dossiers.py
"""
import csv, glob, os, re
from collections import Counter

REPO = os.path.abspath(os.path.join(os.path.dirname(os.path.abspath(__file__)), "..", ".."))
EXPORT = "/root/re/named_export"
OUT = "/root/re/dossiers"
MAX_LINES = 200

TOP = {"blur": "render", "fe": None, "other": None, "system": None}   # same as scoreboard.py


def top(s):
    s = (s or "").strip().split(".")[0]
    return TOP.get(s, s) or None


def a(s):
    return int(s.replace("0x", ""), 16)


# names: addr -> name, addr -> system (rows with confidence U do not set the system, as in scoreboard.py)
named, nsys = {}, {}
for p in sorted(glob.glob(os.path.join(REPO, "census", "names_*.tsv"))):
    if p.endswith("names_seed.tsv"):
        continue
    rows = csv.DictReader((l for l in open(p, encoding="utf-8", errors="replace") if not l.startswith("#")), delimiter="\t")
    for r in rows:
        try:
            x = a(r["addr"])
        except (ValueError, KeyError, TypeError):
            continue
        name = (r.get("name") or "").strip()
        if not name:
            continue
        named.setdefault(x, name)
        conf = (r.get("confidence") or r.get("V|I|U") or "").strip()
        t = top(r.get("system"))
        if t and conf != "U":
            nsys.setdefault(x, t)

# funcs: addr -> (export name, bytes)
funcs = {}
for p in sorted(glob.glob(os.path.join(EXPORT, "funcs_*.tsv"))):
    with open(p, encoding="utf-8", errors="replace") as fh:
        for r in csv.DictReader(fh, delimiter="\t"):
            x = a(r["entry"])
            size = int(r["bytes"]) if (r.get("bytes") or "").strip().isdigit() else 0
            funcs.setdefault(x, (r["name"], size))

# decompile text per function, one pass over the export files
HDR = re.compile(r"^// ([0-9a-f]{8}) (\S+)[ \t]*$", re.M)
text = {}
for p in sorted(glob.glob(os.path.join(EXPORT, "decomp_*.c"))):
    src = open(p, encoding="utf-8", errors="replace").read()
    hs = list(HDR.finditer(src))
    for i, m in enumerate(hs):
        end = hs[i + 1].start() if i + 1 < len(hs) else len(src)
        text[int(m.group(1), 16)] = src[m.end():end].strip("\n")

FUNREF = re.compile(r"\bFUN_([0-9a-f]{8})\b")
IDENT = re.compile(r"[A-Za-z_][A-Za-z0-9_]*(?:::[A-Za-z_][A-Za-z0-9_]*)*")
DAT = re.compile(r"\bDAT_([0-9a-f]{8})\b")
DAT_WRITE = re.compile(r"\bDAT_([0-9a-f]{8})\b(?:\[[^\]\n]*\])*\s*=(?!=)")
STR_LIT = re.compile(r'"((?:[^"\\\n]|\\.)*)"')
STR_LBL = re.compile(r"\b(?:PTR_)?s_([A-Za-z0-9_]+)_([0-9a-f]{8})\b")
HEXC = re.compile(r"\b0x([0-9a-fA-F]+)\b")

name_to_addr = {}
for x, n in named.items():
    name_to_addr.setdefault(n, x)

callees, callers = {}, {}
refs = {}   # addr -> (strings, consts, dat_reads, dat_writes)
for x in funcs:
    t = text.get(x, "")
    cs = set()
    for m in FUNREF.finditer(t):
        y = int(m.group(1), 16)
        if y != x:
            cs.add(y)
    for m in IDENT.finditer(t):
        y = name_to_addr.get(m.group(0))
        if y is not None and y != x:
            cs.add(y)
    callees[x] = cs
    for y in cs:
        callers.setdefault(y, set()).add(x)

    strs = [f'"{m.group(1)}"' for m in STR_LIT.finditer(t)]
    strs += [f"s_{m.group(1)} @ 0x{m.group(2)}" for m in STR_LBL.finditer(t)]
    consts = sorted({int(m.group(1), 16) for m in HEXC.finditer(t) if int(m.group(1), 16) > 0x1000})
    wr_starts = {m.start() for m in DAT_WRITE.finditer(t)}
    reads, writes = set(), set()
    for m in DAT.finditer(t):
        (writes if m.start() in wr_starts else reads).add(m.group(1))
    refs[x] = (strs, consts, sorted(reads), sorted(writes))


def label(y):
    return f"{named[y]} (FUN_{y:08x})" if y in named else f"FUN_{y:08x}"


unnamed = [x for x in funcs if x not in named and funcs[x][0].startswith("FUN_")]
os.makedirs(OUT, exist_ok=True)
index_rows = []
for x in unnamed:
    cs, ks = callees.get(x, set()), callers.get(x, set())
    named_cs = [y for y in cs if y in named]
    named_ks = [y for y in ks if y in named]
    neigh = Counter(nsys[y] for y in named_cs + named_ks if y in nsys)
    gsys = neigh.most_common(1)[0][0] if neigh else "unknown"
    score = len(named_cs) + len(named_ks)
    size = funcs[x][1]
    index_rows.append((x, size, len(ks), len(cs), len(named_cs), len(named_ks), gsys, score))

    strs, consts, dreads, dwrites = refs[x]
    body = text.get(x, "").splitlines()
    out = [
        f"address: 0x{x:08x}",
        f"name: {funcs[x][0]}",
        f"size: {size} bytes",
        f"guessed system: {gsys} (named neighbours with a system: {sum(neigh.values())})",
        "",
        f"callers ({len(ks)}):",
        *[f"  0x{y:08x}  {label(y)}" for y in sorted(ks)],
        "",
        f"callees ({len(cs)}):",
        *[f"  0x{y:08x}  {label(y)}" for y in sorted(cs)],
        "",
        f"string literals ({len(strs)}):",
        *[f"  {s}" for s in strs],
        "",
        f"hex constants above 0x1000 ({len(consts)}):",
        *[f"  0x{c:x}" for c in consts],
        "",
        f"globals DAT_ read ({len(dreads)}):",
        *[f"  DAT_{d}" for d in dreads],
        f"globals DAT_ written ({len(dwrites)}):",
        *[f"  DAT_{d}" for d in dwrites],
        "",
        f"--- decompile ({min(len(body), MAX_LINES)} of {len(body)} lines) ---",
        *body[:MAX_LINES],
        "",
    ]
    with open(os.path.join(OUT, f"{x:08x}.txt"), "w", encoding="utf-8") as fh:
        fh.write("\n".join(out))

index_rows.sort(key=lambda r: (-r[7], r[0]))
with open(os.path.join(OUT, "INDEX.tsv"), "w", encoding="utf-8") as fh:
    fh.write("addr\tsize\tn_callers\tn_callees\tnamed_callees\tnamed_callers\tguessed_system\tscore\n")
    for r in index_rows:
        fh.write(f"{r[0]:08x}\t" + "\t".join(str(v) for v in r[1:]) + "\n")

files = sum(1 for f in os.listdir(OUT) if f.endswith(".txt"))
print(f"rows: {len(index_rows)}  dossier files: {files}  named: {len(named)}  functions: {len(funcs)}")
for sysname, n in Counter(r[6] for r in index_rows).most_common():
    print(f"  {sysname}: {n}")
