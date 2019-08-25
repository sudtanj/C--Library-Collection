#include<iostream>
#include<time.h>
#include<cstdlib>
#include<string>
using namespace std;
int main()
{
	int s,a,b;
	string t="y";
	do
	{
		s=time(NULL);
		srand((unsigned)a);
		a=rand()%15+1;
		cout<<"Guess a Number: ";cin>>b;
		for(int i=1;i<=2;)
			{
				if(b<a)
				{
					i++;
					cout<<"Too low. Try again: "<<endl;
		            cin>>b;
					
				}
				else if(b>a)
				{
					i++;
					cout<<"Too high. Try again: "<<endl;
					cin>>b;
					
				}
				
				else
				{
					cout<<"The Player wins!"<<endl;
					i=3;
				}
				
			}
	if(b!=a)
	{
		cout<<"The Player lost. The correct number is "<<a<<endl;
	}
	else
	{
		cout<<"The Player wins!"<<endl;
	}
	cout<<"Try again? Type 'y': ";cin>>t;
	}
	while(t=="y");
	return 0;	
}
