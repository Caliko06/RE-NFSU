// Voxels in Free Run (docs/voxel.md): the layout shared by host/voxel.c (game thread) and web/voxel/ (page).
// The page reads this struct straight from the wasm heap at rn_voxel_addr(); every offset below is in bytes.
#pragma once
#include <stdint.h>

#define VOX_CH 16                   // chunk edge in cells
#define VOX_CELLS 4096              // cells per chunk; index = x + 16 * (y + 16 * z), z up
#define VOX_SLOTS 1024              // chunk pool
#define VOX_MOBS 64                 // creatures
#define VOX_TYPES 16                // block ids 0..15 (docs/voxel.md)
#define VOX_SCALE 1.0f              // game units per cell (F-Speed measures the unit)

enum { B_AIR, B_ASPHALT, B_CONCRETE, B_BRICK, B_TREAD, B_SCRAP, B_TYRES, B_CRATE, B_BARRIER, B_SODIUM, B_NEON,
       B_GLASS, B_GRIT, B_OIL };

typedef struct {                    // 32 bytes
    int32_t cx, cy, cz;             // chunk coords: cells cx*16 .. cx*16+15
    uint32_t state;                 // 0 free, 1 live
    uint32_t version;               // +1 on any block or light change in this chunk (the page remeshes)
    uint32_t pad[3];               // pad[0]: edited by the player
} VoxSlot;

typedef struct {                    // 32 bytes
    uint32_t kind;                  // 0 none, 1 gutter rat, 2 lamp moth
    float x, y, z, yaw;             // game units, yaw in radians around z
    float anim;                     // 0..1 walk or wing phase
    uint32_t pad[2];
} VoxMob;

typedef struct {
    // header: 64 words (256 bytes)
    uint32_t magic;                 // +0   0x31584f56 'VOX1'
    uint32_t on;                    // +4   host: 1 while voxels are active (Free Run, RN_VOXEL on)
    uint32_t in_break, in_place;    // +8   page: presses so far (counters only grow; the host acts on the difference)
    uint32_t in_slot;               // +16  page: selected hotbar slot 0..8
    uint32_t hotbar[9];             // +20  page: block id per slot
    uint32_t frame;                 // +56  host: voxel frames run
    int32_t target[3];              // +60  host: targeted cell
    uint32_t target_ok;             // +72  host: 1 when target is valid
    int32_t face[3];                // +76  host: outward normal of the hit face (place goes to target + face)
    uint32_t inv[VOX_TYPES];        // +88  host: count per block id
    float eye[3];                   // +152 host: the voxel player's eye (camera until the pedestrian lands)
    uint32_t pad[64 - 41];
    VoxSlot slot[VOX_SLOTS];        // +256
    VoxMob mob[VOX_MOBS];           // +33024
    uint8_t block[VOX_SLOTS][VOX_CELLS];   // +35072
    uint8_t light[VOX_SLOTS][VOX_CELLS];   // +35072 + 4 MB; high nibble sky, low nibble block
} VoxShared;

_Static_assert(sizeof(VoxSlot) == 32 && sizeof(VoxMob) == 32, "vox layout");
_Static_assert(__builtin_offsetof(VoxShared, slot) == 256 && __builtin_offsetof(VoxShared, block) == 35072, "vox layout");

// GPU_VOXEL (host/gpu.h, 16) payload, 40 words: 0..15 View, 16..31 Projection (the guest camera block [0x7404c0] +0 and +0x40,
// D3D row vectors: clip = v * V * P), 32..34 target cell, 35 target_ok, 36 time in seconds (float), 37..39 face normal.

struct Ctx;
void vox_frame(struct Ctx *c);      // once per Free Run frame, before GPU_FXAA (host/d3d9.c): tick, then GPU_VOXEL
int vox_solid(int x, int y, int z); // 1 when the cell blocks movement
// Moves the box [lo, hi] by d, one axis at a time (z, then x, then y), stopping at solid cells; d is clipped in place.
// Returns a bit per blocked axis (1 x, 2 y, 4 z). The pedestrian calls it after the game's ground query.
int vox_sweep(const float lo[3], const float hi[3], float d[3]);
