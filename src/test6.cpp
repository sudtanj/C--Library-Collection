#include <iostream>
using namespace std;

int main(){
	int jumlah,besar=0,input,kecil,average;
	cin >> jumlah;
	for (int i=0; jumlah>i; i++){
		cin >>input;
		if (input>besar){
			besar=input;
		}
		if (input<kecil){
			kecil=input;
		}
		if (i==0){
		average=input;
		}
		else {
			average=average+input;
		}
	}
	cout << besar << endl;
	cout << kecil << endl;
	cout << average/jumlah << endl;
}
