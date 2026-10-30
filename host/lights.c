// BRIDGE: night lights, OWNER 2026-10-27 (Block 7 part 1; RE in docs/night_re.md). RN_LIGHTS=0 (web/mode.js original) = as shipped.
// 1. Live brake lights: 0x56d8d0 lights a tail flare at [0x6b5da0] = 0.7 and adds 16 * brake ([car+0x1e4]) on top, clamped
//    to 1.0, so a brake only went 0.7 -> 1.0. The tail now rests at 0.35 and the brake still reaches 1.0 (flare size and
//    colour follow the intensity in 0x5443f0). Car type 3 keeps 0x6b5da4; 0x6b5da0 has no other reader.
// 2. The player's headlight stays the 2003 one: HeadlightColor (0.8, 0.8, 0.9) at 0x7010ac and the reach ramp of 0x40e560
//    (full to ~48 m, gone by ~98 m). A warm colour x1.25 with full light to ~73 m lit the road far ahead and the game felt
//    slow (OWNER 2026-10-27): in the original the road ahead comes out of the dark, and that is part of its speed.
#include <math.h>
#include "host.h"

static int lights_on(void) {
    static int on = -1;
    if (on < 0) { const char *e = getenv("RN_LIGHTS"); on = !(e && e[0] == '0'); }
    return on;
}

// 4. Flare size (OWNER 2026-10-27, "the car lights have a very big halo"; RE in docs/flare_re.md): 0x5443f0 makes a flare
//    alpha * clamp(z / focal, 0.01, 0.015) * 1.5 world units across; close to the camera (front end, post race, z < 15 m at
//    2560 wide) that is a fixed 1.9 m star on a 4.4 m car. The PS2 (0x29ad30, same tables) has no 1.5, so its stars are 2/3
//    as big: [0x6b633c] = 1.0 (one reader, 0x5444a9; the reflection view, mode 2, already skips it).
//    carpack (RN_CARPACK=1, docs/SCOPE_CARS.md "lamps contained"): the head star is still 1.28 m across at the garage camera
//    (z < 0.01 * focal: k = kmin, fixed in world). RN_FLARE (default 0.55 under carpack) scales the k clamp (kmin, kmax) of the two
//    head layers, 0x6f3f28/2c and 0x6f3f64/68 (rec + 0x30/0x34), so the star shrinks and keeps its alpha: scaling the end alpha
//    (0x6f3efc/0x6f3f38) as well dimmed the Tiburon's tail lamps to black lenses (matrix 4, race_tiburon cp1).
void lights_init(Ctx *c) {
    if (!lights_on()) return;
    stf(c, 0x6b5da0, 0.35f);
    stf(c, 0x6b633c, 1.0f);
    const char *cp = getenv("RN_CARPACK"), *fe = getenv("RN_FLARE");
    float k = fe ? (float)atof(fe) : cp && !strcmp(cp, "1") ? 0.55f : 1.0f;
    if (k != 1.0f) {
        static const uint32_t kk[4] = {0x6f3f28, 0x6f3f2c, 0x6f3f64, 0x6f3f68};
        float was[4];
        for (int n = 0; n < 4; n++) { was[n] = ldf(c, kk[n]); stf(c, kk[n], was[n] * k); }
        rn_log("lights: head flare x%.2f (k clamps %.4f %.4f %.4f %.4f)", k, was[0], was[1], was[2], was[3]);
    }
}

// 3. Other cars' headlights (web only: the SM1 interpreter of the native CPU raster leaves them out). 0x4100a0 lights the
//    world with one projector, the player's: HeadlightWVP = World x VP x S, S = T(0.5, 0.5, 0), VP at [[0x740760]]+0x80
//    (+0 View, +0x40 Proj: near 1, far 100, y flipped). It rides rigidly on the player's car: 0.75 m above its position,
//    looking down its x axis tilted 5.7 deg down (RN_LIGHTSLOG, constant all race). A car's world matrix is rows 0..2 of
//    its rotation and its position as row 3 (0x56d8d0 via 0x401cd0), so car k carries the projector over by the
//    car-to-car motion: VP_k = W_k^-1 W_p VP. On the GPU tp_k = tp x M_k with M_k = (VP S)^-1 W_k^-1 W_p VP S, one matrix
//    per car and frame and no per-draw World (host/sm1.c SM1_HL_VS / PS). In a race every car, the player's too, is in
//    the list [0x7361f8] that 0x570d00 draws (the racer list 0x73d6d8 of 0x570c70 is empty then): head node, next at +0,
//    model +0x4d4. The player's is the one under the projector; the LIGHTS_N nearest others within 150 m get a cone.
typedef double M4[16];

static void mul4(const double *a, const double *b, double *o) {
    M4 t;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++) t[4 * i + j] = a[4 * i] * b[j] + a[4 * i + 1] * b[4 + j] + a[4 * i + 2] * b[8 + j] + a[4 * i + 3] * b[12 + j];
    memcpy(o, t, sizeof t);
}

// Gauss-Jordan with partial pivoting; 0 if singular.
static int inv4(const double *m, double *o) {
    double a[4][8];
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 8; j++) a[i][j] = j < 4 ? m[4 * i + j] : j - 4 == i;
    for (int k = 0; k < 4; k++) {
        int p = k;
        for (int i = k + 1; i < 4; i++) if (fabs(a[i][k]) > fabs(a[p][k])) p = i;
        if (fabs(a[p][k]) < 1e-12) return 0;
        for (int j = 0; j < 8; j++) { double t = a[k][j]; a[k][j] = a[p][j]; a[p][j] = t; }
        for (int j = 7; j >= k; j--) a[k][j] /= a[k][k];
        for (int i = 0; i < 4; i++)
            if (i != k) for (int j = 7; j >= k; j--) a[i][j] -= a[i][k] * a[k][j];
    }
    for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) o[4 * i + j] = a[i][4 + j];
    return 1;
}

