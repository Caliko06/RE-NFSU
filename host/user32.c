// user32: window classes, windows, the message queue, wsprintf. One desktop of DESK_W x DESK_H.
// Messages that Windows sends synchronously (create, show, activate) call the window procedure here.
#include <ctype.h>
#include <strings.h>
#include "host.h"

#define DESK_W 1920
#define DESK_H 1080
#define WM_CREATE 0x0001
#define WM_MOVE 0x0003
#define WM_SIZE 0x0005
#define WM_ACTIVATE 0x0006
#define WM_SETFOCUS 0x0007
#define WM_SHOWWINDOW 0x0018
#define WM_ACTIVATEAPP 0x001c
#define WM_NCCREATE 0x0081
#define WM_QUIT 0x0012

typedef struct { char name[64]; uint32_t proc, style, extra, instance, atom; } WClass;
static WClass classes[32];
static int nclasses;
typedef struct { uint32_t proc, style, exstyle, x, y, w, h, visible, userdata, id, parent; WClass *cls; } Window;
static Window windows[16];
static int nwindows;
static uint32_t focus, active;

typedef struct { uint32_t hwnd, msg, wp, lp; } Msg;
static Msg queue[256];
static unsigned qhead, qtail;
static int quit_posted;
static uint32_t quit_code;

static uint32_t hwnd_of(int k) { return 0x10010 + 4u * k; }
static Window *win(uint32_t h) {
    uint32_t k = (h - 0x10010) / 4;
    return h >= 0x10010 && !(h & 3) && k < (uint32_t)nwindows ? &windows[k] : NULL;
}
static uint32_t send(Ctx *c, uint32_t h, uint32_t msg, uint32_t wp, uint32_t lp) {
    Window *w = win(h);
    if (!w || c->halt) return 0;
    uint32_t args[4] = {h, msg, wp, lp};
    if (rn_trace()) rn_log("send %04x to %08x", msg, h);
    return call_guest(c, w->proc, 4, args);
}

static WClass *find_class(Ctx *c, uint32_t name) {
    for (int k = 0; k < nclasses; k++)
        if (name < 0x10000 ? classes[k].atom == name : !strcasecmp(classes[k].name, G(name))) return &classes[k];
    return NULL;
}
static uint32_t register_class(Ctx *c, uint32_t style, uint32_t proc, uint32_t extra, uint32_t inst, uint32_t name) {
    if (nclasses == 32) { rn_halt(c, "too many window classes"); return 0; }
    WClass *k = &classes[nclasses];
    snprintf(k->name, sizeof k->name, "%s", name < 0x10000 ? "#atom" : G(name));
    k->proc = proc; k->style = style; k->extra = extra; k->instance = inst;
    k->atom = 0xc000 + nclasses++;
    return k->atom;
}
static uint32_t RegisterClassA_(Ctx *c) {
    uint32_t p = ARG(0);
    return register_class(c, ld(c, p, 4), ld(c, p + 4, 4), ld(c, p + 12, 4), ld(c, p + 16, 4), ld(c, p + 36, 4));
}
static uint32_t RegisterClassExA_(Ctx *c) {
    uint32_t p = ARG(0);
    if (ld(c, p, 4) != 48) { set_error(c, 87); return 0; }
    return register_class(c, ld(c, p + 4, 4), ld(c, p + 8, 4), ld(c, p + 16, 4), ld(c, p + 20, 4), ld(c, p + 40, 4));
}
static uint32_t UnregisterClassA_(Ctx *c) { (void)c; return 1; }
// Icons and cursors are only handed back to RegisterClass/SetCursor: a nonzero handle per resource id.
static uint32_t LoadIconA_(Ctx *c) { return 0x20000 + (ARG(1) & 0xffff); }
static uint32_t LoadCursorA_(Ctx *c) { return 0x30000 + (ARG(1) & 0xffff); }
static uint32_t SetCursor_(Ctx *c) { static uint32_t cur; uint32_t old = cur; cur = ARG(0); (void)c; return old; }
static uint32_t ShowCursor_(Ctx *c) { static int count; count += ARG(0) ? 1 : -1; (void)c; return (uint32_t)count; }
static uint32_t SetCursorPos_(Ctx *c) { (void)c; return 1; }

