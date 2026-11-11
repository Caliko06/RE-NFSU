// The keyboard and mouse of this PC. One source feeds them: the browser (web/input.js writes key and
// mouse events into a ring in the shared heap) and, for test runs (native, or web with ?keys=), a script in RN_KEYS:
// RN_KEYS="3000:RETURN,4500:DOWN" taps each key (100 ms down, "4500:D~1500" holds it 1500 ms while the taps after it go on) at that many ms after start. "3000@6/8:DOWN" taps it
// 3000 ms after the game-flow state 6 / race state 8 (RN_FLOWLOG, host/d3d9.c) is first seen once the taps before it are done;
// "3000@3:RETURN" waits for flow state 3 with any race state. "1500@=PostRaceMenu:DOWN" waits for that post-race screen
// (rn_screen, or a front-end package in rn_fe); "4000@!PostRaceMenu:RETURN" counts from the tap before and is dropped if that screen shows when it is due.
// input_poll() hands new events to the key state, the DirectInput devices and the window messages.
#include <strings.h>
#include <unistd.h>
#include <math.h>
#include "host.h"
#include "mc.h"

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
    if (mc_key(dik, d)) return;   // host/mc.c: F and, on foot, the walking keys never reach the game
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
// host/mc.c, leaving the car: every key the game holds goes up (gas, steer), so the parked car gets no input.
void input_release_game(void) { for (int k = 0; k < 256; k++) if (down[k]) key_event((uint8_t)k, 0); }
static void button_event(int b, int d) {
    if (b < 0 || b > 7) return;
    static const uint8_t vk[] = {0x01, 0x02, 0x04, 0x05, 0x06, 0, 0, 0};    // VK_LBUTTON, RBUTTON, MBUTTON, X1, X2
    if (vk[b]) set_vk(vk[b], d);
    dinput8_button(b, d);
}

