#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define fr(va,beg,end) for(lli va=beg;va<end;va++)
#define pb push_back
#define rt return 0
lli input(lli n,vector<lli> &ve);
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
	lli n,d,e,val,ans=100000000000;
	vector<lli> v1,v2;
	cin>>n>>d>>e;
	e  = e*5;
	lli x = n/d;
	for(lli i=x;i>=0;i--){
		val = n - i*d;
		val -= (val/e)*e;
		ans = min(val,ans);
		// cout<<val<<" "<<i<<" "<<ans<<endl;
	}
	cout<<ans<<endl;
rt;
}