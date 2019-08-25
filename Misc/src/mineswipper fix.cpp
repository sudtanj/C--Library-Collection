#include <iostream>
#include <string.h>
using namespace std;

int main(){
	string input;
	int baris,kolom;
	cin >> baris >> kolom;
	int hasil[baris+1][kolom+1];
	memset(hasil,0,sizeof(hasil));
	for (int i=1;i<baris+1;i++) {
	cin >> input; 
	for (int b=0;b<input.length();b++) if (input[b]=='*') hasil[i][b+1]=-1;
	}
	for (int i=1; i<baris+1; i++){
	for (int a=1; a<kolom+1; a++){
		if (hasil[i][a]==-1)
			hasil[i-1][a-1]=hasil[i-1][a-1]+1;
			hasil[i-1][a]=hasil[i-1][a]+1;
			hasil[i-1][a+1]=hasil[i-1][a+1]+1;
			hasil[i][a-1]=hasil[i][a-1]+1;
			hasil[i][a+1]=hasil[i][a+1]+1;
			hasil[i+1][a-1]=hasil[i+1][a-1]+1;
			hasil[i+1][a]=hasil[i+1][a]+1;
			hasil[i+1][a+1]=hasil[i+1][a+1]+1;
	}
	}
		for (int i=1; i<baris+1; i++){
			for (int a=1; a<kolom+1; a++){
			if (hasil[i][a]==-1) cout << " " << "*" << " "; else cout << " " << hasil[i][a] << " ";
			}
			cout << endl;
		}
	return 0;
}
