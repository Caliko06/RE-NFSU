#!/bin/zsh
# Car Look Pack acceptance matrix (docs/SCOPE_CARS.md): one Chrome run per cell, in order, each <= 4 min, waits for load < 6.
# usage: matrix.sh [cell-name-regex]      PNG per cell -> build/carpack/matrix/<cell>_cp0.png / _cp1.png (+ .out, + fe shots)
# A cell = car pick (ArrowRight presses at t=26 in the Quick Race car list) x scene (query). carpack=0 vs 1 per cell.
# Race-start scenes are shot 3 s after the HUD (RN_AFTER_HUD); the garage cell takes one shot per front-end screen (RN_SHOT_FE).
cd /Users/angeldamian/RE-NFSU; mkdir -p build/carpack/matrix
B="http://127.0.0.1:5180/?x=1"
keys(){ # $1 = number of car-list presses
  k='20:Enter,23:Enter'; t=26; for i in $(seq 1 $1); do k="$k,$t:ArrowRight"; t=$((t+1)); done
  echo "$k,29:Enter,32:Enter,35:Enter,38:Enter,44:Enter,50:Enter,58:Enter,66:Enter,74:Enter"; }
# name|car presses|extra query
CELLS=(
  "race_car0||"
  "race_car1|1|"
  "race_car2|2|"
  "race_car3|3|"
  "race_car4|4|"
  "world_night|0|&world=1&jump=3:1001"
  "garage|0|&fe=1"
)
run(){ n=$1; presses=$2; q=$3; cp=$4
  while [ "$(uptime | sed 's/.*averages: //;s/\..*//')" -ge 6 ]; do sleep 10; done
  ~/.claude/hooks/macgate.sh
  extra=(); [[ $n == garage ]] && extra=(RN_SHOT_FE=build/carpack/matrix/${n}_cp$cp.fe)
  [[ $n == garage ]] && mkdir -p build/carpack/matrix/${n}_cp$cp.fe
  env $extra RN_VIEW=1920x1080@1 RN_AFTER_HUD=3 perl -e 'alarm 240; exec @ARGV' node tools/webcheck.mjs "$B$q&carpack=$cp" 150 \
    build/carpack/matrix/${n}_cp$cp.png "$(keys ${presses:-0})" > build/carpack/matrix/${n}_cp$cp.out 2>&1
  echo "$n cp$cp done: $(python3 build/carbright/measure.py build/carpack/matrix/${n}_cp$cp.png 2>&1 | tail -1)"; }
for c in $CELLS; do
  IFS='|' read n p q <<< "$c"
  [[ -n "$1" && ! $n =~ $1 ]] && continue
  run $n "$p" "$q" 0; run $n "$p" "$q" 1
done
