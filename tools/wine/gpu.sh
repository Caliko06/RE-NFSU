#!/bin/bash
# Pod: make the Wine reference draw on the NVIDIA GPU instead of llvmpipe. Speed.exe is 32-bit, so wined3d needs the
# 32-bit NVIDIA userspace (the container ships only the 64-bit one) of the exact kernel driver version, and VirtualGL's
# EGL back end gives Xvfb windows a GPU GL context (no X server on the GPU). run.sh then starts the game under vglrun.
# usage (on the pod, once): gpu.sh
set -e
V=$(nvidia-smi --query-gpu=driver_version --format=csv,noheader)
mkdir -p /root/gl && cd /root/gl
[ -f NVIDIA-Linux-x86_64-$V.run ] || curl -sfLO https://us.download.nvidia.com/XFree86/Linux-x86_64/$V/NVIDIA-Linux-x86_64-$V.run
[ -d NVIDIA-Linux-x86_64-$V ] || sh NVIDIA-Linux-x86_64-$V.run -x > /dev/null
L=/usr/lib/i386-linux-gnu
for f in libGLX_nvidia libEGL_nvidia libnvidia-eglcore libnvidia-glcore libnvidia-glsi libnvidia-tls libnvidia-gpucomp \
         libnvidia-glvkspirv libnvidia-allocator; do
  cp NVIDIA-Linux-x86_64-$V/32/$f.so.$V $L/
done
ln -sf libGLX_nvidia.so.$V $L/libGLX_nvidia.so.0
ln -sf libEGL_nvidia.so.$V $L/libEGL_nvidia.so.0
ln -sf libnvidia-allocator.so.$V $L/libnvidia-allocator.so.1
apt-get install -y -q libegl1:i386 libopengl0:i386 libglx0:i386 > /root/gl/apt.log 2>&1
for d in virtualgl_3.1.5_amd64.deb virtualgl32_3.1.5_amd64.deb; do
  [ -f $d ] || curl -sfLO https://github.com/VirtualGL/virtualgl/releases/download/3.1.5/$d
done
dpkg -i virtualgl_3.1.5_amd64.deb virtualgl32_3.1.5_amd64.deb > /root/gl/dpkg.log 2>&1 || apt-get -f install -y -q >> /root/gl/dpkg.log 2>&1
ldconfig
echo gpu ready $V
