# Census: names and tables read from Speed.exe

What the reverse engineering of **Need for Speed Underground** found, as plain tables. Every name has an address in `pc/Speed.exe` (base 0x400000) and a state: **V** read in the binary, **I** inferred, **U** unknown. The lifter, the patches and the notes in [`docs/re/`](../docs/re) build on these. **Play the game: [nfsu.cc](https://nfsu.cc)** · The tools behind it: [English](https://nfsu.cc/blog/en/reverse-engineering-tools-ghidra-hopper-rea.html) · [Español](https://nfsu.cc/blog/es/herramientas-ingenieria-inversa-ghidra-hopper-rea.html)

| What | Function names | Decompiled code | Lift results | Bit-for-bit test | Game files |
|---|---|---|---|---|---|
| Where | `names_<system>.tsv` (camera, physics, rivals, render, sound...) | [`ghidra/`](ghidra), [`hopper/`](hopper) | [`lift_report.json`](lift_report.json) | [`difftest.json`](difftest.json) | [`game_files.json`](game_files.json), [`data_chunks.tsv`](data_chunks.tsv) |

Made with Ghidra (headless), Hopper ([`tools/hopper/`](../tools/hopper)) and the REA MCP. Back to the [repo](../README.md).
