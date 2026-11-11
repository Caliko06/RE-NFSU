# UG2 TPK texture format — prior art

Two published descriptions plus one real UG2 file checked by hand. Where a source only documents
Most Wanted (2005), it says so; MW uses the same container.

Sources
- S1 MWEncyclopedia, C5.1–C5.4 and C6.1/C6.5: https://github.com/TsyVM/MWEncyclopedia (`C5-Textures-TPK/01-container-anatomy.md`, `02-metadata-tables.md`, `03-two-variants.md`, `04-finding-pixels.md`, `C6-Texture-Codecs/01-format-field.md`, `05-pal8.md`), branch `main`.
- S2 OpenUG2: https://github.com/whoismept/OpenUG2 (`docs/TEXTURE_OVERRIDES.md`, `tools/decode_texture.py`, `tools/ugui_vectors/tpk_table.expected.json`, `tpk_slots.expected.json`), branch `main`.
- S3 Real file, read with python struct this session: `/Users/angeldamian/RE-NFSU-UG2/Need For Speed Underground 2/GLOBAL/GLOBALA.BUN` (1,929,088 B) and `TRACKS/STREAML4RA.BUN`.

## Chunk tree (S1 §C5.1 table + S3 real offsets in GLOBALA.BUN)

| Chunk | Name | GLOBALA.BUN offset | size | Notes |
|---|---|---|---|---|
| `0xB3300000` | TPKContainer | 0x0 | 1,920,888 | root; whole file |
| `0xB3310000` | TPKInfo | 0x40 | 812 | metadata half |
| `0x33310001` | InfoHeader | 0x48 | 124 | version 5, name, path |
| `0x33310002` | HashTable | 0xCC | 32 | 4 × 8 B = 4 textures |
| `0x33310004` | Entries | 0xF4 | 496 | 4 × 124 B (standard variant) |
| `0x33310005` | CompInfo | 0x2EC | 128 | 4 × 32 B, holds the format |
| `0xB3320000` | TPKData | 0x380 | 1,919,992 | pixel half |
| `0x33320001` | DataHeader | 0x388 | 24 | key + flags |
| `0x33320002` | DataRaw | 0x400 | 1,919,864 | one contiguous blob |

