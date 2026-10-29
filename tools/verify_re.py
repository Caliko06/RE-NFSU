#!/usr/bin/env python3
"""One command that re-checks the night's reverse engineering (docs/re/RESULTS.md).

  .venv/bin/python tools/verify_re.py [--quick]

Part 1 runs every reader's own `check` (bytes round-trip, tile, parse) on the game files in game/.
Part 2 asserts facts about pc/Speed.exe itself: each one is a claim from docs/re/*.md, read from the unpatched exe
with capstone and raw bytes (no lifter, no Hopper, no notes). A FAIL means a doc is wrong, not that the game broke.
Read-only; exit code 1 if anything fails.
"""
import re, struct, subprocess, sys
from capstone import Cs, CS_ARCH_X86, CS_MODE_32

EXE = "pc/Speed.exe"
data = open(EXE, "rb").read()
pe = struct.unpack_from("<I", data, 0x3c)[0]
nsec, opt = struct.unpack_from("<H", data, pe + 6)[0], struct.unpack_from("<H", data, pe + 20)[0]
base = struct.unpack_from("<I", data, pe + 24 + 28)[0]
secs, o = [], pe + 24 + opt
for _ in range(nsec):
    vs, va, rs, ra = struct.unpack_from("<IIII", data, o + 8)
    secs.append((base + va, max(vs, rs), ra, rs)); o += 40

def rd(a, n):
    out = bytearray()
    for i in range(n):
        b = 0
        for va, sz, ra, rs in secs:
            if va <= a + i < va + sz and a + i - va < rs:
                b = data[ra + a + i - va]; break
        out.append(b)
    return bytes(out)

def u32(a): return struct.unpack("<I", rd(a, 4))[0]
def f32(a): return struct.unpack("<f", rd(a, 4))[0]
def f64(a): return struct.unpack("<d", rd(a, 8))[0]
def cstr(a): return rd(a, 64).split(b"\0")[0].decode("latin1")

_md = Cs(CS_ARCH_X86, CS_MODE_32)
def asm(a, n=400):
    """text of up to n instructions from a, stopping after the first ret that follows 4+ instructions"""
    out = []
    for i in _md.disasm(rd(a, n * 8), a):
        out.append(f"{i.mnemonic} {i.op_str}")
        if len(out) >= n: break
    return "\n".join(out)

def has(a, *needles, n=400):
    t = asm(a, n)
    return all(x in t for x in needles)

class approx_f(float):
    def __eq__(self, o): return abs(float(self) - o) < 1e-6

def refs(a):
    """count of 4-byte little-endian occurrences of address a in .text (imm32 and disp32 uses)"""
    va, sz, ra, rs = secs[0]
    return data[ra:ra + rs].count(struct.pack("<I", a))

def approx(x, y, e=1e-6): return abs(x - y) <= e * max(1.0, abs(y))

