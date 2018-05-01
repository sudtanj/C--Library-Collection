#include <iostream>
#include <conio.h>
using namespace std;

int main(){
	int spasi=1;
	int turunnaik=1;
	while (1){
	if (_getch()=='d'){
	spasi=spasi+1;
	}
	else if (_getch()=='a') {
		spasi=spasi-1;
	}
	else if (_getch()=='s'){
		turunnaik=turunnaik+1;
	}
	else if (_getch()=='w'){
		turunnaik=turunnaik-1;
	}
	else {
	}
	system("CLS");
	for (int i=0;i<turunnaik;i++){
		cout << endl;
	}
	for (int i=0;i<spasi;i++){
		cout <<" ";
	}
	cout << " X "<< endl;
		for (int i=0;i<spasi;i++){
		cout <<" ";
	}
	cout << "\\|/"<< endl;
		for (int i=0;i<spasi;i++){
		cout <<" ";
	}
	cout << " | "<< endl;
	for (int i=0;i<spasi;i++){
		cout <<" ";
	}
	cout << "/ \\ "<< endl;
}
	return 0;
}
