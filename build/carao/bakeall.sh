#!/bin/zsh
# Bake every car with kit parts: prep.py -> bake_car.py (Blender Cycles, Metal), all four LODs + wide-body kits. 600 s cap per car.
# usage: bakeall.sh [SAMPLES]   (default 4096, distance 1.0 m like the 17 race rows)
cd "$(dirname "$0")"; S=${1:-4096}; export LODS=${LODS:-ABCD}
for c in 240SX 350Z CELICA CIVIC ECLIPSE FOCUS GOLF IMPREZA INTEGRA LANCER MIATA NEON PEUGOT RSX RX7 S2000 SENTRA SKYLINE SUPRA TIBURON; do
  python3 prep.py $c out/$c.in.npz | tail -1
  t=$(date +%s); perl -e 'alarm 600; exec @ARGV' /Applications/Blender.app/Contents/MacOS/Blender -b -t 1 --python bake_car.py -- out/$c.in.npz out/$c.ao.npz $S ${DIST:-1.0} 2>&1 | grep -E "^j[0-9]+ parts|Error|Traceback" > out/$c.log
  echo "$c bake $(( $(date +%s) - t )) s, $(du -k out/$c.ao.npz | cut -f1) KB, $(grep -c parts out/$c.log) assemblies"
done
