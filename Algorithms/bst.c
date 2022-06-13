#include<stdio.h>
#include<stdlib.h>

int n,arr[100];
typedef struct node{
	int val;
	struct node* left;                             /// why cant we declare these NULL here
	struct node* right;
} nodes;

nodes* bst(int value,nodes *node);
int inorder(nodes *node);
int preorder(nodes *node);
int postorder(nodes *node);
/*nodes* newnode(int value){                              //// for simple  tree construction
	node = (nodes*)malloc(sizeof(nodes));
	node->val = value;
return node;
}*/

nodes* bst(int value,nodes *node){
	if(node == NULL){
		node=(nodes*)malloc(sizeof(nodes));
		node->val = value;
	}
	else{
		if(node->val > value){
		 node->left=bst(value,node->left);
		}
		else{
		 node->right=bst(value,node->right);
		}
	}
return node;
}

int inorder(nodes *node){
	if(node->left != NULL){
		inorder(node->left);
	}
	printf("%d ",node->val);
	if(node->right != NULL){
		inorder(node->right);
	}
return 0;
}

int preorder(nodes *node){
	printf("%d ",node->val);
	if(node->left != NULL){
		inorder(node->left);
	}
	if(node->right != NULL){
		inorder(node->right);
	}
return 0;
}

int postorder(nodes *node){
	if(node->right != NULL){
		inorder(node->right);	
	}
	if(node->left != NULL){
		inorder(node->left);
	}
	printf("%d ",node->val);
return 0;
}

int main(void){
	scanf("%d",&n);	
	nodes *root;
	root=NULL;
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
		if(i == 0){
			root=bst(arr[i],root);
		}
		else{
			bst(arr[i],root);
		}
	}
	inorder(root);
	printf("\n");
	// preorder(root);
	// printf("\n");
	// postorder(root);
	// printf("\n");
return 0;
}

		


