// The frame command list (see gpu.h) and its two backends.
// Web: Present hands the list to web/gpu.js through a mailbox in the shared heap; the page's thread
// runs it with WebGPU on its own event loop, so this worker never needs to yield to JavaScript.
// Native: a CPU backend runs the same list and writes the presented frame to a PNG (--shot).
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gpu.h"

static uint32_t *list;
static uint32_t nlist, cap;

void gpu_cmd(int op, int n, const uint32_t *w) {
    if (nlist + 1 + (uint32_t)n > cap) {
        cap = cap ? cap * 2 : 1u << 16;
        list = realloc(list, 4u * cap);
        if (!list) { fprintf(stderr, "gpu: out of memory\n"); exit(1); }
    }
    list[nlist++] = (uint32_t)op | (uint32_t)n << 8;
    memcpy(list + nlist, w, 4u * n);
    nlist += (uint32_t)n;
}

#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#include <emscripten/threading.h>

// seq = frames submitted, done = frames the page has run. Frame k lives in buf[k & 1]: the worker
// writes frame k+1 only after the page finished frame k-1, so one frame is in flight.
typedef struct { uint32_t seq, done, ptr[2], len[2]; } Mailbox;
static Mailbox box;
static uint32_t *buf[2], bufcap[2];

EMSCRIPTEN_KEEPALIVE uint32_t rn_gpu_mailbox(void) { return (uint32_t)(uintptr_t)&box; }

void gpu_set_shot(const char *path) { (void)path; }

void gpu_submit(void) {
    uint32_t k = (box.seq + 1) & 1;
    if (bufcap[k] < nlist) { bufcap[k] = nlist; buf[k] = realloc(buf[k], 4u * nlist); }
    memcpy(buf[k], list, 4u * nlist);
    box.ptr[k] = (uint32_t)(uintptr_t)buf[k];
    box.len[k] = nlist;
    nlist = 0;
    uint32_t n = __atomic_add_fetch(&box.seq, 1, __ATOMIC_SEQ_CST);
    for (;;) {
        uint32_t d = __atomic_load_n(&box.done, __ATOMIC_SEQ_CST);
        if (d + 1 >= n) break;
        emscripten_futex_wait(&box.done, d, 100);
    }
}
#else

// ---- CPU backend ------------------------------------------------------------------------------
typedef struct { uint32_t w, h, kind; uint32_t *color; float *z; uint8_t *stencil; } Target;
static Target targets[8193];     // ids are d3d9 object indexes + 1
static const char *shot;
static uint32_t draws, frames;

void gpu_set_shot(const char *path) { shot = path; }

static void png(const char *path, const uint32_t *argb, uint32_t w, uint32_t h);

void gpu_run(const uint32_t *w, uint32_t n) {
    for (uint32_t i = 0; i < n;) {
        uint32_t op = w[i] & 0xff, len = w[i] >> 8;
        const uint32_t *a = w + i + 1;
        i += 1 + len;
        if (op == GPU_TARGET) {
            Target *t = &targets[a[0]];
            free(t->color); free(t->z); free(t->stencil);
            *t = (Target){a[1], a[2], a[3], NULL, NULL, NULL};
            if (a[3] == 0) t->color = calloc((size_t)a[1] * a[2], 4);
            else { t->z = calloc((size_t)a[1] * a[2], 4); t->stencil = calloc((size_t)a[1] * a[2], 1); }
        } else if (op == GPU_CLEAR) {
            Target *rt = a[0] ? &targets[a[0]] : NULL, *ds = a[1] ? &targets[a[1]] : NULL;
            float z;
            memcpy(&z, &a[4], 4);
            for (uint32_t y = a[7]; y < a[9]; y++)
                for (uint32_t x = a[6]; x < a[8]; x++) {
                    if (rt && (a[2] & 1)) rt->color[y * rt->w + x] = a[3];
                    if (ds && (a[2] & 2)) ds->z[y * ds->w + x] = z;
                    if (ds && (a[2] & 4)) ds->stencil[y * ds->w + x] = (uint8_t)a[5];
                }
        } else if (op == GPU_DRAW) {
            draws++;
        } else if (op == GPU_PRESENT) {
            if (shot) png(shot, targets[a[0]].color, a[1], a[2]);
            if (draws && frames < 3) fprintf(stdout, "gpu: frame %u: %u draws not rendered (no draw path yet)\n", frames, draws);
            frames++;
            draws = 0;
        } else {
            fprintf(stderr, "gpu: unknown command %u\n", op);
            exit(1);
        }
    }
}

