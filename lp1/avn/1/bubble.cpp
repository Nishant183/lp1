#include<bits/stdc++.h>
#include<omp.h>
using namespace std;

int main()
{
	omp_set_dynamic(0);
	omp_set_num_threads(omp_get_num_procs());
	
	int n = 100000, i,j,temp,shift;
	int a[n],b[n];
	for(i=0;i<n;i++)
		a[i] = b[i] = rand()%10000;
	
	double start = omp_get_wtime();
	for(i=1;i<n;i++)
	{
		shift = 0; 
		for(j=0;j<n-i;j++)		
		{
			if(a[j] < a[j+1]) 
			{
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
				shift = 1;
			}
		}
		if(!shift)
			break;
	}
	
	double finish = omp_get_wtime();
	cout<<"Serial Finished "<<a[0];
	cout<<"\nExecution Time = "<<finish - start<<'\n';
	
	start = omp_get_wtime();
	//double finish = omp_get_wtime();
	do
	{
		#pragma omp parallel private(temp,i,j)
		{
			shift = 0;
			#pragma omp for 
			for(j=0;j<n;j+=2)
				if(b[j] < b[j+1]) 
				{
					temp = b[j];
					b[j] = b[j+1];
					b[j+1] = temp;
					shift = 1;
				}
			
			#pragma omp for 
			for(j=1;j<n;j+=2)
				if(b[j] < b[j+1]) 
				{
					temp = b[j];
					b[j] = b[j+1];
					b[j+1] = temp;
					shift = 1;
				} 
		}
	}while(shift);
	finish = omp_get_wtime();
	
	cout<<"Parallel Finished "<<b[0];
	cout<<"\nExecution Time = "<<finish - start<<'\n';
	
	return 0;
}
