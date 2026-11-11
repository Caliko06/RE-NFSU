"""xref finder for SPEED2.EXE: python3 ug2_xref.py 0x7a0b70 [more VAs]  (byte search of the imm32 in .text/.rdata/.data)"""
import sys, struct
E = "/Users/angeldamian/RE-NFSU/pc/ug2/SPEED2.EXE"
d = open(E, "rb").read()
for a in sys.argv[1:]:
    v = int(a, 16); pat = struct.pack('<I', v); p = 0; out = []
    while True:
        p = d.find(pat, p)
        if p < 0: break
        out.append(hex(p + 0x400000)); p += 1
    print(a, out)
