# Headlight flare: clean round glow (remaster lane)

Goal: one round glow on the lamp, no rays, no displaced disc, no blue-white excess, same near/far/stopped.
Original must stay byte-identical: every change below is a Remaster-only runtime write.

Marks: F = read in `pc/Speed.exe` (base 0x400000) or in the texture catalog this session; I = inference; U = not read.

## Answers

### (a) Rays = texture slot 0, HEADLIGHTFLAREINNER, descriptor rec[0x38] = 0

- F: `0x5443fc  mov eax,[esi+0x38]` then `0x544404  mov edi,[4*eax+0x72fa14]` select the texture by the
  descriptor's word 14 (rec[0x38]) through the runtime table 0x72fa14.
- F: descriptor 0 is 0x6f3ef8 (table 0x6f4150 = {0x6f3ef8, 0x6f3f34, 0x6f3f70, 0}, 0x3c bytes each).
  Its rec[0x38] lives at 0x6f3f30 and is `00 00 00 00` = id 0.
- F: the three slots are loaded at 0x544790..0x5447b2 from the keys at 0x6f3ee8/ec/f0:
  0x8868656f, 0x88d8e8a2, 0x3394fe62. `ref/tools/ug1-hud/catalog_all.txt` names them
  HEADLIGHTFLAREINNER (128x64), HEADLIGHTFLAREOUTER (128x64), HEADLIGHTGLOW (128x128).
- F: the PNG `ref/census/local/cars/CIVIC-pc/tex/8868656f_HEADLIGHTFLAREINNER.png` is the star with long
  horizontal and diagonal spikes. `88d8e8a2_...OUTER.png` is a 2:1 colour ring; `3394fe62_...GLOW.png` is a
  round core with thin spikes.
- So the rays are the INNER image, drawn by layer rec0 of type 0 (types 0/7/8 draw rec0+rec1, docs/flare_re.md 3).

Smallest change: write `02` at 0x6f3f30 (rec[0x38] of descriptor 0), so the big soft layer samples slot 2
(HEADLIGHTGLOW) instead of slot 0. rec1 (0x6f3f34, slot 1, the ring) and the size/alpha/exp words are untouched,
so the glow keeps its size and falloff and only loses the spikes. 1 byte, no code.
Alternative if the remaining thin spikes of GLOW still bother: leave the byte and blank slot 0 instead
(write 0 at 0x72fa14), but that kills the glow too. Prefer the byte.

### (b) Reddish disc 22 px above each lamp with LIGHTSTREAKS on: same flare, different eye (I), cause still U

- F: the streak path 0x409b70 runs only when `[0x73645c]==1` (0x409b70/0x409b78), which 0x40b3f0 sets to
  MOTIONBLUR||LIGHTSTREAKS. It binds surface 0x71abb0 (0x409b81..0x409b92), draws the lamp list 0x740a60
  through `0x544f30(view=0x7404c0, mode=0)` (0x409c4d/0x409c52), then blits 0x71aba4 back (0x409ca0..0x409cb4).
- F: `0x544f30` takes the eye from `[view+0x40]` (`0x544f6d  mov eax,[ebx+0x40]`) and each flare centre is
  pulled toward that eye by rec[0x2c] (`0x544450  fld [esi+0x2c]`, `0x544458..0x544472`).
- F: mode 0 does not use the mirror path and does not scale z (`0x5449f3 cmp esi,2` / `cmp esi,1`; mode 0 goes
  to 0x40dc60).
- I: a pull along the eye-to-point ray cannot move the pixel, so the 22 px is not rec[0x2c]. The only way the
  same lamp lands 22 px higher is that view 0x7404c0 has an eye lower than the main view: screen dy = F * dh / z.
  At 1920 the horizontal focal is F = 960/tan(35.75 deg) = 1333 px (docs/flare_re.md 1, [view+0xc]); 22 px at a
  lamp 20 m away = dh 0.33 m. A camera ~0.33 m lower reproduces the disc exactly, and the ring is reddish because
  HEADLIGHTFLAREOUTER's palette is read B,G,R,A (ref/docs/re/LEDGER.md L1-p8), so its blue ring reads red.
