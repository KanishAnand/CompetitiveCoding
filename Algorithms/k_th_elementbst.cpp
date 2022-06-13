#include<iostream>
#include<stdlib.h>
using namespace std;
typedef struct nodes{
	int val;
	int count;
	struct nodes *left;
	struct nodes *right;
}node;

node *insert(int value,node *head){
	if(head == NULL){
		head = (node*)malloc(sizeof(node));
		head->count = 1;
		head->val = value;
		head->left=NULL;
		head->right=NULL;
	}
	else if(head->val > value){
		++head->count;
		head->left=insert(value,head->left);
	}
	else{
		++head->count;
		head->right=insert(value,head->right);
	}
return head;
}

node *find(int k,node *head){
	if(head->left == NULL && head->right != NULL &&head->count - head->right->count == k){
		return head;
	}
	if(head->left == NULL && head->right == NULL &&head->count  == k){
		return head;
	}
	if(head->left != NULL && head->left->count == k - 1){
		return head;
	}
	else if(head->left != NULL && (head->left)->count >= k-1){
		return find(k,head->left);
	}
	else{
		//cout<<k-1-head->left->count<<endl;
		if(head->left != NULL)
			return find(k - 1 - head->left->count ,head->right);
		else
			return find(k-1,head->right);
	}
return 0;
}

int inorder(nodes *node){
	if(node->left != NULL){
		inorder(node->left);
	}
	printf("%d ",node->val);
	printf("%d ",node->count);
	printf("\n");
	if(node->right != NULL){
		inorder(node->right);
	}
return 0;
}

int main(void){
	int n,a;
	cin>>n;
	node *root;
	root=NULL;
	for(int i=0;i<n;i++){
		cin>>a;
		root=insert(a,root);
	}
	//printf("%d ",root->val);
	//inorder(root);
	int k;
	cin>>k;
	root=find(k,root);
	cout<<root->val<<endl;
return 0;
}

	
