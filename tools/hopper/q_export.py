# Full export, chunk K of N (tools/hopper/export.sh writes q_exp<K>.py from this file with K and N set).
# Every procedure whose index % N == K: pseudocode, callers, callees -> build/hopper/exp<K>.txt, ends "DONE".
# Resumes an old file: procedures with a callers line are kept; the one whose header has no callers line hung
# Hopper's decompiler (hpar.sh HOP_STALL killed the window), so it is written without pseudocode this time.
OUT = '/abs/path/build/hopper/exp00.txt'
K, N = 0, 1

import os, re, time
t0 = time.time(); doc = Document.getCurrentDocument(); doc.waitForBackgroundProcessToEnd()
done, hung, old = set(), set(), ''
if os.path.exists(OUT):
    old = open(OUT).read()
    for blk in re.split(r'\n(?=// [0-9a-f]{8} )', old)[1:]:
        (done if '\n// callers:' in blk else hung).add(int(blk[3:11], 16))
    old = '\n'.join(b for b in re.split(r'\n(?=// [0-9a-f]{8} )', old) if b.startswith('#') or '\n// callers:' in b)
f = open(OUT, 'w'); f.write(old or '# export chunk %d/%d\n' % (K, N)); f.write('\nanalysis %.0f s\n' % (time.time() - t0)); f.flush()
def owner(a):
    s = doc.getSegmentAtAddress(a); p = s.getProcedureAtAddress(a) if s else None
    return '%08x' % p.getEntryPoint() if p else '%08x?' % a
i = n = 0
for si in range(doc.getSegmentCount()):
    seg = doc.getSegment(si)
    for pi in range(seg.getProcedureCount()):
        i += 1
        if i % N != K: continue
        p = seg.getProcedureAtIndex(pi); e = p.getEntryPoint(); n += 1
        if e in done: continue
        f.write('\n// %08x %s\n' % (e, doc.getNameAtAddress(e) or '')); f.flush()
        if e in hung: f.write('(decompile hung in Hopper; see census/ghidra)\n')
        else:
            try: f.write((p.decompile() or '(no pseudocode)') + '\n')
            except Exception as x: f.write('(decompile failed: %s)\n' % x)
        try: r = sorted(set(seg.getReferencesOfAddress(e) or []))
        except Exception as x: r = []; f.write('// callers failed: %s\n' % x)   # never an empty callers line for a Hopper error
        f.write('// callers: %s\n' % ' '.join(sorted(set(owner(a) for a in r))))
        try: f.write('// callees: %s\n' % ' '.join('%08x' % c for c in sorted(set(c.toAddress() for c in p.getAllCallees()))))
        except Exception as x: f.write('// callees failed: %s\n' % x)
        f.flush()
f.write('\nDONE %.0f s, %d procedures of %d\n' % (time.time() - t0, n, i)); f.close()
doc.closeDocument()
