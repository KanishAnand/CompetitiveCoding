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
	lli x,y,z;
	vector<lli> v;
	cin>>x>>y>>z;
	lli ans = 0;
	ans += x/z + y/z;
	lli a = x%z;
	lli b = y%z;
	lli p=0;

	if((a + b) / z != 0){
		p = min(z - a, z - b);
		++ans;
	}	
	
	cout<<ans<<" "<<p<<endl;
rt;
}
