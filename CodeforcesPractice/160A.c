#include<stdio.h>
int main(void){
	int s=0,n,sum=0,arr[110],temp;
	scanf("%d",&n);
	
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
		sum += arr[i];
	}
	
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(arr[i] < arr[j]){
				temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
			}
		}
	}
	
	for(int i=0;i<n;i++){
		s += arr[i];
		if(s > sum/2){
			printf("%d\n",i+1);
			break;
		}
	}
	
return 0;
}
