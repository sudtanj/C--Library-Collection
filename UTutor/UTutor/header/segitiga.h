#include <iostream>
#include <iomanip>
using namespace std;

void segitiga();
void segitiga(){
	int pembagicounter,hasilsetw2, hasilbukan2,x,y,input,counter=0,counterbarisakhir=0,checkinput,jarak,counterbintang=0,data,data1,settingcounter;
	double hasilinput=0,hasilsetw,hasilsetw6,hasilsetw5,hasilsetw4,hasilsetw3;
	int hasilinput6,pemundurcounter,countdownjarak1=0,hasilinput5,hasilinput4,hasilinput3,hasilinput2,hasilinput1;
	cin >> input;
	checkinput=input%2;
	cout << checkinput << endl;
	hasilinput=input/2;
	hasilinput=hasilinput+7;
	if (checkinput){

	while (input>counter){
			countdownjarak1=countdownjarak1+1;
			counter=counter+1;
		hasilinput1=input-2;
	 	hasilinput2=3*hasilinput1;
 		hasilinput3=hasilinput2+input;
 		hasilinput4=hasilinput3/2;
 		hasilinput5=hasilinput4-countdownjarak1;
			if (input==counter){
				cout << setw(hasilinput5);
		while (counterbarisakhir<input){
			cout << "*";
			cout << setw(3);
			counterbarisakhir=counterbarisakhir+1;
		}
		cout << endl;
		}
		else {
	counterbintang=0;
	data1=hasilinput-6;
 	while (counterbintang<counter){
 	if (counter==1){
 		cout << setw(hasilinput4-1);
	 }	
	 else {
 	if (counterbintang==0){
 		cout << setw(hasilinput5);
	}
	else if (counterbintang>0 && counterbintang<counter){
	}
	}
	cout << "*";
	data1=data1-2;
	if (counter==input-1){
		cout << setw(3);
	}
	else {
		hasilsetw=input-1;
		hasilsetw2=hasilsetw-1;
		hasilsetw3=3*hasilsetw2;
		hasilsetw4=hasilsetw3-2;
		hasilsetw5=hasilsetw2-1;
		hasilsetw6=hasilsetw4/hasilsetw5;
		if (counter==2){
			cout << setw(3);
		}
		else {
			pemundurcounter=counter-2;
			if (pemundurcounter==counterbintang){
				cout << setw(3);
					}
					else {
					cout << setw(3);
					}
	}
	}
 counterbintang=counterbintang+1;
	if (counterbintang==counter){
		cout << endl;
	}
	}
	}
	hasilinput=hasilinput-1;
	}
	}
	else {
		cout << "not right";
	}
}
