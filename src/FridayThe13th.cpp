#include<iostream>
using namespace std;
int main()
{
	int a[146400],jumlahhari[7],b=0,c=0,n;
	cin>>n;
	for(int i=0;i<n*366;i++)
	{
		a[i]=i%7+2;
		if(a[i]==7)a[i]=0;
		else if(a[i]==8)a[i]=1;
		//cout<<a[i]<<" ";
	}
	for(int i=0;i<=6;i++)
   	{
   		jumlahhari[i]=0;
   	}

	for(int y=1900;y<1900+n;y++)
	{
		for(int m=1;m<=12;m++)
		{
			if(m==4||m==6||m==9||m==11)b=30;
			else if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)b=31;
			else if(m==2&&y%4!=0)b=28;
			else if(m==2&&y%100==0)b=28;
			else b=29;
			for(int d=1;d<=b;d++)
			{
				if(d==13)
				{
					jumlahhari[a[c]]++;
				}
				c++;
			}
		}
	}
	
	for(int i=0;i<=6;i++)
   	{
   		cout<<jumlahhari[i]<<" ";
   	}
	return 0;
}
