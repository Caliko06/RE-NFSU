# F3: WORLD mid-drive teleport

Scope: `host/gps_tp.c` and `web/gps/tp.js`; no pose or route writes. Main owns plan.json and HANDOFF.md.
FACT: `pc/Speed.exe` SHA256 `c0fad450912952f53809a54690d235aa8b4e25b9f46650693c7cbee1b4c074b7`.
Both reads: REA Ghidra 12.1.4 pseudocode in `gps-tp-rea.json`; llvm objdump of the same EXE in `gps-tp/*.objdump`.

| Address | Observed path | Second read |
|---|---|---|
| 0x422eb0 | Race start case 1 seeds viewer 0; case 3 waits at 0x423011 after 2 s, advancing only when AL from 0x445100 is zero | start.objdump |
| 0x445100 | Reads streamer+0x15c; optional worker queue status 0x57c5a0(9); optional 0x57c3b0. Returns busy in AL; exceptional queue/flag mismatch pumps 0x4483c0 and 0x445050 until flag clears. Does not initiate target loads | stream.objdump 0x445100-0x44517b |
| 0x444840 | EAX viewer 0, EDX 0x77a980, ECX xy pointer; copies xy, zeroes velocity, enables viewer, invalidates counter with -1; no wait | stream.objdump 0x444840-0x44486f |
| 0x427e60 | ECX car, EDX xyz pointer, EAX yaw16, two stack zeros; 0x427c50, zone lookup 0x443a10, driver callbacks | reset.objdump (ret 8) |
| 0x427c50 | Writes car+0x60/64/68 and yaw+0x3b4, clears collision cache 0x440740, calls 0x4278d0 | place.objdump 0x427c97-0x427ccd |
| 0x4278d0 | ESI car; calls 0x4273d0(car, car+0x90, car+0x60, car+0x540), updates body origin | snap.objdump |
| 0x4273d0 | Four wheels query 0x440a40 then 0x577060; valid wheels determine height and orientation | wheels.objdump, call at 0x42752e |
| 0x440a40 | Five stack args: collision cache, xyz, material, normal, found-byte. Height on x87; found=0 when no polygon. Rebuilds nearby cache when target is outside its bounds | ground.objdump |
| 0x441380 | chunk 0x34132: world+0x10=chunk+8, world+0x14=size>>5; initializes each 32-byte row | collision.objdump 0x4413da-0x441414 |
| 0x441480 | chunk 0x34132 unload clears world+0x10/+0x14 | unload.objdump 0x4414ad-0x4414c2 |

FACT (actual data, independent subagent read): `build/openworld/TRACKB1010.lzc` md5 `b371396d4c08e514deb839503fa176e0`, JDLZ decoded size 11,145,264. Recursive chunks have zero 0x34153/0x34154. Top-level 0x34132 header 0x41b5d0 has 5,545,696 bytes = 173,303 rows. Second source: tools/openworld/build.py DROP and stream_container; tools/ug2_collfile.py builds the combined resident collision chunk.
INFERENCE supported by loader plus data: WORLD ground collision is resident before teleport; waiting on the mesh streamer does not provide collision that is absent at a mark. The page loads the whole UG2 city separately (`web/ug2/ug2world.js`).
Decision: query real ground at the mark first; reject no-ground coordinates; call native reset/ground snap then seed car+0x60. No blocking wait or guessed delay. This applies only to WORLD, not a streaming shipped track.

Gate: flow 0x604 (active driving), track [0x78a2f0]==1010, player entrant kind 1. Host acknowledges res before clearing req with release stores. JS publishes coordinates then request with Atomics. Complete caller CPU state is restored after synchronous guest calls; guest faults remain faults.
Validation: `RN_JOBS=4 .venv/bin/python tools/recomp/build.py web` PASS (existing host/files.c EM_JS quote warnings). Serve this worktree with `.venv/bin/python tools/serve.py 5182`, then `RN_SECS=240 node tools/gps_tp_check.mjs` PASS in 39.752 s. Chrome used macgate, chrome-bot, headless, mute, temporary profile; W before and after request. One browser run, zero browser exceptions.
FACT runtime log: `30.38 GPS TP: car 018aea40 1714.83 -455.88 63.89 -> -1053.70 993.10 -2.91 ground=1 height=-3.26 yaw=9526 frame=2664 result=1`.
FACT: before speed 17.5 m/s, four wheels; after position (-1054,993,-3), four wheels; 360 presents later position (-1009,1001,-4), speed 4 m/s, four wheels, about 45.7 m driven. Request acknowledged req=0/res=1. See `gps-tp/runtime.json` and `gps-tp/runtime.log`.
Visual inspection: `web/plan/shots/gps_teleport.png` at arrival and `gps_teleport_later.png` about 6 s later show the car on the Bayview street, under the interchange, with the city rendered in both frames.
Integration: import `/gps/tp.js` once, then the dedicated map button calls `window.rnGpsTeleport(x,y,z,yaw16)` on the road node F2 selected. Returns true for a posted request, false for invalid arguments/module absent/request busy; host result arrives at +44 after +40 clears. Pose fields remain zero in this isolated F3 build because F1's gps_frame has not been merged; validation reads the game's existing JC logs.
Not verified here: F1 button integration, main :5180, other marks, Original outside WORLD runtime, native build, auditor approval.
Read-only subagent review: no blocking finding in WORLD gate, reset/ground ABI, CPU/x87 preservation or atomic request ordering. Pose publication precedes teleport in Present, so F1's live pose will reflect the move on the next Present; F3 never writes pose fields.
