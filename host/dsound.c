// dsound: DirectSoundCreate and the sound buffers, as documented by Microsoft (DirectX 9.0b).
// The PC has one stereo output at 44.1 kHz with a software mixer (no hardware buffers). Buffers live in
// guest memory, so Lock hands out pointers into them, and the mixer reads them the way a sound card
// reads its DMA buffers: from its own thread, while the game runs. The mixer keeps LEAD frames ahead
// of the wall clock; the play cursor is what sounds now, the write cursor is what is already mixed.
// Output: web = a ring in the shared heap that web/audio.js plays; native = RN_WAV=out.wav records it.
#include <math.h>
#include <pthread.h>
#include <time.h>
#include "host.h"

#define DS_OK 0u
#define DSERR_INVALIDPARAM 0x80070057u
#define DSERR_INVALIDCALL 0x88780032u
#define DSERR_BADFORMAT 0x88780064u
#define DSERR_NOINTERFACE 0x80004002u
#define DSERR_PRIOLEVELNEEDED 0x88780046u
#define RATE 44100
#define LEAD 2048                       // frames mixed ahead of the clock (46 ms)

#define TR(...) do { if (rn_trace()) rn_log("dsound " __VA_ARGS__); } while (0)

enum { I_DS, I_BUF, I_N };
#define UNK "QueryInterface", "AddRef", "Release"
static const char *const m_ds[] = {UNK, "CreateSoundBuffer", "GetCaps", "DuplicateSoundBuffer", "SetCooperativeLevel",
    "Compact", "GetSpeakerConfig", "SetSpeakerConfig", "Initialize", 0};
static const char *const m_buf[] = {UNK, "GetCaps", "GetCurrentPosition", "GetFormat", "GetVolume", "GetPan",
    "GetFrequency", "GetStatus", "Initialize", "Lock", "Play", "SetCurrentPosition", "SetFormat", "SetVolume",
    "SetPan", "SetFrequency", "Stop", "Unlock", "Restore", 0};
static const char *const iface_name[I_N] = {"IDirectSound", "IDirectSoundBuffer"};
static const char *const *const iface_methods[I_N] = {m_ds, m_buf};
static uint32_t vtables[I_N];

static uint32_t vtable(int i) {
    if (vtables[i]) return vtables[i];
    int n = 0;
    while (iface_methods[i][n]) n++;
    uint32_t v = guest_alloc(4u * n);
    for (int k = 0; k < n; k++) {
        char name[96];
        snprintf(name, sizeof name, "%s::%s", iface_name[i], iface_methods[i][k]);
        st(g_ctx, v + 4u * k, host_addr_of("dsound.dll", name), 4);
    }
    return vtables[i] = v;
}

// A buffer: PCM data in guest memory. pos = play position in frames (fractional: resampling).
typedef struct {
    int iface, primary, playing, looping;
    uint32_t refs, guest, flags, data, size;
    int owner;                          // the IDirectSound object that created it (objs index)
    uint16_t channels, bits, align;
    uint32_t rate, freq;                // format rate; SetFrequency (0 = the format rate)
    int32_t volume, pan;                // hundredths of a dB
    double pos;
    double since_unlock;                // telemetry: frames played since the last Unlock (a stream refills by Unlock)
    uint32_t unlocks;
} Obj;
#define MAXO 512
static Obj objs[MAXO];
static int nobjs;
static pthread_mutex_t mx = PTHREAD_MUTEX_INITIALIZER;     // buffer play state, shared with the mixer
static int32_t master = 0;              // primary buffer volume