- U (what is still unread, this is the gap): the writer of view 0x7404c0 (who fills its matrix and its +0x40 eye,
  and whether that eye equals 0x740580+0x40); the blit rect at 0x409ca6 (0x1fffffff is passed, so the rect is not
  a plain full-screen copy); 0x40d6e0 and 0x40dc60 were not decompiled. One of those three holds the final answer.

Smallest change once the writer is known: give the streak path the main view (push 0x740580 instead of 0x7404c0
at 0x409c4d and 0x409c6a) if the eyes differ; if the offset is in the blit, correct the rect. Do not touch
0x5447c0. Remaster-only either way: the whole block is behind 0x73645c, which Original leaves 0 when
RN_LIGHTS=0 and LIGHTSTREAKS is off.

### (c) Blue-white excess: the streak buffer weights, not the flare colour

- F: the flare colour is a lerp between rec[8..0x14] and rec[0x18..0x24] by x, alpha*fade, clamped to 255 at
  0x6f41a4 (`0x5444ff..0x544566`). Descriptor 0 ends at 100,120,170,80 and descriptor 1 at 100,120,140,20:
  already blue-leaning but not blown out.
- F: the streak buffer 0x71abb0 is multiplied each frame by BLENDFACTOR k = 0x008296b4 (R 150, G 130, B 180) and
  then added with weight 0x1fffffff, so a still lamp settles at w/(1-k) = R 2.0x, G 2.4x, B 3.4x (patches.py
  0x409bdb block; 0x40d6e0 is called twice with that slot, 0x409bca/0x409bfe). That is the blue-white excess:
  it is a per-channel weight, not the descriptor colour.
- F: our patch rewrites 0x409bdb..0x409bfe to read [0x707fcc] instead of 0x1fffffff, and 0x707fcc holds
  s*(1-k), default s = 1.5 (0x1fbc9e71). Uniform 1.5x, so less blue than shipped but still over 1.

Smallest change: set s = 1.0, i.e. [0x707fcc] = 0x1f7d694b (=(1-k): R 125, G 105, B 75). A still lamp is then
exactly its own flare, the trail length is unchanged, and the blue channel stops growing fastest. It is one word
in web/tune.js (the `trails` of the default preset) and in the patches.py initial value; Remaster only, because
the rewritten 0x409bdb is reached only with LIGHTSTREAKS on and Original runs with RN_LIGHTS=0.

### (d) Wider than tall: the OUTER ring's 2:1 image on a square quad (I)

- F: both quad axes get the same half-size: `0x544566  cmp ebx,2`, `0x544569  fld [esp+0x8]` (alpha*k) is
  multiplied by the right vector at `0x544570` and by the up vector at `0x54458f`. Square in world.
- F: the projection is Hor+ (horizontal focal fixed, vertical derived), so a world square is a screen square
  (docs/flare_re.md 2). The projection cannot make it wide.
- F: HEADLIGHTFLAREOUTER is 128x64 and fills the whole UV square, so its 2:1 ellipse is drawn as a circle; the
  INNER image's spikes are what read as "wider than tall". I: after (a) the INNER spikes are gone and what is
  left (GLOW core + OUTER ring) is round; if a wide look survives, the next suspect is the UV set 0x78bcc0
  (not read).

Smallest change: none of its own; (a) removes the wide silhouette. If it survives, read the UVs at 0x78bcc0.

## Order and cost
1. (a) 0x6f3f30 = 02 (1 byte) and (c) [0x707fcc] = 1.0. Both visible, both reversible.
2. (b) needs the writer of 0x7404c0 first; it is the only open cause.
3. Judge near/far/stopped in one session, Remaster vs Original on the same lamp.

Draft patch: `tools/recomp/flare_clean.py` (FEEL-style candidates, all `when=lambda: False`).
Not built, not run: per brief.
