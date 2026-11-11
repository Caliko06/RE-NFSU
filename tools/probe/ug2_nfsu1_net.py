"""counts of the NFSU1 road net inside a TRACKB lzc (default: live build/openworld/TRACKB1010.lzc), via tools/openworld libs (read only)"""
import sys, os, struct, collections
REPO = '/Users/angeldamian/RE-NFSU'
os.environ.setdefault('NFSU1_MAIN', REPO)
sys.path[:0] = [REPO + '/tools/openworld', REPO + '/tools/hopper']
import polys  # noqa
from lib import load, find
path = sys.argv[1] if len(sys.argv) > 1 else REPO + '/build/openworld/TRACKB1010.lzc'
d = load(path)
for cid in (0x34121, 0x34122, 0x34123, 0x34124, 0x34148, 0x34149):
    r = find(d, cid); print(hex(cid), [(hex(b), s) for b, s in r])
(b, s), = find(d, 0x34121)
p = b; n = []; lst = collections.Counter(); tot = 0; ids = []
while p < b + s:
    sid = struct.unpack_from('<h', d, p + 0xa)[0]; l = struct.unpack_from('<i', d, p + 0xc)[0]; k = struct.unpack_from('<h', d, p + 0x10)[0]
    n.append(k); lst[l] += 1; ids.append(sid); p += 0x27c + k * 0x88
print('sections', len(n), 'nodes', sum(n), 'lists', dict(lst), 'ids', min(ids), max(ids), 'max nodes', max(n))
(b, s), = find(d, 0x34122); print('entries', s // 32)
