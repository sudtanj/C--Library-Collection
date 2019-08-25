/*
Name 	: Sudono Tanjung
NIM 	: 00000012273
*/

#include <iostream>
#include <string.h>
#include <cstdlib>
using namespace std;

int menu=0;

int main(){
	string input,memorybaris[1000];
	float jumlahline,jumlahkarakter,huruf[1000];
while (menu==0){
	memset(huruf,0,sizeof(huruf));
	cout << "      ==============================================================   " << endl;
	cout << "      |   Mohon mengakhiri pengetikan dengan menggunakan tanda ';' |" << endl;
	cout << "      |                      Terima kasih.                         |" << endl;
	cout << "      ==============================================================   " << endl;
	for (int i=0; input.length()>=0; i++){
	getline(cin,input);
	jumlahline=jumlahline+1;
	if (i==0){
		for (int jumlah=0; jumlah<input.length(); jumlah++){
		if (input[jumlah]==' '){
		}
		else {
			jumlahkarakter=jumlahkarakter+1;
		}
		}
	}
	else {
		for (int jumlah=0; jumlah<input.length(); jumlah++){
		if (input[jumlah]==' '){
		}
		else {
			jumlahkarakter=jumlahkarakter+1;
		}
		}
	}
	memorybaris[i]=input;
		if (input[input.length()-1]==';'){
		break;
		}
	}
	cout << endl;
	cout << "======================================================================" << endl;
	cout << "The input line had " << jumlahline << " lines," << jumlahkarakter-1 << " words," << endl;
	cout << "and the following letter frequencies:" << endl;
	for (int i=0; jumlahline+1>i; i++){
		for (int a=0; memorybaris[i].length()>a; a++){
		huruf[int (memorybaris[i][a])]=huruf[int (memorybaris[i][a])]+1; 
		}
	}
	cout << "  ";
	for (int i=97; 122>=i; i++){
		if ((i-97)%8==0){
			cout << endl;
		}
		cout << char (i) << ": " << huruf[i] << "   ";
	}
	cout << endl;
		cout << "======================================================================" << endl;
	cout << endl << endl;
	cout << "Apakah anda ingin mengetik dokumen yang baru? (Y/N) ";
	char inputmenu;
	cin >> inputmenu;
	if (inputmenu=='N' || inputmenu=='n'){
		system("CLS");
		cout << "Terima kasih telah menggunakan software ini." << endl;
		system("pause");
		exit(0);
	}
	system("CLS");
}
	return 0;
}
