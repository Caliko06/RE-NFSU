// Minecraft lane, front F-Speed (docs/re/mc_speed_exit.md): in Free Run, F takes the player out of the car and puts a
// pedestrian beside the driver door; WASD + mouse walk it, F near the car gets back in. Remaster only (RN_MC=0 in original mode).
// One world frame: Speed.exe metres, z up; the pedestrian's height is the game's own ground query 0x440a40 on a private cache.
#include "host.h"
#include "mc.h"
#include <math.h>
#include <stddef.h>
#include <string.h>

McPed rn_mc;
#ifdef __EMSCRIPTEN__
#include <emscripten.h>
EMSCRIPTEN_KEEPALIVE
#endif
uint32_t rn_mc_state(void) { return (uint32_t)(uintptr_t)&rn_mc; }

#define DIK_F 0x21
#define DIK_ESC 0x01
#define WALK 4.0f        // m/s
#define RUN 7.0f         // m/s with Shift
#define STEP 0.5f        // highest step up, metres; a higher surface is a wall
#define DOOR 1.6f        // the pedestrian appears this far to the car's left (driver door), metres
#define ENTER 3.5f       // F gets back in within this distance of the car, metres
#define TURN 0.0025f     // radians per mouse pixel

static volatile int want_toggle;          // F pressed (input thread side), consumed by mc_frame
static uint8_t held[256];                 // keys held while on foot
static float mdx, mdy;                    // mouse motion since the last frame
static uint32_t cache, pt;                // the pedestrian's own ground cache (0x2b4 bytes) and a 3-float point
static uint64_t last_us;

static int free_run(Ctx *c);

int mc_enabled(void) {
    static int on = -1;
    if (on < 0) { const char *e = getenv("RN_MC"); on = e && e[0] == '1'; }
    return on;
}

int mc_key(uint8_t dik, int down) {
    if (!mc_enabled()) return 0;
    if (dik == DIK_F) {
        if (!rn_mc.on_foot && (!g_ctx || !g_ctx->mem || !free_run(g_ctx))) return 0;
        if (down) want_toggle = 1;
        return 1;
    }
    if (!rn_mc.on_foot || dik == DIK_ESC) return 0;
    held[dik] = (uint8_t)down;
    return 1;                             // on foot the car hears nothing
}

int mc_mouse(int32_t dx, int32_t dy) {
    if (!mc_enabled() || !rn_mc.on_foot) return 0;
    mdx += (float)dx, mdy += (float)dy;
    return 1;
}

// The player's car: the entry of the car list [0x7361f8] whose driver kind [[r+0x14]+4] is 1 (host/d3d9.c chase_frame).
static uint32_t player_car(Ctx *c) {
    uint32_t h = ld(c, 0x7361f8, 4);
    if (!h || h >= GUEST_MEM - 0x1000) return 0;
    for (uint32_t r = ld(c, h, 4), k = 0; r && r != h && r < GUEST_MEM - 0x1000 && k < 200; r = ld(c, r, 4), k++) {
        uint32_t e = ld(c, r + 0x14, 4);
        if (e && e < GUEST_MEM - 16 && ld(c, e + 4, 4) == 1) return r;
    }
    return 0;
}

// 0x440a40(cache, &xyz, surface*, normal*, hit*), stdcall, height in ST0: the highest surface at or below z + 1.0. The x87 state is
// saved and put back (host/aitel.c rst_ground). The cache refills itself when xy leaves its box (0x440b02..0x440b0c).
static int mc_ground(Ctx *c, float x, float y, float z, float *h) {
    if (!cache) {
        cache = guest_alloc(0x2c0), pt = guest_alloc(16);
        uint32_t eax = c->r[EAX];
        c->r[EAX] = cache, call_guest(c, 0x440740, 0, NULL), c->r[EAX] = eax;   // clear: empty box, so the first query fills it
    }
    stf(c, pt, x), stf(c, pt + 4, y), stf(c, pt + 8, z);
    st(c, pt + 12, 0, 4);
    uint32_t a[5] = {cache, pt, 0, 0, pt + 12};
    uint32_t fcw = c->fcw, fsw = c->fsw, ftop = c->ftop, ftag = c->ftag;
    double st8[8];
    memcpy(st8, c->st, sizeof st8);
    call_guest(c, 0x440a40, 5, a);
    *h = (float)*fr(c, 0);
    fpop(c);
    memcpy(c->st, st8, sizeof st8);
    c->fcw = fcw, c->fsw = fsw, c->ftop = ftop, c->ftag = ftag;
    return ld(c, pt + 12, 1) != 0;
}

