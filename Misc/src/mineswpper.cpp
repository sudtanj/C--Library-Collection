#include <iostream>
#include <string.h>
using namespace std;

int main(){
	int m,n;
	cin >>m>>n;
	string abs[m+1][n+1];
	int absa[m+1][n+1],lokasi[m+1][n+1],hasil[m+1][n+1];
	memset(absa,0,sizeof(absa));
	memset(lokasi,0,sizeof(lokasi));
	memset(hasil,0,sizeof(hasil));
	for (int i=1; i<m+1; i++){
		for (int a=1; a<n+1; a++){
			cin>>abs[i][a];
			if (abs[i][a]=="."){
				absa[i][a]=0;
			}
			if (abs[i][a]=="*"){
				lokasi[i][a]=1;
			}
		}
	}
	for (int i=1; i<m+1; i++){
		for (int a=1; a<n+1; a++){
	if (lokasi[i][a]==1){
		if (absa[i-1][a-1]==lokasi[i-1][a-1]){
		hasil[i-1][a-1]=hasil[i-1][a-1]+1;
		}
		if (absa[i-1][a]==lokasi[i-1][a]){
		hasil[i-1][a]=hasil[i-1][a]+1;
		}
		if (absa[i-1][a+1]==lokasi[i-1][a+1]){
		hasil[i-1][a+1]=hasil[i-1][a+1]+1;
		}
		if (absa[i][a-1]==lokasi[i][a-1]){
		hasil[i][a-1]=hasil[i][a-1]+1;
		}
		if (absa[i][a+1]==lokasi[i][a+1]){
		hasil[i][a+1]=hasil[i][a+1]+1;
		}
		if (absa[i+1][a-1]==lokasi[i+1][a-1]){
		hasil[i+1][a-1]=hasil[i+1][a-1]+1;
		}
		if (absa[i+1][a]==lokasi[i+1][a]){
		hasil[i+1][a]=hasil[i+1][a]+1;
		}
		if (absa[i+1][a+1]==lokasi[i+1][a+1]){
		hasil[i+1][a+1]=hasil[i+1][a+1]+1;
		}
	}
	}
	}
	for (int i=1; i<m+1; i++){
		for (int a=1; a<n+1; a++){
			if (lokasi[i][a]==1){
				cout << " ";
				cout << "*";
				cout << " ";
			}
			else {
				cout << " ";
			cout << hasil[i][a];
				cout << " ";
			}
		}
		cout << endl;
	}
	return 0;
}
