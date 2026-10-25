#!/bin/bash
# Every run with a geodump -> mesh/<run>.npz (geo2mesh, CPU) -> out/world.<run>.npz + out/cars.<run>.npz (bake.py, GPU),
# up to 4 bakes at once. Polls for new runs until the completion queue is gone. usage: setsid nohup all.sh &
cd /root/ao; B=blender-4.2.3-linux-x64/blender; R=/root/RE-NFSU
while :; do
  pgrep -f tools/completion.py >/dev/null && q=1 || q=0
  for g in $R/runs/*/save/geodump; do
    run=$(basename $(dirname $(dirname $g))); [ -e out/world.$run.npz -o -e out/$run.skip ] && continue
    [ $q = 1 ] && ! grep -q ^RN_SECS $R/runs/$run/log.txt 2>/dev/null && continue   # row still running
    [ -e mesh/$run.npz ] || (cd $R && .venv/bin/python tools/ao/geo2mesh.py /root/ao/mesh/$run.npz $g/*.bin) >> out/all.log 2>&1 || { touch out/$run.skip; continue; }   # no race frame
    while [ $(pgrep -c -f "bake.py") -ge 4 ]; do sleep 5; done
    ( $B -b -t 1 --python $R/tools/ao/bake.py -- world out/world.$run.npz 0/1 4096 4.0 mesh/$run.npz > out/world.$run.log 2>&1
      $B -b -t 1 --python $R/tools/ao/bake.py -- cars out/cars.$run.npz 0/1 4096 1.0 mesh/$run.npz > out/cars.$run.log 2>&1 ) &
    sleep 2
  done
  [ $q = 1 ] || { wait; echo ALL-DONE >> out/all.log; exit; }
  sleep 120
done
