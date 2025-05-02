#include <linux/init.h>
#include <linux/module.h>
#include <linux/proc_fs.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Fariz Rahman T");
MODULE_DESCRIPTION("A driver module which supports reading/writing between proc and user space");

static ssize_t myDriverRead(struct file *file_pointer, 
                            char *user_space_buffer, 
                            size_t count, 
                            loff_t *offset);
static ssize_t myDriverWrite(struct file *file_pointer, 
                            const char *user_space_buffer, 
                            size_t count, 
                            loff_t *offset);

static struct proc_ops proc_ops_myDriver = {
    .proc_write = myDriverWrite,
    .proc_read = myDriverRead
};

static struct proc_dir_entry *proc_dir_entry_myDriver = NULL;
static char myDriverBuffer[100] = {};

static ssize_t myDriverWrite(struct file *file_pointer, 
    const char *user_space_buffer, 
    size_t count, 
    loff_t *offset)
{
    int result;

    printk("myDriverWrite\n");

    if(count >= sizeof(myDriverBuffer)){
        printk("myDriverWrite: Write is too large\n");
        return -EINVAL;
    }

    memset(myDriverBuffer, 0, sizeof(myDriverBuffer));
    result = copy_from_user(myDriverBuffer, user_space_buffer, count);
    if (result != 0)
        return -EFAULT;

    myDriverBuffer[count] = '\0';

    return count;
}

static ssize_t myDriverRead(struct file *file_pointer, 
                            char *user_space_buffer, 
                            size_t count, 
                            loff_t *offset)
{
    unsigned int msg_length = strlen(myDriverBuffer);
    int result;

    printk("myDriverRead\n");

    if(*offset >= msg_length) {
        return 0;
    }

    result = copy_to_user(user_space_buffer, myDriverBuffer, msg_length);
    if (result != 0)
        return -EFAULT;

    *offset += msg_length;

    return msg_length;
}

static int myDriver_module_init(void)
{
    printk("myDriver_module_init: Entry\n");

    proc_dir_entry_myDriver = proc_create("myDriver",
                                            0666,
                                            NULL,
                                            &proc_ops_myDriver);
    
    printk("myDriver_module_init: Exit\n");
    return 0;
}

static void myDriver_module_exit(void)
{
    printk("myDriver_module_exit : Entry\n");

    proc_remove(proc_dir_entry_myDriver);

    printk("myDriver_module_exit : Exit\n");
}

module_init(myDriver_module_init);
module_exit(myDriver_module_exit);
