# README media

Every picture here is a real capture of the build. Nothing is drawn or generated.

| File | `banner.png` | `social-preview.png` | `olympic-city.webp`, `garage.png`, `phone.webp` | `launcher.png` |
|---|---|---|---|---|
| What | One Olympic City capture with the title, set by `banner.html` | The same page at 1280x640, for GitHub Settings > Social preview | The game running in Chrome | The page around the game |

Render the banner and the social preview again:

```sh
for s in 1600,640:banner 1280,640:social-preview; do
  chrome-bot --headless=new --mute-audio --hide-scrollbars --force-device-scale-factor=1 --window-size=${s%%:*} \
    --screenshot=docs/media/${s#*:}.png "file://$PWD/docs/media/banner.html"
done
```