// Frame sizes of XP classic style: caption 19, sizing border 4, fixed border 3, thin border 1.
static void frame(uint32_t style, uint32_t ex, int *b, int *cap) {
    *b = 0;
    if (style & 0x00040000) *b = 4;                       // WS_THICKFRAME
    else if ((style & 0x00c00000) || (ex & 1)) *b = 3;    // WS_CAPTION / WS_DLGFRAME / WS_EX_DLGMODALFRAME
    else if (style & 0x00800000) *b = 1;                  // WS_BORDER
    *cap = (style & 0x00c00000) == 0x00c00000 ? 19 : 0;
}
static void adjust(Ctx *c, uint32_t r, uint32_t style, uint32_t ex) {
    int b, cap;
    frame(style, ex, &b, &cap);
    st(c, r, ld(c, r, 4) - b, 4); st(c, r + 4, ld(c, r + 4, 4) - b - cap, 4);
    st(c, r + 8, ld(c, r + 8, 4) + b, 4); st(c, r + 12, ld(c, r + 12, 4) + b, 4);
}
static uint32_t AdjustWindowRect_(Ctx *c) { adjust(c, ARG(0), ARG(1), 0); return 1; }
static uint32_t AdjustWindowRectEx_(Ctx *c) { adjust(c, ARG(0), ARG(1), ARG(3)); return 1; }

