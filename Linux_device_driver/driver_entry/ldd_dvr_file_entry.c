#include <linux/init.h>
#include <linux/module.h>
#include <linux/proc_fs.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Fariz Rahman T");
MODULE_DESCRIPTION("Ldd driver file entry creation");

static struct proc_dir_entry *proc_dir_entry_pyjama = NULL;
static struct proc_ops proc_ops_pyjama = {};

static int ldd_driver_module_init(void)
{
    printk("ldd driver init: entry\n");

    proc_dir_entry_pyjama = proc_create("Pyjama_driver", 
                                        0, 
                                        NULL, 
                                        &proc_ops_pyjama);

    printk("ldd driver init: exit\n");
    return 0;
}

static void ldd_driver_module_exit(void)
{
    printk("ldd driver exit: entry\n");
    
    proc_remove(proc_dir_entry_pyjama);

    printk("ldd driver exit: exit\n");
}

module_init(ldd_driver_module_init);
module_exit(ldd_driver_module_exit);
