#!/bin/sh
# HDR reflection probes (bake.py probes: 1024 wide equirect, 1024 samples, every 10 m), one run after another.
# Run from the dir that holds mesh2/, albedo.tsv, scene.json, out/. usage: setsid nohup probes.sh BLENDER RUN... &
B=$1; shift
for r in "$@"; do
  [ -e out/probes1024.$r.npz ] || $B -b -t 2 --python $(dirname $0)/bake.py -- probes out/probes1024.$r.npz 0/1 1024 1024 mesh2/$r.npz albedo.tsv scene.json $r > out/probes1024.$r.log 2>&1
done
echo PROBES-DONE >> out/probes1024.done
