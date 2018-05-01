#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>
using namespace std;

int random(int i);
int faktor(int input);
void input_data (int *pointer, int n);
void print_data(int *pointer, int n);
int main(){
	int jumlah, angka, jml_faktor;
	int* pointer;
	cin >> jumlah;
	for (int i=0; i<jumlah;i++){
	angka = random(i);
	cout<<angka<<": ";
	jml_faktor = faktor(angka);
	pointer=(int*) malloc(jml_faktor*sizeof(int));
	input_data(pointer, angka);
	print_data(pointer, jml_faktor);
	free(pointer);
	}
	return 0;
}

int faktor (int input){
	int x=0;
	for (int i=1; i<input; i++){
	if (input%i==0){
	x++;	
	}
	}
	return x;
}

int random(int i){
	srand(time(NULL));
	return (rand()*i)%100+1;
}

void input_data (int *pointer, int n)
{
	int x=0;
	for (int i=1; i<n; i++){
	if (n%i==0)
	*(pointer+x)=i;
	x++;
	}
}

void print_data(int *pointer, int n){
	for (int i=0; i<n;i++)
	cout << *(pointer+i) << " ";
	cout << endl;
}
