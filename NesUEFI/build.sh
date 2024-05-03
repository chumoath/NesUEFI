#!/bin/sh

apt install gnu-efi
apt install mtools

make clean
make
make img
