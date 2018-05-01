/*
Name 	: Sudono Tanjung
NIM		: 00000012273
*/
#include <iostream>
#include <malloc.h>
using namespace std;
bool check(string input);
bool run(string input);
int main(){
	string input;
	getline(cin,input);
	if(!check(input)) cout << "Not Valid" << endl; else if (run(input)) cout<<"Valid" << endl; else cout<<"Not Valid"<<endl;
	return 0;
}
bool check(string input){
	int count1=0,count2=0;
	for (int i=0;i<input.length();i++){
		if (input[i]==')' || input[i]==']' || input[i]=='}') 
		if(count1==0) return false; else count2++;
		if (input[i]=='(' || input[i]=='[' || input[i]=='{') count1++; 
	}
	if (count1==count2) return true; else return false;
}
bool run(string input){
	int* count1=(int*) malloc(sizeof(int));
	*(count1)=NULL;
	for (int i=0; i<input.length();i++){
		if(input[i]=='(' || input[i]=='[' || input[i]=='{') count1++;
		if(input[i]==')' || input[i]==']' || input[i]=='}')
			if (*(count1)==NULL) return false; else count1--;
	}
	return true;
}
