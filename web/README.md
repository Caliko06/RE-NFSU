# The page: launcher, WebGPU, audio, controls and saves

What the player opens at **[nfsu.cc](https://nfsu.cc)**: the launcher, the WebAssembly start, and the browser side of the Windows stand-in in [`host/`](../host). Play guide: [English](https://nfsu.cc/blog/en/play-need-for-speed-underground-online.html) · [Español](https://nfsu.cc/blog/es/jugar-need-for-speed-underground-online.html)

| File | [`launcher.js`](launcher.js) | [`boot.js`](boot.js) | [`gpu.js`](gpu.js) | [`audio.js`](audio.js) | [`input.js`](input.js) · [`pad.js`](pad.js) · [`touch.js`](touch.js) | [`saves.js`](saves.js) |
|---|---|---|---|---|---|---|
| Does | The first screen, in the game's menu style | Starts the WebAssembly and the frame loop | Runs each frame with WebGPU | Plays the game's mixer through an AudioWorklet | Keyboard, gamepad, touch: all become DirectInput keys | Saves in this browser (IndexedDB) |

Controls: [English](https://nfsu.cc/blog/en/need-for-speed-underground-controls-keyboard-gamepad-phone.html) · [Español](https://nfsu.cc/blog/es/controles-need-for-speed-underground-teclado-mando-celular.html). Browsers and phones: [English](https://nfsu.cc/blog/en/browsers-phones-performance-settings.html) · [Español](https://nfsu.cc/blog/es/navegadores-celulares-ajustes-rendimiento.html). Guides live in [`blog/`](blog) and are built by [`tools/build_blog.py`](../tools/build_blog.py). Back to the [repo](../README.md).
