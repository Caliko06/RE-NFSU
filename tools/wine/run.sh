#!/bin/bash
# The original Speed.exe under Wine on a disposable pod, the 1:1 reference (AGENTS.md source (b)). No screen, no OWNER focus.
# Fresh pod (as root): dpkg --add-architecture i386; apt-get install wine wine32:i386 wine64 xdotool imagemagick x11-utils
#   libgl1-mesa-dri:i386 libgl1:i386 libglx-mesa0:i386 xvfb; then from the Mac: python3 tools/wine/mkexe.py (exe with only
#   PATCH 0x4f5891 + nfsu.reg), rsync game/ -> /root/wine/NFSU/, Speed.exe nfsu.reg + these scripts -> /root/wine/,
#   save/ -> "pfx/drive_c/ProgramData/NFS Underground/" (quote the space: rsync splits it), WINEARCH=win32 wineboot -i,
#   ln -s /root/wine/NFSU pfx/drive_c/NFSU, cp Speed.exe NFSU/, wine regedit nfsu.reg.
# Notes: Xvfb has no display modes, so the game runs in a Wine virtual desktop (else CreateDevice fails, crash 0x4082c7).
#   DirectInput polls once per frame and llvmpipe is slow: keys are held 0.3 s. Atlantica is locked here (our PATCH 0x735ec1
#   unlocks it); Olympic Square = one ArrowLeft on SELECT LOCATION. Never `pgrep -f "Xvfb :77"` inside an ssh command line.
# Pod side of the Wine reference run of Speed.exe (only PATCH 0x4f5891). usage: run.sh start | key <xdotool key> | shot <file> | stop
export WINEPREFIX=/root/wine/pfx DISPLAY=:77 WINEDEBUG=${WINEDEBUG:-err+all,fixme-all} LP_NUM_THREADS=4
case $1 in
start)
  wineserver -k 2>/dev/null; sleep 1
  pgrep -f "Xvfb :77" >/dev/null || { setsid nohup Xvfb :77 -screen 0 1280x960x24 +extension GLX > /root/wine/xvfb.log 2>&1 < /dev/null & sleep 2; }
  cd /root/wine/pfx/drive_c/NFSU
  # GPU: vglrun -d egl (gpu.sh once per pod); without it wined3d falls back to llvmpipe (slow, keys must be held).
  VGL=; [ -x /opt/VirtualGL/bin/vglrun ] && VGL="/opt/VirtualGL/bin/vglrun -d egl"
  setsid nohup nice -n 10 $VGL wine explorer /desktop=NFSU,${2:-1280x960} Speed.exe > /root/wine/game.log 2>&1 < /dev/null &
  echo started ;;
key) for k in "${@:2}"; do xdotool keydown $k; sleep 0.3; xdotool keyup $k; sleep 0.4; done ;;
shot) import -window root "$2" ;;
stop) wineserver -k ;;
esac
