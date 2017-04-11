#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
int h,m,s;

void *hr_update(void *arg)
{
	while(1)
	{
		if(m==60)
		{
			h++;
			m=0;
		}
		if(h==12)
		h=0;
	}
	pthread_exit("NULL");
}
void *min_update(void *arg)
{
	while(1)
	{
		if(m==59)
			if(s==60)
				m=0;
	}
	pthread_exit("NULL");
}
void *sec_update(void *arg)
{
	while(1)
	{
		system("clear");
		printf("\ncurrent time is %d:%d:%d",h,m,s);
		s++;
		if(s==60)
		{
			s=0;
			m++;
		}
		sleep(1);
	}
	pthread_exit("NULL");
}

int main()
{
	int i,j,k;
	pthread_t hr,min,sec;
	printf("\nEnter time in hh:mm:ss format");
	scanf("%d%d%d",&h,&m,&s);
	pthread_create(&hr,NULL,hr_update,NULL);
	pthread_create(&min,NULL,min_update,NULL);
	pthread_create(&sec,NULL,sec_update,NULL);

	pthread_join(hr,NULL);
	pthread_join(min,NULL);
	pthread_join(sec,NULL);
	return 0;
}
