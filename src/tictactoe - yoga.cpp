#include <iostream>
using namespace std;

int main()
{    
int x,y, start=0, turn=0;
int a[3][3];

for(int i=0;i<3;i++)
{for(int j=0;j<3;j++)
         {a[j][i]=0;}
        }
        
for(int i=0;i<3;i++)
{for(int j=0;j<3;j++)
         {cout<< a[j][i];}
        cout<<endl;}
        
        
//start game
while(start==0) //kalo start nya 0 berarti main terus
{
               
//turn  player 1               
if(turn==0)
{    
cout<< "player 1 turn"<<endl;                       
cout<<"masukan x : ";
cin>>x;
cout<<"masukan y : ";
cin>>y;
x-=1;
y-=1;
turn = 1;

if(a[x][y]!=0)
{cout<<"sudah terisi"<<endl;
  turn = 0;}

else if (a[x][y]==0)
{
a[x][y]=1;
}

}

// turn player 2
else if(turn!=0)
{    
cout<<"player 2 turn"<<endl;                          
cout<<"masukan x : ";
cin>>x;
cout<<"masukan y : ";
cin>>y;
x-=1;
y-=1;
turn = 0;

if(a[x][y]!=0)
{cout<<"sudah terisi"<<endl;
  turn = 1;}

else if (a[x][y]==0)
{
a[x][y]=2;
}
}


//display
for(int i=0;i<3;i++)
{for(int j=0;j<3;j++)
         {cout<< a[j][i];}
        cout<<endl;}

//cek pemenang 

//cek kanan
for(int i=0 ; i<3 ; i++)
{
int q = 0;
if(a[q][i]==1 && a[q+1][i]==1 && a[q+2][i]==1)
      {cout<<"player 1 menang"<<endl; 
       start=1;}
       
else if(a[q][i]==2 && a[q+1][i]==2 && a[q+2][i]==2)
      {cout<<"player 1 menang"<<endl; 
       start=1;}
}       
//cek kebawah     
for(int i=0 ; i<3 ; i++)
{
int q = 0;
if(a[i][q]==1 && a[i][q+1]==1 && a[i][q+2]==1)
      {cout<<"player 1 menang"<<endl; 
       start=1;}
       
else if(a[i][q]==2 && a[i][q+1]==2 && a[i][q+2]==2)
      {cout<<"player 1 menang"<<endl; 
       start=1;}
}   

//cek serong kanan
if(a[0][0]==1 && a[1][1]==1 && a[2][2]==1)
{cout<<"player 1 menang"<<endl;
start=1;}
if(a[0][0]==2 && a[1][1]==2 && a[2][2]==2)
{cout<<"player 2 menang"<<endl;
start=1;}

//cek serong kiri
if(a[2][0]==1 && a[1][1]==1 && a[0][2]==1)
{cout<<"player 1 menang"<<endl;
start=1;}
if(a[2][0]==2 && a[1][1]==2 && a[0][2]==2)
{cout<<"player 2 menang"<<endl;
start=1;}


}

//end of game


     system("pause");
     return 0;
   
   
}

