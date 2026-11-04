#!/usr/bin/env python3
"""Fixture test for tools/census/{evstate,names_merge,scoreboard}.py: evidence state vs confidence, fragments, duplicates.
Run: python3 tools/census/test_evidence.py  (builds a throwaway tree in a temp dir; touches no census file)"""
import csv, json, os, subprocess, sys, tempfile
HERE = os.path.dirname(os.path.abspath(__file__)); sys.path.insert(0, HERE)
from evstate import state

def row(conf, ev): return {"confidence": conf, "evidence": ev}
cases = [(row("high", "I: guess"), ("I", False)), (row("high", "U: unknown"), ("U", False)), (row("high", "V: matches"), ("V", False)),
         (row("high", "trivial: getter"), ("V", True)), (row("high", ""), ("V", True)), (row("I", "V: x"), ("I", False)),
         (row("V", "I: x"), ("V", False)), (row("U", ""), ("U", False)), (row("med", "V: x"), ("V", False)),
         (row("low", "G: gc"), ("I", False)), (row("", "Verified by hand"), ("I", False)), (row("med", "I: x"), ("I", False))]
for r, want in cases: assert state(r) == want, (r, state(r), want)

T = tempfile.mkdtemp(); os.chdir(T)
for d in ("census/hopper", "census/canon", "census/cov", "build/gen"): os.makedirs(d)
H = "addr name system confidence evidence tool doc".replace(" ", "\t")
def names(f, rows): open(f"census/names_{f}.tsv", "w").write(H + "\n" + "\n".join("\t".join(r) for r in rows) + "\n")
names("a", [("0x401000", "A", "car", "high", "I: guess", "t", "d"), ("0x401010", "B", "car", "high", "V: ok", "t", "d"),
            ("0x401020", "C", "car", "high", "trivial: getter", "t", "d"), ("0x401030", "D", "car", "I", "V: x", "t", "d"),
            ("0x401040", "E", "car", "U", "", "t", "d"), ("0x401050", "F", "car", "med", "V: ok", "t", "d"),
            ("0x401060", "OldName", "car", "high", "trivial: x", "t", "d"), ("0x401070", "Frag", "car", "med", "V: ok", "t", "d")])
names("b", [("0x401060", "NewName", "car", "med", "V: ok", "t", "d")])   # duplicate: real V beats legacy V, nothing dropped
open("census/hopper/funcs.tsv", "w").write("addr\n" + "".join(f"0x{x:x}\n" for x in range(0x401000, 0x401070, 0x10)))
open("census/canon/fragments.tsv", "w").write("addr\tparent\twhy\n0x401070\t0x401000\tinside\n0x401080\t0x401010\tinside\n0x401090\t?\tnot a Ghidra function\n")
open("census/systems.tsv", "w").write("addr\tsystem\tconf\n")
json.dump({"addrs": []}, open("census/cov/union.json", "w")); json.dump({"compared_funcs": []}, open("census/difftest.json", "w"))
open("build/gen/f0.c", "w").write("".join(f"void f_{x:06x}(void) {{}}\n" for x in range(0x401000, 0x4010a0, 0x10)))

r = subprocess.run([sys.executable, f"{HERE}/names_merge.py", "out.tsv"], capture_output=True, text=True); assert r.returncode == 0, r.stderr
m = {l.split("\t")[0]: l.rstrip("\n").split("\t") for l in open("out.tsv")}
st = {a: m[a][3] for a in m}
assert st["0x401000"] == "I" and st["0x401010"] == "V" and st["0x401020"] == "V" and st["0x401030"] == "I" and st["0x401040"] == "U", st
assert m["0x401060"][1] == "NewName" and "OldName@a" in m["0x401060"][7], m["0x401060"]
assert m["0x401070"][8:10] == ["fragment", "0x401000"] and m["0x401000"][8] == "func", (m["0x401070"], m["0x401000"])
assert "legacy high-as-V (no explicit state): 1" in r.stdout, r.stdout   # only 0x401020; 0x401060 got a real V
s = subprocess.run([sys.executable, f"{HERE}/scoreboard.py"], capture_output=True, text=True); assert s.returncode == 0, s.stderr
tot = dict(zip(s.stdout.splitlines()[0].split("\t"), s.stdout.splitlines()[-1].split("\t")))
assert tot["named"] == "8" and tot["named V"] == "5" and tot["fragments"] == "2", tot   # V: B C F NewName(0x401060) Frag; fragment 0x401090 has no parent
assert tot["frag/parent named"] == "1", tot   # 0x401080 unnamed, parent 0x401010 named; 0x401070 is named itself (counted once in `named`)
assert "1 of them only by legacy" in s.stderr, s.stderr
print("ok: evstate", len(cases), "cases; names_merge; scoreboard", tot)
