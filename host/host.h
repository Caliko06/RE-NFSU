// Host layer: the Windows APIs Speed.exe imports, written against the documented API.
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "rt.h"

// Guest memory layout (no relocations in Speed.exe: the image must sit at 0x400000).
#define GUEST_MEM   0x40000000u     // 1 GB flat guest space
#define TEB_ADDR    0x00010000u
#define PEB_ADDR    0x00011000u
#define STR_ADDR    0x00012000u     // command line, environment, module name
#define STACK_LO    0x00300000u     // 1 MB main stack (SizeOfStackReserve)
#define STACK_HI    0x00400000u
#define IMAGE_BASE  0x00400000u
#define HEAP_LO     0x00800000u
#define HOST_BASE   0xe0000000u     // fake code addresses of host functions: HOST_BASE + 16*index

#include <dirent.h>

typedef uint32_t (*HostFn)(Ctx *c);
typedef struct { const char *dll, *name; int nargs; HostFn fn; } Api;   // nargs < 0: cdecl

extern Ctx *g_ctx;
extern const Api win32_apis[], user32_apis[], thread_apis[], net_apis[], d3d9_apis[], dinput8_apis[], dsound_apis[];
extern const int win32_api_count, user32_api_count, thread_api_count, net_api_count, d3d9_api_count, dinput8_api_count, dsound_api_count;

enum { H_FREE, H_FILE, H_EVENT, H_MUTEX, H_FIND, H_HEAP, H_THREAD, H_SNAPSHOT, H_KEY };
struct Thread;
typedef struct {
    int kind;
    int gf;                         // files: host/files.c id and the file pointer
    uint32_t pos;
    int signaled, manual;           // events; snapshot position
    uint32_t owner, count;          // mutexes
    struct Thread *thread;
    char path[512];
    DIR *dir;
    char pattern[256];
} Handle;
uint32_t new_handle(int kind);
Handle *get_handle(uint32_t h);

// Arguments of a stdcall/cdecl host function: [esp] = return address, [esp+4] = first argument.
#define ARG(n) ld(c, c->r[ESP] + 4 + 4 * (n), 4)
#define G(p) ((char *)c->mem + (uint32_t)(p))

const Api *find_api(const char *dll, const char *name);
uint32_t call_guest(Ctx *c, uint32_t fn, int n, const uint32_t *args);
uint32_t host_addr_of(const char *dll, const char *name);     // HOST_BASE address, registering if needed
void rn_halt(Ctx *c, const char *fmt, ...);
void rn_log(const char *fmt, ...);
int rn_trace(void);
void win32_init(Ctx *c, uint32_t image_size);
uint32_t guest_alloc(uint32_t size);                           // zeroed, for host-owned guest data
uint64_t now_us(void);
uint32_t virtual_reserve(Ctx *c, uint32_t size);
void gil_acquire(void);
void gil_release(void);
void gil_slice(void);                                          // preempt at an API call after a quantum
void threads_init(Ctx *main_ctx);
void rn_stop(Ctx *c);                                          // report the halt and end the process
void files_set_root(const char *dir);
int gf_stat(const char *gpath);                                // 0 file, 1 directory, -1 missing, -2 outside
int gf_open(const char *gpath);                                // id, or -1 missing, -2 outside, -3 directory
uint64_t gf_size(int id);
int64_t gf_read(int id, uint64_t off, uint8_t *dst, uint32_t n);
void gf_close(int id);
void set_error(Ctx *c, uint32_t e);
