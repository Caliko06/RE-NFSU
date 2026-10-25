# Question (2026-10-25): the Quick Race settings record. 0x4b55b0 copies it into the race parameters (0x78a2f0 track,
# 0x78a2fc ...) from FUN_004ab510() and mode [0x748f70]. Which fields are mode, track, laps, and who calls 0x4b55b0?
# Out: build/hopper/qr.txt = per address: pseudocode, callers (xrefs), and the callers pseudocode. Then quits.
import time
OUT = '/Users/angeldamian/RE-NFSU/build/hopper/qr.txt'
ADDRS = [0x4b55b0, 0x4ab510, 0x4ab670, 0x4abc20, 0x4ab880, 0x4ab900]
t0 = time.time(); doc = Document.getCurrentDocument(); doc.waitForBackgroundProcessToEnd()
f = open(OUT, 'w'); f.write('analysis %.0f s\n' % (time.time() - t0))
seg = doc.getSegmentAtAddress(ADDRS[0]); done = set()
def dump(a, depth):
    p = seg.getProcedureAtAddress(a)
    if p is None or p.getEntryPoint() in done: return
    e = p.getEntryPoint(); done.add(e)
    f.write('\n==== 0x%x %s (depth %d)\n' % (e, doc.getNameAtAddress(e) or '', depth))
    f.write((p.decompile() or '(no pseudocode)') + '\n')
    refs = doc.getReferencesOfAddress(e) or []
    f.write('callers: %s\n' % ' '.join('0x%x' % r for r in refs)); f.flush()
    if depth < 1:
        for r in refs: dump(r, depth + 1)
for a in ADDRS: dump(a, 0)
f.write('\nDONE %.0f s\n' % (time.time() - t0)); f.close()
doc.closeDocument()
