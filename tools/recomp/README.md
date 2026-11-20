# Static recompiler: x86 Speed.exe to C to WebAssembly

The tool that turns **Need for Speed Underground** (2003, PC) into a browser game. It reads `pc/Speed.exe` once, writes every function again as C, and compiles that C to WebAssembly. No emulator runs at play time. **Play the result: [nfsu.cc](https://nfsu.cc)** · How it works, step by step: [English](https://nfsu.cc/blog/en/static-recompilation-x86-to-webassembly.html) · [Español](https://nfsu.cc/blog/es/recompilacion-estatica-x86-a-webassembly.html)

| Step | Find | Lift | Prove | Patch | Build |
|---|---|---|---|---|---|
| File | [`frontend.py`](frontend.py) | [`lift.py`](lift.py) | [`difftest.py`](difftest.py) | [`patches.py`](patches.py) + `patches_*.py` | [`build.py`](build.py) |
| Does | Every function and basic block, by recursive descent | Each function becomes `void f_<addr>(Ctx *c)`; unknown instructions become a TRAP | Runs each lifted function next to Unicorn (reference x86 CPU), bit for bit | One line per change, original bytes checked first | C chunks, address table, `clang` native or `emcc` web |

| Also here | [`abk.py`](abk.py) | [`asm.py`](asm.py) | [`caves/`](caves) |
|---|---|---|---|
| Does | Lifts the x86 code hidden in the sound banks (`.abk`) ahead of time | Disassemble or assemble a patch cave at an address | Hand-written x86 caves for patches |

```sh
.venv/bin/python tools/recomp/build.py web     # lift and compile for the browser
RN_ONLY=<addr> tools/recomp/difftest.py        # prove one function against Unicorn
```

Next: what answers the game when it calls Windows, [`host/`](../../host). Back to the [repo](../../README.md).
