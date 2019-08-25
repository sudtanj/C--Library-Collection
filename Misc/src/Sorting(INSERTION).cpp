#include<iostream>
#include<algorithm>
#include<time.h>
#include<cstdlib>
using namespace std;
void insertionsort(int a[],int n)
{
	int temp, j;
	for(int i=1;i<n;i++)
	{
		temp=a[i];
		j=i-1;
		while(j>=0&&a[j]>temp)
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=temp;
	}
}
int main()
{
	int bil[10];
	int t=time(NULL);
	srand((unsigned)t);
	for(int i=0;i<10;i++)
	{
		bil[i]=rand()%100+1;
		cout<<bil[i]<<" ";
	}
	cout<<endl<<endl;
	insertionsort(bil,10);
	for(int i=0;i<10;i++)cout<<bil[i]<<" ";
}
