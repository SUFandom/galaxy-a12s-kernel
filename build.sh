#!/bin/bash


export PLATFORM_VERSION=13
export ANDROID_MAJOR_VERSION=t
export ARCH=arm64


make clean && make mrproper
# make menuconfig
make ARCH=arm64 exynos850-testing
make ARCH=arm64 -j64
