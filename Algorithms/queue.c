#include<stdio.h>
int add(int val);
int del();
int size();
int n=5,arr[5],l=0,r=0;
int main(void){
//	add(5);
//	printf("%d\n",size());
//	del();
//	printf("%d\n",size());
	add(6);
	add(4);
	add(3);
	add(2);
	add(3);
	printf("%d\n",size());
	add(9);
//	printf("%d\n",size());
//	del(3);
//	add(3);
//	printf("%d\n",size());
	
return 0;
}

int add(int val){
	if(r < n){
		arr[r] = val;
		++r;
	}
	else{
		if(l>0){
			r=0;
			arr[r] = val;
			++r;
		}
		else{
			printf("its full\n");
		}
	}
return 0;
}

int del(){
	++l;
return 0;
}

int size(){
	return (n+r-1-l)%n;
}
