#include<stdio.h>
int p=1000000007;
int n,k,d,flag=0,arr[10000000];
int fun(int n);
int main(void){
//	int n,k,d;
	scanf("%d%d%d",&n,&k,&d);
	printf("%d\n",fun(n));
return 0;
}

int fun(int n){
	if(arr[n] != 0){
		return arr[n];
	}
	int r=0,count=0;
	if(n == 0){
		if(flag == 1){
			++count;
			count = count%p;
		//	return count;
		}
		flag=0;
	return count;
	}

	for(int i=1;i<=k;i++){
		
		if(n-i >= 0){
			if(i >= d){
				flag = 1;
			}
			if(arr[n-i] != 0){
				r += arr[n-i];
			}
			else{	
				r += fun(n-i);
			}
		} 
	}
	arr[n] += r;
return arr[n];
}

