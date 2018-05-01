#include <iostream>
using namespace std;

string pembalik(string kata);
string kata2(string kata);
int pengecek(string masuk1, string masuk2);

int main(){
	int kasus;
	string kata;
	cin >> kasus;
	for (int i=0; i<kasus; i++){
		cin>>kata;
		while (1){
		if (pengecek(kata2(kata),pembalik(kata))==1) kata.erase(kata.length()/2,kata.length()); else break;
		}
		cout << "Case #"<< i+1 << ": " << kata << endl;
	}
	return 0;
}

string pembalik(string kata){
	char hasil[kata.length()/2];
	int j=0;
	for (int i=(kata.length()/2)-1; i>=0;i--){
		hasil[j]=kata[i];
		j++;
	}
	return hasil;
}

string kata2(string kata){
	char hasil[kata.length()-(kata.length()/2)];
	int j=0;
	for(int i=kata.length()/2; i<kata.length();i++){
		hasil[j]=kata[i];
		j++;
	}
	return hasil;
}

int pengecek(string masuk1, string masuk2){
	if (masuk1==masuk2) return 1; else return 0;
}
