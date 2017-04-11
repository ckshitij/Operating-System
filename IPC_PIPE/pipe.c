#include <stdio.h>
#include <unistd.h>
#include <string.h>
#define mem(ar) memset((ar),'\0',sizeof((ar)))
#define B_SZ 10000

int main()
{
	int fdc_p[2],fdp_c[2],data,tot_byt;
	size_t id;
	char buff_p[100],buff_c[B_SZ];
	mem(buff_p);mem(buff_c);
	FILE *fp;
	if(pipe(fdc_p) == -1)
		printf("\n fdc_p is not created\n");
	if(pipe(fdp_c) == -1)
		printf("\n fdp_c is not created\n");
	id =  fork() ;
	if(id)
	{
		printf("\n Parent sending name of file \n ");
		data = write(fdp_c[1],"pipe.c",strlen("pipe.c"));
		printf("\n Parent Wrote %d bytes \n" , data);
		sleep(4);
		data = read(fdc_p[0],buff_c,sizeof(buff_c));
		printf("\n Parent Read %d bytes and file content \n %s ",data,buff_c);
	}
	else
	{
		sleep(2);
		data = read(fdp_c[0],buff_p,sizeof(buff_p));
		printf("\n Child Read %d bytes and file name is %s \n",data,buff_p);
		
		fp = fopen(buff_p,"r");
		fseek(fp,0L,SEEK_END);
		tot_byt = ftell(fp);
		fseek(fp,0L,SEEK_SET);
		if(fp != NULL)
		{
			printf("\n Child Reading the data\n");
			fread(buff_c,sizeof(char),tot_byt,fp);
			fclose(fp);
			printf("\n Child Sending File data \n");
			data = write(fdc_p[1],buff_c,strlen(buff_c));
			printf("\n Child Wrote %d bytes \n",data);
		}
		else
			printf("\n File cannot Open\n");
	}
	return 0;
}
