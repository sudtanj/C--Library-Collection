#include <iostream>
using namespace std;

bool ganjil_genap(int input);
int prima_komposit(int input);

int main(){
	int input;
	cin >> input;
	if (ganjil_genap(input)==1){
		cout << "Ganjil" << endl;
	}
	else {
		cout << "Genap" << endl;
	}
	if (prima_komposit(input)==1){
		cout << "bukan prima" << endl;
	}
	else {
		cout << "prima" << endl;
	}
	
	return 0;
}

bool ganjil_genap(int input){
	if (input%2==0){
		return 0;
	}
	else {
		return 1;
	}
}

int prima_komposit(int input){
	bool a=0;
	for (int i=2; i<input; i++){
		if (input%i==0){
			a=1;
		}
	}
	return a;
}


