// Read-only access to the game folder (C:\NFSU = game/) and the save folder (what the game keeps under
// CSIDL_COMMON_APPDATA\NFS Underground = save/ of this repo). Names match without case, like NTFS.
// Native: the folder on disk. Web: tools/serve.py; the game thread reads byte ranges with synchronous
// XHR (allowed in its worker), through a read-ahead buffer, so only what the game opens is fetched.
#include <ctype.h>
#include <sched.h>
#include <strings.h>
#include <unistd.h>
#include <sys/stat.h>
#include "host.h"

#define MAXF 256
#define AHEAD (256u << 10)
#define AHEAD_MAX (4u << 20)
// Save files live whole in memory (data): changed there, written back whole by gf_flush and gf_close.
typedef struct {
    int used, save, dirty, busy;
    uint64_t size, cap;
    char real[512];
    FILE *f;
    uint8_t *buf, *data;
    uint64_t buf_off, next;               // next: where the last request ended
    uint32_t buf_len, buf_cap, ahead;
} GFile;
static GFile files[MAXF];
static char root[1024], save_root[1024];

void files_set_root(const char *dir) {
    snprintf(root, sizeof root, "%s", dir);
#ifdef __EMSCRIPTEN__
    (void)dir;
    snprintf(save_root, sizeof save_root, "/save");               // web/saves.js mounts it in memory and keeps it in the browser (IndexedDB)
#else
    snprintf(save_root, sizeof save_root, "%s/../save", dir);
    mkdir(save_root, 0755);
#endif
}
// Native: every path is on disk. Web: only the save folder is (an in-memory FS saved in IndexedDB); game files are read over HTTP.
static int on_fs(const char *real) {
#ifdef __EMSCRIPTEN__
    return !strncmp(real, save_root, strlen(save_root));
#else
    (void)real;
    return 1;
#endif
}
#define SAVE_DIR "C:/Documents and Settings/All Users/Application Data/NFS Underground"