static uint32_t CreateWindowExA_(Ctx *c) {
    uint32_t ex = ARG(0), cname = ARG(1), title = ARG(2), style = ARG(3);
    int32_t x = ARG(4), y = ARG(5), w = ARG(6), h = ARG(7);
    uint32_t parent = ARG(8), menu = ARG(9), inst = ARG(10), param = ARG(11);
    WClass *k = find_class(c, cname);
    if (!k) { rn_halt(c, "CreateWindowExA: class %s not registered", cname < 0x10000 ? "#atom" : G(cname)); return 0; }
    if (nwindows == 16) { rn_halt(c, "too many windows"); return 0; }
    if (x == (int32_t)0x80000000) { x = 0; y = 0; }
    if (w == (int32_t)0x80000000) { w = DESK_W; h = DESK_H; }
    Window *wd = &windows[nwindows];
    uint32_t hw = hwnd_of(nwindows++);
    *wd = (Window){k->proc, style, ex, (uint32_t)x, (uint32_t)y, (uint32_t)w, (uint32_t)h, 0, 0, menu, parent, k};
    rn_log("CreateWindowExA \"%s\" class \"%s\" %dx%d at %d,%d style %08x ex %08x -> %08x",
           title ? G(title) : "", k->name, w, h, x, y, style, ex, hw);
    // CREATESTRUCTA for WM_NCCREATE / WM_CREATE.
    uint32_t cs = guest_alloc(48);
    uint32_t f[12] = {param, inst, menu, parent, (uint32_t)h, (uint32_t)w, (uint32_t)y, (uint32_t)x, style, title, cname, ex};
    for (int i = 0; i < 12; i++) st(c, cs + 4 * i, f[i], 4);
    if (!send(c, hw, WM_NCCREATE, 0, cs) && !c->halt) { rn_log("WM_NCCREATE refused"); return 0; }
    if ((int32_t)send(c, hw, WM_CREATE, 0, cs) == -1 && !c->halt) { rn_log("WM_CREATE refused"); return 0; }
    if (c->halt) return 0;
    if (style & 0x10000000) {   // WS_VISIBLE
        wd->visible = 1;
        send(c, hw, WM_SHOWWINDOW, 1, 0);
    }
    send(c, hw, WM_SIZE, 0, ((uint32_t)h << 16) | ((uint32_t)w & 0xffff));
    send(c, hw, WM_MOVE, 0, ((uint32_t)y << 16) | ((uint32_t)x & 0xffff));
    return hw;
}
static void activate(Ctx *c, uint32_t h) {
    if (active == h) return;
    active = h;
    send(c, h, WM_ACTIVATEAPP, 1, 0);
    send(c, h, WM_ACTIVATE, 1, 0);
    if (focus != h) { focus = h; send(c, h, WM_SETFOCUS, 0, 0); }
}
static uint32_t ShowWindow_(Ctx *c) {
    uint32_t h = ARG(0), cmd = ARG(1);
    Window *w = win(h);
    if (!w) return 0;
    uint32_t was = w->visible;
    if (cmd == 0) { w->visible = 0; if (was) send(c, h, WM_SHOWWINDOW, 0, 0); return was; }
    w->visible = 1;
    if (!was) send(c, h, WM_SHOWWINDOW, 1, 0);
    if (cmd != 4 && cmd != 8 && cmd != 7) activate(c, h);    // SW_SHOWNOACTIVATE, SW_SHOWNA, SW_SHOWMINNOACTIVE
    return was;
}
static uint32_t UpdateWindow_(Ctx *c) { return win(ARG(0)) != NULL; }
static uint32_t SetFocus_(Ctx *c) {
    uint32_t h = ARG(0), old = focus;
    if (h && h != focus) { focus = h; send(c, h, WM_SETFOCUS, old, 0); }
    return old;
}
static uint32_t SetForegroundWindow_(Ctx *c) { activate(c, ARG(0)); return 1; }
static uint32_t SetActiveWindow_(Ctx *c) { uint32_t old = active; activate(c, ARG(0)); return old; }
static uint32_t GetForegroundWindow_(Ctx *c) { (void)c; return active; }
static uint32_t GetDesktopWindow_(Ctx *c) { (void)c; return 0x10004; }
static uint32_t GetClientRect_(Ctx *c) {
    uint32_t h = ARG(0), r = ARG(1);
    Window *w = win(h);
    uint32_t cw = DESK_W, ch = DESK_H;
    if (w) {     // client = window minus the frame AdjustWindowRect adds
        int b, cap;
        frame(w->style, w->exstyle, &b, &cap);
        cw = w->w - 2 * b;
        ch = w->h - 2 * b - cap;
    } else if (h != 0x10004) { set_error(c, 1400); return 0; }
    st(c, r, 0, 4); st(c, r + 4, 0, 4); st(c, r + 8, cw, 4); st(c, r + 12, ch, 4);
    return 1;
}
static uint32_t GetWindowRect_(Ctx *c) {
    uint32_t h = ARG(0), r = ARG(1);
    Window *w = win(h);
    if (!w && h != 0x10004) { set_error(c, 1400); return 0; }
    uint32_t x = w ? w->x : 0, y = w ? w->y : 0, ww = w ? w->w : DESK_W, hh = w ? w->h : DESK_H;
    st(c, r, x, 4); st(c, r + 4, y, 4); st(c, r + 8, x + ww, 4); st(c, r + 12, y + hh, 4);
    return 1;
}
static uint32_t SetWindowPos_(Ctx *c) {
    Window *w = win(ARG(0));
    uint32_t flags = ARG(6);
    if (!w) return 0;
    if (!(flags & 2)) { w->x = ARG(2); w->y = ARG(3); }       // SWP_NOMOVE
    if (!(flags & 1)) { w->w = ARG(4); w->h = ARG(5); }       // SWP_NOSIZE
    return 1;
}
static uint32_t SetRect_(Ctx *c) { uint32_t r = ARG(0); for (int k = 0; k < 4; k++) st(c, r + 4 * k, ARG(1 + k), 4); return 1; }
static uint32_t SetWindowLongA_(Ctx *c) {
    Window *w = win(ARG(0));
    int32_t idx = ARG(1);
    uint32_t v = ARG(2), old;
    if (!w) return 0;
    switch (idx) {
    case -4: old = w->proc; w->proc = v; return old;          // GWL_WNDPROC
    case -16: old = w->style; w->style = v; return old;
    case -20: old = w->exstyle; w->exstyle = v; return old;
    case -21: old = w->userdata; w->userdata = v; return old;
    }
    rn_halt(c, "SetWindowLongA index %d", idx);
    return 0;
}
static uint32_t GetWindowLongA_(Ctx *c) {
    Window *w = win(ARG(0));
    int32_t idx = ARG(1);
    if (!w) return 0;
    switch (idx) {
    case -4: return w->proc;
    case -16: return w->style;
    case -20: return w->exstyle;
    case -21: return w->userdata;
    }
    rn_halt(c, "GetWindowLongA index %d", idx);
    return 0;
}
// Painting with nothing drawn by GDI: the paint DC is a handle only, the whole client area is
// the update region. (W3 stand-in so the game gets past WM_PAINT; W2 owns painting.)
static uint32_t BeginPaint_(Ctx *c) {
    uint32_t h = ARG(0), ps = ARG(1);
    Window *w = win(h);
    if (!w) return 0;
    int b, cap;
    frame(w->style, w->exstyle, &b, &cap);
    memset(G(ps), 0, 64);
    st(c, ps, 0x40010000u + (h & 0xffff), 4);              // hdc
    st(c, ps + 16, w->w - 2 * b, 4);                       // rcPaint = client rect
    st(c, ps + 20, w->h - 2 * b - cap, 4);
    return 0x40010000u + (h & 0xffff);
}
static uint32_t EndPaint_(Ctx *c) { (void)c; return 1; }
static uint32_t IsIconic_(Ctx *c) { (void)c; return 0; }
static uint32_t ClientToScreen_(Ctx *c) { (void)c; return 1; }
static uint32_t DestroyWindow_(Ctx *c) { Window *w = win(ARG(0)); if (w) w->visible = 0; return w != NULL; }

