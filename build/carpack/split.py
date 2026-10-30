import sys
from PIL import Image
import numpy as np
lum=lambda x:0.2126*x[...,0]+0.7152*x[...,1]+0.0722*x[...,2]
for p in sys.argv[1:]:
    a=np.asarray(Image.open(p).convert('RGB')).astype(float)/255; h,w=a.shape[:2]
    r=[]
    for lo,hi in ((.44,.5),(.5,.56)):
        c=a[int(h*.58):int(h*.82), int(w*lo):int(w*hi)]
        blue=c[(c[...,2]>c[...,0]*1.3)&(c[...,2]>c[...,1]*1.1)]
        red=c[(c[...,0]>0.6)&(c[...,1]<0.35)&(c[...,2]<0.35)]
        r.append((lum(blue).mean(),len(blue),len(red),(lum(c)>0.9).sum()))
    print(p.split('/')[-1],'left(today) lum %.3f n%d red %d hot %d | right(pack) lum %.3f n%d red %d hot %d'%(r[0]+r[1]), 'ratio %.3f'%(r[1][0]/r[0][0]))
