# Question (2026-10-25): the menu input path after DirectInput. 0x573ab0 runs the per-action handlers of the table at
# 0x703880 (callback +0xc: 0x574410/0x574450/0x5744b0/0x574500/0x574590/0x5747b0; node +0x18 last value, +0x1c force),
# 0x574350 reads the action state; 0x573cb0 records/plays events through the replay object [0x7345d0] (0x594120,
# 0x594220, 0x57c5a0, 0x57c480). Does the post-race menu (over the race replay) take live input or replayed events?
# Out: build/hopper/menu.txt = per address: pseudocode, callers (xrefs), and the callers pseudocode. Then quits.
import time
OUT = '/Users/angeldamian/RE-NFSU/build/hopper/menu.txt'
ADDRS = [0x573ab0, 0x574350, 0x574410, 0x574450, 0x5744b0, 0x574500, 0x574590, 0x5747b0, 0x594120, 0x594220, 0x57c5a0, 0x57c480]
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
