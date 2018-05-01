#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int a,b,c,d,e;
	cin>>a;
	b=a;
	c=d=1;
	e=a-4;
	
	if(a>4&&a%2==1)
	{
		for(int i=1;i<=a;i++)
		{
			for(int k=a;k>=i;k--)
			{
				cout<<" ";
			}
			if(i==1)cout<<"*";
			else if(i<a/2+1)
			{
				cout<<"*";
				for(int l=1;l<=c;l++)
				{
					cout<<" ";
				}
				
				cout<<"*";
				c+=2;
				}
			else if(i==a/2+1)
			{
				for(int j=1;j<=a;j++)cout<<"*";
				
			}
			else if(i<a)
			{
				cout<<"*";
				for(int l=1;l<=d;l++)
				{
					cout<<" ";
			    }
				cout<<"*";
				for(int l=1;l<=e;l++)
				{
					cout<<" ";
			    }
				cout<<"*";
				for(int l=1;l<=d;l++)
				{
					cout<<" ";
			    }
				cout<<"*";
			d+=2;
			e-=2;
			}
			else if(i==a)
			{
				for(int j=1;j<=a*2-1;j++)cout<<"*";
			}
			b=b-1;				
			cout<<endl;
		}
	}
	return 0;
}
