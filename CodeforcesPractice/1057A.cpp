#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define fr(va,beg,end) for(lli va=beg;va<end;va++)
#define pb push_back
#define rt return 0;
stack<lli> st;
vector<lli> vis;
lli n;
vector<vector<lli>> adj;

lli dfs(lli a){
	if(adj[a].size() == 0){
		return 1;
	}
	for(lli i=0;i<adj[a].size();i++){
		if(vis[adj[a][i]] == 0){	
			st.push(adj[a][i]);
			if(adj[a][i] == n){
				return 0;
			}
			vis[adj[a][i]] = 1;
			lli c = dfs(adj[a][i]);
			if(c == 0){
				return 0;
			}
			st.pop();
		}
	}
return 1;
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli a;
	vector<lli> v;
	cin>>n;	
	adj.resize(n+1);
	vis.resize(n+1,0);
	fr(i,0,n-1){
		cin>>a;
		adj[a].pb(i+2);
	}

	vis[1] = 1;
	st.push(1);
	dfs(1);
	while(!st.empty()){
		v.pb(st.top());
		st.pop();
	}

	fr(i,0,v.size()){
		cout<<v[v.size()-1-i]<<" ";
	}
	cout<<endl;
rt;
}
