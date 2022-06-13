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
	lli a,b,c,d;
	vector<lli> v;
	cin>>a>>b>>c>>d;	
	v.pb(a);
	v.pb(b);
	v.pb(c);
	sort(v.begin(),v.end());
	a = v[0];
	b= v[1];
	c = v[2];
	lli x = b - a;
	lli y = c - b,ans=0;
	if(x >= d && y >= d){
		cout<<"0"<<endl;
		rt;
	}
	if(x < d){
		ans += d - x;
	}
	if(y < d){
		ans += d - y;
	}
	cout<<ans<<endl;
rt;
}
	
