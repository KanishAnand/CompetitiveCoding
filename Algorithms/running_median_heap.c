#include<stdio.h>
typedef double d;
d insertmin(d val);
d insertmax(d val);
d siftupmin();
d siftupmax();

d last1=-1,last2=-1,minheap[100],maxheap[100],arr[100];

d insertmin(d val){
	minheap[++last2] = val;
	siftupmin();
return 0; 
}

int insertmax(int val){
	maxheap[++last1] = val;
	siftupmax();
return 0;
}

int siftupmin(){
	int p=last2;
	while(p > 0){
		if(minheap[p/2] > minheap[p]){
			int t=minheap[p];
			minheap[p] = minheap[p/2];
			minheap[p/2] = t;
		}
		p /= 2;
	}
return 0;
}

int siftupmax(){
	int p=last1;
	while(p > 0){
		if(maxheap[p/2] < maxheap[p]){
			int t=maxheap[p];
			maxheap[p] = maxheap[p/2];
			maxheap[p/2] = t;
		}
		p /= 2;
	}
return 0;
}


int main(void){
	int arr[100],n,median;
	scanf("%d",&n);
	// for(int i=0;i<n;i++){
	// 	scanf("%d",&arr[i]);
	// }
	// for(int i=0;i<=n/2;i++){
	// 	insertmax(arr[i]);
	// }
	// for(int i=n/2+1;i<n;i++){
	// 	insertmin(arr[i]);
	// }

	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
		if(i == 0){
			printf("%d\n",arr[i]);
			median=arr[i];
		}
		else if(i == 1){
			median = (median + arr[i] )/2;
			printf("%d\n",median);
		}
		else{
			insertmin(arr[0] > arr[1] ? arr[0] : arr[1]);
			insertmax(arr[0] < arr[1] ? arr[0] : arr[1]);
			if(i%2 == 0){
				if(arr[i] <= maxheap[0]){
					insertmax(arr[i]);
					median = maxheap[last1];
				}
				else{
					insertmin(arr[i]);
					insertmax(maxheap[0]);
				}
			}




		}



	}




	// for(int i=0;i<=last1;i++){
	// 	printf("%d ",maxheap[i]);
	// }
	// printf("\n");
	
return 0;
}
	