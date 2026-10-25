// The keyboard and mouse of this PC. One source feeds them: the browser (web/input.js writes key and
// mouse events into a ring in the shared heap) and, for test runs (native, or web with ?keys=), a script in RN_KEYS:
// RN_KEYS="3000:RETURN,4500:DOWN" taps each key (100 ms down) at that many ms after start. "3000@6/8:DOWN" taps it
// 3000 ms after the game-flow state 6 / race state 8 (RN_FLOWLOG, host/d3d9.c) is first seen once the taps before it are done;
// "3000@3:RETURN" waits for flow state 3 with any race state. "1500@=PostRaceMenu:DOWN" waits for that post-race screen
// (rn_screen, or a front-end package in rn_fe); "4000@!PostRaceMenu:RETURN" counts from the tap before and is dropped if that screen shows when it is due.
// input_poll() hands new events to the key state, the DirectInput devices and the window messages.
#include <strings.h>
#include <unistd.h>
#include "host.h"

// DirectInput key codes (scan codes; 0x80 = the 0xE0-prefixed extended keys), US layout.
typedef struct { uint8_t dik, vk; char ch, shift_ch; const char *name; } Key;
static const Key keys[] = {
    {0x01, 0x1b, 27, 27, "ESCAPE"}, {0x02, '1', '1', '!', "1"}, {0x03, '2', '2', '@', "2"}, {0x04, '3', '3', '#', "3"},
    {0x05, '4', '4', '$', "4"}, {0x06, '5', '5', '%', "5"}, {0x07, '6', '6', '^', "6"}, {0x08, '7', '7', '&', "7"},
    {0x09, '8', '8', '*', "8"}, {0x0a, '9', '9', '(', "9"}, {0x0b, '0', '0', ')', "0"}, {0x0c, 0xbd, '-', '_', "MINUS"},
    {0x0d, 0xbb, '=', '+', "EQUALS"}, {0x0e, 0x08, 8, 8, "BACK"}, {0x0f, 0x09, 9, 9, "TAB"},
    {0x10, 'Q', 'q', 'Q', "Q"}, {0x11, 'W', 'w', 'W', "W"}, {0x12, 'E', 'e', 'E', "E"}, {0x13, 'R', 'r', 'R', "R"},
    {0x14, 'T', 't', 'T', "T"}, {0x15, 'Y', 'y', 'Y', "Y"}, {0x16, 'U', 'u', 'U', "U"}, {0x17, 'I', 'i', 'I', "I"},
    {0x18, 'O', 'o', 'O', "O"}, {0x19, 'P', 'p', 'P', "P"}, {0x1a, 0xdb, '[', '{', "LBRACKET"}, {0x1b, 0xdd, ']', '}', "RBRACKET"},
    {0x1c, 0x0d, 13, 13, "RETURN"}, {0x1d, 0x11, 0, 0, "LCONTROL"},
    {0x1e, 'A', 'a', 'A', "A"}, {0x1f, 'S', 's', 'S', "S"}, {0x20, 'D', 'd', 'D', "D"}, {0x21, 'F', 'f', 'F', "F"},
    {0x22, 'G', 'g', 'G', "G"}, {0x23, 'H', 'h', 'H', "H"}, {0x24, 'J', 'j', 'J', "J"}, {0x25, 'K', 'k', 'K', "K"},
    {0x26, 'L', 'l', 'L', "L"}, {0x27, 0xba, ';', ':', "SEMICOLON"}, {0x28, 0xde, '\'', '"', "APOSTROPHE"},
    {0x29, 0xc0, '`', '~', "GRAVE"}, {0x2a, 0x10, 0, 0, "LSHIFT"}, {0x2b, 0xdc, '\\', '|', "BACKSLASH"},
    {0x2c, 'Z', 'z', 'Z', "Z"}, {0x2d, 'X', 'x', 'X', "X"}, {0x2e, 'C', 'c', 'C', "C"}, {0x2f, 'V', 'v', 'V', "V"},
    {0x30, 'B', 'b', 'B', "B"}, {0x31, 'N', 'n', 'N', "N"}, {0x32, 'M', 'm', 'M', "M"}, {0x33, 0xbc, ',', '<', "COMMA"},
    {0x34, 0xbe, '.', '>', "PERIOD"}, {0x35, 0xbf, '/', '?', "SLASH"}, {0x36, 0x10, 0, 0, "RSHIFT"},
    {0x37, 0x6a, '*', '*', "MULTIPLY"}, {0x38, 0x12, 0, 0, "LMENU"}, {0x39, 0x20, ' ', ' ', "SPACE"},
    {0x3a, 0x14, 0, 0, "CAPITAL"}, {0x3b, 0x70, 0, 0, "F1"}, {0x3c, 0x71, 0, 0, "F2"}, {0x3d, 0x72, 0, 0, "F3"},
    {0x3e, 0x73, 0, 0, "F4"}, {0x3f, 0x74, 0, 0, "F5"}, {0x40, 0x75, 0, 0, "F6"}, {0x41, 0x76, 0, 0, "F7"},
    {0x42, 0x77, 0, 0, "F8"}, {0x43, 0x78, 0, 0, "F9"}, {0x44, 0x79, 0, 0, "F10"}, {0x45, 0x90, 0, 0, "NUMLOCK"},
    {0x46, 0x91, 0, 0, "SCROLL"}, {0x47, 0x67, 0, 0, "NUMPAD7"}, {0x48, 0x68, 0, 0, "NUMPAD8"}, {0x49, 0x69, 0, 0, "NUMPAD9"},
    {0x4a, 0x6d, '-', '-', "SUBTRACT"}, {0x4b, 0x64, 0, 0, "NUMPAD4"}, {0x4c, 0x65, 0, 0, "NUMPAD5"},
    {0x4d, 0x66, 0, 0, "NUMPAD6"}, {0x4e, 0x6b, '+', '+', "ADD"}, {0x4f, 0x61, 0, 0, "NUMPAD1"}, {0x50, 0x62, 0, 0, "NUMPAD2"},
    {0x51, 0x63, 0, 0, "NUMPAD3"}, {0x52, 0x60, 0, 0, "NUMPAD0"}, {0x53, 0x6e, 0, 0, "DECIMAL"},
    {0x57, 0x7a, 0, 0, "F11"}, {0x58, 0x7b, 0, 0, "F12"},
    {0x9c, 0x0d, 13, 13, "NUMPADENTER"}, {0x9d, 0x11, 0, 0, "RCONTROL"}, {0xb5, 0x6f, '/', '/', "DIVIDE"},
    {0xb7, 0x2c, 0, 0, "SYSRQ"}, {0xb8, 0x12, 0, 0, "RMENU"}, {0xc5, 0x13, 0, 0, "PAUSE"}, {0xc7, 0x24, 0, 0, "HOME"},
    {0xc8, 0x26, 0, 0, "UP"}, {0xc9, 0x21, 0, 0, "PRIOR"}, {0xcb, 0x25, 0, 0, "LEFT"}, {0xcd, 0x27, 0, 0, "RIGHT"},
    {0xcf, 0x23, 0, 0, "END"}, {0xd0, 0x28, 0, 0, "DOWN"}, {0xd1, 0x22, 0, 0, "NEXT"}, {0xd2, 0x2d, 0, 0, "INSERT"},
    {0xd3, 0x2e, 0, 0, "DELETE"}, {0xdb, 0x5b, 0, 0, "LWIN"}, {0xdc, 0x5c, 0, 0, "RWIN"}, {0xdd, 0x5d, 0, 0, "APPS"},
};
#define NKEYS (int)(sizeof keys / sizeof keys[0])
static const Key *key_of(uint8_t dik) {
    for (int k = 0; k < NKEYS; k++) if (keys[k].dik == dik) return &keys[k];
    return NULL;
}

