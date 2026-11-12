#!/bin/zsh
# Opens the two Agencia windows (AGENTS.md "Agencia"): Fable on account 3, Opus 5.5 on account 7, both in the main repo.
# Recipe from the agency-windows memory: clean Claude env vars, then claude-acc in a new Ghostty window, no initial prompt.
for spec in "3 claude-fable-5-2 nfsu-fable" "7 claude-opus-5-5 nfsu-opus"; do
  set -- ${=spec}
  f=/tmp/agencia-$3.sh
  print -r -- "unset -m 'CLAUDE*'; cd /Users/angeldamian/RE-NFSU && claude-acc open $1 --model $2 --effort high -n $3" > $f
  open -na Ghostty --args -e zsh $f
done
