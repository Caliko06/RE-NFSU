#!/bin/sh
# Lightmap GI (bake.py lightmap: passes b/s/u to SIZE x SIZE images) for every mesh2/ run, $P Blender at once, biggest first.
# Run from the dir that holds mesh2/, albedo.tsv, scene.json, out/. usage: setsid nohup lightmap.sh BLENDER [P] [SIZE] [SAMPLES] &
B=$1; P=${2:-4}; W=${3:-2048}; N=${4:-1024}; T=$(dirname $(readlink -f $0)); O=lm$W; [ $N = 1024 ] || O=lm${W}s$N   # lm4096 = 4096 spp (first run)
ls -S mesh2 | sed 's/[.]npz$//' | xargs -P $P -I{} sh -c "[ -e out/$O.{}.npz ] || $B -b -t 2 --python $T/bake.py -- lightmap out/$O.{}.npz 0/1 $N $W mesh2/{}.npz albedo.tsv scene.json {} > out/$O.{}.log 2>&1"
echo LM-DONE >> out/$O.done