// Free Run of a Quick Race (host/free.c free_setup's test): mode [0x777cc8] == 3 (StartRaceByMode 0x4b5c00 case 3 calls 0x4b5090), not the career.
static int free_run(Ctx *c) { return rn_racing() && ld(c, 0x777cc8, 4) == 3 && !c->mem[0x78a347]; }

// The player's input object P = [[car+0x2c]+8] (human driver ctor 0x59bfc0 -> 0x460e70; AI cars have none). Its event inputs:
// steer +0x28c (0x461840), gas +0x294 (0x4618b0), brake +0x29c (0x461da0), ebrake +0x2ac (0x461e10); 0x461a60 turns them into the
// outputs the physics reads each update. Parked = all 0 and the ebrake at 1; back in = all 0 (the keys refill them on their next change).
static void car_input(Ctx *c, uint32_t car, int in) {
    uint32_t d = ld(c, car + 0x2c, 4), p = d && d < GUEST_MEM - 16 ? ld(c, d + 8, 4) : 0;
    if (!p || p >= GUEST_MEM - 0x2c0) return;
    stf(c, p + 0x28c, 0), stf(c, p + 0x294, 0), stf(c, p + 0x29c, 0), stf(c, p + 0x2ac, in ? 0.0f : 1.0f);
}

static void get_out(Ctx *c, uint32_t car) {
    float fx = ldf(c, car + 0x90), fy = ldf(c, car + 0x94), n = hypotf(fx, fy);
    if (n < 1e-3f) fx = 1, fy = 0, n = 1;
    fx /= n, fy /= n;
    float x = ldf(c, car + 0x60) - fy * DOOR, y = ldf(c, car + 0x64) + fx * DOOR, z = ldf(c, car + 0x68), h;   // left of forward, z up
    memset(&rn_mc, 0, offsetof(McPed, view));
    rn_mc.on_ground = mc_ground(c, x, y, z + 1.0f, &h);
    rn_mc.pos[0] = x, rn_mc.pos[1] = y, rn_mc.pos[2] = rn_mc.on_ground ? h : z;
    rn_mc.heading = atan2f(fy, fx);
    rn_mc.car = car;
    memset(held, 0, sizeof held), mdx = mdy = 0;
    input_release_game();                 // keys the car still holds (gas, steer) go up
    car_input(c, car, 0);
    input_mouse_exclusive(1);             // the page locks the pointer at the next click (web/input.js)
    rn_mc.on_foot = 1;
    rn_log("MC out: car %08x at %.2f %.2f %.2f, pedestrian at %.2f %.2f %.2f ground %d", car, ldf(c, car + 0x60), ldf(c, car + 0x64), z,
           rn_mc.pos[0], rn_mc.pos[1], rn_mc.pos[2], rn_mc.on_ground);
}

static void get_in(Ctx *c) {
    car_input(c, rn_mc.car, 1);
    dinput8_mouse_mode();
    rn_log("MC in: car %08x", rn_mc.car);
    rn_mc.on_foot = 0, rn_mc.car = 0;
    memset(held, 0, sizeof held);
}

static void walk(Ctx *c, float dt) {
    rn_mc.heading -= mdx * TURN;          // mouse right turns right (z up, counter-clockwise positive)
    rn_mc.pitch -= mdy * TURN;
    rn_mc.pitch = fmaxf(-1.2f, fminf(0.8f, rn_mc.pitch));
    mdx = mdy = 0;
    float f = (float)(held[0x11] - held[0x1f]), s = (float)(held[0x20] - held[0x1e]);   // W S, D A
    float sp = held[0x2a] || held[0x36] ? RUN : WALK, n = hypotf(f, s);
    float ch = cosf(rn_mc.heading), sh = sinf(rn_mc.heading);
    float vx = 0, vy = 0;
    if (n > 0) f /= n, s /= n, vx = (f * ch + s * sh) * sp, vy = (f * sh - s * ch) * sp;   // right of (ch, sh) is (sh, -ch)
    float x = rn_mc.pos[0] + vx * dt, y = rn_mc.pos[1] + vy * dt, z = rn_mc.pos[2], h;
    int hit = mc_ground(c, x, y, z + STEP - 1.0f, &h);   // the query adds 1.0: surfaces up to STEP above the feet
    if (hit && h > z + STEP) hit = 0, x = rn_mc.pos[0], y = rn_mc.pos[1], vx = vy = 0, hit = mc_ground(c, x, y, z + STEP - 1.0f, &h);
    rn_mc.vel[0] = vx, rn_mc.vel[1] = vy;
    if (hit && z - h < 0.3f && rn_mc.vel[2] <= 0) z = h, rn_mc.vel[2] = 0;          // on the ground (or a step down)
    else { rn_mc.vel[2] -= 9.8f * dt; z += rn_mc.vel[2] * dt; if (hit && z < h) z = h, rn_mc.vel[2] = 0; }
    rn_mc.on_ground = hit && z - h < 0.05f;
    rn_mc.pos[0] = x, rn_mc.pos[1] = y, rn_mc.pos[2] = z;
}

