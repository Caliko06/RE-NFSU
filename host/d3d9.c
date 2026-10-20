// d3d9: Direct3DCreate9 and the COM objects behind it, as documented by Microsoft (DirectX 9.0b).
// We present one adapter: an ATI RADEON 9800 PRO (R350, 128 MB) HAL device on a 1920x1080 desktop,
// a DirectX 9 card of the game's time. Every query the game makes is logged with RN_TRACE so the
// answers can be checked against Wine. Objects live in guest memory: [vtable][host index]; every
// vtable slot is a host function "d3d9.dll!Interface::Method", so a method we lack stops loudly.
#include <strings.h>
#include "host.h"
#include "gpu.h"

#define D3D_OK 0u
#define D3DERR_NOTFOUND 0x88760866u
#define D3DERR_NOTAVAILABLE 0x8876086au
#define D3DERR_INVALIDCALL 0x8876086cu
#define D3DERR_OUTOFVIDEOMEMORY 0x8876017cu
#define D3DOK_NOAUTOGEN 0x0876086fu

#define TR(...) do { if (rn_trace()) rn_log("d3d9 " __VA_ARGS__); } while (0)

// ---- interfaces: vtable order of d3d9.h -----------------------------------------------------
enum { I_D3D9, I_DEVICE, I_SURFACE, I_TEXTURE, I_CUBE, I_VB, I_IB, I_SWAPCHAIN, I_DECL, I_VS, I_PS, I_SB, I_QUERY, I_N };
#define UNK "QueryInterface", "AddRef", "Release"
#define RES UNK, "GetDevice", "SetPrivateData", "GetPrivateData", "FreePrivateData", "SetPriority", "GetPriority", \
            "PreLoad", "GetType"
#define BASETEX RES, "SetLOD", "GetLOD", "GetLevelCount", "SetAutoGenFilterType", "GetAutoGenFilterType", \
            "GenerateMipSubLevels"
static const char *const m_d3d9[] = {UNK, "RegisterSoftwareDevice", "GetAdapterCount", "GetAdapterIdentifier",
    "GetAdapterModeCount", "EnumAdapterModes", "GetAdapterDisplayMode", "CheckDeviceType", "CheckDeviceFormat",
    "CheckDeviceMultiSampleType", "CheckDepthStencilMatch", "CheckDeviceFormatConversion", "GetDeviceCaps",
    "GetAdapterMonitor", "CreateDevice", 0};
static const char *const m_device[] = {UNK, "TestCooperativeLevel", "GetAvailableTextureMem",
    "EvictManagedResources", "GetDirect3D", "GetDeviceCaps", "GetDisplayMode", "GetCreationParameters",
    "SetCursorProperties", "SetCursorPosition", "ShowCursor", "CreateAdditionalSwapChain", "GetSwapChain",
    "GetNumberOfSwapChains", "Reset", "Present", "GetBackBuffer", "GetRasterStatus", "SetDialogBoxMode",
    "SetGammaRamp", "GetGammaRamp", "CreateTexture", "CreateVolumeTexture", "CreateCubeTexture",
    "CreateVertexBuffer", "CreateIndexBuffer", "CreateRenderTarget", "CreateDepthStencilSurface", "UpdateSurface",
    "UpdateTexture", "GetRenderTargetData", "GetFrontBufferData", "StretchRect", "ColorFill",
    "CreateOffscreenPlainSurface", "SetRenderTarget", "GetRenderTarget", "SetDepthStencilSurface",
    "GetDepthStencilSurface", "BeginScene", "EndScene", "Clear", "SetTransform", "GetTransform",
    "MultiplyTransform", "SetViewport", "GetViewport", "SetMaterial", "GetMaterial", "SetLight", "GetLight",
    "LightEnable", "GetLightEnable", "SetClipPlane", "GetClipPlane", "SetRenderState", "GetRenderState",
    "CreateStateBlock", "BeginStateBlock", "EndStateBlock", "SetClipStatus", "GetClipStatus", "GetTexture",
    "SetTexture", "GetTextureStageState", "SetTextureStageState", "GetSamplerState", "SetSamplerState",
    "ValidateDevice", "SetPaletteEntries", "GetPaletteEntries", "SetCurrentTexturePalette",
    "GetCurrentTexturePalette", "SetScissorRect", "GetScissorRect", "SetSoftwareVertexProcessing",
    "GetSoftwareVertexProcessing", "SetNPatchMode", "GetNPatchMode", "DrawPrimitive", "DrawIndexedPrimitive",
    "DrawPrimitiveUP", "DrawIndexedPrimitiveUP", "ProcessVertices", "CreateVertexDeclaration",
    "SetVertexDeclaration", "GetVertexDeclaration", "SetFVF", "GetFVF", "CreateVertexShader", "SetVertexShader",
    "GetVertexShader", "SetVertexShaderConstantF", "GetVertexShaderConstantF", "SetVertexShaderConstantI",
    "GetVertexShaderConstantI", "SetVertexShaderConstantB", "GetVertexShaderConstantB", "SetStreamSource",
    "GetStreamSource", "SetStreamSourceFreq", "GetStreamSourceFreq", "SetIndices", "GetIndices",
    "CreatePixelShader", "SetPixelShader", "GetPixelShader", "SetPixelShaderConstantF", "GetPixelShaderConstantF",
    "SetPixelShaderConstantI", "GetPixelShaderConstantI", "SetPixelShaderConstantB", "GetPixelShaderConstantB",
    "DrawRectPatch", "DrawTriPatch", "DeletePatch", "CreateQuery", 0};
static const char *const m_surface[] = {RES, "GetContainer", "GetDesc", "LockRect", "UnlockRect", "GetDC",
    "ReleaseDC", 0};
static const char *const m_texture[] = {BASETEX, "GetLevelDesc", "GetSurfaceLevel", "LockRect", "UnlockRect",
    "AddDirtyRect", 0};
static const char *const m_cube[] = {BASETEX, "GetLevelDesc", "GetCubeMapSurface", "LockRect", "UnlockRect",
    "AddDirtyRect", 0};
static const char *const m_vb[] = {RES, "Lock", "Unlock", "GetDesc", 0};
static const char *const m_swapchain[] = {UNK, "Present", "GetFrontBufferData", "GetBackBuffer",
    "GetRasterStatus", "GetDisplayMode", "GetDevice", "GetPresentParameters", 0};
static const char *const m_decl[] = {UNK, "GetDevice", "GetDeclaration", 0};
static const char *const m_shader[] = {UNK, "GetDevice", "GetFunction", 0};
static const char *const m_sb[] = {UNK, "GetDevice", "Capture", "Apply", 0};
static const char *const m_query[] = {UNK, "GetDevice", "GetType", "GetDataSize", "Issue", "GetData", 0};
static const char *const iface_name[I_N] = {"IDirect3D9", "IDirect3DDevice9", "IDirect3DSurface9",
    "IDirect3DTexture9", "IDirect3DCubeTexture9", "IDirect3DVertexBuffer9", "IDirect3DIndexBuffer9",
    "IDirect3DSwapChain9", "IDirect3DVertexDeclaration9", "IDirect3DVertexShader9", "IDirect3DPixelShader9",
    "IDirect3DStateBlock9", "IDirect3DQuery9"};
static const char *const *const iface_methods[I_N] = {m_d3d9, m_device, m_surface, m_texture, m_cube, m_vb, m_vb,
    m_swapchain, m_decl, m_shader, m_shader, m_sb, m_query};
static uint32_t vtables[I_N];

static uint32_t vtable(int i) {
    if (vtables[i]) return vtables[i];
    int n = 0;
    while (iface_methods[i][n]) n++;
    uint32_t v = guest_alloc(4u * n);
    for (int k = 0; k < n; k++) {
        char name[96];
        snprintf(name, sizeof name, "%s::%s", iface_name[i], iface_methods[i][k]);
        st(g_ctx, v + 4u * k, host_addr_of("d3d9.dll", name), 4);
    }
    return vtables[i] = v;
}

// ---- objects --------------------------------------------------------------------------------
enum { POOL_DEFAULT, POOL_MANAGED, POOL_SYSTEMMEM, POOL_SCRATCH };
typedef struct {
    int iface;
    uint32_t refs, guest;
    uint32_t w, h, fmt, usage, pool, type;  // type: D3DRESOURCETYPE
    uint32_t mem, pitch, size;              // guest memory behind Lock
    uint32_t container;                     // owning object index + 1 (surfaces of textures, back buffers)
    uint32_t gpu;                           // render target / depth id in the command list, 0 = none
    int locked, lockable;
    uint32_t levels, level0, fvf;           // textures: mip count, object index of level 0 (levels follow)
    uint32_t *blob, nblob;                  // shader tokens, vertex elements (host copy)
    struct Rec *rec;                        // state blocks: the recorded Set calls
    uint32_t nrec;
} Obj;
static Obj objs[8192];
static int nobjs;

static uint32_t new_obj(Ctx *c, int iface) {
    if (nobjs == 8192) { rn_halt(c, "d3d9: too many objects"); return 0; }
    Obj *o = &objs[nobjs];
    memset(o, 0, sizeof *o);
    o->iface = iface;
    o->refs = 1;
    o->guest = guest_alloc(16);
    st(c, o->guest, vtable(iface), 4);
    st(c, o->guest + 4, (uint32_t)nobjs + 1, 4);
    nobjs++;
    return o->guest;
}
static Obj *obj_of(Ctx *c, uint32_t p, int iface) {
    uint32_t k = p ? ld(c, p + 4, 4) - 1 : ~0u;
    if (k < (uint32_t)nobjs && objs[k].guest == p && (iface < 0 || objs[k].iface == iface)) return &objs[k];
    rn_halt(c, "d3d9: %08x is not a live %s", p, iface < 0 ? "object" : iface_name[iface]);
    return NULL;
}
#define SELF(iface) Obj *o = obj_of(c, ARG(0), iface); if (!o) return D3DERR_INVALIDCALL
static uint32_t idx(const Obj *o) { return (uint32_t)(o - objs); }

static uint32_t unk_QueryInterface(Ctx *c) {
    uint32_t g = ARG(1);
    rn_halt(c, "d3d9: QueryInterface for {%08x-%04x-%04x-...}", ld(c, g, 4), ld(c, g + 4, 2), ld(c, g + 6, 2));
    return 0x80004002u;     // E_NOINTERFACE
}
static uint32_t unk_AddRef(Ctx *c) { SELF(-1); return ++o->refs; }
// A surface that belongs to a texture or a swap chain shares its container's count (d3d9 docs).
static uint32_t unk_Release(Ctx *c) {
    SELF(-1);
    if (o->container) return --objs[o->container - 1].refs;
    if (!o->refs) { rn_halt(c, "d3d9: Release of a dead %s", iface_name[o->iface]); return 0; }
    if (!--o->refs) TR("%s %08x freed", iface_name[o->iface], o->guest);   // guest memory is not reused yet
    return o->refs;
}

// ---- formats --------------------------------------------------------------------------------
enum {
    F_UNKNOWN = 0, F_R8G8B8 = 20, F_A8R8G8B8, F_X8R8G8B8, F_R5G6B5, F_X1R5G5B5, F_A1R5G5B5, F_A4R4G4B4, F_R3G3B2,
    F_A8, F_A8R3G3B2, F_X4R4G4B4, F_A2B10G10R10, F_A8B8G8R8, F_X8B8G8R8, F_G16R16, F_A2R10G10B10, F_A16B16G16R16,
    F_A8P8 = 40, F_P8, F_L8 = 50, F_A8L8, F_A4L4, F_V8U8 = 60, F_L6V5U5, F_X8L8V8U8, F_Q8W8V8U8, F_V16U16,
    F_D16_LOCKABLE = 70, F_D32, F_D15S1 = 73, F_D24S8 = 75, F_D24X8 = 77, F_D24X4S4 = 79, F_D16, F_L16,
    F_D32F_LOCKABLE, F_D24FS8, F_INDEX16 = 101, F_INDEX32, F_R16F = 111, F_G16R16F, F_A16B16G16R16F, F_R32F,
    F_G32R32F, F_A32B32G32R32F,
};
#define FOURCC(a, b, c_, d) ((uint32_t)(a) | (uint32_t)(b) << 8 | (uint32_t)(c_) << 16 | (uint32_t)(d) << 24)
#define F_DXT1 FOURCC('D', 'X', 'T', '1')
#define F_DXT2 FOURCC('D', 'X', 'T', '2')
#define F_DXT3 FOURCC('D', 'X', 'T', '3')
#define F_DXT4 FOURCC('D', 'X', 'T', '4')
#define F_DXT5 FOURCC('D', 'X', 'T', '5')

