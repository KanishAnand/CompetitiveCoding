#include<stdio.h>
int arr[100006];
int divide(int l,int r);
int merge(int l,int r);
int count=0;
int main(void){
	int n,t;
	scanf("%d",&t);
	for(int j=0;j<t;j++){
		count=0;
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",&arr[i]);
		}
		divide(0,n-1);
		printf("%d\n",count);
	}
return 0;
}

int divide(int l,int r){
	int mid = l + (r - l)/2;
	if(l < r){
		divide(l,mid);
		divide(mid+1,r);
		merge(l,r);
	}
return 0;
}

int merge(int l,int r){
	int mid = l + (r-l)/2;
	int i=0,j=0;
	int n1 = mid - l + 1,n2 = r - mid;
	int left[n1],right[n2];

	while(i < n1){
		left[i] = arr[l+i];
		++i;
	}

	while(j < n2){
		right[j] = arr[mid + 1 + j];
		++j;
	}
	i=0,j=0;
	int k=l;

	while(i < n1 && j < n2){
		if(left[i] <= right[j]){
			arr[k] = left[i];
			++i;
		}

		else{
			arr[k] = right[j];
			count += mid + 1 + j - k;
			++j;
		}
		++k;
	}

	while(i < n1){
		arr[k] = left[i];
		++k;
		++i;
	}
	while(j < n2){
		arr[k] = right[j];
		++j;
		++k;
	}
return 0;
}
	

	


