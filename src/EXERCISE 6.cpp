/*
Name 	: Sudono Tanjung
NIM 	: 00000012273
*/

#include <iostream>
using namespace std;

int main(){
	string input;
	bool lastisexpired=0;
	int countlast=0,countfirst=0,totalmiddle=1,countmiddle[10];
	getline(cin,input);
	for (int i=input.length()-1; input.length()>i; i--){
		if (lastisexpired==0){
		if (input[i]==' '){
			countlast=i+1;
			lastisexpired=1;
		}
		}
		else {
			if(input[i]==' '){
			countmiddle[totalmiddle]=i+1;
			totalmiddle=totalmiddle+1;
			}
			}
		}
		cout << endl;
	for (int i=countlast; input.length()>i; i++){
		cout << input[i];
	}
	cout << ",";
	for (int i=0;input.length()>i;i++){
		if (input[i]==' '){
			break;
		}
		else {
			cout << input[i];
		}
	}
	int a=totalmiddle-1;
	while (a>0){
		cout << " ";
		cout << input[countmiddle[a]];
		cout << ".";
		a=a-1;
	}
	return 0;
}
