#include<iostream>
#include<vector>
using namespace std;
typedef unsigned long long int llu;
llu sum(llu l,llu r);
llu fun(llu l,llu n,llu k);
llu max(llu a,llu b);
vector<unsigned long long int> v;
llu m,t;
llu f[5005][5005]={0};
int main(void){
	llu n,k,a,s=0;
	cin>>n>>m>>k;
	t = n-m;
	for(llu i=0;i<n;i++){
		cin>>a;
		v.push_back(a);
		s += a;
	}
	for(llu i=0;i<=n;i++){
		for(llu j=0;j<=k;j++){
			f[i][j] = -1;
		}
	}
	if(n == m*k){
		cout<<s<<endl;
	}
	else{
		cout<<fun(0,n,k)<<endl;
	}
return 0;
}

llu max(llu a,llu b){
	return (a > b ? a:b);
}

llu fun(llu l,llu n,llu k){
	if(k == 0){
		return 0;
	}
	if(f[l][k] != -1){
		return f[l][k];
	}
	if(l <= t){
		f[l][k] = max(fun(l+m,n-m,k-1) + sum(l,l+m),fun(l+1,n-1,k));
	}
	else{
		return 0;
	}	
return f[l][k];
}

llu sum(llu l,llu r){
	llu s=0;
	for(llu i=l;i<r;i++){
		s += v[i];
	}
return s;
}

