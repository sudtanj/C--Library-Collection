#include<iostream>
using namespace std;
int main()
{
	int a,b,c=0;
	cin>>a;
	for(int i=5;i<=a;i*=5)c+=(a/i);
	cout<<c;
}