static int is_dxt(uint32_t f) { return f == F_DXT1 || f == F_DXT2 || f == F_DXT3 || f == F_DXT4 || f == F_DXT5; }
static int is_depth(uint32_t f) { return f >= F_D16_LOCKABLE && f <= F_D24FS8 && f != F_L16; }
// Bits per pixel (per texel for DXT: 4 or 8). 0 = a format this adapter does not know.
static int fmt_bits(uint32_t f) {
    switch (f) {
    case F_A8R8G8B8: case F_X8R8G8B8: case F_A8B8G8R8: case F_X8B8G8R8: case F_A2B10G10R10: case F_A2R10G10B10:
    case F_G16R16: case F_X8L8V8U8: case F_Q8W8V8U8: case F_V16U16: case F_D32: case F_D24S8: case F_D24X8:
    case F_D24X4S4: case F_D32F_LOCKABLE: case F_D24FS8: case F_G16R16F: case F_R32F: case F_INDEX32: return 32;
    case F_R8G8B8: return 24;
    case F_R5G6B5: case F_X1R5G5B5: case F_A1R5G5B5: case F_A4R4G4B4: case F_A8R3G3B2: case F_X4R4G4B4:
    case F_A8P8: case F_A8L8: case F_V8U8: case F_L6V5U5: case F_D16_LOCKABLE: case F_D15S1: case F_D16:
    case F_L16: case F_R16F: case F_INDEX16: return 16;
    case F_R3G3B2: case F_A8: case F_P8: case F_L8: case F_A4L4: return 8;
    case F_A16B16G16R16: case F_A16B16G16R16F: case F_G32R32F: return 64;
    case F_A32B32G32R32F: return 128;
    case F_DXT1: return 4;
    case F_DXT2: case F_DXT3: case F_DXT4: case F_DXT5: return 8;
    }
    return 0;
}
static uint32_t pitch_of(uint32_t f, uint32_t w) {
    if (is_dxt(f)) return ((w + 3) / 4) * (f == F_DXT1 ? 8 : 16);
    return (w * fmt_bits(f) / 8 + 3) & ~3u;
}
static uint32_t size_of(uint32_t f, uint32_t w, uint32_t h) { return pitch_of(f, w) * (is_dxt(f) ? (h + 3) / 4 : h); }

// ---- the adapter ----------------------------------------------------------------------------
#define DESK_W 1920
#define DESK_H 1080
#define VRAM (128u << 20)
static const uint16_t modes[][2] = {{640, 480}, {720, 480}, {720, 576}, {800, 600}, {1024, 768}, {1152, 864},
    {1280, 720}, {1280, 768}, {1280, 800}, {1280, 960}, {1280, 1024}, {1360, 768}, {1366, 768}, {1400, 1050},
    {1440, 900}, {1600, 900}, {1680, 1050}, {1920, 1080}};
#define NMODES (int)(sizeof modes / sizeof modes[0])
static int display_fmt(uint32_t f) { return f == F_X8R8G8B8 || f == F_R5G6B5; }
static uint32_t vram_used;

static uint32_t d3d9_obj;
static uint32_t Direct3DCreate9_(Ctx *c) {
    uint32_t v = ARG(0) & 0x7fffffffu;
    TR("Direct3DCreate9(%u)", ARG(0));
    if (v != 31 && v != 32) return 0;       // D3D_SDK_VERSION of DirectX 9.0b/9.0c
    if (!d3d9_obj) d3d9_obj = new_obj(c, I_D3D9);
    else objs[ld(c, d3d9_obj + 4, 4) - 1].refs++;
    return d3d9_obj;
}

// Undocumented export that D3DX asks for to validate the shaders it assembles. We have no
// validator: it returns NULL, and D3DX then skips validation (its code checks for NULL).
static uint32_t Direct3DShaderValidatorCreate9_(Ctx *c) { (void)c; rn_log("d3d9 Direct3DShaderValidatorCreate9 -> NULL"); return 0; }
// DebugSetMute(void) silences the debug runtime; the retail runtime has nothing to silence.
static uint32_t DebugSetMute_(Ctx *c) { (void)c; return 0; }

static uint32_t IDirect3D9_GetAdapterCount(Ctx *c) { (void)c; TR("GetAdapterCount -> 1"); return 1; }

static void put_str(Ctx *c, uint32_t p, const char *s) { memcpy(G(p), s, strlen(s) + 1); }
// D3DADAPTER_IDENTIFIER9: Driver[512], Description[512], DeviceName[32], DriverVersion, VendorId, DeviceId,
// SubSysId, Revision, DeviceIdentifier, WHQLLevel. Catalyst 3.10 (October 2003) driver version.
static uint32_t IDirect3D9_GetAdapterIdentifier(Ctx *c) {
    uint32_t ad = ARG(1), flags = ARG(2), p = ARG(3);
    TR("GetAdapterIdentifier(%u, flags %x)", ad, flags);
    if (ad != 0 || !p) return D3DERR_INVALIDCALL;
    memset(G(p), 0, 1100);
    put_str(c, p, "ati2dvag.dll");
    put_str(c, p + 512, "RADEON 9800 PRO");
    put_str(c, p + 1024, "\\\\.\\DISPLAY1");
    st(c, p + 1056, (10u << 16) | 6396, 4);   // 6.14.10.6396
    st(c, p + 1060, (6u << 16) | 14, 4);
    st(c, p + 1064, 0x1002, 4);               // ATI
    st(c, p + 1068, 0x4e48, 4);               // R350 RADEON 9800 PRO
    st(c, p + 1072, 0x00021002, 4);
    st(c, p + 1076, 0, 4);
    // DeviceIdentifier: a per-install GUID; this one is ours and fixed.
    static const uint8_t guid[16] = {0xd7, 0xb7, 0x1e, 0xe2, 0x0d, 0x08, 0xcf, 0x11, 0x8e, 0x46, 0x00, 0x52, 0x4e, 0x48, 0x10, 0x02};
    memcpy(G(p + 1080), guid, 16);
    st(c, p + 1096, (flags & 2) ? 1 : 0, 4);  // D3DENUM_WHQL_LEVEL: signed driver
    return D3D_OK;
}
static uint32_t IDirect3D9_GetAdapterModeCount(Ctx *c) {
    uint32_t ad = ARG(1), f = ARG(2);
    uint32_t n = ad == 0 && display_fmt(f) ? NMODES : 0;
    TR("GetAdapterModeCount(%u, fmt %u) -> %u", ad, f, n);
    return n;
}
static void put_mode(Ctx *c, uint32_t p, uint32_t w, uint32_t h, uint32_t f) {
    st(c, p, w, 4); st(c, p + 4, h, 4); st(c, p + 8, 60, 4); st(c, p + 12, f, 4);
}
static uint32_t IDirect3D9_EnumAdapterModes(Ctx *c) {
    uint32_t ad = ARG(1), f = ARG(2), k = ARG(3), p = ARG(4);
    TR("EnumAdapterModes(%u, fmt %u, %u)", ad, f, k);
    if (ad != 0 || !display_fmt(f) || k >= (uint32_t)NMODES || !p) return D3DERR_INVALIDCALL;
    put_mode(c, p, modes[k][0], modes[k][1], f);
    return D3D_OK;
}
static uint32_t IDirect3D9_GetAdapterDisplayMode(Ctx *c) {
    TR("GetAdapterDisplayMode(%u)", ARG(1));
    if (ARG(1) != 0 || !ARG(2)) return D3DERR_INVALIDCALL;
    put_mode(c, ARG(2), DESK_W, DESK_H, F_X8R8G8B8);
    return D3D_OK;
}
// Back buffer formats per display format (d3d9 "Presentation formats" table); UNKNOWN only windowed.
static int backbuffer_ok(uint32_t disp, uint32_t bb, int windowed) {
    if (bb == F_UNKNOWN) return windowed;
    if (disp == F_X8R8G8B8) return bb == F_X8R8G8B8 || bb == F_A8R8G8B8;
    if (disp == F_R5G6B5) return bb == F_R5G6B5;
    return 0;
}
static uint32_t IDirect3D9_CheckDeviceType(Ctx *c) {
    uint32_t ad = ARG(1), type = ARG(2), disp = ARG(3), bb = ARG(4), win = ARG(5);
    uint32_t r = ad == 0 && type == 1 && display_fmt(disp) && backbuffer_ok(disp, bb, win) ? D3D_OK : D3DERR_NOTAVAILABLE;
    if (ad != 0) r = D3DERR_INVALIDCALL;
    TR("CheckDeviceType(%u, type %u, disp %u, bb %u, windowed %u) -> %08x", ad, type, disp, bb, win, r);
    return r;
}
// Formats of an R300-class part. RTYPE: 1 surface, 3 texture, 4 volume texture, 5 cube texture.
static int tex_fmt(uint32_t f) {
    switch (f) {
    case F_A8R8G8B8: case F_X8R8G8B8: case F_R5G6B5: case F_X1R5G5B5: case F_A1R5G5B5: case F_A4R4G4B4:
    case F_A8: case F_L8: case F_A8L8: case F_V8U8: case F_L6V5U5: case F_X8L8V8U8: case F_Q8W8V8U8:
    case F_V16U16: case F_G16R16: case F_A2R10G10B10: case F_A16B16G16R16: case F_L16: case F_R16F:
    case F_G16R16F: case F_A16B16G16R16F: case F_R32F: case F_G32R32F: case F_A32B32G32R32F:
        return 1;
    }
    return is_dxt(f);
}
static int rt_fmt(uint32_t f) {
    switch (f) {
    case F_A8R8G8B8: case F_X8R8G8B8: case F_R5G6B5: case F_X1R5G5B5: case F_A1R5G5B5: case F_A4R4G4B4:
    case F_G16R16: case F_A2R10G10B10: case F_A16B16G16R16: case F_R16F: case F_G16R16F: case F_A16B16G16R16F:
    case F_R32F: case F_G32R32F: case F_A32B32G32R32F:
        return 1;
    }
    return 0;
}
static int ds_fmt(uint32_t f) { return f == F_D16 || f == F_D16_LOCKABLE || f == F_D24S8 || f == F_D24X8; }
static int float_fmt(uint32_t f) { return f >= F_R16F && f <= F_A32B32G32R32F; }

#define U_RENDERTARGET 0x1u
#define U_DEPTHSTENCIL 0x2u
#define U_DYNAMIC 0x200u
#define U_AUTOGENMIPMAP 0x400u
#define U_QUERY_MASK 0x000f8000u    // QUERY_LEGACYBUMPMAP .. QUERY_VERTEXTEXTURE, SRGBREAD/WRITE, FILTER
static uint32_t check_format(uint32_t disp, uint32_t usage, uint32_t rtype, uint32_t f) {
    if (!display_fmt(disp)) return D3DERR_NOTAVAILABLE;
    uint32_t q = usage & U_QUERY_MASK;
    if (rtype == 6) return f == 100 ? D3D_OK : D3DERR_NOTAVAILABLE;                    // D3DFMT_VERTEXDATA
    if (rtype == 7) return f == F_INDEX16 || f == F_INDEX32 ? D3D_OK : D3DERR_NOTAVAILABLE;
    int ok;
    if (usage & U_DEPTHSTENCIL) ok = rtype == 1 && ds_fmt(f);
    else if (usage & U_RENDERTARGET) ok = (rtype == 1 || rtype == 3 || rtype == 5) && rt_fmt(f);
    else ok = rtype == 1 ? tex_fmt(f) || f == F_UNKNOWN : (rtype == 3 || rtype == 5) ? tex_fmt(f)
            : rtype == 4 ? tex_fmt(f) && !is_dxt(f) : 0;
    if (!ok) return D3DERR_NOTAVAILABLE;
    if (q & 0x20000u) ok = !float_fmt(f);                               // QUERY_FILTER
    if (q & 0x80000u) ok = ok && !float_fmt(f);                         // QUERY_POSTPIXELSHADER_BLENDING
    if (q & 0x10000u) ok = 0;                                           // QUERY_SRGBREAD: not on R300
    if (q & 0x40000u) ok = 0;                                           // QUERY_SRGBWRITE
    if (q & 0x100000u) ok = 0;                                          // QUERY_VERTEXTEXTURE
    if (q & 0x8000u) ok = ok && (f == F_V8U8 || f == F_L6V5U5 || f == F_X8L8V8U8);   // QUERY_LEGACYBUMPMAP
    if (!ok) return D3DERR_NOTAVAILABLE;
    if ((usage & U_AUTOGENMIPMAP) && (float_fmt(f) || is_dxt(f) || fmt_bits(f) < 16)) return D3DOK_NOAUTOGEN;
    return D3D_OK;
}
static uint32_t IDirect3D9_CheckDeviceFormat(Ctx *c) {
    uint32_t ad = ARG(1), type = ARG(2), disp = ARG(3), usage = ARG(4), rtype = ARG(5), f = ARG(6);
    uint32_t r = ad != 0 ? D3DERR_INVALIDCALL : type != 1 ? D3DERR_NOTAVAILABLE : check_format(disp, usage, rtype, f);
    TR("CheckDeviceFormat(%u, type %u, disp %u, usage %x, rtype %u, fmt %u) -> %08x", ad, type, disp, usage, rtype, f, r);
    return r;
}
// Multisampling: 2, 4, 6 samples (and NONMASKABLE with 3 quality levels) on 8888/565 and the depth formats.
static uint32_t IDirect3D9_CheckDeviceMultiSampleType(Ctx *c) {
    uint32_t ad = ARG(1), type = ARG(2), f = ARG(3), win = ARG(4), ms = ARG(5), q = ARG(6);
    int fmt_ok = f == F_A8R8G8B8 || f == F_X8R8G8B8 || f == F_R5G6B5 || ds_fmt(f);
    uint32_t levels = ms == 0 ? 1 : ms == 1 ? 3 : (ms == 2 || ms == 4 || ms == 6) ? 1 : 0;
    uint32_t r = ad != 0 ? D3DERR_INVALIDCALL : type == 1 && levels && (ms == 0 || fmt_ok) ? D3D_OK : D3DERR_NOTAVAILABLE;
    if (q) st(c, q, r == D3D_OK ? levels : 0, 4);
    TR("CheckDeviceMultiSampleType(%u, type %u, fmt %u, windowed %u, ms %u) -> %08x", ad, type, f, win, ms, r);
    return r;
}
static uint32_t IDirect3D9_CheckDepthStencilMatch(Ctx *c) {
    uint32_t ad = ARG(1), disp = ARG(3), rt = ARG(4), ds = ARG(5);
    uint32_t r = ad != 0 ? D3DERR_INVALIDCALL : display_fmt(disp) && rt_fmt(rt) && ds_fmt(ds) ? D3D_OK : D3DERR_NOTAVAILABLE;
    TR("CheckDepthStencilMatch(%u, disp %u, rt %u, ds %u) -> %08x", ad, disp, rt, ds, r);
    return r;
}

