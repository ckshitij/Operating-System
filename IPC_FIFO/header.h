#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>

#define server_fifo_name "/tmp/ser_fifo"
#define client_fifo_name "/tmp/clt_fifo"
#define __size 10000

typedef struct Exchange_data
{
	pid_t pid;
	char data[__size];
	
}Exchange_data;
