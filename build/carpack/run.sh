#!/bin/zsh
# One Chrome run of the build/carbright scene. usage: run.sh <name> "<query>"   (<=4 min, waits for load < 6, CDP 9381)
cd /Users/angeldamian/RE-NFSU
KEYS='20:Enter,23:Enter,26:ArrowRight,29:Enter,32:Enter,35:Enter,38:Enter,44:Enter,50:Enter,58:Enter,66:Enter,74:Enter'
while [ "$(uptime | sed 's/.*averages: //;s/\..*//')" -ge 6 ]; do sleep 10; done
~/.claude/hooks/macgate.sh
RN_VIEW=1920x1080@1 RN_AFTER_HUD=3 perl -e 'alarm 240; exec @ARGV' node tools/webcheck.mjs "http://127.0.0.1:5180/?x=1$2" 150 build/carpack/$1.png "$KEYS" > build/carpack/$1.out 2>&1
python3 build/carbright/measure.py build/carpack/$1.png
