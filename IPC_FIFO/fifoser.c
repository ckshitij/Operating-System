#include "header.h"

int main()
{
	int ser_fd,clt_fd,i=0,j=0,res = 0;
	FILE *temp,*Ser;
	char fil_msg[__size],msg[__size],ch;
	Exchange_data message ;
	mkfifo(server_fifo_name,0777);
	ser_fd = open(server_fifo_name,O_RDONLY);
	
	do
	{
		printf("\nServer is running\n");
		res = read(ser_fd,&message,sizeof(message));
		if(res > 0)
		{

			strcpy(fil_msg,message.data);
			temp = fopen("client_message","w");
			while(fil_msg[i] != '\0')
			{
				fprintf(temp,"%c",fil_msg[i]);
				i++;
			}
			fclose(temp);
			
			temp = fopen("server_output","w");
			system("cat client_message | wc > server_output");
			fclose(temp);
			
			Ser = fopen("server_output","r");
			while((ch = fgetc(Ser)) != EOF)
				msg[j++] = ch;
			msg[j] = '\0';
			fclose(Ser);
			strcpy(message.data,msg);
			
			clt_fd = open(client_fifo_name , O_WRONLY);
			
			if(clt_fd > 0)
			{
				printf("\n The Response send from server to client %s \n",message.data);
				write(clt_fd,&message,sizeof(message));
				res = -1;
			}	
		}
		
	}while(res != -1);
	return 0;
}
