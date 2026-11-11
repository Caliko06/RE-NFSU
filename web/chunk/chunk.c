// One walkable 32x32x32 voxel zone: terrain, player physics, block raycast, place/break, face meshing with AO.
// Own blocks and look (no Minecraft data). Build:
//   emcc -O2 --no-entry -sSTANDALONE_WASM -sEXPORTED_FUNCTIONS=_init,_look,_step,_click,_mesh,_verts,_view,_hit,_player -o web/chunk/chunk.wasm web/chunk/chunk.c
#include <math.h>
#include <stdint.h>

#define N 32
#define MAXV (N * N * N * 6)          // 6 verts per face; terrain uses far less
enum { AIR, GRASS, DIRT, STONE, PLANK, BRICK, SAND, NBLOCK };

static uint8_t W[N][N][N];             // [x][y][z]
typedef struct { float x, y, z; uint32_t a; } Vert;   // a = block | face<<8 | ao<<12
static Vert V[MAXV];
static int nv;
static float P[3], Vel[3], yaw, pitch;
static int ground;
static int H[7];                       // hit: ok, x, y, z, px, py, pz (cell in front of the hit face)
static float VP[16];
static float aspect = 1.6f;
static uint32_t seed = 1234567;

static float rnd(int x, int z) {
    uint32_t h = (uint32_t)x * 374761393u + (uint32_t)z * 668265263u + seed;
    h = (h ^ (h >> 13)) * 1274126177u;
    return (float)((h ^ (h >> 16)) & 0xffff) / 65535.0f;
}
static float smooth(float x, float z, float s) {
    int ix = (int)floorf(x / s), iz = (int)floorf(z / s);
    float fx = x / s - ix, fz = z / s - iz;
    fx = fx * fx * (3 - 2 * fx); fz = fz * fz * (3 - 2 * fz);
    float a = rnd(ix, iz), b = rnd(ix + 1, iz), c = rnd(ix, iz + 1), d = rnd(ix + 1, iz + 1);
    return (a + (b - a) * fx) + ((c + (d - c) * fx) - (a + (b - a) * fx)) * fz;
}

static int solid(int x, int y, int z) {
    if (x < 0 || z < 0 || x >= N || z >= N || y < 0) return 1;   // world edge is a wall
    if (y >= N) return 0;
    return W[x][y][z] != AIR;
}
static int block(int x, int y, int z) {
    if (x < 0 || y < 0 || z < 0 || x >= N || y >= N || z >= N) return AIR;
    return W[x][y][z];
}

void init(void) {
    for (int x = 0; x < N; x++)
        for (int z = 0; z < N; z++) {
            int h = 8 + (int)(smooth(x, z, 9) * 6 + smooth(x, z, 4) * 2);
            for (int y = 0; y < N; y++)
                W[x][y][z] = y > h ? AIR : y == h ? (h <= 9 ? SAND : GRASS) : y > h - 3 ? DIRT : STONE;
        }
    for (int i = 0; i < 4; i++) W[14 + i][1 + 8 + (int)(smooth(14 + i, 14, 9) * 6 + smooth(14 + i, 14, 4) * 2)][14] = BRICK;
    P[0] = 16.5f; P[2] = 10.5f; P[1] = N;
    while (P[1] > 0 && !solid(16, (int)P[1] - 1, 10)) P[1] -= 1;
    yaw = 0; pitch = -0.2f;
}

// Axis-aligned move of the 0.6 x 1.8 player box; stops at the first solid cell.
static void move(int ax, float d) {
    const float r = 0.3f, h = 1.8f, eps = 1e-3f;
    P[ax] += d;
    float lo[3] = { P[0] - r, P[1], P[2] - r }, hi[3] = { P[0] + r, P[1] + h, P[2] + r };
    for (int x = (int)floorf(lo[0]); x <= (int)floorf(hi[0] - eps); x++)
        for (int y = (int)floorf(lo[1]); y <= (int)floorf(hi[1] - eps); y++)
            for (int z = (int)floorf(lo[2]); z <= (int)floorf(hi[2] - eps); z++) {
                if (!solid(x, y, z)) continue;
                int c[3] = { x, y, z };
                if (d > 0) P[ax] = c[ax] - (ax == 1 ? h : r) - eps;
                else P[ax] = c[ax] + 1 + (ax == 1 ? 0 : r) + eps;
                if (ax == 1) { if (d < 0) ground = 1; Vel[1] = 0; }
                return;
            }
}