// The copy of the car's matrix 0x570d00 draws in view 1: bit 1 of +0x530 picks +0x520 / +0x4e0, else +0x50 / +0x90.
static void car_world(Ctx *c, uint32_t r, double *w) {
    int b = ld(c, r + 0x530, 4) >> 1 & 1;
    uint32_t pos = r + (b ? 0x520 : 0x50), rot = r + (b ? 0x4e0 : 0x90);
    for (int k = 0; k < 12; k++) w[k] = ldf(c, rot + 4 * k);
    for (int k = 0; k < 3; k++) w[12 + k] = ldf(c, pos + 4 * k);
    w[15] = 1;
}

static float hl[LIGHTS_N * 16];
static int hl_frame = -1;

// VS constants c16.. for SM1_HL_VS: per car 4 registers, register j = column j of M_k (the shader takes dot(tp, c)).
// Unused cars stay 0: tp_k = 0 and the shader drops w <= 0.
const float *lights_hl(Ctx *c) {
    static int log = -1;
    if (log < 0) log = getenv("RN_LIGHTSLOG") != NULL;
    if (hl_frame == (int)rn_telem.presents) return hl;
    hl_frame = (int)rn_telem.presents;
    memset(hl, 0, sizeof hl);
    uint32_t cam = ld(c, 0x740760, 4);
    if (log && hl_frame % 30 == 0) rn_log("LIGHTS frame %d: projector %08x", hl_frame, cam);
    if (!lights_on() || !cam) return hl;
    M4 vp, s = {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0.5, 0.5, 0, 1}, vps, vpsi, wp, near[LIGHTS_N];
    double dist[LIGHTS_N];
    for (int k = 0; k < 16; k++) vp[k] = ldf(c, cam + 0x80 + 4 * k);
    mul4(vp, s, vps);
    if (!inv4(vps, vpsi)) {
        if (log && hl_frame % 30 == 0) rn_log("LIGHTS frame %d: projector VP singular (%g %g %g %g)", hl_frame, vp[0], vp[5], vp[10], vp[15]);
        return hl;
    }
    // The player's car is the one under the projector (its origin sits ~0.8 m above the car's position); every other
    // car within 150 m competes for the LIGHTS_N slots, nearest first (insertion into near[]).
    M4 view, camw;
    for (int k = 0; k < 16; k++) view[k] = ldf(c, cam + 4 * k);
    if (!inv4(view, camw)) return hl;
    uint32_t h = ld(c, 0x7361f8, 4), player = 0;
    double best = 3.0 * 3.0;
    int n = 0, cars = 0;
    for (uint32_t r = h ? ld(c, h, 4) : 0; r && r != h && cars < 200; r = ld(c, r, 4), cars++) {
        double dx = ldf(c, r + 0x50) - camw[12], dy = ldf(c, r + 0x54) - camw[13], dz = ldf(c, r + 0x58) - camw[14];
        double d = dx * dx + dy * dy + dz * dz;
        if (d < best) best = d, player = r;
    }
    if (!player) {
        if (log && hl_frame % 30 == 0) rn_log("LIGHTS frame %d: no car under the projector of %d", hl_frame, cars);
        return hl;
    }
    car_world(c, player, wp);
    for (uint32_t r = ld(c, h, 4), k = 0; r != h && k < 200; r = ld(c, r, 4), k++) {
        if (r == player || !ld(c, r + 0x4d4, 4)) continue;
        M4 w;
        car_world(c, r, w);
        double dx = w[12] - wp[12], dy = w[13] - wp[13], dz = w[14] - wp[14], d = dx * dx + dy * dy + dz * dz;
        if (d > 150.0 * 150.0 || (n == LIGHTS_N && d >= dist[n - 1])) continue;
        int i = n < LIGHTS_N ? n++ : LIGHTS_N - 1;
        for (; i > 0 && dist[i - 1] > d; i--) { dist[i] = dist[i - 1]; memcpy(near[i], near[i - 1], sizeof(M4)); }
        dist[i] = d; memcpy(near[i], w, sizeof(M4));
    }
    for (int k = 0; k < n; k++) {
        M4 wi, m;
        if (!inv4(near[k], wi)) continue;
        mul4(vpsi, wi, m); mul4(m, wp, m); mul4(m, vps, m);
        for (int j = 0; j < 4; j++) for (int i = 0; i < 4; i++) hl[16 * k + 4 * j + i] = (float)m[4 * i + j];
    }
    if (log && hl_frame % 30 == 0) {
        M4 wpi, rel;
        inv4(wp, wpi); mul4(camw, wpi, rel);
        rn_log("LIGHTS frame %d: player %08x, %d cars near of %d; projector in player car space: x (%.3f %.3f %.3f) z (%.3f %.3f %.3f)"
               " at (%.2f %.2f %.2f); nearest %.1f m", hl_frame, player, n, cars, rel[0], rel[1], rel[2], rel[8], rel[9], rel[10],
               rel[12], rel[13], rel[14], n ? sqrt(dist[0]) : -1.0);
    }
    return hl;
}