// The key's name as GetKeyNameText gives it for the US layout: the aKeyNames / aKeyNamesExt tables of
// kbdus.c (Windows-driver-samples, input/layout/kbdus), else the key's unshifted character, letters in capitals.
typedef struct { uint8_t sc; const char *name; } Name;
static const Name names[] = {
    {0x01, "Esc"}, {0x0e, "Backspace"}, {0x0f, "Tab"}, {0x1c, "Enter"}, {0x1d, "Ctrl"}, {0x2a, "Shift"},
    {0x36, "Right Shift"}, {0x37, "Num *"}, {0x38, "Alt"}, {0x39, "Space"}, {0x3a, "Caps Lock"}, {0x3b, "F1"},
    {0x3c, "F2"}, {0x3d, "F3"}, {0x3e, "F4"}, {0x3f, "F5"}, {0x40, "F6"}, {0x41, "F7"}, {0x42, "F8"}, {0x43, "F9"},
    {0x44, "F10"}, {0x45, "Pause"}, {0x46, "Scroll Lock"}, {0x47, "Num 7"}, {0x48, "Num 8"}, {0x49, "Num 9"},
    {0x4a, "Num -"}, {0x4b, "Num 4"}, {0x4c, "Num 5"}, {0x4d, "Num 6"}, {0x4e, "Num +"}, {0x4f, "Num 1"},
    {0x50, "Num 2"}, {0x51, "Num 3"}, {0x52, "Num 0"}, {0x53, "Num Del"}, {0x54, "Sys Req"}, {0x57, "F11"},
    {0x58, "F12"},
}, names_ext[] = {
    {0x1c, "Num Enter"}, {0x1d, "Right Ctrl"}, {0x35, "Num /"}, {0x37, "Prnt Scrn"}, {0x38, "Right Alt"},
    {0x45, "Num Lock"}, {0x46, "Break"}, {0x47, "Home"}, {0x48, "Up"}, {0x49, "Page Up"}, {0x4b, "Left"},
    {0x4d, "Right"}, {0x4f, "End"}, {0x50, "Down"}, {0x51, "Page Down"}, {0x52, "Insert"}, {0x53, "Delete"},
    {0x56, "Help"}, {0x5b, "Left Windows"}, {0x5c, "Right Windows"}, {0x5d, "Application"},
};

