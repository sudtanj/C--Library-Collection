#include <iostream>
using namespace std;

class Temperatur{
	public:
		const int CELCIUS=1;
		const int REAMUR=2;
		const int FAHRENHEIT=3;
		const int KELVIN=4;
		Temperatur(double temperatur, int satuan);
		double getFahrenheit();
		double getReamur();
		double getCelcius();
		double getKelvin();
		double getTemperatur();
		double getSatuan();
	private:
		void setSatuan(int satuan);
		void setTemperatur(double temperatur);
		int satuan;
		double temperatur;
};

Temperatur::Temperatur(double temperatur, int satuan){
	this->temperatur=temperatur;
	this->satuan=satuan;
}

Temperatur::getFahrenheit(){
	return (this->temperatur)*2.12;
}

