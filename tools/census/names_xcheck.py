# Cross-check agent name rows (Ghidra evidence) against the Hopper export: every address the evidence cites
# must show up in Hopper's body / callers / callees of that function.
import re, sys, csv, pickle, os
D = 'census/hopper/decomp.c'
cache = os.path.join('/tmp', 'nfsu_hop.pkl')
if os.path.exists(cache):
    fn = pickle.load(open(cache, 'rb'))
else:
    fn = {}; cur = None
    for line in open(D, errors='replace'):
        m = re.match(r'^// ([0-9a-f]{8}) sub_', line)
        if m:
            cur = int(m.group(1), 16); fn[cur] = {'callers': set(), 'callees': set(), 'body': []}; continue
        if cur is None: continue
        if line.startswith('// callers:'): fn[cur]['callers'] = {int(x.strip('?'), 16) for x in line.split()[2:] if x.strip('?')}
        elif line.startswith('// callees:'): fn[cur]['callees'] = {int(x.strip('?'), 16) for x in line.split()[2:] if x.strip('?')}
        else: fn[cur]['body'].append(line)
    for v in fn.values(): v['body'] = ''.join(v['body']).lower()
    pickle.dump(fn, open(cache, 'wb'))
import bisect, struct
starts = sorted(fn)
def owner(t):
    i = bisect.bisect_right(starts, t) - 1
    return starts[i] if i >= 0 else None
pe = open('pc/Speed.exe', 'rb').read()
e = struct.unpack_from('<I', pe, 0x3c)[0]; nsec = struct.unpack_from('<H', pe, e + 6)[0]
opt = struct.unpack_from('<H', pe, e + 20)[0]; secs = []
for i in range(nsec):
    o = e + 24 + opt + 40 * i
    vs, va, rs, ro = struct.unpack_from('<IIII', pe, o + 8); secs.append((0x400000 + va, rs, ro))
def dword(v):
    for va, rs, ro in secs:
        if va <= v < va + rs - 3: return struct.unpack_from('<I', pe, ro + v - va)[0]
def in_table(t, a):
    return any(dword(t + 4 * k) == a for k in range(0, 96))
for path in sys.argv[1:]:
    rows = list(csv.DictReader(open(path), delimiter='\t'))
    out = []
    for r in rows:
        a = int(r['addr'], 16); f = fn.get(a)
        toks = {int(t, 16) for t in re.findall(r'0x([0-9a-f]{6,8})', r['evidence'].lower())}
        toks = {t for t in toks if 0x400000 <= t < 0x800000 and t != a}
        if f is None: out.append((r['addr'], 'nohopper', 0, len(toks))); continue
        ok = 0
        for t in toks:
            h = '%x' % t
            if t in f['callers'] or t in f['callees'] or re.search(r'(0x|_)' + h + r'\b', f['body']): ok += 1
            elif t in fn and (a in fn[t]['callees'] or a in fn[t]['callers']): ok += 1
            elif (o := owner(t)) is not None and o != a and a in fn[o]['callees']: ok += 1
            elif in_table(t, a): ok += 1
            # data address cited inside a range: any literal within 0x40 bytes
            elif any(re.search(r'(0x|_)%x\b' % (t + d), f['body']) for d in range(-0x40, 0x41, 4)): ok += 1
        out.append((r['addr'], 'ok', ok, len(toks)))
    print('==', path)
    with open(path + '.x', 'w') as o:
        for x in out: o.write('\t'.join(map(str, x)) + '\n')
    import collections
    c = collections.Counter()
    for _, s, ok, n in out:
        c['nohopper' if s != 'ok' else 'notok' if n == 0 else 'all' if ok == n else 'half+' if 2 * ok >= n else 'low']+=1
    print(c)