static uint8_t down[256];      // by DIK
static uint8_t vk_down[256], vk_toggle[256];

// VK state for GetAsyncKeyState/GetKeyState: the generic VK and the left/right ones.
static void set_vk(uint8_t vk, int d) {
    if (d && !vk_down[vk]) vk_toggle[vk] ^= 1;
    vk_down[vk] = (uint8_t)d;
}
uint32_t input_vk_state(uint32_t vk) {
    input_poll();
    if (vk > 255) return 0;
    return (vk_down[vk] ? 0x8000u : 0) | vk_toggle[vk];
}
int input_shift(void) { return vk_down[0x10]; }
int input_caps(void) { return vk_toggle[0x14]; }
int input_alt(void) { return vk_down[0x12]; }
int input_key_down(uint8_t dik) { return down[dik]; }
uint8_t input_vk_of(uint8_t dik) { const Key *k = key_of(dik); return k ? k->vk : 0; }
char input_char_of(uint8_t vk, int shift) {
    for (int k = 0; k < NKEYS; k++)
        if (keys[k].vk == vk && keys[k].ch) {
            char ch = shift ? keys[k].shift_ch : keys[k].ch;
            if (vk >= 'A' && vk <= 'Z' && input_caps()) ch ^= 0x20;
            return ch;
        }
    return 0;
}

// The kbd tables put Pause at 0x45 and Num Lock at E0 45; the DIK codes are the other way round
// (DIK_NUMLOCK 0x45, DIK_PAUSE 0xC5), so those two swap tables.
void input_key_name(uint8_t dik, char *out, int n) {
    int ext = (dik & 0x80) != 0;
    if ((dik & 0x7f) == 0x45) ext = !ext;
    const Name *t = ext ? names_ext : names;
    int nt = ext ? (int)(sizeof names_ext / sizeof *names_ext) : (int)(sizeof names / sizeof *names);
    for (int k = 0; k < nt; k++)
        if (t[k].sc == (dik & 0x7f)) { snprintf(out, n, "%s", t[k].name); return; }
    const Key *k = key_of(dik);
    char ch = k && k->ch > ' ' ? (k->vk >= 'A' && k->vk <= 'Z' ? k->shift_ch : k->ch) : 0;
    snprintf(out, n, "%.*s", ch ? 1 : 0, &ch);
}

static void key_event(uint8_t dik, int d) {
    if (down[dik] == d) return;
    const Key *k = key_of(dik);
    down[dik] = (uint8_t)d;
    if (k) {
        set_vk(k->vk, d);
        static const uint8_t side[][2] = {{0x2a, 0xa0}, {0x36, 0xa1}, {0x1d, 0xa2}, {0x9d, 0xa3}, {0x38, 0xa4}, {0xb8, 0xa5}};
        for (int s = 0; s < 6; s++) if (side[s][0] == dik) set_vk(side[s][1], d);
        if (k->vk == 0x10 || k->vk == 0x11 || k->vk == 0x12)      // the generic VK is down while either side is
            vk_down[k->vk] = (uint8_t)(vk_down[k->vk == 0x10 ? 0xa0 : k->vk == 0x11 ? 0xa2 : 0xa4] |
                                       vk_down[k->vk == 0x10 ? 0xa1 : k->vk == 0x11 ? 0xa3 : 0xa5]);
    }
    if (rn_trace()) rn_log("input: key %02x %s %s", dik, k ? k->name : "?", d ? "down" : "up");
    dinput8_key(dik, d);
    user32_key(dik, k ? k->vk : 0, d);
}
static void button_event(int b, int d) {
    if (b < 0 || b > 7) return;
    static const uint8_t vk[] = {0x01, 0x02, 0x04, 0x05, 0x06, 0, 0, 0};    // VK_LBUTTON, RBUTTON, MBUTTON, X1, X2
    if (vk[b]) set_vk(vk[b], d);
    dinput8_button(b, d);
}

