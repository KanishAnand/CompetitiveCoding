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
	lli n,k,a;
	vector<lli> v;
	cin>>n>>k;	
	v.resize(k+2,0);
	fr(i,0,n){
		cin>>a;
		v[a]++;
	}

	lli ans=0,rem=0;

	for(lli i=1;i<=k;i++){
		ans += (v[i]/2)*2;
		rem += v[i]%2;
	}

	cout<<ans + rem/2 + rem%2<<endl;
rt;
}
