// Original street-city blocks and shared storage; content: docs/voxel.md.
#include "host.h"
#include <math.h>
#include <string.h>
#include "gpu.h"
#include "voxel.h"

static VoxShared vox __attribute__((aligned(16))) = {.magic = 0x31584f56u};
#ifdef __EMSCRIPTEN__
#include <emscripten.h>
EMSCRIPTEN_KEEPALIVE uint32_t rn_voxel_addr(void) { return (uint32_t)(uintptr_t)&vox; }
#endif

static uint8_t light_cell_init(uint8_t block) {
    return block == B_AIR ? 0xF0 : 0;
}

static int chunk_coord(int x) {
    int q = x / VOX_CH;
    return q - (x % VOX_CH < 0);
}

static int chunk_slot(int cx, int cy, int cz, int create) {
    int free_slot = -1;
    for (int i = 0; i < VOX_SLOTS; i++) {
        VoxSlot *s = &vox.slot[i];
        if (!s->state) { if (free_slot < 0) free_slot = i; }
        else if (s->cx == cx && s->cy == cy && s->cz == cz) return i;
    }
    if (!create || free_slot < 0) return -1;
    VoxSlot *s = &vox.slot[free_slot];
    s->cx = cx; s->cy = cy; s->cz = cz;
    memset(vox.block[free_slot], B_AIR, VOX_CELLS);
    memset(vox.light[free_slot], light_cell_init(B_AIR), VOX_CELLS);
    s->version = 1; s->state = 1;
    return free_slot;
}

static uint8_t get_cell(int x, int y, int z) {
    int cx = chunk_coord(x), cy = chunk_coord(y), cz = chunk_coord(z);
    int s = chunk_slot(cx, cy, cz, 0);
    if (s < 0) return B_AIR;
    return vox.block[s][x - cx * VOX_CH + VOX_CH * (y - cy * VOX_CH + VOX_CH * (z - cz * VOX_CH))];
}

// B. Arnold, "Fast Flood Fill Lighting in a Blocky Voxel Game", Seed of Andromeda blog, 2015: add/remove flood-fill queues.
#define LIGHT_QUEUE_SIZE (1u << 16)
typedef struct {
    // Packed loaded-cell coordinates: local index 0..11, slot 12..21, value 22..25, channel 26 (0 block, 1 sky).
    uint32_t cell[LIGHT_QUEUE_SIZE];
    uint32_t head, tail;
} LightQueue;
static LightQueue light_add, light_remove;
static int light_stopped, light_overflow_logged, light_top;

static int light_open(uint8_t b) { return b == B_AIR || b == B_GLASS || b == B_OIL; }
static int light_emission(uint8_t b) { return b == B_SODIUM ? 14 : b == B_NEON ? 11 : 0; }
static int light_value(int cell, int sky) { return (vox.light[cell / VOX_CELLS][cell % VOX_CELLS] >> (4 * sky)) & 15; }

static void light_write(int cell, int sky, int value) {
    int s = cell / VOX_CELLS, n = cell % VOX_CELLS, shift = 4 * sky;
    uint8_t old = vox.light[s][n], next = (old & ~(15 << shift)) | (value << shift);
    if (old != next) { vox.light[s][n] = next; vox.slot[s].version++; }
}

static void light_push(LightQueue *q, int cell, int sky, int value) {
    if (light_stopped) return;
    if (q->tail - q->head == LIGHT_QUEUE_SIZE) {
        if (!light_overflow_logged) { rn_log("voxel light queue overflow; spreading stopped"); light_overflow_logged = 1; }
        light_stopped = 1;
        return;
    }
    q->cell[q->tail++ & (LIGHT_QUEUE_SIZE - 1)] = (uint32_t)cell | ((uint32_t)value << 22) | ((uint32_t)sky << 26);
}

// Neighbours never allocate chunks; a slot and local index also encode full world coordinates.
static int light_neighbour(int cell, int direction) {
    int s = cell / VOX_CELLS, n = cell % VOX_CELLS;
    int axis = direction / 2, step = direction & 1 ? 1 : -1, stride = 1 << (4 * axis);
    int local = (n >> (4 * axis)) & 15;
    if (local + step >= 0 && local + step < VOX_CH) return cell + step * stride;
    VoxSlot *slot = &vox.slot[s];
    int c[3] = {slot->cx, slot->cy, slot->cz};
    c[axis] += step;
    int next = chunk_slot(c[0], c[1], c[2], 0);
    return next < 0 ? -1 : next * VOX_CELLS + n - step * (VOX_CH - 1) * stride;
}

