#include "carsmooth.h"
#include <math.h>
#include <stdlib.h>
#include <string.h>

/* BRIDGE: car remaster (OWNER 2026-10-20), not in the original. Ported from OpenUG2 src/ug1_carsmooth.c (PN triangles, Vlachos 2001,
 * over crease-aware normals; edges sharper than 45 deg and open borders of the mesh stay straight, so parts keep meeting without
 * gaps). The panel field (decals riding on a panel) is not ported: the caller leaves small draws alone. */
#define CREASE_COS 0.70710678f   /* 45 deg: sharper edges stay as authored */
#define WELD_SCALE 10000.0f      /* positions closer than 0.1 mm share a vertex */
#define FIELD_CELL 0.1f          /* field grid, metres */
#define FIELD_NEAR 0.03f         /* a vertex this close to a panel rides on it */
#define FIELD_ON   0.0002f       /* closer than this it is on the panel (shared border, duplicate face) */

/* One curved triangle: corners, cubic control points (b[c][0] next to corner c on edge c -> c+1,
 * b[c][1] next to corner c+1), corner normals and the normals each edge shares with its partner. */
typedef struct {
    float P[3][3], b[3][2][3], b111[3], cn[3][3], en[3][2][3], fn[3];
    int pid[3], curved[3];
} Patch;

typedef struct { int32_t q[3]; int v; } Weld;
static int weld_cmp(const void *a, const void *b) {
    const Weld *x = (const Weld *)a, *y = (const Weld *)b;
    for (int k = 0; k < 3; k++) if (x->q[k] != y->q[k]) return x->q[k] < y->q[k] ? -1 : 1;
    return x->v - y->v;
}

static float dot3(const float *a, const float *b) { return a[0]*b[0] + a[1]*b[1] + a[2]*b[2]; }
static void norm3(float *a, const float *fallback) {
    float l = sqrtf(dot3(a, a));
    if (l > 1e-12f) { a[0] /= l; a[1] /= l; a[2] /= l; } else memcpy(a, fallback, 3 * sizeof(float));
}

/* PN edge control point next to P (toward Q): (2P + Q - ((Q - P).N) N) / 3, only toward the face's own side (w <= 0).
 * PN bulges toward the convex side whatever way the normal points, so a dark inner shell under the roof (normals inward,
 * same piece) rose through the paint as black blotches (OWNER 2026-10-26, Supra roof, the 268-triangle draw of 774 vertices).
 * Held to its own side each layer moves away from the other; both faces of an edge still get the same point. */
static void edge_ctrl(const float *p, const float *q, const float *n, int curved, float *out) {
    float w = curved ? (q[0]-p[0])*n[0] + (q[1]-p[1])*n[1] + (q[2]-p[2])*n[2] : 0.0f;
    if (w > 0.0f) w = 0.0f;
    for (int k = 0; k < 3; k++) out[k] = (2.0f * p[k] + q[k] - w * n[k]) / 3.0f;
}

/* Point at step s of L along edge A->B. Both faces of an edge call this with the same
 * canonical order (lower position id first), so their points match bit for bit. */
static void edge_point(const float *pa, const float *na, const float *pb, const float *nb,
                       int curved, int s, int L, float *out) {
    float t = (float)s / (float)L, u = 1.0f - t, b1[3], b2[3];
    edge_ctrl(pa, pb, na, curved, b1); edge_ctrl(pb, pa, nb, curved, b2);
    for (int k = 0; k < 3; k++)
        out[k] = u*u*u * pa[k] + 3.0f*u*u*t * b1[k] + 3.0f*u*t*t * b2[k] + t*t*t * pb[k];
}

static void patch_eval(const Patch *p, float u, float v, float w, float *pos) {
    for (int q = 0; q < 3; q++)
        pos[q] = p->P[0][q]*u*u*u + p->P[1][q]*v*v*v + p->P[2][q]*w*w*w
               + 3.0f*(p->b[0][0][q]*u*u*v + p->b[0][1][q]*u*v*v + p->b[1][0][q]*v*v*w
                      + p->b[1][1][q]*v*w*w + p->b[2][0][q]*w*w*u + p->b[2][1][q]*w*u*u)
               + 6.0f*p->b111[q]*u*v*w;
}

