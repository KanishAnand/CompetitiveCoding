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
	vector<vector<lli>> adj;
	cin>>n;	
	adj.resize(n+1);
	fr(i,0,n-1){
		cin>>a>>b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	lli flag = 0;

	fr(i,1,n+1){
		if(adj[i].size() == 2){
			flag = 1;
			break;
		}
	}
	
	if(flag == 1){
		cout<<"NO"<<"\n";
	}
	else{
		cout<<"YES"<<"\n";
	}
rt;
}