static void light_seed(int cell, int sky) {
    if (cell < 0 || light_stopped) return;
    int s = cell / VOX_CELLS, n = cell % VOX_CELLS;
    uint8_t b = vox.block[s][n];
    int source = sky ? 0 : light_emission(b);
    // Only the missing space above the highest loaded layer supplies sky. Sides and bottom are dark.
    if (sky && light_open(b) && n / (VOX_CH * VOX_CH) == VOX_CH - 1 && vox.slot[s].cz == light_top)
        source = b == B_OIL ? 13 : 15;
    int value = light_value(cell, sky);
    if (source > value) { light_write(cell, sky, source); value = source; }
    if (value) light_push(&light_add, cell, sky, value);
}

static void light_drain_remove(void) {
    while (!light_stopped && light_remove.head != light_remove.tail) {
        uint32_t entry = light_remove.cell[light_remove.head++ & (LIGHT_QUEUE_SIZE - 1)];
        int cell = entry & ((1u << 22) - 1), value = (entry >> 22) & 15, sky = (entry >> 26) & 1;
        for (int d = 0; d < 6 && !light_stopped; d++) {
            int next = light_neighbour(cell, d);
            if (next < 0) continue;
            int level = light_value(next, sky);
            if (!level) continue;
            uint8_t b = vox.block[next / VOX_CELLS][next % VOX_CELLS];
            if (!sky && light_emission(b)) { light_push(&light_add, next, sky, level); continue; }
            if (level < value || (sky && d == 4 && value == 15 && level == 15)) {
                light_write(next, sky, 0);
                light_push(&light_remove, next, sky, level);
            } else {
                light_push(&light_add, next, sky, level);
            }
        }
    }
}

static void light_drain_add(void) {
    while (!light_stopped && light_add.head != light_add.tail) {
        uint32_t entry = light_add.cell[light_add.head++ & (LIGHT_QUEUE_SIZE - 1)];
        int cell = entry & ((1u << 22) - 1), sky = (entry >> 26) & 1;
        // Removal can clear a queued border cell before this pass starts; use its surviving value.
        int value = light_value(cell, sky);
        if (!value) continue;
        for (int d = 0; d < 6 && !light_stopped; d++) {
            int next = light_neighbour(cell, d);
            if (next < 0) continue;
            uint8_t b = vox.block[next / VOX_CELLS][next % VOX_CELLS];
            if (!light_open(b)) continue;
            int level = sky && d == 4 && value == 15 && b != B_OIL ? 15 : value - (b == B_OIL ? 2 : 1);
            if (level > light_value(next, sky)) {
                light_write(next, sky, level);
                light_push(&light_add, next, sky, level);
            }
        }
    }
}

static uint8_t light_at(int x, int y, int z) {
    int cx = chunk_coord(x), cy = chunk_coord(y), cz = chunk_coord(z);
    int s = chunk_slot(cx, cy, cz, 0);
    if (s >= 0) return vox.light[s][x - cx * VOX_CH + VOX_CH * (y - cy * VOX_CH + VOX_CH * (z - cz * VOX_CH))];
    for (int i = 0; i < VOX_SLOTS; i++)
        if (vox.slot[i].state && vox.slot[i].cz >= cz) return 0;
    return 0xF0;
}

static void set_cell(int x, int y, int z, uint8_t block) {
    int c[3] = {chunk_coord(x), chunk_coord(y), chunk_coord(z)};
    int p[3] = {x - c[0] * VOX_CH, y - c[1] * VOX_CH, z - c[2] * VOX_CH};
    int s = chunk_slot(c[0], c[1], c[2], block != B_AIR);
    if (s < 0) return;
    int n = p[0] + VOX_CH * (p[1] + VOX_CH * p[2]);
    if (vox.block[s][n] == block) return;
    uint8_t old_light = vox.light[s][n];
    vox.block[s][n] = block;
    vox.slot[s].version++;
    for (int a = 0; a < 3; a++) {
        if (p[a] != 0 && p[a] != VOX_CH - 1) continue;
        int step = p[a] == 0 ? -1 : 1;
        c[a] += step;
        int next = chunk_slot(c[0], c[1], c[2], 0);
        if (next >= 0) vox.slot[next].version++;
        c[a] -= step;
    }
    light_add.head = light_add.tail = light_remove.head = light_remove.tail = 0;
    light_stopped = 0;
    light_top = vox.slot[s].cz;
    for (int i = 0; i < VOX_SLOTS; i++)
        if (vox.slot[i].state && vox.slot[i].cz > light_top) light_top = vox.slot[i].cz;
    int cell = s * VOX_CELLS + n;
    for (int sky = 0; sky < 2; sky++) {
        int value = (old_light >> (4 * sky)) & 15;
        if (!light_open(block) || value) {
            light_write(cell, sky, 0);
            if (value) light_push(&light_remove, cell, sky, value);
        }
    }
    light_drain_remove();
    light_write(cell, 0, light_emission(block));
    for (int sky = 0; sky < 2; sky++) {
        light_seed(cell, sky);
        for (int d = 0; d < 6; d++) light_seed(light_neighbour(cell, d), sky);
    }
    light_drain_add();
}

