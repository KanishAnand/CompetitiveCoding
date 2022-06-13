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
	lli n,m,ans=0;
	vector<lli> v;
	cin>>n>>m;	
	lli x = min(m,n);
	for(lli i=1;i<=x;i++){
		for(lli j=1;j<=x;j++){
			if(((i*i) % m + (j*j) % m) % m == 0){
				lli x = n-i;
				lli k1 = x / m;
				lli y = n - j;
				lli k2 = y / m;
				++k1;
				++k2;
				//cout<<i<<" "<<j<<" "<<k1<<" "<<k2<<endl;
				ans += k1*k2;
			}
		}
	}
	cout<<ans<<endl;
rt;
}
	
