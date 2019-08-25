#include <iostream>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

struct node {
	int data;
	node* left;
	node* right;
};
node* finddata(node* root,int number,node* parent);
void deletenode(node* root,node* parent);
void checkdata(node* root,int check,node* parent);
void inOrder(node* root);
int maksnumber(node* root);
node* insert(struct node* root,int n);
int main(){
	srand(time(NULL));
	node* root=NULL;
	int jumlahnode;
	cin>>jumlahnode;
	for (int i=0; i<jumlahnode; i++){
	root=insert(root,rand()%100+10);
	}
	inOrder(root);
	int check;
	cin>>check;
	checkdata(root,check,root);
	cout<<endl;
	inOrder(root);
	return 0;
}

node* insert(struct node* root,int n)
{
	if(root==NULL)
    {
        root = (struct node*) malloc(sizeof(struct node));
        root->data = n;
        root->left = NULL;
        root->right = NULL;
    }
    else if(n < root->data){
        root->left = insert(root->left, n);
    }
    else {
        root->right = insert(root->right, n);
    }
    return root;
}

void checkdata(node* root,int check,node* parent){
	if(root!=NULL){
		checkdata(root->left,check,root);
		if (root->data%check==0){
			cout<<root->data<<endl;
			deletenode(root,parent);
		}
		checkdata(root->right,check,root);
	}
}

void deletenode(node* root,node* parent){
	if(root->left==NULL && root->right==NULL){
		cout<<"Q";
		if(parent->left==root){
		cout<<"Q1";
			parent->left=NULL;
		}
		if(parent->right==root){
			cout<<"Q2";
			parent->right=NULL;
		}
	}
	if((root->left==NULL && root->right) || (root->left && root->right==NULL)){
		if(parent->left==root){
			cout<<"W";
			if(root->left){
			cout<<"W1";
				parent->left=root->left;
			}
			if(root->right){
					cout<<"W2";
				parent->left=root->right;
			}
		}
		if(parent->right==root){
			cout<<"P";
			if(root->left){
				cout<<"P1";
				parent->right=root->left;
			}
			if(root->right){
				cout<<"P2";
				parent->right=root->right;
			}
		}
	
	}
	if (root->left && root->right){
			cout<<"U";
			if(parent->left==root){
				cout<<"U1"<<endl;
				cout<<parent->data<< endl;
				(parent->left)->data=maksnumber(root);
				(parent->left)->left=root->left;
				(parent->left)->right=root->right;
				
			}
			if(parent->right==root){
				cout<<"U2"<<endl;
				cout<<parent->data<< endl;
				(parent->right)->data=maksnumber(root);	
				(parent->right)->left=root->left;
				(parent->right)->right=root->right;
			}
	
	}
}

int maksnumber(node* root){
	int maks=0;
	if(root!=NULL){
		maksnumber(root->left);
		if (root->left<root->right){
			maks=(root->left)->data;
		}
		if (root->left>root->right){
			maks=(root->right)->data;
		}
		maksnumber(root->right);
	}
	return maks;
}

node* finddata(node* root,int number,node* parent){
	if(root!=NULL){
		finddata(root->left,number,root);
		if (root->data==number){
			return parent;
		}
		finddata(root->right,number,root);
	}
	return 0;
}

void inOrder(node* root){
    if(root!=NULL){
		inOrder(root->left);
		cout<<root->data<<" ";
		inOrder(root->right);
    }
}

