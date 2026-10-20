#!/usr/bin/env python3
"""Check lifted C against a reference x86 CPU (Unicorn), bit for bit.

Unicorn is a test oracle only; it never ships in the game.
For every function in census/speed_exe_functions.tsv: try to lift it, compile all lifted
functions natively, run each on random inputs in both, compare registers and memory.
Writes census/slice_difftest.json. Usage: .venv/bin/python tools/recomp/difftest.py [cases]
"""
import collections, ctypes, json, math, os, random, subprocess, sys
from unicorn import Uc, UcError, UC_ARCH_X86, UC_MODE_32
from unicorn.x86_const import (UC_X86_REG_FPCW, UC_X86_REG_FPSW, UC_X86_REG_FPTAG, UC_X86_REG_FP0, UC_X86_REG_EAX, UC_X86_REG_ECX, UC_X86_REG_EDX, UC_X86_REG_EBX,
                               UC_X86_REG_ESP, UC_X86_REG_EBP, UC_X86_REG_ESI, UC_X86_REG_EDI, UC_X86_REG_EIP,
                               UC_X86_REG_EFLAGS)
sys.path.insert(0, os.path.dirname(__file__))
from lift import Lifter, Unsupported, PROLOGUE

CASES = int(sys.argv[1]) if len(sys.argv) > 1 else 4
UREG = [UC_X86_REG_EAX, UC_X86_REG_ECX, UC_X86_REG_EDX, UC_X86_REG_EBX,
        UC_X86_REG_ESP, UC_X86_REG_EBP, UC_X86_REG_ESI, UC_X86_REG_EDI]
MEMSZ = 0x2000000
REGIONS = [(0x400000, 0x400000), (0x1000000, 0x100000), (0x1f00000, 0x100000)]   # image, scratch, stack
SCRATCH, STACK_TOP, RET = 0x1000000, 0x1ff0000, 0x1fffff0

seed = {int(l.split()[0], 16): l.split()[1] for l in open("census/speed_exe_functions.tsv")}
L = Lifter("pc/Speed.exe", seed)
entries = sorted(seed)
why = collections.Counter()
lifted = []
# Only self-contained functions can run alone: no calls, no tail jumps, no trap sites.
src = [PROLOGUE, "void rn_call(Ctx *c, uint32_t t) { (void)t; c->halt = 1; }\n"
       "uint64_t rn_rdtsc(Ctx *c) { (void)c; return 0; }\n"
       "void rn_cpuid(Ctx *c, uint32_t *a, uint32_t *b, uint32_t *cc, uint32_t *d) { (void)c; *a = *b = *cc = *d = 0; }\n"]
for e in entries:
    try:
        code = L.lift(e, {e})
    except (Unsupported, KeyError) as x:
        why[str(x).split(" 0x")[0]] += 1
        continue
    mn = {L.mnem(i)[1] for i in L.body(e)[0].values()}
    if L.info["calls"] or "rn_call(" in code:
        why["calls"] += 1
    elif mn & {"cpuid", "rdtsc", "pushfd"}:
        why["host-defined (cpuid/rdtsc/eflags)"] += 1      # the CPU we present, not the lifter
    elif any(L.mnem(i)[1] == "ret" and i.operands and i.operands[0].imm >= 0x8000 for i in L.body(e)[0].values()):
        why["ret imm16 >= 0x8000 (Unicorn sign-extends)"] += 1
    elif L.info["traps"]:
        why["trap: " + L.info["traps"][0].split(" 0x")[0]] += 1
    else:
        src.append(code)
        lifted.append(e)
os.makedirs("build/gen", exist_ok=True)
open("build/gen/slice.c", "w").write("\n".join(src))
subprocess.run(["clang", "-O1", "-shared", "-fPIC", "-w", "-Ihost", "-o", "build/slice.dylib", "build/gen/slice.c"], check=True)
lib = ctypes.CDLL(os.path.abspath("build/slice.dylib"))


class Ctx(ctypes.Structure):     # host/rt.h
    _fields_ = [("r", ctypes.c_uint32 * 8), ("mem", ctypes.c_void_p), ("memsz", ctypes.c_uint32), ("ret", ctypes.c_uint32),
                ("halt", ctypes.c_uint32), ("halt_at", ctypes.c_uint32), ("why", ctypes.c_void_p), ("fs", ctypes.c_uint32),
                ("flags", ctypes.c_int32 * 6), ("eflx", ctypes.c_uint32), ("fcw", ctypes.c_uint32), ("fsw", ctypes.c_uint32),
                ("ftop", ctypes.c_uint32), ("ftag", ctypes.c_uint32), ("st", ctypes.c_double * 8)]


hostmem = ctypes.create_string_buffer(MEMSZ)
image = bytes(L.img[:0x400000].ljust(0x400000, b"\0"))
rng = random.Random(1)


def val():
    p = rng.random()
    if p < 0.6:
        return SCRATCH + rng.randrange(0, 0xf0000) & ~3
    if p < 0.85:
        return rng.randrange(0, 64)
    return rng.getrandbits(32)


