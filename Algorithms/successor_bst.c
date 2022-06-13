#include<stdio.h>
#include<stdlib.h>
typedef struct nodes{
	int val;
	struct nodes *left;
	struct nodes *right;
	struct nodes *parent;
}node

int successor(){
	if(head->right != NULL){
		head=head->right;
		while(head->left != NULL){
			head = head->left;
		}
		return head->val;
	}

	else{
		while(head->parent->val < head->val){
			head = head->parent;
		}
		return head->val;
	}
}

int main(void){
	insert(4);
	printf("%d\n",successor());
return 0;
}