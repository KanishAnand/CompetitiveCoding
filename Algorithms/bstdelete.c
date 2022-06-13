#include<stdio.h>
#include<stdlib.h>
typedef long long int lli;
lli arr[100];

typedef struct nodes{
	lli val;
	struct nodes *left;
	struct nodes *right;
	struct nodes *parent;
} node;
node *root;


lli del(lli value,node *head){
	
	if(head->val > value){
		del(value,head->left);
	}
	else if(head->val < value){
		del(value,head->right);
	}
	else{
		
		if(head->left == NULL && head->right  == NULL){
	
			if(head->parent == NULL){
	
				root = NULL;
			}
			
			else if(head->parent->left != NULL && head->val == head->parent->left->val){
	
				head->parent->left = NULL;
		
			}
			else{
	
				head->parent->right = NULL;
	
			}
			free(head);
		}

		else if(head->left == NULL){
			if(head->parent == NULL){
	
				root = head->right;
			}
			else if(head->parent->left != NULL && head->val == head->parent->left->val){
				head->parent->left = head->right;
			}
			else{
				head->parent->right = head->right;
			}
			free(head);
		}

		else if(head->right == NULL){
			if(head->parent == NULL){
				root = head->left;
			}
			else if(head->parent->left != NULL &&head->val == head->parent->left->val){
				head->parent->left = head->left;
			}
			else{
				head->parent->right = head->left;
			}
			free(head);
		}
		else{
	
			node *ptr = head;
			ptr = ptr->right;
			while(ptr->left != NULL){
				ptr = ptr->left;
			}
				
			lli temp = head->val;
			head->val = ptr->val;
			ptr->val = temp;
			del(ptr->val,ptr);
		}
	}
return 0;
}



node *insert(lli value,node *head,node *parent){
	if(head == NULL){
		head = (node *)malloc(sizeof(node));
		head->val = value;
		head->left = NULL;
		head->right = NULL;
		head->parent = parent;
	}
	else{
		if(head->val < value){
			head->right = insert(value,head->right,head);
			
		}
		else{
			head->left = insert(value,head->left,head);
			
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
		root = insert(arr[i],root,NULL);
	}
	root->parent = NULL;
	inorder(root);
	lli p;

	scanf("%lld",&p);
	del(p,root);
	inorder(root);	

}