// C:\NFSU\a\b or a\b or .\a\b -> "a/b": 0 in the game folder, 1 in the save folder, -1 outside both.
// D:\ is the CD-ROM drive with the game disc in it; the OWNER's folder holds the disc files too.
static int game_rel(const char *gpath, char *rel, size_t n) {
    char p[512];
    snprintf(p, sizeof p, "%s", gpath);
    for (char *q = p; *q; q++) if (*q == '\\') *q = '/';
    const char *r = p;
    int save = 0, k = (int)strlen(SAVE_DIR);
    if (!strncasecmp(p, SAVE_DIR, k) && (p[k] == '/' || !p[k])) r = p + k + (p[k] == '/'), save = 1;
    else if (!strncasecmp(p, "C:/NFSU", 7) && (p[7] == '/' || !p[7])) r = p + 7 + (p[7] == '/');
    else if ((p[0] == 'D' || p[0] == 'd') && p[1] == ':' && (p[2] == '/' || !p[2])) r = p + 2 + (p[2] == '/');
    else if (p[0] && p[1] == ':') return -1;
    while (r[0] == '.' && r[1] == '/') r += 2;
    char *o = rel;
    for (; *r && (size_t)(o - rel) < n - 1; r++)
        if (!(*r == '/' && (o == rel || o[-1] == '/'))) *o++ = *r;     // drop empty components
    *o = 0;
    return save;
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
// Names in a directory, "name\tsize\n" (size -1 = a directory), into out; the count, or -1 no directory.
EM_JS(int, web_list, (const char *rel, char *out, int outsz), {
    var dir = UTF8ToString(rel).toLowerCase(), seen = new Map();
    var add = (p, n) => {
        var low = p.toLowerCase();
        if (dir && !low.startsWith(dir + '/')) return;
        var rest = p.slice(dir ? dir.length + 1 : 0), k = rest.indexOf('/');
        if (k < 0) seen.set(rest, n); else if (!seen.has(rest.slice(0, k))) seen.set(rest.slice(0, k), -1);
    };
    for (const [low, e] of Module.rnIndex.files) add(e[0], e[1]);
    var s = '';
    for (const [name, n] of seen) s += name + '\t' + n + '\n';
    stringToUTF8(s, out, outsz);
    return seen.size;
});
// real is "game/<path>".
EM_JS(int, web_read, (const char *real, double off, uint8_t *dst, int n), {
    var x = new XMLHttpRequest();
    x.open('GET', '/' + UTF8ToString(real).split('/').map(encodeURIComponent).join('/'), false);
    x.responseType = 'arraybuffer';
    x.setRequestHeader('Range', 'bytes=' + off + '-' + (off + n - 1));
    x.send();
    if (x.status !== 206) return -1;
    var a = new Uint8Array(x.response);
    HEAPU8.set(a, dst);
    return a.length;
});
#endif

int rn_world_alias(const char *gpath, char *out, size_t n) __attribute__((weak));   // host/openworld.c: a WORLD file is a shipped file of its base track

// 0 = found (size set), 1 = a directory, -1 = missing, -2 = outside the game and save folders.
static int lookup(const char *gpath, char *real, size_t n, uint64_t *size) {
    char rel[512], alt[512];
    if (rn_world_alias && rn_world_alias(gpath, alt, sizeof alt)) gpath = alt;
    int save = game_rel(gpath, rel, sizeof rel);
    if (save < 0) return -2;
#ifdef __EMSCRIPTEN__
    if (!save) {
    char g[512];
    double r = web_lookup(rel, g, sizeof g);
    if (r == -2) return 1;
    if (r < 0) return -1;
    snprintf(real, n, "game/%s", g);
    *size = (uint64_t)r;
    return 0;
    }
#endif
    {
    // Each component, matched without case against the directory on disk.
    snprintf(real, n, "%s", save ? save_root : root);
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
    }
}

// 0 = a file, 1 = a directory, -1 = missing, -2 = outside the game folder.
int gf_stat(const char *gpath) {
    char real[512];
    uint64_t size;
    return lookup(gpath, real, sizeof real, &size);
}

void rn_race_bridge(const char *gpath);   // host/bridge.c
int rn_world_open(const char *gpath, char *real, size_t n, uint64_t *size) __attribute__((weak));   // host/openworld.c (RN_WORLD=1, the WORLD entry)

// Opens a game file: id >= 0, or -1 missing, -2 outside the folder, -3 a directory.
int gf_open(const char *gpath) {
    char real[512];
    uint64_t size = 0;
    rn_race_bridge(gpath);
    int r = rn_world_open && rn_world_open(gpath, real, sizeof real, &size) ? 0 : lookup(gpath, real, sizeof real, &size);
    if (r) return r == 1 ? -3 : r;
    for (int k = 0; k < MAXF; k++) {
        GFile *g = &files[k];
        if (g->used) continue;
        memset(g, 0, sizeof *g);
        if (on_fs(real)) {
            g->f = fopen(real, "rb");
            if (!g->f) return -1;
        }
        g->used = 1;
        g->size = size;
        snprintf(g->real, sizeof g->real, "%s", real);
        return k;
    }
    return -1;
}
uint64_t gf_size(int id) { return files[id].size; }
void gf_close(int id) {
    gf_flush(id);
    if (files[id].f) fclose(files[id].f);
    free(files[id].buf);
    free(files[id].data);
    files[id].used = 0;
}
// Reads up to n bytes at off; returns the count (short at the end of the file), -1 on an I/O error.
#ifdef __EMSCRIPTEN__
// One request to the server, counted for the telemetry. The callers hold the GIL; ReadFile blocks only the calling
// thread on Windows, so the request runs without it and the other guest threads go on (the main loop drew nothing
// while the file thread 0x63e4d0 waited for the server: 1.1 s of the menu->race load, telemetry 2026-10-24).
// g->busy keeps a second thread off the same file (its read-ahead buffer) until the request is back (gf_read).
static int timed_read(GFile *g, uint64_t at, uint8_t *dst, uint32_t n) {
    g->busy = 1;
    gil_release();
    uint64_t t0 = now_us();
    int r = web_read(g->real, (double)at, dst, (int)n);
    uint64_t t1 = now_us();
    gil_acquire();
    g->busy = 0;
    rn_telem.read_ms += (double)(t1 - t0) / 1000;
    rn_telem.reads++;
    rn_telem.read_kb += (r > 0 ? (uint32_t)r : 0) >> 10;
    // A request this slow waited for a connection or the server (a movie or a track stream read as it plays).
    if (t1 - t0 > 100000) rn_log("files: slow read %s at %llu, %u bytes, %.0f ms", g->real, (unsigned long long)at, n, (t1 - t0) / 1000.0);
    return r;
}
#endif
int64_t gf_read(int id, uint64_t off, uint8_t *dst, uint32_t n) {
    GFile *g = &files[id];
    if (off >= g->size) return 0;
    if (n > g->size - off) n = (uint32_t)(g->size - off);
    if (g->save) { memcpy(dst, g->data + off, n); return n; }
#ifdef __EMSCRIPTEN__
    if (!g->f) {
    while (g->busy) { gil_release(); sched_yield(); gil_acquire(); }
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
        // A request costs ~2 ms on top of its bytes (telemetry 2026-10-24: 256 KB in 2.2-3.5 ms), and a track loads
        // in 256 KB steps. While the reads of a file run on in sequence the read-ahead doubles, up to AHEAD_MAX.
        uint32_t want = n - done;
        uint32_t ahead = g->ahead && at == g->next ? (g->ahead < AHEAD_MAX ? 2 * g->ahead : AHEAD_MAX) : AHEAD;
        g->ahead = ahead;
        if (want >= ahead) {        // large reads go straight to the destination
            int r = timed_read(g, at, dst + done, want);
            if (r <= 0) return -1;
            done += (uint32_t)r;
            g->next = at + (uint32_t)r;
            continue;
        }
        if (g->buf_cap < ahead) { free(g->buf); g->buf = malloc(ahead); g->buf_cap = ahead; g->buf_len = 0; }
        uint32_t len = g->size - at < ahead ? (uint32_t)(g->size - at) : ahead;
        int r = timed_read(g, at, g->buf, len);
        if (r <= 0) return -1;
        g->buf_off = at;
        g->buf_len = (uint32_t)r;
        g->next = at + (uint32_t)r;
    }
    return done;
    }
#endif
    if (fseeko(g->f, (off_t)off, SEEK_SET)) return -1;
    return (int64_t)fread(dst, 1, n, g->f);
}

