# README media

Every picture here is a real capture of the build. Nothing is drawn or generated.

| File | `banner.png` | `social-preview.png` | `olympic-city.webp`, `bayview.webp`, `race-start.png`, `garage.png`, `phone.webp` | `world-map.png`, `launcher.png` | `road-network.png` |
|---|---|---|---|---|---|
| What | Two captures side by side, set by `banner.html` | The banner at 1280x640, for Settings > Social preview | The game running in Chrome | The page around the game | The UG2 road data, plotted |

Render the banner again:

```sh
chrome-bot --headless=new --hide-scrollbars --force-device-scale-factor=1 --window-size=1600,640 \
  --screenshot=docs/media/banner.png "file://$PWD/docs/media/banner.html"
```
