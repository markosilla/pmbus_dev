TARGET		:= $(shell uname -r)
KERNEL_MODULES	:= /lib/modules/$(TARGET)
KERNEL_BUILD	:= $(KERNEL_MODULES)/build
DRIVER 		:= pmbus pmbus_core bmr46x

obj-m		:= $(patsubst %,%.o,$(DRIVER))
obj-ko		:= $(patsubst %,%.ko,$(DRIVER))

all: 
	make -C $(KERNEL_BUILD)	M=$(PWD) modules
	#make -C /lib/modules/`uname -r`/build	M=$(PWD) modules_install

clean:
	-rm -f 	$(obj-m) \
			$(obj-ko)
	-rm -f $(patsubst %,.%.cmd,$(obj-m))
	-rm -f $(patsubst %,.%.cmd,$(obj-ko))
	-rm -f $(patsubst %,.%.mod.o.cmd,$(DRIVER))
	-rm -f $(patsubst %,%.mod.c,$(DRIVER))
	-rm -f $(patsubst %,%.mod.o,$(DRIVER))	
	
	-rm -f modules.order
	-rm -f Module.symvers
	-rm -rf .tmp_versions/
	
	make -C $(KERNEL_BUILD)	M=$(PWD) clean