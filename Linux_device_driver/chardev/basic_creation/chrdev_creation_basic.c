#include <linux/module.h>
#include <linux/init.h>

static int major;
static struct file_operations fops = {};

static int __init my_chrdev_init(void)
{
    printk("my_chrdev_init : Entry\n");
    major = register_chrdev(0, "myDriv", &fops);
    if(major < 0)
    {
        printk("my_chrdev_init : register_chrdev() failed\n");
        return major;
    }
    printk("my_chrdev_init : major number is %d\n", major);

    printk("my_chrdev_init : Exit\n");
    return 0;
}

static void __exit my_chrdev_exit(void)
{
    printk("my_chrdev_exit : Entry\n");
    unregister_chrdev(major, "myDriv");
    printk("my_chrdev_exit : Exit\n");

}

module_init(my_chrdev_init);
module_exit(my_chrdev_exit);

MODULE_LICENSE("GPL");
