"""OW reach to unlifted code: python3 tools/recomp/trapreach.py <dir> <root hex>...
<dir>/cg.txt = "caller callee" from build/gen direct f_X(c) calls; <dir>/traps.tsv = fn, addr, insn of each
TRAP("not lifted: ...") in build/gen (perl one-liners: docs/openworld/re_lift_gaps.md)."""
import sys,collections
S=sys.argv[1]; g=collections.defaultdict(set)
for l in open(S+'/cg.txt'): a,b=l.split(); g[a].add(b)
tr=collections.defaultdict(list)
for l in open(S+'/traps.tsv'): f,a,r=l.rstrip('\n').split('\t'); tr[f].append((a,r))
roots=sys.argv[2:]
for r in roots:
  seen={r:None}; q=[r]
  while q:
    x=q.pop()
    for y in g[x]:
      if y not in seen: seen[y]=x; q.append(y)
  hits=[f for f in seen if f in tr]
  print(f"root {r}: reach {len(seen)} fns, {len(hits)} with traps")
  for f in sorted(hits)[:12]:
    p=[];x=f
    while x: p.append(x); x=seen[x]
    print("  ",f,len(tr[f]),"traps e.g.",tr[f][0][1][:30],"| path",">".join(reversed(p))[:120])
