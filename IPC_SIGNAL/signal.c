#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/wait.h>

int n_child;

void handler(int signum)
{
	int status,pid;
	pid = wait(&status);
	printf("The Child Process : %d exited value : %d \n" , pid ,WEXITSTATUS(status));
	n_child--;
}

int main()
{
	int i,cid;
	signal(SIGCHLD,handler);
	for(i = 0 ; i < 3 ; i++)
	{
		if((cid = fork()) == 0)
		{
			sleep(i);
			printf("Child %d with  parent id is %d and process id is %d ;\n",i+1,getppid(),getpid());
			exit(i+1);
		}
		else
			n_child++;
	}
	while(n_child != 0)
	{
		sleep(5);
	}
	return 0;
}
