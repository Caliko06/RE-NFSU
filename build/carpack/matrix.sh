#!/bin/zsh
# Car Look Pack acceptance matrix (docs/SCOPE_CARS.md): one Chrome run per cell, in order, each <= 4 min, waits for load < 6.
# usage: matrix.sh [cell-name-regex]      PNG per cell -> build/carpack/matrix/<cell>_cp0.png / _cp1.png (+ .out)
# Race cells: the player's car is ?car=MODEL:tier:n (RN_CAR, host/rivals.c; n = persona, paint listed by RN_CARLIST), shot 3 s after the
# race HUD (RN_AFTER_HUD). Garage cells: ?env=RN_OPEN opens Car Customize from the main menu (host/input.c), ?keys= is the
# tools/completion.py 'garage' row (profile screens, then Visual > Body kit, 4 parts); RN_SHOT_FE takes shots 3, 8, 13 s after each new
# front-end screen into <cell>_cp<N>.fe/ (the car turns in the garage: those are the front/side/rear views).
cd /Users/angeldamian/RE-NFSU; mkdir -p build/carpack/matrix
B="http://127.0.0.1:5180/?x=1"
RACEKEYS='20:Enter,23:Enter,26:ArrowRight,29:Enter,32:Enter,35:Enter,38:Enter,44:Enter,50:Enter,58:Enter,66:Enter,74:Enter'
PROFILE='0:RETURN,3000@!MU_UG_NewOrLoad_PC2:RETURN,3000@!MU_UG_NewOrLoad_PC2:RETURN,3000@!MU_UG_NewOrLoad_PC2:RETURN,3000@!MU_UG_NewOrLoad_PC2:RETURN,1500@=MU_UG_NewOrLoad_PC2:RETURN'
KIT="$PROFILE,1500@=MU_MainMenuCarCustomize:RETURN,1500@=MU_Garage:RETURN,1500@=MU_GaragePartsChooseVisual:RETURN,1500@=MU_GaragePartsCategoryVisual:RETURN,3000@!NONE:RIGHT,3000@!NONE:RIGHT,3000@!NONE:RIGHT,3000@!NONE:RIGHT"
OPEN='&env=RN_OPEN=MU_Main_PC%3EMU_MainMenuCarCustomize:20,RN_FLOWLOG=1'
# name|query|keys (race: RACEKEYS) |secs
CELLS=(
  "race_sky_stock|&car=SKYLINE:1|race|150"
  "race_sky_kit|&car=SKYLINE:3|race|150"
  "race_tiburon|&car=TIBURON:3|race|150"
  "race_dark|&car=INTEGRA:3:2|race|150"
  "race_light|&car=RSX:3:2|race|150"
  "world_night|&world=1&jump=3:1001|race|150"
  "garage_stock|$OPEN&keys=$PROFILE|fe|110"
  "garage_kit|$OPEN&keys=$KIT|fe|170"
)
run(){ n=$1; q=$2; kind=$3; secs=$4; cp=$5
  while [ "$(uptime | sed 's/.*averages: //;s/\..*//')" -ge 6 ]; do sleep 10; done
  ~/.claude/hooks/macgate.sh
  out=build/carpack/matrix/${n}_cp$cp
  if [[ $kind == fe ]]; then
    mkdir -p $out.fe
    RN_SHOT_FE=$out.fe RN_SHOT_FE_AT=3,8,13 RN_VIEW=1920x1080@1 perl -e 'alarm 240; exec @ARGV' node tools/webcheck.mjs "$B$q&carpack=$cp" $secs $out.png "" > $out.out 2>&1
  else
    RN_VIEW=1920x1080@1 RN_AFTER_HUD=3 perl -e 'alarm 240; exec @ARGV' node tools/webcheck.mjs "$B$q&carpack=$cp" $secs $out.png "$RACEKEYS" > $out.out 2>&1
  fi
  echo "$n cp$cp done: $(python3 build/carbright/measure.py $out.png 2>&1 | tail -1)"; }
for c in $CELLS; do
  IFS='|' read n q kind secs <<< "$c"
  [[ -n "$1" && ! $n =~ $1 ]] && continue
  run $n "$q" $kind $secs 0; run $n "$q" $kind $secs 1
done