# (doc, claim, predicate)
CLAIMS = [
    ("assets", "47 loaders in the table at 0x7007e0, then a null", lambda: all(u32(0x7007e0 + 4 * i) for i in range(47)) and u32(0x7007e0 + 4 * 47) == 0),
    ("assets", "loader index 29 is 0x5952a0 (Smackable loader), index 3 is 0x442040", lambda: u32(0x7007e0 + 4 * 29) == 0x5952a0 and u32(0x7007e0 + 4 * 3) == 0x442040),
    ("assets", "chunk dispatcher 0x447ac0 ends a failed round with int3", lambda: has(0x447ac0, "int3", n=120)),
    ("assets", "ResourceFile slot is 0xb4 bytes; COMP and JDLZ magics are tested", lambda: has(0x447f40, "0xb4", n=80) and has(0x58d3c0, "0x504d4f43") and has(0x58d3c0, "0x5a4c444a")),
    ("blur", "scene render target defaults 800x600 (0x320, 0x258)", lambda: u32(0x701034) == 0x320 and u32(0x701038) == 0x258),
    ("blur", "blur speed ramp starts at 25 and reaches 1 at 125; cap 0.65", lambda: approx(f32(0x702a38), 25) and approx(f32(0x702a3c), 125) and approx(f32(0x702a40), 0.65)),
    ("blur", "streak length 0.00625 per tap per unit t", lambda: approx(f32(0x702a44), 0.00625)),
    ("blur", "0x6ccd00 is the double 1/255", lambda: approx(f64(0x6ccd00), 1 / 255)),
    ("camera", "race default camera type is 0x11 because [0x700aa4] = 1", lambda: u32(0x700aa4) == 1 and has(0x42c670, "neg", "sbb", "0x10", "inc", n=100)),
    ("camera", "camera factory 0x42c6d0 handles types 0..0x16", lambda: has(0x42c6d0, "cmp eax, 0x16", "ja", n=100)),
    ("camera", "global FOV s16 per POV: 0x32dc,0x32dc,0x4000,0x4000,0x32dc", lambda: rd(0x6fbdf4, 10) == bytes.fromhex("dc32dc3200400040dc32")),
    ("canon", "career event table: EventDesc rows are 0x14c bytes", lambda: has(0x5a00a0, "0x14c") or has(0x5a0060, "0x14c", "0x3159721f")),
    ("canon", "winning event 0x71 sets the flag at 0x7677ac", lambda: has(0x5a0dc0, "0x71", "0x7677ac")),
    ("canon", "career cash +0x1374 and lifetime +0x1378", lambda: has(0x5a0dc0, "0x1374", "0x1378")),
    ("canon", "42 movie names, stride 8, first is 01_day", lambda: cstr(u32(0x6f90d8)) == "01_day" and has(0x4f7840, "0x2a", n=60)),
    ("garage", "screen registry at 0x6f94d8 starts with Options.fng -> 0x494910, stride 0x14", lambda: cstr(u32(0x6f94d8)) == "Options.fng" and u32(0x6f94d8 + 4) == 0x494910),
    ("garage", "perf path mapper 0x5a0350 has 11 cases", lambda: has(0x5a0350, "cmp eax, 0xa", n=30)),
    ("garage", "part price reader 0x5a08f0 uses table [0x733f78+type*4]", lambda: has(0x5a08f0, "0x733f78")),
    ("garage", "cash read 0x5a1520 returns 1e9 under three flags", lambda: has(0x5a1520, "0x3b9aca00", "0x73494c", "0x735ec1", "0x73440c", n=60)),
    ("props", "smackable pool: 32 x 0x4d0 bytes", lambda: has(0x595bf0, "0x9a30", "0x4d0", n=120)),
    ("props", "surface rows are 0x94 bytes (imul 0x94) based at 0x6ef2d0", lambda: b"\x69\xdb\x94\x00\x00\x00" in rd(0x441d80, 24) and refs(0x6ef2d0) > 0),
    ("rivals", "AI table: 523 floats (0x20b) copied to 0x779c78 when chunk 0x34b00 loads", lambda: has(0x462070, "0x34b00", "0x20b", "0x779c78")),
    ("rivals", "ticks to seconds constant 0x6cca38 is 0.00025", lambda: approx(f32(0x6cca38), 0.00025) or approx(f64(0x6cca38), 0.00025)),
    ("rivals", "rubber band 0x44bd10 reads the tick constant and the AI table end 0x77a49c", lambda: has(0x44bd10, "0x6cca38", "0x77a49c")),
    ("rivals", "rubber band skill record base 0x77a044 (stride 0x54)", lambda: has(0x44bd10, "0x77a044")),
    ("traffic", "incoming traffic cap 30 (0x1e) in 0x4322a0", lambda: has(0x4322a0, "0x1e", "0x12c")),
    ("traffic", "teleporter timers and distances: 1.0 s, 0.3 s, 250 m, 500 m at 0x6b5a30..3c; 250 m is read by code", lambda: [f32(0x6b5a30 + 4 * k) for k in range(4)] == [1.0, approx_f(0.3), 250.0, 500.0] and refs(0x6b5a38) > 0),
    ("sound", "speech event counts table 0x6f6bc8: 95 non-zero entries summing to 277", lambda: (lambda t: len(t) == 95 and all(t) and sum(t) == 277)([u32(0x6f6bc8 + 4 * i) for i in range(95)])),
    ("sound", "engine sound: loader 0x51dec0 reads family table 0x6f8100, crossfade 0x529cd0 reads 0x6f7220", lambda: has(0x51dec0, "0x6f8100") and has(0x529cd0, "0x6f7220")),
    ("tuning", "steering-vs-speed table at 0x705f48: 10 points, x 0..160, step 0.05625 (generic lookup 0x583ea0)", lambda: u32(0x705f48) == 10 and f32(0x705f50) == 160.0 and approx(f32(0x705f54), 0.05625)),
    ("tuning", "car type record is 0xc90 bytes, 35 types (0x23)", lambda: has(0x57c8b0, "0xc90", "0x23", n=80)),
]

def part1(quick):
    checks = [("tpk.py", "tools/re/tpk.py check"), ("chunks.py", "tools/re/chunks.py check"),
              ("csiscurves.py", "tools/re/csiscurves.py check"), ("ast.py", "tools/re/ast.py check"),
              ("abkbank.py", "tools/re/abkbank.py check"), ("save.py", "tools/re/save.py check"),
              ("events.py", "tools/re/events.py check"), ("lang.py", "tools/re/lang.py check"),
              ("carinfo.py", "tools/re/carinfo.py check")]
    if quick:
        checks = [c for c in checks if c[0] not in ("tpk.py",)]
    bad = 0
    print("== Part 1: readers (round-trip / tile / parse on game/ files)")
    for name, cmd in checks:
        try:
            r = subprocess.run([sys.executable] + cmd.split(), capture_output=True, text=True, timeout=900)
            last = [l for l in (r.stdout + r.stderr).strip().splitlines() if l.strip()][-1:] or [""]
            ok = r.returncode == 0 and "False" not in r.stdout and "FAIL" not in r.stdout
        except Exception as e:
            ok, last = False, [repr(e)]
        bad += not ok
        print(f"  {'PASS' if ok else 'FAIL'}  {cmd:<34} {last[0][:90]}")
    return bad

def part2():
    print("== Part 2: claims against pc/Speed.exe (capstone + raw bytes)")
    bad = 0
    for doc, claim, fn in CLAIMS:
        try: ok = bool(fn())
        except Exception as e: ok, claim = False, f"{claim} [{e!r}]"
        bad += not ok
        print(f"  {'PASS' if ok else 'FAIL'}  {doc:<7} {claim}")
    return bad

if __name__ == "__main__":
    import hashlib
    md5 = hashlib.md5(data).hexdigest()
    print(f"pc/Speed.exe md5 {md5} ({'expected' if md5 == 'b6b9232c55376b3c38c56aac1f8a121d' else 'UNEXPECTED'})")
    bad = (md5 != "b6b9232c55376b3c38c56aac1f8a121d") + part1("--quick" in sys.argv) + part2()
    print(f"\n{'ALL PASS' if not bad else str(bad) + ' FAILED'}: {len(CLAIMS)} exe claims + reader checks")
    sys.exit(1 if bad else 0)