// D3DCAPS9 of the R350 (values of the DirectX Caps Viewer dump for this class of part).
static void put_caps(Ctx *c, uint32_t p) {
    static const struct { uint16_t off; uint32_t v; } caps[] = {
        {0, 1}, {4, 0},                        // DeviceType HAL, AdapterOrdinal
        {8, 0x00020000}, {12, 0x60120000}, {16, 0x000003a0}, {20, 0x8000000f}, {24, 0x3},
        {28, 0x001bbef0},                      // DevCaps: HW T&L, pure device, video memory textures
        {32, 0x00144ff2}, {36, 0x0f732191}, {40, 0xff}, {44, 0x3fff}, {48, 0x3fff}, {52, 0xff},
        {56, 0x00084208}, {60, 0x0007ed07}, {64, 0x07030700}, {68, 0x07030700}, {72, 0x03030300},
        {76, 0x3f}, {80, 0x3f}, {84, 0x1f},
        {88, 2048}, {92, 2048}, {96, 2048}, {100, 2048}, {104, 2048}, {108, 16},
        {136, 0x1ff}, {140, 0x00100008}, {144, 0x03feffff}, {148, 8}, {152, 8}, {156, 0x17b},
        {160, 8}, {164, 6}, {168, 4}, {172, 37}, {180, 0xfffff}, {184, 0xffffff}, {188, 16}, {192, 508},
        {196, 0xfffe0200}, {200, 256}, {204, 0xffff0200}, {212, 0x51},
        {224, 0}, {228, 0}, {232, 1}, {236, 0x33e}, {240, 4}, {244, 0x03000300},
        {248, 0}, {252, 0}, {256, 12}, {260, 1},              // VS20Caps
        {264, 0}, {268, 0}, {272, 12}, {276, 0}, {280, 96},   // PS20Caps
        {284, 0}, {288, 65535}, {292, 96}, {296, 0}, {300, 0},
    };
    static const struct { uint16_t off; float v; } fcaps[] = {
        {112, 1e10f}, {116, -65536.f}, {120, -65536.f}, {124, 65536.f}, {128, 65536.f}, {132, 0.f},
        {176, 256.f}, {208, 8.f}, {216, 0.f},
    };
    memset(G(p), 0, 304);
    for (unsigned k = 0; k < sizeof caps / sizeof caps[0]; k++) st(c, p + caps[k].off, caps[k].v, 4);
    for (unsigned k = 0; k < sizeof fcaps / sizeof fcaps[0]; k++) stf(c, p + fcaps[k].off, fcaps[k].v);
}
static uint32_t IDirect3D9_GetDeviceCaps(Ctx *c) {
    TR("GetDeviceCaps(%u, type %u)", ARG(1), ARG(2));
    if (ARG(1) != 0 || !ARG(3)) return D3DERR_INVALIDCALL;
    if (ARG(2) != 1) return D3DERR_NOTAVAILABLE;
    put_caps(c, ARG(3));
    return D3D_OK;
}
static uint32_t IDirect3D9_GetAdapterMonitor(Ctx *c) { TR("GetAdapterMonitor(%u)", ARG(1)); return ARG(1) == 0 ? 0x10005 : 0; }

// ---- the device -----------------------------------------------------------------------------
// Render, texture stage and sampler state defaults of the d3d9 documentation.
#define F1 0x3f800000u
static const uint32_t rs_default[][2] = {
    {8, 3}, {9, 2}, {14, 1}, {15, 0}, {16, 1}, {19, 2}, {20, 1}, {22, 3}, {23, 4}, {24, 0}, {25, 8}, {26, 0},
    {27, 0}, {28, 0}, {29, 0}, {34, 0}, {35, 0}, {36, 0}, {37, F1}, {38, F1}, {48, 0}, {52, 0}, {53, 1}, {54, 1},
    {55, 1}, {56, 8}, {57, 0}, {58, 0xffffffff}, {59, 0xffffffff}, {60, 0xffffffff}, {136, 1}, {137, 1},
    {139, 0}, {140, 0}, {141, 1}, {142, 1}, {143, 0}, {145, 1}, {146, 2}, {147, 0}, {148, 0}, {151, 0},
    {152, 0}, {154, F1}, {155, F1}, {156, 0}, {157, 0}, {158, F1}, {159, 0}, {160, 0}, {161, 1},
    {162, 0xffffffff}, {163, 0}, {165, 0}, {166, 0x42800000}, {167, 0}, {168, 0xf}, {170, 0}, {171, 1},
    {172, 3}, {173, 1}, {174, 0}, {175, 0}, {176, 0}, {178, F1}, {179, F1}, {180, 0}, {181, 0}, {182, F1},
    {183, 0}, {184, 0}, {185, 0}, {186, 1}, {187, 1}, {188, 1}, {189, 8}, {190, 0xf}, {191, 0xf}, {192, 0xf},
    {193, 0xffffffff}, {194, 0}, {195, 0}, {206, 0}, {207, 2}, {208, 1}, {209, 1},
};
typedef struct { uint32_t x, y, w, h; float zmin, zmax; } Viewport;
static struct {
    uint32_t guest, flags, window;
    uint32_t pp[14];                    // D3DPRESENT_PARAMETERS as the game gave them, completed
    uint32_t backbuf, depth;            // object indexes + 1
    uint32_t rt[4], ds;
    uint32_t rs[256], tss[8][33], ss[16][14];
    float xf[512][16];
    Viewport vp;
    uint32_t scissor[4];
    int in_scene;
    uint32_t frames;
    uint32_t decl, fvf, vs, ps, ib, tex[16];    // object indexes + 1
    struct { uint32_t vb, off, stride, freq; } stream[16];
    float vsf[256][4], psf[32][4];
    int32_t vsi[16][4], psi[16][4];
    uint32_t vsb[16], psb[16];
    uint32_t material[17];
    uint32_t light[64][26], light_on[64], light_set[64];
    float clip[6][4];
    int cursor_shown;
    uint16_t gamma[3][256];
    int recording;                      // between BeginStateBlock and EndStateBlock
    struct Rec *rec;
    uint32_t nrec, caprec;
} dev;

// A recorded Set call: the handler, its arguments (a[0] = the device) and a guest copy of the data
// its pointer argument pointed to. While recording, Set calls are recorded and not applied.
typedef struct Rec { HostFn fn; uint32_t n, a[6]; int pidx; uint32_t bytes; } Rec;
static uint32_t record(Ctx *c, HostFn fn, uint32_t n, int pidx, uint32_t bytes) {
    if (dev.nrec == dev.caprec) {
        dev.caprec = dev.caprec ? 2 * dev.caprec : 64;
        dev.rec = realloc(dev.rec, sizeof(Rec) * dev.caprec);
    }
    Rec *r = &dev.rec[dev.nrec++];
    r->fn = fn; r->n = n; r->pidx = pidx; r->bytes = bytes;
    for (uint32_t k = 0; k < n; k++) r->a[k] = ARG(k);
    if (pidx >= 0) {
        if (!r->a[pidx]) return D3DERR_INVALIDCALL;
        uint32_t d = guest_alloc(bytes ? bytes : 4);
        memcpy(G(d), G(r->a[pidx]), bytes);
        r->a[pidx] = d;
    }
    return D3D_OK;
}
#define REC(fn, n, pidx, bytes) do { if (dev.recording) return record(c, fn, n, pidx, bytes); } while (0)

static Obj *obj_k(uint32_t k1) { return k1 ? &objs[k1 - 1] : NULL; }

static uint32_t new_surface(Ctx *c, uint32_t w, uint32_t h, uint32_t f, uint32_t usage, uint32_t pool, int lockable) {
    uint32_t g = new_obj(c, I_SURFACE);
    if (!g) return 0;
    Obj *o = &objs[nobjs - 1];
    o->w = w; o->h = h; o->fmt = f; o->usage = usage; o->pool = pool; o->type = 1; o->lockable = lockable;
    o->pitch = pitch_of(f, w);
    o->size = size_of(f, w, h);
    if (usage & (U_RENDERTARGET | U_DEPTHSTENCIL)) {
        o->gpu = idx(o) + 1;
        uint32_t t[4] = {o->gpu, w, h, (usage & U_DEPTHSTENCIL) ? 1u : 0u};
        gpu_cmd(GPU_TARGET, 4, t);
        if (pool == POOL_DEFAULT) vram_used += o->size;
    }
    return g;
}
static void reset_viewport(Obj *rt) {
    dev.vp = (Viewport){0, 0, rt->w, rt->h, 0.f, 1.f};
    dev.scissor[0] = 0; dev.scissor[1] = 0; dev.scissor[2] = rt->w; dev.scissor[3] = rt->h;
}
static void default_state(void) {
    memset(dev.rs, 0, sizeof dev.rs);
    for (unsigned k = 0; k < sizeof rs_default / sizeof rs_default[0]; k++) dev.rs[rs_default[k][0]] = rs_default[k][1];
    dev.rs[7] = dev.pp[9] ? 1 : 0;                  // ZENABLE: on with an automatic depth buffer
    for (int s = 0; s < 8; s++) {
        uint32_t *t = dev.tss[s];
        memset(t, 0, sizeof dev.tss[s]);
        t[1] = s ? 1 : 4; t[2] = 2; t[3] = 1; t[4] = s ? 1 : 2; t[5] = 2; t[6] = 1; t[11] = (uint32_t)s;
        t[26] = 1; t[27] = 1; t[28] = 1;
    }
    for (int s = 0; s < 16; s++) {
        uint32_t *t = dev.ss[s];
        memset(t, 0, sizeof dev.ss[s]);
        t[1] = t[2] = t[3] = 1; t[5] = t[6] = 1; t[10] = 1;
    }
    for (int m = 0; m < 512; m++) {
        memset(dev.xf[m], 0, sizeof dev.xf[m]);
        dev.xf[m][0] = dev.xf[m][5] = dev.xf[m][10] = dev.xf[m][15] = 1.f;
    }
}