typedef struct { uint64_t at_us, hold_us; uint8_t dik; uint32_t cond, mask; char op, scr[48]; } Tap;   // cond: flow state to wait for, ~0 = none
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
        taps[ntaps] = (Tap){(uint64_t)ms * 1000, 100000, k->dik, cond, mask, op[0], ""};
        memcpy(taps[ntaps].scr, scr, sizeof scr);
        s += used;
        unsigned hold;                 // "3000:D~1500": held 1500 ms instead of a 100 ms tap
        if (*s == '~' && sscanf(s, "~%u%n", &hold, &used) == 1) taps[ntaps].hold_us = (uint64_t)hold * 1000, s += used;
        ntaps++;
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
static struct { uint8_t dik; uint64_t up_us; } held[8];
static void script_poll(void) {
    static uint32_t down_at, read_at;
    static uint64_t wait_from;
    if (!script_read) read_script();
    uint64_t now = now_us();
    for (int j = 0; j < 8; j++) if (held[j].dik && now >= held[j].up_us) { key_event(held[j].dik, 0); held[j].dik = 0; }
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
        uint64_t at = taps[k].at_us + (next_tap & 1 ? taps[k].hold_us : 0);
        if (at > now || ((next_tap & 1) && rn_telem.presents - down_at < 2)) break;
        int pend = dinput8_key_pending();
        if (pend > 0) read_at = rn_telem.presents;
        int hold = (next_tap & 1) ? pend < 0 : pend > 0 || rn_telem.presents - read_at < 2;
        if (hold) { if (!wait_from) wait_from = now; if (now - wait_from < 10000000) break; }
        wait_from = 0;
        if (!(next_tap & 1)) down_at = rn_telem.presents;
        key_event(taps[k].dik, !(next_tap & 1));
        if (!(next_tap & 1) && taps[k].hold_us != 100000) {   // a held key lets go on its own; the next tap need not wait
            for (int j = 0; j < 8; j++) if (!held[j].dik) { held[j].dik = taps[k].dik, held[j].up_us = now + taps[k].hold_us; break; }
            rn_log("RN_KEYS: hold %u dik 0x%02x at frame %u for %llu ms", k, taps[k].dik, rn_telem.presents, (unsigned long long)taps[k].hold_us / 1000);
            next_tap += 2;
            continue;
        }
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
    // After a career race the hub is home too: the map path below needs no map screen (it started races from the hub,
    // runs/cjump_6), and a dialog over the hub ate the key to the map (runs/cjump_111+..: after 113's NewCareerExtroFMV).
    if ((rn_flow >> 8) != 3 || (*s && !screen_on(home) && !(car && fired && screen_on("MU_UG_UndergroundMenu")))) { seen = 0; return; }
    if (!seen) seen = rn_telem.presents;
    if (rn_telem.presents - seen < 30) return;   // let the screen settle as a player would
    extern uint32_t rn_next_left;
    // The page has no exit: it logs done once and stays (the list read "" as a jump every frame: build/gate3_a.log).
    if (!*s && !rn_next_left) {
        static int done;
        if (!done++) rn_log("RN_JUMP: done, back in the front end at frame %u", rn_telem.presents);
#ifndef __EMSCRIPTEN__
        fflush(NULL); rn_cov_report(); _exit(0);
#endif
        return;
    }
    if (rn_next_left) return;   // a tournament between stages (race message 9 loads the next one)
    if (car) {
        // The map's own path (0x4c5df0): esi = career 0x75eef8, edi = event id, ebx = its record ([0x733ff8 + 4*id],
        // filled by 0x5a0060); 0x5a0ce0 makes the race record [0x7677a8] (= career +0x88b0), 0x4dfa10(eax = record),
        // then 0x4b5df0 (ebx = [0x7677a8]) sets the race up and queues UnloadingFrontEnd 0x448d10 (Hopper evbrief.txt).
        // The briefing (record +0xac) is skipped, as the map does for events 7, 15 and 92.
        unsigned n;
        if (sscanf(s, "e%u%n", &n, &used) != 1) { rn_log("RN_JUMP: cannot read \"%s\"", s); s = ""; return; }
        s += used;
        while (*s == ',' || *s == ' ' || *s == '+') s++;
        // N is the event id (census/rows.json career.N): its record is [0x733ff8 + 4 * id], as the map reads it. The
        // table order is not the id order (runs/cjump_91: the 91st record was id 92, the tournament 1002/1004/1007).
        uint32_t rec = n < 0x100 ? ld(c, 0x733ff8 + 4 * n, 4) : 0, id = rec ? ld(c, rec, 4) : ~0u;
        if (id != n) { rn_log("RN_JUMP: no career event %u", n); s = ""; return; }
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
    // The setup looks the id up in the track-info table ([0x736168] rows x 0xfc, [0x73616c] count, s16 id @+0x6c, loop 0x4b5140)
    // and reads [0+0x69] at 0x4b515b when it is missing: WORLD 1010 is absent in original mode (RN_WORLDROW=0, web/mode.js).
    uint32_t rows = ld(c, 0x736168, 4), n = ld(c, 0x73616c, 4), k = 0;
    while (k < n && (uint16_t)ld(c, rows + k * 0xfc + 0x6c, 2) != t) k++;
    if (k == n) { rn_log("RN_JUMP: track %u is not in the track table (%u rows; WORLD 1010 needs RN_WORLDROW on, i.e. not ?mode=original)", t, n); s = ""; return; }
    st(c, 0x777cc8, m, 4);
    st(c, 0x748f70 + rec[m] + 8, t, 4);
    rn_log("RN_JUMP: mode %u track %u at frame %u", m, t, rn_telem.presents);
    call_guest(c, 0x4b5c00, 0, NULL);
    seen = 0, fired = 1;
}
// RN_FINISH=<place>: test-only, finish each race at that place a second after [[0x73619c]] reaches 4, the way
// the debug race menu's Force Race Finish does (Hopper dbgfin.txt; 0x4c09b0 accept at 0x4c0a52): eax = 0, edx = place,
// stdcall 0x572a90([0x7345d0], player) -> 0x494b90 message 0 sets [[0x73619c]+0x534] = place, +0x538 = player.
// F3 in the page (web/input.js, ring word 6): the same finish at place 1 for one race, the OWNER's skip. Armed from the menus, it also
// passes the event briefing's "buy all upgrades" check (0x4c5fa0 -> 0x5a1fa0): the debug byte 0x735ec1 it reads, set only while the
// briefing is open. Not on in the shops: 0x5a2620 would charge a price the byte let through, and cash goes negative. The byte does not
// pass the min ride rating check 0x4c5f20 (0x5a05b0 against event +0x18), which comes first.
static int cheat_take(void);
static void cheat_briefing(Ctx *c, int armed) {
    static int forced;
    static uint32_t prev;
    int on = armed && rn_fe && strstr(rn_fe, "MU_UG_EventBriefing.fng");
    if (on && !forced) prev = ld(c, 0x735ec1, 1), st(c, 0x735ec1, 1, 1), forced = 1;
    else if (!on && forced) st(c, 0x735ec1, prev, 1), forced = 0;
}
void input_finish(Ctx *c) {
    static const char *s;
    static uint32_t seen, done;
    static int armed;
    if (!s) { s = getenv("RN_FINISH"); if (!s) s = ""; }
    if (cheat_take()) armed = 1, rn_log("CHEAT: F3, this race counts as won (flow %u/%d, frame %u)", rn_flow >> 8, (int)(rn_flow & 0xff), rn_telem.presents);
    cheat_briefing(c, armed);
    if (!*s && !armed) return;
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
    uint32_t place = *s ? (uint32_t)atoi(s) : 1;
    c->r[EAX] = 0, c->r[EDX] = place;
    call_guest(c, 0x572a90, 2, a);
    memcpy(c->r, r, sizeof r);
    rn_log("RN_FINISH: place %u player %u at frame %u", place, player, rn_telem.presents);
    armed = 0, done = *s != 0, seen = 0;   // a cheat fires once, and this function stops running until the next F3
}
// RN_AUTOPILOT only: the game's AI does not always free the player's car (runs/cjump_104: wedged head-on in a wall for 7 minutes after the
// rivals lapped it, GetUnstuck 0x451b00 never fired; cjump_28 drift: the car bounces along a wall for thousands of frames, moving more than
// 40 m between hits, so a position circle never fired), so the race never reaches the results. A human presses Reset there: it is
// car+0x87c = 1 on the player's car, consumed by Car::ServiceResetRequest 0x4264d0 -> Player::ResetToRoute 0x4314a0 (AccidentRecovery
// 0x452710 raises the same flag). Rule: route progress car+0x810 (TrackPath cursor +0x10 of car+0x800 = metres [+0x14] / path length,
// 0x443a10 stores it at 0x443c7f; UpdateLapCounts 0x4338c0 reads it *100 for the lap markers) has not passed its best value of this
// race by 2 % (about 16 m) in 20 s of racing (flow state 6/4 in the log). A drop of more than a half lap is the lap wrap and counts
// as progress. Off without RN_AUTOPILOT, so a human's feel is untouched.
// Where the reset lands (runs/cjump_64: drift event 64 came back to -77,-1280 after each of 52+ resets, 15 m before the same wall):
// 0x4314a0 puts the car on the AI driver's cursor [[car+0x2c]+0x3d8] = (+0 segment = [0x77af30 + 4 * id], +4 piece = segment + 0x27c + 0x88 * n,
// the 0x44adc0 search of the nearest piece when the cursor is empty) through 0x427f70: centre of the piece, its direction, the car's own speed.
// A second reset at the same progress moves that cursor along the driver's route first: [driver+0x3e4] (+4 nodes, +8 node pointers, node+0x58
// metres from its start, node+0x5c segment id byte, node+0x5e piece index word: 0x5a6150 reads them the same way) to the node 40 m
// per repeat past the nearest one (0x5a6150, as the jump camera 0x42c4b0 calls it), driver slot 4 0x44ab50 (seg, piece, -1) sets the cursor,
// and 0x4314a0 runs here, the way 0x4264d0 calls it, because the driver's own update may rewrite the cursor before that car update.
static int route_reset(Ctx *c, uint32_t car, float metres) {
    uint32_t drv = ld(c, car + 0x2c, 4), vt = drv ? ld(c, drv, 4) : 0, ply = ld(c, car + 0x18, 4), kind = ld(c, car + 0x14, 4);
    if (!vt || !ply || !kind || ld(c, vt + 0x20, 4) != 0x44a310 || ld(c, kind + 0x734, 1)) {   // the AI driver only
        rn_log("RN_AUTOPILOT: route reset skipped: driver %x vt %x [vt+0x20] %x player %x kind %x", drv, vt, vt ? ld(c, vt + 0x20, 4) : 0, ply, kind);
        return 0;
    }
    uint32_t route = ld(c, drv + 0x3e4, 4), n = route ? ld(c, route + 4, 4) : 0;
    if (n < 2 || n > 4096) { rn_log("RN_AUTOPILOT: route reset skipped: route %x nodes %u", route, n); return 0; }
    uint32_t r[8], a[3] = {route, car + 0x60, 1};
    memcpy(r, c->r, sizeof r);
    c->r[EAX] = 0;
    int32_t k = (int32_t)call_guest(c, 0x5a6150, 3, a), j = k;
    int ok = k >= 0 && (uint32_t)k + 1 < n, sid = -1, pi = -1;
    if (ok) {
        float base = ldf(c, ld(c, route + 8 + 4 * k, 4) + 0x58);
        // 0x5a6194/0x5a619c: a node with segment 0xff or piece -1 has no piece; skip it as 0x5a6150 does (cjump_64: nodes 22, 29).
        uint32_t node = 0;
        for (; (uint32_t)j < n; j++) {
            node = ld(c, route + 8 + 4 * j, 4), sid = (int8_t)ld(c, node + 0x5c, 1), pi = (int16_t)ld(c, node + 0x5e, 2);
            if (ldf(c, node + 0x58) - base >= metres && sid >= 0 && pi >= 0) break;
        }
        if ((uint32_t)j >= n) j = k, sid = pi = -1;
        uint32_t seg = sid >= 0 ? ld(c, 0x77af30 + 4 * sid, 4) : 0;
        ok = seg && pi >= 0 && j > k;
        if (ok) {
            uint32_t b[3] = {seg, seg + 0x27c + 0x88 * pi, 0xffffffffu};
            c->r[ECX] = drv;
            call_guest(c, ld(c, vt + 0x10, 4), 3, b);
            c->r[EAX] = ply;
            call_guest(c, 0x4314a0, 0, NULL);
            st(c, car + 0x87c, 0, 4);
            rn_log("RN_AUTOPILOT: reset %.0f m on, route node %d -> %d of %u, segment %d piece %d, car now %.0f,%.0f", metres, k, j, n, sid, pi, ldf(c, car + 0x60), ldf(c, car + 0x64));
        }
    }
    if (!ok) rn_log("RN_AUTOPILOT: route reset skipped: nearest node %d -> %d of %u, segment %d piece %d", k, j, n, sid, pi);
    memcpy(c->r, r, sizeof r);
    return ok;
}
void input_unstick(Ctx *c) {
    static int on = -1, same;
    static uint32_t since;
    static float best, at = -1;
    if (on < 0) on = getenv("RN_AUTOPILOT") != NULL;
    if (!on || rn_flow != 0x604) { since = 0; return; }
    uint32_t h = ld(c, 0x7361f8, 4), car = 0;
    if (!h || h >= GUEST_MEM - 0x1000) return;
    for (uint32_t r = ld(c, h, 4), k = 0; r && r < GUEST_MEM - 0x1000 && r != h && k < 200 && !car; r = ld(c, r, 4), k++) {
        uint32_t e = ld(c, r + 0x14, 4);
        if (e && e < GUEST_MEM - 0x1000 && ld(c, e + 4, 4) == 1) car = r;
    }
    if (!car) return;
    float p = ldf(c, car + 0x810);
    if (!since || p > best + 0.02f || p < best - 0.5f) { since = rn_telem.presents ? rn_telem.presents : 1, best = p; return; }
    if (rn_telem.presents - since < 1200) return;
    same = at >= 0 && fabsf(p - at) < 0.02f ? same + 1 : 0, at = p;   // consecutive resets that gained no progress
    rn_log("RN_AUTOPILOT: no progress %u s at %.0f,%.0f (route %.3f, repeat %d), reset requested at frame %u", (rn_telem.presents - since) / 60, ldf(c, car + 0x60), ldf(c, car + 0x64), p, same, rn_telem.presents);
    if (!same || !route_reset(c, car, 40.0f * same)) st(c, car + 0x87c, 1, 4);
    since = rn_telem.presents;
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
uint32_t rn_next_left;   // stages left in the tournament RN_JUMP started
void input_next(Ctx *c) {
    static const char *s;
    static uint32_t seen, done, raced, want, on;
#define left rn_next_left
    extern uint32_t rn_career_stages;
    static int career;
    if (!s) { s = getenv("RN_NEXT"); career = getenv("RN_CAREER") != NULL; if (!s) s = "", on = career; else on = 1, want = (uint32_t)strtoul(s, (char **)&s, 10); }
    if (!on) return;
    // The count arms when the event's first stage races, so RN_JUMP still starts it from the map (RN_CAREER: the
    // stages of the event input_career started; a single race takes one Next Race too: it leaves to the front end)
    if ((rn_flow >> 8) == 6 && !raced) raced = 1, left = career ? rn_career_stages : want;
    if ((rn_flow >> 8) == 3 && raced && !left) {   // the event is over: the next one's count
        raced = 0;
        while (*s == '+' || *s == ',') s++;
        want = (uint32_t)strtoul(s, (char **)&s, 10);
    }
    // RewardPopup: its handler 0x49f0c0 (Hopper rewardpop.txt) walks the post-race screen list [0x735ed0]: 0x406415e3
    // goes forward (the next item, or after the last 0x49dfd0 opens the next screen: PostRaceMenu), 0x911ab364 goes back
    // (0x49e040: StyleAnimator again; runs/cjump_8+.. looped StyleAnimator <-> RewardPopup on it). The RETURN taps ran out
    // on a stage with several rewards (runs/cjump_6 stage 2), so the hook sends "forward" once per 60 frames it stays up.
    // StyleAnimator's 0x49fbc0 (Hopper styleanim.txt) takes the same pair: 0x406415e3 plays the animation on (0x49f7a0)
    // until [this+0x48] == 3, then 0x49dfd0 opens the next screen; 0x911ab364 is 0x49e040, back.
    // The front end's reward screens after a career race (0x4ab670 picks MU_UG_MagazineGiveth or JunkmanGiveth): the
    // magazine's 0x4c9240 (Hopper magaccept.txt) takes 0x911ab364 to mark the covers won ([0x76777c + i] = 1) and autosave
    // (0x4c96f0), then 0x14141414 to leave (0x51bb50, 0x4c72d0: the hub, or the next magazine). 0x406415e3 is not one of
    // its messages (runs/cjump_8+..: it stayed up). The hook sends that pair, 60 frames apart.
    // PostRaceResults is the first screen of that list (0x49e040 / 0x49dfd0 walk it); its RETURN taps ran out on a
    // tournament's second stage (runs/cjump_6). Its handler 0x49ba10 has no 0x406415e3: 0xb5af2461 (accept) sets +0x40,
    // and the next 0xc98356ba plays its out-animation (0x4f6c30) and, once done (0x4f6c80), opens the next screen
    // (0x49dfd0). runs/career_trace stayed on it after event 3 when the RETURN taps ran out.
    static const char *const fwd[6] = {"RewardPopup", "StyleAnimator", "PostRaceResults", "MU_UG_MagazineGiveth", "MU_UG_JunkmanGiveth", "MU_UG_SamanthaGiveth"};
    static uint32_t pop[6], sent[6];
    for (int k = 0; k < 6; k++)
        if (screen_on(fwd[k])) {
            if (!pop[k]) pop[k] = rn_telem.presents;
            if (rn_telem.presents - pop[k] < 60) continue;
            uint32_t m = k < 2 ? 0x406415e3 : k == 2 ? 0xb5af2461 : sent[k]++ ? 0x14141414 : 0x911ab364;
            screen_msg(c, rdata_str(c, fwd[k]), m), pop[k] = rn_telem.presents;
        } else pop[k] = sent[k] = 0;
    static uint32_t logged;
    if (!screen_on("PostRaceMenu")) { seen = done = logged = 0; return; }
    if (!logged++) {   // once per showing: its five item callbacks (0x4975c0: 0x0c407210 with item hash + 0x47583934 = 0..4 calls this+0x54 + 0x10 * k)
        uint32_t l = 0x746104, r[8], pkg, obj, name = rdata_str(c, "PostRaceMenu");
        memcpy(r, c->r, sizeof r);
        c->r[EAX] = name, pkg = call_guest(c, 0x4f3f90, 1, &l), obj = pkg ? ld(c, pkg + 0x14, 4) : 0;
        memcpy(c->r, r, sizeof r);
        if (obj) for (int k = 0; k < 5; k++)
            rn_log("RN_NEXT: PostRaceMenu item %d at +%x: %08x %08x %08x %08x", k, 0x50 + 0x10 * k, ld(c, obj + 0x50 + 0x10 * k, 4),
                   ld(c, obj + 0x54 + 0x10 * k, 4), ld(c, obj + 0x58 + 0x10 * k, 4), ld(c, obj + 0x5c + 0x10 * k, 4));
    }
    if (done || !left) return;
    if (!seen) seen = rn_telem.presents;
    if (rn_telem.presents - seen < 30) return;
    uint32_t name = rdata_str(c, "PostRaceMenu");
    // Between stages 0x64bf64d2 sets +0x44 (0x49774e), which the reactivation runs as 0x497410 (Hopper praitems.txt): the
    // race record's [0x777ccc] vtable+0x18 moves to the next stage and race message 9 loads it, never leaving the race.
    // 0x7e9ccc8f (+0x42) is the other way out: 0x496f00 unloads to the front end and, the event not finished
    // (0x5a2f10), 0x5a0f60 marks it 5 and deletes the record (Hopper prunload.txt); restarting it from the map
    // (0x5a0ce0) ran stage 1 again (runs/cjump_6: 1003 three times).
    screen_msg(c, name, left > 1 ? 0x64bf64d2 : 0x7e9ccc8f);
    screen_msg(c, name, 0xc98356ba);
    done = 1, left--;
}
#undef left

// RN_CAREER=1: test-only trace of the Underground career as the game offers it (docs/archive/PLAN.md 6.1 -> tools/census/
// career_trace.py). Once a career is on (the hub MU_UG_UndergroundMenu or MU_UG_MapScreen, after event 0), each time
// the front end rests there: read the open list the game keeps (status byte 1 at career 0x75eef8 + 0x34c + id, written
// by 0x5a1100), take the lowest id and start it the way the map does (0x4c5df0): difficulty [0x75f240] = 1 (the
// briefing's middle item 0x6baa2200), 0x5a0ce0 (esi = career, edi = id, ebx = record), 0x4dfa10 (eax = record); then,
// when record +0xac names a movie, the screen swaps to MU_UG_NewCareerFMV, whose end starts the race (0x4e862f ->
// 0x4b5df0, [0x735dc8] = 0); else 0x4b5df0 at once (ebx = race [0x7677a8]). For 7, 15 and 92 the game plays that
// movie from the event list before the briefing (0x4c4ee0), so here too it comes before the race. RN_FINISH wins each
// race, RN_NEXT walks the stages (the record's count +0x98) and the reward screens. Logs "career ..." lines.
// RN_CAREER="92,113" (or "92+113", in the page's ?env=): those events in that order instead of the lowest open one (the story movies at their point in
// Chrome, on the default unlocked career), then "career done".
uint32_t rn_career_stages;   // stages of the event this hook started (RN_NEXT reads it when RN_CAREER is on)
static void career_status(Ctx *c, uint8_t st[256]) { for (int k = 0; k < 256; k++) st[k] = (uint8_t)ld(c, 0x75eef8 + 0x34c + k, 1); }
void input_career(Ctx *c) {
    static int on = -1;
    static uint32_t seen, last = 0, cash0, spent0, raced;   // event 0 (the prologue) starts from the new-career keys, not here
    static uint8_t st0[256], cov0[32];
    static const char *list;
    if (on < 0) { list = getenv("RN_CAREER"), on = list != NULL; if (on && !strcmp(list, "1")) list = NULL; }
    if (!on) return;
    if ((rn_flow >> 8) == 6 && last != ~0u && !raced) {   // the race of the event started: what it really loaded
        uint32_t race = ld(c, 0x7677a8, 4);
        raced = 1;
        rn_log("career race %u track %u word1 %u word2 %u mode %u stages %u opp %.8s,%.8s,%.8s (frame %u)", last, ld(c, 0x78a2f0, 4),
               ld(c, 0x78a2fc, 4), ld(c, 0x78a31c, 4), ld(c, 0x78a300, 4), race ? ld(c, race + 0x58a0 + 0x98, 4) : 0,
               race ? G(race + 0x58a0 + 0xd4) : "", race ? G(race + 0x58a0 + 0xf0) : "", race ? G(race + 0x58a0 + 0x10c) : "", rn_telem.presents);
    }
    if ((rn_flow >> 8) != 3 || !(screen_on("MU_UG_UndergroundMenu") || screen_on("MU_UG_MapScreen"))) { seen = 0; return; }
    if (!seen) seen = rn_telem.presents;
    if (rn_telem.presents - seen < 60) return;   // let the screen settle, and the post-race screens finish their work
    uint8_t sb[256], cov[32];
    // The open list is recomputed only when the event list (0x4c4a60) or the map (0x567eb0) builds: 0x5a2270 (eax = career,
    // one arg: 12 ints of -1) runs 0x5a1100, which relocks status 1 and reopens by 0x5a0fc0. The hub does not, so call it
    // as they do (the ints at SCREEN_ADDR + 0x100, test-only). runs/career_trace: 6 stayed locked after 1-5 were won.
    uint32_t r0[8], buf = SCREEN_ADDR + 0x100;
    for (int k = 0; k < 12; k++) st(c, buf + 4 * k, ~0u, 4);
    memcpy(r0, c->r, sizeof r0);
    c->r[EAX] = 0x75eef8, call_guest(c, 0x5a2270, 1, &buf);
    memcpy(c->r, r0, sizeof r0);
    career_status(c, sb);
    for (int k = 0; k < 32; k++) cov[k] = (uint8_t)ld(c, 0x76777c + k, 1);
    uint32_t cash = ld(c, 0x75eef8 + 0x1374, 4), spent = ld(c, 0x75eef8 + 0x137c, 4);   // 0x4c37de: a purchase moves cash to spent
    if (last != ~0u) {   // the event before: its status, cash, what opened, the covers it gave
        char op[512] = "", cv[128] = "";
        size_t n = 0, m = 0;
        for (int k = 0; k < 256; k++) if (sb[k] == 1 && st0[k] != 1 && n < sizeof op - 8) n += (size_t)snprintf(op + n, sizeof op - n, "%s%d", n ? "," : "", k);
        for (int k = 0; k < 32; k++) if (cov[k] != cov0[k] && m < sizeof cv - 8) m += (size_t)snprintf(cv + m, sizeof cv - m, "%s%d", m ? "," : "", k);
        rn_log("career result %u status %u cash %d gain %d spent %d opened %s covers %s beaten %u (frame %u)", last, sb[last], (int)cash,
               (int)(cash - cash0), (int)(spent - spent0), *op ? op : "-", *cv ? cv : "-", ld(c, 0x7677ac, 4), rn_telem.presents);
        if (sb[last] != 2) { rn_log("career stop: event %u not won", last); on = 0; return; }
        guest_mem_log("after the event");
    }
    char op[512] = "";
    size_t n = 0;
    int id = -1;
    for (int k = 0; k < 256; k++)
        if (sb[k] == 1) { if (id < 0) id = k; if (n < sizeof op - 8) n += (size_t)snprintf(op + n, sizeof op - n, "%s%d", n ? "," : "", k); }
    if (list) { while (*list == ',' || *list == '+') list++; id = *list ? (int)strtol(list, (char **)&list, 10) : -1; }
    if (id < 0) {
        rn_log("career done: no %s event, beaten %u, cash %d (frame %u)", list ? "listed" : "open", ld(c, 0x7677ac, 4), (int)cash, rn_telem.presents);
#ifndef __EMSCRIPTEN__
        fflush(NULL); rn_cov_report(); _exit(0);
#endif
        on = 0;
        return;
    }
    uint32_t rec = ld(c, 0x733ff8 + 4 * (uint32_t)id, 4);
    rn_career_stages = ld(c, rec + 0x98, 4);
    rn_log("career start %d open %s cash %d movie %.12s (frame %u)", id, op, (int)cash, G(rec + 0xac), rn_telem.presents);
    memcpy(st0, sb, sizeof st0), memcpy(cov0, cov, sizeof cov0), cash0 = cash, spent0 = spent, last = (uint32_t)id, raced = 0, seen = 0;
    uint32_t r[8];
    memcpy(r, c->r, sizeof r);
    st(c, 0x75f240, 1, 4);
    c->r[ESI] = 0x75eef8, c->r[EDI] = (uint32_t)id, c->r[EBX] = rec;
    call_guest(c, 0x5a0ce0, 0, NULL);
    c->r[EAX] = rec;
    call_guest(c, 0x4dfa10, 0, NULL);
    if (ld(c, rec + 0xac, 1)) {
        st(c, 0x735dc8, 0, 4);
        uint32_t from = rdata_str(c, screen_on("MU_UG_MapScreen") ? "MU_UG_MapScreen" : "MU_UG_UndergroundMenu"), to = rdata_str(c, "MU_UG_NewCareerFMV");
        c->r[EDI] = to;
        call_guest_cdecl(c, 0x4f6360, 1, &from);
    } else {
        c->r[EBX] = ld(c, 0x7677a8, 4);
        call_guest(c, 0x4b5df0, 0, NULL);
    }
    memcpy(c->r, r, sizeof r);
}
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

// RN_STEERLOG=1: test-only trace of the player's steering, read only. Speed.exe: the joy event handler 0x461840 (registered
// for 0x87 STEER / 0x88 STEER_ANALOG by 0x4611f3, ecx = the player input object P) stores the event byte at P+0x288/+0x289
// and the input (b - 128) * -1/128 at P+0x28c (0xff = -1). Each player update (0x461650) filters it through PlayerSteering
// S = P+0x1f0 (0x460930 -> 0x460a80 limit by speed, counter-steer, return ramp; 0x460de0 rate) into the word P+0x1d0.
// Keyboard actions 3/4 (0x702d38, 0x702d88) clear the digital flag [0x736514] (0x4070a0), which selects that model.
// Frame time: 0x585b40 measures it with QPC into dt [0x73ad38]; 0x585d70 steps the world in 1/60 s.
int rn_steerlog;
static uint32_t steer_obj;
void steer_event(Ctx *c) {
    uint32_t esp = c->r[ESP], ev = ld(c, esp + 8, 4), b = ld(c, esp + 12, 1), p = ld(c, esp + 16, 4);
    steer_obj = p;
    rn_log("steer ev %x byte %u at frame %u t %.1f ms", ev, b, rn_telem.presents, (double)now_us() / 1000);
}
void steer_frame(Ctx *c) {
    uint32_t p = steer_obj;
    if (!p || (rn_flow >> 8) != 6) return;
    float in, dt, sp, v[3], s14, s74, s78, eb;
    uint32_t w, car = ld(c, p + 0x26c, 4), s = p + 0x1f0;
#define F(dst, a) (w = ld(c, (a), 4), memcpy(&(dst), &w, 4))
    F(in, p + 0x28c); F(dt, 0x73ad38); F(s14, s + 0x14); F(s74, s + 0x74); F(s78, s + 0x78); F(eb, p + 0x2ac);
    sp = 0, v[0] = v[1] = v[2] = 0;
    if (car) { F(sp, car + 0x3d0); F(v[0], car + 0x70); F(v[1], car + 0x74); F(v[2], car + 0x78); }
#undef F
    rn_log("steer f %u t %.1f keys %d%d%d%d dt %.4f flag %u in %.3f out %d s14 %.3f s74 %.2f s78 %.3f s0car %d spd %.2f v %.2f %.2f %.2f eb %.2f shift %d slide %u hd %u",
           rn_telem.presents, (double)now_us() / 1000, down[0x1e], down[0x20], down[0xcb], down[0xcd], dt, ld(c, 0x736514, 1), in,
           (int16_t)ld(c, p + 0x1d0, 2), s14, s74, s78, ld(c, s, 4) == car, sp, v[0], v[1], v[2],
           eb, down[0x2a] | down[0x36], ld(c, s + 4, 1), car ? ld(c, car + 0x3b4, 2) : 0);
    // the slip angle 0x464ed0 (ESI = car+0x40): heading word car+0x3b4 minus the angle 0x564db0 of the velocity car+0x70/74   // ebrake 0x461e10 -> P+0x2ac; S+4 the slide flag of 0x460a80
}
#ifdef __EMSCRIPTEN__
#include <emscripten.h>
// u32 words: [0] head (page), [1] tail (game), [2..4] mouse dx, dy, wheel (page adds, game takes), [5] exclusive mouse,
// [6] F3 cheat (page sets, game takes), [8..8+RING) events: bit 31 = mouse button (else key), bit 8 = down, low byte = DIK or button.
#define RING 1024
static uint32_t ring[8 + RING];
EMSCRIPTEN_KEEPALIVE uint32_t rn_input_ring(void) { return (uint32_t)(uintptr_t)ring; }
static int cheat_take(void) { return (int)__atomic_exchange_n(&ring[6], 0, __ATOMIC_ACQ_REL); }
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
    if ((dx || dy || dz) && !mc_mouse(dx, dy)) dinput8_motion(dx, dy, dz);
    script_poll();
}
#else
static int cheat_take(void) { return 0; }
void input_mouse_exclusive(int on) { (void)on; }
void input_poll(void) { script_poll(); }
#endif