static uint32_t new_obj(Ctx *c, int iface) {
    if (nobjs == MAXO) { rn_halt(c, "dsound: too many objects"); return 0; }
    Obj *o = &objs[nobjs];
    memset(o, 0, sizeof *o);
    o->iface = iface; o->refs = 1;
    o->guest = guest_alloc(16);
    st(c, o->guest, vtable(iface), 4);
    st(c, o->guest + 4, (uint32_t)nobjs + 1, 4);
    nobjs++;
    return o->guest;
}
static Obj *obj_of(Ctx *c, uint32_t p, int iface) {
    uint32_t k = p ? ld(c, p + 4, 4) - 1 : ~0u;
    if (k < (uint32_t)nobjs && objs[k].guest == p && objs[k].iface == iface) return &objs[k];
    rn_halt(c, "dsound: %08x is not a live %s", p, iface_name[iface]);
    return NULL;
}
#define SELF(iface) Obj *o = obj_of(c, ARG(0), iface); if (!o) return DSERR_INVALIDPARAM

static Obj *any_obj(Ctx *c);
// QueryInterface: an object answers for IUnknown and its own interface. IKsPropertySet (EAX and other
// driver property sets) exists only on hardware buffers, and every buffer here is a software one.
static const struct { uint32_t d1, d2, d3; int iface; } iids[] = {
    {0x00000000u, 0x0000, 0x0000, -1},             // IUnknown {00000000-0000-0000-C000-000000000046}
    {0x279afa83u, 0x4981, 0x11ce, I_DS},           // IDirectSound
    {0x279afa85u, 0x4981, 0x11ce, I_BUF},          // IDirectSoundBuffer
    {0x31efac30u, 0x515c, 0x11d0, -2},             // IKsPropertySet
};
static uint32_t QueryInterface_(Ctx *c) {
    uint32_t g = ARG(1), out_p = ARG(2), d1 = ld(c, g, 4), d2 = ld(c, g + 4, 2), d3 = ld(c, g + 6, 2);
    Obj *o = any_obj(c);
    if (!o || !out_p) return DSERR_INVALIDPARAM;
    st(c, out_p, 0, 4);
    for (unsigned k = 0; k < sizeof iids / sizeof iids[0]; k++) {
        if (iids[k].d1 != d1 || iids[k].d2 != d2 || iids[k].d3 != d3) continue;
        if (iids[k].iface == -2 || (iids[k].iface >= 0 && iids[k].iface != o->iface)) {
            TR("QueryInterface({%08x-...}) on %s -> E_NOINTERFACE", d1, iface_name[o->iface]);
            return DSERR_NOINTERFACE;
        }
        o->refs++;
        st(c, out_p, ARG(0), 4);
        return DS_OK;
    }
    rn_halt(c, "dsound: QueryInterface for {%08x-%04x-%04x-...} on %s", d1, d2, d3, iface_name[o->iface]);
    return DSERR_NOINTERFACE;
}
static Obj *any_obj(Ctx *c) {
    uint32_t k = ld(c, ARG(0) + 4, 4) - 1;
    if (k < (uint32_t)nobjs && objs[k].guest == ARG(0)) return &objs[k];
    rn_halt(c, "dsound: %08x is not a live object", ARG(0));
    return NULL;
}
static uint32_t AddRef_(Ctx *c) { Obj *o = any_obj(c); return o ? ++o->refs : 0; }
// The last Release stops the buffer; its memory stays (guest memory, not reused). The last Release of
// an IDirectSound releases every buffer it created (DirectSound docs; Wine frees them too). Speed.exe
// 0x653d50 lets go of its stream buffer only this way: without it the old stream loops forever.
static uint32_t Release_(Ctx *c) {
    Obj *o = any_obj(c);
    if (!o || !o->refs) return 0;
    if (!--o->refs) {
        int self = (int)(o - objs);
        pthread_mutex_lock(&mx);
        o->playing = 0;
        if (o->iface == I_DS)
            for (int k = 0; k < nobjs; k++)
                if (objs[k].iface == I_BUF && objs[k].owner == self && objs[k].refs) { objs[k].refs = 0; objs[k].playing = 0; }
        pthread_mutex_unlock(&mx);
    }
    return o->refs;
}

