#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>

#define DEVICE_NAME "sysmon_dummy"
#define SUCCESS 0

MODULE_LICENSE("GPL");
MODULE_AUTHOR("System Monitor Project");
MODULE_DESCRIPTION("A simple dummy character device driver for educational purposes.");
MODULE_VERSION("1.0");

static int device_open = 0;
static char msg[80] = "Hello from the Linux Kernel! Driver is active.\n";
static char *msg_ptr;

// Called when a user-space application opens the device file
static int dev_open(struct inode *inodep, struct file *filep) {
    if (device_open) return -EBUSY;
    device_open++;
    msg_ptr = msg;
    printk(KERN_INFO "sysmon_dummy: Device opened.\n");
    return SUCCESS;
}

// Called when a user-space application closes the device file
static int dev_release(struct inode *inodep, struct file *filep) {
    device_open--;
    printk(KERN_INFO "sysmon_dummy: Device successfully closed.\n");
    return SUCCESS;
}

// Called when a user-space application reads from the device file
static ssize_t dev_read(struct file *filep, char *buffer, size_t len, loff_t *offset) {
    int bytes_read = 0;
    
    // If we are at the end of the message, return 0
    if (*msg_ptr == 0) return 0;
    
    // Send data to user-space
    while (len && *msg_ptr) {
        put_user(*(msg_ptr++), buffer++);
        len--;
        bytes_read++;
    }
    
    printk(KERN_INFO "sysmon_dummy: Sent %d characters to the user\n", bytes_read);
    return bytes_read;
}

// Structure that defines the operations our device supports
static struct file_operations fops = {
    .open = dev_open,
    .read = dev_read,
    .release = dev_release,
};

static int major_num;

// Called when the module is loaded into the kernel (insmod)
static int __init monitor_driver_init(void) {
    major_num = register_chrdev(0, DEVICE_NAME, &fops);
    if (major_num < 0) {
        printk(KERN_ALERT "sysmon_dummy: Failed to register a major number\n");
        return major_num;
    }
    printk(KERN_INFO "sysmon_dummy: Registered correctly with major number %d\n", major_num);
    printk(KERN_INFO "sysmon_dummy: To communicate with the driver, create a dev file:\n");
    printk(KERN_INFO "sysmon_dummy: 'mknod /dev/%s c %d 0'.\n", DEVICE_NAME, major_num);
    return SUCCESS;
}

// Called when the module is removed from the kernel (rmmod)
static void __exit monitor_driver_exit(void) {
    unregister_chrdev(major_num, DEVICE_NAME);
    printk(KERN_INFO "sysmon_dummy: Goodbye from the LKM!\n");
}

module_init(monitor_driver_init);
module_exit(monitor_driver_exit);
