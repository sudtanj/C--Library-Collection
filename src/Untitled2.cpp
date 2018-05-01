#include <iostream>
using namespace std;

int main(){
	int kasus;
	cin>>kasus;
	int data1,data2,counter=1,hasil,temp;
	for (int i=0;i<kasus;i++){
		cin>>data1>>data2;
		for (int j=data1;j<=data2;j++){
			hasil=j;
			while (hasil!=1){
				(hasil%2==0)? hasil/=2 : hasil=hasil*3+1;
				counter++;
			}
			if(temp<counter) temp=counter;
			counter=1;
		}
		cout <<data1 <<" " << data2 << " "<< temp << endl;
		counter=1;
		temp=0;
	}	
}
