import struct, sys, collections
P="/Users/angeldamian/RE-NFSU-UG2/Need For Speed Underground 2/TRACKS/ROUTESL4R%s/RoutesFreeRoam.bin"
sec=sys.argv[1] if len(sys.argv)>1 else 'A'
d=open(P%sec,'rb').read()
def chunks(d):
    p=0
    while p+8<=len(d):
        i,s=struct.unpack_from('<II',d,p); yield i,p+8,s; p+=8+s
ch={i:(b,s) for i,b,s in chunks(d)}
print({hex(k):v for k,v in ch.items()})
b,s=ch[0x34121]
p=b; secs=[]
while p<b+s:
    n=struct.unpack_from('<h',d,p+0x34)[0]; sid=struct.unpack_from('<H',d,p+0xa)[0]
    secs.append((p,sid,n)); p+=0x8c+n*0x38
print('sections',len(secs),'end ok',p==b+s,'nodes',sum(x[2] for x in secs))
print('ids',[x[1] for x in secs[:40]], 'max id',max(x[1] for x in secs), 'maxn',max(x[2] for x in secs))
for p,sid,n in secs[:3]:
    print(sid,n,d[p:p+0x8c].hex())
    print(d[p+0x8c:p+0x8c+0x38*2].hex())
