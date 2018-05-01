#include <iostream>
using namespace std;

int matrix(int a[10][10], int b[10][10], int baris, int kolom);

int main(){
	int baris=0,kolom=0;
	cin >> kolom >> baris;
	int a[10][10],b[10][10];
	for (int i=0; baris>i; i++){
		for (int j=0; kolom>j; j++){
			cin >> a[i][j];
		}
	}
	cout << endl;
	cout << "+" << endl;
	for (int i=0; baris>i; i++){
		for (int j=0; kolom>j; j++){
			cin >> b[i][j];
		}
	}
	matrix(a,b,baris,kolom);
	return 0;
}

int matrix(int a[10][10], int b[10][10], int baris, int kolom){
	int hasil[10][10];
	for (int i=0; baris>i; i++){
		for (int j=0; kolom>j; j++){
			hasil[i][j]=a[i][j]+b[i][j];
		}
	}
	for (int i=0; baris>i; i++){
		for (int j=0; kolom>j; j++){
			cout << hasil[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
