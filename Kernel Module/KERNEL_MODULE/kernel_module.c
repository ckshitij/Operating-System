#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

MODULE_LICENSE("GENERAL MODULE_LICENSE ");
MODULE_AUTHOR("RANDOM MODULE_AUTHOR");
MODULE_DESCRIPTION("HELLO WORLD MODULE");

static int __init hello_init(void)
{
	printk(KERN_INFO "Hey This is New Kernel MODULE\n");
    return 0; 
}
static void __exit hello_cleanup(void)
{
    printk(KERN_INFO "Good Bye.\n");
}
module_init(hello_init);
module_exit(hello_cleanup);