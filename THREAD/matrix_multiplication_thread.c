#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#define cin(n) scanf("%d",&(n))
#define SZ 100
#define endl printf("\n")

int A_mat[SZ][SZ],B_mat[SZ][SZ],C_mat[SZ][SZ];
int a,b,c,d;

typedef struct mat
{
	int i,j;
	int count;
}mat;


void *multiply(void *param)/* the thread */
{
   mat *data = param; // the structure that holds our data
   printf("\n thread %d is created\n",data->count);
   sleep(10);
   printf("\n thread %d is multiplying row %d with column %d\n",data->count,data->i,data->j);
   int *arr = (int*)malloc( c * sizeof(int) );
   for(int n = 0 ; n < c ; n++)
   {
      arr[n]= A_mat[data->i][n] * B_mat[n][data->j];
   }
   pthread_exit(arr);
   
}


void input(int ar[][SZ] ,int m ,int n)
{
	printf("Enter the %d elements : \n" , m*n );
	for(int i = 0 ; i < m ; i++)
	{
		for(int j = 0 ; j < n ; j++)
		{
			cin(ar[i][j]);
		}
	}
}

void display(int ar[][SZ] ,int m ,int n)
{
	printf("The matrix Is :\n");
	for(int i = 0 ; i < m ; i++)
	{
		for(int j = 0 ; j < n ; j++)
		{
			printf("%d ",ar[i][j]);
		}endl;
	}
}


int main()
{
	int i,j,k;
	printf("Enter the dimension of matrix 1 : \n");
	cin(a);cin(b);
	input(A_mat,a,b);
	
	printf("Enter the dimension of matrix 2 : \n");
	cin(c);cin(d);
	if(b != c) printf("wrong dimension of matrix 2");
	else
		input(B_mat,c,d);	
	
	display(A_mat,a,b);
	display(B_mat,c,d);
	
	int size = a*d,*ar,count = 0 ;
	pthread_t tid[size];
		
	for(i = 0 ; i < a ; i++)
	{
		for(j = 0 ; j < d ; j++)
		{
			mat *mthread = (mat *)malloc(sizeof(mat));
			mthread->i = i ; mthread->j = j ; mthread->count = ++count;
			pthread_create(&tid[count],NULL,multiply,mthread);
			sleep(1);
		}
	}
	
	for(i = 0 ; i < a ; i++)
	{
		for(j = 0 ; j < d ; j++)
		{
			if(count >= 0)
			{
				pthread_join(tid[count],(void*)&ar);
				int sum=0;
				for(k = 0 ; k < c ; k++)
				 		sum += ar[k];
				C_mat[i][j] = sum;
				count--;
			}
		}
	}
	printf("\n_______________________________\n");
	display(C_mat,a,d);	
	return 0;
}