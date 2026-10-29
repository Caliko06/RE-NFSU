#!/usr/bin/env python3
"""Names from prior art (docs/re/canon_db.md), x86 to x86: NFSMW PC 1.3 symbols (dbalatoni13/nfsmw
config/SPEED_EXE_1_3/symbols.json, fetched to build/prior/nfsmw) on ~/RE-NFSMW/pc/Speed.exe, matched to our Speed.exe.

  prior.py mw    -> census/canon/prior_mw.tsv (addr, mw_addr, mw_name, how, size)

Match keys, strongest first: exact bytes with relocated operands masked; same masked instruction shape; then call-graph
propagation (a matched pair's callees at the same call index, with the same shape class). Only 1:1 keys are kept.
"""
import hashlib, json, os, re, sys
from collections import defaultdict
import capstone, pefile

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
os.chdir(ROOT)
MW_EXE = os.path.expanduser("~/RE-NFSMW/pc/Speed.exe")
MD = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
MD.detail = True
AUTO = re.compile(r"^(sub_|nullsub_|j_|unknown_libname|loc_|def_)")


class Image:
    def __init__(self, path):
        self.pe = pefile.PE(path)
        self.base = self.pe.OPTIONAL_HEADER.ImageBase
        self.lo = self.base
        self.hi = self.base + self.pe.OPTIONAL_HEADER.SizeOfImage

    def read(self, va, n):
        return self.pe.get_data(va - self.base, n)


def shape(img, va, size):
    """(exact, shape, calls): exact = bytes-level with in-image addresses masked; shape = mnemonics + operand kinds;
    calls = direct call targets in order."""
    code = img.read(va, size)
    ex, sh, calls = hashlib.sha1(), hashlib.sha1(), []
    for i in MD.disasm(code, va):
        ops = []
        for o in i.operands:
            if o.type == capstone.x86.X86_OP_IMM:
                v = o.imm & 0xffffffff
                ops.append("A" if img.lo <= v < img.hi else f"i{v:x}")
            elif o.type == capstone.x86.X86_OP_MEM:
                d = o.mem.disp & 0xffffffff
                ops.append(f"m{o.mem.base}.{o.mem.index}.{o.mem.scale}." + ("A" if img.lo <= d < img.hi else f"{d:x}"))
            else:
                ops.append(f"r{o.reg}")
        if i.mnemonic == "call" and i.operands and i.operands[0].type == capstone.x86.X86_OP_IMM:
            calls.append(i.operands[0].imm & 0xffffffff)
        if i.group(capstone.CS_GRP_JUMP) and i.operands and i.operands[0].type == capstone.x86.X86_OP_IMM:
            ops = [f"j{(i.operands[0].imm - va) & 0xffffffff:x}"]   # relative inside the function
        ex.update((i.mnemonic + " " + ",".join(ops) + ";").encode())
        sh.update((i.mnemonic + ";").encode())
    return ex.hexdigest(), sh.hexdigest(), calls


def table(img, funcs):
    out = {}
    for va, size in funcs:
        if size < 6:
            continue
        try:
            out[va] = (size,) + shape(img, va, size)
        except Exception:
            pass
    return out


def unique(tab, k):
    idx = defaultdict(list)
    for va, t in tab.items():
        idx[t[k], t[0]].append(va)
    return {key: v[0] for key, v in idx.items() if len(v) == 1}


def mw():
    sym = json.load(open("build/prior/nfsmw/symbols.json"))
    mw_names = {int(f["start"], 16): f["name"] for f in sym["functions"]}
    mw_funcs = [(int(f["start"], 16), int(f["size"], 16)) for f in sym["functions"]]
    us = [json.loads(l) for l in open("census/canon/funcs.jsonl")]
    our_funcs = [(int(j["addr"], 16), j["size"]) for j in us]
    A, B = table(Image(MW_EXE), mw_funcs), table(Image("pc/Speed.exe"), our_funcs)
    match, how = {}, {}
    for k, tag in ((1, "exact"), (2, "shape")):
        ua, ub = unique(A, k), unique(B, k)
        for key, b in ub.items():
            if key in ua and b not in match and ua[key] not in match.values() and B[b][0] >= (16 if k == 2 else 8):
                match[b], how[b] = ua[key], tag
    # call-graph propagation: same call index, same size class, same shape
    taken = set(match.values())
    for _ in range(6):
        added = 0
        for b, m in list(match.items()):
            cb, cm = B[b][3], A[m][3]
            if len(cb) != len(cm):
                continue
            for x, y in zip(cb, cm):
                if x in B and y in A and x not in match and y not in taken and B[x][2] == A[y][2]:
                    match[x], how[x] = y, "callee"
                    taken.add(y)
                    added += 1
        if not added:
            break
    rows = []
    for b, m in sorted(match.items()):
        n = mw_names.get(m, "")
        if AUTO.match(n):
            continue
        rows.append(f"{b:#x}\t{m:#x}\t{n}\t{how[b]}\t{B[b][0]}")
    with open("census/canon/prior_mw.tsv", "w") as o:
        o.write("addr\tmw_addr\tmw_name\thow\tsize\n" + "\n".join(rows) + "\n")
    c = defaultdict(int)
    for r in rows:
        c[r.split("\t")[3]] += 1
    print(f"mw: {len(match)} matched, {len(rows)} with a real MW name {dict(c)} -> census/canon/prior_mw.tsv")


if __name__ == "__main__":
    {"mw": mw}[sys.argv[1] if len(sys.argv) > 1 else "mw"]()
