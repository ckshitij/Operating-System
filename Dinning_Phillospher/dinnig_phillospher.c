#include<stdio.h>
#include<semaphore.h>
#include<sys/types.h>
#include<pthread.h>
#include<unistd.h>

sem_t room;
sem_t p[5];

void *dinning(void *arg)
{
	int x = (int) arg;
	printf("\n Phillospher %d is thinking",x+1);
	sleep(5);
	printf("\n Phillospher %d is hungry",x+1);
	sem_wait(&room);
	printf("\n Phillospher %d is Entering in room",x+1);
	int right = x;
	int left = (4+x) % 5;
	sem_wait(&p[left]);
	sleep(5);
	sem_wait(&p[right]);
	printf("\n phillospher is eating \n",x+1);
	sem_post(&p[right]);
	sem_post(&p[left]);
	printf("\n %d phip fin eat and left the room\n",x+1);
	sem_post(&room);
}


int main()
{
	
	sem_init(&room,0,4);
	for(int i = 0 ; i < 5 ; i++)
		sem_init(&p[i],0,1);
	pthread_t tid[5];
	for(int i = 0 ; i < 5 ; i++)
	{
		pthread_create(&tid[i],NULL,dinning,(void*)i);
		sleep(1);
	}
	for(int i = 0 ; i < 5 ; i++)
		pthread_join(tid[i],NULL);
	printf("\nProblem End \n");
	return 0;
}
