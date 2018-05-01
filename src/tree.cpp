#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include<time.h>
using namespace std;

struct node{
	int data;
	node* left;
	node* right;
};
struct node* root=NULL;
void postOrder(struct node* root);
void inOrder(struct node* root);
void preOrder(struct node* root);
void insert(struct node** root,int n)
{
	if((*root)==NULL){
        (*root) = new node();
        (*root)->data = n;
        (*root)->left = NULL;
        (*root)->right = NULL;
    }
    else if (n < (*root)->data)
        insert(&(*root)->left, n);
    else
        insert(&(*root)->right, n);
}

int main()
{
    root = NULL;
    int n, v;
    
    srand(time(NULL));

    cout<<"How many data's do you want to insert ";
    cin>>n;

    for(int i=0; i<n; i++){
        v=rand()%10+1;
        insert(&root, v);
    }
    cout<<"Inorder : ";
    inOrder(root);
    cout<<endl;

    cout<<"Preorder : ";
    preOrder(root);
    cout<<endl;

    cout<<"Postorder: ";
    postOrder(root);
    cout<<endl;
    return 0;
}

void inOrder(struct node* root)
{
    if(root!=NULL){
		inOrder(root->left);
		cout<<root->data<<" ";
		inOrder(root->right);
    }
}

void preOrder(struct node* root)
{
    if(root!=NULL){
        cout<< root->data<<" ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(struct node* root)
{
    if(root!=NULL){
        postOrder(root->left);
        postOrder(root->right);
        cout<<root->data<<" ";
    }
}