/* Curved patches of one mesh. Returns the triangle count (0 = failure or nothing to do). */
static int build_patches(const CsIn *in, Patch **out) {
    int nt = in->nidx / 3, nv = in->nverts, npos = 0;
    *out = NULL;
    if (nt < 1 || nv < 3 || !in->verts || !in->idx) return 0;
    const float *V = in->verts;
    const uint16_t *I = in->idx;
    Weld *wk = (Weld *)malloc((size_t)nv * sizeof *wk);
    int *pid = (int *)malloc((size_t)nv * sizeof *pid), *first = NULL, *vf = (int *)malloc((size_t)nt * 3 * sizeof *vf);
    float *fn = (float *)calloc((size_t)nt * 3, sizeof *fn), *ang = (float *)calloc((size_t)nt * 3, sizeof *ang);
    Patch *pt = (Patch *)calloc((size_t)nt, sizeof *pt);
    int ok = wk && pid && vf && fn && ang && pt;
    if (ok) {
        for (int v = 0; v < nv; v++) {
            for (int k = 0; k < 3; k++) wk[v].q[k] = (int32_t)lrintf(V[v*5+k] * WELD_SCALE);
            wk[v].v = v;
        }
        qsort(wk, (size_t)nv, sizeof *wk, weld_cmp);
        for (int i = 0; i < nv; i++) {
            if (i && memcmp(wk[i].q, wk[i-1].q, sizeof wk[i].q)) npos++;
            pid[wk[i].v] = npos;
        }
        npos++;
        first = (int *)calloc((size_t)npos + 1, sizeof *first);
        ok = first != NULL;
    }
    if (ok) {
        for (int t = 0; t < nt; t++) {   /* unit face normals and corner angles (angle-weighted normals) */
            const float *p[3] = {V + I[3*t]*5, V + I[3*t+1]*5, V + I[3*t+2]*5};
            float e1[3], e2[3];
            for (int k = 0; k < 3; k++) { e1[k] = p[1][k] - p[0][k]; e2[k] = p[2][k] - p[0][k]; }
            float n[3] = {e1[1]*e2[2] - e1[2]*e2[1], e1[2]*e2[0] - e1[0]*e2[2], e1[0]*e2[1] - e1[1]*e2[0]};
            float l = sqrtf(dot3(n, n));
            if (l > 1e-12f) for (int k = 0; k < 3; k++) fn[3*t+k] = n[k] / l;
            if (in->nrm) {   /* drawn with culling off, a face may be wound either way: its authored normals say which side is out */
                float s = 0;
                for (int c = 0; c < 3; c++) s += dot3(fn + 3*t, in->nrm + 3*I[3*t+c]);
                if (s < 0) for (int k = 0; k < 3; k++) fn[3*t+k] = -fn[3*t+k];
            }
            for (int c = 0; c < 3; c++) {
                float a[3], b[3];
                for (int k = 0; k < 3; k++) { a[k] = p[(c+1)%3][k] - p[c][k]; b[k] = p[(c+2)%3][k] - p[c][k]; }
                float la = sqrtf(dot3(a, a)), lb = sqrtf(dot3(b, b));
                float d = la > 1e-12f && lb > 1e-12f ? dot3(a, b) / (la * lb) : 1.0f;
                ang[3*t+c] = acosf(d < -1.0f ? -1.0f : d > 1.0f ? 1.0f : d);
            }
            for (int c = 0; c < 3; c++) first[pid[I[3*t+c]] + 1]++;
        }
        for (int p = 0; p < npos; p++) first[p+1] += first[p];
        int *fill = (int *)malloc((size_t)npos * sizeof *fill);
        ok = fill != NULL;
        if (ok) {
            memcpy(fill, first, (size_t)npos * sizeof *fill);
            for (int t = 0; t < nt; t++) for (int c = 0; c < 3; c++) vf[fill[pid[I[3*t+c]]]++] = t;
        }
        free(fill);
    }
    if (ok) {
        for (int t = 0; t < nt; t++) {   /* crease-aware corner normals */
            Patch *q = &pt[t];
            memcpy(q->fn, fn + 3*t, sizeof q->fn);
            for (int c = 0; c < 3; c++) {
                int p = pid[I[3*t+c]];
                float acc[3] = {0, 0, 0};
                const float *own = in->nrm ? in->nrm + 3*I[3*t+c] : NULL;
                for (int f = first[p]; f < first[p+1]; f++) {
                    int g = vf[f];
                    for (int k = 0; k < 3; k++) if (pid[I[3*g+k]] == p) {
                        const float *src = own ? in->nrm + 3*I[3*g+k] : fn + 3*g;
                        if (own ? dot3(src, own) < CREASE_COS : dot3(fn + 3*g, fn + 3*t) < CREASE_COS) break;
                        for (int a = 0; a < 3; a++) acc[a] += src[a] * ang[3*g+k];
                        break;
                    }
                }
                norm3(acc, fn + 3*t);
                memcpy(q->cn[c], acc, sizeof acc);
                memcpy(q->P[c], V + I[3*t+c]*5, 3 * sizeof(float));
                q->pid[c] = p;
            }
        }
        for (int t = 0; t < nt; t++) {   /* edges: partner across a soft edge, shared normals, control points */
            Patch *q = &pt[t];
            float E[3] = {0, 0, 0}, C[3];
            for (int c = 0; c < 3; c++) {
                int a = q->pid[c], b = q->pid[(c+1)%3], partner = -1, count = 0;
                for (int f = first[a]; f < first[a+1]; f++) {
                    int g = vf[f];
                    if (g == t) continue;
                    for (int k = 0; k < 3; k++) if (pid[I[3*g+k]] == b) { partner = g; count++; break; }
                }
                q->curved[c] = count == 1 && a != b && dot3(fn + 3*partner, fn + 3*t) >= CREASE_COS;
                for (int e = 0; e < 2; e++) {
                    int corner = (c + e) % 3, qq = q->pid[corner];
                    memcpy(q->en[c][e], q->cn[corner], 3 * sizeof(float));
                    if (!q->curved[c]) continue;
                    for (int k = 0; k < 3; k++) if (pt[partner].pid[k] == qq) {
                        for (int a2 = 0; a2 < 3; a2++) q->en[c][e][a2] += pt[partner].cn[k][a2];
                        break;
                    }
                    norm3(q->en[c][e], q->cn[corner]);
                }
                edge_ctrl(q->P[c], q->P[(c+1)%3], q->en[c][0], q->curved[c], q->b[c][0]);
                edge_ctrl(q->P[(c+1)%3], q->P[c], q->en[c][1], q->curved[c], q->b[c][1]);
                for (int k = 0; k < 3; k++) E[k] += (q->b[c][0][k] + q->b[c][1][k]) / 6.0f;
            }
            for (int k = 0; k < 3; k++) { C[k] = (q->P[0][k] + q->P[1][k] + q->P[2][k]) / 3.0f; q->b111[k] = E[k] + (E[k] - C[k]) * 0.5f; }
        }
    }
    free(wk); free(pid); free(first); free(vf); free(fn); free(ang);
    if (!ok) { free(pt); return 0; }
    *out = pt;
    return nt;
}


