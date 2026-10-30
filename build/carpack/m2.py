import sys
from PIL import Image
import numpy as np
lum=lambda x:0.2126*x[...,0]+0.7152*x[...,1]+0.0722*x[...,2]
for p in sys.argv[1:]:
    a=np.asarray(Image.open(p).convert('RGB')).astype(float)/255; h,w=a.shape[:2]
    c=a[int(h*.58):int(h*.82), int(w*.37):int(w*.56)]
    blue=c[(c[...,2]>c[...,0]*1.3)&(c[...,2]>c[...,1]*1.1)]
    red=c[(c[...,0]>0.6)&(c[...,1]<0.35)&(c[...,2]<0.35)]
    print(f"{p.split('/')[-1][:-4]:22s} paint {lum(blue).mean():.3f} (n={len(blue)}) red {len(red)} >0.9 {(lum(c)>0.9).sum()}")
