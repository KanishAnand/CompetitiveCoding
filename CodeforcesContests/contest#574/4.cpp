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
lli mod = 998244353;
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli n,a,an=0,t=0;
	vector<lli> v;
	cin>>n;	
	fr(i,0,n){
		cin>>a;
		lli x = a,ans=0,ans2=0,ane;
		lli p = 1,p2=10;
		an=0;
		while(x > 0){
			// ans=0;
			// ans2=0;
			lli r = x%10;
			x /= 10;
			ans = (r*p)%mod;
			p = (p*100)%mod;
			// p %= mod;
			ans2 = (r*p2)%mod;
			p2 = (p2*100)%mod;
			// p2 %= mod;
			ans %= mod;
			ans2 %= mod;
			ane = (ans + ans2)%mod;
			an += (ane*n)%mod;
		}
		//cout<<ans<<" "<<ans2<<endl;
		// an = (ans + ans2)%mod;
		// an = (an*n)%mod;
		t = (t + an)%mod;
		//cout<<an<<endl;
	}

	// lli t=0;
	// fr(i,0,v.size()){
	// 	t += v[i];
	// 	t %= mod;
	// }
	cout<<t<<endl;
rt;
}
	
