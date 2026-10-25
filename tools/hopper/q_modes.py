# Question (2026-10-25): Which code writes the Quick Race mode flags (record +0x1e; records 0x748f70+0xfa10..0xfb44 from 0x4ab510; flags read at 0x75899e 0x7589be 0x7589de 0x7589fe 0x758aa6 0x758ad2 by the list 0x4b70c0)? How does the list move the cursor and set [0x777cc8], and how does the edge read 0x5744b0 drop taps?
# Out: build/hopper/modes.txt = pseudocode, callers (2 levels), callees (1 level), data refs. Then quits.
OUT = '/Users/angeldamian/RE-NFSU/build/hopper/modes.txt'
Q = 'Which code writes the Quick Race mode flags (record +0x1e; records 0x748f70+0xfa10..0xfb44 from 0x4ab510; flags read at 0x75899e 0x7589be 0x7589de 0x7589fe 0x758aa6 0x758ad2 by the list 0x4b70c0)? How does the list move the cursor and set [0x777cc8], and how does the edge read 0x5744b0 drop taps?'
MAXP = 160
ADDRS = [0x4b70c0, 0x4b6880, 0x4b6fe0, 0x4ab510, 0x4ab470, 0x4ab5c0, 0x4ab120, 0x4ab200, 0x5744b0, 0x573cb0, 0x573ab0, 0x4b5c00, 0x4b5d20]
DATA = [0x777cc8, 0x777b4c, 0x75899e, 0x7589be, 0x758aa6, 0x758ad2, 0x7588c4, 0x748f70]

import time
t0 = time.time(); doc = Document.getCurrentDocument(); doc.waitForBackgroundProcessToEnd()
f = open(OUT, 'w'); f.write('# %s\nanalysis %.0f s\n' % (Q, time.time() - t0))
seg = doc.getSegmentAtAddress(0x401000); done = set()
def refs(a):
    # xrefs live in the segment that holds the address (.data for globals), not in .text
    for get in (lambda: doc.getSegmentAtAddress(a).getReferencesOfAddress(a), lambda: doc.getReferencesOfAddress(a)):
        try:
            r = get()
            if r is not None: return list(r)
        except Exception: pass
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
