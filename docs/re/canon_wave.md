# Naming wave brief (one Sonnet session per wave)

Objective: name one batch of ready functions of one system from census/canon/queue.tsv, with evidence, so the canon
export reads named. Method and grades: docs/re/canon_db.md.

Context: census/canon/c/<range>.c holds the named pseudocode (`// ==== 0x<addr> <name>` headers; range file = the
0x10000 block from 0x401000). funcs.jsonl gives callers/callees/globals/strings; data.jsonl gives globals and strings.
The `prior` column is a hint: grade + GameCube (or MW) name. GC full signatures: build/prior/nfsug/symbols.txt.

Scope: write only census/names_<system>.tsv (columns addr name system confidence evidence tool doc) and, for system
changes of unknown rows, census/systems_override.tsv. Read anything.

Per function:
1. Read its pseudocode and the names of its callees and callers.
2. If the prior hint fits what the code does (strings, callees, field use, argument count vs the GC signature), take
   the GC name as `Class::method` (confidence high, evidence `V: <what in the code matches>`, tool `ghidra-canon+nfsug`).
   If it does not fit, say why in one clause and name it from the code (confidence med/low).
3. Trivial functions (EH funclets, thunks, `return this->f`, scalar deleting destructors): one row each with kind of
   trivial in the evidence, named after their target or owner.

Done when: `canon.py apply && canon.py export -j 4 && canon.py queue` runs clean, the system's done count rose by the
batch size, and `.venv/bin/python tools/census/scoreboard.py` still runs.

Limits: batch of 150 functions or 2 hours; no commit, no deletes, no game runs. A hint that is wrong twice in a row
in one source file: stop trusting hints in that file and say so in the report.

Report: append one line to docs/re/night_log.md + a summary of 10 lines max (named, hints taken/rejected per grade).
