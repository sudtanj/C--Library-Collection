#include<iostream>
using namespace std;
int main()
{
	char a[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	char b;
	int x,y;
	for(int i=0;i<26;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
	cin>>x>>y;
	b=a[x];
	a[x]=a[y];
	a[y]=b;
	for(int i=0;i<26;i++)
	{
		cout<<a[i]<<" ";
	}
		
}