static uint32_t IDirect3D9_CreateDevice(Ctx *c) {
    uint32_t ad = ARG(1), type = ARG(2), focus = ARG(3), flags = ARG(4), pp = ARG(5), out = ARG(6);
    for (int k = 0; k < 14; k++) dev.pp[k] = ld(c, pp + 4 * k, 4);
    uint32_t *p = dev.pp;
    rn_log("d3d9 CreateDevice(%u, type %u, focus %08x, flags %x): %ux%u fmt %u x%u ms %u/%u swap %u hwnd %08x "
           "windowed %u autodepth %u fmt %u flags %x %u Hz interval %x",
           ad, type, focus, flags, p[0], p[1], p[2], p[3], p[4], p[5], p[6], p[7], p[8], p[9], p[10], p[11], p[12], p[13]);
    if (ad != 0 || !out || !pp) return D3DERR_INVALIDCALL;
    if (type != 1) return D3DERR_NOTAVAILABLE;
    if (dev.guest) { rn_halt(c, "d3d9: a second device"); return D3DERR_INVALIDCALL; }
    int windowed = p[8] != 0;
    uint32_t window = p[7] ? p[7] : focus;
    if (!p[0] || !p[1]) {
        if (!windowed) return D3DERR_INVALIDCALL;
        rn_halt(c, "d3d9: windowed device sized from window %08x", window);
        return D3DERR_INVALIDCALL;
    }
    if (!windowed) {
        int found = 0;
        for (int k = 0; k < NMODES; k++) found |= modes[k][0] == p[0] && modes[k][1] == p[1];
        if (!found || (!display_fmt(p[2]) && p[2] != F_A8R8G8B8)) return D3DERR_INVALIDCALL;
        if (p[12] && p[12] != 60) return D3DERR_INVALIDCALL;
    }
    if (p[2] == F_UNKNOWN) p[2] = F_X8R8G8B8;
    if (!backbuffer_ok(p[2] == F_A8R8G8B8 || p[2] == F_X8R8G8B8 ? F_X8R8G8B8 : p[2], p[2], windowed))
        return D3DERR_INVALIDCALL;
    if (p[3] == 0) p[3] = 1;
    if (p[3] > 3 || p[4] || (p[9] && !ds_fmt(p[10]))) {
        rn_halt(c, "d3d9: CreateDevice with %u back buffers, multisample %u, depth fmt %u", p[3], p[4], p[10]);
        return D3DERR_INVALIDCALL;
    }
    for (int k = 0; k < 14; k++) st(c, pp + 4 * k, p[k], 4);     // the runtime writes back what it chose
    // Without D3DCREATE_FPU_PRESERVE the runtime sets the calling thread's FPU to single precision, round to nearest.
    if (!(flags & 2)) c->fcw &= ~0xf00u;
    dev.flags = flags;
    dev.window = window;
    dev.guest = new_obj(c, I_DEVICE);
    objs[ld(c, d3d9_obj + 4, 4) - 1].refs++;
    uint32_t bb = new_surface(c, p[0], p[1], p[2], U_RENDERTARGET, POOL_DEFAULT, (p[11] & 1) != 0);  // LOCKABLE_BACKBUFFER
    Obj *b = obj_of(c, bb, I_SURFACE);
    b->container = 0;
    dev.backbuf = dev.rt[0] = idx(b) + 1;
    if (p[9]) {
        Obj *d = obj_of(c, new_surface(c, p[0], p[1], p[10], U_DEPTHSTENCIL, POOL_DEFAULT, p[10] == F_D16_LOCKABLE), I_SURFACE);
        dev.depth = dev.ds = idx(d) + 1;
    }
    default_state();
    reset_viewport(b);
    st(c, out, dev.guest, 4);
    return D3D_OK;
}

#define DEV() do { if (ARG(0) != dev.guest) { rn_halt(c, "d3d9: %08x is not the device", ARG(0)); return D3DERR_INVALIDCALL; } } while (0)

static uint32_t IDirect3DDevice9_TestCooperativeLevel(Ctx *c) { DEV(); return D3D_OK; }
static uint32_t IDirect3DDevice9_GetAvailableTextureMem(Ctx *c) {
    DEV();
    uint32_t m = (VRAM - vram_used + (1u << 19)) & ~((1u << 20) - 1);     // rounded to the nearest MB
    TR("GetAvailableTextureMem -> %u", m);
    return m;
}
static uint32_t IDirect3DDevice9_GetDirect3D(Ctx *c) {
    DEV();
    objs[ld(c, d3d9_obj + 4, 4) - 1].refs++;
    st(c, ARG(1), d3d9_obj, 4);
    return D3D_OK;
}
static uint32_t IDirect3DDevice9_GetDeviceCaps(Ctx *c) { DEV(); TR("Device GetDeviceCaps"); put_caps(c, ARG(1)); return D3D_OK; }
static uint32_t IDirect3DDevice9_GetDisplayMode(Ctx *c) {
    DEV();
    if (ARG(1) != 0) return D3DERR_INVALIDCALL;
    if (dev.pp[8]) put_mode(c, ARG(2), DESK_W, DESK_H, F_X8R8G8B8);
    else put_mode(c, ARG(2), dev.pp[0], dev.pp[1], dev.pp[2] == F_A8R8G8B8 ? F_X8R8G8B8 : dev.pp[2]);
    return D3D_OK;
}
static uint32_t ref_out(Ctx *c, uint32_t out, uint32_t k1) {
    Obj *o = obj_k(k1);
    if (!o) { st(c, out, 0, 4); return D3DERR_NOTFOUND; }
    if (o->container) objs[o->container - 1].refs++; else o->refs++;
    st(c, out, o->guest, 4);
    return D3D_OK;
}
static uint32_t IDirect3DDevice9_GetBackBuffer(Ctx *c) {
    DEV();
    if (ARG(1) != 0 || ARG(2) >= dev.pp[3] || !ARG(4)) return D3DERR_INVALIDCALL;
    if (ARG(2) != 0) { rn_halt(c, "d3d9: GetBackBuffer(%u)", ARG(2)); return D3DERR_INVALIDCALL; }
    return ref_out(c, ARG(4), dev.backbuf);
}
static uint32_t IDirect3DDevice9_GetRenderTarget(Ctx *c) {
    DEV();
    if (ARG(1) >= 4 || !ARG(2)) return D3DERR_INVALIDCALL;
    return ref_out(c, ARG(2), dev.rt[ARG(1)]);
}
static uint32_t IDirect3DDevice9_GetDepthStencilSurface(Ctx *c) { DEV(); return ref_out(c, ARG(1), dev.ds); }

static uint32_t IDirect3DDevice9_BeginScene(Ctx *c) {
    DEV();
    if (dev.in_scene) return D3DERR_INVALIDCALL;
    dev.in_scene = 1;
    return D3D_OK;
}
static uint32_t IDirect3DDevice9_EndScene(Ctx *c) {
    DEV();
    if (!dev.in_scene) return D3DERR_INVALIDCALL;
    dev.in_scene = 0;
    return D3D_OK;
}

// Clear: each rectangle, clipped to the viewport (and the scissor rectangle when the scissor test is on).
static uint32_t IDirect3DDevice9_Clear(Ctx *c) {
    DEV();
    uint32_t n = ARG(1), rects = ARG(2), flags = ARG(3), color = ARG(4), z = ARG(5), stencil = ARG(6);
    Obj *rt = obj_k(dev.rt[0]), *ds = obj_k(dev.ds);
    TR("Clear(%u rects, flags %x, color %08x, z %g, stencil %u)", n, flags, color, (double)ldf(c, c->r[ESP] + 24), stencil);
    if ((n && !rects) || (flags & ~7u) || !flags) return D3DERR_INVALIDCALL;
    if ((flags & 6) && !ds) return D3DERR_INVALIDCALL;
    if ((flags & 4) && ds->fmt != F_D24S8 && ds->fmt != F_D15S1 && ds->fmt != F_D24X4S4 && ds->fmt != F_D24FS8)
        return D3DERR_INVALIDCALL;
    int x0 = (int)dev.vp.x, y0 = (int)dev.vp.y, x1 = x0 + (int)dev.vp.w, y1 = y0 + (int)dev.vp.h;
    if (dev.rs[174]) {
        if ((int)dev.scissor[0] > x0) x0 = (int)dev.scissor[0];
        if ((int)dev.scissor[1] > y0) y0 = (int)dev.scissor[1];
        if ((int)dev.scissor[2] < x1) x1 = (int)dev.scissor[2];
        if ((int)dev.scissor[3] < y1) y1 = (int)dev.scissor[3];
    }
    for (uint32_t k = 0; k < (n ? n : 1); k++) {
        int a0 = x0, b0 = y0, a1 = x1, b1 = y1;
        if (n) {
            int32_t r[4];
            for (int i = 0; i < 4; i++) r[i] = (int32_t)ld(c, rects + 16 * k + 4 * i, 4);
            if (r[0] > a0) a0 = r[0];
            if (r[1] > b0) b0 = r[1];
            if (r[2] < a1) a1 = r[2];
            if (r[3] < b1) b1 = r[3];
        }
        if (a0 >= a1 || b0 >= b1) continue;
        uint32_t w[10] = {(flags & 1) ? rt->gpu : 0, (flags & 6) ? ds->gpu : 0, flags, color, z, stencil,
                          (uint32_t)a0, (uint32_t)b0, (uint32_t)a1, (uint32_t)b1};
        gpu_cmd(GPU_CLEAR, 10, w);
    }
    return D3D_OK;
}

static uint32_t IDirect3DDevice9_Present(Ctx *c) {
    DEV();
    if (ARG(1) || ARG(2) || ARG(3) || ARG(4)) {
        rn_halt(c, "d3d9: Present with rects/window (%08x %08x %08x %08x)", ARG(1), ARG(2), ARG(3), ARG(4));
        return D3DERR_INVALIDCALL;
    }
    if (dev.in_scene) TR("Present inside BeginScene/EndScene");
    Obj *b = obj_k(dev.backbuf);
    uint32_t w[3] = {b->gpu, b->w, b->h};
    gpu_cmd(GPU_PRESENT, 3, w);
    dev.frames++;
    if (dev.frames == 1) rn_log("d3d9 first Present: %ux%u", b->w, b->h);
    gil_release();          // the frame hand-off may wait for the display
    gpu_submit();
    gil_acquire();
    return D3D_OK;
}

// ---- state ----------------------------------------------------------------------------------
static uint32_t IDirect3DDevice9_SetRenderState(Ctx *c) {
    DEV(); REC(IDirect3DDevice9_SetRenderState, 3, -1, 0);
    uint32_t s = ARG(1), v = ARG(2);
    if (s >= 256) return D3DERR_INVALIDCALL;
    TR("SetRenderState(%u, %08x)", s, v);
    dev.rs[s] = v;
    return D3D_OK;
}
static uint32_t IDirect3DDevice9_GetRenderState(Ctx *c) {
    DEV();
    if (ARG(1) >= 256 || !ARG(2)) return D3DERR_INVALIDCALL;
    st(c, ARG(2), dev.rs[ARG(1)], 4);
    return D3D_OK;
}
static uint32_t IDirect3DDevice9_SetTextureStageState(Ctx *c) {
    DEV(); REC(IDirect3DDevice9_SetTextureStageState, 4, -1, 0);
    uint32_t s = ARG(1), t = ARG(2), v = ARG(3);
    if (s >= 8 || t >= 33) return D3DERR_INVALIDCALL;
    TR("SetTextureStageState(%u, %u, %08x)", s, t, v);
    dev.tss[s][t] = v;
    return D3D_OK;
}
static uint32_t IDirect3DDevice9_GetTextureStageState(Ctx *c) {
    DEV();
    if (ARG(1) >= 8 || ARG(2) >= 33 || !ARG(3)) return D3DERR_INVALIDCALL;
    st(c, ARG(3), dev.tss[ARG(1)][ARG(2)], 4);
    return D3D_OK;
}
// Samplers 0-15, D3DDMAPSAMPLER (256) and D3DVERTEXTEXTURESAMPLER0-3 (257-260) are not on this part.
static uint32_t IDirect3DDevice9_SetSamplerState(Ctx *c) {
    DEV(); REC(IDirect3DDevice9_SetSamplerState, 4, -1, 0);
    uint32_t s = ARG(1), t = ARG(2), v = ARG(3);
    if (s >= 16 || t >= 14) return D3DERR_INVALIDCALL;
    TR("SetSamplerState(%u, %u, %08x)", s, t, v);
    dev.ss[s][t] = v;
    return D3D_OK;
}
static uint32_t IDirect3DDevice9_GetSamplerState(Ctx *c) {
    DEV();
    if (ARG(1) >= 16 || ARG(2) >= 14 || !ARG(3)) return D3DERR_INVALIDCALL;
    st(c, ARG(3), dev.ss[ARG(1)][ARG(2)], 4);
    return D3D_OK;
}
static uint32_t IDirect3DDevice9_SetTransform(Ctx *c) {
    DEV(); REC(IDirect3DDevice9_SetTransform, 3, 2, 64);
    uint32_t s = ARG(1), m = ARG(2);
    if (s >= 512 || !m) return D3DERR_INVALIDCALL;
    for (int k = 0; k < 16; k++) dev.xf[s][k] = ldf(c, m + 4 * k);
    return D3D_OK;
}
static uint32_t IDirect3DDevice9_GetTransform(Ctx *c) {
    DEV();
    uint32_t s = ARG(1), m = ARG(2);
    if (s >= 512 || !m) return D3DERR_INVALIDCALL;
    for (int k = 0; k < 16; k++) stf(c, m + 4 * k, dev.xf[s][k]);
    return D3D_OK;
}
static uint32_t IDirect3DDevice9_SetViewport(Ctx *c) {
    DEV(); REC(IDirect3DDevice9_SetViewport, 2, 1, 24);
    uint32_t p = ARG(1);
    Obj *rt = obj_k(dev.rt[0]);
    Viewport v = {ld(c, p, 4), ld(c, p + 4, 4), ld(c, p + 8, 4), ld(c, p + 12, 4), ldf(c, p + 16), ldf(c, p + 20)};
    TR("SetViewport(%u, %u, %ux%u, %g..%g)", v.x, v.y, v.w, v.h, (double)v.zmin, (double)v.zmax);
    if (!v.w || !v.h || v.x + v.w > rt->w || v.y + v.h > rt->h) return D3DERR_INVALIDCALL;
    dev.vp = v;
    return D3D_OK;
}
static uint32_t IDirect3DDevice9_GetViewport(Ctx *c) {
    DEV();
    uint32_t p = ARG(1);
    st(c, p, dev.vp.x, 4); st(c, p + 4, dev.vp.y, 4); st(c, p + 8, dev.vp.w, 4); st(c, p + 12, dev.vp.h, 4);
    stf(c, p + 16, dev.vp.zmin); stf(c, p + 20, dev.vp.zmax);
    return D3D_OK;
}


