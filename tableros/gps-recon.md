# GPS recon (G1), 2026-11-12, Sub
Read-only. Tools: REA (Ghidra 12.1.4 provider) on pc/Speed.exe, objdump (llvm, AT&T) on the same bytes, Hopper export census/hopper/decomp.c, Python byte reads of the PE and of build/openworld/TRACKB1010.lzc (md5 b371396d = the file main serves).
V = read in the binary or data with two tools; I = inferred; U = unknown. Workers: cdx angel 2000527c04 (items 1-2), cdx paola 2000526fdb (3-4), bec 2000520135 (5); every V below re-read by Sub.

## 1. Player position and heading
| Fact | Proof | Tools | |
|---|---|---|---|
| Player car = node of race list `[0x7361f8]` whose entrant `[[car+0x14]+4] == 1` | host/openworld.c:54,323-326; Ghidra decomp_0x401000_0x4a6800.c:26895 | Ghidra export + host read | V |
| Position x,y,z = float car+0x60/+0x64/+0x68 | 0x427cb1-0x427cb7 stores them (objdump); getter 0x41f5e0 `add eax,0x60; ret` | REA 0x427e60/0x427c50 + objdump | V |
| Heading = s16 car+0x3b4 (0..65535 = full turn), +0x3b6 cleared | 0x427c97 / 0x427c9e (objdump); scale [0x6cc980] = 2pi/65536 at 0x564b10 (cdx) | objdump + REA | V (scale I) |
| Axes: XY ground plane, Z up | ground query returns height, gravity [0x7000ac]=9.8 (cdx); placement z-6.2 for UG2 (ug2world.js:237) | objdump + data | V; metres I |
| Page read path today: none. Pose is read only inside Present (host/d3d9.c:1289 -> world_spawn, ai_tel) | tools/recomp/build.py:184 exports, web/telemetry.js:9-12 | code read | V |
| Not the car: [0x740500] is the camera object | Ghidra export :7548 | Ghidra | V |

## 2. Teleport
| Fact | Proof | Tools | |
|---|---|---|---|
| 0x427e60 Car::ResetToPoint(ecx car, edx &pos, eax yaw16, stack 2 args) -> 0x427c50(edx, arg, eax) then 0x443a10(0x7372b0, car+0x60) then driver vtable +0x2c(1), +0x30 | REA pseudo 0x427e60 | REA + objdump 0x427c86 push 0x7372b0 | V |
| 0x427c50 (car in EDI): if [0x7798e0]==0 clears physics 0x426110 + 0x464c80; writes yaw, xyz, speed arg -> +0x3d0 | objdump 0x427c59-0x427cba | objdump + REA | V |
| Ground snap 0x427c50 -> 0x4278d0 -> 0x440a40 per wheel | cdx 0x427520-0x42758d; census names_track.tsv GroundQuery::FindSurfaceBelow | objdump + Ghidra export :48177 | V path; ground at any target U |
| Streaming: 0x444840 only seeds viewer xy (base+eax*0x44+0xd4/0xd8), zeroes vel, sets enabled=1, counter -1. No wait | REA pseudo + objdump 0x444840-0x44486f | REA + objdump | V |
| The game waits on 0x445100 at race start (0x422eb0); host teleport does not | Ghidra export :27018-27025 | Ghidra (cdx) | I for mid-drive need |
| Today host calls 0x427e60 + 0x444840 once per race, at start only (RN_SPAWN) | host/openworld.c:34-67; mid-drive RN_WORLD_AT is native only (:75, :366-447) | code read | V |
| Game's own reset-to-road: 0x4314a0 Player::ResetToRoute (EAX=[car+0x18]) | caller 0x42653b; host/aitel.c:246-259 replays it | Ghidra + census names_track.tsv | V; no arbitrary target |
| Far Bayview: UG2 mesh drawn by the page (city.bin, FAR 6000, ug2world.js:16,88-95); NFSU1 vis polys 0x34151/52 = 101; collision 0x34132 173,303 rows | TRACKB1010 chunks (cdx) | data read | V counts; long-jump breakage U |

