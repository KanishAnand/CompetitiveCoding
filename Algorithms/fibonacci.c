#include<stdio.h>
typedef unsigned long long int llu;
llu fib(llu n); 
llu m[10000]={0};

int main(void){
	llu n;
	scanf("%llu",&n);
	printf("%llu\n",fib(n));
return 0;
}

llu fib(llu n){
	m[1] = 1;
	m[0] = 0;
	if(n == 1 || n == 0){
		return n;
	}
	
	if(m[n] != 0){
		return m[n];
	}
	
	m[n - 1] = fib(n - 1);
       	m[n - 2] = fib(n - 2);
	m[n] = m[n - 1] + m[n - 2];
	return m[n];
}
