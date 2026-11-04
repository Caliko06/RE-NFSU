"""Evidence state of one names_*.tsv row, shared by names_merge.py and scoreboard.py.

State is V (verified), I (inferred) or U (unknown); it is not the confidence word (high/med/low).
Order of authority: an explicit V/I/U in the confidence column, then a `V:`/`I:`/`U:` prefix of the evidence column.
Only when neither exists does `high` stand for V (old ledgers); those rows are `legacy` and counted apart, because
`high` alone is not proof. Anything else (med, low, trivial, empty) is I."""
import re

def state(r):
    """(state, legacy): legacy is True only for a V granted by `high` with no explicit state anywhere."""
    c = (r.get("confidence") or "").strip()
    if c in ("V", "I", "U"): return c, False
    m = re.match(r"\s*([VIU])\s*:", (r.get("evidence") or ""))
    if m: return m.group(1), False
    if c == "high": return "V", True
    return "I", False
