#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int a,b,c,d,e;
	cin>>a;
	b=a;
	c=d=2;
	e=a-3;
	
	if(a>4&&a%2==1)
	{
		for(int i=1;i<=a;i++)
		{
			cout<<setw(b);
			if(i==1)cout<<"*";
			else if(i<a/2+1)
			{
				cout<<"*"<<setw(c)<<"*";
			    c+=2;
			}
			else if(i==a/2+1)
			{
				for(int j=1;j<=a;j++)cout<<"*";
				
			}
			else if(i<a)
			{
				cout<<"*"<<setw(d)<<"*"<<setw(e)<<"*"<<setw(d)<<"*";
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
