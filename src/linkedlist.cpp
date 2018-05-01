
#include <iostream>
#include <stdlib.h>
using namespace std;

struct list{
	int data;
	struct list *link;
};



int main(){
	struct list *data1;
	struct list *data2;
	struct list *data3=NULL;
	int jalan=0;
	data2=(struct list*) malloc(1*sizeof(struct list));
	data2->link=NULL;
	for (int i=0; i<3;i++){
	if (i!=0) data2=data1;
	data1=(struct list*) malloc(1*sizeof(struct list));
	data2->data=i;
	if (i!=0) data2->link=data1;
	}
	struct list *output;
	output=(data2->link)->link;
	for (int i=0;i<3;i++){
		cout<<output->data<< endl;
	}
	return 0;
}
