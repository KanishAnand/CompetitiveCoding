#include<stdio.h>
int insert(int val);
int siftup();
int last=-1,arr[100];


int delete(){
	arr[0] = arr[last];
	
	--last;
	int p=0;
	int child1 = p*2+1;
	int child2 = p*2+2;

	while( (arr[child1] < arr[p] || arr[child2] < arr[p] ) && (child1 <= last || child2 <= last )){

		child1 = p*2+1;
		child2 = p*2+2;

		if(arr[child1] < arr[child2]){
			int t=arr[child1];
			arr[child1] = arr[p];
			arr[p] = t;
			p = child1;
		}
		else{
			int t=arr[child2];
			arr[child2] = arr[p];
			arr[p] = t;
			p = child2;
		}
	}
return 0;
}

int insert(int val){
	arr[++last] = val;
	siftup();
return 0; 
}

int siftup(){
	int p=last;
	while(p > 0){
		if(arr[p/2] > arr[p]){
			int t=arr[p];
			arr[p] = arr[p/2];
			arr[p/2] = t;
		}
		p /= 2;
	}
return 0;
}


int main(void){
	int q,x;
	scanf("%d",&q);
	printf("1.Insert 2.Show min 3.Delete min\n");
	for(int i=0;i<q;i++){
		int j;
		scanf("%d",&j);
		if(j == 1){
			int no;
			scanf("%d",&no);
			insert(no);
		}
		else if(j == 2){
			printf("%d\n",arr[0]);
		}
		else{
			delete();
		}
	}
return 0;
}
	