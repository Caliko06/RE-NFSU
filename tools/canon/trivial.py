#!/usr/bin/env python3
"""Trivial and compiler-generated functions, named from their bytes (docs/re/canon_db.md "Trivial functions").

NIGHT_BRIEF counts a function as done when it is named or "marked trivial with a reason". Most unnamed small functions
are MSVC output with a fixed shape; this reads each unnamed lifted function of <= 48 bytes with capstone and writes one
row per exact shape match. The system comes from structure (thunk target, EH parent, destructor chain, global readers),
never from the low-confidence graph tag; with no solid system the row is left out and counted.

  shape          bytes                                              name
  thunk          jmp T                                              thunk_<T>
  sdd            push esi; mov esi,ecx; call D; test [esp+8],1; ... call _free ... ret 4   <D>::ScalarDeletingDtor
  vtdtor         mov [ecx],VT; (add ecx,N;) jmp D                   Dtor_vt<VT> (sets the vtable, chains to D)
  ehstub         mov eax,FuncInfo; jmp ___CxxFrameHandler           EHStub_<parent>
  unwind         ebp/esp-relative load of ecx/eax; (add ecx,N;) jmp D, no code callers    Unwind_<parent>_<D>
  dyninit        stores to globals only, no calls, ret, no code callers                    DynInit_<global>
  getter/setter  mov eax,[ecx+N]; ret  /  mov eax,[esp+4]; mov [ecx+N],eax; ret 4           Get_<N> / Set_<N>
  nop            ret / ret N                                        Nop_ret<N>

Parents of EH funclets: FuncInfo (magic 0x19930520) -> unwind map entries (toState, action) -> funclet; the stub
`mov eax,FuncInfo; jmp` is pushed by the parent's prologue (its callers in funcs.jsonl).

  trivial.py [--dry]   -> census/names_trivial.tsv (skips addresses another names_*.tsv already names)
"""
import json, os, re, struct, sys
from collections import Counter

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import canon   # noqa: E402  (chdir to the repo root)
import capstone, pefile   # noqa: E402

BASE, FREE, FRAME = 0x400000, 0x671102, 0x673078
L = canon.lifted()
system, rows = canon.merged()
rows = {x: r for x, r in rows.items() if not r["evidence"][3:].startswith("trivial: ") or r["tool"] != "capstone"}   # our own last run
F = {int(j["addr"], 16): j for j in map(json.loads, open("census/canon/funcs.jsonl"))}
G = {int(j["addr"], 16): j for j in map(json.loads, open("census/canon/data.jsonl")) if j.get("kind") == "global"}
pe = pefile.PE("pc/Speed.exe", fast_load=True)
img = pe.get_memory_mapped_image()
md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
md.detail = True


def dis(x, n):
    return [(i.mnemonic, i.op_str, i) for i in md.disasm(img[x - BASE:x - BASE + n], x)]


def solid(x):
    """System of x when it is named or tagged med/high; else None."""
    r = rows.get(x)
    if r and r["system"]:
        return r["system"]
    s, c = system.get(x, ("unknown", "low"))
    return s if c in ("med", "high") and s not in ("unknown", "none") else None


def nm(x):
    r = rows.get(x)
    return re.sub(r"[^A-Za-z0-9_:~]", "", r["name"].split(" (")[0]) if r else f"{x:x}"


def code_callers(x):
    return [c for c in F.get(x, {}).get("callers", []) if not c.startswith("d")]


def callers_vote(x):
    v = Counter(s for s in map(solid, (canon.a(c) for c in code_callers(x))) if s)
    if v:
        s, k = v.most_common(1)[0]
        if k * 10 >= 7 * sum(v.values()):
            return s, f"callers {k}/{sum(v.values())}"
    v = Counter(s for s in (system.get(canon.a(c), ("unknown",))[0] for c in code_callers(x)) if s not in ("unknown", "none"))
    if v:   # fallback: the callers' graph tags (low confidence), so the row stays I
        s, k = v.most_common(1)[0]
        if k * 10 >= 7 * sum(v.values()):
            return s, f"callers graph tags {k}/{sum(v.values())}"
    return None, None