// ---- writes: only inside the save folder; the game folder is read-only ------------------------

static int save_rel(const char *gpath, char *rel, size_t n) { return game_rel(gpath, rel, n); }

static int put_whole(const char *rel, const char *real, const uint8_t *p, uint64_t n) {
    (void)rel;
    FILE *f = fopen(real, "wb");
    if (!f) return -1;
    size_t w = n ? fwrite(p, 1, n, f) : 0;
    return fclose(f) || w != n ? -1 : 0;
}

// The real path (native) of a save path that may not exist yet: its parent must be a directory.
static int save_target(const char *gpath, char *rel, char *real, size_t n) {
    if (save_rel(gpath, rel, 512) != 1) return -2;
    char parent[600];
    snprintf(parent, sizeof parent, "%s", gpath);
    char *s = strrchr(parent, '\\');
    if (!s) s = strrchr(parent, '/');
    if (!s) return -2;
    *s = 0;
    char preal[512];
    uint64_t sz;
    if (lookup(parent, preal, sizeof preal, &sz) != 1) return -3;
    snprintf(real, n, "%s/%s", preal, s + 1);
    return 0;
}

int gf_create(const char *gpath, int disp, int *existed) {
    char rel[512], real[512];
    uint64_t size = 0;
    int r = lookup(gpath, real, sizeof real, &size), save = save_rel(gpath, rel, sizeof rel);
    if (r == -2 || save != 1) return r == -2 ? -2 : -5;     // outside, or the read-only game folder
    if (r == 1) return -3;
    *existed = r == 0;
    if (r == 0 && disp == 1) return -4;                       // CREATE_NEW
    if (r != 0 && (disp == 3 || disp == 5)) return -1;        // OPEN_EXISTING, TRUNCATE_EXISTING
    if (r != 0) {
        int t = save_target(gpath, rel, real, sizeof real);
        if (t) return t == -3 ? -6 : t;                       // -6: the folder does not exist
    }
    int k = 0;
    while (k < MAXF && files[k].used) k++;
    if (k == MAXF) return -1;
    GFile *g = &files[k];
    memset(g, 0, sizeof *g);
    g->used = g->save = 1;
    snprintf(g->real, sizeof g->real, "%s", real);
    g->cap = size > 4096 ? size : 4096;
    g->data = calloc(1, g->cap);
    if (r == 0 && disp != 2 && disp != 5) {                   // keep the contents
        FILE *f = fopen(real, "rb");
        if (!f || fread(g->data, 1, size, f) != size) { if (f) fclose(f); free(g->data); g->used = 0; return -1; }
        fclose(f);
        g->size = size;
    } else g->dirty = 1;                                      // created or truncated: exists from now on
    if (g->dirty) gf_flush(k);
    return k;
}

int gf_is_save(int id) { return files[id].save; }

int64_t gf_write(int id, uint64_t off, const uint8_t *src, uint32_t n) {
    GFile *g = &files[id];
    if (!g->save) return -1;
    if (off + n > g->cap) {
        uint64_t cap = g->cap;
        while (off + n > cap) cap *= 2;
        g->data = realloc(g->data, cap);
        memset(g->data + g->cap, 0, cap - g->cap);
        g->cap = cap;
    }
    memcpy(g->data + off, src, n);
    if (off + n > g->size) g->size = off + n;
    g->dirty = 1;
    return n;
}

int gf_truncate(int id, uint64_t size) {
    GFile *g = &files[id];
    if (!g->save) return -1;
    if (size > g->size) { uint8_t z = 0; if (gf_write(id, size - 1, &z, 1) < 0) return -1; }
    g->size = size;
    g->dirty = 1;
    return 0;
}

