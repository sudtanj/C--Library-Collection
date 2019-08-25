#include <iostream>
using namespace std;

int main(){
	int nilai;
	cin >> nilai;
	for (int i=0; i<=9; i++){
		if (55>nilai){
			cout << "F" << endl;
			break;
		}
		else if((50+((i)*5)<=nilai && nilai<50+((i+1)*5))) {
			if (i<=2){
				cout << char (67);
			}
			else {
			cout << char ((67-(i/3))+1);
			}
			if (i-(3*(i/3))==0){
				cout << "+";
			}
			else if(i-(1*(i/3))==0){
				cout << "-";
			}
			else if(i==1){
				cout << "-";
			}
			break;
		}
		else if(nilai==100){
			cout << char(65);
			break;
		}
		}
	system("pause");
	return 0;
}