// WM_CLOSE goes to DestroyWindow; everything else needs no default action in this layer yet.
static uint32_t DefWindowProcA_(Ctx *c) {
    uint32_t msg = ARG(1);
    if (msg == WM_NCCREATE) return 1;
    if (msg == 0x0010) { DestroyWindow_(c); return 0; }
    return 0;
}

static void post(uint32_t h, uint32_t msg, uint32_t wp, uint32_t lp) {
    if (qtail - qhead < 256) queue[qtail++ % 256] = (Msg){h, msg, wp, lp};
}
static void fill_msg(Ctx *c, uint32_t p, Msg m) {
    st(c, p, m.hwnd, 4); st(c, p + 4, m.msg, 4); st(c, p + 8, m.wp, 4); st(c, p + 12, m.lp, 4);
    st(c, p + 16, (uint32_t)(now_us() / 1000), 4); st(c, p + 20, 0, 4); st(c, p + 24, 0, 4);
}
static uint32_t PeekMessageA_(Ctx *c) {
    uint32_t p = ARG(0), remove = ARG(4) & 1;
    if (qhead != qtail) {
        fill_msg(c, p, queue[qhead % 256]);
        if (remove) qhead++;
        return 1;
    }
    if (quit_posted) {
        fill_msg(c, p, (Msg){0, WM_QUIT, quit_code, 0});
        if (remove) quit_posted = 0;
        return 1;
    }
    return 0;
}
static uint32_t GetMessageA_(Ctx *c) {
    uint32_t p = ARG(0);
    if (qhead != qtail) { fill_msg(c, p, queue[qhead++ % 256]); return 1; }
    if (quit_posted) { fill_msg(c, p, (Msg){0, WM_QUIT, quit_code, 0}); return 0; }
    rn_halt(c, "GetMessageA would wait for input");
    return 0;
}
static uint32_t PostMessageA_(Ctx *c) { post(ARG(0), ARG(1), ARG(2), ARG(3)); return 1; }
static uint32_t PostQuitMessage_(Ctx *c) { quit_posted = 1; quit_code = ARG(0); return 0; }
static uint32_t TranslateMessage_(Ctx *c) { (void)c; return 0; }
static uint32_t DispatchMessageA_(Ctx *c) {
    uint32_t p = ARG(0);
    return send(c, ld(c, p, 4), ld(c, p + 4, 4), ld(c, p + 8, 4), ld(c, p + 12, 4));
}

static uint32_t GetSystemMetrics_(Ctx *c) {
    switch (ARG(0)) {
    case 0: case 16: return DESK_W;     // SM_CXSCREEN, SM_CXFULLSCREEN
    case 1: return DESK_H;
    case 17: return DESK_H - 19;
    case 4: return 19;                  // SM_CYCAPTION
    case 5: case 6: return 1;           // SM_CXBORDER
    case 7: case 8: return 3;           // SM_CXDLGFRAME
    case 32: case 33: return 4;         // SM_CXFRAME
    case 43: return 3;                  // SM_CMOUSEBUTTONS
    }
    rn_halt(c, "GetSystemMetrics(%u)", ARG(0));
    return 0;
}
static uint32_t CharUpperA_(Ctx *c) {
    uint32_t p = ARG(0);
    if (p < 0x10000) return (uint32_t)toupper((int)p);
    for (char *s = G(p); *s; s++) if (*s >= 'a' && *s <= 'z') *s -= 32;
    return p;
}
static uint32_t GetAsyncKeyState_(Ctx *c) { (void)c; return 0; }
static uint32_t GetKeyState_(Ctx *c) { (void)c; return 0; }

