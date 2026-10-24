#!/bin/bash
# Pod: one race of the Wine reference from boot. usage: race.sh OUT.mp4 SECS KEY...  (xdotool names: Return Left Right Up Down)
# Boots the game, waits for the title, taps the keys 3 s apart (the front end draws the RNG only on events, not per frame:
# RN_RNGLOG, 2026-10-24, so seconds are enough), starts the 60 fps recording just before the last key, stops the game.
cd /root/wine
./run.sh start 1280x960 > /dev/null
sleep 22
n=$#; out=$1; secs=$2; shift 2
while [ $# -gt 1 ]; do ./run.sh key $1; sleep 2.3; shift; done
DISPLAY=:77 ./rec.sh $secs $out 1280x960 &
rec=$!
sleep 0.5; ./run.sh key $1
wait $rec
./run.sh stop
