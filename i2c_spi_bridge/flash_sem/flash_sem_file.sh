#!/bin/bash


reset_sem () {
	#i2c-SPI
	echo $(date) ": reset expanders"
	/usr/local/bin/sem_tool rs 3 1
}
release_sem () {
	#i2c-SPI
	echo $(date) ": release expanders"
	/usr/local/bin/sem_tool rs 3 0
}
enable_spibridge () {
	echo $(date) ": enabling spibridge"
	/usr/local/bin/sem_tool is 3 1
	#scan i2c-2 -> the bridge comes up at 0x50@8bit
#	/usr/local/bin/i2c-test --scan -b 2
	/usr/local/bin/i2c-test -b 2 --setspeed 0x190
	#scan i2c-2 -> the bridge comes up at 0x50@8bit
#	/usr/local/bin/i2c-test --scan -b 3
	/usr/local/bin/i2c-test -b 3 --setspeed 0x190
}
disable_spibridge () {
	echo $(date) ": disabling spibridge"
	/usr/local/bin/sem_tool is 3 0
}

load_kernel_modules (){
	#-------------------------------------------
	#insmod /conf/spi-sc18is602.ko
	$(lsmod |grep -q spi_sc18is602) || insmod /lib/modules/generic/kernel/drivers/spi/spi-sc18is602.ko
	$(lsmod |grep -q m25p80) || insmod /lib/modules/generic/kernel/drivers/mtd/devices/m25p80.ko
}

get_mtd_device () {
	local bus=$1
	local mtddev=""
	#--------------
	[ -e /sys/class/spi_master/spi${bus}/ ] || echo sc18is602b 0x28 > /sys/bus/i2c/devices/i2c-${bus}/new_device 
	[ -e /sys/class/spi_master/spi${bus}/spi${bus}.0 ] || echo "m25p80 1000000 0" >/sys/class/spi_master/spi${bus}/hook_to 
	sleep 1
	#-------------
	for i in 0 1 2 3 4 5 6 7 8 9 10
	do
		if [ -d /sys/class/spi_master/spi${bus}/spi${bus}.0/mtd/mtd$i ] && [ -c /dev/mtd$i ]; then
			mtddev="mtd$i"
			break
		fi
	done
	if [ "$mtddev" == "" ];then
		echo $(date) ": MTD device on bus ${bus} not initialized"
#		exit 1
	else
		echo $(date) ": found MTD device on bus ${bus}: $mtddev"
	fi
	varname="mtddev${bus}"
	eval $varname="$mtddev"
}

do_flash () {
	local mtddev=$1
	echo $(date) ": erasing $mtddev" 
	mtd_debug erase /dev/$mtddev 0 0x400000 
	echo $(date) ": programming $mtddev, it takes 12-15 mins. Wait until the message \"$mtddev finished\" " 
	dd of=/dev/$mtddev if=/home/pi/pmbus/i2c_spi_bridge/flash_sem/exp.bin bs=128 
	echo $(date) ": $mtddev finished"
}

#reset_sem
#enable_spibridge
#load_kernel_modules

get_mtd_device 0
get_mtd_device 1

#programming
for mtddev in $mtddev0 $mtddev1
do
	do_flash $mtddev &
done

wait

#disable_spibridge
#release_sem