# The README paintings

`paint.html` paints the four pictures of the main README. It is one file with no dependencies.

| Picture | `hero.png` | `bridge.png` | `recompile.png` | `alive.png` | `social-preview.png` |
|---|---|---|---|---|---|
| Scene | `?q=1`, 1600x800 | `?q=2`, 1600x520 | `?q=3`, 1600x520 | `?q=4`, 800x800 | `hero.png` at 1280x640, for GitHub's Settings > Social preview |

Watch: open `paint.html` in a browser. Click or Space for the next painting, S to save a PNG.

Render one again (headless, at once):

```sh
chrome-bot --headless=new --hide-scrollbars --force-device-scale-factor=1 --window-size=1600,800 \
  --screenshot=docs/art/hero.png "file://$PWD/docs/art/paint.html?static=1&bare=1&q=1"
```

A new painting is a new object in `SCENES`: its size, a `draw` that makes the hidden picture, a `flow` for the stroke direction, and `texts` to letter with the brush.
