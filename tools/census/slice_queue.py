#!/usr/bin/env python3
"""Cut census/hopper/decomp.c into reading chunks for one system, hottest small function first.

slice_queue.py --system render --outdir /tmp/sl/render [--budget 120000] [--max 240]

Reads census/canon/queue.tsv (addr, system, open_callees, size, callees, callers, strings, prior) and
census/names.tsv (addr, name); a function already in names.tsv is skipped. Each block is:

    #### 0x404cc0 callers=3 callees=1 lines=233
    callers: 0x401000 ScratchAlloc16 ...
    callees: 0x401010 sub_401010
    <pseudocode body>

Order: functions of at most --big lines (default 160) first, then by callers descending, then smaller body.
Bodies over --big lines are cut to their head and tail and marked TRUNCATED, so a name derived from one is an
inference, not a verified reading. Chunks are filled to --budget characters, so one chunk is one comfortable read.
Writes <outdir>/index.tsv (chunk, addr, lines) so coverage of what a lane produced can be checked.
"""
import argparse, os, sys

BIG = 160


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--system", required=True)
    ap.add_argument("--outdir", required=True)
    ap.add_argument("--budget", type=int, default=120000)
    ap.add_argument("--max", type=int, default=240)
    ap.add_argument("--big", type=int, default=BIG)
    ap.add_argument("--extra", action="append", default=[],
                    help="extra corpus file in the same block format (e.g. census/ghidra/decomp_gap.c)")
    ap.add_argument("--root", default=".")
    a = ap.parse_args()
    root = a.root

    named = set()
    for line in open(os.path.join(root, "census/names.tsv")):
        f = line.split("\t")
        if f and f[0].startswith("0x"):
            named.add(f[0].lower())

    want = {}
    for line in list(open(os.path.join(root, "census/canon/queue.tsv")))[1:]:
        f = line.rstrip("\n").split("\t")
        if len(f) < 7 or f[1] != a.system or f[0].lower() in named:
            continue
        try:
            want[int(f[0], 16)] = (int(f[5]), int(f[4]), int(f[3]))
        except ValueError:
            continue
    order = sorted(want, key=lambda x: (want[x][2] > a.big, -want[x][0], want[x][2], x))[: a.max]
    picked = set(order)

    body = {}
    cur = None
    for path in [os.path.join(root, "census/hopper/decomp.c")] + \
                [e if os.path.isabs(e) else os.path.join(root, e) for e in a.extra]:
        if not os.path.exists(path):
            sys.exit("missing corpus: " + path)
        for line in open(path, errors="replace"):
            if line.startswith("// ") and len(line) > 11 and line[3:11].strip() and all(
                    c in "0123456789abcdefABCDEF" for c in line[3:11].strip()):
                a0 = int(line[3:11], 16)
                cur = a0 if a0 in picked and a0 not in body else None
                if cur is not None:
                    body[cur] = []
            elif cur is None:
                continue
            elif line.startswith("// callers:"):
                body[cur].append(("callers", line[12:].split()))
                cur = None
            elif line.startswith("// callees:"):
                body[cur].append(("callees", line[13:].split()))
            else:
                t = line.strip()
                if t.startswith("esp = esp") or t.startswith("esp = (esp"):   # lifter stack noise, carries no name
                    continue
                body[cur].append(("code", line.rstrip("\n")))

    names = {}
    for line in open(os.path.join(root, "census/names.tsv")):
        f = line.split("\t")
        if len(f) > 1 and f[0].startswith("0x"):
            names[f[0].lower()] = f[1]

    def nm(x):
        return names.get("0x" + x.lower().replace("0x", "").rjust(6, "0"), "sub_" + x.lower())

    os.makedirs(a.outdir, exist_ok=True)
    idx = open(os.path.join(a.outdir, "index.tsv"), "w")
    idx.write("chunk\taddr\tlines\ttruncated\n")
    chunks, cur_txt, used, cn = [], [], 0, 0
    for a0 in order:
        cs, ds, size = want[a0]
        blocks = body.get(a0) or []
        code = [v for k, v in blocks if k == "code"]
        trunc = len(code) > a.big
        if trunc:
            code = code[:120] + ["    // ... %d lines omitted (TRUNCATED) ..." % (len(code) - 180)] + code[-60:]
        txt = ["#### 0x%06x callers=%d callees=%d lines=%d%s" % (a0, cs, ds, size, " TRUNCATED" if trunc else "")]
        for k in ("callers", "callees"):
            v = [x for kk, x in blocks if kk == k]
            if v and v[0]:
                txt.append("%s: %s" % (k, " ".join("%s %s" % (x, nm(x)) for x in v[0][:14])))
        txt.extend(code)
        blk = "\n".join(txt) + "\n\n"
        if used and used + len(blk) > a.budget:
            chunks.append("".join(cur_txt)); cur_txt, used = [], 0
        cur_txt.append(blk); used += len(blk)
        if len(cur_txt) == 1:
            cn += 1
        idx.write("c%02d\t0x%06x\t%d\t%d\n" % (cn, a0, size, int(trunc)))
    if cur_txt:
        chunks.append("".join(cur_txt))
    for i, c in enumerate(chunks, 1):
        open(os.path.join(a.outdir, "c%02d.txt" % i), "w").write(c)
    idx.close()
    print("%s: %d queued, %d chunked into %d files (%d chars)" % (
        a.system, len(want), len(order), len(chunks), sum(len(c) for c in chunks)))


if __name__ == "__main__":
    sys.exit(main())
