#include<stdio.h>
int pivot(int beg,int end,int pivot){
	int c,d;
	int key = pivot,index = beg;
	/*if(beg == end){
		return 0;
	}*/

	for(i = beg, i < end; i++){
		if(a[i] < key){
			temp = a[i];
			a[i] = a[index];
			a[index] = temp;
			++index;
		}
	}
	a[end] = a[index];
	a[index] = key;
/*	c = pivot(1,index-1,a[index - 1]);
	d = pivot1(index+1,n,a[n]);*/
return index;
}	
	
int quicksort(int beg,int end,int pivot,int index){
	int c,d,e,index,pivot = end;
	while(beg != end){
		d = pivot(beg,index - 1,a[n]);
		e = pivot(index + 1,end,a[n]);
	}
return 0;
}

int main(void){
	int n,index;
	printf("enter array size and array resp");
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	index  = pivot(1,n,a[n]);
	quicksort(1,n,a[n],index);
	for(int j=1;j<=n;j++){
		printf("%d ",a[j]);
	}
	return 0;
}
