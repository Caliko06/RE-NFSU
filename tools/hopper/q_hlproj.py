# Question (2026-10-27, Block 7 night): Projected headlight on PC: who loads fx/worldheadlight.efx (0x701560) and chooses it over world.efx, the effect callbacks 0x40e740/0x40e7b0/0x40e900 (who stores them), how HEADLIGHTWVP, HEADLIGHTCLIPMAT and HEADLIGHTCOLOR are built (position, cone, range, colour value), what 0x71abb4/0x71aa28/0x73640c hold, which cars get it (player only?) and which option (HEADLIGHTS 0x6cb25c, CARLIGHTING 0x6cb220) gates it
# Hopper first: grep census/hopper/decomp.c (every procedure, callers, callees) before writing a query; a query is for
# what the export lacks: data refs (DATA), a body after a new Speed.exe. Ghidra only when Hopper lacks the answer.
# Out: build/hopper/<topic>.txt: per address its pseudocode and callers/callees (addresses + names, no recursion);
# per DATA address each referencing instruction (so reads and writes show). Ends "DONE"; never cut silently.
# Copy as q_<topic>.py, set OUT/Q/ADDRS/DATA, run with tools/hopper/hpar.sh <topic> ...
OUT = '/Users/angeldamian/RE-NFSU/build/hopper/hlproj.txt'
Q = 'Projected headlight on PC: who loads fx/worldheadlight.efx (0x701560) and chooses it over world.efx, the effect callbacks 0x40e740/0x40e7b0/0x40e900 (who stores them), how HEADLIGHTWVP, HEADLIGHTCLIPMAT and HEADLIGHTCOLOR are built (position, cone, range, colour value), what 0x71abb4/0x71aa28/0x73640c hold, which cars get it (player only?) and which option (HEADLIGHTS 0x6cb25c, CARLIGHTING 0x6cb220) gates it'
ADDRS = [0x40e740, 0x40e7b0, 0x40e900]
DATA = [0x701560, 0x40e740, 0x40e7b0, 0x40e900, 0x71abb4, 0x71aa28, 0x6cb25c, 0x6cb220]

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