// ---- resources ------------------------------------------------------------------------------
static int pow2(uint32_t v) { return v && !(v & (v - 1)); }
static uint32_t mip_count(uint32_t w, uint32_t h) {
    uint32_t n = 1;
    while (w > 1 || h > 1) { w = w > 1 ? w / 2 : 1; h = h > 1 ? h / 2 : 1; n++; }
    return n;
}
static int bad_pool(uint32_t usage, uint32_t pool) {
    if (pool > POOL_SCRATCH) return 1;
    if ((usage & (U_RENDERTARGET | U_DEPTHSTENCIL)) && pool != POOL_DEFAULT) return 1;
    if ((usage & U_DYNAMIC) && pool == POOL_MANAGED) return 1;
    return 0;
}
static uint32_t lock_mem(Obj *o) {
    if (!o->mem) o->mem = guest_alloc(o->size ? o->size : 16);
    return o->mem;
}

static uint32_t IDirect3DDevice9_CreateTexture(Ctx *c) {
    DEV();
    uint32_t w = ARG(1), h = ARG(2), levels = ARG(3), usage = ARG(4), f = ARG(5), pool = ARG(6), out = ARG(7);
    TR("CreateTexture(%ux%u, %u levels, usage %x, fmt %u, pool %u)", w, h, levels, usage, f, pool);
    if (!w || !h || !out || ARG(8) || bad_pool(usage, pool)) return D3DERR_INVALIDCALL;
    if (w > 2048 || h > 2048 || (pool != POOL_SCRATCH && check_format(F_X8R8G8B8, usage & ~U_QUERY_MASK, 3, f) >= 0x80000000u))
        return D3DERR_INVALIDCALL;
    uint32_t full = mip_count(w, h);
    if (usage & U_AUTOGENMIPMAP) { rn_halt(c, "d3d9: CreateTexture with AUTOGENMIPMAP"); return D3DERR_INVALIDCALL; }
    if (!levels) levels = full;
    if (levels > full) return D3DERR_INVALIDCALL;
    if ((!pow2(w) || !pow2(h)) && levels != 1 && pool != POOL_SCRATCH) return D3DERR_INVALIDCALL;   // NONPOW2CONDITIONAL
    uint32_t g = new_obj(c, I_TEXTURE);
    if (!g) return D3DERR_OUTOFVIDEOMEMORY;
    Obj *t = &objs[nobjs - 1];
    t->w = w; t->h = h; t->fmt = f; t->usage = usage; t->pool = pool; t->type = 3; t->levels = levels;
    uint32_t tk = idx(t) + 1;
    t->level0 = (uint32_t)nobjs;
    for (uint32_t l = 0; l < levels; l++) {
        uint32_t lw = w >> l ? w >> l : 1, lh = h >> l ? h >> l : 1;
        new_surface(c, lw, lh, f, usage, pool, !(usage & (U_RENDERTARGET | U_DEPTHSTENCIL)));
        objs[nobjs - 1].container = tk;
        if (pool == POOL_DEFAULT || pool == POOL_MANAGED) vram_used += objs[nobjs - 1].size;
    }
    st(c, out, g, 4);
    return D3D_OK;
}
static Obj *level_of(Ctx *c, Obj *t, uint32_t l) {
    if (l >= t->levels) return NULL;
    (void)c;
    return &objs[t->level0 + l];
}
static uint32_t IDirect3DTexture9_GetLevelCount(Ctx *c) { SELF(I_TEXTURE); return o->levels; }
static void surface_desc(Ctx *c, Obj *o, uint32_t p) {
    uint32_t d[8] = {o->fmt, 1, o->usage, o->pool, 0, 0, o->w, o->h};
    if (dev.backbuf && o == obj_k(dev.backbuf)) { d[4] = dev.pp[4]; d[5] = dev.pp[5]; }
    for (int k = 0; k < 8; k++) st(c, p + 4 * k, d[k], 4);
}
static uint32_t IDirect3DTexture9_GetLevelDesc(Ctx *c) {
    SELF(I_TEXTURE);
    Obj *l = level_of(c, o, ARG(1));
    if (!l || !ARG(2)) return D3DERR_INVALIDCALL;
    surface_desc(c, l, ARG(2));
    return D3D_OK;
}
static uint32_t IDirect3DTexture9_GetSurfaceLevel(Ctx *c) {
    SELF(I_TEXTURE);
    Obj *l = level_of(c, o, ARG(1));
    if (!l || !ARG(2)) return D3DERR_INVALIDCALL;
    o->refs++;
    st(c, ARG(2), l->guest, 4);
    return D3D_OK;
}
// D3DLOCKED_RECT {Pitch, pBits}. Default-pool resources lock only when dynamic (or a lockable target).
static uint32_t lock_rect(Ctx *c, Obj *s, uint32_t out, uint32_t rect, uint32_t flags) {
    if (!out) return D3DERR_INVALIDCALL;
    if (s->locked) return D3DERR_INVALIDCALL;
    if (s->pool == POOL_DEFAULT && !(s->usage & U_DYNAMIC) && !s->lockable) return D3DERR_INVALIDCALL;
    if (s->gpu) { rn_halt(c, "d3d9: LockRect of a render target / depth buffer (needs readback)"); return D3DERR_INVALIDCALL; }
    uint32_t off = 0;
    if (rect) {
        uint32_t x = ld(c, rect, 4), y = ld(c, rect + 4, 4);
        off = is_dxt(s->fmt) ? (y / 4) * s->pitch + (x / 4) * (s->fmt == F_DXT1 ? 8 : 16) : y * s->pitch + x * (fmt_bits(s->fmt) / 8);
    }
    s->locked = 1;
    st(c, out, s->pitch, 4);
    st(c, out + 4, lock_mem(s) + off, 4);
    (void)flags;
    return D3D_OK;
}
static uint32_t unlock_rect(Obj *s) {
    if (!s->locked) return D3DERR_INVALIDCALL;
    s->locked = 0;
    return D3D_OK;
}
static uint32_t IDirect3DTexture9_LockRect(Ctx *c) {
    SELF(I_TEXTURE);
    Obj *l = level_of(c, o, ARG(1));
    if (!l) return D3DERR_INVALIDCALL;
    return lock_rect(c, l, ARG(2), ARG(3), ARG(4));
}
static uint32_t IDirect3DTexture9_UnlockRect(Ctx *c) {
    SELF(I_TEXTURE);
    Obj *l = level_of(c, o, ARG(1));
    return l ? unlock_rect(l) : D3DERR_INVALIDCALL;
}
static uint32_t IDirect3DTexture9_GetType(Ctx *c) { SELF(I_TEXTURE); return 3; }
static uint32_t IDirect3DTexture9_PreLoad(Ctx *c) { SELF(I_TEXTURE); return 0; }
static uint32_t IDirect3DSurface9_LockRect(Ctx *c) { SELF(I_SURFACE); return lock_rect(c, o, ARG(1), ARG(2), ARG(3)); }
static uint32_t IDirect3DSurface9_UnlockRect(Ctx *c) { SELF(I_SURFACE); return unlock_rect(o); }

static uint32_t new_buffer(Ctx *c, int iface, uint32_t len, uint32_t usage, uint32_t f, uint32_t pool, uint32_t out) {
    if (!len || !out || bad_pool(usage, pool) || (usage & (U_RENDERTARGET | U_DEPTHSTENCIL))) return D3DERR_INVALIDCALL;
    uint32_t g = new_obj(c, iface);
    if (!g) return D3DERR_OUTOFVIDEOMEMORY;
    Obj *o = &objs[nobjs - 1];
    o->size = len; o->usage = usage; o->pool = pool;
    if (iface == I_VB) { o->fvf = f; o->fmt = 100; o->type = 6; } else { o->fmt = f; o->type = 7; }
    if (pool == POOL_DEFAULT) vram_used += len;
    st(c, out, g, 4);
    return D3D_OK;
}
static uint32_t IDirect3DDevice9_CreateVertexBuffer(Ctx *c) {
    DEV();
    TR("CreateVertexBuffer(%u bytes, usage %x, fvf %x, pool %u)", ARG(1), ARG(2), ARG(3), ARG(4));
    if (ARG(6)) return D3DERR_INVALIDCALL;
    return new_buffer(c, I_VB, ARG(1), ARG(2), ARG(3), ARG(4), ARG(5));
}
static uint32_t IDirect3DDevice9_CreateIndexBuffer(Ctx *c) {
    DEV();
    TR("CreateIndexBuffer(%u bytes, usage %x, fmt %u, pool %u)", ARG(1), ARG(2), ARG(3), ARG(4));
    if (ARG(6) || (ARG(3) != F_INDEX16 && ARG(3) != F_INDEX32)) return D3DERR_INVALIDCALL;
    return new_buffer(c, I_IB, ARG(1), ARG(2), ARG(3), ARG(4), ARG(5));
}
// Lock(OffsetToLock, SizeToLock, ppbData, Flags): size 0 = to the end. Nested locks are allowed.
static uint32_t buffer_lock(Ctx *c, Obj *o) {
    uint32_t off = ARG(1), size = ARG(2), out = ARG(3);
    if (!out || off > o->size || (size && off + size > o->size)) return D3DERR_INVALIDCALL;
    o->locked++;
    st(c, out, lock_mem(o) + off, 4);
    return D3D_OK;
}
static uint32_t buffer_unlock(Obj *o) {
    if (!o->locked) return D3DERR_INVALIDCALL;
    o->locked--;
    return D3D_OK;
}
static uint32_t IDirect3DVertexBuffer9_Lock(Ctx *c) { SELF(I_VB); return buffer_lock(c, o); }
static uint32_t IDirect3DVertexBuffer9_Unlock(Ctx *c) { SELF(I_VB); return buffer_unlock(o); }
static uint32_t IDirect3DIndexBuffer9_Lock(Ctx *c) { SELF(I_IB); return buffer_lock(c, o); }
static uint32_t IDirect3DIndexBuffer9_Unlock(Ctx *c) { SELF(I_IB); return buffer_unlock(o); }
static uint32_t IDirect3DVertexBuffer9_GetDesc(Ctx *c) {
    SELF(I_VB);
    uint32_t d[6] = {100, 6, o->usage, o->pool, o->size, o->fvf}, p = ARG(1);
    for (int k = 0; k < 6; k++) st(c, p + 4 * k, d[k], 4);
    return D3D_OK;
}
static uint32_t IDirect3DIndexBuffer9_GetDesc(Ctx *c) {
    SELF(I_IB);
    uint32_t d[5] = {o->fmt, 7, o->usage, o->pool, o->size}, p = ARG(1);
    for (int k = 0; k < 5; k++) st(c, p + 4 * k, d[k], 4);
    return D3D_OK;
}

