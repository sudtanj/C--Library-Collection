#include<iostream>
#include<cstdlib>
#include<string>
#include<time.h>
using namespace std;
int main()
{
string s, t;
int d1,d2,p1,p2,a,m=0;
p1=p2=0;
cout<<"Snake & Ladder simulation"<<endl
    <<"P1: Human"<<endl
    <<"P2: Computer"<<endl;
while(p1<31&&p2<31)
{
	if(m==0)s="P1";
	else s="P2";
	cout<<s<<" Move"<<endl;
	cout<<"Press r to roll dice: ";cin>>t;
	if(t=="r")
	{
		a=time(NULL);
		srand((unsigned)a);
		d1=rand()%6+1;
		d2=rand()%6+1;
		cout<<d1<<" "<<d2<<endl;
		if(s=="P1")
		{
			p1=p1+d1+d2;
			cout<<"P1 Position: "<<p1<<endl;
			if(p1%5==0)
			{
				p1-=2;
				cout<<"You got down move -2"<<endl
		    		<<"P1 Position: "<<p1<<endl;
			}
			else if(p1%2==0)
			{
				p1+=1;
				cout<<"You got up move +1"<<endl
			    	<<"P1 Position: "<<p1<<endl;
			}
			m=1;
			cout<<endl;	
		}
		else if(s=="P2")
		{
			p2=p2+d1+d2;
			cout<<"P2 Position: "<<p2<<endl;
			if(p2%5==0)
			{
				p2-=2;
				cout<<"You got down move -2"<<endl
		    		<<"P2 Position: "<<p2<<endl;
			}
			else if(p2%2==0)
			{
				p2+=1;
				cout<<"You got up move +1"<<endl
			    	<<"P2 Position: "<<p2<<endl;
			}
			m=0;
			cout<<endl;	
		}	
	}
}
if(p1>30)cout<<"P1 Wins!";
else cout<<"P2 Wins!";

return 0;
}

