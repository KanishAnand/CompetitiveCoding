#include<iostream>
#define p 998244353
using namespace std;
typedef unsigned long long int llu;
llu c[2001][2001]={0};
llu cal(llu n,llu r);
int main(void){
	llu ans,n,m,k;
	cin>>n>>m>>k;
	ans = cal(n-1,k);
	ans *= m;
	ans %= p;
	for(int i=1;i<=k;i++){
		ans *= (m-1)%p;
		ans %= p;
	}
	cout<<ans<<endl;
return 0;
}

llu cal(llu n,llu r){
	if(r == 0 || r == n){
		return 1;
	}
	if(r == 1 || r == n-1){
		return n%p;
	}
	if(c[n][r] != 0){
		return c[n][r];
	}
	c[n][r] = cal(n-1,r)%p + cal(n-1,r-1)%p;
	c[n][r] %= p;
return c[n][r];
}

