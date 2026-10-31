#!/usr/bin/env python3
"""Print a sample of a names_*.tsv with the pseudocode behind each row, so a human or a model can judge it.

audit_rows.py census/names_render_w4b.tsv [--sample 40] [--seed 7] [--conf I] [--system render]

Rows are read from the ledger file given; bodies come from census/hopper/decomp.c plus any --extra corpus file
(census/ghidra/decomp_gap.c covers the functions Hopper's export lacked). Output per row:

    === 0x5a2620 Career::BuyCarPart    V   evidence: cash +0x1374 down
    <pseudocode, esp noise removed>

Purpose: the scoreboard's own check ("sample 50, 45 or more agree on a manual read") needs the body next to the
claim. A row whose body does not carry the artifact its evidence names is a row to drop.
"""
import argparse, os, random, re, sys


def load_bodies(paths):
    body, cur = {}, None
    for p in paths:
        if not os.path.exists(p):
            continue
        for line in open(p, errors="replace"):
            if line.startswith("// ") and len(line) > 11 and line[3:11].strip() and all(
                    c in "0123456789abcdefABCDEF" for c in line[3:11].strip()):
                cur = int(line[3:11], 16)
                body[cur] = []
            elif cur is None:
                continue
            elif line.startswith("// callers:") or line.startswith("// callees:"):
                body[cur].append(line.rstrip("\n"))
                cur = None
            else:
                t = line.strip()
                if t.startswith("esp = esp") or t.startswith("esp = (esp"):
                    continue
                body[cur].append(line.rstrip("\n"))
    return body


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("file")
    ap.add_argument("--sample", type=int, default=40)
    ap.add_argument("--seed", type=int, default=7)
    ap.add_argument("--conf", default="")
    ap.add_argument("--system", default="")
    ap.add_argument("--chars", type=int, default=1400)
    ap.add_argument("--root", default=".")
    a = ap.parse_args()
    rows = []
    lines = [l for l in open(a.file) if not l.startswith("#")]
    for r in lines[1:]:
        f = r.rstrip("\n").split("\t")
        if len(f) < 6 or not f[0].startswith("0x"):
            continue
        if a.conf and len(f) > 3 and f[3] != a.conf:
            continue
        if a.system and len(f) > 2 and f[2] != a.system:
            continue
        rows.append(f)
    random.Random(a.seed).shuffle(rows)
    body = load_bodies([os.path.join(a.root, "census/hopper/decomp.c"),
                        os.path.join(a.root, "census/ghidra/decomp_gap.c")])
    for f in rows[: a.sample]:
        addr = int(f[0], 16)
        print("=== %s  %-42s %-2s %s" % (f[0], f[1], f[3] if len(f) > 3 else "?", f[4] if len(f) > 4 else ""))
        b = "\n".join(body.get(addr, []))[: a.chars]
        print(b if b.strip() else "    (no body in the corpus)")
        print()


if __name__ == "__main__":
    sys.exit(main())
