#include <iostream>
using namespace std;

struct exercise {
	int number;
	bool even_odd=0,prime=0;
}data[5];

int even_odd (int number);
int prime (int number);
int main(){
	struct exercise data[5];
	int kasus;
	cin >> kasus;
	for (int i=0; i<kasus; i++){
		cin>>data[i].number;
		data[i].even_odd=even_odd(data[i].number);
		data[i].prime=prime(data[i].number);
	}
	for (int i=0; i<kasus; i++){
	cout << data[i].number << " ";
	if (data[i].even_odd==1){
		cout << "Even";
	} else {
		cout << "Odd";
	}
	cout << " ";
	if (data[i].number==1){
		cout << "No";
	}
	else {
	if (data[i].prime==1){
		cout << "No";
	}
	else {
		cout << "Yes";
	}
	}
	cout << " " << endl;
	}
	return 0;
}

int even_odd(int number){
	if (number%2==0){
		return 1;
	}
	else {
		return 0;
	}
}

int prime(int number){
	for (int i=2;i<number; i++){
		if (number%i==0){
			return 1;
			break;
		}
	}
	return 0;
}
