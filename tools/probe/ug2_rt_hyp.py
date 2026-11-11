import struct, collections
d=open("/Users/angeldamian/RE-NFSU-UG2/Need For Speed Underground 2/TRACKS/ROUTESL4RA/RoutesFreeRoam.bin","rb").read()
b,s=8,713468
p=b; secs={}
while p<b+s:
    n=struct.unpack_from('<h',d,p+0x34)[0]; sid=struct.unpack_from('<H',d,p+0xa)[0]
    secs[sid]=[d[p+0x8c+i*0x38:p+0x8c+(i+1)*0x38] for i in range(n)]; p+=0x8c+n*0x38
eb=713484+4; ne=3289
E=[d[eb+i*32:eb+(i+1)*32] for i in range(ne)]
# hypothesis: entry u16 at (a,b) = node, (c,d) = section for source
cnt=collections.Counter()
for sid,ns in secs.items():
    for i,n in enumerate(ns):
        for k in (0x1c,0x1e):
            l=struct.unpack_from('<H',n,k)[0]
            if l==0xffff: continue
            e=E[l]; u=struct.unpack_from('<4H',e,4)
            cnt[('node', tuple(j for j in range(4) if u[j]==i))]+=1
            cnt[('sec', tuple(j for j in range(4) if u[j]==sid))]+=1
for k,v in sorted(cnt.items(),key=lambda x:-x[1])[:12]: print(k,v)