static uint32_t IDirect3DDevice9_CreateRenderTarget(Ctx *c) {
    DEV();
    uint32_t w = ARG(1), h = ARG(2), f = ARG(3), ms = ARG(4), lockable = ARG(6), out = ARG(7);
    TR("CreateRenderTarget(%ux%u, fmt %u, ms %u, lockable %u)", w, h, f, ms, lockable);
    if (!w || !h || !out || ARG(8) || !rt_fmt(f)) return D3DERR_INVALIDCALL;
    if (ms) { rn_halt(c, "d3d9: multisampled render target"); return D3DERR_INVALIDCALL; }
    st(c, out, new_surface(c, w, h, f, U_RENDERTARGET, POOL_DEFAULT, lockable != 0), 4);
    return D3D_OK;
}
static uint32_t IDirect3DDevice9_CreateDepthStencilSurface(Ctx *c) {
    DEV();
    uint32_t w = ARG(1), h = ARG(2), f = ARG(3), ms = ARG(4), out = ARG(7);
    TR("CreateDepthStencilSurface(%ux%u, fmt %u, ms %u, discard %u)", w, h, f, ms, ARG(6));
    if (!w || !h || !out || ARG(8) || !ds_fmt(f)) return D3DERR_INVALIDCALL;
    if (ms) { rn_halt(c, "d3d9: multisampled depth buffer"); return D3DERR_INVALIDCALL; }
    st(c, out, new_surface(c, w, h, f, U_DEPTHSTENCIL, POOL_DEFAULT, f == F_D16_LOCKABLE), 4);
    return D3D_OK;
}
static uint32_t IDirect3DDevice9_CreateOffscreenPlainSurface(Ctx *c) {
    DEV();
    uint32_t w = ARG(1), h = ARG(2), f = ARG(3), pool = ARG(4), out = ARG(5);
    TR("CreateOffscreenPlainSurface(%ux%u, fmt %u, pool %u)", w, h, f, pool);
    if (!w || !h || !out || ARG(6) || pool == POOL_MANAGED || pool > POOL_SCRATCH) return D3DERR_INVALIDCALL;
    if (pool != POOL_SCRATCH && !tex_fmt(f)) return D3DERR_INVALIDCALL;
    st(c, out, new_surface(c, w, h, f, 0, pool, 1), 4);
    return D3D_OK;
}
static uint32_t IDirect3DDevice9_SetRenderTarget(Ctx *c) {
    DEV();
    uint32_t i = ARG(1), p = ARG(2);
    if (i >= 4 || (i == 0 && !p)) return D3DERR_INVALIDCALL;
    Obj *s = p ? obj_of(c, p, I_SURFACE) : NULL;
    if (p && (!s || !(s->usage & U_RENDERTARGET))) return D3DERR_INVALIDCALL;
    TR("SetRenderTarget(%u, %08x)", i, p);
    dev.rt[i] = s ? idx(s) + 1 : 0;
    if (i == 0) reset_viewport(s);
    return D3D_OK;
}
static uint32_t IDirect3DDevice9_SetDepthStencilSurface(Ctx *c) {
    DEV();
    uint32_t p = ARG(1);
    Obj *s = p ? obj_of(c, p, I_SURFACE) : NULL;
    if (p && (!s || !(s->usage & U_DEPTHSTENCIL))) return D3DERR_INVALIDCALL;
    TR("SetDepthStencilSurface(%08x)", p);
    dev.ds = s ? idx(s) + 1 : 0;
    return D3D_OK;
}

// ---- declarations and shaders -----------------------------------------------------------------
// D3DVERTEXELEMENT9 {WORD Stream, Offset; BYTE Type, Method, Usage, UsageIndex}, ended by stream 0xff.
static uint32_t IDirect3DDevice9_CreateVertexDeclaration(Ctx *c) {
    DEV();
    uint32_t p = ARG(1), out = ARG(2), n = 0;
    if (!p || !out) return D3DERR_INVALIDCALL;
    while (ld(c, p + 8 * n, 2) != 0xff) if (++n > 64) return D3DERR_INVALIDCALL;
    uint32_t g = new_obj(c, I_DECL);
    Obj *o = &objs[nobjs - 1];
    o->nblob = 2 * (n + 1);
    o->blob = malloc(4u * o->nblob);
    memcpy(o->blob, G(p), 8u * (n + 1));
    if (rn_trace())
        for (uint32_t k = 0; k < n; k++)
            rn_log("d3d9   element stream %u off %u type %u method %u usage %u/%u", ld(c, p + 8 * k, 2),
                   ld(c, p + 8 * k + 2, 2), ld(c, p + 8 * k + 4, 1), ld(c, p + 8 * k + 5, 1), ld(c, p + 8 * k + 6, 1),
                   ld(c, p + 8 * k + 7, 1));
    st(c, out, g, 4);
    return D3D_OK;
}
static uint32_t IDirect3DVertexDeclaration9_GetDeclaration(Ctx *c) {
    SELF(I_DECL);
    if (ARG(2)) st(c, ARG(2), o->nblob / 2, 4);
    if (ARG(1)) memcpy(G(ARG(1)), o->blob, 4u * o->nblob);
    return D3D_OK;
}
// Shader tokens: version, instructions, D3DSIO_END (0x0000ffff).
static uint32_t new_shader(Ctx *c, int iface, uint32_t p, uint32_t out) {
    if (!p || !out) return D3DERR_INVALIDCALL;
    uint32_t ver = ld(c, p, 4), n = 1;
    if (iface == I_VS ? (ver >> 16 != 0xfffe || (ver & 0xffff) > 0x200) : (ver >> 16 != 0xffff || (ver & 0xffff) > 0x200))
        return D3DERR_INVALIDCALL;
    while (ld(c, p + 4 * (n - 1), 4) != 0x0000ffffu) if (++n > 65536) return D3DERR_INVALIDCALL;
    uint32_t g = new_obj(c, iface);
    Obj *o = &objs[nobjs - 1];
    o->nblob = n;
    o->blob = malloc(4u * n);
    memcpy(o->blob, G(p), 4u * n);
    TR("Create%sShader %s_%u_%u, %u tokens -> %08x", iface == I_VS ? "Vertex" : "Pixel", iface == I_VS ? "vs" : "ps",
       (ver >> 8) & 0xff, ver & 0xff, n, g);
    st(c, out, g, 4);
    return D3D_OK;
}
static uint32_t IDirect3DDevice9_CreateVertexShader(Ctx *c) { DEV(); return new_shader(c, I_VS, ARG(1), ARG(2)); }
static uint32_t IDirect3DDevice9_CreatePixelShader(Ctx *c) { DEV(); return new_shader(c, I_PS, ARG(1), ARG(2)); }
static uint32_t shader_function(Ctx *c, Obj *o) {
    if (ARG(2)) st(c, ARG(2), 4 * o->nblob, 4);
    if (ARG(1)) memcpy(G(ARG(1)), o->blob, 4u * o->nblob);
    return D3D_OK;
}
static uint32_t IDirect3DVertexShader9_GetFunction(Ctx *c) { SELF(I_VS); return shader_function(c, o); }
static uint32_t IDirect3DPixelShader9_GetFunction(Ctx *c) { SELF(I_PS); return shader_function(c, o); }

// Bindings hold no reference in this layer's bookkeeping beyond the index (d3d9 AddRefs bound objects;
// the game cannot observe it except through Release return values).
static uint32_t bind(Ctx *c, uint32_t *slot, uint32_t p, int iface) {
    Obj *o = p ? obj_of(c, p, iface) : NULL;
    if (p && !o) return D3DERR_INVALIDCALL;
    *slot = o ? idx(o) + 1 : 0;
    return D3D_OK;
}
static uint32_t get_bound(Ctx *c, uint32_t out, uint32_t k1) {
    if (!out) return D3DERR_INVALIDCALL;
    if (!k1) { st(c, out, 0, 4); return D3D_OK; }
    return ref_out(c, out, k1);
}
static uint32_t IDirect3DDevice9_SetVertexDeclaration(Ctx *c) { DEV(); REC(IDirect3DDevice9_SetVertexDeclaration, 2, -1, 0); dev.fvf = 0; return bind(c, &dev.decl, ARG(1), I_DECL); }
static uint32_t IDirect3DDevice9_GetVertexDeclaration(Ctx *c) { DEV(); return get_bound(c, ARG(1), dev.decl); }
static uint32_t IDirect3DDevice9_SetFVF(Ctx *c) { DEV(); REC(IDirect3DDevice9_SetFVF, 2, -1, 0); TR("SetFVF(%x)", ARG(1)); dev.fvf = ARG(1); dev.decl = 0; return D3D_OK; }
static uint32_t IDirect3DDevice9_GetFVF(Ctx *c) { DEV(); st(c, ARG(1), dev.fvf, 4); return D3D_OK; }
static uint32_t IDirect3DDevice9_SetVertexShader(Ctx *c) { DEV(); REC(IDirect3DDevice9_SetVertexShader, 2, -1, 0); return bind(c, &dev.vs, ARG(1), I_VS); }
static uint32_t IDirect3DDevice9_GetVertexShader(Ctx *c) { DEV(); return get_bound(c, ARG(1), dev.vs); }
static uint32_t IDirect3DDevice9_SetPixelShader(Ctx *c) { DEV(); REC(IDirect3DDevice9_SetPixelShader, 2, -1, 0); return bind(c, &dev.ps, ARG(1), I_PS); }
static uint32_t IDirect3DDevice9_GetPixelShader(Ctx *c) { DEV(); return get_bound(c, ARG(1), dev.ps); }
static uint32_t IDirect3DDevice9_SetIndices(Ctx *c) { DEV(); REC(IDirect3DDevice9_SetIndices, 2, -1, 0); return bind(c, &dev.ib, ARG(1), I_IB); }
static uint32_t IDirect3DDevice9_GetIndices(Ctx *c) { DEV(); return get_bound(c, ARG(1), dev.ib); }
static uint32_t IDirect3DDevice9_SetTexture(Ctx *c) {
    DEV(); REC(IDirect3DDevice9_SetTexture, 3, -1, 0);
    uint32_t s = ARG(1), p = ARG(2);
    if (s >= 16) return D3DERR_INVALIDCALL;
    Obj *o = p ? obj_of(c, p, -1) : NULL;
    if (p && (!o || (o->iface != I_TEXTURE && o->iface != I_CUBE))) return D3DERR_INVALIDCALL;
    dev.tex[s] = o ? idx(o) + 1 : 0;
    return D3D_OK;
}
static uint32_t IDirect3DDevice9_GetTexture(Ctx *c) { DEV(); if (ARG(1) >= 16) return D3DERR_INVALIDCALL; return get_bound(c, ARG(2), dev.tex[ARG(1)]); }
static uint32_t IDirect3DDevice9_SetStreamSource(Ctx *c) {
    DEV(); REC(IDirect3DDevice9_SetStreamSource, 5, -1, 0);
    uint32_t s = ARG(1);
    if (s >= 16) return D3DERR_INVALIDCALL;
    uint32_t r = bind(c, &dev.stream[s].vb, ARG(2), I_VB);
    dev.stream[s].off = ARG(3);
    dev.stream[s].stride = ARG(4);
    return r;
}
static uint32_t IDirect3DDevice9_GetStreamSource(Ctx *c) {
    DEV();
    uint32_t s = ARG(1);
    if (s >= 16) return D3DERR_INVALIDCALL;
    if (ARG(3)) st(c, ARG(3), dev.stream[s].off, 4);
    if (ARG(4)) st(c, ARG(4), dev.stream[s].stride, 4);
    return get_bound(c, ARG(2), dev.stream[s].vb);
}
// Instancing is a shader model 3 feature: this part takes only the default frequency 1.
static uint32_t IDirect3DDevice9_SetStreamSourceFreq(Ctx *c) {
    DEV(); REC(IDirect3DDevice9_SetStreamSourceFreq, 3, -1, 0);
    if (ARG(1) >= 16 || ARG(2) != 1) return D3DERR_INVALIDCALL;
    dev.stream[ARG(1)].freq = 1;
    return D3D_OK;
}

