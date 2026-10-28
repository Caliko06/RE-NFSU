#ifndef CARSMOOTH_H
#define CARSMOOTH_H
#include <stdint.h>
// verts: x y z u v per vertex (5 floats); idx: triangle list, indices relative to verts.
// nrm (may be NULL): the authored normals, 3 floats per vertex. With them a corner's normal is the average of the authored normals
// at that position that agree with its own (the artist's smoothing groups) and faces are oriented to agree with them; without
// them it is the crease-aware average of the face normals.
// want_src: also report where each output vertex comes from (out->tri, out->bary), to carry per-vertex data the smoothing does
// not know (skin weights, colour).
typedef struct { const float *verts; int nverts; const uint16_t *idx; int nidx; int want_src; const float *nrm; } CsIn;
// out->verts: nverts * 5 floats (x y z u v) followed by nverts * 3 floats of normals. With want_src, out->tri[v] is the input
// triangle of vertex v and out->bary[3v..3v+2] its weights of that triangle's corners; NULL otherwise. The caller frees all four.
typedef struct { float *verts; int nverts; uint16_t *idx; int nidx; int *tri; float *bary; } CsOut;
// Curves the triangles with PN patches subdivided `level` times (lowered until the vertices fit 16 bits). 0 = left as it is.
int cs_smooth(const CsIn *in, CsOut *out, int level);
#endif
