# Decode every pack texture (index.tsv key -> original level 0) to orig/<key>.png, RGBA.
import sys, os, numpy as np
from PIL import Image
src=open('/Users/angeldamian/RE-NFSU/tools/remaster/index.py').read().split('game, pngs, out')[0]
ns={}; exec(src,ns)
def c565(v):
    v=v.astype(np.uint32); return np.stack([((v>>11)&31)*255//31,((v>>5)&63)*255//63,(v&31)*255//31],-1).astype(np.float32)
def color_block(c, bw, bh, four):  # c: (n,8) uint8
    c0=c[:,0].astype(np.uint16)|(c[:,1].astype(np.uint16)<<8); c1=c[:,2].astype(np.uint16)|(c[:,3].astype(np.uint16)<<8)
    bits=c[:,4:8].copy().view('<u4')[:,0]
    p0,p1=c565(c0),c565(c1)
    m=(c0>c1)|four
    p2=np.where(m[:,None],(2*p0+p1)/3,(p0+p1)/2); p3=np.where(m[:,None],(p0+2*p1)/3,0)
    pal=np.stack([p0,p1,p2,p3],1)  # n,4,3
    idx=(bits[:,None]>>(2*np.arange(16,dtype=np.uint32)))&3
    rgb=np.take_along_axis(pal,idx[:,:,None].astype(np.int64).repeat(3,2),1)
    a=np.where((~m[:,None])&(idx==3),0,255)
    return rgb,a
def unblock(x,w,h,ch):
    bw,bh=max(1,w//4),max(1,h//4)
    x=x.reshape(bh,bw,4,4,ch).transpose(0,2,1,3,4).reshape(bh*4,bw*4,ch); return x[:h,:w]
def decode(raw,w,h,comp):
    if comp==0x20:
        a=np.frombuffer(raw,np.uint8).reshape(h,w,4); return a[...,[2,1,0,3]]
    bs=8 if comp==0x22 else 16; b=np.frombuffer(raw,np.uint8).reshape(-1,bs)
    if comp==0x22: rgb,a=color_block(b,w,h,np.zeros(len(b),bool))
    else:
        rgb,_=color_block(b[:,8:],w,h,np.ones(len(b),bool))
        if comp==0x24:
            ab=b[:,:8].copy().view('<u8')[:,0]; a=((ab[:,None]>>(4*np.arange(16,dtype=np.uint64)))&15).astype(np.float32)*17
        else:
            a0=b[:,0].astype(np.float32); a1=b[:,1].astype(np.float32)
            ab=np.zeros(len(b),np.uint64)
            for k in range(6): ab|=b[:,2+k].astype(np.uint64)<<np.uint64(8*k)
            idx=((ab[:,None]>>(3*np.arange(16,dtype=np.uint64)))&7).astype(np.int64)
            pal=np.zeros((len(b),8),np.float32); pal[:,0]=a0; pal[:,1]=a1
            big=a0>a1
            for k in range(2,8): pal[:,k]=np.where(big,((8-k)*a0+(k-1)*a1)/7,0)
            for k in range(2,6): pal[:,k]=np.where(big,pal[:,k],((6-k)*a0+(k-1)*a1)/5)
            pal[:,6]=np.where(big,pal[:,6],0); pal[:,7]=np.where(big,pal[:,7],255)
            a=np.take_along_axis(pal,idx,1)
    img=np.concatenate([rgb,a[:,:,None]],2).reshape(-1,16,4)
    return unblock(img,w,h,4).round().clip(0,255).astype(np.uint8)
want={}
for l in open('/Users/angeldamian/RE-NFSU/web/remaster/index.tsv'):
    f=l.rstrip('\n').split('\t'); want[(f[1],f[5])]=f
out=sys.argv[1]; n=0; game='/Users/angeldamian/RE-NFSU/game'
for car in ['']+sorted(os.listdir(game+'/CARS')):
    fn=os.path.join(game,'CARS',car,'TEXTURES.BIN')
    if not os.path.isfile(fn): continue
    for key,w,h,comp,raw in ns['textures'](fn):
        k=f'{key:08x}'
        if (k,car or 'SHARED') in want and w>=4 and h>=4:
            Image.fromarray(decode(raw,w,h,comp),'RGBA').save(f'{out}/{car or "SHARED"}_{k}.png'); n+=1
print(n,'decoded')
