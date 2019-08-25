#include <iostream>
#include <windows.h>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <iomanip>
#include <sstream> 
#include "header/faktor.h"
#include "header/segitiga.h"
using namespace std;

// declare function global
int count;
int random();
int functionfor();
int menu1();
int array();

int main() {
	int a=0;
	int menu=0;
	bool hitunggoto=0;
	while (a==0){
		menu=0;
	   if (count==0){
		MessageBox (NULL, "This program is intended to make UPH student more good at learning programming. Copyright(C) 2015" , "Welcome to UPH AI", 0);
		}
		menu1();
	    cout << "Please enter your choice :" << endl;
	    cout << " ============== " << endl;
	    cout << "|              |" << endl;
	    cout << "|   ";
	    goto gambar;
	    input:
	    cin >> menu;
	    gambar:
	    if (hitunggoto==1){
		}
		else {
		cout << "        |" << endl;
	    cout << "|              |" << endl;
	    cout << " ============== " << endl;	
		hitunggoto=1;		    
		goto input;
	}
		system("cls");
		if (menu==1){
			 random();
		}
		else if (menu==2){
			faktor();
		}
		else if (menu==3){
			functionfor();
		}
		else if (menu==4){
			array();
		}
		else if (menu==5){
			segitiga();
		}
		else {
			cout << "Your number isn't list above or the system encounter some error!" << endl;
		}
					count=1;
				    system("pause");
					system("CLS");
				}
return 0;
}

int menu1(){
			cout << "Please enter the number you choose from the menu available below :" << endl;
			 line (); 
	cout << "1. Random a number" << endl;
	cout << "2. Factorial a number and search for occurence of 0" << endl;
	cout << "3. Using for as looping" << endl;
	cout << "4. Using array" << endl;
	 line ();
	 return 0;
}

int functionfor(){
	cout << "this function will using looping with using for" << endl;
	line();
	float number,i, jnum;
	cout << "input the number limit :" << endl;
	cin >> jnum;
	int jml=0;
	for (i=1;i<jnum;i++)
	{
		float counter;
		cout << "Please enter the";
		while (counter<jnum){
			float numberposition=0;
			numberposition=numberposition+1;
			cout << numberposition << endl;
		} 
		cout << " number in the addition" << endl;
		cin >> number;
		jml+= number;
		
	}
	cout << jml << endl;
}

int random(){
	float b;
		cout << "Your number is :" << endl;
			srand(time(NULL));
			b=rand();
		cout << b << endl;
		cout << "How to guide :" << endl;
		cout << "you will need a srand function as srand(time(NULL)), a rand(), a time.h library and a stdlib library" << endl;
}

int array(){
	float arrayisi[5]={1,2,3,4,5};
	cout << arrayisi[1] << endl;
	return 0;
}

