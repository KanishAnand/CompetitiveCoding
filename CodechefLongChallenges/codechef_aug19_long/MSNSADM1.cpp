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
	lli n,t,a;
	cin>>t;
	while(t--){
		vector<lli> v;
		lli maxx = 0;
		cin>>n;
		fr(i,0,n){
			cin>>a;
			v.pb(20*a);
		}
		fr(i,0,n){
			cin>>a;
			//cout<<v[i]<<endl;
			v[i] -= a*10;
			//cout<<v[i]<<endl;
			if(v[i] > maxx){
				maxx = v[i];
			}
		}
		cout<<maxx<<endl;
	}	
rt;
}
