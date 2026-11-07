# Direction A: After Hours
WebGL2 2.5D compositor + accessible HTML controls: preserve the cinematic light without rebuilding the street in 3D.
Two clean baked plates include the car, environment, mist and reflections; use a 220ms eased crossfade/scale for launch, not a free camera.
Instance sparse rain at three depths; alpha-blend splashes only below the curb/car; refract lens droplets from their alpha gradient.
Use additive light sprites at lamp/headlight anchors; animate a restrained floor reflection displacement only in wet foreground.
HTML/CSS: condensed italic type, 56px primary, 30px secondary at 1080p; 140ms press scale(.97), 180ms focus, reduced-motion stills.
Target MacBook 60fps at 1080p/DPR 1: two scene passes, batched FX, no SSR or real-time shadows; performance is unmeasured.
Keyframes: key_main.png, key_select.png, key_launch.png (1920x1080); UI reference: ui_kit.png (1920x1080).
Clean scene plates: backdrop_main.png, backdrop_launch.png (2560x1440); both contain the illustrated Skyline, not a car.glb render.
RGBA atlases: fx_rain_4x4.png, fx_splashes_4x4.png, fx_lens_water_4x4.png, fx_light_glints_neon_4x4.png (1280 square, 320px cells).
Atlas order: row-major; splash is a 16-frame sequence; rain/lens rows vary depth; light rows are headlamp, metal, red neon, amber.
Native generated scenes were 1672x941 and atlases 1254 square; exports are resampled. No browser, runtime tests, audio or commits.
