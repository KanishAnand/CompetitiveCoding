#include<stdio.h>
int main(){
	long int n,min,flag=0,count=0,a[200005],total=0,b[200005],arr[200005];
	scanf("%ld",&n);
	for(long int i=1;i<=n;i++){
		scanf("%ld",&a[i]);
		arr[a[i]] = i;
	}

	for(long int i=1;i<=n;i++){
		scanf("%ld",&b[i]);
		if(flag == 0){
			min = arr[b[1]];
			flag=1;
		}
		count = arr[b[i]] - total;
		if(arr[b[i]] < min){
			printf("0 ");
		}
		else{
			min = arr[b[i]];
			printf("%ld ",count);
			total = arr[b[i]];
		}
	}
	printf("\n");
return 0;
}

	