static uint32_t set_consts(Ctx *c, void *dst, uint32_t nregs, uint32_t words) {
    uint32_t start = ARG(1), p = ARG(2), n = ARG(3);
    if (!p || start + n > nregs) return D3DERR_INVALIDCALL;
    memcpy((char *)dst + 4u * words * start, G(p), 4u * words * n);
    return D3D_OK;
}
static uint32_t get_consts(Ctx *c, const void *src, uint32_t nregs, uint32_t words) {
    uint32_t start = ARG(1), p = ARG(2), n = ARG(3);
    if (!p || start + n > nregs) return D3DERR_INVALIDCALL;
    memcpy(G(p), (const char *)src + 4u * words * start, 4u * words * n);
    return D3D_OK;
}
static uint32_t IDirect3DDevice9_SetVertexShaderConstantF(Ctx *c) { DEV(); REC(IDirect3DDevice9_SetVertexShaderConstantF, 4, 2, 16 * ARG(3)); return set_consts(c, dev.vsf, 256, 4); }
static uint32_t IDirect3DDevice9_GetVertexShaderConstantF(Ctx *c) { DEV(); return get_consts(c, dev.vsf, 256, 4); }
static uint32_t IDirect3DDevice9_SetVertexShaderConstantI(Ctx *c) { DEV(); REC(IDirect3DDevice9_SetVertexShaderConstantI, 4, 2, 16 * ARG(3)); return set_consts(c, dev.vsi, 16, 4); }
static uint32_t IDirect3DDevice9_SetVertexShaderConstantB(Ctx *c) { DEV(); REC(IDirect3DDevice9_SetVertexShaderConstantB, 4, 2, 4 * ARG(3)); return set_consts(c, dev.vsb, 16, 1); }
static uint32_t IDirect3DDevice9_SetPixelShaderConstantF(Ctx *c) { DEV(); REC(IDirect3DDevice9_SetPixelShaderConstantF, 4, 2, 16 * ARG(3)); return set_consts(c, dev.psf, 32, 4); }
static uint32_t IDirect3DDevice9_GetPixelShaderConstantF(Ctx *c) { DEV(); return get_consts(c, dev.psf, 32, 4); }
static uint32_t IDirect3DDevice9_SetPixelShaderConstantI(Ctx *c) { DEV(); REC(IDirect3DDevice9_SetPixelShaderConstantI, 4, 2, 16 * ARG(3)); return set_consts(c, dev.psi, 16, 4); }
static uint32_t IDirect3DDevice9_SetPixelShaderConstantB(Ctx *c) { DEV(); REC(IDirect3DDevice9_SetPixelShaderConstantB, 4, 2, 4 * ARG(3)); return set_consts(c, dev.psb, 16, 1); }

// ---- fixed function state -----------------------------------------------------------------------
static uint32_t IDirect3DDevice9_SetMaterial(Ctx *c) { DEV(); REC(IDirect3DDevice9_SetMaterial, 2, 1, 68); if (!ARG(1)) return D3DERR_INVALIDCALL; memcpy(dev.material, G(ARG(1)), 68); return D3D_OK; }
static uint32_t IDirect3DDevice9_GetMaterial(Ctx *c) { DEV(); if (!ARG(1)) return D3DERR_INVALIDCALL; memcpy(G(ARG(1)), dev.material, 68); return D3D_OK; }
// D3DLIGHT9 is 104 bytes. Lights are indexed by any DWORD; this layer keeps 64 slots.
static uint32_t IDirect3DDevice9_SetLight(Ctx *c) {
    DEV(); REC(IDirect3DDevice9_SetLight, 3, 2, 104);
    uint32_t i = ARG(1);
    if (!ARG(2)) return D3DERR_INVALIDCALL;
    if (i >= 64) { rn_halt(c, "d3d9: light index %u", i); return D3DERR_INVALIDCALL; }
    memcpy(dev.light[i], G(ARG(2)), 104);
    dev.light_set[i] = 1;
    return D3D_OK;
}
static uint32_t IDirect3DDevice9_GetLight(Ctx *c) {
    DEV();
    uint32_t i = ARG(1);
    if (i >= 64 || !dev.light_set[i] || !ARG(2)) return D3DERR_INVALIDCALL;
    memcpy(G(ARG(2)), dev.light[i], 104);
    return D3D_OK;
}
// LightEnable on a light never set defines it with the default light: white directional along +z.
static uint32_t IDirect3DDevice9_LightEnable(Ctx *c) {
    DEV(); REC(IDirect3DDevice9_LightEnable, 3, -1, 0);
    uint32_t i = ARG(1);
    if (i >= 64) { rn_halt(c, "d3d9: light index %u", i); return D3DERR_INVALIDCALL; }
    if (!dev.light_set[i]) {
        memset(dev.light[i], 0, 104);
        dev.light[i][0] = 3;                                     // D3DLIGHT_DIRECTIONAL
        dev.light[i][1] = dev.light[i][2] = dev.light[i][3] = F1; // Diffuse 1,1,1,0
        dev.light[i][18] = F1;                                   // Direction 0,0,1
        dev.light_set[i] = 1;
    }
    dev.light_on[i] = ARG(2) != 0;
    return D3D_OK;
}
static uint32_t IDirect3DDevice9_GetLightEnable(Ctx *c) {
    DEV();
    uint32_t i = ARG(1);
    if (i >= 64 || !dev.light_set[i] || !ARG(2)) return D3DERR_INVALIDCALL;
    st(c, ARG(2), dev.light_on[i] ? 128 : 0, 4);     // TRUE as d3d9 reports it: a nonzero value
    return D3D_OK;
}
static uint32_t IDirect3DDevice9_SetClipPlane(Ctx *c) {
    DEV(); REC(IDirect3DDevice9_SetClipPlane, 3, 2, 16);
    if (ARG(1) >= 6 || !ARG(2)) return D3DERR_INVALIDCALL;
    memcpy(dev.clip[ARG(1)], G(ARG(2)), 16);
    return D3D_OK;
}
static uint32_t IDirect3DDevice9_GetClipPlane(Ctx *c) {
    DEV();
    if (ARG(1) >= 6 || !ARG(2)) return D3DERR_INVALIDCALL;
    memcpy(G(ARG(2)), dev.clip[ARG(1)], 16);
    return D3D_OK;
}
static uint32_t IDirect3DDevice9_SetScissorRect(Ctx *c) {
    DEV(); REC(IDirect3DDevice9_SetScissorRect, 2, 1, 16);
    if (!ARG(1)) return D3DERR_INVALIDCALL;
    for (int k = 0; k < 4; k++) dev.scissor[k] = ld(c, ARG(1) + 4 * k, 4);
    return D3D_OK;
}
static uint32_t IDirect3DDevice9_GetScissorRect(Ctx *c) {
    DEV();
    if (!ARG(1)) return D3DERR_INVALIDCALL;
    for (int k = 0; k < 4; k++) st(c, ARG(1) + 4 * k, dev.scissor[k], 4);
    return D3D_OK;
}
// ValidateDevice: one pass for whatever is bound; the renderer takes any state this part takes.
static uint32_t IDirect3DDevice9_ValidateDevice(Ctx *c) { DEV(); if (ARG(1)) st(c, ARG(1), 1, 4); TR("ValidateDevice -> 1 pass"); return D3D_OK; }
static uint32_t IDirect3DDevice9_EvictManagedResources(Ctx *c) { DEV(); return D3D_OK; }
static uint32_t IDirect3DDevice9_ShowCursor(Ctx *c) { DEV(); int was = dev.cursor_shown; dev.cursor_shown = ARG(1) != 0; return (uint32_t)was; }
static uint32_t IDirect3DDevice9_SetCursorPosition(Ctx *c) { DEV(); return 0; }
// D3DGAMMARAMP: 3 x 256 WORDs. The ramp is kept; the renderer applies it at present (not yet).
static uint32_t IDirect3DDevice9_SetGammaRamp(Ctx *c) {
    DEV();
    if (ARG(1) != 0 || !ARG(3)) return 0;
    memcpy(dev.gamma, G(ARG(3)), sizeof dev.gamma);
    TR("SetGammaRamp(flags %x): r[128]=%u", ARG(2), dev.gamma[0][128]);
    return 0;
}
static uint32_t IDirect3DDevice9_GetGammaRamp(Ctx *c) {
    DEV();
    if (ARG(1) != 0 || !ARG(2)) return 0;
    memcpy(G(ARG(2)), dev.gamma, sizeof dev.gamma);
    return 0;
}

// ---- draws --------------------------------------------------------------------------------------
// The renderer does not draw yet: the call is checked as d3d9 checks it and goes to the list as GPU_DRAW.
static uint32_t prim_ok(uint32_t type, uint32_t count) {
    return type >= 1 && type <= 6 && count && count <= 0xfffff && dev.in_scene;
}
static void draw_cmd(uint32_t type, uint32_t count) {
    uint32_t w[4] = {type, count, dev.vs, dev.ps};
    gpu_cmd(GPU_DRAW, 4, w);
}
static uint32_t IDirect3DDevice9_DrawPrimitive(Ctx *c) {
    DEV();
    if (!prim_ok(ARG(1), ARG(3)) || !dev.stream[0].vb) return D3DERR_INVALIDCALL;
    draw_cmd(ARG(1), ARG(3));
    return D3D_OK;
}
static uint32_t IDirect3DDevice9_DrawIndexedPrimitive(Ctx *c) {
    DEV();
    if (!prim_ok(ARG(1), ARG(6)) || !dev.stream[0].vb || !dev.ib) return D3DERR_INVALIDCALL;
    draw_cmd(ARG(1), ARG(6));
    return D3D_OK;
}
// The UP draws leave stream 0 (and the index buffer for the indexed one) unset, as documented.
static uint32_t IDirect3DDevice9_DrawPrimitiveUP(Ctx *c) {
    DEV();
    if (!prim_ok(ARG(1), ARG(2)) || !ARG(3) || !ARG(4)) return D3DERR_INVALIDCALL;
    draw_cmd(ARG(1), ARG(2));
    dev.stream[0].vb = 0; dev.stream[0].off = 0; dev.stream[0].stride = 0;
    return D3D_OK;
}
static uint32_t IDirect3DDevice9_DrawIndexedPrimitiveUP(Ctx *c) {
    DEV();
    if (!prim_ok(ARG(1), ARG(4)) || !ARG(5) || !ARG(7) || !ARG(8) || (ARG(6) != F_INDEX16 && ARG(6) != F_INDEX32))
        return D3DERR_INVALIDCALL;
    draw_cmd(ARG(1), ARG(4));
    dev.stream[0].vb = 0; dev.stream[0].off = 0; dev.stream[0].stride = 0;
    dev.ib = 0;
    return D3D_OK;
}

// ---- state blocks ---------------------------------------------------------------------------------
static uint32_t guest_of(uint32_t k1) { return k1 ? objs[k1 - 1].guest : 0; }
static uint32_t IDirect3DDevice9_BeginStateBlock(Ctx *c) {
    DEV();
    if (dev.recording) return D3DERR_INVALIDCALL;
    dev.recording = 1;
    dev.nrec = 0;
    return D3D_OK;
}
static uint32_t IDirect3DDevice9_EndStateBlock(Ctx *c) {
    DEV();
    if (!dev.recording || !ARG(1)) return D3DERR_INVALIDCALL;
    dev.recording = 0;
    uint32_t g = new_obj(c, I_SB);
    Obj *o = &objs[nobjs - 1];
    o->rec = malloc(sizeof(Rec) * (dev.nrec ? dev.nrec : 1));
    memcpy(o->rec, dev.rec, sizeof(Rec) * dev.nrec);
    o->nrec = dev.nrec;
    TR("EndStateBlock: %u calls -> %08x", dev.nrec, g);
    st(c, ARG(1), g, 4);
    return D3D_OK;
}
// Apply replays the recorded calls through their handlers on a scratch frame below the stack.
static uint32_t IDirect3DStateBlock9_Apply(Ctx *c) {
    SELF(I_SB);
    if (dev.recording) return D3DERR_INVALIDCALL;
    uint32_t sp = c->r[ESP];
    for (uint32_t k = 0; k < o->nrec && !c->halt; k++) {
        Rec *r = &o->rec[k];
        c->r[ESP] = sp - 64;
        for (uint32_t i = 0; i < r->n; i++) st(c, c->r[ESP] + 4 + 4 * i, r->a[i], 4);
        r->fn(c);
    }
    c->r[ESP] = sp;
    return D3D_OK;
}
// Capture refreshes the recorded values from the device's current state.
static uint32_t IDirect3DStateBlock9_Capture(Ctx *c) {
    SELF(I_SB);
    if (dev.recording) return D3DERR_INVALIDCALL;
    for (uint32_t k = 0; k < o->nrec; k++) {
        Rec *r = &o->rec[k];
        uint32_t *a = r->a, d = r->pidx >= 0 ? a[r->pidx] : 0;
        if (r->fn == IDirect3DDevice9_SetRenderState) a[2] = dev.rs[a[1]];
        else if (r->fn == IDirect3DDevice9_SetTextureStageState) a[3] = dev.tss[a[1]][a[2]];
        else if (r->fn == IDirect3DDevice9_SetSamplerState) a[3] = dev.ss[a[1]][a[2]];
        else if (r->fn == IDirect3DDevice9_SetTransform) memcpy(G(d), dev.xf[a[1]], 64);
        else if (r->fn == IDirect3DDevice9_SetViewport) memcpy(G(d), &dev.vp, 24);
        else if (r->fn == IDirect3DDevice9_SetVertexDeclaration) a[1] = guest_of(dev.decl);
        else if (r->fn == IDirect3DDevice9_SetFVF) a[1] = dev.fvf;
        else if (r->fn == IDirect3DDevice9_SetVertexShader) a[1] = guest_of(dev.vs);
        else if (r->fn == IDirect3DDevice9_SetPixelShader) a[1] = guest_of(dev.ps);
        else if (r->fn == IDirect3DDevice9_SetIndices) a[1] = guest_of(dev.ib);
        else if (r->fn == IDirect3DDevice9_SetTexture) a[2] = guest_of(dev.tex[a[1]]);
        else if (r->fn == IDirect3DDevice9_SetStreamSource) {
            a[2] = guest_of(dev.stream[a[1]].vb); a[3] = dev.stream[a[1]].off; a[4] = dev.stream[a[1]].stride;
        }
        else if (r->fn == IDirect3DDevice9_SetVertexShaderConstantF) memcpy(G(d), dev.vsf[a[1]], r->bytes);
        else if (r->fn == IDirect3DDevice9_SetVertexShaderConstantI) memcpy(G(d), dev.vsi[a[1]], r->bytes);
        else if (r->fn == IDirect3DDevice9_SetVertexShaderConstantB) memcpy(G(d), &dev.vsb[a[1]], r->bytes);
        else if (r->fn == IDirect3DDevice9_SetPixelShaderConstantF) memcpy(G(d), dev.psf[a[1]], r->bytes);
        else if (r->fn == IDirect3DDevice9_SetPixelShaderConstantI) memcpy(G(d), dev.psi[a[1]], r->bytes);
        else if (r->fn == IDirect3DDevice9_SetPixelShaderConstantB) memcpy(G(d), &dev.psb[a[1]], r->bytes);
        else if (r->fn == IDirect3DDevice9_SetMaterial) memcpy(G(d), dev.material, 68);
        else if (r->fn == IDirect3DDevice9_SetLight) memcpy(G(d), dev.light[a[1]], 104);
        else if (r->fn == IDirect3DDevice9_LightEnable) a[2] = dev.light_on[a[1]];
        else if (r->fn == IDirect3DDevice9_SetClipPlane) memcpy(G(d), dev.clip[a[1]], 16);
        else if (r->fn == IDirect3DDevice9_SetScissorRect) memcpy(G(d), dev.scissor, 16);
        else if (r->fn != IDirect3DDevice9_SetStreamSourceFreq) { rn_halt(c, "d3d9: StateBlock Capture of a call it cannot read back"); return D3DERR_INVALIDCALL; }
    }
    return D3D_OK;
}

