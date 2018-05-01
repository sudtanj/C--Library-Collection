#include <iostream>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

void PrintArray(int* array, int n);
void QuickSort(int* array, int startIndex, int endIndex);
int SplitArray(int* array, int pivotValue, int startIndex, int endIndex);
void swap(int &a, int &b);

int main(void){
	int jumlah=0;
	cout << endl << "           +======================+" << endl << "           | Input Amount of Data |" << endl << "           +======================+" << endl	<< "                      ";
	cin>>jumlah;
	int* array=(int*)malloc(jumlah*sizeof(int));
	system("CLS");
	srand(time(NULL));
	for(int i = 0; i <jumlah; i++) *(array+i)=rand()%100+1;
	cout << endl << "                 +----------------------+"<<endl <<"                 + Random Data Unsorted +"<<endl<<"                 +----------------------+"<<endl;
	PrintArray(array, jumlah);
	QuickSort(array,0,jumlah - 1);				//sort array from first to last element
	cout<<endl<<"                 +----------------------+"<<endl<<"                 +  Random Data sorted  +"<<endl<<"                 +----------------------+"<<endl;
	PrintArray(array, jumlah);
	cout << endl;
	system("pause");
	delete[] array;
	return 0;
}

void swap(int &a, int &b){
	int temp;
	temp = a;
	a = b;
	b = temp;
}

void PrintArray(int* array, int n){
		cout << "                | ";
		for(int i=0; i < n; i++){
			cout<<*(array+i);
			if (*(array+i)<=10 && *(array+i)>0)cout << "  | "; else if(*(array+i)>10 && *(array+i)<100) cout << " | "; else if(*(array+i)>=100) cout <<"| ";
			if ((i+1)>1) { if ((i+1)%5==0 && (i+1)!=n) cout << endl << "                | "; }
		}
}
void QuickSort(int* array, int startIndex, int endIndex){
	int pivot = array[startIndex],splitPoint;
	if(endIndex > startIndex){
		splitPoint = SplitArray(array, pivot, startIndex, endIndex);
		array[splitPoint] = pivot;
		QuickSort(array, startIndex, splitPoint-1);   //Quick sort first half
		QuickSort(array, splitPoint+1, endIndex);	 //Quick sort second half
	}
}

int SplitArray(int* array, int pivot, int startIndex, int endIndex){
	int leftBoundary = startIndex,rightBoundary = endIndex;
	while(leftBoundary < rightBoundary){
		 while( pivot < array[rightBoundary] && rightBoundary > leftBoundary) rightBoundary--;					
		 swap(array[leftBoundary], array[rightBoundary]);
		 while( pivot >= array[leftBoundary] && leftBoundary < rightBoundary) leftBoundary++;						 
		 swap(array[rightBoundary], array[leftBoundary]);
	}
	return leftBoundary;
}
