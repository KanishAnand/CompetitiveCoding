#include<stdio.h>
#include<stdlib.h>
int add(int value);
int display();
int middle();
int sort();
struct nodes{
	int val;
	struct nodes *nextnode;
};

struct nodes *head = NULL;
int main(void){
	add(9);
	add(1);
	add(4);
	add(6);
	add(23);
//	printf("%d\n\n",head->val);
	display();
	printf("\n");
	//middle();
	sort();
	display();
	printf("\n");
return 0;
}

int sort(){
	struct nodes *node,*n;
	node = head;
	while(node != NULL){
		n  = node;
		while(n != NULL){
			if(node->val > n->val){
				int t = node->val;
				node->val = n->val;
				n->val = t;
			}
			n = n->nextnode;
		}
	node = node->nextnode;
	}
return 0;
}

/*int reverse(){
	struct nodes *a,*b;
	a = node;
	while(){
		b = a->nextnode;
		b->nextnode = a;
		a = b;
	}
return 0;
}*/

int middle(){
	struct nodes *ptr1,*ptr2;
	ptr1 = head;
	ptr2 = head;
	while(ptr2 != NULL && ptr2->nextnode != NULL){
		ptr2 = (ptr2->nextnode)->nextnode;
		ptr1 = ptr1->nextnode;
	}
	printf("middle element is %d\n",ptr1->val);
return 0;
}

int add(int value){
	struct nodes *node = (struct nodes *)malloc(sizeof(struct nodes));
	node->val = value;
	node->nextnode = head;
	head = node;
return 0;
}
		
int display(){
	struct nodes *node;
	node = head;
	while(node != NULL){
		printf("%d\n",node->val);
		node = node->nextnode;
	}
return 0;
}




