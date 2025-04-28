#include <linux/init.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");  //*
MODULE_AUTHOR("Fariz");
MODULE_DESCRIPTION("Hello world dynamic lodable kernel module");

static int myModule_module_init(void)
{
  printk("Hello world (from myModule driver!!)\n");
  return 0;
}

static void myModule_module_exit(void)
{
  printk("Good Bye (from myModule driver!!)\n");
}

module_init(myModule_module_init);
module_exit(myModule_module_exit);