int cs_smooth(const CsIn *in, CsOut *out, int level) {
    int nt = in->nidx / 3;
    if (nt < 2 || in->nverts < 3) return 0;
    int L = level;
    while (L > 1 && nt * ((L + 1) * (L + 2) / 2) > 65535) L--;
    if (L < 1 || nt * ((L + 1) * (L + 2) / 2) > 65535) return 0;
    Patch *pt;
    if (build_patches(in, &pt) != nt) return 0;
    int per = (L + 1) * (L + 2) / 2, onv = nt * per, oni = nt * L * L * 3;
    float *verts = (float *)malloc((size_t)onv * 8 * sizeof *verts);
    uint16_t *oi = (uint16_t *)malloc((size_t)oni * sizeof *oi);
    int *tri = in->want_src ? (int *)malloc((size_t)onv * sizeof *tri) : NULL;
    float *bary = in->want_src ? (float *)malloc((size_t)onv * 3 * sizeof *bary) : NULL;
    if (!verts || !oi || (in->want_src && (!tri || !bary))) { free(pt); free(verts); free(oi); free(tri); free(bary); return 0; }
    int vo = 0, io = 0;
    for (int t = 0; t < nt; t++) {
        const Patch *q = &pt[t];
        const float *UV[3] = {in->verts + in->idx[3*t]*5 + 3, in->verts + in->idx[3*t+1]*5 + 3, in->verts + in->idx[3*t+2]*5 + 3};
        for (int r = 0; r <= L; r++) for (int c = 0; c <= r; c++) {
            int i = L - r, j = r - c, k = c;   /* barycentric steps toward corners 0, 1, 2 */
            float u = (float)i / L, v = (float)j / L, w = (float)k / L, pos[3], nor[3];
            int vi = vo + r*(r+1)/2 + c, edge = -1, s = 0;
            if (k == 0 && i && j) { edge = 0; s = j; }        /* corner 0 -> 1 */
            else if (i == 0 && j && k) { edge = 1; s = k; }   /* corner 1 -> 2 */
            else if (j == 0 && k && i) { edge = 2; s = i; }   /* corner 2 -> 0 */
            if (i == L || j == L || k == L) {
                int corner = i == L ? 0 : j == L ? 1 : 2;
                memcpy(pos, q->P[corner], sizeof pos);
                memcpy(nor, q->cn[corner], sizeof nor);
            } else if (edge >= 0) {
                int a = edge, bb = (edge + 1) % 3;
                float tt = (float)s / L;
                if (q->pid[a] <= q->pid[bb]) edge_point(q->P[a], q->en[edge][0], q->P[bb], q->en[edge][1], q->curved[edge], s, L, pos);
                else edge_point(q->P[bb], q->en[edge][1], q->P[a], q->en[edge][0], q->curved[edge], L - s, L, pos);
                for (int m = 0; m < 3; m++) nor[m] = q->en[edge][0][m] * (1.0f - tt) + q->en[edge][1][m] * tt;
            } else {
                patch_eval(q, u, v, w, pos);
                for (int m = 0; m < 3; m++) nor[m] = q->cn[0][m]*u + q->cn[1][m]*v + q->cn[2][m]*w;
            }
            norm3(nor, q->fn);
            memcpy(verts + (size_t)vi * 5, pos, sizeof pos);
            verts[(size_t)vi*5 + 3] = UV[0][0]*u + UV[1][0]*v + UV[2][0]*w;
            verts[(size_t)vi*5 + 4] = UV[0][1]*u + UV[1][1]*v + UV[2][1]*w;
            memcpy(verts + (size_t)onv * 5 + (size_t)vi * 3, nor, sizeof nor);   /* positions + uv, then normals */
            if (tri) { tri[vi] = t; bary[3*vi] = u; bary[3*vi+1] = v; bary[3*vi+2] = w; }
        }
        for (int r = 0; r < L; r++) for (int c = 0; c <= r; c++) {
            int a = vo + r*(r+1)/2 + c, d = vo + (r+1)*(r+2)/2 + c;
            oi[io++] = (uint16_t)a; oi[io++] = (uint16_t)d; oi[io++] = (uint16_t)(d + 1);
            if (c < r) { oi[io++] = (uint16_t)a; oi[io++] = (uint16_t)(d + 1); oi[io++] = (uint16_t)(a + 1); }
        }
        vo += per;
    }
    free(pt);
    out->verts = verts; out->nverts = onv;
    out->idx = oi; out->nidx = oni;
    out->tri = tri; out->bary = bary;
    return 1;
}
