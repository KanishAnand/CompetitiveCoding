#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define fr(va,beg,end) for(lli va=beg;va<end;va++)
#define pb push_back
#define rt return 0;
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
	lli n,q,k,a;
	vector<lli> v;
	cin>>q;

	while(q--){
		cin>>n>>k;
		lli minn = 10000000000,maxx = -1;
		fr(i,0,n){
			cin>>a;
			if(a < minn){
				minn = a;
			}
			if(a > maxx){
				maxx = a;
			}
		}

		lli c = minn + k;
		lli d = maxx - c;
		if(d < 0){
			d = -d;
		}
		if(d <= k){
			cout<<c<<endl;
		}
		else{
			cout<<"-1"<<endl;
		}
	}
rt;
}

	
	
