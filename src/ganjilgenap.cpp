#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main(){
	srand(time(NULL));
	short unsigned int data=0,jumlah=5,loop=1,total=0;
	cin>>jumlah;
	bool ganjil=1;
	while (total!=jumlah){
			for (short int j=0;j<loop;){
				data=rand()%100+1;
				if ((data%2==0 && !ganjil) || (data%2!=0 && ganjil)){
					cout << data << " ";
					j++;
					total++;
				}
				if (total==jumlah) break; 
			}
		loop++;
		(ganjil)? ganjil=0 : ganjil=1;
	}
	return 0;
}
