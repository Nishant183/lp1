#include<iostream>
#include<cstdlib>
#include<omp.h>
using namespace std;
int main()
{
	int m=3,n=2;
	int mat[m][n],vec[n],out[m];

	for(int row=0;row<m;row++)
	{
		for(int col=0;col<n;col++)
		{ 		
			mat[row][col]=1;
		}
	}

	cout<<"\n Matrix: "<<endl;
	
	for(int row=0;row<m;row++)
	{
		for(int col=0;col<n;col++)
		{ 
			cout<<"\t"<<mat[row][col];
		}
		
		cout<<""<<endl;
	}

	
	for(int row=0;row<n;row++)
	{
		vec[row]=2;
	}


	cout<<"\n Vector: ";
	for(int row=0;row<n;row++)
	{
		cout<<vec[row]<<" ";
	}

	#pragma omp parallel
	{
		#pragma omp parallel for
		for(int row=0;row<m;row++)
		{
			out[row]=0;
			for(int col=0;col<n;col++)
			{
	
				out[row]+=mat[row][col]*vec[col];
				int count=out[row];
				
			}	
		}
	}
	
	cout<<"\n Resultant Vector :";
	for(int row=0;row<m;row++)
	{
		cout<<out[row]<<" ";
		
	}
	
	cout<<"\n";


	return 0;
}
