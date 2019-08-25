/*
Name 	: Sudono Tanjung
NIM 	: 00000012273
*/

#include <iostream>
#include <string.h>
#include <cmath>
using namespace std;

int main(){
	int kasus,laki,perempuan;
		cin >> kasus;
	int hasilkasus[kasus],lokasilaki[kasus],lokasiperempuan[kasus];
	memset(hasilkasus,0,sizeof(hasilkasus));
	memset(lokasilaki,0,sizeof(lokasilaki));
	memset(lokasiperempuan,0,sizeof(lokasiperempuan));
		for (int i=0; kasus>i; i++){
			cin >> laki >> perempuan;
	int kualitaslaki[laki],kualitasperempuan[perempuan];
	memset(kualitaslaki,0,sizeof(kualitaslaki));
	memset(kualitasperempuan,0,sizeof(kualitasperempuan));
				for (int l=0; laki>l; l++){
					cin >> kualitaslaki[l];
				}
				for (int p=0; perempuan>p; p++){
					cin >> kualitasperempuan[p];
				}
					hasilkasus[i]=abs(kualitasperempuan[0]-kualitaslaki[0]);
					lokasilaki[i]=kualitaslaki[0];
					lokasiperempuan[i]=kualitasperempuan[0];
	 					for (int a=0; perempuan>a; a++){
							for (int b=0; laki>b; b++){
								if (hasilkasus[i]>abs(kualitasperempuan[a]-kualitaslaki[b])){
									hasilkasus[i]=abs(kualitasperempuan[a]-kualitaslaki[b]);
									lokasilaki[i]=kualitaslaki[b];
									lokasiperempuan[i]=kualitasperempuan[a];
								}
							}
						}
		}
		for (int i=0; kasus>i; i++){
			cout << "Kasus #" << i+1 << ": " << lokasilaki[i] << " " << lokasiperempuan[i] << " " << hasilkasus[i] << endl;
		}
		
	return 0;
}
