//this is code to covert a set into two halves such that diff bw sum of elements of both subset is minium....(BACKTRACKING).

#include<stdio.h>
int arr[100];
int main(void){

	for(int i = 0; i < 100; i++){
		scanf("%d",&arr[i]);
	}
	divide();

}

void divide(){

