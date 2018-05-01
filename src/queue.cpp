#include <iostream>
#include <malloc.h>
using namespace std;

typedef struct node {
	int data;
	node* next;
} queue;

void print(queue* input);
queue* dequeue(queue* input);
queue* enque(int data,queue* input);
int main(){
	queue* number1=NULL;
	queue* temp=number1;
	temp=enque(50,temp);
	number1=temp;
	temp=enque(90,temp);
	temp=enque(20,temp);
	temp=enque(30,temp);
	temp=enque(70,temp);
	temp=enque(10,temp);
	print(number1);
	system("pause");
	number1=dequeue(number1);
	print(number1);
	system("pause");
	return 0;
}

queue* enque(int data,queue* input){
	if (input==NULL){
		input=(queue*) malloc(sizeof(queue));
		input->data=data;
		input->next=NULL;
		return input;
	}
	else {
		input->next=(queue*) malloc(sizeof(queue));
		(input->next)->data=data;
		(input->next)->next=NULL;
		return input->next;
	}
}

queue* dequeue(queue* input){
	queue* temp=input->next;
	free(input);
	return temp;
}

void print(queue* input){
	if(input->next!=NULL){
		cout << input->data << " ";
		print(input->next);
	}
	else cout << input->data << " ";
}
