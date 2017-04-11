#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#define cin(n) scanf("%d",&(n))

void bubblesort(int ar[],int n)
{
	int temp;
	for(int i = 0 ; i < n ; i++)
	{
		for(int j = 0 ; j < n - 1 - i ; j++)
		{
			if(ar[j] > ar[j+1])
			{
				temp = ar[j];
				ar[j] = ar[j+1];
				ar[j+1] = temp;
			}
		}
	}
}

int main()
{
	int val,n;
	char *str[20],buff[20];
	
	printf("\n Please Enter the no. of Element : = ");
	cin(n);
	int *ar = (int *)malloc(n*sizeof(int));
	printf("\n Enter the Elements :\n");
	for(int i = 0 ; i < n ; i++)
		cin(ar[i]);
	bubblesort(ar,n);
	for(int i = 1 ; i < n ; i++)
	{
		snprintf(buff,20,"%d",ar[i]);
		str[i+1] = strdup(buff); 
	}
	str[0] = malloc(9);
	strcpy(str[0],"child");
	str[n+1] = NULL;
	printf("\n String Converted \n");
	int child_id = fork();
	int pid = wait(NULL);
	if(child_id == 0)
	{
		printf("\nThe Process with process id %d and process parent id is %d \n",getpid(),getppid());
		execv("./child",str);
		
		_exit(0);	
	}
	else
	{
		printf("\nThe Process with process id %d and process parent id is %d \n",getpid(),getppid());
		printf("\n The Sorted Array Using Bubble Sort:\n");
		for(int i = 0 ; i < n ; i++)
			printf("%d ",ar[i]);
		printf("\n");
	}
	return 0;
}
