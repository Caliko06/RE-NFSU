# Question (2026-10-25): Options and saves: who reads and writes <profile>.cfg (0x41c680, ROADREFLECTION), .opt and .ugd (profile block 0x7588c4 size 0xf660 via 0x4ab120)? Which garage screens and calls fit a part on the car?
# Out: build/hopper/options.txt = pseudocode, callers (2 levels), callees (1 level), data refs. Then quits.
OUT = '/Users/angeldamian/RE-NFSU/build/hopper/options.txt'
Q = 'Options and saves: who reads and writes <profile>.cfg (0x41c680, ROADREFLECTION), .opt and .ugd (profile block 0x7588c4 size 0xf660 via 0x4ab120)? Which garage screens and calls fit a part on the car?'
MAXP = 160
ADDRS = [0x41c680, 0x4ab120, 0x507e10, 0x509d70, 0x50aa90, 0x5a3570, 0x5a1520]
DATA = [0x7588c4, 0x700e70]

import time
t0 = time.time(); doc = Document.getCurrentDocument(); doc.waitForBackgroundProcessToEnd()
f = open(OUT, 'w'); f.write('# %s\nanalysis %.0f s\n' % (Q, time.time() - t0))
seg = doc.getSegmentAtAddress(0x401000); done = set()
def refs(a):
    for get in (lambda: doc.getReferencesOfAddress(a), lambda: seg.getReferencesOfAddress(a)):
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
