// Read-only access to the game folder (C:\NFSU = game/). Names match without case, like NTFS.
// Native: the folder on disk. Web: tools/serve.py; the game thread reads byte ranges with synchronous
// XHR (allowed in its worker), through a read-ahead buffer, so only what the game opens is fetched.
#include <strings.h>
#include <sys/stat.h>
#include "host.h"

#define MAXF 256
#define AHEAD (256u << 10)
typedef struct { int used; uint64_t size; char real[512]; FILE *f; uint8_t *buf; uint64_t buf_off; uint32_t buf_len; } GFile;
static GFile files[MAXF];
static char root[1024];

void files_set_root(const char *dir) { snprintf(root, sizeof root, "%s", dir); }

// C:\NFSU\a\b or a\b or .\a\b -> "a/b". -1: outside the game folder.
static int game_rel(const char *gpath, char *rel, size_t n) {
    char p[512];
    snprintf(p, sizeof p, "%s", gpath);
    for (char *q = p; *q; q++) if (*q == '\\') *q = '/';
    const char *r = p;
    if (!strncasecmp(p, "C:/NFSU", 7) && (p[7] == '/' || !p[7])) r = p + 7 + (p[7] == '/');
    else if (p[0] && p[1] == ':') return -1;
    while (r[0] == '.' && r[1] == '/') r += 2;
    char *o = rel;
    for (; *r && (size_t)(o - rel) < n - 1; r++)
        if (!(*r == '/' && (o == rel || o[-1] == '/'))) *o++ = *r;     // drop empty components
    *o = 0;
    return 0;
}

#ifdef __EMSCRIPTEN__
#include <emscripten.h>
// Index of game/ from /game-files.json: lower-case path -> [real path, size]; directories too.
EM_JS(double, web_lookup, (const char *rel, char *real, int realsz), {
    if (!Module.rnIndex) {
        var x = new XMLHttpRequest();
        x.open('GET', '/game-files.json', false);
        x.send();
        var files = new Map(), dirs = new Set();
        for (const [p, n] of JSON.parse(x.responseText)) {
            var low = p.toLowerCase();
            files.set(low, [p, n]);
            var parts = low.split('/');
            for (var k = 1; k < parts.length; k++) dirs.add(parts.slice(0, k).join('/'));
        }
        Module.rnIndex = { files: files, dirs: dirs };
    }
    var key = UTF8ToString(rel).toLowerCase();
    var e = Module.rnIndex.files.get(key);
    if (!e) return Module.rnIndex.dirs.has(key) || key === '' ? -2 : -1;
    stringToUTF8(e[0], real, realsz);
    return e[1];
});
EM_JS(int, web_read, (const char *real, double off, uint8_t *dst, int n), {
    var x = new XMLHttpRequest();
    x.open('GET', '/game/' + UTF8ToString(real).split('/').map(encodeURIComponent).join('/'), false);
    x.responseType = 'arraybuffer';
    x.setRequestHeader('Range', 'bytes=' + off + '-' + (off + n - 1));
    x.send();
    if (x.status !== 206) return -1;
    var a = new Uint8Array(x.response);
    HEAPU8.set(a, dst);
    return a.length;
});
#endif

// 0 = found (size set), 1 = a directory, -1 = missing, -2 = outside the game folder.
static int lookup(const char *gpath, char *real, size_t n, uint64_t *size) {
    char rel[512];
    if (game_rel(gpath, rel, sizeof rel)) return -2;
#ifdef __EMSCRIPTEN__
    double r = web_lookup(rel, real, (int)n);
    if (r == -2) return 1;
    if (r < 0) return -1;
    *size = (uint64_t)r;
    return 0;
#else
    // Each component, matched without case against the directory on disk.
    snprintf(real, n, "%s", root);
    for (char *c = rel; *c;) {
        char *e = strchr(c, '/');
        if (e) *e = 0;
        size_t len = strlen(real);
        snprintf(real + len, n - len, "/%s", c);
        struct stat sb;
        if (stat(real, &sb)) {
            real[len] = 0;
            DIR *d = opendir(real);
            int found = 0;
            struct dirent *de;
            while (d && (de = readdir(d)))
                if (!strcasecmp(de->d_name, c)) { snprintf(real + len, n - len, "/%s", de->d_name); found = 1; break; }
            if (d) closedir(d);
            if (!found) return -1;
        }
        if (!e) break;
        c = e + 1;
    }
    struct stat sb;
    if (stat(real, &sb)) return -1;
    if (S_ISDIR(sb.st_mode)) return 1;
    *size = (uint64_t)sb.st_size;
    return 0;
#endif
}

// Opens a game file: id >= 0, or -1 missing, -2 outside the folder, -3 a directory.
int gf_open(const char *gpath) {
    char real[512];
    uint64_t size = 0;
    int r = lookup(gpath, real, sizeof real, &size);
    if (r) return r == 1 ? -3 : r;
    for (int k = 0; k < MAXF; k++) {
        GFile *g = &files[k];
        if (g->used) continue;
        memset(g, 0, sizeof *g);
#ifndef __EMSCRIPTEN__
        g->f = fopen(real, "rb");
        if (!g->f) return -1;
#endif
        g->used = 1;
        g->size = size;
        snprintf(g->real, sizeof g->real, "%s", real);
        return k;
    }
    return -1;
}
uint64_t gf_size(int id) { return files[id].size; }
void gf_close(int id) {
    if (files[id].f) fclose(files[id].f);
    free(files[id].buf);
    files[id].used = 0;
}
// Reads up to n bytes at off; returns the count (short at the end of the file), -1 on an I/O error.
int64_t gf_read(int id, uint64_t off, uint8_t *dst, uint32_t n) {
    GFile *g = &files[id];
    if (off >= g->size) return 0;
    if (n > g->size - off) n = (uint32_t)(g->size - off);
#ifdef __EMSCRIPTEN__
    uint32_t done = 0;
    while (done < n) {
        uint64_t at = off + done;
        if (g->buf && at >= g->buf_off && at < g->buf_off + g->buf_len) {
            uint32_t k = (uint32_t)(g->buf_off + g->buf_len - at);
            if (k > n - done) k = n - done;
            memcpy(dst + done, g->buf + (at - g->buf_off), k);
            done += k;
            continue;
        }
        uint32_t want = n - done;
        if (want >= AHEAD) {        // large reads go straight to the destination
            int r = web_read(g->real, (double)at, dst + done, (int)want);
            if (r <= 0) return -1;
            done += (uint32_t)r;
            continue;
        }
        if (!g->buf) g->buf = malloc(AHEAD);
        uint32_t len = g->size - at < AHEAD ? (uint32_t)(g->size - at) : AHEAD;
        int r = web_read(g->real, (double)at, g->buf, (int)len);
        if (r <= 0) return -1;
        g->buf_off = at;
        g->buf_len = (uint32_t)r;
    }
    return done;
#else
    if (fseeko(g->f, (off_t)off, SEEK_SET)) return -1;
    return (int64_t)fread(dst, 1, n, g->f);
#endif
}