int vox_solid(int x, int y, int z) {
    uint8_t b = get_cell(x, y, z);
    return b != B_AIR && b != B_OIL;
}

// Axis slabs: https://pbr-book.org/4ed/Shapes/Basic_Shape_Interface#RayBoundsIntersections ; sweep each box face against cell slabs.
int vox_sweep(const float lo[3], const float hi[3], float d[3]) {
    const float eps = 1e-3f;
    const int order[3] = {2, 0, 1};
    float l[3], h[3];
    memcpy(l, lo, sizeof l); memcpy(h, hi, sizeof h);
    int blocked = 0;
    for (int pass = 0; pass < 3; pass++) {
        int a = order[pass], low[3], high[3];
        float move = d[a];
        if (move == 0) continue;
        for (int k = 0; k < 3; k++) {
            low[k] = (int)floorf(l[k] + eps);
            high[k] = (int)floorf(h[k] - eps);
        }
        low[a] = (int)floorf(move > 0 ? h[a] : l[a] + move - eps);
        high[a] = (int)floorf(move > 0 ? h[a] + move + eps : l[a]);
        for (int z = low[2]; z <= high[2]; z++)
            for (int y = low[1]; y <= high[1]; y++)
                for (int x = low[0]; x <= high[0]; x++) {
                    if (!vox_solid(x, y, z)) continue;
                    int p[3] = {x, y, z};
                    if (move > 0 && p[a] >= h[a] - eps) {
                        float gap = fmaxf(0, p[a] - h[a] - eps);
                        if (gap < d[a]) d[a] = gap;
                    } else if (move < 0 && p[a] + 1 <= l[a] + eps) {
                        float gap = fminf(0, p[a] + 1 - l[a] + eps);
                        if (gap > d[a]) d[a] = gap;
                    }
                }
        if (d[a] != move) blocked |= 1 << a;
        l[a] += d[a]; h[a] += d[a];
    }
    return blocked;
}

static void test_structure(int x, int y, int z) {
    for (int j = -4; j <= 4; j++)
        for (int i = -4; i <= 4; i++) set_cell(x + i, y + j, z, B_CONCRETE);
    for (int k = 1; k <= 4; k++)
        for (int j = -1; j <= 1; j++)
            for (int i = -1; i <= 1; i++) set_cell(x + i, y + j, z + k, B_BRICK);
    for (int i = -4; i <= 4; i++) set_cell(x + i, y + 3, z + 1, B_TREAD);
    // The display line follows the south edge and continues past its end.
    for (int b = 1; b <= B_OIL; b++) set_cell(x - 5 + b, y - 4, z + 1, b);
    set_cell(x, y, z + 5, B_SODIUM);
    for (int i = -1; i <= 1; i++) set_cell(x + i, y + 2, z + 2, B_GLASS);
}

// The player's node in the race list [0x7361f8] (host/free.c): its entrant (+0x14) has kind 1 at +4.
static uint32_t player_node(Ctx *c) {
    uint32_t h = ld(c, 0x7361f8, 4);
    if (!h || h >= GUEST_MEM - 0x1000) return 0;
    for (uint32_t r = ld(c, h, 4), k = 0; r && r != h && r < GUEST_MEM - 0x1000 && k < 200; r = ld(c, r, 4), k++) {
        uint32_t e = ld(c, r + 0x14, 4);
        if (e && e < GUEST_MEM - 16 && ld(c, e + 4, 4) == 1) return r;
    }
    return 0;
}

