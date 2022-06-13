#include<iostream>
#include<vector>
#include<cmath>
typedef unsigned long long int lli;
int fun(int l,lli r,lli k);
lli search(lli k);
using namespace std;
int n,e;
vector<lli> v;
int main(void){
	lli k,a;
	cin>>n>>k;
	e = n-1;
	if(k % 2 == 1){
		cout<<"1\n";
		return 0;
	}

	for(int i=0;i<n;i++){
		a = pow(2,i+1) - 1;
		v.push_back(a);
	}

	fun(1,pow(2,n)-1,k);
return 0;
}

int fun(int l,lli r,lli k){
	lli mid;
	mid = l + (r - l)/2;

	if(k == mid){
		cout<<e+1<<"\n";
		exit(0);
	}
	if(k > mid){
		k = k - mid;
	}
	r = search(k);
	fun(1,r,k);	
return 0;
}

lli search(lli k){
	lli p;
	for(e=0;e<n;e++){
		if(v[e] >= k){
			p = v[e];
			break;
		}
	}
return p;
}
	
