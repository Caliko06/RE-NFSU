# Naming waves (Sonnet orchestrator + sonnet-exec workers)

Method, grades and measured precision: docs/re/canon_db.md. Context is the cost: nobody opens census/canon/c/*.c,
funcs.jsonl or queue.tsv whole; `canon.py show` and `canon.py batch` print only what a batch needs.

## Orchestrator, one round
1. `.venv/bin/python tools/canon/canon.py queue` (prints per-system total/done/ready/blocked; read only that table).
2. Batches by GameCube source file (since round 5; system tags are graph guesses, files come from link order):
   `canon.py batchfile 60 1`, then `canon.py batchfile 60 2 <files of batch 1>`, then 3 skipping both (the skip list is
   comma-separated file paths, from the `# files:` header line). Functions without a GC file: `canon.py batch <system> 60`.
3. Launch one `sonnet-exec` per batch in parallel with the worker brief below (different files = no overlap); each worker
   writes only its own file `build/canon/out/<batch>.tsv` (batch name = the batch file name without `.txt`; no header, 7
   columns). No worker touches census/names_*.tsv. [Activation PENDING: start this at a round boundary with
   canon-sonnet-c1 idle; until then workers append to census/names_<system>.tsv as before.]
4. When all return: check each report against "Done when", then integrate (orchestrator only, one writer):
   `.venv/bin/python tools/canon/integrate.py build/canon/batch_<x>.txt build/canon/out/<x>.tsv` per batch (dry run), read the
   count line and `<out>.rejected.tsv` (clashes with a ledger row, repeats between workers, bad rows: decide each by hand,
   nothing is dropped silently), then the same with `--apply`. Then `canon.py apply && canon.py export -j 4 && canon.py queue`
   (only the orchestrator runs these: one Ghidra project, one writer), then `tools/census/scoreboard.py`.
5. Commit with exact paths (`git add census/names_<system>.tsv ...`, never -A), one line to docs/re/night_log.md.
6. After 3 rounds, or when context passes ~60 %: write HANDOFF.md and message the Opus session the round summary.

## Worker brief (paste with <system> filled)
Objective: name the 60 functions in build/canon/batch_<file or system>.txt with evidence.
Context: docs/re/canon_wave.md (this file), docs/re/canon_db.md "GameCube alignment" grades.
Read the batch with `.venv/bin/python tools/canon/canon.py show @build/canon/batch_<system>.txt` (named pseudocode +
index line: size, callers, prior hint, strings, globals). Read more of one function only with `canon.py show <addr>`.
Full GC signatures: `grep '<Name>__' build/prior/nfsug/symbols.txt`.
Scope: write rows only to build/canon/out/<batch>.tsv (columns addr name system confidence evidence tool doc, no header).
Confidence word = high/med/low as before, but start `evidence` with `V:` (second source agrees), `I:` (inferred) or `U:`
(unknown): that prefix, not `high`, is what the scoreboard counts as verified (tools/census/evstate.py).
Per function:
- Order of sources: "GC free in file" line, then the GC window, then the file's range in build/prior/nfsug/symbols.txt.
- Prior hint fits the code (strings, callees, field use, argument count vs the GC signature): GC name as
  `Class::method`, confidence high, evidence `V: <what matches>`, tool `ghidra-canon+nfsug`.
- Hint does not fit, or no hint: name from the code, confidence med (read and clear) or low (guess), evidence says why
  in one clause; a rejected hint is named in the evidence (`rejected B Foo::Bar: no string`).
- Trivial (EH funclet, thunk, getter, scalar deleting destructor): one row, evidence starts `trivial:`.
Done when: every address of the batch has one row, each row has 7 columns, no address repeats one already in a
census/names_*.tsv (`grep -h <addr> census/names_*.tsv`); integrate.py checks both.
Limits: no canon.py apply/export/queue, no integrate.py, no commit, no game runs, no deletes. A hint wrong twice in one source file:
stop trusting hints in that file.
Report (<= 10 lines): rows written, hints taken/rejected per grade, anything odd.
