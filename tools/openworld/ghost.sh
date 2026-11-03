#!/bin/sh
# One bounded native ghost run in WORLD: the game's autopilot drives. usage: ghost.sh <tag> [secs=240] [VAR=value ...] -> runs/w_<tag>/log.txt
tag=$1; secs=${2:-240}; shift; shift
R=$(cd "$(dirname "$0")/../.." && pwd); d=$R/runs/w_$tag
rm -rf "$d"; mkdir -p "$d"; ln -s "$R/game" "$d/game"; cp -R "$R/save" "$d/save"; cd "$d" || exit 1
~/.claude/hooks/macgate.sh
exec env RN_TURBO=1 RN_SECS="$secs" RN_SCREEN=640x480 RN_RASTER=1000000 RN_FLOWLOG=1 RN_SEED=1 RN_AUTOPILOT=1 RN_AILOG=1 RN_CARPOS=1 RN_RIVALLOG=1 RN_FREELOG=1 \
  RN_WORLD_DIR="$R/build/openworld" RN_POOL=1 RN_TRAFMODELS=1 RN_TRAFREFILL=1 RN_FREETMOVE=0 RN_JUMP=3:1010 \
  RN_KEYS='20000:RETURN,3000@!MU_UG_NewOrLoad_PC2:RETURN,3000@!MU_UG_NewOrLoad_PC2:RETURN,3000@!MU_UG_NewOrLoad_PC2:RETURN,3000@!MU_UG_NewOrLoad_PC2:RETURN,1500@=MU_UG_NewOrLoad_PC2:RETURN,1500@=MU_Main_PC:RETURN,3000@6:RETURN,3000@6:RETURN' \
  "$@" nice -n 5 "$R/build/speed" "$R/pc/Speed.exe" game --shot shot.png > log.txt 2>&1 < /dev/null
