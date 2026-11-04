#!/usr/bin/env python3
"""Assemble tools/recomp/caves/road.s: each '# @ name addr' starts a snippet. Prints name, address, hex, and the combined
hex of the whole code area (cc between snippets), the string patches.py keeps as _ROAD_CODE."""
import os, re, sys
sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
import asm
src = open(os.path.join(os.path.dirname(os.path.abspath(__file__)), "road.s")).read()
parts = re.split(r"^# @ (\w+) (0x[0-9a-f]+)\n", src, flags=re.M)[1:]
base, out = None, b""
for name, addr, body in zip(parts[0::3], parts[1::3], parts[2::3]):
    a = int(addr, 16)
    base = a if base is None else base
    out += b"\xcc" * (a - base - len(out))
    h = asm.asm(a, body)
    print(f"{name} {addr} {len(h) // 2} bytes", file=sys.stderr)
    out += bytes.fromhex(h)
print(hex(base), len(out))
print(out.hex())
