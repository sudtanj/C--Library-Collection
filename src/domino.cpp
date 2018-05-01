#include <iostream>
using namespace std;

int main(){
	int kasus,jumlah,jatuhmaks=0,jatuh;
	cin >> kasus;
	for (int i=0; i<kasus; i++){
		cin >> jumlah;
		int domino[(2*jumlah)-1];
		for (int j=0; j<jumlah; j++)
			cin >> domino[j];
		for (int j=0;j<jumlah;j++)
			domino[j+jumlah]=domino[j];
		for (int j=0; j<jumlah; j++){
			jatuh=1;
			for (int a=j;a<2*jumlah;a++){
				(domino[a]>domino[a+1])? jatuh++ : a=2*jumlah;
			}
			if (jatuh>jatuhmaks) jatuhmaks=jatuh;
		}
		cout << "Kasus #" << i+1 << ": " << jatuhmaks << endl;
	}
	return 0;
}