// ---- the mixer -------------------------------------------------------------------------------
static float out[2 * 4096];
#ifdef __EMSCRIPTEN__
#include <emscripten.h>
// Header: frames written (mixer), frames taken (web/audio.js), ring address, ring size in stereo float frames.
#define RING 16384
static float ring[2 * RING];
static uint32_t ring_hdr[8];            // [4] frames of silence the page played (underruns), [5] resyncs: web/audio.js
EMSCRIPTEN_KEEPALIVE uint32_t rn_audio_ring(void) {
    ring_hdr[2] = (uint32_t)(uintptr_t)ring;
    ring_hdr[3] = RING;
    return (uint32_t)(uintptr_t)ring_hdr;
}
static void emit(const float *f, uint32_t n) {
    uint32_t w = ring_hdr[0];
    for (uint32_t k = 0; k < n; k++, w++) { ring[2 * (w % RING)] = f[2 * k]; ring[2 * (w % RING) + 1] = f[2 * k + 1]; }
    __atomic_store_n(&ring_hdr[0], w, __ATOMIC_RELEASE);
}
#else
static FILE *wav;
static uint32_t wav_frames;
static void emit(const float *f, uint32_t n) {
    if (!wav) return;
    int16_t s[2 * 4096];
    for (uint32_t k = 0; k < 2 * n; k++) {
        float v = f[k] < -1 ? -1 : f[k] > 1 ? 1 : f[k];
        s[k] = (int16_t)lrintf(v * 32767);
    }
    fwrite(s, 4, n, wav);
    wav_frames += n;
    uint32_t data = wav_frames * 4, riff = 36 + data;
    fseek(wav, 4, SEEK_SET); fwrite(&riff, 4, 1, wav);
    fseek(wav, 40, SEEK_SET); fwrite(&data, 4, 1, wav);
    fseek(wav, 0, SEEK_END);
    fflush(wav);
}
static void open_wav(void) {
    const char *p = getenv("RN_WAV");
    if (!p || !(wav = fopen(p, "wb"))) return;
    // RIFF/WAVE, PCM, 2 channels, 44100 Hz, 16 bits; sizes are rewritten after each write.
    uint8_t h[44] = {'R', 'I', 'F', 'F', 0, 0, 0, 0, 'W', 'A', 'V', 'E', 'f', 'm', 't', ' ', 16, 0, 0, 0, 1, 0, 2, 0,
                     0x44, 0xac, 0, 0, 0x10, 0xb1, 2, 0, 4, 0, 16, 0, 'd', 'a', 't', 'a', 0, 0, 0, 0};
    fwrite(h, 1, 44, wav);
}
#endif

