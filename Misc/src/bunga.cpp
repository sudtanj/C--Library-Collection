#include<iostream>
using namespace std;
long hitungTabungan(long, int, int, int, int, int);
int main()
{
	long tabungan;
	int bunga, kenaikanBunga, lamaMenabung, bulanKenaikan;
	
	cin>> tabungan;
	cin>> lamaMenabung;
	cin>> bunga;
	cin>> kenaikanBunga;
	cin>> bulanKenaikan;
	
	cout << hitungTabungan(tabungan, lamaMenabung, bunga, kenaikanBunga,
	bulanKenaikan, 2);
	//cout << tes << endl;
	return 0;
	
}
long hitungTabungan(long tabungan, int lamaMenabung,
int bunga, int kenaikanBunga, int bulanKenaikan, int counter)
{
	if(lamaMenabung == 1)
	{
		return tabungan;
	}
	else
	{
		if((counter-1) % bulanKenaikan == 0)
			bunga += kenaikanBunga;
			if(counter == lamaMenabung)
				return tabungan + tabungan*bunga/100;
			else
			{
				counter += 1;
				return hitungTabungan(tabungan + tabungan*bunga/100,
				lamaMenabung, bunga, kenaikanBunga, bulanKenaikan, counter);
			}
	}
}
