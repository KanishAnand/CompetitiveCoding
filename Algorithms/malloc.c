#include<stdio.h>
#include<stdlib.h>
int main(void){
	int *arr = (int*)malloc(6*sizeof(int));
	if(arr == NULL){
		printf("fail");
		exit(0);
	}
	int c =sizeof(*arr)/ sizeof(int);   
	printf("%d\n",c);			
	*(arr+1) = 1;				
	*(arr+3) = 3;
	*(arr + 9) = 8;
	for(int i=0;i<=9;i++){
		printf("%d  ",*(arr+i));
	}
	printf("\n");
	arr = (int*)realloc(arr,sizeof(int)*12);
	*(arr+11) = 12;
	for(int i=0;i<=12;i++){
		printf("%d  ",*(arr+i));	
	}
return 0;
}
