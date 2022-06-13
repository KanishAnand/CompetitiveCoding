#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define fr(val) for(lli i=0;i<val;i++)
#define pb push_back
#define rt return 0;
vector<set<lli>> adj;
vector<lli> ans;
set<lli> st;
vector<lli> col(100002,0);
lli input(lli n);
lli input(lli n,vector<lli> &ve){
	lli val;
	for(lli i=0;i<n;i++){
		cin>>val;
		ve.pb(val);
	}
return 0;
}

lli dfs(lli a){
	st.erase(st.begin());
	ans.pb(a);
	for(auto it=adj[a].begin();it!=adj[a].end();it++){
		if(col[*it] == 0){
			col[*it]=1;
			st.insert(*it);
		}
	}
	if(!st.empty()){
		dfs(*st.begin());
	}
rt;
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli n,m,a,b;
	cin>>n>>m;
	adj.resize(n+1);
	fr(m){
		cin>>a>>b;
		adj[a].insert(b);
		adj[b].insert(a);
	}
	col[1] = 1;
	st.insert(1);
	dfs(1);
	fr(n){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
rt;
}

	