static float gain(int32_t v) { return v <= -10000 ? 0.0f : powf(10.0f, (float)v / 2000.0f); }
static float sample(const Obj *o, uint32_t frame, int ch) {
    const uint8_t *p = g_ctx->mem + o->data + (size_t)frame * o->align + (o->channels == 2 ? ch : 0) * (o->bits / 8);
    if (o->bits == 8) return ((int)p[0] - 128) / 128.0f;
    int16_t s;
    memcpy(&s, p, 2);
    return s / 32768.0f;
}
// Frame a+d of a buffer: wraps when it loops, else holds the first or last frame.
static uint32_t at(const Obj *o, uint32_t frames, uint32_t a, int d) {
    int64_t i = (int64_t)a + d;
    if (o->looping) return (uint32_t)((i % frames + frames) % frames);
    return i < 0 ? 0 : i >= frames ? frames - 1 : (uint32_t)i;
}
// 4-point, 3rd-order Hermite between frames a and a+1 (t in [0,1)); t = 0 gives frame a exactly.
static float hermite(const Obj *o, uint32_t frames, uint32_t a, float t, int ch) {
    float ym = sample(o, at(o, frames, a, -1), ch), y0 = sample(o, a, ch);
    float y1 = sample(o, at(o, frames, a, 1), ch), y2 = sample(o, at(o, frames, a, 2), ch);
    float c1 = 0.5f * (y1 - ym), c2 = ym - 2.5f * y0 + 2 * y1 - 0.5f * y2, c3 = 0.5f * (y2 - ym) + 1.5f * (y0 - y1);
    return ((c3 * t + c2) * t + c1) * t + y0;
}
// Mixes n frames of every playing buffer into out[] and moves the buffers on. Called with mx held.
static void mix(uint32_t n) {
    memset(out, 0, 8u * n);
    float m = gain(master);
    for (int k = 0; k < nobjs; k++) {
        Obj *o = &objs[k];
        if (o->iface != I_BUF || o->primary || !o->playing || !o->size) continue;
        uint32_t frames = o->size / o->align;
        double step = (double)(o->freq ? o->freq : o->rate) / RATE;
        float g = gain(o->volume) * m;
        float gl = g * (o->pan > 0 ? gain(-o->pan) : 1), gr = g * (o->pan < 0 ? gain(o->pan) : 1);
        for (uint32_t j = 0; j < n; j++) {
            uint32_t a = (uint32_t)o->pos;
            float t = (float)(o->pos - a);
            out[2 * j] += gl * hermite(o, frames, a, t, 0);
            out[2 * j + 1] += gr * hermite(o, frames, a, t, 1);
            o->pos += step;
            o->since_unlock += step;
            if (o->pos >= frames) {
                if (o->looping) o->pos -= frames * floor(o->pos / frames);
                else { o->playing = 0; o->pos = 0; break; }   // Wine resets the cursor at the end: check
            }
        }
        if (o->looping && o->unlocks >= 2) {                // a stream: the game refills it as it plays
            uint32_t pm = (uint32_t)(1000 * o->since_unlock / frames);
            if (pm > rn_telem.stream_pm) rn_telem.stream_pm = pm;
            if (o->since_unlock >= frames && o->since_unlock - n * step < frames) {
                rn_telem.starves++; rn_telem.starve_buf = (uint32_t)k;
                if (rn_telem.starves <= 20)
                    rn_log("dsound stream %d: a whole lap with no Unlock (%u frames, %u Hz, %u ch, %u Unlocks)", k, frames,
                           o->freq ? o->freq : o->rate, o->channels, o->unlocks);
                if (rn_telem.starves <= 5) dispatch_threads_report();
            }
        }
    }
}
static uint64_t mixed;                  // frames mixed since the device was created
static uint64_t clock_frames(void) { return now_us() * RATE / 1000000; }
static void *mixer(void *arg) {
    (void)arg;
    mixed = clock_frames();
    for (;;) {
        uint64_t want = clock_frames() + LEAD;
        while (mixed < want) {
            uint32_t n = want - mixed > 4096 ? 4096 : (uint32_t)(want - mixed);
            pthread_mutex_lock(&mx);
            mix(n);
            pthread_mutex_unlock(&mx);
            emit(out, n);
            mixed += n;
        }
        struct timespec ts = {0, 5000000};
        nanosleep(&ts, NULL);
    }
    return NULL;
}

// ---- IDirectSound ------------------------------------------------------------------------------
static uint32_t DirectSoundCreate_(Ctx *c) {
    uint32_t guid = ARG(0), out_p = ARG(1);
    if (!out_p || ARG(2)) return DSERR_INVALIDPARAM;
    if (guid) { rn_halt(c, "DirectSoundCreate for device {%08x-...}", ld(c, guid, 4)); return DSERR_INVALIDPARAM; }
    static int started;
    if (!started) {
        started = 1;
#ifndef __EMSCRIPTEN__
        open_wav();
#endif
        pthread_t t;
        pthread_create(&t, NULL, mixer, NULL);
    }
    st(c, out_p, new_obj(c, I_DS), 4);
    TR("DirectSoundCreate -> %08x", ld(c, out_p, 4));
    return DS_OK;
}
static uint32_t IDirectSound_SetCooperativeLevel(Ctx *c) { SELF(I_DS); TR("SetCooperativeLevel(%u)", ARG(2)); return DS_OK; }
static uint32_t IDirectSound_Compact(Ctx *c) { SELF(I_DS); return DS_OK; }
// DSSPEAKER_COMBINED(DSSPEAKER_STEREO, DSSPEAKER_GEOMETRY_WIDE): the Windows XP default for stereo.
static uint32_t IDirectSound_GetSpeakerConfig(Ctx *c) { SELF(I_DS); if (!ARG(1)) return DSERR_INVALIDPARAM; st(c, ARG(1), 4u | 20u << 16, 4); return DS_OK; }
static uint32_t IDirectSound_SetSpeakerConfig(Ctx *c) { SELF(I_DS); return DS_OK; }
// DSCAPS (96 bytes) of a software device: every format, any rate in 100..200000 Hz, no hardware buffers.
static uint32_t IDirectSound_GetCaps(Ctx *c) {
    SELF(I_DS);
    uint32_t p = ARG(1);
    if (!p || ld(c, p, 4) != 96) return DSERR_INVALIDPARAM;
    memset(G(p + 4), 0, 92);
    st(c, p + 4, 0x1 | 0x2 | 0x4 | 0x8 | 0x10 | 0x100 | 0x200 | 0x400 | 0x800, 4);
    st(c, p + 8, 100, 4);               // dwMinSecondarySampleRate
    st(c, p + 12, 200000, 4);
    st(c, p + 16, 1, 4);                // dwPrimaryBuffers
    return DS_OK;
}

