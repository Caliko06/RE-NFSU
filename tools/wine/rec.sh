#!/bin/bash
# Pod: record the Wine reference. usage: rec.sh SECS OUT.mp4 [WxH] ; 60 fps x11grab of the game area (top left of the
# virtual desktop), x264 crf 18. Runs in the foreground; start it with & and drive keys with run.sh key / hold.sh.
nice -n 5 ffmpeg -loglevel error -y -f x11grab -framerate 60 -video_size ${3:-800x600} -i :77+0,0 -t $1 \
  -c:v libx264 -preset veryfast -crf 18 -pix_fmt yuv420p -threads 4 "$2"
