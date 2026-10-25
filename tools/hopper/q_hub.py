# Question (2026-10-25): which handlers drive the career map after ChooseCareerCar: the MapScreen openers 0x4c5320, 0x4c5df0, 0x4c5fa0 and the briefing 0x4c4e90; event cursor [0x735dc8]?
# Use Hopper for what Ghidra does not give: bodies Ghidra lacks or splits differently, or a second reading when
# Ghidra's pseudocode looks wrong. Offsets/writers/callers: Ghidra first (tools/rea/gpar.sh: scalar, xref, callers).
# Out: build/hopper/<topic>.txt: per address its pseudocode and callers/callees (addresses + names, no recursion);
# per DATA address each referencing instruction (so reads and writes show). Ends "DONE"; never cut silently.
# Copy as q_<topic>.py, set OUT/Q/ADDRS/DATA, run with tools/hopper/hpar.sh <topic> ...
OUT = '/Users/angeldamian/RE-NFSU/build/hopper/hub.txt'
Q = 'which handlers drive the career map after ChooseCareerCar: the MapScreen openers 0x4c5320, 0x4c5df0, 0x4c5fa0 and the briefing 0x4c4e90; event cursor [0x735dc8]?'
ADDRS = [0x4c5320, 0x4c5df0, 0x4c5fa0, 0x4c4e90, 0x4c4f00]
DATA = [0x735dc8, 0x733ff8]

import time
t0 = time.time(); doc = Document.getCurrentDocument(); doc.waitForBackgroundProcessToEnd()
f = open(OUT, 'w'); f.write('# %s\nanalysis %.0f s\n' % (Q, time.time() - t0))
def seg(a): return doc.getSegmentAtAddress(a)
def proc(a):
    s = seg(a); return s.getProcedureAtAddress(a) if s else None
def where(a):
    p = proc(a); e = p.getEntryPoint() if p else None
    return '0x%x in %s' % (a, ('0x%x %s' % (e, doc.getNameAtAddress(e) or '')) if e is not None else '?')
def refs(a):
    for get in (lambda: seg(a).getReferencesOfAddress(a), lambda: doc.getReferencesOfAddress(a)):
        try:
            r = get()
            if r is not None: return sorted(set(r))
        except Exception: pass
    return []
def insn(a):
    try:
        i = seg(a).getInstructionAtAddress(a)
        return '%s %s' % (i.getInstructionString(), ', '.join(i.getFormattedArgument(k) for k in range(i.getArgumentCount())))
    except Exception as x: return '(no instruction: %s)' % x
n = 0
for a in ADDRS:
    p = proc(a)
    if p is None: f.write('\n==== 0x%x: no procedure\n' % a); continue
    e = p.getEntryPoint(); n += 1
    f.write('\n==== 0x%x %s (asked 0x%x)\n' % (e, doc.getNameAtAddress(e) or '', a))
    try: f.write((p.decompile() or '(no pseudocode)') + '\n')
    except Exception as x: f.write('(decompile failed: %s)\n' % x)
    f.write('callers: %s\n' % '; '.join(where(r) for r in refs(e)))
    try: f.write('callees: %s\n' % ' '.join('0x%x' % c for c in sorted(set(c.toAddress() for c in p.getAllCallees()))))
    except Exception: pass
    f.flush()
for a in DATA:
    r = refs(a)
    f.write('\n==== data 0x%x: %d refs\n' % (a, len(r)))
    for x in r: f.write('  %s: %s\n' % (where(x), insn(x)))
    f.flush()
f.write('\nDONE %.0f s, %d procedures, %d data\n' % (time.time() - t0, n, len(DATA))); f.close()
doc.closeDocument()
