#!/bin/bash

# A shell script to enable/disable pmbus devices
[ $# -lt 3 ] && { echo "Usage: $0 BUS_NR MODULE ENABLE"; exit 1; }

BUS_NR=$1
MODULE=$2
ENABLE=$3

#Functions
enable_dev () {
	#Enable repeated start
	echo -n 1 > /sys/module/i2c_bcm2708/parameters/combined
	
	#Retrieve and fetch all devices by using i2cdetect 
	i2cdetect_out=$(i2cdetect -y $BUS_NR | grep : | awk -F':' '{print $2}' | tr ' ' '\n')
	
	#Loop
	for dev in $(echo $i2cdetect_out)
	do
		if [[ $dev =~ [0-9] ]]; then
			echo Try to enable $MODULE@0x$dev
			echo $MODULE 0x$dev > /sys/class/i2c-adapter/i2c-$BUS_NR/new_device
		fi
	done
	
	
}

disable_dev () {
	
	#Retrieve and fetch all devices by using i2cdetect 
	sensors_tbdel=$(sensors | grep $MODULE-i2c-$BUS_NR- | awk -F'-' '{print $4}')
	
	#Loop
	for dev in $(echo $sensors_tbdel)
	do
		if [[ $dev =~ [0-9] ]]; then
			echo Disable $MODULE@0x$dev 
			echo 0x$dev > /sys/class/i2c-adapter/i2c-$BUS_NR/delete_device
		fi
	done
	
	
}

[ "$ENABLE" == "EN" ] && enable_dev
[ "$ENABLE" == "DIS" ] && disable_dev

#echo "CHECK"
ls /sys/class/hwmon/