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
cp mtd/devices/m25p80.ko /lib/modules/`uname -r`/
cp mtd/spi-nor/spi-nor.ko /lib/modules/`uname -r`/

echo "DEPMOD"
sudo depmod -a

echo "REMOVE MODULES"
sudo modprobe -r m25p80
sudo modprobe -r spi-nor
sudo modprobe -r spi-sc18is602

echo "ADD MODULES"
sudo modprobe spi-nor
sudo modprobe spi-sc18is602
sudo modprobe m25p80

echo "FINISHED"
