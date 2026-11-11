#!/bin/sh
# d.sh START STOP : objdump SPEED2.EXE compact
E=/Users/angeldamian/RE-NFSU/pc/ug2/SPEED2.EXE
objdump -d -M intel --start-address=$1 --stop-address=$2 $E | tail -n +8 | cut -c1-120 | sed 's/^ *//;s/\t/ /g' | sed -E 's/^([0-9a-f]+): ([0-9a-f ]+)  +/\1 /;s/ <\.text[^>]*>//'
