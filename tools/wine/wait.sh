#!/bin/bash
# wait.sh SECS: wait on the pod, then shot to /root/wine/last.png and print the game state.
sleep $1; /root/wine/run.sh shot /root/wine/last.png; pgrep -f Speed.exe >/dev/null && echo RUNNING || echo DEAD; grep -v "^$" /root/wine/game.log | grep -v ChangeDisplay | tail -6
