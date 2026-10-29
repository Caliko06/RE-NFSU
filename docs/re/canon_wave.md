# Naming waves (Sonnet orchestrator + sonnet-exec workers)

Method, grades and measured precision: docs/re/canon_db.md. Context is the cost: nobody opens census/canon/c/*.c,
funcs.jsonl or queue.tsv whole; `canon.py show` and `canon.py batch` print only what a batch needs.

## Orchestrator, one round
1. `.venv/bin/python tools/canon/canon.py queue` (prints per-system total/done/ready/blocked; read only that table).
2. Pick up to 3 systems with the most ready rows (never online). For each: `canon.py batch <system> 60`.
3. Launch one `sonnet-exec` per system in parallel with the worker brief below (systems disjoint = files disjoint).
4. When all return: check each report against "Done when", then `canon.py apply && canon.py export -j 4 && canon.py queue`
   (only the orchestrator runs these: one Ghidra project, one writer), then `tools/census/scoreboard.py`.
5. Commit with exact paths (`git add census/names_<system>.tsv ...`, never -A), one line to docs/re/night_log.md.
6. After 3 rounds, or when context passes ~60 %: write HANDOFF.md and message the Opus session the round summary.

## Worker brief (paste with <system> filled)
Objective: name the 60 functions in build/canon/batch_<system>.txt with evidence.
Context: docs/re/canon_wave.md (this file), docs/re/canon_db.md "GameCube alignment" grades.
Read the batch with `.venv/bin/python tools/canon/canon.py show @build/canon/batch_<system>.txt` (named pseudocode +
index line: size, callers, prior hint, strings, globals). Read more of one function only with `canon.py show <addr>`.
Full GC signatures: `grep '<Name>__' build/prior/nfsug/symbols.txt`.
Scope: append rows only to census/names_<system>.tsv (columns addr name system confidence evidence tool doc).
Per function:
- Prior hint fits the code (strings, callees, field use, argument count vs the GC signature): GC name as
  `Class::method`, confidence high, evidence `V: <what matches>`, tool `ghidra-canon+nfsug`.
- Hint does not fit, or no hint: name from the code, confidence med (read and clear) or low (guess), evidence says why
  in one clause; a rejected hint is named in the evidence (`rejected B Foo::Bar: no string`).
- Trivial (EH funclet, thunk, getter, scalar deleting destructor): one row, evidence starts `trivial:`.
Done when: every address of the batch has one row, each row has 7 columns, no address repeats one already in another
census/names_*.tsv (`grep -h <addr> census/names_*.tsv`).
Limits: no canon.py apply/export/queue, no commit, no game runs, no deletes. A hint wrong twice in one source file:
stop trusting hints in that file.
Report (<= 10 lines): rows written, hints taken/rejected per grade, anything odd.
