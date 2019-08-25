#include <iostream>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
using namespace std;

struct node{
	int data;
	int spaces;
	struct node* next;
};
struct node* generateque(struct node* input,int jumlah);
int* generatestack(int* stack, int jumlah);
void printque(struct node* stack);
void run(int* stack, struct node* que);
bool faktor(int input1, int input2);
bool kelipatan(int input1, int input2);
void printstack(int* stack, int jumlah);
int main(){
	srand(time(NULL));
	int* stack;
	struct node* que;
	int jumlahstack=0;
	int jumlahque=0;
	cin>>jumlahstack;
	stack=(int*) malloc(sizeof(int*));
	stack=generatestack(stack,jumlahstack);
	cin>>jumlahque;
	que=(struct node*) malloc(sizeof(struct node*));
	que=generateque(que,(jumlahque+1));
	printque(que);
	cout <<"------" << endl;
	printstack(stack,jumlahstack);
	for (int i=0;i<jumlahstack;i++){
		run((stack+i),que);
	}
	printque(que);
	cout << endl;
	printstack(stack,jumlahstack);
	return 0;
}

int* generatestack(int* stack, int jumlah){
	//srand(time(NULL));
	for (int i=0; i<jumlah; i++){
	*(stack+i)=rand()%10+1;
	for (int j=0; j<1000000; j++){
	}
	}
	return stack;
}

struct node* generateque(struct node* input, int jumlah){
	if (jumlah>1){
		input->data=rand()%10+1;
		input->spaces=rand()%20+10;
		input->next=(struct node*) malloc(1*sizeof(struct node*));
		generateque(input->next,(jumlah-1));
	}
	if (jumlah==1){
		input->data=0;
		input->spaces=0;
		input->next=NULL;
	}
	return input;
}
void run(int* stack, struct node* que){
	if (kelipatan(*(stack),que->data)){
		if (que->spaces==0){
			run(stack,que->next);
		}
		else {
		que->spaces=(que->spaces)-(*(stack));
		}
	}
	else {
		run(stack,que->next);
	}
	if (que->next==NULL){
		(que->spaces)+=*(stack);
	}
}

bool faktor(int input1, int input2){
		if (input2%input1!=0){
			return true;
		}
		else {
			return false;
		}
}

bool kelipatan(int input1, int input2){
	return (input1%input2==0 || input2%input1==0);
	//{
		
		//return true;
	//}
	//	return false;
}
void printque(struct node* stack){
	if (stack->next != NULL){
		cout<< stack->data << "--"  << stack->spaces << endl;
		printque(stack->next);
	}
	if (stack->next == NULL){
		cout<< stack->data << "--"  << stack->spaces << endl;
	}
}
void printstack(int* stack, int jumlah){
	for (int i=0;i<jumlah;i++){
		cout<<*(stack+i)<< endl;
	}
}
