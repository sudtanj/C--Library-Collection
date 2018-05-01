/*
Nama kelompok: samuel,sudono,gerry,veri
*/
#include <iostream>
#include <string.h>
using namespace std;

int main(){
	int matriks1[10][10],matriks2[10][10],hasilpenjumlahan[10][10];
	memset(hasilpenjumlahan,0,sizeof(hasilpenjumlahan));
	for (int i=0; 2>i; i++){
		for (int a=0; 3>a; a++){
			cin >> matriks1[i][a];
		}
	}
	for (int i=0; 3>i; i++){
		for (int a=0; 2>a; a++){
			cin >> matriks2[i][a];
		}
	}
	for (int b=0; 2>b; b++){
		for (int c=0; 2>c; c++){
	for (int i=0; 2>i; i++){
		for (int a=0; 3>a; a++){
			hasilpenjumlahan[b][c]=hasilpenjumlahan[b][c]+(matriks1[i][a]*matriks2[a][i]);
		}
	}
}
}
for (int i=0; 2>i; i++){
	for (int a=0; 2>a; a++){
		cout << hasilpenjumlahan[i][a]/2 << " "; 
	}
	cout << endl;
}
	return 0;
}
