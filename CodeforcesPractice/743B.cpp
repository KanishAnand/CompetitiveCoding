#include<iostream>
#include<cmath>
int fun(int l,unsigned long long int r,int n,unsigned long long int k);
using namespace std;
int n;
unsigned long long int k;
int main(void){
	cin>>n>>k;
	int l=1;
	unsigned long long int r;
	if(k % 2 == 1){
		cout<<1<<"\n";
	}
	else{
		r = pow(2,n)-1;
		fun(l,r,n,k);
	}
return 0;
}

int fun(int l,unsigned long long int r,int n,unsigned long long int k){
	unsigned long long int m = l + (r-l)/2;
	if(k == m){
		cout<<n<<"\n";
		exit(0);
	}
	if(k < m){
		n = n - 1;
		r = pow(2,n)-1;
		fun(1,r,n,k);
	}
	if(k < m){
		n = n - 1;
		r = pow(2,n)-1;
		fun(1,r,n,k-m);
	}
return 0;
}

	
	

