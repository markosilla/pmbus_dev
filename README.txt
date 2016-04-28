####
#BUILD KERNEL MODULES
#https://github.com/notro/rpi-source/wiki
#OR follow the rpi-source script under build_kernel_modules
####

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

#in order to use custom pmbus driver, compile the driver and copy the .ko files to folder /lib/modules/4.1.13-v7+/ and use modprobe command to load the module
modprobe bmr46x



####
#FOR TEST DEVELOPERS
####

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

#EXAMPLE scripts
en_i2c_devs_SEM_board.sh - enables i2c repeated start, loads bmr46x driver to all pmb devices found on i2c-1 device
dis_i2c_devs_SEM_board.sh - unloads driver from i2c-1 dev
en_i2c_repstart.sh - enable i2c repeated start

#BMR46x driver code and development enviroment
See Makefile + dev.sh script in pmbus_drivers folder
 
