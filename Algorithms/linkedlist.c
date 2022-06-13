#include<stdio.h>
#include<stdlib.h>
int add(int val);
int reverse();
int display();
int delete(int val);
int insertatgivenplace(int n,int val);
int insertatstart(int val);
int insertatlast(int val);
typedef struct nodes{
	int value;
	struct nodes *nextnode;   //why cant we use int *nextnode
}m;
                                       //how can we pass head* to a function...
struct nodes *head = NULL;

int main(void){
	add(10);
	add(20);
	add(40);
	add(60);
	display();
	add(80);
	display();					// also use free to deallocate space allocated to run a function...
	insertatstart(5);
	display();
	insertatlast(100);
	display();
	delete(80);
	display();
	insertatgivenplace(3,66);
	display();
	reverse();
	display();
//	sort();
	
return 0;
}

int insertatgivenplace(int n,int val){
	struct nodes *newnode = (struct nodes *)malloc(sizeof(struct nodes));
	struct nodes *node;
	node = head;
	for(int i = 1; i <= n-2; i++){
		node = node->nextnode;
	}
	newnode->nextnode = node->nextnode;
	node->nextnode = newnode;
	newnode->value = val;
	printf("element %d inserted at postiton %d\n",val,n);
return 0;
}

int reverse(void){
	struct nodes *node;
	struct nodes *temp;
	struct nodes *temp1;
	node = head;
	temp = node->nextnode;
	node->nextnode = NULL;
	while(temp->nextnode != NULL){
		temp1 = temp->nextnode;              //doubt that value of temp1 change when temp->nextnode value changes ??????
						     //why cant we take node as simply integer instead of pointer...(ans = to tell compiler that 
						     //this variable is storing address...
		temp->nextnode = node;
		node = temp;
		temp = temp1;
	}
	temp->nextnode = node;
	head = temp;
	printf("linked list reversed\n");
return 0;
}

int delete(int val){
	struct nodes *node;
	node = head;
	if(head == NULL){          //this condition is not covered in below condition bcz before assigning any value to linked list there would be 					garbage value stored in it.....
		return 0;
	}
	if(node->value == val){
		head = node->nextnode;
	return 0;
	}
	while(node->nextnode != NULL){
		if((node->nextnode)->value != val){
			node = node->nextnode;
		}
	else{
			node->nextnode = (node->nextnode)->nextnode;
			printf("element deleted is : %d\n",val);
			return 0;
		}
	}
	printf("element not found\n");
return 0;
}

int add(int val){
	struct nodes *node = (struct nodes*)malloc(sizeof(struct nodes));   //why there is special need to allocate memory to node by malloc its only a p			      ointer of datatype struct nodes   if we give it size less than size of its datatype in malloc what would happen ??????
	if(head == NULL){         //why can't i use *head = NULL;
		node->value = val;
		head = node;             //why head = &node is wrong ???????
		node->nextnode = NULL;
	}
	else{
		node->nextnode = head;
		head = node;
		node->value = val;
	}
	printf("added element %d\n",node->value);
return 0;
}	
	
int display(){
	struct nodes *node;
	int i=0;
	node = head;						//we have to copy head so that while traversing through while loop at its end head									 is not lost...bcz if it is lost then functions after first display will not 									work as value of head gets lost...
	if(head == NULL){
		return 0;  					 //why this condition of no element can be covered in loop itself;
	}
	while(node != NULL){       				 
		i++;
		printf("element %d is %d\n",i,node->value);
		node = node->nextnode;
	}
return 0;
}
	
int insertatstart(int val){
	struct nodes *node = (struct nodes*)malloc(sizeof(struct nodes));
	node->nextnode = head;
	head = node;
	node->value = val;
	printf("element inserted at start: %d\n",val);
return 0;
}

int insertatlast(int val){
	struct nodes *node;
	struct nodes *new  = (struct nodes*)malloc(sizeof(struct nodes));
	node = head;
	if(node == NULL){
		new = node;
		new->value = val;
		new->nextnode = new;
		return 0;
	}
	while(node->nextnode != NULL){
		node = node->nextnode;
	}
	node->nextnode = new;
	new->value = val;
	new->nextnode = NULL;
	printf("element added at last :%d\n",val);
return 0;
}
