#include<stdio.h>
typedef unsigned long long int llu;
llu ceill(llu l,llu r,llu a,llu arr[]);
int main(void){
	int n;
	scanf("%d",&n);
	llu arr[n+1];
	for(int i=0;i<n;i++){
		scanf("%llu",&arr[i]);
	}

	for(int i=1;i<n;i++){
		arr[i] += arr[i-1];
	}
	
	llu a,m;
	scanf("%llu",&m);
	for(int i=0;i<m;i++){
		scanf("%llu",&a);
		if(a <= arr[0]){
			printf("1\n");
			continue;
		}
		printf("%llu\n",ceill(0,n-1,a,arr));
	}
return 0;
}

llu ceill(llu l,llu r,llu a,llu arr[]){
	llu mid = (l+r)/2;
	if(arr[mid] == a){
		return mid+1;
	}

	else if(arr[mid] < a){
		if(arr[mid+1] >= a){
			return mid+2;
		}
		else{
			return ceill(mid+1,r,a,arr);
		}
	}

	else{
		if(arr[mid-1] < a){
			return mid+1;
		}
		else if(arr[mid-1] == a){
			return mid;
		}	
		else{
			return ceill(l,mid-1,a,arr);
		}
	}
return 0;
}


	










