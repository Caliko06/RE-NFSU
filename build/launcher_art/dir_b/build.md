NIGHT PRESS: tuner magazine chrome type, coral vinyl, blue Skyline, amber workshop; original composition.
WebGL2 2.5D compositor: one baked hero plate plus instanced FX; avoids live scene lighting and heavy postprocessing.
DOM buttons and text over the canvas: keyboard focus, pointer support, selectable Original/Remaster, readable errors.
Blender offline for final car fidelity: use web/launcher/v3/car.glb; generated Skyline is an art reference, not that mesh render.
Bake matched launch plate from the same camera; the delivered launch key defines tire spray and the short forward push.
Motion: hover 140 ms, press scale(0.97) 120 ms, launch 280 ms; reduced motion swaps states without travel.
Reflection: masked low-amplitude UV ripple only on floor; sparse lens water; no random sparks, no full-screen bloom.
Target 60 fps with capped DPR 1.5 and batched sprites; performance is unmeasured in this art-only pass.
Frames: key_main.png, key_select.png, key_launch.png (1920x1080); component reference: ui_kit.png.
Scene/UI textures: backdrop_main.png (1920x1080), plates_2x2.png (1280 square, 640px cells).
FX: fx_rain_4x4.png, fx_splash_4x4.png, fx_lens_glints_4x4.png (1280 square, RGBA, 320px cells, row-major).
FX source 1254px normalized to 1280px: rain variants; splash sequence; lens rows 1-2, glints/neon rows 3-4; inspect in motion at build.
