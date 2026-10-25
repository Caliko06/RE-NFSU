#!/bin/sh
# Hopper instances in parallel, each bound to its own binary: HOP_DIR=<scratchpad> hpar.sh <topic> ...
# (tools/hopper/q_<topic>.py writes build/hopper/<topic>.txt ending in "DONE"). Replaces run.sh + drive.sh:
# - FACT 2026-10-25: HopperMCPServer binds to a random instance (drive.log: 1500/1501 "Document not found", up to
#   8 retries) and `-e exe -Y py` never runs the script; synthetic "Try the Demo" clicks hit whatever panel is in
#   front (launch.log: "clicked True, panel gone False").
# - Here: `open -g -n -a` with no file; the new PID is the one not running before; the OWNER presses Try the Demo
#   (one instance at a time, so one dialog at a time); then ONE Apple event (send.js, HoppOpEx + EXPY + PE loader)
#   to that PID, never retried, so the binary is never opened twice. The script first checks that its document is
#   Speed_<topic>.exe, else it writes build/hopper/<topic>.wrong and does nothing.
# - Each instance is killed at DONE or 30 min (demo limit), only by its own PID. Waits while Pages free < 20000.
dir=${HOP_DIR:?set HOP_DIR to the scratchpad}; B=$(cd "$(dirname "$0")/../.." && pwd); cd "$B" || exit 1
pids=""
for t in "$@"; do
  q=$B/tools/hopper/q_$t.py; [ -f "$q" ] || { echo "hpar: no $q"; continue; }
  while [ "$(vm_stat | awk '/Pages free/ {gsub(/\./,""); print $3}')" -lt 20000 ]; do sleep 5; done
  exe=$dir/Speed_$t.exe; cp -c pc/Speed.exe "$exe"; rm -f "build/hopper/$t.txt" "build/hopper/$t.wrong"
  cat > "$dir/w_$t.py" <<EOF
import os
_p = Document.getCurrentDocument().getExecutableFilePath() or ''
if os.path.basename(_p) != 'Speed_$t.exe':
    open('$B/build/hopper/$t.wrong', 'w').write('WRONG DOC %s (wanted Speed_$t.exe)\n' % _p)
else:
    exec(compile(open('$q').read(), '$q', 'exec'))
EOF
  before=$(pgrep -x "Hopper Disassembler" | sort)
  open -g -n -a "/Applications/Hopper Disassembler.app"   # exact bundle: ~/Applications and ~/Desktop hold copies with the same id
  pid=""; for i in $(seq 40); do
    for p in $(pgrep -x "Hopper Disassembler"); do echo "$before" | grep -qx "$p" || pid=$p; done
    [ -n "$pid" ] && break; sleep 0.5
  done
  [ -n "$pid" ] || { echo "hpar: $t: no new Hopper process"; continue; }
  echo "Hopper $t PID $pid: presiona Try the Demo" >&2
  echo "$(date +%s) $pid $t" >> build/hopper/launch.log
  echo "hpar: $t: $(osascript -l JavaScript tools/hopper/send.js "$pid" "$exe" "$dir/w_$t.py" 900)"
  pids="$pids $pid:$t:$(date +%s)"
done
# Watch: kill each instance at DONE / .wrong / 30 min, only our PIDs.
while [ -n "$pids" ]; do
  left=""
  for e in $pids; do
    pid=${e%%:*}; r=${e#*:}; t=${r%%:*}; t0=${r#*:}
    if grep -q '^DONE' "build/hopper/$t.txt" 2>/dev/null || [ -f "build/hopper/$t.wrong" ] || [ $(( $(date +%s) - t0 )) -gt 1800 ] \
       || ! kill -0 "$pid" 2>/dev/null; then
      kill "$pid" 2>/dev/null
      echo "hpar: $t done: $(tail -1 "build/hopper/$t.txt" 2>/dev/null)$(cat "build/hopper/$t.wrong" 2>/dev/null)"
    else left="$left $e"; fi
  done
  pids=$left; [ -n "$pids" ] && sleep 10
done
exit 0
