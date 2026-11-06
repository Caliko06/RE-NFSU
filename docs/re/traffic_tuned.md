# Tuned traffic: real parts on a traffic ride (NFSU WORLD, track 1010)

Question: can a traffic car wear real upgrade parts (rims, spoiler, moderate kit) without breaking the teleporter's repaint?
Short answer: **yes for rims (slot 0x11), and it is the cheapest real part**: rims are the only geometry slot the CarPart db
does not bind to one car model, so one rim set fits any model. Kit/hood/wing need the part to exist for that car hash.
Two open NV points: the rim *texture* (traffic rides have wheel texture hash 0 at +0x448) and the mesh draw of a
non-default part on a traffic ride.

Evidence: `objdump -d pc/Speed.exe` (base 0x400000) and the live catalog reader in `host/rivals.c` (same db the garage uses).

## 1. How parts are filled (F)

Traffic, `0x4b3ac0` (AddTrafficCars):
- `0x4b3c03` call `0x57d340(ride)` = RideInfo::FillDefaultParts, then `0x4b3c0d` call `0x57e9a0(ride)`.
- `0x57d340`: loops slots 0..0x22, skips 6, 0xc and 0x1f..0x22, and for each other slot calls
  `0x57d280(ride, slot)` (`push esi / push ebx / xor eax,eax / call` at 0x57d376). `0x57d280` scans the loaded
  CarPart db (list head 0x73ad40, 0x30-byte records) for `record+4 == [0x7326cf08]` (this model's hash) and
  `record+0x10 == 0x12`, writes that record pointer into `ride+0x44c+4*slot`, bumps `ride+0x62c+slot`, calls 0x57ea80.
  I: type 0x12 is the car's stock/"default" record; which mesh a given slot shows is resolved later, not by the pointer.
- `0x57e9a0`: walks the same db for the first record with type byte `+0x10 == 0x1e` (body paint) over all cars, stores it in
  `ride+0x4c4` (F: `movb $0x1e,%al` 0x57e9be, `cmpb %al,0x10(%edx)` 0x57e9d2, `movl %edx,0x4c4(%ebx)` 0x57e9ef), calls
  0x57ea80, then clears **slots 0x1f..0x22** (four dwords at ride+0x4c8..0x4d4, 0x57ea11) = the vinyl layers. Nothing else.
- `0x57d160` (ride reset) zeroes `+0x444` (body skin) and `+0x448` (wheel skin) and the whole part array
  (`rep stosl` 0x78 dwords at +0x44c, 0x57d18a), the dirty counters (+0x62c) and the enabled bytes (+0x6a4).
  So a traffic ride starts with no skin of its own: that is why racer bodies need DUMMY_SKIN (docs/openworld/re_traffic_racers.md).

Opponents: a preset record (`0x4b26f0`, records of 0x408 bytes) holds pairs `slot, part key` at `+0x48+8*slot` / `+0x4c+8*slot`
(F, `host/rivals.c set()`), and 0x4b26f0 installs them with CarPartDatabase::GetCarPart `0x57ce10(car hash, slot, level, prev, -1)`,
which writes `ride+0x44c+4*slot` and calls 0x57ea80 (docs/re/rivals.md:70). So the two paths end in the same field.

## 2. Part kinds, ids, and who they fit (F from the db records as read by rivals.c `catalog()`)

Record 0x30 bytes: `+0 name (char*), +4 car hash (or the slot's shared group), +8 key hash, +0x10 type/slot, +0x11 level,
+0x14 attributes (RED/GREEN/BLUE), +0x1c count`.
Valid slot ids (what the game builds, from `host/rivals.c build()`):

| slot | part | per car? |
|---|---|---|
| 1 / 2 / 0xa | front bumper / rear bumper / side skirts (one kit = same name) | yes |
| 6 | widebody | yes |
| 7 / 8 / 0xb | hood / roof scoop / wing | yes |
| 0xd / 0xe | head / tail lights | yes |
| 0xf | exhaust | yes |
| 0x10 | brakes (calipers disc) | yes |
| **0x11** | **rims** | **no: shared group** |
| 0x13..0x19, 0x1a..0x1d | decal layouts | yes |
| 0x1e | body paint | yes |
| 0x1f..0x22 | vinyl layers | no: shared |
| 0x26 / 0x27 / 0x28 / 0x29 | spoiler, caliper, tip, rim paint | paint family, not per car |
| 0x2a+ | vinyl layer colours | paint family |
| 0x3a / 0x43 / 0x4b | sponsor decals | shared |
| 0x73 / 0x74 | tint / neon | shared |

"per car yes" = the record's +4 must equal the model hash; asking for a part that model never had returns 0
(`0x57ce10` finds nothing, nothing is written). "Level" +0x11: 0 = stock, 1..4 = unlock/career level; a tier-1 build uses 1,
tier-3 uses 4 (rivals.c). Ids are **name hashes**, not small numbers: the id you pass is `record+8`, the same key the garage
bought (docs/re/garage.md).

## 3. Does a part load on a traffic car? (geometry, textures, memory, skin slots)

- Geometry: parts are not per ride. The CarPart db is loaded once at startup (`0x57c927`, head 0x73ad40, records live in the
  guest heap for every car) and the part's model comes from the car type's pack, which is loaded per type at track load.
  A traffic ride already loads its own type's stock meshes; **NV** that a non-default part mesh of the same type is also
  resident, and **NV** that a part installed by pointer is drawn (the draw side reads the array: `0x56c923`
  `leal 0x44c(edx,ecx,4),%ebp` builds CarRenderInfo's part list from ride+0x44c).
- Textures: a part is painted from the ride's own skin/wheel hashes: body work reads `ride+0x444`, rims `ride+0x448`
  (0x5a9ce0 bake, re_traffic_racers.md). Traffic has **0** in both, so a part would draw with the default texture, not the
  car's paint. That is the real risk for rims, and the reason the racer fix was DUMMY_SKIN/DUMMY_WHEEL slots (which cost
  1 MB + 64 KB each, re_traffic_racers.md §memory).
- Memory: no new ride-side allocation; scanning the db costs nothing at run time (it is already in memory).
- Skin slots: fine. The teleporter repaint `0x59b5d0 -> 0x569c30(car, id)` writes the paint id/skin only; it does not touch
  `ride+0x44c`. So a part installed once survives every teleport. 0x57e9a0 clearing 0x1f..0x22 runs only at spawn, so a
  vinyl added later would also survive; but a part in 0x1f..0x22 collides with the racer/teleport code in host/free.c that
  clears those slots on purpose.

## 4. Smallest change (draft, unapplied)

Goal "1 in 4 traffic cars carries real parts": install **rims (slot 0x11)** plus, when the model has one, a **wing (0xb)**
and a mild **kit (1/2/0xa) at level <= 2**; no vinyls. One place: the tail of `free_traffic` in `host/free.c` (it runs for
every traffic ride at `0x4b3c2f`, after 0x57d340/0x57e9a0), calling a new helper in `host/rivals.c` that already owns the
catalog. It only repeats what `0x57d313` does: store the record pointer, bump `ride+0x62c+slot`, call `0x57ea80(ride)`.
Patch: `host/tuned.patch` (a diff, not applied; nothing was built or run).

Risk order: rims are the safe one (shared group, no model binding). Kit/wing can return nothing for a given model; treat 0 as
"stock". The visible defect to expect first is rims with the default/white texture because `+0x448` is 0 on traffic rides;
the fix is the DUMMY_WHEEL overlay slot from re_traffic_racers.md, not more code here.

## Open (NV)

- That the draw picks a part's mesh from the record pointer at `ride+0x44c` (read in 0x56c8xx, not traced to the draw call).
- Whether the type's part meshes are streamed with the type (if not, a rim installs and draws nothing).
- The rim texture with `+0x448 == 0`.
- Whether 0x57ea80 is enough to rebuild the render info after the install (rivals do exactly this, so I: yes).
