#!/bin/bash
# Pod: the M8.6 matrix rows on the Wine reference, one at a time (one wineserver, one display). Each row boots the parity
# exe of its seed (mkexe.py --set parity --seed K --autopilot -> /root/wine/ap<K>/Speed.exe), drives the same menu path as
# tools/completion.py, waits for the race to end (no flow log here: by time), tries the exit keys of its variant, then
# RETURNs for the next race. A WebP shot every 15 s -> /root/wine/runs/<row>.<seed>/<s>.webp.
# Atlantica is locked on Wine (our PATCH 0x735ec1 is not in the exe): Olympic Square = one Left on SELECT LOCATION.
# usage: matrix.sh ROW.SEED ...   (rows: circuit sprint drag drift lapko freerun; under nohup)
cd /root/wine
PY=/root/RE-NFSMW/build/upvenv/bin/python
cp -n NFSU/Speed.exe Speed.plain.exe
declare -A MODE=([circuit]=0 [sprint]=1 [drag]=2 [drift]=3 [lapko]=4 [freerun]=5)
EXIT=("Return q Return Return" "Return Escape Return Return" "q Return q Return")
SEEDS=(0x1234 0x5678 0x9abc)
for run in "$@"; do
  row=${run%.*}; seed=${run#*.}; d=/root/wine/runs/$run
  for i in 0 1 2; do [ ${SEEDS[$i]} = $seed ] && v=$i; done
  rm -rf $d; mkdir -p $d
  cp ap$seed/Speed.exe NFSU/Speed.exe
  ./run.sh start 1280x960 > /dev/null
  ( for s in $(seq 15 15 900); do sleep 15; DISPLAY=:77 import -window root $d/$s.png 2>/dev/null &&
      $PY -c "import sys; from PIL import Image; Image.open(sys.argv[1]).save(sys.argv[1][:-4] + '.webp', quality=80)" $d/$s.png && rm $d/$s.png
    done ) &
  shots=$!
  sleep 45   # the intro movies (THX, EA logo) and the title
  keys="Return Return Right Return $(printf 'Down %.0s' $(seq 1 ${MODE[$row]})) Return Return Return Left Return Return Return Return"
  for k in $keys; do ./run.sh key $k; sleep 2.3; done
  sleep 330  # the race (native circuit: 3:01 race time, plus the countdown)
  for k in ${EXIT[$v]}; do ./run.sh key $k; sleep 3; done
  sleep 10
  for i in $(seq 10); do ./run.sh key Return; sleep 3; done
  sleep 300
  kill $shots 2>/dev/null
  ./run.sh stop
  grep -v "^$" game.log | grep -v ChangeDisplay | tail -20 > $d/game.log
  echo "$run done $(date +%T)"
done
cp Speed.plain.exe NFSU/Speed.exe
