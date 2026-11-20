# Windows and DirectX 9, rewritten for the browser

The recompiled **Need for Speed Underground** still calls Windows: Direct3D 9, DirectSound, DirectInput, files, threads, windows. This folder answers every one of those calls, as Microsoft documents them, and sends the work to WebGPU, Web Audio and the browser's input. **Play it: [nfsu.cc](https://nfsu.cc)** · The full story: [English](https://nfsu.cc/blog/en/directx-9-and-windows-on-webgpu.html) · [Español](https://nfsu.cc/blog/es/directx-9-y-windows-sobre-webgpu.html)

| Windows part | Direct3D 9 | Frames | Sound | Input | Files | Threads | Windows, kernel |
|---|---|---|---|---|---|---|---|
| File | [`d3d9.c`](d3d9.c) | [`gpu.c`](gpu.c) + [`gpu.h`](gpu.h) | [`dsound.c`](dsound.c) | [`dinput8.c`](dinput8.c), [`input.c`](input.c) | [`files.c`](files.c) | [`threads.c`](threads.c) | [`win32.c`](win32.c), [`user32.c`](user32.c) |
| Browser side | | [`web/gpu.js`](../web/gpu.js) (WebGPU) | [`web/audio.js`](../web/audio.js) (AudioWorklet) | [`web/input.js`](../web/input.js), [`pad.js`](../web/pad.js), [`touch.js`](../web/touch.js) | byte ranges over HTTP | one lock, one guest thread at a time | |

| Start | [`main.c`](main.c) | [`dispatch.c`](dispatch.c) | [`cpu.c`](cpu.c) | [`abk.c`](abk.c) |
|---|---|---|---|---|
| Does | Loads Speed.exe like the Windows loader, runs its entry point | Guest address to lifted function or host API | The CPU the game sees: a 2003 Pentium 4 | Finds live sound-bank code modules |

The game is told it runs on Windows XP SP2 with a Radeon 9800 PRO. Nothing in here edits the game: changes to the game are patches in [`tools/recomp/`](../tools/recomp). Loading 2 GB over the web: [English](https://nfsu.cc/blog/en/hosting-a-2-gb-game-on-cloudflare-r2-load-time.html) · [Español](https://nfsu.cc/blog/es/alojar-un-juego-de-2-gb-en-cloudflare-r2-tiempo-de-carga.html). Back to the [repo](../README.md).
