#include <iostream>
#include <malloc.h>
#include <time.h>
#include <stdlib.h>
using namespace std;

int random1(int i,int j);
int random2(int i,int j);
void randompointer(int* pointer,int x[2],int input);
void print_array(int* pointer,int input);

int main(){
	int input;
	int x[2]={0,0};
	cin >> input;
	if (input>=5 && 10>=input){
	for (int i=0; i<input; i++){
		for (int j=0;j<2;j++)
		if (j==0) x[j]=random1(j,i); else x[j]=random2(j,i);
		int* pointer;
		pointer=(int*) malloc(input*sizeof(int));
		randompointer(pointer,x,input);
		cout << x[0] << " ";
		print_array(pointer,input);
		cout << x[1] << endl;
	}
	}
	return 0;
}

int random1(int i, int j){
	srand(time(NULL));
	return (rand()*i+j)%5+1;
}

int random2(int i, int j){
	srand(time(NULL));
	return (rand()+i*j)%50+21;
}

void randompointer(int* pointer,int x[2],int input){
	srand(time(NULL));
	for (int i=0; i<input; i++){
		*(pointer+i)=(rand()*i)%x[1]+x[0];
	}
}
void print_array(int* pointer,int input){
	for (int i=0; i<input; i++){
		cout << *(pointer+i) << " ";
	}
}
