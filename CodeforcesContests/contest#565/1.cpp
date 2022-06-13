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
	lli n,q;
	vector<lli> v;
	cin>>q;	
	fr(i,0,q){
		lli ans=0;
		cin>>n;
		while(n % 2 == 0){
			n = n/2;
			++ans;
		}
		while(n % 3 == 0){
			n = n/3;
			ans += 2;
		}
		while(n % 5 == 0){
			n  = n/5;
			ans += 3;
		}
		if(n  == 1){
			cout<<ans<<endl;
		}
		else{
			cout<<"-1"<<endl;
		}
	}
rt;
}
	
