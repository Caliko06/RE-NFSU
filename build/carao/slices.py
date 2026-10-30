# Do the runtime draws (17 baked race rows, build/pod/ao/mesh) equal the vertex range [min idx, max idx] of one group record of a solid?
import sys; sys.path.insert(0,'.')
import geobin, glob, numpy as np, os, collections
first=collections.defaultdict(list); sol=[]
for f in sorted(glob.glob('../../game/Cars/*/GEOMETRY.BIN')):
    car=f.split('/')[-2]
    for s in geobin.solids(f):
        if not s['nv']: continue
        i=len(sol); idx=s['idx']; gs=set()
        for (mat,fi,cnt) in s['mats']:
            seg=idx[fi:fi+cnt]
            if len(seg): gs.add((int(seg.min()),int(seg.max())-int(seg.min())+1))
        gs.add((0,s['nv']))
        sol.append((car,s['name'],s['pos'],gs))
        for v in range(len(s['pos'])): first[s['pos'][v].tobytes()].append((i,v))
tot=ok=whole=0; bad=[]
for f in sorted(glob.glob('../pod/ao/mesh/*.npz')):
    z=np.load(f)
    for k in sorted({k.split('.')[0] for k in z.files if k[0]=='c' and k.endswith('.vh')}):
        for j,vh in enumerate(z[k+'.vh']):
            p=z[f'{k}.{j}.p']; tot+=1
            for si,v in first.get(p[0].tobytes(),[]):
                q=sol[si][2]
                if v+len(p)<=len(q) and np.array_equal(q[v:v+len(p)],p):
                    if (v,len(p)) in sol[si][3]: ok+=1; whole+= (v==0 and len(p)==len(q))
                    else: bad.append((sol[si][1],v,len(p),len(q)))
                    break
print('runtime draws',tot,'= a group range',ok,'(whole solid',whole,') other',len(bad)); print(bad[:8])
