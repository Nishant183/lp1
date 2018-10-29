#include<omp.h>
#include<iostream>
using namespace std;

int main()
{
		int temp=0;
		int n;
		
		cout<<"\n Enter number of Elements:";
		cin>>n;
		
		int a[n];
		
		cout<<"\n Enter the numbers:";
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			
		}//for
		
		int	changes = 1;
    	int nr = 0;
		
		 while(changes)
    	{
   			 #pragma omp parallel private(temp)
    		{
            	nr++;
            	changes = 0;
            	#pragma omp for \
                    reduction(+:changes)
            	for(int i = 0; i < n - 1; i = i + 2)
            	{
                    if(a[i] > a[i+1] )
                    {
                            temp = a[i];
                            a[i] = a[i+1];
                            a[i+1] = temp;
                            ++changes;
                    }
            	}
            #pragma omp for \
                    reduction(+:changes)
            	for(int i = 1; i < n - 1; i = i + 2)
            	{
                    if( a[i] > a[i+1] )
                    {
                            temp = a[i];
                            a[i] = a[i+1];
                            a[i+1] = temp;
                            ++changes;
                    }
            	}
    		}//pragma
		}
		
		cout<<"\nSorted array :";
		for(int i=0;i<n;i++)
		{
			cout<<a[i]<<" ";
			
		}//for
		
		return 0;
}

/*output

Enter number of Elements:5

Enter the numbers:12 10 8 500 65   

Sorted array :8 10 12 65 500 

*/
