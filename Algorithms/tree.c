#include<stdio.h>
#include<stdlib.h>
typedef struct nodes{
	int val;
	struct nodes *left=NULL;
	struct nodes *right=NULL;
} node;

int inorder(node *root);
node* Newnode(int val);

node* Newnode(int val){
	node *nodes = (node *)malloc(sizeof(node));
	nodes->val = val;
	nodes->left = NULL;
	nodes->right = NULL;
return nodes;
}

int main(void){
	node *root = (node *)malloc(sizeof(node));
	root->val = 1;
	//root->left=NULL;
	//root->right=NULL;
	root->left = Newnode(2);
	root->right = Newnode(3);
	
	/*	root->left->val = 2;
	root->right->val = 3;
	root->left->left->val = 4;
	root->left->right->val = 5;
*/
	inorder(root);
return 0;
}


int inorder(node *root){
//	root =(node *)malloc(sizeof(node));
	if(root->left != NULL){
		inorder(root->left);
//		printf("%d ",root->left->val);
	}
//	else if(root->left == NULL){
//		printf("%d ",root->val);
//		return 0;
//	}

	printf("%d ",root->val);

	if(root->right != NULL){
	//	printf("%d",root->right->val);
		inorder(root->right);
	}


//	else if(root->right == NULL){
//		return 0;
//	}
return 0;
}


