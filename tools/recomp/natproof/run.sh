#!/bin/sh
# Native vs lifted proofs for host/native.h (D3DX 0x5c97cb in h.c, 0x5c85c1 in h2.c): random inputs, compare regs,
# flags, Ctx, memory and device calls. gen*.c = the lifted bodies frozen when the natives landed (40abbee, 8d07ff3).
# Run from the repo root after any change to host/native.h or host/rt.h:  sh tools/recomp/natproof/run.sh [cases]
set -e
B=build/natproof; mkdir -p $B; N=${1:-20000}
[ -f $B/img.bin ] || .venv/bin/python -c "
import sys; sys.path.insert(0, 'tools/recomp'); from lift import Lifter
open('$B/img.bin', 'wb').write(bytes(Lifter('pc/Speed.exe', {}).img))"
for h in h h2; do
  clang -O1 -w -Ihost -Itools/recomp/natproof -fno-strict-aliasing -o $B/$h tools/recomp/natproof/$h.c
  $B/$h $N $B/img.bin | tail -3
done