## 3. Road graph
| Fact | Proof | |
|---|---|---|
| Served WORLD net = TRACKB1010.lzc chunk 0x34121: 254 sections (ids 0-253), 26,567 nodes; chunk 0x34122: 1,902 links | decompressed offsets 0x4f0e4 / 0x3e89ac; layout header 0x27c, node 0x88, count s16 +0x10 read by 0x442b80-0x442bbc | V |
| Split: Olympic sections 0-77 (3,523 nodes), connector 78 (43 nodes), Bayview 79-253 (23,001 resampled nodes) | tools/ug2_traffic.py:440-470 builder + data | V |
| Joins: 28:2->78:0 (0x3e9394), 78:1->28:3 (0x3ea254), 78:42->246:302 (0x3ea274), 246:302->78:42 (0x3f5954) | link entries in 0x34122 | V |
| Undirected: 28,142 edges, ONE component of 26,567 nodes | slots +0x81/+0x82 | V |
| Directed (lane direction entry+0xd, skip type 3): 10,967 strong components, largest 3,373 | model citygraph.py:608, ug2_traffic.py:860 | V model; walker U |
| UG2 source: RoutesFreeRoam.bin 855 sections, 10,603 nodes, 3,289 links, 38 intersections; loader SPEED2.EXE 0x5de1f3-0x5de221 (header 0x8c, node 0x38) | census/ug2/names.tsv 0x5de1c0 | V |
| Frame: served net is already NFSU1 frame. UG2 data -> world: (x,y,z) -> (y-1287.375, -x+812.25, z-6.203125) | ug2world.js:237-238, tools/ug2_roads.py:20-24 | V |

## 4. Map picture and HUD line
| Fact | Proof | |
|---|---|---|
| Streets for the big map: polylines of 0x34121 + links 0x34122 (both cities + bridge, one frame) | section 3 | V |
| Background options: city.bin 4,247,155 verts / 2,952,803 tris (UG2 frame); bridge.bin 1,440 verts; UG2 TRACKMAP4000 2048x2048 (hash 0xf7600936); TRACK1010_MAP 256x256 | UG2M header, TPK 0x33310004 | V |
| 0x58e540 TrackMap ctor looks up "TRACK%d_MAP", texture -> this+0x78 | Hopper decomp.c:826797; objdump 0x58e65b `mov %eax,0x78(%ebx)` | V |
| Per frame: Hud::RenderPass 0x409cd0 -> TrackMap::Draw 0x58e810; 0x58f614 loads this+0x78 and calls 0x58fb10 (Poly2D::ClipToRect) | objdump 0x58f614-0x58f631; census/names_hud.tsv | V |
| 0x590ad0 WorldToMap: rotate by matrix at this+0x20 (0x5abdaf), then u=(x-[r+0x8c])/[r+0x94], v=([r+0x90]-y)/[r+0x94], r=[this+0xa4] | REA pseudo + objdump 0x590ad0-0x590b44 | V |
| WORLD bounds X0=-3650, Y0=4260, S=6240 | host/openworld.c:105-113,149 | V (code) |
| 0x4d04b0 = options menu text for the map option, not the minimap | objdump 0x4d04b0-0x4d0564 calls 0x4f68c0/0x59fb80/0x4f67f0; Hopper :417366 | V |
| Route on minimap = draw into the texture at this+0x78 (copy of TRACK1010_MAP) or a second quad with the same 0x590ad0 transform | I; texture update cost U |
| Prior art: UG2 has its own GPS (SPEED2.EXE strings GPS_SEARCH_Text, GPS_Search_Group, PCNavigationBar); GC Speed.elf may name it | strings | V strings; code U |

## 5. Input
| Fact | Proof | |
|---|---|---|
| Page maps KeyM -> DIK 0x32 and Tab -> 0x0f | web/input.js:11, :6 | V |
| M is bound in the game: action table 0x702c98 row 32 = {0x33, semantic 0x81000432 (DIK 0x32 = M), name 0x6cc2d8 "Debug Camera Select"}; row 31 0x81000418 = O "Debug Camera Out" | Python PE read of 0x702c98 + strings | V. FACT "KeyM unbound" refuted |
| Fix: catch M in the capture phase on the page and do not forward it (as F2 boot.js:27, F3 input.js:33-40, F4 mode.js:55, K binds.js:126 already do) | code read | V pattern |
| Mouse: input.js:74-92 scales to canvas, buttons -> 0x80000100|n; pointer lock only when the game holds the mouse exclusive (input.js:67-72,86; host/dinput8.c:181-189) | code read | V |
| An overlay above the canvas with pointer-events catches clicks before #screen; game keeps running underneath | I (web/gpu.js not read) | I |

## UNKNOWN
- Mid-drive teleport far into Bayview: time until sections and collision are ready; whether 0x445100 must be called. One run settles it (F3).
- Ground under every map click: snap the mark to the nearest net node (route data) before teleport.
- Route on the HUD minimap: texture rewrite cost and the follow/rotate modes (flag +0x21) never run.
- Direction: route over the undirected net (one component, proven). Lane direction would split it into 10,967 parts; free roam has no one-way rule.
