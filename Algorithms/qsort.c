#include<stdio.h>
#include<stdlib.h>
int cmpfunc(const void *a,const void *b);
int arr[] = {7,9,2,4,5};
int main(void){
	int n = 5;
	qsort(arr,n,sizeof(int),cmpfunc);
	for(int i=0;i<5;i++){
		printf("%d ",arr[i]);	
	}
	printf("\n");
return 0;
}

int cmpfunc(const void *a,const void *b){
	return (*(int*)a - *(int*)b);
}

