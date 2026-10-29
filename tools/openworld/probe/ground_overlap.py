import sys,collections
sys.path.insert(0,'tools/openworld'); import polys
from lib import load, find
def rows_of(path=None,tid=None):
    d=load(path) if path else load(polys.trackb_path(polys.PC,tid))
    (b,s),=find(d,0x34132); return [bytes(d[o:o+32]) for o in range(b,b+s-31,32)]
def zat(v,x,y):
    # plane through first 3 verts
    (x0,y0,z0),(x1,y1,z1),(x2,y2,z2)=v[:3]
    ax,ay,az=x1-x0,y1-y0,z1-z0; bx,by,bz=x2-x0,y2-y0,z2-z0
    nx,ny,nz=ay*bz-az*by,az*bx-ax*bz,ax*by-ay*bx
    if abs(nz)<1e-6: return None
    return z0-(nx*(x-x0)+ny*(y-y0))/nz
def inside(v,x,y):
    s=0
    for i in range(len(v)):
        (a,b),(c,d)=v[i][:2],v[(i+1)%len(v)][:2]
        cr=(c-a)*(y-b)-(d-b)*(x-a)
        if cr!=0:
            sg=1 if cr>0 else -1
            if s and sg!=s: return False
            s=sg
    return True
def run(rs,name):
    g=[polys.decode(r) for r in rs]; g=[p for p in g if not p['flags']&0x0a]
    grid=collections.defaultdict(list)
    for i,p in enumerate(g):
        xs=[v[0] for v in p['verts']]; ys=[v[1] for v in p['verts']]
        for cx in range(int(min(xs)//16),int(max(xs)//16)+1):
            for cy in range(int(min(ys)//16),int(max(ys)//16)+1): grid[cx,cy].append(i)
    bad=0; hist=collections.Counter(); ex=[]
    for i,p in enumerate(g):
        v=p['verts']; x=sum(a[0] for a in v)/len(v); y=sum(a[1] for a in v)/len(v); z=zat(v,x,y)
        if z is None: continue
        for j in grid[int(x//16),int(y//16)]:
            if j<=i: continue
            q=g[j]['verts']
            if inside(q,x,y):
                zz=zat(q,x,y)
                if zz is None: continue
                dz=abs(zz-z)
                if 0.01<dz<2.0:
                    bad+=1; hist[round(dz,1)]+=1
                    if len(ex)<5: ex.append((round(x),round(y),round(z,2),round(zz,2),p['surf'],g[j]['surf']))
    print(name,'ground',len(g),'overlaps 1cm..2m',bad,sorted(hist.items())[:12],ex)
run(rows_of(tid=1001),'1001')
run(rows_of(path='build/openworld/TRACKB1001.lzc'),'merged')
