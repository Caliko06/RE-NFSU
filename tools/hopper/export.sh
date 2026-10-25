#!/bin/sh
# Hopper export of every procedure of pc/Speed.exe -> census/hopper/decomp.c + funcs.tsv (grep it before any Ghidra query).
# usage: HOP_DIR=<scratchpad> tools/hopper/export.sh [CHUNKS=6]   (hpar.sh runs the chunks on up to 6 windows)
# A chunk whose window stalls (a decompile that hangs Hopper) is run again; it resumes after the hung procedure.
N=${1:-6}; B=$(cd "$(dirname "$0")/../.." && pwd); cd "$B" || exit 1
topics=""; k=0
mkdir -p build/hopper census/hopper
while [ $k -lt "$N" ]; do
  t=exp$(printf %02d $k)
  sed -e "s|^OUT = .*|OUT = '$B/build/hopper/$t.txt'|" -e "s|^K, N = .*|K, N = $k, $N|" tools/hopper/q_export.py > tools/hopper/q_$t.py
  rm -f build/hopper/$t.txt; topics="$topics $t"; k=$((k + 1))
done
left=$topics; round=0
while [ -n "$left" ] && [ $round -lt 40 ]; do
  HOP_STALL=${HOP_STALL:-90} HOP_KEEP=1 tools/hopper/hpar.sh $left | grep -E 'stalled|no new Hopper|wrong'
  left=""; for t in $topics; do grep -q '^DONE' build/hopper/$t.txt 2>/dev/null || left="$left $t"; done
  round=$((round + 1)); echo "export: round $round, left:${left:- none}"
done
for t in $topics; do rm -f tools/hopper/q_$t.py; done
.venv/bin/python tools/hopper/export_merge.py build/hopper census/hopper $topics
