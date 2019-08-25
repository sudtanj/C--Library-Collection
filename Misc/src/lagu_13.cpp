/*
Name: Frederikus Judianto
NIM: 00000006471
*/
#include<iostream>
using namespace std;
int main()
{
    int n,a[100000],temp,b;
    bool zigzag=true;
	cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    do
	{
    	zigzag=true;
		for(int i=0;i<n-1;i++)
    	{
    		if(a[i]==a[i+1])
    		{
    			b=i+5;
				if(b>n)b=b%n;
				temp=a[i];
    			a[i]=a[i+5];
    			a[i+5]=temp;
    		}
    	}
		for(int i=0;i<n-2;i++)
    	{
    		if(a[i]<a[i+1]&&a[i+1]<a[i+2])
			{
				zigzag=false;
				temp=a[i];
				a[i]=a[i+1];
				a[i+1]=temp;
			}
			else if(a[i]>a[i+1]&&a[i+1]>a[i+2])
			{
				zigzag=false;
				temp=a[i];
				a[i]=a[i+1];
				a[i+1]=temp;
			}
		}
	}while(!zigzag);
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<endl;
	}
    return 0;
}
