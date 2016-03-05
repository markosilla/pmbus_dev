#!/bin/sh

echo "CLOCK SKEW DETECTED"
find . -exec touch {} \;

echo "PULL"
#git pull

echo "BUILD"
make clean
make

echo "COPY MODULES"
cp spi-sc18is602.ko /lib/modules/`uname -r`/

echo "DEPMOD"
sudo depmod -a

echo "REMOVE MODULES"
sudo modprobe -r spi-sc18is602


echo "ADD MODULES"
sudo modprobe spi-sc18is602

echo "FINISHED"
