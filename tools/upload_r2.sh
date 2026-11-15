#!/bin/sh
# Upload dist/ (tools/build_public.py) to a Cloudflare R2 bucket. Run ONLY with the OWNER's go for this upload (AGENTS.md).
# Needs: rclone (brew install rclone) with a remote named "r2" (rclone config: type s3, provider Cloudflare, the R2 API token,
# endpoint https://<account id>.r2.cloudflarestorage.com). The headers R2 cannot set per bucket (COOP/COEP/CORP, "/" -> index.html)
# are Cloudflare rules on the domain: docs/re/hosting.md.
# Usage: tools/upload_r2.sh <bucket>
set -eu
B=${1:?usage: tools/upload_r2.sh <bucket>}
cd "$(dirname "$0")/.."
test -f dist/manifest.json || { echo "no dist/: run python3 tools/build_public.py"; exit 1; }
CACHE="Cache-Control: public, max-age=86400"
# Everything but speed.wasm as is. The *.gz packs are NOT Content-Encoding: the page unpacks them itself (web/ug2/ug2world.js:68,
# web/gpu.js:230). game/ files are read with Range (host/files.c), so they must stay unencoded.
rclone copy dist "r2:$B" --filter "- out/speed.wasm" --filter "- _headers" --filter "- /*.{html,js,json,webmanifest}" --transfers 16 \
  --checksum --s3-no-check-bucket --header-upload "$CACHE" --progress
# The page and its scripts change with each fix: no-cache, so browsers and Cloudflare's edge ask again (304 when unchanged).
# Sent every time (--ignore-times, ~50 small files) so the header reaches files whose bytes did not change.
rclone copy dist "r2:$B" --filter "- _headers" --filter "+ /*.{html,js,json,webmanifest}" --filter "- **" --ignore-times --transfers 16 \
  --s3-no-check-bucket --header-upload "Cache-Control: no-cache"
# speed.wasm 70 MB -> ~16 MB: stored gzipped, sent with Content-Encoding: gzip, the browser unpacks it (fetched whole, no Range).
T=$(mktemp -d)
gzip -9c dist/out/speed.wasm > "$T/speed.wasm"
rclone copyto "$T/speed.wasm" "r2:$B/out/speed.wasm" --s3-no-check-bucket --header-upload "$CACHE" \
  --header-upload "Content-Encoding: gzip" --header-upload "Content-Type: application/wasm"
rm -rf "$T"
echo "uploaded dist/ to r2:$B ($(python3 -c 'import json;print(round(json.load(open("dist/manifest.json"))["bytes"]/1e9,2))') GB)"