// WAVEFORMATEX: wFormatTag, nChannels, nSamplesPerSec, nAvgBytesPerSec, nBlockAlign, wBitsPerSample, cbSize.
static int set_format(Ctx *c, Obj *o, uint32_t f) {
    uint32_t tag = ld(c, f, 2), ch = ld(c, f + 2, 2), rate = ld(c, f + 4, 4), align = ld(c, f + 12, 2), bits = ld(c, f + 14, 2);
    if (tag != 1 || (ch != 1 && ch != 2) || (bits != 8 && bits != 16) || align != ch * bits / 8 || rate < 100 || rate > 200000)
        return 0;
    o->channels = (uint16_t)ch; o->bits = (uint16_t)bits; o->align = (uint16_t)align; o->rate = rate;
    return 1;
}
// DSBUFFERDESC: dwSize (20, or 36 with guid3DAlgorithm), dwFlags, dwBufferBytes, dwReserved, lpwfxFormat.
static uint32_t IDirectSound_CreateSoundBuffer(Ctx *c) {
    SELF(I_DS);
    uint32_t d = ARG(1), out_p = ARG(2), sz = d ? ld(c, d, 4) : 0;
    if (!d || !out_p || ARG(3) || (sz != 20 && sz != 36)) return DSERR_INVALIDPARAM;
    uint32_t flags = ld(c, d + 4, 4), bytes = ld(c, d + 8, 4), fmt = ld(c, d + 16, 4);
    uint32_t g = new_obj(c, I_BUF);
    if (!g) return DSERR_INVALIDPARAM;
    Obj *b = &objs[nobjs - 1];
    b->flags = flags;
    b->owner = (int)(o - objs);
    if (flags & 1) {                    // DSBCAPS_PRIMARYBUFFER: the output, 22 kHz 8-bit stereo until SetFormat
        if (bytes || fmt) { nobjs--; return DSERR_INVALIDPARAM; }
        b->primary = 1; b->channels = 2; b->bits = 8; b->align = 2; b->rate = 22050;
        b->size = 4 * LEAD;
    } else {
        if (!fmt || bytes < 4 || bytes > 0x0fffffff || !set_format(c, b, fmt)) {
            TR("CreateSoundBuffer: format refused");
            nobjs--;
            return fmt ? DSERR_BADFORMAT : DSERR_INVALIDPARAM;
        }
        b->size = bytes - bytes % b->align;
        b->data = guest_alloc(b->size);
        if (!b->data) { rn_halt(c, "dsound: no guest memory for a %u-byte buffer", bytes); return DSERR_INVALIDPARAM; }
        memset(G(b->data), b->bits == 8 ? 0x80 : 0, b->size);
    }
    TR("CreateSoundBuffer(flags %x, %u bytes, %u Hz %u-bit %u ch) -> %08x", flags, b->size, b->rate, b->bits, b->channels, g);
    st(c, out_p, g, 4);
    return DS_OK;
}
static uint32_t IDirectSound_DuplicateSoundBuffer(Ctx *c) {
    SELF(I_DS);
    Obj *src = obj_of(c, ARG(1), I_BUF);
    uint32_t out_p = ARG(2);
    if (!src || !out_p || src->primary) return DSERR_INVALIDCALL;
    uint32_t g = new_obj(c, I_BUF);
    if (!g) return DSERR_INVALIDPARAM;
    Obj *b = &objs[nobjs - 1];
    *b = *src;
    b->guest = g; b->refs = 1; b->playing = 0; b->looping = 0; b->pos = 0;
    st(c, out_p, g, 4);
    return DS_OK;
}

