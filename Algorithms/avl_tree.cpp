#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef struct node{
	int val,height;
	struct node *left;
	struct node *right;	
} box;

int height(box *head){
	if(head == NULL){
		return 0;
	}
return head->height;
}

// see about return status
//and about all 4 cases

struct node *rightrotate(box *head){
	box *temp = head;
	head = head->left;
	temp->left = head->right;
	head->right = temp;
	head->height = max(height(head->left),height(head->right)) + 1;
	temp->height = max(height(temp->left),height(temp->right)) + 1;
return head;
}

struct node *leftrotate(box *head){
	box *temp = head;
	head = head->right;
	temp->right = head->left;
	head->left = temp;
	head->height = max(height(head->left),height(head->right)) + 1;
	temp->height = max(height(temp->left),height(temp->right)) + 1;
return head;
}


struct node *balanceit(box *head,int diff,int value){
	if(diff > 1 && value < head->left->val){
		return rightrotate(head);	
	}
	else if(diff > 1 && value > head->left->val){
		head->left = leftrotate(head->left);
		return rightrotate(head);
	}
	else if(diff < -1 && value > head->right->val){
		return leftrotate(head);
	}
	else if(diff < -1 && value < head->right->val){
		head->right = rightrotate(head->right);
		return leftrotate(head);
	}
}

struct node* insert(int value,box *head){
	if(head == NULL){
		head = (box *)malloc(sizeof(box));
		head->val = value;
		head->left = NULL;
		head->right = NULL;
		head->height = 1;
		return head;
	}
	else{
		if(head->val > value){
			head->left = insert(value,head->left);
		}
		else{
			head->right = insert(value,head->right);
		}
	}

	lli left_height = height(head->left);
	lli right_height = height(head->right);

	head->height = max(left_height,right_height) + 1;
	lli diffinheight = left_height - right_height;

	if(diffinheight > 1 || diffinheight < -1 ){
		head = balanceit(head,diffinheight,value);
	}

return head;
}

int inorder(box *head){
	if(head->left != NULL){
		inorder(head->left);
	}
	cout<<head->val<<" ";
	if(head->right != NULL){
		inorder(head->right);
	}
}

int main(void){
	int n,a;
	cin>>n;
	box *root;
	root = NULL;
	for(int i=0;i<n;i++){
		cin>>a;
		root = insert(a,root);
		// if(root->right != NULL)
		// cout<<root->right->val<<endl;
		//inorder(root);
	}
	inorder(root);
	// cout<<root->right->val;
return 0;
}