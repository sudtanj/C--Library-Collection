#include <iostream>
#include <ctype.h>
using namespace std;

int main(){
	char abc;
	cin >> abc;
	cout << (unsigned char) toupper(abc) << "\n";
	cout << sizeof(unsigned char);
	return 0;
}
