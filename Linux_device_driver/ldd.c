/*********************************************************************************************************
*
*	FileName			:	ldd.c
*	Description			:	Dynamic lodable linux kernel module for printing hello world in kernel log
*	Author				:	Fariz Rahman T
*
**********************************************************************************************************/
#include <linux/init.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");  //*
MODULE_AUTHOR("Fariz");
MODULE_DESCRIPTION("Hello world dynamic lodable kernel module");

static int __init myModule_module_init(void)
{
  printk("Hello world (from myModule driver!!)\n");
  return 0;
}

static void __exit myModule_module_exit(void)
{
  printk("Good Bye (from myModule driver!!)\n");
}

module_init(myModule_module_init);
module_exit(myModule_module_exit);
