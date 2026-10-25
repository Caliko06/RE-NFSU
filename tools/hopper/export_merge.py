# export_merge.py IN_DIR OUT_DIR TOPIC...: chunk files -> OUT_DIR/decomp.c (sorted by entry) + funcs.tsv; fails if a chunk lacks DONE.
import re, sys
src, out, topics = sys.argv[1], sys.argv[2], sys.argv[3:]
procs, bad = {}, []
for t in topics:
    text = open('%s/%s.txt' % (src, t), errors='replace').read()
    if not re.search(r'^DONE', text, re.M): bad.append(t)
    for blk in re.split(r'\n(?=// [0-9a-f]{8} )', text)[1:]:
        blk = re.sub(r'\nanalysis \d+ s\n', '\n', blk.split('\nDONE ')[0])
        procs[int(blk[3:11], 16)] = blk.rstrip() + '\n'
with open(out + '/decomp.c', 'w') as f:
    for e in sorted(procs): f.write('\n' + procs[e])
with open(out + '/funcs.tsv', 'w') as f:
    f.write('entry\tname\tlines\tcallers\tcallees\tfailed\n')
    for e in sorted(procs):
        b = procs[e]; head = b.split('\n', 1)[0].split(' ', 2)
        cr = re.search(r'^// callers: ?(.*)$', b, re.M); ce = re.search(r'^// callees: ?(.*)$', b, re.M)
        f.write('%08x\t%s\t%d\t%d\t%d\t%d\n' % (e, head[2] if len(head) > 2 else '', b.count('\n'),
                len(cr.group(1).split()) if cr else 0, len(ce.group(1).split()) if ce else 0, 'decompile failed' in b or 'decompile hung' in b))
print('export: %d procedures, %d failed, chunks without DONE: %s' % (len(procs),
      sum('decompile failed' in b or 'decompile hung' in b for b in procs.values()), ' '.join(bad) or 'none'))
sys.exit(1 if bad else 0)
