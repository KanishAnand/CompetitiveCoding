#include<stdio.h>
int main(void){
	int *ptr;
	int arr[2][3]={{1,2,3},{4,5,6}};
	ptr = &arr;
	for(int i=1;i<=6;i++){
		printf("%d  ",*ptr);
		ptr++;
	}
return 0;
}
