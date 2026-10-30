#!/bin/sh
# Decompiles the traffic and rival AI functions of docs/openworld/re_traffic_rivals.md. Usage: decomp_traffic.sh <work dir> [out.c]
# The first run imports and analyses pc/Speed.exe into <work dir>; the census export split or misses most of these.
W=$1; O=${2:-$W/traffic_decomp.c}; G=${GHIDRA:-/root/ghidra/ghidra_12.1.4_PUBLIC}/support/analyzeHeadless
A="0x451230 0x4522a0 0x450ec0 0x450bb0 0x450730 0x452710 0x452630 0x451b00 0x44ed70 0x44c2e0 0x453c60 0x583350 0x583700 0x583910 0x582f90
   0x5a6b00 0x59c210 0x5832a0 0x429100 0x462b30 0x462840 0x4623d0 0x44e020 0x44e140 0x45ae10 0x450210 0x59b3e0 0x59aa60 0x4b3ac0 0x4322a0 0x44f470 0x5a6ef0"
if [ -d "$W/nfsu.rep" ]; then S="-process Speed.exe -noanalysis -readOnly"; else mkdir -p "$W"; S="-import pc/Speed.exe -overwrite"; fi
exec "$G" "$W" nfsu $S -scriptPath tools/ghidra -postScript DecompAt.java "$O" $A
