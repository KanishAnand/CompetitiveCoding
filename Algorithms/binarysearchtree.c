#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int val;
	struct node *left;
	struct node *right;
} nodes;

int inorder(nodes *root);
nodes* insert(int value,nodes *newnode);
//nodes *head = NULL;

int main(void){
	int n;
	scanf("%d",&n);
	int arr[n+5];
//	nodes *newnode = (nodes *)malloc(sizeof(nodes));	
//	newnode = NULL;
	nodes *root = NULL;

	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
		if(i == 0){
			root = insert(arr[i],root);
		}
		else{
			insert(arr[i],root);
		}
	}
	inorder(root);

return 0;
}

nodes* insert(int value,nodes* head1){
	
	if(head1 == NULL){
		nodes *newnode = (nodes *)malloc(sizeof(nodes));
		head1 = newnode;
	//	newnode = head1;
		newnode->val = value;	
//		newnode->left = NULL;
//		newnode->right = NULL;
		//	newnode = Newnode;
	}

	else if(head1->val > value){
		head1->left = insert(value,head1->left);
	}

	else{
		head1->right = insert(value,head1->right);
	}

return head1;
}

int inorder(nodes *root){
	if(root->left != NULL){
		inorder(root->left);
	}
	printf("%d ",root->val);
	
	if(root->right != NULL){
		inorder(root->right);
	}
return 0;
}



