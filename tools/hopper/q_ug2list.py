# Listing only, no decompile: every procedure of the document -> build/hopper/ug2list.txt, ends "DONE".
# Same enumeration as q_export.py (segment, procedure, getEntryPoint), so the entries match a full export.
import time
t0 = time.time()
doc = Document.getCurrentDocument()
doc.waitForBackgroundProcessToEnd()
f = open('/Users/angeldamian/RE-NFSU/build/hopper/ug2list.txt', 'w')
f.write('# procedure listing: entry\tname\tsegment start\n')
n = 0
for si in range(doc.getSegmentCount()):
    seg = doc.getSegment(si)
    for pi in range(seg.getProcedureCount()):
        e = seg.getProcedureAtIndex(pi).getEntryPoint()
        f.write('%08x\t%s\t%08x\n' % (e, doc.getNameAtAddress(e) or '', seg.getStartingAddress()))
        n += 1
f.write('DONE %.0f s, %d procedures\n' % (time.time() - t0, n))
f.close()
doc.closeDocument()
