#include<iostream>
#include<string.h>
using namespace std;

typedef struct node {
	bool lamp=false;
	node* next;
} lamp;

void insert(lamp** data);
void print(lamp* print);

void print(lamp* data){
	if (data->next!=NULL){
		cout<< data->lamp <<" ";
		print(data->next);
	}
}
void insert(lamp** data){
	if((*data)==NULL){
		(*data)=new lamp();
		(*data)->next=NULL;
		(*data)->lamp=false;
	}
	if((*data)){
		insert(&(*data)->next);
	}
}

int main(){
	int a,b,c,d;
	lamp* data=NULL;	
	cout<<"Jumlah Lampu: ";
	cin>>a;
	for (int i=0;i<a;i++){
		insert(&data);
	}
	cout<<endl;
	cout<<"Banyak Saklar: ";
	cin>>c;
	for(d=0;d<=c;d++){
		cin>>d;
	}
	while(true){
		cin>>d;
		if(d==0)
		{
			cout<<"lampu mati";
			break;
		}
		for(int b=0;b<=a;b++)
	    {  
			if(b%d==0&&lamp[b]==1)
			{
				lamp[b]=0;
			}else
			if(b%d==0)
	    	{
	    		lamp[b]=1;
			}cout<<lamp[b]<<" ";
		}cout<<endl;		
	}
	return 0;
}
