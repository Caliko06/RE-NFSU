#!/bin/sh
# Ghidra queries in parallel: gpar.sh <plan.txt> ... -> <plan>.out next to each plan (Query.java plan lines).
# FACT 2026-10-25: two analyzeHeadless on build/rea/proj fail "Unable to lock project" even with -readOnly, so each
# plan gets its own APFS clone of the project (cp -c, 92 MB, no extra disk; 2 plans in 3.3 s, ~300 MB RSS each).
# Waits while Pages free < 20000 (vm_stat) before each start.
# Linux pod: Ghidra in /root/ghidra, JDK 21 on PATH, the analyzed project in $GHIDRA_PROJ (default /root/ghidra_proj, copied from the Mac's build/ghidra/proj).
if [ "$(uname)" = Darwin ]; then
  export JAVA_HOME=/opt/homebrew/opt/openjdk@21/libexec/openjdk.jdk/Contents/Home
  export PATH=$JAVA_HOME/bin:$PATH
  H=/opt/homebrew/Cellar/ghidra/12.1.4/libexec/support/analyzeHeadless
else
  H=/root/ghidra/ghidra_12.1.4_PUBLIC/support/analyzeHeadless
  export JAVA_TOOL_OPTIONS="-Duser.name=${GHIDRA_USER:-angeldamian}"   # the project records its creator; headless refuses another user
fi
B=$(cd "$(dirname "$0")/../.." && pwd); T=$(mktemp -d "${TMPDIR:-/tmp}/gpar.XXXX")
P=${GHIDRA_PROJ:-$B/build/ghidra/proj}
cl() { if [ "$(uname)" = Darwin ]; then cp -c -R "$1" "$2"; else cp -R "$1" "$2"; fi; }
lowmem() { [ "$(uname)" = Darwin ] && [ "$(vm_stat | awk '/Pages free/ {gsub(/\./,""); print $3}')" -lt 20000 ]; }
for plan in "$@"; do
  plan=$(cd "$(dirname "$plan")" && pwd)/$(basename "$plan"); out=${plan%.txt}.out; n=$(basename "${plan%.txt}")
  while lowmem; do sleep 5; done
  cl "$P" "$T/$n"
  ( "$H" "$T/$n" nfsu -process Speed.exe -noanalysis -readOnly -scriptPath "$B/tools/ghidra" \
      -postScript Query.java "$plan" "$out" > "$T/$n.log" 2>&1
    grep -q "Unable to lock\|ERROR Abort" "$T/$n.log" && echo "gpar: $n FAILED, see $T/$n.log" || echo "gpar: $n -> $out ($(grep -c '^===' "$out") queries)"
    rm -rf "$T/$n" ) &
done
wait
