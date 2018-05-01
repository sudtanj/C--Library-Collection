#include<iostream>
using namespace std;
int main()
{
	int a,b;
	cin>>a;cin>>b;
	if(a==1)
	{
		for(int i=1;i<=b;i++)
		{
			for(int j=1;j<=b;j++)
			{
				cout<<"*";
			}
			cout<<endl;
		}
	}
		else if(a==2)
	{
		for(int i=1;i<=b;i++)
		{
			for(int j=1;j<=i;j++)
			{
				cout<<"*";
			}
			cout<<endl;
		}
	}
		else if(a==3)
	{
		for(int i=b;i>=1;i--)
		{
			for(int j=i;j>=1;j--)
			{
				cout<<"*";
			}
			cout<<endl;
		}
}
		else if(a==4)
	{
		for(int i=1;i<=b;i++)
		{
			for(int k=b-i;k>=1;k--)
			{
				cout<<" ";
			}
			for(int j=1;j<=i;j++)
			{
				cout<<"**";
			}
			cout<<endl;
		}
	}
else if(a==5)
	{
		for(int i=1;i<=b;i++)
		{
			for(int k=b-i;k>=1;k--)
			{
				cout<<" ";
			}
			for(int j=1;j<=i;j++)
			{
				cout<<"**";
			}
			cout<<endl;
		}
		for(int l=1;l<=b;l++)
		{
			for(int m=1;m<=l-1;m++)
			{
				cout<<" ";
			}
			for(int n=b;n>=l;n--)
			{
				cout<<"**";
			}
			cout<<endl;
		
	}
}
	return 0;
}
