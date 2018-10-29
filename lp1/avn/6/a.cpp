#include<iostream>
using namespace std;
int main()
{
int n,last,t,fir,k,sum,sum1=0,ind=1;
cout<<"\nEnter the number of nodes: ";
cin>>n;
int a[n][n];
int b[n],c[n];
for(int i=1;i<=n;i++)
{
for(int j=1;j<=n;j++)
{
if(i!=j){
cout<<"\nEnter the weight from node "<<i<<" to node "<<j<<" :";
cin>>a[i][j];}
if(i==j)
a[i][j]=0;
}
}
cout<<"\n Enter the starting node :";
cin>>fir;
cout<<"\n Enter the last node :";
cin>>last;

for(int i=1;i<=n;i++)
{
if(i!=last)
{
cout<<"\n Enter the heuristic value of node "<<i<<" :";
cin>>b[i];
}
}
b[last]=0;

c[0]=fir;

int s=fir;
while(s!=last)
{
	k=100;
	t=0;
	for(int j=fir;j<=n;j++)
	{
		sum=0;
		if(a[s][j]!=0)
{
			sum=a[s][j]+b[j];

		if(sum<k)
		{
			k=sum;
			t=j;
			
		}
}
	}
	sum1=sum1+a[s][t];
	c[ind]=t;
	ind++;
	s=t;
}
for(int i=0;i<ind;i++)
{
if(i<(ind-1))
cout<<c[i]<<"-";
else
cout<<c[i];
}
cout<<"\n Distance is : "<<sum1;
}