// ---- IDirectSoundBuffer -------------------------------------------------------------------------
static uint32_t IDirectSoundBuffer_GetCaps(Ctx *c) {
    SELF(I_BUF);
    uint32_t p = ARG(1);
    if (!p || ld(c, p, 4) != 20) return DSERR_INVALIDPARAM;
    st(c, p + 4, o->flags | (o->primary ? 0 : 0x8u), 4);      // DSBCAPS_LOCSOFTWARE
    st(c, p + 8, o->size, 4); st(c, p + 12, 0, 4); st(c, p + 16, 0, 4);
    return DS_OK;
}
// Play cursor = what sounds now: LEAD frames of output behind what is mixed. Write cursor = mixed.
static uint32_t cursor_bytes(Obj *o, double frames_back) {
    uint32_t frames = o->size / o->align;
    double p = o->pos;
    if (o->playing) {
        p -= frames_back;
        if (p < 0) p = o->looping ? p + frames * ceil(-p / frames) : 0;
    }
    return ((uint32_t)p % frames) * o->align;
}
static uint32_t IDirectSoundBuffer_GetCurrentPosition(Ctx *c) {
    SELF(I_BUF);
    uint32_t pp = ARG(1), wp = ARG(2);
    if (o->primary) {                   // the primary buffer cycles at the output rate
        uint32_t at = (uint32_t)(clock_frames() % LEAD) * 4u;
        if (pp) st(c, pp, at, 4);
        if (wp) st(c, wp, (at + 4u * 441) % o->size, 4);
        return DS_OK;
    }
    pthread_mutex_lock(&mx);
    double step = (double)(o->freq ? o->freq : o->rate) / RATE;
    uint64_t ahead = mixed > clock_frames() ? mixed - clock_frames() : 0;
    uint32_t play = cursor_bytes(o, (double)ahead * step), write = cursor_bytes(o, 0);
    pthread_mutex_unlock(&mx);
    if (pp) st(c, pp, play, 4);
    if (wp) st(c, wp, write, 4);
    return DS_OK;
}
static uint32_t IDirectSoundBuffer_GetFormat(Ctx *c) {
    SELF(I_BUF);
    uint32_t f = ARG(1), n = ARG(2), got = ARG(3);
    if (got) st(c, got, 18, 4);
    if (!f) return got ? DS_OK : DSERR_INVALIDPARAM;
    if (n < 16) return DSERR_INVALIDPARAM;
    st(c, f, 1, 2); st(c, f + 2, o->channels, 2); st(c, f + 4, o->rate, 4); st(c, f + 8, o->rate * o->align, 4);
    st(c, f + 12, o->align, 2); st(c, f + 14, o->bits, 2);
    if (n >= 18) st(c, f + 16, 0, 2);
    return DS_OK;
}
static uint32_t IDirectSoundBuffer_SetFormat(Ctx *c) {
    SELF(I_BUF);
    if (!o->primary) return DSERR_INVALIDCALL;
    if (!ARG(1) || !set_format(c, o, ARG(1))) return DSERR_BADFORMAT;
    TR("primary SetFormat: %u Hz %u-bit %u ch (the mixer stays at %u Hz stereo)", o->rate, o->bits, o->channels, RATE);
    return DS_OK;
}
static uint32_t IDirectSoundBuffer_GetVolume(Ctx *c) { SELF(I_BUF); if (!ARG(1)) return DSERR_INVALIDPARAM; st(c, ARG(1), (uint32_t)(o->primary ? master : o->volume), 4); return DS_OK; }
static uint32_t IDirectSoundBuffer_GetPan(Ctx *c) { SELF(I_BUF); if (!ARG(1)) return DSERR_INVALIDPARAM; st(c, ARG(1), (uint32_t)o->pan, 4); return DS_OK; }
static uint32_t IDirectSoundBuffer_GetFrequency(Ctx *c) { SELF(I_BUF); if (!ARG(1)) return DSERR_INVALIDPARAM; st(c, ARG(1), o->freq ? o->freq : o->rate, 4); return DS_OK; }
// The CTRL flags say which controls a buffer has: DSBCAPS_CTRLFREQUENCY 0x20, CTRLPAN 0x40, CTRLVOLUME 0x80.
static uint32_t IDirectSoundBuffer_SetVolume(Ctx *c) {
    SELF(I_BUF);
    int32_t v = (int32_t)ARG(1);
    if (!(o->flags & 0x80)) return 0x8878001eu;                  // DSERR_CONTROLUNAVAIL
    if (v > 0 || v < -10000) return DSERR_INVALIDPARAM;
    pthread_mutex_lock(&mx);
    if (o->primary) master = v; else o->volume = v;
    pthread_mutex_unlock(&mx);
    return DS_OK;
}
static uint32_t IDirectSoundBuffer_SetPan(Ctx *c) {
    SELF(I_BUF);
    int32_t v = (int32_t)ARG(1);
    if (!(o->flags & 0x40)) return 0x8878001eu;
    if (v > 10000 || v < -10000) return DSERR_INVALIDPARAM;
    pthread_mutex_lock(&mx); o->pan = v; pthread_mutex_unlock(&mx);
    return DS_OK;
}
static uint32_t IDirectSoundBuffer_SetFrequency(Ctx *c) {
    SELF(I_BUF);
    uint32_t f = ARG(1);
    if (!(o->flags & 0x20) || o->primary) return 0x8878001eu;
    if (f && (f < 100 || f > 200000)) return DSERR_INVALIDPARAM;
    pthread_mutex_lock(&mx); o->freq = f; pthread_mutex_unlock(&mx);
    return DS_OK;
}
// DSBSTATUS_PLAYING 1, DSBSTATUS_LOOPING 4, DSBSTATUS_LOCSOFTWARE 8 (LOCDEFER buffers only).
static uint32_t IDirectSoundBuffer_GetStatus(Ctx *c) {
    SELF(I_BUF);
    if (!ARG(1)) return DSERR_INVALIDPARAM;
    pthread_mutex_lock(&mx);
    uint32_t s = (o->playing ? 1u : 0) | (o->playing && o->looping ? 4u : 0) | (o->flags & 0x40000 ? 8u : 0);
    pthread_mutex_unlock(&mx);
    st(c, ARG(1), s, 4);
    return DS_OK;
}
static uint32_t IDirectSoundBuffer_Initialize(Ctx *c) { SELF(I_BUF); return 0x88780082u; }   // DSERR_ALREADYINITIALIZED
static uint32_t IDirectSoundBuffer_Restore(Ctx *c) { SELF(I_BUF); return DS_OK; }
// Lock(dwOffset, dwBytes, ppvAudioPtr1, pdwAudioBytes1, ppvAudioPtr2, pdwAudioBytes2, dwFlags):
// DSBLOCK_FROMWRITECURSOR 1, DSBLOCK_ENTIREBUFFER 2. A range past the end wraps into the second part.
static uint32_t IDirectSoundBuffer_Lock(Ctx *c) {
    SELF(I_BUF);
    uint32_t off = ARG(1), n = ARG(2), p1 = ARG(3), n1 = ARG(4), p2 = ARG(5), n2 = ARG(6), flags = ARG(7);
    if (o->primary) return DSERR_PRIOLEVELNEEDED;               // no DSSCL_WRITEPRIMARY here
    if (flags & 2) { off = 0; n = o->size; }
    if (flags & 1) {
        pthread_mutex_lock(&mx);
        off = cursor_bytes(o, 0);
        pthread_mutex_unlock(&mx);
    }
    if (!p1 || !n1 || off >= o->size || !n || n > o->size) return DSERR_INVALIDPARAM;
    uint32_t a = n < o->size - off ? n : o->size - off;
    st(c, p1, o->data + off, 4); st(c, n1, a, 4);
    if (p2) st(c, p2, n > a ? o->data : 0, 4);
    if (n2) st(c, n2, n - a, 4);
    if (n > a && !p2) return DSERR_INVALIDPARAM;
    return DS_OK;
}
static uint32_t IDirectSoundBuffer_Unlock(Ctx *c) {
    SELF(I_BUF);
    pthread_mutex_lock(&mx); o->since_unlock = 0; o->unlocks++; pthread_mutex_unlock(&mx);
    return DS_OK;
}
// Play(dwReserved1, dwPriority, dwFlags): DSBPLAY_LOOPING 1. The primary buffer must loop.
static uint32_t IDirectSoundBuffer_Play(Ctx *c) {
    SELF(I_BUF);
    uint32_t flags = ARG(3);
    if (o->primary && !(flags & 1)) return DSERR_INVALIDPARAM;
    pthread_mutex_lock(&mx);
    o->playing = 1;
    o->looping = flags & 1;
    pthread_mutex_unlock(&mx);
    return DS_OK;
}
static uint32_t IDirectSoundBuffer_Stop(Ctx *c) {
    SELF(I_BUF);
    pthread_mutex_lock(&mx); o->playing = 0; pthread_mutex_unlock(&mx);
    return DS_OK;
}
static uint32_t IDirectSoundBuffer_SetCurrentPosition(Ctx *c) {
    SELF(I_BUF);
    uint32_t p = ARG(1);
    if (o->primary) return DSERR_INVALIDCALL;
    if (p >= o->size) return DSERR_INVALIDPARAM;
    pthread_mutex_lock(&mx); o->pos = p / o->align; pthread_mutex_unlock(&mx);
    return DS_OK;
}

