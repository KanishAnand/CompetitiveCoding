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
	lli n,a,b;
	vector<vector<lli>> v;
	vector<lli> ans;
	cin>>n;	
	v.resize(n+1);
	fr(i,0,n){
		cin>>a>>b;
		v[i+1].pb(a);
		v[i+1].pb(b);
	}

	ans.pb(1);
	lli ch = 1;
	if(n == 3){
		cout<<"1 2 3"<<endl;
		rt;	
	}
	while(ans.size() < n){
		lli c = v[ch][0],d = v[ch][1];
		lli e = v[c][0],f = v[c][1];
		if(d == e || d == f){
			ans.pb(c);
			ch = c;
		}
		else{
			ans.pb(d);
			ch = d;
		}
	}

	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
rt;
}
	
