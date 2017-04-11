#include <stdio.h>
#include <semaphore.h>
#include <pthread>
#include <stdlib.h>
#define cin(n) scanf("%d",&(n))

#define BUFF 20

pthread_mutex_t mid[BUFF] ;
pthread_t pid[BUFF],cid[BUFF];
sem_t full,empty;

int counter;
int buffer[BUFF];

void initialize()
{
	pthread_mutex_init(&mutex,NULL);
	sem_init(&full,0,0);
	sem_init(&empty,0,BUFF);
}

int read()
{
	return buffer[--count];
}

void write(int item)
{
	buffer[count++] = item;
}

void *consumer()
{
	int item;
	sem_wait(&full);
	pthread_mutex_lock(&mutex);
	item = read();
	printf("\n The Consumer consumed item : %d",item);
	pthread_mutex_unlock(&mutex);
	sem_post(&empty);
}

void *producer()
{
	int item;
	item = rand() % 5 ;
	sem_wait(&empty);
	pthread_mutex_lock(&mutex);
	printf("\n The Producer produced item : %d",item);
	write(item);
	pthread_mutex_unlock(&mutex);
	sem_post(&full);
}

int main()
{
	int n,m;
	initialize();
	printf("\n Enter the no. of consumer : ");
	cin(n);
	printf("\n Enter the no. of producers : ");
	cin(m);
	for(int i = 0 ; i < m ; i++)
		pthread_create(&pid[i],NULL,producer,NULL);
	for(int i = 0 ; i < n ; i++)
		pthread_create(&pid[i],NULL,consumer,NULL);
	for(int i = 0 ; i < m ; i++)
		pthread_join(pid[i],NULL);
	for(int i = 0 ; i < m ; i++)
		pthread_join(pid[i],NULL);
	return 0;
}









