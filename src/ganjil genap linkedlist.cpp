#include <iostream>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

struct node {
	struct node* prev;
	int data;
	struct node* next;
};
struct node* deque(struct node* input);
struct node* push(struct node* input,int data);
void print(struct node* input,int jumlah);
void pop(struct node* input);
bool pembanding(int input);
void stackcheck (struct node* input,struct node* stack,int jumlah);
int main(){
	srand(time(NULL));
	int jumlah;
	cin>>jumlah;
	struct node* data1=(struct node*) malloc(sizeof(struct node));
	struct node* temp=data1;
	data1->prev=NULL;
	for (int i=0; i<jumlah; i++){
		temp=push(temp,rand()%100+1);
	}
	struct node* stack=(struct node*) malloc(sizeof(struct node*));
	stack->prev=NULL;
	stackcheck(data1,stack,jumlah);
	print(data1,jumlah);
	cout << endl;
	print (stack,jumlah);
	return 0;
}

struct node* push(struct node* input,int data){
	input->data=data;
	input->next=(struct node*) malloc(sizeof(struct node));
	(input->next)->prev=input;
	(input->next)->next=NULL;
	return input->next;
}

void stackcheck (struct node* input,struct node* stack,int jumlah){
	if(input->next!=NULL){
		if (pembanding(input->data)==1){
		stack=push(stack,input->data);
		input=deque(input);
		jumlah--;
		}
		stackcheck(input->next,stack,jumlah);
	}
}

void pop(struct node* input){
	(input->next)->prev=(input->prev);
	(input->prev)->next=(input->next);
}

struct node* deque(struct node* input){
	(input->next)->prev=(input->prev);
	(input->prev)->next=(input->next);
	return input->prev;
}

bool pembanding(int input){
	if(input%2==0)
		return 1;
	else 
		return 0;
}

void print(struct node* input,int jumlah){
	if (input->next!=NULL){
	cout << input->data << " ";
 	print(input->next,jumlah);
	}
}
