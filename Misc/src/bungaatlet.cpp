#include <iostream>
using namespace std;

int main(){
	int kasus,a,b,c,atlet;
	cin >> kasus;
	for (int i=0;i<kasus;i++){
		cin >> a >> b >> c >> atlet;
		if (a%atlet==0){
			cout << a/atlet;
			cout << " ";
		}
		if (b%atlet==0){
			cout << b/atlet;
			cout << " ";
		}
		if (c%atlet==0){
			cout << c/atlet;
			cout << " ";
		}
		if (a<atlet || b<atlet || c<atlet){
			cout << "Tolak Pesanan :" << endl;
		}
	}
	return 0;
}
