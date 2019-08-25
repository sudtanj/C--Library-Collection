#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int a,b,c;
	cin >> a >> b >> c;
	if ((float)a/b==c){
		cout << "/ ";
	}
	cout << fmod(a,b) << endl << (float) a/b;
	if (fmod(a,b)==c){
		cout << "% ";
	}
	return 0;
}
