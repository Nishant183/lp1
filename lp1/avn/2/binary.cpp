#include<omp.h>
#include<bits/stdc++.h>
using namespace std;

int binarySearch(int * a, int begin, int end, int item)
{
	if(begin > end)
		return -1;
	int mid = (end+begin)/2;
	if(a[mid] == item)
		return mid;
	if(a[mid] < item)
		return binarySearch(a,mid+1,end,item);
	else 
		return binarySearch(a,begin,mid-1,item);
}

int main()
{
	int n = 99999,item,rs;
	cout<<"enter item = ";
	cin>>item;
	double start, finish;

	int a[n];
	for(int i=0;i<n;i++)
		a[i] = i;

	start = omp_get_wtime();
	rs = binarySearch(a,0,n,item);
	finish = omp_get_wtime();
	
	cout<<"\nSerial Finished "<<rs;
	cout<<"\nExecution time = "<<finish - start<<'\n';
	
	start = omp_get_wtime();
	#pragma omp parallel reduction(max:rs)
	{
		#pragma omp task
		rs = binarySearch(a,0,n/2,item);
		rs = binarySearch(a,(n/2)+1,n,item);
	}
	finish = omp_get_wtime();
	
	cout<<"\nParallel Finished "<<rs;
	cout<<"\nExecution Time = "<<finish - start<<'\n';
	
	return 0;
}

