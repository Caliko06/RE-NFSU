# Question (date): <one question this run answers>
# Use Hopper for what Ghidra does not give: bodies Ghidra lacks or splits differently, or a second reading when
# Ghidra's pseudocode looks wrong. Offsets/writers/callers: Ghidra first (tools/rea/gpar.sh: scalar, xref, callers).
# Out: build/hopper/<topic>.txt: per address its pseudocode and callers/callees (addresses + names, no recursion);
# per DATA address each referencing instruction (so reads and writes show). Ends "DONE"; never cut silently.
# Copy as q_<topic>.py, set OUT/Q/ADDRS/DATA, run with tools/hopper/hpar.sh <topic> ...
OUT = '/Users/angeldamian/RE-NFSU/build/hopper/unlockq.txt'
Q = 'Unlock queries over table [0x737668] count [0x73766c]: 0x4d8270, 0x4d82f0, 0x4d8370, 0x4bc170, 0x4c6700, 0x4e0d90, 0x507670, 0x50fb00; what each returns and which flags short-circuit to unlocked'
ADDRS = [0x4d8270, 0x4d82f0, 0x4d8370, 0x4bc170, 0x4c6700, 0x4e0d90, 0x507670, 0x50fb00]
DATA = []

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
seen = set(ADDRS)
for a in DATA:
    for x in refs(a):
        p = proc(x)
        if p is None or len(seen) >= len(ADDRS) + 16: continue
        e = p.getEntryPoint()
        if e in seen: continue
        seen.add(e); n += 1
        f.write('\n==== 0x%x %s (refs data 0x%x)\n' % (e, doc.getNameAtAddress(e) or '', a))
        try: f.write((p.decompile() or '(no pseudocode)') + '\n')
        except Exception as x: f.write('(decompile failed: %s)\n' % x)
        f.write('callers: %s\n' % '; '.join(where(r) for r in refs(e)))
        f.flush()
f.write('\nDONE %.0f s, %d procedures, %d data\n' % (time.time() - t0, n, len(DATA))); f.close()
doc.closeDocument()