#define DSM(name, n) {"dsound.dll", "IDirectSound::" #name, n, IDirectSound_##name}
#define BUFM(name, n) {"dsound.dll", "IDirectSoundBuffer::" #name, n, IDirectSoundBuffer_##name}
const Api dsound_apis[] = {
    {"dsound.dll", "#1", 3, DirectSoundCreate_},
    {"dsound.dll", "IDirectSound::QueryInterface", 3, QueryInterface_}, {"dsound.dll", "IDirectSound::AddRef", 1, AddRef_},
    {"dsound.dll", "IDirectSound::Release", 1, Release_},
    {"dsound.dll", "IDirectSoundBuffer::QueryInterface", 3, QueryInterface_},
    {"dsound.dll", "IDirectSoundBuffer::AddRef", 1, AddRef_}, {"dsound.dll", "IDirectSoundBuffer::Release", 1, Release_},
    DSM(CreateSoundBuffer, 4), DSM(GetCaps, 2), DSM(DuplicateSoundBuffer, 3), DSM(SetCooperativeLevel, 3),
    DSM(Compact, 1), DSM(GetSpeakerConfig, 2), DSM(SetSpeakerConfig, 2),
    BUFM(GetCaps, 2), BUFM(GetCurrentPosition, 3), BUFM(GetFormat, 4), BUFM(GetVolume, 2), BUFM(GetPan, 2),
    BUFM(GetFrequency, 2), BUFM(GetStatus, 2), BUFM(Initialize, 3), BUFM(Lock, 8), BUFM(Play, 4),
    BUFM(SetCurrentPosition, 2), BUFM(SetFormat, 2), BUFM(SetVolume, 2), BUFM(SetPan, 2), BUFM(SetFrequency, 2),
    BUFM(Stop, 1), BUFM(Unlock, 5), BUFM(Restore, 1),
};
const int dsound_api_count = sizeof dsound_apis / sizeof dsound_apis[0];
