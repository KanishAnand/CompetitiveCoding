#include<iostream>
#include<vector>
using namespace std;
typedef unsigned long long int llu;
llu dp(llu l);
llu max(llu a,llu b);
vector<llu> v(100003,0),d(100005,-1);
llu maxm=0;
int main(void){
	llu n,a,min=1000000;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a;
		if(a > maxm){
			maxm = a;
		}
		if(a < min){
			min = a;
		}
		v[a]++;
	}
	cout<<dp(min)<<endl;
return 0;
}

llu max(llu a,llu b){
	return (a > b ? a : b);
}

llu dp(llu l){
	if(l > maxm){
		return 0;
	}
	if(d[l] != -1){
		return d[l];
	}
	if(v[l] == 0){
		return dp(l+1);
	}
	llu a;
	d[l] = max((dp(l+2) + v[l]*l),dp(l+1));
	a = d[l];
return a;
}

