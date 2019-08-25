#include <iostream>
#include <malloc.h>
using namespace std;

struct node {
	int data;
	struct node *next;
};

struct node* masukan;
struct node* temp;
void push(int input);
void print(struct node *);
void pop();
void empty(struct node *);
bool ceking=1;
int jumlah=1;
int main(){
	int input;
	masukan=(struct node*) malloc(1*sizeof(int));
	masukan->next=NULL;
	while (1){
		system("CLS");
		cout << "Menu :" << endl;
		cout << "1. Push" << endl;
		cout << "2. Pop" << endl;
		cout << "3. View List" << endl;
		cout << "4. Empty List" << endl;
		cout << "5. Exit" << endl;
		cin>>input;
		if (input==1){
		cout <<"Please enter value:";
		cin>>input;
		push(input);
		}
		else if (input==2)
		pop();
		else if (input==3)
		{
		print(masukan);
		system("pause");
		}
		else if (input==4){
		empty(masukan);
		masukan=(struct node*) malloc(1*sizeof(int));
		masukan->next=NULL;
		ceking=1;
		}
		else if (input==5){
			break;
		}
		else {
		}
		}
	return 0;
}

void push(int input){
	if (ceking){
		masukan->data=input;
		ceking=0;
	}
	else {
		temp=(struct node*) malloc(1*sizeof(int));
		temp->data=input;
		temp->next=masukan;
		masukan=temp;
	}
}

void pop(){
	masukan=masukan->next;
}

void print(struct node *printing){
	if (printing !=NULL)
	{
		cout << printing->data << endl;
		print(printing->next);
	}
	return;
//}
}

void empty(struct node *printing){
	if (printing !=NULL)
	{
		 empty(printing->next);
		 free(printing);
	}
}