void gpu_submit(void) {
    gpu_run(list, nlist);
    nlist = 0;
}

// PNG with stored (uncompressed) deflate blocks: no zlib needed.
static uint32_t crc_tab[256];
static uint32_t crc(uint32_t c, const uint8_t *p, size_t n) {
    if (!crc_tab[1])
        for (uint32_t k = 0; k < 256; k++) {
            uint32_t v = k;
            for (int j = 0; j < 8; j++) v = v & 1 ? 0xedb88320u ^ (v >> 1) : v >> 1;
            crc_tab[k] = v;
        }
    c = ~c;
    while (n--) c = crc_tab[(c ^ *p++) & 0xff] ^ (c >> 8);
    return ~c;
}
static void be32(uint8_t *p, uint32_t v) { p[0] = v >> 24; p[1] = v >> 16; p[2] = v >> 8; p[3] = v; }
static void chunk(FILE *f, const char *type, const uint8_t *d, uint32_t n) {
    uint8_t h[8];
    be32(h, n);
    memcpy(h + 4, type, 4);
    fwrite(h, 1, 8, f);
    fwrite(d, 1, n, f);
    uint32_t v = crc(crc(0, h + 4, 4), d, n);
    be32(h, v);
    fwrite(h, 1, 4, f);
}
static void png(const char *path, const uint32_t *argb, uint32_t w, uint32_t h) {
    size_t row = 1 + 3 * (size_t)w, raw_n = row * h;
    uint8_t *raw = malloc(raw_n);
    for (uint32_t y = 0; y < h; y++) {
        uint8_t *r = raw + y * row;
        r[0] = 0;
        for (uint32_t x = 0; x < w; x++) {
            uint32_t v = argb[y * w + x];
            r[1 + 3 * x] = v >> 16; r[2 + 3 * x] = v >> 8; r[3 + 3 * x] = v;
        }
    }
    size_t nblk = (raw_n + 65534) / 65535, zn = 2 + raw_n + 5 * nblk + 4;
    uint8_t *z = malloc(zn), *q = z;
    *q++ = 0x78; *q++ = 0x01;
    uint32_t a = 1, b = 0;
    for (size_t off = 0; off < raw_n; off += 65535) {
        uint32_t n = raw_n - off < 65535 ? (uint32_t)(raw_n - off) : 65535;
        *q++ = off + n == raw_n;
        *q++ = n; *q++ = n >> 8; *q++ = ~n; *q++ = (~n) >> 8;
        memcpy(q, raw + off, n);
        q += n;
        for (uint32_t k = 0; k < n; k++) { a = (a + raw[off + k]) % 65521; b = (b + a) % 65521; }
    }
    be32(q, b << 16 | a);
    q += 4;
    FILE *f = fopen(path, "wb");
    if (!f) { fprintf(stderr, "gpu: cannot write %s\n", path); exit(1); }
    fwrite("\x89PNG\r\n\x1a\n", 1, 8, f);
    uint8_t ihdr[13];
    be32(ihdr, w); be32(ihdr + 4, h);
    ihdr[8] = 8; ihdr[9] = 2; ihdr[10] = ihdr[11] = ihdr[12] = 0;
    chunk(f, "IHDR", ihdr, 13);
    chunk(f, "IDAT", z, (uint32_t)(q - z));
    chunk(f, "IEND", NULL, 0);
    fclose(f);
    free(raw);
    free(z);
}
#endif
