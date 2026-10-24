#!/bin/bash
# step.sh WAIT key... : press each key (2 s apart), wait WAIT s, shot to /root/wine/last.png
w=$1; shift; for k in "$@"; do /root/wine/run.sh key $k; sleep 2; done; sleep $w; /root/wine/run.sh shot /root/wine/last.png
