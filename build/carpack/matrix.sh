#!/bin/zsh
# Car Look Pack acceptance matrix (docs/SCOPE_CARS.md): one Chrome run per cell, in order, each <= 4 min, waits for load < 6.
# usage: matrix.sh [cell-name-regex] [cps, default "0 1"]      PNG per cell -> build/carpack/matrix/<cell>_cp0.png / _cp1.png (+ .out)
# Race cells: the player's car is ?car=MODEL:tier:n (RN_CAR, host/rivals.c; n = persona, paint listed by RN_CARLIST), shot 5 s after the
# race HUD (3 s caught race_sky_stock cp0 while the camera was still on the start line, no player car in frame) (RN_AFTER_HUD). Garage cells: ?env=RN_OPEN opens Car Customize from the main menu (host/input.c), ?keys= is the
# tools/completion.py 'garage' row (profile screens, then Visual > Body kit, 4 parts); RN_SHOT_FE takes shots 3, 8, 13 s after each new
# front-end screen into <cell>_cp<N>.fe/ (the car turns in the garage: those are the front/side/rear views).
cd /Users/angeldamian/RE-NFSU; mkdir -p build/carpack/matrix
B="http://127.0.0.1:5180/?x=1$XQ"   # XQ: extra query for a variant, SFX: suffix of the output names
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
  "world_night|&world=1&jump=3:1001|world|300"
  "garage_stock|$OPEN&keys=$PROFILE|fe|110"
  "garage_kit|$OPEN&keys=$KIT|fe|170"
)
# world: the Free Run shows an EA Trax banner first, so the shot is 14 s after the HUD, with the longer 330 s alarm
run(){ n=$1; q=$2; kind=$3; secs=$4; cp=$5
  while [ "$(uptime | sed 's/.*averages: //;s/\..*//')" -ge 6 ]; do sleep 10; done
  ~/.claude/hooks/macgate.sh
  out=build/carpack/matrix/${n}${SFX}_cp$cp
  if [[ $kind == fe ]]; then
    mkdir -p $out.fe
    RN_SHOT_FE=$out.fe RN_SHOT_FE_AT=3,8,13 RN_VIEW=1920x1080@1 perl -e 'alarm 240; exec @ARGV' node tools/webcheck.mjs "$B$q&carpack=$cp" $secs $out.png "" > $out.out 2>&1
    # keep the Car Customize / garage views only, at 1280 px (each cell was 42 MB, the disk is nearly full)
    for f in $out.fe/*.png; do [[ $f == *Customize* || $f == *Garage* ]] && sips -Z 1280 $f >/dev/null || rm -f $f; done
  elif [[ $kind == world ]]; then
    RN_VIEW=1920x1080@1 RN_AFTER_HUD=14 perl -e 'alarm 330; exec @ARGV' node tools/webcheck.mjs "$B$q&carpack=$cp" $secs $out.png "$RACEKEYS" > $out.out 2>&1
  else
    RN_VIEW=1920x1080@1 RN_AFTER_HUD=5 perl -e 'alarm 240; exec @ARGV' node tools/webcheck.mjs "$B$q&carpack=$cp" $secs $out.png "$RACEKEYS" > $out.out 2>&1
  fi
  echo "$n cp$cp done: $(python3 build/carbright/measure.py $out.png 2>&1 | tail -1)"; }
for c in $CELLS; do
  IFS='|' read n q kind secs <<< "$c"
  [[ -n "$1" && ! $n =~ $1 ]] && continue
  for cp in ${=2:-0 1}; do run $n "$q" $kind $secs $cp; done
done
