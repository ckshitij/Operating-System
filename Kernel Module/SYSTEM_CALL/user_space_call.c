#include <stdio.h>
#include <linux/kernel.h>
#include <sys/syscall.h>
#include <unistd.h>
int main()
{
         long int res = syscall(345); //Replace 345 with your sytem call number
         printf("System call sys_hello returned %ld \n", res);
         return 0;
}