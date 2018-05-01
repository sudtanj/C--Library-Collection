#include<iostream>
#include<time.h>
#include<cstdlib>
using namespace std;

int main()
{
	
	int a,matrix[10][10],sinput,count;
	a=time(NULL);
	srand((unsigned)a);
	cin>>sinput;
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
		{
			matrix[i][j]=rand()%100+1;
			if(sinput==matrix[i][j])
			{
			count++;
			cout<<"Baris "<<i<<"Kolom "<<j<<endl;
			break;
			}
		}
	}
  if(count==0)
   cout<<"Not found";
 	return 0;
}
