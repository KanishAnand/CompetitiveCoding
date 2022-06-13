#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define fr(va,beg,end) for(lli va=beg;va<end;va++)
#define pb push_back
#define rt return 0;
lli input(lli n);
lli input(lli n,vector<lli> &ve){
	lli val;
	for(lli i=0;i<n;i++){
		cin>>val;
		ve.pb(val);
	}
return 0;
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli n,k,a;
	vector<lli> v;
	cin>>n>>k;
	fr(i,0,n){
		cin>>a;
		v.pb(a);
	}	
	
	for(lli i=n-2;i>=0;i--){
		v[i] += v[i+1];
	}
	lli ans = v[0];
	sort(v.begin()+1,v.end());
	lli p=n-1,t=1;
	while(t <= k-1){
		ans += v[p];
		--p;
		++t;
	}
	cout<<ans<<endl;
rt;
}

