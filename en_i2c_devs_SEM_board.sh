#you must be root to execute below commands!
#sudo su -
#enable i2crepstart
echo -n 0 > /sys/module/i2c_bcm2708/parameters/combined
echo "ATTACH"

#check aliases by using cmd "modinfo bmr46x" or "modinfo zl6100" 
CHIP_SERA=bmr46x 
CHIP_SERB=bmr46x

echo $CHIP_SERA 0x4d > /sys/class/i2c-adapter/i2c-0/new_device;
echo $CHIP_SERB 0x70 > /sys/class/i2c-adapter/i2c-0/new_device;
echo $CHIP_SERB 0x71 > /sys/class/i2c-adapter/i2c-0/new_device;
echo $CHIP_SERB 0x72 > /sys/class/i2c-adapter/i2c-0/new_device;
echo $CHIP_SERB 0x74 > /sys/class/i2c-adapter/i2c-0/new_device;
echo $CHIP_SERB 0x76 > /sys/class/i2c-adapter/i2c-0/new_device;

echo "CHECK"
ls /sys/class/hwmon/
