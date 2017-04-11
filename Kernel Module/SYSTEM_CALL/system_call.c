#include <linux/kernel.h>

asmlinkage long sys_system_call(void)
{
        printk("Hello world\n");
        return 0;
}