# EH: FuncInfo -> unwind actions; stub -> FuncInfo; stub -> parent (the function that pushes it)
rd = next(s for s in pe.sections if s.Name.startswith(b".rdata"))
lo, hi = BASE + rd.VirtualAddress, BASE + rd.VirtualAddress + rd.Misc_VirtualSize
action_fi = {}
for off in range(lo - BASE, hi - BASE - 12, 4):
    if struct.unpack_from("<I", img, off)[0] != 0x19930520:
        continue
    nstate, umap = struct.unpack_from("<II", img, off + 4)
    if 0 < nstate < 256 and lo <= umap < hi:
        for k in range(nstate):
            act = struct.unpack_from("<I", img, umap - BASE + 8 * k + 4)[0]
            if act:
                action_fi.setdefault(act, BASE + off)
stub_fi, fi_parent = {}, {}
for x in L:
    b = img[x - BASE:x - BASE + 10]
    if len(b) == 10 and b[0] == 0xB8 and b[5] == 0xE9 and x + 10 + struct.unpack_from("<i", b, 6)[0] == FRAME:
        fi = struct.unpack_from("<I", b, 1)[0]
        stub_fi[x] = fi
        ps = [canon.a(c) for c in F.get(x, {}).get("callers", []) if not c.startswith("d")]
        if len(ps) == 1:
            fi_parent[fi] = ps[0]


def parent_of_funclet(x):
    fi = action_fi.get(x)
    return fi_parent.get(fi) if fi else None