// ---- queries ----------------------------------------------------------------------------------
// R300: event (8) and occlusion (9) queries.
static uint32_t IDirect3DDevice9_CreateQuery(Ctx *c) {
    DEV();
    uint32_t type = ARG(1), out = ARG(2);
    uint32_t r = type == 8 || type == 9 ? D3D_OK : D3DERR_NOTAVAILABLE;
    TR("CreateQuery(%u) -> %08x", type, r);
    if (r || !out) return r;
    uint32_t g = new_obj(c, I_QUERY);
    objs[nobjs - 1].type = type;
    st(c, out, g, 4);
    return D3D_OK;
}

// ---- surfaces -------------------------------------------------------------------------------
static uint32_t IDirect3DSurface9_GetDesc(Ctx *c) { SELF(I_SURFACE); surface_desc(c, o, ARG(1)); return D3D_OK; }

#define DEV_ENTRY(name, n) {"d3d9.dll", "IDirect3DDevice9::" #name, n, IDirect3DDevice9_##name}
#define D3D_ENTRY(name, n) {"d3d9.dll", "IDirect3D9::" #name, n, IDirect3D9_##name}
#define UNK_ENTRIES(iface) {"d3d9.dll", iface "::QueryInterface", 3, unk_QueryInterface}, \
    {"d3d9.dll", iface "::AddRef", 1, unk_AddRef}, {"d3d9.dll", iface "::Release", 1, unk_Release}
const Api d3d9_apis[] = {
    {"d3d9.dll", "Direct3DCreate9", 1, Direct3DCreate9_},
    {"d3d9.dll", "Direct3DShaderValidatorCreate9", 0, Direct3DShaderValidatorCreate9_},
    {"d3d9.dll", "DebugSetMute", 0, DebugSetMute_},
    UNK_ENTRIES("IDirect3D9"), UNK_ENTRIES("IDirect3DDevice9"), UNK_ENTRIES("IDirect3DSurface9"),
    UNK_ENTRIES("IDirect3DTexture9"), UNK_ENTRIES("IDirect3DCubeTexture9"), UNK_ENTRIES("IDirect3DVertexBuffer9"),
    UNK_ENTRIES("IDirect3DIndexBuffer9"), UNK_ENTRIES("IDirect3DSwapChain9"),
    D3D_ENTRY(GetAdapterCount, 1), D3D_ENTRY(GetAdapterIdentifier, 4), D3D_ENTRY(GetAdapterModeCount, 3),
    D3D_ENTRY(EnumAdapterModes, 5), D3D_ENTRY(GetAdapterDisplayMode, 3), D3D_ENTRY(CheckDeviceType, 6),
    D3D_ENTRY(CheckDeviceFormat, 7), D3D_ENTRY(CheckDeviceMultiSampleType, 7), D3D_ENTRY(CheckDepthStencilMatch, 6),
    D3D_ENTRY(GetDeviceCaps, 4), D3D_ENTRY(GetAdapterMonitor, 2), D3D_ENTRY(CreateDevice, 7),
    DEV_ENTRY(TestCooperativeLevel, 1), DEV_ENTRY(GetAvailableTextureMem, 1), DEV_ENTRY(GetDirect3D, 2),
    DEV_ENTRY(GetDeviceCaps, 2), DEV_ENTRY(GetDisplayMode, 3), DEV_ENTRY(GetBackBuffer, 5),
    DEV_ENTRY(GetRenderTarget, 3), DEV_ENTRY(GetDepthStencilSurface, 2), DEV_ENTRY(BeginScene, 1),
    DEV_ENTRY(EndScene, 1), DEV_ENTRY(Clear, 7), DEV_ENTRY(Present, 5), DEV_ENTRY(SetRenderState, 3),
    DEV_ENTRY(GetRenderState, 3), DEV_ENTRY(SetTextureStageState, 4), DEV_ENTRY(GetTextureStageState, 4),
    DEV_ENTRY(SetSamplerState, 4), DEV_ENTRY(GetSamplerState, 4), DEV_ENTRY(SetTransform, 3),
    DEV_ENTRY(GetTransform, 3), DEV_ENTRY(SetViewport, 2), DEV_ENTRY(GetViewport, 2),
    DEV_ENTRY(CreateTexture, 9), DEV_ENTRY(CreateVertexBuffer, 7), DEV_ENTRY(CreateIndexBuffer, 7),
    DEV_ENTRY(CreateRenderTarget, 9), DEV_ENTRY(CreateDepthStencilSurface, 9), DEV_ENTRY(CreateOffscreenPlainSurface, 7),
    DEV_ENTRY(SetRenderTarget, 3), DEV_ENTRY(SetDepthStencilSurface, 2), DEV_ENTRY(CreateVertexDeclaration, 3),
    DEV_ENTRY(CreateVertexShader, 3), DEV_ENTRY(CreatePixelShader, 3), DEV_ENTRY(SetVertexDeclaration, 2),
    DEV_ENTRY(GetVertexDeclaration, 2), DEV_ENTRY(SetFVF, 2), DEV_ENTRY(GetFVF, 2), DEV_ENTRY(SetVertexShader, 2),
    DEV_ENTRY(GetVertexShader, 2), DEV_ENTRY(SetPixelShader, 2), DEV_ENTRY(GetPixelShader, 2), DEV_ENTRY(SetIndices, 2),
    DEV_ENTRY(GetIndices, 2), DEV_ENTRY(SetTexture, 3), DEV_ENTRY(GetTexture, 3), DEV_ENTRY(SetStreamSource, 5),
    DEV_ENTRY(GetStreamSource, 5), DEV_ENTRY(SetStreamSourceFreq, 3), DEV_ENTRY(SetVertexShaderConstantF, 4),
    DEV_ENTRY(GetVertexShaderConstantF, 4), DEV_ENTRY(SetVertexShaderConstantI, 4), DEV_ENTRY(SetVertexShaderConstantB, 4),
    DEV_ENTRY(SetPixelShaderConstantF, 4), DEV_ENTRY(GetPixelShaderConstantF, 4), DEV_ENTRY(SetPixelShaderConstantI, 4),
    DEV_ENTRY(SetPixelShaderConstantB, 4), DEV_ENTRY(SetMaterial, 2), DEV_ENTRY(GetMaterial, 2), DEV_ENTRY(SetLight, 3),
    DEV_ENTRY(GetLight, 3), DEV_ENTRY(LightEnable, 3), DEV_ENTRY(GetLightEnable, 3), DEV_ENTRY(SetClipPlane, 3),
    DEV_ENTRY(GetClipPlane, 3), DEV_ENTRY(SetScissorRect, 2), DEV_ENTRY(GetScissorRect, 2), DEV_ENTRY(ValidateDevice, 2),
    DEV_ENTRY(EvictManagedResources, 1), DEV_ENTRY(ShowCursor, 2), DEV_ENTRY(SetCursorPosition, 4),
    DEV_ENTRY(SetGammaRamp, 4), DEV_ENTRY(GetGammaRamp, 3), DEV_ENTRY(CreateQuery, 3),
    DEV_ENTRY(BeginStateBlock, 1), DEV_ENTRY(EndStateBlock, 2), DEV_ENTRY(DrawPrimitive, 4),
    DEV_ENTRY(DrawIndexedPrimitive, 7), DEV_ENTRY(DrawPrimitiveUP, 5), DEV_ENTRY(DrawIndexedPrimitiveUP, 9),
    {"d3d9.dll", "IDirect3DStateBlock9::Apply", 1, IDirect3DStateBlock9_Apply},
    {"d3d9.dll", "IDirect3DStateBlock9::Capture", 1, IDirect3DStateBlock9_Capture},
    {"d3d9.dll", "IDirect3DSurface9::GetDesc", 2, IDirect3DSurface9_GetDesc},
    {"d3d9.dll", "IDirect3DSurface9::LockRect", 4, IDirect3DSurface9_LockRect},
    {"d3d9.dll", "IDirect3DSurface9::UnlockRect", 1, IDirect3DSurface9_UnlockRect},
    {"d3d9.dll", "IDirect3DTexture9::GetLevelCount", 1, IDirect3DTexture9_GetLevelCount},
    {"d3d9.dll", "IDirect3DTexture9::GetLevelDesc", 3, IDirect3DTexture9_GetLevelDesc},
    {"d3d9.dll", "IDirect3DTexture9::GetSurfaceLevel", 3, IDirect3DTexture9_GetSurfaceLevel},
    {"d3d9.dll", "IDirect3DTexture9::LockRect", 5, IDirect3DTexture9_LockRect},
    {"d3d9.dll", "IDirect3DTexture9::UnlockRect", 2, IDirect3DTexture9_UnlockRect},
    {"d3d9.dll", "IDirect3DTexture9::GetType", 1, IDirect3DTexture9_GetType},
    {"d3d9.dll", "IDirect3DTexture9::PreLoad", 1, IDirect3DTexture9_PreLoad},
    {"d3d9.dll", "IDirect3DVertexBuffer9::Lock", 5, IDirect3DVertexBuffer9_Lock},
    {"d3d9.dll", "IDirect3DVertexBuffer9::Unlock", 1, IDirect3DVertexBuffer9_Unlock},
    {"d3d9.dll", "IDirect3DVertexBuffer9::GetDesc", 2, IDirect3DVertexBuffer9_GetDesc},
    {"d3d9.dll", "IDirect3DIndexBuffer9::Lock", 5, IDirect3DIndexBuffer9_Lock},
    {"d3d9.dll", "IDirect3DIndexBuffer9::Unlock", 1, IDirect3DIndexBuffer9_Unlock},
    {"d3d9.dll", "IDirect3DIndexBuffer9::GetDesc", 2, IDirect3DIndexBuffer9_GetDesc},
    {"d3d9.dll", "IDirect3DVertexDeclaration9::GetDeclaration", 3, IDirect3DVertexDeclaration9_GetDeclaration},
    {"d3d9.dll", "IDirect3DVertexShader9::GetFunction", 3, IDirect3DVertexShader9_GetFunction},
    {"d3d9.dll", "IDirect3DPixelShader9::GetFunction", 3, IDirect3DPixelShader9_GetFunction},
    UNK_ENTRIES("IDirect3DVertexDeclaration9"), UNK_ENTRIES("IDirect3DVertexShader9"),
    UNK_ENTRIES("IDirect3DPixelShader9"), UNK_ENTRIES("IDirect3DStateBlock9"), UNK_ENTRIES("IDirect3DQuery9"),
};
const int d3d9_api_count = sizeof d3d9_apis / sizeof d3d9_apis[0];
