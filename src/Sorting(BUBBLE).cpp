#include<iostream>
#include<time.h>
#include<cstdlib>
#include<algorithm>
using namespace std;
void bubblesort(int a[],int n)
{
	bool flag;
	for(int i=0;i<n-1;i++)
	{
		flag=true;
		for(int j=n-1;j>i;j--)
		{
			if(a[j-1]>a[j])
			{
				swap(a[j],a[j-1]);
				flag=false;
			}
		}
		if(flag)break;
	}
}
int main()
{
	int bil[10];
	int t=time(NULL);
	srand((unsigned)t);
	cout<<"Before: ";
	for (int i=0; i<10;i++)
	{
		bil[i]=rand()%100+1;
		cout<<bil[i]<<" ";
	}
	cout<<endl<<endl;
	bubblesort(bil,10);
	cout<<"After: ";
	for (int i=0; i<10;i++)cout<<bil[i]<<" ";
	cout<<endl;	
}