def classify(x, size):
    ins = dis(x, size)
    m = [i[0] for i in ins]
    o = [i[1] for i in ins]
    if not ins or sum(i[2].size for i in ins) != size:
        return None
    def target(i):
        try:
            return int(o[i], 16)
        except ValueError:
            return None
    if m == ["jmp"] and target(0):
        t = target(0)
        s = solid(t)
        if s:
            return (f"thunk_{nm(t)}", s, f"jmp {t:#x}; system of the target")
        s, how = callers_vote(x)
        return (s or False) and (f"thunk_{nm(t)}", s, f"jmp {t:#x}; system by {how}")
    if x in stub_fi:
        p = fi_parent.get(stub_fi[x])
        s = p and solid(p)
        return (s or False) and (f"EHStub_{nm(p)}", s, f"mov eax,FuncInfo {stub_fi[x]:#x}; jmp ___CxxFrameHandler; pushed by {p:#x}")
    if (m[:4] == ["push", "mov", "call", "test"] and o[0] == "esi" and o[1] == "esi, ecx" and "[esp + 8], 1" in o[3]
            and f"call {FREE:#x}" in " ".join(f"{a} {b}" for a, b in zip(m, o)) and m[-1] == "ret" and o[-1] == "4"):
        d = target(2)
        s = d and solid(d)
        cls = nm(d).rsplit("::", 1)[0] if "::" in nm(d) else f"Dtor{d:x}"
        return (s or False) and (f"{cls}::ScalarDeletingDtor", s, f"calls dtor {d:#x}, then _free {FREE:#x} when arg & 1; system of the dtor")
    if m[-1] == "jmp" and m[0] == "mov" and o[0].startswith("dword ptr [ecx], 0x") and m[1:-1] in ([], ["add"]):
        vt, d = int(o[0].split(", ")[1], 16), target(len(m) - 1)
        s = d and solid(d)
        return (s or False) and (f"Dtor_vt{vt:x}", s, f"sets vtable {vt:#x}, chains to {d:#x}; system of {d:#x}")
    if (m[-1] == "jmp" and m[0] in ("mov", "lea") and re.match(r"(ecx|eax), .*\[(ebp|esp)", o[0]) and m[1:-1] in ([], ["add"])
            and not code_callers(x)):
        d, p = target(len(m) - 1), parent_of_funclet(x)
        s = p and solid(p)
        if s:
            return (f"Unwind_{nm(p)}_{d:x}", s, f"EH unwind action of FuncInfo {action_fi[x]:#x} (parent {p:#x}); {o[0]}; jmp {d:#x}")
        s = d and solid(d)
        return (s or False) and (f"Unwind_{d:x}", s, f"EH unwind shape, {o[0]}; jmp {d:#x}; parent not resolved; system of the dtor")
    if m and m[-1] == "ret" and "call" not in m and not code_callers(x) and any(i.startswith(("fstp", "mov")) for i in m):
        dst = [int(g, 16) for a, b in zip(m, o) if a.startswith(("fstp", "mov")) for g in re.findall(r"^\w+ ptr \[(0x[0-9a-f]+)\]", b)]
        if dst and len(dst) == sum(1 for a, b in zip(m, o) if a.startswith(("fstp", "mov")) and b.startswith(("dword ptr [", "qword ptr [", "byte ptr [", "word ptr ["))):
            v = Counter(s for g in dst for s in map(solid, (canon.a(r) for r in G.get(g, {}).get("readers", []))) if s)
            if v:
                s, k = v.most_common(1)[0]
                if k * 10 >= 7 * sum(v.values()):
                    return (f"DynInit_{dst[0]:x}", s, f"static initializer: writes {', '.join(f'{g:#x}' for g in dst)}, no code callers; readers {k}/{sum(v.values())} {s}")
        return None
    if m == ["mov", "ret"] and re.fullmatch(r"(eax|al|ax), (dword|byte|word) ptr \[ecx( \+ 0x[0-9a-f]+)?\]", o[0]) and o[1] == "":
        s, how = callers_vote(x)
        off = (re.findall(r"0x[0-9a-f]+", o[0]) or ["0x0"])[0]
        return (s or False) and (f"Get_{off[2:]}", s, f"{o[0]}; ret; system by {how}")
    if m == ["mov", "mov", "ret"] and o[0] == "eax, dword ptr [esp + 4]" and re.fullmatch(r"dword ptr \[ecx( \+ 0x[0-9a-f]+)?\], eax", o[1]):
        s, how = callers_vote(x)
        off = (re.findall(r"0x[0-9a-f]+", o[1]) or ["0x0"])[0]
        return (s or False) and (f"Set_{off[2:]}", s, f"[ecx+{off}] = arg; ret {o[2]}; system by {how}")
    if m == ["ret"]:
        s, how = callers_vote(x)
        return (s or False) and (f"Nop_ret{o[0]}", s, f"ret {o[0]}; system by {how}")
    return None


out, miss, nosys = [], Counter(), Counter()
for x in sorted(L):
    if x in rows or x not in F or F[x]["size"] > 48:
        continue
    r = classify(x, F[x]["size"])
    if r:
        out.append((x,) + r)
    elif r is None:
        miss["no shape"] += 1
    else:
        nosys["shape, no solid system"] += 1
kinds = Counter(n.split("_")[0].split("::")[-1] for _, n, _, _ in out)
print(f"trivial: {len(out)} rows {dict(kinds)}; {dict(miss)}; {dict(nosys)}; EH FuncInfo actions {len(action_fi)}, stubs {len(stub_fi)}, parents {len(fi_parent)}")
if "--dry" not in sys.argv:
    with open("census/names_trivial.tsv", "w") as f:
        f.write("# Made by tools/canon/trivial.py: compiler-generated or one-instruction functions, shape read in bytes.\n")
        f.write("addr\tname\tsystem\tconfidence\tevidence\ttool\tdoc\n")
        for x, n, s, e in out:
            c = "I" if "system by callers" in e or "parent not resolved" in e else "V"
            f.write(f"{x:#x}\t{n}\t{s}\t{c}\t{c}: trivial: {e}\tcapstone\tdocs/re/canon_db.md\n")
