#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void swap(int *a,int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int *ar,int start,int end)
{
	int pivot = ar[start];
	int i = start+1;
	for(int j = start+1 ; j <= end ; j++)
	{
		if(pivot > ar[j])
		{
			swap(&ar[i],&ar[j]);
			i++;
		}
	}
	swap(&ar[start],&ar[i-1]);
	return i-1;
}

void quicksort(int *ar,int start,int end)
{
	if(start < end)
	{
		int p = partition(ar,start,end);
		quicksort(ar,start,p-1);
		quicksort(ar,p+1,end);
	}
}



void merge(int *ar,int start,int mid,int end)
{
	int right[100],left[100];
	int m = mid - start +1 ,n = end - mid ;
	for(int i = 0 ; i < m ; i++)
		left[i] = ar[start+i];
	for(int i = 0 ; i < n ; i++)
		right[i] = ar[mid+1+i];
	int i = 0 , j = 0 , k = start;
	while(i < m && j < n)
	{
		if(left[i] < right[j])
			ar[k++] = left[i++];
		else
			ar[k++] = right[j++];
	}
	while(i < m)
		ar[k++] = left[i++];
	while(j < n)
		ar[k++] = right[j++];
}


void merge_sort(int *ar ,int start,int end)
{
	if(start < end)
	{
		int mid = (start+end)/2;
		merge_sort(ar,start,mid);
		merge_sort(ar,mid+1,end);
		merge(ar,start,mid,end);
	}
}


void display(int *ar,int n)
{
	for(int  i = 0 ; i < n ; i++)
	{
		printf("%d ",ar[i]);
	}
	printf("\n");
}

int main()
{
	int pid,ppid;
	int i,j,chd_id;
	int *ar,n;
	printf("\n Enter the no. of element = ");
	scanf("%d",&n);
	ar = (int *)malloc(n*sizeof(int));
	printf("\n Enter the element :\n");
	for(i = 0 ; i < n ; i++)
		scanf("%d",&ar[i]);
	chd_id = fork();
	pid = wait(NULL);
	if(chd_id == 0)
	{
		sleep(5);
		printf("\n This the Child code with id %d and parent id is %d" , getpid(),getppid());
		printf("\n The Sorted array by Quick Sort : \n");
		quicksort(ar,0,n-1);
		display(ar,n);
		system("ps -l");
	}
	else
	{
		sleep(5);
		printf("\n This the Parent code with id %d and parent id is %d" , getpid(),getppid());
		printf("\n The Sorted array by Quick Sort : \n");
		merge_sort(ar,0,n-1);
		display(ar,n);
		system("ps -l");
	}
	return 0;
}