// J. Amanatides and A. Woo, "A Fast Voxel Traversal Algorithm for Ray Tracing", Eurographics 1987: https://www.cse.yorku.ca/~amana/research/grid.pdf
static void target_ray(const float forward[3]) {
    int p[3], step[3];
    float next[3], delta[3];
    vox.target_ok = 0;
    memset(vox.face, 0, sizeof vox.face);
    for (int a = 0; a < 3; a++) {
        p[a] = (int)floorf(vox.eye[a]);
        step[a] = forward[a] > 0 ? 1 : forward[a] < 0 ? -1 : 0;
        delta[a] = step[a] ? fabsf(1 / forward[a]) : INFINITY;
        next[a] = step[a] ? (p[a] + (step[a] > 0) - vox.eye[a]) / forward[a] : INFINITY;
    }
    if (vox_solid(p[0], p[1], p[2])) return;
    if (get_cell(p[0], p[1], p[2]) == B_OIL) {
        memcpy(vox.target, p, sizeof p); vox.target_ok = 1;
        return;
    }
    for (;;) {
        int a = next[0] <= next[1] ? 0 : 1;
        if (next[2] < next[a]) a = 2;
        if (next[a] > 12) return;
        p[a] += step[a]; next[a] += delta[a];
        if (get_cell(p[0], p[1], p[2]) == B_AIR) continue;
        memcpy(vox.target, p, sizeof p);
        vox.face[a] = -step[a]; vox.target_ok = 1;
        return;
    }
}

static void collision_probe(int x, int y, int z) {
    // The centre lamp's top is z+6; start the box's feet three cells above it.
    float lo[3] = {x + 0.2f, y + 0.2f, z + 9.0f};
    float hi[3] = {x + 0.8f, y + 0.8f, z + 10.8f};
    float d[3] = {0, 0, -6};
    int blocked = vox_sweep(lo, hi, d);
    rn_log("voxel probe drop d %.3f %.3f %.3f blocked %d", d[0], d[1], d[2], blocked);
    // The tower's west face is x-1; start the box's east face three cells west.
    lo[0] = x - 4.6f; hi[0] = x - 4.0f;
    lo[2] = z + 2.0f; hi[2] = z + 3.8f;
    d[0] = 6; d[2] = 0;
    blocked = vox_sweep(lo, hi, d);
    rn_log("voxel probe slide d %.3f %.3f %.3f blocked %d", d[0], d[1], d[2], blocked);
}

