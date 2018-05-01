#include <iostream>
#include <string.h>
using namespace std;

int jumlahbakteri (int awal, int expire);

int main(){
	int kasus,awal,masahidup,standar,expire,totalbakteri;
	cin >> kasus;
	for (int i=0; i<kasus; i++){
		cin >> awal >> masahidup >> standar >> expire;
	int bakteri[jumlahbakteri(awal,expire)];
	int tampung=awal;
	memset(bakteri,0,sizeof(bakteri));
		for (int a=0; a<awal; a++)
		bakteri[a]=1;
		for (int j=1; j<expire; j++){
			tampung=tampung*2;
			awal=awal+tampung;
				for (int a=0; a<awal; a++){
					if (bakteri[a]!=-1){
					bakteri[a]=bakteri[a]+1;
					if (bakteri[a]==masahidup+1) bakteri[a]=-1;
					}
				}
		}
		totalbakteri=0;
		for (int j=0; j<sizeof(bakteri)/4; j++){
			if (bakteri[j]!=-1)
			totalbakteri=totalbakteri+1;
		}
		cout << "Kasus #" << i+1 << ": ";
		if (totalbakteri<standar) cout << "Tidak" << endl; else cout << "Ya" << endl;
	}
	return 0;
}

int jumlahbakteri (int awal, int expire){
	int tampung=awal;
	for (int i=1; i<expire; i++){
		tampung=tampung*2;
		awal=awal+tampung;
	}
	return awal;
}
