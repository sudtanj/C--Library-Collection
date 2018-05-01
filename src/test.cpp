#include <iostream>
#include <string.h>
using namespace std;

int main(){
	int jumlahkasus,search,banyak=0;
	cin>> jumlahkasus;
	int input[jumlahkasus],lokasi[jumlahkasus];
	memset(lokasi,0,sizeof(lokasi));
	for (int i=0;jumlahkasus>i;i++){
		cin >> input[i];
	} 
	cin >> search;
	for (int i=0; jumlahkasus>i;i++){
		if (input[i]==search){
			cout << i+1 << " ";
			banyak=banyak+1;
		}
	}
	cout << banyak;
	
	cout << endl << "---------------------------------" << endl;
	cout << ">" << search <<" :";
	for (int i=0; jumlahkasus>i; i++){
		if (input[i]>search){
			cout << input[i] << " ";
		}
	}
	cout << endl << "<"<< search <<" :";
	for (int i=0; jumlahkasus>i; i++){
		if (input[i]<search){
			cout << input[i] << " ";
		}
	}	
	cout << endl << "===================================" << endl << "Prima : ";
	for (int i=0; jumlahkasus>i; i++){
		for (int a=2; input[i]>a; a++){
			if (input[i]%a==0){
				lokasi[i]=1;
			}
		}
	}
	for (int i=0; jumlahkasus>i; i++){	
		if (lokasi[i]==0){
			cout << input[i] << " ";
		}
	}
	cout << endl << "===================================" << endl; 
	return 0;
}