void vox_frame(Ctx *c) {
    static int enabled = -1, built, initialized, demo, probe, light_test;
    static int light_anchor[3];
    static uint32_t last_break, last_place, built_frame;
    if (enabled < 0) {
        const char *e = getenv("RN_VOXEL"); enabled = !e || strcmp(e, "0");
        demo = rn_env("RN_VOXDEMO", 0) == 1;
        probe = rn_env("RN_VOXPROBE", 0) == 1;
        const char *light_env = getenv("RN_VOXLIGHT");
        light_test = light_env && !strcmp(light_env, "1");
    }
    vox.on = 0;
    if (!enabled || ld(c, 0x777cc8, 4) != 3) return;
    uint32_t node = player_node(c);
    // The player's view [0x7404c0]: View +0, Projection +0x40. Checked by projecting the car through the 6 view-table entries
    // (0x740460 + 0x60 k): only k 1 and 4 hold a projection, and k 1 draws voxels in register with the street (build/voxel_s3.png).
    uint32_t blk = ld(c, 0x7404c0, 4);
    if (!blk || blk >= GUEST_MEM - 0x80) return;
    float m[32];
    for (int k = 0; k < 32; k++) m[k] = ldf(c, blk + 4 * k);
    vox.on = 1;
    for (int j = 0; j < 3; j++)
        vox.eye[j] = -(m[12] * m[4 * j] + m[13] * m[4 * j + 1] + m[14] * m[4 * j + 2]);
    if (!initialized) {
        static const uint32_t defaults[9] = {2, 3, 4, 7, 8, 9, 10, 11, 13};
        uint32_t assigned = 0;
        for (int b = 1; b <= B_OIL; b++) vox.inv[b] = 30;
        for (int i = 0; i < 9; i++) assigned |= vox.hotbar[i];
        if (!assigned) memcpy(vox.hotbar, defaults, sizeof defaults);
        last_break = vox.in_break; last_place = vox.in_place; initialized = 1;
    }
    float forward[3] = {m[2], m[6], m[10]};
    float len = sqrtf(forward[0] * forward[0] + forward[1] * forward[1] + forward[2] * forward[2]);
    if (len > 0) for (int a = 0; a < 3; a++) forward[a] /= len;
    if (!built && vox.frame >= 90) {
        if (node) {
            float pos[3], heading[3];
            for (int a = 0; a < 3; a++) {
                pos[a] = ldf(c, node + 0x50 + 4 * a);
                heading[a] = ldf(c, node + 0x90 + 4 * a);
            }
            heading[2] = 0;
            float hlen = hypotf(heading[0], heading[1]);
            if (hlen < 1e-5f) {
                heading[0] = forward[0]; heading[1] = forward[1];
                hlen = hypotf(heading[0], heading[1]);
            }
            if (hlen > 0) { heading[0] /= hlen; heading[1] /= hlen; }
            int x = (int)floorf(pos[0] + 9 * heading[0]), y = (int)floorf(pos[1] + 9 * heading[1]);
            int z = (int)floorf(pos[2] - 0.5f);
            test_structure(x, y, z); built = 1; built_frame = vox.frame;
            light_anchor[0] = x; light_anchor[1] = y; light_anchor[2] = z;
            rn_log("voxel anchor %d %d %d car %.3f %.3f %.3f heading %.3f %.3f %.3f", x, y, z,
                   pos[0], pos[1], pos[2], heading[0], heading[1], heading[2]);
            if (probe) collision_probe(x, y, z);
        }
    }
    target_ray(forward);
    int do_break = vox.in_break - last_break != 0;
    int do_place = vox.in_place - last_place != 0;
    last_break = vox.in_break; last_place = vox.in_place;
    if (demo && built) {
        if (vox.frame - built_frame == 240) do_break = 1;
        if (vox.frame - built_frame == 300) do_place = 1;
    }
    if (do_break && vox.target_ok) {
        int x = vox.target[0], y = vox.target[1], z = vox.target[2];
        uint8_t b = get_cell(x, y, z);
        if (b > B_AIR && b <= B_OIL) {
            set_cell(x, y, z, B_AIR);
            if (vox.inv[b] < 999) vox.inv[b]++;
            rn_log("voxel break %d %d %d %u", x, y, z, (unsigned)b);
        }
    }
    if (do_place && vox.target_ok) {
        int p[3], inside = 1;
        const float low[3] = {-0.3f, -0.3f, -1.6f}, high[3] = {0.3f, 0.3f, 0.2f};
        for (int a = 0; a < 3; a++) {
            p[a] = vox.target[a] + vox.face[a];
            if (p[a] + 1 <= vox.eye[a] + low[a] || p[a] >= vox.eye[a] + high[a]) inside = 0;
        }
        uint32_t b = vox.hotbar[vox.in_slot > 8 ? 8 : vox.in_slot];
        uint8_t old = get_cell(p[0], p[1], p[2]);
        if (!inside && (old == B_AIR || old == B_OIL) && b > B_AIR && b <= B_OIL && vox.inv[b]) {
            set_cell(p[0], p[1], p[2], (uint8_t)b);
            if (get_cell(p[0], p[1], p[2]) == b) {
                vox.inv[b]--;
                rn_log("voxel place %d %d %d %u", p[0], p[1], p[2], (unsigned)b);
            }
        }
    }
    if (light_test && built) {
        uint32_t age = vox.frame - built_frame;
        int x = light_anchor[0], y = light_anchor[1], z = light_anchor[2];
        if (age == 360)
            rn_log("voxel light frame 360 above %02x beside %02x under_top %02x",
                   (unsigned)light_at(x, y, z + 6), (unsigned)light_at(x + 3, y, z + 3),
                   (unsigned)light_at(x, y, z + 4));
        if (age == 420) set_cell(x, y, z + 5, B_AIR);
        if (age == 421)
            rn_log("voxel light frame 421 above_removed %02x block %u under_top %02x",
                   (unsigned)light_at(x, y, z + 6), (unsigned)(light_at(x, y, z + 6) & 15),
                   (unsigned)light_at(x, y, z + 4));
    }
    uint32_t w[40] = {0};
    memcpy(w, m, sizeof m);
    memcpy(w + 32, vox.target, sizeof vox.target);
    w[35] = vox.target_ok;
    memcpy(w + 37, vox.face, sizeof vox.face);
    float time = vox.frame / 60.0f;
    memcpy(w + 36, &time, sizeof time);
    gpu_cmd(GPU_VOXEL, 40, w);
    vox.frame++;
}