void mc_frame(Ctx *c) {
    if (!mc_enabled()) return;
    uint64_t t = now_us();
    float dt = last_us ? (float)(t - last_us) * 1e-6f : 1.0f / 60;
    last_us = t;
    dt = fminf(dt, 0.05f);
    int toggle = want_toggle; want_toggle = 0;
    uint32_t car = free_run(c) ? player_car(c) : 0;
    if (rn_mc.on_foot && (!car || car != rn_mc.car)) { get_in(c); return; }   // the event ended or the car changed
    if (!car) return;
    if (!rn_mc.on_foot) { if (toggle) get_out(c, car); return; }
    walk(c, dt);
    static uint32_t n;
    int moving = rn_mc.vel[0] != 0 || rn_mc.vel[1] != 0;
    if (moving && !rn_mc.walked) rn_mc.walked = 1, rn_log("MC walk: from %.2f %.2f %.2f", rn_mc.pos[0], rn_mc.pos[1], rn_mc.pos[2]);
    if (++n % 60 == 0) rn_log("MC at %.2f %.2f %.2f ground %d heading %.2f car %.1f m", rn_mc.pos[0], rn_mc.pos[1], rn_mc.pos[2], rn_mc.on_ground, rn_mc.heading,
                              hypotf(rn_mc.pos[0] - ldf(c, car + 0x60), rn_mc.pos[1] - ldf(c, car + 0x64)));
    car_input(c, car, 0);
    if (toggle && hypotf(rn_mc.pos[0] - ldf(c, car + 0x60), rn_mc.pos[1] - ldf(c, car + 0x64)) < ENTER) get_in(c);
}

// The third-person camera: the eye 4 m behind and above the pedestrian's head along heading and pitch. The view matrix (D3D row vectors,
// world to camera; right, up, forward in columns 0..2, translation row 3) takes the handedness of the mover's own matrix of this frame
// (camera+0..0x3f, written by 0x47d070), so no axis convention is assumed. Then 0x47d070(camera, &m, dt) as the movers call it (0x48c1e4),
// with the cut byte camera+0x270 set so the eye velocity +0x1e0 (speed blur) stays 0.
static uint32_t cam_m;
static void cam_set(Ctx *c) {
    uint32_t cam = ld(c, 0x740500, 4);
    if (!cam || cam >= GUEST_MEM - 0x300) return;
    if (!cam_m) cam_m = guest_alloc(64);
    float ch = cosf(rn_mc.heading), sh = sinf(rn_mc.heading), cp = cosf(rn_mc.pitch), sp = sinf(rn_mc.pitch);
    float f[3] = {cp * ch, cp * sh, sp}, t[3] = {rn_mc.pos[0], rn_mc.pos[1], rn_mc.pos[2] + 1.6f}, e[3], h;
    for (int k = 0; k < 3; k++) e[k] = t[k] - 4.0f * f[k];
    e[2] += 0.6f;
    if (mc_ground(c, e[0], e[1], e[2], &h) && e[2] < h + 0.4f) e[2] = h + 0.4f;   // not under the road
    float n = 0;
    for (int k = 0; k < 3; k++) f[k] = t[k] - e[k], n += f[k] * f[k];
    n = sqrtf(n);
    for (int k = 0; k < 3; k++) f[k] /= n;
    float r[3] = {-f[1], f[0], 0}, rn = hypotf(r[0], r[1]);        // cross(z up, forward)
    r[0] /= rn, r[1] /= rn;
    float g[9];                                                   // the game's columns: right, up, forward
    for (int k = 0; k < 3; k++) g[k] = ldf(c, cam + 16 * k), g[3 + k] = ldf(c, cam + 16 * k + 4), g[6 + k] = ldf(c, cam + 16 * k + 8);
    float det = g[0] * (g[4] * g[8] - g[5] * g[7]) - g[1] * (g[3] * g[8] - g[5] * g[6]) + g[2] * (g[3] * g[7] - g[4] * g[6]);
    float u[3] = {f[1] * r[2] - f[2] * r[1], f[2] * r[0] - f[0] * r[2], f[0] * r[1] - f[1] * r[0]};   // cross(forward, right)
    if (u[2] < 0) for (int k = 0; k < 3; k++) u[k] = -u[k];       // up points up
    float mine = r[0] * (u[1] * f[2] - u[2] * f[1]) - r[1] * (u[0] * f[2] - u[2] * f[0]) + r[2] * (u[0] * f[1] - u[1] * f[0]);
    if ((det < 0) != (mine < 0)) for (int k = 0; k < 3; k++) r[k] = -r[k];
    if (g[5] < 0) for (int k = 0; k < 3; k++) r[k] = -r[k], u[k] = -u[k];   // the game's up column points to world -z: same roll as the game (run 2: 180 deg)
    static int said;
    if (!said) said = 1, rn_log("MC camera: game up column z %.3f, det %.3f", g[5], det);
    float m[16] = {r[0], u[0], f[0], 0, r[1], u[1], f[1], 0, r[2], u[2], f[2], 0,
                   -(r[0] * e[0] + r[1] * e[1] + r[2] * e[2]), -(u[0] * e[0] + u[1] * e[1] + u[2] * e[2]), -(f[0] * e[0] + f[1] * e[1] + f[2] * e[2]), 1};
    for (int k = 0; k < 16; k++) stf(c, cam_m + 4 * k, m[k]);
    uint8_t cut = c->mem[cam + 0x270];
    c->mem[cam + 0x270] = 1;
    uint32_t a[3] = {cam, cam_m, ld(c, 0x73ad38, 4)};
    uint32_t fcw = c->fcw, fsw = c->fsw, ftop = c->ftop, ftag = c->ftag;
    double st8[8];
    memcpy(st8, c->st, sizeof st8);
    call_guest(c, 0x47d070, 3, a);
    memcpy(c->st, st8, sizeof st8);
    c->fcw = fcw, c->fsw = fsw, c->ftop = ftop, c->ftag = ftag;
    c->mem[cam + 0x270] = cut;
}

