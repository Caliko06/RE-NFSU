#!/usr/bin/env python3
"""web/entry_hint.tsv: what the entry into WORLD always reads, for the prefetch threads of host/files.c (RN_PREFETCH).
Source: network captures of a visit (rows with path, Range and start time, the format of tools/loadfast.mjs), kept as
census/entry_reads.tsv. A file is listed when every capture read it (the pool's cars change per visit: host/rivals.c
asks for those itself). Up to WHOLE_MAX (host/files.c) a file is one whole piece; a bigger one is the union of the ranges
read, in pieces of 4 MB. The music and ambience streams stay out (a different song each visit).
Phase b = before the first Global/InGameB.lzc (the race load starts there), w = after.
Usage: tools/entry_hint.py [capture.json ...]   (no arguments: rebuild from census/entry_reads.tsv)"""
import collections, json, os, sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
READS, OUT = os.path.join(ROOT, "census", "entry_reads.tsv"), os.path.join(ROOT, "web", "entry_hint.tsv")
WHOLE_MAX, PIECE = 8 << 20, 4 << 20

if sys.argv[1:]:
    with open(READS, "w") as f:
        f.write("run\tseconds\tpath\toffset\tlength\n")
        for run, name in enumerate(sys.argv[1:]):
            for r in sorted(json.load(open(name))["rows"], key=lambda r: r["start"]):
                if r.get("range") and "/SNDSTREAMS/" not in r["path"]:
                    a, b = map(int, r["range"].split("=")[1].split("-"))
                    f.write(f"{run}\t{r['start']:.2f}\t{r['path'].lstrip('/')}\t{a}\t{b - a + 1}\n")

rows = [l.rstrip("\n").split("\t") for l in open(READS)][1:]
runs = sorted({r[0] for r in rows})
seen = collections.defaultdict(set)
for r in rows:
    seen[r[2]].add(r[0])
first = [r for r in rows if r[0] == runs[0]]
race = next(float(r[1]) for r in first if r[2].endswith("Global/InGameB.lzc"))


def size(path):   # game/<p> = the game folder, world/<p> = build/openworld (tools/build_public.py)
    return os.path.getsize(os.path.join(ROOT, "build", "openworld", path[6:]) if path.startswith("world/") else os.path.join(ROOT, path))


out, done, total = [], set(), 0
for r in first:
    p = r[2]
    if p in done or seen[p] != set(runs):
        continue
    done.add(p)
    ph, n = "b" if float(r[1]) < race else "w", size(p)
    if n <= WHOLE_MAX:
        pieces = [(0, n)]
    else:
        spans = sorted({(int(x[3]), int(x[3]) + int(x[4])) for x in rows if x[2] == p})
        merged = []
        for a, b in spans:
            if merged and a <= merged[-1][1]:
                merged[-1][1] = max(merged[-1][1], b)
            else:
                merged.append([a, b])
        pieces = [(a + k, min(PIECE, b - a - k)) for a, b in merged for k in range(0, b - a, PIECE)]
    for a, n in pieces:
        out.append(f"{ph}\t{p}\t{a}\t{n}\n")
        total += n
open(OUT, "w").writelines(out)
print(f"{OUT}: {len(out)} pieces of {len(done)} files, {total / 1e6:.1f} MB ({sum(1 for l in out if l[0] == 'b')} before the race load); {len(runs)} captures")
