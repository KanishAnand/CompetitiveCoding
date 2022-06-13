#include<stdio.h>
#include<stdlib.h>
typedef long long int lli;
lli arr[100];

typedef struct nodes{
	lli val;
	struct nodes *left;
	struct nodes *right;
	
} node;
node *root;
node *parent=NULL;

lli del(lli value,node *head){
	
	if(head->val > value){
		parent = head;
		del(value,head->left);
	}
	else if(head->val < value){
		parent = head;
		del(value,head->right);
	}
	else{
		
		if(head->left == NULL && head->right  == NULL){
			if(parent == NULL){
				root = NULL;
			}
			else if(parent->left != NULL && head->val == parent->left->val){
				parent->left = NULL;
			}
			else{
				parent->right = NULL;
			}
			free(head);
		}

		else if(head->left == NULL){
			
			if(parent == NULL){
				
				root = root->right;
			}
			else if(parent->left != NULL && head->val == parent->left->val){
				parent->left = head->right;
			}
			else{
				parent->right = head->right;
			}
			//free(head);
		}

		else if(head->right == NULL){
			if(parent == NULL){
				root = root->left;
			}
			else if(parent->left != NULL &&head->val == parent->left->val){
				parent->left = head->left;
			}
			else{
				parent->right = head->left;
			}
		//	free(head);
		}

		else{
			node *ptr;
			ptr = head;
			parent = head;
			ptr = ptr->right;
			while(ptr->left != NULL){
				parent = ptr;
				ptr = ptr->left;
			}
				
			lli temp = head->val;
			head->val = ptr->val;
			ptr->val = temp;
		//	printf("%lld %lld\n",ptr->val,root->val);
			//parent = head;
			del(ptr->val,ptr);
		}
	}
return 0;
}


node *insert(lli value,node *head){
	if(head == NULL){
		head = (node *)malloc(sizeof(node));
		head->val = value;
		head->left = NULL;
		head->right = NULL;
		
	}
	else{
		if(head->val < value){
			head->right = insert(value,head->right);
			
		}
		else{
			head->left = insert(value,head->left);
			
		}
	}
return head;
}

lli inorder(node *head){
	if(head->left != NULL){
		inorder(head->left);
	}
	printf("%lld ",head->val);
	if(head->right != NULL){
		inorder(head->right);
	}
}



int main(void){
	lli n;
	scanf("%lld",&n);
	// node *root;
	root=NULL;
	
	for(int i=0;i<n;i++){
		scanf("%lld",&arr[i]);
		root = insert(arr[i],root);
	}

	inorder(root);
	lli p;
	parent=NULL;
	scanf("%lld",&p);
	del(p,root);
	inorder(root);	

}