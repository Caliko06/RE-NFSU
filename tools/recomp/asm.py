"""x86-32 helper for PATCH caves: disassemble Speed.exe, assemble a cave at its address.

  asm.py dis <addr> [n=40]           capstone listing of the (unpatched) exe at a VA
  asm.py asm <addr> <file.s|->      Intel syntax -> hex for patches.py, assembled for that VA
  asm.py free <addr> <len>          check the bytes there are CC/90 padding

clang (i686 integrated assembler) does the encoding; capstone (pip, any venv) prints the listing. In a .s file, jumps and
calls to absolute addresses outside the cave use the macros `CALLA 0x...` and `JMPA 0x...` (rel32 from this VA);
labels inside the cave work as usual. Data in .s: `.long`, `.float`.
"""
import os, struct, subprocess, sys, tempfile

B = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
EXE = os.path.join(B, "pc", "Speed.exe")


def image():
    d = open(EXE, "rb").read()
    pe = struct.unpack_from("<I", d, 0x3C)[0]
    n = struct.unpack_from("<H", d, pe + 6)[0]
    so = pe + 24 + struct.unpack_from("<H", d, pe + 20)[0]
    secs = [struct.unpack_from("<8sIIII", d, so + 40 * i) for i in range(n)]
    return d, [(0x400000 + va, rs, ra) for _, _, va, rs, ra in secs]


def read(addr, n):
    d, secs = image()
    for va, rs, ra in secs:
        if va <= addr < va + rs:
            return d[ra + addr - va: ra + addr - va + n]
    raise SystemExit(f"{addr:#x}: not in the raw image")


def dis(addr, n=40):
    import capstone
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    for k, i in enumerate(md.disasm(read(addr, 16 * n), addr)):
        if k >= n:
            break
        print(f"{i.address:08x}  {i.bytes.hex():<20} {i.mnemonic} {i.op_str}")


PRE = """.intel_syntax noprefix
.code32
.set ORG, {org}
start:
.macro CALLA t
 .byte 0xe8
 .long \\t - ORG - (. + 4 - start)
.endm
.macro JMPA t
 .byte 0xe9
 .long \\t - ORG - (. + 4 - start)
.endm
"""


def asm(addr, src):
    with tempfile.TemporaryDirectory() as t:
        s, o = os.path.join(t, "c.s"), os.path.join(t, "c.o")
        open(s, "w").write(PRE.format(org=hex(addr)) + src + "\n")
        subprocess.run(["clang", "-target", "i686-linux-gnu", "-c", s, "-o", o], check=True)
        return elf_text(open(o, "rb").read()).hex()


def elf_text(e):
    shoff, = struct.unpack_from("<I", e, 0x20)
    shentsize, shnum, shstrndx = struct.unpack_from("<HHH", e, 0x2E)
    sh = [struct.unpack_from("<IIIIII", e, shoff + i * shentsize) for i in range(shnum)]
    stro = sh[shstrndx][4]
    for name, typ, flags, a, off, size in sh:
        if e[stro + name: e.index(b"\0", stro + name)] == b".text":
            if any(s[1] == 9 for s in sh):   # SHT_REL: an unresolved symbol would be silently wrong
                raise SystemExit("asm: relocations left (use CALLA/JMPA for absolute targets)")
            return e[off: off + size]
    raise SystemExit("asm: no .text")


if __name__ == "__main__":
    a = sys.argv
    if a[1] == "dis":
        dis(int(a[2], 16), int(a[3]) if len(a) > 3 else 40)
    elif a[1] == "asm":
        print(asm(int(a[2], 16), sys.stdin.read() if a[3] == "-" else open(a[3]).read()))
    elif a[1] == "free":
        b = read(int(a[2], 16), int(a[3]))
        print("free" if set(b) <= {0xCC, 0x90} else "USED: " + b.hex())