typedef struct { uint64_t at_us; uint8_t dik; uint32_t cond, mask; char op, scr[48]; } Tap;   // cond: flow state to wait for, ~0 = none
static Tap taps[256];
static int ntaps, script_read;
static unsigned next_tap;
static void read_script(void) {
    script_read = 1;
    const char *s = getenv("RN_KEYS");
    while (s && *s && ntaps < 256) {
        char name[32];
        unsigned ms, fs, rs;
        uint32_t cond = ~0u, mask = ~0u;
        char op[2] = "", scr[48] = "";
        int used;
        if (sscanf(s, "%u@%1[=!]%47[A-Za-z0-9_]:%31[A-Z0-9_]%n", &ms, op, scr, name, &used) == 4) ;
        else if (op[0] = 0, sscanf(s, "%u@%u/%u:%31[A-Z0-9_]%n", &ms, &fs, &rs, name, &used) == 4) cond = fs << 8 | (rs & 0xff);
        else if (sscanf(s, "%u@%u:%31[A-Z0-9_]%n", &ms, &fs, name, &used) == 3) cond = fs << 8, mask = ~0xffu;
        else if (sscanf(s, "%u:%31[A-Z0-9_]%n", &ms, name, &used) != 2) { rn_log("RN_KEYS: cannot read \"%s\"", s); break; }
        const Key *k = NULL;
        for (int j = 0; j < NKEYS && !k; j++) if (!strcasecmp(keys[j].name, name)) k = &keys[j];
        if (!k) { rn_log("RN_KEYS: no key %s", name); break; }
        taps[ntaps] = (Tap){(uint64_t)ms * 1000, k->dik, cond, mask, op[0], ""};
        memcpy(taps[ntaps++].scr, scr, sizeof scr);
        s += used;
        while (*s == ',' || *s == ' ') s++;
    }
}
static int screen_on(const char *scr) {   // the post-race screen, or one of the front end's active packages
    size_t n = strlen(scr);
    if (!strncasecmp(rn_screen, scr, n) && rn_screen[n] == '.') return 1;
    for (const char *f = rn_fe; *f; f++)
        if ((f == rn_fe || f[-1] == ',') && !strncasecmp(f, scr, n) && f[n] == '.') return 1;
    return 0;
}
// Each tap is a down event at its time and an up event 100 ms later, in time order. The up waits two more frames
// (Presents): a slow frame (a rasterized RN_RASTER frame takes ~1 s) would else see both edges and no key down.
// The game finds a press as an edge between two input frames (0x405980 keeps the last mask at 0x7187b8; 0x4070a0 applies
// the GetDeviceData events), so a tap must not outrun the game's reads (runs/e1_down6 2026-10-25: during a 3 s load the
// next down came before the up was read, both in one read, no edge, the tap lost). So, up to 10 s each: the up also
// waits for an acquired keyboard (an up while the game swaps action maps reaches no device and the key stays down in
// its mask, runs/dilog2: ESC), and the next down waits until the game has read every event, plus two frames.
static void script_poll(void) {
    static uint32_t down_at, read_at;
    static uint64_t wait_from;
    if (!script_read) read_script();
    uint64_t now = now_us();
    while (next_tap < 2u * (unsigned)ntaps) {
        unsigned k = next_tap / 2;
        if (!(next_tap & 1) && taps[k].cond != ~0u) {   // anchor a flow-state tap when its state shows up
            if ((rn_flow & taps[k].mask) != taps[k].cond) break;
            taps[k].at_us += now, taps[k].cond = ~0u;
        }
        if (!(next_tap & 1) && (taps[k].op == '=' || taps[k].op == '!')) {   // a screen tap: "=" anchors when it shows, "!" from the tap before
            int on = screen_on(taps[k].scr);
            if (taps[k].op == '=' && !on) break;
            taps[k].at_us += now, taps[k].op = taps[k].op == '!' ? '?' : 0;
        }
        if (!(next_tap & 1) && taps[k].op == '?') {   // due: dropped if the screen came up meanwhile
            if (taps[k].at_us > now) break;
            taps[k].op = 0;
            if (screen_on(taps[k].scr)) { rn_log("RN_KEYS: tap %u dropped on %s", k, rn_screen); next_tap += 2; continue; }
        }
        uint64_t at = taps[k].at_us + (next_tap & 1 ? 100000 : 0);
        if (at > now || ((next_tap & 1) && rn_telem.presents - down_at < 2)) break;
        int pend = dinput8_key_pending();
        if (pend > 0) read_at = rn_telem.presents;
        int hold = (next_tap & 1) ? pend < 0 : pend > 0 || rn_telem.presents - read_at < 2;
        if (hold) { if (!wait_from) wait_from = now; if (now - wait_from < 10000000) break; }
        wait_from = 0;
        if (!(next_tap & 1)) down_at = rn_telem.presents;
        key_event(taps[k].dik, !(next_tap & 1));
        if (!(next_tap & 1)) rn_log("RN_KEYS: tap %u dik 0x%02x at frame %u flow %u/%u on %s", k, taps[k].dik, rn_telem.presents, rn_flow >> 8, rn_flow & 0xff, rn_screen);
        next_tap++;
    }
}
// RN_JUMP="6:1304,6:1305" (or "+" between, for the web ?env=): test-only, start each Quick Race (mode:track) the way the game's Accept does, without the car,
// track and options screens. Mode = [0x777cc8] (0 circuit, 1 sprint, 2 lap KO, 3 free run, 5 drag, 6 drift; rows.py QR).
// Hopper build/hopper/jump.txt: the setup 0x4b49e0..0x4b59b0 reads the mode's record from 0x4ab510(ecx = 0x748f70,
// edx = [0x777cc8]) = 0x748f70 + {0xfa10, 0xfa30, 0xfa50, 0xfa70, 0xfa94, 0xfb18, 0xfb44}[mode], track at +8 (0x4b4a37
// esi = eax[2] -> [0x78a2f0]). Accept 0x4b5c00 (called by the options screens 0x4b8050, 0x4bb2b0, 0x4bd710) runs that
// setup and only queues UnloadingFrontEnd 0x448d10 in [0x77a904]; the main loop 0x447600 runs it (0x4476c5,
// build/hopper/fsm.txt). So a jump fires on MU_QuickRaceModeSelect (gametype and players already set by the menu), the
// next one each time a race comes back to it. Needs RN_FLOWLOG (rn_fe).
void input_jump(Ctx *c) {
    static const uint32_t rec[7] = {0xfa10, 0xfa30, 0xfa50, 0xfa70, 0xfa94, 0xfb18, 0xfb44};
    static const char *s;
    static uint32_t seen;
    if (!s) { s = getenv("RN_JUMP"); if (!s) { s = ""; return; } }
    unsigned m, t;
    int used;
    static int fired;
    // "e<N>": career row N (record N of the event table, FrontB.lzc 0x34A02, 0x14c each), from the career map
    int car = *s ? *s == 'e' : fired == 2;
    const char *home = car ? "MU_UG_MapScreen" : "MU_QuickRaceModeSelect";
    if (!*s && !fired) return;
    // The list done: any front end ends the run (a career race comes back on the hub or another screen, 0x4ab670)
    if ((rn_flow >> 8) != 3 || (*s && !screen_on(home))) { seen = 0; return; }
    if (!seen) seen = rn_telem.presents;
    if (rn_telem.presents - seen < 30) return;   // let the screen settle as a player would
    extern uint32_t rn_next_left;
#ifndef __EMSCRIPTEN__
    if (!*s && !rn_next_left) { rn_log("RN_JUMP: done, back in the front end at frame %u", rn_telem.presents); fflush(NULL); _exit(0); }
#endif
    if (rn_next_left) return;   // the tournament's next stage starts from here
    if (car) {
        // The map's own path (0x4c5df0): esi = career 0x75eef8, edi = event id, ebx = its record ([0x733ff8 + 4*id],
        // filled by 0x5a0060); 0x5a0ce0 makes the race record [0x7677a8] (= career +0x88b0), 0x4dfa10(eax = record),
        // then 0x4b5df0 (ebx = [0x7677a8]) sets the race up and queues UnloadingFrontEnd 0x448d10 (Hopper evbrief.txt).
        // The briefing (record +0xac) is skipped, as the map does for events 7, 15 and 92.
        unsigned n;
        if (sscanf(s, "e%u%n", &n, &used) != 1) { rn_log("RN_JUMP: cannot read \"%s\"", s); s = ""; return; }
        s += used;
        while (*s == ',' || *s == ' ' || *s == '+') s++;
        uint32_t lo = ~0u, rec, id;
        for (uint32_t k = 0; k < 0x100; k++) { uint32_t r = ld(c, 0x733ff8 + 4 * k, 4); if (r && r < lo) lo = r; }
        rec = lo + n * 0x14c, id = ld(c, rec, 4);
        if (lo == ~0u || id >= 0x100 || ld(c, 0x733ff8 + 4 * id, 4) != rec) { rn_log("RN_JUMP: no career event %u", n); s = ""; return; }
        rn_log("RN_JUMP: career event %u (id %u, record %08x) at frame %u", n, id, rec, rn_telem.presents);
        uint32_t r[8];
        memcpy(r, c->r, sizeof r);
        c->r[ESI] = 0x75eef8, c->r[EDI] = id, c->r[EBX] = rec;
        call_guest(c, 0x5a0ce0, 0, NULL);
        c->r[EAX] = rec;
        call_guest(c, 0x4dfa10, 0, NULL);
        c->r[EBX] = ld(c, 0x7677a8, 4);
        call_guest(c, 0x4b5df0, 0, NULL);
        memcpy(c->r, r, sizeof r);
        seen = 0, fired = 2;
        return;
    }
    if (sscanf(s, "%u:%u%n", &m, &t, &used) != 2 || m > 6) { rn_log("RN_JUMP: cannot read \"%s\"", s); s = ""; return; }
    s += used;
    while (*s == ',' || *s == ' ' || *s == '+') s++;
    st(c, 0x777cc8, m, 4);
    st(c, 0x748f70 + rec[m] + 8, t, 4);
    rn_log("RN_JUMP: mode %u track %u at frame %u", m, t, rn_telem.presents);
    call_guest(c, 0x4b5c00, 0, NULL);
    seen = 0, fired = 1;
}
// RN_FINISH=<place>: test-only, finish each race at that place a second after [[0x73619c]] reaches 4, the way
// the debug race menu's Force Race Finish does (Hopper dbgfin.txt; 0x4c09b0 accept at 0x4c0a52): eax = 0, edx = place,
// stdcall 0x572a90([0x7345d0], player) -> 0x494b90 message 0 sets [[0x73619c]+0x534] = place, +0x538 = player.
void input_finish(Ctx *c) {
    static const char *s;
    static uint32_t seen, done;
    if (!s) { s = getenv("RN_FINISH"); if (!s) s = ""; }
    if (!*s) return;
    if (rn_flow >> 8 != 6) { seen = done = 0; return; }
    // The menu offers it only while [[0x73619c]] == 4 (0x4c09c0); runs/cjump_3 fired at 3 and the race went on.
    uint32_t rs = ld(c, 0x73619c, 4), v = rs ? ld(c, rs, 4) : ~0u;
    static uint32_t last = ~1u;
    if (v != last) rn_log("RN_FINISH: [[0x73619c]] = %d at frame %u", (int)v, rn_telem.presents), last = v;
    if (v != 4) { seen = done = 0; return; }   // each tournament stage comes back through 0, 2, 3
    if (done) return;
    if (!seen) seen = rn_telem.presents;
    if (rn_telem.presents - seen < 60) return;
    uint32_t r[8];
    memcpy(r, c->r, sizeof r);
    // Player 0 = the first local player [0x7361b4] (0x4cd610's 0). 0x4cd610 itself reads who paused ([[0x7361f0]+0x1c]):
    // unpaused it gave 1 and no racer matched. The race update 0x435570 (esi = [0x73619c]) finds the racer whose
    // [[r]+0x18]+0x10 == +0x538 and calls 0x4350d0(place, 0, 1).
    uint32_t player = 0, a[2] = {ld(c, 0x7345d0, 4), player};
    c->r[EAX] = 0, c->r[EDX] = (uint32_t)atoi(s);
    call_guest(c, 0x572a90, 2, a);
    memcpy(c->r, r, sizeof r);
    rn_log("RN_FINISH: place %s player %u at frame %u", s, player, rn_telem.presents);
    done = 1;
}
// RN_OPEN="MU_Main_PC>MU_MainMenuCarCustomize:20": test-only, once <from> is on, switch it to <to> the way the menus do
// (0x4b3494: [0x777b4c] = 0x20, edi = "MU_MainMenuCarCustomize.fng", cdecl 0x4f6360("<from>.fng")). 0x4f6360 finds the
// open package by its name (0x4f3f90) and 0x4f0800 replaces it with edi's. ":<hex>" = the [0x777b4c] the menu sets
// (options 0x10, customize 0x20; scratchpad opens.txt lists every call site). Both names are .rdata strings.
static uint32_t rdata_str(Ctx *c, const char *name) {
    char z[80];
    snprintf(z, sizeof z, "%s.fng", name);
    size_t n = strlen(z) + 1;
    for (uint32_t a = 0x697000; a + n < 0x6d4000; a++)
        if (!memcmp(c->mem + a, z, n) && !c->mem[a - 1]) return a;
    return 0;
}
void input_open(Ctx *c) {
    static const char *s;
    static uint32_t seen, done;
    if (!s) { s = getenv("RN_OPEN"); if (!s) s = ""; }
    if (!*s || done) return;
    char from[64] = "", to[64] = "";
    unsigned mode = 0;
    if (sscanf(s, "%63[^>]>%63[^:]:%x", from, to, &mode) < 2) { rn_log("RN_OPEN: cannot read \"%s\"", s); done = 1; return; }
    if ((rn_flow >> 8) != 3 || !screen_on(from)) { seen = 0; return; }
    if (!seen) seen = rn_telem.presents;
    if (rn_telem.presents - seen < 30) return;
    uint32_t f = rdata_str(c, from), t = rdata_str(c, to), r[8];
    done = 1;
    if (!f || !t) { rn_log("RN_OPEN: no string %s or %s", from, to); return; }
    if (mode) st(c, 0x777b4c, mode, 4);
    memcpy(r, c->r, sizeof r);
    c->r[EDI] = t;
    call_guest_cdecl(c, 0x4f6360, 1, &f);
    memcpy(c->r, r, sizeof r);
    rn_log("RN_OPEN: %s -> %s at frame %u", from, to, rn_telem.presents);
}
// RN_NEXT="3+0": test-only, per event of the chain, how many times to pick Next Race on a tournament's PostRaceMenu
// (every stage: after the last one Next Race ends the tournament).
// The menu's flags +0x42..+0x46 follow its items: Next Race's confirm (0x496ea9) answers 0x7e9ccc8f -> +0x42 (0x497759);
// the menu's reactivation 0xc98356ba then runs 0x497809 -> 0x497850 -> 0x4970f0 (race message 0xa, unload). 0xe1a57d51
// (+0x43 -> 0x497260, race message 8) is Restart Race: runs/cjump_6+7 ran stage 1 (1003) four times, never TRACKB1006.
// The screen object = [pkg+0x14] of 0x4f3f90("PostRaceMenu.fng"), sent through its vtable+8 (msg, 0, 0, [pkg+0x18]),
// as 0x435570 sends 0xd8692111. RETURN there opened the confirm with No focused (runs/cjump_6 taps 18-19).
static void screen_msg(Ctx *c, uint32_t name, uint32_t msg) {
    uint32_t r[8], a[4] = {msg, 0, 0, 0}, l = 0x746104;
    memcpy(r, c->r, sizeof r);
    c->r[EAX] = name;
    uint32_t pkg = call_guest(c, 0x4f3f90, 1, &l), obj = pkg ? ld(c, pkg + 0x14, 4) : 0;
    if (obj) a[3] = ld(c, pkg + 0x18, 4), c->r[ECX] = obj, call_guest(c, ld(c, ld(c, obj, 4) + 8, 4), 4, a);
    memcpy(c->r, r, sizeof r);
    rn_log("RN_NEXT: message %08x to package %08x screen %08x (handler %08x) at frame %u", msg, pkg, obj, obj ? ld(c, ld(c, obj, 4) + 8, 4) : 0, rn_telem.presents);
}
uint32_t rn_next_left;   // RN_JUMP waits while a tournament has stages left (Next Race goes through the front end)
void input_next(Ctx *c) {
    static const char *s;
    static uint32_t seen, done, raced, want, on;
#define left rn_next_left
    if (!s) { s = getenv("RN_NEXT"); if (!s) s = ""; else on = 1, want = (uint32_t)strtoul(s, (char **)&s, 10); }
    if (!on) return;
    // The count arms when the event's first stage races, so RN_JUMP still starts it from the map
    if ((rn_flow >> 8) == 6 && !raced) raced = 1, left = want;
    if ((rn_flow >> 8) == 3 && raced && !left) {   // the event is over: the next one's count
        raced = 0;
        while (*s == '+' || *s == ',') s++;
        want = (uint32_t)strtoul(s, (char **)&s, 10);
    }
    // RewardPopup (one per reward, list [0x735ed0]): its handler 0x49f0c0 takes 0x911ab364 as "next": the next reward
    // (0x49f000) or, after the last, 0x49e040 goes on to the next screen (Hopper rewardpop.txt). The RETURN taps did not
    // close it (runs/cjump_6 stage 2, taps 23-24), so the hook sends that message, once per 60 frames it stays up.
    static uint32_t pop;
    if (screen_on("RewardPopup")) {
        if (!pop) pop = rn_telem.presents;
        if (rn_telem.presents - pop >= 60) screen_msg(c, rdata_str(c, "RewardPopup"), 0x911ab364), pop = rn_telem.presents;
    } else pop = 0;
    if (!screen_on("PostRaceMenu")) { seen = done = 0; return; }
    if (done || !left) return;
    if (!seen) seen = rn_telem.presents;
    if (rn_telem.presents - seen < 30) return;
    uint32_t name = rdata_str(c, "PostRaceMenu");
    screen_msg(c, name, 0x7e9ccc8f);
    screen_msg(c, name, 0xc98356ba);
    done = 1, left--;
}
#undef left
// RN_CALL="MU_Main_PC#2:41c7a0": test-only, call a game function with no arguments once, 30 frames into the n-th time
// that screen shows. 0x41c7a0 writes <profile>.cfg and .opt (0x41e200(0x78a478), when [0x736230] names a profile), as the
// autosave 0x4c96f0 does at 0x4c9705. Leaving Options alone saves nothing (0x4d4892: only when 0x4c9570 finds the save
// image changed, and the options are not in it; runs/open_opt).
void input_call(Ctx *c) {
    static const char *s;
    static char scr[48];
    static unsigned want, fn, seen_n, on, done;
    static uint32_t seen;
    if (!s) {
        s = getenv("RN_CALL"); if (!s) s = "";
        if (*s && sscanf(s, "%47[^#]#%u:%x", scr, &want, &fn) != 3) { rn_log("RN_CALL: cannot read \"%s\"", s); s = ""; }
    }
    if (!*s || done) return;
    int now = (rn_flow >> 8) == 3 && screen_on(scr);
    if (now && !on) seen_n++, seen = rn_telem.presents;
    on = now;
    if (!on || seen_n != want || rn_telem.presents - seen < 30) return;
    uint32_t r[8];
    memcpy(r, c->r, sizeof r);
    call_guest(c, fn, 0, NULL);
    memcpy(c->r, r, sizeof r);
    rn_log("RN_CALL: %08x on %s #%u at frame %u", fn, scr, want, rn_telem.presents);
    done = 1;
}
#ifdef __EMSCRIPTEN__
#include <emscripten.h>
// u32 words: [0] head (page), [1] tail (game), [2..4] mouse dx, dy, wheel (page adds, game takes), [5] exclusive mouse,
// [8..8+RING) events: bit 31 = mouse button (else key), bit 8 = down, low byte = DIK or button.
#define RING 1024
static uint32_t ring[8 + RING];
EMSCRIPTEN_KEEPALIVE uint32_t rn_input_ring(void) { return (uint32_t)(uintptr_t)ring; }
void input_mouse_exclusive(int on) { __atomic_store_n(&ring[5], (uint32_t)on, __ATOMIC_RELEASE); }
void input_poll(void) {
    uint32_t head = __atomic_load_n(&ring[0], __ATOMIC_ACQUIRE), tail = ring[1];
    for (; tail != head; tail++) {
        uint32_t e = ring[8 + tail % RING];
        if (e & 0x80000000u) button_event(e & 0xff, (e >> 8) & 1);
        else key_event(e & 0xff, (e >> 8) & 1);
    }
    __atomic_store_n(&ring[1], tail, __ATOMIC_RELEASE);
    int32_t dx = (int32_t)__atomic_exchange_n(&ring[2], 0, __ATOMIC_ACQ_REL);
    int32_t dy = (int32_t)__atomic_exchange_n(&ring[3], 0, __ATOMIC_ACQ_REL);
    int32_t dz = (int32_t)__atomic_exchange_n(&ring[4], 0, __ATOMIC_ACQ_REL);
    if (dx || dy || dz) dinput8_motion(dx, dy, dz);
    script_poll();
}
#else
void input_mouse_exclusive(int on) { (void)on; }
void input_poll(void) { script_poll(); }
#endif
