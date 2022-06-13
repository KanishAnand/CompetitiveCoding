#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define fr(var) for(lli i=0;i<var;i++)
#define pb push_back
#define rt return 0;
vector<vector<lli>> adj;
vector<lli> ans(1000000,0),chk(1000000,0),col(1000000,0);
lli n,cnt=0,va;
lli input(lli n);
lli input(lli n,vector<lli> &ve){
	lli val;
	for(lli i=0;i<n;i++){
		cin>>val;
		ve.pb(val);
	}
return 0;
}
lli dfs_go(lli a);
lli dfs(){
	for(int i=1;i<=n;i++){
		va = i;
		if(col[i] == 0){
			col[i]=1;
			cnt=0;
			dfs_go(i);
			++cnt;
			//cout<<cnt<<" "<<i<<endl;
			ans[va] = cnt;
			chk[va] = 1;
			col[i]=2;
		}
	}
rt;
}

lli dfs_go(lli a){
	if(adj[a].size() == 0){
		rt;
	}
	fr(adj[a].size()){
		if(col[adj[a][i]] == 0){
			col[adj[a][i]] = 1;
			dfs_go(adj[a][i]);
			ans[adj[a][i]] = va;
			++cnt;
			col[adj[a][i]] = 2;
		}
	}
rt;
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli m,a,b,var;
	cin>>n>>m;
	adj.resize(n+2);
	fr(m){
		cin>>a;
		if(a != 0){
			cin>>b;
			var = b;
			for(lli j=0;j<a-1;j++){
				cin>>b;
				adj[var].pb(b);
				adj[b].pb(var);
			}
		}
	}	
	
	dfs();
	for(int i=1;i<=n;i++){
		if(chk[i] == 1){
			cout<<ans[i]<<" ";
		}
		else{
			cout<<ans[ans[i]]<<" ";
		}
	}
	cout<<endl;
return 0;
}
	
