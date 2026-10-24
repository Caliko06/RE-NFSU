#!/bin/bash
# RN_REC frames (dir/<ms>.jpg) -> 60 fps mp4 holding each frame for its real duration. usage: recvideo.sh DIR OUT.mp4
cd "$1" && ls *.jpg | sort -n | awk -F. 'NR>1{printf "file %s\nduration %.4f\n", p, ($1-t)/1000} {p=$0; t=$1} END{printf "file %s\n", p}' > list.txt
ffmpeg -loglevel error -y -f concat -safe 0 -i list.txt -vf fps=60,format=yuv420p -c:v libx264 -crf 18 -preset veryfast "$OLDPWD/$2"
