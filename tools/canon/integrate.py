#!/usr/bin/env python3
"""Orchestrator-only: integrate per-batch worker outputs into the naming ledgers (docs/re/canon_wave.md).

  integrate.py <batch.txt> <worker_out.tsv>... [--apply]

Each worker wrote its own file (7 columns addr name system confidence evidence tool doc, no header). This script checks
them and, with --apply, appends the accepted rows to census/names_<system>.tsv (append only, one writer). Without --apply
it only reports. Nothing is dropped silently: a row that is not appended goes, with its reason, to
<first worker_out>.rejected.tsv (rows already in a ledger under another name, repeats between workers, bad rows).
Never run it while another writer appends to the same ledgers."""
import csv, glob, os, sys

args = [x for x in sys.argv[1:] if x != "--apply"]
apply = "--apply" in sys.argv
if len(args) < 2: sys.exit(__doc__)
batch = {int(l.split()[0], 16) for l in open(args[0]) if l.strip() and not l.startswith("#")}
ledger = {}   # addr -> name in the live ledgers
for p in glob.glob("census/names_*.tsv"):
    if p.endswith("names_seed.tsv"): continue
    for r in csv.reader((l for l in open(p) if not l.startswith("#")), delimiter="\t"):
        try: ledger.setdefault(int(r[0], 16), (r[1], p))
        except (ValueError, IndexError): pass

accept, reject, seen = [], [], {}
for w in args[1:]:
    for line in open(w):
        line = line.rstrip("\n")
        if not line.strip() or line.startswith("#") or line.startswith("addr\t"): continue
        f = line.split("\t")
        why = None
        if len(f) != 7: why = f"{len(f)} columns, need 7"
        else:
            try: x = int(f[0], 16)
            except ValueError: x = None; why = "address not hex"
        if not why and not (f[1] and f[2] and f[3] and f[4]): why = "empty name/system/confidence/evidence"
        if not why and x not in batch: why = "address not in this batch"
        if not why and x in ledger: why = ("already in ledger with the same name" if ledger[x][0] == f[1] else f"already in {ledger[x][1]} as {ledger[x][0]}")
        if not why and x in seen: why = f"also written by {seen[x][0]} as {seen[x][1]}"
        if not why and not os.path.exists(f"census/names_{f[2].split('.')[0]}.tsv"): why = f"no ledger census/names_{f[2].split('.')[0]}.tsv"
        if why: reject.append((why, line, w))
        else:
            seen[x] = (w, f[1]); accept.append((x, f))

by = {}
for x, f in accept: by.setdefault(f"census/names_{f[2].split('.')[0]}.tsv", []).append("\t".join(f) + "\n")
if apply:
    for p, rows in by.items():
        with open(p, "rb+") as o:   # ensure the last line ends in a newline before appending
            o.seek(0, 2)
            if o.tell():
                o.seek(-1, 2); pre = b"" if o.read(1) == b"\n" else b"\n"
            else: pre = b""
            o.seek(0, 2); o.write(pre + "".join(rows).encode())
if reject:
    with open(args[1] + ".rejected.tsv", "w") as o:
        for why, line, w in reject: o.write(f"{why}\t{os.path.basename(w)}\t{line}\n")
done = {x for x, _ in accept} | {x for x in batch if x in ledger}
print(f"{'applied' if apply else 'dry run'}: {len(accept)} rows -> {len(by)} ledgers; {len(reject)} rejected; "
      f"{len(batch - done)} of {len(batch)} batch addresses still without a row" + (f"; rejects in {args[1]}.rejected.tsv" if reject else ""))
