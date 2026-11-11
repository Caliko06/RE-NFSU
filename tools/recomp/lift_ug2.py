#!/usr/bin/env python3
"""Lift every function of the UG2 exe (SPEED2.EXE) with the same lifter as pc/Speed.exe, and count.

Nothing runs: this is static. The NFSU patch series is NOT applied (patches.py addresses are Speed.exe's),
so the number is what the bare lifter does with a foreign binary.

Inputs:  pc/ug2/SPEED2.EXE, census/ug2/speed2_functions.tsv (entry -> call|entry|data)
Output:  census/ug2/lift_report.json
Usage:   .venv/bin/python tools/recomp/lift_ug2.py
"""
import collections
import hashlib
import json
import multiprocessing as mp
import os
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import patches
patches.apply = lambda img, base: None          # Speed.exe caves must not land in SPEED2.EXE
patches.CODE_AREA = (0, 0)
from lift import Lifter, Unsupported            # noqa: E402

EXE = "pc/ug2/SPEED2.EXE"
FUNCS_TSV = "census/ug2/speed2_functions.tsv"
REPORT = "census/ug2/lift_report.json"
JOBS = int(os.environ.get("RN_JOBS") or os.cpu_count())
FUNCS = {int(l.split()[0], 16): l.split()[1] for l in open(FUNCS_TSV)}
L = None


def init():
    global L
    L = Lifter(EXE, FUNCS)


def work(e):
    try:
        src = L.lift(e, set(FUNCS))
        return e, src, L.info, None
    except Unsupported as x:
        return e, None, None, str(x)


def main():
    with mp.Pool(JOBS, initializer=init) as pool:
        res = pool.map(work, sorted(FUNCS), chunksize=64)
    traps, failed, lifted = collections.Counter(), {}, 0
    with_trap = real_trap = int3_only = 0
    blocked = {}
    for e, src, info, err in res:
        if err:
            failed[hex(e)] = err
            continue
        lifted += 1
        reasons = {t.split(" 0x")[0] for t in info["traps"]}
        for t in info["traps"]:
            traps[t.split(" 0x")[0]] += 1
        if reasons:
            with_trap += 1
            if reasons - {"int3"}:
                real_trap += 1
                blocked[f"{e:08x}"] = sorted(reasons - {"int3"})
            else:
                int3_only += 1
    rep = {
        "exe": EXE,
        "exe_sha256": hashlib.sha256(open(EXE, "rb").read()).hexdigest(),
        "census": FUNCS_TSV,
        "census_entries": len(FUNCS),
        "patches": [],
        "lifted": lifted,
        "failed": failed,
        "functions_with_a_trap": with_trap,
        "functions_with_a_real_trap": real_trap,
        "functions_int3_only": int3_only,
        "blocked_functions": blocked,
        "trap_sites_by_reason": dict(traps.most_common()),
    }
    json.dump(rep, open(REPORT, "w"), indent=1)
    print(f"entries {len(FUNCS)}, lifted {lifted}, failed {len(failed)}, trap sites {sum(traps.values())}")
    print(f"functions with a trap {with_trap} (real {real_trap}, int3 only {int3_only})")
    for k, v in traps.most_common(15):
        print(f"  trap {v:6d}  {k}")
    if failed:
        print("failed reasons:", dict(collections.Counter(failed.values()).most_common(10)))


if __name__ == "__main__":
    main()
