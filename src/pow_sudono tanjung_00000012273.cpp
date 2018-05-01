#include <iostream>
#include <iomanip>
using namespace std;

float pow(double base, int exp);
int main(){
	double base;
	int exp;
	cout << "base : ";
	cin >> base;
	cout <<"exp : ";
	cin >> exp;
	cout << fixed << setprecision(0) << pow(base,exp) << endl;
	return 0;
}

float pow(double base, int exp){
	float hasil=base;
	for (int i=1; exp>i; i++){
		hasil*=base;
	}
	return hasil;
}
