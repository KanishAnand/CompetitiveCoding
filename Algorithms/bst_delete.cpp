#include<iostream>
using namespace std;
typedef struct nodes{
	int val;
	int count;
	struct nodes *left;
	struct nodes *right;
}node;

node *findsucc(node *head){
	node *parent = head;
	head=head->right;
	while(head->left != NULL){
		parent = head;
		head = head->left;
	}
	//cout<<head->val<<endl;
	if(parent->right == head){
		parent->right = NULL;
	}
	else{
		parent->left = NULL;
	}
return head;
}

int del(int value,node *head){
	//cout<<head->val<<endl;
	if(head->left != NULL && head->left->val == value){
		node *parent = head;
		head = head->left;
		if(head->left == NULL && head->right == NULL){
			parent->left = NULL;
			return 0;
		}
		if(head->left == NULL){
			parent->left = head->right;
			return 0;
		}
		else if(head->right == NULL){
			parent->left = head->left;
			return 0;
		}
		else{
			node *succ;
			succ = findsucc(head);
			//cout<<succ->val<<endl;
			int t=head->val;
			head->val = succ->val;
			succ->val = t;
		}

	}

	if(head->right != NULL && head->right->val == value){
		node *parent = head;
		head = head->right;
		if(head->left == NULL && head->right == NULL){
			parent->right = NULL;
			return 0;
		}
		if(head->left == NULL){
			parent->right = head->right;
			return 0;
		}
		else if(head->right == NULL){
			parent->right = head->left;
			return 0;
		}
		else{
			cout<<"k"<<endl;
			node *succ;
			succ = findsucc(head);
			cout<<head->val<<endl;
			int t=head->val;
			head->val = succ->val;
			succ->val = t;
		}
	}
return 0;
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

int find(int value,node *head){
	if(head->left != NULL && head->left->val == value){
		//cout<<"kan"<<endl;
		return del(value,head);
	}
	if(head->right != NULL && head->right->val == value){
		return del(value,head);
	}
	if(head->val > value){
		find(value,head->left);
	}
	if(head->val < value){
		find(value,head->right);
	}
return 0;
}

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
int main(void){
	int n,a;
	cin>>n;
	node *root;
	root=NULL;
	for(int i=0;i<n;i++){
		cin>>a;
		root=insert(a,root);
	}
	int k;
	cin>>k;
	//inorder(root);
	find(k,root);
	inorder(root);
return 0;
}