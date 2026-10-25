# Question (2026-10-25): which code reads the DirectInput keyboard (GetDeviceData = vtable +0x28 at 0x406b10, 0x4070a0;
# SetActionMap +0x78 at 0x407760; 0x4079f0) and how the menu layer turns its events into Menu Down (edge or held state)?
# Out: build/hopper/dinput.txt = per address: pseudocode, callers (xrefs), and the callers' pseudocode. Then quits.
import time
OUT = '/Users/angeldamian/RE-NFSU/build/hopper/dinput.txt'
ADDRS = [0x406b10, 0x4070a0, 0x407760, 0x4079f0]
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