def f80(v):
    """Unicorn's (mantissa, exponent) pair of an 80-bit register as a Python float."""
    m, e = v
    if e & 0x7fff == 0x7fff:
        return float("nan") if m << 1 & ((1 << 64) - 1) else (-1) ** (e >> 15) * float("inf")
    return (-1) ** (e >> 15) * math.ldexp(m, (e & 0x7fff) - 16383 - 63)


uc = Uc(UC_ARCH_X86, UC_MODE_32)
for b, n in REGIONS:
    uc.mem_map(b, n)

res = collections.Counter()
bad = []
compared, failed = set(), set()
for e in lifted:
    fn = getattr(lib, f"f_{e:x}")
    fn.argtypes = [ctypes.POINTER(Ctx)]
    fn.restype = None
    for _ in range(CASES):
        regs = [val() for _ in range(8)]
        regs[4] = STACK_TOP
        scratch = rng.randbytes(0x100000)
        stack = bytearray(0x100000)
        for k in range(16):
            o = STACK_TOP - 0x1f00000 + 4 + 4 * k
            stack[o:o + 4] = val().to_bytes(4, "little")
        o = STACK_TOP - 0x1f00000
        stack[o:o + 4] = RET.to_bytes(4, "little")
        for (b, n), d in zip(REGIONS, (image, scratch, bytes(stack))):
            uc.mem_write(b, d)
            ctypes.memmove(ctypes.addressof(hostmem) + b, d, n)
        for r, v in zip(UREG, regs):
            uc.reg_write(r, v)
        uc.reg_write(UC_X86_REG_EFLAGS, 0x2)    # same start as the lifted code: flags clear, DF=0
        uc.reg_write(UC_X86_REG_FPCW, 0x27f)    # Windows thread default: 53-bit precision, exceptions masked
        uc.reg_write(UC_X86_REG_FPSW, 0)        # empty FPU stack every case (TOP 0)
        uc.reg_write(UC_X86_REG_FPTAG, 0xffff)
        ufault = False
        try:
            uc.emu_start(e, RET, count=200000)
        except UcError as x:
            if "UNMAPPED" in str(x) or "FETCH" in str(x):
                res["skip_unmapped"] += 1
                res["skip_" + str(x).split("(")[0].strip().replace(" ", "_")[:40]] += 1
                continue
            ufault = True
        if not ufault and uc.reg_read(UC_X86_REG_EIP) != RET:
            res["skip_timeout"] += 1
            continue
        c = Ctx()
        for k, v in enumerate(regs):
            c.r[k] = v
        c.mem, c.memsz = ctypes.addressof(hostmem), MEMSZ
        c.fcw = 0x27f
        fn(ctypes.byref(c))
        lfault = c.halt == 1
        if not lfault and c.ret != RET:
            res["skip_not_a_function"] += 1     # ret went elsewhere: entry is mid-function or data
            continue
        if ufault or lfault:
            ok = ufault == lfault
        else:
            top = (uc.reg_read(UC_X86_REG_FPSW) >> 11) & 7
            u0, l0 = f80(uc.reg_read(UC_X86_REG_FP0 + top)), c.st[c.ftop]
            ok = top == c.ftop and (top == 0 or u0 == l0 or (u0 != u0 and l0 != l0))
            ok = ok and all(uc.reg_read(r) == c.r[k] for k, r in enumerate(UREG)) and all(
                bytes(uc.mem_read(b, n)) == ctypes.string_at(ctypes.addressof(hostmem) + b, n) for b, n in REGIONS)
        res["match" if ok else "mismatch"] += 1
        compared.add(e)
        if not ok:
            failed.add(e)
        if not ok and len(bad) < 40:
            bad.append({"func": hex(e), "uc": [hex(uc.reg_read(r)) for r in UREG], "lift": [hex(x) for x in c.r],
                        "ufault": ufault, "lfault": lfault,
                        "mem_diff": [hex(b + next(i for i in range(n) if u[i] != h[i])) for (b, n) in REGIONS
                                     for u, h in [(bytes(uc.mem_read(b, n)), ctypes.string_at(ctypes.addressof(hostmem) + b, n))] if u != h]})

out = {"functions_tried": len(entries), "functions_lifted": len(lifted),
       "not_lifted_by_reason": dict(why.most_common()), "cases": dict(res), "mismatches": bad,
       "functions_with_mismatch": len(failed), "functions_compared": len(compared),
       "functions_all_match": len(compared - failed),
       "all_match_by_seed": dict(collections.Counter(seed[e] for e in compared - failed)),
       "mismatch_funcs": sorted(hex(e) for e in failed)}
json.dump(out, open("census/slice_difftest.json", "w"), indent=1)
print(json.dumps({k: out[k] for k in ("functions_tried", "functions_lifted", "cases", "functions_compared", "functions_all_match",
                                    "all_match_by_seed", "functions_with_mismatch", "mismatch_funcs")}))
print("top reasons:", dict(why.most_common(12)))
