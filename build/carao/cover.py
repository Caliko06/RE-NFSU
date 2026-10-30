# Which GEOMETRY.BIN solids did the 17 race rows (build/pod/ao/mesh) draw? Match each runtime part's vertex positions as a slice of a solid.
import sys; sys.path.insert(0,'.')
import geobin, glob, numpy as np, os, collections, re, json
solids=[]   # (car, name, pos)
for f in sorted(glob.glob('../../game/Cars/*/GEOMETRY.BIN')):
    car=f.split('/')[-2]
    for i,s in enumerate(geobin.solids(f)):
        if s['nv']: solids.append((car,s['name'],i,s['pos'],s['nt']))
first=collections.defaultdict(list)
for si,(car,name,i,pos,nt) in enumerate(solids):
    for v in range(len(pos)): first[pos[v].tobytes()].append((si,v))
seen=collections.defaultdict(set); unmatched=0; total=0; carsrun=collections.defaultdict(set)
for f in sorted(glob.glob('build/pod/ao/mesh/*.npz'.replace('build/pod','../pod'))):
    run=os.path.basename(f)[:-4]; z=np.load(f)
    for k in sorted({k.split('.')[0] for k in z.files if k[0]=='c' and k.endswith('.vh')}):
        cm=collections.Counter()
        for j,vh in enumerate(z[k+'.vh']):
            p=z[f'{k}.{j}.p']; total+=1; hit=None
            for si,v in first.get(p[0].tobytes(),[]):
                q=solids[si][3]
                if v+len(p)<=len(q) and np.array_equal(q[v:v+len(p)],p): hit=si; break
            if hit is None: unmatched+=1; continue
            seen[hit].add(run); cm[solids[hit][0]]+=1
        if cm: carsrun[cm.most_common(1)[0][0]].add(run)
print('runtime parts',total,'unmatched',unmatched,'solids matched',len(seen))
bycar=collections.defaultdict(list)
for si in seen: bycar[solids[si][0]].append(solids[si][1].split('_',1)[1])
for c,v in sorted(bycar.items()): print(c,len(v),'runs',len(carsrun[c]),'|',' '.join(sorted(v))[:400])
print('KIT01+ or STYLE solids seen:',sum(1 for si in seen if re.search(r'_(KIT(0[1-9]|1\d)|STYLE\d+)_',solids[si][1])))