static void raycast(void) {
    float o[3] = { P[0], P[1] + 1.62f, P[2] };
    float d[3] = { -sinf(yaw) * cosf(pitch), sinf(pitch), -cosf(yaw) * cosf(pitch) };
    int c[3], st[3], prev[3];
    float tmax[3], tdel[3];
    for (int i = 0; i < 3; i++) {
        c[i] = prev[i] = (int)floorf(o[i]);
        st[i] = d[i] > 0 ? 1 : -1;
        tdel[i] = d[i] != 0 ? fabsf(1 / d[i]) : 1e9f;
        tmax[i] = d[i] != 0 ? ((d[i] > 0 ? c[i] + 1 - o[i] : o[i] - c[i]) * tdel[i]) : 1e9f;
    }
    H[0] = 0;
    for (float t = 0; t < 6;) {
        int a = tmax[0] < tmax[1] ? (tmax[0] < tmax[2] ? 0 : 2) : (tmax[1] < tmax[2] ? 1 : 2);
        prev[0] = c[0]; prev[1] = c[1]; prev[2] = c[2];
        t = tmax[a]; c[a] += st[a]; tmax[a] += tdel[a];
        if (t > 6) break;
        if (block(c[0], c[1], c[2]) != AIR) {
            H[0] = 1; H[1] = c[0]; H[2] = c[1]; H[3] = c[2]; H[4] = prev[0]; H[5] = prev[1]; H[6] = prev[2];
            return;
        }
    }
}

static void matrices(void) {
    float f = 1 / tanf(1.2f / 2), n = 0.05f, far = 200;
    float cy = cosf(yaw), sy = sinf(yaw), cp = cosf(pitch), sp = sinf(pitch);
    float e[3] = { P[0], P[1] + 1.62f, P[2] };
    // camera basis: right, up, back (looking down -back)
    float rt[3] = { cy, 0, -sy }, bk[3] = { sy * cp, -sp, cy * cp };
    float up[3] = { bk[1] * rt[2] - bk[2] * rt[1], bk[2] * rt[0] - bk[0] * rt[2], bk[0] * rt[1] - bk[1] * rt[0] };
    float v[16] = { rt[0], up[0], bk[0], 0, rt[1], up[1], bk[1], 0, rt[2], up[2], bk[2], 0,
                    -(rt[0]*e[0]+rt[1]*e[1]+rt[2]*e[2]), -(up[0]*e[0]+up[1]*e[1]+up[2]*e[2]), -(bk[0]*e[0]+bk[1]*e[1]+bk[2]*e[2]), 1 };
    float p[16] = { f / aspect, 0, 0, 0, 0, f, 0, 0, 0, 0, far / (n - far), -1, 0, 0, n * far / (n - far), 0 };   // WebGPU depth 0..1
    for (int c = 0; c < 4; c++)
        for (int r = 0; r < 4; r++) {
            float s = 0;
            for (int k = 0; k < 4; k++) s += p[k * 4 + r] * v[c * 4 + k];
            VP[c * 4 + r] = s;
        }
}

void look(float dx, float dy, float asp) {
    yaw -= dx * 0.0025f; pitch -= dy * 0.0025f;
    if (pitch > 1.55f) pitch = 1.55f;
    if (pitch < -1.55f) pitch = -1.55f;
    aspect = asp;
}

// fwd/strafe in -1..1, jump 0/1. Fixed substeps keep collision stable at low frame rates.
void step(float dt, float fwd, float strafe, int jump) {
    if (dt > 0.1f) dt = 0.1f;
    for (int i = 0; i < 4; i++) {
        float h = dt / 4, sp = 4.3f;
        float cy = cosf(yaw), sy = sinf(yaw), len = sqrtf(fwd * fwd + strafe * strafe);
        float wx = (-sy * fwd + cy * strafe), wz = (-cy * fwd - sy * strafe);
        if (len > 1) { wx /= len; wz /= len; }
        float k = ground ? 18.f : 5.f;   // less control in the air
        Vel[0] += (wx * sp - Vel[0]) * fminf(1, k * h);
        Vel[2] += (wz * sp - Vel[2]) * fminf(1, k * h);
        if (jump && ground) Vel[1] = 8.4f;
        Vel[1] -= 28.f * h;
        if (Vel[1] < -50) Vel[1] = -50;
        ground = 0;
        move(0, Vel[0] * h); move(2, Vel[2] * h); move(1, Vel[1] * h);
    }
    raycast();
    matrices();
}

