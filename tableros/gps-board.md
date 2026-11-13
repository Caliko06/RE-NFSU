# Tablero: GPS in WORLD: map, route, teleport (2026-11-12)
Goal: in WORLD on :5180, M opens a full map of both cities; a click marks a destination; the route shows on the minimap until arrival or until cleared; a button teleports the car there. Done = G1-G4 approved and the OWNER plays it.

## Fronts
| Front | Owner | Scope | Deliverable |
|---|---|---|---|
| F0 | Sub (Opus 5.5) | recon against the binaries and data; splits F1-F3 among its leads; merges | tableros/gps-recon.md |
| F1 | lead named by Sub | the map: street data of both cities in one picture, the M key, the player arrow | web/plan/shots/gps_map.png |
| F2 | lead named by Sub | destination, route over the joined street net, route on the HUD minimap, arrival and clear | web/plan/shots/gps_route.png |
| F3 | lead named by Sub | teleport of the car mid-drive to the mark | web/plan/shots/gps_teleport.png |
| X | Sonnet adversary | Grade every claim below | gps-board.verdicts.json |

## Claims
| # | Claim | Evidence required |
|---|---|---|
| G1 | Every address, offset and data format the GPS uses was read in the binary or the data file, not taken from our docs | tableros/gps-recon.md: each row has address or chunk id, what was read, and two tools (REA plus objdump, Ghidra or Hopper); census rows added |
| G2 | In WORLD, M opens a full-screen map of the NFSU1 city, the bridge and Bayview drawn from the real street data, with the car's arrow at its live position, and the game keeps running | shot from :5180 with the map open; the code that reads the streets and the car position (file:line); a second shot seconds later where the arrow moved |
| G3 | A click marks a destination and a route along the streets is traced to it, also across the bridge; it shows on the HUD minimap, disappears on arrival, and can be cleared from the map | shots: route on the map, route on the minimap while driving, map after clear; route length and node count for a start-to-Bayview route; the arrival rule (file:line) |
| G4 | The teleport button moves the car mid-drive to the mark and the car drives on there (ground under it, world loaded) | the named code path that moves the car (addresses read twice); log line of position before and after; shot after teleport plus a shot seconds later still on the road |
| G5 | Original mode outside WORLD is unchanged and nothing runs off :5180 | the gate that limits the feature to WORLD (file:line); no new port or server in the diff |
