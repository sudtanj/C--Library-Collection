#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<time.h>
using namespace std;
void MERGING(int b[], int L[], int nL ,int R[], int nR)
{
	//cout<<"MERGING";
	int i,j,k;
	i=j=k=0;
	while(i<nL&j<nR)
	{
		if(L[i]<R[j])
		{
			b[k]=L[i];
			k++;
			i++;
		}
		else
		{
			b[k]=R[j];
			k++;
			j++;
		}
	}
	while(i<nL)
	{
		b[k]=L[i];
		k++;
		i++;
	}
	while(j<nR)
	{
		b[k]=R[j];
		k++;
		j++;
	}
}
void mergesort(int a[],int n)
{
	//cout<<"mergesort"<<endl;
	//cout<<n;
	if(n<2)return;
	int m=n/2;
	int l[m], r[n-m];
	for(int i=0;i<m;i++)l[i]=a[i];
	for(int i=m;i<n;i++)r[i-m]=a[i];
	mergesort(l,m);
	mergesort(r,n-m);
	MERGING(a,l,m,r,n-m);	
}
int main()
{
	int t=time(NULL);
	srand(t);
	int bil[10], n;
	cout<<"Before: ";
	for(int i=0;i<10;i++)
	{
		bil[i]=rand()%100+1;
		cout<<bil[i]<<" ";
	}
	mergesort(bil,10);
	cout<<endl<<endl;
	cout<<"After : ";
	for(int i=0;i<10;i++)cout<<bil[i]<<" ";
	
}
	