// PATCH 0x4479be (tools/recomp/patches_mc.py): the camera movers 0x48e8b0, then the pedestrian's camera.
static uint32_t mc_views(Ctx *c) {
    uint32_t r = call_guest(c, 0x48e8b0, 0, NULL);
    if (mc_enabled() && rn_mc.on_foot) cam_set(c);
    return r;
}
const Api mc_apis[] = {{"rn", "mc_views", 0, mc_views}};
const int mc_api_count = sizeof mc_apis / sizeof *mc_apis;

// Debug marker until F-Max's mesh exists: a 0.5 x 0.5 x 1.8 m box at the feet with a nose toward the heading.
void mc_draw_actor(Ctx *c, const McPed *p) {
    static int maxchar = -1;   // RN_MAXCHAR (web/boot.js, local Max build present): Max Payne is the pedestrian (web/maxpayne/)
    if (maxchar < 0) maxchar = getenv("RN_MAXCHAR") != NULL;
    if (maxchar) return;
    float ch = cosf(p->heading) * 0.25f, sh = sinf(p->heading) * 0.25f, v[8][3];
    for (int k = 0; k < 8; k++) {
        float a = k & 1 ? 1 : -1, b = k & 2 ? 1 : -1;
        v[k][0] = p->pos[0] + a * ch - b * sh, v[k][1] = p->pos[1] + a * sh + b * ch, v[k][2] = p->pos[2] + (k & 4 ? 1.8f : 0);
    }
    static const uint8_t q[6][4] = {{0, 1, 3, 2}, {4, 5, 7, 6}, {0, 1, 5, 4}, {2, 3, 7, 6}, {0, 2, 6, 4}, {1, 3, 7, 5}};
    float tri[14][9];
    for (int f = 0; f < 6; f++) {
        const uint8_t *i = q[f];
        memcpy(tri[2 * f], v[i[0]], 12), memcpy(tri[2 * f] + 3, v[i[1]], 12), memcpy(tri[2 * f] + 6, v[i[2]], 12);
        memcpy(tri[2 * f + 1], v[i[0]], 12), memcpy(tri[2 * f + 1] + 3, v[i[2]], 12), memcpy(tri[2 * f + 1] + 6, v[i[3]], 12);
    }
    d3d9_draw_tris(c, &tri[0][0], 12, 0xffff8000);
    float nose[9] = {p->pos[0] + 2 * ch * 2, p->pos[1] + 2 * sh * 2, p->pos[2] + 1.5f,
                     p->pos[0] - sh, p->pos[1] + ch, p->pos[2] + 1.5f, p->pos[0] + sh, p->pos[1] - ch, p->pos[2] + 1.5f};
    d3d9_draw_tris(c, nose, 1, 0xff00ff40);
}
