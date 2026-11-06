// The host's one view of the game flow and of "this race" (OWNER 2026-11-06, docs/re/gameflow.md).
// The game keeps its flow in [0x77a920] (1 loading FE, 2 unloading FE, 3 FE, 4/5 loading track, 6 race, 7/8 unloading track)
// and its race state in [[0x7361f0]] (1 = on the grid, not racing yet). Host modules used to read [0x77a920] themselves and
// each guessed "a new race" its own way; Restart (pause menu, 0x43ada0) and the next stage of a tournament (8 -> 4) never pass
// through 3, so state of the old race leaked into the new one (free.c's respawn tables, stale car pointers).
// Here a race begins at its grid: Grid::PlaceAllRacers 0x422a70 runs for every race, Restart included (host/free.c grid_fix,
// PATCH 0x422a86), and rn_race counts them. A race ends when the flow leaves 4..6. If no grid was seen (a mode that does not
// place one), the first race frame begins it. Rules for race-scoped state:
//   - state a module's own per-frame code reads and writes: keep a copy of rn_race and zero the state when it changes;
//   - state that guest callbacks fill while the race loads (free.c): reset in free_race_begin, called from here.
#include "host.h"

uint32_t rn_flow = ~0u;     // [0x77a920] << 8 | [[0x7361f0]] & 0xff (0xff without a race object), set at each Present
uint32_t rn_race;           // races begun this session (0 = none yet)
static int open_race;       // rn_race is still going (from its grid or first race frame until the flow leaves 4..6)

static void race_begin(Ctx *c, const char *why) {
    rn_race++, open_race = 1;
    rn_log("phase race %u begins (%s, flow %u/%d, frame %u)", rn_race, why, rn_flow >> 8, (int)(rn_flow & 0xff), rn_telem.presents);
    free_race_begin(c);
}

void rn_phase_tick(Ctx *c) {
    uint32_t rs = ld(c, 0x7361f0, 4), was = rn_flow >> 8;
    rn_flow = ld(c, 0x77a920, 4) << 8 | (rs ? ld(c, rs, 4) & 0xff : 0xff);
    uint32_t f = rn_flow >> 8;
    if (open_race && (f < 4 || f > 6)) {
        open_race = 0;
        rn_log("phase race %u ends (flow %u, frame %u)", rn_race, f, rn_telem.presents);
    }
    if (!open_race && f == 6) race_begin(c, "race frame");
    if (f == 3 && was != 3) free_frontend(c);   // back in the front end: the event (free mode's setup) is over
}

void rn_phase_grid(Ctx *c) {
    if (open_race) rn_log("phase race %u ends (restart, frame %u)", rn_race, rn_telem.presents);
    race_begin(c, "grid");
}
