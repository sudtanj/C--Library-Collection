#include <iostream>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

struct node {
	int process;
	int quantum;
	struct node* next;
};
void enque(struct node* input, struct node* tail);
void deque(struct node* input, struct node* tail);
void jalan(struct node* hasil,struct node* terkahir);
void generator(struct node* generate, int jumlah);
void print(struct node* generate);
void kill();
struct node* temp2;
int main(){
	struct node* tail;
	tail=(struct node*)malloc(1*sizeof(struct node*));
	tail->next=NULL;
	temp2=(struct node*)malloc(1*sizeof(struct node*));
	temp2->process=rand()%9+1;
	temp2->quantum=3;
	int menu;
	while(1){
	cout << "1. Generate Process" << endl;
	cout << "2. View Process" << endl;
	cout << "3. Kill Process" << endl;
	cout << "4. Run Process" << endl;
	cout << "5. Exit Process" << endl;
	cin>>menu;
	if (menu==1){
	int jumlah;
	cout <<"Masukan Jumlah : " << endl;
	cin>>jumlah;
	generator(temp2,jumlah);
	}
	else if (menu==2){
		if (!temp2){
		cout << "please generate first";
		}
		else {
		print(temp2);
		}
	}
	else if (menu==3){
				if (!temp2){
		cout << "please generate first";
		}
		else {
		kill();
		cout << "Process KILL!" << endl;
		}
	}
	else if (menu==4){
		if (!temp2){
		cout << "please generate first";
		}
		else {
	jalan(temp2,tail);

	}
}
else if(menu==5){
	break;
}
	}
}

void jalan(struct node* hasil,struct node* terakhir){
	if (hasil->quantum!=0 && hasil->process!=0){
		hasil->process=(hasil->process)-1;
		hasil->quantum=(hasil->quantum)-1;
	}
	else if (hasil->quantum!=0 && hasil->process==0){
		hasil=hasil->next;
		//free(hasil);
	}
	else if (hasil->quantum == 0 && hasil->process>0) {
		deque(hasil,terakhir);
	}
}
void kill (){
	temp2=temp2->next;
}
void deque (struct node* input,struct node* tail){
	input->quantum=3;
	enque(input,tail);
}
void enque (struct node* input,struct node* tail){
	tail->next=temp2;
	temp2=temp2->next;
}
void generator(struct node* generate,int jumlah){
	if (jumlah!=0){
		struct node* temp1;
		temp1=(struct node*)malloc(1*sizeof(struct node*));
		srand(time(NULL));
		temp1->process=rand()*jumlah%9+1;
		temp1->quantum=3;
		generate->next=temp1;
		jumlah--;
		temp1->next=NULL;
		generator(temp1,jumlah);
	}
}

void print(struct node* generate){
	if (generate->next!=NULL){
		cout << "Process =";
		cout << generate->process << endl;
		cout << "Quantum =";
		cout << generate->quantum << endl;
		print(generate->next);
	}
}