// button 0 = break, 2 = place `kind`. Returns 1 when the world changed (caller remeshes).
int click(int button, int kind) {
    if (!H[0]) return 0;
    if (button == 0) { if (H[2] == 0) return 0; W[H[1]][H[2]][H[3]] = AIR; raycast(); return 1; }
    int x = H[4], y = H[5], z = H[6];
    if (x < 0 || y < 0 || z < 0 || x >= N || y >= N || z >= N || kind <= AIR || kind >= NBLOCK) return 0;
    if (x + 1 > P[0] - 0.3f && x < P[0] + 0.3f && z + 1 > P[2] - 0.3f && z < P[2] + 0.3f && y + 1 > P[1] && y < P[1] + 1.8f) return 0;
    W[x][y][z] = (uint8_t)kind;
    raycast();
    return 1;
}

// Faces: +x -x +y -y +z -z; 4 corners each (unit cube coords).
static const int8_t FN[6][3] = { {1,0,0}, {-1,0,0}, {0,1,0}, {0,-1,0}, {0,0,1}, {0,0,-1} };
static const int8_t FC[6][4][3] = {
    {{1,0,0},{1,1,0},{1,1,1},{1,0,1}}, {{0,0,1},{0,1,1},{0,1,0},{0,0,0}},
    {{0,1,0},{0,1,1},{1,1,1},{1,1,0}}, {{0,0,0},{1,0,0},{1,0,1},{0,0,1}},
    {{1,0,1},{1,1,1},{0,1,1},{0,0,1}}, {{0,0,0},{0,1,0},{1,1,0},{1,0,0}} };

int mesh(void) {
    nv = 0;
    for (int x = 0; x < N; x++)
        for (int y = 0; y < N; y++)
            for (int z = 0; z < N; z++) {
                int b = W[x][y][z];
                if (!b) continue;
                for (int f = 0; f < 6; f++) {
                    int nx = x + FN[f][0], ny = y + FN[f][1], nz = z + FN[f][2];
                    if (block(nx, ny, nz) != AIR) continue;
                    if (ny < 0 || nv + 6 > MAXV) continue;
                    int ao[4];
                    for (int k = 0; k < 4; k++) {
                        int t[3] = { 0, 0, 0 }, u[3] = { 0, 0, 0 }, ti = -1;
                        for (int a = 0; a < 3; a++) {
                            if (FN[f][a]) continue;
                            int s = FC[f][k][a] ? 1 : -1;
                            if (ti < 0) { t[a] = s; ti = a; } else u[a] = s;
                        }
                        int s1 = block(nx + t[0], ny + t[1], nz + t[2]) != AIR;
                        int s2 = block(nx + u[0], ny + u[1], nz + u[2]) != AIR;
                        int cr = block(nx + t[0] + u[0], ny + t[1] + u[1], nz + t[2] + u[2]) != AIR;
                        ao[k] = (s1 && s2) ? 0 : 3 - (s1 + s2 + cr);
                    }
                    // split the quad along the brighter diagonal so AO doesn't crease
                    static const int A[6] = { 0, 1, 2, 0, 2, 3 }, B[6] = { 1, 2, 3, 1, 3, 0 };
                    const int *o = ao[0] + ao[2] >= ao[1] + ao[3] ? A : B;
                    for (int i = 0; i < 6; i++) {
                        int k = o[i];
                        Vert *v = &V[nv++];
                        v->x = x + FC[f][k][0]; v->y = y + FC[f][k][1]; v->z = z + FC[f][k][2];
                        v->a = (uint32_t)b | (uint32_t)f << 8 | (uint32_t)ao[k] << 12;
                    }
                }
            }
    return nv;
}

Vert *verts(void) { return V; }
float *view(void) { return VP; }
int *hit(void) { return H; }
float *player(void) { static float o[5]; o[0] = P[0]; o[1] = P[1]; o[2] = P[2]; o[3] = yaw; o[4] = pitch; return o; }
