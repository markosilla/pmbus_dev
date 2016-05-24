####################################################################
#BUILD KERNEL MODULES
#https://github.com/notro/rpi-source/wiki
#OR follow the rpi-source script under build_kernel_modules
####################################################################

sudo wget https://raw.githubusercontent.com/notro/rpi-source/master/rpi-source -O /usr/bin/rpi-source && sudo chmod +x /usr/bin/rpi-source && /usr/bin/rpi-source -q --tag-update
#replace /usr/bin/ to whatever where is enough space(for ex. /home/pi/)

#Downgrade gcc 4.8.x
sudo update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-4.8 50
sudo update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-4.8 50

#Update back to previous version
sudo update-alternatives --config gcc
sudo update-alternatives --config g++

#copy pmbus.ko & pmbus_core.ko to the /lib/modules/4.1.13-v7+/ and modprobe both
modprobe pmbus
modprobe pmbus_core

#use -r option to unload module(ex zl6100) 
modprobe -r zl6100

#set custom module parameters(delay =>1 us)
sudo modprobe bmr46x delay=1

#resolve all module dependencies
depmod -a

#in order to use custom pmbus driver, compile the driver and 
#copy the .ko files to folder /lib/modules/4.1.13-v7+/ and use 
#modprobe command to load the module
modprobe bmr46x

#IMPORTANT! USE dev.sh script under /home/pi/pmbus/pmbus_drivers/pmbus/ to 
#compile, unbind/rebind all needed modules for pmbus communication
sudo ./dev.sh

####################################################################
#FOR TEST DEVELOPERS - PMBUS - everything related to 
drivers under ~/pmbus/pmbus_drivers/pmbus							   
####################################################################

#Attach module driver to the specific address(for ex. 0x4d)
echo bmr463 0x4d > /sys/bus/i2c/devices/i2c-1/new_device

#all PMBUS capabilities via kernel driver should be visibile under /sys/class/hwmon/hwmon0 etc.
#for instance on SEM board we should see 6 devices hwmon0 - hwmon5

#Install userspace application  lm-sensors
sensors - will print out current status of different sensors

#ENABLE REPEATED START for I2c!! 
echo -n 1 > /sys/module/i2c_bcm2708/parameters/combined

#Check baudrate for I2c
cat /sys/module/i2c_bcm2708/parameters/baudrate

#Change baudrate of I2c to 32khz, needs reboot!-> 
append/change line dtparam=i2c_baudrate=32000 in file /boot/config.txt

#BMR46x driver code and development enviroment
See Makefile + dev.sh script in pmbus_drivers folder

#IMPORTANT! USE script en_pmbus_devices.sh to bind/unbind all available pmbus devices on i2c bus
Usage: sudo ./en_pmbus_devices.sh [i2c device 0/1] [pmbus kernel module bmr46x/pmbus] [bind or unbind EN/DIS]
Example: sudo ./en_pmbus_devices.sh 1 bmr46x EN
Example: sudo ./en_pmbus_devices.sh 1 bmr46x DIS

####################################################################
#FOR TEST DEVELOPERS - I2C_SPI_BRIDGE - everything under ~/pmbus/i2c_spi_bridge													   
####################################################################

#In order to modify and compile needed kernel modules, following SRC was copied from kernel SRC tree:
drivers/spi/spi-sc18is602.c  
drivers/mtd/spi-nor/spi-nor.c
drivers/mtd/devices/m25p80.c

#Applied 2 patch files found in ~/pmbus/i2c_spi_bridge/info/ to drivers/spi/spi-sc18is602.c
07-spi-sc18is602.c-always-set-CS1-to-control-the-mux.patch
08-add-driver-binding-support-to-spi-sc18is602.c.patch

#IMPORTANT! USE dev.sh script under /home/pi/pmbus/i2c_spi_bridge/ to 
#compile, unbind/rebind all needed modules for flashing SEM board
sudo ./dev.sh

#FLASH SEM BOARD! Call script flash_sem_file.sh in /home/pi/pmbus/i2c_spi_bridge/flash_sem/
#SCRIPT will use /home/pi/pmbus/i2c_spi_bridge/flash_sem/exp.bin as a PAYLOAD!
#Before flashing ensure SEM board does not use flash during process and bridge is enabled and so. 
sudo ./flash_sem_file.sh

OUTPUT SHOULD BE SOMETHING LIKE THIS=>

Mon 23 May 17:17:21 CEST 2016 : found MTD device on bus 0: mtd0
Mon 23 May 17:17:22 CEST 2016 : found MTD device on bus 1: mtd1
Mon 23 May 17:17:22 CEST 2016 : erasing mtd1
Mon 23 May 17:17:22 CEST 2016 : erasing mtd0
Erased 4194304 bytes from address 0x00000000 in flash
Mon 23 May 17:18:09 CEST 2016 : programming mtd0, it takes 12-15 mins. Wait until the message "mtd0 finished"
Erased 4194304 bytes from address 0x00000000 in flash
Mon 23 May 17:18:54 CEST 2016 : programming mtd1, it takes 12-15 mins. Wait until the message "mtd1 finished"
32768+0 records in
32768+0 records out
4194304 bytes (1.9 kB) copied, 0.763115 s, 2.5 kB/s
Mon 23 May 17:18:55 CEST 2016 : mtd1 finished
32768+0 records in
32768+0 records out
4194304 bytes (4.2 MB) copied, 1563.46 s, 2.7 kB/s
Mon 23 May 17:44:57 CEST 2016 : mtd0 finished



