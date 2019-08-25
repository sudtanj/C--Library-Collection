#include <iostream>
#define EQ ==
using namespace std;

int main()
{
	//VARIABEL
	double x,y,p;
	double jenistari, jumlahbaris;
	cout << "MASUKKAN JENIS TARI:" << endl << "1. Tari Kotak" << endl << "2. Tari Tambah" << endl << "3. Tari Kurang" 
	<< endl << "4. Tari Segitiga" << endl <<"5. Tari Diamond" << endl;
	cin >> jenistari;
	cout << "MASUKKAN JUMLAH BARIS" << endl;
	cin >> jumlahbaris;

	if (jenistari<2 and jenistari>0)
	{
		for (x=0;x<jumlahbaris;x++)
		{
			for(y=0;y<jumlahbaris;y++)
			{
				cout << "*";
			}
			cout << endl;
		}
	}
	
	if (jenistari<3 and jenistari>1)
	{
		p=1;
		for (x=0;x<jumlahbaris;x++)
		{
			// Pengulangan
			for(y=0;y<p;y++)
			{
				cout << "*";
			}
			p=p+1;
			cout << endl;
		}
	}
	
	if (jenistari<4 and jenistari>2)
	{
		p=jumlahbaris;
		for (x=0;x<jumlahbaris;x++)
		{
			// Pengulangan
			for(y=0;y<p;y++)
			{
				cout << "*";
			}
			p=p-1;
			cout << endl;
		}
	}
	
	
	
		
	return 0;
	getchar();
}