// wsprintf: %[-][#][0][width][.prec][l|h]{c,d,i,s,u,x,X,%}; arguments are guest dwords.
static uint32_t format(Ctx *c, uint32_t out, uint32_t fmt, uint32_t ap) {
    char buf[1025];
    size_t n = 0;
    for (const char *f = G(fmt); *f && n < 1024; f++) {
        if (*f != '%') { buf[n++] = *f; continue; }
        char spec[32] = "%";
        size_t sl = 1;
        f++;
        while (*f && strchr("-#0", *f) && sl < 8) spec[sl++] = *f++;
        while (*f >= '0' && *f <= '9' && sl < 16) spec[sl++] = *f++;
        if (*f == '.') { spec[sl++] = *f++; while (*f >= '0' && *f <= '9' && sl < 24) spec[sl++] = *f++; }
        if (*f == 'l' || *f == 'h') f++;
        char conv = *f, tmp[1025];
        if (!conv) break;
        spec[sl++] = conv == 'i' ? 'd' : conv; spec[sl] = 0;
        if (conv == '%') { buf[n++] = '%'; continue; }
        uint32_t v = ld(c, ap, 4);
        ap += 4;
        if (conv == 's') snprintf(tmp, sizeof tmp, spec, v ? G(v) : "(null)");
        else if (conv == 'c') snprintf(tmp, sizeof tmp, spec, (int)(v & 0xff));
        else if (strchr("diuxX", conv)) snprintf(tmp, sizeof tmp, spec, conv == 'd' || conv == 'i' ? (int)v : v);
        else { rn_halt(c, "wsprintf conversion %%%c", conv); return 0; }
        for (char *t = tmp; *t && n < 1024; t++) buf[n++] = *t;
    }
    buf[n] = 0;
    memcpy(G(out), buf, n + 1);
    return (uint32_t)n;
}
static uint32_t wvsprintfA_(Ctx *c) { return format(c, ARG(0), ARG(1), ARG(2)); }
static uint32_t wsprintfA_(Ctx *c) { return format(c, ARG(0), ARG(1), c->r[ESP] + 12); }

#define U(name, n) {"user32.dll", #name, n, name##_}
const Api user32_apis[] = {
    U(RegisterClassA, 1), U(RegisterClassExA, 1), U(UnregisterClassA, 2), U(LoadIconA, 2), U(LoadCursorA, 2),
    U(SetCursor, 1), U(ShowCursor, 1), U(SetCursorPos, 2), U(AdjustWindowRect, 3), U(AdjustWindowRectEx, 4),
    U(CreateWindowExA, 12), U(ShowWindow, 2), U(UpdateWindow, 1), U(SetFocus, 1), U(SetForegroundWindow, 1),
    U(SetActiveWindow, 1), U(GetForegroundWindow, 0), U(GetDesktopWindow, 0), U(GetClientRect, 2),
    U(GetWindowRect, 2), U(SetWindowPos, 7), U(SetRect, 5), U(SetWindowLongA, 3), U(GetWindowLongA, 2),
    U(BeginPaint, 2), U(EndPaint, 2), U(IsIconic, 1), U(ClientToScreen, 2), U(DestroyWindow, 1), U(DefWindowProcA, 4), U(PeekMessageA, 5),
    U(GetMessageA, 4), U(PostMessageA, 4), U(PostQuitMessage, 1), U(TranslateMessage, 1), U(DispatchMessageA, 1),
    U(GetSystemMetrics, 1), U(CharUpperA, 1), U(GetAsyncKeyState, 1), U(GetKeyState, 1),
    U(wvsprintfA, 3), {"user32.dll", "wsprintfA", -1, wsprintfA_},
};
const int user32_api_count = sizeof user32_apis / sizeof user32_apis[0];
