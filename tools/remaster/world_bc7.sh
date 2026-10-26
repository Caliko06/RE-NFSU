#!/bin/bash
# The world pack (?worldhd=1) as BC7: web/remaster/world_bc/<hash>.dds.gz + index_world_bc.tsv, read by web/gpu.js loadDds.
# Why: with the RGBA8 world pack a race costs 1.5-2 ms more GPU a frame (gate60 1/4, HANDOFF 2026-10-26); BC7 is a
# quarter of the VRAM and bandwidth, and it uploads with no decode on the page thread. Same encoder as NFS Most Wanted's
# pack (~/RE-NFSMW/tools/assets/bcdds.cpp, BC7 with the full mip chain, box-filtered and not premultiplied as mipPipe).
# Each key takes world2/ (v2) when it has it, else world/ (v1), as gpu.js did with both indexes. All are <= 1024 a side.
# Files keep their folder (world_bc/world2/, world/, dump/ <hash>): one hash can name a v1 and a v2 image.
# Resumable: a file whose .dds.gz exists is skipped. Usage: tools/remaster/world_bc7.sh [jobs, default 6]
set -e
cd "$(dirname "$0")/../../web/remaster"
BC=${BCDDS:-$HOME/RE-NFSMW/build/bc/bcdds}
TMP=${TMPDIR:-/tmp}/world_bc7.$$
mkdir -p "$TMP"
trap 'rm -rf "$TMP"' EXIT
cat index_world_v2.tsv index_world.tsv | awk -F'\t' '$2 != "" && !seen[$1]++' > "$TMP/map.tsv"
cut -f2 "$TMP/map.tsv" | sort -u > "$TMP/src.txt"
s=$(date +%s)
export BC TMP
xargs -P "${1:-6}" -n 1 sh -c 'f=$1; o=world_bc/${f%.webp}; [ -s "$o.dds.gz" ] && exit 0; mkdir -p "$(dirname "$o")"
  t="$TMP/$(echo "${f%.webp}" | tr / _)"; dwebp -quiet "$f" -o "$t.png" && "$BC" "$t.png" "$t.dds" && gzip -9c "$t.dds" > "$o.dds.gz.part" \
  && mv "$o.dds.gz.part" "$o.dds.gz"; rm -f "$t.png" "$t.dds"' _ < "$TMP/src.txt"
awk -F'\t' '{ n=$2; sub(/\.webp$/, "", n); print $1 "\tworld_bc/" n ".dds" }' "$TMP/map.tsv" > index_world_bc.tsv
echo "world_bc: $(find world_bc -name '*.dds.gz' | wc -l | tr -d ' ') of $(wc -l < "$TMP/src.txt") files, $(wc -l < index_world_bc.tsv) keys, $(du -sh world_bc | cut -f1), $(($(date +%s) - s)) s"
