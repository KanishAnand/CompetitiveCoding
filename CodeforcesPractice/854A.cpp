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

lli gcd(lli a,lli b){
	if(b == 0){
		return a;
	}
	return gcd(b,a%b);
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli n,ans;
	vector<lli> v;
	cin>>n;	
	for(lli i=1;i<=n/2;i++){
		lli c = gcd(i,n-i);
		if(c == 1){
			ans = i;
		}
	}
	
	cout<<ans<<" "<<n-ans<<"\n";
rt;
}
