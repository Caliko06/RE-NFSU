# Question (2026-10-25): How does the player pick a Quick Race track (SELECT LOCATION list, record +8 -> [0x78a2f0]) and a career event ([0x735dc8] set by 0x4c4f00, table 0x733ff8 by 0x5a0060)? Which keys and screens lead from GO UNDERGROUND to a race start?
# Out: build/hopper/career.txt = pseudocode, callers (2 levels), callees (1 level), data refs. Then quits.
OUT = '/Users/angeldamian/RE-NFSU/build/hopper/career.txt'
Q = 'How does the player pick a Quick Race track (SELECT LOCATION list, record +8 -> [0x78a2f0]) and a career event ([0x735dc8] set by 0x4c4f00, table 0x733ff8 by 0x5a0060)? Which keys and screens lead from GO UNDERGROUND to a race start?'
MAXP = 160
ADDRS = [0x4c4f00, 0x4e8180, 0x5a0060, 0x5a2270, 0x568200, 0x5a16f0, 0x4b9f40, 0x4b49e0, 0x4b52a0, 0x4b2aa0, 0x4c5ee0, 0x5a2040]
DATA = [0x735dc8, 0x733ff8, 0x78a2f0, 0x78a31c, 0x735ec1, 0x73494c]

import time
t0 = time.time(); doc = Document.getCurrentDocument(); doc.waitForBackgroundProcessToEnd()
f = open(OUT, 'w'); f.write('# %s\nanalysis %.0f s\n' % (Q, time.time() - t0))
seg = doc.getSegmentAtAddress(0x401000); done = set()
def refs(a):
    # xrefs live in the segment that holds the address (.data for globals), not in .text
    err = None
    for get in (lambda: doc.getSegmentAtAddress(a).getReferencesOfAddress(a), lambda: doc.getReferencesOfAddress(a)):
        try:
            r = get()
            if r is not None: return list(r)
        except Exception as x: err = x
    if err is not None: f.write('(xrefs of 0x%x failed: %s)\n' % (a, err))   # an empty list must mean no xrefs, never a Hopper error
    return []
def callees(p):
    try: return sorted(set(c.toAddress() for c in p.getAllCallees()))
    except Exception: return []
def dump(a, depth, why):
    # Bounded: 25 min and MAXP procedures, so the 30 min demo never cuts a file in half.
    if time.time() - t0 > 1500 or len(done) >= MAXP: return
    p = seg.getProcedureAtAddress(a)
    if p is None:
        f.write('\n==== 0x%x: no procedure (%s)\n' % (a, why)); return
    e = p.getEntryPoint()
    if e in done: return
    done.add(e)
    f.write('\n==== 0x%x %s (depth %d, %s)\n' % (e, doc.getNameAtAddress(e) or '', depth, why))
    try: f.write((p.decompile() or '(no pseudocode)') + '\n')
    except Exception as x: f.write('(decompile failed: %s)\n' % x)
    cr = refs(e); ce = callees(p)
    f.write('callers: %s\ncallees: %s\n' % (' '.join('0x%x' % r for r in cr), ' '.join('0x%x' % c for c in ce))); f.flush()
    if depth < 2:
        for r in cr: dump(r, depth + 1, 'caller of 0x%x' % e)
    if depth < 1:
        for c in ce: dump(c, depth + 1, 'callee of 0x%x' % e)
for a in DATA:
    r = refs(a)
    f.write('\ndata 0x%x refs: %s\n' % (a, ' '.join('0x%x' % x for x in r))); f.flush()
for a in ADDRS: dump(a, 0, 'asked')
for a in DATA:
    for r in refs(a): dump(r, 1, 'uses data 0x%x' % a)
f.write('\nDONE %.0f s, %d procedures\n' % (time.time() - t0, len(done))); f.close()
doc.closeDocument()