int gf_flush(int id) {
    GFile *g = &files[id];
    if (!g->save || !g->dirty) return 0;
    char rel[512];
    rel[0] = 0;
    if (put_whole(rel, g->real, g->data, g->size)) return -1;
    g->dirty = 0;
    return 0;
}

// 0 made, 1 already there, -1 the parent is missing, -2 outside the save folder.
int gf_mkdir(const char *gpath) {
    char rel[512], real[512];
    int r = gf_stat(gpath);
    if (r == 1) return 1;
    if (r == 0) return 1;
    int t = save_target(gpath, rel, real, sizeof real);
    if (t) return t == -3 ? -1 : -2;
    return mkdir(real, 0755) ? -1 : 0;
}

// 0 deleted, -1 missing, -2 outside the save folder.
int gf_delete(const char *gpath) {
    char rel[512], real[512];
    uint64_t size;
    if (save_rel(gpath, rel, sizeof rel) != 1) return -2;
    if (lookup(gpath, real, sizeof real, &size) != 0) return -1;
    return unlink(real) ? -1 : 0;
}

static int wild(const char *p, const char *s) {
    for (; *p; p++, s++) {
        if (*p == '*') { for (; ; s++) { if (wild(p + 1, s)) return 1; if (!*s) return 0; } }
        if (!*s || (*p != '?' && tolower((unsigned char)*p) != tolower((unsigned char)*s))) return 0;
    }
    return !*s;
}

// First entry of dir\pattern: 0 found (name, is_dir, size), -1 none, -2 outside both folders.
int gf_find(const char *gpath, char *name, size_t n, int *is_dir, uint64_t *size) {
    char dir[600];
    snprintf(dir, sizeof dir, "%s", gpath);
    char *s = strrchr(dir, '\\');
    if (!s) s = strrchr(dir, '/');
    const char *pat = s ? s + 1 : dir;
    char patc[256];
    snprintf(patc, sizeof patc, "%s", pat);
    if (s) *s = 0; else snprintf(dir, sizeof dir, ".");
    if (!strcmp(patc, "*.*")) snprintf(patc, sizeof patc, "*");
    char rel[512], real[512];
    uint64_t sz;
    int save = game_rel(dir, rel, sizeof rel);
    if (save < 0) return -2;
    int r = lookup(dir, real, sizeof real, &sz);
    if (r == -2) return -2;
    if (r != 1 && !(save && !*rel)) return -1;
#ifdef __EMSCRIPTEN__
    if (!save) {
    static char list[65536];
    if (web_list(rel, list, sizeof list) < 0) return -1;
    for (char *l = list; *l;) {
        char *e = strchr(l, '\n');
        *e = 0;
        char *t = strchr(l, '\t');
        *t = 0;
        double v = atof(t + 1);
        if (wild(patc, l)) { snprintf(name, n, "%s", l); *is_dir = v < 0; *size = v < 0 ? 0 : (uint64_t)v; return 0; }
        l = e + 1;
    }
    return -1;
    }
#endif
    DIR *d = opendir(real);
    if (!d) return -1;
    struct dirent *de;
    while ((de = readdir(d)))
        if (strcmp(de->d_name, ".") && strcmp(de->d_name, "..") && wild(patc, de->d_name)) {
            char p[1100];
            struct stat sb;
            snprintf(p, sizeof p, "%s/%s", real, de->d_name);
            stat(p, &sb);
            snprintf(name, n, "%s", de->d_name);
            *is_dir = S_ISDIR(sb.st_mode);
            *size = (uint64_t)sb.st_size;
            closedir(d);
            return 0;
        }
    closedir(d);
    return -1;
}

// State the layer keeps for the PC, not the game: save/<name> (DirectInput user maps). The whole file in
// dst (at most n bytes): its length, -1 missing. layer_store replaces it.
int layer_load(const char *name, uint8_t *dst, int n) {
    char p[600];
    snprintf(p, sizeof p, SAVE_DIR "/%s", name);
    int id = gf_open(p);
    if (id < 0) return -1;
    int64_t r = gf_read(id, 0, dst, gf_size(id) < (uint64_t)n ? (uint32_t)gf_size(id) : (uint32_t)n);
    gf_close(id);
    return (int)r;
}
int layer_store(const char *name, const uint8_t *src, int n) {
    char p[600];
    int existed;
    snprintf(p, sizeof p, SAVE_DIR "/%s", name);
    int id = gf_create(p, 2, &existed);                          // CREATE_ALWAYS
    if (id < 0) return -1;
    int r = gf_write(id, 0, src, (uint32_t)n) == n ? 0 : -1;
    gf_close(id);
    return r;
}
