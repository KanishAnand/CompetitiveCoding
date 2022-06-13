#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define fr(va,beg,end) for(lli va=beg;va<end;va++)
#define pb push_back
#define rt return 0

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
	
	sort(v.begin(),v.end());
	lli x = n/2;
	vector<lli> t(n+2,0);
	t[x] = 0;

	for(lli i = x+1;i<n;i++){
		t[i] = v[i] - v[i-1];
		t[i] += (i - (x+1))*(v[i]-v[i-1]) + t[i-1];
	}
	lli an=x;
	// fr(i,x,n){
	// 	cout<<t[i]<<" "<<i<<endl;
	// }

	for(lli i = x;i<n;i++){
		if(t[i] <= k){
			an = i;
		}
		else{
			break;
		}
	}

	//lli y = v[an] - v[x];
	lli p = an - x +1;
	k -= t[an];
	lli ans = v[an];
	ans += (k/p);
	cout<<ans<<endl;
rt;
}
