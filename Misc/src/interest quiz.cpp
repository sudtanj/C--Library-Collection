//bunga bank
#include<iostream>
using namespace std;

long hitungTabungan(long , int, int , int ,int ,int);

int main()
{
 	long tabungan;
	int bunga,kenaikanBunga,lamaMenabung,bulanKenaikan;
	cin>>tabungan;
	cin>>lamaMenabung;
	cin>>bunga;
	cin>>kenaikanBunga;
	cin>>bulanKenaikan;	
	//kalo counter nya 1 nnti kebanyakan makanya diganti jadi 2
	long tes = hitungTabungan(tabungan, lamaMenabung, bunga, kenaikanBunga,bulanKenaikan, 2);//c nya satu karena mulai ngitungnya dari bulan 1
	cout<<tes<<endl;
return 0;
}

long hitungTabungan(long tabungan, int lamaMenabung, int bunga, int kenaikanBunga,int bulanKenaikan,int counter)
{
	if (lamaMenabung==1)//ini kan bru bulan pertama makanya gak pake bunga
	{
		return tabungan;
	}
	else
	{
		if((counter-1) % bulanKenaikan ==0)
		bunga += kenaikanBunga;
		if(counter == lamaMenabung)//klo gak pake if akan tjd infinite loop
		return tabungan+tabungan*bunga/100;
		
		else 
		counter +=1;
		return hitungTabungan( tabungan + tabungan*bunga/100 ,lamaMenabung, bunga, kenaikanBunga, bulanKenaikan, ++counter );//mestinya ++counter soalnya klo counter++ diplus nya nanti pas udah selesai jalan
	}
}
