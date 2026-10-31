#!/usr/bin/env python3
"""census/strings_func.tsv: which string literal of Speed.exe occurs in which function.

  python3 tools/census/strings_index.py > census/strings_func.tsv

One row per (function, literal): addr, name, literal, count. Sources are the decompiler exports
(census/hopper/decomp.c plus any --extra file, default census/ghidra/decomp_gap.c); names come from census/names.tsv.
Answers "who mentions CAREER_CAR" in one grep instead of a 102 MB scan, and is the input for turning a game string
into the code that handles it. Literals are deduplicated per function; the name column is the ledger name at build
time, so the table stays useful after renames (grep the addr).
"""
import argparse, os, re, sys

LIT = re.compile(r'"((?:[^"\\]|\\.){2,120})"')


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--root", default=".")
    ap.add_argument("--extra", action="append", default=[])
    a = ap.parse_args()
    names = {}
    for line in open(os.path.join(a.root, "census/names.tsv"), errors="replace"):
        f = line.split("\t")
        if len(f) > 1 and f[0].startswith("0x"):
            names[int(f[0], 16)] = f[1]
    out = sys.stdout
    out.write("addr\tname\tliteral\tcount\n")
    n = 0
    for p in [os.path.join(a.root, "census/hopper/decomp.c")] + a.extra:
        if not os.path.exists(p):
            continue
        cur, seen = None, {}
        for line in open(p, errors="replace"):
            if line.startswith("// ") and len(line) > 11 and line[3:11].strip() and all(
                    c in "0123456789abcdefABCDEF" for c in line[3:11].strip()):
                if cur is not None:
                    for lit, c in seen.items():
                        out.write("0x%06x\t%s\t%s\t%d\n" % (cur, names.get(cur, ""), lit, c))
                        n += 1
                cur, seen = int(line[3:11], 16), {}
                continue
            if cur is None:
                continue
            for lit in LIT.findall(line):
                seen[lit] = seen.get(lit, 0) + 1
        if cur is not None:
            for lit, c in seen.items():
                out.write("0x%06x\t%s\t%s\t%d\n" % (cur, names.get(cur, ""), lit, c))
                n += 1
    print("%d rows" % n, file=sys.stderr)


if __name__ == "__main__":
    sys.exit(main())
