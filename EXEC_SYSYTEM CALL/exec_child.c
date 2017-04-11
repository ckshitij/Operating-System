#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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

int binary_search(int ar[],int start ,int end, int key)
{
	if(start < end)
	{
		int mid = (start+end)/2;
		if(key == ar[mid])
			return mid ;
		else if(key < ar[mid])
			return binary_search(ar,start,mid,key);
		else
			return binary_search(ar,mid+1,end,key);
	}
	if( (key < 0) || (key > end) )
		return -1;
}

int main(int argc , char *argv[])
{
	int ch;
	//scanf("%c",&ch);
	int key,count = 0 ;
	int ar[34];
	for(int i = 0 ; argv[i+1] != NULL ; i++)
	{
			ar[i] = atoi(argv[i+1]);
			count++;
	}	
	
	printf("\n Enter the key to be Searched := ");
	scanf("%d",&key);
	int ans = binary_search(ar,0,count-1,key);
	if(ans == -1)
		printf("\n Key not found ");
	else
		printf("\n element found at position %d\n",ans);
	return 0;
}
