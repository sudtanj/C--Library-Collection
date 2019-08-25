#include<iostream>
using namespace std;
int main()
{
	int a[15]; 
	float b,c=0,d=0;
	for(int i=0;i<15;i++)
	{
		cin>>a[i];
		b+=a[i];
	}
	cout<<b<<endl;
	cout<<b/15.0<<endl;
	for(int i=0;i<15;i++)
	{
		if(a[i]<b/15)c++;
	}
	cout<<c<<endl;
	for(int i=0;i<15;i++)
	{
		if(a[i]>b/15)d++;
	}
	cout<<d<<endl;
return 0;
}
