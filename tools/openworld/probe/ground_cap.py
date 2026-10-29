import sys,random
sys.path.insert(0,'tools/hopper'); sys.path.insert(0,'tools/openworld')
import q_owcoll2_sim as Q, polys
from lib import load
for name,d in [('1001',load(polys.trackb_path(polys.PC,1001))),('merged',load('build/openworld/TRACKB1001.lzc'))]:
    w=Q.World(bytearray(d)); random.seed(1); n=full=0; mx=0
    gs=[i for i in range(w.n_wsrc) if not w.d[w.wsrc+32*i+3]&0x0a]
    for i in random.sample(gs,3000):
        a,b,c,e=w.row_vals(i); x=(a+c)/2; y=(b+e)/2; r=10.5
        k=len(w.query((x-r,y-r),(x+r,y+r))); n+=1; full+=k>=160; mx=max(mx,k)
    print(name,'samples',n,'truncated at 160',full,'max',mx)
