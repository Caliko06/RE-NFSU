#!/bin/bash
# GI passes b/s/u + reflection probes for every run with a geodump: mesh2/<run>.npz (geo2mesh with w.col/w.ttk, CPU, 4 at
# once) -> out/gi.<pass>.<run>.npz and out/probes.<run>.npz (bake.py, GPU, $P Blender processes at once).
# SKIP="run ...": no probes for those runs (another Pod bakes them). Needs /root/ao/albedo.tsv and scene.json (tools/ao/scene.py on the Mac). usage: setsid nohup gi.sh [P] [SAMPLES] &
cd /root/ao; R=/root/RE-NFSU; P=${1:-8}; N=${2:-1024}; mkdir -p mesh2 out
runs=$(for g in $R/runs/*/save/geodump; do r=$(basename $(dirname $(dirname $g))); grep -q "\"$r\"" scene.json && echo $r; done)
for r in $runs; do [ -e mesh2/$r.npz ] || echo $r; done | xargs -P 4 -I{} sh -c "cd $R && nice .venv/bin/python tools/ao/geo2mesh.py /root/ao/mesh2/{}.npz runs/{}/save/geodump/*.bin >> /root/ao/out/gi.log 2>&1"
runs=$(ls mesh2 | sed 's/[.]npz$//')   # a matrix rerun deletes its run dir; the mesh stays
for r in $runs; do echo " $SKIP " | grep -q " $r " || echo "probes $r 1024 1024"; for p in b s u; do echo "gi $r $N $p"; done; done |
  xargs -P $P -L 1 sh -c 'o=out/$0.$1.npz; [ $0 = gi ] && o=out/gi.$3.$1.npz; [ -e $o ] || blender-4.2.3-linux-x64/blender -b -t 2 --python '$R'/tools/ao/bake.py -- $0 $o 0/1 $2 $3 mesh2/$1.npz albedo.tsv scene.json $1 > $o.log 2>&1'
echo GI-DONE >> out/gi.log
