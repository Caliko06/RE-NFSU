#!/usr/bin/env python3
"""Fixture test for tools/canon/integrate.py (temp tree; touches no census file)."""
import os, subprocess, sys, tempfile
S = os.path.dirname(os.path.abspath(__file__)) + "/integrate.py"
os.chdir(tempfile.mkdtemp()); os.makedirs("census")
open("census/names_car.tsv", "w").write("addr\tname\tsystem\tconfidence\tevidence\ttool\tdoc\n0x500000\tOld\tcar\tmed\tI: x\tt\td")   # no final newline
open("census/names_hud.tsv", "w").write("addr\tname\tsystem\tconfidence\tevidence\ttool\tdoc\n")
open("batch.txt", "w").write("# files: a.cpp\n" + "".join(f"0x50000{i:x}\n" for i in range(6)))
row = lambda a, n, s="car": f"0x{a:x}\t{n}\t{s}\tmed\tI: e\tt\td\n"
open("w1.tsv", "w").write(row(0x500001, "One") + row(0x500002, "Two", "hud") + row(0x500000, "Other") + "bad\trow\n" + row(0x500009, "Out"))
open("w2.tsv", "w").write(row(0x500001, "OneAlt") + row(0x500003, "Three"))
run = lambda *a: subprocess.run([sys.executable, S, "batch.txt", "w1.tsv", "w2.tsv", *a], capture_output=True, text=True).stdout
d = run(); assert "dry run: 3 rows" in d and "4 rejected" in d, d
assert open("census/names_car.tsv").read().count("\n") == 1   # dry run wrote nothing
a = run("--apply"); assert "applied: 3 rows -> 2 ledgers; 4 rejected; 2 of 6" in a, a   # 0x500004, 0x500005 still open; 0x500000 is in the ledger
car = open("census/names_car.tsv").read().splitlines(); assert car[1].startswith("0x500000\tOld") and car[2].startswith("0x500001\tOne\t") and car[3].startswith("0x500003\tThree"), car
assert open("census/names_hud.tsv").read().splitlines()[1].startswith("0x500002\tTwo")
rej = open("w1.tsv.rejected.tsv").read(); assert "OneAlt" in rej and "as Old" in rej and "7 columns" not in rej and "2 columns, need 7" in rej and "not in this batch" in rej, rej
b = run("--apply"); assert "applied: 0 rows" in b and open("census/names_car.tsv").read().count("\n") == 4   # idempotent
print("ok: integrate (dry run, append, newline repair, ledger clash, cross-worker repeat, bad rows, idempotent)")
