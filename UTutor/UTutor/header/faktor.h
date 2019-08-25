#include <iostream>
#include "garis.h"
#include <math.h>
using namespace std;

int faktor();

int faktor(){
	float data,pengurang, countfaktor,counter=0,counterpenghitung0=0;
	int data1,counterx;
	double data2=data,penghitungnol;
		cout << "Please input the number for factorial below :" << endl;
		cin >> data;
		line ();
		cout << "Calculation :" << endl;
		countfaktor=data;
			while (countfaktor>=2){
				pengurang=countfaktor-1;
				data=data*pengurang;
				line ();
				cout << "Hasil Pemfaktoran :"<< endl;
				cout.precision(0);
				cout << fixed << data << "=" << data/countfaktor+1 << " X " << pengurang << endl;
	 			line();
	 			countfaktor= countfaktor-1;
			}
		line ();
		cout << "\t\t\t   Hasil akhir" << endl;
		cout << "\t\t\t   -----------" << endl;
		cout << "\t\t\t*****************" << endl;
		cout << "\t\t\t               " << endl;
		cout << "\t\t\t    ";
		cout << data;  
		cout << "    " << endl;
		cout << "\t\t\t               " << endl;
		cout << "\t\t\t*****************" << endl;
		cout << "\n Find the 0 occurence :" << endl;
			while (data2>1){
				penghitungnol=fmod(data2,10);
				if (penghitungnol>1){
					counterx=counterx+1;
				} 
				else {
					counterpenghitung0=counterpenghitung0+1;
				}
				data2=data2/10;
				counter=counter+1;
			}
		cout << "Jumlah Angka : " << counter << endl; 
		cout << "Jumlah angka 0 : " << counterpenghitung0 << endl;
	return 0;
}
