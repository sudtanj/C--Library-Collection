#include<iostream>
using namespace std;

	
string cekprima(int x);
int main()
{

	int a;
	cin>>a;
    cout<<cekprima(a);
}
string cekprima(int x)
{
	int b,c=0;
	string s;
	for(b=1;b<=x;b++)
	{
		
		if(x%b==0)
		{
			c++;
		}
	}
		if(c==2)
	{
		s="Prima\n";
	}
	else
	{
		s="Bukan Prima\n";
	}
	return s;
}
