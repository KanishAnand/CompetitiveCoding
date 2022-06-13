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
	lli ye,bl,x,y,z;
	vector<lli> v;
	cin>>ye>>bl;
	cin>>x>>y>>z;
	lli yr = 2*x + y;
	lli zr = 3*z + y;
	lli ans=0;
	if(ye < yr){
		ans += yr - ye;
	}
	if(bl < zr){
		ans += zr - bl;
	}
	cout<<ans<<endl;
rt;
}
	
