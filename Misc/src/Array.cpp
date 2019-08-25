#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<=n-1;i++)
	{
		a[i]=i;
	}
	int b,c;
	for(int i=0;i<=n-1;i++)
	{
		cout<<a[i]<<" ";
	}	
	cout<<endl;
	cin>>b>>c;
	a[b]=c;
	a[c]=b;
	for(int i=0;i<=n-1;i++)
	{
		cout<<a[i]<<" ";
	}
	return 0;
}