Null chunks `0x00000000` (0x8/48 B, 0x418/96 B in S1's dump) are alignment filler, counted in the parent size (S1 §C5.1).
Counts must agree three ways: hash/8 = entries/stride = compinfo/32 (S1 §C5.1).

## InfoHeader `0x33310001` (S1 §C5.2; S3 read GLOBALA.BUN @0x48+8)

| Offset | Field | Real value |
|---|---|---|
| +0x00 | u32 version | 5 |
| +0x04 | char[28] packName | `GLOBALMESSAGETEXTURES` |
| +0x20 | char[64] sourcePath | `GLOBALMESSAGETEXTURES.tpk` |
| +0x60 | u32 pack key | (S1: pack-level key; remaining fields counts/flags = UNKNOWN) |

## Entry `0x33310004`, 124 B, offsets relative to entry (S3 verified on 4 GLOBALB entries; S1 §C5.4 agrees minus the offset field)

| Offset | Field | Real value |
|---|---|---|
| +0x0C | char[24] name | `CHROMEGENERIC_LOADINGBA`, `NFSU_LOGO_CHROME` |
| +0x24 | u32 key | 0x20afcb2c — equals its HashTable slot (S3) |
| +0x30 | u32 data offset into `0x33320002` | 0x0, 0xb00, 0x150b00, 0x154b00 (tile with 256 B alignment) |
| +0x38 | u32 total size (base + mips) | 0xaa0, 0x150000, 0x4000, 0x80000 |
| +0x40 | u32 base size (mip 0) | 0x800 (64×64 DXT1), 0x100000 (1024×1024 DXT5) |
| +0x44 | u16 width, u16 height | 64×64, 1024×1024, 128×128, 1024×512 |
| +0x48 | u8 log2w, u8 log2h | 6,6 / 10,10 / 7,7 / 10,9 |
| +0x4A | u8 engine format id | 0x22 (DXT1), 0x26 (DXT5) — see formats |
| +0x4C | u16 pad, u16 mip count at +0x4E | 4, 3, 1, 1 |
| +0x28 | u32 constant | 0x1a93cf in all four; meaning UNKNOWN |

S1 §C5.4 puts the offset at `+0x30` and dimensions at `+0x44`… it labels `+0x38` "total_size", which matches S3; treat S1's `+0x30` wording as the same field S3 read. `+0x34 = 0xffffffff` in all four entries (S3), meaning UNKNOWN.

## CompInfo `0x33310005`, 32 B (S3 read; S1 §C6.1 identical)

| Offset | Field | Real value |
|---|---|---|
| +0x08 | u32 per-texture flag | 0 or 1 |
| +0x0C | u32 constant | 5 |
| +0x10 | u32 constant | 6 |
| +0x14 | FourCC or numeric D3DFORMAT | `DXT1` (0x31545844), `DXT5` (0x35545844) |

Format rule (S1 §C6.1): if bytes +0x15..+0x17 are zero, the field is a little-endian numeric `D3DFORMAT`
(`0x15` = A8R8G8B8, `0x29` = P8); otherwise it is ASCII FourCC (`DXT1`, `DXT3`, `DXT5`).

## Codecs and size rules

| Tag | Codec | Bytes per 4×4 block / texel | Source |
|---|---|---|---|
| `DXT1` / 0x22 | BC1, RGB + 1-bit alpha | 8 B/block | S1 §C6.1–C6.2; id 0x22 from S2 vectors + S3 `+0x4A` |
| `DXT3` / 0x24 | BC2, BC1 + 4-bit alpha | 16 B/block | S1 §C6.1; id 0x24 only from S2 vectors |
| `DXT5` / 0x26 | BC3, BC1 + interpolated alpha | 16 B/block | S1 §C6.1; id 0x26 from S3 `+0x4A` |
| 0x15 | A8R8G8B8, BGRA in memory | 4 B/texel | S1 §C6.1/C6.4 |
| 0x29 | P8, 8-bit palette index | 1 B/texel, base = w·h | S1 §C6.5 (P8 `TREAD` 128×64 = 8192 B) |

Mips: levels stored largest first, no padding; each level a quarter of the previous; block sizes
`max(1,ceil(w/4))·max(1,ceil(h/4))·8|16`, never below one 4×4 block (S1 §C5.4). S3 check: 64×64 DXT1,
4 mips → 2048+512+128+32 = 2720 = 0xaa0 total. ✅

## Compression / variants

- Standard: `0x33310004`, 124 B entries, all pixels in one `0x33320002` blob addressed by offset+size (S1 §C5.3; S3 confirms tiling).
- Compressed: `0x33310003`, 24 B descriptors, one **JDLZ** sub-blob per texture, decompress then decode (S1 §C5.3, JDLZ in S1 Chapter 3). Detect by chunk id, never by size.
- UNKNOWN for UG2: whether any UG2 pack is the compressed variant. Scanned the first 40 `GLOBAL/*.BUN` (S3, `struct` search of the first 4 MiB each): 0 hits for `0x33310003`. Not scanned: TRACKS/CARS.
- UNKNOWN: no `*.tpk` file exists in the UG2 install tree (S3 `find -iname *.tpk` → empty); packs live inside `.BUN` files.

## OpenUG2 specifics (S2)

- Hardcoded reader in `tools/decode_texture.py`: entry stride 124 starting at payload `+0xC0`, data offset at `+0x24`, dimensions at `+0x38`, blob at `0xB3320000` payload; texture key is the 32-bit hash used for override file names `KEY8HEX[@PACK].dds`.
- Its `+0x24` (offset) and `+0x38` (dimensions) disagree with S3 (`+0x30`, `+0x44`) → the script's constants are stale or pack-specific. Do not copy them; read S3's map.
- Format ids in `tools/ugui_vectors/tpk_table.expected.json`: `0x22` = DXT1, `0x24` = DXT3, `0x20` = BGRA, `0x08` = palette. These are synthetic vectors (`SYN_*` names), so only `0x22`/`0x26` are confirmed against retail data (S3).
- `docs/TEXTURE_OVERRIDES.md`: overrides accept DXT1/3/5 and 32-bit RGBA, power-of-two, 1×/2×/4× the original, full mip chain; HUD and frontend textures not covered.

## Still UNKNOWN

- Meaning of entry `+0x28` (0x1a93cf) and `+0x34` (0xffffffff), and of the `+0x50…+0x7C` tail (per-mip table?).
- P8 palette provenance: not in comp-info, no palette chunk, pointer zeroed on disk, engine-resolved (S1 §C6.5, verified on MW data only).
- Whether UG2 has extra chunk ids beyond the set above: not censused across all packs.
