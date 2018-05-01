#include <iostream>
using namespace std;

int fpb(int a,int b);

int main(){
	int a=0,b=0;
	cin >> a >> b;
	if (a<b){
		cout << fpb(b,a);
	}
	else {
		cout << fpb (a,b);
	}
	return 0;
}

int fpb(int a, int b){
	if (b<(a-b)){
		return fpb((a-b),b);
	}
	else if ((a-b)==0 && a==b){
		return a;
	}
	else {
		return fpb(b,(a-b));
	}
}
