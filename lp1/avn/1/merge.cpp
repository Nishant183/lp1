#include<omp.h>
#include<bits/stdc++.h>
using namespace std;

void merge(int * X, int n, int * tmp) 
{
	int i = 0;
	int j = n/2;
	int ti = 0;

	while (i<n/2 && j<n) 
	{
		if (X[i] < X[j]) 
		{
			tmp[ti] = X[i];
			ti++; i++;
		} else 
		{
			tmp[ti] = X[j];
			ti++; j++;
		}
	}
	while (i<n/2) 
	{ 
		tmp[ti] = X[i];
		ti++; i++;
	}
	while (j<n) 
	{ 
		tmp[ti] = X[j];
		ti++; j++;
	}
	memcpy(X, tmp, n*sizeof(int));
}

void mergesortSer(int * X, int n, int * tmp)
{
	if (n < 2) 
		return;
	mergesortSer(X, n/2, tmp);
	mergesortSer(X+(n/2), n-(n/2), tmp+n/2);
	
	merge(X, n, tmp);
}

void mergesortPar(int * X, int n, int * tmp)
{
	if (n < 16) 
	{
        mergesortSer(X, n, tmp);
        return;
    }
	#pragma omp task firstprivate(X, n, tmp)
	mergesortPar(X, n/2, tmp);
	mergesortPar(X+(n/2), n-(n/2), tmp+n/2);

	#pragma omp taskwait
		merge(X, n, tmp);
}

int main()
{
	int n = 90000;
	double start, finish;

	int a[n],b[n],tmp[n];
	for(int i=0;i<n;i++)
		a[i] = b[i] = rand() % 10000;

	start = omp_get_wtime();
	mergesortSer(a,n,tmp);
	finish = omp_get_wtime();
	
	cout<<"\nSerial Finished "<<a[0];
	cout<<"\nExecution time = "<<finish - start;
	
	memset(tmp,0,sizeof(tmp));
	start = omp_get_wtime();
	#pragma omp parallel
	{
	  #pragma omp single
	  mergesortPar(b, n, tmp);
	}
	finish = omp_get_wtime();
	
	cout<<"\nParallel Finished "<<b[0];
	cout<<"\nExecution Time = "<<finish - start<<'\n';
	
	//for(int i=0;i<n;i++)
		//cout<<a[i]<<" "<<b[i]<<'\n';
	return 0;
}

