# UG2 exe source (OWNER 2026-11-10)

`SPEED2.EXE` 4,800,512 bytes, v1.2. md5 `59b7d600736b09c86760a2c4696e46bd`, sha256
`db8f7b6f6c5439a9fec17829efb0cf31771eaf967de08f99f9146d302ec5a680`.

Source: archive.org item `need-for-speed-underground-2_202602` (German install, already patched to v1.2,
uploaded 2026-02-28). The full tree lives outside this repo, at
`/Users/angeldamian/RE-NFSU-UG2/Need For Speed Underground 2/`.

NOT in git: `.gitignore` has `pc/*.exe`. Copy it here by hand from the path above.

CAVEAT: v1.2 is the build the modding stack requires (Extra Options refuses anything else), so it is the
one to target. The exe imports no `secdrv`/`sfc_os`, i.e. it is not SafeDisc-wrapped, even though the
install still ships the disc's `00000000.016`/`00000000.256`. Whether the release patched a few bytes is
unknown, same caveat as `pc/README.md`.

## PE

Image base `0x400000`, entry `0x75bcc7` (RVA `0x35bcc7`), 7 segments.

| section | VA | vsize |
|---|---|---|
| .text | 0x401000 | 0x381af1 |
| .rdata | 0x783000 | 0x641db |
| .data | 0x7e8000 | 0xd35f8 |
| .rsrc | 0x8bc000 | 0x3854e |
| (8 spaces) | 0x8f5000 | 0x3ac16 |
| (empty) | 0x930000 | 0x2000 |

The last two carry no name and the PE timestamp is 1987, so this is not a clean build artefact. Both
hold no procedures (see the census: 23,518 of 23,522 sit in .text).

Imports (14): advapi32, ddraw, dinput8, dsound, gdi32, kernel32, netapi32, shell32, shfolder, tapi32,
user32, winmm, ws2_32, d3d9.

## Baseline: lift (census/ug2)

`census/ug2/funcs.tsv` = every procedure of the Hopper document, entry + name + segment, listed with
`tools/hopper/q_ug2list.py` through `tools/hopper/hpar.sh` (same enumeration as `q_export.py`).
`census/ug2/speed2_functions.tsv` = the same entries in the shape `build.py` eats.

`tools/recomp/lift_ug2.py` lifts all of them with the NFSU lifter, NFSU patches OFF:

- 23,522 entries, **23,522 lifted, 0 failed**, 12,369 trap sites
- 4,814 functions hold a trap: **199 real**, 4,615 int3 only (padding read as a procedure)
- the 199: 150 need SSE/3DNow (`mulps`, `movaps`, `shufps`, `pfmul`, `femms`...), 49 are bad decodes
  (`decode`, `reg es`, `les`, `stmxcsr`, `fnsave`) or FPU state saves, 0 pure x87
- no patch series applies yet: 0 patches active (NFSU: 361)

For scale, NFSU is 13,760 lifted / 0 failed, and it already traps on `pfmul`/`movaps` too, so the trap
class is the same; UG2 just has 71 % more code and no patch covers it.

Rerun: `RN_JOBS=8 .venv/bin/python tools/recomp/lift_ug2.py` (8 s on the M4).
