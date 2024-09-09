#!/bin/bash


export PLATFORM_VERSION=13
export ANDROID_MAJOR_VERSION=t
export ARCH=arm64


make clean && make mrproper
# make menuconfig
make ARCH=arm64 exynos850_1.3_shiroko
make ARCH=arm64 -j64
