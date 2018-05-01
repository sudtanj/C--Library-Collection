#include <iostream>
using namespace std;

int insert(int input[50],int lokasi, int google,int jumlah);

int main(){
	int input[50],lokasi,google;
	for (int i=0; i<5; i++){
		cin >> input[i];
	}
	cin >> lokasi;
	cin >> google;
	input=insert(input, lokasi, google, 5);
	for (int i=0;i<5;i++)
	cout << input[i] << endl;
	return 0;
}

int insert(int input[50], int lokasi,int google,int jumlah){
		for(int i=jumlah;i>lokasi;i--){
			input[i+1]=input[i];
		}
		input[lokasi]=google;
		return (int)input;
}
