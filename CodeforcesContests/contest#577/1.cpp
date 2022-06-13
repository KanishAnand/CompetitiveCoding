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
	lli n,m,a;
	vector<string> v;
	vector<lli> an;
	string st;
	cin>>n>>m;	
	fr(i,0,n){
		cin>>st;
		v.pb(st);
	}
	fr(i,0,m){
		cin>>a;
		an.pb(a);
	}
	lli ans=0;
	fr(i,0,m){
		vector<lli> cnt(6,0);
		fr(j,0,n){
			cnt[v[j][i] - 'A']++;
		}
		lli ma = -1;
		fr(j,0,6){
			if(cnt[j] > ma){
				ma = cnt[j];
			}
		}
		ans += an[i]*ma;
	}
	cout<<ans<<endl;
rt;
}
	
