#include "temperaturclass.h"
#include <iostream>
using namespace std;

int main(){
	Temperatur* data=new Temperatur(20,Temperatur::CELCIUS);
	cout << data->Temperatur::getFahrenheit();
	return 0;
}
