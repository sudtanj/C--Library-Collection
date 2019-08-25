#include <iostream>
#include <malloc.h>
using namespace std;

typedef struct node {
	node* prev;
	int data;
	node* next;
} doublinklist;
doublinklist* pop(doublinklist* input);
doublinklist* push(int data, doublinklist* input);
void print(doublinklist* input);
int main(){
	doublinklist* head=(doublinklist*) malloc(sizeof(doublinklist));
	doublinklist* tail=head;
	tail=push(60,tail);
	tail=push(20,tail);
	tail=push(30,tail);
	tail=push(20,tail);
	tail=push(50,tail);
	print(tail);
	return 0;	
}

doublinklist* push(int data, doublinklist* input){
	if ((input->prev)->next!=input){
		input->prev=NULL;
	}
	if (input->next==NULL){
		input->data=data;
		input->next=(doublinklist*) malloc(sizeof(doublinklist));
		(input->next)->prev=input;
		(input->next)->next=NULL;
	}
	return input->next;
}

doublinklist* pop(doublinklist* input){
	doublinklist* temp=input->prev;
	free(input);
	return temp;
}

void print(doublinklist* input){
	if((input->prev)->prev!=NULL){
		cout << (input->prev)->data << " ";
		print(input->prev);
	}
	else cout << (input->prev)->data << " ";
}
