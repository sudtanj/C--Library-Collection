/*
Name: Frederikus Judianto
NIM: 00000006471
*/
#include<iostream>
using namespace std;
int main()
{
    int n,a[100000],f=0;
    bool zigzag=true;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
    	if(i==n-2)break;
		if(a[i]<a[i+1]&&a[i+1]<a[i+2])
		{
			zigzag=false;
			f=i;
			break;
		}
		else if(a[i]>a[i+1]&&a[i+1]>a[i+2])
		{
			zigzag=false;
			f=i;
			break;
		}
    }
	if(zigzag)cout<<"ZIGZAG";
	else if(!zigzag)cout<<a[f]<<" "<<a[f+1]<<" "<<a[f+2];
    return 0;
}
