#include <iostream>
#include <conio.h>
using namespace std;
int even_odd (int isi);
int print_data(int isi);
int main(){
	for (int i=1;i>0;i++){
	int isi;
	cin >> isi;
	cout << isi << " is an ";
	print_data(even_odd(isi));
	cout << " number" << endl;
	cout << "Input another number?(y/n) ";
	if (_getch()=='n'){
		break;
	}
	system("CLS");
	}
	return 0;
}
int even_odd (int isi){
	if (isi%2==1){
		return 1;	
	}
	else {
		return 0;
	}
}
int print_data(int isi){
	switch (isi){
		case 0:
			cout << "even";
			break;
		case 1:
			cout << "odd";
			break;
		default:
			break;
	}
}
