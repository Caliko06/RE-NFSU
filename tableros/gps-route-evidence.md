# F2: WORLD GPS route

Status: implemented and observed on slice 5183/9384; main 5180 integration and blind auditor acceptance belong to Sub.

## Implementation

- Path: `web/gps/map.js` map click -> `web/gps/route.js` nearest XY street node -> A* over real undirected road edges -> `host/gps.h` route count +48, XY +52 -> `host/d3d9.c` WORLD map texture -> the game's own transformed/clipped HUD quad. Binary evidence and census: `gps-hud-evidence.md`, `census/names_gps.tsv`.
- The full route is drawn on the map; the HUD receives up to 2048 consecutive forward nodes, refreshed as the car progresses. There are no road arrows. Every route edge comes from `roads.json`.
- Product rules, not recovered binary constants: arrival under20m XY and under8m Z, checked every250ms (`web/gps/route.js:139-141`); recalculate beyond40m XYZ from the route (`:143-149`). XYZ distance prevents stacked roads from advancing the wrong segment.
- Teleport button uses the selected node's XYZ and incoming edge direction, then the existing F3 `rnGpsTeleport` and verified reset/ground path (`gps-tp-evidence.md`). Clear and arrival publish route_n=0 and restore the original minimap pixels.
- WORLD gates: `host/gps.c:11` publishes a valid pose only while racing track1010; `host/d3d9.c:2047` also requires track1010 and the exact WORLD map texture. Outside WORLD the map cannot open or accept a destination.

## Verification

`RN_JOBS=4 .venv/bin/python tools/recomp/build.py web`: built the current slice. Existing warnings in host/files.c; no build failure.
`node tools/gps_shortest_check.cjs`: A* equals independent queue-based edge relaxation exactly on the real graph:4851.0818801214255m,669nodes,zero invalid edges, both cities and bridge78.
`RN_SECS=300 node tools/gps_route_check.mjs`: real muted headless Chrome through macgate; actual map click, driving W/D, clear, off-route teleport to a verified street, automatic reroute, map teleport button, arrival, then drive again. Machine-readable results: `gps-route-run.json`.

Shots in `web/plan/shots/`: `gps_route.png` (start to Bayview,7693m/1135nodes); `gps_route_hud.png` and `gps_route_hud_turn.png` (route in moving/rotating HUD); `gps_route_clear.png`; `gps_route_recalculated.png`; `gps_route_arrival.png`.
Map and HUD screenshots were visually inspected. The yellow route follows the game minimap's streets and rotates with its existing quad. Clear removes the destination and route. Existing256x256 HUD texture limits detail to24.375 world units/texel.

## Reuse and references

Reused F1's exported road graph, F3's teleport helper, and the game's existing minimap transform/clip. Small dependency-free browser A* avoids adding a package to the plain-script page. Prior art: [Red Blob Games A* implementation](https://www.redblobgames.com/pathfinding/a-star/implementation.html) documents weighted-graph search with a priority queue and heuristic. Also inspected [NFSU2Recomp](https://github.com/TalhaMudo/NFSU2Recomp); a bounded page search exposed no reusable GPS implementation.
Visual reference: existing `web/gps/map.css` palette, type and focus style. AGENTS' three named design-reference paths were absent on this machine; no new animation or visual language was introduced.

## Not verified

Driving the complete bridge route, natural arrival after driving its whole length, every possible destination's collision, all minimap option modes, mobile/keyboard-only operation, and a separate Original-mode runtime regression. Original exclusion is established by source gates. No audit approval, main merge, or5180 deployment is claimed.
