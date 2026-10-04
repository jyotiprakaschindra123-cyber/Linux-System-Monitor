obj-m += simple_monitor_driver.o

# The default target compiles the kernel module
all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

# Clean up build files
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
