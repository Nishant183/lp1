#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include<omp.h>
#define N 4

	int A[N][N], B[N][N], C[N][N]; 
int main ()
{

	int i, j, m; 
	int t_1;
	
	 clock_t c_1, c_2;
	
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			A[i][j]= (rand()%5);
			B[i][j]= (rand()%5);
		}
	}

	printf("Matrix A:\n"); 
	
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			printf("%d\t",A[i][j]);
		}
	
		printf("\n");
	}

 	printf("Matrix B:\n"); 
 
 	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			printf("%d\t",B[i][j]);
		}
	
		printf("\n");
	}
	
	c_1=clock(); 



	printf("Max number of threads: %i \n",omp_get_max_threads()); 

	#pragma omp parallel
	#pragma omp single
	{
		printf("Number of threads: %i \n",omp_get_num_threads());
	}

	#pragma omp parallel for private(m,j)
	#pragma omp_set_num_threads(8) 
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{

			C[i][j]=0; 
			for(m=0;m<N;m++)
			{	
				C[i][j]=A[i][m]*B[m][j]+C[i][j];
			}
	
			printf("C: %d \t",C[i][j]);
		}
		
		printf("\n");
	}
	printf("Matrix C:\n"); 
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			printf("%d\t",C[i][j]);
		}
		
		printf("\n");
	}

	c_2=clock(); 
	t_1 = (int)(c_2-c_1)/CLOCKS_PER_SEC; 
	printf("Execution time: %d(in seconds) \n",t_1); 
	
		
	return 0;
}
