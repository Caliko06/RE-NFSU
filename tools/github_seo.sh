#!/bin/sh
# One-shot: rename the GitHub repo to the words people search, set its Google-facing description,
# homepage and topics, point the local remote at the new name, push. Run by the OWNER (needs gh auth login).
set -e
OLD=Caliko06/RE-NFSU NEW=need-for-speed-underground-browser
gh repo rename "$NEW" -R "$OLD" --yes
gh repo edit "Caliko06/$NEW" \
  --description "Play Need for Speed Underground (2003) online in your browser at nfsu.cc: free, no download, no emulator. The PC game recompiled from x86 to WebAssembly." \
  --homepage https://nfsu.cc \
  --add-topic need-for-speed,need-for-speed-underground,nfsu,nfs-underground,browser-game,racing-game,webassembly,wasm,webgpu,static-recompilation,recompilation,reverse-engineering,decompilation,x86,directx9,retro-gaming,game-preservation,ghidra,emscripten,game-port
git remote set-url origin "git@github.com:Caliko06/$NEW.git"
git push origin main
echo "Done. Last step by hand: Settings > Social preview > docs/media/social-preview.png"
