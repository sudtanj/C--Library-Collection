#include<iostream>
#include<time.h>
#include<cstdlib>
#include<algorithm>
using namespace std;
void selectionsort(int bil[],int a)
{
	int idxsmall;
	for(int i=0;i<a-1;i++)
	{
		idxsmall=i;
		for(int j=i+1;j<a;j++)if(bil[idxsmall]>bil[j])idxsmall=j;
		if(idxsmall>i)swap(bil[i],bil[idxsmall]);
	}
}
int main()
{
	int bil[10],t;
	t=time(NULL);
	srand((unsigned)t);
	cout<<"Before: ";
	for(int i=0;i<10;i++)
	{
		bil[i]=rand()%100+1;
		cout<<bil[i]<<" ";
	}
	cout<<endl<<endl<<"After : ";
	selectionsort(bil,10);
	for(int i=0;i<10;i++)
	{
		cout<<bil[i]<<" ";
	}
	return 0;
}
