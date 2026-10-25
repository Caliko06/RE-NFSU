#!/bin/sh
# Hopper in parallel, one click per window: HOP_DIR=<scratchpad> [HOP_WIN=3] hpar.sh <topic> ...
# (tools/hopper/q_<topic>.py writes build/hopper/<topic>.txt ending in "DONE", then closes its document).
# - HOP_WIN windows (default 3) open one at a time from the exact bundle /Applications/Hopper Disassembler.app
#   (~/Applications and ~/Desktop hold copies with the same id); the new PID is the one not running before.
#   The OWNER presses "Try the Demo" ONCE per window.
# - Topics go round-robin to the windows; in each window they run one after another: when a topic ends (DONE or
#   .wrong), the next is sent to the SAME PID (no relaunch, no new click). A topic is not started with less than
#   8 min left of the window's 30 min demo; at 30 min or with no topics left, the window is killed (only our PIDs).
# - Each topic: ONE Apple event (send.js: HoppOpEx + EXPY, loader WinPE; "PE" opens the Loader dialog) to that PID,
#   never retried, so a binary is never opened twice. The script first checks its document is Speed_<topic>.exe,
#   else it writes build/hopper/<topic>.wrong and does nothing.
# - Waits while vm_stat Pages free < 20000 before opening a window.
dir=${HOP_DIR:?set HOP_DIR to the scratchpad}; win=${HOP_WIN:-3}; B=$(cd "$(dirname "$0")/../.." && pwd); cd "$B" || exit 1
APP="/Applications/Hopper Disassembler.app"; LIFE=1800; MINLEFT=480

prep() {    # topic -> exe copy + wrapper script that checks the document
  t=$1; q=$B/tools/hopper/q_$t.py; [ -f "$q" ] || { echo "hpar: no $q"; return 1; }
  cp -c pc/Speed.exe "$dir/Speed_$t.exe"; rm -f "build/hopper/$t.txt" "build/hopper/$t.wrong"
  cat > "$dir/w_$t.py" <<EOF
import os
_p = Document.getCurrentDocument().getExecutableFilePath() or ''
if os.path.basename(_p) != 'Speed_$t.exe':
    open('$B/build/hopper/$t.wrong', 'w').write('WRONG DOC %s (wanted Speed_$t.exe)\n' % _p)
else:
    exec(compile(open('$q').read(), '$q', 'exec'))
EOF
}

window() {  # topics of one window, run in sequence on one PID
  pid=$1; t0=$2; shift 2
  for t in "$@"; do
    left=$(( LIFE - ($(date +%s) - t0) ))
    [ $left -ge $MINLEFT ] || { echo "hpar: PID $pid: $t not started ($left s left; run it in a new window)"; continue; }
    kill -0 "$pid" 2>/dev/null || { echo "hpar: PID $pid gone: $t not started"; continue; }
    prep "$t" || continue
    echo "hpar: PID $pid: $t: $(osascript -l JavaScript tools/hopper/send.js "$pid" "$dir/Speed_$t.exe" "$dir/w_$t.py" 900)"
    while ! grep -q '^DONE' "build/hopper/$t.txt" 2>/dev/null && [ ! -f "build/hopper/$t.wrong" ] \
          && [ $(( $(date +%s) - t0 )) -lt $LIFE ] && kill -0 "$pid" 2>/dev/null; do sleep 5; done
    echo "hpar: PID $pid: $t done: $(tail -1 "build/hopper/$t.txt" 2>/dev/null)$(cat "build/hopper/$t.wrong" 2>/dev/null)"
    sleep 3    # the script closes its document; give Hopper a moment before the next open
  done
  kill "$pid" 2>/dev/null
}

i=0
while [ $i -lt "$win" ] && [ $i -lt $# ]; do
  topics=""; k=0
  for t in "$@"; do [ $((k % win)) -eq $i ] && topics="$topics $t"; k=$((k + 1)); done
  while [ "$(vm_stat | awk '/Pages free/ {gsub(/\./,""); print $3}')" -lt 20000 ]; do sleep 5; done
  before=$(pgrep -x "Hopper Disassembler")
  open -g -n -a "$APP"; t0w=$(date +%s)
  pid=""; for n in $(seq 40); do
    for p in $(pgrep -x "Hopper Disassembler"); do echo "$before" | grep -qx "$p" || pid=$p; done
    [ -n "$pid" ] && break; sleep 0.5
  done
  if [ -z "$pid" ]; then echo "hpar: window $i: no new Hopper process"; i=$((i + 1)); continue; fi
  echo "Hopper window $((i + 1)) PID $pid ($topics ): presiona Try the Demo" >&2
  echo "$(date +%s) $pid$topics" >> build/hopper/launch.log
  # The first send waits for the click (Apple event timeout 900 s); open the next window only after it, so the
  # OWNER sees one demo dialog at a time.
  first=${topics# }; first=${first%% *}; rest=${topics#* $first}
  prep "$first" && echo "hpar: PID $pid: $first: $(osascript -l JavaScript tools/hopper/send.js "$pid" "$dir/Speed_$first.exe" "$dir/w_$first.py" 900)"
  ( t0=$t0w
    while ! grep -q '^DONE' "build/hopper/$first.txt" 2>/dev/null && [ ! -f "build/hopper/$first.wrong" ] \
          && [ $(( $(date +%s) - t0 )) -lt $LIFE ] && kill -0 "$pid" 2>/dev/null; do sleep 5; done
    echo "hpar: PID $pid: $first done: $(tail -1 "build/hopper/$first.txt" 2>/dev/null)$(cat "build/hopper/$first.wrong" 2>/dev/null)"
    sleep 3
    window "$pid" "$t0" $rest ) &
  i=$((i + 1))
done
wait
exit 0
