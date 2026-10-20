// The renderer behind the D3D9 device. d3d9.c records one command list per frame; at Present a
// backend runs it: gpu_web.c hands it to web/gpu.js (WebGPU on the page's thread), gpu_soft.c runs
// it on the CPU for native off-screen shots. The list is the only contract between them.
#pragma once
#include <stdint.h>

// Command: [op | nwords << 8] then nwords payload words.
enum {
    GPU_TARGET = 1,     // id, width, height, kind (0 color, 1 depth/stencil)
    GPU_CLEAR = 2,      // color id (0 none), depth id (0 none), D3DCLEAR flags, ARGB, z (float bits), stencil, x0, y0, x1, y1
    GPU_PRESENT = 3,    // color id, width, height
    GPU_DRAW = 4,       // D3DPRIMITIVETYPE, primitive count, vertex shader, pixel shader (object ids; not drawn yet)
};

void gpu_cmd(int op, int n, const uint32_t *w);
void gpu_submit(void);                  // end of frame: run or hand off the list, then start a new one
void gpu_set_shot(const char *path);    // native: write every presented frame to this PNG

// Backend side: the frame's words.
void gpu_run(const uint32_t *w, uint32_t n);
